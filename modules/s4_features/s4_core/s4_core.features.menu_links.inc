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
    'weight' => '-42',
  );
  // Exported menu link: main-menu:forms
  $menu_links['main-menu:forms'] = array(
    'menu_name' => 'main-menu',
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
    'weight' => '-46',
  );
  // Exported menu link: main-menu:forms/public
  $menu_links['main-menu:forms/public'] = array(
    'menu_name' => 'main-menu',
    'link_path' => 'forms/public',
    'router_path' => 'forms/public',
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
    'weight' => '-45',
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
  // Exported menu link: main-menu:students
  $menu_links['main-menu:students'] = array(
    'menu_name' => 'main-menu',
    'link_path' => 'students',
    'router_path' => 'students',
    'link_title' => 'Students',
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
  // Translatables
  // Included for use with string extractors like potx.
  t('Forms');
  t('Home');
  t('Logout');
  t('Reports');
  t('Site or Community Partner');
  t('Students');


  return $menu_links;
}
