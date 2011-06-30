<?php

/**
*  User progress bar
*/
function s4_core_block_user_progress() {
  global $user;
  if (!s4_core_user_can_signup($user)) {
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
      $status['coordinator'] = array('data' => 'Coordinator',
              'id'   => 'status-coordinator',
                'class'   => (isset($coordinator)) ? array('done') : array(),
              'href' => 'sites/' . $site->nid . '/coordinators',
              'selection' => (isset($coordinator_selection))
                         ? $coordinator_selection
                         : FALSE
              );
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
  return array('subject' => 'Follow these steps to sign up for service:',
         'content' => theme('item_list', array('items' => $status, 'attributes' => array('class' => 'user-signup-status'))) . '<div class="clearfix"></div>');
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
*  The "select this site" button
*/

function s4_core_block_user_site_signup() {
  global $user;
  $node = menu_get_object();
  if (!$node ||   $node->type != 'site' || !s4_core_user_can_signup($user)) {
    return NULL;
  }
  
  
  if (!s4_core_signup_access($node, $user)) {
    $output = '<div class="signup denied"><div class="icon"></div>You can\'t sign up for this site.</div>';
  }
  else {
    $output = '<div class="signup"><div class="icon"></div>' . 
          l(t('Signup for this site'), 's4/signup/site/' . $node->nid,
           array('attributes' => array('data-target' => 'status-site'))) . '</div>';
  }
  return array('subject' => '',
         'content' => $output);
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
  if(!$directions) {
  	return null;
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
  $output = array();
  $auth_types = array('students'       => variable_get('s4_core_auth_students', 'user'),
            'staff'          => variable_get('s4_core_auth_staff', 'user'),
            'faculty'        => variable_get('s4_core_auth_faculty', 'user'),
            'site members'  => variable_get('s4_core_auth_sites', 'none'));
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
    $output[] = t('<strong>!audience:</strong>', array('!audience' => $audience)) . ' ' .
          l(t('Login'), $login_destinations[$option], 
              array('query' => array('destination' => 'dashboard')));
  }
  return array('subject' => NULL,
         'content' => '<p class="intro">' . implode('<br/>', $output) . '</p>');
}



/**
*  Simple form to let managers jump to a node by it's number
*/
function s4_core_block_jump_to_node() {
  drupal_add_js(drupal_get_path('module', 's4_core') . '/css/jump_form.css');
  return array('subject' => '',
         'content' => drupal_get_form('s4_core_block_jump_form'));
}

/**
*  Block callback for rendering the webform submission
*  associated with the signup node.
*/
function s4_core_block_s4_signup_webform_signup() {
  return _s4_core_block_webform('field_form_signup_sid');
}

/**
*  Subscription links block
*/
function s4_core_block_s4_page_notifications() {
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
*  Block helper for rendering a given webform submission
*/
function _s4_core_block_webform($field) {
  $node = menu_get_object();
  $sid = field_get_items('node', $node, $field);
  $site = field_get_items('node', $node, 'field_site');
  $site = node_load($site[0]['nid']);
  $form = field_get_items('node', $site, 'field_site_form');
  $form = node_load($form[0]['nid']);
  $output = '';
  if (count($form)) {
    module_load_include('inc', 'webform', 'includes/webform.submissions');
    $submission = webform_get_submission($form->nid, $sid[0]['value']);
      if (!$submission) {
        return NULL;
      }
      foreach ($form->webform['components'] as $k => $component) {
        $output .= '<p><span class="form-label">' . $component['name'] . ':</span>';
        $output .= '<span class="form-value">' . implode("\n", $submission->data[$k]['value']) . '</span></p>';
      }
      
          return array('subject' => 'Signup form',
                'content' => $output);
  }
}

/**
*  Button block for creating a site
*/
function s4_core_block_s4_add_new_site() {
  if (user_access('create site content')) {
    return array('content' => l(t('<span class="add"></span>Add new site'), 
                  'node/add/site', 
                  array('html' => TRUE,
                       'attributes' => 
                      array('class' => 'button add')
                  )
                  )
          );
  }
  return NULL;
}

/**
*  Button block for creating a new site coordinators
*  Note we add the referenced site's nid to the end of the URL
*/
function s4_core_block_s4_add_new_coordinator() {
  if (user_access('create site content')) {
    $node = menu_get_object();
    return array('content' => l('<span class="add"></span>' . t('Add new coordinator'), 
                  'node/add/coordinator/' . $node->nid, 
                  array('html' => TRUE,
                      'query' => array('destination' => 'node/' . $node->nid),
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
    $link = l(t('<span class="hover">Unsubscribe to file expiration notifications</span><span class="nohover">Subscribed to file expiration notifications</span>'),
          'notifications/unsubscribe/' . $sid,
          array('html' => TRUE,
              'attributes' => array('class' => 'subscription-button subscribed'),
              'query' => array('destination' => $_GET['q'])));
  }
  else {
    $link = l(t('Subscribe to file expiration notifications'),
          'notifications/subscribe/document_expiration',
          array('html' => TRUE,
              'attributes' => array('class' => 'subscription-button not-subscribed'),
              'query' => array('destination' => $_GET['q'])));
  }
  return array('title' => '',
         'content' => $link);
}