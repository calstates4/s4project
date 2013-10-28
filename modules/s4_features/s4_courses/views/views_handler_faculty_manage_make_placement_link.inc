<?php

class views_handler_faculty_manage_make_placement_link extends views_handler_field {

  function render($values) {
  	global $user;
  	if(!s4_courses_user_is_faculty($user) || !user_access('manage course students')) {
  		return;
  	}
  	$uid = (isset($values->uid)) ? $values->uid : $values->users_field_data_field_course_students_uid;
    return l(t('Place'), 'signup/create/faculty/'. $uid, array('query' => array('modal' => 'modal'), 'attributes' => array('class' => array('btn', 'iframe-modal'), 'data-modal-title' => t('Place @first @last', array('@first' => $values->field_field_first_name[0]['raw']['value'], '@last' => $values->field_field_last_name[0]['raw']['value'])))));
  }

  function query() {

  }
}