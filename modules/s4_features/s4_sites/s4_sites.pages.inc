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

function s4_sites_site_log($node) {
  $form = drupal_render(drupal_get_form('s4_sites_site_log_search'));
  $types = $_SESSION['s4_sites_site_log']['type'];
  $bundle = ($types && $types != 'any') ? array($types) : array('file', 'contact_record');
  $query = db_select('field_data_field_site', 's')
           ->condition('field_site_nid', $node->nid)
           ->condition('entity_type', 'node')
           ->condition('bundle', $bundle, 'IN');
  $query->leftJoin('node', 'n', 'n.nid = s.entity_id');
  $query->addField('s', 'entity_id', 'id');
  $query->addField('s', 'bundle', 'type');
  $query->addField('n', 'created', 'timestamp');
  if(in_array($types, array('versions', 'approval', 'any'))) {
    $workbench_query = db_select('workbench_moderation_node_history', 'h');
    $workbench_query->addField('h', 'hid', 'id');
    $workbench_query->addField('h', 'vid', 'type');
    $workbench_query->addField('h', 'stamp', 'timestamp');
    $workbench_query->condition('h.nid', $node->nid);
    $workbench_query->orderBy('timestamp', 'DESC');
    $query->union($workbench_query, 'UNION ALL');
  }
  
  $results = $query->execute()->fetchAllKeyed();
  
  $header = array(t('Date'), t('Type'), t('Name'), t('User'), t('Note'), t('Action'));
  $rows = array();
  foreach($results as $result => $type) {
    if(in_array($type, array('file', 'contact_record'))) {
      $item = node_load($result);
      $type = ($item->type == 'file') ? t('Form') : t('Log entry');
      $note = '';
      if($item->type == 'file') {
        $files = field_get_items('node', $item, 'field_files');
        if($files && count($files)) {
          $file_display = array();
          foreach($files as $file) {
            $file_display[] = drupal_render(field_view_value('node', $item, 'field_files', $file));
          }
          if(count($file_display) == 1) {
            $note = $file_display[0];
          }
          else {
            $note = theme_item_list(array('items' => $file_display));
          }
        }
      }
      else {
        $body = field_get_items('node', $item, 'body');
        if($body && count($body)) {
          $note = drupal_render(field_view_value('node', $item, 'body', $body[0], 'teaser'));
        }
      }
      $rows[] = array(format_date($item->created, 'short'),
                   $type,
                   l($item->title , 'node/'. $item->nid),
                   theme('username', array('account' => user_load($item->uid))),
                   $note,
                   l('edit', 'node/'. $item->nid .'/edit', array('query' => array('destination' => 'node/'. $node->nid .'/log'), 
                      'attributes' => array('class' => array('btn', 'btn-small', 'btn-info')))));
    }
    else {
      if(in_array($types, array('approval', 'any'))) {
        $moderation = db_select('workbench_moderation_node_history', 'h')
                    ->fields('h')
                    ->condition('nid', $node->nid)
                    ->condition('hid', $result)
                    ->execute()
                    ->fetchAssoc();
        $note = t('From @from_state --> @to_state <br/>%note',
            array(
              '@from_state' => workbench_moderation_state_label($moderation['from_state']),
              '@to_state' => workbench_moderation_state_label($moderation['state']),
              '%note' => $moderation['note'],
            )
          );
        $rows[] = array(format_date($moderation['stamp'], 'short'),
               t('Approval'),
               '',
               theme('username', array('account' => user_load($moderation['uid']))),
               $note,
               ''
               );
      }
      if(in_array($types, array('versions', 'any'))) {
        if(isset($displayed_revisions[$type])) {
          continue;
        }
        $displayed_revisions[$type] = $type;
        $revision = db_select('node_revision', 'r')
                    ->fields('r')
                    ->condition('nid', $node->nid)
                    ->condition('vid', $type)
                    ->execute()
                    ->fetchAssoc();
        $note = '';
        $class = '';
        if(!empty($node->workbench_moderation['published']) && $revision['vid'] == $node->workbench_moderation['published']->vid) {
          $note = '<strong>'. t('This is the current published version') .'</strong>';
          $class = 'published';
        }
        elseif($revision['vid'] == $node->workbench_moderation['current']->vid) {
          $note = '<strong>'. t('This is the current draft') .'</strong>';
          $class = 'draft';          
        }
        $action = '';
        if($node->vid != $revision['vid'] && $revision['vid'] != $node->workbench_moderation['current']->vid) {
          $action = l('revert', 'node/'. $node->nid .'/revisions/' . $revision['vid'] .'/revert', array('attributes' => array('class' => array('btn', 'btn-small', 'btn-danger'))));
        }
        $rows[] = array('data' => array(format_date($revision['timestamp'], 'short'),
                                   t('Version'),
                                   l($revision['title'], 'node/'. $node->nid .'/revisions/' . $revision['vid'] .'/view'),
                                   theme('username', array('account' => user_load($revision['uid']))),
                                   $revision['log'] .' '. $note,
                                   $action
                                  ),
                        'class' => array($class),
                        );
      }
    }
  }

  $send_form = drupal_render(drupal_get_form('s4_sites_send_site_form'));
  $node_current = workbench_moderation_node_current_load($node);
  $moderate_form = drupal_render(drupal_get_form('workbench_moderation_moderate_form', $node_current));
  $results = theme('table', array('header' => $header, 'rows' => $rows));

  return theme('s4_sites_log_page', array('moderate_form' => $moderate_form, 'send_form' => $send_form, 'site' => $node, 'form' => $form, 'results' => $results));
}

function s4_sites_site_log_search() {
  $form = array();

  $settings = $_SESSION['s4_sites_site_log'];

  $form['type'] = array(
    '#type' => 'select',
    '#title' => t('Type of entry'),
    '#options' => array('any' => t('-- Any --'),
                        'file' => t('Form'),
                        'contact_record' => t('Log entry'),
                        'versions' => t('Versons'),
                        'approval' => t('Approval'),
                       ),
    '#default_value' => ($settings['type']) ? $settings['type'] : 'any',
    );

  $form['search'] = array(
    '#type' => 'submit',
    '#value' => t('Search'),
    );

  return $form;
}

function s4_sites_site_log_search_submit($form, $form_state) {
  $_SESSION['s4_sites_site_log'] = array();
  $_SESSION['s4_sites_site_log']['type'] = $form_state['values']['type'];
}
