<?php

/**
*  Administrative settings for district data.
*/
function s4_districts_admin_districts_form() {
  $form = array();
  
  $form['rebuild']['#markup'] = l(t('Rebuild relationships between sites and districts'), 'admin/config/s4/districts/rebuild');
  
  $form['s4_districts_district_lookup_service'] = array(
    '#type' => 'textfield',
    '#title' => 'URL to the lookup service',
    '#default_value' => variable_get('s4_districts_district_lookup_service', ''),
  );
  
  $bundle = field_extract_bundle('node', 'site');
  $options = array('' => 'Select one');
  foreach(field_info_instances('node', $bundle) as $field) {
    $options[$field['field_name']] = $field['label'];
  }
  
  foreach(s4_districts_types() as $type => $label) {
    $form['s4_districts_field_'. $type] = array(
      '#type' => 'select',
      '#title' => t('Field for @type', array('@type' => $label)),
      '#options' => $options,
      '#default_value' => variable_get('s4_districts_field_'. $type, ''),
    );
  }
  
  return system_settings_form($form);
}

/**
*  Admin form to let users batch update their site data. 
*  Useful if district lines have been redrawn.
*/
function s4_districts_admin_districts_rebuild_form() {
  $form = array();
  
  $form['description']['#markup'] = t('<p>This process will walk through all sites without state or federal district information and match the location of the site with districts.</p>');
  
  $form['submit'] = array(
    '#type' => 'submit',
    '#value' => 'Start rebuilding',
  );
  
  return $form;
}

/**
*  Form submit for batch updating.
*/
function s4_districts_admin_districts_rebuild_form_submit($form, $form_state) {
  $batch = array(
    'finished' => 's4_districts_admin_districts_rebuild_finished',
    'title' => t('Bulk updating district data'),
    'init_message' => t('Starting the update.'),
    'progress_message' => t('Processed @current out of @total.'),
    'error_message' => t('Uh, oh, we have an error.'),
    'file' => drupal_get_path('module', 's4_districts') . '/s4_districts.admin.inc',
  );
  
  $query = db_select('field_data_field_location', 'fl');
  $query->condition('fl.bundle', 'site');
  $query->fields('fl', array('entity_id'));
  $query->leftJoin('location', 'l', 'fl.field_location_lid = l.lid');
  $query->isNotNull('l.latitude')
      ->isNotNull('l.longitude')
      ->condition('l.latitude', 0, '!=')
      ->condition('l.longitude', 0, '!=');
  $result = $query->execute();
  foreach($result->fetchCol() as $nid) {
    $batch['operations'][] = array('s4_districts_admin_districts_rebuild_operation', array($nid));
  }
  
  
  batch_set($batch);
}

/**
*  Rebuild batch operation
*/
function s4_districts_admin_districts_rebuild_operation($nid, &$context) {
  $node = node_load($nid);
  s4_districts_set_districts($node);
  node_save($node);
  $context['message'] = t('Looking up district data for %title', array('%title' => $node->title));
}

/**
*  Finished callback for batch
*/
function s4_districts_admin_districts_rebuild_finished($success, $results, $operations) {
  if ($success) {
    $message = 'Bulk update complete.';
  }
  else {
    $error_operation = reset($operations);
    $message = t('An error occurred while processing %error_operation with arguments: @arguments', array('%error_operation' => $error_operation[0], '@arguments' => print_r($error_operation[1], TRUE)));
  }
  drupal_set_message($message);
}