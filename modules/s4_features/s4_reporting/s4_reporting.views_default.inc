<?php
/**
 * @file
 * s4_reporting.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function s4_reporting_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'reports_faculty';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'users';
  $view->human_name = 'Reports: faculty';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Student report';
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['access']['perm'] = 'access s4 reporting';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['query']['options']['distinct'] = TRUE;
  $handler->display->display_options['exposed_form']['type'] = 's4_reporting';
  $handler->display->display_options['exposed_form']['options']['s4_reporting'] = array(
    'group-field_first_name_value_1' => '0',
    'group-field_last_name_value' => '0',
    'group-field_term_nid' => '1',
    'group-field_course_subject_value' => '1',
    'group-field_course_catalog_number_value' => '1',
    'group-dyfield' => '3',
    'group-field_site_nid' => '2',
    'group-city' => '2',
    'group-province' => '2',
    'groups' => 'Faculty
Course
Placements
Fields',
  );
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '40';
  $handler->display->display_options['style_plugin'] = 'table';
  /* Header: Global: Result summary */
  $handler->display->display_options['header']['result']['id'] = 'result';
  $handler->display->display_options['header']['result']['table'] = 'views';
  $handler->display->display_options['header']['result']['field'] = 'result';
  $handler->display->display_options['header']['result']['empty'] = FALSE;
  /* Relationship: User: Faculty (field_course_faculty) - reverse */
  $handler->display->display_options['relationships']['reverse_field_course_faculty_node']['id'] = 'reverse_field_course_faculty_node';
  $handler->display->display_options['relationships']['reverse_field_course_faculty_node']['table'] = 'users';
  $handler->display->display_options['relationships']['reverse_field_course_faculty_node']['field'] = 'reverse_field_course_faculty_node';
  $handler->display->display_options['relationships']['reverse_field_course_faculty_node']['required'] = TRUE;
  /* Relationship: Content: Course (field_course) - reverse */
  $handler->display->display_options['relationships']['reverse_field_course_node']['id'] = 'reverse_field_course_node';
  $handler->display->display_options['relationships']['reverse_field_course_node']['table'] = 'node';
  $handler->display->display_options['relationships']['reverse_field_course_node']['field'] = 'reverse_field_course_node';
  $handler->display->display_options['relationships']['reverse_field_course_node']['relationship'] = 'reverse_field_course_faculty_node';
  /* Relationship: Content: Site (field_site) */
  $handler->display->display_options['relationships']['field_site_nid']['id'] = 'field_site_nid';
  $handler->display->display_options['relationships']['field_site_nid']['table'] = 'field_data_field_site';
  $handler->display->display_options['relationships']['field_site_nid']['field'] = 'field_site_nid';
  $handler->display->display_options['relationships']['field_site_nid']['relationship'] = 'reverse_field_course_node';
  $handler->display->display_options['relationships']['field_site_nid']['delta'] = '-1';
  /* Field: Bulk operations: User */
  $handler->display->display_options['fields']['views_bulk_operations']['id'] = 'views_bulk_operations';
  $handler->display->display_options['fields']['views_bulk_operations']['table'] = 'users';
  $handler->display->display_options['fields']['views_bulk_operations']['field'] = 'views_bulk_operations';
  $handler->display->display_options['fields']['views_bulk_operations']['label'] = 'Email';
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
    'action::views_bulk_operations_modify_action' => array(
      'selected' => 0,
      'use_queue' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
      'settings' => array(
        'show_all_tokens' => 1,
        'display_values' => array(
          '_all_' => '_all_',
        ),
      ),
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
    'action::s4_core_email_site_action' => array(
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
      'selected' => 1,
      'use_queue' => 0,
      'skip_confirmation' => 0,
      'override_label' => 1,
      'label' => 'Send faculty email',
    ),
    'action::s4_courses_bulk_signup_students_action' => array(
      'selected' => 0,
      'use_queue' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
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
  $handler->display->display_options['fields']['uid']['label'] = '';
  $handler->display->display_options['fields']['uid']['exclude'] = TRUE;
  $handler->display->display_options['fields']['uid']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['uid']['link_to_user'] = FALSE;
  /* Field: Field: Last Name */
  $handler->display->display_options['fields']['field_last_name']['id'] = 'field_last_name';
  $handler->display->display_options['fields']['field_last_name']['table'] = 'field_data_field_last_name';
  $handler->display->display_options['fields']['field_last_name']['field'] = 'field_last_name';
  $handler->display->display_options['fields']['field_last_name']['label'] = 'Last name';
  $handler->display->display_options['fields']['field_last_name']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['field_last_name']['alter']['path'] = 'user/[uid]';
  /* Field: Field: First Name */
  $handler->display->display_options['fields']['field_first_name']['id'] = 'field_first_name';
  $handler->display->display_options['fields']['field_first_name']['table'] = 'field_data_field_first_name';
  $handler->display->display_options['fields']['field_first_name']['field'] = 'field_first_name';
  $handler->display->display_options['fields']['field_first_name']['label'] = 'First name';
  $handler->display->display_options['fields']['field_first_name']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['field_first_name']['alter']['path'] = 'user/[uid]';
  /* Field: User: Authentication name */
  $handler->display->display_options['fields']['authname']['id'] = 'authname';
  $handler->display->display_options['fields']['authname']['table'] = 'authmap';
  $handler->display->display_options['fields']['authname']['field'] = 'authname';
  $handler->display->display_options['fields']['authname']['label'] = 'Login name';
  /* Field: User: E-mail */
  $handler->display->display_options['fields']['mail']['id'] = 'mail';
  $handler->display->display_options['fields']['mail']['table'] = 'users';
  $handler->display->display_options['fields']['mail']['field'] = 'mail';
  $handler->display->display_options['fields']['mail']['label'] = 'E-mail ';
  /* Field: User: Last login */
  $handler->display->display_options['fields']['login']['id'] = 'login';
  $handler->display->display_options['fields']['login']['table'] = 'users';
  $handler->display->display_options['fields']['login']['field'] = 'login';
  $handler->display->display_options['fields']['login']['label'] = 'Last login ';
  $handler->display->display_options['fields']['login']['date_format'] = 'long';
  /* Field: User: SIS ID */
  $handler->display->display_options['fields']['field_sis_id']['id'] = 'field_sis_id';
  $handler->display->display_options['fields']['field_sis_id']['table'] = 'field_data_field_sis_id';
  $handler->display->display_options['fields']['field_sis_id']['field'] = 'field_sis_id';
  $handler->display->display_options['fields']['field_sis_id']['label'] = 'Faculty ID';
  /* Sort criterion: Field: Last Name (field_last_name) */
  $handler->display->display_options['sorts']['field_last_name_value']['id'] = 'field_last_name_value';
  $handler->display->display_options['sorts']['field_last_name_value']['table'] = 'field_data_field_last_name';
  $handler->display->display_options['sorts']['field_last_name_value']['field'] = 'field_last_name_value';
  /* Sort criterion: Field: First Name (field_first_name) */
  $handler->display->display_options['sorts']['field_first_name_value']['id'] = 'field_first_name_value';
  $handler->display->display_options['sorts']['field_first_name_value']['table'] = 'field_data_field_first_name';
  $handler->display->display_options['sorts']['field_first_name_value']['field'] = 'field_first_name_value';
  /* Sort criterion: User: Created date */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'users';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
  /* Filter criterion: User: Active */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'users';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = '1';
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Field: First Name (field_first_name) */
  $handler->display->display_options['filters']['field_first_name_value_1']['id'] = 'field_first_name_value_1';
  $handler->display->display_options['filters']['field_first_name_value_1']['table'] = 'field_data_field_first_name';
  $handler->display->display_options['filters']['field_first_name_value_1']['field'] = 'field_first_name_value';
  $handler->display->display_options['filters']['field_first_name_value_1']['operator'] = 'starts';
  $handler->display->display_options['filters']['field_first_name_value_1']['group'] = 1;
  $handler->display->display_options['filters']['field_first_name_value_1']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_first_name_value_1']['expose']['operator_id'] = 'field_first_name_value_1_op';
  $handler->display->display_options['filters']['field_first_name_value_1']['expose']['label'] = 'First name';
  $handler->display->display_options['filters']['field_first_name_value_1']['expose']['operator'] = 'field_first_name_value_1_op';
  $handler->display->display_options['filters']['field_first_name_value_1']['expose']['identifier'] = 'field_first_name_value_1';
  /* Filter criterion: Field: Last Name (field_last_name) */
  $handler->display->display_options['filters']['field_last_name_value']['id'] = 'field_last_name_value';
  $handler->display->display_options['filters']['field_last_name_value']['table'] = 'field_data_field_last_name';
  $handler->display->display_options['filters']['field_last_name_value']['field'] = 'field_last_name_value';
  $handler->display->display_options['filters']['field_last_name_value']['operator'] = 'starts';
  $handler->display->display_options['filters']['field_last_name_value']['group'] = 1;
  $handler->display->display_options['filters']['field_last_name_value']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_last_name_value']['expose']['operator_id'] = 'field_last_name_value_op';
  $handler->display->display_options['filters']['field_last_name_value']['expose']['label'] = 'Last name';
  $handler->display->display_options['filters']['field_last_name_value']['expose']['operator'] = 'field_last_name_value_op';
  $handler->display->display_options['filters']['field_last_name_value']['expose']['identifier'] = 'field_last_name_value';
  /* Filter criterion: Content: Term (field_term) */
  $handler->display->display_options['filters']['field_term_nid']['id'] = 'field_term_nid';
  $handler->display->display_options['filters']['field_term_nid']['table'] = 'field_data_field_term';
  $handler->display->display_options['filters']['field_term_nid']['field'] = 'field_term_nid';
  $handler->display->display_options['filters']['field_term_nid']['relationship'] = 'reverse_field_course_faculty_node';
  $handler->display->display_options['filters']['field_term_nid']['group'] = 1;
  $handler->display->display_options['filters']['field_term_nid']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_term_nid']['expose']['operator_id'] = 'field_term_nid_op';
  $handler->display->display_options['filters']['field_term_nid']['expose']['label'] = 'Course term';
  $handler->display->display_options['filters']['field_term_nid']['expose']['operator'] = 'field_term_nid_op';
  $handler->display->display_options['filters']['field_term_nid']['expose']['identifier'] = 'field_term_nid';
  $handler->display->display_options['filters']['field_term_nid']['expose']['multiple'] = TRUE;
  /* Filter criterion: Content: Subject (field_course_subject) */
  $handler->display->display_options['filters']['field_course_subject_value']['id'] = 'field_course_subject_value';
  $handler->display->display_options['filters']['field_course_subject_value']['table'] = 'field_data_field_course_subject';
  $handler->display->display_options['filters']['field_course_subject_value']['field'] = 'field_course_subject_value';
  $handler->display->display_options['filters']['field_course_subject_value']['relationship'] = 'reverse_field_course_faculty_node';
  $handler->display->display_options['filters']['field_course_subject_value']['group'] = 1;
  $handler->display->display_options['filters']['field_course_subject_value']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_course_subject_value']['expose']['operator_id'] = 'field_course_subject_value_op';
  $handler->display->display_options['filters']['field_course_subject_value']['expose']['label'] = 'Course subject';
  $handler->display->display_options['filters']['field_course_subject_value']['expose']['operator'] = 'field_course_subject_value_op';
  $handler->display->display_options['filters']['field_course_subject_value']['expose']['identifier'] = 'field_course_subject_value';
  /* Filter criterion: Content: Catalog number (field_course_catalog_number) */
  $handler->display->display_options['filters']['field_course_catalog_number_value']['id'] = 'field_course_catalog_number_value';
  $handler->display->display_options['filters']['field_course_catalog_number_value']['table'] = 'field_data_field_course_catalog_number';
  $handler->display->display_options['filters']['field_course_catalog_number_value']['field'] = 'field_course_catalog_number_value';
  $handler->display->display_options['filters']['field_course_catalog_number_value']['relationship'] = 'reverse_field_course_faculty_node';
  $handler->display->display_options['filters']['field_course_catalog_number_value']['operator'] = '!=';
  $handler->display->display_options['filters']['field_course_catalog_number_value']['group'] = 1;
  $handler->display->display_options['filters']['field_course_catalog_number_value']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_course_catalog_number_value']['expose']['operator_id'] = 'field_course_catalog_number_value_op';
  $handler->display->display_options['filters']['field_course_catalog_number_value']['expose']['label'] = 'Course number';
  $handler->display->display_options['filters']['field_course_catalog_number_value']['expose']['operator'] = 'field_course_catalog_number_value_op';
  $handler->display->display_options['filters']['field_course_catalog_number_value']['expose']['identifier'] = 'field_course_catalog_number_value';
  /* Filter criterion: Content: Dynamic Fields */
  $handler->display->display_options['filters']['dyfield']['id'] = 'dyfield';
  $handler->display->display_options['filters']['dyfield']['table'] = 'node';
  $handler->display->display_options['filters']['dyfield']['field'] = 'dyfield';
  $handler->display->display_options['filters']['dyfield']['relationship'] = 'reverse_field_course_faculty_node';
  $handler->display->display_options['filters']['dyfield']['group'] = 1;
  $handler->display->display_options['filters']['dyfield']['exposed'] = TRUE;
  $handler->display->display_options['filters']['dyfield']['expose']['operator_id'] = '';
  $handler->display->display_options['filters']['dyfield']['expose']['label'] = 'Fields';
  $handler->display->display_options['filters']['dyfield']['expose']['operator'] = 'dyfield_op';
  $handler->display->display_options['filters']['dyfield']['expose']['identifier'] = 'dyfield';
  $handler->display->display_options['filters']['dyfield']['expose']['multiple'] = TRUE;
  $handler->display->display_options['filters']['dyfield']['filterable_fields'] = array(
    'views_bulk_operations' => 'views_bulk_operations',
    'field_last_name' => 'field_last_name',
    'field_first_name' => 'field_first_name',
    'authname' => 'authname',
    'mail' => 'mail',
    'login' => 'login',
    'field_sis_id' => 'field_sis_id',
  );
  $handler->display->display_options['filters']['dyfield']['defaults_filterable_fields'] = array(
    'views_bulk_operations' => 'views_bulk_operations',
    'field_last_name' => 'field_last_name',
    'field_first_name' => 'field_first_name',
    'authname' => 'authname',
    'mail' => 'mail',
    'field_sis_id' => 'field_sis_id',
    'login' => 0,
  );
  $handler->display->display_options['filters']['dyfield']['sortability'] = 1;
  $handler->display->display_options['filters']['dyfield']['checkboxes'] = 1;
  /* Filter criterion: Content: Site (field_site) */
  $handler->display->display_options['filters']['field_site_nid']['id'] = 'field_site_nid';
  $handler->display->display_options['filters']['field_site_nid']['table'] = 'field_data_field_site';
  $handler->display->display_options['filters']['field_site_nid']['field'] = 'field_site_nid';
  $handler->display->display_options['filters']['field_site_nid']['relationship'] = 'reverse_field_course_node';
  $handler->display->display_options['filters']['field_site_nid']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_site_nid']['expose']['operator_id'] = 'field_site_nid_op';
  $handler->display->display_options['filters']['field_site_nid']['expose']['label'] = 'Specific sites';
  $handler->display->display_options['filters']['field_site_nid']['expose']['operator'] = 'field_site_nid_op';
  $handler->display->display_options['filters']['field_site_nid']['expose']['identifier'] = 'field_site_nid';
  $handler->display->display_options['filters']['field_site_nid']['expose']['multiple'] = TRUE;
  /* Filter criterion: Location: City */
  $handler->display->display_options['filters']['city']['id'] = 'city';
  $handler->display->display_options['filters']['city']['table'] = 'location';
  $handler->display->display_options['filters']['city']['field'] = 'city';
  $handler->display->display_options['filters']['city']['relationship'] = 'field_site_nid';
  $handler->display->display_options['filters']['city']['exposed'] = TRUE;
  $handler->display->display_options['filters']['city']['expose']['operator_id'] = 'city_op';
  $handler->display->display_options['filters']['city']['expose']['label'] = 'City';
  $handler->display->display_options['filters']['city']['expose']['operator'] = 'city_op';
  $handler->display->display_options['filters']['city']['expose']['identifier'] = 'city';
  /* Filter criterion: Location: Province */
  $handler->display->display_options['filters']['province']['id'] = 'province';
  $handler->display->display_options['filters']['province']['table'] = 'location';
  $handler->display->display_options['filters']['province']['field'] = 'province';
  $handler->display->display_options['filters']['province']['relationship'] = 'field_site_nid';
  $handler->display->display_options['filters']['province']['exposed'] = TRUE;
  $handler->display->display_options['filters']['province']['expose']['operator_id'] = 'province_op';
  $handler->display->display_options['filters']['province']['expose']['label'] = 'State';
  $handler->display->display_options['filters']['province']['expose']['operator'] = 'province_op';
  $handler->display->display_options['filters']['province']['expose']['identifier'] = 'province';

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page');
  $handler->display->display_options['path'] = 'reports/faculty';
  $handler->display->display_options['menu']['type'] = 'tab';
  $handler->display->display_options['menu']['title'] = 'Faculty';
  $handler->display->display_options['menu']['weight'] = '2';
  $handler->display->display_options['menu']['context'] = 0;

  /* Display: Export CSV */
  $handler = $view->new_display('views_data_export', 'Export CSV', 'views_data_export_1');
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['style_plugin'] = 'views_data_export_csv';
  $handler->display->display_options['path'] = 'reports/faculty/export/csv';
  $handler->display->display_options['displays'] = array(
    'page' => 'page',
    'default' => 0,
  );

  /* Display: Export XLS */
  $handler = $view->new_display('views_data_export', 'Export XLS', 'views_data_export_2');
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['style_plugin'] = 'views_data_export_xls';
  $handler->display->display_options['style_options']['provide_file'] = 0;
  $handler->display->display_options['style_options']['parent_sort'] = 0;
  $handler->display->display_options['path'] = 'reports/faculty/export/xls';
  $handler->display->display_options['displays'] = array(
    'page' => 'page',
    'default' => 0,
  );

  /* Display: Export DOC */
  $handler = $view->new_display('views_data_export', 'Export DOC', 'views_data_export_3');
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['style_plugin'] = 'views_data_export_doc';
  $handler->display->display_options['style_options']['provide_file'] = 0;
  $handler->display->display_options['style_options']['parent_sort'] = 0;
  $handler->display->display_options['path'] = 'reports/faculty/export/doc';
  $handler->display->display_options['displays'] = array(
    'page' => 'page',
    'default' => 0,
  );
  $translatables['reports_faculty'] = array(
    t('Master'),
    t('Student report'),
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
    t('Displaying @start - @end of @total'),
    t('field_course_faculty'),
    t('field_course'),
    t('field_site'),
    t('Email'),
    t('Last name'),
    t('user/[uid]'),
    t('First name'),
    t('Login name'),
    t('E-mail '),
    t('Last login '),
    t('Faculty ID'),
    t('Course term'),
    t('Course subject'),
    t('Course number'),
    t('Fields'),
    t('Specific sites'),
    t('City'),
    t('State'),
    t('Page'),
    t('Export CSV'),
    t('Export XLS'),
    t('Export DOC'),
  );
  $export['reports_faculty'] = $view;

  $view = new view();
  $view->name = 'reports_site_staff';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Reports: site staff';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Site staff report';
  $handler->display->display_options['css_class'] = 'report-view';
  $handler->display->display_options['link_display'] = 'page';
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['access']['perm'] = 'access s4 reporting';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['query']['options']['distinct'] = TRUE;
  $handler->display->display_options['query']['options']['query_comment'] = FALSE;
  $handler->display->display_options['exposed_form']['type'] = 's4_reporting';
  $handler->display->display_options['exposed_form']['options']['submit_button'] = 'Search';
  $handler->display->display_options['exposed_form']['options']['reset_button'] = TRUE;
  $handler->display->display_options['exposed_form']['options']['s4_reporting'] = array(
    'group-status' => '0',
    'group-city' => '2',
    'group-field_csu_facility_tid' => '1',
    'group-field_csu_org_type_tid' => '1',
    'group-dyfield' => '4',
    'group-field_term_nid' => '1',
    'group-field_district_federal_value' => '2',
    'group-field_district_state_lower_value' => '2',
    'group-field_district_state_upper_value' => '2',
    'group-distance' => '2',
    'group-field_site_restrict_tid' => '1',
    'group-field_tags_tid' => '1',
    'group-field_signup_start_date_value' => '3',
    'group-field_course_subject_value' => '3',
    'group-field_term_nid_1' => '3',
    'group-field_site_nid' => '0',
    'group-field_staff_signup_available_value' => '0',
    'group-field_site_restrict_tid_1' => '0',
    'group-field_staff_role_tid' => '0',
    'groups' => 'Site staff
Site categories
Site location
Placements
Fields',
  );
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '30';
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['columns'] = array(
    'title' => 'title',
    'field_website' => 'field_website',
    'field_site_email' => 'field_site_email',
    'field_phone' => 'field_phone',
    'city' => 'city',
    'postal_code' => 'postal_code',
    'province' => 'province',
    'street' => 'street',
    'field_district_federal' => 'field_district_federal',
    'field_district_state_lower' => 'field_district_state_lower',
    'field_district_state_upper' => 'field_district_state_upper',
    'field_site_users' => 'field_site_users',
    'body' => 'body',
    'field_site_projects' => 'field_site_projects',
    'field_site_demographics' => 'field_site_demographics',
    'field_site_email_1' => 'field_site_email_1',
    'field_site_hours' => 'field_site_hours',
    'field_csu_facility' => 'field_csu_facility',
    'field_signups_max' => 'field_signups_max',
    'field_csu_org_type' => 'field_csu_org_type',
    'field_phone_1' => 'field_phone_1',
    'field_health_risk' => 'field_health_risk',
    'field_site_instructions_required' => 'field_site_instructions_required',
    'field_site_requirements' => 'field_site_requirements',
    'field_site_tour' => 'field_site_tour',
    'field_site_facebook_page' => 'field_site_facebook_page',
    'field_site_instructions' => 'field_site_instructions',
    'field_tags' => 'field_tags',
    'field_site_health_training' => 'field_site_health_training',
    'field_website_1' => 'field_website_1',
    'field_site_hours_minimum' => 'field_site_hours_minimum',
    'field_site_language' => 'field_site_language',
    'field_site_restrict' => 'field_site_restrict',
  );
  $handler->display->display_options['style_options']['default'] = '-1';
  $handler->display->display_options['style_options']['info'] = array(
    'title' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_website' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_site_email' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_phone' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'city' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'postal_code' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'province' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'street' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_district_federal' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_district_state_lower' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_district_state_upper' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_site_users' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'body' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_site_projects' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_site_demographics' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_site_email_1' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_site_hours' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_csu_facility' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_signups_max' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_csu_org_type' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_phone_1' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_health_risk' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_site_instructions_required' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_site_requirements' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_site_tour' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_site_facebook_page' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_site_instructions' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_tags' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_site_health_training' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_website_1' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_site_hours_minimum' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_site_language' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_site_restrict' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
  );
  /* Relationship: Content: Site staff (field_coordinator) - reverse */
  $handler->display->display_options['relationships']['reverse_field_coordinator_node']['id'] = 'reverse_field_coordinator_node';
  $handler->display->display_options['relationships']['reverse_field_coordinator_node']['table'] = 'node';
  $handler->display->display_options['relationships']['reverse_field_coordinator_node']['field'] = 'reverse_field_coordinator_node';
  /* Relationship: Content: Course (field_course) */
  $handler->display->display_options['relationships']['field_course_nid']['id'] = 'field_course_nid';
  $handler->display->display_options['relationships']['field_course_nid']['table'] = 'field_data_field_course';
  $handler->display->display_options['relationships']['field_course_nid']['field'] = 'field_course_nid';
  $handler->display->display_options['relationships']['field_course_nid']['relationship'] = 'reverse_field_coordinator_node';
  $handler->display->display_options['relationships']['field_course_nid']['delta'] = '-1';
  /* Relationship: Content: Site (field_site) */
  $handler->display->display_options['relationships']['field_site_nid']['id'] = 'field_site_nid';
  $handler->display->display_options['relationships']['field_site_nid']['table'] = 'field_data_field_site';
  $handler->display->display_options['relationships']['field_site_nid']['field'] = 'field_site_nid';
  $handler->display->display_options['relationships']['field_site_nid']['required'] = TRUE;
  $handler->display->display_options['relationships']['field_site_nid']['delta'] = '-1';
  /* Field: Bulk operations: Content */
  $handler->display->display_options['fields']['views_bulk_operations']['id'] = 'views_bulk_operations';
  $handler->display->display_options['fields']['views_bulk_operations']['table'] = 'node';
  $handler->display->display_options['fields']['views_bulk_operations']['field'] = 'views_bulk_operations';
  $handler->display->display_options['fields']['views_bulk_operations']['label'] = 'Email';
  $handler->display->display_options['fields']['views_bulk_operations']['vbo']['entity_load_capacity'] = '10';
  $handler->display->display_options['fields']['views_bulk_operations']['vbo']['operations'] = array(
    'action::node_assign_owner_action' => array(
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
    'action::flag_node_action' => array(
      'selected' => 0,
      'use_queue' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
    'action::node_make_sticky_action' => array(
      'selected' => 0,
      'use_queue' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
    'action::node_make_unsticky_action' => array(
      'selected' => 0,
      'use_queue' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
    'action::views_bulk_operations_modify_action' => array(
      'selected' => 0,
      'use_queue' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
      'settings' => array(
        'show_all_tokens' => 1,
        'display_values' => array(
          '_all_' => '_all_',
        ),
      ),
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
    'action::node_promote_action' => array(
      'selected' => 0,
      'use_queue' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
    'action::node_publish_action' => array(
      'selected' => 0,
      'use_queue' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
    'action::system_goto_action' => array(
      'selected' => 0,
      'use_queue' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
    'action::node_unpromote_action' => array(
      'selected' => 0,
      'use_queue' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
    'action::node_save_action' => array(
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
      'selected' => 1,
      'use_queue' => 0,
      'skip_confirmation' => 0,
      'override_label' => 1,
      'label' => 'Send email',
    ),
    'action::s4_core_email_user_action' => array(
      'selected' => 0,
      'use_queue' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
    'action::s4_courses_bulk_signup_students_action' => array(
      'selected' => 0,
      'use_queue' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
    'action::node_unpublish_action' => array(
      'selected' => 0,
      'use_queue' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
    'action::node_unpublish_by_keyword_action' => array(
      'selected' => 0,
      'use_queue' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
  );
  $handler->display->display_options['fields']['views_bulk_operations']['vbo']['enable_select_all_pages'] = 1;
  $handler->display->display_options['fields']['views_bulk_operations']['vbo']['display_type'] = '1';
  $handler->display->display_options['fields']['views_bulk_operations']['vbo']['display_result'] = 1;
  $handler->display->display_options['fields']['views_bulk_operations']['vbo']['force_single'] = 0;
  /* Field: Field: Last Name */
  $handler->display->display_options['fields']['field_last_name']['id'] = 'field_last_name';
  $handler->display->display_options['fields']['field_last_name']['table'] = 'field_data_field_last_name';
  $handler->display->display_options['fields']['field_last_name']['field'] = 'field_last_name';
  $handler->display->display_options['fields']['field_last_name']['label'] = 'Last name';
  /* Field: Field: First Name */
  $handler->display->display_options['fields']['field_first_name']['id'] = 'field_first_name';
  $handler->display->display_options['fields']['field_first_name']['table'] = 'field_data_field_first_name';
  $handler->display->display_options['fields']['field_first_name']['field'] = 'field_first_name';
  $handler->display->display_options['fields']['field_first_name']['label'] = 'First name';
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['relationship'] = 'field_site_nid';
  $handler->display->display_options['fields']['title']['label'] = 'Site';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['title']['hide_alter_empty'] = FALSE;
  /* Field: Content: Role */
  $handler->display->display_options['fields']['field_staff_role']['id'] = 'field_staff_role';
  $handler->display->display_options['fields']['field_staff_role']['table'] = 'field_data_field_staff_role';
  $handler->display->display_options['fields']['field_staff_role']['field'] = 'field_staff_role';
  $handler->display->display_options['fields']['field_staff_role']['label'] = 'Staff role';
  /* Field: Field: Available programs */
  $handler->display->display_options['fields']['field_site_restrict_1']['id'] = 'field_site_restrict_1';
  $handler->display->display_options['fields']['field_site_restrict_1']['table'] = 'field_data_field_site_restrict';
  $handler->display->display_options['fields']['field_site_restrict_1']['field'] = 'field_site_restrict';
  $handler->display->display_options['fields']['field_site_restrict_1']['label'] = 'Staff programs';
  $handler->display->display_options['fields']['field_site_restrict_1']['type'] = 'taxonomy_term_reference_plain';
  $handler->display->display_options['fields']['field_site_restrict_1']['delta_offset'] = '0';
  /* Field: Content: Phone number */
  $handler->display->display_options['fields']['field_phone']['id'] = 'field_phone';
  $handler->display->display_options['fields']['field_phone']['table'] = 'field_data_field_phone';
  $handler->display->display_options['fields']['field_phone']['field'] = 'field_phone';
  $handler->display->display_options['fields']['field_phone']['label'] = 'Staff phone';
  $handler->display->display_options['fields']['field_phone']['click_sort_column'] = 'number';
  /* Field: Content: Students can register with this staff */
  $handler->display->display_options['fields']['field_staff_signup_available']['id'] = 'field_staff_signup_available';
  $handler->display->display_options['fields']['field_staff_signup_available']['table'] = 'field_data_field_staff_signup_available';
  $handler->display->display_options['fields']['field_staff_signup_available']['field'] = 'field_staff_signup_available';
  $handler->display->display_options['fields']['field_staff_signup_available']['label'] = 'Open for placements';
  /* Field: Content: Maximum number of students */
  $handler->display->display_options['fields']['field_signups_max']['id'] = 'field_signups_max';
  $handler->display->display_options['fields']['field_signups_max']['table'] = 'field_data_field_signups_max';
  $handler->display->display_options['fields']['field_signups_max']['field'] = 'field_signups_max';
  $handler->display->display_options['fields']['field_signups_max']['label'] = 'Staff student limit';
  $handler->display->display_options['fields']['field_signups_max']['settings'] = array(
    'thousand_separator' => ' ',
    'prefix_suffix' => 1,
  );
  /* Field: Content: Email address */
  $handler->display->display_options['fields']['field_email']['id'] = 'field_email';
  $handler->display->display_options['fields']['field_email']['table'] = 'field_data_field_email';
  $handler->display->display_options['fields']['field_email']['field'] = 'field_email';
  $handler->display->display_options['fields']['field_email']['label'] = 'Staff Email';
  $handler->display->display_options['fields']['field_email']['type'] = 'email_default';
  /* Field: Location: City */
  $handler->display->display_options['fields']['city']['id'] = 'city';
  $handler->display->display_options['fields']['city']['table'] = 'location';
  $handler->display->display_options['fields']['city']['field'] = 'city';
  $handler->display->display_options['fields']['city']['relationship'] = 'field_site_nid';
  $handler->display->display_options['fields']['city']['exclude'] = TRUE;
  /* Field: Location: Postal Code */
  $handler->display->display_options['fields']['postal_code']['id'] = 'postal_code';
  $handler->display->display_options['fields']['postal_code']['table'] = 'location';
  $handler->display->display_options['fields']['postal_code']['field'] = 'postal_code';
  $handler->display->display_options['fields']['postal_code']['relationship'] = 'field_site_nid';
  $handler->display->display_options['fields']['postal_code']['exclude'] = TRUE;
  /* Field: Location: Province */
  $handler->display->display_options['fields']['province']['id'] = 'province';
  $handler->display->display_options['fields']['province']['table'] = 'location';
  $handler->display->display_options['fields']['province']['field'] = 'province';
  $handler->display->display_options['fields']['province']['relationship'] = 'field_site_nid';
  $handler->display->display_options['fields']['province']['exclude'] = TRUE;
  /* Field: Location: Street */
  $handler->display->display_options['fields']['street']['id'] = 'street';
  $handler->display->display_options['fields']['street']['table'] = 'location';
  $handler->display->display_options['fields']['street']['field'] = 'street';
  $handler->display->display_options['fields']['street']['relationship'] = 'field_site_nid';
  $handler->display->display_options['fields']['street']['label'] = 'Address';
  $handler->display->display_options['fields']['street']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['street']['alter']['text'] = '[street]<br/>
[city], [province]&nbsp;&nbsp; [postal_code]';
  $handler->display->display_options['fields']['street']['empty'] = '&nbsp;';
  /* Field: Content: Federal district */
  $handler->display->display_options['fields']['field_district_federal']['id'] = 'field_district_federal';
  $handler->display->display_options['fields']['field_district_federal']['table'] = 'field_data_field_district_federal';
  $handler->display->display_options['fields']['field_district_federal']['field'] = 'field_district_federal';
  $handler->display->display_options['fields']['field_district_federal']['relationship'] = 'field_site_nid';
  $handler->display->display_options['fields']['field_district_federal']['label'] = 'Legislative District: Federal';
  $handler->display->display_options['fields']['field_district_federal']['hide_alter_empty'] = FALSE;
  /* Field: Content: State lower district */
  $handler->display->display_options['fields']['field_district_state_lower']['id'] = 'field_district_state_lower';
  $handler->display->display_options['fields']['field_district_state_lower']['table'] = 'field_data_field_district_state_lower';
  $handler->display->display_options['fields']['field_district_state_lower']['field'] = 'field_district_state_lower';
  $handler->display->display_options['fields']['field_district_state_lower']['relationship'] = 'field_site_nid';
  $handler->display->display_options['fields']['field_district_state_lower']['label'] = 'Legislative District: Lower state district';
  $handler->display->display_options['fields']['field_district_state_lower']['hide_alter_empty'] = FALSE;
  /* Field: Content: State upper district */
  $handler->display->display_options['fields']['field_district_state_upper']['id'] = 'field_district_state_upper';
  $handler->display->display_options['fields']['field_district_state_upper']['table'] = 'field_data_field_district_state_upper';
  $handler->display->display_options['fields']['field_district_state_upper']['field'] = 'field_district_state_upper';
  $handler->display->display_options['fields']['field_district_state_upper']['relationship'] = 'field_site_nid';
  $handler->display->display_options['fields']['field_district_state_upper']['label'] = 'Legislative District: State upper';
  $handler->display->display_options['fields']['field_district_state_upper']['hide_alter_empty'] = FALSE;
  /* Field: Content: Issues addressed */
  $handler->display->display_options['fields']['field_csu_facility']['id'] = 'field_csu_facility';
  $handler->display->display_options['fields']['field_csu_facility']['table'] = 'field_data_field_csu_facility';
  $handler->display->display_options['fields']['field_csu_facility']['field'] = 'field_csu_facility';
  $handler->display->display_options['fields']['field_csu_facility']['relationship'] = 'field_site_nid';
  $handler->display->display_options['fields']['field_csu_facility']['label'] = 'Issues addressed ';
  $handler->display->display_options['fields']['field_csu_facility']['hide_alter_empty'] = FALSE;
  $handler->display->display_options['fields']['field_csu_facility']['delta_offset'] = '0';
  /* Field: Content: Organization type */
  $handler->display->display_options['fields']['field_csu_org_type']['id'] = 'field_csu_org_type';
  $handler->display->display_options['fields']['field_csu_org_type']['table'] = 'field_data_field_csu_org_type';
  $handler->display->display_options['fields']['field_csu_org_type']['field'] = 'field_csu_org_type';
  $handler->display->display_options['fields']['field_csu_org_type']['relationship'] = 'field_site_nid';
  $handler->display->display_options['fields']['field_csu_org_type']['hide_alter_empty'] = FALSE;
  $handler->display->display_options['fields']['field_csu_org_type']['type'] = 'taxonomy_term_reference_plain';
  $handler->display->display_options['fields']['field_csu_org_type']['delta_offset'] = '0';
  /* Field: Content: Tags */
  $handler->display->display_options['fields']['field_tags']['id'] = 'field_tags';
  $handler->display->display_options['fields']['field_tags']['table'] = 'field_data_field_tags';
  $handler->display->display_options['fields']['field_tags']['field'] = 'field_tags';
  $handler->display->display_options['fields']['field_tags']['relationship'] = 'field_site_nid';
  $handler->display->display_options['fields']['field_tags']['label'] = 'Tags ';
  $handler->display->display_options['fields']['field_tags']['hide_alter_empty'] = FALSE;
  $handler->display->display_options['fields']['field_tags']['type'] = 'taxonomy_term_reference_plain';
  $handler->display->display_options['fields']['field_tags']['delta_offset'] = '0';
  /* Field: Field: Available programs */
  $handler->display->display_options['fields']['field_site_restrict']['id'] = 'field_site_restrict';
  $handler->display->display_options['fields']['field_site_restrict']['table'] = 'field_data_field_site_restrict';
  $handler->display->display_options['fields']['field_site_restrict']['field'] = 'field_site_restrict';
  $handler->display->display_options['fields']['field_site_restrict']['relationship'] = 'field_site_nid';
  $handler->display->display_options['fields']['field_site_restrict']['label'] = 'Site programs';
  $handler->display->display_options['fields']['field_site_restrict']['hide_alter_empty'] = FALSE;
  $handler->display->display_options['fields']['field_site_restrict']['type'] = 'taxonomy_term_reference_plain';
  $handler->display->display_options['fields']['field_site_restrict']['delta_offset'] = '0';
  /* Sort criterion: Field: Last Name (field_last_name) */
  $handler->display->display_options['sorts']['field_last_name_value']['id'] = 'field_last_name_value';
  $handler->display->display_options['sorts']['field_last_name_value']['table'] = 'field_data_field_last_name';
  $handler->display->display_options['sorts']['field_last_name_value']['field'] = 'field_last_name_value';
  /* Sort criterion: Field: First Name (field_first_name) */
  $handler->display->display_options['sorts']['field_first_name_value']['id'] = 'field_first_name_value';
  $handler->display->display_options['sorts']['field_first_name_value']['table'] = 'field_data_field_first_name';
  $handler->display->display_options['sorts']['field_first_name_value']['field'] = 'field_first_name_value';
  /* Sort criterion: Content: Post date */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'node';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = '1';
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['exposed'] = TRUE;
  $handler->display->display_options['filters']['status']['expose']['operator_id'] = '';
  $handler->display->display_options['filters']['status']['expose']['label'] = 'Staff is published';
  $handler->display->display_options['filters']['status']['expose']['operator'] = 'status_op';
  $handler->display->display_options['filters']['status']['expose']['identifier'] = 'status';
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'coordinator' => 'coordinator',
  );
  $handler->display->display_options['filters']['type']['group'] = 1;
  /* Filter criterion: Location: City */
  $handler->display->display_options['filters']['city']['id'] = 'city';
  $handler->display->display_options['filters']['city']['table'] = 'location';
  $handler->display->display_options['filters']['city']['field'] = 'city';
  $handler->display->display_options['filters']['city']['relationship'] = 'field_site_nid';
  $handler->display->display_options['filters']['city']['operator'] = 'contains';
  $handler->display->display_options['filters']['city']['group'] = 1;
  $handler->display->display_options['filters']['city']['exposed'] = TRUE;
  $handler->display->display_options['filters']['city']['expose']['operator_id'] = 'city_op';
  $handler->display->display_options['filters']['city']['expose']['label'] = 'City';
  $handler->display->display_options['filters']['city']['expose']['operator'] = 'city_op';
  $handler->display->display_options['filters']['city']['expose']['identifier'] = 'city';
  /* Filter criterion: Content: Issues addressed (field_csu_facility) */
  $handler->display->display_options['filters']['field_csu_facility_tid']['id'] = 'field_csu_facility_tid';
  $handler->display->display_options['filters']['field_csu_facility_tid']['table'] = 'field_data_field_csu_facility';
  $handler->display->display_options['filters']['field_csu_facility_tid']['field'] = 'field_csu_facility_tid';
  $handler->display->display_options['filters']['field_csu_facility_tid']['relationship'] = 'field_site_nid';
  $handler->display->display_options['filters']['field_csu_facility_tid']['group'] = 1;
  $handler->display->display_options['filters']['field_csu_facility_tid']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_csu_facility_tid']['expose']['operator_id'] = 'field_csu_facility_tid_op';
  $handler->display->display_options['filters']['field_csu_facility_tid']['expose']['label'] = 'Issues addressed';
  $handler->display->display_options['filters']['field_csu_facility_tid']['expose']['operator'] = 'field_csu_facility_tid_op';
  $handler->display->display_options['filters']['field_csu_facility_tid']['expose']['identifier'] = 'field_csu_facility_tid';
  $handler->display->display_options['filters']['field_csu_facility_tid']['expose']['multiple'] = TRUE;
  $handler->display->display_options['filters']['field_csu_facility_tid']['type'] = 'select';
  $handler->display->display_options['filters']['field_csu_facility_tid']['vocabulary'] = 'issues_addressed';
  /* Filter criterion: Content: Organization type (field_csu_org_type) */
  $handler->display->display_options['filters']['field_csu_org_type_tid']['id'] = 'field_csu_org_type_tid';
  $handler->display->display_options['filters']['field_csu_org_type_tid']['table'] = 'field_data_field_csu_org_type';
  $handler->display->display_options['filters']['field_csu_org_type_tid']['field'] = 'field_csu_org_type_tid';
  $handler->display->display_options['filters']['field_csu_org_type_tid']['relationship'] = 'field_site_nid';
  $handler->display->display_options['filters']['field_csu_org_type_tid']['group'] = 1;
  $handler->display->display_options['filters']['field_csu_org_type_tid']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_csu_org_type_tid']['expose']['operator_id'] = 'field_csu_org_type_tid_op';
  $handler->display->display_options['filters']['field_csu_org_type_tid']['expose']['label'] = 'Org. type';
  $handler->display->display_options['filters']['field_csu_org_type_tid']['expose']['operator'] = 'field_csu_org_type_tid_op';
  $handler->display->display_options['filters']['field_csu_org_type_tid']['expose']['identifier'] = 'field_csu_org_type_tid';
  $handler->display->display_options['filters']['field_csu_org_type_tid']['expose']['multiple'] = TRUE;
  $handler->display->display_options['filters']['field_csu_org_type_tid']['type'] = 'select';
  $handler->display->display_options['filters']['field_csu_org_type_tid']['vocabulary'] = 'organization_type';
  $handler->display->display_options['filters']['field_csu_org_type_tid']['error_message'] = FALSE;
  /* Filter criterion: Content: Dynamic Fields */
  $handler->display->display_options['filters']['dyfield']['id'] = 'dyfield';
  $handler->display->display_options['filters']['dyfield']['table'] = 'node';
  $handler->display->display_options['filters']['dyfield']['field'] = 'dyfield';
  $handler->display->display_options['filters']['dyfield']['group'] = 1;
  $handler->display->display_options['filters']['dyfield']['exposed'] = TRUE;
  $handler->display->display_options['filters']['dyfield']['expose']['operator_id'] = '';
  $handler->display->display_options['filters']['dyfield']['expose']['label'] = 'Fields';
  $handler->display->display_options['filters']['dyfield']['expose']['operator'] = 'dyfield_op';
  $handler->display->display_options['filters']['dyfield']['expose']['identifier'] = 'dyfield';
  $handler->display->display_options['filters']['dyfield']['filterable_fields'] = array(
    'views_bulk_operations' => 'views_bulk_operations',
    'field_last_name' => 'field_last_name',
    'field_first_name' => 'field_first_name',
    'title' => 'title',
    'field_staff_role' => 'field_staff_role',
    'field_site_restrict_1' => 'field_site_restrict_1',
    'field_phone' => 'field_phone',
    'field_staff_signup_available' => 'field_staff_signup_available',
    'field_signups_max' => 'field_signups_max',
    'field_email' => 'field_email',
    'street' => 'street',
    'field_district_federal' => 'field_district_federal',
    'field_district_state_lower' => 'field_district_state_lower',
    'field_district_state_upper' => 'field_district_state_upper',
    'field_csu_facility' => 'field_csu_facility',
    'field_csu_org_type' => 'field_csu_org_type',
    'field_tags' => 'field_tags',
    'field_site_restrict' => 'field_site_restrict',
  );
  $handler->display->display_options['filters']['dyfield']['defaults_filterable_fields'] = array(
    'views_bulk_operations' => 'views_bulk_operations',
    'field_last_name' => 'field_last_name',
    'field_first_name' => 'field_first_name',
    'title' => 'title',
    'field_staff_role' => 'field_staff_role',
    'field_site_restrict_1' => 'field_site_restrict_1',
    'field_phone' => 0,
    'field_staff_signup_available' => 0,
    'field_signups_max' => 0,
    'field_email' => 0,
    'street' => 0,
    'field_district_federal' => 0,
    'field_district_state_lower' => 0,
    'field_district_state_upper' => 0,
    'field_csu_facility' => 0,
    'field_csu_org_type' => 0,
    'field_tags' => 0,
    'field_site_restrict' => 0,
  );
  $handler->display->display_options['filters']['dyfield']['sortability'] = 1;
  $handler->display->display_options['filters']['dyfield']['checkboxes'] = 0;
  /* Filter criterion: Content: Term (field_term) */
  $handler->display->display_options['filters']['field_term_nid']['id'] = 'field_term_nid';
  $handler->display->display_options['filters']['field_term_nid']['table'] = 'field_data_field_term';
  $handler->display->display_options['filters']['field_term_nid']['field'] = 'field_term_nid';
  $handler->display->display_options['filters']['field_term_nid']['relationship'] = 'field_course_nid';
  $handler->display->display_options['filters']['field_term_nid']['group'] = 1;
  $handler->display->display_options['filters']['field_term_nid']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_term_nid']['expose']['operator_id'] = 'field_term_nid_op';
  $handler->display->display_options['filters']['field_term_nid']['expose']['label'] = 'Had a student in';
  $handler->display->display_options['filters']['field_term_nid']['expose']['operator'] = 'field_term_nid_op';
  $handler->display->display_options['filters']['field_term_nid']['expose']['identifier'] = 'field_term_nid';
  $handler->display->display_options['filters']['field_term_nid']['expose']['remember'] = TRUE;
  $handler->display->display_options['filters']['field_term_nid']['expose']['multiple'] = TRUE;
  /* Filter criterion: Content: Federal district (field_district_federal) */
  $handler->display->display_options['filters']['field_district_federal_value']['id'] = 'field_district_federal_value';
  $handler->display->display_options['filters']['field_district_federal_value']['table'] = 'field_data_field_district_federal';
  $handler->display->display_options['filters']['field_district_federal_value']['field'] = 'field_district_federal_value';
  $handler->display->display_options['filters']['field_district_federal_value']['relationship'] = 'field_site_nid';
  $handler->display->display_options['filters']['field_district_federal_value']['operator'] = 'contains';
  $handler->display->display_options['filters']['field_district_federal_value']['group'] = 1;
  $handler->display->display_options['filters']['field_district_federal_value']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_district_federal_value']['expose']['operator_id'] = 'field_district_federal_value_op';
  $handler->display->display_options['filters']['field_district_federal_value']['expose']['label'] = 'Federal district';
  $handler->display->display_options['filters']['field_district_federal_value']['expose']['operator'] = 'field_district_federal_value_op';
  $handler->display->display_options['filters']['field_district_federal_value']['expose']['identifier'] = 'field_district_federal_value';
  /* Filter criterion: Content: State lower district (field_district_state_lower) */
  $handler->display->display_options['filters']['field_district_state_lower_value']['id'] = 'field_district_state_lower_value';
  $handler->display->display_options['filters']['field_district_state_lower_value']['table'] = 'field_data_field_district_state_lower';
  $handler->display->display_options['filters']['field_district_state_lower_value']['field'] = 'field_district_state_lower_value';
  $handler->display->display_options['filters']['field_district_state_lower_value']['relationship'] = 'field_site_nid';
  $handler->display->display_options['filters']['field_district_state_lower_value']['operator'] = 'contains';
  $handler->display->display_options['filters']['field_district_state_lower_value']['group'] = 1;
  $handler->display->display_options['filters']['field_district_state_lower_value']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_district_state_lower_value']['expose']['operator_id'] = 'field_district_state_lower_value_op';
  $handler->display->display_options['filters']['field_district_state_lower_value']['expose']['label'] = 'State lower district';
  $handler->display->display_options['filters']['field_district_state_lower_value']['expose']['operator'] = 'field_district_state_lower_value_op';
  $handler->display->display_options['filters']['field_district_state_lower_value']['expose']['identifier'] = 'field_district_state_lower_value';
  /* Filter criterion: Content: State upper district (field_district_state_upper) */
  $handler->display->display_options['filters']['field_district_state_upper_value']['id'] = 'field_district_state_upper_value';
  $handler->display->display_options['filters']['field_district_state_upper_value']['table'] = 'field_data_field_district_state_upper';
  $handler->display->display_options['filters']['field_district_state_upper_value']['field'] = 'field_district_state_upper_value';
  $handler->display->display_options['filters']['field_district_state_upper_value']['relationship'] = 'field_site_nid';
  $handler->display->display_options['filters']['field_district_state_upper_value']['operator'] = 'contains';
  $handler->display->display_options['filters']['field_district_state_upper_value']['group'] = 1;
  $handler->display->display_options['filters']['field_district_state_upper_value']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_district_state_upper_value']['expose']['operator_id'] = 'field_district_state_upper_value_op';
  $handler->display->display_options['filters']['field_district_state_upper_value']['expose']['label'] = 'State upper district';
  $handler->display->display_options['filters']['field_district_state_upper_value']['expose']['operator'] = 'field_district_state_upper_value_op';
  $handler->display->display_options['filters']['field_district_state_upper_value']['expose']['identifier'] = 'field_district_state_upper_value';
  /* Filter criterion: Location: Distance / Proximity */
  $handler->display->display_options['filters']['distance']['id'] = 'distance';
  $handler->display->display_options['filters']['distance']['table'] = 'location';
  $handler->display->display_options['filters']['distance']['field'] = 'distance';
  $handler->display->display_options['filters']['distance']['relationship'] = 'field_site_nid';
  $handler->display->display_options['filters']['distance']['operator'] = 'dist';
  $handler->display->display_options['filters']['distance']['value'] = array(
    'latitude' => '',
    'longitude' => '',
    'postal_code' => '',
    'country' => '',
    'php_code' => '',
    'nid_arg' => '',
    'nid_loc_field' => 'node',
    'uid_arg' => '',
    'search_distance' => '',
    'search_units' => 'mile',
  );
  $handler->display->display_options['filters']['distance']['group'] = 1;
  $handler->display->display_options['filters']['distance']['exposed'] = TRUE;
  $handler->display->display_options['filters']['distance']['expose']['operator_id'] = 'distance_op';
  $handler->display->display_options['filters']['distance']['expose']['label'] = 'Distance / Proximity';
  $handler->display->display_options['filters']['distance']['expose']['operator'] = 'distance_op';
  $handler->display->display_options['filters']['distance']['expose']['identifier'] = 'distance';
  $handler->display->display_options['filters']['distance']['expose']['gmap_macro'] = array(
    'default' => '[gmap ]',
  );
  $handler->display->display_options['filters']['distance']['expose']['user_location_choose'] = array(
    'default' => FALSE,
  );
  $handler->display->display_options['filters']['distance']['origin'] = 'latlon_gmap';
  /* Filter criterion: Field: Available programs (field_site_restrict) */
  $handler->display->display_options['filters']['field_site_restrict_tid']['id'] = 'field_site_restrict_tid';
  $handler->display->display_options['filters']['field_site_restrict_tid']['table'] = 'field_data_field_site_restrict';
  $handler->display->display_options['filters']['field_site_restrict_tid']['field'] = 'field_site_restrict_tid';
  $handler->display->display_options['filters']['field_site_restrict_tid']['relationship'] = 'field_site_nid';
  $handler->display->display_options['filters']['field_site_restrict_tid']['group'] = 1;
  $handler->display->display_options['filters']['field_site_restrict_tid']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_site_restrict_tid']['expose']['operator_id'] = 'field_site_restrict_tid_op';
  $handler->display->display_options['filters']['field_site_restrict_tid']['expose']['label'] = 'Site available programs';
  $handler->display->display_options['filters']['field_site_restrict_tid']['expose']['operator'] = 'field_site_restrict_tid_op';
  $handler->display->display_options['filters']['field_site_restrict_tid']['expose']['identifier'] = 'field_site_restrict_tid';
  $handler->display->display_options['filters']['field_site_restrict_tid']['expose']['multiple'] = TRUE;
  $handler->display->display_options['filters']['field_site_restrict_tid']['type'] = 'select';
  $handler->display->display_options['filters']['field_site_restrict_tid']['vocabulary'] = 'site_restrictions';
  /* Filter criterion: Content: Tags (field_tags) */
  $handler->display->display_options['filters']['field_tags_tid']['id'] = 'field_tags_tid';
  $handler->display->display_options['filters']['field_tags_tid']['table'] = 'field_data_field_tags';
  $handler->display->display_options['filters']['field_tags_tid']['field'] = 'field_tags_tid';
  $handler->display->display_options['filters']['field_tags_tid']['relationship'] = 'field_site_nid';
  $handler->display->display_options['filters']['field_tags_tid']['value'] = '';
  $handler->display->display_options['filters']['field_tags_tid']['group'] = 1;
  $handler->display->display_options['filters']['field_tags_tid']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_tags_tid']['expose']['operator_id'] = 'field_tags_tid_op';
  $handler->display->display_options['filters']['field_tags_tid']['expose']['label'] = 'Site tags';
  $handler->display->display_options['filters']['field_tags_tid']['expose']['use_operator'] = TRUE;
  $handler->display->display_options['filters']['field_tags_tid']['expose']['operator'] = 'field_tags_tid_op';
  $handler->display->display_options['filters']['field_tags_tid']['expose']['identifier'] = 'field_tags_tid';
  $handler->display->display_options['filters']['field_tags_tid']['expose']['multiple'] = TRUE;
  $handler->display->display_options['filters']['field_tags_tid']['reduce_duplicates'] = TRUE;
  $handler->display->display_options['filters']['field_tags_tid']['vocabulary'] = 'tags';
  /* Filter criterion: Content: First day of service (field_signup_start_date) */
  $handler->display->display_options['filters']['field_signup_start_date_value']['id'] = 'field_signup_start_date_value';
  $handler->display->display_options['filters']['field_signup_start_date_value']['table'] = 'field_data_field_signup_start_date';
  $handler->display->display_options['filters']['field_signup_start_date_value']['field'] = 'field_signup_start_date_value';
  $handler->display->display_options['filters']['field_signup_start_date_value']['relationship'] = 'reverse_field_coordinator_node';
  $handler->display->display_options['filters']['field_signup_start_date_value']['operator'] = 'between';
  $handler->display->display_options['filters']['field_signup_start_date_value']['group'] = 1;
  $handler->display->display_options['filters']['field_signup_start_date_value']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_signup_start_date_value']['expose']['operator_id'] = 'field_signup_start_date_value_op';
  $handler->display->display_options['filters']['field_signup_start_date_value']['expose']['label'] = 'Site had at least one student between the following dates';
  $handler->display->display_options['filters']['field_signup_start_date_value']['expose']['operator'] = 'field_signup_start_date_value_op';
  $handler->display->display_options['filters']['field_signup_start_date_value']['expose']['identifier'] = 'field_signup_start_date_value';
  $handler->display->display_options['filters']['field_signup_start_date_value']['granularity'] = 'day';
  $handler->display->display_options['filters']['field_signup_start_date_value']['form_type'] = 'date_select';
  $handler->display->display_options['filters']['field_signup_start_date_value']['default_date'] = '';
  $handler->display->display_options['filters']['field_signup_start_date_value']['default_to_date'] = '';
  $handler->display->display_options['filters']['field_signup_start_date_value']['year_range'] = '-3:+3';
  /* Filter criterion: Content: Subject (field_course_subject) */
  $handler->display->display_options['filters']['field_course_subject_value']['id'] = 'field_course_subject_value';
  $handler->display->display_options['filters']['field_course_subject_value']['table'] = 'field_data_field_course_subject';
  $handler->display->display_options['filters']['field_course_subject_value']['field'] = 'field_course_subject_value';
  $handler->display->display_options['filters']['field_course_subject_value']['relationship'] = 'field_course_nid';
  $handler->display->display_options['filters']['field_course_subject_value']['group'] = 1;
  $handler->display->display_options['filters']['field_course_subject_value']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_course_subject_value']['expose']['operator_id'] = 'field_course_subject_value_op';
  $handler->display->display_options['filters']['field_course_subject_value']['expose']['label'] = 'Who had a student in the following course subject';
  $handler->display->display_options['filters']['field_course_subject_value']['expose']['operator'] = 'field_course_subject_value_op';
  $handler->display->display_options['filters']['field_course_subject_value']['expose']['identifier'] = 'field_course_subject_value';
  /* Filter criterion: Content: Term (field_term) */
  $handler->display->display_options['filters']['field_term_nid_1']['id'] = 'field_term_nid_1';
  $handler->display->display_options['filters']['field_term_nid_1']['table'] = 'field_data_field_term';
  $handler->display->display_options['filters']['field_term_nid_1']['field'] = 'field_term_nid';
  $handler->display->display_options['filters']['field_term_nid_1']['relationship'] = 'field_course_nid';
  $handler->display->display_options['filters']['field_term_nid_1']['group'] = 1;
  $handler->display->display_options['filters']['field_term_nid_1']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_term_nid_1']['expose']['operator_id'] = 'field_term_nid_1_op';
  $handler->display->display_options['filters']['field_term_nid_1']['expose']['label'] = 'Site had a student in the following terms (only applies to students signing up as part of a course)';
  $handler->display->display_options['filters']['field_term_nid_1']['expose']['operator'] = 'field_term_nid_1_op';
  $handler->display->display_options['filters']['field_term_nid_1']['expose']['identifier'] = 'field_term_nid_1';
  $handler->display->display_options['filters']['field_term_nid_1']['expose']['multiple'] = TRUE;
  /* Filter criterion: Content: Site (field_site) */
  $handler->display->display_options['filters']['field_site_nid']['id'] = 'field_site_nid';
  $handler->display->display_options['filters']['field_site_nid']['table'] = 'field_data_field_site';
  $handler->display->display_options['filters']['field_site_nid']['field'] = 'field_site_nid';
  $handler->display->display_options['filters']['field_site_nid']['group'] = 1;
  $handler->display->display_options['filters']['field_site_nid']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_site_nid']['expose']['operator_id'] = 'field_site_nid_op';
  $handler->display->display_options['filters']['field_site_nid']['expose']['label'] = 'Specific sites';
  $handler->display->display_options['filters']['field_site_nid']['expose']['operator'] = 'field_site_nid_op';
  $handler->display->display_options['filters']['field_site_nid']['expose']['identifier'] = 'field_site_nid';
  $handler->display->display_options['filters']['field_site_nid']['expose']['multiple'] = TRUE;
  /* Filter criterion: Content: Students can register with this staff (field_staff_signup_available) */
  $handler->display->display_options['filters']['field_staff_signup_available_value']['id'] = 'field_staff_signup_available_value';
  $handler->display->display_options['filters']['field_staff_signup_available_value']['table'] = 'field_data_field_staff_signup_available';
  $handler->display->display_options['filters']['field_staff_signup_available_value']['field'] = 'field_staff_signup_available_value';
  $handler->display->display_options['filters']['field_staff_signup_available_value']['group'] = 1;
  $handler->display->display_options['filters']['field_staff_signup_available_value']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_staff_signup_available_value']['expose']['operator_id'] = 'field_staff_signup_available_value_op';
  $handler->display->display_options['filters']['field_staff_signup_available_value']['expose']['label'] = 'Staff is available for placements';
  $handler->display->display_options['filters']['field_staff_signup_available_value']['expose']['operator'] = 'field_staff_signup_available_value_op';
  $handler->display->display_options['filters']['field_staff_signup_available_value']['expose']['identifier'] = 'field_staff_signup_available_value';
  /* Filter criterion: Field: Available programs (field_site_restrict) */
  $handler->display->display_options['filters']['field_site_restrict_tid_1']['id'] = 'field_site_restrict_tid_1';
  $handler->display->display_options['filters']['field_site_restrict_tid_1']['table'] = 'field_data_field_site_restrict';
  $handler->display->display_options['filters']['field_site_restrict_tid_1']['field'] = 'field_site_restrict_tid';
  $handler->display->display_options['filters']['field_site_restrict_tid_1']['value'] = '';
  $handler->display->display_options['filters']['field_site_restrict_tid_1']['group'] = 1;
  $handler->display->display_options['filters']['field_site_restrict_tid_1']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_site_restrict_tid_1']['expose']['operator_id'] = 'field_site_restrict_tid_1_op';
  $handler->display->display_options['filters']['field_site_restrict_tid_1']['expose']['label'] = 'Site staff programs';
  $handler->display->display_options['filters']['field_site_restrict_tid_1']['expose']['operator'] = 'field_site_restrict_tid_1_op';
  $handler->display->display_options['filters']['field_site_restrict_tid_1']['expose']['identifier'] = 'field_site_restrict_tid_1';
  $handler->display->display_options['filters']['field_site_restrict_tid_1']['expose']['multiple'] = TRUE;
  $handler->display->display_options['filters']['field_site_restrict_tid_1']['vocabulary'] = 'site_restrictions';
  $handler->display->display_options['filters']['field_site_restrict_tid_1']['error_message'] = FALSE;
  /* Filter criterion: Content: Role (field_staff_role) */
  $handler->display->display_options['filters']['field_staff_role_tid']['id'] = 'field_staff_role_tid';
  $handler->display->display_options['filters']['field_staff_role_tid']['table'] = 'field_data_field_staff_role';
  $handler->display->display_options['filters']['field_staff_role_tid']['field'] = 'field_staff_role_tid';
  $handler->display->display_options['filters']['field_staff_role_tid']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_staff_role_tid']['expose']['operator_id'] = 'field_staff_role_tid_op';
  $handler->display->display_options['filters']['field_staff_role_tid']['expose']['label'] = 'Site staff role';
  $handler->display->display_options['filters']['field_staff_role_tid']['expose']['operator'] = 'field_staff_role_tid_op';
  $handler->display->display_options['filters']['field_staff_role_tid']['expose']['identifier'] = 'field_staff_role_tid';
  $handler->display->display_options['filters']['field_staff_role_tid']['expose']['multiple'] = TRUE;
  $handler->display->display_options['filters']['field_staff_role_tid']['type'] = 'select';
  $handler->display->display_options['filters']['field_staff_role_tid']['vocabulary'] = 'site_staff_role';

  /* Display: Data report page */
  $handler = $view->new_display('page', 'Data report page', 'page');
  $handler->display->display_options['path'] = 'reports/site-staff';
  $handler->display->display_options['menu']['type'] = 'tab';
  $handler->display->display_options['menu']['title'] = 'Site staff';
  $handler->display->display_options['menu']['weight'] = '0';
  $handler->display->display_options['menu']['context'] = 0;
  $handler->display->display_options['tab_options']['type'] = 'normal';
  $handler->display->display_options['tab_options']['title'] = 'Reports';
  $handler->display->display_options['tab_options']['weight'] = '0';

  /* Display: Data export: CSV */
  $handler = $view->new_display('views_data_export', 'Data export: CSV', 'views_data_export_1');
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['style_plugin'] = 'views_data_export_csv';
  $handler->display->display_options['style_options']['provide_file'] = 0;
  $handler->display->display_options['style_options']['parent_sort'] = 0;
  $handler->display->display_options['style_options']['quote'] = 1;
  $handler->display->display_options['style_options']['header'] = 1;
  $handler->display->display_options['path'] = 'reports/sites/export/csv';
  $handler->display->display_options['displays'] = array(
    'default' => 'default',
    'page' => 'page',
  );

  /* Display: Data export: XLS */
  $handler = $view->new_display('views_data_export', 'Data export: XLS', 'views_data_export_2');
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['style_plugin'] = 'views_data_export_xls';
  $handler->display->display_options['style_options']['provide_file'] = 0;
  $handler->display->display_options['style_options']['parent_sort'] = 0;
  $handler->display->display_options['path'] = 'reports/sites/export/xls';
  $handler->display->display_options['displays'] = array(
    'default' => 'default',
    'page' => 'page',
  );

  /* Display: Data export: DOC */
  $handler = $view->new_display('views_data_export', 'Data export: DOC', 'views_data_export_3');
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['style_plugin'] = 'views_data_export_doc';
  $handler->display->display_options['style_options']['provide_file'] = 0;
  $handler->display->display_options['style_options']['parent_sort'] = 0;
  $handler->display->display_options['path'] = 'reports/sites/export/doc';
  $handler->display->display_options['displays'] = array(
    'default' => 'default',
    'page' => 'page',
  );
  $translatables['reports_site_staff'] = array(
    t('Master'),
    t('Site staff report'),
    t('more'),
    t('Search'),
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
    t('field_coordinator'),
    t('field_course'),
    t('field_site'),
    t('Email'),
    t('Last name'),
    t('First name'),
    t('Site'),
    t('Staff role'),
    t('Staff programs'),
    t('Staff phone'),
    t('Open for placements'),
    t('Staff student limit'),
    t('Staff Email'),
    t('City'),
    t('Postal Code'),
    t('Province'),
    t('Address'),
    t('[street]<br/>
[city], [province]&nbsp;&nbsp; [postal_code]'),
    t('&nbsp;'),
    t('Legislative District: Federal'),
    t('Legislative District: Lower state district'),
    t('Legislative District: State upper'),
    t('Issues addressed '),
    t('Organization type'),
    t('Tags '),
    t('Site programs'),
    t('Staff is published'),
    t('Issues addressed'),
    t('Org. type'),
    t('Fields'),
    t('Had a student in'),
    t('Federal district'),
    t('State lower district'),
    t('State upper district'),
    t('Distance / Proximity'),
    t('[gmap ]'),
    t('Site available programs'),
    t('Site tags'),
    t('Site had at least one student between the following dates'),
    t('Who had a student in the following course subject'),
    t('Site had a student in the following terms (only applies to students signing up as part of a course)'),
    t('Specific sites'),
    t('Staff is available for placements'),
    t('Site staff programs'),
    t('Site staff role'),
    t('Data report page'),
    t('Data export: CSV'),
    t('Data export: XLS'),
    t('Data export: DOC'),
  );
  $export['reports_site_staff'] = $view;

  $view = new view();
  $view->name = 'reports_sites';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Reports: sites';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Site Report';
  $handler->display->display_options['css_class'] = 'report-view';
  $handler->display->display_options['link_display'] = 'page';
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['access']['perm'] = 'access s4 reporting';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['query']['options']['distinct'] = TRUE;
  $handler->display->display_options['query']['options']['query_comment'] = FALSE;
  $handler->display->display_options['exposed_form']['type'] = 's4_reporting';
  $handler->display->display_options['exposed_form']['options']['submit_button'] = 'Search';
  $handler->display->display_options['exposed_form']['options']['reset_button'] = TRUE;
  $handler->display->display_options['exposed_form']['options']['s4_reporting'] = array(
    'group-city' => '2',
    'group-field_csu_facility_tid' => '1',
    'group-field_csu_org_type_tid' => '1',
    'group-dyfield' => '4',
    'group-field_term_nid' => '1',
    'group-field_district_federal_value' => '2',
    'group-field_district_state_lower_value' => '2',
    'group-field_district_state_upper_value' => '2',
    'group-distance' => '2',
    'group-field_site_restrict_tid' => '0',
    'group-field_tags_tid' => '1',
    'group-field_signup_start_date_value' => '3',
    'group-field_course_subject_value' => '3',
    'group-field_term_nid_1' => '3',
    'group-title' => '0',
    'group-field_signups_max_value' => '0',
    'groups' => 'General
Categories
Location
Placements
Fields',
  );
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '30';
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['columns'] = array(
    'title' => 'title',
    'field_website' => 'field_website',
    'field_site_email' => 'field_site_email',
    'field_phone' => 'field_phone',
    'city' => 'city',
    'postal_code' => 'postal_code',
    'province' => 'province',
    'street' => 'street',
    'field_district_federal' => 'field_district_federal',
    'field_district_state_lower' => 'field_district_state_lower',
    'field_district_state_upper' => 'field_district_state_upper',
    'field_site_users' => 'field_site_users',
    'body' => 'body',
    'field_site_projects' => 'field_site_projects',
    'field_site_demographics' => 'field_site_demographics',
    'field_site_email_1' => 'field_site_email_1',
    'field_site_hours' => 'field_site_hours',
    'field_csu_facility' => 'field_csu_facility',
    'field_signups_max' => 'field_signups_max',
    'field_csu_org_type' => 'field_csu_org_type',
    'field_phone_1' => 'field_phone_1',
    'field_health_risk' => 'field_health_risk',
    'field_site_instructions_required' => 'field_site_instructions_required',
    'field_site_requirements' => 'field_site_requirements',
    'field_site_tour' => 'field_site_tour',
    'field_site_facebook_page' => 'field_site_facebook_page',
    'field_site_instructions' => 'field_site_instructions',
    'field_tags' => 'field_tags',
    'field_site_health_training' => 'field_site_health_training',
    'field_website_1' => 'field_website_1',
    'field_site_hours_minimum' => 'field_site_hours_minimum',
    'field_site_language' => 'field_site_language',
    'field_site_restrict' => 'field_site_restrict',
  );
  $handler->display->display_options['style_options']['default'] = '-1';
  $handler->display->display_options['style_options']['info'] = array(
    'title' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_website' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_site_email' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_phone' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'city' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'postal_code' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'province' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'street' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_district_federal' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_district_state_lower' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_district_state_upper' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_site_users' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'body' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_site_projects' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_site_demographics' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_site_email_1' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_site_hours' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_csu_facility' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_signups_max' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_csu_org_type' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_phone_1' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_health_risk' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_site_instructions_required' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_site_requirements' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_site_tour' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_site_facebook_page' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_site_instructions' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_tags' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_site_health_training' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_website_1' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_site_hours_minimum' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_site_language' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_site_restrict' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
  );
  /* Relationship: Content: Site (field_site) - reverse */
  $handler->display->display_options['relationships']['reverse_field_site_node']['id'] = 'reverse_field_site_node';
  $handler->display->display_options['relationships']['reverse_field_site_node']['table'] = 'node';
  $handler->display->display_options['relationships']['reverse_field_site_node']['field'] = 'reverse_field_site_node';
  /* Relationship: Content: Course (field_course) */
  $handler->display->display_options['relationships']['field_course_nid']['id'] = 'field_course_nid';
  $handler->display->display_options['relationships']['field_course_nid']['table'] = 'field_data_field_course';
  $handler->display->display_options['relationships']['field_course_nid']['field'] = 'field_course_nid';
  $handler->display->display_options['relationships']['field_course_nid']['relationship'] = 'reverse_field_site_node';
  $handler->display->display_options['relationships']['field_course_nid']['delta'] = '-1';
  /* Field: Bulk operations: Content */
  $handler->display->display_options['fields']['views_bulk_operations']['id'] = 'views_bulk_operations';
  $handler->display->display_options['fields']['views_bulk_operations']['table'] = 'node';
  $handler->display->display_options['fields']['views_bulk_operations']['field'] = 'views_bulk_operations';
  $handler->display->display_options['fields']['views_bulk_operations']['label'] = 'Bulk operations';
  $handler->display->display_options['fields']['views_bulk_operations']['vbo']['entity_load_capacity'] = '3';
  $handler->display->display_options['fields']['views_bulk_operations']['vbo']['operations'] = array(
    'action::node_assign_owner_action' => array(
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
    'action::node_make_sticky_action' => array(
      'selected' => 0,
      'use_queue' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
    'action::node_make_unsticky_action' => array(
      'selected' => 0,
      'use_queue' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
    'action::views_bulk_operations_modify_action' => array(
      'selected' => 0,
      'use_queue' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
      'settings' => array(
        'show_all_tokens' => 1,
        'display_values' => array(
          '_all_' => '_all_',
        ),
      ),
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
    'action::node_promote_action' => array(
      'selected' => 0,
      'use_queue' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
    'action::node_publish_action' => array(
      'selected' => 0,
      'use_queue' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
    'action::system_goto_action' => array(
      'selected' => 0,
      'use_queue' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
    'action::node_unpromote_action' => array(
      'selected' => 0,
      'use_queue' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
    'action::s4_reporting_forms_site' => array(
      'selected' => 1,
      'use_queue' => 0,
      'skip_confirmation' => 0,
      'override_label' => 1,
      'label' => 'Run form report',
    ),
    'action::s4_reporting_forms_signup' => array(
      'selected' => 0,
      'use_queue' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
    'action::node_save_action' => array(
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
    'action::s4_core_email_site_action' => array(
      'selected' => 1,
      'use_queue' => 0,
      'skip_confirmation' => 0,
      'override_label' => 1,
      'label' => 'Send email to main site contact',
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
      'selected' => 0,
      'use_queue' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
    'action::node_unpublish_action' => array(
      'selected' => 0,
      'use_queue' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
    'action::node_unpublish_by_keyword_action' => array(
      'selected' => 0,
      'use_queue' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
  );
  $handler->display->display_options['fields']['views_bulk_operations']['vbo']['enable_select_all_pages'] = 1;
  $handler->display->display_options['fields']['views_bulk_operations']['vbo']['display_type'] = '1';
  $handler->display->display_options['fields']['views_bulk_operations']['vbo']['display_result'] = 1;
  $handler->display->display_options['fields']['views_bulk_operations']['vbo']['force_single'] = 0;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = 'Site';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['title']['hide_alter_empty'] = FALSE;
  /* Field: Content: Website */
  $handler->display->display_options['fields']['field_website']['id'] = 'field_website';
  $handler->display->display_options['fields']['field_website']['table'] = 'field_data_field_website';
  $handler->display->display_options['fields']['field_website']['field'] = 'field_website';
  $handler->display->display_options['fields']['field_website']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_website']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_website']['alter']['text'] = '<strong>Website:</strong> <a href="[field_website-url]">View website</a>';
  $handler->display->display_options['fields']['field_website']['click_sort_column'] = 'url';
  /* Field: Content: Contact email */
  $handler->display->display_options['fields']['field_site_email']['id'] = 'field_site_email';
  $handler->display->display_options['fields']['field_site_email']['table'] = 'field_data_field_site_email';
  $handler->display->display_options['fields']['field_site_email']['field'] = 'field_site_email';
  $handler->display->display_options['fields']['field_site_email']['label'] = 'Email';
  $handler->display->display_options['fields']['field_site_email']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_site_email']['type'] = 'email_default';
  /* Field: Content: Phone number */
  $handler->display->display_options['fields']['field_phone']['id'] = 'field_phone';
  $handler->display->display_options['fields']['field_phone']['table'] = 'field_data_field_phone';
  $handler->display->display_options['fields']['field_phone']['field'] = 'field_phone';
  $handler->display->display_options['fields']['field_phone']['label'] = 'Contact';
  $handler->display->display_options['fields']['field_phone']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_phone']['alter']['text'] = '<strong>Phone:</strong> [field_phone]<br/>
<strong>Email:</strong> [field_site_email]<br/>
[field_website]';
  $handler->display->display_options['fields']['field_phone']['click_sort_column'] = 'number';
  /* Field: Location: City */
  $handler->display->display_options['fields']['city']['id'] = 'city';
  $handler->display->display_options['fields']['city']['table'] = 'location';
  $handler->display->display_options['fields']['city']['field'] = 'city';
  $handler->display->display_options['fields']['city']['exclude'] = TRUE;
  /* Field: Location: Postal Code */
  $handler->display->display_options['fields']['postal_code']['id'] = 'postal_code';
  $handler->display->display_options['fields']['postal_code']['table'] = 'location';
  $handler->display->display_options['fields']['postal_code']['field'] = 'postal_code';
  $handler->display->display_options['fields']['postal_code']['exclude'] = TRUE;
  /* Field: Location: Province */
  $handler->display->display_options['fields']['province']['id'] = 'province';
  $handler->display->display_options['fields']['province']['table'] = 'location';
  $handler->display->display_options['fields']['province']['field'] = 'province';
  $handler->display->display_options['fields']['province']['exclude'] = TRUE;
  /* Field: Location: Street */
  $handler->display->display_options['fields']['street']['id'] = 'street';
  $handler->display->display_options['fields']['street']['table'] = 'location';
  $handler->display->display_options['fields']['street']['field'] = 'street';
  $handler->display->display_options['fields']['street']['label'] = 'Address';
  $handler->display->display_options['fields']['street']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['street']['alter']['text'] = '[street]<br/>
[city], [province]&nbsp;&nbsp; [postal_code]';
  $handler->display->display_options['fields']['street']['empty'] = '&nbsp;';
  /* Field: Content: Federal district */
  $handler->display->display_options['fields']['field_district_federal']['id'] = 'field_district_federal';
  $handler->display->display_options['fields']['field_district_federal']['table'] = 'field_data_field_district_federal';
  $handler->display->display_options['fields']['field_district_federal']['field'] = 'field_district_federal';
  $handler->display->display_options['fields']['field_district_federal']['label'] = 'Legislative District: Federal';
  $handler->display->display_options['fields']['field_district_federal']['hide_alter_empty'] = FALSE;
  /* Field: Content: State lower district */
  $handler->display->display_options['fields']['field_district_state_lower']['id'] = 'field_district_state_lower';
  $handler->display->display_options['fields']['field_district_state_lower']['table'] = 'field_data_field_district_state_lower';
  $handler->display->display_options['fields']['field_district_state_lower']['field'] = 'field_district_state_lower';
  $handler->display->display_options['fields']['field_district_state_lower']['label'] = 'Legislative District: Lower state district';
  $handler->display->display_options['fields']['field_district_state_lower']['hide_alter_empty'] = FALSE;
  /* Field: Content: State upper district */
  $handler->display->display_options['fields']['field_district_state_upper']['id'] = 'field_district_state_upper';
  $handler->display->display_options['fields']['field_district_state_upper']['table'] = 'field_data_field_district_state_upper';
  $handler->display->display_options['fields']['field_district_state_upper']['field'] = 'field_district_state_upper';
  $handler->display->display_options['fields']['field_district_state_upper']['label'] = 'Legislative District: State upper';
  $handler->display->display_options['fields']['field_district_state_upper']['hide_alter_empty'] = FALSE;
  /* Field: Content: Additional users */
  $handler->display->display_options['fields']['field_site_users']['id'] = 'field_site_users';
  $handler->display->display_options['fields']['field_site_users']['table'] = 'field_data_field_site_users';
  $handler->display->display_options['fields']['field_site_users']['field'] = 'field_site_users';
  $handler->display->display_options['fields']['field_site_users']['label'] = 'Users';
  $handler->display->display_options['fields']['field_site_users']['hide_alter_empty'] = FALSE;
  $handler->display->display_options['fields']['field_site_users']['delta_offset'] = '0';
  /* Field: Content: Body */
  $handler->display->display_options['fields']['body']['id'] = 'body';
  $handler->display->display_options['fields']['body']['table'] = 'field_data_body';
  $handler->display->display_options['fields']['body']['field'] = 'body';
  $handler->display->display_options['fields']['body']['label'] = 'Site description';
  $handler->display->display_options['fields']['body']['hide_alter_empty'] = FALSE;
  /* Field: Content: Briefly describe any ongoing needs or special projects with which students can assist agency staff */
  $handler->display->display_options['fields']['field_site_projects']['id'] = 'field_site_projects';
  $handler->display->display_options['fields']['field_site_projects']['table'] = 'field_data_field_site_projects';
  $handler->display->display_options['fields']['field_site_projects']['field'] = 'field_site_projects';
  $handler->display->display_options['fields']['field_site_projects']['label'] = 'Special projects';
  $handler->display->display_options['fields']['field_site_projects']['hide_alter_empty'] = FALSE;
  /* Field: Content: By percentage, what is the demographic of the population you serve? */
  $handler->display->display_options['fields']['field_site_demographics']['id'] = 'field_site_demographics';
  $handler->display->display_options['fields']['field_site_demographics']['table'] = 'field_data_field_site_demographics';
  $handler->display->display_options['fields']['field_site_demographics']['field'] = 'field_site_demographics';
  $handler->display->display_options['fields']['field_site_demographics']['label'] = 'Demographic';
  $handler->display->display_options['fields']['field_site_demographics']['hide_alter_empty'] = FALSE;
  $handler->display->display_options['fields']['field_site_demographics']['delta_offset'] = '0';
  /* Field: Content: Contact email */
  $handler->display->display_options['fields']['field_site_email_1']['id'] = 'field_site_email_1';
  $handler->display->display_options['fields']['field_site_email_1']['table'] = 'field_data_field_site_email';
  $handler->display->display_options['fields']['field_site_email_1']['field'] = 'field_site_email';
  $handler->display->display_options['fields']['field_site_email_1']['label'] = 'Email';
  $handler->display->display_options['fields']['field_site_email_1']['hide_alter_empty'] = FALSE;
  $handler->display->display_options['fields']['field_site_email_1']['type'] = 'email_default';
  /* Field: Content: Days and hours will you accept students for service (check all that apply) */
  $handler->display->display_options['fields']['field_site_hours']['id'] = 'field_site_hours';
  $handler->display->display_options['fields']['field_site_hours']['table'] = 'field_data_field_site_hours';
  $handler->display->display_options['fields']['field_site_hours']['field'] = 'field_site_hours';
  $handler->display->display_options['fields']['field_site_hours']['label'] = 'Hours';
  $handler->display->display_options['fields']['field_site_hours']['hide_alter_empty'] = FALSE;
  $handler->display->display_options['fields']['field_site_hours']['delta_offset'] = '0';
  /* Field: Content: Issues addressed */
  $handler->display->display_options['fields']['field_csu_facility']['id'] = 'field_csu_facility';
  $handler->display->display_options['fields']['field_csu_facility']['table'] = 'field_data_field_csu_facility';
  $handler->display->display_options['fields']['field_csu_facility']['field'] = 'field_csu_facility';
  $handler->display->display_options['fields']['field_csu_facility']['label'] = 'Issues addressed ';
  $handler->display->display_options['fields']['field_csu_facility']['hide_alter_empty'] = FALSE;
  $handler->display->display_options['fields']['field_csu_facility']['type'] = 'taxonomy_term_reference_plain';
  $handler->display->display_options['fields']['field_csu_facility']['delta_offset'] = '0';
  /* Field: Content: Maximum number of students */
  $handler->display->display_options['fields']['field_signups_max']['id'] = 'field_signups_max';
  $handler->display->display_options['fields']['field_signups_max']['table'] = 'field_data_field_signups_max';
  $handler->display->display_options['fields']['field_signups_max']['field'] = 'field_signups_max';
  $handler->display->display_options['fields']['field_signups_max']['label'] = 'Max students';
  $handler->display->display_options['fields']['field_signups_max']['hide_alter_empty'] = FALSE;
  $handler->display->display_options['fields']['field_signups_max']['settings'] = array(
    'thousand_separator' => ' ',
    'prefix_suffix' => 1,
  );
  /* Field: Content: Organization type */
  $handler->display->display_options['fields']['field_csu_org_type']['id'] = 'field_csu_org_type';
  $handler->display->display_options['fields']['field_csu_org_type']['table'] = 'field_data_field_csu_org_type';
  $handler->display->display_options['fields']['field_csu_org_type']['field'] = 'field_csu_org_type';
  $handler->display->display_options['fields']['field_csu_org_type']['hide_alter_empty'] = FALSE;
  $handler->display->display_options['fields']['field_csu_org_type']['type'] = 'taxonomy_term_reference_plain';
  $handler->display->display_options['fields']['field_csu_org_type']['delta_offset'] = '0';
  /* Field: Content: Phone number */
  $handler->display->display_options['fields']['field_phone_1']['id'] = 'field_phone_1';
  $handler->display->display_options['fields']['field_phone_1']['table'] = 'field_data_field_phone';
  $handler->display->display_options['fields']['field_phone_1']['field'] = 'field_phone';
  $handler->display->display_options['fields']['field_phone_1']['label'] = 'Phone number ';
  $handler->display->display_options['fields']['field_phone_1']['hide_alter_empty'] = FALSE;
  $handler->display->display_options['fields']['field_phone_1']['click_sort_column'] = 'number';
  /* Field: Content: Risk Identification */
  $handler->display->display_options['fields']['field_health_risk']['id'] = 'field_health_risk';
  $handler->display->display_options['fields']['field_health_risk']['table'] = 'field_data_field_health_risk';
  $handler->display->display_options['fields']['field_health_risk']['field'] = 'field_health_risk';
  $handler->display->display_options['fields']['field_health_risk']['label'] = 'Risk Identification ';
  $handler->display->display_options['fields']['field_health_risk']['hide_alter_empty'] = FALSE;
  /* Field: Content: Site has special requirements */
  $handler->display->display_options['fields']['field_site_instructions_required']['id'] = 'field_site_instructions_required';
  $handler->display->display_options['fields']['field_site_instructions_required']['table'] = 'field_data_field_site_instructions_required';
  $handler->display->display_options['fields']['field_site_instructions_required']['field'] = 'field_site_instructions_required';
  $handler->display->display_options['fields']['field_site_instructions_required']['label'] = 'Site has special requirements ';
  $handler->display->display_options['fields']['field_site_instructions_required']['hide_alter_empty'] = FALSE;
  /* Field: Content: Site Tour */
  $handler->display->display_options['fields']['field_site_tour']['id'] = 'field_site_tour';
  $handler->display->display_options['fields']['field_site_tour']['table'] = 'field_data_field_site_tour';
  $handler->display->display_options['fields']['field_site_tour']['field'] = 'field_site_tour';
  $handler->display->display_options['fields']['field_site_tour']['label'] = 'Site Tour ';
  $handler->display->display_options['fields']['field_site_tour']['hide_alter_empty'] = FALSE;
  /* Field: Content: Social network page */
  $handler->display->display_options['fields']['field_site_facebook_page']['id'] = 'field_site_facebook_page';
  $handler->display->display_options['fields']['field_site_facebook_page']['table'] = 'field_data_field_site_facebook_page';
  $handler->display->display_options['fields']['field_site_facebook_page']['field'] = 'field_site_facebook_page';
  $handler->display->display_options['fields']['field_site_facebook_page']['label'] = 'Social network page ';
  $handler->display->display_options['fields']['field_site_facebook_page']['hide_alter_empty'] = FALSE;
  $handler->display->display_options['fields']['field_site_facebook_page']['click_sort_column'] = 'url';
  /* Field: Content: Special site instructions */
  $handler->display->display_options['fields']['field_site_instructions']['id'] = 'field_site_instructions';
  $handler->display->display_options['fields']['field_site_instructions']['table'] = 'field_data_field_site_instructions';
  $handler->display->display_options['fields']['field_site_instructions']['field'] = 'field_site_instructions';
  $handler->display->display_options['fields']['field_site_instructions']['label'] = 'Special site instructions ';
  $handler->display->display_options['fields']['field_site_instructions']['hide_alter_empty'] = FALSE;
  /* Field: Content: Tags */
  $handler->display->display_options['fields']['field_tags']['id'] = 'field_tags';
  $handler->display->display_options['fields']['field_tags']['table'] = 'field_data_field_tags';
  $handler->display->display_options['fields']['field_tags']['field'] = 'field_tags';
  $handler->display->display_options['fields']['field_tags']['label'] = 'Tags ';
  $handler->display->display_options['fields']['field_tags']['hide_alter_empty'] = FALSE;
  $handler->display->display_options['fields']['field_tags']['type'] = 'taxonomy_term_reference_plain';
  $handler->display->display_options['fields']['field_tags']['delta_offset'] = '0';
  /* Field: Content: Training and orientation information */
  $handler->display->display_options['fields']['field_site_health_training']['id'] = 'field_site_health_training';
  $handler->display->display_options['fields']['field_site_health_training']['table'] = 'field_data_field_site_health_training';
  $handler->display->display_options['fields']['field_site_health_training']['field'] = 'field_site_health_training';
  $handler->display->display_options['fields']['field_site_health_training']['label'] = 'Training & orientation ';
  $handler->display->display_options['fields']['field_site_health_training']['hide_alter_empty'] = FALSE;
  /* Field: Content: Website */
  $handler->display->display_options['fields']['field_website_1']['id'] = 'field_website_1';
  $handler->display->display_options['fields']['field_website_1']['table'] = 'field_data_field_website';
  $handler->display->display_options['fields']['field_website_1']['field'] = 'field_website';
  $handler->display->display_options['fields']['field_website_1']['label'] = 'Website ';
  $handler->display->display_options['fields']['field_website_1']['hide_alter_empty'] = FALSE;
  $handler->display->display_options['fields']['field_website_1']['click_sort_column'] = 'url';
  /* Field: Content: What is the minimum number of hours you would require of a student in service per term */
  $handler->display->display_options['fields']['field_site_hours_minimum']['id'] = 'field_site_hours_minimum';
  $handler->display->display_options['fields']['field_site_hours_minimum']['table'] = 'field_data_field_site_hours_minimum';
  $handler->display->display_options['fields']['field_site_hours_minimum']['field'] = 'field_site_hours_minimum';
  $handler->display->display_options['fields']['field_site_hours_minimum']['label'] = 'Minimum hours';
  $handler->display->display_options['fields']['field_site_hours_minimum']['hide_alter_empty'] = FALSE;
  /* Field: Content: What languages would you like students to speak other than English? */
  $handler->display->display_options['fields']['field_site_language']['id'] = 'field_site_language';
  $handler->display->display_options['fields']['field_site_language']['table'] = 'field_data_field_site_language';
  $handler->display->display_options['fields']['field_site_language']['field'] = 'field_site_language';
  $handler->display->display_options['fields']['field_site_language']['label'] = 'Languages';
  $handler->display->display_options['fields']['field_site_language']['hide_alter_empty'] = FALSE;
  $handler->display->display_options['fields']['field_site_language']['delta_offset'] = '0';
  /* Field: Field: Available programs */
  $handler->display->display_options['fields']['field_site_restrict']['id'] = 'field_site_restrict';
  $handler->display->display_options['fields']['field_site_restrict']['table'] = 'field_data_field_site_restrict';
  $handler->display->display_options['fields']['field_site_restrict']['field'] = 'field_site_restrict';
  $handler->display->display_options['fields']['field_site_restrict']['label'] = 'Related programs';
  $handler->display->display_options['fields']['field_site_restrict']['hide_alter_empty'] = FALSE;
  $handler->display->display_options['fields']['field_site_restrict']['type'] = 'taxonomy_term_reference_plain';
  $handler->display->display_options['fields']['field_site_restrict']['delta_offset'] = '0';
  /* Sort criterion: Content: Title */
  $handler->display->display_options['sorts']['title']['id'] = 'title';
  $handler->display->display_options['sorts']['title']['table'] = 'node';
  $handler->display->display_options['sorts']['title']['field'] = 'title';
  /* Sort criterion: Content: Post date */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'node';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'site' => 'site',
  );
  $handler->display->display_options['filters']['type']['group'] = 1;
  /* Filter criterion: Location: City */
  $handler->display->display_options['filters']['city']['id'] = 'city';
  $handler->display->display_options['filters']['city']['table'] = 'location';
  $handler->display->display_options['filters']['city']['field'] = 'city';
  $handler->display->display_options['filters']['city']['operator'] = 'contains';
  $handler->display->display_options['filters']['city']['group'] = 1;
  $handler->display->display_options['filters']['city']['exposed'] = TRUE;
  $handler->display->display_options['filters']['city']['expose']['operator_id'] = 'city_op';
  $handler->display->display_options['filters']['city']['expose']['label'] = 'City';
  $handler->display->display_options['filters']['city']['expose']['operator'] = 'city_op';
  $handler->display->display_options['filters']['city']['expose']['identifier'] = 'city';
  /* Filter criterion: Content: Issues addressed (field_csu_facility) */
  $handler->display->display_options['filters']['field_csu_facility_tid']['id'] = 'field_csu_facility_tid';
  $handler->display->display_options['filters']['field_csu_facility_tid']['table'] = 'field_data_field_csu_facility';
  $handler->display->display_options['filters']['field_csu_facility_tid']['field'] = 'field_csu_facility_tid';
  $handler->display->display_options['filters']['field_csu_facility_tid']['group'] = 1;
  $handler->display->display_options['filters']['field_csu_facility_tid']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_csu_facility_tid']['expose']['operator_id'] = 'field_csu_facility_tid_op';
  $handler->display->display_options['filters']['field_csu_facility_tid']['expose']['label'] = 'Issues addressed';
  $handler->display->display_options['filters']['field_csu_facility_tid']['expose']['operator'] = 'field_csu_facility_tid_op';
  $handler->display->display_options['filters']['field_csu_facility_tid']['expose']['identifier'] = 'field_csu_facility_tid';
  $handler->display->display_options['filters']['field_csu_facility_tid']['expose']['multiple'] = TRUE;
  $handler->display->display_options['filters']['field_csu_facility_tid']['type'] = 'select';
  $handler->display->display_options['filters']['field_csu_facility_tid']['vocabulary'] = 'issues_addressed';
  /* Filter criterion: Content: Organization type (field_csu_org_type) */
  $handler->display->display_options['filters']['field_csu_org_type_tid']['id'] = 'field_csu_org_type_tid';
  $handler->display->display_options['filters']['field_csu_org_type_tid']['table'] = 'field_data_field_csu_org_type';
  $handler->display->display_options['filters']['field_csu_org_type_tid']['field'] = 'field_csu_org_type_tid';
  $handler->display->display_options['filters']['field_csu_org_type_tid']['group'] = 1;
  $handler->display->display_options['filters']['field_csu_org_type_tid']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_csu_org_type_tid']['expose']['operator_id'] = 'field_csu_org_type_tid_op';
  $handler->display->display_options['filters']['field_csu_org_type_tid']['expose']['label'] = 'Org. type';
  $handler->display->display_options['filters']['field_csu_org_type_tid']['expose']['operator'] = 'field_csu_org_type_tid_op';
  $handler->display->display_options['filters']['field_csu_org_type_tid']['expose']['identifier'] = 'field_csu_org_type_tid';
  $handler->display->display_options['filters']['field_csu_org_type_tid']['expose']['multiple'] = TRUE;
  $handler->display->display_options['filters']['field_csu_org_type_tid']['type'] = 'select';
  $handler->display->display_options['filters']['field_csu_org_type_tid']['vocabulary'] = 'organization_type';
  $handler->display->display_options['filters']['field_csu_org_type_tid']['error_message'] = FALSE;
  /* Filter criterion: Content: Dynamic Fields */
  $handler->display->display_options['filters']['dyfield']['id'] = 'dyfield';
  $handler->display->display_options['filters']['dyfield']['table'] = 'node';
  $handler->display->display_options['filters']['dyfield']['field'] = 'dyfield';
  $handler->display->display_options['filters']['dyfield']['group'] = 1;
  $handler->display->display_options['filters']['dyfield']['exposed'] = TRUE;
  $handler->display->display_options['filters']['dyfield']['expose']['operator_id'] = '';
  $handler->display->display_options['filters']['dyfield']['expose']['label'] = 'Fields';
  $handler->display->display_options['filters']['dyfield']['expose']['operator'] = 'dyfield_op';
  $handler->display->display_options['filters']['dyfield']['expose']['identifier'] = 'dyfield';
  $handler->display->display_options['filters']['dyfield']['filterable_fields'] = array(
    'title' => 'title',
    'field_phone' => 'field_phone',
    'street' => 'street',
    'field_district_federal' => 'field_district_federal',
    'field_district_state_lower' => 'field_district_state_lower',
    'field_district_state_upper' => 'field_district_state_upper',
    'field_site_users' => 'field_site_users',
    'body' => 'body',
    'field_site_projects' => 'field_site_projects',
    'field_site_demographics' => 'field_site_demographics',
    'field_site_email_1' => 'field_site_email_1',
    'field_site_hours' => 'field_site_hours',
    'field_site_eval_form' => 'field_site_eval_form',
    'field_csu_facility' => 'field_csu_facility',
    'field_signups_max' => 'field_signups_max',
    'field_csu_org_type' => 'field_csu_org_type',
    'field_phone_1' => 'field_phone_1',
    'field_health_risk' => 'field_health_risk',
    'field_site_form' => 'field_site_form',
    'field_site_instructions_required' => 'field_site_instructions_required',
    'field_site_requirements' => 'field_site_requirements',
    'field_site_tour' => 'field_site_tour',
    'field_site_facebook_page' => 'field_site_facebook_page',
    'field_site_instructions' => 'field_site_instructions',
    'field_tags' => 'field_tags',
    'field_site_health_training' => 'field_site_health_training',
    'field_website_1' => 'field_website_1',
    'field_site_hours_minimum' => 'field_site_hours_minimum',
    'field_site_language' => 'field_site_language',
    'field_site_restrict' => 'field_site_restrict',
    'field_workflow_status' => 'field_workflow_status',
  );
  $handler->display->display_options['filters']['dyfield']['defaults_filterable_fields'] = array(
    'title' => 'title',
    'street' => 'street',
    'field_csu_facility' => 'field_csu_facility',
    'field_csu_org_type' => 'field_csu_org_type',
    'field_phone' => 0,
    'field_district_federal' => 0,
    'field_district_state_lower' => 0,
    'field_district_state_upper' => 0,
    'field_site_users' => 0,
    'body' => 0,
    'field_site_projects' => 0,
    'field_site_demographics' => 0,
    'field_site_email_1' => 0,
    'field_site_hours' => 0,
    'field_site_eval_form' => 0,
    'field_signups_max' => 0,
    'field_phone_1' => 0,
    'field_health_risk' => 0,
    'field_site_form' => 0,
    'field_site_instructions_required' => 0,
    'field_site_requirements' => 0,
    'field_site_tour' => 0,
    'field_site_facebook_page' => 0,
    'field_site_instructions' => 0,
    'field_tags' => 0,
    'field_site_health_training' => 0,
    'field_website_1' => 0,
    'field_site_hours_minimum' => 0,
    'field_site_language' => 0,
    'field_site_restrict' => 0,
    'field_workflow_status' => 0,
  );
  $handler->display->display_options['filters']['dyfield']['sortability'] = 1;
  $handler->display->display_options['filters']['dyfield']['checkboxes'] = 0;
  /* Filter criterion: Content: Term (field_term) */
  $handler->display->display_options['filters']['field_term_nid']['id'] = 'field_term_nid';
  $handler->display->display_options['filters']['field_term_nid']['table'] = 'field_data_field_term';
  $handler->display->display_options['filters']['field_term_nid']['field'] = 'field_term_nid';
  $handler->display->display_options['filters']['field_term_nid']['relationship'] = 'field_course_nid';
  $handler->display->display_options['filters']['field_term_nid']['group'] = 1;
  $handler->display->display_options['filters']['field_term_nid']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_term_nid']['expose']['operator_id'] = 'field_term_nid_op';
  $handler->display->display_options['filters']['field_term_nid']['expose']['label'] = 'Had a student in';
  $handler->display->display_options['filters']['field_term_nid']['expose']['operator'] = 'field_term_nid_op';
  $handler->display->display_options['filters']['field_term_nid']['expose']['identifier'] = 'field_term_nid';
  $handler->display->display_options['filters']['field_term_nid']['expose']['remember'] = TRUE;
  $handler->display->display_options['filters']['field_term_nid']['expose']['multiple'] = TRUE;
  /* Filter criterion: Content: Federal district (field_district_federal) */
  $handler->display->display_options['filters']['field_district_federal_value']['id'] = 'field_district_federal_value';
  $handler->display->display_options['filters']['field_district_federal_value']['table'] = 'field_data_field_district_federal';
  $handler->display->display_options['filters']['field_district_federal_value']['field'] = 'field_district_federal_value';
  $handler->display->display_options['filters']['field_district_federal_value']['operator'] = 'contains';
  $handler->display->display_options['filters']['field_district_federal_value']['group'] = 1;
  $handler->display->display_options['filters']['field_district_federal_value']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_district_federal_value']['expose']['operator_id'] = 'field_district_federal_value_op';
  $handler->display->display_options['filters']['field_district_federal_value']['expose']['label'] = 'Federal district';
  $handler->display->display_options['filters']['field_district_federal_value']['expose']['operator'] = 'field_district_federal_value_op';
  $handler->display->display_options['filters']['field_district_federal_value']['expose']['identifier'] = 'field_district_federal_value';
  /* Filter criterion: Content: State lower district (field_district_state_lower) */
  $handler->display->display_options['filters']['field_district_state_lower_value']['id'] = 'field_district_state_lower_value';
  $handler->display->display_options['filters']['field_district_state_lower_value']['table'] = 'field_data_field_district_state_lower';
  $handler->display->display_options['filters']['field_district_state_lower_value']['field'] = 'field_district_state_lower_value';
  $handler->display->display_options['filters']['field_district_state_lower_value']['operator'] = 'contains';
  $handler->display->display_options['filters']['field_district_state_lower_value']['group'] = 1;
  $handler->display->display_options['filters']['field_district_state_lower_value']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_district_state_lower_value']['expose']['operator_id'] = 'field_district_state_lower_value_op';
  $handler->display->display_options['filters']['field_district_state_lower_value']['expose']['label'] = 'State lower district';
  $handler->display->display_options['filters']['field_district_state_lower_value']['expose']['operator'] = 'field_district_state_lower_value_op';
  $handler->display->display_options['filters']['field_district_state_lower_value']['expose']['identifier'] = 'field_district_state_lower_value';
  /* Filter criterion: Content: State upper district (field_district_state_upper) */
  $handler->display->display_options['filters']['field_district_state_upper_value']['id'] = 'field_district_state_upper_value';
  $handler->display->display_options['filters']['field_district_state_upper_value']['table'] = 'field_data_field_district_state_upper';
  $handler->display->display_options['filters']['field_district_state_upper_value']['field'] = 'field_district_state_upper_value';
  $handler->display->display_options['filters']['field_district_state_upper_value']['operator'] = 'contains';
  $handler->display->display_options['filters']['field_district_state_upper_value']['group'] = 1;
  $handler->display->display_options['filters']['field_district_state_upper_value']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_district_state_upper_value']['expose']['operator_id'] = 'field_district_state_upper_value_op';
  $handler->display->display_options['filters']['field_district_state_upper_value']['expose']['label'] = 'State upper district';
  $handler->display->display_options['filters']['field_district_state_upper_value']['expose']['operator'] = 'field_district_state_upper_value_op';
  $handler->display->display_options['filters']['field_district_state_upper_value']['expose']['identifier'] = 'field_district_state_upper_value';
  /* Filter criterion: Location: Distance / Proximity */
  $handler->display->display_options['filters']['distance']['id'] = 'distance';
  $handler->display->display_options['filters']['distance']['table'] = 'location';
  $handler->display->display_options['filters']['distance']['field'] = 'distance';
  $handler->display->display_options['filters']['distance']['operator'] = 'dist';
  $handler->display->display_options['filters']['distance']['value'] = array(
    'latitude' => '',
    'longitude' => '',
    'postal_code' => '',
    'country' => '',
    'php_code' => '',
    'nid_arg' => '',
    'nid_loc_field' => 'node',
    'uid_arg' => '',
    'search_distance' => '',
    'search_units' => 'mile',
  );
  $handler->display->display_options['filters']['distance']['group'] = 1;
  $handler->display->display_options['filters']['distance']['exposed'] = TRUE;
  $handler->display->display_options['filters']['distance']['expose']['operator_id'] = 'distance_op';
  $handler->display->display_options['filters']['distance']['expose']['label'] = 'Distance / Proximity';
  $handler->display->display_options['filters']['distance']['expose']['operator'] = 'distance_op';
  $handler->display->display_options['filters']['distance']['expose']['identifier'] = 'distance';
  $handler->display->display_options['filters']['distance']['expose']['gmap_macro'] = array(
    'default' => '[gmap ]',
  );
  $handler->display->display_options['filters']['distance']['expose']['user_location_choose'] = array(
    'default' => FALSE,
  );
  $handler->display->display_options['filters']['distance']['origin'] = 'latlon_gmap';
  /* Filter criterion: Field: Available programs (field_site_restrict) */
  $handler->display->display_options['filters']['field_site_restrict_tid']['id'] = 'field_site_restrict_tid';
  $handler->display->display_options['filters']['field_site_restrict_tid']['table'] = 'field_data_field_site_restrict';
  $handler->display->display_options['filters']['field_site_restrict_tid']['field'] = 'field_site_restrict_tid';
  $handler->display->display_options['filters']['field_site_restrict_tid']['group'] = 1;
  $handler->display->display_options['filters']['field_site_restrict_tid']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_site_restrict_tid']['expose']['operator_id'] = 'field_site_restrict_tid_op';
  $handler->display->display_options['filters']['field_site_restrict_tid']['expose']['label'] = 'Available programs';
  $handler->display->display_options['filters']['field_site_restrict_tid']['expose']['operator'] = 'field_site_restrict_tid_op';
  $handler->display->display_options['filters']['field_site_restrict_tid']['expose']['identifier'] = 'field_site_restrict_tid';
  $handler->display->display_options['filters']['field_site_restrict_tid']['expose']['multiple'] = TRUE;
  $handler->display->display_options['filters']['field_site_restrict_tid']['type'] = 'select';
  $handler->display->display_options['filters']['field_site_restrict_tid']['vocabulary'] = 'site_restrictions';
  /* Filter criterion: Content: Tags (field_tags) */
  $handler->display->display_options['filters']['field_tags_tid']['id'] = 'field_tags_tid';
  $handler->display->display_options['filters']['field_tags_tid']['table'] = 'field_data_field_tags';
  $handler->display->display_options['filters']['field_tags_tid']['field'] = 'field_tags_tid';
  $handler->display->display_options['filters']['field_tags_tid']['value'] = '';
  $handler->display->display_options['filters']['field_tags_tid']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_tags_tid']['expose']['operator_id'] = 'field_tags_tid_op';
  $handler->display->display_options['filters']['field_tags_tid']['expose']['label'] = 'Site tags';
  $handler->display->display_options['filters']['field_tags_tid']['expose']['use_operator'] = TRUE;
  $handler->display->display_options['filters']['field_tags_tid']['expose']['operator'] = 'field_tags_tid_op';
  $handler->display->display_options['filters']['field_tags_tid']['expose']['identifier'] = 'field_tags_tid';
  $handler->display->display_options['filters']['field_tags_tid']['expose']['multiple'] = TRUE;
  $handler->display->display_options['filters']['field_tags_tid']['reduce_duplicates'] = TRUE;
  $handler->display->display_options['filters']['field_tags_tid']['vocabulary'] = 'tags';
  /* Filter criterion: Content: First day of service (field_signup_start_date) */
  $handler->display->display_options['filters']['field_signup_start_date_value']['id'] = 'field_signup_start_date_value';
  $handler->display->display_options['filters']['field_signup_start_date_value']['table'] = 'field_data_field_signup_start_date';
  $handler->display->display_options['filters']['field_signup_start_date_value']['field'] = 'field_signup_start_date_value';
  $handler->display->display_options['filters']['field_signup_start_date_value']['relationship'] = 'reverse_field_site_node';
  $handler->display->display_options['filters']['field_signup_start_date_value']['operator'] = 'between';
  $handler->display->display_options['filters']['field_signup_start_date_value']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_signup_start_date_value']['expose']['operator_id'] = 'field_signup_start_date_value_op';
  $handler->display->display_options['filters']['field_signup_start_date_value']['expose']['label'] = 'Site had at least one student between the following dates';
  $handler->display->display_options['filters']['field_signup_start_date_value']['expose']['operator'] = 'field_signup_start_date_value_op';
  $handler->display->display_options['filters']['field_signup_start_date_value']['expose']['identifier'] = 'field_signup_start_date_value';
  $handler->display->display_options['filters']['field_signup_start_date_value']['granularity'] = 'day';
  $handler->display->display_options['filters']['field_signup_start_date_value']['form_type'] = 'date_select';
  $handler->display->display_options['filters']['field_signup_start_date_value']['default_date'] = '';
  $handler->display->display_options['filters']['field_signup_start_date_value']['default_to_date'] = '';
  $handler->display->display_options['filters']['field_signup_start_date_value']['year_range'] = '-3:+3';
  /* Filter criterion: Content: Subject (field_course_subject) */
  $handler->display->display_options['filters']['field_course_subject_value']['id'] = 'field_course_subject_value';
  $handler->display->display_options['filters']['field_course_subject_value']['table'] = 'field_data_field_course_subject';
  $handler->display->display_options['filters']['field_course_subject_value']['field'] = 'field_course_subject_value';
  $handler->display->display_options['filters']['field_course_subject_value']['relationship'] = 'field_course_nid';
  $handler->display->display_options['filters']['field_course_subject_value']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_course_subject_value']['expose']['operator_id'] = 'field_course_subject_value_op';
  $handler->display->display_options['filters']['field_course_subject_value']['expose']['label'] = 'Who had a student in the following course subject';
  $handler->display->display_options['filters']['field_course_subject_value']['expose']['operator'] = 'field_course_subject_value_op';
  $handler->display->display_options['filters']['field_course_subject_value']['expose']['identifier'] = 'field_course_subject_value';
  /* Filter criterion: Content: Term (field_term) */
  $handler->display->display_options['filters']['field_term_nid_1']['id'] = 'field_term_nid_1';
  $handler->display->display_options['filters']['field_term_nid_1']['table'] = 'field_data_field_term';
  $handler->display->display_options['filters']['field_term_nid_1']['field'] = 'field_term_nid';
  $handler->display->display_options['filters']['field_term_nid_1']['relationship'] = 'field_course_nid';
  $handler->display->display_options['filters']['field_term_nid_1']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_term_nid_1']['expose']['operator_id'] = 'field_term_nid_1_op';
  $handler->display->display_options['filters']['field_term_nid_1']['expose']['label'] = 'Site had a student in the following terms (only applies to students signing up as part of a course)';
  $handler->display->display_options['filters']['field_term_nid_1']['expose']['operator'] = 'field_term_nid_1_op';
  $handler->display->display_options['filters']['field_term_nid_1']['expose']['identifier'] = 'field_term_nid_1';
  $handler->display->display_options['filters']['field_term_nid_1']['expose']['multiple'] = TRUE;
  /* Filter criterion: Content: Title */
  $handler->display->display_options['filters']['title']['id'] = 'title';
  $handler->display->display_options['filters']['title']['table'] = 'node';
  $handler->display->display_options['filters']['title']['field'] = 'title';
  $handler->display->display_options['filters']['title']['operator'] = 'starts';
  $handler->display->display_options['filters']['title']['exposed'] = TRUE;
  $handler->display->display_options['filters']['title']['expose']['operator_id'] = 'title_op';
  $handler->display->display_options['filters']['title']['expose']['label'] = 'Site name';
  $handler->display->display_options['filters']['title']['expose']['use_operator'] = TRUE;
  $handler->display->display_options['filters']['title']['expose']['operator'] = 'title_op';
  $handler->display->display_options['filters']['title']['expose']['identifier'] = 'title';
  /* Filter criterion: Content: Maximum number of students (field_signups_max) */
  $handler->display->display_options['filters']['field_signups_max_value']['id'] = 'field_signups_max_value';
  $handler->display->display_options['filters']['field_signups_max_value']['table'] = 'field_data_field_signups_max';
  $handler->display->display_options['filters']['field_signups_max_value']['field'] = 'field_signups_max_value';
  $handler->display->display_options['filters']['field_signups_max_value']['operator'] = '>=';
  $handler->display->display_options['filters']['field_signups_max_value']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_signups_max_value']['expose']['operator_id'] = 'field_signups_max_value_op';
  $handler->display->display_options['filters']['field_signups_max_value']['expose']['label'] = 'Maximum number of students';
  $handler->display->display_options['filters']['field_signups_max_value']['expose']['use_operator'] = TRUE;
  $handler->display->display_options['filters']['field_signups_max_value']['expose']['operator'] = 'field_signups_max_value_op';
  $handler->display->display_options['filters']['field_signups_max_value']['expose']['identifier'] = 'field_signups_max_value';

  /* Display: Data report page */
  $handler = $view->new_display('page', 'Data report page', 'page');
  $handler->display->display_options['path'] = 'reports/sites';
  $handler->display->display_options['menu']['type'] = 'default tab';
  $handler->display->display_options['menu']['title'] = 'Sites';
  $handler->display->display_options['menu']['weight'] = '0';
  $handler->display->display_options['tab_options']['type'] = 'normal';
  $handler->display->display_options['tab_options']['title'] = 'Reports';
  $handler->display->display_options['tab_options']['weight'] = '0';

  /* Display: Data export: CSV */
  $handler = $view->new_display('views_data_export', 'Data export: CSV', 'views_data_export_1');
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['style_plugin'] = 'views_data_export_csv';
  $handler->display->display_options['style_options']['provide_file'] = 0;
  $handler->display->display_options['style_options']['parent_sort'] = 0;
  $handler->display->display_options['style_options']['quote'] = 1;
  $handler->display->display_options['style_options']['header'] = 1;
  $handler->display->display_options['path'] = 'reports/sites/export/csv';
  $handler->display->display_options['displays'] = array(
    'default' => 'default',
    'page' => 'page',
  );

  /* Display: Data export: XLS */
  $handler = $view->new_display('views_data_export', 'Data export: XLS', 'views_data_export_2');
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['style_plugin'] = 'views_data_export_xls';
  $handler->display->display_options['style_options']['provide_file'] = 0;
  $handler->display->display_options['style_options']['parent_sort'] = 0;
  $handler->display->display_options['path'] = 'reports/sites/export/xls';
  $handler->display->display_options['displays'] = array(
    'default' => 'default',
    'page' => 'page',
  );

  /* Display: Data export: DOC */
  $handler = $view->new_display('views_data_export', 'Data export: DOC', 'views_data_export_3');
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['style_plugin'] = 'views_data_export_doc';
  $handler->display->display_options['style_options']['provide_file'] = 0;
  $handler->display->display_options['style_options']['parent_sort'] = 0;
  $handler->display->display_options['path'] = 'reports/sites/export/doc';
  $handler->display->display_options['displays'] = array(
    'default' => 'default',
    'page' => 'page',
  );
  $translatables['reports_sites'] = array(
    t('Master'),
    t('Site Report'),
    t('more'),
    t('Search'),
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
    t('field_site'),
    t('field_course'),
    t('Bulk operations'),
    t('Site'),
    t('Website'),
    t('<strong>Website:</strong> <a href="[field_website-url]">View website</a>'),
    t('Email'),
    t('Contact'),
    t('<strong>Phone:</strong> [field_phone]<br/>
<strong>Email:</strong> [field_site_email]<br/>
[field_website]'),
    t('City'),
    t('Postal Code'),
    t('Province'),
    t('Address'),
    t('[street]<br/>
[city], [province]&nbsp;&nbsp; [postal_code]'),
    t('&nbsp;'),
    t('Legislative District: Federal'),
    t('Legislative District: Lower state district'),
    t('Legislative District: State upper'),
    t('Users'),
    t('Site description'),
    t('Special projects'),
    t('Demographic'),
    t('Hours'),
    t('Issues addressed '),
    t('Max students'),
    t('Organization type'),
    t('Phone number '),
    t('Risk Identification '),
    t('Site has special requirements '),
    t('Site Tour '),
    t('Social network page '),
    t('Special site instructions '),
    t('Tags '),
    t('Training & orientation '),
    t('Website '),
    t('Minimum hours'),
    t('Languages'),
    t('Related programs'),
    t('Issues addressed'),
    t('Org. type'),
    t('Fields'),
    t('Had a student in'),
    t('Federal district'),
    t('State lower district'),
    t('State upper district'),
    t('Distance / Proximity'),
    t('[gmap ]'),
    t('Available programs'),
    t('Site tags'),
    t('Site had at least one student between the following dates'),
    t('Who had a student in the following course subject'),
    t('Site had a student in the following terms (only applies to students signing up as part of a course)'),
    t('Site name'),
    t('Maximum number of students'),
    t('Data report page'),
    t('Data export: CSV'),
    t('Data export: XLS'),
    t('Data export: DOC'),
  );
  $export['reports_sites'] = $view;

  $view = new view();
  $view->name = 'reports_students';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'users';
  $view->human_name = 'Reports: students';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Student report';
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['access']['perm'] = 'access s4 reporting';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['query']['options']['distinct'] = TRUE;
  $handler->display->display_options['exposed_form']['type'] = 's4_reporting';
  $handler->display->display_options['exposed_form']['options']['s4_reporting'] = array(
    'group-field_first_name_value' => '0',
    'group-field_last_name_value_1' => '0',
    'group-dyfield' => '3',
    'group-field_term_nid' => '1',
    'group-field_course_subject_value' => '1',
    'group-field_course_catalog_number_value' => '1',
    'group-field_signup_start_date_value' => '2',
    'group-field_term_nid_1' => '2',
    'groups' => 'Student
Course
Placement
Fields',
  );
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '40';
  $handler->display->display_options['style_plugin'] = 'table';
  /* Header: Global: Result summary */
  $handler->display->display_options['header']['result']['id'] = 'result';
  $handler->display->display_options['header']['result']['table'] = 'views';
  $handler->display->display_options['header']['result']['field'] = 'result';
  $handler->display->display_options['header']['result']['empty'] = FALSE;
  /* Relationship: User: Students (field_course_students) - reverse */
  $handler->display->display_options['relationships']['reverse_field_course_students_node']['id'] = 'reverse_field_course_students_node';
  $handler->display->display_options['relationships']['reverse_field_course_students_node']['table'] = 'users';
  $handler->display->display_options['relationships']['reverse_field_course_students_node']['field'] = 'reverse_field_course_students_node';
  /* Relationship: User: User (field_user) - reverse */
  $handler->display->display_options['relationships']['reverse_field_user_node']['id'] = 'reverse_field_user_node';
  $handler->display->display_options['relationships']['reverse_field_user_node']['table'] = 'users';
  $handler->display->display_options['relationships']['reverse_field_user_node']['field'] = 'reverse_field_user_node';
  /* Relationship: Content: Site (field_site) */
  $handler->display->display_options['relationships']['field_site_nid']['id'] = 'field_site_nid';
  $handler->display->display_options['relationships']['field_site_nid']['table'] = 'field_data_field_site';
  $handler->display->display_options['relationships']['field_site_nid']['field'] = 'field_site_nid';
  $handler->display->display_options['relationships']['field_site_nid']['relationship'] = 'reverse_field_course_students_node';
  /* Relationship: Content: Site staff (field_coordinator) */
  $handler->display->display_options['relationships']['field_coordinator_nid']['id'] = 'field_coordinator_nid';
  $handler->display->display_options['relationships']['field_coordinator_nid']['table'] = 'field_data_field_coordinator';
  $handler->display->display_options['relationships']['field_coordinator_nid']['field'] = 'field_coordinator_nid';
  $handler->display->display_options['relationships']['field_coordinator_nid']['relationship'] = 'reverse_field_user_node';
  $handler->display->display_options['relationships']['field_coordinator_nid']['delta'] = '-1';
  /* Relationship: Content: Course (field_course) */
  $handler->display->display_options['relationships']['field_course_nid']['id'] = 'field_course_nid';
  $handler->display->display_options['relationships']['field_course_nid']['table'] = 'field_data_field_course';
  $handler->display->display_options['relationships']['field_course_nid']['field'] = 'field_course_nid';
  $handler->display->display_options['relationships']['field_course_nid']['relationship'] = 'reverse_field_user_node';
  $handler->display->display_options['relationships']['field_course_nid']['label'] = 'field_signup_course';
  $handler->display->display_options['relationships']['field_course_nid']['delta'] = '-1';
  /* Field: Bulk operations: User */
  $handler->display->display_options['fields']['views_bulk_operations']['id'] = 'views_bulk_operations';
  $handler->display->display_options['fields']['views_bulk_operations']['table'] = 'users';
  $handler->display->display_options['fields']['views_bulk_operations']['field'] = 'views_bulk_operations';
  $handler->display->display_options['fields']['views_bulk_operations']['label'] = 'Bulk operations';
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
    'action::views_bulk_operations_modify_action' => array(
      'selected' => 0,
      'use_queue' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
      'settings' => array(
        'show_all_tokens' => 1,
        'display_values' => array(
          '_all_' => '_all_',
        ),
      ),
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
    'action::s4_reporting_forms_site' => array(
      'selected' => 0,
      'use_queue' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
    'action::s4_reporting_forms_signup' => array(
      'selected' => 1,
      'use_queue' => 0,
      'skip_confirmation' => 0,
      'override_label' => 1,
      'label' => 'Run form report',
    ),
    'action::system_send_email_action' => array(
      'selected' => 0,
      'use_queue' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
    'action::s4_core_email_site_action' => array(
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
      'selected' => 1,
      'use_queue' => 0,
      'skip_confirmation' => 0,
      'override_label' => 1,
      'label' => 'Send student email',
    ),
    'action::s4_courses_bulk_signup_students_action' => array(
      'selected' => 0,
      'use_queue' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
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
  $handler->display->display_options['fields']['uid']['label'] = '';
  $handler->display->display_options['fields']['uid']['exclude'] = TRUE;
  $handler->display->display_options['fields']['uid']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['uid']['link_to_user'] = FALSE;
  /* Field: Field: Last Name */
  $handler->display->display_options['fields']['field_last_name']['id'] = 'field_last_name';
  $handler->display->display_options['fields']['field_last_name']['table'] = 'field_data_field_last_name';
  $handler->display->display_options['fields']['field_last_name']['field'] = 'field_last_name';
  $handler->display->display_options['fields']['field_last_name']['label'] = 'Last name';
  $handler->display->display_options['fields']['field_last_name']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['field_last_name']['alter']['path'] = 'user/[uid]';
  /* Field: Field: First Name */
  $handler->display->display_options['fields']['field_first_name']['id'] = 'field_first_name';
  $handler->display->display_options['fields']['field_first_name']['table'] = 'field_data_field_first_name';
  $handler->display->display_options['fields']['field_first_name']['field'] = 'field_first_name';
  $handler->display->display_options['fields']['field_first_name']['label'] = 'First name';
  $handler->display->display_options['fields']['field_first_name']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['field_first_name']['alter']['path'] = 'user/[uid]';
  /* Field: Field: Available programs */
  $handler->display->display_options['fields']['field_site_restrict']['id'] = 'field_site_restrict';
  $handler->display->display_options['fields']['field_site_restrict']['table'] = 'field_data_field_site_restrict';
  $handler->display->display_options['fields']['field_site_restrict']['field'] = 'field_site_restrict';
  $handler->display->display_options['fields']['field_site_restrict']['label'] = 'Student programs';
  $handler->display->display_options['fields']['field_site_restrict']['type'] = 'taxonomy_term_reference_plain';
  $handler->display->display_options['fields']['field_site_restrict']['delta_offset'] = '0';
  /* Field: User: Authentication name */
  $handler->display->display_options['fields']['authname']['id'] = 'authname';
  $handler->display->display_options['fields']['authname']['table'] = 'authmap';
  $handler->display->display_options['fields']['authname']['field'] = 'authname';
  $handler->display->display_options['fields']['authname']['label'] = 'Login name';
  /* Field: User: E-mail */
  $handler->display->display_options['fields']['mail']['id'] = 'mail';
  $handler->display->display_options['fields']['mail']['table'] = 'users';
  $handler->display->display_options['fields']['mail']['field'] = 'mail';
  $handler->display->display_options['fields']['mail']['label'] = 'E-mail ';
  /* Field: User: Last login */
  $handler->display->display_options['fields']['login']['id'] = 'login';
  $handler->display->display_options['fields']['login']['table'] = 'users';
  $handler->display->display_options['fields']['login']['field'] = 'login';
  $handler->display->display_options['fields']['login']['label'] = 'Last login ';
  $handler->display->display_options['fields']['login']['date_format'] = 'long';
  /* Field: User: SIS ID */
  $handler->display->display_options['fields']['field_sis_id']['id'] = 'field_sis_id';
  $handler->display->display_options['fields']['field_sis_id']['table'] = 'field_data_field_sis_id';
  $handler->display->display_options['fields']['field_sis_id']['field'] = 'field_sis_id';
  $handler->display->display_options['fields']['field_sis_id']['label'] = 'Student ID';
  /* Field: Content: Term */
  $handler->display->display_options['fields']['field_term']['id'] = 'field_term';
  $handler->display->display_options['fields']['field_term']['table'] = 'field_data_field_term';
  $handler->display->display_options['fields']['field_term']['field'] = 'field_term';
  $handler->display->display_options['fields']['field_term']['relationship'] = 'reverse_field_course_students_node';
  $handler->display->display_options['fields']['field_term']['label'] = 'Course term';
  $handler->display->display_options['fields']['field_term']['type'] = 'node_reference_plain';
  /* Field: Content: Subject */
  $handler->display->display_options['fields']['field_course_subject']['id'] = 'field_course_subject';
  $handler->display->display_options['fields']['field_course_subject']['table'] = 'field_data_field_course_subject';
  $handler->display->display_options['fields']['field_course_subject']['field'] = 'field_course_subject';
  $handler->display->display_options['fields']['field_course_subject']['relationship'] = 'reverse_field_course_students_node';
  $handler->display->display_options['fields']['field_course_subject']['label'] = 'Course subject';
  /* Field: Content: Catalog number */
  $handler->display->display_options['fields']['field_course_catalog_number']['id'] = 'field_course_catalog_number';
  $handler->display->display_options['fields']['field_course_catalog_number']['table'] = 'field_data_field_course_catalog_number';
  $handler->display->display_options['fields']['field_course_catalog_number']['field'] = 'field_course_catalog_number';
  $handler->display->display_options['fields']['field_course_catalog_number']['relationship'] = 'reverse_field_course_students_node';
  $handler->display->display_options['fields']['field_course_catalog_number']['label'] = 'Course number';
  /* Field: Content: Section number */
  $handler->display->display_options['fields']['field_course_section']['id'] = 'field_course_section';
  $handler->display->display_options['fields']['field_course_section']['table'] = 'field_data_field_course_section';
  $handler->display->display_options['fields']['field_course_section']['field'] = 'field_course_section';
  $handler->display->display_options['fields']['field_course_section']['relationship'] = 'reverse_field_course_students_node';
  $handler->display->display_options['fields']['field_course_section']['label'] = 'Course section';
  $handler->display->display_options['fields']['field_course_section']['settings'] = array(
    'thousand_separator' => ' ',
    'prefix_suffix' => 1,
  );
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['relationship'] = 'field_site_nid';
  $handler->display->display_options['fields']['title']['label'] = 'Site';
  /* Field: Field: First Name */
  $handler->display->display_options['fields']['field_first_name_1']['id'] = 'field_first_name_1';
  $handler->display->display_options['fields']['field_first_name_1']['table'] = 'field_data_field_first_name';
  $handler->display->display_options['fields']['field_first_name_1']['field'] = 'field_first_name';
  $handler->display->display_options['fields']['field_first_name_1']['relationship'] = 'field_coordinator_nid';
  $handler->display->display_options['fields']['field_first_name_1']['label'] = 'Site staff first name';
  /* Field: Field: Last Name */
  $handler->display->display_options['fields']['field_last_name_1']['id'] = 'field_last_name_1';
  $handler->display->display_options['fields']['field_last_name_1']['table'] = 'field_data_field_last_name';
  $handler->display->display_options['fields']['field_last_name_1']['field'] = 'field_last_name';
  $handler->display->display_options['fields']['field_last_name_1']['relationship'] = 'field_coordinator_nid';
  $handler->display->display_options['fields']['field_last_name_1']['label'] = 'Site staff last name';
  /* Sort criterion: Field: Last Name (field_last_name) */
  $handler->display->display_options['sorts']['field_last_name_value']['id'] = 'field_last_name_value';
  $handler->display->display_options['sorts']['field_last_name_value']['table'] = 'field_data_field_last_name';
  $handler->display->display_options['sorts']['field_last_name_value']['field'] = 'field_last_name_value';
  /* Sort criterion: Field: First Name (field_first_name) */
  $handler->display->display_options['sorts']['field_first_name_value']['id'] = 'field_first_name_value';
  $handler->display->display_options['sorts']['field_first_name_value']['table'] = 'field_data_field_first_name';
  $handler->display->display_options['sorts']['field_first_name_value']['field'] = 'field_first_name_value';
  /* Sort criterion: User: Created date */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'users';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
  $handler->display->display_options['filter_groups']['groups'] = array(
    1 => 'AND',
    2 => 'OR',
  );
  /* Filter criterion: User: Active */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'users';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = '1';
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Field: First Name (field_first_name) */
  $handler->display->display_options['filters']['field_first_name_value']['id'] = 'field_first_name_value';
  $handler->display->display_options['filters']['field_first_name_value']['table'] = 'field_data_field_first_name';
  $handler->display->display_options['filters']['field_first_name_value']['field'] = 'field_first_name_value';
  $handler->display->display_options['filters']['field_first_name_value']['operator'] = 'starts';
  $handler->display->display_options['filters']['field_first_name_value']['group'] = 1;
  $handler->display->display_options['filters']['field_first_name_value']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_first_name_value']['expose']['operator_id'] = 'field_first_name_value_op';
  $handler->display->display_options['filters']['field_first_name_value']['expose']['label'] = 'First name';
  $handler->display->display_options['filters']['field_first_name_value']['expose']['operator'] = 'field_first_name_value_op';
  $handler->display->display_options['filters']['field_first_name_value']['expose']['identifier'] = 'field_first_name_value';
  /* Filter criterion: Field: Last Name (field_last_name) */
  $handler->display->display_options['filters']['field_last_name_value_1']['id'] = 'field_last_name_value_1';
  $handler->display->display_options['filters']['field_last_name_value_1']['table'] = 'field_data_field_last_name';
  $handler->display->display_options['filters']['field_last_name_value_1']['field'] = 'field_last_name_value';
  $handler->display->display_options['filters']['field_last_name_value_1']['operator'] = 'starts';
  $handler->display->display_options['filters']['field_last_name_value_1']['group'] = 1;
  $handler->display->display_options['filters']['field_last_name_value_1']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_last_name_value_1']['expose']['operator_id'] = 'field_last_name_value_1_op';
  $handler->display->display_options['filters']['field_last_name_value_1']['expose']['label'] = 'Last name';
  $handler->display->display_options['filters']['field_last_name_value_1']['expose']['operator'] = 'field_last_name_value_1_op';
  $handler->display->display_options['filters']['field_last_name_value_1']['expose']['identifier'] = 'field_last_name_value_1';
  /* Filter criterion: Content: Dynamic Fields */
  $handler->display->display_options['filters']['dyfield']['id'] = 'dyfield';
  $handler->display->display_options['filters']['dyfield']['table'] = 'node';
  $handler->display->display_options['filters']['dyfield']['field'] = 'dyfield';
  $handler->display->display_options['filters']['dyfield']['relationship'] = 'reverse_field_course_students_node';
  $handler->display->display_options['filters']['dyfield']['group'] = 1;
  $handler->display->display_options['filters']['dyfield']['exposed'] = TRUE;
  $handler->display->display_options['filters']['dyfield']['expose']['operator_id'] = '';
  $handler->display->display_options['filters']['dyfield']['expose']['label'] = 'Fields';
  $handler->display->display_options['filters']['dyfield']['expose']['operator'] = 'dyfield_op';
  $handler->display->display_options['filters']['dyfield']['expose']['identifier'] = 'dyfield';
  $handler->display->display_options['filters']['dyfield']['expose']['multiple'] = TRUE;
  $handler->display->display_options['filters']['dyfield']['filterable_fields'] = array(
    'views_bulk_operations' => 'views_bulk_operations',
    'field_last_name' => 'field_last_name',
    'field_first_name' => 'field_first_name',
    'field_site_restrict' => 'field_site_restrict',
    'authname' => 'authname',
    'mail' => 'mail',
    'login' => 'login',
    'field_sis_id' => 'field_sis_id',
    'field_term' => 'field_term',
    'field_course_subject' => 'field_course_subject',
    'field_course_catalog_number' => 'field_course_catalog_number',
    'field_course_section' => 'field_course_section',
    'title' => 'title',
    'field_first_name_1' => 'field_first_name_1',
    'field_last_name_1' => 'field_last_name_1',
  );
  $handler->display->display_options['filters']['dyfield']['defaults_filterable_fields'] = array(
    'views_bulk_operations' => 'views_bulk_operations',
    'field_last_name' => 'field_last_name',
    'field_first_name' => 'field_first_name',
    'field_site_restrict' => 'field_site_restrict',
    'authname' => 'authname',
    'mail' => 'mail',
    'field_sis_id' => 'field_sis_id',
    'login' => 0,
    'field_term' => 0,
    'field_course_subject' => 0,
    'field_course_catalog_number' => 0,
    'field_course_section' => 0,
    'title' => 0,
    'field_first_name_1' => 0,
    'field_last_name_1' => 0,
  );
  $handler->display->display_options['filters']['dyfield']['sortability'] = 1;
  $handler->display->display_options['filters']['dyfield']['checkboxes'] = 0;
  /* Filter criterion: Content: Term (field_term) */
  $handler->display->display_options['filters']['field_term_nid']['id'] = 'field_term_nid';
  $handler->display->display_options['filters']['field_term_nid']['table'] = 'field_data_field_term';
  $handler->display->display_options['filters']['field_term_nid']['field'] = 'field_term_nid';
  $handler->display->display_options['filters']['field_term_nid']['relationship'] = 'reverse_field_course_students_node';
  $handler->display->display_options['filters']['field_term_nid']['group'] = 1;
  $handler->display->display_options['filters']['field_term_nid']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_term_nid']['expose']['operator_id'] = 'field_term_nid_op';
  $handler->display->display_options['filters']['field_term_nid']['expose']['label'] = 'Course term';
  $handler->display->display_options['filters']['field_term_nid']['expose']['operator'] = 'field_term_nid_op';
  $handler->display->display_options['filters']['field_term_nid']['expose']['identifier'] = 'field_term_nid';
  $handler->display->display_options['filters']['field_term_nid']['expose']['multiple'] = TRUE;
  /* Filter criterion: Content: Subject (field_course_subject) */
  $handler->display->display_options['filters']['field_course_subject_value']['id'] = 'field_course_subject_value';
  $handler->display->display_options['filters']['field_course_subject_value']['table'] = 'field_data_field_course_subject';
  $handler->display->display_options['filters']['field_course_subject_value']['field'] = 'field_course_subject_value';
  $handler->display->display_options['filters']['field_course_subject_value']['relationship'] = 'reverse_field_course_students_node';
  $handler->display->display_options['filters']['field_course_subject_value']['group'] = 1;
  $handler->display->display_options['filters']['field_course_subject_value']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_course_subject_value']['expose']['operator_id'] = 'field_course_subject_value_op';
  $handler->display->display_options['filters']['field_course_subject_value']['expose']['label'] = 'Course subject';
  $handler->display->display_options['filters']['field_course_subject_value']['expose']['operator'] = 'field_course_subject_value_op';
  $handler->display->display_options['filters']['field_course_subject_value']['expose']['identifier'] = 'field_course_subject_value';
  /* Filter criterion: Content: Catalog number (field_course_catalog_number) */
  $handler->display->display_options['filters']['field_course_catalog_number_value']['id'] = 'field_course_catalog_number_value';
  $handler->display->display_options['filters']['field_course_catalog_number_value']['table'] = 'field_data_field_course_catalog_number';
  $handler->display->display_options['filters']['field_course_catalog_number_value']['field'] = 'field_course_catalog_number_value';
  $handler->display->display_options['filters']['field_course_catalog_number_value']['relationship'] = 'reverse_field_course_students_node';
  $handler->display->display_options['filters']['field_course_catalog_number_value']['group'] = 1;
  $handler->display->display_options['filters']['field_course_catalog_number_value']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_course_catalog_number_value']['expose']['operator_id'] = 'field_course_catalog_number_value_op';
  $handler->display->display_options['filters']['field_course_catalog_number_value']['expose']['label'] = 'Catalog number';
  $handler->display->display_options['filters']['field_course_catalog_number_value']['expose']['operator'] = 'field_course_catalog_number_value_op';
  $handler->display->display_options['filters']['field_course_catalog_number_value']['expose']['identifier'] = 'field_course_catalog_number_value';
  /* Filter criterion: Field: Available programs (field_site_restrict) */
  $handler->display->display_options['filters']['field_site_restrict_tid']['id'] = 'field_site_restrict_tid';
  $handler->display->display_options['filters']['field_site_restrict_tid']['table'] = 'field_data_field_site_restrict';
  $handler->display->display_options['filters']['field_site_restrict_tid']['field'] = 'field_site_restrict_tid';
  $handler->display->display_options['filters']['field_site_restrict_tid']['operator'] = 'not empty';
  $handler->display->display_options['filters']['field_site_restrict_tid']['value'] = '';
  $handler->display->display_options['filters']['field_site_restrict_tid']['group'] = 2;
  $handler->display->display_options['filters']['field_site_restrict_tid']['vocabulary'] = 'site_restrictions';
  /* Filter criterion: Content: Nid */
  $handler->display->display_options['filters']['nid']['id'] = 'nid';
  $handler->display->display_options['filters']['nid']['table'] = 'node';
  $handler->display->display_options['filters']['nid']['field'] = 'nid';
  $handler->display->display_options['filters']['nid']['relationship'] = 'reverse_field_course_students_node';
  $handler->display->display_options['filters']['nid']['operator'] = 'not empty';
  $handler->display->display_options['filters']['nid']['group'] = 2;
  /* Filter criterion: Content: Nid */
  $handler->display->display_options['filters']['nid_1']['id'] = 'nid_1';
  $handler->display->display_options['filters']['nid_1']['table'] = 'node';
  $handler->display->display_options['filters']['nid_1']['field'] = 'nid';
  $handler->display->display_options['filters']['nid_1']['relationship'] = 'reverse_field_user_node';
  $handler->display->display_options['filters']['nid_1']['operator'] = 'not empty';
  $handler->display->display_options['filters']['nid_1']['group'] = 2;
  /* Filter criterion: Content: First day of service (field_signup_start_date) */
  $handler->display->display_options['filters']['field_signup_start_date_value']['id'] = 'field_signup_start_date_value';
  $handler->display->display_options['filters']['field_signup_start_date_value']['table'] = 'field_data_field_signup_start_date';
  $handler->display->display_options['filters']['field_signup_start_date_value']['field'] = 'field_signup_start_date_value';
  $handler->display->display_options['filters']['field_signup_start_date_value']['relationship'] = 'reverse_field_course_students_node';
  $handler->display->display_options['filters']['field_signup_start_date_value']['operator'] = 'between';
  $handler->display->display_options['filters']['field_signup_start_date_value']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_signup_start_date_value']['expose']['operator_id'] = 'field_signup_start_date_value_op';
  $handler->display->display_options['filters']['field_signup_start_date_value']['expose']['label'] = 'First day of service';
  $handler->display->display_options['filters']['field_signup_start_date_value']['expose']['operator'] = 'field_signup_start_date_value_op';
  $handler->display->display_options['filters']['field_signup_start_date_value']['expose']['identifier'] = 'field_signup_start_date_value';
  $handler->display->display_options['filters']['field_signup_start_date_value']['granularity'] = 'day';
  $handler->display->display_options['filters']['field_signup_start_date_value']['form_type'] = 'date_select';
  $handler->display->display_options['filters']['field_signup_start_date_value']['default_date'] = '';
  $handler->display->display_options['filters']['field_signup_start_date_value']['default_to_date'] = '';
  $handler->display->display_options['filters']['field_signup_start_date_value']['year_range'] = '-3:+3';
  /* Filter criterion: Content: Term (field_term) */
  $handler->display->display_options['filters']['field_term_nid_1']['id'] = 'field_term_nid_1';
  $handler->display->display_options['filters']['field_term_nid_1']['table'] = 'field_data_field_term';
  $handler->display->display_options['filters']['field_term_nid_1']['field'] = 'field_term_nid';
  $handler->display->display_options['filters']['field_term_nid_1']['relationship'] = 'field_course_nid';
  $handler->display->display_options['filters']['field_term_nid_1']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_term_nid_1']['expose']['operator_id'] = 'field_term_nid_1_op';
  $handler->display->display_options['filters']['field_term_nid_1']['expose']['label'] = 'Semester or term';
  $handler->display->display_options['filters']['field_term_nid_1']['expose']['operator'] = 'field_term_nid_1_op';
  $handler->display->display_options['filters']['field_term_nid_1']['expose']['identifier'] = 'field_term_nid_1';
  $handler->display->display_options['filters']['field_term_nid_1']['expose']['multiple'] = TRUE;

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page');
  $handler->display->display_options['path'] = 'reports/students';
  $handler->display->display_options['menu']['type'] = 'tab';
  $handler->display->display_options['menu']['title'] = 'Students';
  $handler->display->display_options['menu']['weight'] = '0';
  $handler->display->display_options['menu']['context'] = 0;

  /* Display: Export CSV */
  $handler = $view->new_display('views_data_export', 'Export CSV', 'views_data_export_1');
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['style_plugin'] = 'views_data_export_csv';
  $handler->display->display_options['path'] = 'reports/students/export/csv';
  $handler->display->display_options['displays'] = array(
    'page' => 'page',
    'default' => 0,
  );

  /* Display: Export XLS */
  $handler = $view->new_display('views_data_export', 'Export XLS', 'views_data_export_2');
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['style_plugin'] = 'views_data_export_xls';
  $handler->display->display_options['style_options']['provide_file'] = 0;
  $handler->display->display_options['style_options']['parent_sort'] = 0;
  $handler->display->display_options['path'] = 'reports/students/export/xls';
  $handler->display->display_options['displays'] = array(
    'page' => 'page',
    'default' => 0,
  );

  /* Display: Export DOC */
  $handler = $view->new_display('views_data_export', 'Export DOC', 'views_data_export_3');
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['style_plugin'] = 'views_data_export_doc';
  $handler->display->display_options['style_options']['provide_file'] = 0;
  $handler->display->display_options['style_options']['parent_sort'] = 0;
  $handler->display->display_options['path'] = 'reports/students/export/doc';
  $handler->display->display_options['displays'] = array(
    'page' => 'page',
    'default' => 0,
  );
  $translatables['reports_students'] = array(
    t('Master'),
    t('Student report'),
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
    t('Displaying @start - @end of @total'),
    t('field_course_students'),
    t('field_user'),
    t('field_site'),
    t('field_coordinator'),
    t('field_signup_course'),
    t('Bulk operations'),
    t('Last name'),
    t('user/[uid]'),
    t('First name'),
    t('Student programs'),
    t('Login name'),
    t('E-mail '),
    t('Last login '),
    t('Student ID'),
    t('Course term'),
    t('Course subject'),
    t('Course number'),
    t('Course section'),
    t('Site'),
    t('Site staff first name'),
    t('Site staff last name'),
    t('Fields'),
    t('Catalog number'),
    t('First day of service'),
    t('Semester or term'),
    t('Page'),
    t('Export CSV'),
    t('Export XLS'),
    t('Export DOC'),
  );
  $export['reports_students'] = $view;

  return $export;
}
