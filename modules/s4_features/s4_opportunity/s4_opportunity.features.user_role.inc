<?php
/**
 * @file
 * s4_opportunity.features.user_role.inc
 */

/**
 * Implements hook_user_default_roles().
 */
function s4_opportunity_user_default_roles() {
  $roles = array();

  // Exported role: opportunity approver
  $roles['opportunity approver'] = array(
    'name' => 'opportunity approver',
    'weight' => '10',
  );

  // Exported role: opportunity manager
  $roles['opportunity manager'] = array(
    'name' => 'opportunity manager',
    'weight' => '9',
  );

  return $roles;
}
