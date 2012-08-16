<?php
/**
 * @file
 * s4_sites.features.field.inc
 */

/**
 * Implements hook_field_default_fields().
 */
function s4_sites_field_default_fields() {
  $fields = array();

  // Exported field: 'field_collection_item-field_site_evaluation_group-field_site_eval_form'
  $fields['field_collection_item-field_site_evaluation_group-field_site_eval_form'] = array(
    'field_config' => array(
      'active' => '1',
      'cardinality' => '1',
      'deleted' => '0',
      'entity_types' => array(),
      'field_name' => 'field_site_eval_form',
      'foreign keys' => array(
        'nid' => array(
          'columns' => array(
            'nid' => 'nid',
          ),
          'table' => 'node',
        ),
      ),
      'global_block_settings' => '1',
      'indexes' => array(
        'nid' => array(
          0 => 'nid',
        ),
      ),
      'module' => 'node_reference',
      'settings' => array(
        'nodeaccess_nodereference' => array(
          'all' => array(
            'view' => 'view',
          ),
          'author' => array(
            'delete' => 0,
            'update' => 0,
            'view' => 0,
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
              'view' => 0,
            ),
            'view' => array(
              'delete' => 0,
              'update' => 0,
              'view' => 0,
            ),
          ),
          'unused' => '0',
        ),
        'referenceable_types' => array(
          'contact_record' => 0,
          'coordinator' => 0,
          'course' => 0,
          'course_term' => 0,
          'downloadable_form' => 0,
          'fieldtrip' => 0,
          'file' => 0,
          'page' => 0,
          'signup' => 0,
          'site' => 0,
          'webform' => 'webform',
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
      'bundle' => 'field_site_evaluation_group',
      'default_value' => NULL,
      'deleted' => '0',
      'description' => '',
      'display' => array(
        'default' => array(
          'label' => 'above',
          'module' => 'node_reference',
          'settings' => array(),
          'type' => 'node_reference_default',
          'weight' => 0,
        ),
      ),
      'display_label' => '',
      'entity_type' => 'field_collection_item',
      'field_name' => 'field_site_eval_form',
      'label' => 'Form',
      'required' => 0,
      'settings' => array(
        'user_register_form' => FALSE,
      ),
      'widget' => array(
        'active' => 1,
        'module' => 'nodereference_url',
        'settings' => array(
          'edit_fallback' => 0,
          'fallback' => 'select',
          'node_link' => array(
            'destination' => 'default',
            'full' => 0,
            'hover_title' => '',
            'teaser' => 0,
            'title' => '',
          ),
        ),
        'type' => 'nodereference_url',
        'weight' => '0',
      ),
    ),
  );

  // Exported field: 'field_collection_item-field_site_evaluation_group-field_site_restrict'
  $fields['field_collection_item-field_site_evaluation_group-field_site_restrict'] = array(
    'field_config' => array(
      'active' => '1',
      'cardinality' => '-1',
      'deleted' => '0',
      'entity_types' => array(),
      'field_name' => 'field_site_restrict',
      'foreign keys' => array(
        'tid' => array(
          'columns' => array(
            'tid' => 'tid',
          ),
          'table' => 'taxonomy_term_data',
        ),
      ),
      'global_block_settings' => '2',
      'indexes' => array(
        'tid' => array(
          0 => 'tid',
        ),
      ),
      'module' => 'taxonomy',
      'settings' => array(
        'allowed_values' => array(
          0 => array(
            'vocabulary' => 'site_restrictions',
            'parent' => '0',
          ),
        ),
      ),
      'translatable' => '1',
      'type' => 'taxonomy_term_reference',
    ),
    'field_instance' => array(
      'bundle' => 'field_site_evaluation_group',
      'default_value' => NULL,
      'deleted' => '0',
      'description' => '',
      'display' => array(
        'default' => array(
          'label' => 'above',
          'module' => 'taxonomy',
          'settings' => array(),
          'type' => 'taxonomy_term_reference_link',
          'weight' => 1,
        ),
      ),
      'display_label' => '',
      'entity_type' => 'field_collection_item',
      'field_name' => 'field_site_restrict',
      'label' => 'Program',
      'required' => 0,
      'settings' => array(
        'user_register_form' => FALSE,
      ),
      'widget' => array(
        'active' => 1,
        'module' => 'options',
        'settings' => array(),
        'type' => 'options_select',
        'weight' => '1',
      ),
    ),
  );

  // Exported field: 'field_collection_item-field_site_signup_group-field_site_form'
  $fields['field_collection_item-field_site_signup_group-field_site_form'] = array(
    'field_config' => array(
      'active' => '1',
      'cardinality' => '1',
      'deleted' => '0',
      'entity_types' => array(),
      'field_name' => 'field_site_form',
      'foreign keys' => array(
        'nid' => array(
          'columns' => array(
            'nid' => 'nid',
          ),
          'table' => 'node',
        ),
      ),
      'global_block_settings' => '1',
      'indexes' => array(
        'nid' => array(
          0 => 'nid',
        ),
      ),
      'module' => 'node_reference',
      'settings' => array(
        'nodeaccess_nodereference' => array(
          'all' => array(
            'view' => 'view',
          ),
          'author' => array(
            'delete' => 0,
            'update' => 0,
            'view' => 0,
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
              'view' => 0,
            ),
            'view' => array(
              'delete' => 0,
              'update' => 0,
              'view' => 0,
            ),
          ),
          'unused' => '0',
        ),
        'referenceable_types' => array(
          'contact_record' => 0,
          'coordinator' => 0,
          'course' => 0,
          'course_term' => 0,
          'downloadable_form' => 0,
          'fieldtrip' => 0,
          'file' => 0,
          'page' => 0,
          'signup' => 0,
          'site' => 0,
          'webform' => 'webform',
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
      'bundle' => 'field_site_signup_group',
      'default_value' => NULL,
      'deleted' => '0',
      'description' => '',
      'display' => array(
        'default' => array(
          'label' => 'above',
          'module' => 'node_reference',
          'settings' => array(),
          'type' => 'node_reference_default',
          'weight' => 0,
        ),
      ),
      'display_label' => '',
      'entity_type' => 'field_collection_item',
      'field_name' => 'field_site_form',
      'label' => 'Form',
      'required' => 0,
      'settings' => array(
        'user_register_form' => FALSE,
      ),
      'widget' => array(
        'active' => 1,
        'module' => 'options',
        'settings' => array(),
        'type' => 'options_select',
        'weight' => '0',
      ),
    ),
  );

  // Exported field: 'field_collection_item-field_site_signup_group-field_site_restrict'
  $fields['field_collection_item-field_site_signup_group-field_site_restrict'] = array(
    'field_config' => array(
      'active' => '1',
      'cardinality' => '-1',
      'deleted' => '0',
      'entity_types' => array(),
      'field_name' => 'field_site_restrict',
      'foreign keys' => array(
        'tid' => array(
          'columns' => array(
            'tid' => 'tid',
          ),
          'table' => 'taxonomy_term_data',
        ),
      ),
      'global_block_settings' => '2',
      'indexes' => array(
        'tid' => array(
          0 => 'tid',
        ),
      ),
      'module' => 'taxonomy',
      'settings' => array(
        'allowed_values' => array(
          0 => array(
            'vocabulary' => 'site_restrictions',
            'parent' => '0',
          ),
        ),
      ),
      'translatable' => '1',
      'type' => 'taxonomy_term_reference',
    ),
    'field_instance' => array(
      'bundle' => 'field_site_signup_group',
      'default_value' => NULL,
      'deleted' => '0',
      'description' => '',
      'display' => array(
        'default' => array(
          'label' => 'above',
          'module' => 'taxonomy',
          'settings' => array(),
          'type' => 'taxonomy_term_reference_link',
          'weight' => 1,
        ),
      ),
      'display_label' => '',
      'entity_type' => 'field_collection_item',
      'field_name' => 'field_site_restrict',
      'label' => 'Available to',
      'required' => 0,
      'settings' => array(
        'user_register_form' => FALSE,
      ),
      'widget' => array(
        'active' => 1,
        'module' => 'options',
        'settings' => array(),
        'type' => 'options_select',
        'weight' => '1',
      ),
    ),
  );

  // Exported field: 'node-contact_record-body'
  $fields['node-contact_record-body'] = array(
    'field_config' => array(
      'active' => '1',
      'cardinality' => '1',
      'deleted' => '0',
      'entity_types' => array(
        0 => 'node',
      ),
      'field_name' => 'body',
      'foreign keys' => array(
        'format' => array(
          'columns' => array(
            'format' => 'format',
          ),
          'table' => 'filter_format',
        ),
      ),
      'global_block_settings' => '2',
      'indexes' => array(
        'format' => array(
          0 => 'format',
        ),
      ),
      'module' => 'text',
      'settings' => array(),
      'translatable' => '1',
      'type' => 'text_with_summary',
    ),
    'field_instance' => array(
      'bundle' => 'contact_record',
      'default_value' => NULL,
      'deleted' => '0',
      'description' => '',
      'display' => array(
        'default' => array(
          'label' => 'hidden',
          'module' => 'text',
          'settings' => array(),
          'type' => 'text_default',
          'weight' => '0',
        ),
        'notifications' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => 0,
        ),
        'teaser' => array(
          'label' => 'hidden',
          'module' => 'text',
          'settings' => array(
            'trim_length' => 600,
          ),
          'type' => 'text_summary_or_trimmed',
          'weight' => 0,
        ),
      ),
      'entity_type' => 'node',
      'field_name' => 'body',
      'label' => 'Body',
      'required' => FALSE,
      'settings' => array(
        'display_summary' => TRUE,
        'text_processing' => 1,
        'user_register_form' => FALSE,
      ),
      'widget' => array(
        'module' => 'text',
        'settings' => array(
          'rows' => 20,
          'summary_rows' => 5,
        ),
        'type' => 'text_textarea_with_summary',
        'weight' => '1',
      ),
      'widget_type' => 'text_textarea_with_summary',
    ),
  );

  // Exported field: 'node-contact_record-field_contact'
  $fields['node-contact_record-field_contact'] = array(
    'field_config' => array(
      'active' => '1',
      'cardinality' => '1',
      'deleted' => '0',
      'entity_types' => array(),
      'field_name' => 'field_contact',
      'foreign keys' => array(),
      'global_block_settings' => '2',
      'indexes' => array(
        'value' => array(
          0 => 'value',
        ),
      ),
      'module' => 'list',
      'settings' => array(
        'allowed_values' => array(
          'Email' => 'Email',
          'In-person' => 'In-person',
          'Internal' => 'Internal',
          'Phone' => 'Phone',
          'Site visit' => 'Site visit',
        ),
        'allowed_values_function' => '',
        'allowed_values_php' => '',
      ),
      'translatable' => '1',
      'type' => 'list_text',
    ),
    'field_instance' => array(
      'bundle' => 'contact_record',
      'default_value' => NULL,
      'default_value_function' => '',
      'default_value_php' => '',
      'deleted' => '0',
      'description' => '',
      'display' => array(
        'default' => array(
          'label' => 'above',
          'module' => 'list',
          'settings' => array(),
          'type' => 'list_default',
          'weight' => '3',
        ),
        'notifications' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => 0,
        ),
        'teaser' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => 0,
        ),
      ),
      'entity_type' => 'node',
      'field_name' => 'field_contact',
      'label' => 'Contact type',
      'required' => 0,
      'settings' => array(
        'user_register_form' => FALSE,
      ),
      'widget' => array(
        'active' => 1,
        'module' => 'options',
        'settings' => array(),
        'type' => 'options_select',
        'weight' => '4',
      ),
    ),
  );

  // Exported field: 'node-contact_record-field_contact_tags'
  $fields['node-contact_record-field_contact_tags'] = array(
    'field_config' => array(
      'active' => '1',
      'cardinality' => '-1',
      'deleted' => '0',
      'entity_types' => array(),
      'field_name' => 'field_contact_tags',
      'foreign keys' => array(
        'tid' => array(
          'columns' => array(
            'tid' => 'tid',
          ),
          'table' => 'taxonomy_term_data',
        ),
      ),
      'global_block_settings' => '2',
      'indexes' => array(
        'tid' => array(
          0 => 'tid',
        ),
      ),
      'module' => 'taxonomy',
      'settings' => array(
        'allowed_values' => array(
          0 => array(
            'parent' => '0',
            'vocabulary' => 'contact_tags',
          ),
        ),
      ),
      'translatable' => '1',
      'type' => 'taxonomy_term_reference',
    ),
    'field_instance' => array(
      'bundle' => 'contact_record',
      'default_value' => NULL,
      'deleted' => '0',
      'description' => 'Enter a few tags to help categorize this type of contact',
      'display' => array(
        'default' => array(
          'label' => 'above',
          'module' => 'taxonomy',
          'settings' => array(),
          'type' => 'taxonomy_term_reference_link',
          'weight' => '4',
        ),
        'notifications' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => 0,
        ),
        'teaser' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => 0,
        ),
      ),
      'entity_type' => 'node',
      'field_name' => 'field_contact_tags',
      'label' => 'Contact tags',
      'required' => 0,
      'settings' => array(
        'user_register_form' => FALSE,
      ),
      'widget' => array(
        'active' => 0,
        'module' => 'taxonomy',
        'settings' => array(
          'autocomplete_path' => 'taxonomy/autocomplete',
          'size' => 60,
        ),
        'type' => 'taxonomy_autocomplete',
        'weight' => '5',
      ),
    ),
  );

  // Exported field: 'node-contact_record-field_files'
  $fields['node-contact_record-field_files'] = array(
    'field_config' => array(
      'active' => '1',
      'cardinality' => '-1',
      'deleted' => '0',
      'entity_types' => array(),
      'field_name' => 'field_files',
      'foreign keys' => array(
        'fid' => array(
          'columns' => array(
            'fid' => 'fid',
          ),
          'table' => 'file_managed',
        ),
      ),
      'global_block_settings' => '2',
      'indexes' => array(
        'fid' => array(
          0 => 'fid',
        ),
      ),
      'module' => 'file',
      'settings' => array(
        'display_default' => 1,
        'display_field' => 1,
        'uri_scheme' => 'private',
      ),
      'translatable' => '1',
      'type' => 'file',
    ),
    'field_instance' => array(
      'bundle' => 'contact_record',
      'deleted' => '0',
      'description' => '',
      'display' => array(
        'default' => array(
          'label' => 'above',
          'module' => 'file',
          'settings' => array(),
          'type' => 'file_default',
          'weight' => '5',
        ),
        'notifications' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => 0,
        ),
        'teaser' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => 0,
        ),
      ),
      'display_label' => '',
      'entity_type' => 'node',
      'field_name' => 'field_files',
      'label' => 'Files',
      'required' => 0,
      'settings' => array(
        'description_field' => 0,
        'file_directory' => 'contact/files',
        'file_extensions' => 'txt doc xml xls pdf',
        'max_filesize' => '',
        'user_register_form' => FALSE,
      ),
      'widget' => array(
        'active' => 1,
        'module' => 'file',
        'settings' => array(
          'insert' => 0,
          'insert_class' => '',
          'insert_default' => 'auto',
          'insert_styles' => array(
            'auto' => 'auto',
            'image' => 0,
            'image_large' => 0,
            'image_medium' => 0,
            'image_thumbnail' => 0,
            'link' => 0,
          ),
          'insert_width' => '',
          'progress_indicator' => 'throbber',
        ),
        'type' => 'file_generic',
        'weight' => '3',
      ),
    ),
  );

  // Exported field: 'node-contact_record-field_site'
  $fields['node-contact_record-field_site'] = array(
    'field_config' => array(
      'active' => '1',
      'cardinality' => '1',
      'deleted' => '0',
      'entity_types' => array(),
      'field_name' => 'field_site',
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
            'view' => 'view',
          ),
          'author' => array(
            'delete' => 0,
            'update' => 0,
            'view' => 0,
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
              'view' => 0,
            ),
            'view' => array(
              'delete' => 0,
              'update' => 0,
              'view' => 'view',
            ),
          ),
          'unused' => '0',
        ),
        'referenceable_types' => array(
          'contact_record' => 0,
          'coordinator' => 0,
          'course' => 0,
          'course_term' => 0,
          'file' => 0,
          'news' => 0,
          'page' => 0,
          'signup' => 0,
          'site' => 'site',
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
      'bundle' => 'contact_record',
      'default_value' => NULL,
      'deleted' => '0',
      'description' => '',
      'display' => array(
        'default' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => '11',
        ),
        'notifications' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => 0,
        ),
        'teaser' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => 0,
        ),
      ),
      'entity_type' => 'node',
      'field_name' => 'field_site',
      'label' => 'Site',
      'required' => 0,
      'settings' => array(
        'user_register_form' => FALSE,
      ),
      'widget' => array(
        'active' => 1,
        'module' => 'nodereference_url',
        'settings' => array(
          'edit_fallback' => 0,
          'fallback' => 'select',
          'node_link' => array(
            'destination' => 'default',
            'full' => 0,
            'hover_title' => '',
            'teaser' => 0,
            'title' => 'Add new contact record',
          ),
        ),
        'type' => 'nodereference_url',
        'weight' => '2',
      ),
    ),
  );

  // Exported field: 'node-coordinator-field_email'
  $fields['node-coordinator-field_email'] = array(
    'field_config' => array(
      'active' => '1',
      'cardinality' => '1',
      'deleted' => '0',
      'entity_types' => array(),
      'field_name' => 'field_email',
      'foreign keys' => array(),
      'global_block_settings' => '1',
      'indexes' => array(),
      'module' => 'email',
      'settings' => array(),
      'translatable' => '1',
      'type' => 'email',
    ),
    'field_instance' => array(
      'bundle' => 'coordinator',
      'default_value' => NULL,
      'deleted' => '0',
      'description' => '',
      'display' => array(
        'cck_blocks' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => 0,
        ),
        'default' => array(
          'label' => 'above',
          'module' => 'email',
          'settings' => array(),
          'type' => 'email_default',
          'weight' => '1',
        ),
        'notifications' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => 0,
        ),
        'teaser' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => 0,
        ),
      ),
      'entity_type' => 'node',
      'field_name' => 'field_email',
      'label' => 'Email address',
      'required' => 0,
      'settings' => array(
        'user_register_form' => FALSE,
      ),
      'widget' => array(
        'active' => 1,
        'module' => 'email',
        'settings' => array(
          'size' => '60',
        ),
        'type' => 'email_textfield',
        'weight' => '8',
      ),
    ),
  );

  // Exported field: 'node-coordinator-field_first_name'
  $fields['node-coordinator-field_first_name'] = array(
    'field_config' => array(
      'active' => '1',
      'cardinality' => '1',
      'deleted' => '0',
      'entity_types' => array(),
      'field_name' => 'field_first_name',
      'foreign keys' => array(
        'format' => array(
          'columns' => array(
            'format' => 'format',
          ),
          'table' => 'filter_format',
        ),
      ),
      'global_block_settings' => '1',
      'indexes' => array(
        'format' => array(
          0 => 'format',
        ),
      ),
      'module' => 'text',
      'settings' => array(
        'max_length' => '255',
      ),
      'translatable' => '1',
      'type' => 'text',
    ),
    'field_instance' => array(
      'bundle' => 'coordinator',
      'default_value' => NULL,
      'deleted' => '0',
      'description' => '',
      'display' => array(
        'cck_blocks' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => 0,
        ),
        'default' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => '2',
        ),
        'notifications' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => 0,
        ),
        'teaser' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => 0,
        ),
      ),
      'entity_type' => 'node',
      'field_name' => 'field_first_name',
      'label' => 'First Name',
      'required' => 0,
      'settings' => array(
        'text_processing' => '0',
        'user_register_form' => FALSE,
      ),
      'widget' => array(
        'active' => 1,
        'module' => 'text',
        'settings' => array(
          'size' => '60',
        ),
        'type' => 'text_textfield',
        'weight' => '1',
      ),
    ),
  );

  // Exported field: 'node-coordinator-field_last_name'
  $fields['node-coordinator-field_last_name'] = array(
    'field_config' => array(
      'active' => '1',
      'cardinality' => '1',
      'deleted' => '0',
      'entity_types' => array(),
      'field_name' => 'field_last_name',
      'foreign keys' => array(
        'format' => array(
          'columns' => array(
            'format' => 'format',
          ),
          'table' => 'filter_format',
        ),
      ),
      'global_block_settings' => '1',
      'indexes' => array(
        'format' => array(
          0 => 'format',
        ),
      ),
      'module' => 'text',
      'settings' => array(
        'max_length' => '255',
      ),
      'translatable' => '1',
      'type' => 'text',
    ),
    'field_instance' => array(
      'bundle' => 'coordinator',
      'default_value' => NULL,
      'deleted' => '0',
      'description' => '',
      'display' => array(
        'cck_blocks' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => 0,
        ),
        'default' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => '3',
        ),
        'notifications' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => 0,
        ),
        'teaser' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => 0,
        ),
      ),
      'entity_type' => 'node',
      'field_name' => 'field_last_name',
      'label' => 'Last Name',
      'required' => 0,
      'settings' => array(
        'text_processing' => '0',
        'user_register_form' => FALSE,
      ),
      'widget' => array(
        'active' => 1,
        'module' => 'text',
        'settings' => array(
          'size' => '60',
        ),
        'type' => 'text_textfield',
        'weight' => '2',
      ),
    ),
  );

  // Exported field: 'node-coordinator-field_phone'
  $fields['node-coordinator-field_phone'] = array(
    'field_config' => array(
      'active' => '1',
      'cardinality' => '-1',
      'deleted' => '0',
      'entity_types' => array(),
      'field_name' => 'field_phone',
      'foreign keys' => array(),
      'global_block_settings' => '2',
      'indexes' => array(),
      'module' => 'cck_phone',
      'settings' => array(
        'size' => '15',
      ),
      'translatable' => '1',
      'type' => 'phone_number',
    ),
    'field_instance' => array(
      'bundle' => 'coordinator',
      'deleted' => '0',
      'description' => '',
      'display' => array(
        'cck_blocks' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => 0,
        ),
        'default' => array(
          'label' => 'above',
          'module' => 'cck_phone',
          'settings' => array(),
          'type' => 'global_phone_number',
          'weight' => 6,
        ),
        'notifications' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => 0,
        ),
        'teaser' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => 0,
        ),
      ),
      'display_label' => '',
      'entity_type' => 'node',
      'field_name' => 'field_phone',
      'label' => 'Phone number',
      'required' => 0,
      'settings' => array(
        'all_country_codes' => 0,
        'country_code_position' => 'after',
        'country_codes' => array(
          'country_selection' => array(
            'ad' => 0,
            'ae' => 0,
            'af' => 0,
            'ag' => 0,
            'ai' => 0,
            'al' => 0,
            'am' => 0,
            'an' => 0,
            'ao' => 0,
            'ar' => 0,
            'as' => 0,
            'at' => 0,
            'au' => 0,
            'aw' => 0,
            'az' => 0,
            'ba' => 0,
            'bb' => 0,
            'bd' => 0,
            'be' => 0,
            'bf' => 0,
            'bg' => 0,
            'bh' => 0,
            'bi' => 0,
            'bj' => 0,
            'bm' => 0,
            'bn' => 0,
            'bo' => 0,
            'br' => 0,
            'bs' => 0,
            'bt' => 0,
            'bw' => 0,
            'by' => 0,
            'bz' => 0,
            'ca' => 0,
            'cc' => 0,
            'cd' => 0,
            'cf' => 0,
            'cg' => 0,
            'ch' => 0,
            'ci' => 0,
            'ck' => 0,
            'cl' => 0,
            'cm' => 0,
            'cn' => 0,
            'co' => 0,
            'cr' => 0,
            'cu' => 0,
            'cv' => 0,
            'cx' => 0,
            'cy' => 0,
            'cz' => 0,
            'de' => 0,
            'dj' => 0,
            'dk' => 0,
            'dm' => 0,
            'do' => 0,
            'dz' => 0,
            'ec' => 0,
            'ee' => 0,
            'eg' => 0,
            'er' => 0,
            'es' => 0,
            'et' => 0,
            'fi' => 0,
            'fj' => 0,
            'fk' => 0,
            'fm' => 0,
            'fo' => 0,
            'fr' => 0,
            'ga' => 0,
            'gb' => 0,
            'gd' => 0,
            'ge' => 0,
            'gf' => 0,
            'gh' => 0,
            'gi' => 0,
            'gl' => 0,
            'gm' => 0,
            'gn' => 0,
            'gp' => 0,
            'gq' => 0,
            'gr' => 0,
            'gt' => 0,
            'gu' => 0,
            'gw' => 0,
            'gy' => 0,
            'hk' => 0,
            'hn' => 0,
            'hr' => 0,
            'ht' => 0,
            'hu' => 0,
            'id' => 0,
            'ie' => 0,
            'il' => 0,
            'in' => 0,
            'io' => 0,
            'iq' => 0,
            'ir' => 0,
            'is' => 0,
            'it' => 0,
            'jm' => 0,
            'jo' => 0,
            'jp' => 0,
            'ke' => 0,
            'kg' => 0,
            'kh' => 0,
            'ki' => 0,
            'km' => 0,
            'kn' => 0,
            'kp' => 0,
            'kr' => 0,
            'kw' => 0,
            'ky' => 0,
            'kz' => 0,
            'la' => 0,
            'lb' => 0,
            'lc' => 0,
            'li' => 0,
            'lk' => 0,
            'lr' => 0,
            'ls' => 0,
            'lt' => 0,
            'lu' => 0,
            'lv' => 0,
            'ly' => 0,
            'ma' => 0,
            'mc' => 0,
            'md' => 0,
            'me' => 0,
            'mg' => 0,
            'mh' => 0,
            'mk' => 0,
            'ml' => 0,
            'mm' => 0,
            'mn' => 0,
            'mo' => 0,
            'mp' => 0,
            'mq' => 0,
            'mr' => 0,
            'ms' => 0,
            'mt' => 0,
            'mu' => 0,
            'mv' => 0,
            'mw' => 0,
            'mx' => 0,
            'my' => 0,
            'mz' => 0,
            'na' => 0,
            'nc' => 0,
            'ne' => 0,
            'nf' => 0,
            'ng' => 0,
            'ni' => 0,
            'nl' => 0,
            'no' => 0,
            'np' => 0,
            'nr' => 0,
            'nu' => 0,
            'nz' => 0,
            'om' => 0,
            'pa' => 0,
            'pe' => 0,
            'pf' => 0,
            'pg' => 0,
            'ph' => 0,
            'pk' => 0,
            'pl' => 0,
            'pm' => 0,
            'pr' => 0,
            'ps' => 0,
            'pt' => 0,
            'pw' => 0,
            'py' => 0,
            'qa' => 0,
            'ro' => 0,
            'rs' => 0,
            'ru' => 0,
            'rw' => 0,
            'sa' => 0,
            'sb' => 0,
            'sc' => 0,
            'sd' => 0,
            'se' => 0,
            'sg' => 0,
            'sh' => 0,
            'si' => 0,
            'sk' => 0,
            'sl' => 0,
            'sm' => 0,
            'sn' => 0,
            'so' => 0,
            'sr' => 0,
            'ss' => 0,
            'st' => 0,
            'sv' => 0,
            'sy' => 0,
            'sz' => 0,
            'tc' => 0,
            'td' => 0,
            'tg' => 0,
            'th' => 0,
            'tj' => 0,
            'tk' => 0,
            'tm' => 0,
            'tn' => 0,
            'to' => 0,
            'tp' => 0,
            'tr' => 0,
            'tt' => 0,
            'tv' => 0,
            'tw' => 0,
            'tz' => 0,
            'ua' => 0,
            'ug' => 0,
            'us' => 'us',
            'uy' => 0,
            'uz' => 0,
            'va' => 0,
            'vc' => 0,
            've' => 0,
            'vg' => 0,
            'vi' => 0,
            'vn' => 0,
            'vu' => 0,
            'wf' => 0,
            'ws' => 0,
            'ye' => 0,
            'yt' => 0,
            'za' => 0,
            'zm' => 0,
            'zw' => 0,
          ),
          'hide_single_cc' => 0,
        ),
        'default_country' => 'us',
        'enable_country_level_validation' => 1,
        'enable_default_country' => 1,
        'enable_extension' => 0,
        'user_register_form' => FALSE,
      ),
      'widget' => array(
        'active' => 0,
        'module' => 'cck_phone',
        'settings' => array(
          'size' => 15,
        ),
        'type' => 'phone_number',
        'weight' => '9',
      ),
    ),
  );

  // Exported field: 'node-coordinator-field_signups_max'
  $fields['node-coordinator-field_signups_max'] = array(
    'field_config' => array(
      'active' => '1',
      'cardinality' => '1',
      'deleted' => '0',
      'entity_types' => array(),
      'field_name' => 'field_signups_max',
      'foreign keys' => array(),
      'global_block_settings' => '2',
      'indexes' => array(),
      'module' => 'number',
      'settings' => array(),
      'translatable' => '1',
      'type' => 'number_integer',
    ),
    'field_instance' => array(
      'bundle' => 'coordinator',
      'default_value' => NULL,
      'deleted' => '0',
      'description' => 'Leave blank or enter zero (0) for no limit',
      'display' => array(
        'cck_blocks' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => 0,
        ),
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
          'weight' => 7,
        ),
        'notifications' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => 0,
        ),
        'teaser' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => 0,
        ),
      ),
      'entity_type' => 'node',
      'field_name' => 'field_signups_max',
      'label' => 'Maximum number of students',
      'required' => 0,
      'settings' => array(
        'max' => '',
        'min' => '0',
        'prefix' => '',
        'suffix' => 'students',
        'user_register_form' => FALSE,
      ),
      'widget' => array(
        'active' => 0,
        'module' => 'number',
        'settings' => array(),
        'type' => 'number',
        'weight' => '3',
      ),
    ),
  );

  // Exported field: 'node-coordinator-field_site'
  $fields['node-coordinator-field_site'] = array(
    'field_config' => array(
      'active' => '1',
      'cardinality' => '1',
      'deleted' => '0',
      'entity_types' => array(),
      'field_name' => 'field_site',
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
            'view' => 'view',
          ),
          'author' => array(
            'delete' => 0,
            'update' => 0,
            'view' => 0,
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
              'view' => 0,
            ),
            'view' => array(
              'delete' => 0,
              'update' => 0,
              'view' => 'view',
            ),
          ),
          'unused' => '0',
        ),
        'referenceable_types' => array(
          'contact_record' => 0,
          'coordinator' => 0,
          'course' => 0,
          'course_term' => 0,
          'file' => 0,
          'news' => 0,
          'page' => 0,
          'signup' => 0,
          'site' => 'site',
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
      'bundle' => 'coordinator',
      'default_value' => NULL,
      'deleted' => '0',
      'description' => '',
      'display' => array(
        'default' => array(
          'label' => 'above',
          'module' => 'node_reference',
          'settings' => array(),
          'type' => 'node_reference_default',
          'weight' => '0',
        ),
        'notifications' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => 0,
        ),
        'teaser' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => 0,
        ),
      ),
      'entity_type' => 'node',
      'field_name' => 'field_site',
      'label' => 'Site',
      'required' => 1,
      'settings' => array(
        'user_register_form' => FALSE,
      ),
      'widget' => array(
        'active' => 1,
        'module' => 'nodereference_url',
        'settings' => array(
          'edit_fallback' => 0,
          'fallback' => 'select',
          'node_link' => array(
            'destination' => 'node',
            'full' => 0,
            'hover_title' => '',
            'teaser' => 0,
            'title' => 'Add a new coordinator',
          ),
        ),
        'type' => 'nodereference_url',
        'weight' => '4',
      ),
    ),
  );

  // Exported field: 'node-coordinator-field_site_restrict'
  $fields['node-coordinator-field_site_restrict'] = array(
    'field_config' => array(
      'active' => '1',
      'cardinality' => '-1',
      'deleted' => '0',
      'entity_types' => array(),
      'field_name' => 'field_site_restrict',
      'foreign keys' => array(
        'tid' => array(
          'columns' => array(
            'tid' => 'tid',
          ),
          'table' => 'taxonomy_term_data',
        ),
      ),
      'global_block_settings' => '2',
      'indexes' => array(
        'tid' => array(
          0 => 'tid',
        ),
      ),
      'module' => 'taxonomy',
      'settings' => array(
        'allowed_values' => array(
          0 => array(
            'vocabulary' => 'site_restrictions',
            'parent' => '0',
          ),
        ),
      ),
      'translatable' => '1',
      'type' => 'taxonomy_term_reference',
    ),
    'field_instance' => array(
      'bundle' => 'coordinator',
      'default_value' => NULL,
      'deleted' => '0',
      'description' => 'Restrict this site staff to the following types of students.',
      'display' => array(
        'cck_blocks' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => 0,
        ),
        'default' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => '5',
        ),
        'notifications' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => 0,
        ),
        'teaser' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => 0,
        ),
      ),
      'entity_type' => 'node',
      'field_name' => 'field_site_restrict',
      'label' => 'Restrict to',
      'required' => 0,
      'settings' => array(
        'user_register_form' => FALSE,
      ),
      'widget' => array(
        'active' => 1,
        'module' => 'options',
        'settings' => array(),
        'type' => 'options_buttons',
        'weight' => '5',
      ),
    ),
  );

  // Exported field: 'node-coordinator-field_site_staff_user'
  $fields['node-coordinator-field_site_staff_user'] = array(
    'field_config' => array(
      'active' => '1',
      'cardinality' => '1',
      'deleted' => '0',
      'entity_types' => array(),
      'field_name' => 'field_site_staff_user',
      'foreign keys' => array(
        'uid' => array(
          'columns' => array(
            'uid' => 'uid',
          ),
          'table' => 'users',
        ),
      ),
      'indexes' => array(
        'uid' => array(
          0 => 'uid',
        ),
      ),
      'module' => 'user_reference',
      'settings' => array(
        'nodeaccess_userreference' => array(
          'all' => array(
            'view' => 0,
          ),
          'author' => array(
            'delete' => 'delete',
            'update' => 'update',
            'view' => 'view',
          ),
          'priority' => '0',
          'referenced' => array(
            'delete' => 0,
            'update' => 'update',
            'view' => 'view',
          ),
          'unused' => '0',
          'views' => array(
            'view' => '',
            'view_args' => '',
          ),
        ),
        'referenceable_roles' => array(
          2 => 0,
          3 => 0,
          4 => 0,
          5 => 0,
          6 => 0,
          7 => 0,
        ),
        'referenceable_status' => array(
          0 => 0,
          1 => '1',
        ),
        'view' => array(
          'args' => array(),
          'display_name' => '',
          'view_name' => '',
        ),
      ),
      'translatable' => '0',
      'type' => 'user_reference',
    ),
    'field_instance' => array(
      'bundle' => 'coordinator',
      'default_value' => NULL,
      'deleted' => '0',
      'description' => 'If this site staff needs to login and view their students, ask them to create a user account and then enter that account name here.',
      'display' => array(
        'default' => array(
          'label' => 'above',
          'module' => 'user_reference',
          'settings' => array(),
          'type' => 'user_reference_default',
          'weight' => 10,
        ),
        'notifications' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => 0,
        ),
        'teaser' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => 0,
        ),
      ),
      'display_label' => '',
      'entity_type' => 'node',
      'field_name' => 'field_site_staff_user',
      'label' => 'Related user',
      'required' => 0,
      'settings' => array(
        'user_register_form' => FALSE,
      ),
      'widget' => array(
        'active' => 1,
        'module' => 'user_reference',
        'settings' => array(
          'autocomplete_match' => 'contains',
          'autocomplete_path' => 'user_reference/autocomplete',
          'size' => '60',
        ),
        'type' => 'user_reference_autocomplete',
        'weight' => '10',
      ),
    ),
  );

  // Exported field: 'node-coordinator-field_staff_role'
  $fields['node-coordinator-field_staff_role'] = array(
    'field_config' => array(
      'active' => '1',
      'cardinality' => '1',
      'deleted' => '0',
      'entity_types' => array(),
      'field_name' => 'field_staff_role',
      'foreign keys' => array(
        'tid' => array(
          'columns' => array(
            'tid' => 'tid',
          ),
          'table' => 'taxonomy_term_data',
        ),
      ),
      'global_block_settings' => '1',
      'indexes' => array(
        'tid' => array(
          0 => 'tid',
        ),
      ),
      'module' => 'taxonomy',
      'settings' => array(
        'allowed_values' => array(
          0 => array(
            'parent' => '0',
            'vocabulary' => 'site_staff_role',
          ),
        ),
      ),
      'translatable' => '1',
      'type' => 'taxonomy_term_reference',
    ),
    'field_instance' => array(
      'bundle' => 'coordinator',
      'default_value' => NULL,
      'deleted' => '0',
      'description' => 'Select the role of this staff person.',
      'display' => array(
        'cck_blocks' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => 0,
        ),
        'default' => array(
          'label' => 'above',
          'module' => 'taxonomy',
          'settings' => array(),
          'type' => 'taxonomy_term_reference_link',
          'weight' => 8,
        ),
        'notifications' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => 0,
        ),
        'teaser' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => 0,
        ),
      ),
      'entity_type' => 'node',
      'field_name' => 'field_staff_role',
      'label' => 'Role',
      'required' => 0,
      'settings' => array(
        'user_register_form' => FALSE,
      ),
      'widget' => array(
        'active' => 1,
        'module' => 'options',
        'settings' => array(),
        'type' => 'options_select',
        'weight' => '6',
      ),
    ),
  );

  // Exported field: 'node-coordinator-field_staff_signup_available'
  $fields['node-coordinator-field_staff_signup_available'] = array(
    'field_config' => array(
      'active' => '1',
      'cardinality' => '1',
      'deleted' => '0',
      'entity_types' => array(),
      'field_name' => 'field_staff_signup_available',
      'foreign keys' => array(),
      'global_block_settings' => '1',
      'indexes' => array(
        'value' => array(
          0 => 'value',
        ),
      ),
      'module' => 'list',
      'settings' => array(
        'allowed_values' => array(
          0 => 'Not available',
          1 => 'Yes',
        ),
        'allowed_values_function' => '',
        'allowed_values_php' => '',
      ),
      'translatable' => '1',
      'type' => 'list_boolean',
    ),
    'field_instance' => array(
      'bundle' => 'coordinator',
      'default_value' => array(
        0 => array(
          'value' => 1,
        ),
      ),
      'default_value_function' => '',
      'default_value_php' => '',
      'deleted' => '0',
      'description' => '',
      'display' => array(
        'cck_blocks' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => 0,
        ),
        'default' => array(
          'label' => 'above',
          'module' => 'list',
          'settings' => array(),
          'type' => 'list_default',
          'weight' => 9,
        ),
        'notifications' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => 0,
        ),
        'teaser' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => 0,
        ),
      ),
      'entity_type' => 'node',
      'field_name' => 'field_staff_signup_available',
      'label' => 'Students can register with this staff',
      'required' => 0,
      'settings' => array(
        'user_register_form' => FALSE,
      ),
      'widget' => array(
        'active' => 1,
        'module' => 'options',
        'settings' => array(
          'display_label' => 1,
        ),
        'type' => 'options_onoff',
        'weight' => '7',
      ),
    ),
  );

  // Exported field: 'node-file-body'
  $fields['node-file-body'] = array(
    'field_config' => array(
      'active' => '1',
      'cardinality' => '1',
      'deleted' => '0',
      'entity_types' => array(
        0 => 'node',
      ),
      'field_name' => 'body',
      'foreign keys' => array(
        'format' => array(
          'columns' => array(
            'format' => 'format',
          ),
          'table' => 'filter_format',
        ),
      ),
      'global_block_settings' => '2',
      'indexes' => array(
        'format' => array(
          0 => 'format',
        ),
      ),
      'module' => 'text',
      'settings' => array(),
      'translatable' => '1',
      'type' => 'text_with_summary',
    ),
    'field_instance' => array(
      'bundle' => 'file',
      'default_value' => NULL,
      'deleted' => '0',
      'description' => '',
      'display' => array(
        'default' => array(
          'label' => 'above',
          'module' => 'text',
          'settings' => array(),
          'type' => 'text_default',
          'weight' => '0',
        ),
        'full' => array(
          'label' => 'above',
          'module' => 'text',
          'settings' => array(),
          'type' => 'text_default',
          'weight' => '2',
        ),
        'notifications' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => 0,
        ),
        'teaser' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => 0,
        ),
      ),
      'entity_type' => 'node',
      'field_name' => 'body',
      'label' => 'File description or notes',
      'required' => 0,
      'settings' => array(
        'display_summary' => 0,
        'text_processing' => '1',
        'user_register_form' => FALSE,
      ),
      'widget' => array(
        'active' => 1,
        'module' => 'text',
        'settings' => array(
          'rows' => '10',
          'summary_rows' => 5,
        ),
        'type' => 'text_textarea_with_summary',
        'weight' => '3',
      ),
    ),
  );

  // Exported field: 'node-file-field_expiration_date'
  $fields['node-file-field_expiration_date'] = array(
    'field_config' => array(
      'active' => '1',
      'cardinality' => '1',
      'deleted' => '0',
      'entity_types' => array(),
      'field_name' => 'field_expiration_date',
      'foreign keys' => array(),
      'global_block_settings' => '2',
      'indexes' => array(),
      'module' => 'date',
      'settings' => array(
        'granularity' => array(
          'day' => 'day',
          'month' => 'month',
          'year' => 'year',
        ),
        'repeat' => 0,
        'timezone_db' => '',
        'todate' => '',
        'tz_handling' => 'none',
      ),
      'translatable' => '1',
      'type' => 'date',
    ),
    'field_instance' => array(
      'bundle' => 'file',
      'deleted' => '0',
      'description' => '',
      'display' => array(
        'cck_blocks' => array(
          'label' => 'above',
          'module' => 'date',
          'settings' => array(
            'format_type' => 'long',
            'fromto' => 'both',
            'multiple_from' => '',
            'multiple_number' => '',
            'multiple_to' => '',
            'show_repeat_rule' => 'show',
          ),
          'type' => 'date_default',
          'weight' => '2',
        ),
        'default' => array(
          'label' => 'above',
          'module' => 'date',
          'settings' => array(
            'format_type' => 'long',
            'fromto' => 'both',
            'multiple_from' => '',
            'multiple_number' => '',
            'multiple_to' => '',
            'show_repeat_rule' => 'show',
          ),
          'type' => 'date_default',
          'weight' => '4',
        ),
        'full' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => '7',
        ),
        'notifications' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => 0,
        ),
        'teaser' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => 0,
        ),
      ),
      'entity_type' => 'node',
      'field_name' => 'field_expiration_date',
      'label' => 'Expiration date',
      'required' => 0,
      'settings' => array(
        'default_format' => 'medium',
        'default_value' => 'strtotime',
        'default_value2' => 'blank',
        'default_value_code' => '+1 year',
        'default_value_code2' => '',
        'user_register_form' => FALSE,
      ),
      'widget' => array(
        'active' => 1,
        'module' => 'date',
        'settings' => array(
          'increment' => '1',
          'input_format' => 'm/d/Y - H:i:s',
          'input_format_custom' => '',
          'label_position' => 'above',
          'repeat_collapsed' => 0,
          'text_parts' => array(),
          'year_range' => '-3:+3',
        ),
        'type' => 'date_popup',
        'weight' => '4',
      ),
    ),
  );

  // Exported field: 'node-file-field_expiration_reminder'
  $fields['node-file-field_expiration_reminder'] = array(
    'field_config' => array(
      'active' => '1',
      'cardinality' => '1',
      'deleted' => '0',
      'entity_types' => array(),
      'field_name' => 'field_expiration_reminder',
      'foreign keys' => array(),
      'global_block_settings' => '2',
      'indexes' => array(
        'value' => array(
          0 => 'value',
        ),
      ),
      'module' => 'list',
      'settings' => array(
        'allowed_values' => array(
          0 => 'Disabled',
          1 => 'Enabled',
        ),
        'allowed_values_function' => '',
        'allowed_values_php' => '',
      ),
      'translatable' => '1',
      'type' => 'list_boolean',
    ),
    'field_instance' => array(
      'bundle' => 'file',
      'default_value' => array(
        0 => array(
          'value' => 0,
        ),
      ),
      'default_value_function' => '',
      'default_value_php' => '',
      'deleted' => '0',
      'description' => 'When checked, users who have opted to receive notifications about expiring files will get a weekly email when this file is about to expire.',
      'display' => array(
        'default' => array(
          'label' => 'above',
          'module' => 'list',
          'settings' => array(),
          'type' => 'list_default',
          'weight' => '14',
        ),
        'full' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => '8',
        ),
        'notifications' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => 0,
        ),
        'teaser' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => 0,
        ),
      ),
      'entity_type' => 'node',
      'field_name' => 'field_expiration_reminder',
      'label' => 'Enable expiration reminder',
      'required' => 0,
      'settings' => array(
        'user_register_form' => FALSE,
      ),
      'widget' => array(
        'active' => 1,
        'module' => 'options',
        'settings' => array(
          'display_label' => 1,
        ),
        'type' => 'options_onoff',
        'weight' => '5',
      ),
    ),
  );

  // Exported field: 'node-file-field_expiration_reminder_date'
  $fields['node-file-field_expiration_reminder_date'] = array(
    'field_config' => array(
      'active' => '1',
      'cardinality' => '1',
      'deleted' => '0',
      'entity_types' => array(),
      'field_name' => 'field_expiration_reminder_date',
      'foreign keys' => array(),
      'global_block_settings' => '1',
      'indexes' => array(),
      'module' => 'date',
      'settings' => array(
        'granularity' => array(
          'day' => 'day',
          'month' => 'month',
          'year' => 'year',
        ),
        'repeat' => 0,
        'timezone_db' => '',
        'todate' => '',
        'tz_handling' => 'none',
      ),
      'translatable' => '1',
      'type' => 'date',
    ),
    'field_instance' => array(
      'bundle' => 'file',
      'deleted' => '0',
      'description' => 'The date when a reminder to check on this file will be sent out.',
      'display' => array(
        'cck_blocks' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => 0,
        ),
        'default' => array(
          'label' => 'above',
          'module' => 'date',
          'settings' => array(
            'format_type' => 'long',
            'fromto' => 'both',
            'multiple_from' => '',
            'multiple_number' => '',
            'multiple_to' => '',
            'show_repeat_rule' => 'show',
          ),
          'type' => 'date_default',
          'weight' => '5',
        ),
        'full' => array(
          'label' => 'above',
          'module' => 'date',
          'settings' => array(
            'format_type' => 'long',
            'fromto' => 'both',
            'multiple_from' => '',
            'multiple_number' => '',
            'multiple_to' => '',
            'show_repeat_rule' => 'show',
          ),
          'type' => 'date_default',
          'weight' => '3',
        ),
        'notifications' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => 0,
        ),
        'teaser' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => 0,
        ),
      ),
      'entity_type' => 'node',
      'field_name' => 'field_expiration_reminder_date',
      'label' => 'Reminder date',
      'required' => 0,
      'settings' => array(
        'default_format' => 'medium',
        'default_value' => 'strtotime',
        'default_value2' => 'blank',
        'default_value_code' => '+11 months',
        'default_value_code2' => '',
        'user_register_form' => FALSE,
      ),
      'widget' => array(
        'active' => 1,
        'module' => 'date',
        'settings' => array(
          'increment' => '1',
          'input_format' => 'm/d/Y - H:i:s',
          'input_format_custom' => '',
          'label_position' => 'above',
          'repeat_collapsed' => 0,
          'text_parts' => array(),
          'year_range' => '-3:+3',
        ),
        'type' => 'date_popup',
        'weight' => '6',
      ),
    ),
  );

  // Exported field: 'node-file-field_file_category'
  $fields['node-file-field_file_category'] = array(
    'field_config' => array(
      'active' => '1',
      'cardinality' => '1',
      'deleted' => '0',
      'entity_types' => array(),
      'field_name' => 'field_file_category',
      'foreign keys' => array(
        'tid' => array(
          'columns' => array(
            'tid' => 'tid',
          ),
          'table' => 'taxonomy_term_data',
        ),
      ),
      'global_block_settings' => '2',
      'indexes' => array(
        'tid' => array(
          0 => 'tid',
        ),
      ),
      'module' => 'taxonomy',
      'settings' => array(
        'allowed_values' => array(
          0 => array(
            'parent' => '0',
            'vocabulary' => 'file_category',
          ),
        ),
      ),
      'translatable' => '1',
      'type' => 'taxonomy_term_reference',
    ),
    'field_instance' => array(
      'bundle' => 'file',
      'default_value' => NULL,
      'deleted' => '0',
      'description' => '',
      'display' => array(
        'default' => array(
          'label' => 'above',
          'module' => 'taxonomy',
          'settings' => array(),
          'type' => 'taxonomy_term_reference_link',
          'weight' => '2',
        ),
        'full' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => '5',
        ),
        'notifications' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => 0,
        ),
        'teaser' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => 0,
        ),
      ),
      'entity_type' => 'node',
      'field_name' => 'field_file_category',
      'label' => 'File category',
      'required' => 0,
      'settings' => array(
        'user_register_form' => FALSE,
      ),
      'widget' => array(
        'active' => 1,
        'module' => 'options',
        'settings' => array(),
        'type' => 'options_select',
        'weight' => '9',
      ),
    ),
  );

  // Exported field: 'node-file-field_file_tags'
  $fields['node-file-field_file_tags'] = array(
    'field_config' => array(
      'active' => '1',
      'cardinality' => '-1',
      'deleted' => '0',
      'entity_types' => array(),
      'field_name' => 'field_file_tags',
      'foreign keys' => array(
        'tid' => array(
          'columns' => array(
            'tid' => 'tid',
          ),
          'table' => 'taxonomy_term_data',
        ),
      ),
      'global_block_settings' => '2',
      'indexes' => array(
        'tid' => array(
          0 => 'tid',
        ),
      ),
      'module' => 'taxonomy',
      'settings' => array(
        'allowed_values' => array(
          0 => array(
            'parent' => '0',
            'vocabulary' => 'file_tags',
          ),
        ),
      ),
      'translatable' => '1',
      'type' => 'taxonomy_term_reference',
    ),
    'field_instance' => array(
      'bundle' => 'file',
      'default_value' => NULL,
      'deleted' => '0',
      'description' => '',
      'display' => array(
        'default' => array(
          'label' => 'above',
          'module' => 'taxonomy',
          'settings' => array(),
          'type' => 'taxonomy_term_reference_link',
          'weight' => '3',
        ),
        'full' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => '6',
        ),
        'notifications' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => 0,
        ),
        'teaser' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => 0,
        ),
      ),
      'entity_type' => 'node',
      'field_name' => 'field_file_tags',
      'label' => 'Tags',
      'required' => 0,
      'settings' => array(
        'user_register_form' => FALSE,
      ),
      'widget' => array(
        'active' => 0,
        'module' => 'taxonomy',
        'settings' => array(
          'autocomplete_path' => 'taxonomy/autocomplete',
          'size' => 60,
        ),
        'type' => 'taxonomy_autocomplete',
        'weight' => '7',
      ),
    ),
  );

  // Exported field: 'node-file-field_files'
  $fields['node-file-field_files'] = array(
    'field_config' => array(
      'active' => '1',
      'cardinality' => '-1',
      'deleted' => '0',
      'entity_types' => array(),
      'field_name' => 'field_files',
      'foreign keys' => array(
        'fid' => array(
          'columns' => array(
            'fid' => 'fid',
          ),
          'table' => 'file_managed',
        ),
      ),
      'global_block_settings' => '2',
      'indexes' => array(
        'fid' => array(
          0 => 'fid',
        ),
      ),
      'module' => 'file',
      'settings' => array(
        'display_default' => 1,
        'display_field' => 1,
        'uri_scheme' => 'private',
      ),
      'translatable' => '1',
      'type' => 'file',
    ),
    'field_instance' => array(
      'bundle' => 'file',
      'deleted' => '0',
      'description' => '',
      'display' => array(
        'default' => array(
          'label' => 'above',
          'module' => 'file',
          'settings' => array(),
          'type' => 'file_default',
          'weight' => '1',
        ),
        'full' => array(
          'label' => 'above',
          'module' => 'file',
          'settings' => array(),
          'type' => 'file_default',
          'weight' => '1',
        ),
        'notifications' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => 0,
        ),
        'teaser' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => 0,
        ),
      ),
      'display_label' => '',
      'entity_type' => 'node',
      'field_name' => 'field_files',
      'label' => 'Files',
      'required' => 0,
      'settings' => array(
        'description_field' => 0,
        'file_directory' => 'sites/files',
        'file_extensions' => 'txt doc docx xls xlsx pdf',
        'max_filesize' => '',
        'user_register_form' => FALSE,
      ),
      'widget' => array(
        'active' => 1,
        'module' => 'file',
        'settings' => array(
          'insert' => 0,
          'insert_class' => '',
          'insert_default' => 'auto',
          'insert_styles' => array(
            'auto' => 'auto',
            'image' => 0,
            'image_large' => 0,
            'image_medium' => 0,
            'image_thumbnail' => 0,
            'link' => 0,
          ),
          'insert_width' => '',
          'progress_indicator' => 'throbber',
        ),
        'type' => 'file_generic',
        'weight' => '2',
      ),
    ),
  );

  // Exported field: 'node-file-field_form_sid'
  $fields['node-file-field_form_sid'] = array(
    'field_config' => array(
      'active' => '1',
      'cardinality' => '1',
      'deleted' => '0',
      'entity_types' => array(),
      'field_name' => 'field_form_sid',
      'foreign keys' => array(),
      'global_block_settings' => '1',
      'indexes' => array(),
      'module' => 'number',
      'settings' => array(),
      'translatable' => '1',
      'type' => 'number_integer',
    ),
    'field_instance' => array(
      'bundle' => 'file',
      'default_value' => NULL,
      'deleted' => '0',
      'description' => '',
      'display' => array(
        'cck_blocks' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => 0,
        ),
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
          'weight' => '13',
        ),
        'full' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => '4',
        ),
        'notifications' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => 0,
        ),
        'teaser' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => 0,
        ),
      ),
      'entity_type' => 'node',
      'field_name' => 'field_form_sid',
      'label' => 'Saved form record',
      'required' => 0,
      'settings' => array(
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
        'weight' => '8',
      ),
    ),
  );

  // Exported field: 'node-file-field_site'
  $fields['node-file-field_site'] = array(
    'field_config' => array(
      'active' => '1',
      'cardinality' => '1',
      'deleted' => '0',
      'entity_types' => array(),
      'field_name' => 'field_site',
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
            'view' => 'view',
          ),
          'author' => array(
            'delete' => 0,
            'update' => 0,
            'view' => 0,
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
              'view' => 0,
            ),
            'view' => array(
              'delete' => 0,
              'update' => 0,
              'view' => 'view',
            ),
          ),
          'unused' => '0',
        ),
        'referenceable_types' => array(
          'contact_record' => 0,
          'coordinator' => 0,
          'course' => 0,
          'course_term' => 0,
          'file' => 0,
          'news' => 0,
          'page' => 0,
          'signup' => 0,
          'site' => 'site',
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
      'bundle' => 'file',
      'default_value' => NULL,
      'deleted' => '0',
      'description' => '',
      'display' => array(
        'default' => array(
          'label' => 'above',
          'module' => 'node_reference',
          'settings' => array(),
          'type' => 'node_reference_default',
          'weight' => '7',
        ),
        'full' => array(
          'label' => 'above',
          'module' => 'node_reference',
          'settings' => array(),
          'type' => 'node_reference_default',
          'weight' => '0',
        ),
        'notifications' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => 0,
        ),
        'teaser' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => 0,
        ),
      ),
      'entity_type' => 'node',
      'field_name' => 'field_site',
      'label' => 'Site',
      'required' => 0,
      'settings' => array(
        'user_register_form' => FALSE,
      ),
      'widget' => array(
        'active' => 1,
        'module' => 'nodereference_url',
        'settings' => array(
          'edit_fallback' => 0,
          'fallback' => 'select',
          'node_link' => array(
            'destination' => 'source',
            'full' => 0,
            'hover_title' => '',
            'teaser' => 0,
            'title' => '',
          ),
        ),
        'type' => 'nodereference_url',
        'weight' => '1',
      ),
    ),
  );

  // Exported field: 'node-site-body'
  $fields['node-site-body'] = array(
    'field_config' => array(
      'active' => '1',
      'cardinality' => '1',
      'deleted' => '0',
      'entity_types' => array(
        0 => 'node',
      ),
      'field_name' => 'body',
      'foreign keys' => array(
        'format' => array(
          'columns' => array(
            'format' => 'format',
          ),
          'table' => 'filter_format',
        ),
      ),
      'global_block_settings' => '2',
      'indexes' => array(
        'format' => array(
          0 => 'format',
        ),
      ),
      'module' => 'text',
      'settings' => array(),
      'translatable' => '1',
      'type' => 'text_with_summary',
    ),
    'field_instance' => array(
      'bundle' => 'site',
      'default_value' => NULL,
      'deleted' => '0',
      'description' => 'Provide an overview description of your organization, i.e. who you are, what you do, and who you serve.',
      'display' => array(
        'default' => array(
          'label' => 'hidden',
          'module' => 'text',
          'settings' => array(),
          'type' => 'text_default',
          'weight' => '0',
        ),
        'full' => array(
          'label' => 'hidden',
          'module' => 'text',
          'settings' => array(),
          'type' => 'text_default',
          'weight' => '0',
        ),
        'notifications' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => 0,
        ),
        'teaser' => array(
          'label' => 'hidden',
          'module' => 'text',
          'settings' => array(
            'trim_length' => 600,
          ),
          'type' => 'text_summary_or_trimmed',
          'weight' => 0,
        ),
      ),
      'entity_type' => 'node',
      'field_name' => 'body',
      'label' => 'Site description',
      'required' => 0,
      'settings' => array(
        'display_summary' => 1,
        'text_processing' => '1',
        'user_register_form' => FALSE,
      ),
      'widget' => array(
        'active' => 1,
        'module' => 'text',
        'settings' => array(
          'rows' => '20',
          'summary_rows' => 5,
        ),
        'type' => 'text_textarea_with_summary',
        'weight' => '-4',
      ),
      'widget_type' => 'text_textarea_with_summary',
    ),
  );

  // Exported field: 'node-site-field_csu_facility'
  $fields['node-site-field_csu_facility'] = array(
    'field_config' => array(
      'active' => '1',
      'cardinality' => '-1',
      'deleted' => '0',
      'entity_types' => array(),
      'field_name' => 'field_csu_facility',
      'foreign keys' => array(
        'tid' => array(
          'columns' => array(
            'tid' => 'tid',
          ),
          'table' => 'taxonomy_term_data',
        ),
      ),
      'global_block_settings' => '2',
      'indexes' => array(
        'tid' => array(
          0 => 'tid',
        ),
      ),
      'module' => 'taxonomy',
      'settings' => array(
        'allowed_values' => array(
          0 => array(
            'parent' => '0',
            'vocabulary' => 'issues_addressed',
          ),
        ),
      ),
      'translatable' => '1',
      'type' => 'taxonomy_term_reference',
    ),
    'field_instance' => array(
      'bundle' => 'site',
      'default_value' => NULL,
      'deleted' => '0',
      'description' => '',
      'display' => array(
        'default' => array(
          'label' => 'above',
          'module' => 'taxonomy',
          'settings' => array(),
          'type' => 'taxonomy_term_reference_link',
          'weight' => '6',
        ),
        'full' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => 0,
        ),
        'notifications' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => 0,
        ),
        'teaser' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => 0,
        ),
      ),
      'entity_type' => 'node',
      'field_name' => 'field_csu_facility',
      'label' => 'Issues addressed',
      'required' => 0,
      'settings' => array(
        'user_register_form' => FALSE,
      ),
      'widget' => array(
        'active' => 1,
        'module' => 'options',
        'settings' => array(),
        'type' => 'options_select',
        'weight' => '4',
      ),
    ),
  );

  // Exported field: 'node-site-field_csu_org_type'
  $fields['node-site-field_csu_org_type'] = array(
    'field_config' => array(
      'active' => '1',
      'cardinality' => '-1',
      'deleted' => '0',
      'entity_types' => array(),
      'field_name' => 'field_csu_org_type',
      'foreign keys' => array(
        'tid' => array(
          'columns' => array(
            'tid' => 'tid',
          ),
          'table' => 'taxonomy_term_data',
        ),
      ),
      'global_block_settings' => '2',
      'indexes' => array(
        'tid' => array(
          0 => 'tid',
        ),
      ),
      'module' => 'taxonomy',
      'settings' => array(
        'allowed_values' => array(
          0 => array(
            'parent' => '0',
            'vocabulary' => 'organization_type',
          ),
        ),
      ),
      'translatable' => '1',
      'type' => 'taxonomy_term_reference',
    ),
    'field_instance' => array(
      'bundle' => 'site',
      'default_value' => NULL,
      'deleted' => '0',
      'description' => '',
      'display' => array(
        'default' => array(
          'label' => 'above',
          'module' => 'taxonomy',
          'settings' => array(),
          'type' => 'taxonomy_term_reference_link',
          'weight' => '8',
        ),
        'full' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => 0,
        ),
        'notifications' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => 0,
        ),
        'teaser' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => 0,
        ),
      ),
      'entity_type' => 'node',
      'field_name' => 'field_csu_org_type',
      'label' => 'Organization type',
      'required' => 0,
      'settings' => array(
        'user_register_form' => FALSE,
      ),
      'widget' => array(
        'active' => 1,
        'module' => 'options',
        'settings' => array(),
        'type' => 'options_select',
        'weight' => '5',
      ),
    ),
  );

  // Exported field: 'node-site-field_district_federal'
  $fields['node-site-field_district_federal'] = array(
    'field_config' => array(
      'active' => '1',
      'cardinality' => '1',
      'deleted' => '0',
      'entity_types' => array(),
      'field_name' => 'field_district_federal',
      'foreign keys' => array(
        'format' => array(
          'columns' => array(
            'format' => 'format',
          ),
          'table' => 'filter_format',
        ),
      ),
      'global_block_settings' => '1',
      'indexes' => array(
        'format' => array(
          0 => 'format',
        ),
      ),
      'module' => 'text',
      'settings' => array(
        'max_length' => '255',
      ),
      'translatable' => '1',
      'type' => 'text',
    ),
    'field_instance' => array(
      'bundle' => 'site',
      'default_value' => NULL,
      'deleted' => '0',
      'description' => '',
      'display' => array(
        'default' => array(
          'label' => 'above',
          'module' => 'text',
          'settings' => array(),
          'type' => 'text_default',
          'weight' => '31',
        ),
        'full' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => '24',
        ),
        'notifications' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => 0,
        ),
        'teaser' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => 0,
        ),
      ),
      'display_label' => '',
      'entity_type' => 'node',
      'field_name' => 'field_district_federal',
      'label' => 'Federal district',
      'required' => 0,
      's4_sites_field_access' => 1,
      'settings' => array(
        'text_processing' => '0',
        'user_register_form' => FALSE,
      ),
      'widget' => array(
        'active' => 1,
        'module' => 'text',
        'settings' => array(
          'size' => '10',
        ),
        'type' => 'text_textfield',
        'weight' => '2',
      ),
    ),
  );

  // Exported field: 'node-site-field_district_state_lower'
  $fields['node-site-field_district_state_lower'] = array(
    'field_config' => array(
      'active' => '1',
      'cardinality' => '1',
      'deleted' => '0',
      'entity_types' => array(),
      'field_name' => 'field_district_state_lower',
      'foreign keys' => array(
        'format' => array(
          'columns' => array(
            'format' => 'format',
          ),
          'table' => 'filter_format',
        ),
      ),
      'global_block_settings' => '1',
      'indexes' => array(
        'format' => array(
          0 => 'format',
        ),
      ),
      'module' => 'text',
      'settings' => array(
        'max_length' => '10',
      ),
      'translatable' => '1',
      'type' => 'text',
    ),
    'field_instance' => array(
      'bundle' => 'site',
      'default_value' => NULL,
      'deleted' => '0',
      'description' => '',
      'display' => array(
        'default' => array(
          'label' => 'above',
          'module' => 'text',
          'settings' => array(),
          'type' => 'text_default',
          'weight' => '33',
        ),
        'full' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => '25',
        ),
        'notifications' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => 0,
        ),
        'teaser' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => 0,
        ),
      ),
      'display_label' => '',
      'entity_type' => 'node',
      'field_name' => 'field_district_state_lower',
      'label' => 'State lower district',
      'required' => 0,
      's4_sites_field_access' => 1,
      'settings' => array(
        'text_processing' => '0',
        'user_register_form' => FALSE,
      ),
      'widget' => array(
        'active' => 1,
        'module' => 'text',
        'settings' => array(
          'size' => '10',
        ),
        'type' => 'text_textfield',
        'weight' => '4',
      ),
    ),
  );

  // Exported field: 'node-site-field_district_state_upper'
  $fields['node-site-field_district_state_upper'] = array(
    'field_config' => array(
      'active' => '1',
      'cardinality' => '1',
      'deleted' => '0',
      'entity_types' => array(),
      'field_name' => 'field_district_state_upper',
      'foreign keys' => array(
        'format' => array(
          'columns' => array(
            'format' => 'format',
          ),
          'table' => 'filter_format',
        ),
      ),
      'global_block_settings' => '1',
      'indexes' => array(
        'format' => array(
          0 => 'format',
        ),
      ),
      'module' => 'text',
      'settings' => array(
        'max_length' => '10',
      ),
      'translatable' => '1',
      'type' => 'text',
    ),
    'field_instance' => array(
      'bundle' => 'site',
      'default_value' => NULL,
      'deleted' => '0',
      'description' => '',
      'display' => array(
        'default' => array(
          'label' => 'above',
          'module' => 'text',
          'settings' => array(),
          'type' => 'text_default',
          'weight' => '34',
        ),
        'full' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => '27',
        ),
        'notifications' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => 0,
        ),
        'teaser' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => 0,
        ),
      ),
      'display_label' => '',
      'entity_type' => 'node',
      'field_name' => 'field_district_state_upper',
      'label' => 'State upper district',
      'required' => 0,
      's4_sites_field_access' => 0,
      'settings' => array(
        'text_processing' => '0',
        'user_register_form' => FALSE,
      ),
      'widget' => array(
        'active' => 1,
        'module' => 'text',
        'settings' => array(
          'size' => '10',
        ),
        'type' => 'text_textfield',
        'weight' => '3',
      ),
    ),
  );

  // Exported field: 'node-site-field_health_risk'
  $fields['node-site-field_health_risk'] = array(
    'field_config' => array(
      'active' => '1',
      'cardinality' => '1',
      'deleted' => '0',
      'entity_types' => array(),
      'field_name' => 'field_health_risk',
      'foreign keys' => array(
        'format' => array(
          'columns' => array(
            'format' => 'format',
          ),
          'table' => 'filter_format',
        ),
      ),
      'global_block_settings' => '1',
      'indexes' => array(
        'format' => array(
          0 => 'format',
        ),
      ),
      'module' => 'text',
      'settings' => array(),
      'translatable' => '1',
      'type' => 'text_long',
    ),
    'field_instance' => array(
      'bundle' => 'site',
      'default_value' => NULL,
      'deleted' => '0',
      'description' => '',
      'display' => array(
        'default' => array(
          'label' => 'above',
          'module' => 'text',
          'settings' => array(),
          'type' => 'text_default',
          'weight' => '2',
        ),
        'full' => array(
          'label' => 'above',
          'module' => 'text',
          'settings' => array(),
          'type' => 'text_default',
          'weight' => '4',
        ),
        'notifications' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => 0,
        ),
        'teaser' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => 0,
        ),
      ),
      'entity_type' => 'node',
      'field_name' => 'field_health_risk',
      'label' => 'Risk Identification',
      'required' => 0,
      's4_sites_field_access' => 0,
      'settings' => array(
        'text_processing' => '1',
        'user_register_form' => FALSE,
      ),
      'widget' => array(
        'active' => 1,
        'module' => 'text',
        'settings' => array(
          'rows' => '5',
        ),
        'type' => 'text_textarea',
        'weight' => '28',
      ),
    ),
  );

  // Exported field: 'node-site-field_location'
  $fields['node-site-field_location'] = array(
    'field_config' => array(
      'active' => '1',
      'cardinality' => '-1',
      'deleted' => '0',
      'entity_types' => array(),
      'field_name' => 'field_location',
      'foreign keys' => array(),
      'global_block_settings' => '2',
      'indexes' => array(
        'lid' => array(
          0 => 'lid',
        ),
      ),
      'module' => 'location_cck',
      'settings' => array(
        'gmap_macro' => '[gmap ]',
        'gmap_marker' => 'drupal',
        'location_settings' => array(
          'display' => array(
            'hide' => array(
              'additional' => 0,
              'city' => 0,
              'coords' => 'coords',
              'country' => 0,
              'country_name' => 0,
              'fax' => 0,
              'locpick' => 0,
              'map_link' => 'map_link',
              'name' => 0,
              'phone' => 0,
              'postal_code' => 0,
              'province' => 0,
              'province_name' => 0,
              'street' => 0,
            ),
          ),
          'form' => array(
            'fields' => array(
              'additional' => array(
                'collect' => '1',
                'default' => '',
                'weight' => '-96',
              ),
              'city' => array(
                'collect' => '1',
                'default' => '',
                'weight' => '-95',
              ),
              'country' => array(
                'collect' => '1',
                'default' => 'us',
                'weight' => '-92',
              ),
              'fax' => array(
                'collect' => '1',
                'default' => '',
                'weight' => '-98',
              ),
              'locpick' => array(
                'collect' => '0',
                'weight' => '-91',
              ),
              'name' => array(
                'collect' => '1',
                'default' => '',
                'weight' => '-100',
              ),
              'phone' => array(
                'collect' => '1',
                'default' => '',
                'weight' => '-99',
              ),
              'postal_code' => array(
                'collect' => '1',
                'default' => '',
                'weight' => '-93',
              ),
              'province' => array(
                'collect' => '1',
                'default' => '',
                'weight' => '-94',
                'widget' => 'autocomplete',
              ),
              'street' => array(
                'collect' => '1',
                'default' => '',
                'weight' => '-97',
              ),
            ),
          ),
        ),
      ),
      'translatable' => '1',
      'type' => 'location',
    ),
    'field_instance' => array(
      'bundle' => 'site',
      'default_value' => NULL,
      'deleted' => '0',
      'description' => 'If you have multiple location sites that you would like students to be placed at, please provide specific location information. (You may add additional locations using the \'Add another\' button below.)',
      'display' => array(
        'default' => array(
          'label' => 'above',
          'module' => 'location_cck',
          'settings' => array(),
          'type' => 'location_default',
          'weight' => '13',
        ),
        'full' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => '3',
        ),
        'notifications' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => 0,
        ),
        'teaser' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => 0,
        ),
      ),
      'display_label' => '',
      'entity_type' => 'node',
      'field_name' => 'field_location',
      'label' => 'Location(s)',
      'required' => 0,
      's4_sites_field_access' => 1,
      'settings' => array(
        'user_register_form' => FALSE,
      ),
      'widget' => array(
        'active' => 0,
        'module' => 'location_cck',
        'settings' => array(),
        'type' => 'location',
        'weight' => '1',
      ),
    ),
  );

  // Exported field: 'node-site-field_phone'
  $fields['node-site-field_phone'] = array(
    'field_config' => array(
      'active' => '1',
      'cardinality' => '-1',
      'deleted' => '0',
      'entity_types' => array(),
      'field_name' => 'field_phone',
      'foreign keys' => array(),
      'global_block_settings' => '2',
      'indexes' => array(),
      'module' => 'cck_phone',
      'settings' => array(
        'size' => '15',
      ),
      'translatable' => '1',
      'type' => 'phone_number',
    ),
    'field_instance' => array(
      'bundle' => 'site',
      'deleted' => '0',
      'description' => '',
      'display' => array(
        'default' => array(
          'label' => 'above',
          'module' => 'cck_phone',
          'settings' => array(),
          'type' => 'local_phone_number',
          'weight' => '11',
        ),
        'full' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => 0,
        ),
        'notifications' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => 0,
        ),
        'teaser' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => 0,
        ),
      ),
      'display_label' => 'Phone number',
      'entity_type' => 'node',
      'field_name' => 'field_phone',
      'label' => 'Main phone number',
      'required' => 0,
      's4_sites_field_access' => 0,
      'settings' => array(
        'all_country_codes' => 0,
        'country_code_position' => 'after',
        'country_codes' => array(
          'country_selection' => array(
            'ad' => 0,
            'ae' => 0,
            'af' => 0,
            'ag' => 0,
            'ai' => 0,
            'al' => 0,
            'am' => 0,
            'an' => 0,
            'ao' => 0,
            'ar' => 0,
            'as' => 0,
            'at' => 0,
            'au' => 0,
            'aw' => 0,
            'az' => 0,
            'ba' => 0,
            'bb' => 0,
            'bd' => 0,
            'be' => 0,
            'bf' => 0,
            'bg' => 0,
            'bh' => 0,
            'bi' => 0,
            'bj' => 0,
            'bm' => 0,
            'bn' => 0,
            'bo' => 0,
            'br' => 0,
            'bs' => 0,
            'bt' => 0,
            'bw' => 0,
            'by' => 0,
            'bz' => 0,
            'ca' => 0,
            'cc' => 0,
            'cd' => 0,
            'cf' => 0,
            'cg' => 0,
            'ch' => 0,
            'ci' => 0,
            'ck' => 0,
            'cl' => 0,
            'cm' => 0,
            'cn' => 0,
            'co' => 0,
            'cr' => 0,
            'cu' => 0,
            'cv' => 0,
            'cx' => 0,
            'cy' => 0,
            'cz' => 0,
            'de' => 0,
            'dj' => 0,
            'dk' => 0,
            'dm' => 0,
            'do' => 0,
            'dz' => 0,
            'ec' => 0,
            'ee' => 0,
            'eg' => 0,
            'er' => 0,
            'es' => 0,
            'et' => 0,
            'fi' => 0,
            'fj' => 0,
            'fk' => 0,
            'fm' => 0,
            'fo' => 0,
            'fr' => 0,
            'ga' => 0,
            'gb' => 0,
            'gd' => 0,
            'ge' => 0,
            'gf' => 0,
            'gh' => 0,
            'gi' => 0,
            'gl' => 0,
            'gm' => 0,
            'gn' => 0,
            'gp' => 0,
            'gq' => 0,
            'gr' => 0,
            'gt' => 0,
            'gu' => 0,
            'gw' => 0,
            'gy' => 0,
            'hk' => 0,
            'hn' => 0,
            'hr' => 0,
            'ht' => 0,
            'hu' => 0,
            'id' => 0,
            'ie' => 0,
            'il' => 0,
            'in' => 0,
            'io' => 0,
            'iq' => 0,
            'ir' => 0,
            'is' => 0,
            'it' => 0,
            'jm' => 0,
            'jo' => 0,
            'jp' => 0,
            'ke' => 0,
            'kg' => 0,
            'kh' => 0,
            'ki' => 0,
            'km' => 0,
            'kn' => 0,
            'kp' => 0,
            'kr' => 0,
            'kw' => 0,
            'ky' => 0,
            'kz' => 0,
            'la' => 0,
            'lb' => 0,
            'lc' => 0,
            'li' => 0,
            'lk' => 0,
            'lr' => 0,
            'ls' => 0,
            'lt' => 0,
            'lu' => 0,
            'lv' => 0,
            'ly' => 0,
            'ma' => 0,
            'mc' => 0,
            'md' => 0,
            'me' => 0,
            'mg' => 0,
            'mh' => 0,
            'mk' => 0,
            'ml' => 0,
            'mm' => 0,
            'mn' => 0,
            'mo' => 0,
            'mp' => 0,
            'mq' => 0,
            'mr' => 0,
            'ms' => 0,
            'mt' => 0,
            'mu' => 0,
            'mv' => 0,
            'mw' => 0,
            'mx' => 0,
            'my' => 0,
            'mz' => 0,
            'na' => 0,
            'nc' => 0,
            'ne' => 0,
            'nf' => 0,
            'ng' => 0,
            'ni' => 0,
            'nl' => 0,
            'no' => 0,
            'np' => 0,
            'nr' => 0,
            'nu' => 0,
            'nz' => 0,
            'om' => 0,
            'pa' => 0,
            'pe' => 0,
            'pf' => 0,
            'pg' => 0,
            'ph' => 0,
            'pk' => 0,
            'pl' => 0,
            'pm' => 0,
            'pr' => 0,
            'ps' => 0,
            'pt' => 0,
            'pw' => 0,
            'py' => 0,
            'qa' => 0,
            'ro' => 0,
            'rs' => 0,
            'ru' => 0,
            'rw' => 0,
            'sa' => 0,
            'sb' => 0,
            'sc' => 0,
            'sd' => 0,
            'se' => 0,
            'sg' => 0,
            'sh' => 0,
            'si' => 0,
            'sk' => 0,
            'sl' => 0,
            'sm' => 0,
            'sn' => 0,
            'so' => 0,
            'sr' => 0,
            'ss' => 0,
            'st' => 0,
            'sv' => 0,
            'sy' => 0,
            'sz' => 0,
            'tc' => 0,
            'td' => 0,
            'tg' => 0,
            'th' => 0,
            'tj' => 0,
            'tk' => 0,
            'tm' => 0,
            'tn' => 0,
            'to' => 0,
            'tp' => 0,
            'tr' => 0,
            'tt' => 0,
            'tv' => 0,
            'tw' => 0,
            'tz' => 0,
            'ua' => 0,
            'ug' => 0,
            'us' => 'us',
            'uy' => 0,
            'uz' => 0,
            'va' => 0,
            'vc' => 0,
            've' => 0,
            'vg' => 0,
            'vi' => 0,
            'vn' => 0,
            'vu' => 0,
            'wf' => 0,
            'ws' => 0,
            'ye' => 0,
            'yt' => 0,
            'za' => 0,
            'zm' => 0,
            'zw' => 0,
          ),
          'hide_single_cc' => 0,
        ),
        'default_country' => 'us',
        'enable_country_level_validation' => 0,
        'enable_default_country' => TRUE,
        'enable_extension' => 1,
        'user_register_form' => FALSE,
      ),
      'widget' => array(
        'active' => 0,
        'module' => 'cck_phone',
        'settings' => array(
          'size' => 15,
        ),
        'type' => 'phone_number',
        'weight' => '-2',
      ),
    ),
  );

  // Exported field: 'node-site-field_population_size'
  $fields['node-site-field_population_size'] = array(
    'field_config' => array(
      'active' => '1',
      'cardinality' => '1',
      'deleted' => '0',
      'entity_types' => array(),
      'field_name' => 'field_population_size',
      'foreign keys' => array(),
      'global_block_settings' => '1',
      'indexes' => array(),
      'module' => 'number',
      'settings' => array(),
      'translatable' => '1',
      'type' => 'number_integer',
    ),
    'field_instance' => array(
      'bundle' => 'site',
      'default_value' => NULL,
      'deleted' => '0',
      'description' => '',
      'display' => array(
        'cck_blocks' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => 0,
        ),
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
          'weight' => '16',
        ),
        'full' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => '5',
        ),
        'notifications' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => 0,
        ),
        'teaser' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => 0,
        ),
      ),
      'display_label' => 'Number of people served',
      'entity_type' => 'node',
      'field_name' => 'field_population_size',
      'label' => 'How many people does your organization serve?',
      'required' => 0,
      's4_sites_field_access' => 1,
      'settings' => array(
        'max' => '',
        'min' => '0',
        'prefix' => '',
        'suffix' => '',
        'user_register_form' => FALSE,
      ),
      'widget' => array(
        'active' => 0,
        'module' => 'number',
        'settings' => array(),
        'type' => 'number',
        'weight' => '26',
      ),
    ),
  );

  // Exported field: 'node-site-field_signups_max'
  $fields['node-site-field_signups_max'] = array(
    'field_config' => array(
      'active' => '1',
      'cardinality' => '1',
      'deleted' => '0',
      'entity_types' => array(),
      'field_name' => 'field_signups_max',
      'foreign keys' => array(),
      'global_block_settings' => '2',
      'indexes' => array(),
      'module' => 'number',
      'settings' => array(),
      'translatable' => '1',
      'type' => 'number_integer',
    ),
    'field_instance' => array(
      'bundle' => 'site',
      'default_value' => NULL,
      'deleted' => '0',
      'description' => 'Once this number is reached, students will not be able to register with your site.',
      'display' => array(
        'cck_blocks' => array(
          'label' => 'above',
          'module' => 'number',
          'settings' => array(
            'decimal_separator' => '.',
            'prefix_suffix' => TRUE,
            'scale' => 0,
            'thousand_separator' => ' ',
          ),
          'type' => 'number_integer',
          'weight' => '7',
        ),
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
          'weight' => '28',
        ),
        'full' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => '12',
        ),
        'notifications' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => 0,
        ),
        'teaser' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => 0,
        ),
      ),
      'entity_type' => 'node',
      'field_name' => 'field_signups_max',
      'label' => 'Maximum number of students your site can accept at any given time',
      'required' => 0,
      'settings' => array(
        'max' => '',
        'min' => '0',
        'prefix' => '',
        'suffix' => 'students',
        'user_register_form' => FALSE,
      ),
      'widget' => array(
        'active' => 0,
        'module' => 'number',
        'settings' => array(),
        'type' => 'number',
        'weight' => '27',
      ),
    ),
  );

  // Exported field: 'node-site-field_site_demographics'
  $fields['node-site-field_site_demographics'] = array(
    'field_config' => array(
      'active' => '1',
      'cardinality' => '-1',
      'deleted' => '0',
      'entity_types' => array(),
      'field_name' => 'field_site_demographics',
      'foreign keys' => array(),
      'global_block_settings' => '1',
      'indexes' => array(
        'col' => array(
          0 => 'col',
        ),
        'row' => array(
          0 => 'row',
        ),
        'value' => array(
          0 => 'value',
        ),
      ),
      'module' => 'matrix',
      'settings' => array(
        'cols_count' => '1',
        'define' => 'cols',
        'preview' => array(
          'cols' => array(
            1 => array(
              'button' => 'Change settings',
            ),
          ),
          'define' => 'cols',
          'rows' => array(
            1 => array(
              'button' => 'Change settings',
            ),
            2 => array(
              'button' => 'Change settings',
            ),
            3 => array(
              'button' => 'Change settings',
            ),
            4 => array(
              'button' => 'Change settings',
            ),
            5 => array(
              'button' => 'Change settings',
            ),
            6 => array(
              'button' => 'Change settings',
            ),
            7 => array(
              'button' => 'Change settings',
            ),
            8 => array(
              'button' => 'Change settings',
            ),
          ),
        ),
        'rows_count' => '8',
        'settings' => 'a:6:{i:0;b:0;s:10:"old_define";s:4:"cols";s:14:"old_rows_count";s:1:"8";s:14:"old_cols_count";s:1:"1";s:4:"cols";a:1:{i:1;a:8:{s:10:"field_type";s:9:"textfield";s:5:"title";s:7:"Percent";s:9:"textfield";a:3:{s:4:"size";s:1:"3";s:6:"prefix";s:0:"";s:6:"suffix";s:1:"%";}s:6:"select";a:2:{s:14:"allowed_values";s:0:"";s:23:"allowed_values_function";s:1:"0";}s:6:"radios";a:2:{s:14:"allowed_values";s:0:"";s:23:"allowed_values_function";s:1:"0";}s:10:"checkboxes";a:2:{s:14:"allowed_values";s:0:"";s:23:"allowed_values_function";s:1:"0";}s:11:"calculation";a:4:{s:11:"calculation";s:3:"sum";s:6:"prefix";s:0:"";s:6:"suffix";s:0:"";s:8:"rounding";s:0:"";}s:6:"custom";a:1:{s:6:"custom";s:32:"matrix_custom_processing_example";}}}s:4:"rows";a:8:{i:1;a:8:{s:10:"field_type";s:4:"none";s:5:"title";s:16:"African American";s:9:"textfield";a:3:{s:4:"size";s:0:"";s:6:"prefix";s:0:"";s:6:"suffix";s:0:"";}s:6:"select";a:2:{s:14:"allowed_values";s:0:"";s:23:"allowed_values_function";s:1:"0";}s:6:"radios";a:2:{s:14:"allowed_values";s:0:"";s:23:"allowed_values_function";s:1:"0";}s:10:"checkboxes";a:2:{s:14:"allowed_values";s:0:"";s:23:"allowed_values_function";s:1:"0";}s:11:"calculation";a:4:{s:11:"calculation";s:3:"sum";s:6:"prefix";s:0:"";s:6:"suffix";s:0:"";s:8:"rounding";s:0:"";}s:6:"custom";a:1:{s:6:"custom";s:32:"matrix_custom_processing_example";}}i:2;a:8:{s:10:"field_type";s:4:"none";s:5:"title";s:14:"Asian American";s:9:"textfield";a:3:{s:4:"size";s:0:"";s:6:"prefix";s:0:"";s:6:"suffix";s:0:"";}s:6:"select";a:2:{s:14:"allowed_values";s:0:"";s:23:"allowed_values_function";s:1:"0";}s:6:"radios";a:2:{s:14:"allowed_values";s:0:"";s:23:"allowed_values_function";s:1:"0";}s:10:"checkboxes";a:2:{s:14:"allowed_values";s:0:"";s:23:"allowed_values_function";s:1:"0";}s:11:"calculation";a:4:{s:11:"calculation";s:3:"sum";s:6:"prefix";s:0:"";s:6:"suffix";s:0:"";s:8:"rounding";s:0:"";}s:6:"custom";a:1:{s:6:"custom";s:32:"matrix_custom_processing_example";}}i:3;a:8:{s:10:"field_type";s:4:"none";s:5:"title";s:22:"Biracial/Multicultural";s:9:"textfield";a:3:{s:4:"size";s:0:"";s:6:"prefix";s:0:"";s:6:"suffix";s:0:"";}s:6:"select";a:2:{s:14:"allowed_values";s:0:"";s:23:"allowed_values_function";s:1:"0";}s:6:"radios";a:2:{s:14:"allowed_values";s:0:"";s:23:"allowed_values_function";s:1:"0";}s:10:"checkboxes";a:2:{s:14:"allowed_values";s:0:"";s:23:"allowed_values_function";s:1:"0";}s:11:"calculation";a:4:{s:11:"calculation";s:3:"sum";s:6:"prefix";s:0:"";s:6:"suffix";s:0:"";s:8:"rounding";s:0:"";}s:6:"custom";a:1:{s:6:"custom";s:32:"matrix_custom_processing_example";}}i:4;a:8:{s:10:"field_type";s:4:"none";s:5:"title";s:9:"Caucasian";s:9:"textfield";a:3:{s:4:"size";s:0:"";s:6:"prefix";s:0:"";s:6:"suffix";s:0:"";}s:6:"select";a:2:{s:14:"allowed_values";s:0:"";s:23:"allowed_values_function";s:1:"0";}s:6:"radios";a:2:{s:14:"allowed_values";s:0:"";s:23:"allowed_values_function";s:1:"0";}s:10:"checkboxes";a:2:{s:14:"allowed_values";s:0:"";s:23:"allowed_values_function";s:1:"0";}s:11:"calculation";a:4:{s:11:"calculation";s:3:"sum";s:6:"prefix";s:0:"";s:6:"suffix";s:0:"";s:8:"rounding";s:0:"";}s:6:"custom";a:1:{s:6:"custom";s:32:"matrix_custom_processing_example";}}i:5;a:8:{s:10:"field_type";s:4:"none";s:5:"title";s:8:"Latino/a";s:9:"textfield";a:3:{s:4:"size";s:0:"";s:6:"prefix";s:0:"";s:6:"suffix";s:0:"";}s:6:"select";a:2:{s:14:"allowed_values";s:0:"";s:23:"allowed_values_function";s:1:"0";}s:6:"radios";a:2:{s:14:"allowed_values";s:0:"";s:23:"allowed_values_function";s:1:"0";}s:10:"checkboxes";a:2:{s:14:"allowed_values";s:0:"";s:23:"allowed_values_function";s:1:"0";}s:11:"calculation";a:4:{s:11:"calculation";s:3:"sum";s:6:"prefix";s:0:"";s:6:"suffix";s:0:"";s:8:"rounding";s:0:"";}s:6:"custom";a:1:{s:6:"custom";s:32:"matrix_custom_processing_example";}}i:6;a:8:{s:10:"field_type";s:4:"none";s:5:"title";s:15:"Native American";s:9:"textfield";a:3:{s:4:"size";s:0:"";s:6:"prefix";s:0:"";s:6:"suffix";s:0:"";}s:6:"select";a:2:{s:14:"allowed_values";s:0:"";s:23:"allowed_values_function";s:1:"0";}s:6:"radios";a:2:{s:14:"allowed_values";s:0:"";s:23:"allowed_values_function";s:1:"0";}s:10:"checkboxes";a:2:{s:14:"allowed_values";s:0:"";s:23:"allowed_values_function";s:1:"0";}s:11:"calculation";a:4:{s:11:"calculation";s:3:"sum";s:6:"prefix";s:0:"";s:6:"suffix";s:0:"";s:8:"rounding";s:0:"";}s:6:"custom";a:1:{s:6:"custom";s:32:"matrix_custom_processing_example";}}i:7;a:8:{s:10:"field_type";s:4:"none";s:5:"title";s:16:"Pacific Islander";s:9:"textfield";a:3:{s:4:"size";s:0:"";s:6:"prefix";s:0:"";s:6:"suffix";s:0:"";}s:6:"select";a:2:{s:14:"allowed_values";s:0:"";s:23:"allowed_values_function";s:1:"0";}s:6:"radios";a:2:{s:14:"allowed_values";s:0:"";s:23:"allowed_values_function";s:1:"0";}s:10:"checkboxes";a:2:{s:14:"allowed_values";s:0:"";s:23:"allowed_values_function";s:1:"0";}s:11:"calculation";a:4:{s:11:"calculation";s:3:"sum";s:6:"prefix";s:0:"";s:6:"suffix";s:0:"";s:8:"rounding";s:0:"";}s:6:"custom";a:1:{s:6:"custom";s:32:"matrix_custom_processing_example";}}i:8;a:8:{s:10:"field_type";s:4:"none";s:5:"title";s:5:"Other";s:9:"textfield";a:3:{s:4:"size";s:0:"";s:6:"prefix";s:0:"";s:6:"suffix";s:0:"";}s:6:"select";a:2:{s:14:"allowed_values";s:0:"";s:23:"allowed_values_function";s:1:"0";}s:6:"radios";a:2:{s:14:"allowed_values";s:0:"";s:23:"allowed_values_function";s:1:"0";}s:10:"checkboxes";a:2:{s:14:"allowed_values";s:0:"";s:23:"allowed_values_function";s:1:"0";}s:11:"calculation";a:4:{s:11:"calculation";s:3:"sum";s:6:"prefix";s:0:"";s:6:"suffix";s:0:"";s:8:"rounding";s:0:"";}s:6:"custom";a:1:{s:6:"custom";s:32:"matrix_custom_processing_example";}}}}',
      ),
      'translatable' => '1',
      'type' => 'matrix_custom',
    ),
    'field_instance' => array(
      'bundle' => 'site',
      'deleted' => '0',
      'description' => '',
      'display' => array(
        'default' => array(
          'label' => 'above',
          'module' => 's4_sites',
          'settings' => array(),
          'type' => 's4_sites_population_matrix',
          'weight' => '17',
        ),
        'full' => array(
          'label' => 'above',
          'module' => 'matrix',
          'settings' => array(),
          'type' => 'matrix_default',
          'weight' => '13',
        ),
        'notifications' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => 0,
        ),
        'teaser' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => 0,
        ),
      ),
      'display_label' => 'Population served',
      'entity_type' => 'node',
      'field_name' => 'field_site_demographics',
      'label' => 'By percentage, what is the demographic of the population you serve?',
      'required' => 0,
      's4_sites_field_access' => 1,
      'settings' => array(
        'user_register_form' => FALSE,
      ),
      'widget' => array(
        'active' => 0,
        'module' => 'matrix',
        'settings' => array(),
        'type' => 'matrix_custom',
        'weight' => '27',
      ),
    ),
  );

  // Exported field: 'node-site-field_site_email'
  $fields['node-site-field_site_email'] = array(
    'field_config' => array(
      'active' => '1',
      'cardinality' => '1',
      'deleted' => '0',
      'entity_types' => array(),
      'field_name' => 'field_site_email',
      'foreign keys' => array(),
      'global_block_settings' => '1',
      'indexes' => array(),
      'module' => 'email',
      'settings' => array(),
      'translatable' => '1',
      'type' => 'email',
    ),
    'field_instance' => array(
      'bundle' => 'site',
      'default_value' => NULL,
      'deleted' => '0',
      'description' => 'This will be shown to the public, so only include a generic email contact for the site.',
      'display' => array(
        'default' => array(
          'label' => 'above',
          'module' => 'email',
          'settings' => array(),
          'type' => 'email_default',
          'weight' => '12',
        ),
        'full' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => 0,
        ),
        'notifications' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => 0,
        ),
        'teaser' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => 0,
        ),
      ),
      'entity_type' => 'node',
      'field_name' => 'field_site_email',
      'label' => 'Contact email',
      'required' => 0,
      'settings' => array(
        'user_register_form' => FALSE,
      ),
      'widget' => array(
        'active' => 1,
        'module' => 'email',
        'settings' => array(
          'size' => '60',
        ),
        'type' => 'email_textfield',
        'weight' => '0',
      ),
    ),
  );

  // Exported field: 'node-site-field_site_evaluation_group'
  $fields['node-site-field_site_evaluation_group'] = array(
    'field_config' => array(
      'active' => '1',
      'cardinality' => '-1',
      'deleted' => '0',
      'entity_types' => array(),
      'field_name' => 'field_site_evaluation_group',
      'foreign keys' => array(),
      'indexes' => array(),
      'module' => 'field_collection',
      'settings' => array(
        'path' => '',
      ),
      'translatable' => '0',
      'type' => 'field_collection',
    ),
    'field_instance' => array(
      'bundle' => 'site',
      'default_value' => NULL,
      'deleted' => '0',
      'description' => '',
      'display' => array(
        'default' => array(
          'label' => 'above',
          'module' => 'field_collection',
          'settings' => array(
            'add' => 'Add',
            'delete' => 'Delete',
            'description' => TRUE,
            'edit' => 'Edit',
          ),
          'type' => 'field_collection_list',
          'weight' => '37',
        ),
        'notifications' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => 0,
        ),
        'teaser' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => 0,
        ),
      ),
      'display_label' => '',
      'entity_type' => 'node',
      'field_name' => 'field_site_evaluation_group',
      'label' => 'Evaluation forms',
      'required' => 0,
      's4_sites_field_access' => 1,
      'settings' => array(
        'user_register_form' => FALSE,
      ),
      'widget' => array(
        'active' => 0,
        'module' => 'field_collection_table',
        'settings' => array(),
        'type' => 'field_collection_table',
        'weight' => '31',
      ),
    ),
  );

  // Exported field: 'node-site-field_site_facebook_page'
  $fields['node-site-field_site_facebook_page'] = array(
    'field_config' => array(
      'active' => '1',
      'cardinality' => '1',
      'deleted' => '0',
      'entity_types' => array(),
      'field_name' => 'field_site_facebook_page',
      'foreign keys' => array(),
      'global_block_settings' => '2',
      'indexes' => array(),
      'module' => 'link',
      'settings' => array(
        'attributes' => array(
          'class' => '',
          'rel' => '',
          'target' => 'default',
        ),
        'display' => array(
          'url_cutoff' => 80,
        ),
        'enable_tokens' => 1,
        'title' => 'optional',
        'title_maxlength' => 128,
        'title_value' => '',
        'url' => 0,
      ),
      'translatable' => '1',
      'type' => 'link_field',
    ),
    'field_instance' => array(
      'bundle' => 'site',
      'default_value' => NULL,
      'deleted' => '0',
      'description' => 'If your organization has a presence on Facebook, Twitter, or another social network, please provide the address.',
      'display' => array(
        'default' => array(
          'label' => 'above',
          'module' => 'link',
          'settings' => array(),
          'type' => 'link_default',
          'weight' => '15',
        ),
        'full' => array(
          'label' => 'above',
          'module' => 'link',
          'settings' => array(),
          'type' => 'link_default',
          'weight' => '14',
        ),
        'notifications' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => 0,
        ),
        'teaser' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => 0,
        ),
      ),
      'entity_type' => 'node',
      'field_name' => 'field_site_facebook_page',
      'label' => 'Social network page',
      'required' => 0,
      'settings' => array(
        'attributes' => array(
          'class' => 'social-link',
          'rel' => '',
          'target' => '_blank',
        ),
        'display' => array(
          'url_cutoff' => '80',
        ),
        'enable_tokens' => 0,
        'title' => 'none',
        'title_maxlength' => 128,
        'title_value' => '',
        'url' => 0,
        'user_register_form' => FALSE,
        'validate_url' => 1,
      ),
      'widget' => array(
        'active' => 0,
        'module' => 'link',
        'settings' => array(),
        'type' => 'link_field',
        'weight' => '2',
      ),
    ),
  );

  // Exported field: 'node-site-field_site_health_training'
  $fields['node-site-field_site_health_training'] = array(
    'field_config' => array(
      'active' => '1',
      'cardinality' => '1',
      'deleted' => '0',
      'entity_types' => array(),
      'field_name' => 'field_site_health_training',
      'foreign keys' => array(
        'format' => array(
          'columns' => array(
            'format' => 'format',
          ),
          'table' => 'filter_format',
        ),
      ),
      'global_block_settings' => '1',
      'indexes' => array(
        'format' => array(
          0 => 'format',
        ),
      ),
      'module' => 'text',
      'settings' => array(),
      'translatable' => '1',
      'type' => 'text_long',
    ),
    'field_instance' => array(
      'bundle' => 'site',
      'default_value' => NULL,
      'deleted' => '0',
      'description' => '',
      'display' => array(
        'default' => array(
          'label' => 'above',
          'module' => 'text',
          'settings' => array(),
          'type' => 'text_default',
          'weight' => '1',
        ),
        'full' => array(
          'label' => 'above',
          'module' => 'text',
          'settings' => array(),
          'type' => 'text_default',
          'weight' => '2',
        ),
        'notifications' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => 0,
        ),
        'teaser' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => 0,
        ),
      ),
      'entity_type' => 'node',
      'field_name' => 'field_site_health_training',
      'label' => 'Training and orientation information',
      'required' => 0,
      'settings' => array(
        'text_processing' => '1',
        'user_register_form' => FALSE,
      ),
      'widget' => array(
        'active' => 1,
        'module' => 'text',
        'settings' => array(
          'rows' => '5',
        ),
        'type' => 'text_textarea',
        'weight' => '26',
      ),
    ),
  );

  // Exported field: 'node-site-field_site_hours'
  $fields['node-site-field_site_hours'] = array(
    'field_config' => array(
      'active' => '1',
      'cardinality' => '-1',
      'deleted' => '0',
      'entity_types' => array(),
      'field_name' => 'field_site_hours',
      'foreign keys' => array(),
      'global_block_settings' => '1',
      'indexes' => array(
        'col' => array(
          0 => 'col',
        ),
        'row' => array(
          0 => 'row',
        ),
        'value' => array(
          0 => 'value',
        ),
      ),
      'module' => 'matrix',
      'settings' => array(
        'cols_count' => '7',
        'define' => 'cols',
        'preview' => array(
          'cols' => array(
            1 => array(
              'button' => 'Change settings',
            ),
            2 => array(
              'button' => 'Change settings',
            ),
            3 => array(
              'button' => 'Change settings',
            ),
            4 => array(
              'button' => 'Change settings',
            ),
            5 => array(
              'button' => 'Change settings',
            ),
            6 => array(
              'button' => 'Change settings',
            ),
            7 => array(
              'button' => 'Change settings',
            ),
          ),
          'define' => 'cols',
          'rows' => array(
            1 => array(
              'button' => 'Change settings',
            ),
            2 => array(
              'button' => 'Change settings',
            ),
            3 => array(
              'button' => 'Change settings',
            ),
            4 => array(
              'button' => 'Change settings',
            ),
            5 => array(
              'button' => 'Change settings',
            ),
            6 => array(
              'button' => 'Change settings',
            ),
            7 => array(
              'button' => 'Change settings',
            ),
            8 => array(
              'button' => 'Change settings',
            ),
          ),
        ),
        'rows_count' => '8',
        'settings' => 'a:6:{i:0;b:0;s:10:"old_define";s:4:"cols";s:14:"old_rows_count";s:1:"8";s:14:"old_cols_count";s:1:"7";s:4:"cols";a:7:{i:1;a:8:{s:10:"field_type";s:10:"checkboxes";s:5:"title";s:6:"Monday";s:9:"textfield";a:3:{s:4:"size";s:0:"";s:6:"prefix";s:0:"";s:6:"suffix";s:0:"";}s:6:"select";a:2:{s:14:"allowed_values";s:0:"";s:23:"allowed_values_function";s:1:"0";}s:6:"radios";a:2:{s:14:"allowed_values";s:0:"";s:23:"allowed_values_function";s:1:"0";}s:10:"checkboxes";a:2:{s:14:"allowed_values";s:7:"Monday|";s:23:"allowed_values_function";s:1:"0";}s:11:"calculation";a:4:{s:11:"calculation";s:3:"sum";s:6:"prefix";s:0:"";s:6:"suffix";s:0:"";s:8:"rounding";s:0:"";}s:6:"custom";a:1:{s:6:"custom";s:32:"matrix_custom_processing_example";}}i:2;a:8:{s:10:"field_type";s:10:"checkboxes";s:5:"title";s:7:"Tuesday";s:9:"textfield";a:3:{s:4:"size";s:0:"";s:6:"prefix";s:0:"";s:6:"suffix";s:0:"";}s:6:"select";a:2:{s:14:"allowed_values";s:0:"";s:23:"allowed_values_function";s:1:"0";}s:6:"radios";a:2:{s:14:"allowed_values";s:0:"";s:23:"allowed_values_function";s:1:"0";}s:10:"checkboxes";a:2:{s:14:"allowed_values";s:8:"Tuesday|";s:23:"allowed_values_function";s:1:"0";}s:11:"calculation";a:4:{s:11:"calculation";s:3:"sum";s:6:"prefix";s:0:"";s:6:"suffix";s:0:"";s:8:"rounding";s:0:"";}s:6:"custom";a:1:{s:6:"custom";s:32:"matrix_custom_processing_example";}}i:3;a:8:{s:10:"field_type";s:10:"checkboxes";s:5:"title";s:9:"Wednesday";s:9:"textfield";a:3:{s:4:"size";s:0:"";s:6:"prefix";s:0:"";s:6:"suffix";s:0:"";}s:6:"select";a:2:{s:14:"allowed_values";s:0:"";s:23:"allowed_values_function";s:1:"0";}s:6:"radios";a:2:{s:14:"allowed_values";s:0:"";s:23:"allowed_values_function";s:1:"0";}s:10:"checkboxes";a:2:{s:14:"allowed_values";s:10:"Wednesday|";s:23:"allowed_values_function";s:1:"0";}s:11:"calculation";a:4:{s:11:"calculation";s:3:"sum";s:6:"prefix";s:0:"";s:6:"suffix";s:0:"";s:8:"rounding";s:0:"";}s:6:"custom";a:1:{s:6:"custom";s:32:"matrix_custom_processing_example";}}i:4;a:8:{s:10:"field_type";s:10:"checkboxes";s:5:"title";s:8:"Thursday";s:9:"textfield";a:3:{s:4:"size";s:0:"";s:6:"prefix";s:0:"";s:6:"suffix";s:0:"";}s:6:"select";a:2:{s:14:"allowed_values";s:0:"";s:23:"allowed_values_function";s:1:"0";}s:6:"radios";a:2:{s:14:"allowed_values";s:0:"";s:23:"allowed_values_function";s:1:"0";}s:10:"checkboxes";a:2:{s:14:"allowed_values";s:9:"Thursday|";s:23:"allowed_values_function";s:1:"0";}s:11:"calculation";a:4:{s:11:"calculation";s:3:"sum";s:6:"prefix";s:0:"";s:6:"suffix";s:0:"";s:8:"rounding";s:0:"";}s:6:"custom";a:1:{s:6:"custom";s:32:"matrix_custom_processing_example";}}i:5;a:8:{s:10:"field_type";s:10:"checkboxes";s:5:"title";s:6:"Friday";s:9:"textfield";a:3:{s:4:"size";s:0:"";s:6:"prefix";s:0:"";s:6:"suffix";s:0:"";}s:6:"select";a:2:{s:14:"allowed_values";s:0:"";s:23:"allowed_values_function";s:1:"0";}s:6:"radios";a:2:{s:14:"allowed_values";s:0:"";s:23:"allowed_values_function";s:1:"0";}s:10:"checkboxes";a:2:{s:14:"allowed_values";s:7:"Friday|";s:23:"allowed_values_function";s:1:"0";}s:11:"calculation";a:4:{s:11:"calculation";s:3:"sum";s:6:"prefix";s:0:"";s:6:"suffix";s:0:"";s:8:"rounding";s:0:"";}s:6:"custom";a:1:{s:6:"custom";s:32:"matrix_custom_processing_example";}}i:6;a:8:{s:10:"field_type";s:10:"checkboxes";s:5:"title";s:8:"Saturday";s:9:"textfield";a:3:{s:4:"size";s:0:"";s:6:"prefix";s:0:"";s:6:"suffix";s:0:"";}s:6:"select";a:2:{s:14:"allowed_values";s:0:"";s:23:"allowed_values_function";s:1:"0";}s:6:"radios";a:2:{s:14:"allowed_values";s:0:"";s:23:"allowed_values_function";s:1:"0";}s:10:"checkboxes";a:2:{s:14:"allowed_values";s:9:"Saturday|";s:23:"allowed_values_function";s:1:"0";}s:11:"calculation";a:4:{s:11:"calculation";s:3:"sum";s:6:"prefix";s:0:"";s:6:"suffix";s:0:"";s:8:"rounding";s:0:"";}s:6:"custom";a:1:{s:6:"custom";s:32:"matrix_custom_processing_example";}}i:7;a:8:{s:10:"field_type";s:10:"checkboxes";s:5:"title";s:6:"Sunday";s:9:"textfield";a:3:{s:4:"size";s:0:"";s:6:"prefix";s:0:"";s:6:"suffix";s:0:"";}s:6:"select";a:2:{s:14:"allowed_values";s:0:"";s:23:"allowed_values_function";s:1:"0";}s:6:"radios";a:2:{s:14:"allowed_values";s:0:"";s:23:"allowed_values_function";s:1:"0";}s:10:"checkboxes";a:2:{s:14:"allowed_values";s:7:"Sunday|";s:23:"allowed_values_function";s:1:"0";}s:11:"calculation";a:4:{s:11:"calculation";s:3:"sum";s:6:"prefix";s:0:"";s:6:"suffix";s:0:"";s:8:"rounding";s:0:"";}s:6:"custom";a:1:{s:6:"custom";s:32:"matrix_custom_processing_example";}}}s:4:"rows";a:8:{i:1;a:8:{s:10:"field_type";s:4:"none";s:5:"title";s:10:"6 - 8 a.m.";s:9:"textfield";a:3:{s:4:"size";s:0:"";s:6:"prefix";s:0:"";s:6:"suffix";s:0:"";}s:6:"select";a:2:{s:14:"allowed_values";s:0:"";s:23:"allowed_values_function";s:1:"0";}s:6:"radios";a:2:{s:14:"allowed_values";s:0:"";s:23:"allowed_values_function";s:1:"0";}s:10:"checkboxes";a:2:{s:14:"allowed_values";s:0:"";s:23:"allowed_values_function";s:1:"0";}s:11:"calculation";a:4:{s:11:"calculation";s:3:"sum";s:6:"prefix";s:0:"";s:6:"suffix";s:0:"";s:8:"rounding";s:0:"";}s:6:"custom";a:1:{s:6:"custom";s:32:"matrix_custom_processing_example";}}i:2;a:8:{s:10:"field_type";s:4:"none";s:5:"title";s:11:"8 - 10 a.m.";s:9:"textfield";a:3:{s:4:"size";s:0:"";s:6:"prefix";s:0:"";s:6:"suffix";s:0:"";}s:6:"select";a:2:{s:14:"allowed_values";s:0:"";s:23:"allowed_values_function";s:1:"0";}s:6:"radios";a:2:{s:14:"allowed_values";s:0:"";s:23:"allowed_values_function";s:1:"0";}s:10:"checkboxes";a:2:{s:14:"allowed_values";s:0:"";s:23:"allowed_values_function";s:1:"0";}s:11:"calculation";a:4:{s:11:"calculation";s:3:"sum";s:6:"prefix";s:0:"";s:6:"suffix";s:0:"";s:8:"rounding";s:0:"";}s:6:"custom";a:1:{s:6:"custom";s:32:"matrix_custom_processing_example";}}i:3;a:8:{s:10:"field_type";s:4:"none";s:5:"title";s:9:"10 - Noon";s:9:"textfield";a:3:{s:4:"size";s:0:"";s:6:"prefix";s:0:"";s:6:"suffix";s:0:"";}s:6:"select";a:2:{s:14:"allowed_values";s:0:"";s:23:"allowed_values_function";s:1:"0";}s:6:"radios";a:2:{s:14:"allowed_values";s:0:"";s:23:"allowed_values_function";s:1:"0";}s:10:"checkboxes";a:2:{s:14:"allowed_values";s:0:"";s:23:"allowed_values_function";s:1:"0";}s:11:"calculation";a:4:{s:11:"calculation";s:3:"sum";s:6:"prefix";s:0:"";s:6:"suffix";s:0:"";s:8:"rounding";s:0:"";}s:6:"custom";a:1:{s:6:"custom";s:32:"matrix_custom_processing_example";}}i:4;a:8:{s:10:"field_type";s:4:"none";s:5:"title";s:13:"Noon - 2 p.m.";s:9:"textfield";a:3:{s:4:"size";s:0:"";s:6:"prefix";s:0:"";s:6:"suffix";s:0:"";}s:6:"select";a:2:{s:14:"allowed_values";s:0:"";s:23:"allowed_values_function";s:1:"0";}s:6:"radios";a:2:{s:14:"allowed_values";s:0:"";s:23:"allowed_values_function";s:1:"0";}s:10:"checkboxes";a:2:{s:14:"allowed_values";s:0:"";s:23:"allowed_values_function";s:1:"0";}s:11:"calculation";a:4:{s:11:"calculation";s:3:"sum";s:6:"prefix";s:0:"";s:6:"suffix";s:0:"";s:8:"rounding";s:0:"";}s:6:"custom";a:1:{s:6:"custom";s:32:"matrix_custom_processing_example";}}i:5;a:8:{s:10:"field_type";s:4:"none";s:5:"title";s:10:"2 - 4 p.m.";s:9:"textfield";a:3:{s:4:"size";s:0:"";s:6:"prefix";s:0:"";s:6:"suffix";s:0:"";}s:6:"select";a:2:{s:14:"allowed_values";s:0:"";s:23:"allowed_values_function";s:1:"0";}s:6:"radios";a:2:{s:14:"allowed_values";s:0:"";s:23:"allowed_values_function";s:1:"0";}s:10:"checkboxes";a:2:{s:14:"allowed_values";s:0:"";s:23:"allowed_values_function";s:1:"0";}s:11:"calculation";a:4:{s:11:"calculation";s:3:"sum";s:6:"prefix";s:0:"";s:6:"suffix";s:0:"";s:8:"rounding";s:0:"";}s:6:"custom";a:1:{s:6:"custom";s:32:"matrix_custom_processing_example";}}i:6;a:8:{s:10:"field_type";s:4:"none";s:5:"title";s:10:"4 - 6 p.m.";s:9:"textfield";a:3:{s:4:"size";s:0:"";s:6:"prefix";s:0:"";s:6:"suffix";s:0:"";}s:6:"select";a:2:{s:14:"allowed_values";s:0:"";s:23:"allowed_values_function";s:1:"0";}s:6:"radios";a:2:{s:14:"allowed_values";s:0:"";s:23:"allowed_values_function";s:1:"0";}s:10:"checkboxes";a:2:{s:14:"allowed_values";s:0:"";s:23:"allowed_values_function";s:1:"0";}s:11:"calculation";a:4:{s:11:"calculation";s:3:"sum";s:6:"prefix";s:0:"";s:6:"suffix";s:0:"";s:8:"rounding";s:0:"";}s:6:"custom";a:1:{s:6:"custom";s:32:"matrix_custom_processing_example";}}i:7;a:8:{s:10:"field_type";s:4:"none";s:5:"title";s:10:"6 - 8 p.m.";s:9:"textfield";a:3:{s:4:"size";s:0:"";s:6:"prefix";s:0:"";s:6:"suffix";s:0:"";}s:6:"select";a:2:{s:14:"allowed_values";s:0:"";s:23:"allowed_values_function";s:1:"0";}s:6:"radios";a:2:{s:14:"allowed_values";s:0:"";s:23:"allowed_values_function";s:1:"0";}s:10:"checkboxes";a:2:{s:14:"allowed_values";s:0:"";s:23:"allowed_values_function";s:1:"0";}s:11:"calculation";a:4:{s:11:"calculation";s:3:"sum";s:6:"prefix";s:0:"";s:6:"suffix";s:0:"";s:8:"rounding";s:0:"";}s:6:"custom";a:1:{s:6:"custom";s:32:"matrix_custom_processing_example";}}i:8;a:8:{s:10:"field_type";s:4:"none";s:5:"title";s:11:"8 - 10 p.m.";s:9:"textfield";a:3:{s:4:"size";s:0:"";s:6:"prefix";s:0:"";s:6:"suffix";s:0:"";}s:6:"select";a:2:{s:14:"allowed_values";s:0:"";s:23:"allowed_values_function";s:1:"0";}s:6:"radios";a:2:{s:14:"allowed_values";s:0:"";s:23:"allowed_values_function";s:1:"0";}s:10:"checkboxes";a:2:{s:14:"allowed_values";s:0:"";s:23:"allowed_values_function";s:1:"0";}s:11:"calculation";a:4:{s:11:"calculation";s:3:"sum";s:6:"prefix";s:0:"";s:6:"suffix";s:0:"";s:8:"rounding";s:0:"";}s:6:"custom";a:1:{s:6:"custom";s:32:"matrix_custom_processing_example";}}}}',
      ),
      'translatable' => '1',
      'type' => 'matrix_custom',
    ),
    'field_instance' => array(
      'bundle' => 'site',
      'deleted' => '0',
      'description' => '',
      'display' => array(
        'default' => array(
          'label' => 'above',
          'module' => 's4_sites',
          'settings' => array(),
          'type' => 's4_sites_hours_matrix',
          'weight' => '5',
        ),
        'full' => array(
          'label' => 'above',
          'module' => 'matrix',
          'settings' => array(),
          'type' => 'matrix_default',
          'weight' => '10',
        ),
        'notifications' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => 0,
        ),
        'teaser' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => 0,
        ),
      ),
      'entity_type' => 'node',
      'field_name' => 'field_site_hours',
      'label' => 'Days and hours will you accept students for service (check all that apply)',
      'required' => 0,
      'settings' => array(
        'user_register_form' => FALSE,
      ),
      'widget' => array(
        'active' => 0,
        'module' => 'matrix',
        'settings' => array(),
        'type' => 'matrix_custom',
        'weight' => '29',
      ),
    ),
  );

  // Exported field: 'node-site-field_site_hours_minimum'
  $fields['node-site-field_site_hours_minimum'] = array(
    'field_config' => array(
      'active' => '1',
      'cardinality' => '1',
      'deleted' => '0',
      'entity_types' => array(),
      'field_name' => 'field_site_hours_minimum',
      'foreign keys' => array(),
      'global_block_settings' => '1',
      'indexes' => array(
        'value' => array(
          0 => 'value',
        ),
      ),
      'module' => 'list',
      'settings' => array(
        'allowed_values' => array(
          1 => '1-10',
          10 => '11-20',
          20 => '21-30',
          30 => '31-40',
          40 => '41-50',
          50 => '51-60',
          60 => '61-70',
          70 => '71-80',
          80 => 'More than 80',
        ),
        'allowed_values_function' => '',
        'allowed_values_php' => '',
      ),
      'translatable' => '1',
      'type' => 'list_integer',
    ),
    'field_instance' => array(
      'bundle' => 'site',
      'default_value' => array(
        0 => array(
          'value' => '30',
        ),
      ),
      'default_value_function' => '',
      'default_value_php' => '',
      'deleted' => '0',
      'description' => '',
      'display' => array(
        'default' => array(
          'label' => 'above',
          'module' => 'list',
          'settings' => array(),
          'type' => 'list_default',
          'weight' => '20',
        ),
        'full' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => '11',
        ),
        'notifications' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => 0,
        ),
        'teaser' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => 0,
        ),
      ),
      'display_label' => 'Minimum hours',
      'entity_type' => 'node',
      'field_name' => 'field_site_hours_minimum',
      'label' => 'What is the minimum number of hours you would require of a student in service per term',
      'required' => 0,
      's4_sites_field_access' => 1,
      'settings' => array(
        'user_register_form' => FALSE,
      ),
      'widget' => array(
        'active' => 1,
        'module' => 'options',
        'settings' => array(),
        'type' => 'options_select',
        'weight' => '28',
      ),
    ),
  );

  // Exported field: 'node-site-field_site_instructions'
  $fields['node-site-field_site_instructions'] = array(
    'field_config' => array(
      'active' => '1',
      'cardinality' => '1',
      'deleted' => '0',
      'entity_types' => array(),
      'field_name' => 'field_site_instructions',
      'foreign keys' => array(
        'format' => array(
          'columns' => array(
            'format' => 'format',
          ),
          'table' => 'filter_format',
        ),
      ),
      'global_block_settings' => '2',
      'indexes' => array(
        'format' => array(
          0 => 'format',
        ),
      ),
      'module' => 'text',
      'settings' => array(),
      'translatable' => '1',
      'type' => 'text_long',
    ),
    'field_instance' => array(
      'bundle' => 'site',
      'default_value' => NULL,
      'deleted' => '0',
      'description' => '',
      'display' => array(
        'default' => array(
          'label' => 'above',
          'module' => 'text',
          'settings' => array(),
          'type' => 'text_default',
          'weight' => '32',
        ),
        'full' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => 0,
        ),
        'notifications' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => 0,
        ),
        'teaser' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => 0,
        ),
      ),
      'entity_type' => 'node',
      'field_name' => 'field_site_instructions',
      'label' => 'Special site instructions',
      'required' => 0,
      'settings' => array(
        'text_processing' => '1',
        'user_register_form' => FALSE,
      ),
      'widget' => array(
        'active' => 1,
        'module' => 'text',
        'settings' => array(
          'rows' => '5',
        ),
        'type' => 'text_textarea',
        'weight' => '24',
      ),
    ),
  );

  // Exported field: 'node-site-field_site_instructions_required'
  $fields['node-site-field_site_instructions_required'] = array(
    'field_config' => array(
      'active' => '1',
      'cardinality' => '1',
      'deleted' => '0',
      'entity_types' => array(),
      'field_name' => 'field_site_instructions_required',
      'foreign keys' => array(),
      'global_block_settings' => '1',
      'indexes' => array(
        'value' => array(
          0 => 'value',
        ),
      ),
      'module' => 'list',
      'settings' => array(
        'allowed_values' => array(
          0 => '',
          1 => '',
        ),
        'allowed_values_function' => '',
        'allowed_values_php' => '',
      ),
      'translatable' => '1',
      'type' => 'list_boolean',
    ),
    'field_instance' => array(
      'bundle' => 'site',
      'default_value' => array(
        0 => array(
          'value' => 0,
        ),
      ),
      'default_value_function' => '',
      'default_value_php' => '',
      'deleted' => '0',
      'description' => 'This information will be displayed to students before they sign up. This could contain additional information the student needs to know when they sign up for issues like TB testing, background checks, or specialized training',
      'display' => array(
        'default' => array(
          'label' => 'above',
          'module' => 'list',
          'settings' => array(),
          'type' => 'list_default',
          'weight' => '35',
        ),
        'full' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => 0,
        ),
        'notifications' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => 0,
        ),
        'teaser' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => 0,
        ),
      ),
      'entity_type' => 'node',
      'field_name' => 'field_site_instructions_required',
      'label' => 'Site has special requirements',
      'required' => 0,
      'settings' => array(
        'user_register_form' => FALSE,
      ),
      'widget' => array(
        'active' => 1,
        'module' => 'options',
        'settings' => array(
          'display_label' => 1,
        ),
        'type' => 'options_onoff',
        'weight' => '23',
      ),
    ),
  );

  // Exported field: 'node-site-field_site_language'
  $fields['node-site-field_site_language'] = array(
    'field_config' => array(
      'active' => '1',
      'cardinality' => '-1',
      'deleted' => '0',
      'entity_types' => array(),
      'field_name' => 'field_site_language',
      'foreign keys' => array(
        'tid' => array(
          'columns' => array(
            'tid' => 'tid',
          ),
          'table' => 'taxonomy_term_data',
        ),
      ),
      'global_block_settings' => '1',
      'indexes' => array(
        'tid' => array(
          0 => 'tid',
        ),
      ),
      'module' => 'taxonomy',
      'settings' => array(
        'allowed_values' => array(
          0 => array(
            'vocabulary' => 'language',
            'parent' => '0',
          ),
        ),
      ),
      'translatable' => '1',
      'type' => 'taxonomy_term_reference',
    ),
    'field_instance' => array(
      'bundle' => 'site',
      'default_value' => NULL,
      'deleted' => '0',
      'description' => '',
      'display' => array(
        'default' => array(
          'label' => 'above',
          'module' => 'taxonomy',
          'settings' => array(),
          'type' => 'taxonomy_term_reference_link',
          'weight' => '18',
        ),
        'full' => array(
          'label' => 'above',
          'module' => 'taxonomy',
          'settings' => array(),
          'type' => 'taxonomy_term_reference_link',
          'weight' => '15',
        ),
        'notifications' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => 0,
        ),
        'teaser' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => 0,
        ),
      ),
      'display_label' => 'Languages',
      'entity_type' => 'node',
      'field_name' => 'field_site_language',
      'label' => 'What languages would you like students to speak other than English?',
      'required' => 0,
      's4_sites_field_access' => 0,
      'settings' => array(
        'user_register_form' => FALSE,
      ),
      'widget' => array(
        'active' => 1,
        'module' => 'options',
        'settings' => array(),
        'type' => 'options_select',
        'weight' => '2',
      ),
    ),
  );

  // Exported field: 'node-site-field_site_other_csu'
  $fields['node-site-field_site_other_csu'] = array(
    'field_config' => array(
      'active' => '1',
      'cardinality' => '-1',
      'deleted' => '0',
      'entity_types' => array(),
      'field_name' => 'field_site_other_csu',
      'foreign keys' => array(),
      'indexes' => array(
        'value' => array(
          0 => 'value',
        ),
      ),
      'module' => 'list',
      'settings' => array(
        'allowed_values' => array(
          'California State University Bakersfield' => 'California State University Bakersfield',
          'California State University Channel Islands' => 'California State University Channel Islands',
          'California State University Chico' => 'California State University Chico',
          'California State University Dominguez Hills' => 'California State University Dominguez Hills',
          'California State University East Bay' => 'California State University East Bay',
          'California State University Fresno' => 'California State University Fresno',
          'California State University Fullerton' => 'California State University Fullerton',
          'Humboldt State University' => 'Humboldt State University',
          'California State University Long Beach' => 'California State University Long Beach',
          'California State University Los Angeles' => 'California State University Los Angeles',
          'California Maritime Academy' => 'California Maritime Academy',
          'California State University Monterey Bay' => 'California State University Monterey Bay',
          'California State University Northridge' => 'California State University Northridge',
          'California State Polytechnic University, Pomona' => 'California State Polytechnic University, Pomona',
          'California State University Sacramento' => 'California State University Sacramento',
          'California State University San Bernardino' => 'California State University San Bernardino',
          'San Diego State University' => 'San Diego State University',
          'San Francisco State University' => 'San Francisco State University',
          'San Jose State University' => 'San Jose State University',
          'California Polytechnic State University, San Luis Obispo' => 'California Polytechnic State University, San Luis Obispo',
          'California State University San Marcos' => 'California State University San Marcos',
          'Sonoma State University' => 'Sonoma State University',
          'California State University Stanislaus' => 'California State University Stanislaus',
        ),
        'allowed_values_function' => '',
        'allowed_values_php' => '',
      ),
      'translatable' => '0',
      'type' => 'list_text',
    ),
    'field_instance' => array(
      'bundle' => 'site',
      'default_value' => NULL,
      'default_value_function' => '',
      'default_value_php' => '',
      'deleted' => '0',
      'description' => '',
      'display' => array(
        'default' => array(
          'label' => 'above',
          'module' => 'list',
          'settings' => array(),
          'type' => 'list_default',
          'weight' => '38',
        ),
        'notifications' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => 0,
        ),
        'teaser' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => 0,
        ),
      ),
      'display_label' => 'Other campuses',
      'entity_type' => 'node',
      'field_name' => 'field_site_other_csu',
      'label' => 'Do you have a partnership with another CSU campus?',
      'required' => 0,
      's4_sites_field_access' => 1,
      'settings' => array(
        'user_register_form' => FALSE,
      ),
      'widget' => array(
        'active' => 1,
        'module' => 'options',
        'settings' => array(),
        'type' => 'options_select',
        'weight' => '6',
      ),
    ),
  );

  // Exported field: 'node-site-field_site_projects'
  $fields['node-site-field_site_projects'] = array(
    'field_config' => array(
      'active' => '1',
      'cardinality' => '1',
      'deleted' => '0',
      'entity_types' => array(),
      'field_name' => 'field_site_projects',
      'foreign keys' => array(
        'format' => array(
          'columns' => array(
            'format' => 'format',
          ),
          'table' => 'filter_format',
        ),
      ),
      'global_block_settings' => '1',
      'indexes' => array(
        'format' => array(
          0 => 'format',
        ),
      ),
      'module' => 'text',
      'settings' => array(),
      'translatable' => '1',
      'type' => 'text_long',
    ),
    'field_instance' => array(
      'bundle' => 'site',
      'default_value' => NULL,
      'deleted' => '0',
      'description' => '',
      'display' => array(
        'default' => array(
          'label' => 'above',
          'module' => 'text',
          'settings' => array(),
          'type' => 'text_default',
          'weight' => '3',
        ),
        'full' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => '1',
        ),
        'notifications' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => 0,
        ),
        'teaser' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => 0,
        ),
      ),
      'display_label' => 'Ongoing needs and special projects',
      'entity_type' => 'node',
      'field_name' => 'field_site_projects',
      'label' => 'Briefly describe any ongoing needs or special projects with which students can assist agency staff',
      'required' => 0,
      's4_sites_field_access' => 1,
      'settings' => array(
        'text_processing' => '1',
        'user_register_form' => FALSE,
      ),
      'widget' => array(
        'active' => 1,
        'module' => 'text',
        'settings' => array(
          'rows' => '5',
        ),
        'type' => 'text_textarea',
        'weight' => '-3',
      ),
    ),
  );

  // Exported field: 'node-site-field_site_requirements'
  $fields['node-site-field_site_requirements'] = array(
    'field_config' => array(
      'active' => '1',
      'cardinality' => '-1',
      'deleted' => '0',
      'entity_types' => array(),
      'field_name' => 'field_site_requirements',
      'foreign keys' => array(
        'tid' => array(
          'columns' => array(
            'tid' => 'tid',
          ),
          'table' => 'taxonomy_term_data',
        ),
      ),
      'global_block_settings' => '2',
      'indexes' => array(
        'tid' => array(
          0 => 'tid',
        ),
      ),
      'module' => 'taxonomy',
      'settings' => array(
        'allowed_values' => array(
          0 => array(
            'parent' => '0',
            'vocabulary' => 'special_requirements',
          ),
        ),
      ),
      'translatable' => '1',
      'type' => 'taxonomy_term_reference',
    ),
    'field_instance' => array(
      'bundle' => 'site',
      'default_value' => NULL,
      'deleted' => '0',
      'description' => '',
      'display' => array(
        'default' => array(
          'label' => 'above',
          'module' => 'taxonomy',
          'settings' => array(),
          'type' => 'taxonomy_term_reference_link',
          'weight' => '19',
        ),
        'full' => array(
          'label' => 'above',
          'module' => 'taxonomy',
          'settings' => array(),
          'type' => 'taxonomy_term_reference_link',
          'weight' => '16',
        ),
        'notifications' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => 0,
        ),
        'teaser' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => 0,
        ),
      ),
      'entity_type' => 'node',
      'field_name' => 'field_site_requirements',
      'label' => 'Site special requirements',
      'required' => 0,
      'settings' => array(
        'user_register_form' => FALSE,
      ),
      'widget' => array(
        'active' => 1,
        'module' => 'options',
        'settings' => array(),
        'type' => 'options_buttons',
        'weight' => '25',
      ),
    ),
  );

  // Exported field: 'node-site-field_site_restrict'
  $fields['node-site-field_site_restrict'] = array(
    'field_config' => array(
      'active' => '1',
      'cardinality' => '-1',
      'deleted' => '0',
      'entity_types' => array(),
      'field_name' => 'field_site_restrict',
      'foreign keys' => array(
        'tid' => array(
          'columns' => array(
            'tid' => 'tid',
          ),
          'table' => 'taxonomy_term_data',
        ),
      ),
      'global_block_settings' => '2',
      'indexes' => array(
        'tid' => array(
          0 => 'tid',
        ),
      ),
      'module' => 'taxonomy',
      'settings' => array(
        'allowed_values' => array(
          0 => array(
            'vocabulary' => 'site_restrictions',
            'parent' => '0',
          ),
        ),
      ),
      'translatable' => '1',
      'type' => 'taxonomy_term_reference',
    ),
    'field_instance' => array(
      'bundle' => 'site',
      'default_value' => NULL,
      'deleted' => '0',
      'description' => 'Select which programs can access this site.',
      'display' => array(
        'default' => array(
          'label' => 'above',
          'module' => 'taxonomy',
          'settings' => array(),
          'type' => 'taxonomy_term_reference_plain',
          'weight' => '7',
        ),
        'full' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => '5',
        ),
        'notifications' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => 0,
        ),
        'teaser' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => 0,
        ),
      ),
      'display_label' => '',
      'entity_type' => 'node',
      'field_name' => 'field_site_restrict',
      'label' => 'Program(s)',
      'required' => 1,
      's4_sites_field_access' => 0,
      'settings' => array(
        'user_register_form' => FALSE,
      ),
      'widget' => array(
        'active' => 1,
        'module' => 'options',
        'settings' => array(),
        'type' => 'options_buttons',
        'weight' => '3',
      ),
    ),
  );

  // Exported field: 'node-site-field_site_signup_group'
  $fields['node-site-field_site_signup_group'] = array(
    'field_config' => array(
      'active' => '1',
      'cardinality' => '-1',
      'deleted' => '0',
      'entity_types' => array(),
      'field_name' => 'field_site_signup_group',
      'foreign keys' => array(),
      'indexes' => array(),
      'module' => 'field_collection',
      'settings' => array(
        'path' => '',
      ),
      'translatable' => '0',
      'type' => 'field_collection',
    ),
    'field_instance' => array(
      'bundle' => 'site',
      'default_value' => NULL,
      'deleted' => '0',
      'description' => '',
      'display' => array(
        'default' => array(
          'label' => 'above',
          'module' => 'field_collection',
          'settings' => array(
            'add' => 'Add',
            'delete' => 'Delete',
            'description' => TRUE,
            'edit' => 'Edit',
          ),
          'type' => 'field_collection_list',
          'weight' => '36',
        ),
        'notifications' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => 0,
        ),
        'teaser' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => 0,
        ),
      ),
      'display_label' => '',
      'entity_type' => 'node',
      'field_name' => 'field_site_signup_group',
      'label' => 'Signup forms',
      'required' => 0,
      's4_sites_field_access' => 1,
      'settings' => array(
        'user_register_form' => FALSE,
      ),
      'widget' => array(
        'active' => 0,
        'module' => 'field_collection_table',
        'settings' => array(),
        'type' => 'field_collection_table',
        'weight' => '30',
      ),
    ),
  );

  // Exported field: 'node-site-field_site_tour'
  $fields['node-site-field_site_tour'] = array(
    'field_config' => array(
      'active' => '1',
      'cardinality' => '1',
      'deleted' => '0',
      'entity_types' => array(),
      'field_name' => 'field_site_tour',
      'foreign keys' => array(
        'format' => array(
          'columns' => array(
            'format' => 'format',
          ),
          'table' => 'filter_format',
        ),
      ),
      'global_block_settings' => '1',
      'indexes' => array(
        'format' => array(
          0 => 'format',
        ),
      ),
      'module' => 'text',
      'settings' => array(),
      'translatable' => '1',
      'type' => 'text_long',
    ),
    'field_instance' => array(
      'bundle' => 'site',
      'default_value' => NULL,
      'deleted' => '0',
      'description' => '',
      'display' => array(
        'default' => array(
          'label' => 'above',
          'module' => 'text',
          'settings' => array(),
          'type' => 'text_default',
          'weight' => '27',
        ),
        'full' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => '3',
        ),
        'notifications' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => 0,
        ),
        'teaser' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => 0,
        ),
      ),
      'entity_type' => 'node',
      'field_name' => 'field_site_tour',
      'label' => 'Site Tour',
      'required' => 0,
      's4_sites_field_access' => 0,
      'settings' => array(
        'text_processing' => '1',
        'user_register_form' => FALSE,
      ),
      'widget' => array(
        'active' => 1,
        'module' => 'text',
        'settings' => array(
          'rows' => '5',
        ),
        'type' => 'text_textarea',
        'weight' => '27',
      ),
    ),
  );

  // Exported field: 'node-site-field_site_users'
  $fields['node-site-field_site_users'] = array(
    'field_config' => array(
      'active' => '1',
      'cardinality' => '-1',
      'deleted' => '0',
      'entity_types' => array(),
      'field_name' => 'field_site_users',
      'foreign keys' => array(
        'uid' => array(
          'columns' => array(
            'uid' => 'uid',
          ),
          'table' => 'users',
        ),
      ),
      'global_block_settings' => '1',
      'indexes' => array(
        'uid' => array(
          0 => 'uid',
        ),
      ),
      'module' => 'user_reference',
      'settings' => array(
        'nodeaccess_userreference' => array(
          'all' => array(
            'view' => 'view',
          ),
          'author' => array(
            'delete' => 'delete',
            'update' => 'update',
            'view' => 'view',
          ),
          'priority' => '0',
          'referenced' => array(
            'delete' => 0,
            'deny_delete' => 0,
            'deny_update' => 0,
            'deny_view' => 0,
            'update' => 'update',
            'view' => 0,
          ),
          'unused' => '0',
          'views' => array(
            'view' => '',
            'view_args' => '',
          ),
        ),
        'referenceable_roles' => array(
          2 => 0,
          3 => 0,
          4 => 0,
        ),
        'referenceable_status' => array(
          0 => 0,
          1 => '1',
        ),
        'view' => array(
          'args' => array(),
          'display_name' => '',
          'view_name' => '',
        ),
      ),
      'translatable' => '1',
      'type' => 'user_reference',
    ),
    'field_instance' => array(
      'bundle' => 'site',
      'default_value' => NULL,
      'deleted' => '0',
      'description' => 'These are other users (besides department staff) who can edit this site\'s information, along with information about associated coordinators.',
      'display' => array(
        'default' => array(
          'label' => 'above',
          'module' => 'user_reference',
          'settings' => array(),
          'type' => 'user_reference_default',
          'weight' => '30',
        ),
        'full' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => 0,
        ),
        'notifications' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => 0,
        ),
        'teaser' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => 0,
        ),
      ),
      'entity_type' => 'node',
      'field_name' => 'field_site_users',
      'label' => 'Additional users',
      'required' => 0,
      's4_sites_field_access' => 0,
      'settings' => array(
        'user_register_form' => FALSE,
      ),
      'widget' => array(
        'active' => 1,
        'module' => 'user_reference',
        'settings' => array(
          'autocomplete_match' => 'contains',
          'autocomplete_path' => 'user_reference/autocomplete',
          'size' => '40',
        ),
        'type' => 'user_reference_autocomplete',
        'weight' => '7',
      ),
    ),
  );

  // Exported field: 'node-site-field_tags'
  $fields['node-site-field_tags'] = array(
    'field_config' => array(
      'active' => '1',
      'cardinality' => '-1',
      'deleted' => '0',
      'entity_types' => array(),
      'field_name' => 'field_tags',
      'foreign keys' => array(
        'tid' => array(
          'columns' => array(
            'tid' => 'tid',
          ),
          'table' => 'taxonomy_term_data',
        ),
      ),
      'global_block_settings' => '2',
      'indexes' => array(
        'tid' => array(
          0 => 'tid',
        ),
      ),
      'module' => 'taxonomy',
      'settings' => array(
        'allowed_values' => array(
          0 => array(
            'parent' => 0,
            'vocabulary' => 'tags',
          ),
        ),
      ),
      'translatable' => '0',
      'type' => 'taxonomy_term_reference',
    ),
    'field_instance' => array(
      'bundle' => 'site',
      'default_value' => NULL,
      'deleted' => '0',
      'description' => 'Enter a few tags to describe this site.',
      'display' => array(
        'default' => array(
          'label' => 'above',
          'module' => 'taxonomy',
          'settings' => array(),
          'type' => 'taxonomy_term_reference_link',
          'weight' => '29',
        ),
        'full' => array(
          'label' => 'above',
          'module' => 'taxonomy',
          'settings' => array(),
          'type' => 'taxonomy_term_reference_link',
          'weight' => '1',
        ),
        'notifications' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => 0,
        ),
        'teaser' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => 0,
        ),
      ),
      'entity_type' => 'node',
      'field_name' => 'field_tags',
      'label' => 'Tags',
      'required' => 0,
      'settings' => array(
        'user_register_form' => FALSE,
      ),
      'widget' => array(
        'active' => 0,
        'module' => 'taxonomy',
        'settings' => array(
          'autocomplete_path' => 'taxonomy/autocomplete',
          'size' => 60,
        ),
        'type' => 'taxonomy_autocomplete',
        'weight' => '1',
      ),
    ),
  );

  // Exported field: 'node-site-field_website'
  $fields['node-site-field_website'] = array(
    'field_config' => array(
      'active' => '1',
      'cardinality' => '1',
      'deleted' => '0',
      'entity_types' => array(),
      'field_name' => 'field_website',
      'foreign keys' => array(),
      'global_block_settings' => '2',
      'indexes' => array(),
      'module' => 'link',
      'settings' => array(
        'attributes' => array(
          'class' => '',
          'rel' => '',
          'target' => 'default',
        ),
        'display' => array(
          'url_cutoff' => 80,
        ),
        'enable_tokens' => 1,
        'title' => 'optional',
        'title_maxlength' => 128,
        'title_value' => '',
        'url' => 0,
      ),
      'translatable' => '1',
      'type' => 'link_field',
    ),
    'field_instance' => array(
      'bundle' => 'site',
      'default_value' => NULL,
      'deleted' => '0',
      'description' => 'Enter the URL to this site\'s website.',
      'display' => array(
        'default' => array(
          'label' => 'above',
          'module' => 'link',
          'settings' => array(),
          'type' => 'link_default',
          'weight' => '9',
        ),
        'full' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => '2',
        ),
        'notifications' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => 0,
        ),
        'teaser' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => 0,
        ),
      ),
      'entity_type' => 'node',
      'field_name' => 'field_website',
      'label' => 'Website',
      'required' => 0,
      'settings' => array(
        'attributes' => array(
          'class' => 'site-website',
          'rel' => '',
          'target' => '_blank',
        ),
        'display' => array(
          'url_cutoff' => '80',
        ),
        'enable_tokens' => 1,
        'title' => 'none',
        'title_maxlength' => 128,
        'title_value' => 'Visit Website',
        'url' => 0,
        'user_register_form' => FALSE,
        'validate_url' => 1,
      ),
      'widget' => array(
        'active' => 0,
        'module' => 'link',
        'settings' => array(),
        'type' => 'link_field',
        'weight' => '1',
      ),
    ),
  );

  // Exported field: 'taxonomy_term-file_category-field_type_reminder_days'
  $fields['taxonomy_term-file_category-field_type_reminder_days'] = array(
    'field_config' => array(
      'active' => '1',
      'cardinality' => '1',
      'deleted' => '0',
      'entity_types' => array(),
      'field_name' => 'field_type_reminder_days',
      'foreign keys' => array(),
      'global_block_settings' => '1',
      'indexes' => array(),
      'module' => 'number',
      'settings' => array(),
      'translatable' => '1',
      'type' => 'number_integer',
    ),
    'field_instance' => array(
      'bundle' => 'file_category',
      'default_value' => array(
        0 => array(
          'value' => '30',
        ),
      ),
      'deleted' => '0',
      'description' => 'Enter the number of days before a file of this type expires that an email reminder should be sent to department staff. ',
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
          'weight' => 0,
        ),
      ),
      'entity_type' => 'taxonomy_term',
      'field_name' => 'field_type_reminder_days',
      'label' => 'Reminder period (days)',
      'required' => 1,
      'settings' => array(
        'max' => '',
        'min' => '1',
        'prefix' => '',
        'suffix' => 'days',
        'user_register_form' => FALSE,
      ),
      'widget' => array(
        'active' => 0,
        'module' => 'number',
        'settings' => array(),
        'type' => 'number',
        'weight' => '1',
      ),
    ),
  );

  // Exported field: 'taxonomy_term-organization_type-field_educational_organization'
  $fields['taxonomy_term-organization_type-field_educational_organization'] = array(
    'field_config' => array(
      'active' => '1',
      'cardinality' => '1',
      'deleted' => '0',
      'entity_types' => array(),
      'field_name' => 'field_educational_organization',
      'foreign keys' => array(),
      'indexes' => array(
        'value' => array(
          0 => 'value',
        ),
      ),
      'module' => 'list',
      'settings' => array(
        'allowed_values' => array(
          0 => '',
          1 => '',
        ),
        'allowed_values_function' => '',
        'allowed_values_php' => '',
      ),
      'translatable' => '0',
      'type' => 'list_boolean',
    ),
    'field_instance' => array(
      'bundle' => 'organization_type',
      'default_value' => array(
        0 => array(
          'value' => 0,
        ),
      ),
      'default_value_function' => '',
      'default_value_php' => '',
      'deleted' => '0',
      'description' => 'When checked, this will help separate reporting on these type of organizations.',
      'display' => array(
        'default' => array(
          'label' => 'above',
          'module' => 'list',
          'settings' => array(),
          'type' => 'list_default',
          'weight' => 0,
        ),
      ),
      'display_label' => '',
      'entity_type' => 'taxonomy_term',
      'field_name' => 'field_educational_organization',
      'label' => 'Educational organization',
      'required' => 0,
      'settings' => array(
        'user_register_form' => FALSE,
      ),
      'widget' => array(
        'active' => 1,
        'module' => 'options',
        'settings' => array(
          'display_label' => 1,
        ),
        'type' => 'options_onoff',
        'weight' => '1',
      ),
    ),
  );

  // Exported field: 'taxonomy_term-site_restrictions-field_form_instructions'
  $fields['taxonomy_term-site_restrictions-field_form_instructions'] = array(
    'field_config' => array(
      'active' => '1',
      'cardinality' => '1',
      'deleted' => '0',
      'entity_types' => array(),
      'field_name' => 'field_form_instructions',
      'foreign keys' => array(
        'format' => array(
          'columns' => array(
            'format' => 'format',
          ),
          'table' => 'filter_format',
        ),
      ),
      'indexes' => array(
        'format' => array(
          0 => 'format',
        ),
      ),
      'module' => 'text',
      'settings' => array(),
      'translatable' => '0',
      'type' => 'text_long',
    ),
    'field_instance' => array(
      'bundle' => 'site_restrictions',
      'default_value' => NULL,
      'deleted' => '0',
      'description' => 'This message appears when users are viewing your paper forms and are in the process of signing up.',
      'display' => array(
        'default' => array(
          'label' => 'above',
          'module' => 'text',
          'settings' => array(),
          'type' => 'text_default',
          'weight' => 1,
        ),
      ),
      'display_label' => '',
      'entity_type' => 'taxonomy_term',
      'field_name' => 'field_form_instructions',
      'label' => 'Downloadable form instructions',
      'required' => 0,
      'settings' => array(
        'text_processing' => '1',
        'user_register_form' => FALSE,
      ),
      'widget' => array(
        'active' => 1,
        'module' => 'text',
        'settings' => array(
          'rows' => '5',
        ),
        'type' => 'text_textarea',
        'weight' => '5',
      ),
    ),
  );

  // Exported field: 'taxonomy_term-site_restrictions-field_thank_you_message'
  $fields['taxonomy_term-site_restrictions-field_thank_you_message'] = array(
    'field_config' => array(
      'active' => '1',
      'cardinality' => '1',
      'deleted' => '0',
      'entity_types' => array(),
      'field_name' => 'field_thank_you_message',
      'foreign keys' => array(
        'format' => array(
          'columns' => array(
            'format' => 'format',
          ),
          'table' => 'filter_format',
        ),
      ),
      'global_block_settings' => '1',
      'indexes' => array(
        'format' => array(
          0 => 'format',
        ),
      ),
      'module' => 'text',
      'settings' => array(),
      'translatable' => '0',
      'type' => 'text_long',
    ),
    'field_instance' => array(
      'bundle' => 'site_restrictions',
      'default_value' => NULL,
      'deleted' => '0',
      'description' => '',
      'display' => array(
        'default' => array(
          'label' => 'above',
          'module' => 'text',
          'settings' => array(),
          'type' => 'text_default',
          'weight' => 0,
        ),
      ),
      'display_label' => '',
      'entity_type' => 'taxonomy_term',
      'field_name' => 'field_thank_you_message',
      'label' => 'Thank-you message',
      'required' => 0,
      'settings' => array(
        'text_processing' => '1',
        'user_register_form' => FALSE,
      ),
      'widget' => array(
        'active' => 1,
        'module' => 'text',
        'settings' => array(
          'rows' => '5',
        ),
        'type' => 'text_textarea',
        'weight' => '4',
      ),
    ),
  );

  // Translatables
  // Included for use with string extractors like potx.
  t('Additional users');
  t('Available to');
  t('Body');
  t('Briefly describe any ongoing needs or special projects with which students can assist agency staff');
  t('By percentage, what is the demographic of the population you serve?');
  t('Contact email');
  t('Contact tags');
  t('Contact type');
  t('Days and hours will you accept students for service (check all that apply)');
  t('Do you have a partnership with another CSU campus?');
  t('Downloadable form instructions');
  t('Educational organization');
  t('Email address');
  t('Enable expiration reminder');
  t('Enter a few tags to describe this site.');
  t('Enter a few tags to help categorize this type of contact');
  t('Enter the URL to this site\'s website.');
  t('Enter the number of days before a file of this type expires that an email reminder should be sent to department staff. ');
  t('Evaluation forms');
  t('Expiration date');
  t('Federal district');
  t('File category');
  t('File description or notes');
  t('Files');
  t('First Name');
  t('Form');
  t('How many people does your organization serve?');
  t('If this site staff needs to login and view their students, ask them to create a user account and then enter that account name here.');
  t('If you have multiple location sites that you would like students to be placed at, please provide specific location information. (You may add additional locations using the \'Add another\' button below.)');
  t('If your organization has a presence on Facebook, Twitter, or another social network, please provide the address.');
  t('Issues addressed');
  t('Last Name');
  t('Leave blank or enter zero (0) for no limit');
  t('Location(s)');
  t('Main phone number');
  t('Maximum number of students');
  t('Maximum number of students your site can accept at any given time');
  t('Once this number is reached, students will not be able to register with your site.');
  t('Organization type');
  t('Phone number');
  t('Program');
  t('Program(s)');
  t('Provide an overview description of your organization, i.e. who you are, what you do, and who you serve.');
  t('Related user');
  t('Reminder date');
  t('Reminder period (days)');
  t('Restrict this site staff to the following types of students.');
  t('Restrict to');
  t('Risk Identification');
  t('Role');
  t('Saved form record');
  t('Select the role of this staff person.');
  t('Select which programs can access this site.');
  t('Signup forms');
  t('Site');
  t('Site Tour');
  t('Site description');
  t('Site has special requirements');
  t('Site special requirements');
  t('Social network page');
  t('Special site instructions');
  t('State lower district');
  t('State upper district');
  t('Students can register with this staff');
  t('Tags');
  t('Thank-you message');
  t('The date when a reminder to check on this file will be sent out.');
  t('These are other users (besides department staff) who can edit this site\'s information, along with information about associated coordinators.');
  t('This information will be displayed to students before they sign up. This could contain additional information the student needs to know when they sign up for issues like TB testing, background checks, or specialized training');
  t('This message appears when users are viewing your paper forms and are in the process of signing up.');
  t('This will be shown to the public, so only include a generic email contact for the site.');
  t('Training and orientation information');
  t('Website');
  t('What is the minimum number of hours you would require of a student in service per term');
  t('What languages would you like students to speak other than English?');
  t('When checked, this will help separate reporting on these type of organizations.');
  t('When checked, users who have opted to receive notifications about expiring files will get a weekly email when this file is about to expire.');

  return $fields;
}
