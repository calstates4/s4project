<?php
/**
 * @file
 * s4_sites.context.inc
 */

/**
 * Implementation of hook_context_default_contexts().
 */
function s4_sites_context_default_contexts() {
  $export = array();

  $context = new stdClass;
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'map';
  $context->description = 'User is on the large site map';
  $context->tag = 'sites';
  $context->conditions = array(
    'path' => array(
      'values' => array(
        'map' => 'map',
        'map*' => 'map*',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'views--exp-location_gmap-page' => array(
          'module' => 'views',
          'delta' => '-exp-location_gmap-page',
          'region' => 'content_top_left',
          'weight' => '-10',
        ),
      ),
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('User is on the large site map');
  t('sites');
  $export['map'] = $context;

  $context = new stdClass;
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'site';
  $context->description = 'User is on a site page';
  $context->tag = 'sites';
  $context->conditions = array(
    'node' => array(
      'values' => array(
        'site' => 'site',
      ),
      'options' => array(
        'node_form' => '0',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        's4_core-s4_page_notifications' => array(
          'module' => 's4_core',
          'delta' => 's4_page_notifications',
          'region' => 'content_subscriptions',
          'weight' => '-10',
        ),
        's4_core-user_site_signup' => array(
          'module' => 's4_core',
          'delta' => 'user_site_signup',
          'region' => 'content_right',
          'weight' => '-54',
        ),
        'views-user_courses-block_1' => array(
          'module' => 'views',
          'delta' => 'user_courses-block_1',
          'region' => 'content_right',
          'weight' => '-53',
        ),
        'cck_blocks-field_csu_facility' => array(
          'module' => 'cck_blocks',
          'delta' => 'field_csu_facility',
          'region' => 'content_right',
          'weight' => '-52',
        ),
        'cck_blocks-field_csu_org_type' => array(
          'module' => 'cck_blocks',
          'delta' => 'field_csu_org_type',
          'region' => 'content_right',
          'weight' => '-51',
        ),
        'cck_blocks-field_website' => array(
          'module' => 'cck_blocks',
          'delta' => 'field_website',
          'region' => 'content_right',
          'weight' => '-50',
        ),
        'cck_blocks-field_phone' => array(
          'module' => 'cck_blocks',
          'delta' => 'field_phone',
          'region' => 'content_right',
          'weight' => '-49',
        ),
        'cck_blocks-field_location' => array(
          'module' => 'cck_blocks',
          'delta' => 'field_location',
          'region' => 'content_right',
          'weight' => '-48',
        ),
        'cck_blocks-field_site_images' => array(
          'module' => 'cck_blocks',
          'delta' => 'field_site_images',
          'region' => 'content_right',
          'weight' => '-41',
        ),
        'cck_blocks-field_site_requirements' => array(
          'module' => 'cck_blocks',
          'delta' => 'field_site_requirements',
          'region' => 'content_right',
          'weight' => '-10',
        ),
        'cck_blocks-field_site_language' => array(
          'module' => 'cck_blocks',
          'delta' => 'field_site_language',
          'region' => 'content_right',
          'weight' => '-10',
        ),
        'cck_blocks-field_site_demographics' => array(
          'module' => 'cck_blocks',
          'delta' => 'field_site_demographics',
          'region' => 'content_right',
          'weight' => '-10',
        ),
        'cck_blocks-field_site_hours_minimum' => array(
          'module' => 'cck_blocks',
          'delta' => 'field_site_hours_minimum',
          'region' => 'content_right',
          'weight' => '-10',
        ),
        'cck_blocks-field_site_facebook_page' => array(
          'module' => 'cck_blocks',
          'delta' => 'field_site_facebook_page',
          'region' => 'content_right',
          'weight' => '-10',
        ),
        'cck_blocks-field_signups_max' => array(
          'module' => 'cck_blocks',
          'delta' => 'field_signups_max',
          'region' => 'content_right',
          'weight' => '-10',
        ),
      ),
    ),
    'breadcrumb' => 'site-list',
    'menu' => 'site-list',
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('User is on a site page');
  t('sites');
  $export['site'] = $context;

  $context = new stdClass;
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'site-file';
  $context->description = 'User is on a site file page';
  $context->tag = 'site';
  $context->conditions = array(
    'node' => array(
      'values' => array(
        'file' => 'file',
      ),
      'options' => array(
        'node_form' => '0',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'cck_blocks-field_file_category' => array(
          'module' => 'cck_blocks',
          'delta' => 'field_file_category',
          'region' => 'content_right',
          'weight' => '-10',
        ),
        'cck_blocks-field_file_tags' => array(
          'module' => 'cck_blocks',
          'delta' => 'field_file_tags',
          'region' => 'content_right',
          'weight' => '-9',
        ),
        'cck_blocks-field_expiration_date' => array(
          'module' => 'cck_blocks',
          'delta' => 'field_expiration_date',
          'region' => 'content_right',
          'weight' => '-8',
        ),
        'cck_blocks-field_expiration_reminder' => array(
          'module' => 'cck_blocks',
          'delta' => 'field_expiration_reminder',
          'region' => 'content_right',
          'weight' => '-7',
        ),
      ),
    ),
    'menu' => 'site-list',
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('User is on a site file page');
  t('site');
  $export['site-file'] = $context;

  $context = new stdClass;
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'site-forms';
  $context->description = 'User is on the site forms page';
  $context->tag = 'sites';
  $context->conditions = array(
    'path' => array(
      'values' => array(
        'node/*/forms' => 'node/*/forms',
      ),
    ),
    'user' => array(
      'values' => array(
        'administrator' => 'administrator',
        'staff' => 'staff',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        's4_pages-add_site_file' => array(
          'module' => 's4_pages',
          'delta' => 'add_site_file',
          'region' => 'content_right',
          'weight' => '-10',
        ),
      ),
    ),
  );
  $context->condition_mode = 1;

  // Translatables
  // Included for use with string extractors like potx.
  t('User is on the site forms page');
  t('sites');
  $export['site-forms'] = $context;

  $context = new stdClass;
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'site-list';
  $context->description = 'User is on the site list and search page';
  $context->tag = 'sites';
  $context->conditions = array(
    'path' => array(
      'values' => array(
        'site-list' => 'site-list',
        'site-list*' => 'site-list*',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        's4_core-s4_add_new_site' => array(
          'module' => 's4_core',
          'delta' => 's4_add_new_site',
          'region' => 'content_top_left',
          'weight' => '-10',
        ),
        's4_core-site_list_course_restriction' => array(
          'module' => 's4_core',
          'delta' => 'site_list_course_restriction',
          'region' => 'content_top_left',
          'weight' => '-9',
        ),
        's4_sites-s4_sites_search_help' => array(
          'module' => 's4_sites',
          'delta' => 's4_sites_search_help',
          'region' => 'content_top_left',
          'weight' => '-10',
        ),
        's4_sites-s4_sites_search_map' => array(
          'module' => 's4_sites',
          'delta' => 's4_sites_search_map',
          'region' => 'content_right',
          'weight' => '-10',
        ),
      ),
    ),
    'theme_html' => array(
      'class' => 'site-list',
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('User is on the site list and search page');
  t('sites');
  $export['site-list'] = $context;

  $context = new stdClass;
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'site-location-list';
  $context->description = 'User is on the site location listing';
  $context->tag = 'sites';
  $context->conditions = array(
    'path' => array(
      'values' => array(
        'sites/*/locations' => 'sites/*/locations',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        's4_sites-s4_sites_search_map' => array(
          'module' => 's4_sites',
          'delta' => 's4_sites_search_map',
          'region' => 'content_right',
          'weight' => '-10',
        ),
      ),
    ),
    'theme_html' => array(
      'class' => 'site-list',
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('User is on the site location listing');
  t('sites');
  $export['site-location-list'] = $context;

  $context = new stdClass;
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'site-notes';
  $context->description = 'User is on the site notes page';
  $context->tag = 'sites';
  $context->conditions = array(
    'path' => array(
      'values' => array(
        'node/*/notes' => 'node/*/notes',
      ),
    ),
    'user' => array(
      'values' => array(
        'administrator' => 'administrator',
        'staff' => 'staff',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        's4_pages-add_contact_record' => array(
          'module' => 's4_pages',
          'delta' => 'add_contact_record',
          'region' => 'content_right',
          'weight' => '-10',
        ),
      ),
    ),
  );
  $context->condition_mode = 1;

  // Translatables
  // Included for use with string extractors like potx.
  t('User is on the site notes page');
  t('sites');
  $export['site-notes'] = $context;

  $context = new stdClass;
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'site-staff';
  $context->description = 'User is on the site staff page';
  $context->tag = 'sites';
  $context->conditions = array(
    'path' => array(
      'values' => array(
        'node/*/site-staff' => 'node/*/site-staff',
      ),
    ),
    'user' => array(
      'values' => array(
        'administrator' => 'administrator',
        'staff' => 'staff',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        's4_core-s4_add_new_coordinator' => array(
          'module' => 's4_core',
          'delta' => 's4_add_new_coordinator',
          'region' => 'content',
          'weight' => '-10',
        ),
      ),
    ),
  );
  $context->condition_mode = 1;

  // Translatables
  // Included for use with string extractors like potx.
  t('User is on the site staff page');
  t('sites');
  $export['site-staff'] = $context;

  $context = new stdClass;
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'site-students';
  $context->description = 'User is on the site students list';
  $context->tag = 'site';
  $context->conditions = array(
    'path' => array(
      'values' => array(
        'node/*/students' => 'node/*/students',
        'node/*/students*' => 'node/*/students*',
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
        'views-site_signups-block' => array(
          'module' => 'views',
          'delta' => 'site_signups-block',
          'region' => 'content',
          'weight' => '-10',
        ),
      ),
    ),
  );
  $context->condition_mode = 1;

  // Translatables
  // Included for use with string extractors like potx.
  t('User is on the site students list');
  t('site');
  $export['site-students'] = $context;

  $context = new stdClass;
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'views-contact-records';
  $context->description = 'User is on a generic view page';
  $context->tag = 'views';
  $context->conditions = array(
    'path' => array(
      'values' => array(
        'node/*/contact-records' => 'node/*/contact-records',
        'node/*/contact-records*' => 'node/*/contact-records*',
      ),
    ),
  );
  $context->reactions = array(
    'menu' => 'site-list',
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('User is on a generic view page');
  t('views');
  $export['views-contact-records'] = $context;

  return $export;
}
