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
		'#value' => ($user->uid) ? $user->uid : $form_state['values']['user'],
		);

	$form['actions'] = array(
		'#type' => 'action',
		'#weight' => 50
		);

	$form['actions']['submit'] = array(
		'#type' => 'submit',
		'#value' => t('Save @type', array('@type' => $type->label)),
		);

	$form['modal'] = array(
    '#type' => 'value', 
    '#value' => ((isset($_GET['modal']) && $_GET['modal']) || $form_state['values']['modal']),
  );
	unset($form['hours']);
	unset($form['cc_myself']);
	unset($form['email_student']);

	$endpoints = array();
	$relation = relation_create('opportunity_placement', $endpoints);	
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
	watchdog('opportunities', 'Create relation for opportunity with user @user and opportunity @opportunity', array('@user' => $form_state['values']['user'], '@opportunity' => $form_state['values']['opportunities']));
	$endpoints = array(array('entity_type' => 'user', 'entity_id' => $form_state['values']['user']),
												 array('entity_type' => 's4_opportunity', 'entity_id' => $form_state['values']['opportunities']));
	$relation = relation_create('opportunity_placement', $endpoints);
	if($form_state['values']['site-staff']) {
		$relation->field_coordinator[LANGUAGE_NONE][0]['nid'] = $form_state['values']['site-staff'];
	}
	if($form_state['values']['course'] && $form_state['values']['course'] != 'none') {
		$relation->field_course[LANGUAGE_NONE][0]['nid'] = $form_state['values']['course'];
	}
	relation_save($relation);

	if($form_state['values']['modal']) {
    s4_core_modal_close(true);
  }
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
	drupal_goto('opportunities/create/opportunity', array('query' => array('field_opportunity_sites' => $create['site'])));
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
	drupal_goto('opportunities/create/opportunity', array('query' => array('field_opportunity_sites' => $create['site'])));
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
	drupal_set_title(t('Create new @type', array('@type' => $type->label)));
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

		$risk = '';
		foreach($risk_output as $field => $render) {
			$risk .= drupal_render($render);
		}

		$form['risk_identification']['warning'] = array(
			'#prefix' => '<div class="alert alert-error">',
			'#suffix' => '</div>',
			'#markup' => t('<h3>Please review the risks associated with @site.</h3> !risk', 
				array('@site' => $site->title,
						  '@type' => strtolower($type->label),
						  '!risk' => $risk)),
			);
		
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
    '#default_value' => isset($s4_opportunity->status) ? $s4_opportunity->status : 0,
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
  $opportunity->field_opportunity_sites[LANGUAGE_NONE][0]['target_id'] = $create['site'];
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
	$opportunity = s4_opportunity_load($create['opportunity']);
	$site = field_get_items('s4_opportunity', $opportunity, 'field_')
	$placement = array(
		'coordinator' => $create['site_staff'],
		'site' => 0,
		'course' => $course->nid,
		'opportunity' => $create['opportunity'],

		)

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
	if(!count($courses)) {
		drupal_set_message(t('Thank you for submitting this @type.', array('@type' => $type->label)), 'success');
		drupal_goto('opportunities/create/done');
	}
	$results = s4_opportunity_user_can_place($user, $opportunity);
	drupal_set_title(t('Would you like to sign up for @name?', array('@name' => $opportunity->name)));
	return theme('s4_opportunity_place_options', array('opportunity' => $opportunity, 'type' => $type, 'courses' => $courses, 'programs' => $results['programs']));
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
	if(isset($_GET['destination'])) {
		drupal_goto($_GET['destination']);
	}
	else {
		drupal_goto('<front>');
	}
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

	$form['compare'] = array(
		'#prefix' => '<div class="row">',
		'#suffix' => '</div>',
		);

	$form['compare']['opportunity_view'] = array(
		'#markup' => '<h2>'. $type->label .'</h2>' .
			drupal_render(s4_opportunity_page_view($opportunity)),
		'#prefix' => '<div class="span6">',
		'#suffix' => '</div>',
		);

	$form['compare']['relation_view'] = array(
		'#markup' => '<h2>'. t('Placement') .'</h2>' .
			drupal_render(relation_view($relation)),
		'#prefix' => '<div class="span6">',
		'#suffix' => '</div>',
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

	$form['approval_header'] = array(
		'#markup' => '<h1>' . t('Your approval') .'</h1>',
		);

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

function s4_opportunity_placement_approve() {
	global $user;
	$user = user_load($user->uid);
	$results = s4_opportunity_get_require_approval($user);
	
	if(!count($results)) {
		return '<p class="lead">' . t('There are no opportunities requiring your approval.') .'</p>';
	}
	$header = array(t('Course'), t('Last name'), t('First name'), t('Opportunity'), t('Approve'));
	$rows = array();

	foreach($results as $result) {
		$endpoints = field_get_items('relation', $result, 'endpoints');
		$student = user_load($endpoints[0]['entity_id']);
		$opportunity = s4_opportunity_load($endpoints[1]['entity_id']);
		$first_name = field_get_items('user', $student, 'field_first_name');
		$last_name = field_get_items('user', $student, 'field_last_name');
		$course = field_get_items('relation', $result, 'field_course');
		$course = node_load($course[0]['nid']);
		$rows[$last_name[0]['value'].$first_name[0]['value'].$result->rid] = array($course->title, $last_name[0]['value'], $first_name[0]['value'], $opportunity->name, l(t('Approve or deny'), 'opportunities/approve/'. $result->rid, array('attributes' => array('class' => array('btn')))));
	}
	ksort($rows);
	return theme('table', array('header' => $header, 'rows' => $rows));
}

function s4_opportunity_place_self_confirm($form, $form_state, $opportunity, $placement_type, $entity_id) {
	$form = array();
	$type = s4_opportunity_type_load($opportunity->type);
	$form['opportunity'] = array(
		'#type' => 'value',
		'#value' => $opportunity,
		);

	$form['placement_type'] = array(
		'#type' => 'value',
		'#value' => $placement_type,
		);

	$form['entity_id'] = array(
		'#type' => 'value',
		'#value' => $entity_id,
		);

	$form = confirm_form($form,
    t('Are you sure you want to place with the @type %name?', array('@type' => $type->label, 
      '%name' => $opportunity->name)),
    'admin/content/opportunities/s4_opportunity',
    '',
    t('Make placement'),
    t('Cancel'),
    'confirm'
  );

	return $form;
}

function s4_opportunity_place_self_confirm_submit($form, $form_state) {
	global $user;
	if($form_state['values']['placement_type'] == 'course') {
		$course = node_load($form_state['values']['placement_type']);
	}
	
	$endpoints = array(array('entity_type' => 'user', 'entity_id' => $user->uid),
												 array('entity_type' => 's4_opportunity', 'entity_id' => $form_state['values']['opportunity']->s4_opportunity_id));
	$relation = relation_create('opportunity_placement', $endpoints);
	$staff = field_get_items('s4_opportunity', $form_state['values']['opportunity'], 'field_opportunity_site_staff');
	if($staff[0]['entity_id']) {
		$relation->field_coordinator[LANGUAGE_NONE][0]['nid'] = $staff[0]['entity_id'];	
	}
	if($course) {
		$relation->field_course[LANGUAGE_NONE][0]['nid'] = $course->nid;
	}
	$id = relation_save($relation);
	drupal_set_message(t('Your request to be placed with @name has been submitted. Thank you.', array('@name' => $opporutnity->name)), 'success');
	$_SESSION['s4_opportunity_create'] = FALSE;
	$type = s4_opportunity_type_load($form_state['values']['opportunity']->type);

	if(isset($type->data['placement_form']) && $type->data['placement_form']) {
		drupal_goto('opportunities/create/done', array('query' => array('destination' => 'opportunities/form/'. $id)));
	}
	else {
	drupal_goto('opportunities/create/done');
	}
}
