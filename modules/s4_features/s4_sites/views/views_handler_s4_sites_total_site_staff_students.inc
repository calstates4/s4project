<?php

/**
*  Views handler indicating a user can signup with a site
*/
class views_handler_s4_sites_total_site_staff_students extends views_handler_field {

  function render($values) {
    $count = db_select('field_data_field_coordinator', 'c')
             ->condition('field_coordinator_nid', $values->nid)
             ->condition('deleted', 0)
             ->condition('bundle', 'signup')
             ->condition('entity_type', 'node')
             ->fields('c', array('field_coordinator_nid'))
             ->countQuery()->execute()->fetchField();
    return ($count) ? $count : 0;
  }
  
  function query() {
    
  }
}