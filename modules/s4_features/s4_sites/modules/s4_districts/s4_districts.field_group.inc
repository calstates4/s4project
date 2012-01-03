<?php
/**
 * @file
 * s4_districts.field_group.inc
 */

/**
 * Implements hook_field_group_info().
 */
function s4_districts_field_group_info() {
  $export = array();

  $field_group = new stdClass;
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
      0 => 'field_location',
      1 => 'field_district_federal',
      2 => 'field_district_state_lower',
      3 => 'field_district_state_upper',
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

  $field_group = new stdClass;
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
      0 => 'group_site_general',
      1 => 'group_site_images',
      2 => 'group_site_instructions',
      3 => 'group_site_locations',
      4 => 'group_site_contact',
      5 => 'group_site_health_safety',
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
