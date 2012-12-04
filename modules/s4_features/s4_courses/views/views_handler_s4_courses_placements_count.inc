<?php

class views_handler_s4_courses_placements_count extends views_handler_field {

  function render($values) {
    $language = $values->_field_data['nid']['entity']->language;
    $enrollment = count($values->_field_data['nid']['entity']->field_course_students[$language]);
    if(!$enrollment) {
      return 0;
    }
    $placements = db_select('field_data_field_course', 'c')
                    ->condition('entity_type', 'node')
                    ->condition('bundle', 'signup')
                    ->condition('deleted', 0)
                    ->condition('field_course_nid',  $values->nid)
                    ->fields('c', array('entity_id'))
                    ->countQuery()
                    ->execute()
                    ->fetchField();
    if($this->options['display_percentage']) {
      return t('@placements (@percent%)', array('@placements' => $placements,
                                              '@percent' => round(($placements / $enrollment) * 100)));
    }
    return $placements;
  }
  
  function option_definition() {
    $options = parent::option_definition();

    $options['display_percentage'] = array('default' => FALSE, 'bool' => TRUE);

    return $options;
  }
  
  function options_form(&$form, &$form_state) {

    $form['display_percentage'] = array(
      '#type' => 'checkbox',
      '#title' => t('Display percentage'),
      '#description' => t('If checked, the percent of students placed will be displayed.'),
      '#default_value' => $this->options['display_percentage'],
    );

    parent::options_form($form, $form_state);
  }
  
  function query() {
    
  }

}