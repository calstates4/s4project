<?php
/**
 * @file
 * s4_fieldtrip.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function s4_fieldtrip_ctools_plugin_api() {
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
 * Implements hook_views_api().
 */
function s4_fieldtrip_views_api() {
  return array("version" => "3.0");
}

/**
 * Implements hook_node_info().
 */
function s4_fieldtrip_node_info() {
  $items = array(
    'fieldtrip' => array(
      'name' => t('Field trip'),
      'base' => 'node_content',
      'description' => t('A field trip for a course.'),
      'has_title' => '1',
      'title_label' => t('Field trip name'),
      'help' => '',
    ),
  );
  return $items;
}
