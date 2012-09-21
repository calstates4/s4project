<?php

/**
*  Views handler to render a link indicating the user can signup with a course
*/
class views_handler_s4_course_student_signup extends views_handler_field {

  function render($values) {
    $output = '';
    $query = db_select('field_data_field_user', 'f');
    $query->leftJoin('node', 'n', 'n.nid = f.entity_id');
    $node = menu_get_object();
    if($node && $node->type == 'course') {
      $query->leftJoin('field_data_field_course', 'c', 'c.entity_id = f.entity_id');
      $query->condition('c.field_course_nid', $node->nid);
    }
    $result = $query->condition('n.status', 1)
          ->condition('n.type', 'signup')
          ->condition('f.field_user_uid', $values->users_field_data_field_course_students_uid)
          ->fields('n', array('nid'))
          ->execute();
    $items = array();
    foreach ($result as $row) {
      $output = '';
      $node = node_load($row->nid);
      if(node_access('view', $node)) {
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