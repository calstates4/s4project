<?php

class views_handler_s4_assessment_link extends views_handler_field {

  function render($values) {
    $node = menu_get_object();
    if(!$node || $node->type != 'course') {
    	return null;
    }
   
    $assessment = variable_get('s4_assessment_assessment_form', '');
    if(!$assessment) {
    	return null;
    }
    $signup_query = db_select('field_data_field_course', 'c')
    				->condition('c.field_course_nid', $node->nid)
    				->condition('c.bundle', 'signup')
    				->fields('c', array('entity_id'));
    $signup_query->leftJoin('field_data_field_user', 'u', 'u.entity_id = c.entity_id AND u.bundle = c.bundle');
    $signup_query->condition('u.field_user_uid', $values->users_field_data_field_course_students_uid);
    $signup = $signup_query->execute()->fetchField();
    
     $assessment = db_select('field_data_field_form_assessment_sid', 'a')
    		 ->condition('a.entity_id', $signup)
    		 ->condition('a.bundle', 'signup')
    		 ->fields('a', array('field_form_assessment_sid_value'))
    		 ->execute()
    		 ->fetchField();
    if($assessment > 0) {
    	return 'Assessment completed';
    }
    if($signup) {
	    return l('Complete assessment', 
	    		 'node/'. $assessment, 
	    		 array('query' => array('signup' => $signup,
	    		 						'destination' => 'node/'. $node->nid
	    		 )));
  	}
  }
  
  function query() {
    
  }
}