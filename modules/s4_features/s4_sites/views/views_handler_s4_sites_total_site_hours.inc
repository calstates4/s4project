<?php

/**
*	Views handler indicating a user can signup with a site
*/
class views_handler_s4_sites_total_site_hours extends views_handler_field {

  function render($values) {
    return rand(400, 1500);
    
  }
  
  function query() {
    
  }
}