<?php

/**
*  Views handler indicating a user can signup with a site
*/
class views_handler_s4_sites_total_site_hours extends views_handler_field {

  function render($values) {
    $total = db_select('field_data_field_site', 's')
         ->condition('s.bundle', 'signup')
         ->condition('s.field_site_nid', $values->nid);
    $total->leftJoin('field_data_field_signup_hours', 'h', 'h.entity_id = s.entity_id AND h.bundle = s.bundle');
    $total->addExpression('SUM(h.field_signup_hours_value)', 'total');
    $total = $total->execute()
         ->fetchField();
    return ($total)
        ? $total
        : 0;
    
  }
  
  function query() {
    
  }
}