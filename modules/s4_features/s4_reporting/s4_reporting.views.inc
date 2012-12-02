<?php

/**
*  @file Views hooks
*/

/**
* Implements hook_views_data
*/
function s4_reporting_views_data() {
  $data['s4_reporting']['table']['group'] = t('Form Evaluation');
  $data['s4_reporting']['table']['join'] = array(
    'node' => array(
      'left_field' => 'nid',
      'field' => 'nid',
    ),
  );

  $data['s4_reporting']['webform_report_result'] = array(
    'title' => t('Webform site result'),
    'help' => t('The end user is selecting this course to signup with.'),
    'field' => array(
      'handler' => 'views_handler_field',
      'click sortable' => FALSE,
    ),
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
  );
  
  $data['s4_reporting']['total_hours'] = array(
    'title' => t('Total hours'),
    'help' => t('Renders the total hours worked at a site.'),
    'field' => array(
      'handler' => 'views_handler_s4_reporting_site_hours',
      'click sortable' => FALSE,
    ),
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
  );
  
  $data['s4_reporting']['total_placements'] = array(
    'title' => t('Total placements'),
    'help' => t('Renders the total placements at a site.'),
    'field' => array(
      'handler' => 'views_handler_s4_reporting_site_placements',
      'click sortable' => FALSE,
    ),
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
  );
  
  return $data;
}
