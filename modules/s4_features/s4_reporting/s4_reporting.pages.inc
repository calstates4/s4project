<?php


function s4_reporting_term_report($form, &$form_state) {
	$form['term'] = array(
		'#type' => 'fieldset',
		'#title' => 'Report by term',
	);
	
	$terms = array();
	$query = db_select('node', 'n')
	         ->fields('n', array('nid', 'title'))
	         ->condition('n.status', 1)
	         ->condition('n.type', 'course_term');
	$results = $query->execute()->fetchAll();
	foreach($results as $result) {
		$terms[$result->nid] = $result->title;
	}
	
	$form['term']['report_term'] = array(
		'#type' => 'select',
		'#title' => 'Report on one or more terms',
		'#multiple' => true,
		'#options' => $terms,
		'#attributes' => array('class' => array('chosen'),
							   'style' => 'width: 50%;'),
		'#default_value' => $form_state['storage']['values']['report_term'],
	);
	
	$form['dates'] = array(
		'#type' => 'fieldset',
		'#title' => 'Report by date',
		'#collapsible' => true,
		'#collapsed' => ($form_state['storage']['values']['date_enabled']) ? false : true ,
	);
	
	$form['dates']['date_enabled'] = array(
		'#type' => 'checkbox',
		'#title' => 'Ignore terms and run report for a period of time',
		'#default_value' => $form_state['storage']['values']['date_enabled'],
	);
	
	$form['dates']['date_start'] = array(
		'#type' => 'date',
		'#title' => 'Start date',
		'#default_value' => $form_state['storage']['values']['date_start'],
	);
	
	$form['dates']['date_end'] = array(
		'#type' => 'date',
		'#title' => 'End date',
		'#default_value' => $form_state['storage']['values']['date_end'],
	);
	
	$form['submit'] = array(
		'#type' => 'submit',
		'#value' => 'Run report',
	);
	
	if($form_state['storage']['results']) {
		$form += $form_state['storage']['results'];
	}
	
	return $form;
}

function s4_reporting_term_report_validate(&$form, $form_state) {
	if($form_state['values']['date_enabled']) {
		$start = $form_state['values']['date_start'];
		$end = $form_state['values']['date_end'];
		if(mktime(0, 0, 0, $start['month'], $start['day'], $start['year']) >=
		   mktime(0, 0, 0, $end['month'], $end['day'], $end['year'])) {
		   	form_set_error('date_start', t('The start date must be earlier than the end date.'));
		   }
	}
	else {
		if(!count($form_state['values']['report_term'])) {
			form_set_error('report_term', t('You must select at least one term if you are not running this report using dates.'));
		}
	}
}

function s4_reporting_term_report_submit($form, &$form_state) {
	$report_items = array();
	if($form_state['values']['date_enabled']) {
		$start = $form_state['values']['date_start'];
		$end = $form_state['values']['date_end'];

		$report_items[0] = array('start' => date('Y-m-d', mktime(0, 0, 0, $start['month'], $start['day'], $start['year'])), 
						 		'end' => date('Y-m-d', mktime(0, 0, 0, $end['month'], $end['day'], $end['year'])),
						 		'term' => false);
	}
	else {
		foreach($form_state['values']['report_term'] as $nid) {
			$term = node_load($nid);
			$dates = field_get_items('node', $term, 'field_term_date_start');
			$report_items[$nid] = array('start' => $dates[0]['value'],
										'end' => $dates[0]['value2'],
										'term' => $term);
		}
	}
	$output = array();
	$result = module_invoke_all('s4_reporting_term_report', $report_items);
	foreach($result['totals'] as $t => $total) {
		$output['totals'][$t] = t('<strong>@title</strong>: @count', array(
			'@title' => $total['title'],
			'@count' => $total['count']
		));
	}
	$output += $result['output'];
	$output['totals'] = array(
		'#markup' => theme('item_list', array('items' => $output['totals']))
		);	
	$form_state['rebuild'] = TRUE;
	$form_state['storage']['values'] = $form_state['values'];
	$form_state['storage']['results'] = $output;
}

function s4_reporting_object_report($node, $type = 'signup') {
	module_load_include('inc', 'webform', 'includes/webform.report');
	if($node->type == 'site') {
		if($type == 'signup') {
			$form = field_get_items('node', $node, 'field_site_form');
			$form = node_load($form[0]['nid']);
		}
		if($type == 'evaluation') {
			$form = field_get_items('node', $node, 'field_site_eval_form');
			$form = node_load($form[0]['nid']);
		}
		$sids = _s4_reporting_get_site_sids($node, $type);
		if(!count($sids)) {
			return t('<div class="empty"><h3>No @type results yet.</h3></div>', array('@type' => $type));
		}
		return webform_results_analysis($form, $sids);
	}
	if($node->type == 'course') {
		$forms = array();
		$sids = _s4_reporting_get_course_sids($node, $type);
		if(!is_array($sids) || !count($sids)) {
			return t('<div class="empty"><h3>No @type results yet.</h3></div>', array('@type' => $type));
		}
		foreach($sids as $form => $sids) {
			$form = node_load($form);
			$output .= t('<h3>@form</h3>', array('@form' => $form->title));
			if(count($sids)) {
				$output .= webform_results_analysis($form, $sids);
			}
			else {
				$output .= t('<div class="empty"><h3>No @type results yet.</h3></div>', array('@type' => $type));
			}
		}
		return $output;
	}
}

function _s4_reporting_get_course_sids($node, $type = 'signup') {
	$query = db_select('field_data_field_course', 'c')
			 ->condition('c.entity_type', 'node')
			 ->condition('c.field_course_nid', $node->nid);
	$query->leftJoin('field_data_field_site', 'site', 'c.entity_id = site.entity_id AND site.entity_type = :node', array(':node' => 'node'));
	if($type == 'signup') {
		$query->leftJoin('field_data_field_site_form', 'form', 'form.entity_id = site.field_site_nid AND form.entity_type = :node', array(':node' => 'node'));
		$query->addField('form', 'field_site_form_nid', 'form');
		$query->leftJoin('field_data_field_form_signup_sid', 'sid', 'sid.entity_id = c.entity_id AND sid.entity_type = :node', array(':node' => 'node'));
		$query->addField('sid', 'field_form_signup_sid_value', 'sid');
	}
	if($type == 'evaluation') {
		$query->leftJoin('field_data_field_site_eval_form', 'form', 'form.entity_id = site.field_site_nid AND form.entity_type = :node', array(':node' => 'node'));
		$query->addField('form', 'field_site_eval_form_nid', 'form');
		$query->leftJoin('field_data_field_form_evaluation_sid', 'sid', 'sid.entity_id = c.entity_id AND sid.entity_type = :node', array(':node' => 'node'));
		$query->addField('sid', 'field_form_evaluation_sid_value', 'sid');
	}
	$sids = array();
	$result = $query->execute();
	while($row = $result->fetchAssoc()) {
		if($row['sid']) {
			$sids[$row['form']][] = $row['sid'];
		}
	}
	return $sids;
}

function _s4_reporting_get_site_sids($node, $type = 'signup') {
	$query = db_select('field_data_field_site', 's')
			 ->condition('s.entity_type', 'node')
			 ->condition('s.field_site_nid', $node->nid);
	if($type == 'signup') {
		$query->leftJoin('field_data_field_form_signup_sid', 'sid', 'sid.entity_id = s.entity_id AND sid.entity_type = :node', array(':node' => 'node'));
		$query->fields('sid', array('field_form_signup_sid_value'));
	}
	if($type == 'evaluation') {
		$query->leftJoin('field_data_field_form_evaluation_sid', 'sid', 'sid.entity_id = s.entity_id AND sid.entity_type = :node', array(':node' => 'node'));
		$query->fields('sid', array('field_form_evaluation_sid_value'));
	}
	$sids = array();
	$result = $query->execute();
	while($sid = $result->fetchField()) {
		$sids[$sid] = $sid;
	}
	return $sids;
}