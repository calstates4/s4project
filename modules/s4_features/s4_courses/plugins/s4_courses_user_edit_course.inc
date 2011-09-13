<?php

/**
 * Expose that a user can edit a node
 */
class s4_courses_user_edit_course extends context_condition {
  /**
   * Omit condition values. We will provide a custom input form for our conditions.
   */
  function condition_values() {
    return array(1 => t('User is faculty or staff'));
  }

  /**
   * Condition form.
   */
  function editor_form($context) {
    $form = parent::editor_form($context);
    $form[1]['#title'] = t('Active if user is faculty in a course');
    $form['#weight'] = -10;

    return $form;
  }

  /**
   * Execute.
   */
  function execute($value) {
    foreach ($this->get_contexts($value) as $context) {
		// Include both the path alias and normal path for matching.
		global $user;
		$faculty = array();
		$course_faculty = field_get_items('node', $value, 'field_course_faculty');
		if(is_array($course_faculty)) {
		  foreach($course_faculty as $faculty_uid) {
		  	$faculty[] = $faculty_uid['uid'];
		  }
		}
		if($value->type == 'course' && in_array($user->uid, $faculty)) {
			$this->condition_met($context, $value);
		}
    }
  }

}
