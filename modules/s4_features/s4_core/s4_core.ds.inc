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

  $ds_fieldsetting = new stdClass();
  $ds_fieldsetting->api_version = 1;
  $ds_fieldsetting->id = 'node|signup|default';
  $ds_fieldsetting->entity_type = 'node';
  $ds_fieldsetting->bundle = 'signup';
  $ds_fieldsetting->view_mode = 'default';
  $ds_fieldsetting->settings = array(
    'placement_opportunity' => array(
      'weight' => '5',
      'label' => 'hidden',
      'format' => 'default',
    ),
    'author' => array(
      'weight' => '6',
      'label' => 'above',
      'format' => 'author_linked',
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

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'node|signup|default';
  $ds_layout->entity_type = 'node';
  $ds_layout->bundle = 'signup';
  $ds_layout->view_mode = 'default';
  $ds_layout->layout = 'ds_2col';
  $ds_layout->settings = array(
    'regions' => array(
      'left' => array(
        0 => 'field_course',
        1 => 'field_site',
        2 => 'field_coordinator',
        3 => 'field_signup_location',
        4 => 's4_core_assessment_submission',
        5 => 'placement_opportunity',
      ),
      'right' => array(
        6 => 'author',
        7 => 'field_signup_hours',
        8 => 'field_signup_start_date',
        9 => 'field_signup_last_date',
        10 => 's4_core_evaluation_submission',
        11 => 's4_core_signup_submission',
      ),
    ),
    'fields' => array(
      'field_course' => 'left',
      'field_site' => 'left',
      'field_coordinator' => 'left',
      'field_signup_location' => 'left',
      's4_core_assessment_submission' => 'left',
      'placement_opportunity' => 'left',
      'author' => 'right',
      'field_signup_hours' => 'right',
      'field_signup_start_date' => 'right',
      'field_signup_last_date' => 'right',
      's4_core_evaluation_submission' => 'right',
      's4_core_signup_submission' => 'right',
    ),
    'classes' => array(),
    'wrappers' => array(
      'left' => 'div',
      'right' => 'div',
    ),
    'layout_wrapper' => 'div',
    'layout_attributes' => '',
    'layout_attributes_merge' => 1,
  );
  $export['node|signup|default'] = $ds_layout;

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'node|signup|full';
  $ds_layout->entity_type = 'node';
  $ds_layout->bundle = 'signup';
  $ds_layout->view_mode = 'full';
  $ds_layout->layout = 'ds_2col';
  $ds_layout->settings = array(
    'hide_empty_regions' => 0,
    'hide_sidebars' => 0,
    'regions' => array(
      'left' => array(
        0 => 'field_course',
        1 => 'field_site',
        2 => 'field_signup_location',
        3 => 'field_coordinator',
        4 => 's4_core_assessment_submission',
      ),
      'right' => array(
        0 => 'field_signup_hours',
        1 => 'field_signup_start_date',
        2 => 'field_signup_last_date',
        3 => 's4_core_signup_submission',
        4 => 's4_core_evaluation_submission',
      ),
    ),
    'fields' => array(
      'field_course' => 'left',
      'field_site' => 'left',
      'field_signup_location' => 'left',
      'field_coordinator' => 'left',
      's4_core_assessment_submission' => 'left',
      'field_signup_hours' => 'right',
      'field_signup_start_date' => 'right',
      'field_signup_last_date' => 'right',
      's4_core_signup_submission' => 'right',
      's4_core_evaluation_submission' => 'right',
    ),
    'classes' => array(),
  );
  $export['node|signup|full'] = $ds_layout;

  return $export;
}
