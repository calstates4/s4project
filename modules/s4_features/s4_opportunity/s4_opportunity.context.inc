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
  $context->name = 'opportunity-list';
  $context->description = 'User is on the public opportunity list';
  $context->tag = 'opportunities';
  $context->conditions = array(
    'views' => array(
      'values' => array(
        's4_opportunities:page_2' => 's4_opportunities:page_2',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        's4_opportunity-view_manage' => array(
          'module' => 's4_opportunity',
          'delta' => 'view_manage',
          'region' => 'content_subscriptions',
          'weight' => '-10',
        ),
      ),
    ),
    'menu' => 'opportunities',
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('User is on the public opportunity list');
  t('opportunities');
  $export['opportunity-list'] = $context;

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'opportunity-manage';
  $context->description = 'User is on an opportunity management page';
  $context->tag = 'opportunities';
  $context->conditions = array(
    'views' => array(
      'values' => array(
        's4_opportunities:page' => 's4_opportunities:page',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        's4_opportunity-view_public' => array(
          'module' => 's4_opportunity',
          'delta' => 'view_public',
          'region' => 'content_subscriptions',
          'weight' => '-10',
        ),
      ),
    ),
    'menu' => 'opportunities',
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('User is on an opportunity management page');
  t('opportunities');
  $export['opportunity-manage'] = $context;

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'opportunity-progress';
  $context->description = 'Display the opportunity progress bar.';
  $context->tag = 'opportunities';
  $context->conditions = array(
    'user' => array(
      'values' => array(
        'authenticated user' => 'authenticated user',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        's4_opportunity-opportunity_progress' => array(
          'module' => 's4_opportunity',
          'delta' => 'opportunity_progress',
          'region' => 'content_top_wide',
          'weight' => '-10',
        ),
      ),
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('Display the opportunity progress bar.');
  t('opportunities');
  $export['opportunity-progress'] = $context;

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
          'region' => 'content_subscriptions',
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
