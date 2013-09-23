<?php

function s4_courses_faculty_signup_student_form($form, $form_state, $student) {
	global $user;
	module_load_include('inc', 's4_core', 's4_core.pages');
	$form = s4_core_create_signup_form($form, $form_state, $student->uid, 'new');

	$course_list = db_select('field_data_field_course_students', 's')
         ->fields('s', array('entity_id'))
         ->condition('s.bundle', 'course')
         ->condition('s.field_course_students_uid', $student->uid)
         ->distinct()
         ->execute()
         ->fetchCol();

  $form['course'] = array(
    '#type' => 'select',
    '#title' => 'Course',
    '#options' => $courses,
    '#attributes' => array('class' => array('chosen')),
    '#ajax' => array(
      'callback' => 's4_core_site_options_courses',
      'wrapper' => 'site-list',
      'progress' => array(
        'type' => 'throbber',
        'message' => t('Changing sites'),
      ),
    ),
  );

  foreach ($course_list as $course) {
    $course = node_load($course);
    $instructors = field_get_items('node', $course, 'field_course_faculty');
    foreach($instructors as $instructor) {
    	if($user->uid == $instructor['uid']) {
    		$term = field_get_items('node', $course, 'field_term');
		    if($term[0]['nid']) {
		      $term = node_load($term[0]['nid']);
		      $dates = field_get_items('node', $term, 'field_term_date_start');
		      if(strtotime($dates[0]['value']) < time() && strtotime($dates[0]['value2']) > time()) {
		        $form['course']['#default_value'] = $course->nid;
		      }
		      $form['course']['#options'][$term->title][$course->nid] = $course->title;
		    }
    	}
    }
  }

	return $form;
}