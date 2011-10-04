<?php
if(!function_exists('profiler_v2')) {
  require_once('libraries/profiler/profiler.inc');
}

profiler_v2('student_signup');

function student_signup_form_install_configure_form_alter(&$form, $form_state) {
	$form['#submit'][] = 'student_signup_setup_homepage';
}

function student_signup_setup_homepage($form, $form_state) {
	foreach(user_roles() as $rid => $name) {
		db_delete('front_page')
				 ->condition('rid', $rid)
				 ->execute();
		if($name == 'staff') {
			$result = db_insert('front_page')
			->fields(array('rid' => $rid, 
						   'mode' => 'alias', 
						   'data' => 'home', 
						   'filter_format' => '', 
						   'weight' => 0))
			->execute();
		}
		else {
			db_insert('front_page')
			->fields(array('rid' => $rid, 
						   'mode' => '', 
						   'data' => '', 
						   'filter_format' => '', 
						   'weight' => 0))
			->execute();
		}
	}

}