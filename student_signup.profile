<?php
if(!function_exists('profiler_v2')) {
  require_once('libraries/profiler/profiler.inc');
}

profiler_v2('student_signup');

/**
*  Implements hook_task_list
*/
function student_signup_profile_task_list() {
  return array(
    'student_signup_wysiwyg' => st('Setting up WYSIWYG editor'),
  );
}

/**
*  Implementation of hook_profile_task
*/
function student_signup_profile_tasks(&$task, $url) {
  if($task == 'student_signup_wysiwyg') {
    $settings = array(
      'default' => 1,
      'user_choose' => 0,
      'show_toggle' => 1,
      'theme' => 'advanced',
      'language' => 'en',
      'buttons' => array(
        'default' => array(
          'bold' => 1,
          'italic' => 1,
          'underline' => 1,
          'bullist' => 1,
          'numlist' => 1,
          'undo' => 1,
          'redo' => 1,
          'link' => 1,
          'unlink' => 1,
          'anchor' => 1,
          'image' => 1,
          'blockquote' => 1,
          'cut' => 1,
          'copy' => 1,
          'paste' => 1,
          'removeformat' => 1,
          'charmap' => 1,
        ),
        'font' => array(
          'formatselect' => 1,
        ),
        'imce' => array(
          'imce' => 1,
        ),
      ),
      'toolbar_loc' => 'top',
      'toolbar_align' => 'left',
      'path_loc' => 'bottom',
      'resizing' => 1,
      'verify_html' => 1,
      'preformatted' => 0,
      'convert_fonts_to_spans' => 1,
      'remove_linebreaks' => 1,
      'apply_source_formatting' => 0,
      'paste_auto_cleanup_on_paste' => 0,
      'block_formats' => 'p,h2,h3,h4,h5,h6',
      'css_setting' => 'self',
      'css_path' => '%b%t/css/editor.css',
      'css_classes' => '',
    );
    
    $fields = array(
      'format' => 'filtered_html',
      'editor' => 'tinymce',
      'settings' => serialize($settings),
      'status' => 3,
      'module' => 's3_editor',
    );
    $result = db_insert('wysiwyg')
          ->fields($fields)
          ->execute();
  }
}