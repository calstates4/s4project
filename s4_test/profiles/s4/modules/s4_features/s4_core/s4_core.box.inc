<?php
/**
 * @file
 * s4_core.box.inc
 */

/**
 * Implementation of hook_default_box().
 */
function s4_core_default_box() {
  $export = array();

  $box = new stdClass;
  $box->disabled = FALSE; /* Edit this to true to make a default box disabled initially */
  $box->api_version = 1;
  $box->delta = 's4_mission';
  $box->plugin_key = 'simple';
  $box->title = '';
  $box->description = 'Site Mission Statement';
  $box->options = array(
    'body' => array(
      'value' => '<p class="intro">This where you can give users more information about your program. Let us know in a few sentences what you do, and what the community gets from your program.</p><p>Hover over this paragraph and click the gear icon to edit this information.</p>',
      'format' => 'filtered_html',
    ),
  );
  $export['s4_mission'] = $box;

  return $export;
}
