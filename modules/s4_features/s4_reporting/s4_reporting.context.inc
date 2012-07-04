<?php
/**
 * @file
 * s4_reporting.context.inc
 */

/**
 * Implements hook_context_default_contexts().
 */
function s4_reporting_context_default_contexts() {
  $export = array();

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'reports';
  $context->description = 'User is on a report page';
  $context->tag = 'reports';
  $context->conditions = array(
    'path' => array(
      'values' => array(
        'reports' => 'reports',
        'reports/*' => 'reports/*',
      ),
    ),
    'user' => array(
      'values' => array(
        'staff' => 'staff',
      ),
    ),
  );
  $context->reactions = array(
    'menu' => 'reports',
  );
  $context->condition_mode = 1;

  // Translatables
  // Included for use with string extractors like potx.
  t('User is on a report page');
  t('reports');
  $export['reports'] = $context;

  return $export;
}
