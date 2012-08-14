<?php

function s4_courses_load_demo_course() {
  $result = db_query('SELECT uid FROM users WHERE name LIKE :student', array(':student' => 'student%'));
  $students = array();
  foreach($result as $row) {
     $students[] = array('uid' => $row->uid);
  }
  $result = db_query('SELECT uid FROM users WHERE name LIKE :faculty', array(':faculty' => 'faculty%'));
  $faculty = array();
  foreach($result as $row) {
     $faculty[] = array('uid' => $row->uid);
  }
  $term = db_query('SELECT nid FROM node WHERE type = :type LIMIT 1', array(':type' => 'course_term'));
  foreach($term as $t) {
    $term = $t->nid;
  }
  $node = new stdClass();
  $node->type = 'course';
  node_object_prepare($node);

  foreach(taxonomy_get_vocabularies() as $vocabulary) {
    if($vocabulary->machine_name == 'site_restrictions') {
      foreach(taxonomy_get_tree($vocabulary->vid) as $term) {
        if($term->name == 'Service Learning') {
          $tid = $term->tid;
        }
      }
    }
  }
  $node->uid = 1;
  $node->language = LANGUAGE_NONE;
  $node->title = 'TEST 101 (1): Testing S4';
  $node->field_course_catalog_number[$node->language][0]['value'] = '101';
  $node->field_course_faculty[$node->language] = $faculty;
  $node->field_course_students[$node->language] = $students;
  $node->field_course_subject[$node->language][0]['value'] = 'TEST';
  $node->field_course_section[$node->language][0]['value'] = 1;
  $node->field_site_restrict[$node->language][0]['tid'] = $tid;
  $node->field_course_title[$node->language][0]['value'] = 'Testing S4';
  $node->field_term[$node->language][0]['nid'] = $term;
  
  node_save($node);
}