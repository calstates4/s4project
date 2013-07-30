<?php
/**
 * @file
 * s4_mail.features.inc
 */

/**
 * Implements hook_flag_default_flags().
 */
function s4_mail_flag_default_flags() {
  $flags = array();
  // Exported flag: "Course placement subscription".
  $flags['subscription_course_placements'] = array(
    'entity_type' => 'node',
    'title' => 'Course placement subscription',
    'global' => '0',
    'types' => array(
      0 => 'course',
    ),
    'errors' => array(),
    'flag_short' => 'Subscribe to placements',
    'flag_long' => '',
    'flag_message' => '',
    'unflag_short' => 'Unsubscribe to placements',
    'unflag_long' => '',
    'unflag_message' => '',
    'unflag_denied_text' => '',
    'link_type' => 'normal',
    'weight' => 0,
    'show_in_links' => array(
      'full' => 0,
      'teaser' => 0,
      'rss' => 0,
      'search_index' => 0,
      'search_result' => 0,
      'notifications' => 0,
      'print' => 0,
      'token' => 0,
      'revision' => 0,
    ),
    'show_as_field' => 0,
    'show_on_form' => 0,
    'access_author' => '',
    'show_contextual_link' => 0,
    'i18n' => 0,
    'module' => 's4_mail',
    'locked' => array(
      0 => 'name',
    ),
    'api_version' => 3,
  );
  // Exported flag: "Expired forms subscription".
  $flags['subscription_expired_forms'] = array(
    'entity_type' => 'taxonomy_term',
    'title' => 'Expired forms subscription',
    'global' => '0',
    'types' => array(
      0 => 'site_restrictions',
    ),
    'errors' => array(),
    'flag_short' => 'Subscribe',
    'flag_long' => '',
    'flag_message' => '',
    'unflag_short' => 'Unsubscribe',
    'unflag_long' => '',
    'unflag_message' => '',
    'unflag_denied_text' => '',
    'link_type' => 'normal',
    'weight' => 0,
    'show_in_links' => array(
      'full' => 0,
      'token' => 0,
    ),
    'show_as_field' => 0,
    'show_on_form' => 0,
    'access_author' => '',
    'show_contextual_link' => 0,
    'module' => 's4_mail',
    'locked' => array(
      0 => 'name',
    ),
    'api_version' => 3,
  );
  // Exported flag: "New site subscription".
  $flags['subscription_new_sites'] = array(
    'entity_type' => 'taxonomy_term',
    'title' => 'New site subscription',
    'global' => '0',
    'types' => array(
      0 => 'site_restrictions',
    ),
    'errors' => array(),
    'flag_short' => 'Subscribe to new sites',
    'flag_long' => '',
    'flag_message' => '',
    'unflag_short' => 'Unsubscribe to new sites',
    'unflag_long' => '',
    'unflag_message' => '',
    'unflag_denied_text' => '',
    'link_type' => 'toggle',
    'weight' => 0,
    'show_in_links' => array(
      'full' => 0,
      'token' => 0,
    ),
    'show_as_field' => 0,
    'show_on_form' => 0,
    'access_author' => '',
    'show_contextual_link' => 0,
    'api_version' => 3,
    'module' => 's4_mail',
    'locked' => array(
      0 => 'name',
    ),
  );
  // Exported flag: "Subscribe to site placements".
  $flags['subscription_site_placements'] = array(
    'entity_type' => 'node',
    'title' => 'Subscribe to site placements',
    'global' => '0',
    'types' => array(
      0 => 'site',
    ),
    'errors' => array(),
    'flag_short' => 'Subscribe to placements',
    'flag_long' => '',
    'flag_message' => '',
    'unflag_short' => 'Unsubscribe to placements',
    'unflag_long' => '',
    'unflag_message' => '',
    'unflag_denied_text' => '',
    'link_type' => 'normal',
    'weight' => 0,
    'show_in_links' => array(
      'full' => 0,
      'teaser' => 0,
      'rss' => 0,
      'search_index' => 0,
      'search_result' => 0,
      'notifications' => 0,
      'print' => 0,
      'token' => 0,
      'revision' => 0,
    ),
    'show_as_field' => 0,
    'show_on_form' => 0,
    'access_author' => '',
    'show_contextual_link' => 0,
    'i18n' => 0,
    'module' => 's4_mail',
    'locked' => array(
      0 => 'name',
    ),
    'api_version' => 3,
  );
  return $flags;

}
