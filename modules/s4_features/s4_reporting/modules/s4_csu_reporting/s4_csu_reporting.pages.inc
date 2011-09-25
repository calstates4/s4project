<?php

function s4_csu_reporting_form($form, $form_state) {
	module_load_include('inc', 's4_reporting', 's4_reporting.pages');
	$form = s4_reporting_term_report($form, $form_state);
	if($form_state['storage']['results']) {
		$form += $form_state['storage']['results'];
	}
	return $form;
}

function s4_csu_reporting_form_validate(&$form, $form_state) {
	module_load_include('inc', 's4_reporting', 's4_reporting.pages');
	s4_reporting_term_report_validate($form, $form_state);
}

function s4_csu_reporting_form_submit(&$form, &$form_state) {
	$report_items = array();
	if($form_state['values']['date_enabled']) {
		$start = $form_state['values']['date_start'];
		$end = $form_state['values']['date_end'];

		$report_items = array('start' => date('Y-m-d', mktime(0, 0, 0, $start['month'], $start['day'], $start['year'])), 
						 	  'end' => date('Y-m-d', mktime(0, 0, 0, $end['month'], $end['day'], $end['year'])),
						 	  'term' => false);
	}
	else {
		$term = node_load($form_state['values']['report_term']);
		$dates = field_get_items('node', $term, 'field_term_date_start');
		$report_items = array('start' => $dates[0]['value'],
							  'end' => $dates[0]['value2'],
							  'term' => $term);
	}
	
	$output = array();
	$result = array();
	foreach(_s4_csu_reporting_functions() as $function_name) {
		$result[$function_name] = $function_name($report_items);
	}
	$form_state['rebuild'] = TRUE;
	$form_state['storage']['values'] = $form_state['values'];
	$form_state['storage']['results'] = $result;
}

function s4_csu_reporting_totals($report_items) {
	$result = module_invoke_all('s4_reporting_term_report', $report_items);
	foreach($result['totals'] as $t => $total) {
		$totals[$t] = t('<strong>@title</strong>: @count', array(
			'@title' => $total['title'],
			'@count' => $total['count']
		));
	}
	return array('#markup' => theme('item_list', array('items' => $totals)));
}

/**
Total number of SL students placed
Total estimate # of SL hours
Number of SL Courses
Number of SL Sections
Total Upper Division SL courses
Total Lower Division SL courses
Total Evaluations Completed
Total number of learning sites in the database
Total number of ACTIVE learning sites
Total number of school sites
Total number of ACTIVE school sites (would be great if we could break this down by early
childhood, K-5, 6-8, 9-12 grades or early childhood, elementary, middle and high school)

**/