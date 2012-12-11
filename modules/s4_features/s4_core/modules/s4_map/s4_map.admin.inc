<?php

function s4_map_admin_rebuild_counties() {
  $form = array();
  
  $form['instructions'] = array(
    '#markup' => t('When you rebuild county data, every site\'s county information will be recomputed based on the main physical location of each site.'),
  );
  
  $form['submit'] = array(
    '#type' => 'submit',
    '#value' => t('Re-build county data'),
  );
  
  return $form;
}

function s4_map_admin_rebuild_counties_submit() {
  $batch = array(
    'finished' => 's4_map_admin_rebuild_counties_finished',
    'title' => t('Bulk updating county data'),
    'init_message' => t('Starting the update.'),
    'progress_message' => t('Processed @current out of @total.'),
    'error_message' => t('Uh, oh, we have an error.'),
    'file' => drupal_get_path('module', 's4_map') . '/s4_map.admin.inc',
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
    $batch['operations'][] = array('s4_map_admin_rebuild_counties_operation', array($nid));
  }
  batch_set($batch);
}

/**
*  Rebuild batch operation
*/
function s4_map_admin_rebuild_counties_operation($nid, &$context) {
  $node = node_load($nid);
  s4_map_assign_county($node, TRUE);
  node_save($node);
  $context['message'] = t('Rebuilding county data for %title', array('%title' => $node->title));
}

/**
*  Finished callback for batch
*/
function s4_map_admin_rebuild_counties_finished($success, $results, $operations) {
  if ($success) {
    $message = 'Bulk update complete.';
  }
  else {
    $error_operation = reset($operations);
    $message = t('An error occurred while processing %error_operation with arguments: @arguments', array('%error_operation' => $error_operation[0], '@arguments' => print_r($error_operation[1], TRUE)));
  }
  drupal_set_message($message);
}