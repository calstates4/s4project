<?php
/**
 * @file
 * s4_sites.views_default.inc
 */

/**
 * Implementation of hook_views_default_views().
 */
function s4_sites_views_default_views() {
  $export = array();

  $view = new view;
  $view->name = 'bookmarked_sites';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Bookmarked Sites';
  $view->core = 7;
  $view->api_version = '3.0-alpha1';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Bookmarked Sites';
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['query']['options']['query_comment'] = FALSE;
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '10';
  $handler->display->display_options['style_plugin'] = 'table';
  /* Relationship: Flags: bookmarks */
  $handler->display->display_options['relationships']['flag_content_rel']['id'] = 'flag_content_rel';
  $handler->display->display_options['relationships']['flag_content_rel']['table'] = 'node';
  $handler->display->display_options['relationships']['flag_content_rel']['field'] = 'flag_content_rel';
  $handler->display->display_options['relationships']['flag_content_rel']['flag'] = 'bookmarks';
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
  /* Field: Flags: Flag link */
  $handler->display->display_options['fields']['ops']['id'] = 'ops';
  $handler->display->display_options['fields']['ops']['table'] = 'flag_content';
  $handler->display->display_options['fields']['ops']['field'] = 'ops';
  $handler->display->display_options['fields']['ops']['relationship'] = 'flag_content_rel';
  $handler->display->display_options['fields']['ops']['label'] = 'Unbookmark';
  $handler->display->display_options['fields']['ops']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['ops']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['ops']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['ops']['alter']['external'] = 0;
  $handler->display->display_options['fields']['ops']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['ops']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['ops']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['ops']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['ops']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['ops']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['ops']['alter']['html'] = 0;
  $handler->display->display_options['fields']['ops']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['ops']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['ops']['hide_empty'] = 0;
  $handler->display->display_options['fields']['ops']['empty_zero'] = 0;
  /* Field: Content: Updated date */
  $handler->display->display_options['fields']['changed']['id'] = 'changed';
  $handler->display->display_options['fields']['changed']['table'] = 'node';
  $handler->display->display_options['fields']['changed']['field'] = 'changed';
  /* Sort criterion: Content: Title */
  $handler->display->display_options['sorts']['title']['id'] = 'title';
  $handler->display->display_options['sorts']['title']['table'] = 'node';
  $handler->display->display_options['sorts']['title']['field'] = 'title';
  $handler->display->display_options['sorts']['title']['order'] = 'DESC';
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

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page');
  $handler->display->display_options['defaults']['fields'] = FALSE;
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
  /* Field: Content: Updated date */
  $handler->display->display_options['fields']['changed']['id'] = 'changed';
  $handler->display->display_options['fields']['changed']['table'] = 'node';
  $handler->display->display_options['fields']['changed']['field'] = 'changed';
  /* Field: Flags: Flag link */
  $handler->display->display_options['fields']['ops']['id'] = 'ops';
  $handler->display->display_options['fields']['ops']['table'] = 'flag_content';
  $handler->display->display_options['fields']['ops']['field'] = 'ops';
  $handler->display->display_options['fields']['ops']['relationship'] = 'flag_content_rel';
  $handler->display->display_options['fields']['ops']['label'] = 'Unbookmark';
  $handler->display->display_options['fields']['ops']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['ops']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['ops']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['ops']['alter']['external'] = 0;
  $handler->display->display_options['fields']['ops']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['ops']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['ops']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['ops']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['ops']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['ops']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['ops']['alter']['html'] = 0;
  $handler->display->display_options['fields']['ops']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['ops']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['ops']['hide_empty'] = 0;
  $handler->display->display_options['fields']['ops']['empty_zero'] = 0;
  $handler->display->display_options['path'] = 'bookmarked-sites';

  /* Display: Block */
  $handler = $view->new_display('block', 'Block', 'block');
  $handler->display->display_options['defaults']['css_class'] = FALSE;
  $handler->display->display_options['css_class'] = 'bookmarks';
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '100';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'list';
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
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
  /* Field: Flags: Flag link */
  $handler->display->display_options['fields']['ops']['id'] = 'ops';
  $handler->display->display_options['fields']['ops']['table'] = 'flag_content';
  $handler->display->display_options['fields']['ops']['field'] = 'ops';
  $handler->display->display_options['fields']['ops']['relationship'] = 'flag_content_rel';
  $handler->display->display_options['fields']['ops']['label'] = '';
  $handler->display->display_options['fields']['ops']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['ops']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['ops']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['ops']['alter']['external'] = 0;
  $handler->display->display_options['fields']['ops']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['ops']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['ops']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['ops']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['ops']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['ops']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['ops']['alter']['html'] = 0;
  $handler->display->display_options['fields']['ops']['element_label_colon'] = 0;
  $handler->display->display_options['fields']['ops']['element_default_classes'] = 0;
  $handler->display->display_options['fields']['ops']['hide_empty'] = 0;
  $handler->display->display_options['fields']['ops']['empty_zero'] = 0;
  $translatables['bookmarked_sites'] = array(
    t('Master'),
    t('Bookmarked Sites'),
    t('more'),
    t('Apply'),
    t('Reset'),
    t('Sort by'),
    t('Asc'),
    t('Desc'),
    t('Items per page'),
    t('- All -'),
    t('Offset'),
    t('flag'),
    t('Unbookmark'),
    t('Updated date'),
    t('Page'),
    t('Block'),
  );
  $export['bookmarked_sites'] = $view;

  $view = new view;
  $view->name = 'contact_records';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Site notes & forms';
  $view->core = 7;
  $view->api_version = '3.0-alpha1';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Files close to expiration';
  $handler->display->display_options['access']['type'] = 'type_role';
  $handler->display->display_options['access']['role'] = array(
    3 => '3',
    4 => '4',
  );
  $handler->display->display_options['access']['node_type'] = 'site';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['query']['options']['query_comment'] = FALSE;
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '20';
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['columns'] = array(
    'created' => 'created',
    'field_expiration_date' => 'field_expiration_date',
    'title' => 'title',
    'field_file_category' => 'field_file_category',
    'field_files' => 'field_files',
  );
  $handler->display->display_options['style_options']['default'] = 'created';
  $handler->display->display_options['style_options']['info'] = array(
    'created' => array(
      'sortable' => 1,
      'default_sort_order' => 'desc',
      'align' => '',
      'separator' => '',
    ),
    'field_expiration_date' => array(
      'sortable' => 1,
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
    'field_file_category' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
    ),
    'field_files' => array(
      'align' => '',
      'separator' => '',
    ),
  );
  $handler->display->display_options['style_options']['override'] = 1;
  $handler->display->display_options['style_options']['sticky'] = 0;
  $handler->display->display_options['style_options']['empty_table'] = 0;
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
  /* Field: Content: Contact tags */
  $handler->display->display_options['fields']['field_contact_tags']['id'] = 'field_contact_tags';
  $handler->display->display_options['fields']['field_contact_tags']['table'] = 'field_data_field_contact_tags';
  $handler->display->display_options['fields']['field_contact_tags']['field'] = 'field_contact_tags';
  $handler->display->display_options['fields']['field_contact_tags']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_contact_tags']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_contact_tags']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_contact_tags']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_contact_tags']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_contact_tags']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_contact_tags']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_contact_tags']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_contact_tags']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_contact_tags']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_contact_tags']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_contact_tags']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['field_contact_tags']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_contact_tags']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_contact_tags']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_contact_tags']['group_rows'] = 1;
  $handler->display->display_options['fields']['field_contact_tags']['delta_offset'] = '0';
  $handler->display->display_options['fields']['field_contact_tags']['delta_reversed'] = 0;
  $handler->display->display_options['fields']['field_contact_tags']['field_api_classes'] = 0;
  /* Field: Content: Contact type */
  $handler->display->display_options['fields']['field_contact']['id'] = 'field_contact';
  $handler->display->display_options['fields']['field_contact']['table'] = 'field_data_field_contact';
  $handler->display->display_options['fields']['field_contact']['field'] = 'field_contact';
  $handler->display->display_options['fields']['field_contact']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_contact']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_contact']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_contact']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_contact']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_contact']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_contact']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_contact']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_contact']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_contact']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_contact']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_contact']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['field_contact']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_contact']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_contact']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_contact']['field_api_classes'] = 0;
  /* Field: Content: Files */
  $handler->display->display_options['fields']['field_files']['id'] = 'field_files';
  $handler->display->display_options['fields']['field_files']['table'] = 'field_data_field_files';
  $handler->display->display_options['fields']['field_files']['field'] = 'field_files';
  $handler->display->display_options['fields']['field_files']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_files']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_files']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_files']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_files']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_files']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_files']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_files']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_files']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_files']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_files']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_files']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['field_files']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_files']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_files']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_files']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_files']['group_rows'] = 1;
  $handler->display->display_options['fields']['field_files']['delta_offset'] = '0';
  $handler->display->display_options['fields']['field_files']['delta_reversed'] = 0;
  $handler->display->display_options['fields']['field_files']['field_api_classes'] = 0;
  /* Sort criterion: Content: Post date */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'node';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
  /* Contextual filter: Content: Site (field_site) */
  $handler->display->display_options['arguments']['field_site_nid']['id'] = 'field_site_nid';
  $handler->display->display_options['arguments']['field_site_nid']['table'] = 'field_data_field_site';
  $handler->display->display_options['arguments']['field_site_nid']['field'] = 'field_site_nid';
  $handler->display->display_options['arguments']['field_site_nid']['default_action'] = 'default';
  $handler->display->display_options['arguments']['field_site_nid']['default_argument_type'] = 'node';
  $handler->display->display_options['arguments']['field_site_nid']['default_argument_skip_url'] = 1;
  $handler->display->display_options['arguments']['field_site_nid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['field_site_nid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['field_site_nid']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['field_site_nid']['break_phrase'] = 0;
  $handler->display->display_options['arguments']['field_site_nid']['not'] = 0;
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
    'contact_record' => 'contact_record',
  );
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

  /* Display: Files close to expiration */
  $handler = $view->new_display('block', 'Files close to expiration', 'block_3');
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['columns'] = array(
    'created' => 'created',
    'field_expiration_date' => 'field_expiration_date',
    'field_site' => 'field_site',
    'title' => 'title',
    'field_file_category' => 'field_file_category',
    'field_files' => 'field_files',
  );
  $handler->display->display_options['style_options']['default'] = 'created';
  $handler->display->display_options['style_options']['info'] = array(
    'created' => array(
      'sortable' => 0,
      'default_sort_order' => 'desc',
      'align' => '',
      'separator' => '',
    ),
    'field_expiration_date' => array(
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
    'title' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
    ),
    'field_file_category' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
    ),
    'field_files' => array(
      'align' => '',
      'separator' => '',
    ),
  );
  $handler->display->display_options['style_options']['override'] = 1;
  $handler->display->display_options['style_options']['sticky'] = 0;
  $handler->display->display_options['style_options']['empty_table'] = 0;
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Expiration date */
  $handler->display->display_options['fields']['field_expiration_date']['id'] = 'field_expiration_date';
  $handler->display->display_options['fields']['field_expiration_date']['table'] = 'field_data_field_expiration_date';
  $handler->display->display_options['fields']['field_expiration_date']['field'] = 'field_expiration_date';
  $handler->display->display_options['fields']['field_expiration_date']['label'] = 'Expires';
  $handler->display->display_options['fields']['field_expiration_date']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_expiration_date']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_expiration_date']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_expiration_date']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_expiration_date']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_expiration_date']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_expiration_date']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_expiration_date']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_expiration_date']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_expiration_date']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_expiration_date']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_expiration_date']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['field_expiration_date']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_expiration_date']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_expiration_date']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_expiration_date']['settings'] = array(
    'format_type' => 'long',
    'fromto' => 'both',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
    'show_repeat_rule' => 'show',
  );
  $handler->display->display_options['fields']['field_expiration_date']['field_api_classes'] = 0;
  /* Field: Content: Site */
  $handler->display->display_options['fields']['field_site']['id'] = 'field_site';
  $handler->display->display_options['fields']['field_site']['table'] = 'field_data_field_site';
  $handler->display->display_options['fields']['field_site']['field'] = 'field_site';
  $handler->display->display_options['fields']['field_site']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_site']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_site']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_site']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_site']['alter']['replace_spaces'] = 0;
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
  $handler->display->display_options['fields']['field_site']['field_api_classes'] = 0;
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
  /* Field: Content: File category */
  $handler->display->display_options['fields']['field_file_category']['id'] = 'field_file_category';
  $handler->display->display_options['fields']['field_file_category']['table'] = 'field_data_field_file_category';
  $handler->display->display_options['fields']['field_file_category']['field'] = 'field_file_category';
  $handler->display->display_options['fields']['field_file_category']['label'] = 'Category';
  $handler->display->display_options['fields']['field_file_category']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_file_category']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_file_category']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_file_category']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_file_category']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_file_category']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_file_category']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_file_category']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_file_category']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_file_category']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_file_category']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_file_category']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['field_file_category']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_file_category']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_file_category']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_file_category']['field_api_classes'] = 0;
  /* Field: Content: Files */
  $handler->display->display_options['fields']['field_files']['id'] = 'field_files';
  $handler->display->display_options['fields']['field_files']['table'] = 'field_data_field_files';
  $handler->display->display_options['fields']['field_files']['field'] = 'field_files';
  $handler->display->display_options['fields']['field_files']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_files']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_files']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_files']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_files']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_files']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_files']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_files']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_files']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_files']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_files']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_files']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['field_files']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_files']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_files']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_files']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_files']['group_rows'] = 1;
  $handler->display->display_options['fields']['field_files']['delta_offset'] = '0';
  $handler->display->display_options['fields']['field_files']['delta_reversed'] = 0;
  $handler->display->display_options['fields']['field_files']['field_api_classes'] = 0;
  $handler->display->display_options['defaults']['sorts'] = FALSE;
  /* Sort criterion: Content: Expiration date (field_expiration_date) */
  $handler->display->display_options['sorts']['field_expiration_date_value']['id'] = 'field_expiration_date_value';
  $handler->display->display_options['sorts']['field_expiration_date_value']['table'] = 'field_data_field_expiration_date';
  $handler->display->display_options['sorts']['field_expiration_date_value']['field'] = 'field_expiration_date_value';
  $handler->display->display_options['sorts']['field_expiration_date_value']['order'] = 'DESC';
  /* Sort criterion: Content: Post date */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'node';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
  $handler->display->display_options['defaults']['arguments'] = FALSE;
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
    'file' => 'file',
  );

  /* Display: Site notes */
  $handler = $view->new_display('page', 'Site notes', 'page_1');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Site notes';
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Contextual filter: Content: Site (field_site) */
  $handler->display->display_options['arguments']['field_site_nid']['id'] = 'field_site_nid';
  $handler->display->display_options['arguments']['field_site_nid']['table'] = 'field_data_field_site';
  $handler->display->display_options['arguments']['field_site_nid']['field'] = 'field_site_nid';
  $handler->display->display_options['arguments']['field_site_nid']['default_action'] = 'default';
  $handler->display->display_options['arguments']['field_site_nid']['default_argument_type'] = 'node';
  $handler->display->display_options['arguments']['field_site_nid']['default_argument_skip_url'] = 1;
  $handler->display->display_options['arguments']['field_site_nid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['field_site_nid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['field_site_nid']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['field_site_nid']['break_phrase'] = 0;
  $handler->display->display_options['arguments']['field_site_nid']['not'] = 0;
  $handler->display->display_options['path'] = 'node/%/notes';
  $handler->display->display_options['menu']['type'] = 'tab';
  $handler->display->display_options['menu']['title'] = 'Notes';
  $handler->display->display_options['menu']['weight'] = '2';

  /* Display: Site forms */
  $handler = $view->new_display('page', 'Site forms', 'page_2');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Site forms';
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = 'Name';
  $handler->display->display_options['fields']['title']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['title']['alter']['text'] = '[title] [timestamp]';
  $handler->display->display_options['fields']['title']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['title']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['title']['alter']['external'] = 0;
  $handler->display->display_options['fields']['title']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['title']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['title']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['title']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['title']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['title']['alter']['html'] = 0;
  $handler->display->display_options['fields']['title']['element_label_colon'] = 0;
  $handler->display->display_options['fields']['title']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['title']['hide_empty'] = 0;
  $handler->display->display_options['fields']['title']['empty_zero'] = 0;
  $handler->display->display_options['fields']['title']['hide_alter_empty'] = 0;
  $handler->display->display_options['fields']['title']['link_to_node'] = 1;
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
  /* Field: Content: Expiration date */
  $handler->display->display_options['fields']['field_expiration_date']['id'] = 'field_expiration_date';
  $handler->display->display_options['fields']['field_expiration_date']['table'] = 'field_data_field_expiration_date';
  $handler->display->display_options['fields']['field_expiration_date']['field'] = 'field_expiration_date';
  $handler->display->display_options['fields']['field_expiration_date']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_expiration_date']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_expiration_date']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_expiration_date']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_expiration_date']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_expiration_date']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_expiration_date']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_expiration_date']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_expiration_date']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_expiration_date']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_expiration_date']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_expiration_date']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_expiration_date']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['field_expiration_date']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_expiration_date']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_expiration_date']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_expiration_date']['hide_alter_empty'] = 0;
  $handler->display->display_options['fields']['field_expiration_date']['settings'] = array(
    'format_type' => 'long',
    'fromto' => 'both',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
    'show_repeat_rule' => 'show',
  );
  $handler->display->display_options['fields']['field_expiration_date']['field_api_classes'] = 0;
  /* Field: Content: Files */
  $handler->display->display_options['fields']['field_files']['id'] = 'field_files';
  $handler->display->display_options['fields']['field_files']['table'] = 'field_data_field_files';
  $handler->display->display_options['fields']['field_files']['field'] = 'field_files';
  $handler->display->display_options['fields']['field_files']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_files']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_files']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_files']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_files']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_files']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_files']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_files']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_files']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_files']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_files']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_files']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['field_files']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_files']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_files']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_files']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_files']['group_rows'] = 1;
  $handler->display->display_options['fields']['field_files']['delta_offset'] = '0';
  $handler->display->display_options['fields']['field_files']['delta_reversed'] = 0;
  $handler->display->display_options['fields']['field_files']['field_api_classes'] = 0;
  /* Field: Content: File category */
  $handler->display->display_options['fields']['field_file_category']['id'] = 'field_file_category';
  $handler->display->display_options['fields']['field_file_category']['table'] = 'field_data_field_file_category';
  $handler->display->display_options['fields']['field_file_category']['field'] = 'field_file_category';
  $handler->display->display_options['fields']['field_file_category']['label'] = 'Category';
  $handler->display->display_options['fields']['field_file_category']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_file_category']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_file_category']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_file_category']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_file_category']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_file_category']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_file_category']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_file_category']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_file_category']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_file_category']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_file_category']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_file_category']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_file_category']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['field_file_category']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_file_category']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_file_category']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_file_category']['hide_alter_empty'] = 0;
  $handler->display->display_options['fields']['field_file_category']['type'] = 'taxonomy_term_reference_plain';
  $handler->display->display_options['fields']['field_file_category']['field_api_classes'] = 0;
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
    'file' => 'file',
  );
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
  $handler->display->display_options['path'] = 'node/%/forms';
  $handler->display->display_options['menu']['type'] = 'tab';
  $handler->display->display_options['menu']['title'] = 'Forms';
  $handler->display->display_options['menu']['weight'] = '3';
  $translatables['contact_records'] = array(
    t('Master'),
    t('Files close to expiration'),
    t('more'),
    t('Apply'),
    t('Reset'),
    t('Sort by'),
    t('Asc'),
    t('Desc'),
    t('Items per page'),
    t('- All -'),
    t('Offset'),
    t('Date'),
    t('Contact tags'),
    t('Contact type'),
    t('Files'),
    t('All'),
    t('Search'),
    t('Expires'),
    t('Site'),
    t('Category'),
    t('Site notes'),
    t('Site forms'),
    t('Name'),
    t('[title] [timestamp]'),
    t('Expiration date'),
  );
  $export['contact_records'] = $view;

  $view = new view;
  $view->name = 'email_site_contacts';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Email: Site coordinators';
  $view->core = 7;
  $view->api_version = '3.0-alpha1';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Site coordinators';
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
    'field_csu_facility_tid' => array(
      'more_options' => array(
        'bef_filter_description' => '',
      ),
    ),
    'tid' => array(
      'bef_format' => 'bef',
      'more_options' => array(
        'bef_select_all_none' => 0,
        'bef_collapsible' => 0,
        'bef_filter_description' => '',
      ),
    ),
    'field_term_nid' => array(
      'bef_format' => 'default',
      'more_options' => array(
        'bef_select_all_none' => 0,
        'bef_collapsible' => 0,
        'bef_filter_description' => '',
      ),
    ),
    'created' => array(
      'more_options' => array(
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
  $handler->display->display_options['style_options']['columns'] = array(
    'views_bulk_operations' => 'views_bulk_operations',
    'title' => 'title',
    'field_email' => 'field_email',
    'edit_node' => 'edit_node',
    'title_1' => 'title_1',
    'nothing' => 'nothing',
    'title_2' => 'title_2',
    'field_first_name' => 'field_first_name',
    'field_last_name' => 'field_last_name',
  );
  $handler->display->display_options['style_options']['default'] = '-1';
  $handler->display->display_options['style_options']['info'] = array(
    'views_bulk_operations' => array(
      'align' => '',
      'separator' => '',
    ),
    'title' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
    ),
    'field_email' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
    ),
    'edit_node' => array(
      'align' => '',
      'separator' => '',
    ),
    'title_1' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
    ),
    'nothing' => array(
      'align' => '',
      'separator' => '',
    ),
    'title_2' => array(
      'sortable' => 0,
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
    'field_last_name' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
    ),
  );
  $handler->display->display_options['style_options']['override'] = 1;
  $handler->display->display_options['style_options']['sticky'] = 0;
  $handler->display->display_options['style_options']['empty_table'] = 0;
  /* Relationship: Content: Site (field_site) */
  $handler->display->display_options['relationships']['field_site_nid']['id'] = 'field_site_nid';
  $handler->display->display_options['relationships']['field_site_nid']['table'] = 'field_data_field_site';
  $handler->display->display_options['relationships']['field_site_nid']['field'] = 'field_site_nid';
  $handler->display->display_options['relationships']['field_site_nid']['required'] = 0;
  $handler->display->display_options['relationships']['field_site_nid']['delta'] = '-1';
  /* Relationship: Content: Coordinator (field_coordinator) */
  $handler->display->display_options['relationships']['field_coordinator_nid']['id'] = 'field_coordinator_nid';
  $handler->display->display_options['relationships']['field_coordinator_nid']['table'] = 'field_data_field_coordinator';
  $handler->display->display_options['relationships']['field_coordinator_nid']['field'] = 'field_coordinator_nid';
  $handler->display->display_options['relationships']['field_coordinator_nid']['required'] = 0;
  $handler->display->display_options['relationships']['field_coordinator_nid']['delta'] = '-1';
  /* Relationship: Content: Course (field_course) */
  $handler->display->display_options['relationships']['field_course_nid']['id'] = 'field_course_nid';
  $handler->display->display_options['relationships']['field_course_nid']['table'] = 'field_data_field_course';
  $handler->display->display_options['relationships']['field_course_nid']['field'] = 'field_course_nid';
  $handler->display->display_options['relationships']['field_course_nid']['relationship'] = 'field_coordinator_nid';
  $handler->display->display_options['relationships']['field_course_nid']['required'] = 0;
  $handler->display->display_options['relationships']['field_course_nid']['delta'] = '-1';
  /* Field: Content: Bulk operations */
  $handler->display->display_options['fields']['views_bulk_operations']['id'] = 'views_bulk_operations';
  $handler->display->display_options['fields']['views_bulk_operations']['table'] = 'node';
  $handler->display->display_options['fields']['views_bulk_operations']['field'] = 'views_bulk_operations';
  $handler->display->display_options['fields']['views_bulk_operations']['label'] = 'Send email';
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
    's4_core_email_site_coordinator_action' => array(
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
  /* Field: Content: Email address */
  $handler->display->display_options['fields']['field_email']['id'] = 'field_email';
  $handler->display->display_options['fields']['field_email']['table'] = 'field_data_field_email';
  $handler->display->display_options['fields']['field_email']['field'] = 'field_email';
  $handler->display->display_options['fields']['field_email']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_email']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_email']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_email']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_email']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_email']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_email']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_email']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_email']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_email']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_email']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_email']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['field_email']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_email']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_email']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_email']['type'] = 'email_default';
  $handler->display->display_options['fields']['field_email']['field_api_classes'] = 0;
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
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title_1']['id'] = 'title_1';
  $handler->display->display_options['fields']['title_1']['table'] = 'node';
  $handler->display->display_options['fields']['title_1']['field'] = 'title';
  $handler->display->display_options['fields']['title_1']['exclude'] = TRUE;
  $handler->display->display_options['fields']['title_1']['alter']['alter_text'] = 1;
  $handler->display->display_options['fields']['title_1']['alter']['text'] = 'view';
  $handler->display->display_options['fields']['title_1']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['title_1']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['title_1']['alter']['external'] = 0;
  $handler->display->display_options['fields']['title_1']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['title_1']['alter']['trim_whitespace'] = 0;
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
  $handler->display->display_options['fields']['title_1']['hide_alter_empty'] = 0;
  $handler->display->display_options['fields']['title_1']['link_to_node'] = 1;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title_2']['id'] = 'title_2';
  $handler->display->display_options['fields']['title_2']['table'] = 'node';
  $handler->display->display_options['fields']['title_2']['field'] = 'title';
  $handler->display->display_options['fields']['title_2']['relationship'] = 'field_site_nid';
  $handler->display->display_options['fields']['title_2']['label'] = 'Site';
  $handler->display->display_options['fields']['title_2']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['title_2']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['title_2']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['title_2']['alter']['external'] = 0;
  $handler->display->display_options['fields']['title_2']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['title_2']['alter']['trim_whitespace'] = 0;
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
  $handler->display->display_options['fields']['title_2']['hide_alter_empty'] = 0;
  $handler->display->display_options['fields']['title_2']['link_to_node'] = 1;
  /* Field: Global: Custom text */
  $handler->display->display_options['fields']['nothing']['id'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['table'] = 'views';
  $handler->display->display_options['fields']['nothing']['field'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['label'] = 'Operations';
  $handler->display->display_options['fields']['nothing']['alter']['text'] = '[title_1] | [edit_node]';
  $handler->display->display_options['fields']['nothing']['alter']['make_link'] = 0;
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
  /* Sort criterion: Content: Title */
  $handler->display->display_options['sorts']['title']['id'] = 'title';
  $handler->display->display_options['sorts']['title']['table'] = 'node';
  $handler->display->display_options['sorts']['title']['field'] = 'title';
  $handler->display->display_options['sorts']['title']['order'] = 'DESC';
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
    'coordinator' => 'coordinator',
  );
  /* Filter criterion: Content: Post date */
  $handler->display->display_options['filters']['created']['id'] = 'created';
  $handler->display->display_options['filters']['created']['table'] = 'node';
  $handler->display->display_options['filters']['created']['field'] = 'created';
  $handler->display->display_options['filters']['created']['relationship'] = 'field_coordinator_nid';
  $handler->display->display_options['filters']['created']['operator'] = '>=';
  $handler->display->display_options['filters']['created']['exposed'] = TRUE;
  $handler->display->display_options['filters']['created']['expose']['operator_id'] = 'created_op';
  $handler->display->display_options['filters']['created']['expose']['label'] = 'Who had at least one student since';
  $handler->display->display_options['filters']['created']['expose']['operator'] = 'created_op';
  $handler->display->display_options['filters']['created']['expose']['identifier'] = 'created';
  $handler->display->display_options['filters']['created']['expose']['multiple'] = FALSE;

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page');
  $handler->display->display_options['path'] = 'email/coordinators';
  $handler->display->display_options['menu']['type'] = 'default tab';
  $handler->display->display_options['menu']['title'] = 'Coordinators';
  $handler->display->display_options['menu']['weight'] = '0';
  $handler->display->display_options['tab_options']['type'] = 'normal';
  $handler->display->display_options['tab_options']['title'] = 'Contacts';
  $handler->display->display_options['tab_options']['weight'] = '0';
  $translatables['email_site_contacts'] = array(
    t('Master'),
    t('Site coordinators'),
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
    t('field_coordinator'),
    t('field_course'),
    t('Send email'),
    t('First Name'),
    t('Last Name'),
    t('Email address'),
    t('Edit link'),
    t('Title'),
    t('view'),
    t('Site'),
    t('Operations'),
    t('[title_1] | [edit_node]'),
    t('Who had at least one student since'),
    t('Page'),
  );
  $export['email_site_contacts'] = $view;

  $view = new view;
  $view->name = 'location_gmap';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Site Locations Map';
  $view->core = 7;
  $view->api_version = '3.0-alpha1';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Map';
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['query']['options']['query_comment'] = FALSE;
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '500';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['style_plugin'] = 'gmap';
  $handler->display->display_options['style_options']['macro'] = '[gmap width=462px |height=270px ]';
  $handler->display->display_options['style_options']['markertype'] = '';
  $handler->display->display_options['style_options']['latfield'] = 'title';
  $handler->display->display_options['style_options']['lonfield'] = 'title';
  $handler->display->display_options['style_options']['markerfield'] = 'title';
  $handler->display->display_options['style_options']['enablermt'] = 0;
  $handler->display->display_options['style_options']['rmtfield'] = 'title';
  $handler->display->display_options['style_options']['tooltipfield'] = 'title';
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['exposed_block'] = TRUE;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['title']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['title']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['title']['alter']['external'] = 0;
  $handler->display->display_options['fields']['title']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['title']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = 0;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = 0;
  $handler->display->display_options['fields']['title']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['title']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['title']['alter']['html'] = 0;
  $handler->display->display_options['fields']['title']['element_type'] = 'h3';
  $handler->display->display_options['fields']['title']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['title']['element_default_classes'] = 0;
  $handler->display->display_options['fields']['title']['hide_empty'] = 0;
  $handler->display->display_options['fields']['title']['empty_zero'] = 0;
  $handler->display->display_options['fields']['title']['link_to_node'] = 1;
  /* Field: Content: Edit link */
  $handler->display->display_options['fields']['edit_node']['id'] = 'edit_node';
  $handler->display->display_options['fields']['edit_node']['table'] = 'node';
  $handler->display->display_options['fields']['edit_node']['field'] = 'edit_node';
  $handler->display->display_options['fields']['edit_node']['label'] = '';
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
  $handler->display->display_options['fields']['edit_node']['element_label_colon'] = 0;
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

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page');
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'gmap';
  $handler->display->display_options['style_options']['macro'] = '[gmap width=100% |height=600px ]';
  $handler->display->display_options['style_options']['markertype'] = '';
  $handler->display->display_options['style_options']['latfield'] = 'title';
  $handler->display->display_options['style_options']['lonfield'] = 'title';
  $handler->display->display_options['style_options']['markerfield'] = 'title';
  $handler->display->display_options['style_options']['enablermt'] = 0;
  $handler->display->display_options['style_options']['rmtfield'] = 'title';
  $handler->display->display_options['style_options']['tooltipfield'] = 'title';
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['path'] = 'map';

  /* Display: Site Map */
  $handler = $view->new_display('block', 'Site Map', 'block_1');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '500';
  $handler->display->display_options['pager']['options']['offset'] = '0';

  /* Display: Site Small Map */
  $handler = $view->new_display('block', 'Site Small Map', 'block_2');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'gmap';
  $handler->display->display_options['style_options']['macro'] = '[gmap width=100% |height=270px ]';
  $handler->display->display_options['style_options']['markertype'] = '';
  $handler->display->display_options['style_options']['latfield'] = 'title';
  $handler->display->display_options['style_options']['lonfield'] = 'title';
  $handler->display->display_options['style_options']['markerfield'] = 'title';
  $handler->display->display_options['style_options']['enablermt'] = 0;
  $handler->display->display_options['style_options']['rmtfield'] = 'title';
  $handler->display->display_options['style_options']['tooltipfield'] = 'title';
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $translatables['location_gmap'] = array(
    t('Master'),
    t('Map'),
    t('more'),
    t('Apply'),
    t('Reset'),
    t('Sort by'),
    t('Asc'),
    t('Desc'),
    t('City'),
    t('Search'),
    t('Page'),
    t('Site Map'),
    t('Site Small Map'),
  );
  $export['location_gmap'] = $view;

  $view = new view;
  $view->name = 'site_coordinators';
  $view->description = 'Listings of site coordinators';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Site coordinators';
  $view->core = 7;
  $view->api_version = '3.0-alpha1';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Site Staff';
  $handler->display->display_options['access']['type'] = 'type_role';
  $handler->display->display_options['access']['role'] = array(
    3 => '3',
    4 => '4',
  );
  $handler->display->display_options['access']['node_type'] = 'site';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['query']['options']['query_comment'] = FALSE;
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '15';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['pager']['options']['id'] = '0';
  $handler->display->display_options['pager']['options']['expose']['items_per_page_options_all'] = 0;
  $handler->display->display_options['style_plugin'] = 'table';
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = 'Name';
  $handler->display->display_options['fields']['title']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['title']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['title']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['title']['alter']['external'] = 0;
  $handler->display->display_options['fields']['title']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['title']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = 0;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = 0;
  $handler->display->display_options['fields']['title']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['title']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['title']['alter']['html'] = 0;
  $handler->display->display_options['fields']['title']['element_type'] = 'h3';
  $handler->display->display_options['fields']['title']['element_class'] = 'coordinator-name';
  $handler->display->display_options['fields']['title']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['title']['element_default_classes'] = 0;
  $handler->display->display_options['fields']['title']['hide_empty'] = 0;
  $handler->display->display_options['fields']['title']['empty_zero'] = 0;
  $handler->display->display_options['fields']['title']['link_to_node'] = 1;
  /* Field: Field: Restricted to */
  $handler->display->display_options['fields']['field_site_restrict']['id'] = 'field_site_restrict';
  $handler->display->display_options['fields']['field_site_restrict']['table'] = 'field_data_field_site_restrict';
  $handler->display->display_options['fields']['field_site_restrict']['field'] = 'field_site_restrict';
  $handler->display->display_options['fields']['field_site_restrict']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_site_restrict']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_site_restrict']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_site_restrict']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_site_restrict']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_site_restrict']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_site_restrict']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_site_restrict']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_site_restrict']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_site_restrict']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_site_restrict']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_site_restrict']['element_label_colon'] = 0;
  $handler->display->display_options['fields']['field_site_restrict']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_site_restrict']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_site_restrict']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_site_restrict']['group_rows'] = 1;
  $handler->display->display_options['fields']['field_site_restrict']['delta_offset'] = '0';
  $handler->display->display_options['fields']['field_site_restrict']['delta_reversed'] = 0;
  $handler->display->display_options['fields']['field_site_restrict']['field_api_classes'] = 0;
  /* Field: Content: Phone number */
  $handler->display->display_options['fields']['field_phone']['id'] = 'field_phone';
  $handler->display->display_options['fields']['field_phone']['table'] = 'field_data_field_phone';
  $handler->display->display_options['fields']['field_phone']['field'] = 'field_phone';
  $handler->display->display_options['fields']['field_phone']['label'] = 'Phone';
  $handler->display->display_options['fields']['field_phone']['alter']['alter_text'] = 0;
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
  $handler->display->display_options['fields']['field_phone']['type'] = 'local_phone_number';
  $handler->display->display_options['fields']['field_phone']['field_api_classes'] = 0;
  /* Sort criterion: Content: Title */
  $handler->display->display_options['sorts']['title']['id'] = 'title';
  $handler->display->display_options['sorts']['title']['table'] = 'node';
  $handler->display->display_options['sorts']['title']['field'] = 'title';
  $handler->display->display_options['sorts']['title']['order'] = 'DESC';
  /* Contextual filter: Content: Site (field_site) */
  $handler->display->display_options['arguments']['field_site_nid']['id'] = 'field_site_nid';
  $handler->display->display_options['arguments']['field_site_nid']['table'] = 'field_data_field_site';
  $handler->display->display_options['arguments']['field_site_nid']['field'] = 'field_site_nid';
  $handler->display->display_options['arguments']['field_site_nid']['default_action'] = 'default';
  $handler->display->display_options['arguments']['field_site_nid']['default_argument_type'] = 'node';
  $handler->display->display_options['arguments']['field_site_nid']['default_argument_skip_url'] = 0;
  $handler->display->display_options['arguments']['field_site_nid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['field_site_nid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['field_site_nid']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['field_site_nid']['break_phrase'] = 0;
  $handler->display->display_options['arguments']['field_site_nid']['not'] = 0;
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
    'coordinator' => 'coordinator',
  );

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page_1');
  $handler->display->display_options['defaults']['header'] = FALSE;
  /* Header: Global: Text area */
  $handler->display->display_options['header']['area']['id'] = 'area';
  $handler->display->display_options['header']['area']['table'] = 'views';
  $handler->display->display_options['header']['area']['field'] = 'area';
  $handler->display->display_options['header']['area']['empty'] = FALSE;
  $handler->display->display_options['header']['area']['content'] = '<p class="intro">Select a coordinator who will be working with you during your service.</p>';
  $handler->display->display_options['header']['area']['format'] = 'full_html';
  $handler->display->display_options['defaults']['fields'] = FALSE;
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
  /* Field: Field: Restricted to */
  $handler->display->display_options['fields']['field_site_restrict']['id'] = 'field_site_restrict';
  $handler->display->display_options['fields']['field_site_restrict']['table'] = 'field_data_field_site_restrict';
  $handler->display->display_options['fields']['field_site_restrict']['field'] = 'field_site_restrict';
  $handler->display->display_options['fields']['field_site_restrict']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_site_restrict']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_site_restrict']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_site_restrict']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_site_restrict']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_site_restrict']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_site_restrict']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_site_restrict']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_site_restrict']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_site_restrict']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_site_restrict']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_site_restrict']['element_label_colon'] = 0;
  $handler->display->display_options['fields']['field_site_restrict']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_site_restrict']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_site_restrict']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_site_restrict']['group_rows'] = 1;
  $handler->display->display_options['fields']['field_site_restrict']['delta_offset'] = '0';
  $handler->display->display_options['fields']['field_site_restrict']['delta_reversed'] = 0;
  $handler->display->display_options['fields']['field_site_restrict']['field_api_classes'] = 0;
  /* Field: Content: Phone number */
  $handler->display->display_options['fields']['field_phone']['id'] = 'field_phone';
  $handler->display->display_options['fields']['field_phone']['table'] = 'field_data_field_phone';
  $handler->display->display_options['fields']['field_phone']['field'] = 'field_phone';
  $handler->display->display_options['fields']['field_phone']['label'] = 'Phone';
  $handler->display->display_options['fields']['field_phone']['alter']['alter_text'] = 0;
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
  $handler->display->display_options['fields']['field_phone']['type'] = 'local_phone_number';
  $handler->display->display_options['fields']['field_phone']['field_api_classes'] = 0;
  /* Field: Signup: User select coordinator */
  $handler->display->display_options['fields']['faculty_coordinator_select']['id'] = 'faculty_coordinator_select';
  $handler->display->display_options['fields']['faculty_coordinator_select']['table'] = 's4_signup';
  $handler->display->display_options['fields']['faculty_coordinator_select']['field'] = 'faculty_coordinator_select';
  $handler->display->display_options['fields']['faculty_coordinator_select']['label'] = 'Select';
  $handler->display->display_options['fields']['faculty_coordinator_select']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['faculty_coordinator_select']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['faculty_coordinator_select']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['faculty_coordinator_select']['alter']['external'] = 0;
  $handler->display->display_options['fields']['faculty_coordinator_select']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['faculty_coordinator_select']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['faculty_coordinator_select']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['faculty_coordinator_select']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['faculty_coordinator_select']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['faculty_coordinator_select']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['faculty_coordinator_select']['alter']['html'] = 0;
  $handler->display->display_options['fields']['faculty_coordinator_select']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['faculty_coordinator_select']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['faculty_coordinator_select']['hide_empty'] = 0;
  $handler->display->display_options['fields']['faculty_coordinator_select']['empty_zero'] = 0;
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Contextual filter: Content: Site (field_site) */
  $handler->display->display_options['arguments']['field_site_nid']['id'] = 'field_site_nid';
  $handler->display->display_options['arguments']['field_site_nid']['table'] = 'field_data_field_site';
  $handler->display->display_options['arguments']['field_site_nid']['field'] = 'field_site_nid';
  $handler->display->display_options['arguments']['field_site_nid']['default_action'] = 'default';
  $handler->display->display_options['arguments']['field_site_nid']['default_argument_type'] = 'node';
  $handler->display->display_options['arguments']['field_site_nid']['default_argument_skip_url'] = 0;
  $handler->display->display_options['arguments']['field_site_nid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['field_site_nid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['field_site_nid']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['field_site_nid']['break_phrase'] = 0;
  $handler->display->display_options['arguments']['field_site_nid']['not'] = 0;
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
    'coordinator' => 'coordinator',
  );
  /* Filter criterion: Content: Students can register with this staff (field_staff_signup_available) */
  $handler->display->display_options['filters']['field_staff_signup_available_value']['id'] = 'field_staff_signup_available_value';
  $handler->display->display_options['filters']['field_staff_signup_available_value']['table'] = 'field_data_field_staff_signup_available';
  $handler->display->display_options['filters']['field_staff_signup_available_value']['field'] = 'field_staff_signup_available_value';
  $handler->display->display_options['filters']['field_staff_signup_available_value']['value'] = array(
    1 => '1',
  );
  $handler->display->display_options['path'] = 'sites/%/coordinators';

  /* Display: Site staff tab */
  $handler = $view->new_display('page', 'Site staff tab', 'page_2');
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['columns'] = array(
    'field_last_name' => 'field_last_name',
    'field_first_name' => 'field_first_name',
    'field_phone' => 'field_phone',
    'field_email' => 'field_email',
    'field_site_restrict' => 'field_site_restrict',
    'field_staff_role' => 'field_staff_role',
    'field_signups_max' => 'field_signups_max',
    'edit_node' => 'edit_node',
    'view_node' => 'view_node',
    'nothing' => 'nothing',
  );
  $handler->display->display_options['style_options']['default'] = 'field_last_name';
  $handler->display->display_options['style_options']['info'] = array(
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
    'field_phone' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
    ),
    'field_email' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
    ),
    'field_site_restrict' => array(
      'align' => '',
      'separator' => '',
    ),
    'field_staff_role' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
    ),
    'field_signups_max' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
    ),
    'edit_node' => array(
      'align' => '',
      'separator' => '',
    ),
    'view_node' => array(
      'align' => '',
      'separator' => '',
    ),
    'nothing' => array(
      'align' => '',
      'separator' => '',
    ),
  );
  $handler->display->display_options['style_options']['override'] = 1;
  $handler->display->display_options['style_options']['sticky'] = 0;
  $handler->display->display_options['style_options']['empty_table'] = 0;
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
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
  /* Field: Content: Phone number */
  $handler->display->display_options['fields']['field_phone']['id'] = 'field_phone';
  $handler->display->display_options['fields']['field_phone']['table'] = 'field_data_field_phone';
  $handler->display->display_options['fields']['field_phone']['field'] = 'field_phone';
  $handler->display->display_options['fields']['field_phone']['label'] = 'Phone';
  $handler->display->display_options['fields']['field_phone']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_phone']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_phone']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_phone']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_phone']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_phone']['alter']['trim_whitespace'] = 0;
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
  $handler->display->display_options['fields']['field_phone']['hide_alter_empty'] = 0;
  $handler->display->display_options['fields']['field_phone']['click_sort_column'] = 'number';
  $handler->display->display_options['fields']['field_phone']['type'] = 's4_sites_local_phone_number';
  $handler->display->display_options['fields']['field_phone']['field_api_classes'] = 0;
  /* Field: Content: Email address */
  $handler->display->display_options['fields']['field_email']['id'] = 'field_email';
  $handler->display->display_options['fields']['field_email']['table'] = 'field_data_field_email';
  $handler->display->display_options['fields']['field_email']['field'] = 'field_email';
  $handler->display->display_options['fields']['field_email']['label'] = 'Email';
  $handler->display->display_options['fields']['field_email']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_email']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_email']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_email']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_email']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_email']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_email']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_email']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_email']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_email']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_email']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_email']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_email']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['field_email']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_email']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_email']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_email']['hide_alter_empty'] = 0;
  $handler->display->display_options['fields']['field_email']['type'] = 'email_default';
  $handler->display->display_options['fields']['field_email']['field_api_classes'] = 0;
  /* Field: Content: Role */
  $handler->display->display_options['fields']['field_staff_role']['id'] = 'field_staff_role';
  $handler->display->display_options['fields']['field_staff_role']['table'] = 'field_data_field_staff_role';
  $handler->display->display_options['fields']['field_staff_role']['field'] = 'field_staff_role';
  $handler->display->display_options['fields']['field_staff_role']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_staff_role']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_staff_role']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_staff_role']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_staff_role']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_staff_role']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_staff_role']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_staff_role']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_staff_role']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_staff_role']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_staff_role']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_staff_role']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_staff_role']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['field_staff_role']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_staff_role']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_staff_role']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_staff_role']['hide_alter_empty'] = 0;
  $handler->display->display_options['fields']['field_staff_role']['type'] = 'taxonomy_term_reference_plain';
  $handler->display->display_options['fields']['field_staff_role']['field_api_classes'] = 0;
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
    'thousand_separator' => ',',
    'prefix_suffix' => 0,
  );
  $handler->display->display_options['fields']['field_signups_max']['field_api_classes'] = 0;
  /* Field: Content: Students can register with this staff */
  $handler->display->display_options['fields']['field_staff_signup_available']['id'] = 'field_staff_signup_available';
  $handler->display->display_options['fields']['field_staff_signup_available']['table'] = 'field_data_field_staff_signup_available';
  $handler->display->display_options['fields']['field_staff_signup_available']['field'] = 'field_staff_signup_available';
  $handler->display->display_options['fields']['field_staff_signup_available']['label'] = 'Register?';
  $handler->display->display_options['fields']['field_staff_signup_available']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_staff_signup_available']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_staff_signup_available']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_staff_signup_available']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_staff_signup_available']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_staff_signup_available']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_staff_signup_available']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_staff_signup_available']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_staff_signup_available']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_staff_signup_available']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_staff_signup_available']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_staff_signup_available']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_staff_signup_available']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['field_staff_signup_available']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_staff_signup_available']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_staff_signup_available']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_staff_signup_available']['hide_alter_empty'] = 0;
  $handler->display->display_options['fields']['field_staff_signup_available']['field_api_classes'] = 0;
  /* Field: Content: Edit link */
  $handler->display->display_options['fields']['edit_node']['id'] = 'edit_node';
  $handler->display->display_options['fields']['edit_node']['table'] = 'node';
  $handler->display->display_options['fields']['edit_node']['field'] = 'edit_node';
  $handler->display->display_options['fields']['edit_node']['label'] = 'Edit';
  $handler->display->display_options['fields']['edit_node']['exclude'] = TRUE;
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
  /* Field: Content: Link */
  $handler->display->display_options['fields']['view_node']['id'] = 'view_node';
  $handler->display->display_options['fields']['view_node']['table'] = 'node';
  $handler->display->display_options['fields']['view_node']['field'] = 'view_node';
  $handler->display->display_options['fields']['view_node']['label'] = '';
  $handler->display->display_options['fields']['view_node']['exclude'] = TRUE;
  $handler->display->display_options['fields']['view_node']['alter']['alter_text'] = 1;
  $handler->display->display_options['fields']['view_node']['alter']['text'] = 'view';
  $handler->display->display_options['fields']['view_node']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['view_node']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['view_node']['alter']['external'] = 0;
  $handler->display->display_options['fields']['view_node']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['view_node']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['view_node']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['view_node']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['view_node']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['view_node']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['view_node']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['view_node']['alter']['html'] = 0;
  $handler->display->display_options['fields']['view_node']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['view_node']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['view_node']['hide_empty'] = 0;
  $handler->display->display_options['fields']['view_node']['empty_zero'] = 0;
  $handler->display->display_options['fields']['view_node']['hide_alter_empty'] = 0;
  /* Field: Global: Custom text */
  $handler->display->display_options['fields']['nothing']['id'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['table'] = 'views';
  $handler->display->display_options['fields']['nothing']['field'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['label'] = 'Options';
  $handler->display->display_options['fields']['nothing']['alter']['text'] = '[view_node] | [edit_node]';
  $handler->display->display_options['fields']['nothing']['alter']['make_link'] = 0;
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
    'coordinator' => 'coordinator',
  );
  /* Filter criterion: Field: First Name (field_first_name) */
  $handler->display->display_options['filters']['field_first_name_value']['id'] = 'field_first_name_value';
  $handler->display->display_options['filters']['field_first_name_value']['table'] = 'field_data_field_first_name';
  $handler->display->display_options['filters']['field_first_name_value']['field'] = 'field_first_name_value';
  $handler->display->display_options['filters']['field_first_name_value']['operator'] = 'contains';
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
  $handler->display->display_options['filters']['field_last_name_value']['operator'] = 'contains';
  $handler->display->display_options['filters']['field_last_name_value']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_last_name_value']['expose']['operator_id'] = 'field_last_name_value_op';
  $handler->display->display_options['filters']['field_last_name_value']['expose']['label'] = 'Last Name';
  $handler->display->display_options['filters']['field_last_name_value']['expose']['operator'] = 'field_last_name_value_op';
  $handler->display->display_options['filters']['field_last_name_value']['expose']['identifier'] = 'field_last_name_value';
  $handler->display->display_options['filters']['field_last_name_value']['expose']['required'] = 0;
  $handler->display->display_options['filters']['field_last_name_value']['expose']['multiple'] = FALSE;
  $handler->display->display_options['path'] = 'node/%/site-staff';
  $handler->display->display_options['menu']['type'] = 'tab';
  $handler->display->display_options['menu']['title'] = 'Site Staff';
  $handler->display->display_options['menu']['weight'] = '0';
  $translatables['site_coordinators'] = array(
    t('Master'),
    t('Site Staff'),
    t('more'),
    t('Apply'),
    t('Reset'),
    t('Sort by'),
    t('Asc'),
    t('Desc'),
    t('Items per page'),
    t('- All -'),
    t('Offset'),
    t('Name'),
    t('Restricted to'),
    t('Phone'),
    t('All'),
    t('Page'),
    t('<p class="intro">Select a coordinator who will be working with you during your service.</p>'),
    t('Select'),
    t('Site staff tab'),
    t('Last Name'),
    t('First Name'),
    t('Email'),
    t('Role'),
    t('Max students'),
    t('Register?'),
    t('Edit'),
    t('view'),
    t('Options'),
    t('[view_node] | [edit_node]'),
  );
  $export['site_coordinators'] = $view;

  $view = new view;
  $view->name = 'site_location';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'site location';
  $view->core = 7;
  $view->api_version = '3.0-alpha1';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['query']['options']['query_comment'] = FALSE;
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '1';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'fields';
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
  $handler->display->display_options['fields']['street']['label'] = 'street';
  $handler->display->display_options['fields']['street']['exclude'] = TRUE;
  $handler->display->display_options['fields']['street']['alter']['alter_text'] = 0;
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
  $handler->display->display_options['fields']['street']['hide_empty'] = 0;
  $handler->display->display_options['fields']['street']['empty_zero'] = 0;
  $handler->display->display_options['fields']['street']['style'] = 'street';
  /* Field: Location: Street */
  $handler->display->display_options['fields']['street_1']['id'] = 'street_1';
  $handler->display->display_options['fields']['street_1']['table'] = 'location';
  $handler->display->display_options['fields']['street_1']['field'] = 'street';
  $handler->display->display_options['fields']['street_1']['label'] = 'Address';
  $handler->display->display_options['fields']['street_1']['alter']['alter_text'] = 1;
  $handler->display->display_options['fields']['street_1']['alter']['text'] = '<br/>
[street]<br/>
[street_1]<br/>
[city], [province]&nbsp;&nbsp;[postal_code]';
  $handler->display->display_options['fields']['street_1']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['street_1']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['street_1']['alter']['external'] = 0;
  $handler->display->display_options['fields']['street_1']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['street_1']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['street_1']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['street_1']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['street_1']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['street_1']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['street_1']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['street_1']['alter']['html'] = 0;
  $handler->display->display_options['fields']['street_1']['element_label_type'] = 'strong';
  $handler->display->display_options['fields']['street_1']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['street_1']['element_wrapper_type'] = 'div';
  $handler->display->display_options['fields']['street_1']['element_wrapper_class'] = 'postal-address';
  $handler->display->display_options['fields']['street_1']['element_default_classes'] = 0;
  $handler->display->display_options['fields']['street_1']['hide_empty'] = 0;
  $handler->display->display_options['fields']['street_1']['empty_zero'] = 0;
  $handler->display->display_options['fields']['street_1']['hide_alter_empty'] = 0;
  $handler->display->display_options['fields']['street_1']['style'] = 'additional';
  /* Sort criterion: Content: Post date */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'node';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
  /* Contextual filter: Content: Nid */
  $handler->display->display_options['arguments']['nid']['id'] = 'nid';
  $handler->display->display_options['arguments']['nid']['table'] = 'node';
  $handler->display->display_options['arguments']['nid']['field'] = 'nid';
  $handler->display->display_options['arguments']['nid']['default_action'] = 'default';
  $handler->display->display_options['arguments']['nid']['default_argument_type'] = 'node';
  $handler->display->display_options['arguments']['nid']['default_argument_skip_url'] = 0;
  $handler->display->display_options['arguments']['nid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['nid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['nid']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['nid']['break_phrase'] = 0;
  $handler->display->display_options['arguments']['nid']['not'] = 0;
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

  /* Display: Site Address */
  $handler = $view->new_display('block', 'Site Address', 'block');
  $translatables['site_location'] = array(
    t('Master'),
    t('more'),
    t('Apply'),
    t('Reset'),
    t('Sort by'),
    t('Asc'),
    t('Desc'),
    t('Items per page'),
    t('- All -'),
    t('Offset'),
    t('City'),
    t('Postal Code'),
    t('Province'),
    t('street'),
    t('Address'),
    t('<br/>
[street]<br/>
[street_1]<br/>
[city], [province]&nbsp;&nbsp;[postal_code]'),
    t('All'),
    t('Site Address'),
  );
  $export['site_location'] = $view;

  $view = new view;
  $view->name = 'site_locations';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Site locations';
  $view->core = 7;
  $view->api_version = '3.0-alpha1';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Site locations';
  $handler->display->display_options['css_class'] = 'site-listing';
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['query']['options']['query_comment'] = FALSE;
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Header: Global: Text area */
  $handler->display->display_options['header']['area']['id'] = 'area';
  $handler->display->display_options['header']['area']['table'] = 'views';
  $handler->display->display_options['header']['area']['field'] = 'area';
  $handler->display->display_options['header']['area']['empty'] = FALSE;
  $handler->display->display_options['header']['area']['content'] = '<p class="intro">This site has multiple locations. Please select the location you will be working at.</p>';
  $handler->display->display_options['header']['area']['format'] = 'filtered_html';
  $handler->display->display_options['header']['area']['tokenize'] = 0;
  /* Field: Content: Location(s) */
  $handler->display->display_options['fields']['field_location']['id'] = 'field_location';
  $handler->display->display_options['fields']['field_location']['table'] = 'field_data_field_location';
  $handler->display->display_options['fields']['field_location']['field'] = 'field_location';
  $handler->display->display_options['fields']['field_location']['label'] = '';
  $handler->display->display_options['fields']['field_location']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_location']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_location']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_location']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_location']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_location']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_location']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_location']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_location']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_location']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_location']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_location']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_location']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_location']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_location']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_location']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_location']['hide_alter_empty'] = 0;
  $handler->display->display_options['fields']['field_location']['type'] = 's4_sites_address_select';
  $handler->display->display_options['fields']['field_location']['group_rows'] = 1;
  $handler->display->display_options['fields']['field_location']['delta_offset'] = '0';
  $handler->display->display_options['fields']['field_location']['delta_reversed'] = 0;
  $handler->display->display_options['fields']['field_location']['multi_type'] = 'ul';
  $handler->display->display_options['fields']['field_location']['field_api_classes'] = 0;
  /* Sort criterion: Content: Post date */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'node';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
  /* Contextual filter: Content: Nid */
  $handler->display->display_options['arguments']['nid']['id'] = 'nid';
  $handler->display->display_options['arguments']['nid']['table'] = 'node';
  $handler->display->display_options['arguments']['nid']['field'] = 'nid';
  $handler->display->display_options['arguments']['nid']['default_action'] = 'not found';
  $handler->display->display_options['arguments']['nid']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['nid']['default_argument_skip_url'] = 0;
  $handler->display->display_options['arguments']['nid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['nid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['nid']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['nid']['break_phrase'] = 0;
  $handler->display->display_options['arguments']['nid']['not'] = 0;
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

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page');
  $handler->display->display_options['path'] = 'sites/%/locations';
  $translatables['site_locations'] = array(
    t('Master'),
    t('Site locations'),
    t('more'),
    t('Apply'),
    t('Reset'),
    t('Sort by'),
    t('Asc'),
    t('Desc'),
    t('<p class="intro">This site has multiple locations. Please select the location you will be working at.</p>'),
    t('All'),
    t('Page'),
  );
  $export['site_locations'] = $view;

  $view = new view;
  $view->name = 'site_signups';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Site signups';
  $view->core = 7;
  $view->api_version = '3.0-alpha1';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Students';
  $handler->display->display_options['css_class'] = 'quicksearch';
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['query']['options']['query_comment'] = FALSE;
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '30';
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['columns'] = array(
    'field_first_name' => 'field_first_name',
    'field_last_name' => 'field_last_name',
    'field_course' => 'field_course',
    'field_coordinator' => 'field_coordinator',
    'nid' => 'nid',
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
    'field_course' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
    ),
    'field_coordinator' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
    ),
    'nid' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
    ),
  );
  $handler->display->display_options['style_options']['override'] = 1;
  $handler->display->display_options['style_options']['sticky'] = 0;
  $handler->display->display_options['style_options']['empty_table'] = 0;
  $handler->display->display_options['exposed_block'] = TRUE;
  /* No results behavior: Global: Text area */
  $handler->display->display_options['empty']['area']['id'] = 'area';
  $handler->display->display_options['empty']['area']['table'] = 'views';
  $handler->display->display_options['empty']['area']['field'] = 'area';
  $handler->display->display_options['empty']['area']['empty'] = FALSE;
  $handler->display->display_options['empty']['area']['content'] = '<p class="intro">No students signed up for this term.</p>';
  $handler->display->display_options['empty']['area']['format'] = 'full_html';
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
  /* Field: Content: Nid */
  $handler->display->display_options['fields']['nid']['id'] = 'nid';
  $handler->display->display_options['fields']['nid']['table'] = 'node';
  $handler->display->display_options['fields']['nid']['field'] = 'nid';
  $handler->display->display_options['fields']['nid']['label'] = 'View';
  $handler->display->display_options['fields']['nid']['alter']['alter_text'] = 1;
  $handler->display->display_options['fields']['nid']['alter']['text'] = 'View';
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
  /* Field: Content: Nid */
  $handler->display->display_options['fields']['nid_1']['id'] = 'nid_1';
  $handler->display->display_options['fields']['nid_1']['table'] = 'node';
  $handler->display->display_options['fields']['nid_1']['field'] = 'nid';
  $handler->display->display_options['fields']['nid_1']['label'] = 'Edit';
  $handler->display->display_options['fields']['nid_1']['alter']['alter_text'] = 1;
  $handler->display->display_options['fields']['nid_1']['alter']['text'] = 'Edit';
  $handler->display->display_options['fields']['nid_1']['alter']['make_link'] = 1;
  $handler->display->display_options['fields']['nid_1']['alter']['path'] = 'node/[nid_1]/edit';
  $handler->display->display_options['fields']['nid_1']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['nid_1']['alter']['external'] = 0;
  $handler->display->display_options['fields']['nid_1']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['nid_1']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['nid_1']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['nid_1']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['nid_1']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['nid_1']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['nid_1']['alter']['html'] = 0;
  $handler->display->display_options['fields']['nid_1']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['nid_1']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['nid_1']['hide_empty'] = 0;
  $handler->display->display_options['fields']['nid_1']['empty_zero'] = 0;
  $handler->display->display_options['fields']['nid_1']['link_to_node'] = 0;
  /* Sort criterion: Content: Post date */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'node';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
  /* Contextual filter: Content: Nid */
  $handler->display->display_options['arguments']['nid']['id'] = 'nid';
  $handler->display->display_options['arguments']['nid']['table'] = 'node';
  $handler->display->display_options['arguments']['nid']['field'] = 'nid';
  $handler->display->display_options['arguments']['nid']['relationship'] = 'field_site_nid';
  $handler->display->display_options['arguments']['nid']['default_action'] = 'default';
  $handler->display->display_options['arguments']['nid']['default_argument_type'] = 'node';
  $handler->display->display_options['arguments']['nid']['default_argument_skip_url'] = 0;
  $handler->display->display_options['arguments']['nid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['nid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['nid']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['nid']['break_phrase'] = 0;
  $handler->display->display_options['arguments']['nid']['not'] = 0;
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
  $handler->display->display_options['filters']['field_term_nid']['expose']['label'] = 'Terms';
  $handler->display->display_options['filters']['field_term_nid']['expose']['operator'] = 'field_term_nid_op';
  $handler->display->display_options['filters']['field_term_nid']['expose']['identifier'] = 'field_term_nid';
  $handler->display->display_options['filters']['field_term_nid']['expose']['remember'] = 1;
  $handler->display->display_options['filters']['field_term_nid']['expose']['multiple'] = 1;
  $handler->display->display_options['filters']['field_term_nid']['expose']['reduce'] = 0;
  /* Filter criterion: Field: First Name (field_first_name) */
  $handler->display->display_options['filters']['field_first_name_value']['id'] = 'field_first_name_value';
  $handler->display->display_options['filters']['field_first_name_value']['table'] = 'field_data_field_first_name';
  $handler->display->display_options['filters']['field_first_name_value']['field'] = 'field_first_name_value';
  $handler->display->display_options['filters']['field_first_name_value']['relationship'] = 'field_user_uid';
  $handler->display->display_options['filters']['field_first_name_value']['operator'] = 'contains';
  $handler->display->display_options['filters']['field_first_name_value']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_first_name_value']['expose']['operator_id'] = 'field_first_name_value_op';
  $handler->display->display_options['filters']['field_first_name_value']['expose']['label'] = 'First Name';
  $handler->display->display_options['filters']['field_first_name_value']['expose']['operator'] = 'field_first_name_value_op';
  $handler->display->display_options['filters']['field_first_name_value']['expose']['identifier'] = 'field_first_name_value';
  $handler->display->display_options['filters']['field_first_name_value']['expose']['multiple'] = FALSE;
  /* Filter criterion: Field: Last Name (field_last_name) */
  $handler->display->display_options['filters']['field_last_name_value']['id'] = 'field_last_name_value';
  $handler->display->display_options['filters']['field_last_name_value']['table'] = 'field_data_field_last_name';
  $handler->display->display_options['filters']['field_last_name_value']['field'] = 'field_last_name_value';
  $handler->display->display_options['filters']['field_last_name_value']['relationship'] = 'field_user_uid';
  $handler->display->display_options['filters']['field_last_name_value']['operator'] = 'contains';
  $handler->display->display_options['filters']['field_last_name_value']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_last_name_value']['expose']['operator_id'] = 'field_last_name_value_op';
  $handler->display->display_options['filters']['field_last_name_value']['expose']['label'] = 'Last name';
  $handler->display->display_options['filters']['field_last_name_value']['expose']['operator'] = 'field_last_name_value_op';
  $handler->display->display_options['filters']['field_last_name_value']['expose']['identifier'] = 'field_last_name_value';
  $handler->display->display_options['filters']['field_last_name_value']['expose']['multiple'] = FALSE;

  /* Display: Site signups */
  $handler = $view->new_display('block', 'Site signups', 'block');
  $translatables['site_signups'] = array(
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
    t('<p class="intro">No students signed up for this term.</p>'),
    t('field_course'),
    t('field_site'),
    t('field_user'),
    t('First Name'),
    t('Last Name'),
    t('Course'),
    t('Coordinator'),
    t('View'),
    t('node/[nid]'),
    t('Edit'),
    t('node/[nid_1]/edit'),
    t('All'),
    t('Terms'),
    t('Last name'),
    t('Site signups'),
  );
  $export['site_signups'] = $view;

  $view = new view;
  $view->name = 'sites';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'sites';
  $view->core = 7;
  $view->api_version = '3.0-alpha1';
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
  $handler->display->display_options['style_plugin'] = 'list';
  $handler->display->display_options['style_options']['wrapper_class'] = 'site-listing';
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['row_options']['hide_empty'] = 0;
  $handler->display->display_options['exposed_block'] = TRUE;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['exclude'] = TRUE;
  $handler->display->display_options['fields']['title']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['title']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['title']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['title']['alter']['external'] = 0;
  $handler->display->display_options['fields']['title']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['title']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = 0;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = 0;
  $handler->display->display_options['fields']['title']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['title']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['title']['alter']['html'] = 0;
  $handler->display->display_options['fields']['title']['element_type'] = 'h4';
  $handler->display->display_options['fields']['title']['element_label_colon'] = 0;
  $handler->display->display_options['fields']['title']['element_default_classes'] = 0;
  $handler->display->display_options['fields']['title']['hide_empty'] = 0;
  $handler->display->display_options['fields']['title']['empty_zero'] = 0;
  $handler->display->display_options['fields']['title']['link_to_node'] = 1;
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
  $handler->display->display_options['fields']['field_csu_facility']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_csu_facility']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_csu_facility']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_csu_facility']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_csu_facility']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_csu_facility']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_csu_facility']['element_label_colon'] = 0;
  $handler->display->display_options['fields']['field_csu_facility']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_csu_facility']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_csu_facility']['empty_zero'] = 0;
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
  $handler->display->display_options['fields']['field_csu_org_type']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_csu_org_type']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_csu_org_type']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_csu_org_type']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_csu_org_type']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_csu_org_type']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_csu_org_type']['element_label_colon'] = 0;
  $handler->display->display_options['fields']['field_csu_org_type']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_csu_org_type']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_csu_org_type']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_csu_org_type']['field_api_classes'] = 0;
  /* Field: Title and type */
  $handler->display->display_options['fields']['nothing_1']['id'] = 'nothing_1';
  $handler->display->display_options['fields']['nothing_1']['table'] = 'views';
  $handler->display->display_options['fields']['nothing_1']['field'] = 'nothing';
  $handler->display->display_options['fields']['nothing_1']['ui_name'] = 'Title and type';
  $handler->display->display_options['fields']['nothing_1']['label'] = '';
  $handler->display->display_options['fields']['nothing_1']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['nothing_1']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['nothing_1']['alter']['external'] = 0;
  $handler->display->display_options['fields']['nothing_1']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['nothing_1']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['nothing_1']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['nothing_1']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['nothing_1']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['nothing_1']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['nothing_1']['alter']['html'] = 0;
  $handler->display->display_options['fields']['nothing_1']['element_label_colon'] = 0;
  $handler->display->display_options['fields']['nothing_1']['element_wrapper_type'] = 'div';
  $handler->display->display_options['fields']['nothing_1']['element_wrapper_class'] = 'site-info';
  $handler->display->display_options['fields']['nothing_1']['element_default_classes'] = 0;
  $handler->display->display_options['fields']['nothing_1']['empty'] = '<h4>[title]</h4><div class="meta">[field_csu_facility] - [field_csu_org_type]</div>';
  $handler->display->display_options['fields']['nothing_1']['hide_empty'] = 0;
  $handler->display->display_options['fields']['nothing_1']['empty_zero'] = 0;
  /* Field: Field: Restricted to */
  $handler->display->display_options['fields']['field_site_restrict']['id'] = 'field_site_restrict';
  $handler->display->display_options['fields']['field_site_restrict']['table'] = 'field_data_field_site_restrict';
  $handler->display->display_options['fields']['field_site_restrict']['field'] = 'field_site_restrict';
  $handler->display->display_options['fields']['field_site_restrict']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_site_restrict']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_site_restrict']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_site_restrict']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_site_restrict']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_site_restrict']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_site_restrict']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_site_restrict']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_site_restrict']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_site_restrict']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_site_restrict']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_site_restrict']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['field_site_restrict']['element_wrapper_type'] = 'div';
  $handler->display->display_options['fields']['field_site_restrict']['element_wrapper_class'] = 'site-restrictions';
  $handler->display->display_options['fields']['field_site_restrict']['element_default_classes'] = 0;
  $handler->display->display_options['fields']['field_site_restrict']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_site_restrict']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_site_restrict']['type'] = 'taxonomy_term_reference_plain';
  $handler->display->display_options['fields']['field_site_restrict']['group_rows'] = 1;
  $handler->display->display_options['fields']['field_site_restrict']['delta_offset'] = '0';
  $handler->display->display_options['fields']['field_site_restrict']['delta_reversed'] = 0;
  $handler->display->display_options['fields']['field_site_restrict']['field_api_classes'] = 0;
  /* Field: Signup: Site location links */
  $handler->display->display_options['fields']['site_location_links']['id'] = 'site_location_links';
  $handler->display->display_options['fields']['site_location_links']['table'] = 's4_signup';
  $handler->display->display_options['fields']['site_location_links']['field'] = 'site_location_links';
  $handler->display->display_options['fields']['site_location_links']['label'] = '';
  $handler->display->display_options['fields']['site_location_links']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['site_location_links']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['site_location_links']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['site_location_links']['alter']['external'] = 0;
  $handler->display->display_options['fields']['site_location_links']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['site_location_links']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['site_location_links']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['site_location_links']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['site_location_links']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['site_location_links']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['site_location_links']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['site_location_links']['alter']['html'] = 0;
  $handler->display->display_options['fields']['site_location_links']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['site_location_links']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['site_location_links']['hide_empty'] = 0;
  $handler->display->display_options['fields']['site_location_links']['empty_zero'] = 0;
  $handler->display->display_options['fields']['site_location_links']['hide_alter_empty'] = 0;
  /* Sort criterion: Content: Title */
  $handler->display->display_options['sorts']['title']['id'] = 'title';
  $handler->display->display_options['sorts']['title']['table'] = 'node';
  $handler->display->display_options['sorts']['title']['field'] = 'title';
  /* Contextual filter: Content: Nid */
  $handler->display->display_options['arguments']['nid']['id'] = 'nid';
  $handler->display->display_options['arguments']['nid']['table'] = 'node';
  $handler->display->display_options['arguments']['nid']['field'] = 'nid';
  $handler->display->display_options['arguments']['nid']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['nid']['default_argument_skip_url'] = 0;
  $handler->display->display_options['arguments']['nid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['nid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['nid']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['nid']['break_phrase'] = 1;
  $handler->display->display_options['arguments']['nid']['not'] = 0;
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
  $handler->display->display_options['path'] = 'site-list';

  /* Display: Block */
  $handler = $view->new_display('block', 'Block', 'block_1');
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '10';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'list';
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['row_options']['inline'] = array(
    'title' => 'title',
  );
  $handler->display->display_options['row_options']['hide_empty'] = 0;
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['title']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['title']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['title']['alter']['external'] = 0;
  $handler->display->display_options['fields']['title']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['title']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = 0;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = 0;
  $handler->display->display_options['fields']['title']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['title']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['title']['alter']['html'] = 0;
  $handler->display->display_options['fields']['title']['element_label_colon'] = 0;
  $handler->display->display_options['fields']['title']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['title']['hide_empty'] = 0;
  $handler->display->display_options['fields']['title']['empty_zero'] = 0;
  $handler->display->display_options['fields']['title']['link_to_node'] = 1;
  $handler->display->display_options['defaults']['sorts'] = FALSE;
  /* Sort criterion: Content: Post date */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'node';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
  $handler->display->display_options['block_description'] = 'Newest Sites';
  $translatables['sites'] = array(
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
    t('<h4>[title]</h4><div class="meta">[field_csu_facility] - [field_csu_org_type]</div>'),
    t('Restricted to'),
    t('All'),
    t('Search'),
    t('City'),
    t('Page'),
    t('Block'),
    t('Newest Sites'),
  );
  $export['sites'] = $view;

  return $export;
}
