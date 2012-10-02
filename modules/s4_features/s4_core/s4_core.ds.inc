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
    'edit_signup_link' => array(
      'weight' => '0',
      'label' => 'hidden',
      'format' => 'default',
    ),
    'author' => array(
      'weight' => '0',
      'label' => 'above',
      'format' => 'author_linked',
    ),
  );
  $export['node|signup|default'] = $ds_fieldsetting;

  return $export;
}

/**
 * Implements hook_ds_custom_fields_info().
 */
function s4_core_ds_custom_fields_info() {
  $export = array();

  $ds_field = new stdClass();
  $ds_field->api_version = 1;
  $ds_field->field = 'edit_signup_link';
  $ds_field->label = 'Edit signup link';
  $ds_field->field_type = 6;
  $ds_field->entities = array(
    'node' => 'node',
  );
  $ds_field->properties = array(
    'block' => 's4_core|s4_signup_edit',
    'block_render' => '1',
  );
  $export['edit_signup_link'] = $ds_field;

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
    'hide_empty_regions' => 0,
    'hide_sidebars' => 0,
    'regions' => array(
      'right' => array(
        0 => 'edit_signup_link',
        1 => 'author',
        2 => 'field_signup_hours',
        3 => 'field_signup_start_date',
        4 => 'field_signup_last_date',
        5 => 's4_core_signup_submission',
        6 => 's4_core_evaluation_submission',
      ),
      'left' => array(
        0 => 'field_course',
        1 => 'field_site',
        2 => 'field_coordinator',
        3 => 'field_signup_location',
        4 => 's4_core_assessment_submission',
      ),
    ),
    'fields' => array(
      'edit_signup_link' => 'right',
      'author' => 'right',
      'field_course' => 'left',
      'field_site' => 'left',
      'field_coordinator' => 'left',
      'field_signup_location' => 'left',
      'field_signup_hours' => 'right',
      'field_signup_start_date' => 'right',
      'field_signup_last_date' => 'right',
      's4_core_signup_submission' => 'right',
      's4_core_assessment_submission' => 'left',
      's4_core_evaluation_submission' => 'right',
    ),
    'classes' => array(),
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
