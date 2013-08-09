<?php

class views_handler_s4_courses_faculty_actions extends views_handler_field {

  function render($values) {
    $output[] = l(t('Add sites'), 'faculty/add-sites/'. $values->nid, array('html' => TRUE, 'attributes' => array('class' => array('btn btn-success')), 'query' => array('return' => $_GET['q'])));
    $output[] = l(t('View students'), 'node/'. $values->nid, array('attributes' => array('class' => array('btn'))));
    
    return implode(' ', $output);
  }
  
  function query() {
    
  }

}