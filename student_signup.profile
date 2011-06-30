<?php
if(!function_exists('profiler_v2')) {
  require_once('libraries/profiler/profiler.inc');
}

profiler_v2('student_signup');
/*
function student_signup_install_tasks() {
	return array(
		'student_signup_install_change_block_titles' => array(
			'display_name' => t('Changing block titles'),
			'type' => 'normal',
		),
	);
}

function student_signup_install_change_block_titles() {
  $block_titles = array('field_files' => 'Attachments',
                        'field_site_images' => '<none>',
                        'field_site' => '<none>',
                        'field_site' => '<none>',
                        'field_website' => '<none>',
                        'field_files' => 'Attachments',
                        'field_site' => '<none>',
                        'field_site_images' => '<none>',
                        'field_website' => '<none>',
                        'field_csu_facility' => '<none>',
                        'field_csu_org_type' => '<none>',
                        'field_course_faculty' => '<none>',
                        'field_site_restrict' => '<none>',
                        'field_course_students' => '<none>',
                        'field_phone' => '<none>',
                        'field_file_category' => '<none>',
                        'field_file_tags' => '<none>',
                        'field_expiration_date' => '<none>',
                        'field_expiration_reminder' => '<none>',
                        'field_user' => '<none>',
                        'field_coordinator' => '<none>',
                        'field_course' => '<none>',);
  foreach($block_titles as $block => $title) {
    db_update('block')
      ->fields(array(
        'title' => $title
      ))
      ->condition('module', 'cck_blocks')
      ->condition('delta', $block)
      ->execute();
  }
}*/