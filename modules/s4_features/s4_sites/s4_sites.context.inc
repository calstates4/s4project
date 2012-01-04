<?php
/**
 * @file
 * s4_sites.context.inc
 */

/**
 * Implements hook_context_default_contexts().
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
    'path' => array(
      'values' => array(
        '~node/*/talk' => '~node/*/talk',
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
          'weight' => '0',
        ),
        'views-site_fields-block_1' => array(
          'module' => 'views',
          'delta' => 'site_fields-block_1',
          'region' => 'content',
          'weight' => '1',
        ),
        's4_sites-s4_sites_site_status' => array(
          'module' => 's4_sites',
          'delta' => 's4_sites_site_status',
          'region' => 'content_right',
          'weight' => '-10',
        ),
        's4_core-user_site_signup' => array(
          'module' => 's4_core',
          'delta' => 'user_site_signup',
          'region' => 'content_right',
          'weight' => '-9',
        ),
        'views-user_courses-block_1' => array(
          'module' => 'views',
          'delta' => 'user_courses-block_1',
          'region' => 'content_right',
          'weight' => '-8',
        ),
        'views-site_fields-block' => array(
          'module' => 'views',
          'delta' => 'site_fields-block',
          'region' => 'content_right',
          'weight' => '-7',
        ),
      ),
    ),
    'breadcrumb' => 'site-list',
    'menu' => 'site-list',
  );
  $context->condition_mode = 1;

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
  $context->name = 'site-form-view';
  $context->description = 'User is viewing a site form';
  $context->tag = 'sites';
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
        's4_sites-s4_sites_form_webform' => array(
          'module' => 's4_sites',
          'delta' => 's4_sites_form_webform',
          'region' => 'content_bottom',
          'weight' => '-10',
        ),
      ),
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('User is viewing a site form');
  t('sites');
  $export['site-form-view'] = $context;

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
        's4_core-s4_subscribe_file_expiration' => array(
          'module' => 's4_core',
          'delta' => 's4_subscribe_file_expiration',
          'region' => 'content_right',
          'weight' => '-10',
        ),
        's4_pages-add_site_file' => array(
          'module' => 's4_pages',
          'delta' => 'add_site_file',
          'region' => 'content_right',
          'weight' => '-9',
        ),
        's4_sites-s4_sites_site_send_form' => array(
          'module' => 's4_sites',
          'delta' => 's4_sites_site_send_form',
          'region' => 'content_right',
          'weight' => '-7',
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
        's4_sites-s4_sites_search_help' => array(
          'module' => 's4_sites',
          'delta' => 's4_sites_search_help',
          'region' => 'content_top_left',
          'weight' => '-10',
        ),
        's4_core-site_list_course_restriction' => array(
          'module' => 's4_core',
          'delta' => 'site_list_course_restriction',
          'region' => 'content_top_left',
          'weight' => '-9',
        ),
        's4_map-s4_map_site_list_map' => array(
          'module' => 's4_map',
          'delta' => 's4_map_site_list_map',
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
          'weight' => '-18',
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
  $context->name = 'sites-talk-page';
  $context->description = 'User is on the talk page';
  $context->tag = 'sites';
  $context->conditions = array(
    'path' => array(
      'values' => array(
        'node/*/talk' => 'node/*/talk',
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
        'views-contact_records-block_1' => array(
          'module' => 'views',
          'delta' => 'contact_records-block_1',
          'region' => 'content_top_left',
          'weight' => '-10',
        ),
        's4_sites-s4_sites_site_comment' => array(
          'module' => 's4_sites',
          'delta' => 's4_sites_site_comment',
          'region' => 'content_right',
          'weight' => '-10',
        ),
      ),
    ),
  );
  $context->condition_mode = 1;

  // Translatables
  // Included for use with string extractors like potx.
  t('User is on the talk page');
  t('sites');
  $export['sites-talk-page'] = $context;

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
