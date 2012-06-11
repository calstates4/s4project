<?php

function s4_assessment_node_report($node) {
	module_load_include('inc', 'webform', 'includes/webform.report');
	$form = node_load(variable_get('s4_assessment_assessment_form', 0));
	$sids = _s4_assessment_get_course_sids($node->nid);
	return webform_results_analysis($form, $sids);
}

function _s4_assessment_get_course_sids($nid) {
	module_load_include('inc', 'webform', 'includes/webform.report');
	$form = node_load(variable_get('s4_assessment_assessment_form', 0));
	$query = db_select('field_data_field_course', 'c')
			 ->condition('field_course_nid', $nid);
	$query->leftJoin('field_data_field_form_assessment_sid', 'a', 'a.entity_id = c.entity_id AND a.bundle = c.bundle');
	$query->isNotNull('a.field_form_assessment_sid_value');
	$query->fields('a', array('field_form_assessment_sid_value'));
	$sids = $query->execute()->fetchCol();
	return ($sids) ? $sids : array();
}


function s4_assessment_report() {
	module_load_include('inc', 'webform', 'includes/webform.report');
	$view = views_get_view('reports_courses');
	$view = $view->clone_view();
	$view->set_display('page');
	$view->init_handlers(); //initialize display handlers
	$view->override_path = 'reports/assessments';
	$form_state = array(
	  'view' => $view,
	  'display' => $display,
	  'exposed_form_plugin' => $view->display_handler->get_plugin('exposed_form'),
	  'method' => 'get',
	  'rerender' => TRUE,
	  'no_redirect' => false,
	  'destination' => 'reports/assessments'
	);
	foreach($view->display as $key => $display) {
		$view->display[$key]->display_options['pager']['options']['items_per_page'] = 0;
	}
	$view->display_handler->options['items_per_page'] = 0;
	$form = drupal_build_form('views_exposed_form', $form_state);
	$courses = views_get_view_result('reports_courses', 'page');
	$results = null;
	if(count($courses)) {
		$sids = array();
		foreach($courses as $course) {
			$course_sids = _s4_assessment_get_course_sids($course->nid);
			if(count($course_sids)) {
				$sids += $course_sids;
			}
		}
		$assessment_form = node_load(variable_get('s4_assessment_assessment_form', 0));
		$form['results']= array(
			'#title' => 'Assessment results',
			'#markup' => webform_results_analysis($assessment_form, $sids),
			'#weight' => 10,
		);
	}
	
	return $form;
}

function s4_assessment_rubric_form($form, $form_state, $node, $component) {
	module_load_include('inc', 'webform', 'components/select');
	$form = array();
	
	$component = $node->webform['components'][$component];
	$options = _webform_select_options_from_text($component['extra']['options']);
	$questions = _webform_select_options_from_text($component['extra']['questions']);
	
	$form['nid'] = array(
		'#type' => 'hidden',
		'#value' => $node->nid,
	);
	
	$form['component'] = array(
		'#type' => 'hidden',
		'#value' => $component['cid'],
	);
	

	foreach($questions as $question_key => $question) {
		foreach($options as $option_key => $option) {
			$form[$question_key .'-'. $option_key] = array(
				'#type' => 'textarea',
				'#title' => check_plain(t('@question: Option @option', array('@question' => $question, '@option' => $option))),
				'#default_value' => $component['extra']['rubric'][$question_key][$option_key],
			);
		}
	}
	
	$form['#theme'][] = 's4_assessment_webform_components_form';
	
	$form['submit'] = array(
		'#type' => 'submit',
		'#value' => 'Save settings',
	);
	return $form;
}

function s4_assessment_rubric_form_submit($form, $form_state) {
	$node = node_load($form_state['values']['nid']);
	$component = $node->webform['components'][$form_state['values']['component']];

	$options = _webform_select_options_from_text($component['extra']['options']);
	$questions = _webform_select_options_from_text($component['extra']['questions']);
	
	if(!is_array($component['extra']['rubric'])) {
		$component['extra']['rubric'] = array();
	}
	
	foreach($questions as $question_key => $question) {
		foreach($options as $option_key => $option) {
			$component['extra']['rubric'][$question_key][$option_key] = 
				$form_state['values'][$question_key .'-'. $option_key];
		}
	}
	webform_component_update($component);
}