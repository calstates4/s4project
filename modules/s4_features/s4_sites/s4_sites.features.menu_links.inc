<?php
/**
 * @file
 * s4_sites.features.menu_links.inc
 */

/**
 * Implements hook_menu_default_menu_links().
 */
function s4_sites_menu_default_menu_links() {
  $menu_links = array();

  // Exported menu link: main-menu:site
  $menu_links['main-menu:site'] = array(
    'menu_name' => 'main-menu',
    'link_path' => 'site',
    'router_path' => 'site',
    'link_title' => 'Sites',
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
    'weight' => '-44',
  );
  // Translatables
  // Included for use with string extractors like potx.
  t('Sites');


  return $menu_links;
}
