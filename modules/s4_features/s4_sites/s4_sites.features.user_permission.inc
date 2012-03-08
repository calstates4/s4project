<?php
/**
 * @file
 * s4_sites.features.user_permission.inc
 */

/**
 * Implements hook_user_default_permissions().
 */
function s4_sites_user_default_permissions() {
  $permissions = array();

  // Exported permission: access workbench
  $permissions['access workbench'] = array(
    'name' => 'access workbench',
    'roles' => array(),
  );

  // Exported permission: administer workbench moderation
  $permissions['administer workbench moderation'] = array(
    'name' => 'administer workbench moderation',
    'roles' => array(),
  );

  // Exported permission: bypass workbench moderation
  $permissions['bypass workbench moderation'] = array(
    'name' => 'bypass workbench moderation',
    'roles' => array(),
  );

  // Exported permission: create contact_record content
  $permissions['create contact_record content'] = array(
    'name' => 'create contact_record content',
    'roles' => array(
      0 => 'staff',
    ),
    'module' => 'node',
  );

  // Exported permission: create coordinator content
  $permissions['create coordinator content'] = array(
    'name' => 'create coordinator content',
    'roles' => array(
      0 => 'authenticated user',
      1 => 'staff',
    ),
    'module' => 'node',
  );

  // Exported permission: create file content
  $permissions['create file content'] = array(
    'name' => 'create file content',
    'roles' => array(
      0 => 'staff',
    ),
    'module' => 'node',
  );

  // Exported permission: create site content
  $permissions['create site content'] = array(
    'name' => 'create site content',
    'roles' => array(
      0 => 'anonymous user',
      1 => 'authenticated user',
      2 => 'staff',
    ),
    'module' => 'node',
  );

  // Exported permission: delete any contact_record content
  $permissions['delete any contact_record content'] = array(
    'name' => 'delete any contact_record content',
    'roles' => array(
      0 => 'staff',
    ),
    'module' => 'node',
  );

  // Exported permission: delete any coordinator content
  $permissions['delete any coordinator content'] = array(
    'name' => 'delete any coordinator content',
    'roles' => array(
      0 => 'staff',
    ),
    'module' => 'node',
  );

  // Exported permission: delete any file content
  $permissions['delete any file content'] = array(
    'name' => 'delete any file content',
    'roles' => array(
      0 => 'staff',
    ),
    'module' => 'node',
  );

  // Exported permission: delete any site content
  $permissions['delete any site content'] = array(
    'name' => 'delete any site content',
    'roles' => array(
      0 => 'staff',
    ),
    'module' => 'node',
  );

  // Exported permission: delete own contact_record content
  $permissions['delete own contact_record content'] = array(
    'name' => 'delete own contact_record content',
    'roles' => array(
      0 => 'staff',
    ),
    'module' => 'node',
  );

  // Exported permission: delete own coordinator content
  $permissions['delete own coordinator content'] = array(
    'name' => 'delete own coordinator content',
    'roles' => array(
      0 => 'staff',
    ),
    'module' => 'node',
  );

  // Exported permission: delete own file content
  $permissions['delete own file content'] = array(
    'name' => 'delete own file content',
    'roles' => array(
      0 => 'staff',
    ),
    'module' => 'node',
  );

  // Exported permission: delete own site content
  $permissions['delete own site content'] = array(
    'name' => 'delete own site content',
    'roles' => array(),
  );

  // Exported permission: delete terms in 1
  $permissions['delete terms in 1'] = array(
    'name' => 'delete terms in 1',
    'roles' => array(),
  );

  // Exported permission: delete terms in 10
  $permissions['delete terms in 10'] = array(
    'name' => 'delete terms in 10',
    'roles' => array(),
  );

  // Exported permission: delete terms in 11
  $permissions['delete terms in 11'] = array(
    'name' => 'delete terms in 11',
    'roles' => array(),
  );

  // Exported permission: delete terms in 2
  $permissions['delete terms in 2'] = array(
    'name' => 'delete terms in 2',
    'roles' => array(),
  );

  // Exported permission: delete terms in 3
  $permissions['delete terms in 3'] = array(
    'name' => 'delete terms in 3',
    'roles' => array(),
  );

  // Exported permission: delete terms in 4
  $permissions['delete terms in 4'] = array(
    'name' => 'delete terms in 4',
    'roles' => array(),
  );

  // Exported permission: delete terms in 5
  $permissions['delete terms in 5'] = array(
    'name' => 'delete terms in 5',
    'roles' => array(),
  );

  // Exported permission: delete terms in 6
  $permissions['delete terms in 6'] = array(
    'name' => 'delete terms in 6',
    'roles' => array(),
  );

  // Exported permission: delete terms in 7
  $permissions['delete terms in 7'] = array(
    'name' => 'delete terms in 7',
    'roles' => array(),
  );

  // Exported permission: delete terms in 8
  $permissions['delete terms in 8'] = array(
    'name' => 'delete terms in 8',
    'roles' => array(),
  );

  // Exported permission: delete terms in 9
  $permissions['delete terms in 9'] = array(
    'name' => 'delete terms in 9',
    'roles' => array(),
  );

  // Exported permission: edit any contact_record content
  $permissions['edit any contact_record content'] = array(
    'name' => 'edit any contact_record content',
    'roles' => array(
      0 => 'staff',
    ),
    'module' => 'node',
  );

  // Exported permission: edit any coordinator content
  $permissions['edit any coordinator content'] = array(
    'name' => 'edit any coordinator content',
    'roles' => array(
      0 => 'staff',
    ),
    'module' => 'node',
  );

  // Exported permission: edit any file content
  $permissions['edit any file content'] = array(
    'name' => 'edit any file content',
    'roles' => array(
      0 => 'staff',
    ),
    'module' => 'node',
  );

  // Exported permission: edit any site content
  $permissions['edit any site content'] = array(
    'name' => 'edit any site content',
    'roles' => array(
      0 => 'staff',
    ),
    'module' => 'node',
  );

  // Exported permission: edit own contact_record content
  $permissions['edit own contact_record content'] = array(
    'name' => 'edit own contact_record content',
    'roles' => array(
      0 => 'staff',
    ),
    'module' => 'node',
  );

  // Exported permission: edit own coordinator content
  $permissions['edit own coordinator content'] = array(
    'name' => 'edit own coordinator content',
    'roles' => array(
      0 => 'staff',
    ),
    'module' => 'node',
  );

  // Exported permission: edit own file content
  $permissions['edit own file content'] = array(
    'name' => 'edit own file content',
    'roles' => array(
      0 => 'staff',
    ),
    'module' => 'node',
  );

  // Exported permission: edit own site content
  $permissions['edit own site content'] = array(
    'name' => 'edit own site content',
    'roles' => array(),
  );

  // Exported permission: edit terms in 1
  $permissions['edit terms in 1'] = array(
    'name' => 'edit terms in 1',
    'roles' => array(),
  );

  // Exported permission: edit terms in 10
  $permissions['edit terms in 10'] = array(
    'name' => 'edit terms in 10',
    'roles' => array(),
  );

  // Exported permission: edit terms in 11
  $permissions['edit terms in 11'] = array(
    'name' => 'edit terms in 11',
    'roles' => array(),
  );

  // Exported permission: edit terms in 2
  $permissions['edit terms in 2'] = array(
    'name' => 'edit terms in 2',
    'roles' => array(),
  );

  // Exported permission: edit terms in 3
  $permissions['edit terms in 3'] = array(
    'name' => 'edit terms in 3',
    'roles' => array(),
  );

  // Exported permission: edit terms in 4
  $permissions['edit terms in 4'] = array(
    'name' => 'edit terms in 4',
    'roles' => array(),
  );

  // Exported permission: edit terms in 5
  $permissions['edit terms in 5'] = array(
    'name' => 'edit terms in 5',
    'roles' => array(),
  );

  // Exported permission: edit terms in 6
  $permissions['edit terms in 6'] = array(
    'name' => 'edit terms in 6',
    'roles' => array(),
  );

  // Exported permission: edit terms in 7
  $permissions['edit terms in 7'] = array(
    'name' => 'edit terms in 7',
    'roles' => array(),
  );

  // Exported permission: edit terms in 8
  $permissions['edit terms in 8'] = array(
    'name' => 'edit terms in 8',
    'roles' => array(),
  );

  // Exported permission: edit terms in 9
  $permissions['edit terms in 9'] = array(
    'name' => 'edit terms in 9',
    'roles' => array(),
  );

  // Exported permission: moderate content from approved_by_purchasing to needs_purchasing_approval
  $permissions['moderate content from approved_by_purchasing to needs_purchasing_approval'] = array(
    'name' => 'moderate content from approved_by_purchasing to needs_purchasing_approval',
    'roles' => array(
      0 => 'site approver',
      1 => 'staff',
    ),
    'module' => 'workbench_moderation',
  );

  // Exported permission: moderate content from approved_by_purchasing to program_approval
  $permissions['moderate content from approved_by_purchasing to program_approval'] = array(
    'name' => 'moderate content from approved_by_purchasing to program_approval',
    'roles' => array(
      0 => 'site approver',
      1 => 'staff',
    ),
    'module' => 'workbench_moderation',
  );

  // Exported permission: moderate content from approved_by_risk_manager to needs_purchasing_approval
  $permissions['moderate content from approved_by_risk_manager to needs_purchasing_approval'] = array(
    'name' => 'moderate content from approved_by_risk_manager to needs_purchasing_approval',
    'roles' => array(
      0 => 'staff',
    ),
    'module' => 'workbench_moderation',
  );

  // Exported permission: moderate content from approved_by_risk_manager to needs_risk_manager_approval
  $permissions['moderate content from approved_by_risk_manager to needs_risk_manager_approval'] = array(
    'name' => 'moderate content from approved_by_risk_manager to needs_risk_manager_approval',
    'roles' => array(
      0 => 'site approver',
      1 => 'staff',
    ),
    'module' => 'workbench_moderation',
  );

  // Exported permission: moderate content from draft to needs_risk_manager_approval
  $permissions['moderate content from draft to needs_risk_manager_approval'] = array(
    'name' => 'moderate content from draft to needs_risk_manager_approval',
    'roles' => array(
      0 => 'staff',
    ),
    'module' => 'workbench_moderation',
  );

  // Exported permission: moderate content from needs_purchasing_approval to approved_by_purchasing
  $permissions['moderate content from needs_purchasing_approval to approved_by_purchasing'] = array(
    'name' => 'moderate content from needs_purchasing_approval to approved_by_purchasing',
    'roles' => array(
      0 => 'staff',
    ),
    'module' => 'workbench_moderation',
  );

  // Exported permission: moderate content from needs_risk_manager_approval to approved_by_risk_manager
  $permissions['moderate content from needs_risk_manager_approval to approved_by_risk_manager'] = array(
    'name' => 'moderate content from needs_risk_manager_approval to approved_by_risk_manager',
    'roles' => array(
      0 => 'site approver',
      1 => 'staff',
    ),
    'module' => 'workbench_moderation',
  );

  // Exported permission: moderate content from program_approval to needs_purchasing_approval
  $permissions['moderate content from program_approval to needs_purchasing_approval'] = array(
    'name' => 'moderate content from program_approval to needs_purchasing_approval',
    'roles' => array(
      0 => 'manager',
      1 => 'staff',
    ),
    'module' => 'workbench_moderation',
  );

  // Exported permission: moderate content from program_approval to needs_risk_manager_approval
  $permissions['moderate content from program_approval to needs_risk_manager_approval'] = array(
    'name' => 'moderate content from program_approval to needs_risk_manager_approval',
    'roles' => array(
      0 => 'staff',
    ),
    'module' => 'workbench_moderation',
  );

  // Exported permission: moderate content from program_approval to published
  $permissions['moderate content from program_approval to published'] = array(
    'name' => 'moderate content from program_approval to published',
    'roles' => array(
      0 => 'staff',
    ),
    'module' => 'workbench_moderation',
  );

  // Exported permission: moderate site information
  $permissions['moderate site information'] = array(
    'name' => 'moderate site information',
    'roles' => array(
      0 => 'staff',
    ),
    'module' => 's4_sites',
  );

  // Exported permission: skip CAPTCHA
  $permissions['skip CAPTCHA'] = array(
    'name' => 'skip CAPTCHA',
    'roles' => array(
      0 => 'authenticated user',
    ),
    'module' => 'captcha',
  );

  // Exported permission: use workbench_moderation my drafts tab
  $permissions['use workbench_moderation my drafts tab'] = array(
    'name' => 'use workbench_moderation my drafts tab',
    'roles' => array(
      0 => 'staff',
    ),
    'module' => 'workbench_moderation',
  );

  // Exported permission: use workbench_moderation needs review tab
  $permissions['use workbench_moderation needs review tab'] = array(
    'name' => 'use workbench_moderation needs review tab',
    'roles' => array(
      0 => 'staff',
    ),
    'module' => 'workbench_moderation',
  );

  // Exported permission: view all unpublished content
  $permissions['view all unpublished content'] = array(
    'name' => 'view all unpublished content',
    'roles' => array(
      0 => 'staff',
    ),
    'module' => 'workbench_moderation',
  );

  // Exported permission: view moderation history
  $permissions['view moderation history'] = array(
    'name' => 'view moderation history',
    'roles' => array(
      0 => 'staff',
    ),
    'module' => 'workbench_moderation',
  );

  // Exported permission: view moderation messages
  $permissions['view moderation messages'] = array(
    'name' => 'view moderation messages',
    'roles' => array(
      0 => 'staff',
    ),
    'module' => 'workbench_moderation',
  );

  return $permissions;
}
