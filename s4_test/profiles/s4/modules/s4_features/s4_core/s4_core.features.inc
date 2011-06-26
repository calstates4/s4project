<?php
/**
 * @file
 * s4_core.features.inc
 */

/**
 * Implementation of hook_ctools_plugin_api().
 */
function s4_core_ctools_plugin_api() {
  list($module, $api) = func_get_args();
  if ($module == "boxes" && $api == "box") {
    return array("version" => "1");
  }
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
function s4_core_node_info() {
  $items = array(
    'page' => array(
      'name' => t('Basic page'),
      'base' => 'node_content',
      'description' => t('Basic pages are for generic content like help pages.'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => t('Basic pages are for generic content like "About Us" or documentation.'),
    ),
    'signup' => array(
      'name' => t('Signup'),
      'base' => 'node_content',
      'description' => t('A signup is a record of a student signing up for a site.'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
    'webform' => array(
      'name' => t('Webform'),
      'base' => 'node_content',
      'description' => t('Create a new form or questionnaire accessible to users. Submission results and statistics are recorded and accessible to privileged users.'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  return $items;
}
