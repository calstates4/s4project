<?php

/**
*  User progress bar
*/
function s4_core_block_user_progress() {
  global $user;
  if (!s4_core_user_can_signup($user) || user_access('create signups for other users')) {
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
    $site_selection = '<div class="selection">' . l($site->title, 'node/' . $site->nid) . '</div>';
  }
  if (isset($_SESSION['s4_signup_program']) && !isset($_SESSION['s4_signup_course'])) {
    $program = taxonomy_term_load($_SESSION['s4_signup_program']);
    $status['program'] = array('data'  => 'Program',
            'id'     => 'status-program',
            'class'  => array('done'),
            'href'  => null,
            'selection' => '<div class="selection">' . $program->name .'</div>',
            );
  }
  $status['site'] = array('data'  => 'Site',
            'id'     => 'status-site',
            'class'   => (isset($site)) ? array('done') : array(),
            'href'  => (isset($course))
                    ? _s4_core_get_course_site_arguments($course)
                    : 'site-list',
            'selection' => (isset($site_selection)) ? $site_selection : FALSE,
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
      if($site) {
        $status['coordinator']['href'] = 'sites/' . $site->nid . '/coordinators';
      }
    }
  }
  if (isset($site)) {
    $form = field_get_items('node', $site, 'field_site_form');
    if ($form !== FALSE && count($form)) {
      $status['form'] = array('data' => 'Form',
              'id'   => 'status-form',
                'class'   => (isset($form_done)) ? array('done') : array(),
              'href' => 'node/' . $form[0]['nid'],
              'selection' => FALSE
              );
    }
    $form_terms = s4_core_site_has_downloadable_forms($site);
    if (count($form_terms) && !$_SESSION['s4_core_viewed_downloadable_forms']) {
      $status['form'] = array('data' => 'Forms',
              'id'   => 'status-form',
                'class'   => (isset($form_done)) ? array('done') : array(),
              'href' => 'forms/download/' . implode('+', $form_terms),
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
    $status[$key]['data'] = '<div><span class="number">' . ($number) . '</span>' . $stat['data'] . '</div>';
    if (isset($stat['href'])) {
      $status[$key]['data'] = l($status[$key]['data'], $stat['href'], array('html' => TRUE));
      $status[$key]['class'][] = 'clickable';
      unset($status[$key]['href']);
    }
    if (isset($stat['selection'])) {
      $status[$key]['data'] .= $stat['selection'];
      unset($status[$key]['selection']);
    }
    $status[$key]['class'][] = 'items-' . count($status);
    $number++;
  }
  $finished = ($_GET['finished'] == 'finished')
        ? 'finished'
        :   '';
  $status[] = array('data' => '<div>Done!</div>',
            'class' => array('complete', $finished));
  return array('content' => theme('item_list', array('items' => $status, 'attributes' => array('class' => 'user-signup-status'))) . '<div class="clearfix"></div>');
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
              '!link' => l(t('site not included on this list'), 'site-list')));
  }
  return array('subject' => '',
         'content' => '<p class="intro">' . $output . '</p>');
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
  $auth_types = array('students'        => variable_get('s4_core_auth_students', 'user'),
                'staff'             => variable_get('s4_core_auth_staff', 'user'),
                'faculty'           => variable_get('s4_core_auth_faculty', 'user'),
                'community members' => variable_get('s4_core_auth_sites', 'none'));
  $login_destinations = array('user' => 'user',
                              'ldap' => 'user',
                              'cas'  => 'cas/login');

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
         'content' => '<p class="intro">' . implode('<br/>', $output) . '</p>');
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
  global $user;
  if (!$user->uid) {
    return NULL;
  }
  $list = notifications_subscription_list('page subscriptions')
      ->filter_option('subscriptions_block');
  $links = array();
  foreach ($list->get_instances() as $notification) {
    $link = $notification->element_link();
    if ($notification->is_stored()) {
      $link['#title'] = t('<span class="hover">Unsubscribe</span><span class="nohover">Subscribed</span>');
      $link['#options']['attributes']['class'] = 'subscribed';
    }
    else {
      $link['#title'] = t('Subscribe to changes');
      $link['#options']['attributes']['class'] = 'not-subscribed';
    }
    $link['#options']['attributes']['class'] .= ' subscription-button';
    $links[] = drupal_render($link);
  }
  if (count($links)) {
    drupal_add_css(drupal_get_path('module', 's4_core') . '/css/subscriptions.css');
    return array('subject' => 'Subscriptions',
          'content' => theme('item_list', array('items' => $links))
         );
  }
  return NULL;
}

/**
*  Button block for creating a site
*/
function s4_core_block_s4_add_new_site() {
  global $user;
  if (user_access('moderate site information') && !s4_core_user_can_signup($user)) {
    $add_link = l(t('<span class="add"></span>Add new site'),
                'node/add/site',
                array('html' => TRUE,
                     'attributes' =>
                    array('class' => 'button add')
                )
                );
    $manage_link = l(t('Manage sites'),
                'site-list/manage',
                array('html' => TRUE,
                     'attributes' =>
                    array('class' => 'button add')
                )
                );
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
    return array('content' => l(t('<span class="add"></span>Add new site staff'),
                  'node/add/coordinator/' . $node->nid,
                  array('html' => TRUE,
                      'query' => array('destination' => 'node/' . $node->nid . '/site-staff'),
                       'attributes' =>
                      array('class' => 'button add')
                  )
                  )
          );
  }
  return NULL;
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

/**
*  Link to subscribe to file expiration notices
*/
function s4_core_block_s4_subscribe_file_expiration() {
  if (!user_access('get file expiration notifications')) {
    return NULL;
  }
  drupal_add_css(drupal_get_path('module', 's4_core') . '/css/subscriptions.css');
  global $user;
  $query = db_select('notifications_subscription', 'n');
  $query->condition('n.uid', $user->uid)
      ->condition('n.type', 'document_expiration')
      ->fields('n', array('sid'));
  $result = $query->execute();
  $sid = $result->fetchField();
  if ($sid) {
    $link = l(t('<span class="hover">Cancel email subscription</span><span class="nohover">Email me when a form will expire</span>'),
          'notifications/unsubscribe/' . $sid,
          array('html' => TRUE,
              'attributes' => array('class' => 'subscription-button subscribed'),
              'query' => array('destination' => $_GET['q'])));
  }
  else {
    $link = l(t('Email me when a form expires'),
          'notifications/subscribe/document_expiration',
          array('html' => TRUE,
              'attributes' => array('class' => 'subscription-button not-subscribed'),
              'query' => array('destination' => $_GET['q'])));
  }
  return array('title' => '',
         'content' => $link);
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
  return array('content' => l(t('Hello <strong>@username</strong>', array('@username' => $first_name[0]['value'])), 'user/' . $user->uid, array('html' => TRUE)) . $masquerade_switch);

}

/**
*  Link to the site settings page
*/
function s4_core_block_s4_site_settings() {
  if (!user_access('access s4 site settings')) {
    return NULL;
  }
  return array('content' => l(t('Site settings'), 's4/settings', array('attributes' => array('class' => array('s4-site-settings')))));
}

function s4_core_block_s4_signup_error() {
  if(user_access('create signups for other users')) {
    return;
  }
  $return = false;
  if(module_exists('s4_courses')) {
    $view = views_get_view('user_courses');
    $view->set_display('block_2');
    $view->execute();
    if(count($view->result)) {
      return;
    }
  }
  global $user;
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
  $output = '<p class="intro">'. t('You cannot register for a placement. The following information may help you if you are part of a course or program and think you should be able to register.') .'</p>';
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
    $message['value'] = '<p class="intro">This where you can give users more information about your program. Let us know in a few sentences what you do, and what the community gets from your program.</p><p>Select <strong>Site Settings</strong> then <strong> General settings</strong> to change this message.</p>';
  }
  return array('content' => $message['value']);
}

/**
 * Link from the downloadable form page to continue
 */
function s4_core_block_s4_signup_forms() {
  if (!$_SESSION['s4_signup_site']) {
    return;
  }
  return array('content' => '<div class="signup"><div class="icon"></div>' .
                            l(t('Continue signing up'), 's4/signup/site/' . $_SESSION['s4_signup_site'])
                            . '</div>');
}

/**
 * Form to edit existing placement.
 */
function s4_core_block_s4_signup_edit() {
  $node = menu_get_object();
  if(!node_access('update', $node)) {
    return;
  }
  $user = field_get_items('node', $node, 'field_user');
  return array('content' => l(t('Edit this placement'), 'signup/create/'. $user[0]['uid'] .'/edit/'. $node->nid));
}