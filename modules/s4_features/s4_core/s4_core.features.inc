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
  if ($module == "context" && $api == "context") {
    return array("version" => "3");
  }
  list($module, $api) = func_get_args();
  if ($module == "ds" && $api == "ds") {
    return array("version" => "1");
  }
  list($module, $api) = func_get_args();
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_views_api().
 */
function s4_core_views_api() {
  return array("version" => "3.0");
}

/**
 * Implements hook_homebox().
 */
function s4_core_homebox() {
  $homeboxes = array();

  $homeboxes['home'] = array (
    'regions' => 2,
    'cache' => 0,
    'color' => 0,
    'colors' => 
    array (
      0 => '#E4F0F8',
      1 => '#E4F0F8',
      2 => '#E4F0F8',
      3 => '#E4F0F8',
      4 => '#E4F0F8',
      5 => '#E4F0F8',
    ),
    'blocks' => 
    array (
      's4_reporting_course_summary' => 
      array (
        'module' => 's4_reporting',
        'delta' => 'course_summary',
        'region' => 2,
        'movable' => 1,
        'status' => 1,
        'open' => 1,
        'closable' => 1,
        'title' => '',
        'weight' => -48,
      ),
      'masquerade_masquerade' => 
      array (
        'module' => 'masquerade',
        'delta' => 'masquerade',
        'region' => 2,
        'movable' => 1,
        'status' => 1,
        'open' => 1,
        'closable' => 1,
        'title' => '',
        'weight' => -48,
      ),
      's4_reporting_site_summary' => 
      array (
        'module' => 's4_reporting',
        'delta' => 'site_summary',
        'region' => 1,
        'movable' => 1,
        'status' => 1,
        'open' => 1,
        'closable' => 1,
        'title' => '',
        'weight' => -48,
      ),
      'views_bookmarked_sites-block' => 
      array (
        'module' => 'views',
        'delta' => 'bookmarked_sites-block',
        'region' => 2,
        'movable' => 1,
        'status' => 1,
        'open' => 1,
        'closable' => 1,
        'title' => '',
        'weight' => -48,
      ),
      'views_65656e1f5a12cde25f0722f735fe7969' => 
      array (
        'module' => 'views',
        'delta' => '65656e1f5a12cde25f0722f735fe7969',
        'region' => 2,
        'movable' => 1,
        'status' => 1,
        'open' => 1,
        'closable' => 1,
        'title' => '',
        'weight' => -48,
      ),
      'views_manage_sites-block_1' => 
      array (
        'module' => 'views',
        'delta' => 'manage_sites-block_1',
        'region' => 1,
        'movable' => 1,
        'status' => 1,
        'open' => 1,
        'closable' => 1,
        'title' => '',
        'weight' => -47,
      ),
      'views_recent_activity-block' => 
      array (
        'module' => 'views',
        'delta' => 'recent_activity-block',
        'region' => 1,
        'movable' => 1,
        'status' => 1,
        'open' => 1,
        'closable' => 1,
        'title' => '',
        'weight' => -46,
      ),
    ),
    'widths' => 
    array (
    ),
    'title' => 'Home',
    'path' => 'home',
    'menu' => 0,
    'enabled' => 1,
    'auto_save' => 1,
    'full' => 0,
    'roles' => 
    array (
      0 => 'authenticated user',
    ),
  );


  return $homeboxes;
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
