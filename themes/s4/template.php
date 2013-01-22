<?php

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

/**
*	Override the status messages to place a container div within them
*/
function s4_status_messages($variables) {
  $display = $variables['display'];
  $output = '';

  $status_heading = array(
    'status' => t('Status message'), 
    'error' => t('Error message'), 
    'warning' => t('Warning message'),
  );
  foreach (drupal_get_messages($display) as $type => $messages) {
    $output .= "<div class=\"messages $type\">\n";
    $output .= "<div class=\"container\">\n";
    $output .= "<div class=\"message-icon\"></div>";
    if (!empty($status_heading[$type])) {
      $output .= '<h2 class="element-invisible">' . $status_heading[$type] . "</h2>\n";
    }
    if (count($messages) > 1) {
      $output .= " <ul>\n";
      foreach ($messages as $message) {
        $output .= '  <li>' . $message . "</li>\n";
      }
      $output .= " </ul>\n";
    }
    else {
      $output .= $messages[0];
    }
    $output .= "</div>\n";
    $output .= "</div>\n";
  }
  return $output;
}
?>