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
    'name' => array(
      'weight' => '2',
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
  $ds_layout->layout = 'ds_2col';
  $ds_layout->settings = array(
    'hide_empty_regions' => 0,
    'hide_sidebars' => 0,
    'regions' => array(
      'left' => array(
        0 => 'field_first_name',
        1 => 'field_last_name',
      ),
      'right' => array(
        0 => 'name',
        1 => 'field_sis_id',
        2 => 'field_site_restrict',
      ),
    ),
    'fields' => array(
      'field_first_name' => 'left',
      'field_last_name' => 'left',
      'name' => 'right',
      'field_sis_id' => 'right',
      'field_site_restrict' => 'right',
    ),
    'classes' => array(),
  );
  $export['user|user|default'] = $ds_layout;

  return $export;
}
