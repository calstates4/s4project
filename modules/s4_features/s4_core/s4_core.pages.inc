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
      $instructions = field_get_items('node', $site, 'field_site_instructions_required', $node->language);
      $instruction_text = field_get_items('node', $site, 'field_site_instructions');
      $locations = field_get_items('node', $site, 'field_location');
      $form_terms = s4_core_site_has_downloadable_forms($site);
      if($_GET['agreed']) {
        $_SESSION['s4_signup_agreed'] = true;
      }
      if(!$_SESSION['s4_signup_location'] && count($locations) > 1) {
      	drupal_goto('sites/'. $site->nid .'/locations');
      }
      elseif ($instructions[0]['value'] && strip_tags($instruction_text[0]['value']) != '' && !$_SESSION['s4_signup_agreed']) {
        drupal_set_message('This site requires that you read and agree to these additional instructions');
        drupal_set_title(t('Site instructions'));
        return check_markup($instruction_text[0]['value'], $instruction_text[0]['format']) . 
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
        if($form_terms && !$_SESSION['s4_core_viewed_downloadable_forms']) {
          $_SESSION['s4_core_viewed_downloadable_forms'] = TRUE;
          drupal_goto('forms/download/' . implode('+', $form_terms));
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
		's4_site_settings' => array(
			'group' => t('General settings'),
			'title' => t('Site name'),
			'description' => t('Change the site name and footer message.'),
			'href' => 'admin/config/system/site-information',
		),
		's4_general_user' => array(
			'group' => t('General settings'),
			'title' => t('Map user fields to SIS field'),
			'description' => t('Add additional user attributes coming from your SIS.'),
			'href' => 'admin/config/s4/user-attributes',
		),
	);
}

/**
*	Form to quickly sign up student with a site
*/
function s4_core_create_signup_form($form, $form_state, $uid) {

	$user = user_load($uid);
	drupal_set_title(t('Sign up @name', array('@name' => s4_core_get_user_full_name($user))));
	$form = array();
	
	$form['user'] = array(
		'#type' => 'hidden',
		'#value' => $user->uid,
	);
	
	if(module_exists('s4_courses')) {
		$courses = array();
		
		$course_list = db_select('field_data_field_course_students', 's')
				 ->fields('s', array('entity_id'))
				 ->condition('s.bundle', 'course')
				 ->condition('s.field_course_students_uid', $user->uid)
				 ->distinct()
				 ->execute()
				 ->fetchCol();
		
		foreach($course_list as $course) {
			$course = node_load($course);
			$term = field_get_items('node', $course, 'field_term');
			$term = node_load($term[0]['nid']);
			$courses[$term->title][$course->nid] = $course->title;
		}
		
		$form['course'] = array(
			'#type' => 'select',
			'#title' => 'Course',
			'#options' => $courses,
			'#attributes' => array('class' => array('chosen')),
		);
	}
	
	$sites = array(0 => 'Select a site');
	$query = db_select('node', 'n')
			 ->fields('n', array('nid', 'title'))
			 ->condition('type', 'site')
			 ->orderBy('title', 'ASC');
	$results = $query->execute();
	foreach($results as $result) {
		$sites[$result->nid] = $result->title;
	}
	$form['site'] = array(
		'#type' => 'select',
		'#title' => 'Site',
		'#options' => $sites,
		'#attributes' => array('class' => array('chosen')),
		'#ajax' => array(
			'callback' => 's4_core_site_staff_choice',
			'wrapper' => 'site-staff-select',
			'progress' => array(
				'type' => 'throbber',
				'message' => 'Looking up site staff',
			),
		),
	);
	
	$site_staff_options = array();
	if($form_state['values']['site']) {
		$site_staff = db_select('field_data_field_site', 's')
					  ->fields('s', array('entity_id'))
					  ->condition('s.bundle', 'coordinator')
					  ->condition('s.field_site_nid', $form_state['values']['site'])
					  ->execute()
					  ->fetchCol();
		foreach($site_staff as $staff) {
			$staff = node_load($staff);
			$available = field_get_items('node', $staff, 'field_staff_signup_available');
			if($available[0]['value']) {
				$role = field_get_items('node', $staff, 'field_staff_role');
				$role = taxonomy_term_load($role[0]['tid']);
				$site_staff_options[$staff->nid] = t('@title (@role)', array('@title' => $staff->title,
																			 '@role' => $role->name));
			}
		}
	}
	
	$form['site-staff'] = array(
		'#type' => 'radios',
		'#prefix' => '<div id="site-staff-select">',
		'#suffix' => '</div>',
		'#title' => 'Site staff',
		'#options' => $site_staff_options,
	);
	
	$form['hours'] = array(
		'#type' => 'textfield',
		'#title' => 'Number of expected hours of services',
		'#size' => 6,
	);
	
	$form['email-student'] = array(
		'#type' => 'checkbox',
		'#title' => 'Send student email to complete a signup form (if the site has one)',
		'#default_value' => 1,
	);
	
	$form['submit'] = array(
		'#type' => 'submit',
		'#value' => 'Create signup',
	);
	
	return $form;
}

function s4_core_create_signup_form_validate($form, $form_state) {
	if($form_state['values']['site'] == 0) {
		form_set_error('site', t('You must select a site to save this signup record.'));
	}
}

function s4_core_create_signup_form_submit($form, $form_state) {
	$signup = array('user' => $form_state['values']['user'],
           'site' => $form_state['values']['site'],
           'course' => $form_state['values']['course'],
           'coordinator' => ($form_state['values']['site-staff']) ? $form_state['values']['site-staff'] : 0,
           'hours' => $form_state['values']['hours']
          );
	$signup = _s4_core_create_signup($form_state['values']['user'], $signup);
	drupal_set_message('Created !signup record', array('!signup' => l(t('signup #@number', array('@number' => $signup->nid)), 'node/'. $signup->nid)));
	$site = node_load($form_state['values']['site']);
	$form = field_get_items('node', $site, 'field_site_form');
	if($form[0]['nid'] && $form_state['values']['email-student']) {
		
	}
	drupal_goto($form_state['values']['destination']);
}

function s4_core_student_signup_complete($signup) {
	$signup = node_load($signup);
	$site = field_get_items('node', $signup, 'field_site');
	$site = node_load($site[0]['nid']);
	$form = field_get_items('node', $site, 'field_site_form');
	$sid = field_get_items('node', $signup, 'field_form_assessment_sid');
	if(!$sid[0]['value']) {
		$_SESSION['s4_core_student_signup_complete'] = $signup->nid;
		drupal_goto('node/'. $form[0]['nid']);
	}
}