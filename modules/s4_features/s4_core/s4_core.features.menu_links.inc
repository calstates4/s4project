<?php
/**
 * @file
 * s4_core.features.menu_links.inc
 */

/**
 * Implements hook_menu_default_menu_links().
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
    'weight' => '-43',
  );
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
  // Exported menu link: main-menu:users
  $menu_links['main-menu:users'] = array(
    'menu_name' => 'main-menu',
    'link_path' => 'users',
    'router_path' => 'users',
    'link_title' => 'Users',
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
    'weight' => '-45',
  );
  // Exported menu link: menu-add-content:node/add/site
  $menu_links['menu-add-content:node/add/site'] = array(
    'menu_name' => 'menu-add-content',
    'link_path' => 'node/add/site',
    'router_path' => 'node/add/site',
    'link_title' => 'Site or Community Partner',
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
    'weight' => '0',
  );
  // Exported menu link: menu-staff-actions:admin/structure/taxonomy/site_restrictions
  $menu_links['menu-staff-actions:admin/structure/taxonomy/site_restrictions'] = array(
    'menu_name' => 'menu-staff-actions',
    'link_path' => 'admin/structure/taxonomy/site_restrictions',
    'router_path' => 'admin/structure/taxonomy/%',
    'link_title' => 'Manage programs',
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
    'weight' => '-45',
  );
  // Exported menu link: menu-staff-actions:node/add/downloadable-form
  $menu_links['menu-staff-actions:node/add/downloadable-form'] = array(
    'menu_name' => 'menu-staff-actions',
    'link_path' => 'node/add/downloadable-form',
    'router_path' => 'node/add/downloadable-form',
    'link_title' => 'Add a new downloadable form',
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
  // Exported menu link: menu-staff-actions:node/add/site
  $menu_links['menu-staff-actions:node/add/site'] = array(
    'menu_name' => 'menu-staff-actions',
    'link_path' => 'node/add/site',
    'router_path' => 'node/add/site',
    'link_title' => 'Add a new site',
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
  // Exported menu link: menu-staff-actions:node/add/webform
  $menu_links['menu-staff-actions:node/add/webform'] = array(
    'menu_name' => 'menu-staff-actions',
    'link_path' => 'node/add/webform',
    'router_path' => 'node/add/webform',
    'link_title' => 'Add a new online form',
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
  // Exported menu link: menu-staff-actions:s4/settings
  $menu_links['menu-staff-actions:s4/settings'] = array(
    'menu_name' => 'menu-staff-actions',
    'link_path' => 's4/settings',
    'router_path' => 's4/settings',
    'link_title' => 'Change settings',
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
  // Exported menu link: menu-staff-actions:site-list/manage
  $menu_links['menu-staff-actions:site-list/manage'] = array(
    'menu_name' => 'menu-staff-actions',
    'link_path' => 'site-list/manage',
    'router_path' => 'site-list/manage',
    'link_title' => 'Manage sites',
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
  // Translatables
  // Included for use with string extractors like potx.
  t('Add a new downloadable form');
  t('Add a new online form');
  t('Add a new site');
  t('Change settings');
  t('Home');
  t('Logout');
  t('Manage programs');
  t('Manage sites');
  t('Reports');
  t('Site or Community Partner');
  t('Users');


  return $menu_links;
}
