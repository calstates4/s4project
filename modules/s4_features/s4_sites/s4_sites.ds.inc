<?php
/**
 * @file
 * s4_sites.ds.inc
 */

/**
 * Implements hook_ds_field_settings_info().
 */
function s4_sites_ds_field_settings_info() {
  $export = array();

  $ds_fieldsetting = new stdClass();
  $ds_fieldsetting->api_version = 1;
  $ds_fieldsetting->id = 'node|contact_record|default';
  $ds_fieldsetting->entity_type = 'node';
  $ds_fieldsetting->bundle = 'contact_record';
  $ds_fieldsetting->view_mode = 'default';
  $ds_fieldsetting->settings = array(
    'return_to_site' => array(
      'weight' => '1',
      'label' => 'hidden',
      'format' => 'default',
    ),
    'post_date' => array(
      'weight' => '2',
      'label' => 'hidden',
      'format' => 'ds_post_date_long',
    ),
  );
  $export['node|contact_record|default'] = $ds_fieldsetting;

  $ds_fieldsetting = new stdClass();
  $ds_fieldsetting->api_version = 1;
  $ds_fieldsetting->id = 'node|file|default';
  $ds_fieldsetting->entity_type = 'node';
  $ds_fieldsetting->bundle = 'file';
  $ds_fieldsetting->view_mode = 'default';
  $ds_fieldsetting->settings = array(
    'return_to_site' => array(
      'weight' => '0',
      'label' => 'hidden',
      'format' => 'default',
    ),
  );
  $export['node|file|default'] = $ds_fieldsetting;

  $ds_fieldsetting = new stdClass();
  $ds_fieldsetting->api_version = 1;
  $ds_fieldsetting->id = 'node|site|default';
  $ds_fieldsetting->entity_type = 'node';
  $ds_fieldsetting->bundle = 'site';
  $ds_fieldsetting->view_mode = 'default';
  $ds_fieldsetting->settings = array(
    'add_to_sites_link' => array(
      'weight' => '0',
      'label' => 'hidden',
      'format' => 'default',
    ),
    'map' => array(
      'weight' => '4',
      'label' => 'hidden',
      'format' => 'default',
    ),
    'site_is_full' => array(
      'weight' => '2',
      'label' => 'hidden',
      'format' => 'default',
    ),
    'site_opportunities' => array(
      'weight' => '26',
      'label' => 'hidden',
      'format' => 'default',
    ),
    'site_staff' => array(
      'weight' => '22',
      'label' => 'hidden',
      'format' => 'default',
    ),
  );
  $export['node|site|default'] = $ds_fieldsetting;

  return $export;
}

/**
 * Implements hook_ds_custom_fields_info().
 */
function s4_sites_ds_custom_fields_info() {
  $export = array();

  $ds_field = new stdClass();
  $ds_field->api_version = 1;
  $ds_field->field = 'add_to_sites_link';
  $ds_field->label = 'Add to sites link';
  $ds_field->field_type = 6;
  $ds_field->entities = array(
    'node' => 'node',
  );
  $ds_field->ui_limit = 'site|*';
  $ds_field->properties = array(
    'block' => 's4_courses|s4_courses_add_site',
    'block_render' => '1',
  );
  $export['add_to_sites_link'] = $ds_field;

  $ds_field = new stdClass();
  $ds_field->api_version = 1;
  $ds_field->field = 'map';
  $ds_field->label = 'Map';
  $ds_field->field_type = 6;
  $ds_field->entities = array(
    'node' => 'node',
  );
  $ds_field->ui_limit = '';
  $ds_field->properties = array(
    'block' => 's4_map|s4_map_site_view_map',
    'block_render' => '1',
  );
  $export['map'] = $ds_field;

  $ds_field = new stdClass();
  $ds_field->api_version = 1;
  $ds_field->field = 'merge_sites_link';
  $ds_field->label = 'Merge sites link';
  $ds_field->field_type = 6;
  $ds_field->entities = array(
    'node' => 'node',
  );
  $ds_field->ui_limit = '';
  $ds_field->properties = array(
    'block' => 's4_sites|s4_sites_merge_link',
    'block_render' => '1',
  );
  $export['merge_sites_link'] = $ds_field;

  $ds_field = new stdClass();
  $ds_field->api_version = 1;
  $ds_field->field = 'return_to_site';
  $ds_field->label = 'Return to site';
  $ds_field->field_type = 6;
  $ds_field->entities = array(
    'node' => 'node',
  );
  $ds_field->ui_limit = '';
  $ds_field->properties = array(
    'block' => 's4_sites|s4_sites_return_tab',
    'block_render' => '1',
  );
  $export['return_to_site'] = $ds_field;

  $ds_field = new stdClass();
  $ds_field->api_version = 1;
  $ds_field->field = 'site_is_full';
  $ds_field->label = 'Site is full';
  $ds_field->field_type = 6;
  $ds_field->entities = array(
    'node' => 'node',
  );
  $ds_field->ui_limit = '';
  $ds_field->properties = array(
    'block' => 's4_sites|s4_sites_site_full',
    'block_render' => '1',
  );
  $export['site_is_full'] = $ds_field;

  $ds_field = new stdClass();
  $ds_field->api_version = 1;
  $ds_field->field = 'site_opportunities';
  $ds_field->label = 'Site Opportunities';
  $ds_field->field_type = 6;
  $ds_field->entities = array(
    'node' => 'node',
  );
  $ds_field->ui_limit = 'site|*';
  $ds_field->properties = array(
    'block' => 'views|efea6a94fb18c085977a2ebcc3e657d0',
    'block_render' => '3',
  );
  $export['site_opportunities'] = $ds_field;

  $ds_field = new stdClass();
  $ds_field->api_version = 1;
  $ds_field->field = 'site_staff';
  $ds_field->label = 'Site staff';
  $ds_field->field_type = 6;
  $ds_field->entities = array(
    'node' => 'node',
  );
  $ds_field->ui_limit = '';
  $ds_field->properties = array(
    'block' => 'views|site_coordinators-block_1',
    'block_render' => '1',
  );
  $export['site_staff'] = $ds_field;

  return $export;
}

/**
 * Implements hook_ds_layout_settings_info().
 */
function s4_sites_ds_layout_settings_info() {
  $export = array();

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'node|contact_record|default';
  $ds_layout->entity_type = 'node';
  $ds_layout->bundle = 'contact_record';
  $ds_layout->view_mode = 'default';
  $ds_layout->layout = 'ds_2col';
  $ds_layout->settings = array(
    'hide_empty_regions' => 0,
    'hide_sidebars' => 0,
    'regions' => array(
      'left' => array(
        0 => 'body',
      ),
      'right' => array(
        0 => 'return_to_site',
        1 => 'post_date',
        2 => 'field_contact',
        3 => 'field_contact_tags',
        4 => 'field_files',
      ),
    ),
    'fields' => array(
      'body' => 'left',
      'return_to_site' => 'right',
      'post_date' => 'right',
      'field_contact' => 'right',
      'field_contact_tags' => 'right',
      'field_files' => 'right',
    ),
    'classes' => array(),
  );
  $export['node|contact_record|default'] = $ds_layout;

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'node|file|default';
  $ds_layout->entity_type = 'node';
  $ds_layout->bundle = 'file';
  $ds_layout->view_mode = 'default';
  $ds_layout->layout = 's4_75_25';
  $ds_layout->settings = array(
    'hide_empty_regions' => 0,
    'hide_sidebars' => 0,
    'classes' => array(),
    'regions' => array(
      'left' => array(
        0 => 'body',
        1 => 'field_files',
      ),
      'right' => array(
        0 => 'return_to_site',
        1 => 'field_file_category',
        2 => 'field_file_tags',
        3 => 'field_expiration_date',
        4 => 'field_expiration_reminder_date',
      ),
    ),
    'fields' => array(
      'body' => 'left',
      'field_files' => 'left',
      'return_to_site' => 'right',
      'field_file_category' => 'right',
      'field_file_tags' => 'right',
      'field_expiration_date' => 'right',
      'field_expiration_reminder_date' => 'right',
    ),
  );
  $export['node|file|default'] = $ds_layout;

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'node|site|default';
  $ds_layout->entity_type = 'node';
  $ds_layout->bundle = 'site';
  $ds_layout->view_mode = 'default';
  $ds_layout->layout = 's4_site';
  $ds_layout->settings = array(
    'regions' => array(
      'left' => array(
        0 => 'add_to_sites_link',
        1 => 'body',
      ),
      'right' => array(
        2 => 'site_is_full',
        3 => 's4_core_signup_select_site',
        4 => 'map',
      ),
      'details' => array(
        5 => 'field_phone',
        6 => 'field_site_email',
        7 => 'field_location',
        8 => 'field_county',
        9 => 'field_signups_max',
        10 => 'field_site_language_bilingual',
        11 => 'field_site_projects',
      ),
      'details_1' => array(
        12 => 'field_website',
        13 => 'field_site_facebook_page',
      ),
      'details_2' => array(
        14 => 'field_site_restrict',
      ),
      'details_3' => array(
        15 => 'field_csu_facility',
      ),
      'details_4' => array(
        16 => 'field_csu_org_type',
      ),
      'risks' => array(
        17 => 'field_site_instructions',
        18 => 'field_site_health_training',
        19 => 'field_site_tour',
        20 => 'field_health_risk',
      ),
      'risks_sidebar' => array(
        21 => 'field_site_requirements',
      ),
      'staff' => array(
        22 => 'site_staff',
      ),
      'hours' => array(
        23 => 'field_site_hours_minimum',
        24 => 'field_site_hours',
        25 => 'field_operating_hours',
      ),
      'opportunities' => array(
        26 => 'site_opportunities',
      ),
      'demographics' => array(
        27 => 'field_population_size',
      ),
      'language' => array(
        28 => 'field_site_language',
      ),
      'population' => array(
        29 => 'field_site_demographics',
      ),
    ),
    'fields' => array(
      'add_to_sites_link' => 'left',
      'body' => 'left',
      'site_is_full' => 'right',
      's4_core_signup_select_site' => 'right',
      'map' => 'right',
      'field_phone' => 'details',
      'field_site_email' => 'details',
      'field_location' => 'details',
      'field_county' => 'details',
      'field_signups_max' => 'details',
      'field_site_language_bilingual' => 'details',
      'field_site_projects' => 'details',
      'field_website' => 'details_1',
      'field_site_facebook_page' => 'details_1',
      'field_site_restrict' => 'details_2',
      'field_csu_facility' => 'details_3',
      'field_csu_org_type' => 'details_4',
      'field_site_instructions' => 'risks',
      'field_site_health_training' => 'risks',
      'field_site_tour' => 'risks',
      'field_health_risk' => 'risks',
      'field_site_requirements' => 'risks_sidebar',
      'site_staff' => 'staff',
      'field_site_hours_minimum' => 'hours',
      'field_site_hours' => 'hours',
      'field_operating_hours' => 'hours',
      'site_opportunities' => 'opportunities',
      'field_population_size' => 'demographics',
      'field_site_language' => 'language',
      'field_site_demographics' => 'population',
    ),
    'classes' => array(),
    'wrappers' => array(
      'left' => 'div',
      'right' => 'div',
      'details' => 'div',
      'details_1' => 'div',
      'details_2' => 'div',
      'details_3' => 'div',
      'details_4' => 'div',
      'risks' => 'div',
      'risks_sidebar' => 'div',
      'staff' => 'div',
      'hours' => 'div',
      'opportunities' => 'div',
      'demographics' => 'div',
      'language' => 'div',
      'population' => 'div',
    ),
    'layout_wrapper' => 'div',
    'layout_attributes' => '',
    'layout_attributes_merge' => 1,
  );
  $export['node|site|default'] = $ds_layout;

  return $export;
}
