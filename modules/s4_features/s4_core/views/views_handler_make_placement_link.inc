<?php

class views_handler_make_placement_link extends views_handler_field {

  function render($values) {
    return l(t('Place'), 'signup/create/'. $values->uid, array('query' => drupal_get_destination(), 'attributes' => array('class' => array('btn'))));
  }

  function query() {

  }
}