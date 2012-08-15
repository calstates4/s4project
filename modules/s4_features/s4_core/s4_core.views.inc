<?php

/**
*  @file Views hooks
*/

/**
* Implements hook_views_data
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

  $data['s4_signup']['site_location_links'] = array(
    'title' => t('Site location links'),
    'help' => t('Links to all site locations'),
    'field' => array(
      'handler' => 'views_handler_s4_site_locations',
      'click sortable' => FALSE,
    ),
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
  );
  
  $data['s4_signup']['cancel_signup_link'] = array(
    'title' => t('Cancel signup link'),
    'help' => t('Links user to delete their signup'),
    'field' => array(
      'handler' => 'views_handler_s4_cancel_signup_link',
      'click sortable' => FALSE,
    ),
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
  );

  $data['s4_user_signup']['table']['group'] = t('User Signup');
  $data['s4_user_signup']['table']['join'] = array(
    'users' => array(
      'left_field' => 'uid',
      'field' => 'uid',
    ),
  );

  $data['s4_user_signup']['student_signup_list'] = array(
    'title' => t('List all signups for a user'),
    'help' => t('Renders an unordered list of a user\'s signup records.'),
    'field' => array(
      'handler' => 'views_handler_s4_student_signup_list',
      'click sortable' => FALSE,
    ),
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
  );


  $data['s4_user_signup']['user_program_select'] = array(
    'title' => t('User select program'),
    'help' => t('The end user is selecting this program to signup with.'),
    'field' => array(
      'handler' => 'views_handler_s4_user_program_select',
      'click sortable' => FALSE,
    ),
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
  );

  return $data;
}

/**
*  Implementatio of hook_views_plugins
*/
function s4_core_views_plugins() {
  $plugins = array(
    'access' => array(
      'type_role' => array(
        'title' => t('Node type and role'),
        'help' => t('Access will be granted to users with the specified role where the node in the URL argument is given.'),
        'handler' => 's4_core_views_access_node_type_role',
        'uses options' => TRUE,
        'help topic' => 'access-perm',
      ),
      'role_reverse' => array(
        'title' => t('User is not in a role'),
        'help' => t('Access will be granted to users without the selected role.'),
        'handler' => 's4_core_views_access_role_reverse',
        'uses options' => TRUE,
        'help topic' => 'access-perm',
      ),
    ),
  );
  return $plugins;
}

/**
* Implements hook_views_plugins_alter
*/
function s4_core_views_plugins_alter(&$plugins) {
  $plugins['style']['views_data_export_csv']['export feed icon'] = drupal_get_path('module', 's4_core') . '/images/export_csv.png';
  $plugins['style']['views_data_export_doc']['export feed icon'] = drupal_get_path('module', 's4_core') . '/images/export_word.png';
  $plugins['style']['views_data_export_xls']['export feed icon'] = drupal_get_path('module', 's4_core') . '/images/export_excel.png';
}