<?php
/**
 * @file
 * s4_opportunity.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function s4_opportunity_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 's4_opportunity_site_opportunities';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 's4_opportunity';
  $view->human_name = 'S4 opportunity: Site opportunities';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Opportunities';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'type_permission';
  $handler->display->display_options['access']['permission'] = 'administer opportunities';
  $handler->display->display_options['access']['node_type'] = 'site';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '30';
  $handler->display->display_options['style_plugin'] = 'table';
  /* No results behavior: Global: Text area */
  $handler->display->display_options['empty']['area']['id'] = 'area';
  $handler->display->display_options['empty']['area']['table'] = 'views';
  $handler->display->display_options['empty']['area']['field'] = 'area';
  $handler->display->display_options['empty']['area']['empty'] = TRUE;
  $handler->display->display_options['empty']['area']['content'] = '<p class="lead">No opportunities yet! Use the form to the right to create one.</p>';
  $handler->display->display_options['empty']['area']['format'] = 'full_html';
  /* Relationship: Entity Reference: Referenced Entity */
  $handler->display->display_options['relationships']['field_opportunity_sites_target_id']['id'] = 'field_opportunity_sites_target_id';
  $handler->display->display_options['relationships']['field_opportunity_sites_target_id']['table'] = 'field_data_field_opportunity_sites';
  $handler->display->display_options['relationships']['field_opportunity_sites_target_id']['field'] = 'field_opportunity_sites_target_id';
  /* Field: Field: Program(s) */
  $handler->display->display_options['fields']['field_site_restrict']['id'] = 'field_site_restrict';
  $handler->display->display_options['fields']['field_site_restrict']['table'] = 'field_data_field_site_restrict';
  $handler->display->display_options['fields']['field_site_restrict']['field'] = 'field_site_restrict';
  $handler->display->display_options['fields']['field_site_restrict']['type'] = 'taxonomy_term_reference_plain';
  $handler->display->display_options['fields']['field_site_restrict']['delta_offset'] = '0';
  /* Field: Field: Site staff */
  $handler->display->display_options['fields']['field_coordinator']['id'] = 'field_coordinator';
  $handler->display->display_options['fields']['field_coordinator']['table'] = 'field_data_field_coordinator';
  $handler->display->display_options['fields']['field_coordinator']['field'] = 'field_coordinator';
  /* Contextual filter: Content: Nid */
  $handler->display->display_options['arguments']['nid']['id'] = 'nid';
  $handler->display->display_options['arguments']['nid']['table'] = 'node';
  $handler->display->display_options['arguments']['nid']['field'] = 'nid';
  $handler->display->display_options['arguments']['nid']['relationship'] = 'field_opportunity_sites_target_id';
  $handler->display->display_options['arguments']['nid']['default_action'] = 'default';
  $handler->display->display_options['arguments']['nid']['title_enable'] = TRUE;
  $handler->display->display_options['arguments']['nid']['title'] = '%1';
  $handler->display->display_options['arguments']['nid']['default_argument_type'] = 'node';
  $handler->display->display_options['arguments']['nid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['nid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['nid']['summary_options']['items_per_page'] = '25';

  /* Display: Opportunity site tab */
  $handler = $view->new_display('page', 'Opportunity site tab', 'page');
  $handler->display->display_options['path'] = 'node/%/opportunities';
  $handler->display->display_options['menu']['type'] = 'tab';
  $handler->display->display_options['menu']['title'] = 'Opportunities';
  $handler->display->display_options['menu']['weight'] = '0';
  $handler->display->display_options['menu']['context'] = 0;
  $handler->display->display_options['menu']['context_only_inline'] = 0;
  $translatables['s4_opportunity_site_opportunities'] = array(
    t('Master'),
    t('Opportunities'),
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
    t('<p class="lead">No opportunities yet! Use the form to the right to create one.</p>'),
    t('Content entity referenced from field_opportunity_sites'),
    t('Program(s)'),
    t('Site staff'),
    t('All'),
    t('%1'),
    t('Opportunity site tab'),
  );
  $export['s4_opportunity_site_opportunities'] = $view;

  return $export;
}
