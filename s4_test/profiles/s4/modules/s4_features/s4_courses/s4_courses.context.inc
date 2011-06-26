<?php
/**
 * @file
 * s4_courses.context.inc
 */

/**
 * Implementation of hook_context_default_contexts().
 */
function s4_courses_context_default_contexts() {
  $export = array();

  $context = new stdClass;
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'course';
  $context->description = 'User is on a course page';
  $context->tag = 'course';
  $context->conditions = array(
    'node' => array(
      'values' => array(
        'course' => 'course',
      ),
      'options' => array(
        'node_form' => '0',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        's4_courses-s4_courses_subscriptions' => array(
          'module' => 's4_courses',
          'delta' => 's4_courses_subscriptions',
          'region' => 'content_subscriptions',
          'weight' => '-10',
        ),
        'cck_blocks-field_course_faculty' => array(
          'module' => 'cck_blocks',
          'delta' => 'field_course_faculty',
          'region' => 'content_right',
          'weight' => '-10',
        ),
        'cck_blocks-field_sites' => array(
          'module' => 'cck_blocks',
          'delta' => 'field_sites',
          'region' => 'content_right',
          'weight' => '-10',
        ),
        'cck_blocks-field_site_restrict' => array(
          'module' => 'cck_blocks',
          'delta' => 'field_site_restrict',
          'region' => 'content_right',
          'weight' => '-9',
        ),
      ),
    ),
    'breadcrumb' => 'courses',
    'menu' => 'courses',
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('User is on a course page');
  t('course');
  $export['course'] = $context;

  $context = new stdClass;
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'course-list-staff';
  $context->description = 'Staff is on course listing page';
  $context->tag = 'course';
  $context->conditions = array(
    'path' => array(
      'values' => array(
        'courses' => 'courses',
        'courses?*' => 'courses?*',
      ),
    ),
    'user' => array(
      'values' => array(
        'staff' => 'staff',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        's4_courses-s4_courses_add_course' => array(
          'module' => 's4_courses',
          'delta' => 's4_courses_add_course',
          'region' => 'content_top_left',
          'weight' => '-10',
        ),
        'views-terms-block' => array(
          'module' => 'views',
          'delta' => 'terms-block',
          'region' => 'content_right',
          'weight' => '-10',
        ),
      ),
    ),
  );
  $context->condition_mode = 1;

  // Translatables
  // Included for use with string extractors like potx.
  t('Staff is on course listing page');
  t('course');
  $export['course-list-staff'] = $context;

  $context = new stdClass;
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'course-staff';
  $context->description = 'Staff is viewing a course';
  $context->tag = 'course';
  $context->conditions = array(
    'node' => array(
      'values' => array(
        'course' => 'course',
      ),
      'options' => array(
        'node_form' => '0',
      ),
    ),
    'user' => array(
      'values' => array(
        'faculty' => 'faculty',
        'staff' => 'staff',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'views-course_students-block' => array(
          'module' => 'views',
          'delta' => 'course_students-block',
          'region' => 'content',
          'weight' => '4',
        ),
      ),
    ),
  );
  $context->condition_mode = 1;

  // Translatables
  // Included for use with string extractors like potx.
  t('Staff is viewing a course');
  t('course');
  $export['course-staff'] = $context;

  $context = new stdClass;
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'course-student-list';
  $context->description = 'A student is on the my courses page';
  $context->tag = 'course';
  $context->conditions = array(
    'path' => array(
      'values' => array(
        'my-courses' => 'my-courses',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'views-terms-block_1' => array(
          'module' => 'views',
          'delta' => 'terms-block_1',
          'region' => 'content_right',
          'weight' => '-10',
        ),
      ),
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('A student is on the my courses page');
  t('course');
  $export['course-student-list'] = $context;

  $context = new stdClass;
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'dashboard-courses';
  $context->description = 'Dashboard course information';
  $context->tag = 'dashboard';
  $context->conditions = array(
    'path' => array(
      'values' => array(
        'dashboard' => 'dashboard',
        'dashboard/*' => 'dashboard/*',
      ),
    ),
    'user' => array(
      'values' => array(
        'authenticated user' => 'authenticated user',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'views-user_courses-block_2' => array(
          'module' => 'views',
          'delta' => 'user_courses-block_2',
          'region' => 'content',
          'weight' => '-10',
        ),
        'views-user_courses-block' => array(
          'module' => 'views',
          'delta' => 'user_courses-block',
          'region' => 'content_right',
          'weight' => '-10',
        ),
      ),
    ),
  );
  $context->condition_mode = 1;

  // Translatables
  // Included for use with string extractors like potx.
  t('Dashboard course information');
  t('dashboard');
  $export['dashboard-courses'] = $context;

  return $export;
}
