<?php
/**
 * @file
 * s4_courses.context.inc
 */

/**
 * Implements hook_context_default_contexts().
 */
function s4_courses_context_default_contexts() {
  $export = array();

  $context = new stdClass();
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
        's4_mail-s4_mail_subscribe' => array(
          'module' => 's4_mail',
          'delta' => 's4_mail_subscribe',
          'region' => 'content_subscriptions',
          'weight' => '-10',
        ),
        's4_courses-s4_couress_add_sites' => array(
          'module' => 's4_courses',
          'delta' => 's4_couress_add_sites',
          'region' => 'content_subscriptions',
          'weight' => '-9',
        ),
      ),
    ),
    'breadcrumb' => 'courses',
    'menu' => 'courses',
  );
  $context->condition_mode = 1;

  // Translatables
  // Included for use with string extractors like potx.
  t('User is on a course page');
  t('course');
  $export['course'] = $context;

  $context = new stdClass();
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
          'region' => 'content_subscriptions',
          'weight' => '-10',
        ),
        'views-terms-block' => array(
          'module' => 'views',
          'delta' => 'terms-block',
          'region' => 'content_top_left',
          'weight' => '-9',
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

  return $export;
}
