<?php
/**
 * @file
 * s4_core.features.menu_custom.inc
 */

/**
 * Implements hook_menu_default_menu_custom().
 */
function s4_core_menu_default_menu_custom() {
  $menus = array();

  // Exported menu: main-menu
  $menus['main-menu'] = array(
    'menu_name' => 'main-menu',
    'title' => 'Main menu',
    'description' => 'The <em>Main</em> menu is used on many sites to show the major sections of the site, often in a top navigation bar.',
  );
  // Exported menu: menu-add-content
  $menus['menu-add-content'] = array(
    'menu_name' => 'menu-add-content',
    'title' => 'Add Content',
    'description' => '',
  );
  // Translatables
  // Included for use with string extractors like potx.
  t('Add Content');
  t('Main menu');
  t('The <em>Main</em> menu is used on many sites to show the major sections of the site, often in a top navigation bar.');


  return $menus;
}
