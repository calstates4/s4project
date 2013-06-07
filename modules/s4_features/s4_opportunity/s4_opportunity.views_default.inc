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
  $view->name = 's4_opportunities';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 's4_opportunity';
  $view->human_name = 'S4 opportunities';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Opportunities';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['access']['perm'] = 'administer opportunities';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'views_exposed_groups';
  $handler->display->display_options['exposed_form']['options']['submit_button'] = 'Search';
  $handler->display->display_options['exposed_form']['options']['views_exposed_groups'] = array(
    'format_groups' => 'vertical_tabs',
    'groups' => 'Opportunity
Site',
    'group-field_csu_facility_tid' => array(
      'group' => '1',
      'filter_name' => 'field_csu_facility_tid',
      'weight' => '-2',
    ),
    'group-field_csu_org_type_tid' => array(
      'group' => '1',
      'filter_name' => 'field_csu_org_type_tid',
      'weight' => '-1',
    ),
    'group-field_site_restrict_tid' => array(
      'group' => '0',
      'filter_name' => 'field_site_restrict_tid',
      'weight' => '-3',
    ),
    'group-status' => array(
      'group' => '0',
      'filter_name' => 'status',
      'weight' => '-4',
    ),
    'group-field_opportunity_category_tid' => array(
      'group' => '0',
      'filter_name' => 'field_opportunity_category_tid',
      'weight' => '-5',
    ),
  );
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '40';
  $handler->display->display_options['style_plugin'] = 'table';
  /* Relationship: Entity Reference: Referenced Entity */
  $handler->display->display_options['relationships']['field_opportunity_sites_target_id']['id'] = 'field_opportunity_sites_target_id';
  $handler->display->display_options['relationships']['field_opportunity_sites_target_id']['table'] = 'field_data_field_opportunity_sites';
  $handler->display->display_options['relationships']['field_opportunity_sites_target_id']['field'] = 'field_opportunity_sites_target_id';
  /* Field: Opportunity: Name */
  $handler->display->display_options['fields']['name']['id'] = 'name';
  $handler->display->display_options['fields']['name']['table'] = 's4_opportunity';
  $handler->display->display_options['fields']['name']['field'] = 'name';
  $handler->display->display_options['fields']['name']['link'] = 1;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['relationship'] = 'field_opportunity_sites_target_id';
  $handler->display->display_options['fields']['title']['label'] = 'Site';
  /* Field: Opportunity: Opportunity type */
  $handler->display->display_options['fields']['type']['id'] = 'type';
  $handler->display->display_options['fields']['type']['table'] = 's4_opportunity';
  $handler->display->display_options['fields']['type']['field'] = 'type';
  $handler->display->display_options['fields']['type']['label'] = 'Type';
  /* Field: Opportunity: Status */
  $handler->display->display_options['fields']['status']['id'] = 'status';
  $handler->display->display_options['fields']['status']['table'] = 's4_opportunity';
  $handler->display->display_options['fields']['status']['field'] = 'status';
  /* Filter criterion: Content: Issues addressed (field_csu_facility) */
  $handler->display->display_options['filters']['field_csu_facility_tid']['id'] = 'field_csu_facility_tid';
  $handler->display->display_options['filters']['field_csu_facility_tid']['table'] = 'field_data_field_csu_facility';
  $handler->display->display_options['filters']['field_csu_facility_tid']['field'] = 'field_csu_facility_tid';
  $handler->display->display_options['filters']['field_csu_facility_tid']['relationship'] = 'field_opportunity_sites_target_id';
  $handler->display->display_options['filters']['field_csu_facility_tid']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_csu_facility_tid']['expose']['operator_id'] = 'field_csu_facility_tid_op';
  $handler->display->display_options['filters']['field_csu_facility_tid']['expose']['label'] = 'Issues addressed';
  $handler->display->display_options['filters']['field_csu_facility_tid']['expose']['operator'] = 'field_csu_facility_tid_op';
  $handler->display->display_options['filters']['field_csu_facility_tid']['expose']['identifier'] = 'field_csu_facility_tid';
  $handler->display->display_options['filters']['field_csu_facility_tid']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    4 => 0,
    6 => 0,
    3 => 0,
    5 => 0,
    7 => 0,
    8 => 0,
  );
  $handler->display->display_options['filters']['field_csu_facility_tid']['type'] = 'select';
  $handler->display->display_options['filters']['field_csu_facility_tid']['vocabulary'] = 'issues_addressed';
  /* Filter criterion: Content: Organization type (field_csu_org_type) */
  $handler->display->display_options['filters']['field_csu_org_type_tid']['id'] = 'field_csu_org_type_tid';
  $handler->display->display_options['filters']['field_csu_org_type_tid']['table'] = 'field_data_field_csu_org_type';
  $handler->display->display_options['filters']['field_csu_org_type_tid']['field'] = 'field_csu_org_type_tid';
  $handler->display->display_options['filters']['field_csu_org_type_tid']['relationship'] = 'field_opportunity_sites_target_id';
  $handler->display->display_options['filters']['field_csu_org_type_tid']['value'] = '';
  $handler->display->display_options['filters']['field_csu_org_type_tid']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_csu_org_type_tid']['expose']['operator_id'] = 'field_csu_org_type_tid_op';
  $handler->display->display_options['filters']['field_csu_org_type_tid']['expose']['label'] = 'Organization type';
  $handler->display->display_options['filters']['field_csu_org_type_tid']['expose']['operator'] = 'field_csu_org_type_tid_op';
  $handler->display->display_options['filters']['field_csu_org_type_tid']['expose']['identifier'] = 'field_csu_org_type_tid';
  $handler->display->display_options['filters']['field_csu_org_type_tid']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    4 => 0,
    6 => 0,
    3 => 0,
    5 => 0,
    7 => 0,
    8 => 0,
  );
  $handler->display->display_options['filters']['field_csu_org_type_tid']['type'] = 'select';
  $handler->display->display_options['filters']['field_csu_org_type_tid']['vocabulary'] = 'organization_type';
  /* Filter criterion: Field: Program(s) (field_site_restrict) */
  $handler->display->display_options['filters']['field_site_restrict_tid']['id'] = 'field_site_restrict_tid';
  $handler->display->display_options['filters']['field_site_restrict_tid']['table'] = 'field_data_field_site_restrict';
  $handler->display->display_options['filters']['field_site_restrict_tid']['field'] = 'field_site_restrict_tid';
  $handler->display->display_options['filters']['field_site_restrict_tid']['value'] = '';
  $handler->display->display_options['filters']['field_site_restrict_tid']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_site_restrict_tid']['expose']['operator_id'] = 'field_site_restrict_tid_op';
  $handler->display->display_options['filters']['field_site_restrict_tid']['expose']['label'] = 'Program(s)';
  $handler->display->display_options['filters']['field_site_restrict_tid']['expose']['operator'] = 'field_site_restrict_tid_op';
  $handler->display->display_options['filters']['field_site_restrict_tid']['expose']['identifier'] = 'field_site_restrict_tid';
  $handler->display->display_options['filters']['field_site_restrict_tid']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    4 => 0,
    6 => 0,
    3 => 0,
    5 => 0,
    7 => 0,
    8 => 0,
  );
  $handler->display->display_options['filters']['field_site_restrict_tid']['type'] = 'select';
  $handler->display->display_options['filters']['field_site_restrict_tid']['vocabulary'] = 'site_restrictions';
  /* Filter criterion: Opportunity: Status */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 's4_opportunity';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['exposed'] = TRUE;
  $handler->display->display_options['filters']['status']['expose']['operator_id'] = '';
  $handler->display->display_options['filters']['status']['expose']['label'] = 'Active';
  $handler->display->display_options['filters']['status']['expose']['operator'] = 'status_op';
  $handler->display->display_options['filters']['status']['expose']['identifier'] = 'status';
  $handler->display->display_options['filters']['status']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    4 => 0,
    6 => 0,
    3 => 0,
    5 => 0,
    7 => 0,
    8 => 0,
  );
  /* Filter criterion: Opportunity: Category (field_opportunity_category) */
  $handler->display->display_options['filters']['field_opportunity_category_tid']['id'] = 'field_opportunity_category_tid';
  $handler->display->display_options['filters']['field_opportunity_category_tid']['table'] = 'field_data_field_opportunity_category';
  $handler->display->display_options['filters']['field_opportunity_category_tid']['field'] = 'field_opportunity_category_tid';
  $handler->display->display_options['filters']['field_opportunity_category_tid']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_opportunity_category_tid']['expose']['operator_id'] = 'field_opportunity_category_tid_op';
  $handler->display->display_options['filters']['field_opportunity_category_tid']['expose']['label'] = 'Category';
  $handler->display->display_options['filters']['field_opportunity_category_tid']['expose']['operator'] = 'field_opportunity_category_tid_op';
  $handler->display->display_options['filters']['field_opportunity_category_tid']['expose']['identifier'] = 'field_opportunity_category_tid';
  $handler->display->display_options['filters']['field_opportunity_category_tid']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    4 => 0,
    6 => 0,
    3 => 0,
    5 => 0,
    7 => 0,
    8 => 0,
  );
  $handler->display->display_options['filters']['field_opportunity_category_tid']['reduce_duplicates'] = TRUE;
  $handler->display->display_options['filters']['field_opportunity_category_tid']['type'] = 'select';
  $handler->display->display_options['filters']['field_opportunity_category_tid']['vocabulary'] = 'opportunity_category';
  $handler->display->display_options['filters']['field_opportunity_category_tid']['error_message'] = FALSE;

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page');
  $handler->display->display_options['path'] = 'opportunities';
  $handler->display->display_options['menu']['type'] = 'normal';
  $handler->display->display_options['menu']['title'] = 'Opportunities';
  $handler->display->display_options['menu']['weight'] = '-47';
  $handler->display->display_options['menu']['name'] = 'main-menu';
  $handler->display->display_options['menu']['context'] = 0;
  $handler->display->display_options['menu']['context_only_inline'] = 0;
  $translatables['s4_opportunities'] = array(
    t('Master'),
    t('Opportunities'),
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
    t('Content entity referenced from field_opportunity_sites'),
    t('Name'),
    t('1'),
    t('Site'),
    t('Type'),
    t('Status'),
    t('Issues addressed'),
    t('Organization type'),
    t('Program(s)'),
    t('Active'),
    t('Category'),
    t('Page'),
  );
  $export['s4_opportunities'] = $view;

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
  /* Field: Opportunity: Name */
  $handler->display->display_options['fields']['name']['id'] = 'name';
  $handler->display->display_options['fields']['name']['table'] = 's4_opportunity';
  $handler->display->display_options['fields']['name']['field'] = 'name';
  $handler->display->display_options['fields']['name']['link'] = 1;
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
  /* Field: Opportunity: Opportunity type */
  $handler->display->display_options['fields']['type']['id'] = 'type';
  $handler->display->display_options['fields']['type']['table'] = 's4_opportunity';
  $handler->display->display_options['fields']['type']['field'] = 'type';
  $handler->display->display_options['fields']['type']['label'] = 'Type';
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
    t('Name'),
    t('1'),
    t('Program(s)'),
    t('Site staff'),
    t('Type'),
    t('All'),
    t('%1'),
    t('Opportunity site tab'),
  );
  $export['s4_opportunity_site_opportunities'] = $view;

  return $export;
}
