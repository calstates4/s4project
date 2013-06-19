<?php
/**
 * @file
 * s4_opportunity.features.menu_links.inc
 */

/**
 * Implements hook_menu_default_menu_links().
 */
function s4_opportunity_menu_default_menu_links() {
  $menu_links = array();

  // Exported menu link: main-menu:opportunities
  $menu_links['main-menu:opportunities'] = array(
    'menu_name' => 'main-menu',
    'link_path' => 'opportunities',
    'router_path' => 'opportunities',
    'link_title' => 'Opportunities',
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
    'weight' => '-46',
  );
  // Translatables
  // Included for use with string extractors like potx.
  t('Opportunities');


  return $menu_links;
}
