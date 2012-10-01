<?php

class views_handler_make_placement_link extends views_handler_field {

  function render($values) {
    return l(t('Make placement'), 'signup/create/'. $values->uid, array('query' => drupal_get_destination()));
  }

  function query() {

  }
}