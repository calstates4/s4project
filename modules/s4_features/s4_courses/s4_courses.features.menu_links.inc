<?php
/**
 * @file
 * s4_courses.features.menu_links.inc
 */

/**
 * Implements hook_menu_default_menu_links().
 */
function s4_courses_menu_default_menu_links() {
  $menu_links = array();

  // Exported menu link: main-menu:courses/manage
  $menu_links['main-menu:courses/manage'] = array(
    'menu_name' => 'main-menu',
    'link_path' => 'courses/manage',
    'router_path' => 'courses/manage',
    'link_title' => 'Courses',
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
  // Translatables
  // Included for use with string extractors like potx.
  t('Courses');


  return $menu_links;
}
