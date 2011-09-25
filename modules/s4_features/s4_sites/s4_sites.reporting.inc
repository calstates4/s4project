<?php

function _s4_sites_s4_reporting_term_report($report_criteria) {
	$totals = array('total_sites' => array('count' => 0,
											   'title' => t('Total number of sites')),
						'total_active_sites' => array('count' => 0,
											   'title' => t('Total active sites')),
											   );
	$sites = array();
	$locations = array();
	$locations_total = array();
	$query = db_select('node_revision', 'r')
				   ->fields('r', array('nid', 'status'))
				   ->condition('r.timestamp', strtotime($report_criteria['start']), '>=')
				   ->condition('r.timestamp', strtotime($report_criteria['end']), '<=');
	$query->leftJoin('node', 'n', 'n.vid = r.vid');
	$query->condition('n.type', 'site');
	$query->leftJoin('field_data_field_location', 'fl', 'fl.entity_id = r.nid AND fl.bundle = :site', array(':site' => 'site'));
	$query->leftJoin('location', 'l', 'l.lid = fl.field_location_lid');
	$query->fields('l', array('city', 'province'));
	$results = $query->execute()->fetchAll();
	
	foreach($results as $result) {
		$totals['total_sites']['count']++;
		if($result->status) {
			$totals['total_active_sites']['count']++;
			if(!isset($locations[md5($result->city . $result->province)])) {
			  $locations[md5($result->city . $result->province)] = (array)$result;
			}
			$locations_total[md5($result->city . $result->province)]++;
		}
	}
	$output['site_org_types'] = array(
		'#type' => 'fieldset',
		'#title' => 'Sites by organization type',
		'#collapsible' => true,
		'#collapsed' => true,
	);
	
	$output['site_org_types']['org_table']['#markup'] = _s4_sites_reporting_org_type($report_criteria);
	
	$output['site_issues'] = array(
		'#type' => 'fieldset',
		'#title' => 'Sites by issues addressed',
		'#collapsible' => true,
		'#collapsed' => true,
	);
	
	$output['site_issues']['issues_table']['#markup'] = _s4_sites_reporting_issues($report_criteria);	
	
	$output['districts_lower'] = array(
		'#type' => 'fieldset',
		'#title' => 'Sites by state lower district',
		'#collapsible' => true,
		'#collapsed' => true,
	);
	$output['districts_lower']['district_table']['#markup'] = _s4_sites_reporting_district($report_criteria, 'state_lower');	
	
	$output['districts_upper'] = array(
		'#type' => 'fieldset',
		'#title' => 'Sites by state upper district',
		'#collapsible' => true,
		'#collapsed' => true,
	);
	$output['districts_upper']['district_table']['#markup'] = _s4_sites_reporting_district($report_criteria, 'state_upper');	
	
	$output['locations'] = array(
		'#type' => 'fieldset',
		'#title' => 'Sites by location',
		'#collapsible' => true,
		'#collapsed' => true,
	);
	arsort($locations_total);
	$header = array('City', 'Total', 'Percent');
	$rows = array();
	foreach($locations_total as $k => $total) {
		$rows[] = array($locations[$k]['city'] .', '. $locations[$k]['province'],
						$total,
						round(($total / $totals['total_active_sites']['count']) * 100, 2) .'%');
	}
	$output['locations']['location_table']['#markup'] = theme('table', array('header' => $header, 'rows' => $rows));
	
	return array('totals' => $totals,
				 'output' => $output,
				);
}

function _s4_sites_reporting_district($report_criteria, $district_type) {
	$districts = array();
	$header = array('District', 'Active sites', 'Population size', 'Placements', 'Hours');
	$rows = array();
	$query = db_select('node_revision', 'r')
			   ->fields('r', array('nid', 'status'))
			   ->condition('r.timestamp', strtotime($report_criteria['start']), '>=')
			   ->condition('r.timestamp', strtotime($report_criteria['end']), '<=');
	if($district_type == 'state_lower') {
		$query->leftJoin('field_revision_field_district_state_lower', 'd', 'd.entity_id = r.nid AND d.revision_id = r.vid AND d.bundle = :site', array(':site' => 'site'));
		$query->addField('d', 'field_district_state_lower_value', 'district');
	}
	if($district_type == 'state_upper') {
		$query->leftJoin('field_revision_field_district_state_upper', 'd', 'd.entity_id = r.nid AND d.revision_id = r.vid AND d.bundle = :site', array(':site' => 'site'));
		$query->addField('d', 'field_district_state_upper_value', 'district');
	}
	$query->distinct();
	$query->leftJoin('field_data_field_population_size', 'p', 'p.entity_id = d.entity_id AND p.bundle = d.bundle');
	$query->fields('p', array('field_population_size_value'));
	$result = $query->execute()->fetchAll();
	
	foreach($result as $row) {
		$districts[$row->district][$row->nid] = array('population' => $row->field_population_size_value);
		$query = db_select('node_revision', 'r')
			   ->fields('r', array('nid'))
			   ->condition('r.status', 1)
			   ->condition('r.timestamp', strtotime($report_criteria['start']), '>=')
			   ->condition('r.timestamp', strtotime($report_criteria['end']), '<=');
		$query->leftJoin('node', 'n', 'n.nid = r.nid');
		$query->leftJoin('field_revision_field_signup_hours', 'h', 'h.revision_id = r.vid AND h.entity_id = r.nid AND h.bundle = :signup', array(':signup' => 'signup'));
		$query->leftJoin('field_revision_field_site', 's', 's.revision_id = r.vid AND s.entity_id = r.nid AND s.bundle = :signup', array(':signup' => 'signup'));
		$query->leftJoin('field_data_field_form_evaluation_sid', 'e', 'e.entity_id = r.nid AND e.bundle = :signup', array(':signup' => 'signup'));
		$query->fields('e', array('field_form_evaluation_sid_value'));
		$query->condition('s.field_site_nid', $row->nid);
		$query->fields('h', array('field_signup_hours_value'));
		$signup_result = $query->execute()->fetchAll();
		foreach($signup_result as $signup) {
			$districts[$row->district][$row->nid]['signups'][$signup->nid] = $signup->field_signup_hours_value;
			if($signup->field_form_evaluation_sid_value && $row->district) {
				$districts[$row->district][$row->nid]['evaluations']++;
			}
		}
	}
	foreach($districts as $district_name => $district) {
		$population = 0;
		$signups = 0;
		$hours = 0;
		foreach($district as $site) {
			$population += $site['population'];
			if(is_array($site['signups'])) {
				$signups += count($site['signups']);
				$hours += array_sum($site['signups']);
			}
		}
		$rows[] = array($district_name, count($district), $population, $signups, $hours);
	}
	return theme('table', array('header' => $header, 'rows' => $rows));
}

function _s4_sites_reporting_issues($report_criteria) {
	// issues_addressed
	foreach(taxonomy_get_vocabularies() as $vid => $vocabulary) {
		if($vocabulary->machine_name == 'issues_addressed') {
			$issue_type = taxonomy_get_tree($vid);
		}
	}
	
	$header = array('Issues', 'Active sites', 'Population size', 'Placements', 'Hours', 'Evaluations');
	$rows[] = array();
	foreach($issue_type as $o) {
		$sites = 0;
		$population = 0;
		$signups = array();
		$evaluations = 0;
		$query = db_select('node_revision', 'r')
				   ->fields('r', array('nid', 'status'))
				   ->condition('r.timestamp', strtotime($report_criteria['start']), '>=')
				   ->condition('r.timestamp', strtotime($report_criteria['end']), '<=');
		$query->leftJoin('field_data_field_csu_facility', 'o', 'o.entity_id = r.nid AND o.bundle = :site', array(':site' => 'site'));
		$query->distinct();
		$query->condition('o.field_csu_facility_tid', $o->tid);
		$query->leftJoin('field_data_field_population_size', 'p', 'p.entity_id = o.entity_id AND p.bundle = o.bundle');
		$query->fields('p', array('field_population_size_value'));
		$result = $query->execute()->fetchAll();
		foreach($result as $row) {
			$sites++;
			$population += $row->field_population_size_value;
			$query = db_select('node_revision', 'r')
				   ->fields('r', array('nid'))
				   ->condition('r.status', 1)
				   ->condition('r.timestamp', strtotime($report_criteria['start']), '>=')
				   ->condition('r.timestamp', strtotime($report_criteria['end']), '<=');
			$query->leftJoin('node', 'n', 'n.nid = r.nid');
			$query->leftJoin('field_revision_field_signup_hours', 'h', 'h.revision_id = r.vid AND h.entity_id = r.nid AND h.bundle = :signup', array(':signup' => 'signup'));
			$query->leftJoin('field_revision_field_site', 's', 's.revision_id = r.vid AND s.entity_id = r.nid AND s.bundle = :signup', array(':signup' => 'signup'));
			$query->leftJoin('field_data_field_form_evaluation_sid', 'e', 'e.entity_id = r.nid AND e.bundle = :signup', array(':signup' => 'signup'));
			$query->fields('e', array('field_form_evaluation_sid_value'));
			$query->condition('s.field_site_nid', $row->nid);
			$query->fields('h', array('field_signup_hours_value'));
			$signup_result = $query->execute()->fetchAll();
			foreach($signup_result as $signup) {
				$signups[$signup->nid] = $signup->field_signup_hours_value;
				if($signup->field_form_evaluation_sid_value) {
					$evaluations++;
				}
			}

		}
		$rows[] = array($o->name, $sites, $population, count($signups), array_sum($signups), $evaluations);
	}
	return theme('table', array('header' => $header, 'rows' => $rows));
}

function _s4_sites_reporting_org_type($report_criteria) {
	foreach(taxonomy_get_vocabularies() as $vid => $vocabulary) {
		if($vocabulary->machine_name == 'organization_type') {
			$org_type = taxonomy_get_tree($vid);
		}
	}
	$header = array('Org Type', 'Active sites', 'Population size', 'Placements', 'Hours', 'Evaluations');
	$rows[] = array();
	foreach($org_type as $o) {
		$sites = 0;
		$population = 0;
		$signups = array();
		$evaluations = 0;
		$query = db_select('node_revision', 'r')
				   ->fields('r', array('nid', 'status'))
				   ->condition('r.timestamp', strtotime($report_criteria['start']), '>=')
				   ->condition('r.timestamp', strtotime($report_criteria['end']), '<=');
		$query->leftJoin('field_data_field_csu_org_type', 'o', 'o.entity_id = r.nid AND o.bundle = :site', array(':site' => 'site'));
		$query->distinct();
		$query->condition('o.field_csu_org_type_tid', $o->tid);
		$query->leftJoin('field_data_field_population_size', 'p', 'p.entity_id = o.entity_id AND p.bundle = o.bundle');
		$query->fields('p', array('field_population_size_value'));
		$result = $query->execute()->fetchAll();
		foreach($result as $row) {
			$sites++;
			$population += $row->field_population_size_value;
			$query = db_select('node_revision', 'r')
				   ->fields('r', array('nid'))
				   ->condition('r.status', 1)
				   ->condition('r.timestamp', strtotime($report_criteria['start']), '>=')
				   ->condition('r.timestamp', strtotime($report_criteria['end']), '<=');
			$query->leftJoin('node', 'n', 'n.nid = r.nid');
			$query->leftJoin('field_revision_field_signup_hours', 'h', 'h.revision_id = r.vid AND h.entity_id = r.nid AND h.bundle = :signup', array(':signup' => 'signup'));
			$query->leftJoin('field_revision_field_site', 's', 's.revision_id = r.vid AND s.entity_id = r.nid AND s.bundle = :signup', array(':signup' => 'signup'));
			$query->leftJoin('field_data_field_form_evaluation_sid', 'e', 'e.entity_id = r.nid AND e.bundle = :signup', array(':signup' => 'signup'));
			$query->fields('e', array('field_form_evaluation_sid_value'));
			$query->condition('s.field_site_nid', $row->nid);
			$query->fields('h', array('field_signup_hours_value'));
			$signup_result = $query->execute()->fetchAll();
			foreach($signup_result as $signup) {
				$signups[$signup->nid] = $signup->field_signup_hours_value;
				if($signup->field_form_evaluation_sid_value) {
					$evaluations++;
				}
			}
		}
		$rows[] = array($o->name, $sites, $population, count($signups), array_sum($signups), $evaluations);
	}
	return theme('table', array('header' => $header, 'rows' => $rows));
}