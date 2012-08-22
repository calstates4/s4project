<?php
/**
 * @file
 * s4_map.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function s4_map_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'site_map';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Site Map';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Site Map';
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['query']['options']['query_comment'] = FALSE;
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['style_plugin'] = 'views_json';
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  /* Field: Location: Latitude */
  $handler->display->display_options['fields']['latitude']['id'] = 'latitude';
  $handler->display->display_options['fields']['latitude']['table'] = 'location';
  $handler->display->display_options['fields']['latitude']['field'] = 'latitude';
  $handler->display->display_options['fields']['latitude']['label'] = 'latitude';
  $handler->display->display_options['fields']['latitude']['hide_alter_empty'] = FALSE;
  $handler->display->display_options['fields']['latitude']['style'] = 'dd';
  /* Field: Location: Longitude */
  $handler->display->display_options['fields']['longitude']['id'] = 'longitude';
  $handler->display->display_options['fields']['longitude']['table'] = 'location';
  $handler->display->display_options['fields']['longitude']['field'] = 'longitude';
  $handler->display->display_options['fields']['longitude']['label'] = 'longitude';
  $handler->display->display_options['fields']['longitude']['hide_alter_empty'] = FALSE;
  $handler->display->display_options['fields']['longitude']['style'] = 'dd';
  /* Field: Content: Nid */
  $handler->display->display_options['fields']['nid']['id'] = 'nid';
  $handler->display->display_options['fields']['nid']['table'] = 'node';
  $handler->display->display_options['fields']['nid']['field'] = 'nid';
  $handler->display->display_options['fields']['nid']['label'] = 'nid';
  $handler->display->display_options['fields']['nid']['hide_alter_empty'] = FALSE;
  /* Field: Content: Path */
  $handler->display->display_options['fields']['path']['id'] = 'path';
  $handler->display->display_options['fields']['path']['table'] = 'node';
  $handler->display->display_options['fields']['path']['field'] = 'path';
  $handler->display->display_options['fields']['path']['label'] = 'path';
  $handler->display->display_options['fields']['path']['hide_alter_empty'] = FALSE;
  /* Field: Site Data: Total hours */
  $handler->display->display_options['fields']['total_site_hours']['id'] = 'total_site_hours';
  $handler->display->display_options['fields']['total_site_hours']['table'] = 's4_sites';
  $handler->display->display_options['fields']['total_site_hours']['field'] = 'total_site_hours';
  $handler->display->display_options['fields']['total_site_hours']['label'] = 'hours';
  $handler->display->display_options['fields']['total_site_hours']['hide_alter_empty'] = FALSE;
  /* Field: Site Data: Total students */
  $handler->display->display_options['fields']['total_students']['id'] = 'total_students';
  $handler->display->display_options['fields']['total_students']['table'] = 's4_sites';
  $handler->display->display_options['fields']['total_students']['field'] = 'total_students';
  $handler->display->display_options['fields']['total_students']['label'] = 'students';
  $handler->display->display_options['fields']['total_students']['hide_alter_empty'] = FALSE;
  /* Sort criterion: Content: Post date */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'node';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
  /* Contextual filter: Field: Program (field_site_restrict) */
  $handler->display->display_options['arguments']['field_site_restrict_tid']['id'] = 'field_site_restrict_tid';
  $handler->display->display_options['arguments']['field_site_restrict_tid']['table'] = 'field_data_field_site_restrict';
  $handler->display->display_options['arguments']['field_site_restrict_tid']['field'] = 'field_site_restrict_tid';
  $handler->display->display_options['arguments']['field_site_restrict_tid']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['field_site_restrict_tid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['field_site_restrict_tid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['field_site_restrict_tid']['summary_options']['items_per_page'] = '25';
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
  $handler->display->display_options['path'] = 'json/map/sites';
  $export['site_map'] = $view;

  return $export;
}
