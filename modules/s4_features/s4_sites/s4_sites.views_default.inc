<?php
/**
 * @file
 * s4_sites.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function s4_sites_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'location_gmap';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'S4: Site Locations Map';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Map';
  $handler->display->display_options['use_more_always'] = FALSE;
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
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['title']['element_type'] = 'h3';
  $handler->display->display_options['fields']['title']['element_default_classes'] = FALSE;
  /* Field: Content: Edit link */
  $handler->display->display_options['fields']['edit_node']['id'] = 'edit_node';
  $handler->display->display_options['fields']['edit_node']['table'] = 'views_entity_node';
  $handler->display->display_options['fields']['edit_node']['field'] = 'edit_node';
  $handler->display->display_options['fields']['edit_node']['label'] = '';
  $handler->display->display_options['fields']['edit_node']['element_label_colon'] = FALSE;
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
  /* Filter criterion: Search: Search Terms */
  $handler->display->display_options['filters']['keys']['id'] = 'keys';
  $handler->display->display_options['filters']['keys']['table'] = 'search_index';
  $handler->display->display_options['filters']['keys']['field'] = 'keys';
  $handler->display->display_options['filters']['keys']['exposed'] = TRUE;
  $handler->display->display_options['filters']['keys']['expose']['operator_id'] = 'keys_op';
  $handler->display->display_options['filters']['keys']['expose']['label'] = 'Search';
  $handler->display->display_options['filters']['keys']['expose']['operator'] = 'keys_op';
  $handler->display->display_options['filters']['keys']['expose']['identifier'] = 'keys';

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

  $view = new view();
  $view->name = 's4_manage_sites';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'S4: Manage sites';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Manage sites';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['group_by'] = TRUE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['access']['perm'] = 'view all unpublished content';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['query']['options']['distinct'] = TRUE;
  $handler->display->display_options['exposed_form']['type'] = 'views_exposed_groups';
  $handler->display->display_options['exposed_form']['options']['submit_button'] = 'Search';
  $handler->display->display_options['exposed_form']['options']['reset_button'] = TRUE;
  $handler->display->display_options['exposed_form']['options']['views_exposed_groups'] = array(
    'format_groups' => 'vertical_tabs',
    'groups' => 'Site
Status
Location',
    'group-title' => array(
      'group' => '0',
      'filter_name' => 'title',
      'weight' => '-11',
    ),
    'group-field_csu_org_type_tid' => array(
      'group' => '0',
      'filter_name' => 'field_csu_org_type_tid',
      'weight' => '-10',
    ),
    'group-field_csu_facility_tid' => array(
      'group' => '0',
      'filter_name' => 'field_csu_facility_tid',
      'weight' => '-9',
    ),
    'group-programs' => array(
      'group' => '0',
      'filter_name' => 'field_site_restrict_tid',
      'weight' => '-12',
    ),
    'group-city' => array(
      'group' => '2',
      'filter_name' => 'city',
      'weight' => '-12',
    ),
    'group-province' => array(
      'group' => '2',
      'filter_name' => 'province',
      'weight' => '-11',
    ),
    'group-status' => array(
      'group' => '1',
      'filter_name' => 'state',
      'weight' => '-12',
    ),
    'group-state' => array(
      'group' => '1',
      'filter_name' => 'status',
      'weight' => '-12',
    ),
    'group-field_district_state_lower_value' => array(
      'group' => '2',
      'filter_name' => 'field_district_state_lower_value',
      'weight' => '-10',
    ),
    'group-field_district_state_upper_value' => array(
      'group' => '2',
      'filter_name' => 'field_district_state_upper_value',
      'weight' => '-9',
    ),
    'group-field_county_value' => array(
      'group' => '2',
      'filter_name' => 'field_county_value',
      'weight' => '-12',
    ),
  );
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '40';
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['columns'] = array(
    'title' => 'title',
    'field_site_restrict' => 'field_site_restrict',
    'status' => 'status',
    'state' => 'state',
    'changed' => 'changed',
  );
  $handler->display->display_options['style_options']['default'] = 'title';
  $handler->display->display_options['style_options']['info'] = array(
    'title' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_site_restrict' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'status' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'state' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'changed' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
  );
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  /* Field: Field: Program(s) */
  $handler->display->display_options['fields']['field_site_restrict']['id'] = 'field_site_restrict';
  $handler->display->display_options['fields']['field_site_restrict']['table'] = 'field_data_field_site_restrict';
  $handler->display->display_options['fields']['field_site_restrict']['field'] = 'field_site_restrict';
  $handler->display->display_options['fields']['field_site_restrict']['label'] = 'Programs';
  $handler->display->display_options['fields']['field_site_restrict']['type'] = 'taxonomy_term_reference_plain';
  $handler->display->display_options['fields']['field_site_restrict']['group_column'] = 'entity_id';
  $handler->display->display_options['fields']['field_site_restrict']['delta_offset'] = '0';
  /* Field: Content: Published */
  $handler->display->display_options['fields']['status']['id'] = 'status';
  $handler->display->display_options['fields']['status']['table'] = 'node';
  $handler->display->display_options['fields']['status']['field'] = 'status';
  $handler->display->display_options['fields']['status']['label'] = 'Active';
  $handler->display->display_options['fields']['status']['not'] = 0;
  /* Field: MAX(Workbench Moderation: State) */
  $handler->display->display_options['fields']['state']['id'] = 'state';
  $handler->display->display_options['fields']['state']['table'] = 'workbench_moderation_node_history';
  $handler->display->display_options['fields']['state']['field'] = 'state';
  $handler->display->display_options['fields']['state']['group_type'] = 'max';
  $handler->display->display_options['fields']['state']['label'] = 'Approval Status';
  $handler->display->display_options['fields']['state']['machine_name'] = 0;
  /* Field: Content: Updated date */
  $handler->display->display_options['fields']['changed']['id'] = 'changed';
  $handler->display->display_options['fields']['changed']['table'] = 'node';
  $handler->display->display_options['fields']['changed']['field'] = 'changed';
  $handler->display->display_options['fields']['changed']['date_format'] = 'short';
  /* Field: Content: Edit link */
  $handler->display->display_options['fields']['edit_node']['id'] = 'edit_node';
  $handler->display->display_options['fields']['edit_node']['table'] = 'views_entity_node';
  $handler->display->display_options['fields']['edit_node']['field'] = 'edit_node';
  $handler->display->display_options['fields']['edit_node']['label'] = 'Edit';
  /* Field: Content: Nid */
  $handler->display->display_options['fields']['nid']['id'] = 'nid';
  $handler->display->display_options['fields']['nid']['table'] = 'node';
  $handler->display->display_options['fields']['nid']['field'] = 'nid';
  $handler->display->display_options['fields']['nid']['exclude'] = TRUE;
  /* Sort criterion: Content: Post date */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'node';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
  /* Contextual filter: Content: Title */
  $handler->display->display_options['arguments']['title']['id'] = 'title';
  $handler->display->display_options['arguments']['title']['table'] = 'node';
  $handler->display->display_options['arguments']['title']['field'] = 'title';
  $handler->display->display_options['arguments']['title']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['title']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['title']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['title']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['title']['glossary'] = TRUE;
  $handler->display->display_options['arguments']['title']['limit'] = '1';
  $handler->display->display_options['arguments']['title']['case'] = 'upper';
  $handler->display->display_options['arguments']['title']['path_case'] = 'lower';
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'site' => 'site',
  );
  $handler->display->display_options['filters']['type']['group'] = 1;
  /* Filter criterion: Content: Title */
  $handler->display->display_options['filters']['title']['id'] = 'title';
  $handler->display->display_options['filters']['title']['table'] = 'node';
  $handler->display->display_options['filters']['title']['field'] = 'title';
  $handler->display->display_options['filters']['title']['operator'] = 'allwords';
  $handler->display->display_options['filters']['title']['group'] = 1;
  $handler->display->display_options['filters']['title']['exposed'] = TRUE;
  $handler->display->display_options['filters']['title']['expose']['operator_id'] = 'title_op';
  $handler->display->display_options['filters']['title']['expose']['label'] = 'Site name';
  $handler->display->display_options['filters']['title']['expose']['operator'] = 'title_op';
  $handler->display->display_options['filters']['title']['expose']['identifier'] = 'title';
  /* Filter criterion: Content: Organization type (field_csu_org_type) */
  $handler->display->display_options['filters']['field_csu_org_type_tid']['id'] = 'field_csu_org_type_tid';
  $handler->display->display_options['filters']['field_csu_org_type_tid']['table'] = 'field_data_field_csu_org_type';
  $handler->display->display_options['filters']['field_csu_org_type_tid']['field'] = 'field_csu_org_type_tid';
  $handler->display->display_options['filters']['field_csu_org_type_tid']['group'] = 1;
  $handler->display->display_options['filters']['field_csu_org_type_tid']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_csu_org_type_tid']['expose']['operator_id'] = 'field_csu_org_type_tid_op';
  $handler->display->display_options['filters']['field_csu_org_type_tid']['expose']['label'] = 'Organization type';
  $handler->display->display_options['filters']['field_csu_org_type_tid']['expose']['operator'] = 'field_csu_org_type_tid_op';
  $handler->display->display_options['filters']['field_csu_org_type_tid']['expose']['identifier'] = 'field_csu_org_type_tid';
  $handler->display->display_options['filters']['field_csu_org_type_tid']['expose']['multiple'] = TRUE;
  $handler->display->display_options['filters']['field_csu_org_type_tid']['type'] = 'select';
  $handler->display->display_options['filters']['field_csu_org_type_tid']['vocabulary'] = 'organization_type';
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
  /* Filter criterion: Field: Program(s) (field_site_restrict) */
  $handler->display->display_options['filters']['field_site_restrict_tid']['id'] = 'field_site_restrict_tid';
  $handler->display->display_options['filters']['field_site_restrict_tid']['table'] = 'field_data_field_site_restrict';
  $handler->display->display_options['filters']['field_site_restrict_tid']['field'] = 'field_site_restrict_tid';
  $handler->display->display_options['filters']['field_site_restrict_tid']['group'] = 1;
  $handler->display->display_options['filters']['field_site_restrict_tid']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_site_restrict_tid']['expose']['operator_id'] = 'field_site_restrict_tid_op';
  $handler->display->display_options['filters']['field_site_restrict_tid']['expose']['label'] = 'Programs';
  $handler->display->display_options['filters']['field_site_restrict_tid']['expose']['operator'] = 'field_site_restrict_tid_op';
  $handler->display->display_options['filters']['field_site_restrict_tid']['expose']['identifier'] = 'programs';
  $handler->display->display_options['filters']['field_site_restrict_tid']['expose']['multiple'] = TRUE;
  $handler->display->display_options['filters']['field_site_restrict_tid']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    4 => 0,
    6 => 0,
    3 => 0,
    5 => 0,
    7 => 0,
    8 => 0,
    9 => 0,
    10 => 0,
  );
  $handler->display->display_options['filters']['field_site_restrict_tid']['type'] = 'select';
  $handler->display->display_options['filters']['field_site_restrict_tid']['vocabulary'] = 'site_restrictions';
  $handler->display->display_options['filters']['field_site_restrict_tid']['error_message'] = FALSE;
  /* Filter criterion: Location: City */
  $handler->display->display_options['filters']['city']['id'] = 'city';
  $handler->display->display_options['filters']['city']['table'] = 'location';
  $handler->display->display_options['filters']['city']['field'] = 'city';
  $handler->display->display_options['filters']['city']['group'] = 1;
  $handler->display->display_options['filters']['city']['exposed'] = TRUE;
  $handler->display->display_options['filters']['city']['expose']['operator_id'] = 'city_op';
  $handler->display->display_options['filters']['city']['expose']['label'] = 'City';
  $handler->display->display_options['filters']['city']['expose']['operator'] = 'city_op';
  $handler->display->display_options['filters']['city']['expose']['identifier'] = 'city';
  /* Filter criterion: Location: Province */
  $handler->display->display_options['filters']['province']['id'] = 'province';
  $handler->display->display_options['filters']['province']['table'] = 'location';
  $handler->display->display_options['filters']['province']['field'] = 'province';
  $handler->display->display_options['filters']['province']['group'] = 1;
  $handler->display->display_options['filters']['province']['exposed'] = TRUE;
  $handler->display->display_options['filters']['province']['expose']['operator_id'] = 'province_op';
  $handler->display->display_options['filters']['province']['expose']['label'] = 'State';
  $handler->display->display_options['filters']['province']['expose']['operator'] = 'province_op';
  $handler->display->display_options['filters']['province']['expose']['identifier'] = 'province';
  /* Filter criterion: Workbench Moderation: State */
  $handler->display->display_options['filters']['state']['id'] = 'state';
  $handler->display->display_options['filters']['state']['table'] = 'workbench_moderation_node_history';
  $handler->display->display_options['filters']['state']['field'] = 'state';
  $handler->display->display_options['filters']['state']['group'] = 1;
  $handler->display->display_options['filters']['state']['exposed'] = TRUE;
  $handler->display->display_options['filters']['state']['expose']['operator_id'] = 'state_op';
  $handler->display->display_options['filters']['state']['expose']['label'] = 'Approval status';
  $handler->display->display_options['filters']['state']['expose']['operator'] = 'state_op';
  $handler->display->display_options['filters']['state']['expose']['identifier'] = 'status';
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 'All';
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['exposed'] = TRUE;
  $handler->display->display_options['filters']['status']['expose']['operator_id'] = '';
  $handler->display->display_options['filters']['status']['expose']['label'] = 'Active';
  $handler->display->display_options['filters']['status']['expose']['operator'] = 'status_op';
  $handler->display->display_options['filters']['status']['expose']['identifier'] = 'state';
  /* Filter criterion: Content: State lower district (field_district_state_lower) */
  $handler->display->display_options['filters']['field_district_state_lower_value']['id'] = 'field_district_state_lower_value';
  $handler->display->display_options['filters']['field_district_state_lower_value']['table'] = 'field_data_field_district_state_lower';
  $handler->display->display_options['filters']['field_district_state_lower_value']['field'] = 'field_district_state_lower_value';
  $handler->display->display_options['filters']['field_district_state_lower_value']['operator'] = 'starts';
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
  $handler->display->display_options['filters']['field_district_state_upper_value']['operator'] = 'starts';
  $handler->display->display_options['filters']['field_district_state_upper_value']['group'] = 1;
  $handler->display->display_options['filters']['field_district_state_upper_value']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_district_state_upper_value']['expose']['operator_id'] = 'field_district_state_upper_value_op';
  $handler->display->display_options['filters']['field_district_state_upper_value']['expose']['label'] = 'State upper district';
  $handler->display->display_options['filters']['field_district_state_upper_value']['expose']['operator'] = 'field_district_state_upper_value_op';
  $handler->display->display_options['filters']['field_district_state_upper_value']['expose']['identifier'] = 'field_district_state_upper_value';
  /* Filter criterion: Content: County (field_county) */
  $handler->display->display_options['filters']['field_county_value']['id'] = 'field_county_value';
  $handler->display->display_options['filters']['field_county_value']['table'] = 'field_data_field_county';
  $handler->display->display_options['filters']['field_county_value']['field'] = 'field_county_value';
  $handler->display->display_options['filters']['field_county_value']['operator'] = 'contains';
  $handler->display->display_options['filters']['field_county_value']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_county_value']['expose']['operator_id'] = 'field_county_value_op';
  $handler->display->display_options['filters']['field_county_value']['expose']['label'] = 'County';
  $handler->display->display_options['filters']['field_county_value']['expose']['operator'] = 'field_county_value_op';
  $handler->display->display_options['filters']['field_county_value']['expose']['identifier'] = 'field_county_value';

  /* Display: Manage sites page */
  $handler = $view->new_display('page', 'Manage sites page', 'page');
  $handler->display->display_options['path'] = 'site-list/manage';

  /* Display: Glossary attachment */
  $handler = $view->new_display('attachment', 'Glossary attachment', 'attachment_1');
  $handler->display->display_options['defaults']['query'] = FALSE;
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['defaults']['exposed_form'] = FALSE;
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['defaults']['header'] = FALSE;
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Contextual filter: Content: Title */
  $handler->display->display_options['arguments']['title']['id'] = 'title';
  $handler->display->display_options['arguments']['title']['table'] = 'node';
  $handler->display->display_options['arguments']['title']['field'] = 'title';
  $handler->display->display_options['arguments']['title']['default_action'] = 'summary';
  $handler->display->display_options['arguments']['title']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['title']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['title']['summary']['format'] = 'unformatted_summary';
  $handler->display->display_options['arguments']['title']['summary_options']['count'] = FALSE;
  $handler->display->display_options['arguments']['title']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['title']['summary_options']['inline'] = TRUE;
  $handler->display->display_options['arguments']['title']['summary_options']['separator'] = ' | ';
  $handler->display->display_options['arguments']['title']['specify_validation'] = TRUE;
  $handler->display->display_options['arguments']['title']['glossary'] = TRUE;
  $handler->display->display_options['arguments']['title']['limit'] = '1';
  $handler->display->display_options['arguments']['title']['case'] = 'upper';
  $handler->display->display_options['arguments']['title']['path_case'] = 'lower';
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  $handler->display->display_options['displays'] = array(
    'page' => 'page',
    'default' => 0,
  );
  $translatables['s4_manage_sites'] = array(
    t('Master'),
    t('Manage sites'),
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
    t('Title'),
    t('Programs'),
    t('Active'),
    t('Approval Status'),
    t('Updated date'),
    t('Edit'),
    t('Nid'),
    t('All'),
    t('Site name'),
    t('Organization type'),
    t('Issues addressed'),
    t('City'),
    t('State'),
    t('Approval status'),
    t('State lower district'),
    t('State upper district'),
    t('County'),
    t('Manage sites page'),
    t('Glossary attachment'),
    t('Apply'),
  );
  $export['s4_manage_sites'] = $view;

  $view = new view();
  $view->name = 's4_site_staff_students';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'S4: Site staff students';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Current students';
  $handler->display->display_options['css_class'] = 'quicksearch';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'type_permission';
  $handler->display->display_options['access']['permission'] = 'create signups for other users';
  $handler->display->display_options['access']['node_type'] = 'coordinator';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['exposed_form']['options']['submit_button'] = 'Search';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '50';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['pager']['options']['id'] = '0';
  $handler->display->display_options['pager']['options']['quantity'] = '9';
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['columns'] = array(
    'title' => 'title',
    'field_first_name' => 'field_first_name',
    'field_last_name' => 'field_last_name',
    'field_course' => 'field_course',
    'edit_node' => 'edit_node',
    'delete_node' => 'delete_node',
    'nothing' => 'nothing',
    'field_signup_start_date' => 'field_signup_start_date',
    'field_signup_last_date' => 'field_signup_last_date',
  );
  $handler->display->display_options['style_options']['default'] = 'field_signup_start_date';
  $handler->display->display_options['style_options']['info'] = array(
    'title' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_first_name' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_last_name' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_course' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'edit_node' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'delete_node' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'nothing' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_signup_start_date' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_signup_last_date' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
  );
  /* No results behavior: Global: Text area */
  $handler->display->display_options['empty']['area']['id'] = 'area';
  $handler->display->display_options['empty']['area']['table'] = 'views';
  $handler->display->display_options['empty']['area']['field'] = 'area';
  $handler->display->display_options['empty']['area']['content'] = 'There are currently no students placed with this site staff.';
  $handler->display->display_options['empty']['area']['format'] = 'filtered_html';
  /* Relationship: Content: User (field_user) */
  $handler->display->display_options['relationships']['field_user_uid']['id'] = 'field_user_uid';
  $handler->display->display_options['relationships']['field_user_uid']['table'] = 'field_data_field_user';
  $handler->display->display_options['relationships']['field_user_uid']['field'] = 'field_user_uid';
  $handler->display->display_options['relationships']['field_user_uid']['delta'] = '-1';
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  /* Field: Field: First Name */
  $handler->display->display_options['fields']['field_first_name']['id'] = 'field_first_name';
  $handler->display->display_options['fields']['field_first_name']['table'] = 'field_data_field_first_name';
  $handler->display->display_options['fields']['field_first_name']['field'] = 'field_first_name';
  $handler->display->display_options['fields']['field_first_name']['relationship'] = 'field_user_uid';
  /* Field: Field: Last Name */
  $handler->display->display_options['fields']['field_last_name']['id'] = 'field_last_name';
  $handler->display->display_options['fields']['field_last_name']['table'] = 'field_data_field_last_name';
  $handler->display->display_options['fields']['field_last_name']['field'] = 'field_last_name';
  $handler->display->display_options['fields']['field_last_name']['relationship'] = 'field_user_uid';
  /* Field: Field: Course */
  $handler->display->display_options['fields']['field_course']['id'] = 'field_course';
  $handler->display->display_options['fields']['field_course']['table'] = 'field_data_field_course';
  $handler->display->display_options['fields']['field_course']['field'] = 'field_course';
  /* Field: Content: Edit link */
  $handler->display->display_options['fields']['edit_node']['id'] = 'edit_node';
  $handler->display->display_options['fields']['edit_node']['table'] = 'views_entity_node';
  $handler->display->display_options['fields']['edit_node']['field'] = 'edit_node';
  $handler->display->display_options['fields']['edit_node']['label'] = '';
  $handler->display->display_options['fields']['edit_node']['exclude'] = TRUE;
  $handler->display->display_options['fields']['edit_node']['element_label_colon'] = FALSE;
  /* Field: Content: Delete link */
  $handler->display->display_options['fields']['delete_node']['id'] = 'delete_node';
  $handler->display->display_options['fields']['delete_node']['table'] = 'views_entity_node';
  $handler->display->display_options['fields']['delete_node']['field'] = 'delete_node';
  $handler->display->display_options['fields']['delete_node']['label'] = '';
  $handler->display->display_options['fields']['delete_node']['exclude'] = TRUE;
  $handler->display->display_options['fields']['delete_node']['element_label_colon'] = FALSE;
  /* Field: Global: Custom text */
  $handler->display->display_options['fields']['nothing']['id'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['table'] = 'views';
  $handler->display->display_options['fields']['nothing']['field'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['label'] = 'Options';
  $handler->display->display_options['fields']['nothing']['alter']['text'] = '[edit_node] | [delete_node]';
  /* Sort criterion: Content: Post date */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'node';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
  /* Contextual filter: Field: Site staff (field_coordinator) */
  $handler->display->display_options['arguments']['field_coordinator_nid']['id'] = 'field_coordinator_nid';
  $handler->display->display_options['arguments']['field_coordinator_nid']['table'] = 'field_data_field_coordinator';
  $handler->display->display_options['arguments']['field_coordinator_nid']['field'] = 'field_coordinator_nid';
  $handler->display->display_options['arguments']['field_coordinator_nid']['default_action'] = 'default';
  $handler->display->display_options['arguments']['field_coordinator_nid']['default_argument_type'] = 'node';
  $handler->display->display_options['arguments']['field_coordinator_nid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['field_coordinator_nid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['field_coordinator_nid']['summary_options']['items_per_page'] = '25';
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
    'signup' => 'signup',
  );
  /* Filter criterion: Content: First day of service (field_signup_start_date) */
  $handler->display->display_options['filters']['field_signup_start_date_value']['id'] = 'field_signup_start_date_value';
  $handler->display->display_options['filters']['field_signup_start_date_value']['table'] = 'field_data_field_signup_start_date';
  $handler->display->display_options['filters']['field_signup_start_date_value']['field'] = 'field_signup_start_date_value';
  $handler->display->display_options['filters']['field_signup_start_date_value']['operator'] = '<=';
  $handler->display->display_options['filters']['field_signup_start_date_value']['default_date'] = 'now';
  /* Filter criterion: Content: Last expected date of service (field_signup_last_date) */
  $handler->display->display_options['filters']['field_signup_last_date_value']['id'] = 'field_signup_last_date_value';
  $handler->display->display_options['filters']['field_signup_last_date_value']['table'] = 'field_data_field_signup_last_date';
  $handler->display->display_options['filters']['field_signup_last_date_value']['field'] = 'field_signup_last_date_value';
  $handler->display->display_options['filters']['field_signup_last_date_value']['operator'] = '>=';
  $handler->display->display_options['filters']['field_signup_last_date_value']['default_date'] = 'now - 7 days';

  /* Display: Block: Current students */
  $handler = $view->new_display('block', 'Block: Current students', 'block');

  /* Display: Page: All students */
  $handler = $view->new_display('page', 'Page: All students', 'page_1');
  $handler->display->display_options['defaults']['css_class'] = FALSE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  /* Field: Field: First Name */
  $handler->display->display_options['fields']['field_first_name']['id'] = 'field_first_name';
  $handler->display->display_options['fields']['field_first_name']['table'] = 'field_data_field_first_name';
  $handler->display->display_options['fields']['field_first_name']['field'] = 'field_first_name';
  $handler->display->display_options['fields']['field_first_name']['relationship'] = 'field_user_uid';
  /* Field: Field: Last Name */
  $handler->display->display_options['fields']['field_last_name']['id'] = 'field_last_name';
  $handler->display->display_options['fields']['field_last_name']['table'] = 'field_data_field_last_name';
  $handler->display->display_options['fields']['field_last_name']['field'] = 'field_last_name';
  $handler->display->display_options['fields']['field_last_name']['relationship'] = 'field_user_uid';
  /* Field: Field: Course */
  $handler->display->display_options['fields']['field_course']['id'] = 'field_course';
  $handler->display->display_options['fields']['field_course']['table'] = 'field_data_field_course';
  $handler->display->display_options['fields']['field_course']['field'] = 'field_course';
  /* Field: Content: First day of service */
  $handler->display->display_options['fields']['field_signup_start_date']['id'] = 'field_signup_start_date';
  $handler->display->display_options['fields']['field_signup_start_date']['table'] = 'field_data_field_signup_start_date';
  $handler->display->display_options['fields']['field_signup_start_date']['field'] = 'field_signup_start_date';
  $handler->display->display_options['fields']['field_signup_start_date']['label'] = 'Start';
  $handler->display->display_options['fields']['field_signup_start_date']['settings'] = array(
    'format_type' => 'short',
    'fromto' => 'both',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
    'show_repeat_rule' => 'show',
  );
  /* Field: Content: Last expected date of service */
  $handler->display->display_options['fields']['field_signup_last_date']['id'] = 'field_signup_last_date';
  $handler->display->display_options['fields']['field_signup_last_date']['table'] = 'field_data_field_signup_last_date';
  $handler->display->display_options['fields']['field_signup_last_date']['field'] = 'field_signup_last_date';
  $handler->display->display_options['fields']['field_signup_last_date']['label'] = 'End';
  $handler->display->display_options['fields']['field_signup_last_date']['settings'] = array(
    'format_type' => 'short',
    'fromto' => 'both',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
    'show_repeat_rule' => 'show',
  );
  /* Field: Content: Edit link */
  $handler->display->display_options['fields']['edit_node']['id'] = 'edit_node';
  $handler->display->display_options['fields']['edit_node']['table'] = 'views_entity_node';
  $handler->display->display_options['fields']['edit_node']['field'] = 'edit_node';
  $handler->display->display_options['fields']['edit_node']['label'] = '';
  $handler->display->display_options['fields']['edit_node']['exclude'] = TRUE;
  $handler->display->display_options['fields']['edit_node']['element_label_colon'] = FALSE;
  /* Field: Content: Delete link */
  $handler->display->display_options['fields']['delete_node']['id'] = 'delete_node';
  $handler->display->display_options['fields']['delete_node']['table'] = 'views_entity_node';
  $handler->display->display_options['fields']['delete_node']['field'] = 'delete_node';
  $handler->display->display_options['fields']['delete_node']['label'] = '';
  $handler->display->display_options['fields']['delete_node']['exclude'] = TRUE;
  $handler->display->display_options['fields']['delete_node']['element_label_colon'] = FALSE;
  /* Field: Global: Custom text */
  $handler->display->display_options['fields']['nothing']['id'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['table'] = 'views';
  $handler->display->display_options['fields']['nothing']['field'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['label'] = 'Options';
  $handler->display->display_options['fields']['nothing']['alter']['text'] = '[edit_node] | [delete_node]';
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Contextual filter: Field: Site staff (field_coordinator) */
  $handler->display->display_options['arguments']['field_coordinator_nid']['id'] = 'field_coordinator_nid';
  $handler->display->display_options['arguments']['field_coordinator_nid']['table'] = 'field_data_field_coordinator';
  $handler->display->display_options['arguments']['field_coordinator_nid']['field'] = 'field_coordinator_nid';
  $handler->display->display_options['arguments']['field_coordinator_nid']['default_action'] = 'default';
  $handler->display->display_options['arguments']['field_coordinator_nid']['title_enable'] = TRUE;
  $handler->display->display_options['arguments']['field_coordinator_nid']['title'] = '%1';
  $handler->display->display_options['arguments']['field_coordinator_nid']['default_argument_type'] = 'node';
  $handler->display->display_options['arguments']['field_coordinator_nid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['field_coordinator_nid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['field_coordinator_nid']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
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
    'signup' => 'signup',
  );
  $handler->display->display_options['filters']['type']['group'] = 1;
  /* Filter criterion: Field: First Name (field_first_name) */
  $handler->display->display_options['filters']['field_first_name_value']['id'] = 'field_first_name_value';
  $handler->display->display_options['filters']['field_first_name_value']['table'] = 'field_data_field_first_name';
  $handler->display->display_options['filters']['field_first_name_value']['field'] = 'field_first_name_value';
  $handler->display->display_options['filters']['field_first_name_value']['relationship'] = 'field_user_uid';
  $handler->display->display_options['filters']['field_first_name_value']['operator'] = 'starts';
  $handler->display->display_options['filters']['field_first_name_value']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_first_name_value']['expose']['operator_id'] = 'field_first_name_value_op';
  $handler->display->display_options['filters']['field_first_name_value']['expose']['label'] = 'First name';
  $handler->display->display_options['filters']['field_first_name_value']['expose']['operator'] = 'field_first_name_value_op';
  $handler->display->display_options['filters']['field_first_name_value']['expose']['identifier'] = 'field_first_name_value';
  /* Filter criterion: Field: Last Name (field_last_name) */
  $handler->display->display_options['filters']['field_last_name_value']['id'] = 'field_last_name_value';
  $handler->display->display_options['filters']['field_last_name_value']['table'] = 'field_data_field_last_name';
  $handler->display->display_options['filters']['field_last_name_value']['field'] = 'field_last_name_value';
  $handler->display->display_options['filters']['field_last_name_value']['relationship'] = 'field_user_uid';
  $handler->display->display_options['filters']['field_last_name_value']['operator'] = 'starts';
  $handler->display->display_options['filters']['field_last_name_value']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_last_name_value']['expose']['operator_id'] = 'field_last_name_value_op';
  $handler->display->display_options['filters']['field_last_name_value']['expose']['label'] = 'Last name';
  $handler->display->display_options['filters']['field_last_name_value']['expose']['operator'] = 'field_last_name_value_op';
  $handler->display->display_options['filters']['field_last_name_value']['expose']['identifier'] = 'field_last_name_value';
  $handler->display->display_options['path'] = 'node/%/site-staff-students';
  $handler->display->display_options['menu']['type'] = 'tab';
  $handler->display->display_options['menu']['title'] = 'All students';
  $handler->display->display_options['menu']['weight'] = '0';
  $handler->display->display_options['menu']['context'] = 0;
  $translatables['s4_site_staff_students'] = array(
    t('Master'),
    t('Current students'),
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
    t('There are currently no students placed with this site staff.'),
    t('field_user'),
    t('Title'),
    t('First Name'),
    t('Last Name'),
    t('Course'),
    t('Options'),
    t('[edit_node] | [delete_node]'),
    t('All'),
    t('Block: Current students'),
    t('Page: All students'),
    t('Start'),
    t('End'),
    t('%1'),
    t('First name'),
    t('Last name'),
  );
  $export['s4_site_staff_students'] = $view;

  $view = new view();
  $view->name = 'site_coordinators';
  $view->description = 'Listings of site coordinators';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'S4: Site staff';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Site Staff';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'type_role';
  $handler->display->display_options['access']['role'] = array(
    6 => '6',
  );
  $handler->display->display_options['access']['node_type'] = 'site';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['query']['options']['query_comment'] = FALSE;
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['exposed_form']['options']['submit_button'] = 'Search';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '15';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['pager']['options']['id'] = '0';
  $handler->display->display_options['style_plugin'] = 'table';
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = 'Name';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['title']['element_type'] = 'h3';
  $handler->display->display_options['fields']['title']['element_class'] = 'coordinator-name';
  $handler->display->display_options['fields']['title']['element_default_classes'] = FALSE;
  /* Field: Field: Program(s) */
  $handler->display->display_options['fields']['field_site_restrict']['id'] = 'field_site_restrict';
  $handler->display->display_options['fields']['field_site_restrict']['table'] = 'field_data_field_site_restrict';
  $handler->display->display_options['fields']['field_site_restrict']['field'] = 'field_site_restrict';
  $handler->display->display_options['fields']['field_site_restrict']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_site_restrict']['delta_offset'] = '0';
  /* Field: Content: Main phone number */
  $handler->display->display_options['fields']['field_phone']['id'] = 'field_phone';
  $handler->display->display_options['fields']['field_phone']['table'] = 'field_data_field_phone';
  $handler->display->display_options['fields']['field_phone']['field'] = 'field_phone';
  $handler->display->display_options['fields']['field_phone']['label'] = 'Phone';
  $handler->display->display_options['fields']['field_phone']['click_sort_column'] = 'number';
  $handler->display->display_options['fields']['field_phone']['type'] = 'local_phone_number';
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
  $handler->display->display_options['arguments']['field_site_nid']['title_enable'] = TRUE;
  $handler->display->display_options['arguments']['field_site_nid']['title'] = '%1';
  $handler->display->display_options['arguments']['field_site_nid']['default_argument_type'] = 'node';
  $handler->display->display_options['arguments']['field_site_nid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['field_site_nid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['field_site_nid']['summary_options']['items_per_page'] = '25';
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

  /* Display: Page: Student list of site staff */
  $handler = $view->new_display('page', 'Page: Student list of site staff', 'page_1');
  $handler->display->display_options['defaults']['access'] = FALSE;
  $handler->display->display_options['access']['type'] = 'role';
  $handler->display->display_options['access']['role'] = array(
    2 => '2',
  );
  $handler->display->display_options['defaults']['header'] = FALSE;
  /* Header: Global: Text area */
  $handler->display->display_options['header']['area']['id'] = 'area';
  $handler->display->display_options['header']['area']['table'] = 'views';
  $handler->display->display_options['header']['area']['field'] = 'area';
  $handler->display->display_options['header']['area']['content'] = '<p class="lead">Select a coordinator who will be working with you during your service.</p>';
  $handler->display->display_options['header']['area']['format'] = 'full_html';
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  /* Field: Field: Program(s) */
  $handler->display->display_options['fields']['field_site_restrict']['id'] = 'field_site_restrict';
  $handler->display->display_options['fields']['field_site_restrict']['table'] = 'field_data_field_site_restrict';
  $handler->display->display_options['fields']['field_site_restrict']['field'] = 'field_site_restrict';
  $handler->display->display_options['fields']['field_site_restrict']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_site_restrict']['delta_offset'] = '0';
  /* Field: Content: Job title */
  $handler->display->display_options['fields']['field_job_title']['id'] = 'field_job_title';
  $handler->display->display_options['fields']['field_job_title']['table'] = 'field_data_field_job_title';
  $handler->display->display_options['fields']['field_job_title']['field'] = 'field_job_title';
  /* Field: Content: Email address */
  $handler->display->display_options['fields']['field_email']['id'] = 'field_email';
  $handler->display->display_options['fields']['field_email']['table'] = 'field_data_field_email';
  $handler->display->display_options['fields']['field_email']['field'] = 'field_email';
  $handler->display->display_options['fields']['field_email']['label'] = 'Email';
  /* Field: Content: Main phone number */
  $handler->display->display_options['fields']['field_phone']['id'] = 'field_phone';
  $handler->display->display_options['fields']['field_phone']['table'] = 'field_data_field_phone';
  $handler->display->display_options['fields']['field_phone']['field'] = 'field_phone';
  $handler->display->display_options['fields']['field_phone']['label'] = 'Phone';
  $handler->display->display_options['fields']['field_phone']['click_sort_column'] = 'number';
  $handler->display->display_options['fields']['field_phone']['type'] = 's4_sites_local_phone_number';
  $handler->display->display_options['fields']['field_phone']['delta_offset'] = '0';
  /* Field: Signup: User select coordinator */
  $handler->display->display_options['fields']['faculty_coordinator_select']['id'] = 'faculty_coordinator_select';
  $handler->display->display_options['fields']['faculty_coordinator_select']['table'] = 's4_signup';
  $handler->display->display_options['fields']['faculty_coordinator_select']['field'] = 'faculty_coordinator_select';
  $handler->display->display_options['fields']['faculty_coordinator_select']['label'] = 'Select';
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Contextual filter: Content: Site (field_site) */
  $handler->display->display_options['arguments']['field_site_nid']['id'] = 'field_site_nid';
  $handler->display->display_options['arguments']['field_site_nid']['table'] = 'field_data_field_site';
  $handler->display->display_options['arguments']['field_site_nid']['field'] = 'field_site_nid';
  $handler->display->display_options['arguments']['field_site_nid']['default_action'] = 'default';
  $handler->display->display_options['arguments']['field_site_nid']['default_argument_type'] = 'node';
  $handler->display->display_options['arguments']['field_site_nid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['field_site_nid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['field_site_nid']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'coordinator' => 'coordinator',
  );
  /* Filter criterion: Content: Active (field_site_staff_active) */
  $handler->display->display_options['filters']['field_site_staff_active_value']['id'] = 'field_site_staff_active_value';
  $handler->display->display_options['filters']['field_site_staff_active_value']['table'] = 'field_data_field_site_staff_active';
  $handler->display->display_options['filters']['field_site_staff_active_value']['field'] = 'field_site_staff_active_value';
  $handler->display->display_options['filters']['field_site_staff_active_value']['value'] = array(
    1 => '1',
  );
  /* Filter criterion: Content: Students can register with this staff (field_staff_signup_available) */
  $handler->display->display_options['filters']['field_staff_signup_available_value']['id'] = 'field_staff_signup_available_value';
  $handler->display->display_options['filters']['field_staff_signup_available_value']['table'] = 'field_data_field_staff_signup_available';
  $handler->display->display_options['filters']['field_staff_signup_available_value']['field'] = 'field_staff_signup_available_value';
  $handler->display->display_options['filters']['field_staff_signup_available_value']['value'] = array(
    1 => '1',
  );
  $handler->display->display_options['path'] = 'sites/%/coordinators';

  /* Display: Page: Site staff tab */
  $handler = $view->new_display('page', 'Page: Site staff tab', 'page_2');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Site staff';
  $handler->display->display_options['defaults']['css_class'] = FALSE;
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
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Nid */
  $handler->display->display_options['fields']['nid']['id'] = 'nid';
  $handler->display->display_options['fields']['nid']['table'] = 'node';
  $handler->display->display_options['fields']['nid']['field'] = 'nid';
  $handler->display->display_options['fields']['nid']['label'] = '';
  $handler->display->display_options['fields']['nid']['exclude'] = TRUE;
  $handler->display->display_options['fields']['nid']['element_label_colon'] = FALSE;
  /* Field: Field: Last Name */
  $handler->display->display_options['fields']['field_last_name']['id'] = 'field_last_name';
  $handler->display->display_options['fields']['field_last_name']['table'] = 'field_data_field_last_name';
  $handler->display->display_options['fields']['field_last_name']['field'] = 'field_last_name';
  $handler->display->display_options['fields']['field_last_name']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['field_last_name']['alter']['path'] = 'node/[nid]';
  $handler->display->display_options['fields']['field_last_name']['hide_alter_empty'] = FALSE;
  /* Field: Field: First Name */
  $handler->display->display_options['fields']['field_first_name']['id'] = 'field_first_name';
  $handler->display->display_options['fields']['field_first_name']['table'] = 'field_data_field_first_name';
  $handler->display->display_options['fields']['field_first_name']['field'] = 'field_first_name';
  $handler->display->display_options['fields']['field_first_name']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['field_first_name']['alter']['path'] = 'node/[nid]';
  $handler->display->display_options['fields']['field_first_name']['hide_alter_empty'] = FALSE;
  /* Field: Field: Program(s) */
  $handler->display->display_options['fields']['field_site_restrict']['id'] = 'field_site_restrict';
  $handler->display->display_options['fields']['field_site_restrict']['table'] = 'field_data_field_site_restrict';
  $handler->display->display_options['fields']['field_site_restrict']['field'] = 'field_site_restrict';
  $handler->display->display_options['fields']['field_site_restrict']['type'] = 'taxonomy_term_reference_plain';
  $handler->display->display_options['fields']['field_site_restrict']['delta_offset'] = '0';
  /* Field: Content: Main phone number */
  $handler->display->display_options['fields']['field_phone']['id'] = 'field_phone';
  $handler->display->display_options['fields']['field_phone']['table'] = 'field_data_field_phone';
  $handler->display->display_options['fields']['field_phone']['field'] = 'field_phone';
  $handler->display->display_options['fields']['field_phone']['label'] = 'Phone';
  $handler->display->display_options['fields']['field_phone']['hide_alter_empty'] = FALSE;
  $handler->display->display_options['fields']['field_phone']['click_sort_column'] = 'number';
  $handler->display->display_options['fields']['field_phone']['type'] = 's4_sites_local_phone_number';
  $handler->display->display_options['fields']['field_phone']['delta_offset'] = '0';
  /* Field: Content: Email address */
  $handler->display->display_options['fields']['field_email']['id'] = 'field_email';
  $handler->display->display_options['fields']['field_email']['table'] = 'field_data_field_email';
  $handler->display->display_options['fields']['field_email']['field'] = 'field_email';
  $handler->display->display_options['fields']['field_email']['label'] = 'Email';
  $handler->display->display_options['fields']['field_email']['hide_alter_empty'] = FALSE;
  /* Field: Content: Role */
  $handler->display->display_options['fields']['field_staff_role']['id'] = 'field_staff_role';
  $handler->display->display_options['fields']['field_staff_role']['table'] = 'field_data_field_staff_role';
  $handler->display->display_options['fields']['field_staff_role']['field'] = 'field_staff_role';
  $handler->display->display_options['fields']['field_staff_role']['hide_alter_empty'] = FALSE;
  $handler->display->display_options['fields']['field_staff_role']['type'] = 'taxonomy_term_reference_plain';
  /* Field: Content: Job title */
  $handler->display->display_options['fields']['field_job_title']['id'] = 'field_job_title';
  $handler->display->display_options['fields']['field_job_title']['table'] = 'field_data_field_job_title';
  $handler->display->display_options['fields']['field_job_title']['field'] = 'field_job_title';
  /* Field: Content: Maximum number of students your site can accept at any given time */
  $handler->display->display_options['fields']['field_signups_max']['id'] = 'field_signups_max';
  $handler->display->display_options['fields']['field_signups_max']['table'] = 'field_data_field_signups_max';
  $handler->display->display_options['fields']['field_signups_max']['field'] = 'field_signups_max';
  $handler->display->display_options['fields']['field_signups_max']['label'] = 'Max students';
  $handler->display->display_options['fields']['field_signups_max']['hide_alter_empty'] = FALSE;
  $handler->display->display_options['fields']['field_signups_max']['settings'] = array(
    'thousand_separator' => ',',
    'prefix_suffix' => 0,
  );
  /* Field: Content: Students can register with this staff */
  $handler->display->display_options['fields']['field_staff_signup_available']['id'] = 'field_staff_signup_available';
  $handler->display->display_options['fields']['field_staff_signup_available']['table'] = 'field_data_field_staff_signup_available';
  $handler->display->display_options['fields']['field_staff_signup_available']['field'] = 'field_staff_signup_available';
  $handler->display->display_options['fields']['field_staff_signup_available']['label'] = 'Register?';
  $handler->display->display_options['fields']['field_staff_signup_available']['hide_alter_empty'] = FALSE;
  /* Field: Content: Active */
  $handler->display->display_options['fields']['field_site_staff_active']['id'] = 'field_site_staff_active';
  $handler->display->display_options['fields']['field_site_staff_active']['table'] = 'field_data_field_site_staff_active';
  $handler->display->display_options['fields']['field_site_staff_active']['field'] = 'field_site_staff_active';
  /* Field: Global: Custom text */
  $handler->display->display_options['fields']['nothing_1']['id'] = 'nothing_1';
  $handler->display->display_options['fields']['nothing_1']['table'] = 'views';
  $handler->display->display_options['fields']['nothing_1']['field'] = 'nothing';
  $handler->display->display_options['fields']['nothing_1']['label'] = 'Edit';
  $handler->display->display_options['fields']['nothing_1']['alter']['text'] = 'edit';
  $handler->display->display_options['fields']['nothing_1']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['nothing_1']['alter']['path'] = 'node/[nid]/edit';
  $handler->display->display_options['fields']['nothing_1']['alter']['link_class'] = 'btn btn-small btn-info';
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'coordinator' => 'coordinator',
  );
  $handler->display->display_options['filters']['type']['group'] = 1;
  /* Filter criterion: Content: Active (field_site_staff_active) */
  $handler->display->display_options['filters']['field_site_staff_active_value']['id'] = 'field_site_staff_active_value';
  $handler->display->display_options['filters']['field_site_staff_active_value']['table'] = 'field_data_field_site_staff_active';
  $handler->display->display_options['filters']['field_site_staff_active_value']['field'] = 'field_site_staff_active_value';
  $handler->display->display_options['filters']['field_site_staff_active_value']['value'] = array(
    1 => '1',
  );
  $handler->display->display_options['filters']['field_site_staff_active_value']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_site_staff_active_value']['expose']['operator_id'] = 'field_site_staff_active_value_op';
  $handler->display->display_options['filters']['field_site_staff_active_value']['expose']['label'] = 'Active';
  $handler->display->display_options['filters']['field_site_staff_active_value']['expose']['operator'] = 'field_site_staff_active_value_op';
  $handler->display->display_options['filters']['field_site_staff_active_value']['expose']['identifier'] = 'field_site_staff_active_value';
  /* Filter criterion: Field: First Name (field_first_name) */
  $handler->display->display_options['filters']['field_first_name_value']['id'] = 'field_first_name_value';
  $handler->display->display_options['filters']['field_first_name_value']['table'] = 'field_data_field_first_name';
  $handler->display->display_options['filters']['field_first_name_value']['field'] = 'field_first_name_value';
  $handler->display->display_options['filters']['field_first_name_value']['operator'] = 'starts';
  $handler->display->display_options['filters']['field_first_name_value']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_first_name_value']['expose']['operator_id'] = 'field_first_name_value_op';
  $handler->display->display_options['filters']['field_first_name_value']['expose']['label'] = 'First name';
  $handler->display->display_options['filters']['field_first_name_value']['expose']['operator'] = 'field_first_name_value_op';
  $handler->display->display_options['filters']['field_first_name_value']['expose']['identifier'] = 'field_first_name_value';
  /* Filter criterion: Field: Last Name (field_last_name) */
  $handler->display->display_options['filters']['field_last_name_value']['id'] = 'field_last_name_value';
  $handler->display->display_options['filters']['field_last_name_value']['table'] = 'field_data_field_last_name';
  $handler->display->display_options['filters']['field_last_name_value']['field'] = 'field_last_name_value';
  $handler->display->display_options['filters']['field_last_name_value']['operator'] = 'starts';
  $handler->display->display_options['filters']['field_last_name_value']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_last_name_value']['expose']['operator_id'] = 'field_last_name_value_op';
  $handler->display->display_options['filters']['field_last_name_value']['expose']['label'] = 'Last name';
  $handler->display->display_options['filters']['field_last_name_value']['expose']['operator'] = 'field_last_name_value_op';
  $handler->display->display_options['filters']['field_last_name_value']['expose']['identifier'] = 'field_last_name_value';
  /* Filter criterion: Field: Program(s) (field_site_restrict) */
  $handler->display->display_options['filters']['field_site_restrict_tid']['id'] = 'field_site_restrict_tid';
  $handler->display->display_options['filters']['field_site_restrict_tid']['table'] = 'field_data_field_site_restrict';
  $handler->display->display_options['filters']['field_site_restrict_tid']['field'] = 'field_site_restrict_tid';
  $handler->display->display_options['filters']['field_site_restrict_tid']['value'] = '';
  $handler->display->display_options['filters']['field_site_restrict_tid']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_site_restrict_tid']['expose']['operator_id'] = 'field_site_restrict_tid_op';
  $handler->display->display_options['filters']['field_site_restrict_tid']['expose']['label'] = 'Program';
  $handler->display->display_options['filters']['field_site_restrict_tid']['expose']['operator'] = 'field_site_restrict_tid_op';
  $handler->display->display_options['filters']['field_site_restrict_tid']['expose']['identifier'] = 'field_site_restrict_tid';
  $handler->display->display_options['filters']['field_site_restrict_tid']['type'] = 'select';
  $handler->display->display_options['filters']['field_site_restrict_tid']['vocabulary'] = 'site_restrictions';
  $handler->display->display_options['filters']['field_site_restrict_tid']['error_message'] = FALSE;
  $handler->display->display_options['path'] = 'node/%/site-staff';
  $handler->display->display_options['menu']['type'] = 'tab';
  $handler->display->display_options['menu']['title'] = 'Site Staff';
  $handler->display->display_options['menu']['weight'] = '0';

  /* Display: Block: Active site staff */
  $handler = $view->new_display('block', 'Block: Active site staff', 'block_1');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['defaults']['access'] = FALSE;
  $handler->display->display_options['access']['type'] = 'role';
  $handler->display->display_options['access']['role'] = array(
    2 => '2',
  );
  $handler->display->display_options['defaults']['fields'] = FALSE;
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
  /* Field: Field: Program(s) */
  $handler->display->display_options['fields']['field_site_restrict']['id'] = 'field_site_restrict';
  $handler->display->display_options['fields']['field_site_restrict']['table'] = 'field_data_field_site_restrict';
  $handler->display->display_options['fields']['field_site_restrict']['field'] = 'field_site_restrict';
  $handler->display->display_options['fields']['field_site_restrict']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_site_restrict']['type'] = 'taxonomy_term_reference_plain';
  $handler->display->display_options['fields']['field_site_restrict']['delta_offset'] = '0';
  /* Field: Content: Job title */
  $handler->display->display_options['fields']['field_job_title']['id'] = 'field_job_title';
  $handler->display->display_options['fields']['field_job_title']['table'] = 'field_data_field_job_title';
  $handler->display->display_options['fields']['field_job_title']['field'] = 'field_job_title';
  $handler->display->display_options['fields']['field_job_title']['element_label_colon'] = FALSE;
  /* Field: Content: Main phone number */
  $handler->display->display_options['fields']['field_phone']['id'] = 'field_phone';
  $handler->display->display_options['fields']['field_phone']['table'] = 'field_data_field_phone';
  $handler->display->display_options['fields']['field_phone']['field'] = 'field_phone';
  $handler->display->display_options['fields']['field_phone']['label'] = 'Phone';
  $handler->display->display_options['fields']['field_phone']['click_sort_column'] = 'number';
  $handler->display->display_options['fields']['field_phone']['type'] = 's4_sites_local_phone_number';
  $handler->display->display_options['fields']['field_phone']['delta_offset'] = '0';
  /* Field: Content: Email address */
  $handler->display->display_options['fields']['field_email']['id'] = 'field_email';
  $handler->display->display_options['fields']['field_email']['table'] = 'field_data_field_email';
  $handler->display->display_options['fields']['field_email']['field'] = 'field_email';
  /* Field: Content: Edit link */
  $handler->display->display_options['fields']['edit_node']['id'] = 'edit_node';
  $handler->display->display_options['fields']['edit_node']['table'] = 'views_entity_node';
  $handler->display->display_options['fields']['edit_node']['field'] = 'edit_node';
  $handler->display->display_options['fields']['edit_node']['label'] = 'Edit';
  $handler->display->display_options['defaults']['sorts'] = FALSE;
  /* Sort criterion: Field: First Name (field_first_name) */
  $handler->display->display_options['sorts']['field_first_name_value']['id'] = 'field_first_name_value';
  $handler->display->display_options['sorts']['field_first_name_value']['table'] = 'field_data_field_first_name';
  $handler->display->display_options['sorts']['field_first_name_value']['field'] = 'field_first_name_value';
  /* Sort criterion: Field: Last Name (field_last_name) */
  $handler->display->display_options['sorts']['field_last_name_value']['id'] = 'field_last_name_value';
  $handler->display->display_options['sorts']['field_last_name_value']['table'] = 'field_data_field_last_name';
  $handler->display->display_options['sorts']['field_last_name_value']['field'] = 'field_last_name_value';
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Contextual filter: Content: Site (field_site) */
  $handler->display->display_options['arguments']['field_site_nid']['id'] = 'field_site_nid';
  $handler->display->display_options['arguments']['field_site_nid']['table'] = 'field_data_field_site';
  $handler->display->display_options['arguments']['field_site_nid']['field'] = 'field_site_nid';
  $handler->display->display_options['arguments']['field_site_nid']['default_action'] = 'default';
  $handler->display->display_options['arguments']['field_site_nid']['default_argument_type'] = 'node';
  $handler->display->display_options['arguments']['field_site_nid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['field_site_nid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['field_site_nid']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
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
  /* Filter criterion: Content: Active (field_site_staff_active) */
  $handler->display->display_options['filters']['field_site_staff_active_value']['id'] = 'field_site_staff_active_value';
  $handler->display->display_options['filters']['field_site_staff_active_value']['table'] = 'field_data_field_site_staff_active';
  $handler->display->display_options['filters']['field_site_staff_active_value']['field'] = 'field_site_staff_active_value';
  $handler->display->display_options['filters']['field_site_staff_active_value']['value'] = array(
    1 => '1',
  );
  $handler->display->display_options['block_description'] = 'Site staff';
  $translatables['site_coordinators'] = array(
    t('Master'),
    t('Site Staff'),
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
    t('Name'),
    t('Program(s)'),
    t('Phone'),
    t('All'),
    t('%1'),
    t('Page: Student list of site staff'),
    t('<p class="lead">Select a coordinator who will be working with you during your service.</p>'),
    t('Job title'),
    t('Email'),
    t('Select'),
    t('Page: Site staff tab'),
    t('Site staff'),
    t('Last Name'),
    t('First Name'),
    t('Role'),
    t('Max students'),
    t('Register?'),
    t('Active'),
    t('Edit'),
    t('edit'),
    t('First name'),
    t('Last name'),
    t('Program'),
    t('Block: Active site staff'),
    t('Email address'),
  );
  $export['site_coordinators'] = $view;

  $view = new view();
  $view->name = 'site_fields';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'S4: Site fields';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['query']['options']['query_comment'] = FALSE;
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '1';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Field: Content: Organization type */
  $handler->display->display_options['fields']['field_csu_org_type']['id'] = 'field_csu_org_type';
  $handler->display->display_options['fields']['field_csu_org_type']['table'] = 'field_data_field_csu_org_type';
  $handler->display->display_options['fields']['field_csu_org_type']['field'] = 'field_csu_org_type';
  $handler->display->display_options['fields']['field_csu_org_type']['element_label_type'] = 'strong';
  $handler->display->display_options['fields']['field_csu_org_type']['hide_empty'] = TRUE;
  $handler->display->display_options['fields']['field_csu_org_type']['hide_alter_empty'] = FALSE;
  $handler->display->display_options['fields']['field_csu_org_type']['type'] = 'taxonomy_term_reference_plain';
  /* Field: Content: Issues addressed */
  $handler->display->display_options['fields']['field_csu_facility']['id'] = 'field_csu_facility';
  $handler->display->display_options['fields']['field_csu_facility']['table'] = 'field_data_field_csu_facility';
  $handler->display->display_options['fields']['field_csu_facility']['field'] = 'field_csu_facility';
  $handler->display->display_options['fields']['field_csu_facility']['element_label_type'] = 'strong';
  $handler->display->display_options['fields']['field_csu_facility']['hide_empty'] = TRUE;
  $handler->display->display_options['fields']['field_csu_facility']['hide_alter_empty'] = FALSE;
  $handler->display->display_options['fields']['field_csu_facility']['type'] = 'taxonomy_term_reference_plain';
  /* Field: Content: Website */
  $handler->display->display_options['fields']['field_website']['id'] = 'field_website';
  $handler->display->display_options['fields']['field_website']['table'] = 'field_data_field_website';
  $handler->display->display_options['fields']['field_website']['field'] = 'field_website';
  $handler->display->display_options['fields']['field_website']['element_label_type'] = 'strong';
  $handler->display->display_options['fields']['field_website']['hide_empty'] = TRUE;
  $handler->display->display_options['fields']['field_website']['hide_alter_empty'] = FALSE;
  $handler->display->display_options['fields']['field_website']['click_sort_column'] = 'url';
  $handler->display->display_options['fields']['field_website']['type'] = 'url';
  /* Field: Content: Social network page */
  $handler->display->display_options['fields']['field_site_facebook_page']['id'] = 'field_site_facebook_page';
  $handler->display->display_options['fields']['field_site_facebook_page']['table'] = 'field_data_field_site_facebook_page';
  $handler->display->display_options['fields']['field_site_facebook_page']['field'] = 'field_site_facebook_page';
  $handler->display->display_options['fields']['field_site_facebook_page']['element_label_type'] = 'strong';
  $handler->display->display_options['fields']['field_site_facebook_page']['hide_empty'] = TRUE;
  $handler->display->display_options['fields']['field_site_facebook_page']['hide_alter_empty'] = FALSE;
  $handler->display->display_options['fields']['field_site_facebook_page']['click_sort_column'] = 'url';
  $handler->display->display_options['fields']['field_site_facebook_page']['type'] = 'url';
  /* Field: Content: Main phone number */
  $handler->display->display_options['fields']['field_phone']['id'] = 'field_phone';
  $handler->display->display_options['fields']['field_phone']['table'] = 'field_data_field_phone';
  $handler->display->display_options['fields']['field_phone']['field'] = 'field_phone';
  $handler->display->display_options['fields']['field_phone']['element_label_type'] = 'strong';
  $handler->display->display_options['fields']['field_phone']['hide_empty'] = TRUE;
  $handler->display->display_options['fields']['field_phone']['hide_alter_empty'] = FALSE;
  $handler->display->display_options['fields']['field_phone']['click_sort_column'] = 'number';
  $handler->display->display_options['fields']['field_phone']['type'] = 's4_sites_local_phone_number';
  /* Field: Content: Location(s) */
  $handler->display->display_options['fields']['field_location']['id'] = 'field_location';
  $handler->display->display_options['fields']['field_location']['table'] = 'field_data_field_location';
  $handler->display->display_options['fields']['field_location']['field'] = 'field_location';
  $handler->display->display_options['fields']['field_location']['element_label_type'] = 'strong';
  $handler->display->display_options['fields']['field_location']['hide_empty'] = TRUE;
  $handler->display->display_options['fields']['field_location']['hide_alter_empty'] = FALSE;
  $handler->display->display_options['fields']['field_location']['type'] = 's4_sites_address';
  $handler->display->display_options['fields']['field_location']['delta_offset'] = '0';
  /* Field: Content: What languages would you like students to speak other than English? */
  $handler->display->display_options['fields']['field_site_language']['id'] = 'field_site_language';
  $handler->display->display_options['fields']['field_site_language']['table'] = 'field_data_field_site_language';
  $handler->display->display_options['fields']['field_site_language']['field'] = 'field_site_language';
  $handler->display->display_options['fields']['field_site_language']['label'] = 'Suggested languages';
  $handler->display->display_options['fields']['field_site_language']['element_label_type'] = 'strong';
  $handler->display->display_options['fields']['field_site_language']['hide_empty'] = TRUE;
  $handler->display->display_options['fields']['field_site_language']['hide_alter_empty'] = FALSE;
  /* Field: Content: How many people does your organization serve? */
  $handler->display->display_options['fields']['field_population_size']['id'] = 'field_population_size';
  $handler->display->display_options['fields']['field_population_size']['table'] = 'field_data_field_population_size';
  $handler->display->display_options['fields']['field_population_size']['field'] = 'field_population_size';
  $handler->display->display_options['fields']['field_population_size']['label'] = 'Number of people served';
  $handler->display->display_options['fields']['field_population_size']['element_label_type'] = 'strong';
  $handler->display->display_options['fields']['field_population_size']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_population_size']['hide_empty'] = TRUE;
  $handler->display->display_options['fields']['field_population_size']['hide_alter_empty'] = FALSE;
  $handler->display->display_options['fields']['field_population_size']['settings'] = array(
    'thousand_separator' => ' ',
    'prefix_suffix' => 1,
  );
  /* Field: Content: By percentage, what is the demographic of the population you serve? */
  $handler->display->display_options['fields']['field_site_demographics']['id'] = 'field_site_demographics';
  $handler->display->display_options['fields']['field_site_demographics']['table'] = 'field_data_field_site_demographics';
  $handler->display->display_options['fields']['field_site_demographics']['field'] = 'field_site_demographics';
  $handler->display->display_options['fields']['field_site_demographics']['label'] = 'Population served';
  $handler->display->display_options['fields']['field_site_demographics']['element_label_type'] = 'strong';
  $handler->display->display_options['fields']['field_site_demographics']['hide_empty'] = TRUE;
  $handler->display->display_options['fields']['field_site_demographics']['hide_alter_empty'] = FALSE;
  $handler->display->display_options['fields']['field_site_demographics']['type'] = 's4_sites_population_matrix';
  $handler->display->display_options['fields']['field_site_demographics']['delta_offset'] = '0';
  /* Field: Content: Maximum number of students your site can accept at any given time */
  $handler->display->display_options['fields']['field_signups_max']['id'] = 'field_signups_max';
  $handler->display->display_options['fields']['field_signups_max']['table'] = 'field_data_field_signups_max';
  $handler->display->display_options['fields']['field_signups_max']['field'] = 'field_signups_max';
  $handler->display->display_options['fields']['field_signups_max']['element_label_type'] = 'strong';
  $handler->display->display_options['fields']['field_signups_max']['hide_empty'] = TRUE;
  $handler->display->display_options['fields']['field_signups_max']['hide_alter_empty'] = FALSE;
  $handler->display->display_options['fields']['field_signups_max']['settings'] = array(
    'thousand_separator' => ' ',
    'prefix_suffix' => 1,
  );
  /* Field: Content: What is the minimum number of hours you would require of a student in service per term */
  $handler->display->display_options['fields']['field_site_hours_minimum']['id'] = 'field_site_hours_minimum';
  $handler->display->display_options['fields']['field_site_hours_minimum']['table'] = 'field_data_field_site_hours_minimum';
  $handler->display->display_options['fields']['field_site_hours_minimum']['field'] = 'field_site_hours_minimum';
  $handler->display->display_options['fields']['field_site_hours_minimum']['label'] = 'Minimum hours';
  $handler->display->display_options['fields']['field_site_hours_minimum']['element_label_type'] = 'strong';
  $handler->display->display_options['fields']['field_site_hours_minimum']['hide_empty'] = TRUE;
  $handler->display->display_options['fields']['field_site_hours_minimum']['hide_alter_empty'] = FALSE;
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
  $handler->display->display_options['arguments']['nid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['nid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['nid']['summary_options']['items_per_page'] = '25';
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'site' => 'site',
  );

  /* Display: Block */
  $handler = $view->new_display('block', 'Block', 'block');
  $handler->display->display_options['block_description'] = 'Site fields';

  /* Display: Site operating hours */
  $handler = $view->new_display('block', 'Site operating hours', 'block_1');
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Days and hours will you accept students for service (check all that apply) */
  $handler->display->display_options['fields']['field_site_hours']['id'] = 'field_site_hours';
  $handler->display->display_options['fields']['field_site_hours']['table'] = 'field_data_field_site_hours';
  $handler->display->display_options['fields']['field_site_hours']['field'] = 'field_site_hours';
  $handler->display->display_options['fields']['field_site_hours']['label'] = 'Available hours';
  $handler->display->display_options['fields']['field_site_hours']['element_label_type'] = 'h4';
  $handler->display->display_options['fields']['field_site_hours']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_site_hours']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_site_hours']['hide_empty'] = TRUE;
  $handler->display->display_options['fields']['field_site_hours']['hide_alter_empty'] = FALSE;
  $handler->display->display_options['fields']['field_site_hours']['type'] = 's4_sites_hours_matrix';
  $handler->display->display_options['fields']['field_site_hours']['delta_offset'] = '0';
  $handler->display->display_options['block_description'] = 'Site operating hours';
  $translatables['site_fields'] = array(
    t('Master'),
    t('more'),
    t('Apply'),
    t('Reset'),
    t('Sort by'),
    t('Asc'),
    t('Desc'),
    t('Organization type'),
    t('Issues addressed'),
    t('Website'),
    t('Social network page'),
    t('Main phone number'),
    t('Location(s)'),
    t('Suggested languages'),
    t('Number of people served'),
    t('Population served'),
    t('Maximum number of students your site can accept at any given time'),
    t('Minimum hours'),
    t('All'),
    t('Block'),
    t('Site fields'),
    t('Site operating hours'),
    t('Available hours'),
  );
  $export['site_fields'] = $view;

  $view = new view();
  $view->name = 'site_location';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'S4: Site Location';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['use_more_always'] = FALSE;
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
  $handler->display->display_options['fields']['street']['label'] = 'street';
  $handler->display->display_options['fields']['street']['exclude'] = TRUE;
  $handler->display->display_options['fields']['street']['style'] = 'street';
  /* Field: Location: Street */
  $handler->display->display_options['fields']['street_1']['id'] = 'street_1';
  $handler->display->display_options['fields']['street_1']['table'] = 'location';
  $handler->display->display_options['fields']['street_1']['field'] = 'street';
  $handler->display->display_options['fields']['street_1']['label'] = 'Address';
  $handler->display->display_options['fields']['street_1']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['street_1']['alter']['text'] = '<br/>
[street]<br/>
[street_1]<br/>
[city], [province]&nbsp;&nbsp;[postal_code]';
  $handler->display->display_options['fields']['street_1']['element_label_type'] = 'strong';
  $handler->display->display_options['fields']['street_1']['element_wrapper_type'] = 'div';
  $handler->display->display_options['fields']['street_1']['element_wrapper_class'] = 'postal-address';
  $handler->display->display_options['fields']['street_1']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['street_1']['hide_alter_empty'] = FALSE;
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
  $handler->display->display_options['arguments']['nid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['nid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['nid']['summary_options']['items_per_page'] = '25';
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
    t('« first'),
    t('‹ previous'),
    t('next ›'),
    t('last »'),
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

  $view = new view();
  $view->name = 'site_locations';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'S4: Site locations';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Site locations';
  $handler->display->display_options['css_class'] = 'site-listing';
  $handler->display->display_options['use_more_always'] = FALSE;
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
  $handler->display->display_options['header']['area']['content'] = '<p class="lead">This site has multiple locations. Please select the location you will be working at.</p>';
  $handler->display->display_options['header']['area']['format'] = 'filtered_html';
  /* Field: Content: Location(s) */
  $handler->display->display_options['fields']['field_location']['id'] = 'field_location';
  $handler->display->display_options['fields']['field_location']['table'] = 'field_data_field_location';
  $handler->display->display_options['fields']['field_location']['field'] = 'field_location';
  $handler->display->display_options['fields']['field_location']['label'] = '';
  $handler->display->display_options['fields']['field_location']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_location']['hide_alter_empty'] = FALSE;
  $handler->display->display_options['fields']['field_location']['type'] = 's4_sites_address_select';
  $handler->display->display_options['fields']['field_location']['delta_offset'] = '0';
  $handler->display->display_options['fields']['field_location']['multi_type'] = 'ul';
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
  $handler->display->display_options['arguments']['nid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['nid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['nid']['summary_options']['items_per_page'] = '25';
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
    t('<p class="lead">This site has multiple locations. Please select the location you will be working at.</p>'),
    t('All'),
    t('Page'),
  );
  $export['site_locations'] = $view;

  $view = new view();
  $view->name = 'site_signups';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'S4: Site placements';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Students';
  $handler->display->display_options['css_class'] = 'quicksearch';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['query']['options']['query_comment'] = FALSE;
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '30';
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['grouping'] = array(
    0 => array(
      'field' => 'field_term',
      'rendered' => 1,
      'rendered_strip' => 0,
    ),
  );
  $handler->display->display_options['style_options']['columns'] = array(
    'field_first_name' => 'field_first_name',
    'field_last_name' => 'field_last_name',
    'field_course' => 'field_course',
    'field_coordinator' => 'field_coordinator',
    'nid' => 'nid',
    'nid_1' => 'nid_1',
    'field_term' => 'field_term',
  );
  $handler->display->display_options['style_options']['default'] = 'field_last_name';
  $handler->display->display_options['style_options']['info'] = array(
    'field_first_name' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_last_name' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_course' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_coordinator' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'nid' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'nid_1' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_term' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
  );
  $handler->display->display_options['exposed_block'] = TRUE;
  /* No results behavior: Global: Text area */
  $handler->display->display_options['empty']['area']['id'] = 'area';
  $handler->display->display_options['empty']['area']['table'] = 'views';
  $handler->display->display_options['empty']['area']['field'] = 'area';
  $handler->display->display_options['empty']['area']['content'] = '<p class="lead">No students signed up for this term.</p>';
  $handler->display->display_options['empty']['area']['format'] = 'full_html';
  /* Relationship: Field: Course (field_course) */
  $handler->display->display_options['relationships']['field_course_nid']['id'] = 'field_course_nid';
  $handler->display->display_options['relationships']['field_course_nid']['table'] = 'field_data_field_course';
  $handler->display->display_options['relationships']['field_course_nid']['field'] = 'field_course_nid';
  $handler->display->display_options['relationships']['field_course_nid']['delta'] = '-1';
  /* Relationship: Content: Site (field_site) */
  $handler->display->display_options['relationships']['field_site_nid']['id'] = 'field_site_nid';
  $handler->display->display_options['relationships']['field_site_nid']['table'] = 'field_data_field_site';
  $handler->display->display_options['relationships']['field_site_nid']['field'] = 'field_site_nid';
  $handler->display->display_options['relationships']['field_site_nid']['delta'] = '-1';
  /* Relationship: Content: User (field_user) */
  $handler->display->display_options['relationships']['field_user_uid']['id'] = 'field_user_uid';
  $handler->display->display_options['relationships']['field_user_uid']['table'] = 'field_data_field_user';
  $handler->display->display_options['relationships']['field_user_uid']['field'] = 'field_user_uid';
  $handler->display->display_options['relationships']['field_user_uid']['delta'] = '-1';
  /* Field: Field: First Name */
  $handler->display->display_options['fields']['field_first_name']['id'] = 'field_first_name';
  $handler->display->display_options['fields']['field_first_name']['table'] = 'field_data_field_first_name';
  $handler->display->display_options['fields']['field_first_name']['field'] = 'field_first_name';
  $handler->display->display_options['fields']['field_first_name']['relationship'] = 'field_user_uid';
  /* Field: Field: Last Name */
  $handler->display->display_options['fields']['field_last_name']['id'] = 'field_last_name';
  $handler->display->display_options['fields']['field_last_name']['table'] = 'field_data_field_last_name';
  $handler->display->display_options['fields']['field_last_name']['field'] = 'field_last_name';
  $handler->display->display_options['fields']['field_last_name']['relationship'] = 'field_user_uid';
  /* Field: Field: Course */
  $handler->display->display_options['fields']['field_course']['id'] = 'field_course';
  $handler->display->display_options['fields']['field_course']['table'] = 'field_data_field_course';
  $handler->display->display_options['fields']['field_course']['field'] = 'field_course';
  /* Field: Field: Site staff */
  $handler->display->display_options['fields']['field_coordinator']['id'] = 'field_coordinator';
  $handler->display->display_options['fields']['field_coordinator']['table'] = 'field_data_field_coordinator';
  $handler->display->display_options['fields']['field_coordinator']['field'] = 'field_coordinator';
  /* Field: Content: Nid */
  $handler->display->display_options['fields']['nid']['id'] = 'nid';
  $handler->display->display_options['fields']['nid']['table'] = 'node';
  $handler->display->display_options['fields']['nid']['field'] = 'nid';
  $handler->display->display_options['fields']['nid']['label'] = 'View';
  $handler->display->display_options['fields']['nid']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['nid']['alter']['text'] = 'View';
  $handler->display->display_options['fields']['nid']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['nid']['alter']['path'] = 'node/[nid]';
  /* Field: Content: Nid */
  $handler->display->display_options['fields']['nid_1']['id'] = 'nid_1';
  $handler->display->display_options['fields']['nid_1']['table'] = 'node';
  $handler->display->display_options['fields']['nid_1']['field'] = 'nid';
  $handler->display->display_options['fields']['nid_1']['label'] = 'Edit';
  $handler->display->display_options['fields']['nid_1']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['nid_1']['alter']['text'] = 'Edit';
  $handler->display->display_options['fields']['nid_1']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['nid_1']['alter']['path'] = 'node/[nid_1]/edit';
  /* Field: Content: Term */
  $handler->display->display_options['fields']['field_term']['id'] = 'field_term';
  $handler->display->display_options['fields']['field_term']['table'] = 'field_data_field_term';
  $handler->display->display_options['fields']['field_term']['field'] = 'field_term';
  $handler->display->display_options['fields']['field_term']['relationship'] = 'field_course_nid';
  $handler->display->display_options['fields']['field_term']['label'] = '';
  $handler->display->display_options['fields']['field_term']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_term']['type'] = 'node_reference_plain';
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
  $handler->display->display_options['arguments']['nid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['nid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['nid']['summary_options']['items_per_page'] = '25';
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
  $handler->display->display_options['filters']['field_term_nid']['expose']['remember'] = TRUE;
  $handler->display->display_options['filters']['field_term_nid']['expose']['multiple'] = TRUE;
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
    t('« first'),
    t('‹ previous'),
    t('next ›'),
    t('last »'),
    t('<p class="lead">No students signed up for this term.</p>'),
    t('field_course'),
    t('field_site'),
    t('field_user'),
    t('First Name'),
    t('Last Name'),
    t('Course'),
    t('Site staff'),
    t('View'),
    t('Edit'),
    t('All'),
    t('Terms'),
    t('Last name'),
    t('Site signups'),
  );
  $export['site_signups'] = $view;

  $view = new view();
  $view->name = 'sites';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'S4: Sites';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Sites';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'none';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['query']['options']['distinct'] = TRUE;
  $handler->display->display_options['query']['options']['pure_distinct'] = TRUE;
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['exposed_form']['options']['submit_button'] = 'Search';
  $handler->display->display_options['exposed_form']['options']['expose_sort_order'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '20';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['pager']['options']['id'] = '0';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['style_options']['default_row_class'] = FALSE;
  $handler->display->display_options['style_options']['row_class_special'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['exposed_block'] = TRUE;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['title']['element_type'] = 'h4';
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title']['element_default_classes'] = FALSE;
  /* Field: Field: Program(s) */
  $handler->display->display_options['fields']['field_site_restrict']['id'] = 'field_site_restrict';
  $handler->display->display_options['fields']['field_site_restrict']['table'] = 'field_data_field_site_restrict';
  $handler->display->display_options['fields']['field_site_restrict']['field'] = 'field_site_restrict';
  $handler->display->display_options['fields']['field_site_restrict']['label'] = 'Programs';
  $handler->display->display_options['fields']['field_site_restrict']['element_wrapper_type'] = 'div';
  $handler->display->display_options['fields']['field_site_restrict']['element_wrapper_class'] = 'site-restrictions';
  $handler->display->display_options['fields']['field_site_restrict']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_site_restrict']['type'] = 'taxonomy_term_reference_plain';
  $handler->display->display_options['fields']['field_site_restrict']['delta_offset'] = '0';
  /* Field: Content: Issues addressed */
  $handler->display->display_options['fields']['field_csu_facility']['id'] = 'field_csu_facility';
  $handler->display->display_options['fields']['field_csu_facility']['table'] = 'field_data_field_csu_facility';
  $handler->display->display_options['fields']['field_csu_facility']['field'] = 'field_csu_facility';
  $handler->display->display_options['fields']['field_csu_facility']['type'] = 's4_sites_limited_taxonomy_term';
  $handler->display->display_options['fields']['field_csu_facility']['delta_offset'] = '0';
  /* Field: Content: Organization type */
  $handler->display->display_options['fields']['field_csu_org_type']['id'] = 'field_csu_org_type';
  $handler->display->display_options['fields']['field_csu_org_type']['table'] = 'field_data_field_csu_org_type';
  $handler->display->display_options['fields']['field_csu_org_type']['field'] = 'field_csu_org_type';
  $handler->display->display_options['fields']['field_csu_org_type']['type'] = 's4_sites_limited_taxonomy_term';
  $handler->display->display_options['fields']['field_csu_org_type']['delta_offset'] = '0';
  /* Field: Location: Latitude */
  $handler->display->display_options['fields']['latitude']['id'] = 'latitude';
  $handler->display->display_options['fields']['latitude']['table'] = 'location';
  $handler->display->display_options['fields']['latitude']['field'] = 'latitude';
  $handler->display->display_options['fields']['latitude']['style'] = 'dd';
  /* Field: Location: Longitude */
  $handler->display->display_options['fields']['longitude']['id'] = 'longitude';
  $handler->display->display_options['fields']['longitude']['table'] = 'location';
  $handler->display->display_options['fields']['longitude']['field'] = 'longitude';
  $handler->display->display_options['fields']['longitude']['style'] = 'dd';
  /* Field: Content: Body */
  $handler->display->display_options['fields']['body']['id'] = 'body';
  $handler->display->display_options['fields']['body']['table'] = 'field_data_body';
  $handler->display->display_options['fields']['body']['field'] = 'body';
  $handler->display->display_options['fields']['body']['type'] = 'text_trimmed';
  $handler->display->display_options['fields']['body']['settings'] = array(
    'trim_length' => '200',
  );
  /* Field: Content: Location(s) */
  $handler->display->display_options['fields']['field_location']['id'] = 'field_location';
  $handler->display->display_options['fields']['field_location']['table'] = 'field_data_field_location';
  $handler->display->display_options['fields']['field_location']['field'] = 'field_location';
  $handler->display->display_options['fields']['field_location']['element_type'] = '0';
  $handler->display->display_options['fields']['field_location']['element_label_type'] = '0';
  $handler->display->display_options['fields']['field_location']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_location']['type'] = 's4_sites_address';
  $handler->display->display_options['fields']['field_location']['delta_offset'] = '0';
  /* Field: Content: Main phone number */
  $handler->display->display_options['fields']['field_phone']['id'] = 'field_phone';
  $handler->display->display_options['fields']['field_phone']['table'] = 'field_data_field_phone';
  $handler->display->display_options['fields']['field_phone']['field'] = 'field_phone';
  $handler->display->display_options['fields']['field_phone']['click_sort_column'] = 'number';
  $handler->display->display_options['fields']['field_phone']['type'] = 's4_sites_local_phone_number';
  $handler->display->display_options['fields']['field_phone']['delta_offset'] = '0';
  /* Field: Content: Website */
  $handler->display->display_options['fields']['field_website']['id'] = 'field_website';
  $handler->display->display_options['fields']['field_website']['table'] = 'field_data_field_website';
  $handler->display->display_options['fields']['field_website']['field'] = 'field_website';
  $handler->display->display_options['fields']['field_website']['label'] = '';
  $handler->display->display_options['fields']['field_website']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_website']['click_sort_column'] = 'url';
  $handler->display->display_options['fields']['field_website']['type'] = 'link_plain';
  /* Sort criterion: Content: Title */
  $handler->display->display_options['sorts']['title']['id'] = 'title';
  $handler->display->display_options['sorts']['title']['table'] = 'node';
  $handler->display->display_options['sorts']['title']['field'] = 'title';
  /* Contextual filter: Content: Nid */
  $handler->display->display_options['arguments']['nid']['id'] = 'nid';
  $handler->display->display_options['arguments']['nid']['table'] = 'node';
  $handler->display->display_options['arguments']['nid']['field'] = 'nid';
  $handler->display->display_options['arguments']['nid']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['nid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['nid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['nid']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['nid']['break_phrase'] = TRUE;
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
  /* Filter criterion: Field: Program(s) (field_site_restrict) */
  $handler->display->display_options['filters']['field_site_restrict_tid']['id'] = 'field_site_restrict_tid';
  $handler->display->display_options['filters']['field_site_restrict_tid']['table'] = 'field_data_field_site_restrict';
  $handler->display->display_options['filters']['field_site_restrict_tid']['field'] = 'field_site_restrict_tid';
  $handler->display->display_options['filters']['field_site_restrict_tid']['group'] = 1;
  $handler->display->display_options['filters']['field_site_restrict_tid']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_site_restrict_tid']['expose']['operator_id'] = 'field_site_restrict_tid_op';
  $handler->display->display_options['filters']['field_site_restrict_tid']['expose']['label'] = 'Program';
  $handler->display->display_options['filters']['field_site_restrict_tid']['expose']['operator'] = 'field_site_restrict_tid_op';
  $handler->display->display_options['filters']['field_site_restrict_tid']['expose']['identifier'] = 'program';
  $handler->display->display_options['filters']['field_site_restrict_tid']['expose']['remember'] = TRUE;
  $handler->display->display_options['filters']['field_site_restrict_tid']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    4 => 0,
    6 => 0,
    3 => 0,
    5 => 0,
    7 => 0,
    8 => 0,
    9 => 0,
  );
  $handler->display->display_options['filters']['field_site_restrict_tid']['reduce_duplicates'] = TRUE;
  $handler->display->display_options['filters']['field_site_restrict_tid']['type'] = 'select';
  $handler->display->display_options['filters']['field_site_restrict_tid']['vocabulary'] = 'site_restrictions';
  $handler->display->display_options['filters']['field_site_restrict_tid']['error_message'] = FALSE;
  /* Filter criterion: Content: Title */
  $handler->display->display_options['filters']['title']['id'] = 'title';
  $handler->display->display_options['filters']['title']['table'] = 'node';
  $handler->display->display_options['filters']['title']['field'] = 'title';
  $handler->display->display_options['filters']['title']['operator'] = 'allwords';
  $handler->display->display_options['filters']['title']['group'] = 1;
  $handler->display->display_options['filters']['title']['exposed'] = TRUE;
  $handler->display->display_options['filters']['title']['expose']['operator_id'] = 'title_op';
  $handler->display->display_options['filters']['title']['expose']['label'] = 'Site name';
  $handler->display->display_options['filters']['title']['expose']['operator'] = 'title_op';
  $handler->display->display_options['filters']['title']['expose']['identifier'] = 'title';
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
  $handler->display->display_options['filters']['field_csu_facility_tid']['expose']['identifier'] = 'issues';
  $handler->display->display_options['filters']['field_csu_facility_tid']['expose']['remember'] = TRUE;
  $handler->display->display_options['filters']['field_csu_facility_tid']['expose']['multiple'] = TRUE;
  $handler->display->display_options['filters']['field_csu_facility_tid']['reduce_duplicates'] = TRUE;
  $handler->display->display_options['filters']['field_csu_facility_tid']['type'] = 'select';
  $handler->display->display_options['filters']['field_csu_facility_tid']['vocabulary'] = 'issues_addressed';
  /* Filter criterion: Content: Organization type (field_csu_org_type) */
  $handler->display->display_options['filters']['field_csu_org_type_tid']['id'] = 'field_csu_org_type_tid';
  $handler->display->display_options['filters']['field_csu_org_type_tid']['table'] = 'field_data_field_csu_org_type';
  $handler->display->display_options['filters']['field_csu_org_type_tid']['field'] = 'field_csu_org_type_tid';
  $handler->display->display_options['filters']['field_csu_org_type_tid']['group'] = 1;
  $handler->display->display_options['filters']['field_csu_org_type_tid']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_csu_org_type_tid']['expose']['operator_id'] = 'field_csu_org_type_tid_op';
  $handler->display->display_options['filters']['field_csu_org_type_tid']['expose']['label'] = 'Organization type';
  $handler->display->display_options['filters']['field_csu_org_type_tid']['expose']['operator'] = 'field_csu_org_type_tid_op';
  $handler->display->display_options['filters']['field_csu_org_type_tid']['expose']['identifier'] = 'organization';
  $handler->display->display_options['filters']['field_csu_org_type_tid']['expose']['remember'] = TRUE;
  $handler->display->display_options['filters']['field_csu_org_type_tid']['expose']['multiple'] = TRUE;
  $handler->display->display_options['filters']['field_csu_org_type_tid']['reduce_duplicates'] = TRUE;
  $handler->display->display_options['filters']['field_csu_org_type_tid']['type'] = 'select';
  $handler->display->display_options['filters']['field_csu_org_type_tid']['vocabulary'] = 'organization_type';

  /* Display: Site listing page */
  $handler = $view->new_display('page', 'Site listing page', 'page');
  $handler->display->display_options['defaults']['css_class'] = FALSE;
  $handler->display->display_options['css_class'] = 'search-results';
  $handler->display->display_options['defaults']['header'] = FALSE;
  /* Header: Global: Result summary */
  $handler->display->display_options['header']['result']['id'] = 'result';
  $handler->display->display_options['header']['result']['table'] = 'views';
  $handler->display->display_options['header']['result']['field'] = 'result';
  $handler->display->display_options['header']['result']['content'] = 'Showing @start - @end of @total';
  $handler->display->display_options['defaults']['relationships'] = FALSE;
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Contextual filter: Content: Nid */
  $handler->display->display_options['arguments']['nid']['id'] = 'nid';
  $handler->display->display_options['arguments']['nid']['table'] = 'node';
  $handler->display->display_options['arguments']['nid']['field'] = 'nid';
  $handler->display->display_options['arguments']['nid']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['nid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['nid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['nid']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['nid']['break_phrase'] = TRUE;
  /* Contextual filter: Content: Has taxonomy term ID */
  $handler->display->display_options['arguments']['tid']['id'] = 'tid';
  $handler->display->display_options['arguments']['tid']['table'] = 'taxonomy_index';
  $handler->display->display_options['arguments']['tid']['field'] = 'tid';
  $handler->display->display_options['arguments']['tid']['default_action'] = 'empty';
  $handler->display->display_options['arguments']['tid']['default_argument_type'] = 'taxonomy_tid';
  $handler->display->display_options['arguments']['tid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['tid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['tid']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['tid']['specify_validation'] = TRUE;
  $handler->display->display_options['arguments']['tid']['validate']['type'] = 'taxonomy_term';
  $handler->display->display_options['arguments']['tid']['validate_options']['vocabularies'] = array(
    'site_restrictions' => 'site_restrictions',
  );
  $handler->display->display_options['arguments']['tid']['validate_options']['type'] = 'convert';
  $handler->display->display_options['arguments']['tid']['validate_options']['transform'] = TRUE;
  $handler->display->display_options['arguments']['tid']['break_phrase'] = TRUE;
  $handler->display->display_options['path'] = 'site-list';

  /* Display: Block */
  $handler = $view->new_display('block', 'Block', 'block_1');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Newest Sites';
  $handler->display->display_options['defaults']['use_ajax'] = FALSE;
  $handler->display->display_options['use_ajax'] = TRUE;
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'mini';
  $handler->display->display_options['pager']['options']['items_per_page'] = '10';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['pager']['options']['id'] = '0';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'list';
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['row_options']['inline'] = array(
    'title' => 'title',
  );
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  $handler->display->display_options['defaults']['sorts'] = FALSE;
  /* Sort criterion: Content: Post date */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'node';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'site' => 'site',
  );
  $handler->display->display_options['filters']['type']['group'] = 1;
  /* Filter criterion: Content: Post date */
  $handler->display->display_options['filters']['created']['id'] = 'created';
  $handler->display->display_options['filters']['created']['table'] = 'node';
  $handler->display->display_options['filters']['created']['field'] = 'created';
  $handler->display->display_options['filters']['created']['operator'] = '>=';
  $handler->display->display_options['filters']['created']['value']['value'] = '-3 months';
  $handler->display->display_options['filters']['created']['value']['type'] = 'offset';
  $handler->display->display_options['block_description'] = 'Newest Sites';
  $translatables['sites'] = array(
    t('Master'),
    t('Sites'),
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
    t('Programs'),
    t('Issues addressed'),
    t('Organization type'),
    t('Latitude'),
    t('Longitude'),
    t('Body'),
    t('Location(s)'),
    t('Main phone number'),
    t('All'),
    t('Program'),
    t('Site name'),
    t('City'),
    t('Site listing page'),
    t('Showing @start - @end of @total'),
    t('Block'),
    t('Newest Sites'),
  );
  $export['sites'] = $view;

  return $export;
}
