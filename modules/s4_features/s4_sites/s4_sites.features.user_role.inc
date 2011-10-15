<?php
/**
 * @file
 * s4_sites.features.user_role.inc
 */

/**
 * Implementation of hook_user_default_roles().
 */
function s4_sites_user_default_roles() {
  $roles = array();

  // Exported role: site approver
  $roles['site approver'] = array(
    'name' => 'site approver',
    'weight' => '6',
  );

  return $roles;
}
