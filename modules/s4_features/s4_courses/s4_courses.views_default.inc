<?php
/**
 * @file
 * s4_courses.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function s4_courses_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'course_students';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Course students';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Course students';
  $handler->display->display_options['css_class'] = 'quicksearch';
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['access']['perm'] = 'manage course students';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['query']['options']['query_comment'] = FALSE;
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '0';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['columns'] = array(
    'field_first_name' => 'field_first_name',
    'field_last_name' => 'field_last_name',
    'login' => 'login',
  );
  $handler->display->display_options['style_options']['default'] = '-1';
  $handler->display->display_options['style_options']['info'] = array(
    'field_first_name' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
    ),
    'field_last_name' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
    ),
    'login' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
    ),
  );
  /* Relationship: Content: Students (field_course_students) */
  $handler->display->display_options['relationships']['field_course_students_uid']['id'] = 'field_course_students_uid';
  $handler->display->display_options['relationships']['field_course_students_uid']['table'] = 'field_data_field_course_students';
  $handler->display->display_options['relationships']['field_course_students_uid']['field'] = 'field_course_students_uid';
  $handler->display->display_options['relationships']['field_course_students_uid']['delta'] = '-1';
  /* Field: User: Uid */
  $handler->display->display_options['fields']['uid']['id'] = 'uid';
  $handler->display->display_options['fields']['uid']['table'] = 'users';
  $handler->display->display_options['fields']['uid']['field'] = 'uid';
  $handler->display->display_options['fields']['uid']['relationship'] = 'field_course_students_uid';
  $handler->display->display_options['fields']['uid']['exclude'] = TRUE;
  $handler->display->display_options['fields']['uid']['hide_alter_empty'] = FALSE;
  $handler->display->display_options['fields']['uid']['link_to_user'] = FALSE;
  /* Field: Field: First Name */
  $handler->display->display_options['fields']['field_first_name']['id'] = 'field_first_name';
  $handler->display->display_options['fields']['field_first_name']['table'] = 'field_data_field_first_name';
  $handler->display->display_options['fields']['field_first_name']['field'] = 'field_first_name';
  $handler->display->display_options['fields']['field_first_name']['relationship'] = 'field_course_students_uid';
  $handler->display->display_options['fields']['field_first_name']['hide_alter_empty'] = FALSE;
  /* Field: Field: Last Name */
  $handler->display->display_options['fields']['field_last_name']['id'] = 'field_last_name';
  $handler->display->display_options['fields']['field_last_name']['table'] = 'field_data_field_last_name';
  $handler->display->display_options['fields']['field_last_name']['field'] = 'field_last_name';
  $handler->display->display_options['fields']['field_last_name']['relationship'] = 'field_course_students_uid';
  /* Field: User: Last login */
  $handler->display->display_options['fields']['login']['id'] = 'login';
  $handler->display->display_options['fields']['login']['table'] = 'users';
  $handler->display->display_options['fields']['login']['field'] = 'login';
  $handler->display->display_options['fields']['login']['relationship'] = 'field_course_students_uid';
  $handler->display->display_options['fields']['login']['date_format'] = 'long';
  /* Field: Signup: Signup related to student */
  $handler->display->display_options['fields']['student_signup_node']['id'] = 'student_signup_node';
  $handler->display->display_options['fields']['student_signup_node']['table'] = 's4_signup';
  $handler->display->display_options['fields']['student_signup_node']['field'] = 'student_signup_node';
  $handler->display->display_options['fields']['student_signup_node']['label'] = 'Site';
  /* Field: Assessment: Assessment link */
  $handler->display->display_options['fields']['assessment_link']['id'] = 'assessment_link';
  $handler->display->display_options['fields']['assessment_link']['table'] = 's4_assessment';
  $handler->display->display_options['fields']['assessment_link']['field'] = 'assessment_link';
  $handler->display->display_options['fields']['assessment_link']['label'] = 'Assessment';
  $handler->display->display_options['fields']['assessment_link']['hide_alter_empty'] = FALSE;
  /* Contextual filter: Content: Nid */
  $handler->display->display_options['arguments']['nid']['id'] = 'nid';
  $handler->display->display_options['arguments']['nid']['table'] = 'node';
  $handler->display->display_options['arguments']['nid']['field'] = 'nid';
  $handler->display->display_options['arguments']['nid']['default_action'] = 'default';
  $handler->display->display_options['arguments']['nid']['default_argument_type'] = 'node';
  $handler->display->display_options['arguments']['nid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['nid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['nid']['summary_options']['items_per_page'] = '25';
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 0;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'course' => 'course',
  );

  /* Display: Course students */
  $handler = $view->new_display('block', 'Course students', 'block');
  $handler->display->display_options['defaults']['link_display'] = FALSE;
  $handler->display->display_options['link_url'] = 'node/!1';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['columns'] = array(
    'field_first_name' => 'field_first_name',
    'field_last_name' => 'field_last_name',
    'login' => 'login',
    'student_signup_node' => 'student_signup_node',
  );
  $handler->display->display_options['style_options']['default'] = 'field_last_name';
  $handler->display->display_options['style_options']['info'] = array(
    'field_first_name' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
    ),
    'field_last_name' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
    ),
    'login' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
    ),
    'student_signup_node' => array(
      'align' => '',
      'separator' => '',
    ),
  );
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Bulk operations: User */
  $handler->display->display_options['fields']['views_bulk_operations']['id'] = 'views_bulk_operations';
  $handler->display->display_options['fields']['views_bulk_operations']['table'] = 'users';
  $handler->display->display_options['fields']['views_bulk_operations']['field'] = 'views_bulk_operations';
  $handler->display->display_options['fields']['views_bulk_operations']['relationship'] = 'field_course_students_uid';
  $handler->display->display_options['fields']['views_bulk_operations']['vbo']['entity_load_capacity'] = '10';
  $handler->display->display_options['fields']['views_bulk_operations']['vbo']['operations'] = array(
    'action::system_block_ip_action' => array(
      'selected' => 0,
      'use_queue' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
    'action::user_block_user_action' => array(
      'selected' => 0,
      'use_queue' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
    'action::views_bulk_operations_delete_item' => array(
      'selected' => 0,
      'use_queue' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
    'action::system_message_action' => array(
      'selected' => 0,
      'use_queue' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
    'action::views_bulk_operations_script_action' => array(
      'selected' => 0,
      'use_queue' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
    'action::flag_user_action' => array(
      'selected' => 0,
      'use_queue' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
    'action::views_bulk_operations_user_roles_action' => array(
      'selected' => 0,
      'use_queue' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
    'action::views_bulk_operations_argument_selector_action' => array(
      'selected' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
      'settings' => array(
        'url' => '',
      ),
    ),
    'action::system_goto_action' => array(
      'selected' => 0,
      'use_queue' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
    'action::system_send_email_action' => array(
      'selected' => 0,
      'use_queue' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
    'action::s4_core_email_site_coordinator_action' => array(
      'selected' => 0,
      'use_queue' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
    'action::s4_core_email_user_action' => array(
      'selected' => 0,
      'use_queue' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
    'action::s4_courses_bulk_signup_students_action' => array(
      'selected' => 1,
      'use_queue' => 0,
      'skip_confirmation' => 0,
      'override_label' => 1,
      'label' => 'Signup student',
    ),
  );
  $handler->display->display_options['fields']['views_bulk_operations']['vbo']['enable_select_all_pages'] = 1;
  $handler->display->display_options['fields']['views_bulk_operations']['vbo']['display_type'] = '1';
  $handler->display->display_options['fields']['views_bulk_operations']['vbo']['display_result'] = 1;
  $handler->display->display_options['fields']['views_bulk_operations']['vbo']['force_single'] = 0;
  /* Field: User: Uid */
  $handler->display->display_options['fields']['uid']['id'] = 'uid';
  $handler->display->display_options['fields']['uid']['table'] = 'users';
  $handler->display->display_options['fields']['uid']['field'] = 'uid';
  $handler->display->display_options['fields']['uid']['relationship'] = 'field_course_students_uid';
  $handler->display->display_options['fields']['uid']['exclude'] = TRUE;
  $handler->display->display_options['fields']['uid']['hide_alter_empty'] = FALSE;
  $handler->display->display_options['fields']['uid']['link_to_user'] = FALSE;
  /* Field: Field: First Name */
  $handler->display->display_options['fields']['field_first_name']['id'] = 'field_first_name';
  $handler->display->display_options['fields']['field_first_name']['table'] = 'field_data_field_first_name';
  $handler->display->display_options['fields']['field_first_name']['field'] = 'field_first_name';
  $handler->display->display_options['fields']['field_first_name']['relationship'] = 'field_course_students_uid';
  $handler->display->display_options['fields']['field_first_name']['hide_alter_empty'] = FALSE;
  /* Field: Field: Last Name */
  $handler->display->display_options['fields']['field_last_name']['id'] = 'field_last_name';
  $handler->display->display_options['fields']['field_last_name']['table'] = 'field_data_field_last_name';
  $handler->display->display_options['fields']['field_last_name']['field'] = 'field_last_name';
  $handler->display->display_options['fields']['field_last_name']['relationship'] = 'field_course_students_uid';
  /* Field: User: Last login */
  $handler->display->display_options['fields']['login']['id'] = 'login';
  $handler->display->display_options['fields']['login']['table'] = 'users';
  $handler->display->display_options['fields']['login']['field'] = 'login';
  $handler->display->display_options['fields']['login']['relationship'] = 'field_course_students_uid';
  $handler->display->display_options['fields']['login']['date_format'] = 'long';
  /* Field: Signup: Signup related to student */
  $handler->display->display_options['fields']['student_signup_node']['id'] = 'student_signup_node';
  $handler->display->display_options['fields']['student_signup_node']['table'] = 's4_signup';
  $handler->display->display_options['fields']['student_signup_node']['field'] = 'student_signup_node';
  $handler->display->display_options['fields']['student_signup_node']['label'] = 'Site';
  /* Field: Assessment: Assessment link */
  $handler->display->display_options['fields']['assessment_link']['id'] = 'assessment_link';
  $handler->display->display_options['fields']['assessment_link']['table'] = 's4_assessment';
  $handler->display->display_options['fields']['assessment_link']['field'] = 'assessment_link';
  $handler->display->display_options['fields']['assessment_link']['label'] = 'Assessment';
  $handler->display->display_options['fields']['assessment_link']['hide_alter_empty'] = FALSE;

  /* Display: All faculty students */
  $handler = $view->new_display('block', 'All faculty students', 'block_1');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Search your students';
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '250';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['pager']['options']['id'] = '0';
  $handler->display->display_options['pager']['options']['quantity'] = '9';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['columns'] = array(
    'nid' => 'nid',
    'field_course_catalog_number' => 'field_course_catalog_number',
    'field_course_section' => 'field_course_section',
    'field_course_subject' => 'field_course_subject',
    'field_first_name' => 'field_first_name',
    'field_last_name' => 'field_last_name',
    'login' => 'login',
    'student_signup_node' => 'student_signup_node',
    'evaluation_completed' => 'evaluation_completed',
    'assessment_link' => 'assessment_link',
  );
  $handler->display->display_options['style_options']['default'] = 'field_last_name';
  $handler->display->display_options['style_options']['info'] = array(
    'nid' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_course_catalog_number' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_course_section' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_course_subject' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_first_name' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_last_name' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'login' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'student_signup_node' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'evaluation_completed' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'assessment_link' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
  );
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Nid */
  $handler->display->display_options['fields']['nid']['id'] = 'nid';
  $handler->display->display_options['fields']['nid']['table'] = 'node';
  $handler->display->display_options['fields']['nid']['field'] = 'nid';
  $handler->display->display_options['fields']['nid']['label'] = '';
  $handler->display->display_options['fields']['nid']['exclude'] = TRUE;
  $handler->display->display_options['fields']['nid']['element_label_colon'] = FALSE;
  /* Field: Content: Catalog number */
  $handler->display->display_options['fields']['field_course_catalog_number']['id'] = 'field_course_catalog_number';
  $handler->display->display_options['fields']['field_course_catalog_number']['table'] = 'field_data_field_course_catalog_number';
  $handler->display->display_options['fields']['field_course_catalog_number']['field'] = 'field_course_catalog_number';
  $handler->display->display_options['fields']['field_course_catalog_number']['label'] = '';
  $handler->display->display_options['fields']['field_course_catalog_number']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_course_catalog_number']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_course_catalog_number']['hide_alter_empty'] = FALSE;
  /* Field: Content: Section number */
  $handler->display->display_options['fields']['field_course_section']['id'] = 'field_course_section';
  $handler->display->display_options['fields']['field_course_section']['table'] = 'field_data_field_course_section';
  $handler->display->display_options['fields']['field_course_section']['field'] = 'field_course_section';
  $handler->display->display_options['fields']['field_course_section']['label'] = '';
  $handler->display->display_options['fields']['field_course_section']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_course_section']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_course_section']['hide_alter_empty'] = FALSE;
  $handler->display->display_options['fields']['field_course_section']['settings'] = array(
    'thousand_separator' => ' ',
    'prefix_suffix' => 1,
  );
  /* Field: Content: Subject */
  $handler->display->display_options['fields']['field_course_subject']['id'] = 'field_course_subject';
  $handler->display->display_options['fields']['field_course_subject']['table'] = 'field_data_field_course_subject';
  $handler->display->display_options['fields']['field_course_subject']['field'] = 'field_course_subject';
  $handler->display->display_options['fields']['field_course_subject']['label'] = 'Course';
  $handler->display->display_options['fields']['field_course_subject']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_course_subject']['alter']['text'] = '[field_course_subject-value] [field_course_catalog_number] ([field_course_section])';
  $handler->display->display_options['fields']['field_course_subject']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['field_course_subject']['alter']['path'] = 'node/[nid]';
  $handler->display->display_options['fields']['field_course_subject']['hide_alter_empty'] = FALSE;
  /* Field: Field: First Name */
  $handler->display->display_options['fields']['field_first_name']['id'] = 'field_first_name';
  $handler->display->display_options['fields']['field_first_name']['table'] = 'field_data_field_first_name';
  $handler->display->display_options['fields']['field_first_name']['field'] = 'field_first_name';
  $handler->display->display_options['fields']['field_first_name']['relationship'] = 'field_course_students_uid';
  /* Field: Field: Last Name */
  $handler->display->display_options['fields']['field_last_name']['id'] = 'field_last_name';
  $handler->display->display_options['fields']['field_last_name']['table'] = 'field_data_field_last_name';
  $handler->display->display_options['fields']['field_last_name']['field'] = 'field_last_name';
  $handler->display->display_options['fields']['field_last_name']['relationship'] = 'field_course_students_uid';
  /* Field: User: Last login */
  $handler->display->display_options['fields']['login']['id'] = 'login';
  $handler->display->display_options['fields']['login']['table'] = 'users';
  $handler->display->display_options['fields']['login']['field'] = 'login';
  $handler->display->display_options['fields']['login']['relationship'] = 'field_course_students_uid';
  $handler->display->display_options['fields']['login']['date_format'] = 'long';
  /* Field: Signup: Signup related to student */
  $handler->display->display_options['fields']['student_signup_node']['id'] = 'student_signup_node';
  $handler->display->display_options['fields']['student_signup_node']['table'] = 's4_signup';
  $handler->display->display_options['fields']['student_signup_node']['field'] = 'student_signup_node';
  $handler->display->display_options['fields']['student_signup_node']['label'] = 'Site';
  $handler->display->display_options['fields']['student_signup_node']['hide_alter_empty'] = FALSE;
  /* Field: Site Data: Evaluation completed */
  $handler->display->display_options['fields']['evaluation_completed']['id'] = 'evaluation_completed';
  $handler->display->display_options['fields']['evaluation_completed']['table'] = 's4_sites';
  $handler->display->display_options['fields']['evaluation_completed']['field'] = 'evaluation_completed';
  $handler->display->display_options['fields']['evaluation_completed']['label'] = 'Evaluation status';
  /* Field: Assessment: Assessment link */
  $handler->display->display_options['fields']['assessment_link']['id'] = 'assessment_link';
  $handler->display->display_options['fields']['assessment_link']['table'] = 's4_assessment';
  $handler->display->display_options['fields']['assessment_link']['field'] = 'assessment_link';
  $handler->display->display_options['fields']['assessment_link']['label'] = 'Complete assessment';
  $handler->display->display_options['fields']['assessment_link']['hide_alter_empty'] = FALSE;
  $handler->display->display_options['defaults']['sorts'] = FALSE;
  /* Sort criterion: Content: Post date */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'node';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Contextual filter: Content: Faculty (field_course_faculty) */
  $handler->display->display_options['arguments']['field_course_faculty_uid']['id'] = 'field_course_faculty_uid';
  $handler->display->display_options['arguments']['field_course_faculty_uid']['table'] = 'field_data_field_course_faculty';
  $handler->display->display_options['arguments']['field_course_faculty_uid']['field'] = 'field_course_faculty_uid';
  $handler->display->display_options['arguments']['field_course_faculty_uid']['default_action'] = 'default';
  $handler->display->display_options['arguments']['field_course_faculty_uid']['default_argument_type'] = 'current_user';
  $handler->display->display_options['arguments']['field_course_faculty_uid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['field_course_faculty_uid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['field_course_faculty_uid']['summary_options']['items_per_page'] = '25';

  /* Display: Course faculty */
  $handler = $view->new_display('block', 'Course faculty', 'block_2');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Faculty';
  $handler->display->display_options['defaults']['css_class'] = FALSE;
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'list';
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['relationships'] = FALSE;
  /* Relationship: Content: Faculty (field_course_faculty) */
  $handler->display->display_options['relationships']['field_course_faculty_uid']['id'] = 'field_course_faculty_uid';
  $handler->display->display_options['relationships']['field_course_faculty_uid']['table'] = 'field_data_field_course_faculty';
  $handler->display->display_options['relationships']['field_course_faculty_uid']['field'] = 'field_course_faculty_uid';
  $handler->display->display_options['relationships']['field_course_faculty_uid']['delta'] = '-1';
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Field: First Name */
  $handler->display->display_options['fields']['field_first_name']['id'] = 'field_first_name';
  $handler->display->display_options['fields']['field_first_name']['table'] = 'field_data_field_first_name';
  $handler->display->display_options['fields']['field_first_name']['field'] = 'field_first_name';
  $handler->display->display_options['fields']['field_first_name']['relationship'] = 'field_course_faculty_uid';
  $handler->display->display_options['fields']['field_first_name']['label'] = '';
  $handler->display->display_options['fields']['field_first_name']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_first_name']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_first_name']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_first_name']['hide_empty'] = TRUE;
  $handler->display->display_options['fields']['field_first_name']['hide_alter_empty'] = FALSE;
  /* Field: Field: Last Name */
  $handler->display->display_options['fields']['field_last_name']['id'] = 'field_last_name';
  $handler->display->display_options['fields']['field_last_name']['table'] = 'field_data_field_last_name';
  $handler->display->display_options['fields']['field_last_name']['field'] = 'field_last_name';
  $handler->display->display_options['fields']['field_last_name']['relationship'] = 'field_course_faculty_uid';
  $handler->display->display_options['fields']['field_last_name']['label'] = '';
  $handler->display->display_options['fields']['field_last_name']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_last_name']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_last_name']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_last_name']['hide_alter_empty'] = FALSE;
  /* Field: User: Uid */
  $handler->display->display_options['fields']['uid']['id'] = 'uid';
  $handler->display->display_options['fields']['uid']['table'] = 'users';
  $handler->display->display_options['fields']['uid']['field'] = 'uid';
  $handler->display->display_options['fields']['uid']['relationship'] = 'field_course_faculty_uid';
  $handler->display->display_options['fields']['uid']['label'] = '';
  $handler->display->display_options['fields']['uid']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['uid']['alter']['text'] = '[field_first_name] [field_last_name]';
  $handler->display->display_options['fields']['uid']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['uid']['alter']['path'] = 'user/[uid]';
  $handler->display->display_options['fields']['uid']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['uid']['hide_alter_empty'] = FALSE;

  /* Display: Course students (Staff view) */
  $handler = $view->new_display('block', 'Course students (Staff view)', 'block_3');
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['columns'] = array(
    'field_first_name' => 'field_first_name',
    'field_last_name' => 'field_last_name',
    'login' => 'login',
    'student_signup_node' => 'student_signup_node',
  );
  $handler->display->display_options['style_options']['default'] = 'field_last_name';
  $handler->display->display_options['style_options']['info'] = array(
    'field_first_name' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
    ),
    'field_last_name' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
    ),
    'login' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
    ),
    'student_signup_node' => array(
      'align' => '',
      'separator' => '',
    ),
  );
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Bulk operations: User */
  $handler->display->display_options['fields']['views_bulk_operations']['id'] = 'views_bulk_operations';
  $handler->display->display_options['fields']['views_bulk_operations']['table'] = 'users';
  $handler->display->display_options['fields']['views_bulk_operations']['field'] = 'views_bulk_operations';
  $handler->display->display_options['fields']['views_bulk_operations']['relationship'] = 'field_course_students_uid';
  $handler->display->display_options['fields']['views_bulk_operations']['label'] = '';
  $handler->display->display_options['fields']['views_bulk_operations']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['views_bulk_operations']['vbo']['entity_load_capacity'] = '10';
  $handler->display->display_options['fields']['views_bulk_operations']['vbo']['operations'] = array(
    'action::system_block_ip_action' => array(
      'selected' => 0,
      'use_queue' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
    'action::user_block_user_action' => array(
      'selected' => 0,
      'use_queue' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
    'action::views_bulk_operations_delete_item' => array(
      'selected' => 0,
      'use_queue' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
    'action::system_message_action' => array(
      'selected' => 0,
      'use_queue' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
    'action::views_bulk_operations_script_action' => array(
      'selected' => 0,
      'use_queue' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
    'action::flag_user_action' => array(
      'selected' => 0,
      'use_queue' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
    'action::views_bulk_operations_user_roles_action' => array(
      'selected' => 0,
      'use_queue' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
    'action::views_bulk_operations_argument_selector_action' => array(
      'selected' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
      'settings' => array(
        'url' => '',
      ),
    ),
    'action::system_goto_action' => array(
      'selected' => 0,
      'use_queue' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
    'action::system_send_email_action' => array(
      'selected' => 0,
      'use_queue' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
    'action::s4_core_email_site_coordinator_action' => array(
      'selected' => 0,
      'use_queue' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
    'action::s4_core_email_user_action' => array(
      'selected' => 0,
      'use_queue' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
    'action::s4_courses_bulk_signup_students_action' => array(
      'selected' => 1,
      'use_queue' => 0,
      'skip_confirmation' => 0,
      'override_label' => 1,
      'label' => 'Signup students',
    ),
  );
  $handler->display->display_options['fields']['views_bulk_operations']['vbo']['enable_select_all_pages'] = 1;
  $handler->display->display_options['fields']['views_bulk_operations']['vbo']['display_type'] = '1';
  $handler->display->display_options['fields']['views_bulk_operations']['vbo']['display_result'] = 1;
  $handler->display->display_options['fields']['views_bulk_operations']['vbo']['force_single'] = 0;
  /* Field: Field: First Name */
  $handler->display->display_options['fields']['field_first_name']['id'] = 'field_first_name';
  $handler->display->display_options['fields']['field_first_name']['table'] = 'field_data_field_first_name';
  $handler->display->display_options['fields']['field_first_name']['field'] = 'field_first_name';
  $handler->display->display_options['fields']['field_first_name']['relationship'] = 'field_course_students_uid';
  $handler->display->display_options['fields']['field_first_name']['hide_alter_empty'] = FALSE;
  /* Field: Field: Last Name */
  $handler->display->display_options['fields']['field_last_name']['id'] = 'field_last_name';
  $handler->display->display_options['fields']['field_last_name']['table'] = 'field_data_field_last_name';
  $handler->display->display_options['fields']['field_last_name']['field'] = 'field_last_name';
  $handler->display->display_options['fields']['field_last_name']['relationship'] = 'field_course_students_uid';
  /* Field: User: Last login */
  $handler->display->display_options['fields']['login']['id'] = 'login';
  $handler->display->display_options['fields']['login']['table'] = 'users';
  $handler->display->display_options['fields']['login']['field'] = 'login';
  $handler->display->display_options['fields']['login']['relationship'] = 'field_course_students_uid';
  $handler->display->display_options['fields']['login']['date_format'] = 'long';
  /* Field: Signup: Signup related to student */
  $handler->display->display_options['fields']['student_signup_node']['id'] = 'student_signup_node';
  $handler->display->display_options['fields']['student_signup_node']['table'] = 's4_signup';
  $handler->display->display_options['fields']['student_signup_node']['field'] = 'student_signup_node';
  $handler->display->display_options['fields']['student_signup_node']['label'] = 'Site';
  /* Field: User: Uid */
  $handler->display->display_options['fields']['uid']['id'] = 'uid';
  $handler->display->display_options['fields']['uid']['table'] = 'users';
  $handler->display->display_options['fields']['uid']['field'] = 'uid';
  $handler->display->display_options['fields']['uid']['relationship'] = 'field_course_students_uid';
  $handler->display->display_options['fields']['uid']['label'] = 'Signup student';
  $handler->display->display_options['fields']['uid']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['uid']['alter']['text'] = 'Signup student';
  $handler->display->display_options['fields']['uid']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['uid']['alter']['path'] = 'signup/create/[uid]';
  $handler->display->display_options['fields']['uid']['hide_alter_empty'] = FALSE;
  $handler->display->display_options['fields']['uid']['link_to_user'] = FALSE;
  $translatables['course_students'] = array(
    t('Master'),
    t('Course students'),
    t('more'),
    t('Apply'),
    t('Reset'),
    t('Sort by'),
    t('Asc'),
    t('Desc'),
    t('field_course_students'),
    t('Uid'),
    t('First Name'),
    t('Last Name'),
    t('Last login'),
    t('Site'),
    t('Assessment'),
    t('All'),
    t('User'),
    t('All faculty students'),
    t('Search your students'),
    t('Items per page'),
    t('- All -'),
    t('Offset'),
    t('« first'),
    t('‹ previous'),
    t('next ›'),
    t('last »'),
    t('Course'),
    t('[field_course_subject-value] [field_course_catalog_number] ([field_course_section])'),
    t('node/[nid]'),
    t('Evaluation status'),
    t('Complete assessment'),
    t('Course faculty'),
    t('Faculty'),
    t('field_course_faculty'),
    t('[field_first_name] [field_last_name]'),
    t('user/[uid]'),
    t('Course students (Staff view)'),
    t('Signup student'),
    t('signup/create/[uid]'),
  );
  $export['course_students'] = $view;

  $view = new view();
  $view->name = 'terms';
  $view->description = 'A listing of terms for courses';
  $view->tag = 'course';
  $view->base_table = 'node';
  $view->human_name = 'Course Terms';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Current Terms';
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['access']['perm'] = 'signup for service';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['query']['options']['query_comment'] = FALSE;
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '20';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['pager']['options']['id'] = '0';
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['columns'] = array(
    'title' => 'title',
  );
  $handler->display->display_options['style_options']['default'] = '-1';
  $handler->display->display_options['style_options']['info'] = array(
    'title' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
    ),
  );
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = 'Term';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  /* Field: Content: Term Code */
  $handler->display->display_options['fields']['field_term_code']['id'] = 'field_term_code';
  $handler->display->display_options['fields']['field_term_code']['table'] = 'field_data_field_term_code';
  $handler->display->display_options['fields']['field_term_code']['field'] = 'field_term_code';
  /* Field: Content: Term dates */
  $handler->display->display_options['fields']['field_term_date_start']['id'] = 'field_term_date_start';
  $handler->display->display_options['fields']['field_term_date_start']['table'] = 'field_data_field_term_date_start';
  $handler->display->display_options['fields']['field_term_date_start']['field'] = 'field_term_date_start';
  $handler->display->display_options['fields']['field_term_date_start']['label'] = 'Start Date';
  $handler->display->display_options['fields']['field_term_date_start']['settings'] = array(
    'format_type' => 'medium',
    'fromto' => 'value',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
    'show_repeat_rule' => 'show',
  );
  /* Field: Content: Term dates */
  $handler->display->display_options['fields']['field_term_date_start_1']['id'] = 'field_term_date_start_1';
  $handler->display->display_options['fields']['field_term_date_start_1']['table'] = 'field_data_field_term_date_start';
  $handler->display->display_options['fields']['field_term_date_start_1']['field'] = 'field_term_date_start';
  $handler->display->display_options['fields']['field_term_date_start_1']['label'] = 'End date';
  $handler->display->display_options['fields']['field_term_date_start_1']['settings'] = array(
    'format_type' => 'long',
    'fromto' => 'value2',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
    'show_repeat_rule' => 'show',
  );
  /* Sort criterion: Content: Term dates (field_term_date_start) */
  $handler->display->display_options['sorts']['field_term_date_start_value']['id'] = 'field_term_date_start_value';
  $handler->display->display_options['sorts']['field_term_date_start_value']['table'] = 'field_data_field_term_date_start';
  $handler->display->display_options['sorts']['field_term_date_start_value']['field'] = 'field_term_date_start_value';
  $handler->display->display_options['sorts']['field_term_date_start_value']['order'] = 'DESC';
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 0;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'course_term' => 'course_term',
  );

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Course terms';
  $handler->display->display_options['defaults']['header'] = FALSE;
  /* Header: Global: Text area */
  $handler->display->display_options['header']['area']['id'] = 'area';
  $handler->display->display_options['header']['area']['table'] = 'views';
  $handler->display->display_options['header']['area']['field'] = 'area';
  $handler->display->display_options['header']['area']['empty'] = TRUE;
  $handler->display->display_options['header']['area']['content'] = '<a class="button" href="node/add/course-term">Add new term</a>';
  $handler->display->display_options['header']['area']['format'] = 'full_html';
  $handler->display->display_options['path'] = 'terms';

  /* Display: Term list */
  $handler = $view->new_display('block', 'Term list', 'block');
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '5';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['footer'] = FALSE;
  /* Footer: Global: Text area */
  $handler->display->display_options['footer']['area']['id'] = 'area';
  $handler->display->display_options['footer']['area']['table'] = 'views';
  $handler->display->display_options['footer']['area']['field'] = 'area';
  $handler->display->display_options['footer']['area']['empty'] = TRUE;
  $handler->display->display_options['footer']['area']['content'] = '<a class="button" href="terms">View all terms</a><br/>
<a class="button" href="node/add/course-term">Add new term</a>';
  $handler->display->display_options['footer']['area']['format'] = 'full_html';
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['title']['element_type'] = 'h4';
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 0;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'course_term' => 'course_term',
  );
  /* Filter criterion: Content: Term dates (field_term_date_start) */
  $handler->display->display_options['filters']['field_term_date_start_value']['id'] = 'field_term_date_start_value';
  $handler->display->display_options['filters']['field_term_date_start_value']['table'] = 'field_data_field_term_date_start';
  $handler->display->display_options['filters']['field_term_date_start_value']['field'] = 'field_term_date_start_value';
  $handler->display->display_options['filters']['field_term_date_start_value']['operator'] = '<=';
  $handler->display->display_options['filters']['field_term_date_start_value']['granularity'] = 'day';
  $handler->display->display_options['filters']['field_term_date_start_value']['form_type'] = 'date_select';
  $handler->display->display_options['filters']['field_term_date_start_value']['default_date'] = 'now';
  $handler->display->display_options['filters']['field_term_date_start_value']['default_to_date'] = '';
  $handler->display->display_options['filters']['field_term_date_start_value']['year_range'] = '-3:+3';
  /* Filter criterion: Content: Term dates (field_term_date_start:value2) */
  $handler->display->display_options['filters']['field_term_date_start_value2']['id'] = 'field_term_date_start_value2';
  $handler->display->display_options['filters']['field_term_date_start_value2']['table'] = 'field_data_field_term_date_start';
  $handler->display->display_options['filters']['field_term_date_start_value2']['field'] = 'field_term_date_start_value2';
  $handler->display->display_options['filters']['field_term_date_start_value2']['operator'] = '>=';
  $handler->display->display_options['filters']['field_term_date_start_value2']['granularity'] = 'day';
  $handler->display->display_options['filters']['field_term_date_start_value2']['form_type'] = 'date_select';
  $handler->display->display_options['filters']['field_term_date_start_value2']['default_date'] = 'now + 1 day';
  $handler->display->display_options['filters']['field_term_date_start_value2']['default_to_date'] = '';
  $handler->display->display_options['filters']['field_term_date_start_value2']['year_range'] = '-3:+3';

  /* Display: Student Term list */
  $handler = $view->new_display('block', 'Student Term list', 'block_1');
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '5';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['footer'] = FALSE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['title']['element_type'] = 'h4';
  $handler->display->display_options['fields']['title']['link_to_node'] = FALSE;
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 0;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'course_term' => 'course_term',
  );
  $translatables['terms'] = array(
    t('Master'),
    t('Current Terms'),
    t('more'),
    t('Apply'),
    t('Reset'),
    t('Sort by'),
    t('Asc'),
    t('Desc'),
    t('Items per page'),
    t('- All -'),
    t('Offset'),
    t('« first'),
    t('‹ previous'),
    t('next ›'),
    t('last »'),
    t('Term'),
    t('Term Code'),
    t('Start Date'),
    t('End date'),
    t('Page'),
    t('Course terms'),
    t('<a class="button" href="node/add/course-term">Add new term</a>'),
    t('Term list'),
    t('<a class="button" href="terms">View all terms</a><br/>
<a class="button" href="node/add/course-term">Add new term</a>'),
    t('Student Term list'),
  );
  $export['terms'] = $view;

  $view = new view();
  $view->name = 'user_courses';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Courses';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Sign up for service';
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['access']['perm'] = 'signup for service';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['query']['options']['distinct'] = TRUE;
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '30';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['pager']['options']['id'] = '0';
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['columns'] = array(
    'title' => 'title',
  );
  $handler->display->display_options['style_options']['default'] = '-1';
  $handler->display->display_options['style_options']['info'] = array(
    'title' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
    ),
  );
  /* No results behavior: Global: Text area */
  $handler->display->display_options['empty']['area']['id'] = 'area';
  $handler->display->display_options['empty']['area']['table'] = 'views';
  $handler->display->display_options['empty']['area']['field'] = 'area';
  $handler->display->display_options['empty']['area']['label'] = 'No courses';
  $handler->display->display_options['empty']['area']['empty'] = FALSE;
  $handler->display->display_options['empty']['area']['content'] = '<p class="intro">It looks like you don\'t have any courses this semester.</p><p><strong>Don\'t panic:</strong> if you just registered for a course, it might be taking a while for your registration to get to our system. Also, in some situations we don\'t bring over courses unless they have a service learning, internship, or other training component. Check with your faculty if you think your course should show up here.</p>';
  $handler->display->display_options['empty']['area']['format'] = 'full_html';
  /* Relationship: Content: Term (field_term) */
  $handler->display->display_options['relationships']['field_term_nid']['id'] = 'field_term_nid';
  $handler->display->display_options['relationships']['field_term_nid']['table'] = 'field_data_field_term';
  $handler->display->display_options['relationships']['field_term_nid']['field'] = 'field_term_nid';
  $handler->display->display_options['relationships']['field_term_nid']['delta'] = '-1';
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title_1']['id'] = 'title_1';
  $handler->display->display_options['fields']['title_1']['table'] = 'node';
  $handler->display->display_options['fields']['title_1']['field'] = 'title';
  $handler->display->display_options['fields']['title_1']['relationship'] = 'field_term_nid';
  $handler->display->display_options['fields']['title_1']['label'] = '';
  $handler->display->display_options['fields']['title_1']['exclude'] = TRUE;
  $handler->display->display_options['fields']['title_1']['link_to_node'] = FALSE;
  /* Sort criterion: Content: Post date */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'node';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
  /* Contextual filter: Content: Faculty (field_course_faculty) */
  $handler->display->display_options['arguments']['field_course_faculty_uid']['id'] = 'field_course_faculty_uid';
  $handler->display->display_options['arguments']['field_course_faculty_uid']['table'] = 'field_data_field_course_faculty';
  $handler->display->display_options['arguments']['field_course_faculty_uid']['field'] = 'field_course_faculty_uid';
  $handler->display->display_options['arguments']['field_course_faculty_uid']['default_action'] = 'default';
  $handler->display->display_options['arguments']['field_course_faculty_uid']['default_argument_type'] = 'current_user';
  $handler->display->display_options['arguments']['field_course_faculty_uid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['field_course_faculty_uid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['field_course_faculty_uid']['summary_options']['items_per_page'] = '25';
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 0;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'course' => 'course',
  );
  /* Filter criterion: Content: Term dates (field_term_date_start) */
  $handler->display->display_options['filters']['field_term_date_start_value']['id'] = 'field_term_date_start_value';
  $handler->display->display_options['filters']['field_term_date_start_value']['table'] = 'field_data_field_term_date_start';
  $handler->display->display_options['filters']['field_term_date_start_value']['field'] = 'field_term_date_start_value';
  $handler->display->display_options['filters']['field_term_date_start_value']['relationship'] = 'field_term_nid';
  $handler->display->display_options['filters']['field_term_date_start_value']['operator'] = '<=';
  $handler->display->display_options['filters']['field_term_date_start_value']['granularity'] = 'day';
  $handler->display->display_options['filters']['field_term_date_start_value']['form_type'] = 'date_select';
  $handler->display->display_options['filters']['field_term_date_start_value']['default_date'] = 'now';
  $handler->display->display_options['filters']['field_term_date_start_value']['default_to_date'] = '';
  $handler->display->display_options['filters']['field_term_date_start_value']['year_range'] = '-3:+3';
  /* Filter criterion: Content: Term dates (field_term_date_start:value2) */
  $handler->display->display_options['filters']['field_term_date_start_value2']['id'] = 'field_term_date_start_value2';
  $handler->display->display_options['filters']['field_term_date_start_value2']['table'] = 'field_data_field_term_date_start';
  $handler->display->display_options['filters']['field_term_date_start_value2']['field'] = 'field_term_date_start_value2';
  $handler->display->display_options['filters']['field_term_date_start_value2']['relationship'] = 'field_term_nid';
  $handler->display->display_options['filters']['field_term_date_start_value2']['operator'] = '>=';
  $handler->display->display_options['filters']['field_term_date_start_value2']['granularity'] = 'day';
  $handler->display->display_options['filters']['field_term_date_start_value2']['form_type'] = 'date_select';
  $handler->display->display_options['filters']['field_term_date_start_value2']['default_date'] = 'now';
  $handler->display->display_options['filters']['field_term_date_start_value2']['default_to_date'] = '';
  $handler->display->display_options['filters']['field_term_date_start_value2']['year_range'] = '-3:+3';

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page');
  $handler->display->display_options['path'] = 'user-courses';

  /* Display: Faculty Course List */
  $handler = $view->new_display('block', 'Faculty Course List', 'block');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Manage your courses';
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '5';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['style_options']['grouping'] = 'title_1';
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['empty'] = FALSE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['title']['element_type'] = 'strong';
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title']['hide_alter_empty'] = FALSE;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title_1']['id'] = 'title_1';
  $handler->display->display_options['fields']['title_1']['table'] = 'node';
  $handler->display->display_options['fields']['title_1']['field'] = 'title';
  $handler->display->display_options['fields']['title_1']['relationship'] = 'field_term_nid';
  $handler->display->display_options['fields']['title_1']['label'] = '';
  $handler->display->display_options['fields']['title_1']['exclude'] = TRUE;
  $handler->display->display_options['fields']['title_1']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title_1']['hide_alter_empty'] = FALSE;
  $handler->display->display_options['fields']['title_1']['link_to_node'] = FALSE;
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 0;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'course' => 'course',
  );
  /* Filter criterion: Content: Term dates (field_term_date_start) */
  $handler->display->display_options['filters']['field_term_date_start_value']['id'] = 'field_term_date_start_value';
  $handler->display->display_options['filters']['field_term_date_start_value']['table'] = 'field_data_field_term_date_start';
  $handler->display->display_options['filters']['field_term_date_start_value']['field'] = 'field_term_date_start_value';
  $handler->display->display_options['filters']['field_term_date_start_value']['relationship'] = 'field_term_nid';
  $handler->display->display_options['filters']['field_term_date_start_value']['operator'] = '<=';
  $handler->display->display_options['filters']['field_term_date_start_value']['granularity'] = 'day';
  $handler->display->display_options['filters']['field_term_date_start_value']['form_type'] = 'date_select';
  $handler->display->display_options['filters']['field_term_date_start_value']['default_date'] = 'now';
  $handler->display->display_options['filters']['field_term_date_start_value']['default_to_date'] = '';
  $handler->display->display_options['filters']['field_term_date_start_value']['year_range'] = '-3:+3';
  /* Filter criterion: Content: Term dates (field_term_date_start:value2) */
  $handler->display->display_options['filters']['field_term_date_start_value2']['id'] = 'field_term_date_start_value2';
  $handler->display->display_options['filters']['field_term_date_start_value2']['table'] = 'field_data_field_term_date_start';
  $handler->display->display_options['filters']['field_term_date_start_value2']['field'] = 'field_term_date_start_value2';
  $handler->display->display_options['filters']['field_term_date_start_value2']['relationship'] = 'field_term_nid';
  $handler->display->display_options['filters']['field_term_date_start_value2']['operator'] = '>=';
  $handler->display->display_options['filters']['field_term_date_start_value2']['granularity'] = 'day';
  $handler->display->display_options['filters']['field_term_date_start_value2']['form_type'] = 'date_select';
  $handler->display->display_options['filters']['field_term_date_start_value2']['default_date'] = 'now';
  $handler->display->display_options['filters']['field_term_date_start_value2']['default_to_date'] = '';
  $handler->display->display_options['filters']['field_term_date_start_value2']['year_range'] = '-3:+3';

  /* Display: Staff course listing */
  $handler = $view->new_display('page', 'Staff course listing', 'page_1');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Courses';
  $handler->display->display_options['defaults']['access'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['access']['perm'] = 'create course content';
  $handler->display->display_options['defaults']['relationships'] = FALSE;
  /* Relationship: Content: Faculty (field_course_faculty) */
  $handler->display->display_options['relationships']['field_course_faculty_uid']['id'] = 'field_course_faculty_uid';
  $handler->display->display_options['relationships']['field_course_faculty_uid']['table'] = 'field_data_field_course_faculty';
  $handler->display->display_options['relationships']['field_course_faculty_uid']['field'] = 'field_course_faculty_uid';
  /* Relationship: Content: Term (field_term) */
  $handler->display->display_options['relationships']['field_term_nid']['id'] = 'field_term_nid';
  $handler->display->display_options['relationships']['field_term_nid']['table'] = 'field_data_field_term';
  $handler->display->display_options['relationships']['field_term_nid']['field'] = 'field_term_nid';
  $handler->display->display_options['relationships']['field_term_nid']['delta'] = '-1';
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Nid */
  $handler->display->display_options['fields']['nid']['id'] = 'nid';
  $handler->display->display_options['fields']['nid']['table'] = 'node';
  $handler->display->display_options['fields']['nid']['field'] = 'nid';
  $handler->display->display_options['fields']['nid']['label'] = 'View';
  $handler->display->display_options['fields']['nid']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['nid']['alter']['text'] = 'View';
  $handler->display->display_options['fields']['nid']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['nid']['alter']['path'] = 'node/[nid]';
  /* Field: Content: Subject */
  $handler->display->display_options['fields']['field_course_subject']['id'] = 'field_course_subject';
  $handler->display->display_options['fields']['field_course_subject']['table'] = 'field_data_field_course_subject';
  $handler->display->display_options['fields']['field_course_subject']['field'] = 'field_course_subject';
  /* Field: Content: Catalog number */
  $handler->display->display_options['fields']['field_course_catalog_number']['id'] = 'field_course_catalog_number';
  $handler->display->display_options['fields']['field_course_catalog_number']['table'] = 'field_data_field_course_catalog_number';
  $handler->display->display_options['fields']['field_course_catalog_number']['field'] = 'field_course_catalog_number';
  $handler->display->display_options['fields']['field_course_catalog_number']['label'] = 'Number';
  /* Field: Content: Section number */
  $handler->display->display_options['fields']['field_course_section']['id'] = 'field_course_section';
  $handler->display->display_options['fields']['field_course_section']['table'] = 'field_data_field_course_section';
  $handler->display->display_options['fields']['field_course_section']['field'] = 'field_course_section';
  $handler->display->display_options['fields']['field_course_section']['label'] = 'Section';
  $handler->display->display_options['fields']['field_course_section']['settings'] = array(
    'thousand_separator' => ' ',
    'prefix_suffix' => 1,
  );
  /* Field: Content: Course title */
  $handler->display->display_options['fields']['field_course_title']['id'] = 'field_course_title';
  $handler->display->display_options['fields']['field_course_title']['table'] = 'field_data_field_course_title';
  $handler->display->display_options['fields']['field_course_title']['field'] = 'field_course_title';
  $handler->display->display_options['fields']['field_course_title']['label'] = 'Title';
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title_1']['id'] = 'title_1';
  $handler->display->display_options['fields']['title_1']['table'] = 'node';
  $handler->display->display_options['fields']['title_1']['field'] = 'title';
  $handler->display->display_options['fields']['title_1']['relationship'] = 'field_term_nid';
  $handler->display->display_options['fields']['title_1']['label'] = 'Term';
  $handler->display->display_options['fields']['title_1']['link_to_node'] = FALSE;
  /* Field: Field: Program */
  $handler->display->display_options['fields']['field_site_restrict']['id'] = 'field_site_restrict';
  $handler->display->display_options['fields']['field_site_restrict']['table'] = 'field_data_field_site_restrict';
  $handler->display->display_options['fields']['field_site_restrict']['field'] = 'field_site_restrict';
  $handler->display->display_options['fields']['field_site_restrict']['label'] = 'Programs';
  $handler->display->display_options['fields']['field_site_restrict']['type'] = 'taxonomy_term_reference_plain';
  $handler->display->display_options['fields']['field_site_restrict']['delta_offset'] = '0';
  /* Field: Field: Last Name */
  $handler->display->display_options['fields']['field_last_name']['id'] = 'field_last_name';
  $handler->display->display_options['fields']['field_last_name']['table'] = 'field_data_field_last_name';
  $handler->display->display_options['fields']['field_last_name']['field'] = 'field_last_name';
  $handler->display->display_options['fields']['field_last_name']['relationship'] = 'field_course_faculty_uid';
  $handler->display->display_options['fields']['field_last_name']['exclude'] = TRUE;
  /* Field: Field: First Name */
  $handler->display->display_options['fields']['field_first_name']['id'] = 'field_first_name';
  $handler->display->display_options['fields']['field_first_name']['table'] = 'field_data_field_first_name';
  $handler->display->display_options['fields']['field_first_name']['field'] = 'field_first_name';
  $handler->display->display_options['fields']['field_first_name']['relationship'] = 'field_course_faculty_uid';
  $handler->display->display_options['fields']['field_first_name']['label'] = 'Faculty';
  $handler->display->display_options['fields']['field_first_name']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_first_name']['alter']['text'] = '[field_last_name], [field_first_name]';
  /* Field: Content: Students */
  $handler->display->display_options['fields']['field_course_students']['id'] = 'field_course_students';
  $handler->display->display_options['fields']['field_course_students']['table'] = 'field_data_field_course_students';
  $handler->display->display_options['fields']['field_course_students']['field'] = 'field_course_students';
  $handler->display->display_options['fields']['field_course_students']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_course_students']['hide_alter_empty'] = FALSE;
  $handler->display->display_options['fields']['field_course_students']['delta_offset'] = '0';
  /* Field: Course: Total course enrollment */
  $handler->display->display_options['fields']['course_student_enrollment']['id'] = 'course_student_enrollment';
  $handler->display->display_options['fields']['course_student_enrollment']['table'] = 's4_course';
  $handler->display->display_options['fields']['course_student_enrollment']['field'] = 'course_student_enrollment';
  $handler->display->display_options['fields']['course_student_enrollment']['label'] = 'Enrollment';
  $handler->display->display_options['fields']['course_student_enrollment']['hide_alter_empty'] = FALSE;
  /* Field: Content: Edit link */
  $handler->display->display_options['fields']['edit_node']['id'] = 'edit_node';
  $handler->display->display_options['fields']['edit_node']['table'] = 'views_entity_node';
  $handler->display->display_options['fields']['edit_node']['field'] = 'edit_node';
  $handler->display->display_options['fields']['edit_node']['label'] = 'Edit';
  $handler->display->display_options['defaults']['sorts'] = FALSE;
  /* Sort criterion: Content: Subject (field_course_subject) */
  $handler->display->display_options['sorts']['field_course_subject_value']['id'] = 'field_course_subject_value';
  $handler->display->display_options['sorts']['field_course_subject_value']['table'] = 'field_data_field_course_subject';
  $handler->display->display_options['sorts']['field_course_subject_value']['field'] = 'field_course_subject_value';
  /* Sort criterion: Content: Catalog number (field_course_catalog_number) */
  $handler->display->display_options['sorts']['field_course_catalog_number_value']['id'] = 'field_course_catalog_number_value';
  $handler->display->display_options['sorts']['field_course_catalog_number_value']['table'] = 'field_data_field_course_catalog_number';
  $handler->display->display_options['sorts']['field_course_catalog_number_value']['field'] = 'field_course_catalog_number_value';
  /* Sort criterion: Content: Section number (field_course_section) */
  $handler->display->display_options['sorts']['field_course_section_value']['id'] = 'field_course_section_value';
  $handler->display->display_options['sorts']['field_course_section_value']['table'] = 'field_data_field_course_section';
  $handler->display->display_options['sorts']['field_course_section_value']['field'] = 'field_course_section_value';
  /* Sort criterion: Content: Post date */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'node';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 0;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'course' => 'course',
  );
  $handler->display->display_options['filters']['type']['group'] = 0;
  /* Filter criterion: Content: Subject (field_course_subject) */
  $handler->display->display_options['filters']['field_course_subject_value']['id'] = 'field_course_subject_value';
  $handler->display->display_options['filters']['field_course_subject_value']['table'] = 'field_data_field_course_subject';
  $handler->display->display_options['filters']['field_course_subject_value']['field'] = 'field_course_subject_value';
  $handler->display->display_options['filters']['field_course_subject_value']['operator'] = 'contains';
  $handler->display->display_options['filters']['field_course_subject_value']['group'] = 0;
  $handler->display->display_options['filters']['field_course_subject_value']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_course_subject_value']['expose']['operator_id'] = 'field_course_subject_value_op';
  $handler->display->display_options['filters']['field_course_subject_value']['expose']['label'] = 'Subject';
  $handler->display->display_options['filters']['field_course_subject_value']['expose']['operator'] = 'field_course_subject_value_op';
  $handler->display->display_options['filters']['field_course_subject_value']['expose']['identifier'] = 'field_course_subject_value';
  /* Filter criterion: Content: Catalog number (field_course_catalog_number) */
  $handler->display->display_options['filters']['field_course_catalog_number_value']['id'] = 'field_course_catalog_number_value';
  $handler->display->display_options['filters']['field_course_catalog_number_value']['table'] = 'field_data_field_course_catalog_number';
  $handler->display->display_options['filters']['field_course_catalog_number_value']['field'] = 'field_course_catalog_number_value';
  $handler->display->display_options['filters']['field_course_catalog_number_value']['operator'] = 'contains';
  $handler->display->display_options['filters']['field_course_catalog_number_value']['group'] = 0;
  $handler->display->display_options['filters']['field_course_catalog_number_value']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_course_catalog_number_value']['expose']['operator_id'] = 'field_course_catalog_number_value_op';
  $handler->display->display_options['filters']['field_course_catalog_number_value']['expose']['label'] = 'Catalog number';
  $handler->display->display_options['filters']['field_course_catalog_number_value']['expose']['operator'] = 'field_course_catalog_number_value_op';
  $handler->display->display_options['filters']['field_course_catalog_number_value']['expose']['identifier'] = 'field_course_catalog_number_value';
  /* Filter criterion: Content: Section number (field_course_section) */
  $handler->display->display_options['filters']['field_course_section_value']['id'] = 'field_course_section_value';
  $handler->display->display_options['filters']['field_course_section_value']['table'] = 'field_data_field_course_section';
  $handler->display->display_options['filters']['field_course_section_value']['field'] = 'field_course_section_value';
  $handler->display->display_options['filters']['field_course_section_value']['group'] = 0;
  $handler->display->display_options['filters']['field_course_section_value']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_course_section_value']['expose']['operator_id'] = 'field_course_section_value_op';
  $handler->display->display_options['filters']['field_course_section_value']['expose']['label'] = 'Section';
  $handler->display->display_options['filters']['field_course_section_value']['expose']['operator'] = 'field_course_section_value_op';
  $handler->display->display_options['filters']['field_course_section_value']['expose']['identifier'] = 'field_course_section_value';
  /* Filter criterion: Content: Term (field_term) */
  $handler->display->display_options['filters']['field_term_nid']['id'] = 'field_term_nid';
  $handler->display->display_options['filters']['field_term_nid']['table'] = 'field_data_field_term';
  $handler->display->display_options['filters']['field_term_nid']['field'] = 'field_term_nid';
  $handler->display->display_options['filters']['field_term_nid']['group'] = '0';
  $handler->display->display_options['filters']['field_term_nid']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_term_nid']['expose']['operator_id'] = 'field_term_nid_op';
  $handler->display->display_options['filters']['field_term_nid']['expose']['label'] = 'Term';
  $handler->display->display_options['filters']['field_term_nid']['expose']['operator'] = 'field_term_nid_op';
  $handler->display->display_options['filters']['field_term_nid']['expose']['identifier'] = 'field_term_nid';
  $handler->display->display_options['filters']['field_term_nid']['expose']['remember'] = TRUE;
  $handler->display->display_options['filters']['field_term_nid']['expose']['multiple'] = TRUE;
  /* Filter criterion: Field: Program (field_site_restrict) */
  $handler->display->display_options['filters']['field_site_restrict_tid']['id'] = 'field_site_restrict_tid';
  $handler->display->display_options['filters']['field_site_restrict_tid']['table'] = 'field_data_field_site_restrict';
  $handler->display->display_options['filters']['field_site_restrict_tid']['field'] = 'field_site_restrict_tid';
  $handler->display->display_options['filters']['field_site_restrict_tid']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_site_restrict_tid']['expose']['operator_id'] = 'field_site_restrict_tid_op';
  $handler->display->display_options['filters']['field_site_restrict_tid']['expose']['label'] = 'Course programs';
  $handler->display->display_options['filters']['field_site_restrict_tid']['expose']['operator'] = 'field_site_restrict_tid_op';
  $handler->display->display_options['filters']['field_site_restrict_tid']['expose']['identifier'] = 'field_site_restrict_tid';
  $handler->display->display_options['filters']['field_site_restrict_tid']['expose']['multiple'] = TRUE;
  $handler->display->display_options['filters']['field_site_restrict_tid']['reduce_duplicates'] = TRUE;
  $handler->display->display_options['filters']['field_site_restrict_tid']['type'] = 'select';
  $handler->display->display_options['filters']['field_site_restrict_tid']['vocabulary'] = 'site_restrictions';
  $handler->display->display_options['filters']['field_site_restrict_tid']['error_message'] = FALSE;
  $handler->display->display_options['path'] = 'courses';

  /* Display: Student course list */
  $handler = $view->new_display('page', 'Student course list', 'page_2');
  $handler->display->display_options['defaults']['empty'] = FALSE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title_1']['id'] = 'title_1';
  $handler->display->display_options['fields']['title_1']['table'] = 'node';
  $handler->display->display_options['fields']['title_1']['field'] = 'title';
  $handler->display->display_options['fields']['title_1']['relationship'] = 'field_term_nid';
  $handler->display->display_options['fields']['title_1']['label'] = '';
  $handler->display->display_options['fields']['title_1']['exclude'] = TRUE;
  $handler->display->display_options['fields']['title_1']['link_to_node'] = FALSE;
  /* Field: Content: Catalog number */
  $handler->display->display_options['fields']['field_course_catalog_number']['id'] = 'field_course_catalog_number';
  $handler->display->display_options['fields']['field_course_catalog_number']['table'] = 'field_data_field_course_catalog_number';
  $handler->display->display_options['fields']['field_course_catalog_number']['field'] = 'field_course_catalog_number';
  $handler->display->display_options['fields']['field_course_catalog_number']['label'] = '';
  $handler->display->display_options['fields']['field_course_catalog_number']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_course_catalog_number']['element_label_colon'] = FALSE;
  /* Field: Content: Subject */
  $handler->display->display_options['fields']['field_course_subject']['id'] = 'field_course_subject';
  $handler->display->display_options['fields']['field_course_subject']['table'] = 'field_data_field_course_subject';
  $handler->display->display_options['fields']['field_course_subject']['field'] = 'field_course_subject';
  $handler->display->display_options['fields']['field_course_subject']['label'] = 'Course';
  $handler->display->display_options['fields']['field_course_subject']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_course_subject']['alter']['text'] = '[field_course_subject] [field_course_catalog_number]';
  /* Field: Content: Section number */
  $handler->display->display_options['fields']['field_course_section']['id'] = 'field_course_section';
  $handler->display->display_options['fields']['field_course_section']['table'] = 'field_data_field_course_section';
  $handler->display->display_options['fields']['field_course_section']['field'] = 'field_course_section';
  $handler->display->display_options['fields']['field_course_section']['label'] = 'Section';
  $handler->display->display_options['fields']['field_course_section']['settings'] = array(
    'thousand_separator' => ' ',
    'prefix_suffix' => 1,
  );
  /* Field: Content: Course title */
  $handler->display->display_options['fields']['field_course_title']['id'] = 'field_course_title';
  $handler->display->display_options['fields']['field_course_title']['table'] = 'field_data_field_course_title';
  $handler->display->display_options['fields']['field_course_title']['field'] = 'field_course_title';
  $handler->display->display_options['fields']['field_course_title']['label'] = 'Title';
  /* Field: Content: Faculty */
  $handler->display->display_options['fields']['field_course_faculty']['id'] = 'field_course_faculty';
  $handler->display->display_options['fields']['field_course_faculty']['table'] = 'field_data_field_course_faculty';
  $handler->display->display_options['fields']['field_course_faculty']['field'] = 'field_course_faculty';
  $handler->display->display_options['fields']['field_course_faculty']['type'] = 'user_reference_plain';
  $handler->display->display_options['fields']['field_course_faculty']['delta_offset'] = '0';
  /* Field: Signup: User select course */
  $handler->display->display_options['fields']['user_course_select']['id'] = 'user_course_select';
  $handler->display->display_options['fields']['user_course_select']['table'] = 's4_signup';
  $handler->display->display_options['fields']['user_course_select']['field'] = 'user_course_select';
  $handler->display->display_options['fields']['user_course_select']['label'] = 'Select';
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Contextual filter: Content: Students (field_course_students) */
  $handler->display->display_options['arguments']['field_course_students_uid']['id'] = 'field_course_students_uid';
  $handler->display->display_options['arguments']['field_course_students_uid']['table'] = 'field_data_field_course_students';
  $handler->display->display_options['arguments']['field_course_students_uid']['field'] = 'field_course_students_uid';
  $handler->display->display_options['arguments']['field_course_students_uid']['default_action'] = 'default';
  $handler->display->display_options['arguments']['field_course_students_uid']['default_argument_type'] = 'current_user';
  $handler->display->display_options['arguments']['field_course_students_uid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['field_course_students_uid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['field_course_students_uid']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['path'] = 'my-courses';

  /* Display: Add to course list */
  $handler = $view->new_display('block', 'Add to course list', 'block_1');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '5';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['style_options']['grouping'] = 'title_1';
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['empty'] = FALSE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Nid */
  $handler->display->display_options['fields']['nid']['id'] = 'nid';
  $handler->display->display_options['fields']['nid']['table'] = 'node';
  $handler->display->display_options['fields']['nid']['field'] = 'nid';
  $handler->display->display_options['fields']['nid']['label'] = '';
  $handler->display->display_options['fields']['nid']['exclude'] = TRUE;
  $handler->display->display_options['fields']['nid']['element_label_colon'] = FALSE;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['exclude'] = TRUE;
  $handler->display->display_options['fields']['title']['alter']['text'] = '<div class="signup add"><div class="icon"></div><a href="s4/course-list/[nid]">Add to [title]</a></div>';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['title']['link_to_node'] = FALSE;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title_1']['id'] = 'title_1';
  $handler->display->display_options['fields']['title_1']['table'] = 'node';
  $handler->display->display_options['fields']['title_1']['field'] = 'title';
  $handler->display->display_options['fields']['title_1']['relationship'] = 'field_term_nid';
  $handler->display->display_options['fields']['title_1']['label'] = '';
  $handler->display->display_options['fields']['title_1']['exclude'] = TRUE;
  $handler->display->display_options['fields']['title_1']['link_to_node'] = FALSE;
  /* Field: Signup: Faculty site select */
  $handler->display->display_options['fields']['faculty_site_select']['id'] = 'faculty_site_select';
  $handler->display->display_options['fields']['faculty_site_select']['table'] = 's4_signup';
  $handler->display->display_options['fields']['faculty_site_select']['field'] = 'faculty_site_select';
  $handler->display->display_options['fields']['faculty_site_select']['label'] = '';
  $handler->display->display_options['fields']['faculty_site_select']['element_label_colon'] = FALSE;
  /* Field: Content: Sites */
  $handler->display->display_options['fields']['field_sites']['id'] = 'field_sites';
  $handler->display->display_options['fields']['field_sites']['table'] = 'field_data_field_sites';
  $handler->display->display_options['fields']['field_sites']['field'] = 'field_sites';
  $handler->display->display_options['fields']['field_sites']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_sites']['delta_offset'] = '0';
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 0;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'course' => 'course',
  );
  /* Filter criterion: Content: Term dates (field_term_date_start) */
  $handler->display->display_options['filters']['field_term_date_start_value']['id'] = 'field_term_date_start_value';
  $handler->display->display_options['filters']['field_term_date_start_value']['table'] = 'field_data_field_term_date_start';
  $handler->display->display_options['filters']['field_term_date_start_value']['field'] = 'field_term_date_start_value';
  $handler->display->display_options['filters']['field_term_date_start_value']['relationship'] = 'field_term_nid';
  $handler->display->display_options['filters']['field_term_date_start_value']['operator'] = '<=';
  $handler->display->display_options['filters']['field_term_date_start_value']['granularity'] = 'day';
  $handler->display->display_options['filters']['field_term_date_start_value']['form_type'] = 'date_select';
  $handler->display->display_options['filters']['field_term_date_start_value']['default_date'] = 'now';
  $handler->display->display_options['filters']['field_term_date_start_value']['default_to_date'] = '';
  $handler->display->display_options['filters']['field_term_date_start_value']['year_range'] = '-3:+3';
  /* Filter criterion: Content: Term dates (field_term_date_start:value2) */
  $handler->display->display_options['filters']['field_term_date_start_value2']['id'] = 'field_term_date_start_value2';
  $handler->display->display_options['filters']['field_term_date_start_value2']['table'] = 'field_data_field_term_date_start';
  $handler->display->display_options['filters']['field_term_date_start_value2']['field'] = 'field_term_date_start_value2';
  $handler->display->display_options['filters']['field_term_date_start_value2']['relationship'] = 'field_term_nid';
  $handler->display->display_options['filters']['field_term_date_start_value2']['operator'] = '>=';
  $handler->display->display_options['filters']['field_term_date_start_value2']['granularity'] = 'day';
  $handler->display->display_options['filters']['field_term_date_start_value2']['form_type'] = 'date_select';
  $handler->display->display_options['filters']['field_term_date_start_value2']['default_date'] = 'now';
  $handler->display->display_options['filters']['field_term_date_start_value2']['default_to_date'] = '';
  $handler->display->display_options['filters']['field_term_date_start_value2']['year_range'] = '-3:+3';

  /* Display: Student course block */
  $handler = $view->new_display('block', 'Student course block', 'block_2');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Sign up as part of a course';
  $handler->display->display_options['defaults']['header'] = FALSE;
  /* Header: Global: Text area */
  $handler->display->display_options['header']['area']['id'] = 'area';
  $handler->display->display_options['header']['area']['table'] = 'views';
  $handler->display->display_options['header']['area']['field'] = 'area';
  $handler->display->display_options['header']['area']['label'] = 'Directions';
  $handler->display->display_options['header']['area']['empty'] = FALSE;
  $handler->display->display_options['header']['area']['content'] = '<p class="intro">To begin looking for a site, click the <strong>Select this Course</strong> link near the course you are taking for this service.</p>';
  $handler->display->display_options['header']['area']['format'] = 'full_html';
  $handler->display->display_options['defaults']['empty'] = FALSE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title_1']['id'] = 'title_1';
  $handler->display->display_options['fields']['title_1']['table'] = 'node';
  $handler->display->display_options['fields']['title_1']['field'] = 'title';
  $handler->display->display_options['fields']['title_1']['relationship'] = 'field_term_nid';
  $handler->display->display_options['fields']['title_1']['label'] = '';
  $handler->display->display_options['fields']['title_1']['exclude'] = TRUE;
  $handler->display->display_options['fields']['title_1']['link_to_node'] = FALSE;
  /* Field: Content: Catalog number */
  $handler->display->display_options['fields']['field_course_catalog_number']['id'] = 'field_course_catalog_number';
  $handler->display->display_options['fields']['field_course_catalog_number']['table'] = 'field_data_field_course_catalog_number';
  $handler->display->display_options['fields']['field_course_catalog_number']['field'] = 'field_course_catalog_number';
  $handler->display->display_options['fields']['field_course_catalog_number']['label'] = '';
  $handler->display->display_options['fields']['field_course_catalog_number']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_course_catalog_number']['element_label_colon'] = FALSE;
  /* Field: Content: Subject */
  $handler->display->display_options['fields']['field_course_subject']['id'] = 'field_course_subject';
  $handler->display->display_options['fields']['field_course_subject']['table'] = 'field_data_field_course_subject';
  $handler->display->display_options['fields']['field_course_subject']['field'] = 'field_course_subject';
  $handler->display->display_options['fields']['field_course_subject']['label'] = 'Course';
  $handler->display->display_options['fields']['field_course_subject']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_course_subject']['alter']['text'] = '[field_course_subject] [field_course_catalog_number]';
  /* Field: Content: Section number */
  $handler->display->display_options['fields']['field_course_section']['id'] = 'field_course_section';
  $handler->display->display_options['fields']['field_course_section']['table'] = 'field_data_field_course_section';
  $handler->display->display_options['fields']['field_course_section']['field'] = 'field_course_section';
  $handler->display->display_options['fields']['field_course_section']['label'] = 'Section';
  $handler->display->display_options['fields']['field_course_section']['settings'] = array(
    'thousand_separator' => ' ',
    'prefix_suffix' => 1,
  );
  /* Field: Content: Course title */
  $handler->display->display_options['fields']['field_course_title']['id'] = 'field_course_title';
  $handler->display->display_options['fields']['field_course_title']['table'] = 'field_data_field_course_title';
  $handler->display->display_options['fields']['field_course_title']['field'] = 'field_course_title';
  $handler->display->display_options['fields']['field_course_title']['label'] = 'Title';
  /* Field: Signup: User select course */
  $handler->display->display_options['fields']['user_course_select']['id'] = 'user_course_select';
  $handler->display->display_options['fields']['user_course_select']['table'] = 's4_signup';
  $handler->display->display_options['fields']['user_course_select']['field'] = 'user_course_select';
  $handler->display->display_options['fields']['user_course_select']['label'] = 'Select';
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Contextual filter: Content: Students (field_course_students) */
  $handler->display->display_options['arguments']['field_course_students_uid']['id'] = 'field_course_students_uid';
  $handler->display->display_options['arguments']['field_course_students_uid']['table'] = 'field_data_field_course_students';
  $handler->display->display_options['arguments']['field_course_students_uid']['field'] = 'field_course_students_uid';
  $handler->display->display_options['arguments']['field_course_students_uid']['default_action'] = 'default';
  $handler->display->display_options['arguments']['field_course_students_uid']['default_argument_type'] = 'current_user';
  $handler->display->display_options['arguments']['field_course_students_uid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['field_course_students_uid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['field_course_students_uid']['summary_options']['items_per_page'] = '25';
  $translatables['user_courses'] = array(
    t('Master'),
    t('Sign up for service'),
    t('more'),
    t('Apply'),
    t('Reset'),
    t('Sort by'),
    t('Asc'),
    t('Desc'),
    t('Items per page'),
    t('- All -'),
    t('Offset'),
    t('« first'),
    t('‹ previous'),
    t('next ›'),
    t('last »'),
    t('No courses'),
    t('<p class="intro">It looks like you don\'t have any courses this semester.</p><p><strong>Don\'t panic:</strong> if you just registered for a course, it might be taking a while for your registration to get to our system. Also, in some situations we don\'t bring over courses unless they have a service learning, internship, or other training component. Check with your faculty if you think your course should show up here.</p>'),
    t('field_term'),
    t('All'),
    t('Page'),
    t('Faculty Course List'),
    t('Manage your courses'),
    t('Staff course listing'),
    t('Courses'),
    t('field_course_faculty'),
    t('View'),
    t('node/[nid]'),
    t('Subject'),
    t('Number'),
    t('Section'),
    t('Title'),
    t('Term'),
    t('Programs'),
    t('Last Name'),
    t('Faculty'),
    t('[field_last_name], [field_first_name]'),
    t('Students'),
    t('Enrollment'),
    t('Edit'),
    t('Catalog number'),
    t('Course programs'),
    t('Student course list'),
    t('Course'),
    t('[field_course_subject] [field_course_catalog_number]'),
    t('Select'),
    t('Add to course list'),
    t('<div class="signup add"><div class="icon"></div><a href="s4/course-list/[nid]">Add to [title]</a></div>'),
    t('Sites'),
    t('Student course block'),
    t('Sign up as part of a course'),
    t('Directions'),
    t('<p class="intro">To begin looking for a site, click the <strong>Select this Course</strong> link near the course you are taking for this service.</p>'),
  );
  $export['user_courses'] = $view;

  return $export;
}
