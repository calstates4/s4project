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
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Students';
  $handler->display->display_options['css_class'] = 'report-view';
  $handler->display->display_options['access']['type'] = 'role';
  $handler->display->display_options['access']['role'] = array(
    3 => '3',
    4 => '4',
  );
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['query']['options']['query_comment'] = FALSE;
  $handler->display->display_options['exposed_form']['type'] = 's4_reporting';
  $handler->display->display_options['exposed_form']['options']['submit_button'] = 'Search';
  $handler->display->display_options['exposed_form']['options']['reset_button'] = TRUE;
  $handler->display->display_options['exposed_form']['options']['autosubmit'] = 0;
  $handler->display->display_options['exposed_form']['options']['autosubmit_hide'] = 1;
  $handler->display->display_options['exposed_form']['options']['s4_reporting'] = array(
    'group-dyfield' => '2',
    'group-field_site_nid' => '1',
    'group-field_term_nid' => '0',
    'group-field_course_subject_value' => '0',
    'group-field_course_catalog_number_value' => '0',
    'group-field_course_section_value' => '0',
    'groups' => 'Course
Specific Site(s)
Fields',
  );
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
  $handler->display->display_options['fields']['nid']['alter']['trim_whitespace'] = 0;
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
  $handler->display->display_options['fields']['nid']['hide_alter_empty'] = 0;
  $handler->display->display_options['fields']['nid']['link_to_node'] = 1;
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
  /* Field: Content: Evaluation Form Results */
  $handler->display->display_options['fields']['field_form_evaluation_sid']['id'] = 'field_form_evaluation_sid';
  $handler->display->display_options['fields']['field_form_evaluation_sid']['table'] = 'field_data_field_form_evaluation_sid';
  $handler->display->display_options['fields']['field_form_evaluation_sid']['field'] = 'field_form_evaluation_sid';
  $handler->display->display_options['fields']['field_form_evaluation_sid']['label'] = 'Evaluation Form';
  $handler->display->display_options['fields']['field_form_evaluation_sid']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_form_evaluation_sid']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_form_evaluation_sid']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_form_evaluation_sid']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_form_evaluation_sid']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_form_evaluation_sid']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_form_evaluation_sid']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_form_evaluation_sid']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_form_evaluation_sid']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_form_evaluation_sid']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_form_evaluation_sid']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_form_evaluation_sid']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_form_evaluation_sid']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['field_form_evaluation_sid']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_form_evaluation_sid']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_form_evaluation_sid']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_form_evaluation_sid']['hide_alter_empty'] = 0;
  $handler->display->display_options['fields']['field_form_evaluation_sid']['settings'] = array(
    'thousand_separator' => ' ',
    'prefix_suffix' => 1,
  );
  $handler->display->display_options['fields']['field_form_evaluation_sid']['field_api_classes'] = 0;
  /* Field: Content: Signup Form Results */
  $handler->display->display_options['fields']['field_form_signup_sid']['id'] = 'field_form_signup_sid';
  $handler->display->display_options['fields']['field_form_signup_sid']['table'] = 'field_data_field_form_signup_sid';
  $handler->display->display_options['fields']['field_form_signup_sid']['field'] = 'field_form_signup_sid';
  $handler->display->display_options['fields']['field_form_signup_sid']['label'] = 'Signup Form';
  $handler->display->display_options['fields']['field_form_signup_sid']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_form_signup_sid']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_form_signup_sid']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_form_signup_sid']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_form_signup_sid']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_form_signup_sid']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_form_signup_sid']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_form_signup_sid']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_form_signup_sid']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_form_signup_sid']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_form_signup_sid']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_form_signup_sid']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_form_signup_sid']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['field_form_signup_sid']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_form_signup_sid']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_form_signup_sid']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_form_signup_sid']['hide_alter_empty'] = 0;
  $handler->display->display_options['fields']['field_form_signup_sid']['settings'] = array(
    'thousand_separator' => ' ',
    'prefix_suffix' => 1,
  );
  $handler->display->display_options['fields']['field_form_signup_sid']['field_api_classes'] = 0;
  /* Field: Content: Evaluation Form */
  $handler->display->display_options['fields']['field_site_eval_form']['id'] = 'field_site_eval_form';
  $handler->display->display_options['fields']['field_site_eval_form']['table'] = 'field_data_field_site_eval_form';
  $handler->display->display_options['fields']['field_site_eval_form']['field'] = 'field_site_eval_form';
  $handler->display->display_options['fields']['field_site_eval_form']['relationship'] = 'field_site_nid';
  $handler->display->display_options['fields']['field_site_eval_form']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_site_eval_form']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_site_eval_form']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_site_eval_form']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_site_eval_form']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_site_eval_form']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_site_eval_form']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_site_eval_form']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_site_eval_form']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_site_eval_form']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_site_eval_form']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_site_eval_form']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_site_eval_form']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_site_eval_form']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['field_site_eval_form']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_site_eval_form']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_site_eval_form']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_site_eval_form']['hide_alter_empty'] = 0;
  $handler->display->display_options['fields']['field_site_eval_form']['field_api_classes'] = 0;
  /* Field: Content: Signup form */
  $handler->display->display_options['fields']['field_site_form']['id'] = 'field_site_form';
  $handler->display->display_options['fields']['field_site_form']['table'] = 'field_data_field_site_form';
  $handler->display->display_options['fields']['field_site_form']['field'] = 'field_site_form';
  $handler->display->display_options['fields']['field_site_form']['relationship'] = 'field_site_nid';
  $handler->display->display_options['fields']['field_site_form']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_site_form']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_site_form']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_site_form']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_site_form']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_site_form']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_site_form']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_site_form']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_site_form']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_site_form']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_site_form']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_site_form']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_site_form']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_site_form']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['field_site_form']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_site_form']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_site_form']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_site_form']['hide_alter_empty'] = 0;
  $handler->display->display_options['fields']['field_site_form']['field_api_classes'] = 0;
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
  $handler->display->display_options['filters']['type']['group'] = 0;
  /* Filter criterion: Content: Dynamic Fields */
  $handler->display->display_options['filters']['dyfield']['id'] = 'dyfield';
  $handler->display->display_options['filters']['dyfield']['table'] = 'node';
  $handler->display->display_options['filters']['dyfield']['field'] = 'dyfield';
  $handler->display->display_options['filters']['dyfield']['group'] = 0;
  $handler->display->display_options['filters']['dyfield']['exposed'] = TRUE;
  $handler->display->display_options['filters']['dyfield']['expose']['operator_id'] = '';
  $handler->display->display_options['filters']['dyfield']['expose']['label'] = 'Select fields';
  $handler->display->display_options['filters']['dyfield']['expose']['use_operator'] = FALSE;
  $handler->display->display_options['filters']['dyfield']['expose']['operator'] = 'dyfield_op';
  $handler->display->display_options['filters']['dyfield']['expose']['identifier'] = 'dyfield';
  $handler->display->display_options['filters']['dyfield']['filterable_fields'] = array(
    'nid' => 'nid',
    'field_last_name' => 'field_last_name',
    'field_first_name' => 'field_first_name',
    'title_3' => 'title_3',
    'title' => 'title',
    'title_1' => 'title_1',
    'title_2' => 'title_2',
    'nothing' => 'nothing',
    'field_form_evaluation_sid' => 'field_form_evaluation_sid',
    'field_form_signup_sid' => 'field_form_signup_sid',
  );
  $handler->display->display_options['filters']['dyfield']['defaults_filterable_fields'] = array(
    'nid' => 'nid',
    'field_last_name' => 'field_last_name',
    'field_first_name' => 'field_first_name',
    'title_3' => 'title_3',
    'title' => 'title',
    'title_1' => 'title_1',
    'title_2' => 0,
    'nothing' => 0,
    'field_form_evaluation_sid' => 0,
    'field_form_signup_sid' => 0,
  );
  $handler->display->display_options['filters']['dyfield']['sortability'] = 1;
  $handler->display->display_options['filters']['dyfield']['checkboxes'] = 1;
  /* Filter criterion: Content: Site (field_site) */
  $handler->display->display_options['filters']['field_site_nid']['id'] = 'field_site_nid';
  $handler->display->display_options['filters']['field_site_nid']['table'] = 'field_data_field_site';
  $handler->display->display_options['filters']['field_site_nid']['field'] = 'field_site_nid';
  $handler->display->display_options['filters']['field_site_nid']['group'] = 0;
  $handler->display->display_options['filters']['field_site_nid']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_site_nid']['expose']['operator_id'] = 'field_site_nid_op';
  $handler->display->display_options['filters']['field_site_nid']['expose']['label'] = 'Site(s)';
  $handler->display->display_options['filters']['field_site_nid']['expose']['operator'] = 'field_site_nid_op';
  $handler->display->display_options['filters']['field_site_nid']['expose']['identifier'] = 'field_site_nid';
  $handler->display->display_options['filters']['field_site_nid']['expose']['multiple'] = 1;
  $handler->display->display_options['filters']['field_site_nid']['expose']['reduce'] = 0;
  /* Filter criterion: Content: Term (field_term) */
  $handler->display->display_options['filters']['field_term_nid']['id'] = 'field_term_nid';
  $handler->display->display_options['filters']['field_term_nid']['table'] = 'field_data_field_term';
  $handler->display->display_options['filters']['field_term_nid']['field'] = 'field_term_nid';
  $handler->display->display_options['filters']['field_term_nid']['relationship'] = 'field_course_nid';
  $handler->display->display_options['filters']['field_term_nid']['group'] = 0;
  $handler->display->display_options['filters']['field_term_nid']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_term_nid']['expose']['operator_id'] = 'field_term_nid_op';
  $handler->display->display_options['filters']['field_term_nid']['expose']['label'] = 'Term';
  $handler->display->display_options['filters']['field_term_nid']['expose']['operator'] = 'field_term_nid_op';
  $handler->display->display_options['filters']['field_term_nid']['expose']['identifier'] = 'field_term_nid';
  $handler->display->display_options['filters']['field_term_nid']['expose']['multiple'] = 1;
  $handler->display->display_options['filters']['field_term_nid']['expose']['reduce'] = 0;
  /* Filter criterion: Content: Subject (field_course_subject) */
  $handler->display->display_options['filters']['field_course_subject_value']['id'] = 'field_course_subject_value';
  $handler->display->display_options['filters']['field_course_subject_value']['table'] = 'field_data_field_course_subject';
  $handler->display->display_options['filters']['field_course_subject_value']['field'] = 'field_course_subject_value';
  $handler->display->display_options['filters']['field_course_subject_value']['relationship'] = 'field_course_nid';
  $handler->display->display_options['filters']['field_course_subject_value']['group'] = 0;
  $handler->display->display_options['filters']['field_course_subject_value']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_course_subject_value']['expose']['operator_id'] = 'field_course_subject_value_op';
  $handler->display->display_options['filters']['field_course_subject_value']['expose']['label'] = 'Course Prefix';
  $handler->display->display_options['filters']['field_course_subject_value']['expose']['operator'] = 'field_course_subject_value_op';
  $handler->display->display_options['filters']['field_course_subject_value']['expose']['identifier'] = 'field_course_subject_value';
  $handler->display->display_options['filters']['field_course_subject_value']['expose']['required'] = 0;
  $handler->display->display_options['filters']['field_course_subject_value']['expose']['remember'] = 1;
  $handler->display->display_options['filters']['field_course_subject_value']['expose']['multiple'] = FALSE;
  /* Filter criterion: Content: Catalog number (field_course_catalog_number) */
  $handler->display->display_options['filters']['field_course_catalog_number_value']['id'] = 'field_course_catalog_number_value';
  $handler->display->display_options['filters']['field_course_catalog_number_value']['table'] = 'field_data_field_course_catalog_number';
  $handler->display->display_options['filters']['field_course_catalog_number_value']['field'] = 'field_course_catalog_number_value';
  $handler->display->display_options['filters']['field_course_catalog_number_value']['relationship'] = 'field_course_nid';
  $handler->display->display_options['filters']['field_course_catalog_number_value']['group'] = 0;
  $handler->display->display_options['filters']['field_course_catalog_number_value']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_course_catalog_number_value']['expose']['operator_id'] = 'field_course_catalog_number_value_op';
  $handler->display->display_options['filters']['field_course_catalog_number_value']['expose']['label'] = 'Course number';
  $handler->display->display_options['filters']['field_course_catalog_number_value']['expose']['operator'] = 'field_course_catalog_number_value_op';
  $handler->display->display_options['filters']['field_course_catalog_number_value']['expose']['identifier'] = 'field_course_catalog_number_value';
  $handler->display->display_options['filters']['field_course_catalog_number_value']['expose']['required'] = 0;
  $handler->display->display_options['filters']['field_course_catalog_number_value']['expose']['remember'] = 1;
  $handler->display->display_options['filters']['field_course_catalog_number_value']['expose']['multiple'] = FALSE;
  /* Filter criterion: Content: Section number (field_course_section) */
  $handler->display->display_options['filters']['field_course_section_value']['id'] = 'field_course_section_value';
  $handler->display->display_options['filters']['field_course_section_value']['table'] = 'field_data_field_course_section';
  $handler->display->display_options['filters']['field_course_section_value']['field'] = 'field_course_section_value';
  $handler->display->display_options['filters']['field_course_section_value']['relationship'] = 'field_course_nid';
  $handler->display->display_options['filters']['field_course_section_value']['group'] = 0;
  $handler->display->display_options['filters']['field_course_section_value']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_course_section_value']['expose']['operator_id'] = 'field_course_section_value_op';
  $handler->display->display_options['filters']['field_course_section_value']['expose']['label'] = 'Section';
  $handler->display->display_options['filters']['field_course_section_value']['expose']['operator'] = 'field_course_section_value_op';
  $handler->display->display_options['filters']['field_course_section_value']['expose']['identifier'] = 'field_course_section_value';
  $handler->display->display_options['filters']['field_course_section_value']['expose']['multiple'] = FALSE;

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page');
  $handler->display->display_options['path'] = 'reports/students';
  $handler->display->display_options['menu']['type'] = 'tab';
  $handler->display->display_options['menu']['title'] = 'Students';
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
    t('Students'),
    t('more'),
    t('Search'),
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
    t('Evaluation Form'),
    t('Signup Form'),
    t('Signup form'),
    t('Select fields'),
    t('Site(s)'),
    t('Course Prefix'),
    t('Course number'),
    t('Section'),
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
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Course report';
  $handler->display->display_options['css_class'] = 'report-view';
  $handler->display->display_options['link_display'] = 'page';
  $handler->display->display_options['access']['type'] = 'role';
  $handler->display->display_options['access']['role'] = array(
    3 => '3',
    4 => '4',
  );
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['query']['options']['query_comment'] = FALSE;
  $handler->display->display_options['exposed_form']['type'] = 's4_reporting';
  $handler->display->display_options['exposed_form']['options']['submit_button'] = 'Search';
  $handler->display->display_options['exposed_form']['options']['reset_button'] = TRUE;
  $handler->display->display_options['exposed_form']['options']['autosubmit'] = 0;
  $handler->display->display_options['exposed_form']['options']['autosubmit_hide'] = 1;
  $handler->display->display_options['exposed_form']['options']['s4_reporting'] = array(
    'group-field_course_subject_value' => '0',
    'group-field_term_nid' => '0',
    'group-dyfield' => '3',
    'group-field_course_catalog_number_value' => '0',
    'group-field_csu_facility_tid' => '1',
    'group-field_csu_org_type_tid' => '1',
    'group-city' => '2',
    'group-distance' => '2',
    'groups' => 'Course
Site information
Site location
Fields',
  );
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '40';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['pager']['options']['id'] = '0';
  $handler->display->display_options['pager']['options']['expose']['items_per_page_options_all'] = 0;
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['columns'] = array(
    'field_course_subject' => 'field_course_subject',
    'field_course_catalog_number' => 'field_course_catalog_number',
    'field_course_section' => 'field_course_section',
    'field_course_title' => 'field_course_title',
    'field_course_students' => 'field_course_students',
    'course_student_enrollment' => 'course_student_enrollment',
    'field_course_signups' => 'field_course_signups',
    'view_node' => 'view_node',
  );
  $handler->display->display_options['style_options']['default'] = '-1';
  $handler->display->display_options['style_options']['info'] = array(
    'field_course_subject' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
    ),
    'field_course_catalog_number' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
    ),
    'field_course_section' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
    ),
    'field_course_title' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
    ),
    'field_course_students' => array(
      'align' => '',
      'separator' => '',
    ),
    'course_student_enrollment' => array(
      'align' => '',
      'separator' => '',
    ),
    'field_course_signups' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
    ),
    'view_node' => array(
      'align' => '',
      'separator' => '',
    ),
  );
  $handler->display->display_options['style_options']['override'] = 1;
  $handler->display->display_options['style_options']['sticky'] = 0;
  $handler->display->display_options['style_options']['empty_table'] = 0;
  /* Relationship: Content: Term (field_term) */
  $handler->display->display_options['relationships']['field_term_nid']['id'] = 'field_term_nid';
  $handler->display->display_options['relationships']['field_term_nid']['table'] = 'field_data_field_term';
  $handler->display->display_options['relationships']['field_term_nid']['field'] = 'field_term_nid';
  $handler->display->display_options['relationships']['field_term_nid']['required'] = 1;
  $handler->display->display_options['relationships']['field_term_nid']['delta'] = '-1';
  /* Relationship: Content: Students (field_course_students) */
  $handler->display->display_options['relationships']['field_course_students_uid']['id'] = 'field_course_students_uid';
  $handler->display->display_options['relationships']['field_course_students_uid']['table'] = 'field_data_field_course_students';
  $handler->display->display_options['relationships']['field_course_students_uid']['field'] = 'field_course_students_uid';
  $handler->display->display_options['relationships']['field_course_students_uid']['required'] = 0;
  $handler->display->display_options['relationships']['field_course_students_uid']['delta'] = '-1';
  /* Relationship: Content: Course (field_course) - reverse */
  $handler->display->display_options['relationships']['reverse_field_course_node']['id'] = 'reverse_field_course_node';
  $handler->display->display_options['relationships']['reverse_field_course_node']['table'] = 'node';
  $handler->display->display_options['relationships']['reverse_field_course_node']['field'] = 'reverse_field_course_node';
  $handler->display->display_options['relationships']['reverse_field_course_node']['required'] = 0;
  /* Relationship: Content: Site (field_site) */
  $handler->display->display_options['relationships']['field_site_nid']['id'] = 'field_site_nid';
  $handler->display->display_options['relationships']['field_site_nid']['table'] = 'field_data_field_site';
  $handler->display->display_options['relationships']['field_site_nid']['field'] = 'field_site_nid';
  $handler->display->display_options['relationships']['field_site_nid']['relationship'] = 'reverse_field_course_node';
  $handler->display->display_options['relationships']['field_site_nid']['required'] = 0;
  $handler->display->display_options['relationships']['field_site_nid']['delta'] = '-1';
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
  /* Field: Content: Site */
  $handler->display->display_options['fields']['field_site']['id'] = 'field_site';
  $handler->display->display_options['fields']['field_site']['table'] = 'field_data_field_site';
  $handler->display->display_options['fields']['field_site']['field'] = 'field_site';
  $handler->display->display_options['fields']['field_site']['relationship'] = 'reverse_field_course_node';
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
  /* Field: Content: Federal district */
  $handler->display->display_options['fields']['field_district_federal']['id'] = 'field_district_federal';
  $handler->display->display_options['fields']['field_district_federal']['table'] = 'field_data_field_district_federal';
  $handler->display->display_options['fields']['field_district_federal']['field'] = 'field_district_federal';
  $handler->display->display_options['fields']['field_district_federal']['relationship'] = 'field_site_nid';
  $handler->display->display_options['fields']['field_district_federal']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_district_federal']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_district_federal']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_district_federal']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_district_federal']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_district_federal']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_district_federal']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_district_federal']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_district_federal']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_district_federal']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_district_federal']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_district_federal']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_district_federal']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['field_district_federal']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_district_federal']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_district_federal']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_district_federal']['hide_alter_empty'] = 0;
  $handler->display->display_options['fields']['field_district_federal']['field_api_classes'] = 0;
  /* Field: Content: State lower district */
  $handler->display->display_options['fields']['field_district_state_lower']['id'] = 'field_district_state_lower';
  $handler->display->display_options['fields']['field_district_state_lower']['table'] = 'field_data_field_district_state_lower';
  $handler->display->display_options['fields']['field_district_state_lower']['field'] = 'field_district_state_lower';
  $handler->display->display_options['fields']['field_district_state_lower']['relationship'] = 'field_site_nid';
  $handler->display->display_options['fields']['field_district_state_lower']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_district_state_lower']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_district_state_lower']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_district_state_lower']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_district_state_lower']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_district_state_lower']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_district_state_lower']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_district_state_lower']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_district_state_lower']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_district_state_lower']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_district_state_lower']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_district_state_lower']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_district_state_lower']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['field_district_state_lower']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_district_state_lower']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_district_state_lower']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_district_state_lower']['hide_alter_empty'] = 0;
  $handler->display->display_options['fields']['field_district_state_lower']['field_api_classes'] = 0;
  /* Field: Content: State upper district */
  $handler->display->display_options['fields']['field_district_state_upper']['id'] = 'field_district_state_upper';
  $handler->display->display_options['fields']['field_district_state_upper']['table'] = 'field_data_field_district_state_upper';
  $handler->display->display_options['fields']['field_district_state_upper']['field'] = 'field_district_state_upper';
  $handler->display->display_options['fields']['field_district_state_upper']['relationship'] = 'field_site_nid';
  $handler->display->display_options['fields']['field_district_state_upper']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_district_state_upper']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_district_state_upper']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_district_state_upper']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_district_state_upper']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_district_state_upper']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_district_state_upper']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_district_state_upper']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_district_state_upper']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_district_state_upper']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_district_state_upper']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_district_state_upper']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_district_state_upper']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['field_district_state_upper']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_district_state_upper']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_district_state_upper']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_district_state_upper']['hide_alter_empty'] = 0;
  $handler->display->display_options['fields']['field_district_state_upper']['field_api_classes'] = 0;
  /* Field: Location: City */
  $handler->display->display_options['fields']['city']['id'] = 'city';
  $handler->display->display_options['fields']['city']['table'] = 'location';
  $handler->display->display_options['fields']['city']['field'] = 'city';
  $handler->display->display_options['fields']['city']['relationship'] = 'field_site_nid';
  $handler->display->display_options['fields']['city']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['city']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['city']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['city']['alter']['external'] = 0;
  $handler->display->display_options['fields']['city']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['city']['alter']['trim_whitespace'] = 0;
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
  $handler->display->display_options['fields']['city']['hide_alter_empty'] = 0;
  /* Field: Location: Postal Code */
  $handler->display->display_options['fields']['postal_code']['id'] = 'postal_code';
  $handler->display->display_options['fields']['postal_code']['table'] = 'location';
  $handler->display->display_options['fields']['postal_code']['field'] = 'postal_code';
  $handler->display->display_options['fields']['postal_code']['relationship'] = 'field_site_nid';
  $handler->display->display_options['fields']['postal_code']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['postal_code']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['postal_code']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['postal_code']['alter']['external'] = 0;
  $handler->display->display_options['fields']['postal_code']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['postal_code']['alter']['trim_whitespace'] = 0;
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
  $handler->display->display_options['fields']['postal_code']['hide_alter_empty'] = 0;
  /* Field: Location: Province */
  $handler->display->display_options['fields']['province']['id'] = 'province';
  $handler->display->display_options['fields']['province']['table'] = 'location';
  $handler->display->display_options['fields']['province']['field'] = 'province';
  $handler->display->display_options['fields']['province']['relationship'] = 'field_site_nid';
  $handler->display->display_options['fields']['province']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['province']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['province']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['province']['alter']['external'] = 0;
  $handler->display->display_options['fields']['province']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['province']['alter']['trim_whitespace'] = 0;
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
  $handler->display->display_options['fields']['province']['hide_alter_empty'] = 0;
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
  /* Filter criterion: Content: Subject (field_course_subject) */
  $handler->display->display_options['filters']['field_course_subject_value']['id'] = 'field_course_subject_value';
  $handler->display->display_options['filters']['field_course_subject_value']['table'] = 'field_data_field_course_subject';
  $handler->display->display_options['filters']['field_course_subject_value']['field'] = 'field_course_subject_value';
  $handler->display->display_options['filters']['field_course_subject_value']['operator'] = 'starts';
  $handler->display->display_options['filters']['field_course_subject_value']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_course_subject_value']['expose']['operator_id'] = 'field_course_subject_value_op';
  $handler->display->display_options['filters']['field_course_subject_value']['expose']['label'] = 'Course Prefix (i.e. "ENG" for "ENG 101")';
  $handler->display->display_options['filters']['field_course_subject_value']['expose']['operator'] = 'field_course_subject_value_op';
  $handler->display->display_options['filters']['field_course_subject_value']['expose']['identifier'] = 'field_course_subject_value';
  $handler->display->display_options['filters']['field_course_subject_value']['expose']['required'] = 0;
  $handler->display->display_options['filters']['field_course_subject_value']['expose']['multiple'] = FALSE;
  /* Filter criterion: Content: Term (field_term) */
  $handler->display->display_options['filters']['field_term_nid']['id'] = 'field_term_nid';
  $handler->display->display_options['filters']['field_term_nid']['table'] = 'field_data_field_term';
  $handler->display->display_options['filters']['field_term_nid']['field'] = 'field_term_nid';
  $handler->display->display_options['filters']['field_term_nid']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_term_nid']['expose']['operator_id'] = 'field_term_nid_op';
  $handler->display->display_options['filters']['field_term_nid']['expose']['label'] = 'Term';
  $handler->display->display_options['filters']['field_term_nid']['expose']['operator'] = 'field_term_nid_op';
  $handler->display->display_options['filters']['field_term_nid']['expose']['identifier'] = 'field_term_nid';
  $handler->display->display_options['filters']['field_term_nid']['expose']['multiple'] = 1;
  $handler->display->display_options['filters']['field_term_nid']['expose']['reduce'] = 0;
  /* Filter criterion: Content: Dynamic Fields */
  $handler->display->display_options['filters']['dyfield']['id'] = 'dyfield';
  $handler->display->display_options['filters']['dyfield']['table'] = 'node';
  $handler->display->display_options['filters']['dyfield']['field'] = 'dyfield';
  $handler->display->display_options['filters']['dyfield']['exposed'] = TRUE;
  $handler->display->display_options['filters']['dyfield']['expose']['operator_id'] = '';
  $handler->display->display_options['filters']['dyfield']['expose']['label'] = 'Fields';
  $handler->display->display_options['filters']['dyfield']['expose']['use_operator'] = FALSE;
  $handler->display->display_options['filters']['dyfield']['expose']['operator'] = 'dyfield_op';
  $handler->display->display_options['filters']['dyfield']['expose']['identifier'] = 'dyfield';
  $handler->display->display_options['filters']['dyfield']['filterable_fields'] = array(
    'field_course_subject' => 'field_course_subject',
    'field_course_catalog_number' => 'field_course_catalog_number',
    'field_course_section' => 'field_course_section',
    'field_course_title' => 'field_course_title',
    'course_student_enrollment' => 'course_student_enrollment',
    'field_course_signups' => 'field_course_signups',
    'view_node' => 'view_node',
    'field_site' => 'field_site',
    'field_district_federal' => 'field_district_federal',
    'field_district_state_lower' => 'field_district_state_lower',
    'field_district_state_upper' => 'field_district_state_upper',
    'city' => 0,
    'postal_code' => 0,
    'province' => 0,
  );
  $handler->display->display_options['filters']['dyfield']['defaults_filterable_fields'] = array(
    'field_course_subject' => 'field_course_subject',
    'field_course_catalog_number' => 'field_course_catalog_number',
    'field_course_section' => 'field_course_section',
    'field_course_signups' => 'field_course_signups',
    'view_node' => 'view_node',
    'field_course_title' => 0,
    'course_student_enrollment' => 0,
    'field_site' => 0,
    'field_district_federal' => 0,
    'field_district_state_lower' => 0,
    'field_district_state_upper' => 0,
    'city' => 0,
    'postal_code' => 0,
    'province' => 0,
  );
  $handler->display->display_options['filters']['dyfield']['sortability'] = 1;
  $handler->display->display_options['filters']['dyfield']['checkboxes'] = 0;
  /* Filter criterion: Content: Catalog number (field_course_catalog_number) */
  $handler->display->display_options['filters']['field_course_catalog_number_value']['id'] = 'field_course_catalog_number_value';
  $handler->display->display_options['filters']['field_course_catalog_number_value']['table'] = 'field_data_field_course_catalog_number';
  $handler->display->display_options['filters']['field_course_catalog_number_value']['field'] = 'field_course_catalog_number_value';
  $handler->display->display_options['filters']['field_course_catalog_number_value']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_course_catalog_number_value']['expose']['operator_id'] = 'field_course_catalog_number_value_op';
  $handler->display->display_options['filters']['field_course_catalog_number_value']['expose']['label'] = 'Catalog number';
  $handler->display->display_options['filters']['field_course_catalog_number_value']['expose']['operator'] = 'field_course_catalog_number_value_op';
  $handler->display->display_options['filters']['field_course_catalog_number_value']['expose']['identifier'] = 'field_course_catalog_number_value';
  $handler->display->display_options['filters']['field_course_catalog_number_value']['expose']['required'] = 0;
  $handler->display->display_options['filters']['field_course_catalog_number_value']['expose']['multiple'] = FALSE;
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
  $handler->display->display_options['filters']['city']['expose']['required'] = 0;
  $handler->display->display_options['filters']['city']['expose']['multiple'] = FALSE;
  /* Filter criterion: Content: Issues addressed (field_csu_facility) */
  $handler->display->display_options['filters']['field_csu_facility_tid']['id'] = 'field_csu_facility_tid';
  $handler->display->display_options['filters']['field_csu_facility_tid']['table'] = 'field_data_field_csu_facility';
  $handler->display->display_options['filters']['field_csu_facility_tid']['field'] = 'field_csu_facility_tid';
  $handler->display->display_options['filters']['field_csu_facility_tid']['relationship'] = 'field_site_nid';
  $handler->display->display_options['filters']['field_csu_facility_tid']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_csu_facility_tid']['expose']['operator_id'] = 'field_csu_facility_tid_op';
  $handler->display->display_options['filters']['field_csu_facility_tid']['expose']['label'] = 'Issues addressed';
  $handler->display->display_options['filters']['field_csu_facility_tid']['expose']['operator'] = 'field_csu_facility_tid_op';
  $handler->display->display_options['filters']['field_csu_facility_tid']['expose']['identifier'] = 'field_csu_facility_tid';
  $handler->display->display_options['filters']['field_csu_facility_tid']['expose']['multiple'] = 1;
  $handler->display->display_options['filters']['field_csu_facility_tid']['expose']['reduce'] = 0;
  $handler->display->display_options['filters']['field_csu_facility_tid']['reduce_duplicates'] = 0;
  $handler->display->display_options['filters']['field_csu_facility_tid']['type'] = 'select';
  $handler->display->display_options['filters']['field_csu_facility_tid']['vocabulary'] = 'issues_addressed';
  $handler->display->display_options['filters']['field_csu_facility_tid']['error_message'] = 1;
  /* Filter criterion: Content: Organization type (field_csu_org_type) */
  $handler->display->display_options['filters']['field_csu_org_type_tid']['id'] = 'field_csu_org_type_tid';
  $handler->display->display_options['filters']['field_csu_org_type_tid']['table'] = 'field_data_field_csu_org_type';
  $handler->display->display_options['filters']['field_csu_org_type_tid']['field'] = 'field_csu_org_type_tid';
  $handler->display->display_options['filters']['field_csu_org_type_tid']['relationship'] = 'field_site_nid';
  $handler->display->display_options['filters']['field_csu_org_type_tid']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_csu_org_type_tid']['expose']['operator_id'] = 'field_csu_org_type_tid_op';
  $handler->display->display_options['filters']['field_csu_org_type_tid']['expose']['label'] = 'Organization type';
  $handler->display->display_options['filters']['field_csu_org_type_tid']['expose']['operator'] = 'field_csu_org_type_tid_op';
  $handler->display->display_options['filters']['field_csu_org_type_tid']['expose']['identifier'] = 'field_csu_org_type_tid';
  $handler->display->display_options['filters']['field_csu_org_type_tid']['expose']['multiple'] = 1;
  $handler->display->display_options['filters']['field_csu_org_type_tid']['expose']['reduce'] = 0;
  $handler->display->display_options['filters']['field_csu_org_type_tid']['reduce_duplicates'] = 0;
  $handler->display->display_options['filters']['field_csu_org_type_tid']['type'] = 'select';
  $handler->display->display_options['filters']['field_csu_org_type_tid']['vocabulary'] = 'organization_type';
  $handler->display->display_options['filters']['field_csu_org_type_tid']['error_message'] = 1;

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
    t('Search'),
    t('Reset'),
    t('Sort by'),
    t('Asc'),
    t('Desc'),
    t('Items per page'),
    t('- All -'),
    t('Offset'),
    t('field_term'),
    t('field_course_students'),
    t('field_course'),
    t('field_site'),
    t('Subject'),
    t('Number'),
    t('Section'),
    t('Title'),
    t('Students'),
    t('Enrollment'),
    t('Total signed up'),
    t('View'),
    t('Site'),
    t('Federal district'),
    t('State lower district'),
    t('State upper district'),
    t('City'),
    t('Postal Code'),
    t('Province'),
    t('Course Prefix (i.e. "ENG" for "ENG 101")'),
    t('Term'),
    t('Fields'),
    t('Catalog number'),
    t('Issues addressed'),
    t('Organization type'),
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
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Site Report';
  $handler->display->display_options['css_class'] = 'report-view';
  $handler->display->display_options['link_display'] = 'page';
  $handler->display->display_options['access']['type'] = 'role';
  $handler->display->display_options['access']['role'] = array(
    3 => '3',
    4 => '4',
  );
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['query']['options']['distinct'] = TRUE;
  $handler->display->display_options['query']['options']['query_comment'] = FALSE;
  $handler->display->display_options['exposed_form']['type'] = 's4_reporting';
  $handler->display->display_options['exposed_form']['options']['submit_button'] = 'Search';
  $handler->display->display_options['exposed_form']['options']['reset_button'] = TRUE;
  $handler->display->display_options['exposed_form']['options']['autosubmit'] = 0;
  $handler->display->display_options['exposed_form']['options']['autosubmit_hide'] = 1;
  $handler->display->display_options['exposed_form']['options']['s4_reporting'] = array(
    'group-city' => '1',
    'group-field_csu_facility_tid' => '0',
    'group-field_csu_org_type_tid' => '0',
    'group-dyfield' => '3',
    'group-field_term_nid' => '0',
    'group-field_course_subject_value' => '2',
    'group-field_course_catalog_number_value' => '2',
    'group-field_district_federal_value' => '1',
    'group-field_district_state_lower_value' => '1',
    'group-field_district_state_upper_value' => '1',
    'group-distance' => '1',
    'groups' => 'Site information
Location
Courses
Fields',
  );
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '30';
  $handler->display->display_options['style_plugin'] = 'views_calc';
  $handler->display->display_options['style_options']['columns'] = array(
    'title' => 'title',
    'field_website' => 'field_website',
    'field_site_email' => 'field_site_email',
    'field_phone' => 'field_phone',
    'city' => 'city',
    'postal_code' => 'postal_code',
    'province' => 'province',
    'street' => 'street',
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
    'field_site_restrict_1' => 'field_site_restrict_1',
    'field_workflow_status' => 'field_workflow_status',
    'field_signup_hours' => 'field_signup_hours',
  );
  $handler->display->display_options['style_options']['default'] = '-1';
  $handler->display->display_options['style_options']['info'] = array(
    'title' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'has_calc' => 1,
      'calc' => array(
        'COUNT' => 'COUNT',
      ),
    ),
    'field_website' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'has_calc' => 0,
      'calc' => array(),
    ),
    'field_site_email' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'has_calc' => 0,
      'calc' => array(),
    ),
    'field_phone' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'has_calc' => 0,
      'calc' => array(),
    ),
    'city' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'has_calc' => 0,
      'calc' => array(),
    ),
    'postal_code' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'has_calc' => 0,
      'calc' => array(),
    ),
    'province' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'has_calc' => 0,
      'calc' => array(),
    ),
    'street' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'has_calc' => 0,
      'calc' => array(),
    ),
    'field_site_users' => array(
      'align' => '',
      'separator' => '',
      'has_calc' => 0,
      'calc' => array(),
    ),
    'body' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'has_calc' => 0,
      'calc' => array(),
    ),
    'field_site_projects' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'has_calc' => 0,
      'calc' => array(),
    ),
    'field_site_demographics' => array(
      'align' => '',
      'separator' => '',
      'has_calc' => 0,
      'calc' => array(),
    ),
    'field_site_email_1' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'has_calc' => 0,
      'calc' => array(),
    ),
    'field_site_hours' => array(
      'align' => '',
      'separator' => '',
      'has_calc' => 0,
      'calc' => array(),
    ),
    'field_site_eval_form' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'has_calc' => 0,
      'calc' => array(),
    ),
    'field_csu_facility' => array(
      'align' => '',
      'separator' => '',
      'has_calc' => 0,
      'calc' => array(),
    ),
    'field_signups_max' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'has_calc' => 0,
      'calc' => array(),
    ),
    'field_csu_org_type' => array(
      'align' => '',
      'separator' => '',
      'has_calc' => 0,
      'calc' => array(),
    ),
    'field_phone_1' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'has_calc' => 0,
      'calc' => array(),
    ),
    'field_health_risk' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'has_calc' => 0,
      'calc' => array(),
    ),
    'field_site_form' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'has_calc' => 0,
      'calc' => array(),
    ),
    'field_site_instructions_required' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'has_calc' => 0,
      'calc' => array(),
    ),
    'field_site_requirements' => array(
      'align' => '',
      'separator' => '',
      'has_calc' => 0,
      'calc' => array(),
    ),
    'field_site_tour' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'has_calc' => 0,
      'calc' => array(),
    ),
    'field_site_facebook_page' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'has_calc' => 0,
      'calc' => array(),
    ),
    'field_site_instructions' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'has_calc' => 0,
      'calc' => array(),
    ),
    'field_tags' => array(
      'align' => '',
      'separator' => '',
      'has_calc' => 0,
      'calc' => array(),
    ),
    'field_site_health_training' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'has_calc' => 0,
      'calc' => array(),
    ),
    'field_website_1' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'has_calc' => 0,
      'calc' => array(),
    ),
    'field_site_hours_minimum' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'has_calc' => 0,
      'calc' => array(),
    ),
    'field_site_language' => array(
      'align' => '',
      'separator' => '',
      'has_calc' => 0,
      'calc' => array(),
    ),
    'field_site_restrict' => array(
      'align' => '',
      'separator' => '',
      'has_calc' => 0,
      'calc' => array(),
    ),
    'field_site_restrict_1' => array(
      'align' => '',
      'separator' => '',
      'has_calc' => 0,
      'calc' => array(),
    ),
    'field_workflow_status' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'has_calc' => 0,
      'calc' => array(),
    ),
    'field_signup_hours' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'has_calc' => 1,
      'calc' => array(
        'SUM' => 'SUM',
      ),
    ),
  );
  $handler->display->display_options['style_options']['override'] = 1;
  $handler->display->display_options['style_options']['sticky'] = 0;
  $handler->display->display_options['style_options']['empty_table'] = 0;
  $handler->display->display_options['style_options']['detailed_values'] = '0';
  /* Relationship: Content: Site (field_site) - reverse */
  $handler->display->display_options['relationships']['reverse_field_site_node']['id'] = 'reverse_field_site_node';
  $handler->display->display_options['relationships']['reverse_field_site_node']['table'] = 'node';
  $handler->display->display_options['relationships']['reverse_field_site_node']['field'] = 'reverse_field_site_node';
  $handler->display->display_options['relationships']['reverse_field_site_node']['required'] = 0;
  /* Relationship: Content: Course (field_course) */
  $handler->display->display_options['relationships']['field_course_nid']['id'] = 'field_course_nid';
  $handler->display->display_options['relationships']['field_course_nid']['table'] = 'field_data_field_course';
  $handler->display->display_options['relationships']['field_course_nid']['field'] = 'field_course_nid';
  $handler->display->display_options['relationships']['field_course_nid']['relationship'] = 'reverse_field_site_node';
  $handler->display->display_options['relationships']['field_course_nid']['required'] = 0;
  $handler->display->display_options['relationships']['field_course_nid']['delta'] = '-1';
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = 'Site';
  $handler->display->display_options['fields']['title']['alter']['alter_text'] = 0;
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
  $handler->display->display_options['fields']['title']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['title']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['title']['hide_empty'] = 0;
  $handler->display->display_options['fields']['title']['empty_zero'] = 0;
  $handler->display->display_options['fields']['title']['hide_alter_empty'] = 0;
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
  /* Field: Content: Federal district */
  $handler->display->display_options['fields']['field_district_federal']['id'] = 'field_district_federal';
  $handler->display->display_options['fields']['field_district_federal']['table'] = 'field_data_field_district_federal';
  $handler->display->display_options['fields']['field_district_federal']['field'] = 'field_district_federal';
  $handler->display->display_options['fields']['field_district_federal']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_district_federal']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_district_federal']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_district_federal']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_district_federal']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_district_federal']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_district_federal']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_district_federal']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_district_federal']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_district_federal']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_district_federal']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_district_federal']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_district_federal']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['field_district_federal']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_district_federal']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_district_federal']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_district_federal']['hide_alter_empty'] = 0;
  $handler->display->display_options['fields']['field_district_federal']['field_api_classes'] = 0;
  /* Field: Content: State lower district */
  $handler->display->display_options['fields']['field_district_state_lower']['id'] = 'field_district_state_lower';
  $handler->display->display_options['fields']['field_district_state_lower']['table'] = 'field_data_field_district_state_lower';
  $handler->display->display_options['fields']['field_district_state_lower']['field'] = 'field_district_state_lower';
  $handler->display->display_options['fields']['field_district_state_lower']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_district_state_lower']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_district_state_lower']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_district_state_lower']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_district_state_lower']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_district_state_lower']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_district_state_lower']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_district_state_lower']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_district_state_lower']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_district_state_lower']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_district_state_lower']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_district_state_lower']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_district_state_lower']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['field_district_state_lower']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_district_state_lower']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_district_state_lower']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_district_state_lower']['hide_alter_empty'] = 0;
  $handler->display->display_options['fields']['field_district_state_lower']['field_api_classes'] = 0;
  /* Field: Content: State upper district */
  $handler->display->display_options['fields']['field_district_state_upper']['id'] = 'field_district_state_upper';
  $handler->display->display_options['fields']['field_district_state_upper']['table'] = 'field_data_field_district_state_upper';
  $handler->display->display_options['fields']['field_district_state_upper']['field'] = 'field_district_state_upper';
  $handler->display->display_options['fields']['field_district_state_upper']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_district_state_upper']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_district_state_upper']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_district_state_upper']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_district_state_upper']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_district_state_upper']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_district_state_upper']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_district_state_upper']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_district_state_upper']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_district_state_upper']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_district_state_upper']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_district_state_upper']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_district_state_upper']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['field_district_state_upper']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_district_state_upper']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_district_state_upper']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_district_state_upper']['hide_alter_empty'] = 0;
  $handler->display->display_options['fields']['field_district_state_upper']['field_api_classes'] = 0;
  /* Field: Content: Additional users */
  $handler->display->display_options['fields']['field_site_users']['id'] = 'field_site_users';
  $handler->display->display_options['fields']['field_site_users']['table'] = 'field_data_field_site_users';
  $handler->display->display_options['fields']['field_site_users']['field'] = 'field_site_users';
  $handler->display->display_options['fields']['field_site_users']['label'] = 'Users';
  $handler->display->display_options['fields']['field_site_users']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_site_users']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_site_users']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_site_users']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_site_users']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_site_users']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_site_users']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_site_users']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_site_users']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_site_users']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_site_users']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_site_users']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_site_users']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['field_site_users']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_site_users']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_site_users']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_site_users']['hide_alter_empty'] = 0;
  $handler->display->display_options['fields']['field_site_users']['group_rows'] = 1;
  $handler->display->display_options['fields']['field_site_users']['delta_offset'] = '0';
  $handler->display->display_options['fields']['field_site_users']['delta_reversed'] = 0;
  $handler->display->display_options['fields']['field_site_users']['field_api_classes'] = 0;
  /* Field: Content: Body */
  $handler->display->display_options['fields']['body']['id'] = 'body';
  $handler->display->display_options['fields']['body']['table'] = 'field_data_body';
  $handler->display->display_options['fields']['body']['field'] = 'body';
  $handler->display->display_options['fields']['body']['label'] = 'Description';
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
  $handler->display->display_options['fields']['body']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['body']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['body']['hide_empty'] = 0;
  $handler->display->display_options['fields']['body']['empty_zero'] = 0;
  $handler->display->display_options['fields']['body']['hide_alter_empty'] = 0;
  $handler->display->display_options['fields']['body']['field_api_classes'] = 0;
  /* Field: Content: Briefly describe any ongoing needs or special projects with which students can assist agency staff */
  $handler->display->display_options['fields']['field_site_projects']['id'] = 'field_site_projects';
  $handler->display->display_options['fields']['field_site_projects']['table'] = 'field_data_field_site_projects';
  $handler->display->display_options['fields']['field_site_projects']['field'] = 'field_site_projects';
  $handler->display->display_options['fields']['field_site_projects']['label'] = 'Special projects';
  $handler->display->display_options['fields']['field_site_projects']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_site_projects']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_site_projects']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_site_projects']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_site_projects']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_site_projects']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_site_projects']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_site_projects']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_site_projects']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_site_projects']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_site_projects']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_site_projects']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_site_projects']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['field_site_projects']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_site_projects']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_site_projects']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_site_projects']['hide_alter_empty'] = 0;
  $handler->display->display_options['fields']['field_site_projects']['field_api_classes'] = 0;
  /* Field: Content: By percentage, what is the demographic of the population you serve? */
  $handler->display->display_options['fields']['field_site_demographics']['id'] = 'field_site_demographics';
  $handler->display->display_options['fields']['field_site_demographics']['table'] = 'field_data_field_site_demographics';
  $handler->display->display_options['fields']['field_site_demographics']['field'] = 'field_site_demographics';
  $handler->display->display_options['fields']['field_site_demographics']['label'] = 'Demographic';
  $handler->display->display_options['fields']['field_site_demographics']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_site_demographics']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_site_demographics']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_site_demographics']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_site_demographics']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_site_demographics']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_site_demographics']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_site_demographics']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_site_demographics']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_site_demographics']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_site_demographics']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_site_demographics']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_site_demographics']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['field_site_demographics']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_site_demographics']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_site_demographics']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_site_demographics']['hide_alter_empty'] = 0;
  $handler->display->display_options['fields']['field_site_demographics']['group_rows'] = 1;
  $handler->display->display_options['fields']['field_site_demographics']['delta_offset'] = '0';
  $handler->display->display_options['fields']['field_site_demographics']['delta_reversed'] = 0;
  $handler->display->display_options['fields']['field_site_demographics']['field_api_classes'] = 0;
  /* Field: Content: Contact email */
  $handler->display->display_options['fields']['field_site_email_1']['id'] = 'field_site_email_1';
  $handler->display->display_options['fields']['field_site_email_1']['table'] = 'field_data_field_site_email';
  $handler->display->display_options['fields']['field_site_email_1']['field'] = 'field_site_email';
  $handler->display->display_options['fields']['field_site_email_1']['label'] = 'Email';
  $handler->display->display_options['fields']['field_site_email_1']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_site_email_1']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_site_email_1']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_site_email_1']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_site_email_1']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_site_email_1']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_site_email_1']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_site_email_1']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_site_email_1']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_site_email_1']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_site_email_1']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_site_email_1']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_site_email_1']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['field_site_email_1']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_site_email_1']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_site_email_1']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_site_email_1']['hide_alter_empty'] = 0;
  $handler->display->display_options['fields']['field_site_email_1']['type'] = 'email_default';
  $handler->display->display_options['fields']['field_site_email_1']['field_api_classes'] = 0;
  /* Field: Content: Days and hours will you accept students for service (check all that apply) */
  $handler->display->display_options['fields']['field_site_hours']['id'] = 'field_site_hours';
  $handler->display->display_options['fields']['field_site_hours']['table'] = 'field_data_field_site_hours';
  $handler->display->display_options['fields']['field_site_hours']['field'] = 'field_site_hours';
  $handler->display->display_options['fields']['field_site_hours']['label'] = 'Hours';
  $handler->display->display_options['fields']['field_site_hours']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_site_hours']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_site_hours']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_site_hours']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_site_hours']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_site_hours']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_site_hours']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_site_hours']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_site_hours']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_site_hours']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_site_hours']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_site_hours']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_site_hours']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['field_site_hours']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_site_hours']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_site_hours']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_site_hours']['hide_alter_empty'] = 0;
  $handler->display->display_options['fields']['field_site_hours']['group_rows'] = 1;
  $handler->display->display_options['fields']['field_site_hours']['delta_offset'] = '0';
  $handler->display->display_options['fields']['field_site_hours']['delta_reversed'] = 0;
  $handler->display->display_options['fields']['field_site_hours']['field_api_classes'] = 0;
  /* Field: Content: Evaluation Form */
  $handler->display->display_options['fields']['field_site_eval_form']['id'] = 'field_site_eval_form';
  $handler->display->display_options['fields']['field_site_eval_form']['table'] = 'field_data_field_site_eval_form';
  $handler->display->display_options['fields']['field_site_eval_form']['field'] = 'field_site_eval_form';
  $handler->display->display_options['fields']['field_site_eval_form']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_site_eval_form']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_site_eval_form']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_site_eval_form']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_site_eval_form']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_site_eval_form']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_site_eval_form']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_site_eval_form']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_site_eval_form']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_site_eval_form']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_site_eval_form']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_site_eval_form']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_site_eval_form']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['field_site_eval_form']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_site_eval_form']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_site_eval_form']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_site_eval_form']['hide_alter_empty'] = 0;
  $handler->display->display_options['fields']['field_site_eval_form']['field_api_classes'] = 0;
  /* Field: Content: Issues addressed */
  $handler->display->display_options['fields']['field_csu_facility']['id'] = 'field_csu_facility';
  $handler->display->display_options['fields']['field_csu_facility']['table'] = 'field_data_field_csu_facility';
  $handler->display->display_options['fields']['field_csu_facility']['field'] = 'field_csu_facility';
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
  $handler->display->display_options['fields']['field_csu_facility']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['field_csu_facility']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_csu_facility']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_csu_facility']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_csu_facility']['hide_alter_empty'] = 0;
  $handler->display->display_options['fields']['field_csu_facility']['group_rows'] = 1;
  $handler->display->display_options['fields']['field_csu_facility']['delta_offset'] = '0';
  $handler->display->display_options['fields']['field_csu_facility']['delta_reversed'] = 0;
  $handler->display->display_options['fields']['field_csu_facility']['field_api_classes'] = 0;
  /* Field: Content: Maximum number of students */
  $handler->display->display_options['fields']['field_signups_max']['id'] = 'field_signups_max';
  $handler->display->display_options['fields']['field_signups_max']['table'] = 'field_data_field_signups_max';
  $handler->display->display_options['fields']['field_signups_max']['field'] = 'field_signups_max';
  $handler->display->display_options['fields']['field_signups_max']['label'] = 'Max students';
  $handler->display->display_options['fields']['field_signups_max']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_signups_max']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_signups_max']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_signups_max']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_signups_max']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_signups_max']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_signups_max']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_signups_max']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_signups_max']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_signups_max']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_signups_max']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_signups_max']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_signups_max']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['field_signups_max']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_signups_max']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_signups_max']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_signups_max']['hide_alter_empty'] = 0;
  $handler->display->display_options['fields']['field_signups_max']['settings'] = array(
    'thousand_separator' => ' ',
    'prefix_suffix' => 1,
  );
  $handler->display->display_options['fields']['field_signups_max']['field_api_classes'] = 0;
  /* Field: Content: Organization type */
  $handler->display->display_options['fields']['field_csu_org_type']['id'] = 'field_csu_org_type';
  $handler->display->display_options['fields']['field_csu_org_type']['table'] = 'field_data_field_csu_org_type';
  $handler->display->display_options['fields']['field_csu_org_type']['field'] = 'field_csu_org_type';
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
  $handler->display->display_options['fields']['field_csu_org_type']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['field_csu_org_type']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_csu_org_type']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_csu_org_type']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_csu_org_type']['hide_alter_empty'] = 0;
  $handler->display->display_options['fields']['field_csu_org_type']['group_rows'] = 1;
  $handler->display->display_options['fields']['field_csu_org_type']['delta_offset'] = '0';
  $handler->display->display_options['fields']['field_csu_org_type']['delta_reversed'] = 0;
  $handler->display->display_options['fields']['field_csu_org_type']['field_api_classes'] = 0;
  /* Field: Content: Phone number */
  $handler->display->display_options['fields']['field_phone_1']['id'] = 'field_phone_1';
  $handler->display->display_options['fields']['field_phone_1']['table'] = 'field_data_field_phone';
  $handler->display->display_options['fields']['field_phone_1']['field'] = 'field_phone';
  $handler->display->display_options['fields']['field_phone_1']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_phone_1']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_phone_1']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_phone_1']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_phone_1']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_phone_1']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_phone_1']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_phone_1']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_phone_1']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_phone_1']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_phone_1']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_phone_1']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_phone_1']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['field_phone_1']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_phone_1']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_phone_1']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_phone_1']['hide_alter_empty'] = 0;
  $handler->display->display_options['fields']['field_phone_1']['click_sort_column'] = 'number';
  $handler->display->display_options['fields']['field_phone_1']['field_api_classes'] = 0;
  /* Field: Content: Risk Identification */
  $handler->display->display_options['fields']['field_health_risk']['id'] = 'field_health_risk';
  $handler->display->display_options['fields']['field_health_risk']['table'] = 'field_data_field_health_risk';
  $handler->display->display_options['fields']['field_health_risk']['field'] = 'field_health_risk';
  $handler->display->display_options['fields']['field_health_risk']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_health_risk']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_health_risk']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_health_risk']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_health_risk']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_health_risk']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_health_risk']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_health_risk']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_health_risk']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_health_risk']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_health_risk']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_health_risk']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_health_risk']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['field_health_risk']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_health_risk']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_health_risk']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_health_risk']['hide_alter_empty'] = 0;
  $handler->display->display_options['fields']['field_health_risk']['field_api_classes'] = 0;
  /* Field: Content: Signup form */
  $handler->display->display_options['fields']['field_site_form']['id'] = 'field_site_form';
  $handler->display->display_options['fields']['field_site_form']['table'] = 'field_data_field_site_form';
  $handler->display->display_options['fields']['field_site_form']['field'] = 'field_site_form';
  $handler->display->display_options['fields']['field_site_form']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_site_form']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_site_form']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_site_form']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_site_form']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_site_form']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_site_form']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_site_form']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_site_form']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_site_form']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_site_form']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_site_form']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_site_form']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['field_site_form']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_site_form']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_site_form']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_site_form']['hide_alter_empty'] = 0;
  $handler->display->display_options['fields']['field_site_form']['field_api_classes'] = 0;
  /* Field: Content: Site has special requirements */
  $handler->display->display_options['fields']['field_site_instructions_required']['id'] = 'field_site_instructions_required';
  $handler->display->display_options['fields']['field_site_instructions_required']['table'] = 'field_data_field_site_instructions_required';
  $handler->display->display_options['fields']['field_site_instructions_required']['field'] = 'field_site_instructions_required';
  $handler->display->display_options['fields']['field_site_instructions_required']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_site_instructions_required']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_site_instructions_required']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_site_instructions_required']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_site_instructions_required']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_site_instructions_required']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_site_instructions_required']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_site_instructions_required']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_site_instructions_required']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_site_instructions_required']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_site_instructions_required']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_site_instructions_required']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_site_instructions_required']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['field_site_instructions_required']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_site_instructions_required']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_site_instructions_required']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_site_instructions_required']['hide_alter_empty'] = 0;
  $handler->display->display_options['fields']['field_site_instructions_required']['field_api_classes'] = 0;
  /* Field: Content: Site special requirements */
  $handler->display->display_options['fields']['field_site_requirements']['id'] = 'field_site_requirements';
  $handler->display->display_options['fields']['field_site_requirements']['table'] = 'field_data_field_site_requirements';
  $handler->display->display_options['fields']['field_site_requirements']['field'] = 'field_site_requirements';
  $handler->display->display_options['fields']['field_site_requirements']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_site_requirements']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_site_requirements']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_site_requirements']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_site_requirements']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_site_requirements']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_site_requirements']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_site_requirements']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_site_requirements']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_site_requirements']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_site_requirements']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_site_requirements']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_site_requirements']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['field_site_requirements']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_site_requirements']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_site_requirements']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_site_requirements']['hide_alter_empty'] = 0;
  $handler->display->display_options['fields']['field_site_requirements']['group_rows'] = 1;
  $handler->display->display_options['fields']['field_site_requirements']['delta_offset'] = '0';
  $handler->display->display_options['fields']['field_site_requirements']['delta_reversed'] = 0;
  $handler->display->display_options['fields']['field_site_requirements']['field_api_classes'] = 0;
  /* Field: Content: Site Tour */
  $handler->display->display_options['fields']['field_site_tour']['id'] = 'field_site_tour';
  $handler->display->display_options['fields']['field_site_tour']['table'] = 'field_data_field_site_tour';
  $handler->display->display_options['fields']['field_site_tour']['field'] = 'field_site_tour';
  $handler->display->display_options['fields']['field_site_tour']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_site_tour']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_site_tour']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_site_tour']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_site_tour']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_site_tour']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_site_tour']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_site_tour']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_site_tour']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_site_tour']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_site_tour']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_site_tour']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_site_tour']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['field_site_tour']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_site_tour']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_site_tour']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_site_tour']['hide_alter_empty'] = 0;
  $handler->display->display_options['fields']['field_site_tour']['field_api_classes'] = 0;
  /* Field: Content: Social network page */
  $handler->display->display_options['fields']['field_site_facebook_page']['id'] = 'field_site_facebook_page';
  $handler->display->display_options['fields']['field_site_facebook_page']['table'] = 'field_data_field_site_facebook_page';
  $handler->display->display_options['fields']['field_site_facebook_page']['field'] = 'field_site_facebook_page';
  $handler->display->display_options['fields']['field_site_facebook_page']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_site_facebook_page']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_site_facebook_page']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_site_facebook_page']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_site_facebook_page']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_site_facebook_page']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_site_facebook_page']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_site_facebook_page']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_site_facebook_page']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_site_facebook_page']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_site_facebook_page']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_site_facebook_page']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_site_facebook_page']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['field_site_facebook_page']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_site_facebook_page']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_site_facebook_page']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_site_facebook_page']['hide_alter_empty'] = 0;
  $handler->display->display_options['fields']['field_site_facebook_page']['click_sort_column'] = 'url';
  $handler->display->display_options['fields']['field_site_facebook_page']['field_api_classes'] = 0;
  /* Field: Content: Special site instructions */
  $handler->display->display_options['fields']['field_site_instructions']['id'] = 'field_site_instructions';
  $handler->display->display_options['fields']['field_site_instructions']['table'] = 'field_data_field_site_instructions';
  $handler->display->display_options['fields']['field_site_instructions']['field'] = 'field_site_instructions';
  $handler->display->display_options['fields']['field_site_instructions']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_site_instructions']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_site_instructions']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_site_instructions']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_site_instructions']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_site_instructions']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_site_instructions']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_site_instructions']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_site_instructions']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_site_instructions']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_site_instructions']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_site_instructions']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_site_instructions']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['field_site_instructions']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_site_instructions']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_site_instructions']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_site_instructions']['hide_alter_empty'] = 0;
  $handler->display->display_options['fields']['field_site_instructions']['field_api_classes'] = 0;
  /* Field: Content: Tags */
  $handler->display->display_options['fields']['field_tags']['id'] = 'field_tags';
  $handler->display->display_options['fields']['field_tags']['table'] = 'field_data_field_tags';
  $handler->display->display_options['fields']['field_tags']['field'] = 'field_tags';
  $handler->display->display_options['fields']['field_tags']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_tags']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_tags']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_tags']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_tags']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_tags']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_tags']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_tags']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_tags']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_tags']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_tags']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_tags']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_tags']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['field_tags']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_tags']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_tags']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_tags']['hide_alter_empty'] = 0;
  $handler->display->display_options['fields']['field_tags']['group_rows'] = 1;
  $handler->display->display_options['fields']['field_tags']['delta_offset'] = '0';
  $handler->display->display_options['fields']['field_tags']['delta_reversed'] = 0;
  $handler->display->display_options['fields']['field_tags']['field_api_classes'] = 0;
  /* Field: Content: Training and orientation information */
  $handler->display->display_options['fields']['field_site_health_training']['id'] = 'field_site_health_training';
  $handler->display->display_options['fields']['field_site_health_training']['table'] = 'field_data_field_site_health_training';
  $handler->display->display_options['fields']['field_site_health_training']['field'] = 'field_site_health_training';
  $handler->display->display_options['fields']['field_site_health_training']['label'] = 'Training & orientation';
  $handler->display->display_options['fields']['field_site_health_training']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_site_health_training']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_site_health_training']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_site_health_training']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_site_health_training']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_site_health_training']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_site_health_training']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_site_health_training']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_site_health_training']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_site_health_training']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_site_health_training']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_site_health_training']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_site_health_training']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['field_site_health_training']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_site_health_training']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_site_health_training']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_site_health_training']['hide_alter_empty'] = 0;
  $handler->display->display_options['fields']['field_site_health_training']['field_api_classes'] = 0;
  /* Field: Content: Website */
  $handler->display->display_options['fields']['field_website_1']['id'] = 'field_website_1';
  $handler->display->display_options['fields']['field_website_1']['table'] = 'field_data_field_website';
  $handler->display->display_options['fields']['field_website_1']['field'] = 'field_website';
  $handler->display->display_options['fields']['field_website_1']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_website_1']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_website_1']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_website_1']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_website_1']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_website_1']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_website_1']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_website_1']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_website_1']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_website_1']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_website_1']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_website_1']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_website_1']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['field_website_1']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_website_1']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_website_1']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_website_1']['hide_alter_empty'] = 0;
  $handler->display->display_options['fields']['field_website_1']['click_sort_column'] = 'url';
  $handler->display->display_options['fields']['field_website_1']['field_api_classes'] = 0;
  /* Field: Content: What is the minimum number of hours you would require of a student in service per term */
  $handler->display->display_options['fields']['field_site_hours_minimum']['id'] = 'field_site_hours_minimum';
  $handler->display->display_options['fields']['field_site_hours_minimum']['table'] = 'field_data_field_site_hours_minimum';
  $handler->display->display_options['fields']['field_site_hours_minimum']['field'] = 'field_site_hours_minimum';
  $handler->display->display_options['fields']['field_site_hours_minimum']['label'] = 'Minimum hours';
  $handler->display->display_options['fields']['field_site_hours_minimum']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_site_hours_minimum']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_site_hours_minimum']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_site_hours_minimum']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_site_hours_minimum']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_site_hours_minimum']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_site_hours_minimum']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_site_hours_minimum']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_site_hours_minimum']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_site_hours_minimum']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_site_hours_minimum']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_site_hours_minimum']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_site_hours_minimum']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['field_site_hours_minimum']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_site_hours_minimum']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_site_hours_minimum']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_site_hours_minimum']['hide_alter_empty'] = 0;
  $handler->display->display_options['fields']['field_site_hours_minimum']['field_api_classes'] = 0;
  /* Field: Content: What languages would you like students to speak other than English? */
  $handler->display->display_options['fields']['field_site_language']['id'] = 'field_site_language';
  $handler->display->display_options['fields']['field_site_language']['table'] = 'field_data_field_site_language';
  $handler->display->display_options['fields']['field_site_language']['field'] = 'field_site_language';
  $handler->display->display_options['fields']['field_site_language']['label'] = 'Languages';
  $handler->display->display_options['fields']['field_site_language']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_site_language']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_site_language']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_site_language']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_site_language']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_site_language']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_site_language']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_site_language']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_site_language']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_site_language']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_site_language']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_site_language']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_site_language']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['field_site_language']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_site_language']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_site_language']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_site_language']['hide_alter_empty'] = 0;
  $handler->display->display_options['fields']['field_site_language']['group_rows'] = 1;
  $handler->display->display_options['fields']['field_site_language']['delta_offset'] = '0';
  $handler->display->display_options['fields']['field_site_language']['delta_reversed'] = 0;
  $handler->display->display_options['fields']['field_site_language']['field_api_classes'] = 0;
  /* Field: Field: Restricted to */
  $handler->display->display_options['fields']['field_site_restrict']['id'] = 'field_site_restrict';
  $handler->display->display_options['fields']['field_site_restrict']['table'] = 'field_data_field_site_restrict';
  $handler->display->display_options['fields']['field_site_restrict']['field'] = 'field_site_restrict';
  $handler->display->display_options['fields']['field_site_restrict']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_site_restrict']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_site_restrict']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_site_restrict']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_site_restrict']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_site_restrict']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_site_restrict']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_site_restrict']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_site_restrict']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_site_restrict']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_site_restrict']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_site_restrict']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_site_restrict']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['field_site_restrict']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_site_restrict']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_site_restrict']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_site_restrict']['hide_alter_empty'] = 0;
  $handler->display->display_options['fields']['field_site_restrict']['group_rows'] = 1;
  $handler->display->display_options['fields']['field_site_restrict']['delta_offset'] = '0';
  $handler->display->display_options['fields']['field_site_restrict']['delta_reversed'] = 0;
  $handler->display->display_options['fields']['field_site_restrict']['field_api_classes'] = 0;
  /* Field: Field: Status */
  $handler->display->display_options['fields']['field_workflow_status']['id'] = 'field_workflow_status';
  $handler->display->display_options['fields']['field_workflow_status']['table'] = 'field_data_field_workflow_status';
  $handler->display->display_options['fields']['field_workflow_status']['field'] = 'field_workflow_status';
  $handler->display->display_options['fields']['field_workflow_status']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_workflow_status']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_workflow_status']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_workflow_status']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_workflow_status']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_workflow_status']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_workflow_status']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_workflow_status']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_workflow_status']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_workflow_status']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_workflow_status']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_workflow_status']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_workflow_status']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['field_workflow_status']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_workflow_status']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_workflow_status']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_workflow_status']['hide_alter_empty'] = 0;
  $handler->display->display_options['fields']['field_workflow_status']['field_api_classes'] = 0;
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
  $handler->display->display_options['filters']['type']['group'] = 0;
  /* Filter criterion: Location: City */
  $handler->display->display_options['filters']['city']['id'] = 'city';
  $handler->display->display_options['filters']['city']['table'] = 'location';
  $handler->display->display_options['filters']['city']['field'] = 'city';
  $handler->display->display_options['filters']['city']['operator'] = 'contains';
  $handler->display->display_options['filters']['city']['group'] = 0;
  $handler->display->display_options['filters']['city']['exposed'] = TRUE;
  $handler->display->display_options['filters']['city']['expose']['operator_id'] = 'city_op';
  $handler->display->display_options['filters']['city']['expose']['label'] = 'City';
  $handler->display->display_options['filters']['city']['expose']['operator'] = 'city_op';
  $handler->display->display_options['filters']['city']['expose']['identifier'] = 'city';
  $handler->display->display_options['filters']['city']['expose']['multiple'] = FALSE;
  /* Filter criterion: Content: Issues addressed (field_csu_facility) */
  $handler->display->display_options['filters']['field_csu_facility_tid']['id'] = 'field_csu_facility_tid';
  $handler->display->display_options['filters']['field_csu_facility_tid']['table'] = 'field_data_field_csu_facility';
  $handler->display->display_options['filters']['field_csu_facility_tid']['field'] = 'field_csu_facility_tid';
  $handler->display->display_options['filters']['field_csu_facility_tid']['group'] = 0;
  $handler->display->display_options['filters']['field_csu_facility_tid']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_csu_facility_tid']['expose']['operator_id'] = 'field_csu_facility_tid_op';
  $handler->display->display_options['filters']['field_csu_facility_tid']['expose']['label'] = 'Issues addressed';
  $handler->display->display_options['filters']['field_csu_facility_tid']['expose']['operator'] = 'field_csu_facility_tid_op';
  $handler->display->display_options['filters']['field_csu_facility_tid']['expose']['identifier'] = 'field_csu_facility_tid';
  $handler->display->display_options['filters']['field_csu_facility_tid']['expose']['multiple'] = 1;
  $handler->display->display_options['filters']['field_csu_facility_tid']['expose']['reduce'] = 0;
  $handler->display->display_options['filters']['field_csu_facility_tid']['reduce_duplicates'] = 0;
  $handler->display->display_options['filters']['field_csu_facility_tid']['type'] = 'select';
  $handler->display->display_options['filters']['field_csu_facility_tid']['vocabulary'] = 'issues_addressed';
  $handler->display->display_options['filters']['field_csu_facility_tid']['error_message'] = 1;
  /* Filter criterion: Content: Organization type (field_csu_org_type) */
  $handler->display->display_options['filters']['field_csu_org_type_tid']['id'] = 'field_csu_org_type_tid';
  $handler->display->display_options['filters']['field_csu_org_type_tid']['table'] = 'field_data_field_csu_org_type';
  $handler->display->display_options['filters']['field_csu_org_type_tid']['field'] = 'field_csu_org_type_tid';
  $handler->display->display_options['filters']['field_csu_org_type_tid']['group'] = 0;
  $handler->display->display_options['filters']['field_csu_org_type_tid']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_csu_org_type_tid']['expose']['operator_id'] = 'field_csu_org_type_tid_op';
  $handler->display->display_options['filters']['field_csu_org_type_tid']['expose']['label'] = 'Org. type';
  $handler->display->display_options['filters']['field_csu_org_type_tid']['expose']['operator'] = 'field_csu_org_type_tid_op';
  $handler->display->display_options['filters']['field_csu_org_type_tid']['expose']['identifier'] = 'field_csu_org_type_tid';
  $handler->display->display_options['filters']['field_csu_org_type_tid']['expose']['multiple'] = 1;
  $handler->display->display_options['filters']['field_csu_org_type_tid']['expose']['reduce'] = 0;
  $handler->display->display_options['filters']['field_csu_org_type_tid']['reduce_duplicates'] = 0;
  $handler->display->display_options['filters']['field_csu_org_type_tid']['type'] = 'select';
  $handler->display->display_options['filters']['field_csu_org_type_tid']['vocabulary'] = 'organization_type';
  $handler->display->display_options['filters']['field_csu_org_type_tid']['error_message'] = 0;
  /* Filter criterion: Content: Dynamic Fields */
  $handler->display->display_options['filters']['dyfield']['id'] = 'dyfield';
  $handler->display->display_options['filters']['dyfield']['table'] = 'node';
  $handler->display->display_options['filters']['dyfield']['field'] = 'dyfield';
  $handler->display->display_options['filters']['dyfield']['group'] = 0;
  $handler->display->display_options['filters']['dyfield']['exposed'] = TRUE;
  $handler->display->display_options['filters']['dyfield']['expose']['operator_id'] = '';
  $handler->display->display_options['filters']['dyfield']['expose']['label'] = 'Fields';
  $handler->display->display_options['filters']['dyfield']['expose']['use_operator'] = FALSE;
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
  $handler->display->display_options['filters']['field_term_nid']['group'] = 0;
  $handler->display->display_options['filters']['field_term_nid']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_term_nid']['expose']['operator_id'] = 'field_term_nid_op';
  $handler->display->display_options['filters']['field_term_nid']['expose']['label'] = 'Had a student in';
  $handler->display->display_options['filters']['field_term_nid']['expose']['operator'] = 'field_term_nid_op';
  $handler->display->display_options['filters']['field_term_nid']['expose']['identifier'] = 'field_term_nid';
  $handler->display->display_options['filters']['field_term_nid']['expose']['remember'] = 1;
  $handler->display->display_options['filters']['field_term_nid']['expose']['multiple'] = 1;
  $handler->display->display_options['filters']['field_term_nid']['expose']['reduce'] = 0;
  /* Filter criterion: Content: Subject (field_course_subject) */
  $handler->display->display_options['filters']['field_course_subject_value']['id'] = 'field_course_subject_value';
  $handler->display->display_options['filters']['field_course_subject_value']['table'] = 'field_data_field_course_subject';
  $handler->display->display_options['filters']['field_course_subject_value']['field'] = 'field_course_subject_value';
  $handler->display->display_options['filters']['field_course_subject_value']['relationship'] = 'field_course_nid';
  $handler->display->display_options['filters']['field_course_subject_value']['group'] = 0;
  $handler->display->display_options['filters']['field_course_subject_value']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_course_subject_value']['expose']['operator_id'] = 'field_course_subject_value_op';
  $handler->display->display_options['filters']['field_course_subject_value']['expose']['label'] = 'Course Prefix';
  $handler->display->display_options['filters']['field_course_subject_value']['expose']['operator'] = 'field_course_subject_value_op';
  $handler->display->display_options['filters']['field_course_subject_value']['expose']['identifier'] = 'field_course_subject_value';
  $handler->display->display_options['filters']['field_course_subject_value']['expose']['required'] = 0;
  $handler->display->display_options['filters']['field_course_subject_value']['expose']['multiple'] = FALSE;
  /* Filter criterion: Content: Catalog number (field_course_catalog_number) */
  $handler->display->display_options['filters']['field_course_catalog_number_value']['id'] = 'field_course_catalog_number_value';
  $handler->display->display_options['filters']['field_course_catalog_number_value']['table'] = 'field_data_field_course_catalog_number';
  $handler->display->display_options['filters']['field_course_catalog_number_value']['field'] = 'field_course_catalog_number_value';
  $handler->display->display_options['filters']['field_course_catalog_number_value']['relationship'] = 'field_course_nid';
  $handler->display->display_options['filters']['field_course_catalog_number_value']['group'] = 0;
  $handler->display->display_options['filters']['field_course_catalog_number_value']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_course_catalog_number_value']['expose']['operator_id'] = 'field_course_catalog_number_value_op';
  $handler->display->display_options['filters']['field_course_catalog_number_value']['expose']['label'] = 'Course Catalog Number';
  $handler->display->display_options['filters']['field_course_catalog_number_value']['expose']['operator'] = 'field_course_catalog_number_value_op';
  $handler->display->display_options['filters']['field_course_catalog_number_value']['expose']['identifier'] = 'field_course_catalog_number_value';
  $handler->display->display_options['filters']['field_course_catalog_number_value']['expose']['required'] = 0;
  $handler->display->display_options['filters']['field_course_catalog_number_value']['expose']['multiple'] = FALSE;
  /* Filter criterion: Content: Federal district (field_district_federal) */
  $handler->display->display_options['filters']['field_district_federal_value']['id'] = 'field_district_federal_value';
  $handler->display->display_options['filters']['field_district_federal_value']['table'] = 'field_data_field_district_federal';
  $handler->display->display_options['filters']['field_district_federal_value']['field'] = 'field_district_federal_value';
  $handler->display->display_options['filters']['field_district_federal_value']['operator'] = 'contains';
  $handler->display->display_options['filters']['field_district_federal_value']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_district_federal_value']['expose']['operator_id'] = 'field_district_federal_value_op';
  $handler->display->display_options['filters']['field_district_federal_value']['expose']['label'] = 'Federal district';
  $handler->display->display_options['filters']['field_district_federal_value']['expose']['operator'] = 'field_district_federal_value_op';
  $handler->display->display_options['filters']['field_district_federal_value']['expose']['identifier'] = 'field_district_federal_value';
  $handler->display->display_options['filters']['field_district_federal_value']['expose']['required'] = 0;
  $handler->display->display_options['filters']['field_district_federal_value']['expose']['multiple'] = FALSE;
  /* Filter criterion: Content: State lower district (field_district_state_lower) */
  $handler->display->display_options['filters']['field_district_state_lower_value']['id'] = 'field_district_state_lower_value';
  $handler->display->display_options['filters']['field_district_state_lower_value']['table'] = 'field_data_field_district_state_lower';
  $handler->display->display_options['filters']['field_district_state_lower_value']['field'] = 'field_district_state_lower_value';
  $handler->display->display_options['filters']['field_district_state_lower_value']['operator'] = 'contains';
  $handler->display->display_options['filters']['field_district_state_lower_value']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_district_state_lower_value']['expose']['operator_id'] = 'field_district_state_lower_value_op';
  $handler->display->display_options['filters']['field_district_state_lower_value']['expose']['label'] = 'State lower district';
  $handler->display->display_options['filters']['field_district_state_lower_value']['expose']['operator'] = 'field_district_state_lower_value_op';
  $handler->display->display_options['filters']['field_district_state_lower_value']['expose']['identifier'] = 'field_district_state_lower_value';
  $handler->display->display_options['filters']['field_district_state_lower_value']['expose']['required'] = 0;
  $handler->display->display_options['filters']['field_district_state_lower_value']['expose']['multiple'] = FALSE;
  /* Filter criterion: Content: State upper district (field_district_state_upper) */
  $handler->display->display_options['filters']['field_district_state_upper_value']['id'] = 'field_district_state_upper_value';
  $handler->display->display_options['filters']['field_district_state_upper_value']['table'] = 'field_data_field_district_state_upper';
  $handler->display->display_options['filters']['field_district_state_upper_value']['field'] = 'field_district_state_upper_value';
  $handler->display->display_options['filters']['field_district_state_upper_value']['operator'] = 'contains';
  $handler->display->display_options['filters']['field_district_state_upper_value']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_district_state_upper_value']['expose']['operator_id'] = 'field_district_state_upper_value_op';
  $handler->display->display_options['filters']['field_district_state_upper_value']['expose']['label'] = 'State upper district';
  $handler->display->display_options['filters']['field_district_state_upper_value']['expose']['operator'] = 'field_district_state_upper_value_op';
  $handler->display->display_options['filters']['field_district_state_upper_value']['expose']['identifier'] = 'field_district_state_upper_value';
  $handler->display->display_options['filters']['field_district_state_upper_value']['expose']['required'] = 0;
  $handler->display->display_options['filters']['field_district_state_upper_value']['expose']['multiple'] = FALSE;
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
  $handler->display->display_options['filters']['distance']['exposed'] = TRUE;
  $handler->display->display_options['filters']['distance']['expose']['operator_id'] = 'distance_op';
  $handler->display->display_options['filters']['distance']['expose']['label'] = 'Distance / Proximity';
  $handler->display->display_options['filters']['distance']['expose']['operator'] = 'distance_op';
  $handler->display->display_options['filters']['distance']['expose']['identifier'] = 'distance';
  $handler->display->display_options['filters']['distance']['expose']['multiple'] = FALSE;
  $handler->display->display_options['filters']['distance']['expose']['gmap_macro'] = array(
    'default' => '[gmap ]',
  );
  $handler->display->display_options['filters']['distance']['expose']['user_location_choose'] = array(
    'default' => FALSE,
  );
  $handler->display->display_options['filters']['distance']['origin'] = 'latlon_gmap';

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
    t('field_site'),
    t('field_course'),
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
    t('Federal district'),
    t('State lower district'),
    t('State upper district'),
    t('Users'),
    t('Description'),
    t('Special projects'),
    t('Demographic'),
    t('Hours'),
    t('Evaluation Form'),
    t('Issues addressed'),
    t('Max students'),
    t('Organization type'),
    t('Phone number'),
    t('Risk Identification'),
    t('Signup form'),
    t('Site has special requirements'),
    t('Site special requirements'),
    t('Site Tour'),
    t('Social network page'),
    t('Special site instructions'),
    t('Tags'),
    t('Training & orientation'),
    t('Minimum hours'),
    t('Languages'),
    t('Restricted to'),
    t('Status'),
    t('Org. type'),
    t('Fields'),
    t('Had a student in'),
    t('Course Prefix'),
    t('Course Catalog Number'),
    t('Distance / Proximity'),
    t('[gmap ]'),
    t('Data report page'),
    t('Data export: CSV'),
    t('Data export: XLS'),
    t('Data export: DOC'),
  );
  $export['reports_sites'] = $view;

  return $export;
}
