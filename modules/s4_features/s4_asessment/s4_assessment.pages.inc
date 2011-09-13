<?php

function s4_assessment_node_report($node) {
	module_load_include('inc', 'webform', 'includes/webform.report');
	$form = node_load(variable_get('s4_assessment_assessment_form', 0));
	$query = db_select('field_data_field_course', 'c')
			 ->condition('field_course_nid', $node->nid);
	$query->leftJoin('field_data_field_form_assessment_sid', 'a', 'a.entity_id = c.entity_id AND a.bundle = c.bundle');
	$query->fields('a', array('field_form_assessment_sid_value'));
	$sids = $query->execute()->fetchCol();
	return webform_results_analysis($form, $sids);
	
}