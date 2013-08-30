<?php

/**
*  User progress bar
*/
function s4_core_block_user_progress() {
  global $user;
  if (!s4_core_user_can_signup($user) || $_SESSION['s4_opportunity_create'] || user_access('create signups for other users') || (!$_SESSION['s4_signup_program'] && !$_SESSION['s4_signup_course'])) {
    return NULL;
  }
  drupal_add_css(drupal_get_path('module', 's4_core') . '/css/status.css');
  $status = array();

  if (isset($_SESSION['s4_signup_site'])) {
    $site = node_load($_SESSION['s4_signup_site']);
  }
  if (isset($_SESSION['s4_signup_coordinator'])) {
    $coordinator = node_load($_SESSION['s4_signup_coordinator']);
  }

  if (isset($site)) {
    $title = (strlen($site->title) > 30) ? substr($site->title, 0, 30) .'...' : $site->title;
    $site_selection = l($title, 'node/' . $site->nid);
  }
  if (isset($_SESSION['s4_signup_program']) && !isset($_SESSION['s4_signup_course'])) {
    $program = taxonomy_term_load($_SESSION['s4_signup_program']);
    $status['program'] = array('data'  => 'Program',
            'id'     => 'status-program',
            'class'  => array('done'),
            'selection' => '<div class="selection">' . $program->name .'</div>',
            );
  }
  $status['site'] = array('data'  => 'Site',
            'id'     => 'status-site',
            'class'   => (isset($site)) ? array('done') : array(),
            'selection' => (isset($site_selection)) ? '<div class="selection">' . $site_selection .'</div>': FALSE,
            );

  if (variable_get('s4_core_signup_require_coordinator', 1)) {
    if ($site && module_exists('views')) {
      $site_coordinators = views_get_view_result('site_coordinators', 'block', $site->nid);
    }
    if (isset($coordinator)) {
      $coordinator_selection = '<div class="selection">' .
            l($coordinator->title, 'node/' . $coordinator->nid) . '</div>';
    }
    if (!$site || count($site_coordinators)) {
      $status['coordinator'] = array('data' => 'Site Staff',
              'id'   => 'status-coordinator',
              'class'   => (isset($coordinator)) ? array('done') : array(),
              'selection' => (isset($coordinator_selection))
                         ? $coordinator_selection
                         : FALSE
              );
    }
  }
  if(isset($_SESSION['s4_signup_program'])) {
    $programs = (is_array($_SESSION['s4_signup_program'])) ? array_keys($_SESSION['s4_signup_program']) : array($_SESSION['s4_signup_program']);
    foreach($programs as $program) {
      $term = taxonomy_term_load($program);
      $form = field_get_items('taxonomy_term', $term, 'field_site_form');
      if($form && count($form)) {
        if ($form !== FALSE && count($form)) {
          $status['form'] = array('data' => 'Form',
                  'id'   => 'status-form',
                    'class'   => (isset($form_done)) ? array('done') : array(),
                  'selection' => FALSE
                  );
        }
      }
    }
  }
  if (isset($site)) {
    $form = field_get_items('node', $site, 'field_site_form');
    
    if ($form !== FALSE && count($form)) {
      $status['form'] = array('data' => 'Form',
              'id'   => 'status-form',
                'class'   => (isset($form_done)) ? array('done') : array(),
              'selection' => FALSE
              );
    }
    $form_terms = s4_core_site_has_downloadable_forms($site, TRUE);
    if (count($form_terms) && !$_SESSION['s4_core_viewed_downloadable_forms']) {
      $status['form'] = array('data' => 'Forms',
              'id'   => 'status-form',
                'class'   => (isset($form_done)) ? array('done') : array(),
              'selection' => FALSE
              );
    }
  }

  foreach (module_implements('s4_user_status') as $module) {
    //Iterate over modules and pass status by reference
    $function_name = $module . '_s4_user_status';
    $function_name($status);
  }

  $number = 1;
  foreach ($status as $key => $stat) {
    $status[$key]['data'] = '<div class="arrow-body"><span class="number">' . ($number) . '</span>' . $stat['data'] . '</div>';
    if (isset($stat['href'])) {
      $status[$key]['data'] = l($status[$key]['data'], $stat['href'], array('html' => TRUE));
      $status[$key]['class'][] = 'clickable';
      unset($status[$key]['href']);
    }
    if (isset($stat['selection'])) {
      $status[$key]['data'] .= $stat['selection'];
      unset($status[$key]['selection']);
    }
    $status[$key]['class'][] = 'span' . floor(11 / count($status));
    $status[$key]['data'] .= '<span class="arrow"></span>';
    $number++;
  }
  $finished = ($_GET['finished'] == 'finished')
        ? 'finished'
        :   '';
  $status[] = array('data' => '<div>Done!</div>',
                    'class' => array('span1', 'complete', $finished));
  return array('content' => theme('item_list', array('items' => $status, 'attributes' => array('class' => array('user-signup-status', 'row')))));
}

/**
*  Helper function to retrieve all course site arguments
*/
function _s4_core_get_course_site_arguments($course) {
  $sites = field_get_items('node', $course, 'field_sites');
  if (!$sites || !count($sites)) {
    return 'site-list';
  }

  $site_arguments = array();
  foreach ($sites as $site) {
    $site_arguments[] = $site['nid'];
  }
  return 'site-list/' . implode('+', $site_arguments);
}

/**
*  Note to students about the site list being either restrictive or non-restrictive
*/
function s4_core_block_site_list_course_restriction() {
  if (!isset($_SESSION['s4_signup_course']) || arg(0) != 'site-list') {
    return NULL;
  }
  $course = node_load($_SESSION['s4_signup_course']);
  $restrict = field_get_items('node', $course, 'field_site_restrict_to_list');
  $program = field_get_items('node', $course, 'field_site_restrict');
  $suggested_sites = field_get_items('node', $course, 'field_sites');
  if (!$suggested_sites) {
    return NULL;
  }
  if ($restrict[0]['value']) {

    if (!arg(1)) {
      $output = t('This is a list of all sites; however, you are restricted by @course to sign up for only a few sites. !link',
          array('@course' => $course->title,
                '!link' => l(t('View list of allowed sites.'), _s4_core_get_course_site_arguments($course))));
    }
    else {
      $output = t('You are restricted to selecting from the following sites for @course.',
          array('@course' => $course->title));
    }
  }
  else {
    $output = t('Your faculty for @course suggest the following sites; however, you are allowed to select a !link.',
          array('@course' => $course->title,
              '!link' => l(t('site not included on this list'), 'site-list', array('query' => array('program[]' => $program[0]['tid'])))));
  }
  return array('subject' => '',
         'content' => '<p class="lead">' . $output . '</p>');
}

/**
*  Displays the help message on the top of the login form
*/
function s4_core_block_s4_user_login_message() {
  $directions = variable_get('s4_core_auth_directions', FALSE);
  if (!$directions) {
    return NULL;
  }
  $directions = check_markup($directions['value'], $directions['format']);
  if (!strlen(trim($directions))) {
    return NULL;
  }
  return array('subject' => 'Account help',
         'content' => $directions);
}

/**
*  Generic user login paragraph
*/
function s4_core_block_s4_user_login() {
  global $user;
  $output = array();
  $auth_types = array('students'    => variable_get('s4_core_auth_students', 'user'),
                'staff'             => variable_get('s4_core_auth_staff', 'user'),
                'faculty'           => variable_get('s4_core_auth_faculty', 'user'),
                'community members' => variable_get('s4_core_auth_sites', 'none'));
  $login_destinations = s4_core_login_destinations();

  $login_options = array();
  foreach ($auth_types as $audience => $method) {
    if ($method != 'none') {
      $login_options[$method][] = $audience;
    }
  }
  foreach ($login_options as $option => $audience) {
    if (count($audience) > 2) {
      end($audience);
      $audience[key($audience)] = '&amp; ' . current($audience);
      $join_list = ',';
    }
    $audience = ucfirst(implode(((isset($join_list)) ? $join_list : ' &amp;') . ' ', $audience));
    $login_url = ($user->uid) ? '<front>' : $login_destinations[$option];
    $output[] = t('<strong>!audience:</strong>', array('!audience' => $audience)) . ' ' .
          l(t('Login'), $login_url,
              array('query' => array('destination' => '<front>')));
  }
  return array('subject' => NULL,
         'content' => '<p class="lead">' . implode('<br/>', $output) . '</p>');
}



/**
*  Simple form to let managers jump to a node by it's number
*/
function s4_core_block_jump_to_node() {
  drupal_add_css(drupal_get_path('module', 's4_core') . '/css/jump_form.css');
  return array('subject' => '',
         'content' => drupal_get_form('s4_core_block_jump_form'));
}

/**
*  Subscription links block
*/
function s4_core_block_s4_page_notifications() {
  
}

/**
*  Button block for creating a site
*/
function s4_core_block_s4_add_new_site() {
  global $user;
  if (user_access('moderate site information')) {
    $add_link = l(t('<i class="icon-plus icon-white"></i> Add new site'),
                'node/add/site',
                array('html' => TRUE,
                     'attributes' =>
                    array('class' => array('btn', 'btn-success'))
                )
                );
    if(arg(1) != 'manage') {
      $manage_link = l(t('Manage sites'),
                'site-list/manage',
                array('html' => TRUE,
                     'attributes' =>
                    array('class' => array('btn'))
                )
                );
    }
    else {
      $manage_link = l(t('View public list'),
                'site-list',
                array('html' => TRUE,
                     'attributes' =>
                    array('class' => array('btn'))
                )
                );
    }
    return array('content' => $add_link . ' ' . $manage_link);
  }
}

/**
*  Button block for creating a new site coordinators
*  Note we add the referenced site's nid to the end of the URL
*/
function s4_core_block_s4_add_new_coordinator() {
  if (user_access('create site content')) {
    $node = node_load(check_plain(arg(1)));
    return array('content' => l(t('<i class="icon-plus icon-white"></i> Add new site staff'),
                  'node/add/coordinator/' . $node->nid,
                  array('html' => TRUE,
                      'query' => array('destination' => 'node/' . $node->nid . '/site-staff'),
                       'attributes' =>
                      array('class' => 'btn btn-success')
                  )
                  )
          );
  }
  return NULL;
}

/**
  * 
  */
function s4_core_block_s4_add_forms() {
  $buttons = array();

  if(user_access('create webform content')) {
    $buttons[] = l('<i class="icon-plus icon-white"></i> '. t('Add online form'),
                   'node/add/webform',
                   array('html' => TRUE,
                         'attributes' => array(
                            'class' => array('btn', 'btn-success'),
                          ),
                        )
                   );
  }
  if(user_access('create downloadable_form content')) {
    $buttons[] = l('<i class="icon-plus icon-white"></i> '. t('Add downloadable form'),
                   'node/add/downloadable-form',
                   array('html' => TRUE,
                         'attributes' => array(
                            'class' => array('btn', 'btn-success'),
                          ),
                        )
                   );
  }

  return array('content' => implode(' ', $buttons));
}
/**
*  Generates a link to export a report view
*/
function s4_core_block_s4_report_export_link() {
  $arguments = $_GET;
  $url = $_GET['q'];
  unset($arguments['q']);
  return array('content' => l(t('Export data'), $url . '/export',
                array('query' => $arguments,
                    'attributes' => array('class' => 'button export-link'))));
}

/*
*  Provides a link to the current user's informaiton
*/
function s4_core_block_s4_current_user_link() {
  global $user;
  if (!$user->uid) {
    return NULL;
  }
  $masquerade_switch = '';
  if (isset($_SESSION['masquerading'])) {
    $masquerade_switch = l(t('switch back'), 'masquerade/unswitch', array('attributes' => array('class' => 'switch-link'), 'query' => array('token' => drupal_get_token('masquerade/unswitch'))));
  }
  $user = user_load($user->uid);
  $first_name = field_get_items('user', $user, 'field_first_name');
  $links = array();
  $links[] = l(t('Hello <strong>@username</strong>', array('@username' => $first_name[0]['value'])),'user/' . $user->uid, array('html' => TRUE)) . $masquerade_switch;
  if (user_access('access s4 site settings')) {
  	$links[] = l('<i class="icon-cog"></i> '. t('Site settings'), 's4/settings', array('html' => TRUE));
  }
  $links[] = array('data' => '', 'class' => array('divider-vertical'));
  return array('content' => '<div class="hidden-phone">' . 
    theme('item_list', array('items' => $links, 'attributes' => array('class' => array('nav')))) .
    '</div>');

}

/**
*  Link to the site settings page
*/
function s4_core_block_s4_site_settings() {
  return null;
}

function s4_core_block_s4_signup_error() {
  if(user_access('create signups for other users')) {
    return;
  }
  $return = false;
  global $user;
  if(module_exists('s4_courses')) {
    $view = views_get_view('user_courses');
    $view->set_display('block_2');
    $view->execute();
    if(count($view->result)) {
      return;
    }
    if(s4_courses_user_is_faculty($user)) {
      return;
    }
  }
  $programs = field_get_items('user', $user, 'field_site_restrict');
  if($programs && count($programs)) {
    return;
  }
  $vid = db_select('taxonomy_vocabulary', 'v')
         ->fields('v', array('vid'))
         ->condition('v.machine_name', 'site_restrictions')
         ->execute()
         ->fetchField();
  $output = t('<h2>Cannnot register</h2>');
  $output = '<p class="lead">'. t('<strong>Sorry!</strong> You cannot register for a placement. The following information may help you if you are part of a course or program and think you should be able to register.') .'</p>';
  foreach(taxonomy_get_tree($vid) as $term) {
    $term = taxonomy_term_load($term->tid);
    $message = field_get_items('taxonomy_term', $term, 'field_program_error');
    if($message[0]['value']) {
      $output .= '<h3>' . $term->name . '</h3>';
      $output .= '<p>' . $message[0]['value'] . '</p>';
    }
  }
  return array('content' => $output);
}

function s4_core_block_s4_welcome_message() {
  $message = variable_get('s4_core_welcome_message', array('value' => FALSE));
  if (!$message['value']) {
    $message['value'] = '<p class="lead">This where you can give users more information about your program. Let us know in a few sentences what you do, and what the community gets from your program.</p><p>Select <strong>Site Settings</strong> then <strong> General settings</strong> to change this message.</p>';
  }
  return array('content' => '<div class="hero-unit">' . $message['value'] . '</div>');
}

/**
 * Link from the downloadable form page to continue
 */
function s4_core_block_s4_signup_forms() {
  if (!$_SESSION['s4_signup_site']) {
    return;
  }
  return array('content' => 
                            l('<i class="icon-arrow-right icon-white"></i> ' . t('Continue'), 's4/signup/site/' . $_SESSION['s4_signup_site'],
             array('html' => TRUE,
             'attributes' => array('class' => array('btn', 'btn-primary', 'btn-large', 'btn-block')))));

}
