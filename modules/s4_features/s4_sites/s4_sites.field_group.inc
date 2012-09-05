<?php
/**
 * @file
 * s4_sites.field_group.inc
 */

/**
 * Implements hook_field_group_info().
 */
function s4_sites_field_group_info() {
  $export = array();

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_site_contact|node|site|form';
  $field_group->group_name = 'group_site_contact';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'site';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_site_tabs';
  $field_group->data = array(
    'label' => 'Contact',
    'weight' => '21',
    'children' => array(),
    'format_type' => 'htab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'classes' => '',
        'required_fields' => 1,
      ),
    ),
  );
  $export['group_site_contact|node|site|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_site_forms|node|site|form';
  $field_group->group_name = 'group_site_forms';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'site';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_site_tabs';
  $field_group->data = array(
    'label' => 'Forms',
    'weight' => '26',
    'children' => array(
      0 => 'field_site_evaluation_group',
      1 => 'field_site_signup_group',
    ),
    'format_type' => 'htab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'description' => '',
        'classes' => '',
        'required_fields' => 1,
      ),
    ),
  );
  $export['group_site_forms|node|site|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_site_general|node|site|form';
  $field_group->group_name = 'group_site_general';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'site';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_site_tabs';
  $field_group->data = array(
    'label' => 'General',
    'weight' => '19',
    'children' => array(
      0 => 'body',
      1 => 'field_phone',
      2 => 'field_site_email',
      3 => 'field_site_facebook_page',
      4 => 'field_site_projects',
      5 => 'field_website',
      6 => 'title',
    ),
    'format_type' => 'htab',
    'format_settings' => array(
      'label' => 'General',
      'instance_settings' => array(
        'required_fields' => 1,
        'classes' => '',
        'description' => '',
      ),
      'formatter' => 'open',
    ),
  );
  $export['group_site_general|node|site|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_site_health_safety|node|site|form';
  $field_group->group_name = 'group_site_health_safety';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'site';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_site_tabs';
  $field_group->data = array(
    'label' => 'Health & Safety',
    'weight' => '23',
    'children' => array(
      0 => 'field_health_risk',
      1 => 'field_site_health_training',
      2 => 'field_site_instructions',
      3 => 'field_site_instructions_required',
      4 => 'field_site_requirements',
      5 => 'field_site_tour',
    ),
    'format_type' => 'htab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'classes' => '',
        'required_fields' => 1,
      ),
    ),
  );
  $export['group_site_health_safety|node|site|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_site_instructions|node|site|form';
  $field_group->group_name = 'group_site_instructions';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'site';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_site_tabs';
  $field_group->data = array(
    'label' => 'Service Hours',
    'weight' => '22',
    'children' => array(
      0 => 'field_signups_max',
      1 => 'field_site_hours',
      2 => 'field_site_hours_minimum',
      3 => 'field_operating_hours',
    ),
    'format_type' => 'htab',
    'format_settings' => array(
      'label' => 'Service Hours',
      'instance_settings' => array(
        'required_fields' => 0,
        'classes' => '',
        'description' => '',
      ),
      'formatter' => 'closed',
    ),
  );
  $export['group_site_instructions|node|site|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_site_locations|node|site|form';
  $field_group->group_name = 'group_site_locations';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'site';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_site_tabs';
  $field_group->data = array(
    'label' => 'Location(s)',
    'weight' => '20',
    'children' => array(
      0 => 'field_district_federal',
      1 => 'field_district_state_lower',
      2 => 'field_district_state_upper',
      3 => 'field_location',
    ),
    'format_type' => 'htab',
    'format_settings' => array(
      'label' => 'Location(s)',
      'instance_settings' => array(
        'required_fields' => 1,
        'classes' => '',
        'description' => '',
      ),
      'formatter' => 'closed',
    ),
  );
  $export['group_site_locations|node|site|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_site_population|node|site|form';
  $field_group->group_name = 'group_site_population';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'site';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_site_tabs';
  $field_group->data = array(
    'label' => 'Population',
    'weight' => '24',
    'children' => array(
      0 => 'field_population_size',
      1 => 'field_site_demographics',
    ),
    'format_type' => 'htab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'classes' => '',
        'required_fields' => 1,
      ),
    ),
  );
  $export['group_site_population|node|site|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_site_tabs|node|site|form';
  $field_group->group_name = 'group_site_tabs';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'site';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Site tabs',
    'weight' => '0',
    'children' => array(
      0 => 'group_site_locations',
      1 => 'group_site_contact',
      2 => 'group_site_forms',
      3 => 'group_site_general',
      4 => 'group_site_health_safety',
      5 => 'group_site_instructions',
      6 => 'group_site_population',
    ),
    'format_type' => 'htabs',
    'format_settings' => array(
      'formatter' => '',
      'instance_settings' => array(
        'classes' => '',
      ),
    ),
  );
  $export['group_site_tabs|node|site|form'] = $field_group;

  return $export;
}
