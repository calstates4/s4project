<?php
/**
 * @file
 * s4_courses.ds.inc
 */

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
  $ds_layout->layout = 's4_site';
  $ds_layout->settings = array(
    'hide_empty_regions' => 0,
    'hide_sidebars' => 0,
    'regions' => array(
      'left' => array(
        0 => 'field_sites',
      ),
      'right' => array(
        0 => 'field_course_department',
      ),
    ),
    'fields' => array(
      'field_sites' => 'left',
      'field_course_faculty' => 'right',
      'field_course_department' => 'right',
    ),
    'classes' => array(),
  );
  $export['node|course|default'] = $ds_layout;

  return $export;
}
