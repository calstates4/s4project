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

  // Exported permission: access active opportunities
  $permissions['access active opportunities'] = array(
    'name' => 'access active opportunities',
    'roles' => array(
      0 => 'anonymous user',
      1 => 'authenticated user',
    ),
    'module' => 's4_opportunity',
  );

  // Exported permission: access inactive opportunities
  $permissions['access inactive opportunities'] = array(
    'name' => 'access inactive opportunities',
    'roles' => array(),
  );

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

  // Exported permission: approve opportunities
  $permissions['approve opportunities'] = array(
    'name' => 'approve opportunities',
    'roles' => array(
      0 => 'opportunity approver',
    ),
    'module' => 's4_opportunity',
  );

  // Exported permission: place students in opportunities
  $permissions['place students in opportunities'] = array(
    'name' => 'place students in opportunities',
    'roles' => array(
      0 => 'opportunity manager',
    ),
    'module' => 's4_opportunity',
  );

  // Exported permission: start new opportunities
  $permissions['start new opportunities'] = array(
    'name' => 'start new opportunities',
    'roles' => array(
      0 => 'authenticated user',
    ),
    'module' => 's4_opportunity',
  );

  return $permissions;
}
