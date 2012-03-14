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

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'views_savedsearches';
  $strongarm->value = array(
    'reports_sites' => 'reports_sites',
    'reports_courses' => 'reports_courses',
    'report_students' => 'report_students',
    'sites' => 0,
    'user_signups' => 0,
    'site_locations' => 0,
    'email_site_contacts' => 0,
    'site_coordinators' => 0,
    'contact_records' => 0,
    'site_moderation' => 0,
    'site_fields' => 0,
    'recent_activity' => 0,
    'course_students' => 0,
    'user_courses' => 0,
    'site_map' => 0,
    's4_students' => 0,
    'report_template' => 0,
    'student_signups' => 0,
    'admin_content' => 0,
    'email_faculty' => 0,
    's4_search' => 0,
    'email_students' => 0,
    'admin_people' => 0,
    'archive' => 0,
    'backlinks' => 0,
    'bookmarked_sites' => 0,
    'community_member_your_sites' => 0,
    'date_browser' => 0,
    'flag_bookmarks' => 0,
    'flag_bookmarks_tab' => 0,
    'frontpage' => 0,
    'glossary' => 0,
    'location_directory' => 0,
    'location_gmap' => 0,
    'location_table' => 0,
    'news' => 0,
    'notifications_content_node_list' => 0,
    's4_search_students' => 0,
    's4_user_signups' => 0,
    'site_forms' => 0,
    'site_location' => 0,
    'site_signups' => 0,
    'taxonomy_term' => 0,
    'terms' => 0,
    'tracker' => 0,
    'user_location_table' => 0,
  );
  $export['views_savedsearches'] = $strongarm;

  return $export;
}
