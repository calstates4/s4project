<?php


function s4_core_admin_form() {
	$form = array();
	
	$form['s4_core_signup_require_coordinator'] = array(
		'#type' => 'checkbox',
		'#title' => 'Students should sign up with a coordinator',
		'#description' => 'If unchecked, no coordinators are ever signed up with by students. Generally, this should be left on, as you can override this on a per-site basis. What this does is enable the "Select a coordinator" step from the progress bar.',
		'#default_value' => variable_get('s4_core_signup_require_coordinator', 1),
	);
	
	$form['s4_core_signup_require_course'] = array(
		'#type' => 'checkbox',
		'#title' => 'Enable registering as part of a course',
		'#description' => 'If unchecked, students will never be asked to relate their signup with a course. Individual students through your SIS integration can have an option to be given access regardless of their relationship with a course, so it is usually best to keep this on.',
		'#default_value' => variable_get('s4_core_signup_require_course', 1),
	);
	
	$form['s4_core_default_service_length'] = array(
		'#type' => 'textfield',
		'#title' => 'Default length of service (in days)',
		'#description' => 'If there are no other options like courses or sites to choose the service length, enter the number of days before users get a site evaluation',
		'#default_value' => variable_get('s4_core_default_service_length', 100),
	);
		
	$form['auth'] = array(
		'#type' => 'fieldset',
		'#title' => 'Authentication',
		'#description' => 'Select the types of authentication users should use',
	);
	
	$auth_options = array('none' => t(' - Cannot login - '),
						  'user' => t('Custom S4-only account'),);
	if(module_exists('cas')) {
		$auth_options['cas'] = t('CAS Single-sign on');
	}
	if(module_exists('ldap')) {
		$auth_options['ldap'] = t('LDAP');
	}
	if(module_exists('shibboleth')) {
		$auth_options['ldap'] = t('Shibboleth');
	}
	
	$form['auth']['s4_core_auth_staff'] = array(
		'#type' => 'select',
		'#title' => 'Staff',
		'#options' => $auth_options,
		'#default_value' => variable_get('s4_core_auth_staff', 'user'),
	);
	
	$form['auth']['s4_core_auth_faculty'] = array(
		'#type' => 'select',
		'#title' => 'Faculy',
		'#options' => $auth_options,
		'#default_value' => variable_get('s4_core_auth_faculty', 'user'),
	);
	
	$form['auth']['s4_core_auth_students'] = array(
		'#type' => 'select',
		'#title' => 'Students',
		'#options' => $auth_options,
		'#default_value' => variable_get('s4_core_auth_students', 'user'),
	);
	
	$form['auth']['s4_core_auth_sites'] = array(
		'#type' => 'select',
		'#title' => 'Site coordinators',
		'#options' => $auth_options,
		'#default_value' => variable_get('s4_core_auth_sites', 'none'),
	);
	
	$form['auth']['s4_core_auth_directions'] = array(
		'#type' => 'text_format',
		'#title' => 'Custom message',
		'#options' => 'Message to appear above the login form. This could include information on who to call if the account does not work.',
		'#text_format' => FILTER_FORMAT_DEFAULT, 
		'#default_value' => variable_get('s4_core_auth_directions', ''),
	);
	
	$form['evaluation_reminder'] = array(
		'#type' => 'fieldset',
		'#title' => 'Evaluation email message',
	);
	
	$form['evaluation_reminder']['s4_core_reminder_email_subject'] = array(
		'#type' => 'textfield',
		'#title' => 'Email subject',
		'#default_value' => variable_get('s4_core_reminder_email_subject', ''),
	);
	
	$form['evaluation_reminder']['s4_core_reminder_email_body'] = array(
		'#type' => 'textarea',
		'#title' => 'Email message',
		'#description' => 'The email body to be sent when reminding users to complete their evaluations',
		'#default_value' => variable_get('s4_core_reminder_email_body', ''),
	);
	
	if (module_exists('token')) {
	    theme('token_tree', array('token_types' => array('node')));
		// Or use it in a form:
		$form['tokens'] = array(
			'#theme' => 'token_tree',
			'#token_types' => array('s4_signup'),
		);
	}
	
	return system_settings_form($form);
}

function s4_core_admin_user_attributes_list() {
	$attributes = variable_get('s4_core_user_attribute_mappings', array());
	$header = array('Argument from SIS', 'User attribute', 'Options');
	$data = array();
	foreach($attributes as $sis => $attribute) {
		$data[] = array($sis, 
						$attribute, 
						l('Edit', 'admin/config/s4/user-attributes/edit/'. $sis) .' '. 
						l('Delete', 'admin/config/s4/user-attributes/delete/'. $sis)
						);
										
	}
	return theme('table', array('header' => $header, 'rows' => $data));
}

function s4_core_admin_user_attributes_edit($form_state, $form, $attribute = false) {
	$form = array();
	
	if($attribute) {
		$attributes = variable_get('s4_core_user_attribute_mappings', array());
		$field = $attributes[$attribute];
	}
	else {
		$attribute = array();
	}
	$user_fields = array();
	$bundle = field_extract_bundle('user', 'user');
	foreach(field_info_instances('user', $bundle) as $field_key => $field) {
		$user_fields[$field_key] = $field['label'];
	}
	
	$form['field'] = array(
		'#type' => 'select',
		'#title' => 'User attribute',
		'#options' => $user_fields,
		'#default_value' => $field,
	);
	
	$form['sis_field'] = array(
		'#type' => 'textfield',
		'#title' => 'SIS field',
		'#description' => 'The field name as coming from your SIS.',
		'#default_value' => $attribute,
	);
	
	$form['submit'] = array(
		'#type' => 'submit',
		'#value' => 'Save attribute',
	);
	
	return $form;
}

function s4_core_admin_user_attributes_edit_submit($form, $form_state) {
	$attributes = variable_get('s4_core_user_attribute_mappings', array());
	$attributes[$form_state['values']['sis_field']] = $form_state['values']['field'];
	variable_set('s4_core_user_attribute_mappings', $attributes);
	drupal_set_message('User attribute mapping saved.');
	drupal_goto('admin/config/s4/user-attributes');
}

function s4_core_admin_user_attributes_delete($form_state, $attribute) {

}

function s4_core_admin_user_attributes_test($form, &$form_state) {
	$form = array();
	
	$form['login_id'] = array(
		'#type' => 'textfield',
		'#title' => 'Enter user login ID',
		'#description' => 'This user will be queried against your SIS for testing.',
		'#default_value' => $form_state['values']['login_id'],
	);
	
	$form['submit'] = array(
		'#type' => 'submit',
		'#value' => 'Test user',
	);
	
	if($form_state['storage']['user']) {
		$header = array('SIS Field', 'User attribute', 'Value');
		$form['results'] = array(
			'#type' => 'item',
			'#title' => t('Results'),
			'#markup' => theme('table', array('header' => $header, 'data' => $form_state['storage']['user']))
		);
	}
	
	return $form;
}

function s4_core_admin_user_attributes_test_submit($form, &$form_state) {
	$user = module_invoke_all('s4_get_user', $form_state['values']['login_id']);
	$mapping = _s4_core_map_user_attributes();
	$form_state['storage'] = array();
	foreach($mapping as $sis_field => $field) {
		$form_state['storage']['user'][] = array($sis_field,
										   $field,
										   $user[$sis_field]);
	}
	
}