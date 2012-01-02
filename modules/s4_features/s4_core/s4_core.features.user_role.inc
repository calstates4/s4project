<?php
/**
 * @file
 * s4_core.features.user_role.inc
 */

/**
 * Implements hook_user_default_roles().
 */
function s4_core_user_default_roles() {
  $roles = array();

  // Exported role: administrator
  $roles['administrator'] = array(
    'name' => 'administrator',
    'weight' => '2',
  );

  // Exported role: staff
  $roles['staff'] = array(
    'name' => 'staff',
    'weight' => '4',
  );

  return $roles;
}
