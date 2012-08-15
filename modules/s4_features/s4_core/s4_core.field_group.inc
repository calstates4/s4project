<?php
/**
 * @file
 * s4_core.field_group.inc
 */

/**
 * Implements hook_field_group_info().
 */
function s4_core_field_group_info() {
  $export = array();

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_confirmation_email|taxonomy_term|site_restrictions|form';
  $field_group->group_name = 'group_confirmation_email';
  $field_group->entity_type = 'taxonomy_term';
  $field_group->bundle = 'site_restrictions';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Confirmation Email',
    'weight' => '7',
    'children' => array(
      0 => 'field_confirmation_email',
      1 => 'field_confirmation_email_sender',
      2 => 'field_confirmation_send_email',
      3 => 'field_confirmation_subject',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(
        'description' => '',
        'classes' => '',
        'required_fields' => 1,
      ),
    ),
  );
  $export['group_confirmation_email|taxonomy_term|site_restrictions|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_evaluation_email|taxonomy_term|site_restrictions|form';
  $field_group->group_name = 'group_evaluation_email';
  $field_group->entity_type = 'taxonomy_term';
  $field_group->bundle = 'site_restrictions';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Evaluation email',
    'weight' => '8',
    'children' => array(
      0 => 'field_evaluation_email_body',
      1 => 'field_evaluation_email_subject',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(
        'description' => '',
        'classes' => '',
        'required_fields' => 1,
      ),
    ),
  );
  $export['group_evaluation_email|taxonomy_term|site_restrictions|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_program_homepage|taxonomy_term|site_restrictions|form';
  $field_group->group_name = 'group_program_homepage';
  $field_group->entity_type = 'taxonomy_term';
  $field_group->bundle = 'site_restrictions';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Custom homepage',
    'weight' => '10',
    'children' => array(
      0 => 'field_welcome_message',
      1 => 'field_statistics_message',
      2 => 'field_frontpage_title',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(
        'description' => '',
        'classes' => '',
        'required_fields' => 1,
      ),
    ),
  );
  $export['group_program_homepage|taxonomy_term|site_restrictions|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_starting_over|taxonomy_term|site_restrictions|form';
  $field_group->group_name = 'group_starting_over';
  $field_group->entity_type = 'taxonomy_term';
  $field_group->bundle = 'site_restrictions';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Starting over',
    'weight' => '6',
    'children' => array(
      0 => 'field_start_over',
      1 => 'field_grace_period',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(
        'description' => '',
        'classes' => '',
        'required_fields' => 1,
      ),
    ),
  );
  $export['group_starting_over|taxonomy_term|site_restrictions|form'] = $field_group;

  return $export;
}
