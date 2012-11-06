<?php

/**
*  @file Views hooks
*/

/**
* Implements hook_views_data
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
  
  $data['s4_sites']['total_site_staff_students'] = array(
    'title' => t('Total site staff students'),
    'help' => t('Total students assigned to a site staff'),
    'field' => array(
      'handler' => 'views_handler_s4_sites_total_site_staff_students',
      'click sortable' => FALSE,
    ),
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
  );
  
  $data['s4_sites']['current_site_staff_students'] = array(
    'title' => t('Current site staff students'),
    'help' => t('Current number of students assigned to a site staff'),
    'field' => array(
      'handler' => 'views_handler_s4_sites_current_site_staff_students',
      'click sortable' => FALSE,
    ),
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
  );
  
  $data['s4_sites']['evaluation_link'] = array(
    'title' => t('Evaluation link'),
    'help' => t('Link for a user to complete a site evalution.'),
    'field' => array(
      'handler' => 'views_handler_s4_sites_evaluation_link',
      'click sortable' => FALSE,
    ),
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
  );
  
  $data['s4_sites']['evaluation_completed'] = array(
    'title' => t('Evaluation completed'),
    'help' => t('Lists whether a user completed an evaluation.'),
    'field' => array(
      'handler' => 'views_handler_s4_sites_evaluation_status',
      'click sortable' => FALSE,
    ),
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
  );
  
  return $data;
}

