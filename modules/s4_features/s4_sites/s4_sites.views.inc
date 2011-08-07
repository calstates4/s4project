<?php

/**
*  @file Views hooks
*/

/**
*  Implementation of hook_views_data
*/
function s4_sites_views_data() {
  $data['s4_sites']['table']['group'] = t('Site Data');
  $data['s4_sites']['table']['join'] = array(
    'node' => array(
      'left_field' => 'nid',
      'field' => 'nid',
    ),
  );

  $data['s4_sites']['total_site_hours'] = array(
    'title' => t('Total hours'),
    'help' => t('Total hours worked at a site'),
    'field' => array(
      'handler' => 'views_handler_s4_sites_total_site_hours',
      'click sortable' => FALSE,
    ),
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
  );
  
  $data['s4_sites']['total_students'] = array(
    'title' => t('Total students'),
    'help' => t('Total students worked at a site'),
    'field' => array(
      'handler' => 'views_handler_s4_sites_total_site_students',
      'click sortable' => FALSE,
    ),
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
  );
  
  return $data;
}

