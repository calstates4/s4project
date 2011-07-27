<?php

class views_handler_s4_assessment_link extends views_handler_field {

  function render($values) {
    $assessment = variable_get('s4_assessment_assessment_form', '');
    if(!$assessment) {
    	return null;
    }
    return l('Complete assessment', 'node/'. $assessment);
  }
  
  function query() {
    
  }
}