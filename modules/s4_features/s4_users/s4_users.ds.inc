<?php
/**
 * @file
 * s4_users.ds.inc
 */

/**
 * Implements hook_ds_field_settings_info().
 */
function s4_users_ds_field_settings_info() {
  $export = array();

  $ds_fieldsetting = new stdClass();
  $ds_fieldsetting->api_version = 1;
  $ds_fieldsetting->id = 'user|user|default';
  $ds_fieldsetting->entity_type = 'user';
  $ds_fieldsetting->bundle = 'user';
  $ds_fieldsetting->view_mode = 'default';
  $ds_fieldsetting->settings = array(
    'user_current_courses' => array(
      'weight' => '0',
      'label' => 'hidden',
      'format' => 'default',
    ),
    'user_profile_placements' => array(
      'weight' => '1',
      'label' => 'hidden',
      'format' => 'default',
    ),
    'name' => array(
      'weight' => '4',
      'label' => 'inline',
      'format' => 'default',
      'formatter_settings' => array(
        'link' => '0',
        'wrapper' => '',
        'class' => '',
      ),
    ),
  );
  $export['user|user|default'] = $ds_fieldsetting;

  return $export;
}

/**
 * Implements hook_ds_custom_fields_info().
 */
function s4_users_ds_custom_fields_info() {
  $export = array();

  $ds_field = new stdClass();
  $ds_field->api_version = 1;
  $ds_field->field = 'user_current_courses';
  $ds_field->label = 'User current courses';
  $ds_field->field_type = 6;
  $ds_field->entities = array(
    'user' => 'user',
  );
  $ds_field->ui_limit = '';
  $ds_field->properties = array(
    'block' => 'views|user_courses-block_3',
    'block_render' => '1',
  );
  $export['user_current_courses'] = $ds_field;

  $ds_field = new stdClass();
  $ds_field->api_version = 1;
  $ds_field->field = 'user_profile_placements';
  $ds_field->label = 'User profile placements';
  $ds_field->field_type = 6;
  $ds_field->entities = array(
    'user' => 'user',
  );
  $ds_field->ui_limit = '';
  $ds_field->properties = array(
    'block' => 'views|s4_user_signups-block',
    'block_render' => '1',
  );
  $export['user_profile_placements'] = $ds_field;

  return $export;
}

/**
 * Implements hook_ds_layout_settings_info().
 */
function s4_users_ds_layout_settings_info() {
  $export = array();

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'user|user|default';
  $ds_layout->entity_type = 'user';
  $ds_layout->bundle = 'user';
  $ds_layout->view_mode = 'default';
  $ds_layout->layout = 's4_75_25';
  $ds_layout->settings = array(
    'regions' => array(
      'left' => array(
        0 => 'user_current_courses',
        1 => 'user_profile_placements',
      ),
      'right' => array(
        2 => 'field_first_name',
        3 => 'field_last_name',
        4 => 'name',
        5 => 'field_sis_id',
        6 => 'field_site_restrict',
        7 => 'field_program_default',
      ),
    ),
    'fields' => array(
      'user_current_courses' => 'left',
      'user_profile_placements' => 'left',
      'field_first_name' => 'right',
      'field_last_name' => 'right',
      'name' => 'right',
      'field_sis_id' => 'right',
      'field_site_restrict' => 'right',
      'field_program_default' => 'right',
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
  $export['user|user|default'] = $ds_layout;

  return $export;
}
