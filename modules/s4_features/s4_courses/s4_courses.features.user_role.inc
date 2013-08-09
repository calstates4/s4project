<?php
/**
 * @file
 * s4_courses.features.user_role.inc
 */

/**
 * Implements hook_user_default_roles().
 */
function s4_courses_user_default_roles() {
  $roles = array();

  // Exported role: faculty
  $roles['faculty'] = array(
    'name' => 'faculty',
    'weight' => '11',
  );

  // Exported role: super faculty
  $roles['super faculty'] = array(
    'name' => 'super faculty',
    'weight' => '8',
  );

  return $roles;
}
