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

  // Exported permission: access s4 reporting
  $permissions['access s4 reporting'] = array(
    'name' => 'access s4 reporting',
    'roles' => array(
      0 => 'administrator',
      1 => 'staff',
    ),
    'module' => 's4_reporting',
  );

  // Exported permission: view assessment reports
  $permissions['view assessment reports'] = array(
    'name' => 'view assessment reports',
    'roles' => array(),
  );

  // Exported permission: xls export views
  $permissions['xls export views'] = array(
    'name' => 'xls export views',
    'roles' => array(
      0 => 'authenticated user',
    ),
    'module' => 'views_export_xls',
  );

  return $permissions;
}
