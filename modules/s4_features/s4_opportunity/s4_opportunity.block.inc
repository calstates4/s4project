<?php

function s4_opportunity_create_form($form_state) {
	$form = array();

	$options = array();

	foreach (s4_opportunity_get_types() as $type) {
		if(user_access('administer opportunities') || user_access('edit any ' . $type->type .' s4_opportunity')) {
			$options[$type->type] = check_plain($type->label);
		}
	}

	$site = node_load(arg(1));

	$form['site'] = array(
		'#type' => 'value',
		'#value' => $site->nid
		);

	$form['types'] = array(
		'#type' => 'select',
		'#title' => t('Select type of opportunity'),
		'#options' => $options,
		);

	$form['submit'] = array(
		'#type' => 'submit',
		'#value' => t('Create'),
		'#html' => TRUE,
		'#attributes' => array('class' => array('btn', 'btn-success'))
		);

	return $form;
}

function s4_opportunity_create_form_submit($form, $form_state) {
	drupal_goto('opportunities/add/' . $form_state['values']['types'], array('query' => array('field_opportunity_sites' => $form_state['values']['site'])));
}

function s4_opportunity_block_start() {
	$types = s4_opportunity_get_types();
	$type_list = array();
	foreach($types as $k => $type) {
		if(user_access('create any '. $type->type .' s4_opportunity')) {
			$type_list[] = $type->label;
		}
	}
	if(!count($type_list)) {
		return false;
	}
	$type_list = (count($type_list) == 1) ? $type_list[0] : implode(',', $type_list);
	$output = '<p class="lead">';
	$output .= t('Start a new @types.', array('@types' => $type_list));
	$output .= '</p>';
	$output .= '<p>';
	$output .= l('Start', 'opportunities/create', array('attributes' => array('class' => array('btn', 'btn-primary'))));
	$output .= '</p>';
	return $output;
}
