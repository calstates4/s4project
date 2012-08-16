<?php
/**
 * @file
 * s4_districts.strongarm.inc
 */

/**
 * Implements hook_strongarm().
 */
function s4_districts_strongarm() {
  $export = array();

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 's4_districts_district_lookup_service';
  $strongarm->value = 'http://congress.mcommons.com/districts/lookup.xml';
  $export['s4_districts_district_lookup_service'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 's4_districts_field_federal';
  $strongarm->value = 'field_district_federal';
  $export['s4_districts_field_federal'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 's4_districts_field_state_lower';
  $strongarm->value = 'field_district_state_lower';
  $export['s4_districts_field_state_lower'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 's4_districts_field_state_upper';
  $strongarm->value = 'field_district_state_upper';
  $export['s4_districts_field_state_upper'] = $strongarm;

  return $export;
}
