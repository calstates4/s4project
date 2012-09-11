<?php


function s4_sites_merge_sites($form, $form_state, $node) {
  $form = array();
  
  $form['instructions'] = array(
    '#markup' => t('When a site is merged with another, all the student placements, site staff, notes, forms, and other records are brought over. However, one site will be losing basic information like site description. Make sure you have all the information you need transferred to one of these sites before merging.'),
  );
  
  $sites = array();
  $query = db_select('node', 'n')
       ->fields('n', array('nid', 'title'))
       ->condition('type', 'site')
       ->orderBy('title', 'ASC');
  $results = $query->execute();
  foreach ($results as $result) {
    if($result->nid != $node->nid) {
      $sites[$result->nid] = $result->title;
    }
  }
  
  $form['action'] = array(
    '#type' => 'radios',
    '#title' => t('Select which site should lose its data'),
    '#options' => array('current' => $node->title,
                        'selected' => t('The site selected below'))
  );
  
  $form['other_site'] = array(
    '#type' => 'select',
    '#title' => t('Site to merge with'),
    '#options' => $sites,
    '#attributes' => array('class' => array('chosen')),
    '#required' => TRUE,
  );
  
  $form['current_site'] = array(
    '#type' => 'hidden',
    '#value' => $node->nid,
  );
  
  $form['actions'] = array('#type' => 'actions');
  
  $form['actions']['submit'] = array(
    '#type' => 'submit',
    '#value' => 'Merge sites',
  );
  
  $form['actions']['cancel'] = array(
    '#markup' => l(t('Cancel'), 'node/'. $node->nid),
  );
  
  return $form;
}

function s4_sites_merge_sites_submit($form, $form_state) {
  $batch = array(
    'operations' => array(),
    'finished' => 's4_sites_merge_sites_finished',
    'title' => t('Merging site information'),
    'init_message' => t('Preparint to merge sites.'),
    'progress_message' => t('Processed @current out of @total.'),
    'error_message' => t('Whoops, we have encountered an error.'),
    'file' => drupal_get_path('module', 's4_sites') . '/s4_sites.pages.inc',
  );
  if($form_state['values']['action'] == 'current') {
    $source = $form_state['values']['current_site'];
    $target = $form_state['values']['other_site'];
  }
  else {
    $source = $form_state['values']['other_site'];
    $target = $form_state['values']['current_site'];    
  }
  foreach(array('coordinator', 'contact_record', 'file', 'signup') as $bundle) {
    $items = db_query('select n.nid, n.title from {field_data_field_site} s
                             left join {node} n ON n.nid = s.entity_id
                             where bundle = :bundle and field_site_nid = :source',
              array(':bundle' => $bundle, ':source' => $source))->fetchAll();
    foreach($items as $item) {
      $batch['operations'][] = array(
        's4_sites_merge_sites_change_field',
        array(
          $item->nid,
          t('Moving @name', array('@name' => $item->title)),
          'field_site',
          $target,
        )
      );
    }
  }
  $courses = db_query('select n.nid, n.title from {field_data_field_site} s
                             left join {node} n ON n.nid = s.entity_id
                             where bundle = :bundle and field_site_nid = :source',
              array(':bundle' => 'course', ':source' => $source))->fetchAll();
  foreach($items as $item) {
    $batch['operations'][] = array(
      's4_sites_merge_sites_change_course',
      array(
        $item->nid,
        t('Moving @name', array('@name' => $item->title)),
        $target,
        $source,
      )
    );
  }
  $batch['operations'][] = array(
    's4_sites_merge_sites_delete_source',
    array($source),
  );
  batch_set($batch);
}

function s4_sites_merge_sites_change_course($node, $message, $target, &$context) {
  $node = node_load($nid);
  foreach($node->field_sites[$node->language] as $k => $site) {
    if($site['nid'] == $source) {
      $node->field_sites[$node->language][$k]['nid'] = $target;
    }
  } 
  $context['message'] = $message;
}

function s4_sites_merge_sites_change_field($nid, $message, $field, $target, &$context) {
  $node = node_load($nid);
  $node->{$field}[$node->language][0]['nid'] = $target;
  node_save($node);
  $context['message'] = $message;
}

function s4_sites_merge_sites_delete_source($nid, &$context) {
  $node = node_load($nid);
  node_delete($node->nid);
  $context['message'] = t('Deleting @title', array('@title' => $node->title));
}

function s4_sites_merge_sites_finished($success, $results, $operations) {
  if ($success) {
    // Here we do something meaningful with the results.
    $message = t('@count completed', array('@count' => count($results)));
    $message .= theme('item_list', $results);
  }
  else {
    // An error occurred.
    // $operations contains the operations that remained unprocessed.
    $error_operation = reset($operations);
    $message = t('An error occurred while processing %error_operation with arguments: @arguments', array('%error_operation' => $error_operation[0], '@arguments' => print_r($error_operation[1], TRUE)));
  }
  drupal_set_message($message);
}