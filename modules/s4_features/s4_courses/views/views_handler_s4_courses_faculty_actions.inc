<?php

class views_handler_s4_courses_faculty_actions extends views_handler_field {

  function render($values) {
    $output = array();
    $output[] = l('<i class="icon-plus icon-white"></i> '. t('Add sites'), 'faculty/add-sites/'. $values->nid, array('html' => TRUE, 'attributes' => array('class' => array('btn btn-success'))));
    $output[] = l(t('View students'), 'node/'. $values->nid, array('attributes' => array('class' => array('btn'))));
    return implode(' ', $output);
  }
  
  function query() {
    
  }

}