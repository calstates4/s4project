<?php
/**
 * @file
 * s4_sites.ds.inc
 */

/**
 * Implements hook_ds_layout_settings_info().
 */
function s4_sites_ds_layout_settings_info() {
  $export = array();

  $ds_layout = new stdClass;
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
        4 => 'field_site_hours',
      ),
      'right' => array(
        0 => 'field_csu_facility',
        1 => 'field_csu_org_type',
        2 => 'field_website',
        3 => 'field_phone',
        4 => 'field_site_email',
        5 => 'field_location',
        6 => 'field_site_facebook_page',
        7 => 'field_population_size',
        8 => 'field_site_demographics',
        9 => 'field_site_language',
        10 => 'field_site_requirements',
        11 => 'field_site_hours_minimum',
        12 => 'field_site_images',
      ),
    ),
    'fields' => array(
      'body' => 'left',
      'field_site_health_training' => 'left',
      'field_health_risk' => 'left',
      'field_site_projects' => 'left',
      'field_site_hours' => 'left',
      'field_csu_facility' => 'right',
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
      'field_site_images' => 'right',
    ),
    'classes' => array(),
  );
  $export['node|site|default'] = $ds_layout;

  return $export;
}
