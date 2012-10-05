<?php
/**
 * @file
 * s4_demo.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function s4_demo_ctools_plugin_api() {
  list($module, $api) = func_get_args();
  if ($module == "feeds") {
    return array("version" => "1");
  }
  list($module, $api) = func_get_args();
  if ($module == "feeds_tamper") {
    return array("version" => "2");
  }
}
