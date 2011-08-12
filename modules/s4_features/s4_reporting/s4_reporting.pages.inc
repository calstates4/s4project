<?php

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

function s4_reporting_report_view() {
	
	return 'report!';
}