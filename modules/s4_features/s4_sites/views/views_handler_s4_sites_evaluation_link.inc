<?php

/**
*  Views handler linking users to complete their evaluation.
*/
class views_handler_s4_sites_evaluation_link extends views_handler_field {

  function render($values) {
    $signup = node_load($values->nid);
    $evaluation = field_get_items('node', $signup, 'field_form_evaluation_sid');
    if($evaluation[0]['value']) {
      return t('Evaluation completed');
    }
    $last_date = field_get_items('node', $signup, 'field_signup_last_date');
    if(time() < strtotime($last_date[0]['value']) - (variable_get('s4_sites_evaluation_form_lead_time', '14') * (24 * 60 * 60))) {
      return t('Cannot complete evaluation until @date', array('@date' => format_date(strtotime($last_date[0]['value']) - (variable_get('s4_sites_evaluation_form_lead_time', '14') * (24 * 60 * 60)))));
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
          return l('Complete evaluation', 'signup/'. $values->nid .'/evaluation');
        }
      }
    }
    return t('No evaluation required.');
  }
  
  function query() {
    
  }
}