<?php
/**
 * @file
 * s4_opportunity.context.inc
 */

/**
 * Implements hook_context_default_contexts().
 */
function s4_opportunity_context_default_contexts() {
  $export = array();

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'site-opportunities';
  $context->description = 'User is on the site opportunity tab.';
  $context->tag = 'site';
  $context->conditions = array(
    'views' => array(
      'values' => array(
        's4_opportunity_site_opportunities:page' => 's4_opportunity_site_opportunities:page',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        's4_opportunity-new_opportunity' => array(
          'module' => 's4_opportunity',
          'delta' => 'new_opportunity',
          'region' => 'content_right',
          'weight' => '-10',
        ),
      ),
    ),
  );
  $context->condition_mode = 1;

  // Translatables
  // Included for use with string extractors like potx.
  t('User is on the site opportunity tab.');
  t('site');
  $export['site-opportunities'] = $context;

  return $export;
}
