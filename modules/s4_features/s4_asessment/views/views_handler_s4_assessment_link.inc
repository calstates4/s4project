<?php

class views_handler_s4_assessment_link extends views_handler_field {

  function render($values) {
    if($values->nid) {
    	$node = node_load($values->nid);
    }
    else {
	    $node = menu_get_object();
    }
    if(!$node || $node->type != 'course') {
    	return null;
    }
   
    $assessment_forms = variable_get('s4_assessment_assessment_form', '');
    if(!$assessment_forms) {
    	return null;
    }
    $signup_query = db_select('field_data_field_course', 'c')
    				->condition('c.field_course_nid', $node->nid)
    				->condition('c.bundle', 'signup')
    				->fields('c', array('entity_id'));
    $signup_query->leftJoin('field_data_field_user', 'u', 'u.entity_id = c.entity_id AND u.bundle = c.bundle');
    $signup_query->condition('u.field_user_uid', $values->users_field_data_field_course_students_uid);
    $signup = $signup_query->execute()->fetchField();
    if(!$signup) {
      return null;
    }
    module_load_include('inc', 'webform', 'includes/webform.submissions');
    $existing_submissions = db_select('field_data_field_form_assessment_sid', 'a')
    		 ->condition('a.entity_id', $signup)
    		 ->condition('a.bundle', 'signup')
    		 ->fields('a', array('field_form_assessment_sid_value'))
    		 ->execute()
    		 ->fetchAllKeyed(0, 0);
    $existing_assessments = array();
    foreach($existing_submissions as $existing) {
      $submission = webform_get_submissions(array('sid' => $existing));
      $existing_assessments[$submission[$existing]->nid] = $submission[$existing]->nid;
    }
    
    $assessments = array();
    foreach($assessment_forms as $form_nid => $enabled) {
      if($enabled) {
        $form = node_load($form_nid);
        if($existing_assessments[$form->nid]) {
          $assessments[] = t('%title completed', array('%title' => $form->title));
        }
        else {
          $assessments[] = l($form->title, 
  	    		 'node/'. $form->nid, 
  	    		 array('query' => array('signup' => $signup,
  	    		 						'destination' => 'node/'. $node->nid
  	    		 )));
        }
      }
    }
    return theme('item_list', array('items' => $assessments));
    if($assessment > 0) {
    	return 'Assessment completed';
    }
    if($signup) {
	    return l('Complete assessment', 
	    		 'node/'. $assessment_form, 
	    		 array('query' => array('signup' => $signup,
	    		 						'destination' => 'node/'. $node->nid
	    		 )));
  	}
  }
  
  function query() {
    
  }
}