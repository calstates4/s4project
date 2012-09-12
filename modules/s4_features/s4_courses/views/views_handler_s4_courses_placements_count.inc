<?php

class views_handler_s4_courses_placements_count extends views_handler_field {

  function render($values) {
    $language = $values->_field_data['nid']['entity']->language;
    $enrollment = count($values->_field_data['nid']['entity']->field_course_students[$language]);
    $placements = db_select('field_data_field_course', 'c')
                    ->condition('entity_type', 'node')
                    ->condition('bundle', 'signup')
                    ->condition('deleted', 0)
                    ->condition('field_course_nid',  $values->nid)
                    ->fields('c', array('entity_id'))
                    ->countQuery()
                    ->execute()
                    ->fetchField();
    return t('@placements (@percent%)', array('@placements' => $placements,
                                              '@percent' => round($placements / $enrollment, 1)));
  }
  
  function query() {
    
  }
}