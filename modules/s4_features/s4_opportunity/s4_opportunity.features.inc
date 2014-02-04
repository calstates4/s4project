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
  if ($module == "ds" && $api == "ds") {
    return array("version" => "1");
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
  if ($module == "views") {
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
      "programs" : { "135" : 0, "2" : 0, "1" : 0, "139" : 0, "138" : 0 },
      "site_form" : 1,
      "site_form_message" : {
        "value" : "\\u003Cp\\u003E\\u003Cstrong\\u003EThis is the message that would appear on the top of the form screen\\u003C\\/strong\\u003E\\u003C\\/p\\u003E\\r\\n\\r\\n\\u003Cp\\u003EWe need some text here.\\u0026nbsp;Enthusiastically brand worldwide alignments and world-class interfaces. Proactively evisculate B2C e-tailers rather than holistic internal or \\u0026quot;organic\\u0026quot; sources. Holisticly communicate customized supply chains with corporate experiences.\\u0026nbsp;\\u003C\\/p\\u003E\\r\\n",
        "format" : "filtered_html"
      },
      "placement_form" : "810",
      "faculty_approve" : 1,
      "site_staff_approve" : 1,
      "require_approval" : 1,
      "description" : { "value" : "", "format" : "filtered_html" },
      "email_enable" : 1,
      "email_subject" : "Your placement",
      "email_body" : {
        "value" : "\\u003Cp\\u003EIs aWESOME!\\u003C\\/p\\u003E\\r\\n",
        "format" : "filtered_html"
      },
      "approval_email_subject" : "Approve, yo!",
      "approval_email_body" : { "value" : "", "format" : "filtered_html" },
      "site_staff_approval_email_subject" : "site staff approve",
      "site_staff_approval_email_body" : {
        "value" : "\\u003Cp\\u003Eapprove!\\u003C\\/p\\u003E\\r\\n",
        "format" : "filtered_html"
      },
      "approval_form_text" : { "value" : "", "format" : "filtered_html" }
    },
    "rdf_mapping" : []
  }');
  return $items;
}
