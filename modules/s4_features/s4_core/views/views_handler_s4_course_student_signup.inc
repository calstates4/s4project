<?php

/**
*  Views handler to render a link indicating the user can signup with a course
*/
class views_handler_s4_course_student_signup extends views_handler_field {

  function render($values) {
    $output = '';
    $result = db_query('select f.entity_id FROM {field_data_field_user} f LEFT JOIN {node} n ON n.nid = f.entity_id  WHERE f.field_user_uid = :uid AND n.type = :type AND n.status = 1',
    array(':uid' =>  $values->users_field_data_field_course_students_uid,
        ':type' => 'signup'));
    $items = array();
    foreach ($result as $row) {
      $output = '';
      $node = node_load($row->entity_id);
      $site = field_get_items('node', $node, 'field_site');
      $site = node_load($site[0]['nid']);
      $output .= l($site->title, 'node/' . $site->nid);
      $coordinator = field_get_items('node', $node, 'field_coordinator');
      if ($coordinator[0]['nid']) {
        $coordinator = node_load($coordinator[0]['nid']);
        $output .= ' with ' . l($coordinator->title, 'node/' . $coordinator->nid);
      }
      $output .= '<br/>' . l(t('View placement'), 'node/' . $node->nid, array('query' => array('destination' => $_GET['q'])));
      $items[] = $output;
    }
    if(!count($items)) {
      return t('Not signed up');
    }
    if(count($items) == 1) {
      return reset($items);
    }
    return theme('item_list', array('items' => $items));
  }

  function query() {

  }
}