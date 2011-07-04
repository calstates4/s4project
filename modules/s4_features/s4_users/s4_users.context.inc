<?php
/**
 * @file
 * s4_users.context.inc
 */

/**
 * Implementation of hook_context_default_contexts().
 */
function s4_users_context_default_contexts() {
  $export = array();

  $context = new stdClass;
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'user-page';
  $context->description = 'Staff member is on a user\'s page';
  $context->tag = 'user';
  $context->conditions = array(
    'user' => array(
      'values' => array(
        'administrator' => 'administrator',
        'staff' => 'staff',
      ),
    ),
    'user_page' => array(
      'values' => array(
        'view' => 'view',
      ),
      'options' => array(
        'mode' => 'all',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'views-s4_user_signups-block' => array(
          'module' => 'views',
          'delta' => 's4_user_signups-block',
          'region' => 'content',
          'weight' => '-10',
        ),
      ),
    ),
  );
  $context->condition_mode = 1;

  // Translatables
  // Included for use with string extractors like potx.
  t('Staff member is on a user\'s page');
  t('user');
  $export['user-page'] = $context;

  return $export;
}
