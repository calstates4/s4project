<?php

/**
*  The base class for all S4 web cases
*/
class s4WebTestCase extends DrupalWebTestCase {
  
  protected $privileged_user;
  
  var $profile = 'student_signup';
  
  var $roles = array();
  
  var $modules = array(
          'auto_nodetitle',
          'better_exposed_filters',
          'block',
          'cck',
          'cck_phone',
          'color',
          'content_access',
          'context',
          'contextual',
          'context_layouts',
          'context_ui',
          'ctools',
          'dashboard',
          'datatables',
          'date',
          'date_api',
          'date_popup',
          'date_tools',
          'date_views',
          'dblog',
          'devel',
          'devel_generate',
          'devel_node_access',
          'email',
          'entity',
          'fancybox',
          'features',
          'field',
          'field_display_label',
          'field_group',
          'field_sql_storage',
          'field_ui',
          'file',
          'filter',
          'flag',
          'flag_actions',
          'front_page',
          'gmap',
          'gmap_location',
          'gmap_macro_builder',
          'help',
          'homebox',
          'image',
          'imce',
          'imce_wysiwyg',
          'insert',
          'link',
          'list',
          'locale',
          'location',
          'location_cck',
          'location_fax',
          'location_generate',
          'location_node',
          'location_phone',
          'location_search',
          'masquerade',
          'matrix',
          'menu',
          'messaging',
          'messaging_htmlmail',
          'messaging_mail',
          'messaging_template',
          'node',
          'nodeaccess_userreference',
          'nodeformcols',
          'nodereference_count',
          'nodereference_url',
          'node_reference',
          'notifications',
          'notifications_account',
          'notifications_content',
          'notifications_ui',
          'number',
          'options',
          'options_element',
          'page_manager',
          'path',
          'pathauto',
          'rdf',
          'references',
          's4_api_batch',
          's4_api_db',
          's4_api_devel',
          's4_api_rest',
          's4_assessment',
          's4_core',
          's4_courses',
          's4_csu_reporting',
          's4_districts',
          's4_editor',
          's4_generate',
          's4_help',
          's4_map',
          's4_news',
          's4_pages',
          's4_reporting',
          's4_sites',
          's4_users',
          's4_webform',
          'save_draft',
          'search',
          'select_or_other',
          'shortcut',
          'simpletest',
          'strongarm',
          'system',
          'talk',
          'taxonomy',
          'text',
          'token',
          'toolbar',
          'trigger',
          'user',
          'user_reference',
          'views',
          'views_bulk_operations',
          'views_calc',
          'views_data_export',
          'views_dynamic_fields',
          'views_json',
          'views_savedsearches',
          'views_ui',
          'view_unpublished',
          'webform',
          'wysiwyg',
  );
  
  function setUp($args) {
    foreach(user_roles() as $rid => $role) {
      $permissions = db_select('role_permission', 'r')
               ->fields('r', array('permission'))
               ->condition('r.rid', $rid);
        
      $this->roles[$role] = $permissions->execute()->fetchCol();
    }
    parent::setUp($args);
  }
  
}