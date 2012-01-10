<?php
/**
 * @file
 * s4_demo.feeds_importer_default.inc
 */

/**
 * Implements hook_feeds_importer_default().
 */
function s4_demo_feeds_importer_default() {
  $export = array();

  $feeds_importer = new stdClass;
  $feeds_importer->disabled = FALSE; /* Edit this to true to make a default feeds_importer disabled initially */
  $feeds_importer->api_version = 1;
  $feeds_importer->id = 'demo_course_importer';
  $feeds_importer->config = array(
    'name' => 'Demo course importer',
    'description' => 'Demonstration importer for courses.',
    'fetcher' => array(
      'plugin_key' => 'FeedsFileFetcher',
      'config' => array(
        'allowed_extensions' => 'txt csv tsv xml opml',
        'direct' => FALSE,
      ),
    ),
    'parser' => array(
      'plugin_key' => 'FeedsCSVParser',
      'config' => array(
        'delimiter' => ',',
        'no_headers' => 0,
      ),
    ),
    'processor' => array(
      'plugin_key' => 'S4CourseProcessor',
      'config' => array(
        'content_type' => 'page',
        'expire' => -1,
        'author' => 0,
        'mappings' => array(
          0 => array(
            'source' => 'term',
            'target' => 'term_code',
            'unique' => FALSE,
          ),
          1 => array(
            'source' => 'subject',
            'target' => 'field_course_subject',
            'unique' => FALSE,
          ),
          2 => array(
            'source' => 'catalog_number',
            'target' => 'field_course_catalog_number',
            'unique' => FALSE,
          ),
          3 => array(
            'source' => 'section',
            'target' => 'field_course_section',
            'unique' => FALSE,
          ),
          4 => array(
            'source' => 'title',
            'target' => 'field_course_title',
            'unique' => FALSE,
          ),
        ),
        'update_existing' => 0,
        'input_format' => NULL,
      ),
    ),
    'content_type' => '',
    'update' => 0,
    'import_period' => '-1',
    'expire_period' => 3600,
    'import_on_create' => 1,
    'process_in_background' => 0,
  );
  $export['demo_course_importer'] = $feeds_importer;

  $feeds_importer = new stdClass;
  $feeds_importer->disabled = FALSE; /* Edit this to true to make a default feeds_importer disabled initially */
  $feeds_importer->api_version = 1;
  $feeds_importer->id = 'demo_enrollment_importer';
  $feeds_importer->config = array(
    'name' => 'Demo enrollment importer',
    'description' => 'Demonstration importer for course enrollment',
    'fetcher' => array(
      'plugin_key' => 'FeedsFileFetcher',
      'config' => array(
        'allowed_extensions' => 'txt csv tsv xml opml',
        'direct' => FALSE,
      ),
    ),
    'parser' => array(
      'plugin_key' => 'FeedsCSVParser',
      'config' => array(
        'delimiter' => ',',
        'no_headers' => 0,
      ),
    ),
    'processor' => array(
      'plugin_key' => 'S4CourseEnrollmentProcessor',
      'config' => array(
        'expire' => -1,
        'author' => 0,
        'mappings' => array(
          0 => array(
            'source' => 'course_id',
            'target' => 'course_id',
            'unique' => FALSE,
          ),
          1 => array(
            'source' => 'user_id',
            'target' => 'sis_id',
            'unique' => FALSE,
          ),
          2 => array(
            'source' => 'enrolled',
            'target' => 'enrollment_indicator',
            'unique' => FALSE,
          ),
        ),
        'update_existing' => 0,
        'input_format' => NULL,
      ),
    ),
    'content_type' => '',
    'update' => 0,
    'import_period' => '-1',
    'expire_period' => 3600,
    'import_on_create' => 1,
    'process_in_background' => 0,
  );
  $export['demo_enrollment_importer'] = $feeds_importer;

  $feeds_importer = new stdClass;
  $feeds_importer->disabled = FALSE; /* Edit this to true to make a default feeds_importer disabled initially */
  $feeds_importer->api_version = 1;
  $feeds_importer->id = 'demo_faculty_importer';
  $feeds_importer->config = array(
    'name' => 'Demo faculty importer',
    'description' => 'Demonstration importer for faculty assignments',
    'fetcher' => array(
      'plugin_key' => 'FeedsFileFetcher',
      'config' => array(
        'allowed_extensions' => 'txt csv tsv xml opml',
        'direct' => FALSE,
      ),
    ),
    'parser' => array(
      'plugin_key' => 'FeedsCSVParser',
      'config' => array(
        'delimiter' => ',',
        'no_headers' => 0,
      ),
    ),
    'processor' => array(
      'plugin_key' => 'S4CourseFaculyProcessor',
      'config' => array(
        'expire' => -1,
        'author' => 0,
        'mappings' => array(
          0 => array(
            'source' => 'user_id',
            'target' => 'sis_id',
            'unique' => FALSE,
          ),
          1 => array(
            'source' => 'course_id',
            'target' => 'course_id',
            'unique' => FALSE,
          ),
        ),
        'update_existing' => 0,
        'input_format' => NULL,
      ),
    ),
    'content_type' => '',
    'update' => 0,
    'import_period' => '-1',
    'expire_period' => 3600,
    'import_on_create' => 1,
    'process_in_background' => 0,
  );
  $export['demo_faculty_importer'] = $feeds_importer;

  $feeds_importer = new stdClass;
  $feeds_importer->disabled = FALSE; /* Edit this to true to make a default feeds_importer disabled initially */
  $feeds_importer->api_version = 1;
  $feeds_importer->id = 'demo_term_importer';
  $feeds_importer->config = array(
    'name' => 'Demo term importer',
    'description' => 'Demonstration importer for term (semester, quarter, etc.) data.',
    'fetcher' => array(
      'plugin_key' => 'FeedsFileFetcher',
      'config' => array(
        'allowed_extensions' => 'txt csv tsv xml opml',
        'direct' => FALSE,
      ),
    ),
    'parser' => array(
      'plugin_key' => 'FeedsCSVParser',
      'config' => array(
        'delimiter' => ',',
        'no_headers' => 0,
      ),
    ),
    'processor' => array(
      'plugin_key' => 'FeedsNodeProcessor',
      'config' => array(
        'content_type' => 'course_term',
        'expire' => '-1',
        'author' => 0,
        'mappings' => array(
          0 => array(
            'source' => 'term_title',
            'target' => 'title',
            'unique' => FALSE,
          ),
          1 => array(
            'source' => 'term_code',
            'target' => 'field_term_code',
            'unique' => FALSE,
          ),
          2 => array(
            'source' => 'term_code',
            'target' => 'guid',
            'unique' => 1,
          ),
          3 => array(
            'source' => 'start_date',
            'target' => 'field_term_date_start:start',
            'unique' => FALSE,
          ),
          4 => array(
            'source' => 'end_date',
            'target' => 'field_term_date_start:end',
            'unique' => FALSE,
          ),
        ),
        'update_existing' => '2',
        'input_format' => 'plain_text',
      ),
    ),
    'content_type' => '',
    'update' => 0,
    'import_period' => '-1',
    'expire_period' => 3600,
    'import_on_create' => 1,
    'process_in_background' => 0,
  );
  $export['demo_term_importer'] = $feeds_importer;

  $feeds_importer = new stdClass;
  $feeds_importer->disabled = FALSE; /* Edit this to true to make a default feeds_importer disabled initially */
  $feeds_importer->api_version = 1;
  $feeds_importer->id = 'demo_user_importer';
  $feeds_importer->config = array(
    'name' => 'Demo user importer',
    'description' => 'Demonstration importer for users (students and faculty)',
    'fetcher' => array(
      'plugin_key' => 'FeedsFileFetcher',
      'config' => array(
        'allowed_extensions' => 'txt csv tsv xml opml',
        'direct' => FALSE,
      ),
    ),
    'parser' => array(
      'plugin_key' => 'FeedsCSVParser',
      'config' => array(
        'delimiter' => ',',
        'no_headers' => 0,
      ),
    ),
    'processor' => array(
      'plugin_key' => 'FeedsUserProcessor',
      'config' => array(
        'roles' => array(),
        'status' => 1,
        'defuse_mail' => FALSE,
        'mappings' => array(
          0 => array(
            'source' => 'login_id',
            'target' => 'name',
            'unique' => 0,
          ),
          1 => array(
            'source' => 'email',
            'target' => 'mail',
            'unique' => 0,
          ),
          2 => array(
            'source' => 'first_name',
            'target' => 'field_first_name',
            'unique' => FALSE,
          ),
          3 => array(
            'source' => 'last_name',
            'target' => 'field_last_name',
            'unique' => FALSE,
          ),
          4 => array(
            'source' => 'restrictions',
            'target' => 'field_site_restrict',
            'unique' => FALSE,
          ),
          5 => array(
            'source' => 'user_id',
            'target' => 'field_sis_id',
            'unique' => FALSE,
          ),
          6 => array(
            'source' => 'constant_registration',
            'target' => 'field_course_ignore',
            'unique' => FALSE,
          ),
          7 => array(
            'source' => 'user_id',
            'target' => 'guid',
            'unique' => 1,
          ),
        ),
        'update_existing' => 0,
        'input_format' => NULL,
      ),
    ),
    'content_type' => '',
    'update' => 0,
    'import_period' => '-1',
    'expire_period' => 3600,
    'import_on_create' => 1,
    'process_in_background' => 0,
  );
  $export['demo_user_importer'] = $feeds_importer;

  return $export;
}
