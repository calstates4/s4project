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


function s4_assessment_report() {
	module_load_include('inc', 'webform', 'includes/webform.report');
	$view = views_get_view('reports_courses');
	$view->set_display('page');
	$view->init_handlers(); //initialize display handlers
	$form_state = array(
	  'view' => $view,
	  'display' => $view->display_handler->display,
	  'exposed_form_plugin' => $view->display_handler->get_plugin('exposed_form'),
	  'method' => 'get',
	  'rerender' => TRUE,
	  'no_redirect' => TRUE,
	  'action' => 'reports/assessments'
	);
	$form = drupal_build_form('views_exposed_form', $form_state);
//	dpm(views_get_view_result('reports_courses', 'page'));
	return $form;
}