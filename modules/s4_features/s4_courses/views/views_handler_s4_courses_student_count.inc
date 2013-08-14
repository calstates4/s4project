<?php

class views_handler_s4_courses_student_count extends views_handler_field {

  function render($values) {
  	$node = $values->_field_data['nid_1']['entity'];
  	return count(field_get_items('node', $node, 'field_course_students'));
  }
  
  function query() {
    
  }
}