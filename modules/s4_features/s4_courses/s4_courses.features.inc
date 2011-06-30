<?php
/**
 * @file
 * s4_courses.features.inc
 */

/**
 * Implementation of hook_ctools_plugin_api().
 */
function s4_courses_ctools_plugin_api() {
  list($module, $api) = func_get_args();
  if ($module == "context" && $api == "context") {
    return array("version" => "3");
  }
  list($module, $api) = func_get_args();
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implementation of hook_node_info().
 */
function s4_courses_node_info() {
  $items = array(
    'course' => array(
      'name' => t('Course'),
      'base' => 'node_content',
      'description' => t('A course is a collection of students and faculty, useful to restrict access to certain sites or only allow students assigned to a course to register with a site.'),
      'has_title' => '1',
      'title_label' => t('Course Name'),
      'help' => '',
    ),
    'course_term' => array(
      'name' => t('Course Term'),
      'base' => 'node_content',
      'description' => t('A course term is a semester, quarter, etc. that courses reference.'),
      'has_title' => '1',
      'title_label' => t('Term Name'),
      'help' => '',
    ),
  );
  return $items;
}
