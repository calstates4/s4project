<?php

function s4_reporting_object_report($node) {
	module_load_include('inc', 'webform', 'includes/webform.report');
	$form = field_get_items('node', $node, 'field_site_form');
	$form = node_load($form[0]['nid']);
	$query = db_select('field_data_field_site', 's')
			 ->condition('s.entity_type', 'node')
			 ->condition('s.field_site_nid', $node->nid);
	$query->leftJoin('field_data_field_form_signup_sid', 'sid', 'sid.entity_id = s.entity_id AND sid.entity_type = :node', array(':node' => 'node'));
	$query->fields('sid', array('field_form_signup_sid_value'));
	$sids = array();
	$result = $query->execute();
	while($sid = $result->fetchField()) {
		$sids[$sid] = $sid;
	}
	return webform_results_analysis($form, $sids);
}