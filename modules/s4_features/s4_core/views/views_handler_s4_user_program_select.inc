<?php

class views_handler_s4_user_program_select extends views_handler_field {

  function render($values) {
    if(!$values->taxonomy_term_data_field_data_field_site_restrict_tid) {
      return;
    }
    if (isset($_SESSION['s4_signup_program']) && $_SESSION['s4_signup_program'] == $values->taxonomy_term_data_field_data_field_site_restrict_tid) {
      return '<div class="signup signed-up"><div class="icon"></div>Program selected</div>';
    }
    global $user;
    return '<div class="signup"><div class="icon"></div>' .
      l(t('Select this program'), 's4/signup/program/' . $values->taxonomy_term_data_field_data_field_site_restrict_tid,
        array('attributes' => array('data-target' => 'signup-program')))
      . '</div>';
  }

  function query() {

  }
}