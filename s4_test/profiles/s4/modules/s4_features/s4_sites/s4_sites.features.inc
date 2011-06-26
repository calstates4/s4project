<?php
/**
 * @file
 * s4_sites.features.inc
 */

/**
 * Implementation of hook_ctools_plugin_api().
 */
function s4_sites_ctools_plugin_api() {
  list($module, $api) = func_get_args();
  if ($module == "boxes" && $api == "box") {
    return array("version" => "1");
  }
  list($module, $api) = func_get_args();
  if ($module == "context" && $api == "context") {
    return array("version" => "3");
  }
  list($module, $api) = func_get_args();
  if ($module == "field_group" && $api == "field_group") {
    return array("version" => "1");
  }
  list($module, $api) = func_get_args();
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implementation of hook_views_api().
 */
function s4_sites_views_api() {
  list($module, $api) = func_get_args();
  if ($module == "views" && $api == "views_default") {
    return array("version" => "3.0");
  }
}

/**
 * Implementation of hook_node_info().
 */
function s4_sites_node_info() {
  $items = array(
    'contact_record' => array(
      'name' => t('Contact Record'),
      'base' => 'node_content',
      'description' => t('A Contact Record is used to track a history of files or contacts with a site. Useful for maintaining good relationships with sites and to retain documents that might be useful to retain in the future.'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => t('Leave a note or file about a contact with a site.'),
    ),
    'coordinator' => array(
      'name' => t('Coordinator'),
      'base' => 'node_content',
      'description' => t('A site coordinator is someone who students sign up with for service.'),
      'has_title' => '1',
      'title_label' => t('Coordinator Name'),
      'help' => t('A site coordinator is someone who students sign up with for service.'),
    ),
    'file' => array(
      'name' => t('File'),
      'base' => 'node_content',
      'description' => t('A file is a record of a file for a site. '),
      'has_title' => '1',
      'title_label' => t('File name'),
      'help' => t('Use files to store service agreements, workers\' comp paperwork, or other files that need to be tracked and possibly remind others when they expire.'),
    ),
    'site' => array(
      'name' => t('Site'),
      'base' => 'node_content',
      'description' => t('A site is a location or project which students sign up with for community service, service learning, internships, and the like.'),
      'has_title' => '1',
      'title_label' => t('Site Name'),
      'help' => t('A site is a location or project which students sign up with for community service, service learning, internships, and the like.'),
    ),
  );
  return $items;
}
