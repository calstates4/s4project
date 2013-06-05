<?php

/**
 * @file
 * Providing extra functionality for the s4_opportunity UI via views.
 */


/**
 * Implements hook_views_data()
 */
function s4_opportunity_views_data_alter(&$data) { 
  $data['s4_opportunity']['link__s4_opportunity'] = array(
    'field' => array(
      'title' => t('Link'),
      'help' => t('Provide a link to the s4_opportunity.'),
      'handler' => 's4_opportunity_handler_link_field',
    ),
  );
  $data['s4_opportunity']['edit_s4_opportunity'] = array(
    'field' => array(
      'title' => t('Edit Link'),
      'help' => t('Provide a link to the edit form for the s4_opportunity.'),
      'handler' => 's4_opportunity_handler_edit_link_field',
    ),
  );
  $data['s4_opportunity']['delete_s4_opportunity'] = array(
    'field' => array(
      'title' => t('Delete Link'),
      'help' => t('Provide a link to delete the s4_opportunity.'),
      'handler' => 's4_opportunity_handler_delete_link_field',
    ),
  );
  // This content of this field are decided based on the menu structure that
  // follows s4_opportunitys/s4_opportunity/%s4_opportunity_id/op
  $data['s4_opportunity']['operations'] = array(
    'field' => array(
      'title' => t('Operations links'),
      'help' => t('Display all operations available for this s4_opportunity.'),
      'handler' => 's4_opportunity_handler_s4_opportunity_operations_field',
    ),
  );
}
