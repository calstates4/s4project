<?php

class views_handler_s4_user_course_select extends views_handler_field {

  function render($values) {
    if (isset($_SESSION['s4_signup_course']) && $_SESSION['s4_signup_course'] == $values->nid) {
      return '<div class="signup signed-up"><div class="icon"></div>Course selected</div>';
    }
    global $user;
    $signups = s4_core_get_user_signups($user->uid);
    foreach ($signups as $signup) {
      $course = field_get_items('node', $signup, 'field_course');
      if (count($course) && $course[0]['nid'] == $values->nid) {
        return '<div class="signup denied"><div class="icon"></div>' .
            t('Already signed up') .
             '</div>';
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