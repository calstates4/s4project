<?php
/**
 * @file
 * s4_courses.ds.inc
 */

/**
 * Implements hook_ds_field_settings_info().
 */
function s4_courses_ds_field_settings_info() {
  $export = array();

  $ds_fieldsetting = new stdClass();
  $ds_fieldsetting->api_version = 1;
  $ds_fieldsetting->id = 'node|course|default';
  $ds_fieldsetting->entity_type = 'node';
  $ds_fieldsetting->bundle = 'course';
  $ds_fieldsetting->view_mode = 'default';
  $ds_fieldsetting->settings = array(
    'course_students' => array(
      'weight' => '1',
      'label' => 'hidden',
      'format' => 'default',
    ),
  );
  $export['node|course|default'] = $ds_fieldsetting;

  return $export;
}

/**
 * Implements hook_ds_custom_fields_info().
 */
function s4_courses_ds_custom_fields_info() {
  $export = array();

  $ds_field = new stdClass();
  $ds_field->api_version = 1;
  $ds_field->field = 'course_students';
  $ds_field->label = 'Course students';
  $ds_field->field_type = 6;
  $ds_field->entities = array(
    'node' => 'node',
  );
  $ds_field->ui_limit = 'course|*';
  $ds_field->properties = array(
    'block' => 'views|course_students-block',
    'block_render' => '1',
  );
  $export['course_students'] = $ds_field;

  return $export;
}

/**
 * Implements hook_ds_layout_settings_info().
 */
function s4_courses_ds_layout_settings_info() {
  $export = array();

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'node|course|default';
  $ds_layout->entity_type = 'node';
  $ds_layout->bundle = 'course';
  $ds_layout->view_mode = 'default';
  $ds_layout->layout = 'ds_1col';
  $ds_layout->settings = array(
    'regions' => array(
      'ds_content' => array(
        0 => 'field_site_restrict_to_list',
        1 => 'course_students',
      ),
    ),
    'fields' => array(
      'field_site_restrict_to_list' => 'ds_content',
      'course_students' => 'ds_content',
    ),
    'classes' => array(),
    'wrappers' => array(
      'ds_content' => 'div',
    ),
    'layout_wrapper' => 'div',
    'layout_attributes' => '',
    'layout_attributes_merge' => 1,
  );
  $export['node|course|default'] = $ds_layout;

  return $export;
}
