<?php
/**
 * @file
 * s4_sites.strongarm.inc
 */

/**
 * Implements hook_strongarm().
 */
function s4_sites_strongarm() {
  $export = array();

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'ant_coordinator';
  $strongarm->value = '1';
  $export['ant_coordinator'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'ant_pattern_coordinator';
  $strongarm->value = '[node:field-first-name:value] [node:field-last-name:value]';
  $export['ant_pattern_coordinator'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'ant_php_coordinator';
  $strongarm->value = 0;
  $export['ant_php_coordinator'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_anonymous_contact_record';
  $strongarm->value = 0;
  $export['comment_anonymous_contact_record'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_anonymous_coordinator';
  $strongarm->value = 0;
  $export['comment_anonymous_coordinator'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_anonymous_file';
  $strongarm->value = 0;
  $export['comment_anonymous_file'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_anonymous_site';
  $strongarm->value = 0;
  $export['comment_anonymous_site'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_contact_record';
  $strongarm->value = '2';
  $export['comment_contact_record'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_coordinator';
  $strongarm->value = '2';
  $export['comment_coordinator'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_default_mode_contact_record';
  $strongarm->value = 1;
  $export['comment_default_mode_contact_record'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_default_mode_coordinator';
  $strongarm->value = 1;
  $export['comment_default_mode_coordinator'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_default_mode_file';
  $strongarm->value = 1;
  $export['comment_default_mode_file'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_default_mode_site';
  $strongarm->value = 1;
  $export['comment_default_mode_site'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_default_per_page_contact_record';
  $strongarm->value = '50';
  $export['comment_default_per_page_contact_record'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_default_per_page_coordinator';
  $strongarm->value = '50';
  $export['comment_default_per_page_coordinator'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_default_per_page_file';
  $strongarm->value = '50';
  $export['comment_default_per_page_file'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_default_per_page_site';
  $strongarm->value = '50';
  $export['comment_default_per_page_site'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_file';
  $strongarm->value = '0';
  $export['comment_file'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_form_location_contact_record';
  $strongarm->value = 1;
  $export['comment_form_location_contact_record'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_form_location_coordinator';
  $strongarm->value = 1;
  $export['comment_form_location_coordinator'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_form_location_file';
  $strongarm->value = 1;
  $export['comment_form_location_file'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_form_location_site';
  $strongarm->value = 1;
  $export['comment_form_location_site'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_preview_contact_record';
  $strongarm->value = '1';
  $export['comment_preview_contact_record'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_preview_coordinator';
  $strongarm->value = '1';
  $export['comment_preview_coordinator'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_preview_file';
  $strongarm->value = '1';
  $export['comment_preview_file'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_preview_site';
  $strongarm->value = '0';
  $export['comment_preview_site'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_site';
  $strongarm->value = '2';
  $export['comment_site'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_subject_field_contact_record';
  $strongarm->value = 1;
  $export['comment_subject_field_contact_record'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_subject_field_coordinator';
  $strongarm->value = 1;
  $export['comment_subject_field_coordinator'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_subject_field_file';
  $strongarm->value = 0;
  $export['comment_subject_field_file'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_subject_field_site';
  $strongarm->value = 1;
  $export['comment_subject_field_site'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_talk_site';
  $strongarm->value = 1;
  $export['comment_talk_site'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'gmap_default';
  $strongarm->value = array(
    'width' => '100%',
    'height' => '400px',
    'latlong' => '36.66814353758172,-121.74877166748047',
    'zoom' => '12',
    'maxzoom' => '14',
    'styles' => array(
      'line_default' => array(
        0 => '0000ff',
        1 => '5',
        2 => '45',
        3 => '',
        4 => '',
      ),
      'poly_default' => array(
        0 => '000000',
        1 => '3',
        2 => '25',
        3 => 'ff0000',
        4 => '45',
      ),
      'highlight_color' => 'ff0000',
    ),
    'controltype' => 'Small',
    'mtc' => 'standard',
    'maptype' => 'Map',
    'baselayers' => array(
      'Map' => 1,
      'Satellite' => 1,
      'Hybrid' => 1,
      'Physical' => 0,
    ),
    'behavior' => array(
      'locpick' => FALSE,
      'nodrag' => 0,
      'nokeyboard' => 1,
      'nomousezoom' => 0,
      'nocontzoom' => 0,
      'autozoom' => 0,
      'dynmarkers' => 0,
      'overview' => 0,
      'collapsehack' => 0,
      'scale' => 0,
      'extramarkerevents' => FALSE,
      'clickableshapes' => FALSE,
      'googlebar' => 0,
      'highlight' => 0,
    ),
    'markermode' => '1',
    'line_colors' => array(
      0 => '#00cc00',
      1 => '#ff0000',
      2 => '#0000ff',
    ),
  );
  $export['gmap_default'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'gmap_marker_file';
  $strongarm->value = '1';
  $export['gmap_marker_file'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'gmap_markermanager';
  $strongarm->value = array(
    'gmarkermanager' => array(
      'borderPadding' => '256',
      'maxZoom' => '4',
      'trackMarkers' => 0,
      'markerMinZoom' => '4',
      'markerMaxZoom' => '0',
    ),
    'markermanager' => array(
      'filename' => 'markermanager_packed.js',
      'borderPadding' => '256',
      'maxZoom' => '4',
      'trackMarkers' => 0,
      'markerMinZoom' => '4',
      'markerMaxZoom' => '0',
    ),
    'markerclusterer' => array(
      'filename' => 'markerclusterer/markerclusterer_packed.js',
      'gridSize' => '30',
      'maxZoom' => '17',
    ),
    'clusterer' => array(
      'filename' => 'Clusterer2.js',
      'marker' => 'cluster',
      'max_nocluster' => '150',
      'cluster_min' => '5',
      'max_lines' => '10',
      'popup_mode' => 'orig',
    ),
    'clustermarker' => array(
      'filename' => 'ClusterMarker.js',
      'borderPadding' => '256',
      'clusteringEnabled' => 1,
      'clusterMarkerIcon' => '',
      'clusterMarkerTitle' => '',
      'fitMapMaxZoom' => '0',
      'intersectPadding' => '0',
    ),
  );
  $export['gmap_markermanager'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'gmap_mm_type';
  $strongarm->value = 'markerclusterer';
  $export['gmap_mm_type'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'language_content_type_coordinator';
  $strongarm->value = '0';
  $export['language_content_type_coordinator'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'language_content_type_file';
  $strongarm->value = '0';
  $export['language_content_type_file'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'language_content_type_site';
  $strongarm->value = '0';
  $export['language_content_type_site'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'location_defaultnum_coordinator';
  $strongarm->value = '1';
  $export['location_defaultnum_coordinator'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'location_defaultnum_site';
  $strongarm->value = '1';
  $export['location_defaultnum_site'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'location_maxnum_coordinator';
  $strongarm->value = '0';
  $export['location_maxnum_coordinator'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'location_maxnum_site';
  $strongarm->value = '0';
  $export['location_maxnum_site'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'location_settings_node_coordinator';
  $strongarm->value = array(
    'multiple' => array(
      'min' => '0',
      'max' => '0',
      'add' => '1',
    ),
    'form' => array(
      'weight' => '0',
      'collapsible' => 1,
      'collapsed' => 1,
      'fields' => array(
        'name' => array(
          'collect' => '1',
          'default' => '',
          'weight' => '2',
        ),
        'street' => array(
          'collect' => '1',
          'default' => '',
          'weight' => '4',
        ),
        'additional' => array(
          'collect' => '1',
          'default' => '',
          'weight' => '6',
        ),
        'city' => array(
          'collect' => '0',
          'default' => '',
          'weight' => '8',
        ),
        'province' => array(
          'collect' => '0',
          'widget' => 'autocomplete',
          'default' => '',
          'weight' => '10',
        ),
        'postal_code' => array(
          'collect' => '0',
          'default' => '',
          'weight' => '12',
        ),
        'country' => array(
          'collect' => '1',
          'default' => 'us',
          'weight' => '14',
        ),
        'locpick' => array(
          'collect' => '1',
          'weight' => '20',
        ),
        'phone' => array(
          'collect' => '0',
          'default' => '',
          'weight' => '25',
        ),
        'fax' => array(
          'collect' => '0',
          'default' => '',
          'weight' => '30',
        ),
      ),
    ),
    'display' => array(
      'weight' => '0',
      'hide' => array(
        'name' => 0,
        'street' => 0,
        'additional' => 0,
        'city' => 0,
        'province' => 0,
        'postal_code' => 0,
        'country' => 0,
        'locpick' => 0,
        'fax' => 0,
        'phone' => 0,
        'province_name' => 0,
        'country_name' => 0,
        'map_link' => 0,
        'coords' => 0,
      ),
      'teaser' => 1,
      'full' => 1,
    ),
    'rss' => array(
      'mode' => 'simple',
    ),
  );
  $export['location_settings_node_coordinator'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'location_settings_node_site';
  $strongarm->value = array(
    'multiple' => array(
      'min' => '0',
      'max' => '0',
      'add' => '1',
    ),
    'form' => array(
      'weight' => '0',
      'collapsible' => 1,
      'collapsed' => 1,
      'fields' => array(
        'name' => array(
          'collect' => '1',
          'default' => '',
          'weight' => '2',
        ),
        'street' => array(
          'collect' => '1',
          'default' => '',
          'weight' => '4',
        ),
        'additional' => array(
          'collect' => '1',
          'default' => '',
          'weight' => '6',
        ),
        'city' => array(
          'collect' => '0',
          'default' => '',
          'weight' => '8',
        ),
        'province' => array(
          'collect' => '0',
          'widget' => 'autocomplete',
          'default' => '',
          'weight' => '10',
        ),
        'postal_code' => array(
          'collect' => '0',
          'default' => '',
          'weight' => '12',
        ),
        'country' => array(
          'collect' => '1',
          'default' => 'us',
          'weight' => '14',
        ),
        'locpick' => array(
          'collect' => '1',
          'weight' => '20',
        ),
        'phone' => array(
          'collect' => '0',
          'default' => '',
          'weight' => '25',
        ),
        'fax' => array(
          'collect' => '0',
          'default' => '',
          'weight' => '30',
        ),
      ),
    ),
    'display' => array(
      'weight' => '0',
      'hide' => array(
        'name' => 0,
        'street' => 0,
        'additional' => 0,
        'city' => 0,
        'province' => 0,
        'postal_code' => 0,
        'country' => 0,
        'locpick' => 0,
        'fax' => 0,
        'phone' => 0,
        'province_name' => 0,
        'country_name' => 0,
        'map_link' => 0,
        'coords' => 0,
      ),
      'teaser' => 0,
      'full' => 0,
    ),
    'rss' => array(
      'mode' => 'simple',
    ),
  );
  $export['location_settings_node_site'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_options_contact_record';
  $strongarm->value = array(
    0 => 'status',
    1 => 'revision',
  );
  $export['node_options_contact_record'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_options_coordinator';
  $strongarm->value = array(
    0 => 'status',
    1 => 'revision',
  );
  $export['node_options_coordinator'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_options_file';
  $strongarm->value = array(
    0 => 'status',
    1 => 'revision',
  );
  $export['node_options_file'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_options_site';
  $strongarm->value = array(
    0 => 'status',
    1 => 'revision',
  );
  $export['node_options_site'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_submitted_coordinator';
  $strongarm->value = 0;
  $export['node_submitted_coordinator'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_submitted_site';
  $strongarm->value = 0;
  $export['node_submitted_site'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'nodeaccess_nodereference';
  $strongarm->value = array(
    'coordinator' => array(
      'field_site' => array(
        'referenced' => array(
          'view' => array(
            'view' => 'view',
            'update' => 0,
            'delete' => 0,
          ),
          'update' => array(
            'update' => 0,
            'view' => 0,
            'delete' => 0,
          ),
          'delete' => array(
            'delete' => 0,
            'view' => 0,
            'update' => 0,
          ),
        ),
        'author' => array(
          'view' => 0,
          'update' => 0,
          'delete' => 0,
        ),
        'all' => array(
          'view' => 'view',
        ),
        'unused' => '0',
        'priority' => '0',
      ),
    ),
    'site' => array(
      'field_site_form' => array(
        'referenced' => array(
          'view' => array(
            'view' => 0,
            'update' => 0,
            'delete' => 0,
          ),
          'update' => array(
            'update' => 0,
            'view' => 0,
            'delete' => 0,
          ),
          'delete' => array(
            'delete' => 0,
            'view' => 0,
            'update' => 0,
          ),
        ),
        'author' => array(
          'view' => 0,
          'update' => 0,
          'delete' => 0,
        ),
        'all' => array(
          'view' => 'view',
        ),
        'unused' => '0',
        'priority' => '0',
      ),
      'field_site_eval_form' => array(
        'referenced' => array(
          'view' => array(
            'view' => 0,
            'update' => 0,
            'delete' => 0,
          ),
          'update' => array(
            'update' => 0,
            'view' => 0,
            'delete' => 0,
          ),
          'delete' => array(
            'delete' => 0,
            'view' => 0,
            'update' => 0,
          ),
        ),
        'author' => array(
          'view' => 0,
          'update' => 0,
          'delete' => 0,
        ),
        'all' => array(
          'view' => 'view',
        ),
        'unused' => '0',
        'priority' => '0',
      ),
    ),
  );
  $export['nodeaccess_nodereference'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'nodeaccess_nodereference_cross_access';
  $strongarm->value = array(
    'view' => FALSE,
    'update' => FALSE,
    'delete' => FALSE,
  );
  $export['nodeaccess_nodereference_cross_access'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'nodeaccess_userreference';
  $strongarm->value = array(
    'course' => array(
      'field_course_faculty' => array(
        'referenced' => array(
          'view' => 'view',
          'update' => 0,
          'delete' => 0,
          'deny_view' => 0,
          'deny_update' => 0,
          'deny_delete' => 0,
        ),
        'author' => array(
          'view' => 0,
          'update' => 0,
          'delete' => 0,
        ),
        'all' => array(
          'view' => 0,
        ),
        'unused' => '0',
        'views' => array(
          'view' => '',
          'view_args' => '',
        ),
        'priority' => '9',
      ),
      'field_course_students' => array(
        'referenced' => array(
          'view' => 'view',
          'update' => 0,
          'delete' => 0,
        ),
        'author' => array(
          'view' => 0,
          'update' => 0,
          'delete' => 0,
        ),
        'all' => array(
          'view' => 'view',
        ),
        'unused' => '1',
        'views' => array(
          'view' => '',
          'view_args' => '',
        ),
        'priority' => '0',
      ),
    ),
    'site' => array(
      'field_site_users' => array(
        'referenced' => array(
          'update' => 'update',
          'view' => 0,
          'delete' => 0,
          'deny_view' => 0,
          'deny_update' => 0,
          'deny_delete' => 0,
        ),
        'author' => array(
          'view' => 'view',
          'update' => 'update',
          'delete' => 'delete',
        ),
        'all' => array(
          'view' => 'view',
        ),
        'unused' => '0',
        'views' => array(
          'view' => '',
          'view_args' => '',
        ),
        'priority' => '0',
      ),
    ),
    'signup' => array(
      'field_user' => array(
        'referenced' => array(
          'view' => 'view',
          'update' => 0,
          'delete' => 0,
          'deny_view' => 0,
          'deny_update' => 0,
          'deny_delete' => 0,
        ),
        'author' => array(
          'view' => 0,
          'update' => 0,
          'delete' => 0,
        ),
        'all' => array(
          'view' => 0,
        ),
        'unused' => '0',
        'views' => array(
          'view' => '',
          'view_args' => '',
        ),
        'priority' => '2',
      ),
    ),
  );
  $export['nodeaccess_userreference'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'nodeformscols_field_placements_contact_record_default';
  $strongarm->value = array(
    'title' => array(
      'region' => 'main',
      'weight' => '0',
      'has_required' => TRUE,
      'title' => 'Title',
    ),
    'additional_settings' => array(
      'region' => 'main',
      'weight' => '6',
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
    'body' => array(
      'region' => 'main',
      'weight' => '2',
      'has_required' => FALSE,
      'title' => 'Body',
      'hidden' => 0,
    ),
    'field_files' => array(
      'region' => 'right',
      'weight' => '3',
      'has_required' => FALSE,
      'title' => 'Files',
      'hidden' => 0,
    ),
    'field_site' => array(
      'region' => 'right',
      'weight' => '1',
      'has_required' => FALSE,
      'title' => 'Site',
      'hidden' => 0,
    ),
    'field_contact' => array(
      'region' => 'main',
      'weight' => '1',
      'has_required' => FALSE,
      'title' => 'Contact type',
      'hidden' => 0,
    ),
    'field_contact_tags' => array(
      'region' => 'right',
      'weight' => '2',
      'has_required' => FALSE,
      'title' => 'Contact tags',
      'hidden' => 0,
    ),
  );
  $export['nodeformscols_field_placements_contact_record_default'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'nodeformscols_field_placements_coordinator_default';
  $strongarm->value = array(
    'additional_settings' => array(
      'region' => 'main',
      'weight' => '5',
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
    'field_site' => array(
      'region' => 'right',
      'weight' => '1',
      'has_required' => TRUE,
      'title' => 'Site',
    ),
    'field_site_restrict' => array(
      'region' => 'right',
      'weight' => '5',
      'has_required' => FALSE,
      'title' => 'Restrict to',
      'hidden' => 0,
    ),
    'field_email' => array(
      'region' => 'main',
      'weight' => '3',
      'has_required' => FALSE,
      'title' => 'Email address',
      'hidden' => 0,
    ),
    'field_first_name' => array(
      'region' => 'main',
      'weight' => '1',
      'has_required' => FALSE,
      'title' => 'First Name',
      'hidden' => 0,
    ),
    'field_last_name' => array(
      'region' => 'main',
      'weight' => '2',
      'has_required' => FALSE,
      'title' => 'Last Name',
      'hidden' => 0,
    ),
    'field_phone' => array(
      'region' => 'main',
      'weight' => '4',
      'has_required' => FALSE,
      'title' => 'Phone number',
      'hidden' => 0,
    ),
    'notifications' => array(
      'region' => 'main',
      'weight' => '6',
      'has_required' => FALSE,
      'title' => 'Notifications',
      'collapsed' => 0,
      'hidden' => 0,
    ),
    'field_signups_max' => array(
      'region' => 'right',
      'weight' => '4',
      'has_required' => FALSE,
      'title' => 'Maximum number of students',
      'hidden' => 0,
    ),
    'field_staff_role' => array(
      'region' => 'main',
      'weight' => '0',
      'has_required' => FALSE,
      'title' => 'Role',
      'hidden' => 0,
    ),
    'field_staff_signup_available' => array(
      'region' => 'right',
      'weight' => '3',
      'has_required' => FALSE,
      'title' => 'Students can register with this staff',
      'hidden' => 0,
    ),
  );
  $export['nodeformscols_field_placements_coordinator_default'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'nodeformscols_field_placements_file_default';
  $strongarm->value = array(
    'title' => array(
      'region' => 'main',
      'weight' => '0',
      'has_required' => TRUE,
      'title' => 'File name',
    ),
    'additional_settings' => array(
      'region' => 'main',
      'weight' => '5',
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
    'body' => array(
      'region' => 'main',
      'weight' => '1',
      'has_required' => FALSE,
      'title' => 'File description or notes',
      'hidden' => 0,
    ),
    'field_expiration_date' => array(
      'region' => 'right',
      'weight' => '3',
      'has_required' => FALSE,
      'title' => 'Expiration date',
      'hidden' => 0,
    ),
    'field_expiration_reminder' => array(
      'region' => 'right',
      'weight' => '4',
      'has_required' => FALSE,
      'title' => 'Enable expiration reminder',
      'hidden' => 0,
    ),
    'field_expiration_reminder_date' => array(
      'region' => 'right',
      'weight' => '5',
      'has_required' => FALSE,
      'title' => 'Reminder date',
      'hidden' => 0,
    ),
    'field_file_category' => array(
      'region' => 'right',
      'weight' => '1',
      'has_required' => FALSE,
      'title' => 'File category',
      'hidden' => 0,
    ),
    'field_file_tags' => array(
      'region' => 'right',
      'weight' => '2',
      'has_required' => FALSE,
      'title' => 'Tags',
      'hidden' => 0,
    ),
    'field_files' => array(
      'region' => 'main',
      'weight' => '2',
      'has_required' => FALSE,
      'title' => 'Files',
      'hidden' => 0,
    ),
    'field_site' => array(
      'region' => 'main',
      'weight' => '3',
      'has_required' => FALSE,
      'title' => 'Site',
      'hidden' => 0,
    ),
    'notifications' => array(
      'region' => 'main',
      'weight' => '6',
      'has_required' => FALSE,
      'title' => 'Notifications',
      'collapsed' => 0,
      'hidden' => 0,
    ),
  );
  $export['nodeformscols_field_placements_file_default'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'nodeformscols_field_placements_site_default';
  $strongarm->value = array(
    'title' => array(
      'region' => 'main',
      'weight' => '0',
      'has_required' => TRUE,
      'title' => 'Site Name',
    ),
    'additional_settings' => array(
      'region' => 'main',
      'weight' => '7',
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
    'body' => array(
      'region' => 'main',
      'weight' => '4',
      'has_required' => FALSE,
      'title' => 'Site description',
      'hidden' => 0,
    ),
    'field_site_images' => array(
      'region' => 'main',
      'weight' => '10',
      'has_required' => FALSE,
      'title' => 'Site Images',
      'hidden' => 0,
    ),
    'field_tags' => array(
      'region' => 'right',
      'weight' => '9',
      'has_required' => FALSE,
      'title' => 'Tags',
      'hidden' => 0,
    ),
    'field_site_restrict' => array(
      'region' => 'right',
      'weight' => '3',
      'has_required' => TRUE,
      'title' => 'Restrict site to',
    ),
    'field_location' => array(
      'region' => 'main',
      'weight' => '6',
      'has_required' => FALSE,
      'title' => 'Location(s)',
      'hidden' => 0,
    ),
    'field_website' => array(
      'region' => 'main',
      'weight' => '2',
      'has_required' => FALSE,
      'title' => 'Website',
      'hidden' => 0,
    ),
    'field_csu_facility' => array(
      'region' => 'right',
      'weight' => '6',
      'has_required' => FALSE,
      'title' => 'Issues addressed',
      'hidden' => 0,
    ),
    'field_csu_org_type' => array(
      'region' => 'right',
      'weight' => '7',
      'has_required' => FALSE,
      'title' => 'Organization type',
      'hidden' => 0,
    ),
    'field_site_users' => array(
      'region' => 'right',
      'weight' => '10',
      'has_required' => FALSE,
      'title' => 'Additional users',
      'hidden' => 0,
    ),
    'field_site_form' => array(
      'region' => 'right',
      'weight' => '4',
      'has_required' => FALSE,
      'title' => 'Signup form',
      'hidden' => 0,
    ),
    'field_site_instructions' => array(
      'region' => 'main',
      'weight' => '5',
      'has_required' => FALSE,
      'title' => 'Special site instructions',
      'hidden' => 0,
    ),
    'field_site_email' => array(
      'region' => 'main',
      'weight' => '8',
      'has_required' => FALSE,
      'title' => 'Contact email',
      'hidden' => 0,
    ),
    'field_phone' => array(
      'region' => 'main',
      'weight' => '9',
      'has_required' => FALSE,
      'title' => 'Main phone number',
      'hidden' => 0,
    ),
    'field_site_eval_form' => array(
      'region' => 'right',
      'weight' => '5',
      'has_required' => FALSE,
      'title' => 'Evaluation Form',
      'hidden' => 0,
    ),
    'notifications' => array(
      'region' => 'main',
      'weight' => '1',
      'has_required' => FALSE,
      'title' => 'Notifications',
      'collapsed' => 0,
      'hidden' => 0,
    ),
    'field_site_instructions_required' => array(
      'region' => 'main',
      'weight' => '17',
      'has_required' => FALSE,
      'title' => 'Site has special requirements',
      'hidden' => 0,
    ),
    'field_signups_max' => array(
      'region' => 'main',
      'weight' => '15',
      'has_required' => FALSE,
      'title' => 'Maximum number of students your site can accept at any given time',
      'hidden' => 0,
    ),
    'field_site_hours_minimum' => array(
      'region' => 'main',
      'weight' => '16',
      'has_required' => FALSE,
      'title' => 'What is the minimum number of hours you would require of a student in service per term',
      'hidden' => 0,
    ),
    'field_site_projects' => array(
      'region' => 'main',
      'weight' => '-3',
      'has_required' => FALSE,
      'title' => 'Briefly describe any ongoing needs or special projects with which students can assist agency staff',
      'hidden' => 0,
    ),
    'field_site_hours' => array(
      'region' => 'main',
      'weight' => '18',
      'has_required' => FALSE,
      'title' => 'Days and hours will you accept students for service (check all that apply)',
      'hidden' => 0,
    ),
    'field_site_facebook_page' => array(
      'region' => 'main',
      'weight' => '1',
      'has_required' => FALSE,
      'title' => 'Social network page',
      'hidden' => 0,
    ),
    'field_site_demographics' => array(
      'region' => 'main',
      'weight' => '3',
      'has_required' => FALSE,
      'title' => 'By percentage, what is the demographic of the population you serve?',
      'hidden' => 0,
    ),
    'field_site_language' => array(
      'region' => 'right',
      'weight' => '8',
      'has_required' => FALSE,
      'title' => 'What languages would you like students to speak other than English?',
      'hidden' => 0,
    ),
    'field_site_health_training' => array(
      'region' => 'main',
      'weight' => '20',
      'has_required' => FALSE,
      'title' => 'Training and orientation information',
      'hidden' => 0,
    ),
    'field_site_tour' => array(
      'region' => 'main',
      'weight' => '21',
      'has_required' => FALSE,
      'title' => 'Site Tour',
      'hidden' => 0,
    ),
    'field_health_risk' => array(
      'region' => 'main',
      'weight' => '22',
      'has_required' => FALSE,
      'title' => 'Risk Identification',
      'hidden' => 0,
    ),
    'field_site_requirements' => array(
      'region' => 'main',
      'weight' => '19',
      'has_required' => FALSE,
      'title' => 'Site special requirements',
      'hidden' => 0,
    ),
    'field_workflow_status' => array(
      'region' => 'right',
      'weight' => '2',
      'has_required' => FALSE,
      'title' => 'Status',
      'hidden' => 0,
    ),
    'field_district_federal' => array(
      'region' => 'main',
      'weight' => '2',
      'has_required' => FALSE,
      'title' => 'Federal district',
      'hidden' => 0,
    ),
    'field_district_state_lower' => array(
      'region' => 'main',
      'weight' => '4',
      'has_required' => FALSE,
      'title' => 'State lower district',
      'hidden' => 0,
    ),
    'field_district_state_upper' => array(
      'region' => 'main',
      'weight' => '3',
      'has_required' => FALSE,
      'title' => 'State upper district',
      'hidden' => 0,
    ),
    'field_population_size' => array(
      'region' => 'main',
      'weight' => '26',
      'has_required' => FALSE,
      'title' => 'How many people does your organization serve?',
      'hidden' => 0,
    ),
    'captcha' => array(
      'region' => 'right',
      'weight' => '1',
      'has_required' => FALSE,
      'title' => 'CAPTCHA',
      'hidden' => 0,
    ),
  );
  $export['nodeformscols_field_placements_site_default'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'pathauto_node_contact_record_pattern';
  $strongarm->value = 'notes/[node:nid]';
  $export['pathauto_node_contact_record_pattern'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'pathauto_node_coordinator_pattern';
  $strongarm->value = 'site-staff/[node:nid]';
  $export['pathauto_node_coordinator_pattern'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'pathauto_node_file_pattern';
  $strongarm->value = 'form/[node:nid]';
  $export['pathauto_node_file_pattern'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'pathauto_node_site_pattern';
  $strongarm->value = 'sites/[node:title]';
  $export['pathauto_node_site_pattern'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'pathauto_node_webform_pattern';
  $strongarm->value = 'form/[node:nid]';
  $export['pathauto_node_webform_pattern'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 's4_sites_field_access';
  $strongarm->value = array(
    'field_site_form' => FALSE,
    'field_site_restrict' => FALSE,
    'field_site_users' => FALSE,
    'field_site_eval_form' => FALSE,
    'field_workflow_status' => FALSE,
    'field_health_risk' => FALSE,
    'field_site_tour' => FALSE,
    'field_population_size' => FALSE,
    'field_district_federal' => FALSE,
    'field_district_state_lower' => FALSE,
    'field_district_state_upper' => FALSE,
    'field_phone' => FALSE,
  );
  $export['s4_sites_field_access'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'talk_link';
  $strongarm->value = '';
  $export['talk_link'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'talk_page';
  $strongarm->value = '[node:title]';
  $export['talk_page'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'talk_page_no_comments';
  $strongarm->value = 1;
  $export['talk_page_no_comments'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'talk_tab';
  $strongarm->value = 'Approval';
  $export['talk_tab'] = $strongarm;

  return $export;
}
