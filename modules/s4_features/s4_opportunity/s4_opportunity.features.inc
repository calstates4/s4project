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
      "programs" : { "139" : "139", "135" : 0, "2" : 0, "1" : 0, "138" : 0 },
      "student_signup_form" : "",
      "faculty_approve" : 0,
      "site_staff_approve" : 1,
      "description" : {
        "value" : "\\u003Cp\\u003EThis is a thing that is the \\u003Cstrong\\u003Ething\\u003C\\/strong\\u003E.\\u003C\\/p\\u003E\\r\\n",
        "format" : "filtered_html"
      },
      "email_enable" : 0,
      "email_subject" : "",
      "email_body" : { "value" : "", "format" : "filtered_html" },
      "require_approval" : 1,
      "approval_email_subject" : "Approve, yo!",
      "approval_email_body" : {
        "value" : "\\u003Cp\\u003EHey, this must be approved!\\u003C\\/p\\u003E\\r\\n",
        "format" : "filtered_html"
      }
    },
    "rdf_mapping" : []
  }');
  return $items;
}
