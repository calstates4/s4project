<?php

/**
*  Views handler to render a link indicating the user can signup with a course
*/
class views_handler_s4_course_student_signup extends views_handler_field {

  function render($values) {
    $output = 'Not signed up';
    $result = db_query('select f.entity_id FROM {field_data_field_user} f LEFT JOIN {node} n ON n.nid = f.entity_id  WHERE f.field_user_uid = :uid AND n.type = :type AND n.status = 1',
    array(':uid' =>  $values->users_field_data_field_course_students_uid,
        ':type' => 'signup'));
    foreach ($result as $row) {
      $node = node_load($row->entity_id);
      $site = field_get_items('node', $node, 'field_site');
      $site = node_load($site[0]['nid']);
      $output = l($site->title, 'node/' . $site->nid);
      $coordinator = field_get_items('node', $node, 'field_coordinator');
      if ($coordinator[0]['nid']) {
        $coordinator = node_load($coordinator[0]['nid']);
        $output .= ' with ' . l($coordinator->title, 'node/' . $coordinator->nid);
      }
      $output .= '<br/>' . l(t('View signup'), 'node/' . $node->nid);
    }
    return $output;
  }

  function query() {

  }
}