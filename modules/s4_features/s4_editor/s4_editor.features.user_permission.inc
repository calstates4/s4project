<?php
/**
 * @file
 * s4_editor.features.user_permission.inc
 */

/**
 * Implementation of hook_user_default_permissions().
 */
function s4_sites_user_default_permissions() {
  $permissions = array();

  // Exported permission: use text format filtered_html
  $permissions['use text format filtered_html'] = array(
    'name' => 'use text format filtered_html',
    'roles' => array(
      0 => 'authenticated user',
    ),
    'module' => 'filter',
  );

  return $permissions;
}