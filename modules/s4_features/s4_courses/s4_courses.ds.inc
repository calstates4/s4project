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
    'course_faculty_list' => array(
      'weight' => '2',
      'label' => 'above',
      'format' => 'default',
    ),
    'course_settings' => array(
      'weight' => '1',
      'label' => 'hidden',
      'format' => 'default',
    ),
    'course_students' => array(
      'weight' => '0',
      'label' => 'hidden',
      'format' => 'default',
    ),
  );
  $export['node|course|default'] = $ds_fieldsetting;

  $ds_fieldsetting = new stdClass();
  $ds_fieldsetting->api_version = 1;
  $ds_fieldsetting->id = 'node|course|full';
  $ds_fieldsetting->entity_type = 'node';
  $ds_fieldsetting->bundle = 'course';
  $ds_fieldsetting->view_mode = 'full';
  $ds_fieldsetting->settings = array(
    'course_settings' => array(
      'weight' => '0',
      'label' => 'hidden',
      'format' => 'default',
    ),
    'course_students' => array(
      'weight' => '0',
      'label' => 'hidden',
      'format' => 'default',
    ),
  );
  $export['node|course|full'] = $ds_fieldsetting;

  return $export;
}

/**
 * Implements hook_ds_custom_fields_info().
 */
function s4_courses_ds_custom_fields_info() {
  $export = array();

  $ds_field = new stdClass();
  $ds_field->api_version = 1;
  $ds_field->field = 'course_faculty_list';
  $ds_field->label = 'Faculty';
  $ds_field->field_type = 6;
  $ds_field->entities = array(
    'node' => 'node',
  );
  $ds_field->ui_limit = 'course|*';
  $ds_field->properties = array(
    'block' => 'views|course_students-block_2',
    'block_render' => '1',
  );
  $export['course_faculty_list'] = $ds_field;

  $ds_field = new stdClass();
  $ds_field->api_version = 1;
  $ds_field->field = 'course_settings';
  $ds_field->label = 'Course settings';
  $ds_field->field_type = 6;
  $ds_field->entities = array(
    'node' => 'node',
  );
  $ds_field->ui_limit = 'course|*';
  $ds_field->properties = array(
    'block' => 's4_courses|s4_courses_restriction_form',
    'block_render' => '1',
  );
  $export['course_settings'] = $ds_field;

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
  $ds_layout->layout = 's4_75_25';
  $ds_layout->settings = array(
    'regions' => array(
      'left' => array(
        0 => 'course_students',
      ),
      'right' => array(
        1 => 'course_settings',
        2 => 'course_faculty_list',
        3 => 'field_sites',
        4 => 'field_course_department',
        5 => 'field_max_placements',
        6 => 'field_site_restrict',
      ),
    ),
    'fields' => array(
      'course_students' => 'left',
      'course_settings' => 'right',
      'course_faculty_list' => 'right',
      'field_sites' => 'right',
      'field_course_department' => 'right',
      'field_max_placements' => 'right',
      'field_site_restrict' => 'right',
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
  $export['node|course|default'] = $ds_layout;

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'node|course|full';
  $ds_layout->entity_type = 'node';
  $ds_layout->bundle = 'course';
  $ds_layout->view_mode = 'full';
  $ds_layout->layout = 's4_75_25';
  $ds_layout->settings = array(
    'regions' => array(
      'right' => array(
        0 => 'course_settings',
        2 => 'field_sites',
        3 => 'field_course_faculty',
        4 => 'field_course_department',
        5 => 'field_max_placements',
        6 => 'field_site_restrict',
      ),
      'left' => array(
        1 => 'course_students',
      ),
    ),
    'fields' => array(
      'course_settings' => 'right',
      'course_students' => 'left',
      'field_sites' => 'right',
      'field_course_faculty' => 'right',
      'field_course_department' => 'right',
      'field_max_placements' => 'right',
      'field_site_restrict' => 'right',
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
  $export['node|course|full'] = $ds_layout;

  return $export;
}
