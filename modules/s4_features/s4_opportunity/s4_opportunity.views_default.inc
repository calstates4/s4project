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
    'group-name' => array(
      'group' => '0',
      'filter_name' => 'name',
      'weight' => '-6',
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
  /* Field: Opportunity: Active date */
  $handler->display->display_options['fields']['field_active_date']['id'] = 'field_active_date';
  $handler->display->display_options['fields']['field_active_date']['table'] = 'field_data_field_active_date';
  $handler->display->display_options['fields']['field_active_date']['field'] = 'field_active_date';
  $handler->display->display_options['fields']['field_active_date']['label'] = 'Active ';
  $handler->display->display_options['fields']['field_active_date']['settings'] = array(
    'format_type' => 'short',
    'fromto' => 'both',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
  );
  /* Field: Opportunity: ID */
  $handler->display->display_options['fields']['s4_opportunity_id']['id'] = 's4_opportunity_id';
  $handler->display->display_options['fields']['s4_opportunity_id']['table'] = 's4_opportunity';
  $handler->display->display_options['fields']['s4_opportunity_id']['field'] = 's4_opportunity_id';
  $handler->display->display_options['fields']['s4_opportunity_id']['label'] = 'Edit';
  $handler->display->display_options['fields']['s4_opportunity_id']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['s4_opportunity_id']['alter']['text'] = 'edit';
  $handler->display->display_options['fields']['s4_opportunity_id']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['s4_opportunity_id']['alter']['path'] = 'opportunity/[s4_opportunity_id]/edit';
  $handler->display->display_options['fields']['s4_opportunity_id']['element_label_colon'] = FALSE;
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
  $handler->display->display_options['filters']['status']['value'] = 'All';
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
  /* Filter criterion: Opportunity: Name */
  $handler->display->display_options['filters']['name']['id'] = 'name';
  $handler->display->display_options['filters']['name']['table'] = 's4_opportunity';
  $handler->display->display_options['filters']['name']['field'] = 'name';
  $handler->display->display_options['filters']['name']['operator'] = 'contains';
  $handler->display->display_options['filters']['name']['exposed'] = TRUE;
  $handler->display->display_options['filters']['name']['expose']['operator_id'] = 'name_op';
  $handler->display->display_options['filters']['name']['expose']['label'] = 'Name';
  $handler->display->display_options['filters']['name']['expose']['operator'] = 'name_op';
  $handler->display->display_options['filters']['name']['expose']['identifier'] = 'name';
  $handler->display->display_options['filters']['name']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    4 => 0,
    6 => 0,
    3 => 0,
    5 => 0,
    7 => 0,
    8 => 0,
  );

  /* Display: Manage opportunities */
  $handler = $view->new_display('page', 'Manage opportunities', 'page');
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
    t('Active '),
    t('Edit'),
    t('edit'),
    t('Issues addressed'),
    t('Organization type'),
    t('Program(s)'),
    t('Active'),
    t('Category'),
    t('Manage opportunities'),
  );
  $export['s4_opportunities'] = $view;

  $view = new view();
  $view->name = 's4_opportunities_create';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'S4 opportunities: Create';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Select a site staff';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['access']['perm'] = 'start new opportunities';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['query']['options']['disable_sql_rewrite'] = TRUE;
  $handler->display->display_options['query']['options']['distinct'] = TRUE;
  $handler->display->display_options['query']['options']['slave'] = TRUE;
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['exposed_form']['options']['submit_button'] = 'Search';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '50';
  $handler->display->display_options['style_plugin'] = 'table';
  /* Header: Global: Text area */
  $handler->display->display_options['header']['area']['id'] = 'area';
  $handler->display->display_options['header']['area']['table'] = 'views';
  $handler->display->display_options['header']['area']['field'] = 'area';
  $handler->display->display_options['header']['area']['empty'] = TRUE;
  $handler->display->display_options['header']['area']['content'] = '<p class="lead">Search for and select where this opportunity will be. If we don\'t have that site on the list, you can <a href="../../opportunities/create/sites/new">always create a new site</a>.';
  $handler->display->display_options['header']['area']['format'] = 'full_html';
  /* No results behavior: Global: Text area */
  $handler->display->display_options['empty']['area']['id'] = 'area';
  $handler->display->display_options['empty']['area']['table'] = 'views';
  $handler->display->display_options['empty']['area']['field'] = 'area';
  $handler->display->display_options['empty']['area']['empty'] = TRUE;
  $handler->display->display_options['empty']['area']['content'] = '<p class="lead">Didn\'t find the site you were looking for? <a href="../../opportunities/create/site/new">Let us know about a new site</a>.';
  $handler->display->display_options['empty']['area']['format'] = 'full_html';
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = 'Site name';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  /* Field: Content: Nid */
  $handler->display->display_options['fields']['nid']['id'] = 'nid';
  $handler->display->display_options['fields']['nid']['table'] = 'node';
  $handler->display->display_options['fields']['nid']['field'] = 'nid';
  $handler->display->display_options['fields']['nid']['label'] = '';
  $handler->display->display_options['fields']['nid']['exclude'] = TRUE;
  $handler->display->display_options['fields']['nid']['element_label_colon'] = FALSE;
  /* Field: Content: Location(s) */
  $handler->display->display_options['fields']['field_location']['id'] = 'field_location';
  $handler->display->display_options['fields']['field_location']['table'] = 'field_data_field_location';
  $handler->display->display_options['fields']['field_location']['field'] = 'field_location';
  $handler->display->display_options['fields']['field_location']['label'] = 'Address';
  $handler->display->display_options['fields']['field_location']['type'] = 's4_sites_address';
  $handler->display->display_options['fields']['field_location']['delta_limit'] = '1';
  $handler->display->display_options['fields']['field_location']['delta_offset'] = '0';
  /* Field: Content: Published */
  $handler->display->display_options['fields']['status']['id'] = 'status';
  $handler->display->display_options['fields']['status']['table'] = 'node';
  $handler->display->display_options['fields']['status']['field'] = 'status';
  $handler->display->display_options['fields']['status']['label'] = 'Active';
  $handler->display->display_options['fields']['status']['type'] = 'custom';
  $handler->display->display_options['fields']['status']['type_custom_true'] = 'Active';
  $handler->display->display_options['fields']['status']['type_custom_false'] = 'Inactive';
  $handler->display->display_options['fields']['status']['not'] = 0;
  /* Field: Global: Custom text */
  $handler->display->display_options['fields']['nothing']['id'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['table'] = 'views';
  $handler->display->display_options['fields']['nothing']['field'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['label'] = 'Select';
  $handler->display->display_options['fields']['nothing']['alter']['text'] = 'Select';
  $handler->display->display_options['fields']['nothing']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['nothing']['alter']['path'] = 'opportunities/create/site/[nid]';
  $handler->display->display_options['fields']['nothing']['alter']['link_class'] = 'btn';
  /* Sort criterion: Content: Title */
  $handler->display->display_options['sorts']['title']['id'] = 'title';
  $handler->display->display_options['sorts']['title']['table'] = 'node';
  $handler->display->display_options['sorts']['title']['field'] = 'title';
  /* Sort criterion: Content: Post date */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'node';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
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
  $handler->display->display_options['filters']['keys']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    4 => 0,
    6 => 0,
    3 => 0,
    5 => 0,
    7 => 0,
    8 => 0,
  );
  /* Filter criterion: Location: City */
  $handler->display->display_options['filters']['city']['id'] = 'city';
  $handler->display->display_options['filters']['city']['table'] = 'location';
  $handler->display->display_options['filters']['city']['field'] = 'city';
  $handler->display->display_options['filters']['city']['exposed'] = TRUE;
  $handler->display->display_options['filters']['city']['expose']['operator_id'] = 'city_op';
  $handler->display->display_options['filters']['city']['expose']['label'] = 'City';
  $handler->display->display_options['filters']['city']['expose']['operator'] = 'city_op';
  $handler->display->display_options['filters']['city']['expose']['identifier'] = 'city';
  $handler->display->display_options['filters']['city']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    4 => 0,
    6 => 0,
    3 => 0,
    5 => 0,
    7 => 0,
    8 => 0,
  );

  /* Display: Sites list */
  $handler = $view->new_display('page', 'Sites list', 'page');
  $handler->display->display_options['path'] = 'opportunities/create/sites';

  /* Display: Site staff list */
  $handler = $view->new_display('page', 'Site staff list', 'page_1');
  $handler->display->display_options['defaults']['header'] = FALSE;
  /* Header: Global: Text area */
  $handler->display->display_options['header']['area']['id'] = 'area';
  $handler->display->display_options['header']['area']['table'] = 'views';
  $handler->display->display_options['header']['area']['field'] = 'area';
  $handler->display->display_options['header']['area']['empty'] = TRUE;
  $handler->display->display_options['header']['area']['content'] = '<p class="lead">Site staff are the people who are responsible for this thing. If you can\'t find one, <a href="../../../opportunities/create/site-staff/new">just create one</a>.';
  $handler->display->display_options['header']['area']['format'] = 'full_html';
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
  /* Field: Field: First Name */
  $handler->display->display_options['fields']['field_first_name']['id'] = 'field_first_name';
  $handler->display->display_options['fields']['field_first_name']['table'] = 'field_data_field_first_name';
  $handler->display->display_options['fields']['field_first_name']['field'] = 'field_first_name';
  /* Field: Content: Role */
  $handler->display->display_options['fields']['field_staff_role']['id'] = 'field_staff_role';
  $handler->display->display_options['fields']['field_staff_role']['table'] = 'field_data_field_staff_role';
  $handler->display->display_options['fields']['field_staff_role']['field'] = 'field_staff_role';
  /* Field: Content: Job title */
  $handler->display->display_options['fields']['field_job_title']['id'] = 'field_job_title';
  $handler->display->display_options['fields']['field_job_title']['table'] = 'field_data_field_job_title';
  $handler->display->display_options['fields']['field_job_title']['field'] = 'field_job_title';
  /* Field: Content: Active */
  $handler->display->display_options['fields']['field_site_staff_active']['id'] = 'field_site_staff_active';
  $handler->display->display_options['fields']['field_site_staff_active']['table'] = 'field_data_field_site_staff_active';
  $handler->display->display_options['fields']['field_site_staff_active']['field'] = 'field_site_staff_active';
  /* Field: Content: Email address */
  $handler->display->display_options['fields']['field_email']['id'] = 'field_email';
  $handler->display->display_options['fields']['field_email']['table'] = 'field_data_field_email';
  $handler->display->display_options['fields']['field_email']['field'] = 'field_email';
  /* Field: Global: Custom text */
  $handler->display->display_options['fields']['nothing']['id'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['table'] = 'views';
  $handler->display->display_options['fields']['nothing']['field'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['alter']['text'] = 'Select';
  $handler->display->display_options['fields']['nothing']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['nothing']['alter']['path'] = 'opportunities/create/site-staff/[nid]';
  $handler->display->display_options['fields']['nothing']['alter']['link_class'] = 'btn';
  $handler->display->display_options['defaults']['sorts'] = FALSE;
  /* Sort criterion: Field: Last Name (field_last_name) */
  $handler->display->display_options['sorts']['field_last_name_value']['id'] = 'field_last_name_value';
  $handler->display->display_options['sorts']['field_last_name_value']['table'] = 'field_data_field_last_name';
  $handler->display->display_options['sorts']['field_last_name_value']['field'] = 'field_last_name_value';
  /* Sort criterion: Field: First Name (field_first_name) */
  $handler->display->display_options['sorts']['field_first_name_value']['id'] = 'field_first_name_value';
  $handler->display->display_options['sorts']['field_first_name_value']['table'] = 'field_data_field_first_name';
  $handler->display->display_options['sorts']['field_first_name_value']['field'] = 'field_first_name_value';
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Contextual filter: Content: Site (field_site) */
  $handler->display->display_options['arguments']['field_site_nid']['id'] = 'field_site_nid';
  $handler->display->display_options['arguments']['field_site_nid']['table'] = 'field_data_field_site';
  $handler->display->display_options['arguments']['field_site_nid']['field'] = 'field_site_nid';
  $handler->display->display_options['arguments']['field_site_nid']['default_action'] = 'not found';
  $handler->display->display_options['arguments']['field_site_nid']['default_argument_type'] = 'fixed';
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
  $handler->display->display_options['filters']['type']['group'] = 1;
  $handler->display->display_options['path'] = 'opportunities/create/site-staff/%';
  $translatables['s4_opportunities_create'] = array(
    t('Master'),
    t('Select a site staff'),
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
    t('<p class="lead">Search for and select where this opportunity will be. If we don\'t have that site on the list, you can <a href="../../opportunities/create/sites/new">always create a new site</a>.'),
    t('<p class="lead">Didn\'t find the site you were looking for? <a href="../../opportunities/create/site/new">Let us know about a new site</a>.'),
    t('Site name'),
    t('Address'),
    t('Active'),
    t('Inactive'),
    t('Select'),
    t('City'),
    t('Sites list'),
    t('Site staff list'),
    t('<p class="lead">Site staff are the people who are responsible for this thing. If you can\'t find one, <a href="../../../opportunities/create/site-staff/new">just create one</a>.'),
    t('Last Name'),
    t('First Name'),
    t('Role'),
    t('Job title'),
    t('Email address'),
    t('Custom text'),
    t('All'),
  );
  $export['s4_opportunities_create'] = $view;

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
