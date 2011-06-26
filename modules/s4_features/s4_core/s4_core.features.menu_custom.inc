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

  // Exported menu: menu-staff-options
  $menus['menu-staff-options'] = array(
    'menu_name' => 'menu-staff-options',
    'title' => 'Staff Options',
    'description' => 'Options for department staff and administrators.',
  );
  // Translatables
  // Included for use with string extractors like potx.
  t('Options for department staff and administrators.');
  t('Staff Options');


  return $menus;
}
