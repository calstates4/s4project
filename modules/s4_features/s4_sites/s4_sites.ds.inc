<?php
/**
 * @file
 * s4_sites.ds.inc
 */

/**
 * Implements hook_ds_field_settings_info().
 */
function s4_sites_ds_field_settings_info() {
  $export = array();

  $ds_fieldsetting = new stdClass();
  $ds_fieldsetting->api_version = 1;
  $ds_fieldsetting->id = 'node|contact_record|default';
  $ds_fieldsetting->entity_type = 'node';
  $ds_fieldsetting->bundle = 'contact_record';
  $ds_fieldsetting->view_mode = 'default';
  $ds_fieldsetting->settings = array(
    'return_to_site' => array(
      'weight' => '1',
      'label' => 'hidden',
      'format' => 'default',
    ),
    'post_date' => array(
      'weight' => '2',
      'label' => 'hidden',
      'format' => 'ds_post_date_long',
    ),
  );
  $export['node|contact_record|default'] = $ds_fieldsetting;

  $ds_fieldsetting = new stdClass();
  $ds_fieldsetting->api_version = 1;
  $ds_fieldsetting->id = 'node|file|default';
  $ds_fieldsetting->entity_type = 'node';
  $ds_fieldsetting->bundle = 'file';
  $ds_fieldsetting->view_mode = 'default';
  $ds_fieldsetting->settings = array(
    'return_to_site' => array(
      'weight' => '0',
      'label' => 'hidden',
      'format' => 'default',
    ),
  );
  $export['node|file|default'] = $ds_fieldsetting;

  $ds_fieldsetting = new stdClass();
  $ds_fieldsetting->api_version = 1;
  $ds_fieldsetting->id = 'node|site|default';
  $ds_fieldsetting->entity_type = 'node';
  $ds_fieldsetting->bundle = 'site';
  $ds_fieldsetting->view_mode = 'default';
  $ds_fieldsetting->settings = array(
    'site_staff' => array(
      'weight' => '4',
      'label' => 'hidden',
      'format' => 'default',
    ),
  );
  $export['node|site|default'] = $ds_fieldsetting;

  return $export;
}

/**
 * Implements hook_ds_custom_fields_info().
 */
function s4_sites_ds_custom_fields_info() {
  $export = array();

  $ds_field = new stdClass();
  $ds_field->api_version = 1;
  $ds_field->field = 'map';
  $ds_field->label = 'Map';
  $ds_field->field_type = 6;
  $ds_field->entities = array(
    'node' => 'node',
  );
  $ds_field->properties = array(
    'block' => 's4_map|s4_map_site_view_map',
    'block_render' => '1',
  );
  $export['map'] = $ds_field;

  $ds_field = new stdClass();
  $ds_field->api_version = 1;
  $ds_field->field = 'return_to_site';
  $ds_field->label = 'Return to site';
  $ds_field->field_type = 6;
  $ds_field->entities = array(
    'node' => 'node',
  );
  $ds_field->properties = array(
    'block' => 's4_sites|s4_sites_return_tab',
    'block_render' => '1',
  );
  $export['return_to_site'] = $ds_field;

  $ds_field = new stdClass();
  $ds_field->api_version = 1;
  $ds_field->field = 'site_staff';
  $ds_field->label = 'Site staff';
  $ds_field->field_type = 6;
  $ds_field->entities = array(
    'node' => 'node',
  );
  $ds_field->properties = array(
    'block' => 'views|site_coordinators-block_1',
    'block_render' => '1',
  );
  $export['site_staff'] = $ds_field;

  return $export;
}

/**
 * Implements hook_ds_layout_settings_info().
 */
function s4_sites_ds_layout_settings_info() {
  $export = array();

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'node|contact_record|default';
  $ds_layout->entity_type = 'node';
  $ds_layout->bundle = 'contact_record';
  $ds_layout->view_mode = 'default';
  $ds_layout->layout = 'ds_2col';
  $ds_layout->settings = array(
    'hide_empty_regions' => 0,
    'hide_sidebars' => 0,
    'regions' => array(
      'left' => array(
        0 => 'body',
      ),
      'right' => array(
        0 => 'return_to_site',
        1 => 'post_date',
        2 => 'field_contact',
        3 => 'field_contact_tags',
        4 => 'field_files',
      ),
    ),
    'fields' => array(
      'body' => 'left',
      'return_to_site' => 'right',
      'post_date' => 'right',
      'field_contact' => 'right',
      'field_contact_tags' => 'right',
      'field_files' => 'right',
    ),
    'classes' => array(),
  );
  $export['node|contact_record|default'] = $ds_layout;

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'node|file|default';
  $ds_layout->entity_type = 'node';
  $ds_layout->bundle = 'file';
  $ds_layout->view_mode = 'default';
  $ds_layout->layout = 's4_site';
  $ds_layout->settings = array(
    'hide_empty_regions' => 0,
    'hide_sidebars' => 0,
    'regions' => array(
      'left' => array(
        0 => 'body',
        1 => 'field_files',
      ),
      'right' => array(
        0 => 'return_to_site',
        1 => 'field_file_category',
        2 => 'field_file_tags',
        3 => 'field_expiration_date',
        4 => 'field_expiration_reminder_date',
      ),
    ),
    'fields' => array(
      'body' => 'left',
      'field_files' => 'left',
      'return_to_site' => 'right',
      'field_file_category' => 'right',
      'field_file_tags' => 'right',
      'field_expiration_date' => 'right',
      'field_expiration_reminder_date' => 'right',
    ),
    'classes' => array(),
  );
  $export['node|file|default'] = $ds_layout;

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'node|site|default';
  $ds_layout->entity_type = 'node';
  $ds_layout->bundle = 'site';
  $ds_layout->view_mode = 'default';
  $ds_layout->layout = 's4_site';
  $ds_layout->settings = array(
    'hide_empty_regions' => 1,
    'hide_sidebars' => 0,
    'regions' => array(
      'left' => array(
        0 => 'body',
        1 => 'field_site_health_training',
        2 => 'field_health_risk',
        3 => 'field_site_projects',
        4 => 'site_staff',
        5 => 'field_site_hours',
      ),
      'right' => array(
        0 => 's4_core_signup_select_site',
        1 => 'field_csu_facility',
        2 => 'field_site_restrict',
        3 => 'field_csu_org_type',
        4 => 'field_website',
        5 => 'field_phone',
        6 => 'field_site_email',
        7 => 'field_location',
        8 => 'map',
        9 => 'field_site_facebook_page',
        10 => 'field_population_size',
        11 => 'field_site_demographics',
        12 => 'field_site_language',
        13 => 'field_site_requirements',
        14 => 'field_signups_max',
        15 => 'field_site_hours_minimum',
      ),
    ),
    'fields' => array(
      'body' => 'left',
      'field_site_health_training' => 'left',
      'field_health_risk' => 'left',
      'field_site_projects' => 'left',
      'site_staff' => 'left',
      'field_site_hours' => 'left',
      's4_core_signup_select_site' => 'right',
      'field_csu_facility' => 'right',
      'field_site_restrict' => 'right',
      'field_csu_org_type' => 'right',
      'field_website' => 'right',
      'field_phone' => 'right',
      'field_site_email' => 'right',
      'field_location' => 'right',
      'field_site_facebook_page' => 'right',
      'field_population_size' => 'right',
      'field_site_demographics' => 'right',
      'field_site_language' => 'right',
      'field_site_requirements' => 'right',
      'field_site_hours_minimum' => 'right',
    ),
    'classes' => array(),
  );
  $export['node|site|default'] = $ds_layout;

  return $export;
}
