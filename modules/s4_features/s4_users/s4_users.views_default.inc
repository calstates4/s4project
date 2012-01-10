<?php
/**
 * @file
 * s4_users.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function s4_users_views_default_views() {
  $export = array();

  $view = new view;
  $view->name = 's4_user_signups';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'S4: User Signups';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Sites';
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['query']['options']['query_comment'] = FALSE;
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '20';
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['grouping'] = 'field_term';
  $handler->display->display_options['style_options']['columns'] = array(
    'field_term' => 'field_term',
    'field_course_1' => 'field_course_1',
    'created' => 'created',
    'field_site' => 'field_site',
    'field_coordinator' => 'field_coordinator',
  );
  $handler->display->display_options['style_options']['default'] = '-1';
  $handler->display->display_options['style_options']['info'] = array(
    'field_term' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
    ),
    'field_course_1' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
    ),
    'created' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
    ),
    'field_site' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
    ),
    'field_coordinator' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
    ),
  );
  $handler->display->display_options['style_options']['override'] = 1;
  $handler->display->display_options['style_options']['sticky'] = 0;
  $handler->display->display_options['style_options']['empty_table'] = 0;
  /* Relationship: Content: Course (field_course) */
  $handler->display->display_options['relationships']['field_course_nid']['id'] = 'field_course_nid';
  $handler->display->display_options['relationships']['field_course_nid']['table'] = 'field_data_field_course';
  $handler->display->display_options['relationships']['field_course_nid']['field'] = 'field_course_nid';
  $handler->display->display_options['relationships']['field_course_nid']['required'] = 0;
  $handler->display->display_options['relationships']['field_course_nid']['delta'] = '-1';
  /* Field: Content: Term */
  $handler->display->display_options['fields']['field_term']['id'] = 'field_term';
  $handler->display->display_options['fields']['field_term']['table'] = 'field_data_field_term';
  $handler->display->display_options['fields']['field_term']['field'] = 'field_term';
  $handler->display->display_options['fields']['field_term']['relationship'] = 'field_course_nid';
  $handler->display->display_options['fields']['field_term']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_term']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_term']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_term']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_term']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_term']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_term']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_term']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_term']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_term']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_term']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_term']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_term']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_term']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['field_term']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_term']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_term']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_term']['hide_alter_empty'] = 0;
  $handler->display->display_options['fields']['field_term']['field_api_classes'] = 0;
  /* Field: Content: Course */
  $handler->display->display_options['fields']['field_course_1']['id'] = 'field_course_1';
  $handler->display->display_options['fields']['field_course_1']['table'] = 'field_data_field_course';
  $handler->display->display_options['fields']['field_course_1']['field'] = 'field_course';
  $handler->display->display_options['fields']['field_course_1']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_course_1']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_course_1']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_course_1']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_course_1']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_course_1']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_course_1']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_course_1']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_course_1']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_course_1']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_course_1']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_course_1']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_course_1']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['field_course_1']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_course_1']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_course_1']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_course_1']['hide_alter_empty'] = 0;
  $handler->display->display_options['fields']['field_course_1']['field_api_classes'] = 0;
  /* Field: Content: Post date */
  $handler->display->display_options['fields']['created']['id'] = 'created';
  $handler->display->display_options['fields']['created']['table'] = 'node';
  $handler->display->display_options['fields']['created']['field'] = 'created';
  $handler->display->display_options['fields']['created']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['created']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['created']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['created']['alter']['external'] = 0;
  $handler->display->display_options['fields']['created']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['created']['alter']['trim_whitespace'] = 0;
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
  $handler->display->display_options['fields']['created']['hide_alter_empty'] = 0;
  $handler->display->display_options['fields']['created']['date_format'] = 'long';
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
  /* Field: Content: Site staff */
  $handler->display->display_options['fields']['field_coordinator']['id'] = 'field_coordinator';
  $handler->display->display_options['fields']['field_coordinator']['table'] = 'field_data_field_coordinator';
  $handler->display->display_options['fields']['field_coordinator']['field'] = 'field_coordinator';
  $handler->display->display_options['fields']['field_coordinator']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_coordinator']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_coordinator']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_coordinator']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_coordinator']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_coordinator']['alter']['trim_whitespace'] = 0;
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
  $handler->display->display_options['fields']['field_coordinator']['hide_alter_empty'] = 0;
  $handler->display->display_options['fields']['field_coordinator']['field_api_classes'] = 0;
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
  $handler->display->display_options['arguments']['field_user_uid']['default_argument_type'] = 'user';
  $handler->display->display_options['arguments']['field_user_uid']['default_argument_options']['user'] = FALSE;
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

  /* Display: Block */
  $handler = $view->new_display('block', 'Block', 'block');
  $handler->display->display_options['block_description'] = 'User page signups';
  $translatables['s4_user_signups'] = array(
    t('Master'),
    t('Sites'),
    t('more'),
    t('Apply'),
    t('Reset'),
    t('Sort by'),
    t('Asc'),
    t('Desc'),
    t('Items per page'),
    t('- All -'),
    t('Offset'),
    t('field_course'),
    t('Term'),
    t('Course'),
    t('Post date'),
    t('Site'),
    t('Site staff'),
    t('All'),
    t('Block'),
    t('User page signups'),
  );
  $export['s4_user_signups'] = $view;

  return $export;
}
