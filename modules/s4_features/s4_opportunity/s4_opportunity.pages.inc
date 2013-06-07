<?php

function s4_opportunity_place_form($form, $form_state, $type, $user) {
	$form = array();
	
	$type = s4_opportunity_type_load($type);
	module_load_include('inc', 's4_core', 's4_core.pages');
	$form = s4_core_create_signup_form($form, $form_state, $user->uid);
	if($form_state['values']['site']) {
		$opportunities = s4_opportunity_get_site_opportunities($form_state['values']['site'], $type->type);
		if(count($opportunities)) {
			$options = array();
			foreach($opportunities as $opportunity) {
				$options[$opportunity->s4_opportunity_id] = $opportunity->name;
			}
			$form['opportunities'] = array(
				'#type' => 'select',
				'#title' => $type->label,
				'#options' => $options,
				);
		}
	}
	$form['type'] = array(
		'#type' => 'value',
		'#value' => $type->type,
		);

	$form['user'] = array(
		'#type' => 'value',
		'#value' => $user->uid,
		);

	$form['actions'] = array(
		'#type' => 'action',
		'#weight' => 50
		);

	$form['actions']['submit'] = array(
		'#type' => 'submit',
		'#value' => t('Save @type', array('@type' => $type->label)),
		);
	if($form_state['values']['site'] && !count($opportunities)) {
		$form['actions']['submit']['#disabled'] = TRUE;
		$form['actions']['submit']['#value'] = t('This site does not have any @type', array('@type' => $type->label));
	}

	return $form;
}

function s4_opportunity_place_form_submit($form, $form_state) {

	$endpoints = array(array('entity_type' => 'node', 'entity_id' => $form_state['values']['user']),
												 array('entity_type' => 'node', 'entity_id' => $test->nid));
	$relation = relation_create('opportunity_placement', $endpoints);
	field_attach_submit('relation', $relation, $form, $form_state);
	relation_save($relation);
}