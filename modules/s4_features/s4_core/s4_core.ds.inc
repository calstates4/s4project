<?php
/**
 * @file
 * s4_core.ds.inc
 */

/**
 * Implements hook_ds_field_settings_info().
 */
function s4_core_ds_field_settings_info() {
  $export = array();

  $ds_fieldsetting = new stdClass;
  $ds_fieldsetting->api_version = 1;
  $ds_fieldsetting->id = 'node|signup|default';
  $ds_fieldsetting->entity_type = 'node';
  $ds_fieldsetting->bundle = 'signup';
  $ds_fieldsetting->view_mode = 'default';
  $ds_fieldsetting->settings = array(
    'post_date' => array(
      'weight' => '3',
      'label' => 'hidden',
      'format' => 'ds_post_date_long',
    ),
  );
  $export['node|signup|default'] = $ds_fieldsetting;

  return $export;
}

/**
 * Implements hook_ds_layout_settings_info().
 */
function s4_core_ds_layout_settings_info() {
  $export = array();

  $ds_layout = new stdClass;
  $ds_layout->api_version = 1;
  $ds_layout->id = 'node|signup|default';
  $ds_layout->entity_type = 'node';
  $ds_layout->bundle = 'signup';
  $ds_layout->view_mode = 'default';
  $ds_layout->layout = 's4_site';
  $ds_layout->settings = array(
    'hide_empty_regions' => 0,
    'hide_sidebars' => 0,
    'regions' => array(
      'left' => array(
        0 => 'field_site',
        1 => 'field_coordinator',
        2 => 'field_signup_location',
      ),
      'right' => array(
        0 => 'post_date',
        1 => 'field_course',
        2 => 'field_signup_hours',
        3 => 'field_signup_start_date',
        4 => 'field_signup_last_date',
      ),
    ),
    'fields' => array(
      'field_site' => 'left',
      'field_coordinator' => 'left',
      'field_signup_location' => 'left',
      'post_date' => 'right',
      'field_course' => 'right',
      'field_signup_hours' => 'right',
      'field_signup_start_date' => 'right',
      'field_signup_last_date' => 'right',
    ),
    'classes' => array(),
  );
  $export['node|signup|default'] = $ds_layout;

  return $export;
}