<?php
/**
 * @file
 * s4_demo.feeds_tamper_default.inc
 */

/**
 * Implements hook_feeds_tamper_default().
 */
function s4_demo_feeds_tamper_default() {
  $export = array();

  $feeds_tamper = new stdClass;
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'demo_site_importer-issues-explode';
  $feeds_tamper->importer = 'demo_site_importer';
  $feeds_tamper->source = 'issues';
  $feeds_tamper->plugin_id = 'explode';
  $feeds_tamper->settings = array(
    'separator' => '|',
    'limit' => '',
    'real_separator' => '|',
  );
  $feeds_tamper->weight = 0;
  $feeds_tamper->description = 'Explode';
  $export['demo_site_importer-issues-explode'] = $feeds_tamper;

  $feeds_tamper = new stdClass;
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'demo_site_importer-org_types-explode';
  $feeds_tamper->importer = 'demo_site_importer';
  $feeds_tamper->source = 'org_types';
  $feeds_tamper->plugin_id = 'explode';
  $feeds_tamper->settings = array(
    'separator' => '|',
    'limit' => '',
    'real_separator' => '|',
  );
  $feeds_tamper->weight = 0;
  $feeds_tamper->description = 'Explode';
  $export['demo_site_importer-org_types-explode'] = $feeds_tamper;

  return $export;
}
