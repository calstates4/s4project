<?php
/**
 * @file
 * s4_core.views_default.inc
 */

/**
 * Implementation of hook_views_default_views().
 */
function s4_core_views_default_views() {
  $export = array();

  $view = new view;
  $view->name = 'community_member_your_sites';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Community member: your sites';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Your sites';
  $handler->display->display_options['css_class'] = 'intro';
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['query']['options']['query_comment'] = FALSE;
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '15';
  $handler->display->display_options['style_plugin'] = 'list';
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Header: Global: Text area */
  $handler->display->display_options['header']['area']['id'] = 'area';
  $handler->display->display_options['header']['area']['table'] = 'views';
  $handler->display->display_options['header']['area']['field'] = 'area';
  $handler->display->display_options['header']['area']['label'] = 'Instructions';
  $handler->display->display_options['header']['area']['empty'] = FALSE;
  $handler->display->display_options['header']['area']['content'] = 'You have been given access to edit and view the students within these sites:';
  $handler->display->display_options['header']['area']['format'] = 'filtered_html';
  $handler->display->display_options['header']['area']['tokenize'] = 0;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['title']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['title']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = 0;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = 0;
  $handler->display->display_options['fields']['title']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['title']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['title']['alter']['html'] = 0;
  $handler->display->display_options['fields']['title']['hide_empty'] = 0;
  $handler->display->display_options['fields']['title']['empty_zero'] = 0;
  $handler->display->display_options['fields']['title']['link_to_node'] = 1;
  /* Sort criterion: Content: Post date */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'node';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
  /* Contextual filter: Content: Additional users (field_site_users) */
  $handler->display->display_options['arguments']['field_site_users_uid']['id'] = 'field_site_users_uid';
  $handler->display->display_options['arguments']['field_site_users_uid']['table'] = 'field_data_field_site_users';
  $handler->display->display_options['arguments']['field_site_users_uid']['field'] = 'field_site_users_uid';
  $handler->display->display_options['arguments']['field_site_users_uid']['default_action'] = 'default';
  $handler->display->display_options['arguments']['field_site_users_uid']['default_argument_type'] = 'current_user';
  $handler->display->display_options['arguments']['field_site_users_uid']['default_argument_skip_url'] = 0;
  $handler->display->display_options['arguments']['field_site_users_uid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['field_site_users_uid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['field_site_users_uid']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['field_site_users_uid']['break_phrase'] = 0;
  $handler->display->display_options['arguments']['field_site_users_uid']['not'] = 0;
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
    'site' => 'site',
  );

  /* Display: Block */
  $handler = $view->new_display('block', 'Block', 'block');
  $translatables['community_member_your_sites'] = array(
    t('Master'),
    t('Your sites'),
    t('more'),
    t('Apply'),
    t('Reset'),
    t('Sort by'),
    t('Asc'),
    t('Desc'),
    t('Items per page'),
    t('- All -'),
    t('Offset'),
    t('Instructions'),
    t('You have been given access to edit and view the students within these sites:'),
    t('All'),
    t('Block'),
  );
  $export['community_member_your_sites'] = $view;

  $view = new view;
  $view->name = 'email_students';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Email: Students';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Email: Students';
  $handler->display->display_options['access']['type'] = 'role';
  $handler->display->display_options['access']['role'] = array(
    4 => '4',
  );
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['query']['options']['query_comment'] = FALSE;
  $handler->display->display_options['exposed_form']['type'] = 'better_exposed_filters';
  $handler->display->display_options['exposed_form']['options']['submit_button'] = 'Search';
  $handler->display->display_options['exposed_form']['options']['autosubmit'] = 0;
  $handler->display->display_options['exposed_form']['options']['autosubmit_hide'] = 1;
  $handler->display->display_options['exposed_form']['options']['bef'] = array(
    'field_term_nid' => array(
      'bef_format' => 'default',
      'more_options' => array(
        'bef_select_all_none' => 0,
        'bef_collapsible' => 0,
        'bef_filter_description' => '',
      ),
    ),
    'field_site_restrict_tid' => array(
      'bef_format' => 'bef',
      'more_options' => array(
        'bef_select_all_none' => 0,
        'bef_collapsible' => 0,
        'bef_filter_description' => '',
      ),
    ),
  );
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '30';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['pager']['options']['id'] = '0';
  $handler->display->display_options['pager']['options']['expose']['items_per_page_options_all'] = 0;
  $handler->display->display_options['style_plugin'] = 'table';
  /* Relationship: Content: User (field_user) */
  $handler->display->display_options['relationships']['field_user_uid']['id'] = 'field_user_uid';
  $handler->display->display_options['relationships']['field_user_uid']['table'] = 'field_data_field_user';
  $handler->display->display_options['relationships']['field_user_uid']['field'] = 'field_user_uid';
  $handler->display->display_options['relationships']['field_user_uid']['required'] = 0;
  $handler->display->display_options['relationships']['field_user_uid']['delta'] = '-1';
  /* Relationship: Content: Course (field_course) */
  $handler->display->display_options['relationships']['field_course_nid']['id'] = 'field_course_nid';
  $handler->display->display_options['relationships']['field_course_nid']['table'] = 'field_data_field_course';
  $handler->display->display_options['relationships']['field_course_nid']['field'] = 'field_course_nid';
  $handler->display->display_options['relationships']['field_course_nid']['required'] = 0;
  $handler->display->display_options['relationships']['field_course_nid']['delta'] = '-1';
  /* Field: User: Bulk operations */
  $handler->display->display_options['fields']['views_bulk_operations']['id'] = 'views_bulk_operations';
  $handler->display->display_options['fields']['views_bulk_operations']['table'] = 'users';
  $handler->display->display_options['fields']['views_bulk_operations']['field'] = 'views_bulk_operations';
  $handler->display->display_options['fields']['views_bulk_operations']['relationship'] = 'field_user_uid';
  $handler->display->display_options['fields']['views_bulk_operations']['label'] = 'Email';
  $handler->display->display_options['fields']['views_bulk_operations']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['views_bulk_operations']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['views_bulk_operations']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['views_bulk_operations']['alter']['external'] = 0;
  $handler->display->display_options['fields']['views_bulk_operations']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['views_bulk_operations']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['views_bulk_operations']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['views_bulk_operations']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['views_bulk_operations']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['views_bulk_operations']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['views_bulk_operations']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['views_bulk_operations']['alter']['html'] = 0;
  $handler->display->display_options['fields']['views_bulk_operations']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['views_bulk_operations']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['views_bulk_operations']['hide_empty'] = 0;
  $handler->display->display_options['fields']['views_bulk_operations']['empty_zero'] = 0;
  $handler->display->display_options['fields']['views_bulk_operations']['hide_alter_empty'] = 0;
  $handler->display->display_options['fields']['views_bulk_operations']['vbo']['operations'] = array(
    's4_core_email_user_action' => array(
      'selected' => TRUE,
      'skip_confirmation' => 0,
    ),
  );
  $handler->display->display_options['fields']['views_bulk_operations']['vbo']['display_type'] = '1';
  $handler->display->display_options['fields']['views_bulk_operations']['vbo']['display_result'] = 1;
  $handler->display->display_options['fields']['views_bulk_operations']['vbo']['merge_single_action'] = 0;
  /* Field: Field: First Name */
  $handler->display->display_options['fields']['field_first_name']['id'] = 'field_first_name';
  $handler->display->display_options['fields']['field_first_name']['table'] = 'field_data_field_first_name';
  $handler->display->display_options['fields']['field_first_name']['field'] = 'field_first_name';
  $handler->display->display_options['fields']['field_first_name']['relationship'] = 'field_user_uid';
  $handler->display->display_options['fields']['field_first_name']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_first_name']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_first_name']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_first_name']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_first_name']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_first_name']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_first_name']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_first_name']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_first_name']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_first_name']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_first_name']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_first_name']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_first_name']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['field_first_name']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_first_name']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_first_name']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_first_name']['hide_alter_empty'] = 0;
  $handler->display->display_options['fields']['field_first_name']['field_api_classes'] = 0;
  /* Field: Field: Last Name */
  $handler->display->display_options['fields']['field_last_name']['id'] = 'field_last_name';
  $handler->display->display_options['fields']['field_last_name']['table'] = 'field_data_field_last_name';
  $handler->display->display_options['fields']['field_last_name']['field'] = 'field_last_name';
  $handler->display->display_options['fields']['field_last_name']['relationship'] = 'field_user_uid';
  $handler->display->display_options['fields']['field_last_name']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_last_name']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_last_name']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_last_name']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_last_name']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_last_name']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_last_name']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_last_name']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_last_name']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_last_name']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_last_name']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_last_name']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_last_name']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['field_last_name']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_last_name']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_last_name']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_last_name']['hide_alter_empty'] = 0;
  $handler->display->display_options['fields']['field_last_name']['field_api_classes'] = 0;
  /* Field: Content: Site */
  $handler->display->display_options['fields']['field_site']['id'] = 'field_site';
  $handler->display->display_options['fields']['field_site']['table'] = 'field_data_field_site';
  $handler->display->display_options['fields']['field_site']['field'] = 'field_site';
  $handler->display->display_options['fields']['field_site']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_site']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_site']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_site']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_site']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_site']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_site']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_site']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_site']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_site']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_site']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_site']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_site']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['field_site']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_site']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_site']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_site']['hide_alter_empty'] = 0;
  $handler->display->display_options['fields']['field_site']['field_api_classes'] = 0;
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
  $handler->display->display_options['filters']['status']['group'] = 0;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'signup' => 'signup',
  );
  /* Filter criterion: Content: Term (field_term) */
  $handler->display->display_options['filters']['field_term_nid']['id'] = 'field_term_nid';
  $handler->display->display_options['filters']['field_term_nid']['table'] = 'field_data_field_term';
  $handler->display->display_options['filters']['field_term_nid']['field'] = 'field_term_nid';
  $handler->display->display_options['filters']['field_term_nid']['relationship'] = 'field_course_nid';
  $handler->display->display_options['filters']['field_term_nid']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_term_nid']['expose']['operator_id'] = 'field_term_nid_op';
  $handler->display->display_options['filters']['field_term_nid']['expose']['label'] = 'Term';
  $handler->display->display_options['filters']['field_term_nid']['expose']['operator'] = 'field_term_nid_op';
  $handler->display->display_options['filters']['field_term_nid']['expose']['identifier'] = 'field_term_nid';
  $handler->display->display_options['filters']['field_term_nid']['expose']['reduce'] = 0;
  /* Filter criterion: Field: Restricted to (field_site_restrict) */
  $handler->display->display_options['filters']['field_site_restrict_tid']['id'] = 'field_site_restrict_tid';
  $handler->display->display_options['filters']['field_site_restrict_tid']['table'] = 'field_data_field_site_restrict';
  $handler->display->display_options['filters']['field_site_restrict_tid']['field'] = 'field_site_restrict_tid';
  $handler->display->display_options['filters']['field_site_restrict_tid']['relationship'] = 'field_user_uid';
  $handler->display->display_options['filters']['field_site_restrict_tid']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_site_restrict_tid']['expose']['operator_id'] = 'field_site_restrict_tid_op';
  $handler->display->display_options['filters']['field_site_restrict_tid']['expose']['label'] = 'Student site access';
  $handler->display->display_options['filters']['field_site_restrict_tid']['expose']['operator'] = 'field_site_restrict_tid_op';
  $handler->display->display_options['filters']['field_site_restrict_tid']['expose']['identifier'] = 'field_site_restrict_tid';
  $handler->display->display_options['filters']['field_site_restrict_tid']['expose']['multiple'] = 1;
  $handler->display->display_options['filters']['field_site_restrict_tid']['expose']['reduce'] = 0;
  $handler->display->display_options['filters']['field_site_restrict_tid']['reduce_duplicates'] = 0;
  $handler->display->display_options['filters']['field_site_restrict_tid']['type'] = 'select';
  $handler->display->display_options['filters']['field_site_restrict_tid']['vocabulary'] = 'site_restrictions';
  $handler->display->display_options['filters']['field_site_restrict_tid']['error_message'] = 1;

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page');
  $handler->display->display_options['path'] = 'email/students';
  $handler->display->display_options['menu']['type'] = 'tab';
  $handler->display->display_options['menu']['title'] = 'Students';
  $handler->display->display_options['menu']['weight'] = '0';
  $translatables['email_students'] = array(
    t('Master'),
    t('Email: Students'),
    t('more'),
    t('Search'),
    t('Reset'),
    t('Sort by'),
    t('Asc'),
    t('Desc'),
    t('Items per page'),
    t('- All -'),
    t('Offset'),
    t('field_user'),
    t('field_course'),
    t('Email'),
    t('First Name'),
    t('Last Name'),
    t('Site'),
    t('Term'),
    t('Student site access'),
    t('Page'),
  );
  $export['email_students'] = $view;

  $view = new view;
  $view->name = 's4_search';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'S4: Search entire site';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Coordinators';
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['query']['options']['query_comment'] = FALSE;
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['exposed_form']['options']['submit_button'] = 'Search';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '20';
  $handler->display->display_options['style_plugin'] = 'list';
  $handler->display->display_options['style_options']['wrapper_class'] = 'site-listing';
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['row_options']['hide_empty'] = 0;
  $handler->display->display_options['row_options']['default_field_elements'] = 1;
  $handler->display->display_options['exposed_block'] = TRUE;
  /* Field: Content: Issues addressed */
  $handler->display->display_options['fields']['field_csu_facility']['id'] = 'field_csu_facility';
  $handler->display->display_options['fields']['field_csu_facility']['table'] = 'field_data_field_csu_facility';
  $handler->display->display_options['fields']['field_csu_facility']['field'] = 'field_csu_facility';
  $handler->display->display_options['fields']['field_csu_facility']['label'] = '';
  $handler->display->display_options['fields']['field_csu_facility']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_csu_facility']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_csu_facility']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_csu_facility']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_csu_facility']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_csu_facility']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_csu_facility']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_csu_facility']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_csu_facility']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_csu_facility']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_csu_facility']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_csu_facility']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_csu_facility']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_csu_facility']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_csu_facility']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_csu_facility']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_csu_facility']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_csu_facility']['hide_alter_empty'] = 0;
  $handler->display->display_options['fields']['field_csu_facility']['field_api_classes'] = 0;
  /* Field: Content: Organization type */
  $handler->display->display_options['fields']['field_csu_org_type']['id'] = 'field_csu_org_type';
  $handler->display->display_options['fields']['field_csu_org_type']['table'] = 'field_data_field_csu_org_type';
  $handler->display->display_options['fields']['field_csu_org_type']['field'] = 'field_csu_org_type';
  $handler->display->display_options['fields']['field_csu_org_type']['label'] = '';
  $handler->display->display_options['fields']['field_csu_org_type']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_csu_org_type']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_csu_org_type']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_csu_org_type']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_csu_org_type']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_csu_org_type']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_csu_org_type']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_csu_org_type']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_csu_org_type']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_csu_org_type']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_csu_org_type']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_csu_org_type']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_csu_org_type']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_csu_org_type']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_csu_org_type']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_csu_org_type']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_csu_org_type']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_csu_org_type']['hide_alter_empty'] = 0;
  $handler->display->display_options['fields']['field_csu_org_type']['field_api_classes'] = 0;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['alter_text'] = 1;
  $handler->display->display_options['fields']['title']['alter']['text'] = '<h4>[title]</h4>
<div class="meta">[field_csu_facility] - [field_csu_org_type]</div>';
  $handler->display->display_options['fields']['title']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['title']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['title']['alter']['external'] = 0;
  $handler->display->display_options['fields']['title']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['title']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['title']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = 0;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = 0;
  $handler->display->display_options['fields']['title']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['title']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['title']['alter']['html'] = 0;
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['title']['hide_empty'] = 0;
  $handler->display->display_options['fields']['title']['empty_zero'] = 0;
  $handler->display->display_options['fields']['title']['hide_alter_empty'] = 0;
  $handler->display->display_options['fields']['title']['link_to_node'] = 1;
  /* Field: Content: Body */
  $handler->display->display_options['fields']['body']['id'] = 'body';
  $handler->display->display_options['fields']['body']['table'] = 'field_data_body';
  $handler->display->display_options['fields']['body']['field'] = 'body';
  $handler->display->display_options['fields']['body']['label'] = '';
  $handler->display->display_options['fields']['body']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['body']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['body']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['body']['alter']['external'] = 0;
  $handler->display->display_options['fields']['body']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['body']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['body']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['body']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['body']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['body']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['body']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['body']['alter']['html'] = 0;
  $handler->display->display_options['fields']['body']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['body']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['body']['hide_empty'] = 0;
  $handler->display->display_options['fields']['body']['empty_zero'] = 0;
  $handler->display->display_options['fields']['body']['hide_alter_empty'] = 0;
  $handler->display->display_options['fields']['body']['type'] = 'text_summary_or_trimmed';
  $handler->display->display_options['fields']['body']['settings'] = array(
    'trim_length' => '600',
  );
  $handler->display->display_options['fields']['body']['field_api_classes'] = 0;
  /* Sort criterion: Search: Score */
  $handler->display->display_options['sorts']['score']['id'] = 'score';
  $handler->display->display_options['sorts']['score']['table'] = 'search_index';
  $handler->display->display_options['sorts']['score']['field'] = 'score';
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
  $handler->display->display_options['filters']['status']['group'] = 0;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Search: Search Terms */
  $handler->display->display_options['filters']['keys']['id'] = 'keys';
  $handler->display->display_options['filters']['keys']['table'] = 'search_index';
  $handler->display->display_options['filters']['keys']['field'] = 'keys';
  $handler->display->display_options['filters']['keys']['exposed'] = TRUE;
  $handler->display->display_options['filters']['keys']['expose']['operator_id'] = 'keys_op';
  $handler->display->display_options['filters']['keys']['expose']['label'] = 'Search';
  $handler->display->display_options['filters']['keys']['expose']['operator'] = 'keys_op';
  $handler->display->display_options['filters']['keys']['expose']['identifier'] = 'keys';
  $handler->display->display_options['filters']['keys']['expose']['multiple'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'site' => 'site',
  );

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Search';
  $handler->display->display_options['exposed_block'] = TRUE;
  $handler->display->display_options['path'] = 'site-search';

  /* Display: Feed */
  $handler = $view->new_display('feed', 'Feed', 'feed');
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['style_plugin'] = 'rss';
  $handler->display->display_options['row_plugin'] = 'node_rss';
  $handler->display->display_options['path'] = 'search.xml';
  $handler->display->display_options['displays'] = array(
    'default' => 'default',
    'page' => 'page',
  );

  /* Display: Coordinator search */
  $handler = $view->new_display('block', 'Coordinator search', 'block_1');
  $handler->display->display_options['defaults']['use_ajax'] = FALSE;
  $handler->display->display_options['use_ajax'] = TRUE;
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'mini';
  $handler->display->display_options['pager']['options']['items_per_page'] = '20';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['pager']['options']['id'] = '0';
  $handler->display->display_options['pager']['options']['expose']['items_per_page_options_all'] = 0;
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'list';
  $handler->display->display_options['style_options']['wrapper_class'] = 'search-sidebar';
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['row_options']['inline'] = array(
    'field_last_name' => 'field_last_name',
    'field_site' => 'field_site',
  );
  $handler->display->display_options['row_options']['hide_empty'] = 0;
  $handler->display->display_options['row_options']['default_field_elements'] = 0;
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Nid */
  $handler->display->display_options['fields']['nid']['id'] = 'nid';
  $handler->display->display_options['fields']['nid']['table'] = 'node';
  $handler->display->display_options['fields']['nid']['field'] = 'nid';
  $handler->display->display_options['fields']['nid']['label'] = '';
  $handler->display->display_options['fields']['nid']['exclude'] = TRUE;
  $handler->display->display_options['fields']['nid']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['nid']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['nid']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['nid']['alter']['external'] = 0;
  $handler->display->display_options['fields']['nid']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['nid']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['nid']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['nid']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['nid']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['nid']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['nid']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['nid']['alter']['html'] = 0;
  $handler->display->display_options['fields']['nid']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['nid']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['nid']['hide_empty'] = 0;
  $handler->display->display_options['fields']['nid']['empty_zero'] = 0;
  $handler->display->display_options['fields']['nid']['hide_alter_empty'] = 0;
  $handler->display->display_options['fields']['nid']['link_to_node'] = 0;
  /* Field: Field: First Name */
  $handler->display->display_options['fields']['field_first_name']['id'] = 'field_first_name';
  $handler->display->display_options['fields']['field_first_name']['table'] = 'field_data_field_first_name';
  $handler->display->display_options['fields']['field_first_name']['field'] = 'field_first_name';
  $handler->display->display_options['fields']['field_first_name']['label'] = '';
  $handler->display->display_options['fields']['field_first_name']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_first_name']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_first_name']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_first_name']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_first_name']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_first_name']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_first_name']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_first_name']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_first_name']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_first_name']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_first_name']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_first_name']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_first_name']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_first_name']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_first_name']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_first_name']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_first_name']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_first_name']['hide_alter_empty'] = 0;
  $handler->display->display_options['fields']['field_first_name']['field_api_classes'] = 0;
  /* Field: Field: Last Name */
  $handler->display->display_options['fields']['field_last_name']['id'] = 'field_last_name';
  $handler->display->display_options['fields']['field_last_name']['table'] = 'field_data_field_last_name';
  $handler->display->display_options['fields']['field_last_name']['field'] = 'field_last_name';
  $handler->display->display_options['fields']['field_last_name']['label'] = '';
  $handler->display->display_options['fields']['field_last_name']['alter']['alter_text'] = 1;
  $handler->display->display_options['fields']['field_last_name']['alter']['text'] = '[field_last_name], [field_first_name] ';
  $handler->display->display_options['fields']['field_last_name']['alter']['make_link'] = 1;
  $handler->display->display_options['fields']['field_last_name']['alter']['path'] = 'node/[nid]';
  $handler->display->display_options['fields']['field_last_name']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_last_name']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_last_name']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_last_name']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_last_name']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_last_name']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_last_name']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_last_name']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_last_name']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_last_name']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_last_name']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_last_name']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_last_name']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_last_name']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_last_name']['hide_alter_empty'] = 0;
  $handler->display->display_options['fields']['field_last_name']['field_api_classes'] = 0;
  /* Field: Content: Site */
  $handler->display->display_options['fields']['field_site']['id'] = 'field_site';
  $handler->display->display_options['fields']['field_site']['table'] = 'field_data_field_site';
  $handler->display->display_options['fields']['field_site']['field'] = 'field_site';
  $handler->display->display_options['fields']['field_site']['label'] = '';
  $handler->display->display_options['fields']['field_site']['alter']['alter_text'] = 1;
  $handler->display->display_options['fields']['field_site']['alter']['text'] = ' at [field_site]';
  $handler->display->display_options['fields']['field_site']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_site']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_site']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_site']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_site']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_site']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_site']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_site']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_site']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_site']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_site']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_site']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_site']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_site']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_site']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_site']['hide_alter_empty'] = 0;
  $handler->display->display_options['fields']['field_site']['field_api_classes'] = 0;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 0;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Search: Search Terms */
  $handler->display->display_options['filters']['keys']['id'] = 'keys';
  $handler->display->display_options['filters']['keys']['table'] = 'search_index';
  $handler->display->display_options['filters']['keys']['field'] = 'keys';
  $handler->display->display_options['filters']['keys']['exposed'] = TRUE;
  $handler->display->display_options['filters']['keys']['expose']['operator_id'] = 'keys_op';
  $handler->display->display_options['filters']['keys']['expose']['label'] = 'Search';
  $handler->display->display_options['filters']['keys']['expose']['operator'] = 'keys_op';
  $handler->display->display_options['filters']['keys']['expose']['identifier'] = 'keys';
  $handler->display->display_options['filters']['keys']['expose']['multiple'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'coordinator' => 'coordinator',
  );
  $handler->display->display_options['block_description'] = 'Search coordinators';
  $translatables['s4_search'] = array(
    t('Master'),
    t('Coordinators'),
    t('more'),
    t('Search'),
    t('Reset'),
    t('Sort by'),
    t('Asc'),
    t('Desc'),
    t('Items per page'),
    t('- All -'),
    t('Offset'),
    t('<h4>[title]</h4>
<div class="meta">[field_csu_facility] - [field_csu_org_type]</div>'),
    t('Page'),
    t('Feed'),
    t('Coordinator search'),
    t('[field_last_name], [field_first_name] '),
    t('node/[nid]'),
    t(' at [field_site]'),
    t('Search coordinators'),
  );
  $export['s4_search'] = $view;

  $view = new view;
  $view->name = 's4_search_students';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'users';
  $view->human_name = 's4: Search students';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Students';
  $handler->display->display_options['use_ajax'] = TRUE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['access']['perm'] = 'edit any signup content';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['query']['options']['query_comment'] = FALSE;
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'mini';
  $handler->display->display_options['pager']['options']['items_per_page'] = '20';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['pager']['options']['id'] = '0';
  $handler->display->display_options['pager']['options']['expose']['items_per_page_options_all'] = 0;
  $handler->display->display_options['style_plugin'] = 'list';
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['row_options']['hide_empty'] = 0;
  $handler->display->display_options['row_options']['default_field_elements'] = 0;
  /* Field: Field: First Name */
  $handler->display->display_options['fields']['field_first_name']['id'] = 'field_first_name';
  $handler->display->display_options['fields']['field_first_name']['table'] = 'field_data_field_first_name';
  $handler->display->display_options['fields']['field_first_name']['field'] = 'field_first_name';
  $handler->display->display_options['fields']['field_first_name']['label'] = '';
  $handler->display->display_options['fields']['field_first_name']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_first_name']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_first_name']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_first_name']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_first_name']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_first_name']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_first_name']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_first_name']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_first_name']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_first_name']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_first_name']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_first_name']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_first_name']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_first_name']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_first_name']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_first_name']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_first_name']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_first_name']['hide_alter_empty'] = 0;
  $handler->display->display_options['fields']['field_first_name']['field_api_classes'] = 0;
  /* Field: Field: Last Name */
  $handler->display->display_options['fields']['field_last_name']['id'] = 'field_last_name';
  $handler->display->display_options['fields']['field_last_name']['table'] = 'field_data_field_last_name';
  $handler->display->display_options['fields']['field_last_name']['field'] = 'field_last_name';
  $handler->display->display_options['fields']['field_last_name']['label'] = '';
  $handler->display->display_options['fields']['field_last_name']['alter']['alter_text'] = 1;
  $handler->display->display_options['fields']['field_last_name']['alter']['text'] = '[field_last_name], [field_first_name]';
  $handler->display->display_options['fields']['field_last_name']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_last_name']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_last_name']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_last_name']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_last_name']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_last_name']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_last_name']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_last_name']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_last_name']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_last_name']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_last_name']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_last_name']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_last_name']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_last_name']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_last_name']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_last_name']['hide_alter_empty'] = 0;
  $handler->display->display_options['fields']['field_last_name']['field_api_classes'] = 0;
  /* Field: User: Name */
  $handler->display->display_options['fields']['name']['id'] = 'name';
  $handler->display->display_options['fields']['name']['table'] = 'users';
  $handler->display->display_options['fields']['name']['field'] = 'name';
  $handler->display->display_options['fields']['name']['label'] = '';
  $handler->display->display_options['fields']['name']['alter']['alter_text'] = 1;
  $handler->display->display_options['fields']['name']['alter']['text'] = '([name])';
  $handler->display->display_options['fields']['name']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['name']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['name']['alter']['external'] = 0;
  $handler->display->display_options['fields']['name']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['name']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['name']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['name']['alter']['word_boundary'] = 0;
  $handler->display->display_options['fields']['name']['alter']['ellipsis'] = 0;
  $handler->display->display_options['fields']['name']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['name']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['name']['alter']['html'] = 0;
  $handler->display->display_options['fields']['name']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['name']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['name']['hide_empty'] = 0;
  $handler->display->display_options['fields']['name']['empty_zero'] = 0;
  $handler->display->display_options['fields']['name']['hide_alter_empty'] = 0;
  $handler->display->display_options['fields']['name']['link_to_user'] = 1;
  $handler->display->display_options['fields']['name']['overwrite_anonymous'] = 0;
  /* Sort criterion: Field: Last Name (field_last_name:format) */
  $handler->display->display_options['sorts']['field_last_name_format']['id'] = 'field_last_name_format';
  $handler->display->display_options['sorts']['field_last_name_format']['table'] = 'field_data_field_last_name';
  $handler->display->display_options['sorts']['field_last_name_format']['field'] = 'field_last_name_format';
  /* Sort criterion: Field: First Name (field_first_name:format) */
  $handler->display->display_options['sorts']['field_first_name_format']['id'] = 'field_first_name_format';
  $handler->display->display_options['sorts']['field_first_name_format']['table'] = 'field_data_field_first_name';
  $handler->display->display_options['sorts']['field_first_name_format']['field'] = 'field_first_name_format';
  /* Filter criterion: User: Name */
  $handler->display->display_options['filters']['uid']['id'] = 'uid';
  $handler->display->display_options['filters']['uid']['table'] = 'users';
  $handler->display->display_options['filters']['uid']['field'] = 'uid';
  $handler->display->display_options['filters']['uid']['value'] = '';
  $handler->display->display_options['filters']['uid']['exposed'] = TRUE;
  $handler->display->display_options['filters']['uid']['expose']['operator_id'] = 'uid_op';
  $handler->display->display_options['filters']['uid']['expose']['label'] = 'Name';
  $handler->display->display_options['filters']['uid']['expose']['operator'] = 'uid_op';
  $handler->display->display_options['filters']['uid']['expose']['identifier'] = 'keys';
  $handler->display->display_options['filters']['uid']['expose']['required'] = 1;
  $handler->display->display_options['filters']['uid']['expose']['multiple'] = FALSE;
  $handler->display->display_options['filters']['uid']['expose']['reduce'] = 0;

  /* Display: Block */
  $handler = $view->new_display('block', 'Block', 'block');
  $handler->display->display_options['block_description'] = 'Search for students';
  $translatables['s4_search_students'] = array(
    t('Master'),
    t('Students'),
    t('more'),
    t('Apply'),
    t('Reset'),
    t('Sort by'),
    t('Asc'),
    t('Desc'),
    t('Items per page'),
    t('- All -'),
    t('Offset'),
    t('[field_last_name], [field_first_name]'),
    t('([name])'),
    t('Name'),
    t('Block'),
    t('Search for students'),
  );
  $export['s4_search_students'] = $view;

  $view = new view;
  $view->name = 's4_students';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'users';
  $view->human_name = 'S4: Students';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Students';
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['access']['perm'] = 'access user profiles';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['query']['options']['query_comment'] = FALSE;
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '40';
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['columns'] = array(
    'name' => 'name',
    'field_first_name' => 'field_first_name',
    'field_last_name' => 'field_last_name',
  );
  $handler->display->display_options['style_options']['default'] = '-1';
  $handler->display->display_options['style_options']['info'] = array(
    'name' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
    ),
    'field_first_name' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
    ),
    'field_last_name' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
    ),
  );
  $handler->display->display_options['style_options']['override'] = 1;
  $handler->display->display_options['style_options']['sticky'] = 0;
  $handler->display->display_options['style_options']['empty_table'] = 0;
  /* Field: Field: First Name */
  $handler->display->display_options['fields']['field_first_name']['id'] = 'field_first_name';
  $handler->display->display_options['fields']['field_first_name']['table'] = 'field_data_field_first_name';
  $handler->display->display_options['fields']['field_first_name']['field'] = 'field_first_name';
  $handler->display->display_options['fields']['field_first_name']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_first_name']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_first_name']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_first_name']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_first_name']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_first_name']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_first_name']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_first_name']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_first_name']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_first_name']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_first_name']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_first_name']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_first_name']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['field_first_name']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_first_name']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_first_name']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_first_name']['hide_alter_empty'] = 0;
  $handler->display->display_options['fields']['field_first_name']['field_api_classes'] = 0;
  /* Field: Field: Last Name */
  $handler->display->display_options['fields']['field_last_name']['id'] = 'field_last_name';
  $handler->display->display_options['fields']['field_last_name']['table'] = 'field_data_field_last_name';
  $handler->display->display_options['fields']['field_last_name']['field'] = 'field_last_name';
  $handler->display->display_options['fields']['field_last_name']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_last_name']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_last_name']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_last_name']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_last_name']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_last_name']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_last_name']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_last_name']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_last_name']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_last_name']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_last_name']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_last_name']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_last_name']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['field_last_name']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_last_name']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_last_name']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_last_name']['hide_alter_empty'] = 0;
  $handler->display->display_options['fields']['field_last_name']['field_api_classes'] = 0;
  /* Field: User: Name */
  $handler->display->display_options['fields']['name']['id'] = 'name';
  $handler->display->display_options['fields']['name']['table'] = 'users';
  $handler->display->display_options['fields']['name']['field'] = 'name';
  $handler->display->display_options['fields']['name']['label'] = 'Login ID';
  $handler->display->display_options['fields']['name']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['name']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['name']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['name']['alter']['external'] = 0;
  $handler->display->display_options['fields']['name']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['name']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['name']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['name']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['name']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['name']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['name']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['name']['alter']['html'] = 0;
  $handler->display->display_options['fields']['name']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['name']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['name']['hide_empty'] = 0;
  $handler->display->display_options['fields']['name']['empty_zero'] = 0;
  $handler->display->display_options['fields']['name']['hide_alter_empty'] = 0;
  $handler->display->display_options['fields']['name']['link_to_user'] = 0;
  $handler->display->display_options['fields']['name']['overwrite_anonymous'] = 0;
  /* Field: User: Last login */
  $handler->display->display_options['fields']['login']['id'] = 'login';
  $handler->display->display_options['fields']['login']['table'] = 'users';
  $handler->display->display_options['fields']['login']['field'] = 'login';
  $handler->display->display_options['fields']['login']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['login']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['login']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['login']['alter']['external'] = 0;
  $handler->display->display_options['fields']['login']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['login']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['login']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['login']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['login']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['login']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['login']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['login']['alter']['html'] = 0;
  $handler->display->display_options['fields']['login']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['login']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['login']['hide_empty'] = 0;
  $handler->display->display_options['fields']['login']['empty_zero'] = 0;
  $handler->display->display_options['fields']['login']['hide_alter_empty'] = 0;
  $handler->display->display_options['fields']['login']['date_format'] = 'long';
  /* Field: Global: Custom text */
  $handler->display->display_options['fields']['nothing_1']['id'] = 'nothing_1';
  $handler->display->display_options['fields']['nothing_1']['table'] = 'views';
  $handler->display->display_options['fields']['nothing_1']['field'] = 'nothing';
  $handler->display->display_options['fields']['nothing_1']['label'] = 'View';
  $handler->display->display_options['fields']['nothing_1']['alter']['text'] = 'view';
  $handler->display->display_options['fields']['nothing_1']['alter']['make_link'] = 1;
  $handler->display->display_options['fields']['nothing_1']['alter']['path'] = 'user/[uid]';
  $handler->display->display_options['fields']['nothing_1']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['nothing_1']['alter']['external'] = 0;
  $handler->display->display_options['fields']['nothing_1']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['nothing_1']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['nothing_1']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['nothing_1']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['nothing_1']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['nothing_1']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['nothing_1']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['nothing_1']['alter']['html'] = 0;
  $handler->display->display_options['fields']['nothing_1']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['nothing_1']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['nothing_1']['hide_empty'] = 0;
  $handler->display->display_options['fields']['nothing_1']['empty_zero'] = 0;
  $handler->display->display_options['fields']['nothing_1']['hide_alter_empty'] = 0;
  /* Field: User: Edit link */
  $handler->display->display_options['fields']['edit_node']['id'] = 'edit_node';
  $handler->display->display_options['fields']['edit_node']['table'] = 'users';
  $handler->display->display_options['fields']['edit_node']['field'] = 'edit_node';
  $handler->display->display_options['fields']['edit_node']['label'] = 'Edit';
  $handler->display->display_options['fields']['edit_node']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['edit_node']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['edit_node']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['edit_node']['alter']['external'] = 0;
  $handler->display->display_options['fields']['edit_node']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['edit_node']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['edit_node']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['edit_node']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['edit_node']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['edit_node']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['edit_node']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['edit_node']['alter']['html'] = 0;
  $handler->display->display_options['fields']['edit_node']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['edit_node']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['edit_node']['hide_empty'] = 0;
  $handler->display->display_options['fields']['edit_node']['empty_zero'] = 0;
  $handler->display->display_options['fields']['edit_node']['hide_alter_empty'] = 0;
  /* Field: User: Uid */
  $handler->display->display_options['fields']['uid']['id'] = 'uid';
  $handler->display->display_options['fields']['uid']['table'] = 'users';
  $handler->display->display_options['fields']['uid']['field'] = 'uid';
  $handler->display->display_options['fields']['uid']['exclude'] = TRUE;
  $handler->display->display_options['fields']['uid']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['uid']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['uid']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['uid']['alter']['external'] = 0;
  $handler->display->display_options['fields']['uid']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['uid']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['uid']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['uid']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['uid']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['uid']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['uid']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['uid']['alter']['html'] = 0;
  $handler->display->display_options['fields']['uid']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['uid']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['uid']['hide_empty'] = 0;
  $handler->display->display_options['fields']['uid']['empty_zero'] = 0;
  $handler->display->display_options['fields']['uid']['hide_alter_empty'] = 0;
  $handler->display->display_options['fields']['uid']['link_to_user'] = 1;
  /* Field: User Signup: List all signups for a user */
  $handler->display->display_options['fields']['student_signup_list']['id'] = 'student_signup_list';
  $handler->display->display_options['fields']['student_signup_list']['table'] = 's4_user_signup';
  $handler->display->display_options['fields']['student_signup_list']['field'] = 'student_signup_list';
  $handler->display->display_options['fields']['student_signup_list']['label'] = 'Signups';
  $handler->display->display_options['fields']['student_signup_list']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['student_signup_list']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['student_signup_list']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['student_signup_list']['alter']['external'] = 0;
  $handler->display->display_options['fields']['student_signup_list']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['student_signup_list']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['student_signup_list']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['student_signup_list']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['student_signup_list']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['student_signup_list']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['student_signup_list']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['student_signup_list']['alter']['html'] = 0;
  $handler->display->display_options['fields']['student_signup_list']['element_label_colon'] = 0;
  $handler->display->display_options['fields']['student_signup_list']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['student_signup_list']['hide_empty'] = 0;
  $handler->display->display_options['fields']['student_signup_list']['empty_zero'] = 0;
  $handler->display->display_options['fields']['student_signup_list']['hide_alter_empty'] = 0;
  /* Field: Global: Custom text */
  $handler->display->display_options['fields']['nothing']['id'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['table'] = 'views';
  $handler->display->display_options['fields']['nothing']['field'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['label'] = 'Add signup';
  $handler->display->display_options['fields']['nothing']['alter']['text'] = 'Sign-up student';
  $handler->display->display_options['fields']['nothing']['alter']['make_link'] = 1;
  $handler->display->display_options['fields']['nothing']['alter']['path'] = 'signup/create/[uid]';
  $handler->display->display_options['fields']['nothing']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['nothing']['alter']['external'] = 0;
  $handler->display->display_options['fields']['nothing']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['nothing']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['nothing']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['nothing']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['nothing']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['nothing']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['nothing']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['nothing']['alter']['html'] = 0;
  $handler->display->display_options['fields']['nothing']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['nothing']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['nothing']['hide_empty'] = 0;
  $handler->display->display_options['fields']['nothing']['empty_zero'] = 0;
  $handler->display->display_options['fields']['nothing']['hide_alter_empty'] = 0;
  /* Sort criterion: Field: Last Name (field_last_name) */
  $handler->display->display_options['sorts']['field_last_name_value']['id'] = 'field_last_name_value';
  $handler->display->display_options['sorts']['field_last_name_value']['table'] = 'field_data_field_last_name';
  $handler->display->display_options['sorts']['field_last_name_value']['field'] = 'field_last_name_value';
  /* Sort criterion: Field: First Name (field_first_name) */
  $handler->display->display_options['sorts']['field_first_name_value']['id'] = 'field_first_name_value';
  $handler->display->display_options['sorts']['field_first_name_value']['table'] = 'field_data_field_first_name';
  $handler->display->display_options['sorts']['field_first_name_value']['field'] = 'field_first_name_value';
  /* Filter criterion: User: Active */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'users';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = '1';
  $handler->display->display_options['filters']['status']['group'] = 0;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: User: Roles */
  $handler->display->display_options['filters']['rid']['id'] = 'rid';
  $handler->display->display_options['filters']['rid']['table'] = 'users_roles';
  $handler->display->display_options['filters']['rid']['field'] = 'rid';
  $handler->display->display_options['filters']['rid']['operator'] = 'not';
  $handler->display->display_options['filters']['rid']['value'] = array(
    3 => '3',
    4 => '4',
  );
  $handler->display->display_options['filters']['rid']['reduce_duplicates'] = 0;
  /* Filter criterion: Field: First Name (field_first_name) */
  $handler->display->display_options['filters']['field_first_name_value']['id'] = 'field_first_name_value';
  $handler->display->display_options['filters']['field_first_name_value']['table'] = 'field_data_field_first_name';
  $handler->display->display_options['filters']['field_first_name_value']['field'] = 'field_first_name_value';
  $handler->display->display_options['filters']['field_first_name_value']['operator'] = 'starts';
  $handler->display->display_options['filters']['field_first_name_value']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_first_name_value']['expose']['operator_id'] = 'field_first_name_value_op';
  $handler->display->display_options['filters']['field_first_name_value']['expose']['label'] = 'First Name';
  $handler->display->display_options['filters']['field_first_name_value']['expose']['operator'] = 'field_first_name_value_op';
  $handler->display->display_options['filters']['field_first_name_value']['expose']['identifier'] = 'field_first_name_value';
  $handler->display->display_options['filters']['field_first_name_value']['expose']['required'] = 0;
  $handler->display->display_options['filters']['field_first_name_value']['expose']['multiple'] = FALSE;
  /* Filter criterion: Field: Last Name (field_last_name) */
  $handler->display->display_options['filters']['field_last_name_value']['id'] = 'field_last_name_value';
  $handler->display->display_options['filters']['field_last_name_value']['table'] = 'field_data_field_last_name';
  $handler->display->display_options['filters']['field_last_name_value']['field'] = 'field_last_name_value';
  $handler->display->display_options['filters']['field_last_name_value']['operator'] = 'starts';
  $handler->display->display_options['filters']['field_last_name_value']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_last_name_value']['expose']['operator_id'] = 'field_last_name_value_op';
  $handler->display->display_options['filters']['field_last_name_value']['expose']['label'] = 'Last Name';
  $handler->display->display_options['filters']['field_last_name_value']['expose']['operator'] = 'field_last_name_value_op';
  $handler->display->display_options['filters']['field_last_name_value']['expose']['identifier'] = 'field_last_name_value';
  $handler->display->display_options['filters']['field_last_name_value']['expose']['required'] = 0;
  $handler->display->display_options['filters']['field_last_name_value']['expose']['multiple'] = FALSE;
  /* Filter criterion: User: Name (raw) */
  $handler->display->display_options['filters']['name']['id'] = 'name';
  $handler->display->display_options['filters']['name']['table'] = 'users';
  $handler->display->display_options['filters']['name']['field'] = 'name';
  $handler->display->display_options['filters']['name']['operator'] = 'starts';
  $handler->display->display_options['filters']['name']['exposed'] = TRUE;
  $handler->display->display_options['filters']['name']['expose']['operator_id'] = 'name_op';
  $handler->display->display_options['filters']['name']['expose']['label'] = 'Login ID';
  $handler->display->display_options['filters']['name']['expose']['operator'] = 'name_op';
  $handler->display->display_options['filters']['name']['expose']['identifier'] = 'name';
  $handler->display->display_options['filters']['name']['expose']['required'] = 0;
  $handler->display->display_options['filters']['name']['expose']['multiple'] = FALSE;
  /* Filter criterion: Field: Restricted to (field_site_restrict) */
  $handler->display->display_options['filters']['field_site_restrict_tid']['id'] = 'field_site_restrict_tid';
  $handler->display->display_options['filters']['field_site_restrict_tid']['table'] = 'field_data_field_site_restrict';
  $handler->display->display_options['filters']['field_site_restrict_tid']['field'] = 'field_site_restrict_tid';
  $handler->display->display_options['filters']['field_site_restrict_tid']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_site_restrict_tid']['expose']['operator_id'] = 'field_site_restrict_tid_op';
  $handler->display->display_options['filters']['field_site_restrict_tid']['expose']['label'] = 'Site restrictions';
  $handler->display->display_options['filters']['field_site_restrict_tid']['expose']['operator'] = 'field_site_restrict_tid_op';
  $handler->display->display_options['filters']['field_site_restrict_tid']['expose']['identifier'] = 'field_site_restrict_tid';
  $handler->display->display_options['filters']['field_site_restrict_tid']['expose']['reduce'] = 0;
  $handler->display->display_options['filters']['field_site_restrict_tid']['reduce_duplicates'] = 0;
  $handler->display->display_options['filters']['field_site_restrict_tid']['type'] = 'select';
  $handler->display->display_options['filters']['field_site_restrict_tid']['vocabulary'] = 'site_restrictions';
  $handler->display->display_options['filters']['field_site_restrict_tid']['error_message'] = 1;
  /* Filter criterion: User: Name */
  $handler->display->display_options['filters']['uid']['id'] = 'uid';
  $handler->display->display_options['filters']['uid']['table'] = 'users';
  $handler->display->display_options['filters']['uid']['field'] = 'uid';
  $handler->display->display_options['filters']['uid']['operator'] = 'not in';
  $handler->display->display_options['filters']['uid']['value'] = array(
    0 => 0,
  );

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page');
  $handler->display->display_options['path'] = 'students';
  $translatables['s4_students'] = array(
    t('Master'),
    t('Students'),
    t('more'),
    t('Apply'),
    t('Reset'),
    t('Sort by'),
    t('Asc'),
    t('Desc'),
    t('Items per page'),
    t('- All -'),
    t('Offset'),
    t('First Name'),
    t('Last Name'),
    t('Login ID'),
    t('Last login'),
    t('View'),
    t('view'),
    t('user/[uid]'),
    t('Edit'),
    t('Uid'),
    t('Signups'),
    t('Add signup'),
    t('Sign-up student'),
    t('signup/create/[uid]'),
    t('Site restrictions'),
    t('Page'),
  );
  $export['s4_students'] = $view;

  $view = new view;
  $view->name = 'site_forms';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Forms';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Forms';
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['access']['perm'] = 'create webform content';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['query']['options']['query_comment'] = FALSE;
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '20';
  $handler->display->display_options['style_plugin'] = 'table';
  /* Header: Global: Text area */
  $handler->display->display_options['header']['area']['id'] = 'area';
  $handler->display->display_options['header']['area']['table'] = 'views';
  $handler->display->display_options['header']['area']['field'] = 'area';
  $handler->display->display_options['header']['area']['empty'] = TRUE;
  $handler->display->display_options['header']['area']['content'] = '<p><a class="button" href="node/add/webform"><span class="add"></span>Add new form</a></p>';
  $handler->display->display_options['header']['area']['format'] = 'full_html';
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['title']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['title']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = 0;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = 0;
  $handler->display->display_options['fields']['title']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['title']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['title']['alter']['html'] = 0;
  $handler->display->display_options['fields']['title']['hide_empty'] = 0;
  $handler->display->display_options['fields']['title']['empty_zero'] = 0;
  $handler->display->display_options['fields']['title']['link_to_node'] = 1;
  /* Field: Content: Webform submission count */
  $handler->display->display_options['fields']['webform_submission_count_node']['id'] = 'webform_submission_count_node';
  $handler->display->display_options['fields']['webform_submission_count_node']['table'] = 'node';
  $handler->display->display_options['fields']['webform_submission_count_node']['field'] = 'webform_submission_count_node';
  $handler->display->display_options['fields']['webform_submission_count_node']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['webform_submission_count_node']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['webform_submission_count_node']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['webform_submission_count_node']['alter']['external'] = 0;
  $handler->display->display_options['fields']['webform_submission_count_node']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['webform_submission_count_node']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['webform_submission_count_node']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['webform_submission_count_node']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['webform_submission_count_node']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['webform_submission_count_node']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['webform_submission_count_node']['alter']['html'] = 0;
  $handler->display->display_options['fields']['webform_submission_count_node']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['webform_submission_count_node']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['webform_submission_count_node']['hide_empty'] = 0;
  $handler->display->display_options['fields']['webform_submission_count_node']['empty_zero'] = 0;
  /* Field: Content: Edit link */
  $handler->display->display_options['fields']['edit_node']['id'] = 'edit_node';
  $handler->display->display_options['fields']['edit_node']['table'] = 'node';
  $handler->display->display_options['fields']['edit_node']['field'] = 'edit_node';
  $handler->display->display_options['fields']['edit_node']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['edit_node']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['edit_node']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['edit_node']['alter']['external'] = 0;
  $handler->display->display_options['fields']['edit_node']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['edit_node']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['edit_node']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['edit_node']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['edit_node']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['edit_node']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['edit_node']['alter']['html'] = 0;
  $handler->display->display_options['fields']['edit_node']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['edit_node']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['edit_node']['hide_empty'] = 0;
  $handler->display->display_options['fields']['edit_node']['empty_zero'] = 0;
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
  $handler->display->display_options['filters']['status']['group'] = 0;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'webform' => 'webform',
  );

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page');
  $handler->display->display_options['path'] = 'forms';
  $translatables['site_forms'] = array(
    t('Master'),
    t('Forms'),
    t('more'),
    t('Apply'),
    t('Reset'),
    t('Sort by'),
    t('Asc'),
    t('Desc'),
    t('Items per page'),
    t('- All -'),
    t('Offset'),
    t('<p><a class="button" href="node/add/webform"><span class="add"></span>Add new form</a></p>'),
    t('# of Submissions'),
    t('Edit link'),
    t('Page'),
  );
  $export['site_forms'] = $view;

  $view = new view;
  $view->name = 'user_signups';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'User signups';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Your sites';
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['query']['options']['query_comment'] = FALSE;
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '0';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['pager']['options']['id'] = '0';
  $handler->display->display_options['pager']['options']['expose']['items_per_page_options_all'] = 0;
  $handler->display->display_options['style_plugin'] = 'table';
  /* Field: Content: Nid */
  $handler->display->display_options['fields']['nid']['id'] = 'nid';
  $handler->display->display_options['fields']['nid']['table'] = 'node';
  $handler->display->display_options['fields']['nid']['field'] = 'nid';
  $handler->display->display_options['fields']['nid']['label'] = 'View';
  $handler->display->display_options['fields']['nid']['alter']['alter_text'] = 1;
  $handler->display->display_options['fields']['nid']['alter']['text'] = 'Record # [nid]';
  $handler->display->display_options['fields']['nid']['alter']['make_link'] = 1;
  $handler->display->display_options['fields']['nid']['alter']['path'] = 'node/[nid]';
  $handler->display->display_options['fields']['nid']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['nid']['alter']['external'] = 0;
  $handler->display->display_options['fields']['nid']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['nid']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['nid']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['nid']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['nid']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['nid']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['nid']['alter']['html'] = 0;
  $handler->display->display_options['fields']['nid']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['nid']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['nid']['hide_empty'] = 0;
  $handler->display->display_options['fields']['nid']['empty_zero'] = 0;
  $handler->display->display_options['fields']['nid']['link_to_node'] = 0;
  /* Field: Content: Course */
  $handler->display->display_options['fields']['field_course']['id'] = 'field_course';
  $handler->display->display_options['fields']['field_course']['table'] = 'field_data_field_course';
  $handler->display->display_options['fields']['field_course']['field'] = 'field_course';
  $handler->display->display_options['fields']['field_course']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_course']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_course']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_course']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_course']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_course']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_course']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_course']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_course']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_course']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_course']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_course']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['field_course']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_course']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_course']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_course']['field_api_classes'] = 0;
  /* Field: Content: Site */
  $handler->display->display_options['fields']['field_site']['id'] = 'field_site';
  $handler->display->display_options['fields']['field_site']['table'] = 'field_data_field_site';
  $handler->display->display_options['fields']['field_site']['field'] = 'field_site';
  /* Field: Content: Coordinator */
  $handler->display->display_options['fields']['field_coordinator']['id'] = 'field_coordinator';
  $handler->display->display_options['fields']['field_coordinator']['table'] = 'field_data_field_coordinator';
  $handler->display->display_options['fields']['field_coordinator']['field'] = 'field_coordinator';
  $handler->display->display_options['fields']['field_coordinator']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_coordinator']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_coordinator']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_coordinator']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_coordinator']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_coordinator']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_coordinator']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_coordinator']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_coordinator']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_coordinator']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_coordinator']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_coordinator']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['field_coordinator']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_coordinator']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_coordinator']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_coordinator']['field_api_classes'] = 0;
  /* Field: Content: Post date */
  $handler->display->display_options['fields']['created']['id'] = 'created';
  $handler->display->display_options['fields']['created']['table'] = 'node';
  $handler->display->display_options['fields']['created']['field'] = 'created';
  $handler->display->display_options['fields']['created']['label'] = 'Date';
  $handler->display->display_options['fields']['created']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['created']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['created']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['created']['alter']['external'] = 0;
  $handler->display->display_options['fields']['created']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['created']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['created']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['created']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['created']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['created']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['created']['alter']['html'] = 0;
  $handler->display->display_options['fields']['created']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['created']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['created']['hide_empty'] = 0;
  $handler->display->display_options['fields']['created']['empty_zero'] = 0;
  $handler->display->display_options['fields']['created']['date_format'] = 'long';
  /* Sort criterion: Content: Post date */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'node';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
  /* Contextual filter: Content: User (field_user) */
  $handler->display->display_options['arguments']['field_user_uid']['id'] = 'field_user_uid';
  $handler->display->display_options['arguments']['field_user_uid']['table'] = 'field_data_field_user';
  $handler->display->display_options['arguments']['field_user_uid']['field'] = 'field_user_uid';
  $handler->display->display_options['arguments']['field_user_uid']['default_action'] = 'default';
  $handler->display->display_options['arguments']['field_user_uid']['default_argument_type'] = 'current_user';
  $handler->display->display_options['arguments']['field_user_uid']['default_argument_skip_url'] = 0;
  $handler->display->display_options['arguments']['field_user_uid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['field_user_uid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['field_user_uid']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['field_user_uid']['break_phrase'] = 0;
  $handler->display->display_options['arguments']['field_user_uid']['not'] = 0;
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
    'signup' => 'signup',
  );

  /* Display: Current users sites */
  $handler = $view->new_display('block', 'Current users sites', 'block');

  /* Display: User profile sites */
  $handler = $view->new_display('block', 'User profile sites', 'block_1');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Sites';
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Contextual filter: Content: User (field_user) */
  $handler->display->display_options['arguments']['field_user_uid']['id'] = 'field_user_uid';
  $handler->display->display_options['arguments']['field_user_uid']['table'] = 'field_data_field_user';
  $handler->display->display_options['arguments']['field_user_uid']['field'] = 'field_user_uid';
  $handler->display->display_options['arguments']['field_user_uid']['default_action'] = 'default';
  $handler->display->display_options['arguments']['field_user_uid']['default_argument_type'] = 'user';
  $handler->display->display_options['arguments']['field_user_uid']['default_argument_options']['user'] = FALSE;
  $handler->display->display_options['arguments']['field_user_uid']['default_argument_skip_url'] = 0;
  $handler->display->display_options['arguments']['field_user_uid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['field_user_uid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['field_user_uid']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['field_user_uid']['break_phrase'] = 0;
  $handler->display->display_options['arguments']['field_user_uid']['not'] = 0;
  $handler->display->display_options['block_description'] = 'User profile sites';
  $translatables['user_signups'] = array(
    t('Master'),
    t('Your sites'),
    t('more'),
    t('Apply'),
    t('Reset'),
    t('Sort by'),
    t('Asc'),
    t('Desc'),
    t('Items per page'),
    t('- All -'),
    t('Offset'),
    t('View'),
    t('Record # [nid]'),
    t('node/[nid]'),
    t('Course'),
    t('Site'),
    t('Coordinator'),
    t('Date'),
    t('All'),
    t('Current users sites'),
    t('User profile sites'),
    t('Sites'),
  );
  $export['user_signups'] = $view;

  return $export;
}
