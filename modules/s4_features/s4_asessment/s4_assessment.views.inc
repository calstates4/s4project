<?php

function s4_assessment_views_data() {
  $data['s4_assessment']['table']['group'] = t('Assessment');
  $data['s4_assessment']['table']['join'] = array(
  'node' => array(
    'left_field' => 'nid',
    'field' => 'nid',
  ),
  );


  $data['s4_assessment']['assessment_link'] = array(
    'title' => t('Assessment link'),
    'help' => t('Link to view/complete the assessment.'),
    'field' => array(
      'handler' => 'views_handler_s4_assessment_link',
      'click sortable' => FALSE,
    ),
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
  );
  
  return $data;
}
