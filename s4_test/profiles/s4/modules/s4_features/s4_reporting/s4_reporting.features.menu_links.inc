<?php
/**
 * @file
 * s4_reporting.features.menu_links.inc
 */

/**
 * Implementation of hook_menu_default_menu_links().
 */
function s4_reporting_menu_default_menu_links() {
  $menu_links = array();

  // Exported menu link: main-menu:reports
  $menu_links['main-menu:reports'] = array(
    'menu_name' => 'main-menu',
    'link_path' => 'reports',
    'router_path' => 'reports',
    'link_title' => 'Reports',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
    ),
    'module' => 'menu',
    'hidden' => '0',
    'external' => '0',
    'has_children' => '0',
    'expanded' => '0',
    'weight' => '-48',
  );
  // Translatables
  // Included for use with string extractors like potx.
  t('Reports');


  return $menu_links;
}
