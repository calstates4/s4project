<?php
/**
 * @file
 * s4_sites.field_group.inc
 */

/**
 * Implementation of hook_field_group_info().
 */
function s4_sites_field_group_info() {
  $export = array();

  $field_group = new stdClass;
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

  $field_group = new stdClass;
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
      3 => 'field_website',
      4 => 'field_site_projects',
      5 => 'field_site_facebook_page',
      6 => 'title',
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
  $export['group_site_general|node|site|form'] = $field_group;

  $field_group = new stdClass;
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
      0 => 'field_site_instructions',
      1 => 'field_site_instructions_required',
      2 => 'field_site_health_training',
      3 => 'field_site_tour',
      4 => 'field_health_risk',
      5 => 'field_site_requirements',
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

  $field_group = new stdClass;
  $field_group->api_version = 1;
  $field_group->identifier = 'group_site_images|node|site|form';
  $field_group->group_name = 'group_site_images';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'site';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_site_tabs';
  $field_group->data = array(
    'label' => 'Images',
    'weight' => '25',
    'children' => array(
      0 => 'field_site_images',
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
  $export['group_site_images|node|site|form'] = $field_group;

  $field_group = new stdClass;
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
      1 => 'field_site_hours_minimum',
      2 => 'field_site_hours',
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

  $field_group = new stdClass;
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
      0 => 'field_site_demographics',
      1 => 'field_population_size',
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

  $field_group = new stdClass;
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
