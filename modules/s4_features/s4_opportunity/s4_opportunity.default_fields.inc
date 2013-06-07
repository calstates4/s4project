<?php

function _s4_opportunity_add_default_fields($type) {
	$field = field_info_field('field_opportunity_sites');
  $instance = field_info_instance('s4_opportunity', 'field_opportunity_sites', $type);
  if (empty($field)) {
    $field = array(
      'active' => '1',
      'cardinality' => '-1',
      'deleted' => '0',
      'entity_types' => array(),
      'field_name' => 'field_opportunity_sites',
      'foreign keys' => array(
        'node' => array(
          'columns' => array(
            'target_id' => 'nid',
          ),
          'table' => 'node',
        ),
      ),
      'indexes' => array(
        'target_id' => array(
          0 => 'target_id',
        ),
      ),
      'module' => 'entityreference',
      'settings' => array(
        'handler' => 'base',
        'handler_settings' => array(
          'behaviors' => array(
            'views-select-list' => array(
              'status' => 0,
            ),
          ),
          'sort' => array(
            'type' => 'none',
          ),
          'target_bundles' => array(
            'site' => 'site',
          ),
        ),
        'target_type' => 'node',
      ),
      'translatable' => '0',
      'type' => 'entityreference',
    );
    $field = field_create_field($field);
  }
  if (empty($instance)) {
    $instance = array(
      'bundle' => $type,
      'default_value' => NULL,
      'default_value_function' => 'entityreference_prepopulate_field_default_value',
      'deleted' => '0',
      'description' => '',
      'display' => array(
        'default' => array(
          'label' => 'above',
          'module' => 'entityreference',
          'settings' => array(
            'link' => FALSE,
          ),
          'type' => 'entityreference_label',
          'weight' => 14,
        ),
      ),
      'display_label' => '',
      'entity_type' => 's4_opportunity',
      'field_name' => 'field_opportunity_sites',
      'label' => 'Sites',
      'required' => 0,
      'field_lock' => 1,
      'settings' => array(
        'behaviors' => array(
          'prepopulate' => array(
            'action' => 'hide',
            'action_on_edit' => 1,
            'fallback' => 'hide',
            'og_context' => 0,
            'skip_perm' => '0',
            'status' => 1,
          ),
        ),
        'custom_add_another' => '',
        'user_register_form' => FALSE,
      ),
      'widget' => array(
        'active' => 1,
        'module' => 'entityreference',
        'settings' => array(
          'match_operator' => 'CONTAINS',
          'path' => '',
          'size' => '60',
        ),
        'type' => 'entityreference_autocomplete',
        'weight' => '7',
      ),
    );
    $instance = field_create_instance($instance);
  }

  $field = field_info_field('field_opportunity_site_staff');
  $instance = field_info_instance('s4_opportunity', 'field_opportunity_site_staff', $type);
  if (empty($field)) {
    $field = array(
		  'active' => '1',
      'cardinality' => '-1',
      'deleted' => '0',
      'entity_types' => array(),
      'field_name' => 'field_opportunity_site_staff',
      'foreign keys' => array(
        'node' => array(
          'columns' => array(
            'target_id' => 'nid',
          ),
          'table' => 'node',
        ),
      ),
      'indexes' => array(
        'target_id' => array(
          0 => 'target_id',
        ),
      ),
      'module' => 'entityreference',
      'settings' => array(
        'handler' => 'base',
        'handler_settings' => array(
          'behaviors' => array(
            'views-select-list' => array(
              'status' => 0,
            ),
          ),
          'sort' => array(
            'type' => 'none',
          ),
          'target_bundles' => array(
            'coordinator' => 'coordinator',
          ),
        ),
        'target_type' => 'node',
      ),
      'translatable' => '0',
      'type' => 'entityreference',
		);
    $field = field_create_field($field);
  }
  if (empty($instance)) {
    $instance = array(
      'bundle' => $type,
      'default_value' => NULL,
      'default_value_function' => 'entityreference_prepopulate_field_default_value',
      'deleted' => '0',
      'description' => '',
      'display' => array(
        'default' => array(
          'label' => 'above',
          'module' => 'entityreference',
          'settings' => array(
            'link' => FALSE,
          ),
          'type' => 'entityreference_label',
          'weight' => 15,
        ),
      ),
      'display_label' => '',
      'entity_type' => 's4_opportunity',
      'field_name' => 'field_opportunity_site_staff',
      'label' => 'Site staff',
      'required' => 0,
      'field_lock' => 1,
      'settings' => array(
        'behaviors' => array(
          'prepopulate' => array(
            'action' => 'hide',
            'action_on_edit' => 1,
            'fallback' => 'hide',
            'og_context' => 0,
            'skip_perm' => '0',
            'status' => 1,
          ),
        ),
        'custom_add_another' => '',
        'user_register_form' => FALSE,
      ),
      'widget' => array(
        'active' => 1,
        'module' => 'entityreference',
        'settings' => array(
          'match_operator' => 'CONTAINS',
          'path' => '',
          'size' => '60',
        ),
        'type' => 'entityreference_autocomplete',
        'weight' => '8',
      ),
    );
    $instance = field_create_instance($instance);
  }


  $field = field_info_field('field_site_restrict');
  $instance = field_info_instance('s4_opportunity', 'field_site_restrict', $type);
  if (empty($field)) {
    $field = array(
		  'entity_types' => array(),
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
		      'tid',
		    ),
		  ),
		  'settings' => array(
		    'allowed_values' => array(
		      array(
		        'vocabulary' => 'site_restrictions',
		        'parent' => '0',
		      ),
		    ),
		  ),
		  'translatable' => '1',
		  'storage' => array(
		    'type' => 'field_sql_storage',
		    'settings' => array(),
		    'module' => 'field_sql_storage',
		    'active' => '1',
		    'details' => array(
		      'sql' => array(
		        'FIELD_LOAD_CURRENT' => array(
		          'field_data_field_site_restrict' => array(
		            'tid' => 'field_site_restrict_tid',
		          ),
		        ),
		        'FIELD_LOAD_REVISION' => array(
		          'field_revision_field_site_restrict' => array(
		            'tid' => 'field_site_restrict_tid',
		          ),
		        ),
		      ),
		    ),
		  ),
		  'field_name' => 'field_site_restrict',
		  'type' => 'taxonomy_term_reference',
		  'module' => 'taxonomy',
		  'active' => '1',
		  'locked' => '0',
		  'cardinality' => '-1',
		  'deleted' => '0',
		  'columns' => array(
		    'tid' => array(
		      'type' => 'int',
		      'unsigned' => TRUE,
		      'not null' => FALSE,
		    ),
		  ),
		  'bundles' => array(
		    'field_collection_item' => array(
		      'field_site_evaluation_group',
		      'field_site_signup_group',
		    ),
		    'node' => array(
		      'coordinator',
		      'site',
		      'downloadable_form',
		      'signup',
		      'course',
		      'webform',
		    ),
		    'user' => array(
		      'user',
		    ),
		  ),
		);
    $field = field_create_field($field);
  }
  if (empty($instance)) {
    $instance = array(
      'bundle' => $type,
      'entity_type' => 's4_opportunity',
		  'default_value' => NULL,
		  'description' => 'Select which programs can access this site.',
		  'display' => array(
		    'default' => array(
		      'label' => 'above',
		      'type' => 'taxonomy_term_reference_plain',
		      'weight' => '11',
		      'settings' => array(),
		      'module' => 'taxonomy',
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
		    'search_index' => array(
		      'label' => 'above',
		      'type' => 'hidden',
		      'weight' => '2',
		      'settings' => array(),
		    ),
		  ),
		  'display_label' => '',
		  'label' => 'Program(s)',
		  'required' => 1,
      'field_lock' => 1,
		  's4_sites_field_access' => 0,
		  'settings' => array(
		    'user_register_form' => FALSE,
		    'custom_add_another' => '',
		  ),
		  'widget' => array(
		    'weight' => '4',
		    'type' => 'options_buttons',
		    'module' => 'options',
		    'active' => 1,
		    'settings' => array(),
		  ),
		  'field_name' => 'field_site_restrict',
		  'deleted' => '0',
		);
    $instance = field_create_instance($instance);
  }

  $field = field_info_field('field_active_date');
  $instance = field_info_instance('s4_opportunity', 'field_active_date', $type);
  if (empty($field)) {
    $field = array(
		  'translatable' => '0',
		  'entity_types' => array(),
		  'settings' => array(
		    'granularity' => array(
		      'month' => 'month',
		      'day' => 'day',
		      'year' => 'year',
		      'hour' => 0,
		      'minute' => 0,
		      'second' => 0,
		    ),
		    'tz_handling' => 'none',
		    'timezone_db' => '',
		    'cache_enabled' => 0,
		    'cache_count' => '4',
		    'todate' => 'required',
		  ),
		  'storage' => array(
		    'type' => 'field_sql_storage',
		    'settings' => array(),
		    'module' => 'field_sql_storage',
		    'active' => '1',
		    'details' => array(
		      'sql' => array(
		        'FIELD_LOAD_CURRENT' => array(
		          'field_data_field_active_date' => array(
		            'value' => 'field_active_date_value',
		            'value2' => 'field_active_date_value2',
		          ),
		        ),
		        'FIELD_LOAD_REVISION' => array(
		          'field_revision_field_active_date' => array(
		            'value' => 'field_active_date_value',
		            'value2' => 'field_active_date_value2',
		          ),
		        ),
		      ),
		    ),
		  ),
		  'foreign keys' => array(),
		  'indexes' => array(),
		  'field_name' => 'field_active_date',
		  'type' => 'datetime',
		  'module' => 'date',
		  'active' => '1',
		  'locked' => '0',
		  'cardinality' => '1',
		  'deleted' => '0',
		  'columns' => array(
		    'value' => array(
		      'type' => 'datetime',
		      'mysql_type' => 'datetime',
		      'pgsql_type' => 'timestamp without time zone',
		      'sqlite_type' => 'varchar',
		      'sqlsrv_type' => 'smalldatetime',
		      'not null' => FALSE,
		      'sortable' => TRUE,
		      'views' => TRUE,
		    ),
		    'value2' => array(
		      'type' => 'datetime',
		      'mysql_type' => 'datetime',
		      'pgsql_type' => 'timestamp without time zone',
		      'sqlite_type' => 'varchar',
		      'sqlsrv_type' => 'smalldatetime',
		      'not null' => FALSE,
		      'sortable' => TRUE,
		      'views' => FALSE,
		    ),
		  ),
		  'bundles' => array(
		    's4_opportunity' => array(
		      $type,
		    ),
		  ),
		);
    $field = field_create_field($field);
  }

  if (empty($instance)) {
    $instance = array(
		  'label' => 'Active date',
		  'widget' => array(
		    'weight' => '6',
		    'type' => 'date_popup',
		    'module' => 'date',
		    'active' => 1,
		    'settings' => array(
		      'input_format' => 'm/d/Y - H:i:s',
		      'input_format_custom' => '',
		      'year_range' => '-3:+3',
		      'increment' => '15',
		      'label_position' => 'above',
		      'text_parts' => array(),
		      'display_all_day' => 0,
		    ),
		  ),
		  'settings' => array(
		    'default_value' => 'now',
		    'default_value_code' => '',
		    'default_value2' => 'strtotime',
        'default_value_code2' => '+1 year',
		    'custom_add_another' => '',
		    'user_register_form' => FALSE,
		  ),
		  'display' => array(
		    'default' => array(
		      'label' => 'above',
		      'type' => 'date_default',
		      'settings' => array(
		        'format_type' => 'long',
		        'multiple_number' => '',
		        'multiple_from' => '',
		        'multiple_to' => '',
		        'fromto' => 'both',
		      ),
		      'module' => 'date',
		      'weight' => 13,
		    ),
		  ),
		  'required' => 0,
      'field_lock' => 1,
		  'description' => 'Select the time when this opportunity is available.',
		  'display_label' => '',
		  'field_name' => 'field_active_date',
		  'entity_type' => 's4_opportunity',
		  'bundle' => $type,
		  'deleted' => '0',
		);
    $instance = field_create_instance($instance);
  }

  $field = field_info_field('field_maximum_placements');
  $instance = field_info_instance('s4_opportunity', 'field_maximum_placements', $type);
  if (empty($field)) {
    $field = array(
		  'translatable' => '0',
		  'entity_types' => array(),
		  'settings' => array(),
		  'storage' => array(
		    'type' => 'field_sql_storage',
		    'settings' => array(),
		    'module' => 'field_sql_storage',
		    'active' => '1',
		    'details' => array(
		      'sql' => array(
		        'FIELD_LOAD_CURRENT' => array(
		          'field_data_field_maximum_placements' => array(
		            'value' => 'field_maximum_placements_value',
		          ),
		        ),
		        'FIELD_LOAD_REVISION' => array(
		          'field_revision_field_maximum_placements' => array(
		            'value' => 'field_maximum_placements_value',
		          ),
		        ),
		      ),
		    ),
		  ),
		  'foreign keys' => array(),
		  'indexes' => array(),
		  'field_name' => 'field_maximum_placements',
		  'type' => 'number_integer',
		  'module' => 'number',
		  'active' => '1',
		  'locked' => '0',
		  'cardinality' => '1',
		  'deleted' => '0',
		  'columns' => array(
		    'value' => array(
		      'type' => 'int',
		      'not null' => FALSE,
		    ),
		  ),
		  'bundles' => array(
		    's4_opportunity' => array(
		      $type,
		    ),
		  ),
		);
    $field = field_create_field($field);
  }
  if (empty($instance)) {
    $instance = array(
		  'label' => 'Maximum placements',
		  'widget' => array(
		    'weight' => '5',
		    'type' => 'number',
		    'module' => 'number',
		    'active' => 0,
		    'settings' => array(),
		  ),
		  'settings' => array(
		    'min' => '',
		    'max' => '',
		    'prefix' => '',
		    'suffix' => '',
		    'custom_add_another' => '',
		    'user_register_form' => FALSE,
		  ),
		  'display' => array(
		    'default' => array(
		      'label' => 'above',
		      'type' => 'number_integer',
		      'settings' => array(
		        'thousand_separator' => ' ',
		        'decimal_separator' => '.',
		        'scale' => 0,
		        'prefix_suffix' => TRUE,
		      ),
		      'module' => 'number',
		      'weight' => 12,
		    ),
		  ),
		  'required' => 0,
      'field_lock' => 1,
		  'description' => 'Enter the maximum number of placements that can be made at any given time.',
		  'display_label' => '',
		  'default_value' => NULL,
		  'field_name' => 'field_maximum_placements',
		  'entity_type' => 's4_opportunity',
		  'bundle' => $type,
		  'deleted' => '0',
		);
    $instance = field_create_instance($instance);
  }
  $field = field_info_field('field_opportunity_category');
  $instance = field_info_instance('s4_opportunity', 'field_opportunity_category', $type);
  if (empty($field)) {
    $field = array(
      'translatable' => '0',
      'entity_types' => array(),
      'settings' => array(
        'allowed_values' => array(
          array(
            'vocabulary' => 'opportunity_category',
            'parent' => '0',
          ),
        ),
      ),
      'storage' => array(
        'type' => 'field_sql_storage',
        'settings' => array(),
        'module' => 'field_sql_storage',
        'active' => '1',
        'details' => array(
          'sql' => array(
            'FIELD_LOAD_CURRENT' => array(
              'field_data_field_opportunity_category' => array(
                'tid' => 'field_opportunity_category_tid',
              ),
            ),
            'FIELD_LOAD_REVISION' => array(
              'field_revision_field_opportunity_category' => array(
                'tid' => 'field_opportunity_category_tid',
              ),
            ),
          ),
        ),
      ),
      'foreign keys' => array(
        'tid' => array(
          'table' => 'taxonomy_term_data',
          'columns' => array(
            'tid' => 'tid',
          ),
        ),
      ),
      'indexes' => array(
        'tid' => array(
          'tid',
        ),
      ),
      'field_name' => 'field_opportunity_category',
      'type' => 'taxonomy_term_reference',
      'module' => 'taxonomy',
      'active' => '1',
      'locked' => '0',
      'cardinality' => '-1',
      'deleted' => '0',
      'columns' => array(
        'tid' => array(
          'type' => 'int',
          'unsigned' => TRUE,
          'not null' => FALSE,
        ),
      ),
      'bundles' => array(
        's4_opportunity' => array(
          $type,
        ),
      ),
    );
    $field = field_create_field($field);
  }
  if (empty($instance)) {
    $instance = array(
      'bundle' => $type,
      'label' => 'Category',
      'widget' => array(
        'weight' => '9',
        'type' => 'options_select',
        'module' => 'options',
        'active' => 1,
        'settings' => array(),
      ),
      'settings' => array(
        'custom_add_another' => '',
        'user_register_form' => FALSE,
      ),
      'display' => array(
        'default' => array(
          'label' => 'above',
          'type' => 'taxonomy_term_reference_link',
          'settings' => array(),
          'module' => 'taxonomy',
          'weight' => 16,
        ),
      ),
      'field_lock' => 1,
      'required' => 0,
      'description' => '',
      'display_label' => '',
      'default_value' => NULL,
      'field_name' => 'field_opportunity_category',
      'entity_type' => 's4_opportunity',
      'deleted' => '0',
    );
    $instance = field_create_instance($instance);
  }
}