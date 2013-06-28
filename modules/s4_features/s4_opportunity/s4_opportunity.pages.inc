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
			$form['site_options']['opportunities'] = array(
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

	unset($form['hours']);
	unset($form['cc_myself']);
	unset($form['email_student']);

	$endpoints = array();
	$relation = relation_create('opportunity_placement', $endpoints);	
	field_attach_form('relation', $relation, $form, $form_state, entity_language('relation', $relation));
	foreach(array('endpoints', 'field_form_signup_sid', 'field_course', 'field_coordinator', 'field_approving_user', 'field_placement_approved', 'field_coordinator') as $field) {
		$form[$field]['#access'] = FALSE;
	}

	if($form_state['values']['site'] && !count($opportunities)) {
		$form['actions']['submit']['#disabled'] = TRUE;
		$form['actions']['submit']['#value'] = t('This site does not have any @type', array('@type' => $type->label));
	}

	return $form;
}

function s4_opportunity_place_form_submit($form, $form_state) {
	$endpoints = array(array('entity_type' => 'user', 'entity_id' => $form_state['values']['user']),
												 array('entity_type' => 's4_opportunity', 'entity_id' => $form_state['values']['opportunities']));
	$relation = relation_create('opportunity_placement', $endpoints);
	field_attach_submit('relation', $relation, $form, $form_state);
	$relation->field_coordinator[LANGUAGE_NONE][0]['nid'] = $form_state['values']['site-staff'];
	$relation->field_course[LANGUAGE_NONE][0]['nid'] = $form_state['values']['course'];
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
	if(count($types) == 1) {
		$type = reset($types);
		drupal_goto('opportunities/create/'. $type->type);
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

	$site = node_load($_SESSION['s4_opportunity_create']['site']);

	$risk_fields = array('field_health_risk',
											 'field_site_health_training',
											 'field_site_instructions',
											 'field_site_requirements');
	$risk_output = array();
	foreach($risk_fields as $field) {
		$item = field_get_items('node', $site, $field);
		if($item && $item[0]['value']) {
			$risk_output[$field] = field_view_field('node', $site, $field);
		}
	}
	if(count($risk_output)) {
		$form['risk_identification'] = array(
			'#type' => 'fieldset',
			'#title' => t('Site risk identification'),
			'#collapsible' => TRUE,
			'#weight' => -50
			);
		$form['risk_identification']['warning'] = array(
			'#prefix' => '<div class="alert alert-error">',
			'#suffix' => '</div>',
			'#markup' => t('<strong>@site has risk information assocaited with it.</strong> Please read the below risks identified for the site you have selected and make sure to add any additional risk identification to your @type.', array('@site' => $site->title, '@type' => $type->label)),
			);
		foreach($risk_output as $field => $render) {
			$form['risk_identification']['risk_' . $field] = array(
				'#markup' => drupal_render($render)
				);
		}
	}

	$opportunity = s4_opportunity_create(array('type' => $type->type));
	$form['#opportunity'] = $opportunity;

	$form['name'] = array(
    '#type' => 'textfield',
    '#title' => t('@type Name', array('@type' => $type->label)),
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

  if(!user_access('administer opportunities')) {
    $form['status']['#access'] = FALSE;
  }

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
	global $user;
	$create = $_SESSION['s4_opportunity_create'];
	$opportunity = $form['#opportunity'];
  field_attach_submit('s4_opportunity', $opportunity, $form, $form_state);
  $opportunity->name = check_plain($form_state['values']['name']);
  $opportunity->save();
  $create['opportunity'] = $opportunity->s4_opportunity_id;
	$_SESSION['s4_opportunity_create'] = $create;
	$result = views_get_view_result('s4_opportunities_create', 'page_2', $user->uid);
	if(!$result || !count($result)) {
		drupal_goto('opportunities/create/place');
		return;
	}
	drupal_goto('opportunities/create/students');
}

function s4_opportunity_create_select_student($user, $course) {
	_s4_opportunity_create_access_check(array('type', 'site', 'opportunity'));

	$create = $_SESSION['s4_opportunity_create'];
	$endpoints = array(array('entity_type' => 'user', 'entity_id' => $user->uid),
												 array('entity_type' => 's4_opportunity', 'entity_id' => $create['opportunity']));
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

function s4_opportunities_place_option() {
	global $user;
	_s4_opportunity_create_access_check(array('type', 'site', 'opportunity'));
	$create = $_SESSION['s4_opportunity_create'];
	$opportunity = s4_opportunity_load($create['opportunity']);
	$type = s4_opportunity_type_load($create['type']);
	$courses = views_get_view_result('user_courses', 'block_2', $user->uid);
	drupal_set_title(t('Would you like to place yourself in @name?', array('@name' => $opportunity->name)));
	return theme('s4_opportunity_place_options', array('opportunity' => $opportunity, 'type' => $type, 'courses' => $courses));
}

function s4_opportunities_place_immediately() {
	global $user;
	if(arg(3)) {
		$course = node_load(arg(3));
	}
	_s4_opportunity_create_access_check(array('type', 'site', 'opportunity'));
	$create = $_SESSION['s4_opportunity_create'];
	$endpoints = array(array('entity_type' => 'user', 'entity_id' => $user->uid),
												 array('entity_type' => 's4_opportunity', 'entity_id' => $create['opportunity']));
	$relation = relation_create('opportunity_placement', $endpoints);
	$relation->field_coordinator[LANGUAGE_NONE][0]['nid'] = $create['site_staff'];
	if($course) {
		$relation->field_course[LANGUAGE_NONE][0]['nid'] = $course->nid;
	}
	$id = relation_save($relation);
	drupal_set_message(t('Your request to be placed with @name has been submitted. Thank you.', array('@name' => $opporutnity->name)), 'success');
	$_SESSION['s4_opportunity_create'] = FALSE;
	drupal_goto('opportunities/create/done');

}

function s4_opportunity_create_done() {
	unset($_SESSION['s4_opportunity_create']);
	drupal_goto('<front>');
}

function s4_opportunity_approve_form($form, $form_state, $relation) {
	$form = array();
	global $user;
	if(!$user->uid) {
		$staff = field_get_items('relation', $relation, 'field_coordinator');
    $staff = node_load($staff[0]['nid']);
	}
	$endpoints = field_get_items('relation', $relation, 'endpoints');
	$opportunity = s4_opportunity_load($endpoints[1]['entity_id']);
	$type = s4_opportunity_type_load($opportunity->type);
	s4_opportunity_check_placement_approval($opportunity, $relation);
	
	if($type->data['approval_form_text']) {
		$form['message'] = array(
			'#markup' => check_markup($type->data['approval_form_text']['value'], $type->data['approval_form_text']['format']),
			'#prefix' => '<div class="well">',
			'#suffix' => '</div>',
			);
	}

	$form['relation'] = array(
		'#type' => 'value',
		'#value' => $relation->rid,
		);

	$form['opportunity'] = array(
		'#type' => 'value',
		'#value' => $opportunity->s4_opportunity_id
		);

	$form['opportunity_type'] = array(
		'#type' => 'value',
		'#value' => $type->type
		);

	$form['relation_view'] = array(
		'#markup' => drupal_render(relation_view($relation)),
		);
	if($user->uid) {
		$endpoints = array(array('entity_type' => 'user', 'entity_id' => $user->uid),
											 array('entity_type' => 'relation', 'entity_id' => $relation->rid));
	}
	else {
		$form['site_staff'] = array(
			'#type' => 'value',
			'#value' => $staff->nid,
			);
		$endpoints = array(array('entity_type' => 'node', 'entity_id' => $staff->nid),
											 array('entity_type' => 'relation', 'entity_id' => $relation->rid));

	}
	$approval = relation_create('approval', $endpoints);	

	field_attach_form('relation', $approval, $form, $form_state, entity_language('relation', $relation));
	
	$form['endpoints']['#access'] = FALSE;
	$form['field_approved']['#access'] = FALSE;

	$form['actions'] = array(
		'#type' => 'actions',
		'#weight' => 50
		);

	$form['actions']['submit_approved'] = array(
		'#type' => 'submit',
		'#value' => t('Approve @type', array('@type' => $type->label)),
		'#attributes' => array('class' => array('btn btn-success')),
		);

	$form['actions']['submit_denied'] = array(
		'#type' => 'submit',
		'#value' => t('Deny @type', array('@type' => $type->label)),
		'#attributes' => array('class' => array('btn btn-danger')),
		);
	return $form;
}

function s4_opportunity_approve_form_submit($form, $form_state) {
	global $user;

	$opportunity = s4_opportunity_load($form_state['values']['opportunity']);
	$placement = relation_load($form_state['values']['relation']);
	if($user->uid) {
		$endpoints = array(array('entity_type' => 'user', 'entity_id' => $user->uid),
										 array('entity_type' => 'relation', 'entity_id' => $form_state['values']['relation']));
	}
	else {
		$staff = node_load($form_state['values']['site_staff']);
		$endpoints = array(array('entity_type' => 'node', 'entity_id' => $staff->nid),
										 array('entity_type' => 'relation', 'entity_id' => $form_state['values']['relation']));
	}
	$type = s4_opportunity_type_load($form_state['values']['opportunity_type']);
	$approval = relation_create('approval', $endpoints);
	field_attach_submit('relation', $approval, $form, $form_state);
	$approval->field_approved[LANGUAGE_NONE][0]['value'] = 
		($form_state['clicked_button']['#value'] == t('Approve @type', array('@type' => $type->label)));
	relation_save($approval);
	drupal_set_message(t('Thank you'), 'success');
	s4_opportunity_check_placement_approval($opportunity, $placement);
	drupal_goto('<front>');
}

function s4_opportunity_placement_form($relation) {
	$endpoints = field_get_items('relation', $relation, 'endpoints');
	$opportunity = s4_opportunity_load($endpoints[1]['entity_id']);
	$type = s4_opportunity_type_load($opportunity->type);
	$_SESSION['s4_opportunity_placement_form'] = array('relation' => $relation->rid,
			'opportunity' => $opportunity->s4_opportunity_id
			);
	drupal_goto('node/'. $type->data['placement_form']);
}