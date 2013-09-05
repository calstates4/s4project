<?php

class views_handler_s4_user_course_select extends views_handler_field {

  function render($values) {
    if (isset($_SESSION['s4_signup_course']) && $_SESSION['s4_signup_course'] == $values->nid) {
      
      return l('<i class="icon-check icon-white"></i> ' .
				 t('Course selected'), 
				 's4/signup/course/' . $values->nid,
         array('html' => TRUE,
         			 'attributes' => array(
			         	  'class' => array('btn', 'btn-info'),
			         	  'data-target' => 'signup-course')));
    }
    global $user;
    $signups = s4_core_get_user_signups($user->uid);
    $count = array();
    foreach ($signups as $signup) {
      $course = field_get_items('node', $signup, 'field_course');
      $course = node_load($course[0]['nid']);
      if($course) {
        $count[$course->nid] = ($count[$course->nid]) ? $count[$course->nid] : 0;
        $max = field_get_items('node', $course, 'field_max_placements');
        $max = ($max[0]['value'] || $max[0]['value'] == 0)
               ? $max[0]['value']
               : 1;
        $count[$course->nid]++;
        if ($course->nid == $values->nid && ($count[$course->nid] >= $max)) {
          return '<a class="disabled btn btn-info"><i class="icon-white icon-remove"></i> Already placed with this course</a>';
        }
      }
    }
    return l('<i class="icon-ok-circle icon-white"></i> ' . 
    					t('Select this course'),
    					's4/signup/course/' . $values->nid,
			         array('html' => TRUE,
			         	     'attributes' => array(
			         	     'class' => array('btn', 'btn-primary'),
			         	     'data-target' => 'signup-course')));
  }

  function query() {

  }
}