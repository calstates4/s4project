<?php
/**
 * @file
 * s4_core.features.menu_custom.inc
 */

/**
 * Implementation of hook_menu_default_menu_custom().
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
  // Exported menu: menu-staff-options
  $menus['menu-staff-options'] = array(
    'menu_name' => 'menu-staff-options',
    'title' => 'Staff Options',
    'description' => 'Options for department staff and administrators.',
  );
  // Translatables
  // Included for use with string extractors like potx.
  t('Add Content');
  t('Main menu');
  t('Options for department staff and administrators.');
  t('Staff Options');
  t('The <em>Main</em> menu is used on many sites to show the major sections of the site, often in a top navigation bar.');


  return $menus;
}
