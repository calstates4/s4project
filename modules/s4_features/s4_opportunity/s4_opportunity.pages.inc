<?php

function s4_opportunity_place_form($form, $form_state, $type, $user) {
	$form = array();
	dpm($user);
	$type = s4_opportunity_type_load($type);

	$form['type'] = array(
		'#type' => 'value',
		'#value' => $type->type,
		);

	$form['user'] = array(
		'#type' => 'value',
		'#value' => $user->uid,
		);

	/*$endpoints = array(array('entity_type' => 'node', 'entity_id' => $user->uid),
										 array('entity_type' => 'node', 'entity_id' => 0));*/
	$relation = relation_create('opportunity_placement', $endpoints);
	
	field_attach_form('relation', $relation, $form, $form_state);

	dpm($form);
	$form['endpoints']['#access'] = false;

	$form['actions'] = array(
		'#type' => 'action',
		'#weight' => 50
		);

	$form['actions']['submit'] = array(
		'#type' => 'submit',
		'#value' => t('Save @type', array('@type' => $type->label)),
		);

	return $form;
}

function s4_opportunity_place_form_submit($form, $form_state) {

	$endpoints = array(array('entity_type' => 'node', 'entity_id' => $form_state['values']['user']),
												 array('entity_type' => 'node', 'entity_id' => $test->nid));
	$relation = relation_create('opportunity_placement', $endpoints);
	field_attach_submit('relation', $relation, $form, $form_state);
	relation_save($relation);
}