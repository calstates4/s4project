<?php
/**
 * @file
 * s4_core.features.menu_links.inc
 */

/**
 * Implementation of hook_menu_default_menu_links().
 */
function s4_core_menu_default_menu_links() {
  $menu_links = array();

  // Exported menu link: main-menu:<front>
  $menu_links['main-menu:<front>'] = array(
    'menu_name' => 'main-menu',
    'link_path' => '<front>',
    'router_path' => '',
    'link_title' => 'Home',
    'options' => array(),
    'module' => 'menu',
    'hidden' => '0',
    'external' => '1',
    'has_children' => '0',
    'expanded' => '0',
    'weight' => '-44',
  );
  // Exported menu link: main-menu:dashboard
  $menu_links['main-menu:dashboard'] = array(
    'menu_name' => 'main-menu',
    'link_path' => 'dashboard',
    'router_path' => 'dashboard',
    'link_title' => 'Dashboard',
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
    'weight' => '-49',
  );
  // Exported menu link: main-menu:user/logout
  $menu_links['main-menu:user/logout'] = array(
    'menu_name' => 'main-menu',
    'link_path' => 'user/logout',
    'router_path' => 'user/logout',
    'link_title' => 'Logout',
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
    'weight' => '-50',
  );
  // Exported menu link: menu-staff-options:admin/appearance/settings/s4
  $menu_links['menu-staff-options:admin/appearance/settings/s4'] = array(
    'menu_name' => 'menu-staff-options',
    'link_path' => 'admin/appearance/settings/s4',
    'router_path' => 'admin/appearance/settings/s4',
    'link_title' => 'Change colors',
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
    'weight' => '-47',
  );
  // Exported menu link: menu-staff-options:email/sites
  $menu_links['menu-staff-options:email/sites'] = array(
    'menu_name' => 'menu-staff-options',
    'link_path' => 'email/sites',
    'router_path' => 'email',
    'link_title' => 'Send emails',
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
    'weight' => '-49',
  );
  // Exported menu link: menu-staff-options:forms
  $menu_links['menu-staff-options:forms'] = array(
    'menu_name' => 'menu-staff-options',
    'link_path' => 'forms',
    'router_path' => 'forms',
    'link_title' => 'Forms',
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
  // Exported menu link: menu-staff-options:map
  $menu_links['menu-staff-options:map'] = array(
    'menu_name' => 'menu-staff-options',
    'link_path' => 'map',
    'router_path' => 'map',
    'link_title' => 'Map',
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
  // Exported menu link: menu-staff-options:reports
  $menu_links['menu-staff-options:reports'] = array(
    'menu_name' => 'menu-staff-options',
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
    'weight' => '-50',
  );
  // Translatables
  // Included for use with string extractors like potx.
  t('Change colors');
  t('Dashboard');
  t('Forms');
  t('Home');
  t('Logout');
  t('Map');
  t('Reports');
  t('Send emails');


  return $menu_links;
}
