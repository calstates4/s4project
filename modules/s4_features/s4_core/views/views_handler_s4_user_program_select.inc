<?php

class views_handler_s4_user_program_select extends views_handler_field {

  function render($values) {
    if(!$values->taxonomy_term_data_field_data_field_site_restrict_tid) {
      return;
    }
    if (isset($_SESSION['s4_signup_program']) && $_SESSION['s4_signup_program'] == $values->taxonomy_term_data_field_data_field_site_restrict_tid) {
      return '<a class="btn btn-info disabled"><i class="icon-check icon-white"></i> Program selected</a>';
    }
    global $user;
    return 
      l('<i class="icon-ok-circle icon-white"></i> ' . t('Select this program'), 
      	's4/signup/program/' . $values->taxonomy_term_data_field_data_field_site_restrict_tid,
        array('html' => TRUE,
        			'attributes' => array(
        				'class' => array('btn', 'btn-primary'),
	        			'data-target' => 'signup-program')));
  }

  function query() {

  }
}