<?php
/**
 * @file
 * s4_reporting.features.user_permission.inc
 */

/**
 * Implements hook_user_default_permissions().
 */
function s4_reporting_user_default_permissions() {
  $permissions = array();

  // Exported permission: view assessment reports
  $permissions['view assessment reports'] = array(
    'name' => 'view assessment reports',
    'roles' => array(),
  );

  return $permissions;
}
