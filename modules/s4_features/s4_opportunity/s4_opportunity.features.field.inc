<?php
/**
 * @file
 * s4_opportunity.features.field.inc
 */

/**
 * Implements hook_field_default_fields().
 */
function s4_opportunity_field_default_fields() {
  $fields = array();

  // Exported field: 'relation-opportunity_placement-endpoints'
  $fields['relation-opportunity_placement-endpoints'] = array(
    'field_config' => array(
      'active' => '1',
      'cardinality' => '-1',
      'deleted' => '0',
      'entity_types' => array(),
      'field_name' => 'endpoints',
      'foreign keys' => array(),
      'indexes' => array(
        'relation' => array(
          0 => 'entity_type',
          1 => 'entity_id',
          2 => 'r_index',
        ),
      ),
      'module' => 'relation_endpoint',
      'settings' => array(),
      'translatable' => '0',
      'type' => 'relation_endpoint',
    ),
    'field_instance' => array(
      'bundle' => 'opportunity_placement',
      'default_value' => NULL,
      'deleted' => '0',
      'description' => '',
      'display' => array(
        'default' => array(
          'label' => 'above',
          'module' => 'relation_endpoint',
          'settings' => array(
            'view_modes' => array(
              'field_collection_item' => 'default',
              'file' => 'default',
              'messaging_destination' => 'default',
              'messaging_message' => 'default',
              'node' => 'default',
              'notifications_event' => 'default',
              'notifications_subscription' => 'default',
              'relation' => 'default',
              's4_opportunity' => 'default',
              's4_opportunity_type' => 'default',
              'taxonomy_term' => 'default',
              'taxonomy_vocabulary' => 'default',
              'user' => 'default',
              'webform_submission_entity' => 'default',
              'webform_submission_entity_type' => 'default',
              'wysiwyg_profile' => 'default',
            ),
          ),
          'type' => 'relation_endpoint',
          'weight' => 0,
        ),
      ),
      'entity_type' => 'relation',
      'field_name' => 'endpoints',
      'label' => 'endpoints',
      'required' => FALSE,
      'settings' => array(
        'custom_add_another' => '',
        'user_register_form' => FALSE,
      ),
      'widget' => array(
        'module' => 'relation_endpoint',
        'settings' => array(),
        'type' => 'relation_endpoint',
        'weight' => '0',
      ),
    ),
  );

  // Exported field: 'relation-opportunity_placement-field_coordinator'
  $fields['relation-opportunity_placement-field_coordinator'] = array(
    'field_config' => array(
      'active' => '1',
      'cardinality' => '1',
      'deleted' => '0',
      'entity_types' => array(),
      'field_name' => 'field_coordinator',
      'foreign keys' => array(
        'nid' => array(
          'columns' => array(
            'nid' => 'nid',
          ),
          'table' => 'node',
        ),
      ),
      'global_block_settings' => '2',
      'indexes' => array(
        'nid' => array(
          0 => 'nid',
        ),
      ),
      'module' => 'node_reference',
      'settings' => array(
        'nodeaccess_nodereference' => array(
          'all' => array(
            'view' => 0,
          ),
          'author' => array(
            'delete' => 0,
            'update' => 'update',
            'view' => 'view',
          ),
          'priority' => '0',
          'referenced' => array(
            'delete' => array(
              'delete' => 0,
              'update' => 0,
              'view' => 'view',
            ),
            'update' => array(
              'delete' => 0,
              'update' => 0,
              'view' => 'view',
            ),
            'view' => array(
              'delete' => 0,
              'update' => 0,
              'view' => 0,
            ),
          ),
        ),
        'referenceable_types' => array(
          'contact_record' => 0,
          'coordinator' => 'coordinator',
          'course' => 0,
          'course_term' => 0,
          'downloadable_form' => 0,
          'file' => 0,
          'page' => 0,
          'signup' => 0,
          'site' => 0,
          'webform' => 0,
        ),
        'view' => array(
          'args' => array(),
          'display_name' => '',
          'view_name' => '',
        ),
      ),
      'translatable' => '1',
      'type' => 'node_reference',
    ),
    'field_instance' => array(
      'bundle' => 'opportunity_placement',
      'default_value' => NULL,
      'deleted' => '0',
      'description' => '',
      'display' => array(
        'default' => array(
          'label' => 'above',
          'module' => 'node_reference',
          'settings' => array(),
          'type' => 'node_reference_default',
          'weight' => 1,
        ),
      ),
      'display_label' => '',
      'entity_type' => 'relation',
      'field_name' => 'field_coordinator',
      'label' => 'Site staff',
      'required' => 0,
      'settings' => array(
        'custom_add_another' => '',
        'user_register_form' => FALSE,
      ),
      'widget' => array(
        'active' => 1,
        'module' => 'node_reference',
        'settings' => array(
          'autocomplete_match' => 'contains',
          'autocomplete_path' => 'node_reference/autocomplete',
          'edit_fallback' => 0,
          'fallback' => 'select',
          'node_link' => array(
            'destination' => 'default',
            'full' => 0,
            'hover_title' => '',
            'teaser' => 0,
            'title' => '',
          ),
          'size' => 60,
        ),
        'type' => 'node_reference_autocomplete',
        'weight' => '1',
      ),
    ),
  );

  // Exported field: 'relation-opportunity_placement-field_course'
  $fields['relation-opportunity_placement-field_course'] = array(
    'field_config' => array(
      'active' => '1',
      'cardinality' => '1',
      'deleted' => '0',
      'entity_types' => array(),
      'field_name' => 'field_course',
      'foreign keys' => array(
        'nid' => array(
          'columns' => array(
            'nid' => 'nid',
          ),
          'table' => 'node',
        ),
      ),
      'global_block_settings' => '2',
      'indexes' => array(
        'nid' => array(
          0 => 'nid',
        ),
      ),
      'module' => 'node_reference',
      'settings' => array(
        'nodeaccess_nodereference' => array(
          'all' => array(
            'view' => 0,
          ),
          'author' => array(
            'delete' => 0,
            'update' => 'update',
            'view' => 'view',
          ),
          'priority' => '0',
          'referenced' => array(
            'delete' => array(
              'delete' => 0,
              'update' => 0,
              'view' => 0,
            ),
            'update' => array(
              'delete' => 0,
              'update' => 0,
              'view' => 'view',
            ),
            'view' => array(
              'delete' => 0,
              'update' => 0,
              'view' => 0,
            ),
          ),
        ),
        'referenceable_types' => array(
          'contact_record' => 0,
          'coordinator' => 0,
          'course' => 'course',
          'course_term' => 0,
          'downloadable_form' => 0,
          'file' => 0,
          'page' => 0,
          'signup' => 0,
          'site' => 0,
          'webform' => 0,
        ),
        'view' => array(
          'args' => array(),
          'display_name' => '',
          'view_name' => '',
        ),
      ),
      'translatable' => '1',
      'type' => 'node_reference',
    ),
    'field_instance' => array(
      'bundle' => 'opportunity_placement',
      'default_value' => NULL,
      'deleted' => '0',
      'description' => '',
      'display' => array(
        'default' => array(
          'label' => 'above',
          'module' => 'node_reference',
          'settings' => array(),
          'type' => 'node_reference_default',
          'weight' => 2,
        ),
      ),
      'display_label' => '',
      'entity_type' => 'relation',
      'field_name' => 'field_course',
      'label' => 'Course',
      'required' => 0,
      'settings' => array(
        'custom_add_another' => '',
        'user_register_form' => FALSE,
      ),
      'widget' => array(
        'active' => 1,
        'module' => 'node_reference',
        'settings' => array(
          'autocomplete_match' => 'contains',
          'autocomplete_path' => 'node_reference/autocomplete',
          'edit_fallback' => 0,
          'fallback' => 'select',
          'node_link' => array(
            'destination' => 'default',
            'full' => 0,
            'hover_title' => '',
            'teaser' => 0,
            'title' => '',
          ),
          'size' => 60,
        ),
        'type' => 'node_reference_autocomplete',
        'weight' => '2',
      ),
    ),
  );

  // Exported field: 'relation-opportunity_placement-field_dates'
  $fields['relation-opportunity_placement-field_dates'] = array(
    'field_config' => array(
      'active' => '1',
      'cardinality' => '1',
      'deleted' => '0',
      'entity_types' => array(),
      'field_name' => 'field_dates',
      'foreign keys' => array(),
      'indexes' => array(),
      'module' => 'date',
      'settings' => array(
        'cache_count' => '4',
        'cache_enabled' => 0,
        'granularity' => array(
          'day' => 'day',
          'hour' => 0,
          'minute' => 0,
          'month' => 'month',
          'second' => 0,
          'year' => 'year',
        ),
        'timezone_db' => '',
        'todate' => 'optional',
        'tz_handling' => 'none',
      ),
      'translatable' => '0',
      'type' => 'datetime',
    ),
    'field_instance' => array(
      'bundle' => 'opportunity_placement',
      'deleted' => '0',
      'description' => '',
      'display' => array(
        'default' => array(
          'label' => 'above',
          'module' => 'date',
          'settings' => array(
            'format_type' => 'long',
            'fromto' => 'both',
            'multiple_from' => '',
            'multiple_number' => '',
            'multiple_to' => '',
          ),
          'type' => 'date_default',
          'weight' => 3,
        ),
      ),
      'display_label' => '',
      'entity_type' => 'relation',
      'field_name' => 'field_dates',
      'label' => 'Dates',
      'required' => 0,
      'settings' => array(
        'custom_add_another' => '',
        'default_value' => 'now',
        'default_value2' => 'same',
        'default_value_code' => '',
        'default_value_code2' => '',
        'user_register_form' => FALSE,
      ),
      'widget' => array(
        'active' => 1,
        'module' => 'date',
        'settings' => array(
          'display_all_day' => 0,
          'increment' => '15',
          'input_format' => 'm/d/Y - H:i:s',
          'input_format_custom' => '',
          'label_position' => 'above',
          'text_parts' => array(),
          'year_range' => '-3:+3',
        ),
        'type' => 'date_popup',
        'weight' => '3',
      ),
    ),
  );

  // Exported field: 'relation-opportunity_placement-field_form_signup_sid'
  $fields['relation-opportunity_placement-field_form_signup_sid'] = array(
    'field_config' => array(
      'active' => '1',
      'cardinality' => '1',
      'deleted' => '0',
      'entity_types' => array(),
      'field_name' => 'field_form_signup_sid',
      'foreign keys' => array(),
      'global_block_settings' => '1',
      'indexes' => array(),
      'module' => 'number',
      'settings' => array(),
      'translatable' => '1',
      'type' => 'number_integer',
    ),
    'field_instance' => array(
      'bundle' => 'opportunity_placement',
      'default_value' => NULL,
      'deleted' => '0',
      'description' => '',
      'display' => array(
        'default' => array(
          'label' => 'above',
          'module' => 'number',
          'settings' => array(
            'decimal_separator' => '.',
            'prefix_suffix' => TRUE,
            'scale' => 0,
            'thousand_separator' => ' ',
          ),
          'type' => 'number_integer',
          'weight' => 4,
        ),
      ),
      'display_label' => '',
      'entity_type' => 'relation',
      'field_name' => 'field_form_signup_sid',
      'label' => 'Signup Form Results',
      'required' => 0,
      'settings' => array(
        'custom_add_another' => '',
        'max' => '',
        'min' => '',
        'prefix' => '',
        'suffix' => '',
        'user_register_form' => FALSE,
      ),
      'widget' => array(
        'active' => 0,
        'module' => 'number',
        'settings' => array(),
        'type' => 'number',
        'weight' => '4',
      ),
    ),
  );

  // Translatables
  // Included for use with string extractors like potx.
  t('Course');
  t('Dates');
  t('Signup Form Results');
  t('Site staff');
  t('endpoints');

  return $fields;
}
