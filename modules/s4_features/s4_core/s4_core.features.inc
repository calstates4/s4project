<?php
/**
 * @file
 * s4_core.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function s4_core_ctools_plugin_api() {
  list($module, $api) = func_get_args();
  if ($module == "context") {
    return array("version" => "3");
  }
  list($module, $api) = func_get_args();
  if ($module == "ds") {
    return array("version" => "1");
  }
  list($module, $api) = func_get_args();
  if ($module == "field_group") {
    return array("version" => "1");
  }
  list($module, $api) = func_get_args();
  if ($module == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_views_api().
 */
function s4_core_views_api() {
  list($module, $api) = func_get_args();
  if ($module == "views") {
    return array("version" => "3.0");
  }
}

/**
 * Implements hook_node_info().
 */
function s4_core_node_info() {
  $items = array(
    'downloadable_form' => array(
      'name' => t('Downloadable form'),
      'base' => 'node_content',
      'description' => t('A paper form for users to download.'),
      'has_title' => '1',
      'title_label' => t('Form name'),
      'help' => '',
    ),
    'page' => array(
      'name' => t('Basic page'),
      'base' => 'node_content',
      'description' => t('Basic pages are for generic content like help pages.'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => t('Basic pages are for generic content like "About Us" or documentation.'),
    ),
    'signup' => array(
      'name' => t('Placement'),
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
