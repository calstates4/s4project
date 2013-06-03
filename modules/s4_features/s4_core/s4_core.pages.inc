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
    $message = t('Site added');
  }
  if ($op == 'remove') {
    foreach ($sites as $key => $course_site) {
      if ($course_site['nid'] == $site->nid) {
        unset($sites[$key]);
      }
    }
    $message = t('Site removed');
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
  if ($type == 'program') {
    $_SESSION['s4_signup_program'] = $nid;
    drupal_goto('site-list', array('query' => array('program[]' => $nid)));
  }
  if ($type == 'site') {
    $site = node_load($nid);
    if ($site->type == 'site') {
      $instructions = field_get_items('node', $site, 'field_site_instructions_required', $node->language);
      $instruction_text = field_get_items('node', $site, 'field_site_instructions');
      $locations = field_get_items('node', $site, 'field_location');
      $form_terms = s4_core_site_has_downloadable_forms($site);
      $program_forms = s4_core_program_has_downloadable_forms($_SESSION['s4_signup_program']);
      if ($_GET['agreed']) {
        $_SESSION['s4_signup_agreed'] = TRUE;
      }
      if (!$_SESSION['s4_signup_location'] && count($locations) > 1) {
        drupal_goto('sites/' . $site->nid . '/locations');
      }
      elseif ($instructions[0]['value'] && strip_tags($instruction_text[0]['value']) != '' && !$_SESSION['s4_signup_agreed']) {
        drupal_set_message(t('This site requires that you read and agree to these additional instructions'));
        drupal_set_title(t('Site instructions'));
        return check_markup($instruction_text[0]['value'], $instruction_text[0]['format']) .
            '<p>' .
                 l(t('Agree'), 's4/signup/' . $type . '/' . $site->nid,
                   array('query' => array('agreed' => 1),
                          'attributes' => array('class' => array('btn')))) .
                 ' ' . l(t('Return to site'), 'node/' . $site->nid) .
            '</p>';
      }
      else {
        $_SESSION['s4_signup_site'] = check_plain($nid);
        if (variable_get('s4_core_collect_service_hours', TRUE) && !$_SESSION['s4_signup_hours']) {
           drupal_set_title(t('Service hours'));
           return drupal_get_form('s4_core_student_signup_hours');
        }
        if (($program_forms || $form_terms) && !$_SESSION['s4_core_viewed_downloadable_forms']) {
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

  if ($type == 'location') {
    $_SESSION['s4_signup_location'] = check_plain($nid);
    drupal_goto('s4/signup/site/' . check_plain(arg(4)));
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
    $forms = field_get_items('node', $site, 'field_site_signup_group');
    foreach($forms as $form) {
      $form = field_collection_item_load($form['value']);
      $programs = field_get_items('field_collection_item', $form, 'field_site_restrict');
      $webform = field_get_items('field_collection_item', $form, 'field_site_form');
      foreach($programs as $k => $program) {
        if($program['tid'] == $_SESSION['s4_signup_program'] || $_SESSION['s4_signup_program'][$program['tid']]) {
          drupal_goto('node/' . $webform[0]['nid']);
          return;
        }
      }
    }
    s4_core_user_signup_completed();
  }

  drupal_set_message(check_plain(t($message)));
  drupal_goto('node/' . $nid);
}

/**
*  System settings landing page
*/
function s4_core_site_settings() {
  drupal_add_css(drupal_get_path('module', 's4_core') . '/css/admin.css');
  drupal_add_css(drupal_get_path('module', 'system') . 'system.admin.css');
  $links = module_invoke_all('s4_site_configuration');
  $result = array();
  foreach ($links as $k => $link) {
    $result[$link['group']][$k] = l($link['title'], $link['href']) . '<div class="description">' . $link['description'];
  }
  foreach ($result as $k => $r) {
    $result[$k] = array('title' => $k,
              'show' => TRUE,
              'content' => theme('item_list', array('items' => $r, 'attributes' => array('class' => array('admin-list')))));
  }
  return theme('admin_page', array('blocks' => $result));
}

/**
*  Implementation of hook_s4_site_configuration
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
    's4_general_workbench' => array(
      'group' => t('General settings'),
      'title' => t('Change approval process'),
      'description' => t('Alter the way that new sites are approved and the possible transitions from Proposed to Published.'),
      'href' => 'admin/config/workbench/moderation',
    ),
  );
}

/**
*  Form to quickly sign up student with a site
*/
function s4_core_create_signup_form($form, &$form_state, $uid, $option = 'new', $existing_node = FALSE, $courses = TRUE) {
  global $user;
  $user = user_load($user->uid);
  $default_program = field_get_items('user', $user, 'field_program_default');

  $account = user_load($uid);
  drupal_set_title(t('Sign up @name', array('@name' => s4_core_get_user_full_name($account))));
  $form = array();
  
  if($existing_node) {
    drupal_set_title(t('Edit placement for @name', array('@name' => s4_core_get_user_full_name($account))));
    $form['existing_node'] = array(
      '#type' => 'hidden',
      '#value' => $existing_node->nid,
    );
  }
  if($_GET['destination']) {
    $form_state['destination'] = check_plain($_GET['destination']);
  }

  $form['user'] = array(
    '#type' => 'hidden',
    '#value' => $account->uid,
  );

  if (module_exists('s4_courses') && $courses) {
    $courses = array();

    $course_list = db_select('field_data_field_course_students', 's')
         ->fields('s', array('entity_id'))
         ->condition('s.bundle', 'course')
         ->condition('s.field_course_students_uid', $account->uid)
         ->distinct()
         ->execute()
         ->fetchCol();


    $form['course'] = array(
      '#type' => 'select',
      '#title' => 'Course',
      '#options' => $courses,
      '#attributes' => array('class' => array('chosen')),
    );

    foreach ($course_list as $course) {
      $course = node_load($course);
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

    
    if(in_array(arg(3), $course_list)) {
      $form['course']['#default_value'] = intval(arg(3));
    }
    if($existing_node) {
      $course = field_get_items('node', $existing_node, 'field_course');
      $form['course']['#default_value'] = $course[0]['nid'];
    }
  }
  
  $sites = array();
  $query = db_select('node', 'n')
       ->fields('n', array('nid', 'title'))
       ->condition('type', 'site')
       ->orderBy('title', 'ASC');
  if($default_program && count($default_program)) {
  	$programs = array();
  	foreach($default_program as $program) {
  		$programs[] = $program['tid'];
  	}
	if(count($programs)) {
	  $query->leftJoin('field_data_field_site_restrict', 'r', 'r.entity_id = n.nid AND r.entity_type = :node', array(':node' => 'node'));
	  $query->condition('r.field_site_restrict_tid', $programs, 'IN');
	}
  }
  
  $results = $query->execute();
  foreach ($results as $result) {
    $sites[$result->nid] = $result->title;
  }
  $form['site'] = array(
    '#type' => 'select',
    '#title' => 'Site',
    '#options' => $sites,
    '#attributes' => array('class' => array('chosen')),
    '#required' => TRUE,
    '#empty_option' => t('-- Select a site --'),
    '#ajax' => array(
      'callback' => 's4_core_site_options_choice',
      'wrapper' => 'site-options',
      'progress' => array(
        'type' => 'throbber',
        'message' => t('Looking up site information'),
      ),
    ),
  );
  if($existing_node && !$form_state['values']['site']) {
    $site = field_get_items('node', $existing_node, 'field_site');
    $form['site']['#default_value'] = $site[0]['nid'];
    $form_state['values']['site'] = $site[0]['nid'];
  }

  $site_staff_options = array();
  $program_options = array();
  if ($form_state['values']['site']) {
    $site_staff = db_select('field_data_field_site', 's')
            ->fields('s', array('entity_id'))
            ->condition('s.bundle', 'coordinator')
            ->condition('s.field_site_nid', $form_state['values']['site'])
            ->execute()
            ->fetchCol();
    foreach ($site_staff as $staff) {
      $staff = node_load($staff);
      $available = field_get_items('node', $staff, 'field_staff_signup_available');
      $active = field_get_items('node', $staff, 'field_site_staff_active');
      if ($available[0]['value'] && $active[0]['value']) {
        $programs = field_get_items('node', $staff, 'field_site_restrict');
        foreach($programs as &$program) {
          $program = taxonomy_term_load($program['tid']);
          $program = $program->name;
        }
        if(!count($programs)) {
          $site_staff_options[$staff->nid] = check_plain($staff->title);
        }
        else {
          $site_staff_options[$staff->nid] = t('@title - @program', array('@title' => $staff->title,
                                       '@program' => (count($programs) > 1) ? implode(', ', $programs) : $programs[0]));
        }
      }
    }
    $site = node_load($form_state['values']['site']);
    $program_options = array();
    foreach(field_get_items('node', $site, 'field_site_restrict') as $program) {
      $program = taxonomy_term_load($program['tid']);
      $program_options[$program->tid] = $program->name;
    }
  }
  $form['site_options'] = array(
    '#type' => 'fieldset',
    '#title' => t('Site options'),
    '#prefix' => '<div id="site-options">',
    '#suffix' => '</div>',
  );
  
  $form['site_options']['site-staff'] = array(
    '#type' => 'radios',
    '#title' => 'Site staff',
    '#options' => $site_staff_options,
  );

  $form['site_options']['program'] = array(
    '#type' => 'radios',
    '#title' => 'Related program',
    '#options' => $program_options,
  );
  if($program_options) {
    $form['site_options']['program']['#required'] = TRUE;
  }

  $form['hours'] = array(
    '#type' => 'textfield',
    '#title' => 'Number of expected hours of services',
    '#size' => 6,
  );
    
  if($existing_node) {
    $site = field_get_items('node', $existing_node, 'field_site');
    if($site[0]['nid'] == $form['site']['#default_value']) {
      $site_staff = field_get_items('node', $existing_node, 'field_coordinator');
      $form['site_options']['site-staff']['#default_value'] = $site_staff[0]['nid'];
      $program = field_get_items('node', $existing_node, 'field_site_restrict');
      $form['site_options']['program']['#default_value'] = $program[0]['tid'];
    }
    $hours = field_get_items('node', $existing_node, 'field_signup_hours');
    $form['hours']['#default_value'] = $hours[0]['value'];

  }

  $form['email_student'] = array(
    '#type' => 'checkbox',
    '#title' => 'Send student email to complete a signup form (if the site has one)',
    '#default_value' => 1,
  );
  
  if(module_exists('s4_courses') && $courses) {
    $form['email_faculty'] = array(
      '#type' => 'checkbox',
      '#title' => t('Also email faculty about signup'),
    );
  }
  
  $form['cc_myself'] = array(
    '#type' => 'checkbox',
    '#title' => t('CC myself a copy of the confirmation email sent to the student'),
  );
  
  if($existing_node) {
    $form['revision_log'] = array(
      '#type' => 'textarea',
      '#title' => t('Leave a note about why this placement was changed.'),
      '#rows' => 3,
    );
  }
  
  $form['actions'] = array(
    '#type' => 'actions',
  );

  $form['actions']['submit'] = array(
    '#type' => 'submit',
    '#value' => ($existing_node) ? t('Update placement') : t('Create placement'),
  );
  
  $form['actions']['cancel'] = array(
    '#type' => 'markup',
    '#markup' => l(t('Cancel'), $_GET['destination']),
  );

  return $form;
}

function s4_core_create_signup_form_validate($form, $form_state) {
  if ($form_state['values']['site'] == 0) {
    form_set_error('site', t('You must select a site to save this signup record.'));
  }
}

function s4_core_create_signup_form_submit($form, $form_state) {
  if($form_state['values']['existing_node']) {
    $node = node_load($form_state['values']['existing_node']);
    $node->field_site[$node->language][0]['nid'] = $form_state['values']['site'];
    $node->field_coordinator[$node->language][0]['nid'] = ($form_state['values']['site-staff']) 
      ? $form_state['values']['site-staff'] 
      : 0;
    $node->field_site_restrict[$node->language][0]['tid'] = $form_state['values']['program'];
    $node->field_signup_hours[$node->language][0]['value'] = $form_state['values']['hours'];
    if($form_state['values']['course']) {
      $node->field_course[$node->course][0]['nid'] = $form_state['values']['course'];
    }
    if($form_state['values']['revision_log']) {
      $node->log = check_plain($form_state['values']['revision_log']);
    }
    $node->revision = TRUE;
    node_save($node);
    drupal_goto(($form_state['values']['destination']) ? $form_state['values']['destination'] : 'node/'. $node->nid);
    return;
  }
  $signup = array('user' => $form_state['values']['user'],
           'site' => $form_state['values']['site'],
           'course' => $form_state['values']['course'],
           'coordinator' => ($form_state['values']['site-staff']) ? $form_state['values']['site-staff'] : 0,
           'hours' => ($form_state['values']['hours']) ? $form_state['values']['hours'] : 0,
           'program' => $form_state['values']['program']
          );
  if ($form_state['values']['email_faculty'] && $form_state['values']['course']) {
    $signup['cc_faculty'] = TRUE;
  }
  if ($form_state['values']['cc_myself']) {
    global $user;
    $signup['cc_user'] = $user->mail;
  }
  $signup = _s4_core_create_signup($form_state['values']['user'], $signup);
  drupal_set_message(t('Created !signup record', array('!signup' => l(t('signup #@number', array('@number' => $signup->nid)), 'node/' . $signup->nid))));
  $site = node_load($form_state['values']['site']);
  $form = field_get_items('node', $site, 'field_site_form');
  if(module_exists('overlay')) {
    overlay_close_dialog();
  }
  else {
    drupal_goto($form_state['values']['destination']);
  }
}

function s4_core_student_signup_complete($signup) {
  $signup = node_load($signup);
  $site = field_get_items('node', $signup, 'field_site');
  $site = node_load($site[0]['nid']);
  $form = field_get_items('node', $site, 'field_site_form');
  $sid = field_get_items('node', $signup, 'field_form_assessment_sid');
  if (!$sid[0]['value']) {
    $_SESSION['s4_core_student_signup_complete'] = $signup->nid;
    drupal_goto('node/' . $form[0]['nid']);
  }
}
