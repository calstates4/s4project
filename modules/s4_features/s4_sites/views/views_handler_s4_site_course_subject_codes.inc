<?php

/**
*  Views handler with list of subject codes 
*/
class views_handler_s4_site_course_subject_codes extends views_handler_field {

  function render($values) {
    $query = db_select('node', 'n')
             ->condition('n.type', 'signup')
             ->condition('n.status', 1);
    $query->leftJoin('field_data_field_site', 's', 's.entity_id = n.nid AND s.revision_id = n.vid AND s.entity_type = :node', array(':node' => 'node'));
    $query->leftJoin('field_data_field_course', 'c', 'c.entity_id = n.nid AND c.revision_id = n.vid AND s.entity_type = :node', array(':node' => 'node'));
    $query->leftJoin('field_data_field_course_subject', 'su', 'su.entity_id = c.field_course_nid AND su.entity_type = :node', array(':node' => 'node'));
    $query->condition('s.field_site_nid', $values->nid);
    $date = $this->view->exposed_raw_input['field_signup_start_date_value'];
    $term = $this->view->exposed_raw_input['field_term_nid_1'];
    if(is_array($term) && count($term)) {
      $query->leftJoin('field_data_field_term', 't', 't.entity_id = c.field_course_nid AND t.entity_type = :node', array(':node' => 'node'));
      $query->condition('t.field_term_nid', $term, 'IN');
    }
    elseif($date['default_date'] && $date['default_to_date']) {
      $query->leftJoin('field_data_field_signup_start_date', 'd', 'd.entity_id = n.nid AND d.revision_id = n.vid AND d.entity_type = :node', array(':node' => 'node'));
      $query->condition('d.field_signup_start_date_value', date('Y-m-d', strtotime($date['defalut_date'])), '>=');$query->condition('d.field_signup_start_date_value', date('Y-m-d', strtotime($date['defalut_to_date'])), '<=');
    }
    $query->fields('su', array('field_course_subject_value'));
    $query->distinct();
    $query->addExpression('COUNT(n.nid)');
    $query->groupBy('field_course_subject_value');
    $result = $query->execute()->fetchAllKeyed();
    if(!count($result)) {
      return;
    }
    foreach($result as $subject => $total) {
      $result[$subject] = '<strong>'. $subject .':</strong> '. $total;
    }
    return theme('item_list', array('items' => $result));
  }
  
  function query() {
    
  }
}