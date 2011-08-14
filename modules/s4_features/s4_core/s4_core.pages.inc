<?php

/**
*  Menu callback to handle the student doing their site evaluations
*/
function s4_core_signup_evaluation($node) {
  $eval_date = field_get_items('node', $node, 'field_signup_last_date');
  if (strtotime($eval_date[0]['value']) >= time()) {
    drupal_set_message(t('You cannot complete your evaluation until @date',
              array('@date' => format_date(strtotime($eval_date[0]['value'])))), 'error');
    return '';
  }
  $site = field_get_items('node', $node, 'field_site');
  $site = node_load($site[0]['nid']);
  $eval_form = field_get_items('node', $site, 'field_site_eval_form');
  $eval_form = node_load($eval_form[0]['nid']);
  if (!$eval_form) {
    drupal_set_message(t('The site @site does not require an evaluation', 
               array('@site' => $site->title)), 'error');
    return '';
  }
  $_SESSION['s4_core_site_eval_signup'] = $node->nid;
  drupal_goto('node/' . $eval_form->nid);
}

/**
*  Menu callback to handle when a user has added a site to 
*  a course.
*/
function s4_core_add_site_to_course($op = 'add', $course, $site) {
  $course = node_load($course);
  $site = node_load($site);
  if (!$sites = field_get_items('node', $course, 'field_sites')) {
    $sites = array();
  }
  if ($op == 'add') {
    $sites[] = array('nid' => $site->nid);
    $message = 'Site added';
  }
  if ($op == 'remove') {
    foreach ($sites as $key => $course_site) {
      if ($course_site['nid'] == $site->nid) {
        unset($sites[$key]);
      }
    }
    $message = 'Site removed';
  }
  $course->field_sites[$course->language] = $sites;
  node_save($course);
  if ($_GET['js']) {
    print json_encode(array('success' => 1, 'action' => $op, 'message' => $message));
    die();
  }
  drupal_goto('node/' . $site->nid);
  return '';
}

/**
*  Menu callback to handle signup actions by users
*  This should handle all links which add additional data
*  to the current user's signup record
*/
function s4_core_signup($type, $nid) {
  module_invoke_all('s4_signup', $type, $nid);
  if ($type == 'site') {
    $site = node_load($nid);
    if ($site->type == 'site') {
      $instructions = field_get_items('node', $site, 'field_site_instructions_required');
      $instruction_text = field_get_items('node', $site, 'field_site_instructions');
      $locations = field_get_items('node', $site, 'field_location');
      
      if(!$_SESSION['s4_signup_location'] && count($locations) > 1) {
      	drupal_goto('sites/'. $site->nid .'/locations');
      }
      elseif ($instructions[0]['value'] && strip_tags($instruction_text[0]['value']) != '' && !$_GET['agreed']) {
        drupal_set_message('This site requires that you read and agree to these additional instructions');
        drupal_set_title(t('Site instructions'));
        return $instruction_text[0]['value'] . 
            '<p>' .
                 l('Agree', 's4/signup/' . $type . '/' . $site->nid,
                   array('query' => array('agreed' => 1),
                   			 'attributes' => array('class' => array('button')))) .
                 ' ' . l('Return to site', 'node/' . $site->nid) . 
            '</p>';
      }
      else {
        $_SESSION['s4_signup_site'] = check_plain($nid);
        if(variable_get('s4_core_collect_service_hours', TRUE) && !$_SESSION['s4_signup_hours']) {
	  	   drupal_set_title('Service hours');
	  	   return drupal_get_form('s4_core_student_signup_hours');
	    }
        $form = field_get_items('node', $site, 'field_site_form');
        if ($form) {
          drupal_set_message(t('This site requires an additional form to be completed after you select your coordinator'));
        }
        drupal_set_message(t('Site @site selected.', array('@site' => $site->title)));
        if (module_exists('views')) {
          $site_coordinators = views_get_view_result('site_coordinators', 'block', $site->nid);
          if (!count($site_coordinators)) {
            drupal_set_message(t('This site does not have any coordinators, so we\'re skipping this step.'));
            $site_skip_coordinator = TRUE;
          }
          else {
            drupal_goto('sites/' . $site->nid . '/coordinators');
          }
        }
      }
    }
  }
  
  if($type == 'location') {
  	$_SESSION['s4_signup_location'] = check_plain($nid);
  	drupal_goto('s4/signup/site/'. check_plain(arg(4)));
  }
  
  if ($type == 'coordinator') {
    $site = node_load($_SESSION['s4_signup_site']);
    $coordinator = node_load($nid);
    if ($coordinator && $coordinator->type == 'coordinator') {
      $_SESSION['s4_signup_coordinator'] = check_plain($nid);
    }
    else {
      drupal_set_message(t('That is not a coordinator'));
    }
  }
  if ($type == 'coordinator' || ($type == 'site' && $site_skip_coordinator)) {
    $form = field_get_items('node', $site, 'field_site_form');    
    if ($form !== FALSE && count($form)) {
      drupal_goto('node/' . $form[0]['nid']);
    }
    else {
      s4_core_user_signup_completed();
    }
  }
  
  drupal_set_message(t($message));
  drupal_goto('node/' . $nid);
}  


/**
*	System settings landing page
*/
function s4_core_site_settings() {
	drupal_add_css(drupal_get_path('module', 's4_core') .'/css/admin.css');
	drupal_add_css(drupal_get_path('module', 'system') .'system.admin.css');
	$links = module_invoke_all('s4_site_configuration');
	$result = array();
	foreach($links as $k => $link) {
		$result[$link['group']][$k] = l($link['title'], $link['href']) . '<div class="description">'. $link['description'];
	}
	foreach($result as $k => $r) {
		$result[$k] = array('title' => $k,
							'show' => TRUE,
							'content' => theme('item_list', array('items' => $r, 'attributes' => array('class' => array('admin-list')))));
	}
	return theme('admin_page', array('blocks' => $result));
}

/**
*	Implementation of hook_s4_site_configuration
*/
function s4_core_s4_site_configuration() {
	return array(
		'theme_colors' => array(
			'group' => t('Appearance'),
			'title' => t('Change colors & logo'),
			'href' => 'admin/appearance/settings/s4',
		),
		's4_general' => array(
			'group' => t('General settings'),
			'title' => t('General configuration'),
			'description' => t('Change login preferences, messages, and other general settings.'),
			'href' => 'admin/config/s4',
		),
		's4_general_user' => array(
			'group' => t('General settings'),
			'title' => t('Map user fields to SIS field'),
			'description' => t('Add additional user attributes coming from your SIS.'),
			'href' => 'admin/config/s4/user-attributes',
		),
	);
}