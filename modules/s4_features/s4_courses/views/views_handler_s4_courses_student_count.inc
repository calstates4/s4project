<?php

class views_handler_s4_courses_student_count extends views_handler_field {

  function render($values) {
    $language = $values->_field_data['nid']['entity']->language;
    return count($values->_field_data['nid']['entity']->field_course_students[$language]);
  }
  
  function query() {
    
  }
}