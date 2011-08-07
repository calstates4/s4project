<?php

function s4_courses_views_data() {
  $data['s4_course']['table']['group'] = t('Course');
  $data['s4_course']['table']['join'] = array(
  'node' => array(
    'left_field' => 'nid',
    'field' => 'nid',
  ),
  );


  $data['s4_course']['course_student_enrollment'] = array(
    'title' => t('Total course enrollment'),
    'help' => t('Total number of students in a course.'),
    'field' => array(
      'handler' => 'views_handler_s4_courses_student_count',
      'click sortable' => FALSE,
    ),
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
  );
  
  return $data;
}
