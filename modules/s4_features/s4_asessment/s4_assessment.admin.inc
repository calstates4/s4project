<?php

/**
*	Admin form for selecting the rubric to use
*/
function s4_assessment_admin_form() {
	$form = array();
	
	$options = array();
	$query = db_select('node', 'n')
			 ->fields('n', array('nid', 'title'))
			 ->condition('status', 1)
			 ->condition('type', 'webform')
			 ->orderBy('title');
	$results = $query->execute();
	foreach($results as $result) {
		$options[$result->nid] = $result->title;
	}
	
	$form['s4_assessment_assessment_form'] = array(
		'#type' => 'checkboxes',
		'#title' => 'Select the form template to use for assessment',
		'#options' => $options,
		'#default_value' => variable_get('s4_assessment_assessment_form', 0),
	);
	
	return system_settings_form($form);
}