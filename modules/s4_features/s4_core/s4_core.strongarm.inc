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
  $strongarm->name = 'field_bundle_settings_node__signup';
  $strongarm->value = array(
    'view_modes' => array(
      'teaser' => array(
        'custom_settings' => TRUE,
      ),
      'notifications' => array(
        'custom_settings' => TRUE,
      ),
      'full' => array(
        'custom_settings' => FALSE,
      ),
      'rss' => array(
        'custom_settings' => FALSE,
      ),
      'search_index' => array(
        'custom_settings' => FALSE,
      ),
      'search_result' => array(
        'custom_settings' => FALSE,
      ),
      'print' => array(
        'custom_settings' => FALSE,
      ),
      'token' => array(
        'custom_settings' => FALSE,
      ),
    ),
    'extra_fields' => array(
      'form' => array(
        'title' => array(
          'weight' => '-5',
        ),
        'path' => array(
          'weight' => '30',
        ),
      ),
      'display' => array(
        's4_core_signup_submission' => array(
          'default' => array(
            'weight' => '10',
            'visible' => TRUE,
          ),
        ),
        's4_core_evaluation_submission' => array(
          'default' => array(
            'weight' => '10',
            'visible' => TRUE,
          ),
        ),
        's4_core_assessment_submission' => array(
          'default' => array(
            'weight' => '10',
            'visible' => TRUE,
          ),
        ),
      ),
    ),
  );
  $export['field_bundle_settings_node__signup'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'field_bundle_settings_node__webform';
  $strongarm->value = array(
    'view_modes' => array(
      'teaser' => array(
        'custom_settings' => TRUE,
      ),
      'notifications' => array(
        'custom_settings' => TRUE,
      ),
      'full' => array(
        'custom_settings' => FALSE,
      ),
      'rss' => array(
        'custom_settings' => FALSE,
      ),
      'search_index' => array(
        'custom_settings' => FALSE,
      ),
      'search_result' => array(
        'custom_settings' => FALSE,
      ),
      'print' => array(
        'custom_settings' => FALSE,
      ),
      'token' => array(
        'custom_settings' => FALSE,
      ),
    ),
    'extra_fields' => array(
      'form' => array(
        'title' => array(
          'weight' => '-5',
        ),
      ),
      'display' => array(
        'webform' => array(
          'default' => array(
            'weight' => '1',
            'visible' => TRUE,
          ),
        ),
      ),
    ),
  );
  $export['field_bundle_settings_node__webform'] = $strongarm;

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
  $strongarm->name = 'menu_options_downloadable_form';
  $strongarm->value = array(
    0 => 'main-menu',
  );
  $export['menu_options_downloadable_form'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'menu_options_signup';
  $strongarm->value = array(
    0 => 'main-menu',
  );
  $export['menu_options_signup'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'menu_options_webform';
  $strongarm->value = array(
    0 => 'main-menu',
  );
  $export['menu_options_webform'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'menu_parent_downloadable_form';
  $strongarm->value = 'main-menu:0';
  $export['menu_parent_downloadable_form'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'menu_parent_signup';
  $strongarm->value = 'main-menu:0';
  $export['menu_parent_signup'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'menu_parent_webform';
  $strongarm->value = 'main-menu:0';
  $export['menu_parent_webform'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'messaging_default_method';
  $strongarm->value = 'htmlmail';
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
  $strongarm->name = 'node_preview_downloadable_form';
  $strongarm->value = '0';
  $export['node_preview_downloadable_form'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_preview_signup';
  $strongarm->value = '0';
  $export['node_preview_signup'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_preview_webform';
  $strongarm->value = '0';
  $export['node_preview_webform'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_submitted_downloadable_form';
  $strongarm->value = 0;
  $export['node_submitted_downloadable_form'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_submitted_signup';
  $strongarm->value = 1;
  $export['node_submitted_signup'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_submitted_webform';
  $strongarm->value = 0;
  $export['node_submitted_webform'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'pathauto_node_signup_pattern';
  $strongarm->value = 'signup/[node:nid]';
  $export['pathauto_node_signup_pattern'] = $strongarm;

  return $export;
}
