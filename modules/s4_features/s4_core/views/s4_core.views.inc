<?php

/**
*  @file Views hooks
*/

/**
*  Implementation of hook_views_data
*/
function s4_core_views_data() {
  $data['s4_signup']['table']['group'] = t('Signup');
  $data['s4_signup']['table']['join'] = array(
    'node' => array(
      'left_field' => 'nid',
      'field' => 'nid',
    ),
  );


  $data['s4_signup']['user_course_select'] = array(
    'title' => t('User select course'),
    'help' => t('The end user is selecting this course to signup with.'),
    'field' => array(
      'handler' => 'views_handler_s4_user_course_select',
      'click sortable' => FALSE,
    ),
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
  );

  $data['s4_signup']['faculty_site_select'] = array(
    'title' => t('Faculty site select'),
    'help' => t('The faculty is adding a site to their course.'),
    'field' => array(
      'handler' => 'views_handler_s4_faculty_site_select',
      'click sortable' => FALSE,
    ),
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
  );
  
  $data['s4_signup']['faculty_coordinator_select'] = array(
    'title' => t('User select coordinator'),
    'help' => t('The user is adding a coordinator.'),
    'field' => array(
      'handler' => 'views_handler_s4_user_coordinator_select',
      'click sortable' => FALSE,
    ),
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
  );
  
  $data['s4_signup']['student_signup_node'] = array(
    'title' => t('Signup related to student'),
    'help' => t('For listings of students assigned to a course'),
    'field' => array(
      'handler' => 'views_handler_s4_course_student_signup',
      'click sortable' => FALSE,
    ),
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
  );
  
  return $data;
}

/**
*  Implementation of hook_views_plugins_alter
*/
function s4_core_views_plugins_alter(&$plugins) {
  $plugins['style']['views_data_export_csv']['export feed icon'] = drupal_get_path('module', 's4_core') . '/images/export_csv.png';
  $plugins['style']['views_data_export_doc']['export feed icon'] = drupal_get_path('module', 's4_core') . '/images/export_word.png';
  $plugins['style']['views_data_export_xls']['export feed icon'] = drupal_get_path('module', 's4_core') . '/images/export_excel.png';
}