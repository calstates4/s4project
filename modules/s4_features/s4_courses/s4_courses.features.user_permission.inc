<?php
/**
 * @file
 * s4_courses.features.user_permission.inc
 */

/**
 * Implements hook_user_default_permissions().
 */
function s4_courses_user_default_permissions() {
  $permissions = array();

  // Exported permission: create course content
  $permissions['create course content'] = array(
    'name' => 'create course content',
    'roles' => array(
      0 => 'administrator',
      1 => 'staff',
    ),
    'module' => 'node',
  );

  // Exported permission: create course_term content
  $permissions['create course_term content'] = array(
    'name' => 'create course_term content',
    'roles' => array(
      0 => 'administrator',
      1 => 'staff',
    ),
    'module' => 'node',
  );

  // Exported permission: delete any course content
  $permissions['delete any course content'] = array(
    'name' => 'delete any course content',
    'roles' => array(
      0 => 'administrator',
      1 => 'staff',
    ),
    'module' => 'node',
  );

  // Exported permission: delete any course_term content
  $permissions['delete any course_term content'] = array(
    'name' => 'delete any course_term content',
    'roles' => array(
      0 => 'administrator',
      1 => 'staff',
    ),
    'module' => 'node',
  );

  // Exported permission: delete own course content
  $permissions['delete own course content'] = array(
    'name' => 'delete own course content',
    'roles' => array(
      0 => 'administrator',
      1 => 'staff',
    ),
    'module' => 'node',
  );

  // Exported permission: delete own course_term content
  $permissions['delete own course_term content'] = array(
    'name' => 'delete own course_term content',
    'roles' => array(
      0 => 'administrator',
      1 => 'staff',
    ),
    'module' => 'node',
  );

  // Exported permission: edit any course content
  $permissions['edit any course content'] = array(
    'name' => 'edit any course content',
    'roles' => array(
      0 => 'administrator',
      1 => 'staff',
    ),
    'module' => 'node',
  );

  // Exported permission: edit any course_term content
  $permissions['edit any course_term content'] = array(
    'name' => 'edit any course_term content',
    'roles' => array(
      0 => 'administrator',
      1 => 'staff',
    ),
    'module' => 'node',
  );

  // Exported permission: edit own course content
  $permissions['edit own course content'] = array(
    'name' => 'edit own course content',
    'roles' => array(
      0 => 'administrator',
      1 => 'staff',
    ),
    'module' => 'node',
  );

  // Exported permission: edit own course_term content
  $permissions['edit own course_term content'] = array(
    'name' => 'edit own course_term content',
    'roles' => array(
      0 => 'administrator',
      1 => 'staff',
    ),
    'module' => 'node',
  );

  return $permissions;
}
