<?php

/**
*	Add more body classes for the toolbar
*/
function s4_preprocess_html(&$vars) {
	if(!$vars['page']['content_right']) {
		$vars['classes_array'][] = 'no-content-sidebar';
	}
	if(!$vars['page']['content_top_right']) {
		$vars['classes_array'][] = 'no-content-top-right';
	}
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

/**
*	Override & remove the filter guidelines
*/
function s4_filter_guidelines($variables) {
	return '';
}

/**
*	Override & remove the filter tips
*/
function s4_filter_tips($variables) {
	return '';
}

/**
*	Override & remove the filter tips more info link
*/
function s4_filter_tips_more_info($variables) {
	return '';
}

