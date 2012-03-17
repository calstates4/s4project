<?php

/**
*  Views handler indicating a user can signup with a site
*/
class views_handler_s4_sites_total_site_students extends views_handler_field {

  function render($values) {
    $total = db_select('field_data_field_site', 's')
         ->condition('bundle', 'signup')
         ->condition('field_site_nid', $values->nid);
    $total->addExpression('COUNT(entity_id)', 'total');
    $total = $total->execute()
         ->fetchField();
    return ($total)
        ? $total
        : 0;
    
  }
  
  function query() {
    
  }
}