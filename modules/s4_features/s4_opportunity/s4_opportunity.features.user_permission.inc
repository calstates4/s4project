<?php
/**
 * @file
 * s4_opportunity.features.user_permission.inc
 */

/**
 * Implements hook_user_default_permissions().
 */
function s4_opportunity_user_default_permissions() {
  $permissions = array();

  // Exported permission: administer opportunities
  $permissions['administer opportunities'] = array(
    'name' => 'administer opportunities',
    'roles' => array(
      0 => 'opportunity manager',
    ),
    'module' => 's4_opportunity',
  );

  // Exported permission: administer s4_opportunity types
  $permissions['administer s4_opportunity types'] = array(
    'name' => 'administer s4_opportunity types',
    'roles' => array(
      0 => 'opportunity manager',
    ),
    'module' => 's4_opportunity',
  );

  return $permissions;
}
