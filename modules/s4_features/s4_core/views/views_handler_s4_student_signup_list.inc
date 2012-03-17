<?php

/**
*  Views handler to render links to all locations in a site
*/
class views_handler_s4_student_signup_list extends views_handler_field {

  function render($values) {
    $query = db_select('field_data_field_user', 's')
         ->condition('s.bundle', 'signup')
         ->condition('s.entity_type', 'node')
         ->condition('s.field_user_uid', $values->uid);
    $query->leftJoin('field_data_field_site', 'site', 's.entity_id = site.entity_id AND s.bundle = :signup', array(':signup' => 'signup'));
    $query->leftJoin('node', 'n', 'n.nid = s.entity_id');
    $query->fields('n', array('nid', 'title'));
    $results = $query->execute();
    $list = array();
    while ($row = $results->fetchAssoc()) {
      $signup = node_load($row['nid']);
      $site = field_get_items('node', $signup, 'field_site');
      $site = node_load($site[0]['nid']);
         $list[] = l($site->title, 'node/' . $row['nid']);
    }
    if (count($list) == 0) {
      return '';
    }
    return theme('item_list', array('items' => $list));
  }

  function query() {

  }
}