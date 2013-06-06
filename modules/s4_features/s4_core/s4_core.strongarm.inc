<?php
/**
 * @file
 * s4_core.strongarm.inc
 */

/**
 * Implements hook_strongarm().
 */
function s4_core_strongarm() {
  $export = array();

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'content_access_settings';
  $strongarm->value = array(
    'view' => array(
      'contact_record' => array(
        0 => 4,
        1 => 3,
      ),
      'course' => array(
        0 => 2,
        1 => 5,
        2 => 4,
      ),
      'file' => array(
        0 => 6,
        1 => 3,
        2 => 4,
      ),
      'signup' => array(
        0 => 6,
        1 => 3,
        2 => 4,
      ),
    ),
    'view_own' => array(
      'contact_record' => array(
        0 => 2,
        1 => 3,
      ),
      'course' => array(
        0 => 5,
        1 => 4,
      ),
      'file' => array(
        0 => 6,
        1 => 3,
        2 => 4,
      ),
      'signup' => array(
        0 => 2,
        1 => 6,
        2 => 3,
        3 => 4,
      ),
    ),
    'per_node' => array(
      'contact_record' => 0,
      'course' => 0,
      'file' => 0,
      'signup' => 0,
    ),
    'priority' => array(
      'contact_record' => '0',
      'course' => '0',
      'file' => '0',
      'signup' => '0',
    ),
  );
  $export['content_access_settings'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'front_page_enable';
  $strongarm->value = 1;
  $export['front_page_enable'] = $strongarm;
  
  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'language_content_type_downloadable_form';
  $strongarm->value = '0';
  $export['language_content_type_downloadable_form'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'language_content_type_signup';
  $strongarm->value = '0';
  $export['language_content_type_signup'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'language_content_type_webform';
  $strongarm->value = '0';
  $export['language_content_type_webform'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'location_geocode_us';
  $strongarm->value = 'google';
  $export['location_geocode_us'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'location_usegmap';
  $strongarm->value = 1;
  $export['location_usegmap'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'messaging_default_method';
  $strongarm->value = 'mail';
  $export['messaging_default_method'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'messaging_method_enabled';
  $strongarm->value = array(
    'mail' => 'mail',
    'htmlmail' => 0,
  );
  $export['messaging_method_enabled'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_options_downloadable_form';
  $strongarm->value = array(
    0 => 'status',
    1 => 'promote',
  );
  $export['node_options_downloadable_form'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_options_page';
  $strongarm->value = array(
    0 => 'status',
    1 => 'revision',
  );
  $export['node_options_page'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_options_signup';
  $strongarm->value = array(
    0 => 'status',
    1 => 'revision',
  );
  $export['node_options_signup'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_options_webform';
  $strongarm->value = array(
    0 => 'status',
    1 => 'promote',
  );
  $export['node_options_webform'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_submitted_downloadable_form';
  $strongarm->value = 0;
  $export['node_submitted_downloadable_form'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_submitted_webform';
  $strongarm->value = 0;
  $export['node_submitted_webform'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'nodeformscols_field_placements_downloadable_form_default';
  $strongarm->value = array(
    'title' => array(
      'region' => 'main',
      'weight' => '0',
      'has_required' => TRUE,
      'title' => 'Form name',
    ),
    'additional_settings' => array(
      'region' => 'main',
      'weight' => '4',
      'has_required' => FALSE,
      'title' => 'Vertical tabs',
      'hidden' => 0,
    ),
    'actions' => array(
      'region' => 'right',
      'weight' => '0',
      'has_required' => FALSE,
      'title' => 'Publish',
      'hidden' => 0,
    ),
    'body' => array(
      'region' => 'main',
      'weight' => '1',
      'has_required' => FALSE,
      'title' => 'File description',
      'hidden' => 0,
    ),
    'field_downloadable_file' => array(
      'region' => 'right',
      'weight' => '3',
      'has_required' => TRUE,
      'title' => 'File',
    ),
    'field_site_restrict' => array(
      'region' => 'right',
      'weight' => '1',
      'has_required' => TRUE,
      'title' => 'Available to',
    ),
    'notifications' => array(
      'region' => 'footer',
      'weight' => '5',
      'has_required' => FALSE,
      'title' => 'Notifications',
      'collapsed' => 0,
      'hidden' => 1,
    ),
    'field_downloadable_show' => array(
      'region' => 'right',
      'weight' => '2',
      'has_required' => FALSE,
      'title' => 'Yes',
      'hidden' => 0,
    ),
  );
  $export['nodeformscols_field_placements_downloadable_form_default'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'nodeformscols_field_placements_signup_default';
  $strongarm->value = array(
    'title' => array(
      'region' => 'main',
      'weight' => '0',
      'has_required' => TRUE,
      'title' => 'Title',
    ),
    'additional_settings' => array(
      'region' => 'main',
      'weight' => '6',
      'has_required' => FALSE,
      'title' => 'Vertical tabs',
      'hidden' => 0,
    ),
    'actions' => array(
      'region' => 'right',
      'weight' => '0',
      'has_required' => FALSE,
      'title' => 'Publish',
      'hidden' => 0,
    ),
    'field_coordinator' => array(
      'region' => 'right',
      'weight' => '3',
      'has_required' => FALSE,
      'title' => 'Site staff',
      'hidden' => 0,
    ),
    'field_course' => array(
      'region' => 'right',
      'weight' => '4',
      'has_required' => FALSE,
      'title' => 'Course',
      'hidden' => 0,
    ),
    'field_form_assessment_sid' => array(
      'region' => 'main',
      'weight' => '3',
      'has_required' => FALSE,
      'title' => 'Assessment results',
      'hidden' => 0,
    ),
    'field_form_evaluation_sid' => array(
      'region' => 'main',
      'weight' => '2',
      'has_required' => FALSE,
      'title' => 'Evaluation Form Results',
      'hidden' => 0,
    ),
    'field_form_signup_sid' => array(
      'region' => 'main',
      'weight' => '1',
      'has_required' => FALSE,
      'title' => 'Signup Form Results',
      'hidden' => 0,
    ),
    'field_signup_hours' => array(
      'region' => 'right',
      'weight' => '5',
      'has_required' => FALSE,
      'title' => 'Service hours',
      'hidden' => 0,
    ),
    'field_signup_last_date' => array(
      'region' => 'right',
      'weight' => '7',
      'has_required' => TRUE,
      'title' => 'Last expected date of service',
    ),
    'field_signup_location' => array(
      'region' => 'main',
      'weight' => '4',
      'has_required' => FALSE,
      'title' => 'Location',
      'hidden' => 0,
    ),
    'field_signup_start_date' => array(
      'region' => 'right',
      'weight' => '6',
      'has_required' => FALSE,
      'title' => 'First day of service',
      'hidden' => 0,
    ),
    'field_site' => array(
      'region' => 'right',
      'weight' => '2',
      'has_required' => FALSE,
      'title' => 'Site',
      'hidden' => 0,
    ),
    'field_site_restrict' => array(
      'region' => 'main',
      'weight' => '5',
      'has_required' => FALSE,
      'title' => 'Program',
      'hidden' => 0,
    ),
    'field_user' => array(
      'region' => 'right',
      'weight' => '1',
      'has_required' => FALSE,
      'title' => 'User',
      'hidden' => 0,
    ),
    'notifications' => array(
      'region' => 'main',
      'weight' => '7',
      'has_required' => FALSE,
      'title' => 'Notifications',
      'collapsed' => 0,
      'hidden' => 0,
    ),
  );
  $export['nodeformscols_field_placements_signup_default'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'notifications_content_per_type';
  $strongarm->value = '0';
  $export['notifications_content_per_type'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'notifications_content_type';
  $strongarm->value = array(
    'site' => 'site',
    'page' => 0,
    'contact_record' => 0,
    'coordinator' => 0,
    'course' => 0,
    'course_term' => 0,
    'file' => 0,
    'news' => 0,
    'signup' => 0,
    'webform' => 0,
  );
  $export['notifications_content_type'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'notifications_default_send_interval';
  $strongarm->value = '0';
  $export['notifications_default_send_interval'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'notifications_event_dispatch';
  $strongarm->value = '1';
  $export['notifications_event_dispatch'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'notifications_event_queue';
  $strongarm->value = '1';
  $export['notifications_event_queue'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'notifications_option_subscribe_links';
  $strongarm->value = '1';
  $export['notifications_option_subscribe_links'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'notifications_option_subscription_types_content_thread';
  $strongarm->value = array(
    'enabled' => 1,
    'subscriptions_block' => 1,
    'node_links' => 0,
    'teaser_links' => 0,
  );
  $export['notifications_option_subscription_types_content_thread'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'notifications_option_subscription_types_content_type';
  $strongarm->value = array(
    'enabled' => 0,
    'subscriptions_block' => 0,
    'node_links' => 0,
    'teaser_links' => 0,
  );
  $export['notifications_option_subscription_types_content_type'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'notifications_option_subscription_types_course_signup';
  $strongarm->value = array(
    'enabled' => 1,
    'subscriptions_block' => 0,
    'node_links' => 0,
  );
  $export['notifications_option_subscription_types_course_signup'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'notifications_option_subscription_types_document_expiration';
  $strongarm->value = array(
    'enabled' => 1,
    'subscriptions_block' => 0,
    'node_links' => 0,
  );
  $export['notifications_option_subscription_types_document_expiration'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'notifications_option_unsubscribe_links';
  $strongarm->value = '1';
  $export['notifications_option_unsubscribe_links'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'notifications_sender';
  $strongarm->value = '0';
  $export['notifications_sender'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'notifications_sendself';
  $strongarm->value = 1;
  $export['notifications_sendself'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'pathauto_node_signup_pattern';
  $strongarm->value = 'signup/[node:nid]';
  $export['pathauto_node_signup_pattern'] = $strongarm;

  return $export;
}
