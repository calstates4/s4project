<?php

/**
*  Views handler linking users to complete their evaluation.
*/
class views_handler_s4_sites_evaluation_status extends views_handler_field {

  function render($values) {
    $result = db_query('select f.entity_id FROM {field_data_field_user} f LEFT JOIN {node} n ON n.nid = f.entity_id  WHERE f.field_user_uid = :uid AND n.type = :type AND n.status = 1',
    array(':uid' =>  $values->users_field_data_field_course_students_uid,
        ':type' => 'signup'));
    foreach ($result as $row) {
      $signup = node_load($row->entity_id);
      $evaluation = field_get_items('node', $signup, 'field_form_evaluation_sid');
      if($evaluation[0]['value']) {
        return t('Evaluation completed');
      }
      $site = field_get_items('node', $signup, 'field_site');
      $site = node_load($site[0]['nid']);
      if(!$site) {
        return;
      }
      $signup_program = field_get_items('node', $signup, 'field_site_restrict');
      $forms = field_get_items('node', $site, 'field_site_evaluation_group');
      foreach($forms as $form) {
        $form = field_collection_item_load($form['value']);
        $programs = field_get_items('field_collection_item', $form, 'field_site_restrict');
        foreach($programs as $k => $program) {
          if($program['tid'] == $signup_program[0]['tid']) {
            $last_date = field_get_items('node', $signup, 'field_signup_last_date');
            if(time() < strtotime($last_date[0]['value']) - (variable_get('s4_sites_evaluation_form_lead_time', '14') * (24 * 60 * 60))) {
              return t('Cannot complete evaluation until @date', array('@date' => format_date(strtotime($last_date[0]['value']) - (variable_get('s4_sites_evaluation_form_lead_time', '14') * (24 * 60 * 60)))));
            }
            else {
              t('Evaluation not completed');
            }
          }
        }
      }
      return t('None required.');
    }
  }
  
  function query() {
    
  }
}