<?php


include_once(drupal_get_path('theme', 's4') . '/includes/s4.inc');
include_once(drupal_get_path('theme', 's4') . '/includes/modules/theme.inc');
include_once(drupal_get_path('theme', 's4') . '/includes/modules/pager.inc');
include_once(drupal_get_path('theme', 's4') . '/includes/modules/form.inc');
include_once(drupal_get_path('theme', 's4') . '/includes/modules/admin.inc');
include_once(drupal_get_path('theme', 's4') . '/includes/modules/menu.inc');
include_once(drupal_get_path('theme', 's4') . '/includes/modules/views.inc');


/**
*  Add more body classes for the toolbar
*/
function s4_preprocess_html(&$vars) {
  if(!$vars['page']['content_right']) {
    $vars['classes_array'][] = 'no-content-sidebar';
  }
  if(!$vars['page']['content_top_right']) {
    $vars['classes_array'][] = 'no-content-top-right';
  }
  if($vars['page']['footer_map']) {
    $vars['classes_array'][] = 'has-footer-map';
  }
  drupal_add_css(path_to_theme() . '/css/ie7.css', array('group' => CSS_THEME, 'browsers' => array('IE' => 'lte IE 8', '!IE' => FALSE), 'preprocess' => FALSE));
}

/**
 * Override or insert variables into the page template for HTML output.
 */
function s4_process_html(&$variables) {
  // Hook into color.module.
  if (module_exists('color')) {
    _color_html_alter($variables);
  }
}

function s4_preprocess_page(&$variables) {
	if($variables['page']['#views_contextual_links_info']['views_ui']['view_name'] == 'sites') {
		$variables['flip_columns'] = true;
	}
}

function s4_links__system_main_menu($variables) {
  global $conf;
  if($conf['s4_pages_program_homepage']) {
    
    foreach($variables['links'] as &$link) {
      if($link['href'] == 'site') {
        $link['href'] = 'site-list';
        $link['query'] = array('program' => array($conf['s4_pages_program_homepage']));
      }
    }
  }
  return theme_links($variables);
}
 
function s4_progress_bar($variables) {
  $output = '<div id="progress" class="progress progress-striped active">';
  $output .= '<div class="bar" style="width: ' . $variables['percent'] . '%"></div>';
  $output .= '</div>';
  $output .= '<div class="message">' . $variables['message'] . '</div>';

  return $output;
}

/**
*  Override & remove the filter guidelines
*/
function s4_filter_guidelines($variables) {
  return '';
}

/**
*  Override & remove the filter tips
*/
function s4_filter_tips($variables) {
  return '';
}

/**
*  Override & remove the filter tips more info link
*/
function s4_filter_tips_more_info($variables) {
  return '';
}

function s4_file_link($variables) {
  $file = $variables['file'];
  $icon_directory = $variables['icon_directory'];

  $url = file_create_url($file->uri);
  $icon = theme('file_icon', array('file' => $file, 'icon_directory' => $icon_directory));

  // Set options as per anchor format described at
  // http://microformats.org/wiki/file-format-examples
  $options = array(
    'attributes' => array(
      'type' => $file->filemime . '; length=' . $file->filesize,
    ),
  );

  // Use the description as the link text if available.
  if (empty($file->description)) {
    $link_text = $file->filename;
  }
  else {
    $link_text = $file->description;
    $options['attributes']['title'] = check_plain($file->filename);
  }

  //open files of particular mime types in new window
  $new_window_mimetypes = array('application/pdf','text/plain');
  if (in_array($file->filemime, $new_window_mimetypes)) {
    $options['attributes']['target'] = '_blank';
  }

  return '<span class="file">' . $icon . ' ' . l($link_text, $url, $options) . '</span>';
}

?>