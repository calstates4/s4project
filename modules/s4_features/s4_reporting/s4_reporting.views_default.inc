<?php
/**
 * @file
 * s4_reporting.views_default.inc
 */

/**
 * Implementation of hook_views_default_views().
 */
function s4_reporting_views_default_views() {
  $export = array();

  $view = new view;
  $view->name = 'report_students';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Report: Students';
  $view->core = 7;
  $view->api_version = '3.0-alpha1';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Signups';
  $handler->display->display_options['access']['type'] = 'role';
  $handler->display->display_options['access']['role'] = array(
    5 => '5',
  );
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['query']['options']['query_comment'] = FALSE;
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '50';
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['columns'] = array(
    'nid' => 'nid',
    'field_last_name' => 'field_last_name',
    'field_first_name' => 'field_first_name',
    'title_3' => 'title_3',
    'title' => 'title',
    'title_1' => 'title_1',
    'title_2' => 'title_2',
    'edit_node' => 'edit_node',
    'title_4' => 'title_4',
  );
  $handler->display->display_options['style_options']['default'] = 'field_last_name';
  $handler->display->display_options['style_options']['info'] = array(
    'nid' => array(
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
    'field_first_name' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
    ),
    'title_3' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
    ),
    'title' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
    ),
    'title_1' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
    ),
    'title_2' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
    ),
    'edit_node' => array(
      'align' => '',
      'separator' => '',
    ),
    'title_4' => array(
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
  /* Relationship: Content: Site (field_site) */
  $handler->display->display_options['relationships']['field_site_nid']['id'] = 'field_site_nid';
  $handler->display->display_options['relationships']['field_site_nid']['table'] = 'field_data_field_site';
  $handler->display->display_options['relationships']['field_site_nid']['field'] = 'field_site_nid';
  $handler->display->display_options['relationships']['field_site_nid']['required'] = 0;
  $handler->display->display_options['relationships']['field_site_nid']['delta'] = '-1';
  /* Relationship: Content: User (field_user) */
  $handler->display->display_options['relationships']['field_user_uid']['id'] = 'field_user_uid';
  $handler->display->display_options['relationships']['field_user_uid']['table'] = 'field_data_field_user';
  $handler->display->display_options['relationships']['field_user_uid']['field'] = 'field_user_uid';
  $handler->display->display_options['relationships']['field_user_uid']['required'] = 0;
  $handler->display->display_options['relationships']['field_user_uid']['delta'] = '-1';
  /* Relationship: Content: Term (field_term) */
  $handler->display->display_options['relationships']['field_term_nid']['id'] = 'field_term_nid';
  $handler->display->display_options['relationships']['field_term_nid']['table'] = 'field_data_field_term';
  $handler->display->display_options['relationships']['field_term_nid']['field'] = 'field_term_nid';
  $handler->display->display_options['relationships']['field_term_nid']['relationship'] = 'field_course_nid';
  $handler->display->display_options['relationships']['field_term_nid']['required'] = 0;
  $handler->display->display_options['relationships']['field_term_nid']['delta'] = '-1';
  /* Relationship: Content: Coordinator (field_coordinator) */
  $handler->display->display_options['relationships']['field_coordinator_nid']['id'] = 'field_coordinator_nid';
  $handler->display->display_options['relationships']['field_coordinator_nid']['table'] = 'field_data_field_coordinator';
  $handler->display->display_options['relationships']['field_coordinator_nid']['field'] = 'field_coordinator_nid';
  $handler->display->display_options['relationships']['field_coordinator_nid']['required'] = 0;
  $handler->display->display_options['relationships']['field_coordinator_nid']['delta'] = '-1';
  /* Relationship: Content: Author */
  $handler->display->display_options['relationships']['uid']['id'] = 'uid';
  $handler->display->display_options['relationships']['uid']['table'] = 'node';
  $handler->display->display_options['relationships']['uid']['field'] = 'uid';
  $handler->display->display_options['relationships']['uid']['required'] = 0;
  /* Field: Content: Nid */
  $handler->display->display_options['fields']['nid']['id'] = 'nid';
  $handler->display->display_options['fields']['nid']['table'] = 'node';
  $handler->display->display_options['fields']['nid']['field'] = 'nid';
  $handler->display->display_options['fields']['nid']['label'] = 'ID';
  $handler->display->display_options['fields']['nid']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['nid']['alter']['make_link'] = 0;
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
  /* Field: Field: Last Name */
  $handler->display->display_options['fields']['field_last_name']['id'] = 'field_last_name';
  $handler->display->display_options['fields']['field_last_name']['table'] = 'field_data_field_last_name';
  $handler->display->display_options['fields']['field_last_name']['field'] = 'field_last_name';
  $handler->display->display_options['fields']['field_last_name']['relationship'] = 'uid';
  $handler->display->display_options['fields']['field_last_name']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_last_name']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_last_name']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_last_name']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_last_name']['alter']['replace_spaces'] = 0;
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
  $handler->display->display_options['fields']['field_last_name']['field_api_classes'] = 0;
  /* Field: Field: First Name */
  $handler->display->display_options['fields']['field_first_name']['id'] = 'field_first_name';
  $handler->display->display_options['fields']['field_first_name']['table'] = 'field_data_field_first_name';
  $handler->display->display_options['fields']['field_first_name']['field'] = 'field_first_name';
  $handler->display->display_options['fields']['field_first_name']['relationship'] = 'uid';
  $handler->display->display_options['fields']['field_first_name']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_first_name']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_first_name']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_first_name']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_first_name']['alter']['replace_spaces'] = 0;
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
  $handler->display->display_options['fields']['field_first_name']['field_api_classes'] = 0;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title_3']['id'] = 'title_3';
  $handler->display->display_options['fields']['title_3']['table'] = 'node';
  $handler->display->display_options['fields']['title_3']['field'] = 'title';
  $handler->display->display_options['fields']['title_3']['relationship'] = 'field_term_nid';
  $handler->display->display_options['fields']['title_3']['label'] = 'Term';
  $handler->display->display_options['fields']['title_3']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['title_3']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['title_3']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['title_3']['alter']['external'] = 0;
  $handler->display->display_options['fields']['title_3']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['title_3']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['title_3']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['title_3']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['title_3']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['title_3']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['title_3']['alter']['html'] = 0;
  $handler->display->display_options['fields']['title_3']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['title_3']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['title_3']['hide_empty'] = 0;
  $handler->display->display_options['fields']['title_3']['empty_zero'] = 0;
  $handler->display->display_options['fields']['title_3']['link_to_node'] = 1;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['relationship'] = 'field_course_nid';
  $handler->display->display_options['fields']['title']['label'] = 'Course';
  $handler->display->display_options['fields']['title']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['title']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['title']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['title']['alter']['external'] = 0;
  $handler->display->display_options['fields']['title']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['title']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['title']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['title']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['title']['alter']['html'] = 0;
  $handler->display->display_options['fields']['title']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['title']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['title']['hide_empty'] = 0;
  $handler->display->display_options['fields']['title']['empty_zero'] = 0;
  $handler->display->display_options['fields']['title']['link_to_node'] = 1;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title_1']['id'] = 'title_1';
  $handler->display->display_options['fields']['title_1']['table'] = 'node';
  $handler->display->display_options['fields']['title_1']['field'] = 'title';
  $handler->display->display_options['fields']['title_1']['relationship'] = 'field_site_nid';
  $handler->display->display_options['fields']['title_1']['label'] = 'Site';
  $handler->display->display_options['fields']['title_1']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['title_1']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['title_1']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['title_1']['alter']['external'] = 0;
  $handler->display->display_options['fields']['title_1']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['title_1']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['title_1']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['title_1']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['title_1']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['title_1']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['title_1']['alter']['html'] = 0;
  $handler->display->display_options['fields']['title_1']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['title_1']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['title_1']['hide_empty'] = 0;
  $handler->display->display_options['fields']['title_1']['empty_zero'] = 0;
  $handler->display->display_options['fields']['title_1']['link_to_node'] = 1;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title_2']['id'] = 'title_2';
  $handler->display->display_options['fields']['title_2']['table'] = 'node';
  $handler->display->display_options['fields']['title_2']['field'] = 'title';
  $handler->display->display_options['fields']['title_2']['relationship'] = 'field_coordinator_nid';
  $handler->display->display_options['fields']['title_2']['label'] = 'Coordinator';
  $handler->display->display_options['fields']['title_2']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['title_2']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['title_2']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['title_2']['alter']['external'] = 0;
  $handler->display->display_options['fields']['title_2']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['title_2']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['title_2']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['title_2']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['title_2']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['title_2']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['title_2']['alter']['html'] = 0;
  $handler->display->display_options['fields']['title_2']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['title_2']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['title_2']['hide_empty'] = 0;
  $handler->display->display_options['fields']['title_2']['empty_zero'] = 0;
  $handler->display->display_options['fields']['title_2']['link_to_node'] = 1;
  /* Field: Content: Edit link */
  $handler->display->display_options['fields']['edit_node']['id'] = 'edit_node';
  $handler->display->display_options['fields']['edit_node']['table'] = 'node';
  $handler->display->display_options['fields']['edit_node']['field'] = 'edit_node';
  $handler->display->display_options['fields']['edit_node']['exclude'] = TRUE;
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
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title_4']['id'] = 'title_4';
  $handler->display->display_options['fields']['title_4']['table'] = 'node';
  $handler->display->display_options['fields']['title_4']['field'] = 'title';
  $handler->display->display_options['fields']['title_4']['label'] = 'Actions';
  $handler->display->display_options['fields']['title_4']['exclude'] = TRUE;
  $handler->display->display_options['fields']['title_4']['alter']['alter_text'] = 1;
  $handler->display->display_options['fields']['title_4']['alter']['text'] = 'view';
  $handler->display->display_options['fields']['title_4']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['title_4']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['title_4']['alter']['external'] = 0;
  $handler->display->display_options['fields']['title_4']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['title_4']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['title_4']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['title_4']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['title_4']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['title_4']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['title_4']['alter']['html'] = 0;
  $handler->display->display_options['fields']['title_4']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['title_4']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['title_4']['hide_empty'] = 0;
  $handler->display->display_options['fields']['title_4']['empty_zero'] = 0;
  $handler->display->display_options['fields']['title_4']['link_to_node'] = 1;
  /* Field: Global: Custom text */
  $handler->display->display_options['fields']['nothing']['id'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['table'] = 'views';
  $handler->display->display_options['fields']['nothing']['field'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['label'] = 'Actions';
  $handler->display->display_options['fields']['nothing']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['nothing']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['nothing']['alter']['external'] = 0;
  $handler->display->display_options['fields']['nothing']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['nothing']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['nothing']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['nothing']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['nothing']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['nothing']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['nothing']['alter']['html'] = 0;
  $handler->display->display_options['fields']['nothing']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['nothing']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['nothing']['empty'] = '[edit_node] | [title_4]';
  $handler->display->display_options['fields']['nothing']['hide_empty'] = 0;
  $handler->display->display_options['fields']['nothing']['empty_zero'] = 0;
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
  /* Filter criterion: Content: Title */
  $handler->display->display_options['filters']['title']['id'] = 'title';
  $handler->display->display_options['filters']['title']['table'] = 'node';
  $handler->display->display_options['filters']['title']['field'] = 'title';
  $handler->display->display_options['filters']['title']['relationship'] = 'field_site_nid';
  $handler->display->display_options['filters']['title']['operator'] = 'contains';
  $handler->display->display_options['filters']['title']['exposed'] = TRUE;
  $handler->display->display_options['filters']['title']['expose']['operator_id'] = 'title_op';
  $handler->display->display_options['filters']['title']['expose']['label'] = 'Site name';
  $handler->display->display_options['filters']['title']['expose']['operator'] = 'title_op';
  $handler->display->display_options['filters']['title']['expose']['identifier'] = 'title';
  $handler->display->display_options['filters']['title']['expose']['multiple'] = FALSE;

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page');
  $handler->display->display_options['path'] = 'reports/signup';
  $handler->display->display_options['menu']['type'] = 'tab';
  $handler->display->display_options['menu']['title'] = 'Signups';
  $handler->display->display_options['menu']['weight'] = '0';

  /* Display: Data export : CSV */
  $handler = $view->new_display('views_data_export', 'Data export : CSV', 'views_data_export_1');
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['style_plugin'] = 'views_data_export_csv';
  $handler->display->display_options['path'] = 'reports/signup/export';
  $handler->display->display_options['displays'] = array(
    'page' => 'page',
    'default' => 0,
  );

  /* Display: Data export : XLS */
  $handler = $view->new_display('views_data_export', 'Data export : XLS', 'views_data_export_2');
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['style_plugin'] = 'views_data_export_xls';
  $handler->display->display_options['style_options']['provide_file'] = 0;
  $handler->display->display_options['style_options']['parent_sort'] = 0;
  $handler->display->display_options['path'] = 'reports/signup/export/xls';
  $handler->display->display_options['displays'] = array(
    'page' => 'page',
    'default' => 0,
  );

  /* Display: Data export : DOC */
  $handler = $view->new_display('views_data_export', 'Data export : DOC', 'views_data_export_3');
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['style_plugin'] = 'views_data_export_doc';
  $handler->display->display_options['style_options']['provide_file'] = 0;
  $handler->display->display_options['style_options']['parent_sort'] = 0;
  $handler->display->display_options['path'] = 'reports/signup/export/doc';
  $handler->display->display_options['displays'] = array(
    'page' => 'page',
    'default' => 0,
  );
  $translatables['report_students'] = array(
    t('Master'),
    t('Signups'),
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
    t('field_site'),
    t('field_user'),
    t('field_term'),
    t('field_coordinator'),
    t('author'),
    t('ID'),
    t('Last Name'),
    t('First Name'),
    t('Term'),
    t('Course'),
    t('Site'),
    t('Coordinator'),
    t('Edit link'),
    t('Actions'),
    t('view'),
    t('[edit_node] | [title_4]'),
    t('Site name'),
    t('Page'),
    t('Data export : CSV'),
    t('Data export : XLS'),
    t('Data export : DOC'),
  );
  $export['report_students'] = $view;

  $view = new view;
  $view->name = 'reports_courses';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Reports: Courses';
  $view->core = 7;
  $view->api_version = '3.0-alpha1';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Course report';
  $handler->display->display_options['link_display'] = 'page';
  $handler->display->display_options['access']['type'] = 'role';
  $handler->display->display_options['access']['role'] = array(
    3 => '3',
    5 => '5',
  );
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['query']['options']['query_comment'] = FALSE;
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '50';
  $handler->display->display_options['style_plugin'] = 'table';
  /* Relationship: Content: Term (field_term) */
  $handler->display->display_options['relationships']['field_term_nid']['id'] = 'field_term_nid';
  $handler->display->display_options['relationships']['field_term_nid']['table'] = 'field_data_field_term';
  $handler->display->display_options['relationships']['field_term_nid']['field'] = 'field_term_nid';
  $handler->display->display_options['relationships']['field_term_nid']['required'] = 1;
  $handler->display->display_options['relationships']['field_term_nid']['delta'] = '-1';
  /* Field: Content: Subject */
  $handler->display->display_options['fields']['field_course_subject']['id'] = 'field_course_subject';
  $handler->display->display_options['fields']['field_course_subject']['table'] = 'field_data_field_course_subject';
  $handler->display->display_options['fields']['field_course_subject']['field'] = 'field_course_subject';
  $handler->display->display_options['fields']['field_course_subject']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_course_subject']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_course_subject']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_course_subject']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_course_subject']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_course_subject']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_course_subject']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_course_subject']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_course_subject']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_course_subject']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_course_subject']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_course_subject']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['field_course_subject']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_course_subject']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_course_subject']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_course_subject']['field_api_classes'] = 0;
  /* Field: Content: Catalog number */
  $handler->display->display_options['fields']['field_course_catalog_number']['id'] = 'field_course_catalog_number';
  $handler->display->display_options['fields']['field_course_catalog_number']['table'] = 'field_data_field_course_catalog_number';
  $handler->display->display_options['fields']['field_course_catalog_number']['field'] = 'field_course_catalog_number';
  $handler->display->display_options['fields']['field_course_catalog_number']['label'] = 'Number';
  $handler->display->display_options['fields']['field_course_catalog_number']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_course_catalog_number']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_course_catalog_number']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_course_catalog_number']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_course_catalog_number']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_course_catalog_number']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_course_catalog_number']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_course_catalog_number']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_course_catalog_number']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_course_catalog_number']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_course_catalog_number']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_course_catalog_number']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['field_course_catalog_number']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_course_catalog_number']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_course_catalog_number']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_course_catalog_number']['field_api_classes'] = 0;
  /* Field: Content: Section number */
  $handler->display->display_options['fields']['field_course_section']['id'] = 'field_course_section';
  $handler->display->display_options['fields']['field_course_section']['table'] = 'field_data_field_course_section';
  $handler->display->display_options['fields']['field_course_section']['field'] = 'field_course_section';
  $handler->display->display_options['fields']['field_course_section']['label'] = 'Section';
  $handler->display->display_options['fields']['field_course_section']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_course_section']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_course_section']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_course_section']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_course_section']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_course_section']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_course_section']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_course_section']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_course_section']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_course_section']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_course_section']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_course_section']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['field_course_section']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_course_section']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_course_section']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_course_section']['settings'] = array(
    'thousand_separator' => ' ',
    'prefix_suffix' => 1,
  );
  $handler->display->display_options['fields']['field_course_section']['field_api_classes'] = 0;
  /* Field: Content: Course title */
  $handler->display->display_options['fields']['field_course_title']['id'] = 'field_course_title';
  $handler->display->display_options['fields']['field_course_title']['table'] = 'field_data_field_course_title';
  $handler->display->display_options['fields']['field_course_title']['field'] = 'field_course_title';
  $handler->display->display_options['fields']['field_course_title']['label'] = 'Title';
  $handler->display->display_options['fields']['field_course_title']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_course_title']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_course_title']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_course_title']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_course_title']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_course_title']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_course_title']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_course_title']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_course_title']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_course_title']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_course_title']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_course_title']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['field_course_title']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_course_title']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_course_title']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_course_title']['field_api_classes'] = 0;
  /* Field: Content: Faculty */
  $handler->display->display_options['fields']['field_course_faculty']['id'] = 'field_course_faculty';
  $handler->display->display_options['fields']['field_course_faculty']['table'] = 'field_data_field_course_faculty';
  $handler->display->display_options['fields']['field_course_faculty']['field'] = 'field_course_faculty';
  $handler->display->display_options['fields']['field_course_faculty']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_course_faculty']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_course_faculty']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_course_faculty']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_course_faculty']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_course_faculty']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_course_faculty']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_course_faculty']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_course_faculty']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_course_faculty']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_course_faculty']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_course_faculty']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['field_course_faculty']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_course_faculty']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_course_faculty']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_course_faculty']['group_rows'] = 1;
  $handler->display->display_options['fields']['field_course_faculty']['delta_offset'] = '0';
  $handler->display->display_options['fields']['field_course_faculty']['delta_reversed'] = 0;
  $handler->display->display_options['fields']['field_course_faculty']['multi_type'] = 'ul';
  $handler->display->display_options['fields']['field_course_faculty']['field_api_classes'] = 0;
  /* Field: Content: Students */
  $handler->display->display_options['fields']['field_course_students']['id'] = 'field_course_students';
  $handler->display->display_options['fields']['field_course_students']['table'] = 'field_data_field_course_students';
  $handler->display->display_options['fields']['field_course_students']['field'] = 'field_course_students';
  $handler->display->display_options['fields']['field_course_students']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_course_students']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_course_students']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_course_students']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_course_students']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_course_students']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_course_students']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_course_students']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_course_students']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_course_students']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_course_students']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_course_students']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_course_students']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['field_course_students']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_course_students']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_course_students']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_course_students']['group_rows'] = 1;
  $handler->display->display_options['fields']['field_course_students']['delta_offset'] = '0';
  $handler->display->display_options['fields']['field_course_students']['delta_reversed'] = 0;
  $handler->display->display_options['fields']['field_course_students']['field_api_classes'] = 0;
  /* Field: Course: Total course enrollment */
  $handler->display->display_options['fields']['course_student_enrollment']['id'] = 'course_student_enrollment';
  $handler->display->display_options['fields']['course_student_enrollment']['table'] = 's4_course';
  $handler->display->display_options['fields']['course_student_enrollment']['field'] = 'course_student_enrollment';
  $handler->display->display_options['fields']['course_student_enrollment']['label'] = 'Enrollment';
  $handler->display->display_options['fields']['course_student_enrollment']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['course_student_enrollment']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['course_student_enrollment']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['course_student_enrollment']['alter']['external'] = 0;
  $handler->display->display_options['fields']['course_student_enrollment']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['course_student_enrollment']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['course_student_enrollment']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['course_student_enrollment']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['course_student_enrollment']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['course_student_enrollment']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['course_student_enrollment']['alter']['html'] = 0;
  $handler->display->display_options['fields']['course_student_enrollment']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['course_student_enrollment']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['course_student_enrollment']['hide_empty'] = 0;
  $handler->display->display_options['fields']['course_student_enrollment']['empty_zero'] = 0;
  /* Field: Content: Signups */
  $handler->display->display_options['fields']['field_course_signups']['id'] = 'field_course_signups';
  $handler->display->display_options['fields']['field_course_signups']['table'] = 'field_data_field_course_signups';
  $handler->display->display_options['fields']['field_course_signups']['field'] = 'field_course_signups';
  $handler->display->display_options['fields']['field_course_signups']['label'] = 'Total signed up';
  $handler->display->display_options['fields']['field_course_signups']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_course_signups']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_course_signups']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_course_signups']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_course_signups']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_course_signups']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_course_signups']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_course_signups']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_course_signups']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_course_signups']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_course_signups']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_course_signups']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['field_course_signups']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_course_signups']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_course_signups']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_course_signups']['type'] = 'nodereference_count_default';
  $handler->display->display_options['fields']['field_course_signups']['field_api_classes'] = 0;
  /* Field: Content: Link */
  $handler->display->display_options['fields']['view_node']['id'] = 'view_node';
  $handler->display->display_options['fields']['view_node']['table'] = 'node';
  $handler->display->display_options['fields']['view_node']['field'] = 'view_node';
  $handler->display->display_options['fields']['view_node']['label'] = 'View';
  $handler->display->display_options['fields']['view_node']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['view_node']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['view_node']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['view_node']['alter']['external'] = 0;
  $handler->display->display_options['fields']['view_node']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['view_node']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['view_node']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['view_node']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['view_node']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['view_node']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['view_node']['alter']['html'] = 0;
  $handler->display->display_options['fields']['view_node']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['view_node']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['view_node']['hide_empty'] = 0;
  $handler->display->display_options['fields']['view_node']['empty_zero'] = 0;
  $handler->display->display_options['fields']['view_node']['text'] = 'View';
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
    'course' => 'course',
  );
  /* Filter criterion: Content: Term (field_term) */
  $handler->display->display_options['filters']['field_term_nid']['id'] = 'field_term_nid';
  $handler->display->display_options['filters']['field_term_nid']['table'] = 'field_data_field_term';
  $handler->display->display_options['filters']['field_term_nid']['field'] = 'field_term_nid';
  $handler->display->display_options['filters']['field_term_nid']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_term_nid']['expose']['operator_id'] = 'field_term_nid_op';
  $handler->display->display_options['filters']['field_term_nid']['expose']['label'] = 'Term';
  $handler->display->display_options['filters']['field_term_nid']['expose']['operator'] = 'field_term_nid_op';
  $handler->display->display_options['filters']['field_term_nid']['expose']['identifier'] = 'field_term_nid';
  $handler->display->display_options['filters']['field_term_nid']['expose']['required'] = 1;
  $handler->display->display_options['filters']['field_term_nid']['expose']['remember'] = 1;
  $handler->display->display_options['filters']['field_term_nid']['expose']['reduce'] = 0;
  /* Filter criterion: Content: Subject (field_course_subject) */
  $handler->display->display_options['filters']['field_course_subject_value']['id'] = 'field_course_subject_value';
  $handler->display->display_options['filters']['field_course_subject_value']['table'] = 'field_data_field_course_subject';
  $handler->display->display_options['filters']['field_course_subject_value']['field'] = 'field_course_subject_value';
  $handler->display->display_options['filters']['field_course_subject_value']['operator'] = 'starts';
  $handler->display->display_options['filters']['field_course_subject_value']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_course_subject_value']['expose']['operator_id'] = 'field_course_subject_value_op';
  $handler->display->display_options['filters']['field_course_subject_value']['expose']['label'] = 'Subject';
  $handler->display->display_options['filters']['field_course_subject_value']['expose']['operator'] = 'field_course_subject_value_op';
  $handler->display->display_options['filters']['field_course_subject_value']['expose']['identifier'] = 'field_course_subject_value';
  $handler->display->display_options['filters']['field_course_subject_value']['expose']['remember'] = 1;
  $handler->display->display_options['filters']['field_course_subject_value']['expose']['multiple'] = FALSE;

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page');
  $handler->display->display_options['path'] = 'reports/course';
  $handler->display->display_options['menu']['type'] = 'tab';
  $handler->display->display_options['menu']['title'] = 'Courses';
  $handler->display->display_options['menu']['weight'] = '0';

  /* Display: Data export: CSV */
  $handler = $view->new_display('views_data_export', 'Data export: CSV', 'views_data_export_1');
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['style_plugin'] = 'views_data_export_csv';
  $handler->display->display_options['path'] = 'reports/course/export/csv';
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
  $handler->display->display_options['path'] = 'reports/course/export/xls';
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
  $handler->display->display_options['path'] = 'reports/course/export/doc';
  $handler->display->display_options['displays'] = array(
    'default' => 'default',
    'page' => 'page',
  );
  $translatables['reports_courses'] = array(
    t('Master'),
    t('Course report'),
    t('more'),
    t('Apply'),
    t('Reset'),
    t('Sort by'),
    t('Asc'),
    t('Desc'),
    t('Items per page'),
    t('- All -'),
    t('Offset'),
    t('field_term'),
    t('Subject'),
    t('Number'),
    t('Section'),
    t('Title'),
    t('Faculty'),
    t('Students'),
    t('Enrollment'),
    t('Total signed up'),
    t('View'),
    t('Term'),
    t('Page'),
    t('Data export: CSV'),
    t('Data export: XLS'),
    t('Data export: DOC'),
  );
  $export['reports_courses'] = $view;

  $view = new view;
  $view->name = 'reports_sites';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Reports: sites';
  $view->core = 7;
  $view->api_version = '3.0-alpha1';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Site Report';
  $handler->display->display_options['link_display'] = 'page';
  $handler->display->display_options['access']['type'] = 'role';
  $handler->display->display_options['access']['role'] = array(
    3 => '3',
    4 => '4',
  );
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['query']['options']['query_comment'] = FALSE;
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '30';
  $handler->display->display_options['style_plugin'] = 'views_calc';
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
  /* Field: Content: Website */
  $handler->display->display_options['fields']['field_website']['id'] = 'field_website';
  $handler->display->display_options['fields']['field_website']['table'] = 'field_data_field_website';
  $handler->display->display_options['fields']['field_website']['field'] = 'field_website';
  $handler->display->display_options['fields']['field_website']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_website']['alter']['alter_text'] = 1;
  $handler->display->display_options['fields']['field_website']['alter']['text'] = '<strong>Website:</strong> <a href="[field_website-url]">View website</a>';
  $handler->display->display_options['fields']['field_website']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_website']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_website']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_website']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_website']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_website']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_website']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_website']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_website']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_website']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_website']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['field_website']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_website']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_website']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_website']['click_sort_column'] = 'url';
  $handler->display->display_options['fields']['field_website']['field_api_classes'] = 0;
  /* Field: Content: Contact email */
  $handler->display->display_options['fields']['field_site_email']['id'] = 'field_site_email';
  $handler->display->display_options['fields']['field_site_email']['table'] = 'field_data_field_site_email';
  $handler->display->display_options['fields']['field_site_email']['field'] = 'field_site_email';
  $handler->display->display_options['fields']['field_site_email']['label'] = 'Email';
  $handler->display->display_options['fields']['field_site_email']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_site_email']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_site_email']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_site_email']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_site_email']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_site_email']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_site_email']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_site_email']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_site_email']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_site_email']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_site_email']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_site_email']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_site_email']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['field_site_email']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_site_email']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_site_email']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_site_email']['type'] = 'email_default';
  $handler->display->display_options['fields']['field_site_email']['field_api_classes'] = 0;
  /* Field: Content: Phone number */
  $handler->display->display_options['fields']['field_phone']['id'] = 'field_phone';
  $handler->display->display_options['fields']['field_phone']['table'] = 'field_data_field_phone';
  $handler->display->display_options['fields']['field_phone']['field'] = 'field_phone';
  $handler->display->display_options['fields']['field_phone']['label'] = 'Contact';
  $handler->display->display_options['fields']['field_phone']['alter']['alter_text'] = 1;
  $handler->display->display_options['fields']['field_phone']['alter']['text'] = '<strong>Phone:</strong> [field_phone]<br/>
<strong>Email:</strong> [field_site_email]<br/>
[field_website]';
  $handler->display->display_options['fields']['field_phone']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_phone']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_phone']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_phone']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_phone']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_phone']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_phone']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_phone']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_phone']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_phone']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_phone']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['field_phone']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_phone']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_phone']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_phone']['click_sort_column'] = 'number';
  $handler->display->display_options['fields']['field_phone']['field_api_classes'] = 0;
  /* Field: Location: City */
  $handler->display->display_options['fields']['city']['id'] = 'city';
  $handler->display->display_options['fields']['city']['table'] = 'location';
  $handler->display->display_options['fields']['city']['field'] = 'city';
  $handler->display->display_options['fields']['city']['exclude'] = TRUE;
  $handler->display->display_options['fields']['city']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['city']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['city']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['city']['alter']['external'] = 0;
  $handler->display->display_options['fields']['city']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['city']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['city']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['city']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['city']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['city']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['city']['alter']['html'] = 0;
  $handler->display->display_options['fields']['city']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['city']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['city']['hide_empty'] = 0;
  $handler->display->display_options['fields']['city']['empty_zero'] = 0;
  /* Field: Location: Postal Code */
  $handler->display->display_options['fields']['postal_code']['id'] = 'postal_code';
  $handler->display->display_options['fields']['postal_code']['table'] = 'location';
  $handler->display->display_options['fields']['postal_code']['field'] = 'postal_code';
  $handler->display->display_options['fields']['postal_code']['exclude'] = TRUE;
  $handler->display->display_options['fields']['postal_code']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['postal_code']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['postal_code']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['postal_code']['alter']['external'] = 0;
  $handler->display->display_options['fields']['postal_code']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['postal_code']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['postal_code']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['postal_code']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['postal_code']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['postal_code']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['postal_code']['alter']['html'] = 0;
  $handler->display->display_options['fields']['postal_code']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['postal_code']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['postal_code']['hide_empty'] = 0;
  $handler->display->display_options['fields']['postal_code']['empty_zero'] = 0;
  /* Field: Location: Province */
  $handler->display->display_options['fields']['province']['id'] = 'province';
  $handler->display->display_options['fields']['province']['table'] = 'location';
  $handler->display->display_options['fields']['province']['field'] = 'province';
  $handler->display->display_options['fields']['province']['exclude'] = TRUE;
  $handler->display->display_options['fields']['province']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['province']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['province']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['province']['alter']['external'] = 0;
  $handler->display->display_options['fields']['province']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['province']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['province']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['province']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['province']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['province']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['province']['alter']['html'] = 0;
  $handler->display->display_options['fields']['province']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['province']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['province']['hide_empty'] = 0;
  $handler->display->display_options['fields']['province']['empty_zero'] = 0;
  /* Field: Location: Street */
  $handler->display->display_options['fields']['street']['id'] = 'street';
  $handler->display->display_options['fields']['street']['table'] = 'location';
  $handler->display->display_options['fields']['street']['field'] = 'street';
  $handler->display->display_options['fields']['street']['label'] = 'Address';
  $handler->display->display_options['fields']['street']['alter']['alter_text'] = 1;
  $handler->display->display_options['fields']['street']['alter']['text'] = '[street]<br/>
[city], [province]&nbsp;&nbsp; [postal_code]';
  $handler->display->display_options['fields']['street']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['street']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['street']['alter']['external'] = 0;
  $handler->display->display_options['fields']['street']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['street']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['street']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['street']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['street']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['street']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['street']['alter']['html'] = 0;
  $handler->display->display_options['fields']['street']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['street']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['street']['empty'] = '&nbsp;';
  $handler->display->display_options['fields']['street']['hide_empty'] = 0;
  $handler->display->display_options['fields']['street']['empty_zero'] = 0;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title_1']['id'] = 'title_1';
  $handler->display->display_options['fields']['title_1']['table'] = 'node';
  $handler->display->display_options['fields']['title_1']['field'] = 'title';
  $handler->display->display_options['fields']['title_1']['relationship'] = 'field_site_nid';
  $handler->display->display_options['fields']['title_1']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['title_1']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['title_1']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['title_1']['alter']['external'] = 0;
  $handler->display->display_options['fields']['title_1']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['title_1']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['title_1']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['title_1']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['title_1']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['title_1']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['title_1']['alter']['html'] = 0;
  $handler->display->display_options['fields']['title_1']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['title_1']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['title_1']['hide_empty'] = 0;
  $handler->display->display_options['fields']['title_1']['empty_zero'] = 0;
  $handler->display->display_options['fields']['title_1']['link_to_node'] = 1;
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
  $handler->display->display_options['filters']['status']['group'] = 0;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'site' => 'site',
  );
  /* Filter criterion: Location: City */
  $handler->display->display_options['filters']['city']['id'] = 'city';
  $handler->display->display_options['filters']['city']['table'] = 'location';
  $handler->display->display_options['filters']['city']['field'] = 'city';
  $handler->display->display_options['filters']['city']['operator'] = 'contains';
  $handler->display->display_options['filters']['city']['exposed'] = TRUE;
  $handler->display->display_options['filters']['city']['expose']['operator_id'] = 'city_op';
  $handler->display->display_options['filters']['city']['expose']['label'] = 'City';
  $handler->display->display_options['filters']['city']['expose']['operator'] = 'city_op';
  $handler->display->display_options['filters']['city']['expose']['identifier'] = 'city';
  $handler->display->display_options['filters']['city']['expose']['multiple'] = FALSE;

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page');
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
    t('Apply'),
    t('Reset'),
    t('Sort by'),
    t('Asc'),
    t('Desc'),
    t('Items per page'),
    t('- All -'),
    t('Offset'),
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
    t('Title'),
    t('Page'),
    t('Data export: CSV'),
    t('Data export: XLS'),
    t('Data export: DOC'),
  );
  $export['reports_sites'] = $view;

  return $export;
}
