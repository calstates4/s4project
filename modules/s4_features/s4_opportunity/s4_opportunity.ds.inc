<?php
/**
 * @file
 * s4_opportunity.ds.inc
 */

/**
 * Implements hook_ds_field_settings_info().
 */
function s4_opportunity_ds_field_settings_info() {
  $export = array();

  $ds_fieldsetting = new stdClass();
  $ds_fieldsetting->api_version = 1;
  $ds_fieldsetting->id = 'relation|opportunity_placement|default';
  $ds_fieldsetting->entity_type = 'relation';
  $ds_fieldsetting->bundle = 'opportunity_placement';
  $ds_fieldsetting->view_mode = 'default';
  $ds_fieldsetting->settings = array(
    'opportunity_placement_approval' => array(
      'weight' => '1',
      'label' => 'hidden',
      'format' => 'default',
    ),
    'opportunity_placement_form' => array(
      'weight' => '2',
      'label' => 'hidden',
      'format' => 'default',
    ),
  );
  $export['relation|opportunity_placement|default'] = $ds_fieldsetting;

  return $export;
}

/**
 * Implements hook_ds_custom_fields_info().
 */
function s4_opportunity_ds_custom_fields_info() {
  $export = array();

  $ds_field = new stdClass();
  $ds_field->api_version = 1;
  $ds_field->field = 'opportunity_placement_approval';
  $ds_field->label = 'Opportunity placement: approval';
  $ds_field->field_type = 6;
  $ds_field->entities = array(
    'relation' => 'relation',
  );
  $ds_field->ui_limit = 'opportunity_placement|*';
  $ds_field->properties = array(
    'block' => 's4_opportunity|placement_approval',
    'block_render' => '1',
  );
  $export['opportunity_placement_approval'] = $ds_field;

  $ds_field = new stdClass();
  $ds_field->api_version = 1;
  $ds_field->field = 'opportunity_placement_form';
  $ds_field->label = 'Opportunity placement: form';
  $ds_field->field_type = 6;
  $ds_field->entities = array(
    'relation' => 'relation',
  );
  $ds_field->ui_limit = 'opportunity_placement|*';
  $ds_field->properties = array(
    'block' => 's4_opportunity|placement_form',
    'block_render' => '1',
  );
  $export['opportunity_placement_form'] = $ds_field;

  return $export;
}

/**
 * Implements hook_ds_layout_settings_info().
 */
function s4_opportunity_ds_layout_settings_info() {
  $export = array();

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'relation|opportunity_placement|default';
  $ds_layout->entity_type = 'relation';
  $ds_layout->bundle = 'opportunity_placement';
  $ds_layout->view_mode = 'default';
  $ds_layout->layout = 's4_site';
  $ds_layout->settings = array(
    'regions' => array(
      'left' => array(
        0 => 'field_placement_approved',
        1 => 'opportunity_placement_approval',
        2 => 'opportunity_placement_form',
      ),
      'right' => array(
        3 => 'field_dates',
        4 => 'field_course',
        5 => 'field_coordinator',
      ),
    ),
    'fields' => array(
      'field_placement_approved' => 'left',
      'opportunity_placement_approval' => 'left',
      'opportunity_placement_form' => 'left',
      'field_dates' => 'right',
      'field_course' => 'right',
      'field_coordinator' => 'right',
    ),
    'classes' => array(),
    'wrappers' => array(
      'left' => 'div',
      'right' => 'div',
    ),
    'layout_wrapper' => 'div',
    'layout_attributes' => '',
    'layout_attributes_merge' => 1,
  );
  $export['relation|opportunity_placement|default'] = $ds_layout;

  return $export;
}
