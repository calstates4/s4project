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
    'weight' => '22',
    'children' => array(
      0 => 'field_location',
      1 => 'field_website',
      2 => 'field_site_email',
      3 => 'field_phone',
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
      1 => 'title',
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
  $field_group->identifier = 'group_site_images|node|site|form';
  $field_group->group_name = 'group_site_images';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'site';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_site_tabs';
  $field_group->data = array(
    'label' => 'Images',
    'weight' => '20',
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
    'label' => 'Student Instructions',
    'weight' => '23',
    'children' => array(
      0 => 'field_site_instructions_required',
      1 => 'field_site_instructions',
      2 => 'field_health_safety',
    ),
    'format_type' => 'htab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'classes' => '',
        'required_fields' => 0,
      ),
    ),
  );
  $export['group_site_instructions|node|site|form'] = $field_group;

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
      0 => 'group_instructions',
      1 => 'group_site_general',
      2 => 'group_site_images',
      3 => 'group_site_contact',
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
