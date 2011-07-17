<?php
/**
 * @file
 * s4_editor.features.inc
 */

/**
 * Implementation of hook_ctools_plugin_api().
 */
function s4_editor_ctools_plugin_api() {
  list($module, $api) = func_get_args();
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}
