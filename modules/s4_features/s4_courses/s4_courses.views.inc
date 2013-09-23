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
  
  $data['s4_course']['course_student_placements'] = array(
    'title' => t('Total course placements'),
    'help' => t('Total number of placements made in a course.'),
    'field' => array(
      'handler' => 'views_handler_s4_courses_placements_count',
      'click sortable' => FALSE,
    ),
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
  );

  $data['s4_course']['course_faculty_actions'] = array(
    'title' => t('Faculty actions'),
    'help' => t('Faculty actions for a course.'),
    'field' => array(
      'handler' => 'views_handler_s4_courses_faculty_actions',
      'click sortable' => FALSE,
    ),
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
  );

  $data['s4_course_user']['table']['group'] = t('Course student');
  $data['s4_course_user']['table']['join'] = array(
    'users' => array(
      'left_field' => 'uid',
      'field' => 'uid',
    ),
  );

  $data['s4_course_user']['faculty_manage_make_placement_link'] = array(
    'title' => t('Make placement link (for faculty)'),
    'help' => t('Provides link to make a placement on a user\'s behalf for faculty.'),
    'field' => array(
      'handler' => 'views_handler_faculty_manage_make_placement_link',
      'click sortable' => FALSE,
    ),
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
  );
  
  return $data;
}

/**
*  Implements hook_views_plugins
*/
function s4_courses_views_plugins() {
  $plugins = array(
    'access' => array(
      'user_faculty' => array(
        'title' => t('User is faculty'),
        'help' => t('Access is granted if the current user is a faculty for the course on the current page.'),
        'handler' => 's4_courses_views_access_course_faculty',
        'uses options' => TRUE,
        'help topic' => 'access-perm',
      ),
    ),
  );
  return $plugins;
}