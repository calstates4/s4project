<?php
/**
 * @file
 * s4_courses.features.menu_links.inc
 */

/**
 * Implementation of hook_menu_default_menu_links().
 */
function s4_courses_menu_default_menu_links() {
  $menu_links = array();

  // Exported menu link: main-menu:courses
  $menu_links['main-menu:courses'] = array(
    'menu_name' => 'main-menu',
    'link_path' => 'courses',
    'router_path' => 'courses',
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
