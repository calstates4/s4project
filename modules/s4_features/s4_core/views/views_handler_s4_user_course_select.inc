<?php

class views_handler_s4_user_course_select extends views_handler_field {

  function render($values) {
    if (isset($_SESSION['s4_signup_course']) && $_SESSION['s4_signup_course'] == $values->nid) {
      return '<div class="signup signed-up"><div class="icon"></div>' .
        l(t('Course selected'), 's4/signup/course/' . $values->nid,
        array('attributes' => array('data-target' => 'signup-course')))
        . '</div>';
    }
    global $user;
    $signups = s4_core_get_user_signups($user->uid);
    $count = array();
    foreach ($signups as $signup) {
      $course = field_get_items('node', $signup, 'field_course');
      $course = node_load($course[0]['nid']);
      if($course) {
        $count[$course->nid] = ($count[$course->nid]) ? $count[$course->nid] : 0;
        $max = field_get_items('node', $course, 'field_max_placements');
        $max = ($max[0]['value'] || $max[0]['value'] == 0)
               ? $max[0]['value']
               : 1;
        $count[$course->nid]++;
        if ($course->nid == $values->nid && ($max === 0 || $count[$course->nid] >= $max)) {
          return '<div class="signup denied"><div class="icon"></div>' .
              t('Already signed up') .
               '</div>';
        }
      }
    }
    return '<div class="signup"><div class="icon"></div>' .
      l(t('Select this course'), 's4/signup/course/' . $values->nid,
        array('attributes' => array('data-target' => 'signup-course')))
      . '</div>';
  }

  function query() {

  }
}