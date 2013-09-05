<?php

class views_handler_make_placement_link extends views_handler_field {

  function render($values) {
  	$uid = (isset($values->uid)) ? $values->uid : $values->users_field_data_field_course_students_uid;
    return l(t('Place'), 'signup/create/'. $uid, array('query' => drupal_get_destination(), 'attributes' => array('class' => array('btn'))));
  }

  function query() {

  }
}