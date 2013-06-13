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
												 array('entity_type' => 'node', 'entity_id' => $form_state['values']['opportunities']));
	$relation = relation_create('opportunity_placement', $endpoints);
	field_attach_submit('relation', $relation, $form, $form_state);
	relation_save($relation);
}

function s4_opportunity_create_start() {
	$types = s4_opportunity_get_types();
	$_SESSION['s4_opportunity_create'] = array();
	foreach($types as $k => $type) {
		if(!user_access('create any '. $type->type .' s4_opportunity')) {
			unset($types[$k]);
		}
	}
	return theme('s4_opportunity_create_start', array('types' => $types));
}

function _s4_opportunity_create_access_check($keys = array()) {
	$create = $_SESSION['s4_opportunity_create'];
	$create = ($create) ? $create : array();
	$access = ($create) ? true : false;
	foreach($keys as $key) {
		if(!isset($create[$key])) {
			$access = false;
		}
	}
	if(!$access) {
		$_SESSION['s4_opportunity_create'] = false;
		drupal_set_message(t('It appears you selected the wrong type of content. Please try again.'), 'error');
		drupal_goto('<front>');
	}
}

function s4_opportunity_create_start_type($type) {
	$_SESSION['s4_opportunity_create'] = array('step' => 1, 'type' => $type->type);
	drupal_goto('opportunities/create/sites');
}

function s4_opportunity_create_site_select($site) {
	$create = $_SESSION['s4_opportunity_create'];
	_s4_opportunity_create_access_check(array('type'));
	$create['site'] = $site->nid;
	$_SESSION['s4_opportunity_create'] = $create;
	drupal_goto('opportunities/create/site-staff/'. $site->nid);
}

function s4_opportunity_create_site_staff_select($site_staff) {
	$create = $_SESSION['s4_opportunity_create'];
	_s4_opportunity_create_access_check(array('type', 'site'));
	$create['site_staff'] = $site_staff->nid;
	$_SESSION['s4_opportunity_create'] = $create;
	drupal_goto('opportunities/create/opportunity');
}

function s4_opportunity_create_new_site_staff_form($form, $form_state) {
	$create = $_SESSION['s4_opportunity_create'];
	$type = s4_opportunity_type_load($create['type']);
	_s4_opportunity_create_access_check(array('type', 'site'));

	$form = array();
	$node = new stdClass();
	$node->type = 'coordinator';

	field_attach_form('node', $node, $form, $form_state);
	$form['#node'] = $node;
	$form['field_site']['#access'] = false;
	$form['field_signups_max']['#access'] = false;
	$form['field_site_staff_user']['#access'] = false;
	if($type->data['site_staff_approve']) {
		$language = $form['field_email']['#language'];
		$form['field_email'][$language][0]['email']['#required'] = true;
		$form['field_email'][$language][0]['email']['#description'] = t('Because these type of opportunities require site staff approval, an email for this site staff is required.');
	}
	$language = $form['field_phone']['#language'];
	unset($form['field_phone'][$language]['add_more']);

	$form['actions'] = array(
		'#type' => 'action',
		'#weight' => 50
		);

	$form['actions']['submit'] = array(
		'#type' => 'submit',
		'#value' => t('Save site staff'),
	  );
	return $form;
}

function s4_opportunity_create_new_site_staff_form_validate($form, $form_state) {
	$node = $form['#node'];
	field_attach_validate('node', $node);
}

function s4_opportunity_create_new_site_staff_form_submit($form, $form_state) {
	$create = $_SESSION['s4_opportunity_create'];
	$node = $form['#node'];
  field_attach_submit('node', $node, $form, $form_state);
  node_save($node);
  $node->field_site[LANGUAGE_NONE][0]['nid'] = $create['site'];
  node_save($node);

  $create['site_staff'] = $node->nid;
	$_SESSION['s4_opportunity_create'] = $create;
	drupal_goto('opportunities/create/opportunity');
}

function s4_opportunity_create_opportunity_title() {
	$create = $_SESSION['s4_opportunity_create'];
	$type = s4_opportunity_type_load($create['type']);
	return t('Create new @type', array('@type' => $type->label));
}

function s4_opportunity_create_opportunity_form($form, $form_state) {
	$form = array();
	$create = $_SESSION['s4_opportunity_create'];
	$type = s4_opportunity_type_load($create['type']);

	$opportunity = s4_opportunity_create(array('type' => $type->type));
	$form['#opportunity'] = $opportunity;

	$form['name'] = array(
    '#type' => 'textfield',
    '#title' => t('Opportunity Name'),
    '#default_value' => isset($s4_opportunity->name) ? $s4_opportunity->name : '',
    '#maxlength' => 255,
    '#required' => TRUE,
    '#weight' => -5,
  );

  $form['status'] = array(
    '#type' => 'checkbox',
    '#title' => t('Active'),
    '#description' => t('Active @types are available for students to be placed with. Inactive @types are only visible to department staff.', array('@types' => check_plain($type->label))),
    '#default_value' => isset($s4_opportunity->active) ? $s4_opportunity->active : 0,
    '#maxlength' => 255,
    '#weight' => -4,
  );
	field_attach_form('s4_opportunity', $opportunity, $form, $form_state);
	
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

function s4_opportunity_create_opportunity_form_validate($form, $form_state) {
	$opportunity = $form['#opportunity'];
	field_attach_validate('s4_opportunity', $opportunity);
}

function s4_opportunity_create_opportunity_form_submit($form, $form_state) {
	$create = $_SESSION['s4_opportunity_create'];
	$opportunity = $form['#opportunity'];
  field_attach_submit('s4_opportunity', $opportunity, $form, $form_state);
  $opportunity->save();

  $create['opportunity'] = $opportunity->s4_opportunity_id;
	$_SESSION['s4_opportunity_create'] = $create;
	drupal_goto('opportunities/create/students');
}

function s4_opportunity_create_select_student($user, $course) {
	_s4_opportunity_create_access_check(array('type', 'site', 'opportunity'));

	$create = $_SESSION['s4_opportunity_create'];
	$endpoints = array(array('entity_type' => 'user', 'entity_id' => $user->uid),
												 array('entity_type' => 'node', 'entity_id' => $create['opportunity']));
	$relation = relation_create('opportunity_placement', $endpoints);
	$relation->field_coordinator[LANGUAGE_NONE][0]['nid'] = $create['site_staff'];
	$relation->field_course[LANGUAGE_NONE][0]['nid'] = $course->nid;
	$id = relation_save($relation);
	$first_name = field_get_items('user', $user, 'field_first_name');
	$last_name = field_get_items('user', $user, 'field_last_name');
	drupal_set_message(t('@first_name @last_name has been placed.', array('@first_name' => $first_name[0]['value'], '@last_name' => $last_name[0]['value'])));
	$create['students'] = (isset($create['students'])) ? $create['students'] : array();
	$create['students'][$user->uid] = $user->uid;
	$_SESSION['s4_opportunity_create'] = $create;
	drupal_goto('opportunities/create/students/'. implode(',', $create['students']));
}

function s4_opportunity_create_done() {
	unset($_SESSION['s4_opportunity_create']);
	drupal_goto('<front>');
}