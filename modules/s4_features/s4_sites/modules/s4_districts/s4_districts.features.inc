<?php
/**
 * @file
 * s4_districts.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function s4_districts_ctools_plugin_api() {
  list($module, $api) = func_get_args();
  if ($module == "field_group") {
    return array("version" => "1");
  }
  list($module, $api) = func_get_args();
  if ($module == "strongarm") {
    return array("version" => "1");
  }
}
