<?php
/**
 * @file
 * s4_reporting.strongarm.inc
 */

/**
 * Implements hook_strongarm().
 */
function s4_reporting_strongarm() {
  $export = array();

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'views_savedsearches';
  $strongarm->value = array(
    'reports_sites' => 'reports_sites',
    'reports_site_staff' => 'reports_site_staff',
    'reports_students' => 'reports_students',
    'reports_faculty' => 'reports_faculty',
    'site_coordinators' => 0,
    'contact_records' => 0,
    'user_courses' => 0,
    'manage_sites' => 0,
    'admin_content' => 0,
    'admin_people' => 0,
    'archive' => 0,
    'backlinks' => 0,
    'community_member_your_sites' => 0,
    'course_students' => 0,
    'date_browser' => 0,
    'feeds_log' => 0,
    'frontpage' => 0,
    'glossary' => 0,
    'location_directory' => 0,
    'location_gmap' => 0,
    'location_table' => 0,
    'Maillog' => 0,
    'notifications_content_node_list' => 0,
    's4_search' => 0,
    's4_search_students' => 0,
    's4_students' => 0,
    's4_user_signups' => 0,
    'sites' => 0,
    'site_fields' => 0,
    'site_forms' => 0,
    'site_location' => 0,
    'site_locations' => 0,
    'site_map' => 0,
    'site_signups' => 0,
    'taxonomy_term' => 0,
    'terms' => 0,
    'user_location_table' => 0,
    'user_signups' => 0,
    'workbench_current_user' => 0,
    'workbench_edited' => 0,
    'workbench_moderation' => 0,
    'workbench_recent_content' => 0,
  );
  $export['views_savedsearches'] = $strongarm;

  return $export;
}
