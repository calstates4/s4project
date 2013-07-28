<?php

/**
*  Views handler to render links to all locations in a site
*/
class views_handler_s4_student_signup_list extends views_handler_field {

  function render($values) {
    $uid = array_shift(array_values($values->_field_data));
    $uid = $uid['entity']->uid;
    $query = db_select('field_data_field_user', 's')
         ->condition('s.bundle', 'signup')
         ->condition('s.entity_type', 'node')
         ->condition('s.field_user_uid', $uid);
    $query->leftJoin('field_data_field_site', 'site', 's.entity_id = site.entity_id AND s.bundle = :signup', array(':signup' => 'signup'));
    $query->leftJoin('node', 'n', 'n.nid = s.entity_id');
    $query->fields('n', array('nid', 'title'));
    if($this->options['only_current']) {
      $query->leftJoin('field_data_field_signup_start_date', 'sd', 'sd.entity_id = s.entity_id AND sd.entity_type = s.entity_type');
      $query->leftJoin('field_data_field_signup_last_date', 'ld', 'ld.entity_id = s.entity_id AND ld.entity_type = s.entity_type');
      $query->condition('sd.field_signup_start_date_value', date('Y-m-d'), '<=');
      $query->condition('ld.field_signup_last_date_value', date('Y-m-d'), '>=');
    }
    if($this->options['course']) {
      $course = menu_get_object();
      $query->leftJoin('field_data_field_course', 'c', 'c.entity_id = s.entity_id AND c.entity_type = s.entity_type');
      $query->condition('c.field_course_nid', $course->nid);
    }
    $results = $query->execute();
    $list = array();
    while ($row = $results->fetchAssoc()) {
      $signup = node_load($row['nid']);
      $site = field_get_items('node', $signup, 'field_site');
      $site = node_load($site[0]['nid']);
      $list[$row['nid']] = l($site->title, 'node/' . $row['nid'], array('query' => array('destination' => $_GET['q'])));
      if(user_access('create signups for other users')) {
        $list[$row['nid']] .= ' - '. l(t('edit'), 
          'signup/create/'. $uid .'/edit/'.$row['nid'], 
          array('query' => array('modal' => 'modal'), 'attributes' => array('class' => array('iframe-modal'), 'data-modal-title' => t('Edit placement for @first @last', array('@first' => $values->field_data_field_first_name_field_first_name_value, '@last' => $values->field_data_field_last_name_field_last_name_value)))));
        $list[$row['nid']] .= ' - '. l(t('delete'), 
          'node/'. $row['nid'] .'/signup-delete', 
          array('query' => array('modal' => 'modal'), 'attributes' => array('class' => array('iframe-modal'), 'data-modal-title' => t('Delete placement for @first @last', array('@first' => $values->field_data_field_first_name_field_first_name_value, '@last' => $values->field_data_field_last_name_field_last_name_value)))));
      }
     
    }
    drupal_alter('s4_student_signup_list', $list);
    if (count($list) == 0) {
      return '';
    }
    return theme('item_list', array('items' => $list));
  }

  function query() {
    
  }
  
  function options_form(&$form, &$form_state) {
    parent::options_form($form, $form_state);
    
    $form['course'] = array(
      '#type' => 'checkbox',
      '#title' => t('Only display placements in current course'),
      '#default_value' => $this->options['course'],
    );
    
    $form['only_current'] = array(
      '#type' => 'checkbox',
      '#title' => t('Only display current placements'),
      '#default_value' => $this->options['only_current'],
    );
    return $form;
  }
  
  function options_submit(&$form, &$form_state) {   
    $options = &$form_state['values']['options']; 
  }
  
  function option_definition() {
    $options = parent::option_definition();
    
    $options['course'] = array(
      'default' => FALSE,
      'translatable' => FALSE,
    );
    
    $options['only_current'] = array(
      'default' => FALSE,
      'translatable' => FALSE,
    );
    
    return $options;
  }
}