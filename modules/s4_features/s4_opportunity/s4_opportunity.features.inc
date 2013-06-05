<?php
/**
 * @file
 * s4_opportunity.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function s4_opportunity_ctools_plugin_api() {
  list($module, $api) = func_get_args();
  if ($module == "relation" && $api == "relation_type_default") {
    return array("version" => "1");
  }
}
