<?php

/**
*  Views handler indicating a user can signup with a site
*/
class views_handler_s4_sites_current_site_staff_students extends views_handler_field {

  function render($values) {
    $query = db_select('field_data_field_coordinator', 'c')
             ->condition('field_coordinator_nid', $values->nid)
             ->condition('c.deleted', 0)
             ->condition('c.bundle', 'signup')
             ->condition('c.entity_type', 'node')
             ->fields('c', array('field_coordinator_nid'));
    $query->leftJoin('field_data_field_signup_start_date', 's', 's.entity_type = c.entity_type AND s.entity_id = c.entity_id AND s.revision_id = c.revision_id');
    $query->leftJoin('field_data_field_signup_last_date', 'l', 'l.entity_type = c.entity_type AND l.entity_id = c.entity_id AND l.revision_id = c.revision_id');
    $query->condition('s.field_signup_start_date_value', date('Y-m-d'), '<=');
    $query->condition('l.field_signup_last_date_value', date('Y-m-d'), '>=');
    $count = $query->countQuery()->execute()->fetchField();
    return ($count) ? $count : 0;
  }

  
  function query() {
    
  }
}