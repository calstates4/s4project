<?php

class views_handler_s4_user_coordinator_select extends views_handler_field {

  function render($values) {
    if (!isset($_SESSION['s4_signup_site'])) {
      return '<div class="signup denied"><div class="icon"></div>' .
        t('Select a site first.')
        . '</div>';
    }
    $coordinator = node_load($values->nid);
    if(_s4_core_object_is_full($coordinator)) {
    	return '<div class="signup denied"><div class="icon"></div>' .
        t('Coordinator unavailable.')
        . '</div>';
    }
    if (isset($_SESSION['s4_signup_coordinator']) && $_SESSION['s4_signup_coordinator'] == $values->nid) {
      return '<div class="signup signed-up"><div class="icon"></div>Coordinator selected</div>';
    }
    return '<div class="signup"><div class="icon"></div>' .
      l(t('Select this coordinator'), 's4/signup/coordinator/' . $values->nid,
        array('attributes' => array('data-target' => 'signup-course')))
      . '</div>';
  }
  
  function query() {
    
  }
}