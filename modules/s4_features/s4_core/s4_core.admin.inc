<?php

/**
*  Admin form for general site settings
*/
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
  
  $form['s4_core_anonymous_site_registration'] = array(
    '#type' => 'checkbox',
    '#title' => 'Allow anyone to propose a new site',
    '#description' => 'Allows anyone to propose a new site (can be overwritten on a program-by-program basis).',
    '#default_value' => variable_get('s4_core_anonymous_site_registration', 0),
  );

  $form['s4_core_default_service_length'] = array(
    '#type' => 'textfield',
    '#title' => 'Default length of service (in days)',
    '#description' => 'If there are no other options like courses or sites to choose the service length, enter the number of days before users get a site evaluation',
    '#default_value' => variable_get('s4_core_default_service_length', 100),
  );

  $form['s4_core_collect_service_hours'] = array(
    '#type' => 'checkbox',
    '#title' => 'Ask students to provide service hours',
    '#description' => 'When checked, students will be prompted to enter their estimated number of service hours when they sign up. Students are also asked about hours during their site evaluation, at which time the initial quote is corrected; however, this ensures that even if a student does not complete an evaluation, an estimate for number of hours served still exists.',
    '#default_value' => variable_get('s4_core_collect_service_hours', TRUE),
  );

  $form['auth'] = array(
    '#type' => 'fieldset',
    '#title' => 'Authentication',
    '#description' => 'Select the types of authentication users should use',
  );

  $auth_options = array('none' => t('- Cannot login -'),
              'user' => t('Custom S4-only account'));
  if (module_exists('cas')) {
    $auth_options['cas'] = t('CAS Single-sign on');
  }
  if (module_exists('ldap')) {
    $auth_options['ldap'] = t('LDAP');
  }
  if (module_exists('shibboleth')) {
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

  $directions = variable_get('s4_core_auth_directions', array('value' => ''));
  $form['auth']['s4_core_auth_directions'] = array(
    '#type' => 'text_format',
    '#title' => 'Custom message',
    '#options' => 'Message to appear above the login form. This could include information on who to call if the account does not work.',
    '#text_format' => FILTER_FORMAT_DEFAULT,
    '#default_value' => $directions['value'],
  );
  $message = variable_get('s4_core_welcome_message', array('value' => ''));
  $form['s4_core_welcome_message'] = array(
    '#type' => 'text_format',
    '#title' => 'Welcome message',
    '#options' => 'This message appears on your site\'s front page.',
    '#text_format' => FILTER_FORMAT_DEFAULT,
    '#default_value' => $message['value'],
  );

  return system_settings_form($form);
}
