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
 * Implementation of hook_views_api().
 */
function s4_core_views_api() {
  list($module, $api) = func_get_args();
  if ($module == "views" && $api == "views_default") {
    return array("version" => "3.0");
  }
}

/**
 * Implementation of hook_homebox().
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
        'weight' => -59,
      ),
      'views_site_moderation-block' => 
      array (
        'module' => 'views',
        'delta' => 'site_moderation-block',
        'region' => 1,
        'movable' => 1,
        'status' => 1,
        'open' => 1,
        'closable' => 1,
        'title' => '',
        'weight' => -54,
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
        'weight' => -58,
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
        'weight' => -54,
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
        'weight' => -57,
      ),
      's4_reporting_site_summary' => 
      array (
        'module' => 's4_reporting',
        'delta' => 'site_summary',
        'region' => 2,
        'movable' => 1,
        'status' => 1,
        'open' => 1,
        'closable' => 1,
        'title' => '',
        'weight' => -59,
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
