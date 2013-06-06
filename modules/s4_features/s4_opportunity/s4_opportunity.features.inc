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
  if ($module == "context" && $api == "context") {
    return array("version" => "3");
  }
  list($module, $api) = func_get_args();
  if ($module == "relation" && $api == "relation_type_default") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_views_api().
 */
function s4_opportunity_views_api() {
  list($module, $api) = func_get_args();
  if ($module == "views" && $api == "views_default") {
    return array("version" => "3.0");
  }
}

/**
 * Implements hook_default_s4_opportunity_type().
 */
function s4_opportunity_default_s4_opportunity_type() {
  $items = array();
  $items['internship'] = entity_import('s4_opportunity_type', '{
    "type" : "internship",
    "label" : "Internship",
    "weight" : "0",
    "data" : {
      "students_can_place" : 1,
      "signup_form" : "",
      "email_enable" : 0,
      "email_subject" : "",
      "email_body" : { "value" : "", "format" : "filtered_html" }
    },
    "rdf_mapping" : []
  }');
  return $items;
}
