<?php
/**
 * @file
 * s4_map.features.inc
 */

/**
 * Implements hook_views_api().
 */
function s4_map_views_api() {
  list($module, $api) = func_get_args();
  if ($module == "views") {
    return array("version" => "3.0");
  }
}
