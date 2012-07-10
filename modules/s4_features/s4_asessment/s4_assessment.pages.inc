<?php

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