<?php
/**
 * @file
 * s4_map.views_default.inc
 */

/**
 * Implementation of hook_views_default_views().
 */
function s4_map_views_default_views() {
  $export = array();

  $view = new view;
  $view->name = 'site_map';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Site Map';
  $view->core = 7;
  $view->api_version = '3.0-alpha1';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Site Map';
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['query']['options']['query_comment'] = FALSE;
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '50';
  $handler->display->display_options['style_plugin'] = 'views_json';
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
  /* Field: Location: Latitude */
  $handler->display->display_options['fields']['latitude']['id'] = 'latitude';
  $handler->display->display_options['fields']['latitude']['table'] = 'location';
  $handler->display->display_options['fields']['latitude']['field'] = 'latitude';
  $handler->display->display_options['fields']['latitude']['label'] = 'latitude';
  $handler->display->display_options['fields']['latitude']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['latitude']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['latitude']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['latitude']['alter']['external'] = 0;
  $handler->display->display_options['fields']['latitude']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['latitude']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['latitude']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['latitude']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['latitude']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['latitude']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['latitude']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['latitude']['alter']['html'] = 0;
  $handler->display->display_options['fields']['latitude']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['latitude']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['latitude']['hide_empty'] = 0;
  $handler->display->display_options['fields']['latitude']['empty_zero'] = 0;
  $handler->display->display_options['fields']['latitude']['hide_alter_empty'] = 0;
  $handler->display->display_options['fields']['latitude']['style'] = 'dd';
  /* Field: Location: Longitude */
  $handler->display->display_options['fields']['longitude']['id'] = 'longitude';
  $handler->display->display_options['fields']['longitude']['table'] = 'location';
  $handler->display->display_options['fields']['longitude']['field'] = 'longitude';
  $handler->display->display_options['fields']['longitude']['label'] = 'longitude';
  $handler->display->display_options['fields']['longitude']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['longitude']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['longitude']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['longitude']['alter']['external'] = 0;
  $handler->display->display_options['fields']['longitude']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['longitude']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['longitude']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['longitude']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['longitude']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['longitude']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['longitude']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['longitude']['alter']['html'] = 0;
  $handler->display->display_options['fields']['longitude']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['longitude']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['longitude']['hide_empty'] = 0;
  $handler->display->display_options['fields']['longitude']['empty_zero'] = 0;
  $handler->display->display_options['fields']['longitude']['hide_alter_empty'] = 0;
  $handler->display->display_options['fields']['longitude']['style'] = 'dd';
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
  /* Filter criterion: Location: Latitude */
  $handler->display->display_options['filters']['latitude']['id'] = 'latitude';
  $handler->display->display_options['filters']['latitude']['table'] = 'location';
  $handler->display->display_options['filters']['latitude']['field'] = 'latitude';
  $handler->display->display_options['filters']['latitude']['operator'] = '!=';
  $handler->display->display_options['filters']['latitude']['value']['value'] = '0';
  /* Filter criterion: Location: Longitude */
  $handler->display->display_options['filters']['longitude']['id'] = 'longitude';
  $handler->display->display_options['filters']['longitude']['table'] = 'location';
  $handler->display->display_options['filters']['longitude']['field'] = 'longitude';
  $handler->display->display_options['filters']['longitude']['operator'] = '!=';
  $handler->display->display_options['filters']['longitude']['value']['value'] = '0';

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page');
  $handler->display->display_options['path'] = 'json/map/sites/%/%';
  $translatables['site_map'] = array(
    t('Master'),
    t('Site Map'),
    t('more'),
    t('Apply'),
    t('Reset'),
    t('Sort by'),
    t('Asc'),
    t('Desc'),
    t('latitude'),
    t('longitude'),
    t('Page'),
  );
  $export['site_map'] = $view;

  return $export;
}
