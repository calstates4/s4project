<?php

class views_handler_s4_cancel_signup_link extends views_handler_field {

  function render($values) {
    $node = node_load($values->nid);
    if(s4_core_start_over_access($node)) {
      return l(t('Cancel placement'), 's4/start-over/' . $node->nid);
    }
    return t('Cannot cancel');
  }

  function query() {

  }
}