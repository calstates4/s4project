<?php
/**
 * @file
 * s4_courses.strongarm.inc
 */

/**
 * Implements hook_strongarm().
 */
function s4_courses_strongarm() {
  $export = array();

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'language_content_type_course';
  $strongarm->value = '0';
  $export['language_content_type_course'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_options_course';
  $strongarm->value = array(
    0 => 'status',
    1 => 'revision',
  );
  $export['node_options_course'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_options_course_term';
  $strongarm->value = array(
    0 => 'status',
    1 => 'revision',
  );
  $export['node_options_course_term'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_submitted_course';
  $strongarm->value = 0;
  $export['node_submitted_course'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'nodeformscols_field_placements_course_default';
  $strongarm->value = array(
    'additional_settings' => array(
      'region' => 'main',
      'weight' => '9',
      'has_required' => FALSE,
      'title' => 'Vertical tabs',
      'hidden' => 0,
    ),
    'actions' => array(
      'region' => 'right',
      'weight' => '0',
      'has_required' => FALSE,
      'title' => 'Publish',
      'hidden' => 0,
    ),
    'field_course_faculty' => array(
      'region' => 'right',
      'weight' => '5',
      'has_required' => FALSE,
      'title' => 'Faculty',
      'hidden' => 0,
    ),
    'field_course_students' => array(
      'region' => 'main',
      'weight' => '7',
      'has_required' => FALSE,
      'title' => 'Students',
      'hidden' => 0,
    ),
    'field_site_restrict' => array(
      'region' => 'right',
      'weight' => '4',
      'has_required' => FALSE,
      'title' => 'Available programs',
      'hidden' => 0,
    ),
    'field_sites' => array(
      'region' => 'main',
      'weight' => '6',
      'has_required' => FALSE,
      'title' => 'Sites',
      'hidden' => 0,
    ),
    'field_term' => array(
      'region' => 'right',
      'weight' => '3',
      'has_required' => FALSE,
      'title' => 'Term',
      'hidden' => 0,
    ),
    'field_site_restrict_to_list' => array(
      'region' => 'main',
      'weight' => '8',
      'has_required' => FALSE,
      'title' => 'Restrict students to only these sites',
      'hidden' => 0,
    ),
    'field_service_end' => array(
      'region' => 'right',
      'weight' => '1',
      'has_required' => FALSE,
      'title' => 'Date to send evaluations',
      'hidden' => 0,
    ),
    'field_course_subject' => array(
      'region' => 'main',
      'weight' => '1',
      'has_required' => TRUE,
      'title' => 'Subject',
    ),
    'field_course_catalog_number' => array(
      'region' => 'main',
      'weight' => '3',
      'has_required' => TRUE,
      'title' => 'Catalog number',
    ),
    'field_course_section' => array(
      'region' => 'main',
      'weight' => '4',
      'has_required' => TRUE,
      'title' => 'Section number',
    ),
    'field_course_title' => array(
      'region' => 'main',
      'weight' => '5',
      'has_required' => FALSE,
      'title' => 'Course title',
      'hidden' => 0,
    ),
    'notifications' => array(
      'region' => 'main',
      'weight' => '12',
      'has_required' => FALSE,
      'title' => 'Notifications',
      'collapsed' => 0,
      'hidden' => 1,
    ),
    'field_course_signups' => array(
      'region' => 'main',
      'weight' => '2',
      'has_required' => FALSE,
      'title' => NULL,
      'hidden' => 0,
    ),
    'field_course_syllabus' => array(
      'region' => 'main',
      'weight' => '11',
      'has_required' => FALSE,
      'title' => 'Syllabus',
      'hidden' => 0,
    ),
    'field_course_faculty_email' => array(
      'region' => 'main',
      'weight' => '10',
      'has_required' => FALSE,
      'title' => 'Allow system to send emails on behalf of faculty members',
      'hidden' => 0,
    ),
    'field_max_placements' => array(
      'region' => 'right',
      'weight' => '2',
      'has_required' => FALSE,
      'title' => 'Maximum number of placements per student',
      'hidden' => 0,
    ),
  );
  $export['nodeformscols_field_placements_course_default'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'nodeformscols_field_placements_course_term_default';
  $strongarm->value = array(
    'additional_settings' => array(
      'region' => 'main',
      'weight' => '1',
      'has_required' => FALSE,
      'title' => 'Vertical tabs',
      'hidden' => 0,
    ),
    'actions' => array(
      'region' => 'right',
      'weight' => '0',
      'has_required' => FALSE,
      'title' => 'Publish',
      'hidden' => 0,
    ),
    'field_term_code' => array(
      'region' => 'right',
      'weight' => '1',
      'has_required' => TRUE,
      'title' => 'Term Code',
    ),
  );
  $export['nodeformscols_field_placements_course_term_default'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'pathauto_node_course_pattern';
  $strongarm->value = 'course/[node:nid]';
  $export['pathauto_node_course_pattern'] = $strongarm;

  return $export;
}
