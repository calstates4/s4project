<?php
/**
 * @file
 * s4_sites.ds.inc
 */

/**
 * Implements hook_ds_custom_fields_info().
 */
function s4_sites_ds_custom_fields_info() {
  $export = array();

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
        0 => 'field_file_category',
        1 => 'field_file_tags',
        2 => 'field_expiration_date',
        3 => 'field_expiration_reminder_date',
      ),
    ),
    'fields' => array(
      'body' => 'left',
      'field_files' => 'left',
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
        8 => 'field_site_facebook_page',
        9 => 'field_population_size',
        10 => 'field_site_demographics',
        11 => 'field_site_language',
        12 => 'field_site_requirements',
        13 => 'field_site_hours_minimum',
      ),
    ),
    'fields' => array(
      'body' => 'left',
      'field_site_health_training' => 'left',
      'field_health_risk' => 'left',
      'field_site_projects' => 'left',
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
