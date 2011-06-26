<?php

function _s4_core_check_array($values, $validate, $debug = false) {
  foreach($validate as $key => $rule) {
    if(!isset($values[$key])) {
      if($debug) {
        drupal_set_message(t('There must be a value for %key', 
                   array('%key' => $key)));
      }
      return false;
    }
    if($rule == 'date' && !is_string($values[$key])) {
      if($debug) {
        drupal_set_message(t('The value %value for %key is not a proper date.', 
                   array('%key' => $key,
                        '%value' => $values[$key])));
      }
      return false;
    }
    if($rule == 'number' && !is_numeric($values[$key])) {
      if($debug) {
        drupal_set_message(t('The value %value for %key is not a proper number.', 
                   array('%key' => $key,
                        '%value' => $values[$key])));
      }
      return false;
    }
    if($rule == 'array' && !is_array($values[$key])) {
      if($debug) {
        drupal_set_message(t('The value %value for %key is not a proper array.', 
                   array('%key' => $key,
                        '%value' => $values[$key])));
      }
      return false;
    }
    if($rule == 'string' && !is_string($values[$key])) {
      if($debug) {
        drupal_set_message(t('The value %value for %key is not a proper string.', 
                   array('%key' => $key,
                        '%value' => $values[$key])));
      }
      return false;
    }
  }
  return true;
}

function _s4_core_check_s4_get_term($results, $debug = false) {
  $required_values = array('term_title' => 'string',
               'term_code'  => 'string',
               'start_date' => 'date',
               'end_date'   => 'date');
  foreach($results as $result) {
    if(!_s4_core_check_array($result, $required_values, $debug)) {
      return false;
    }
  }
  return true;
}

function _s4_core_check_s4_get_courses($results, $debug = false, $check_users = true) {
  $required_values = array('subject' => 'string',
               'catalog_number' => 'string',
               'section' => 'number',
               'title' => 'string',
               'status' => 'string',
            );
  foreach($results as $result) {
    if(!_s4_core_check_array($result, $required_values, $debug)) {
      return false;
    }
    if($check_users) {
      foreach($result['faculty'] as $user) {
        if(!_s4_core_check_s4_get_user($user, $debug)) {
          return false;
        }
      }
      foreach($result['students'] as $user) {
        if(!_s4_core_check_s4_get_user($user, $debug)) {
          return false;
        }
      }
    }
  }
  return true;
}

function _s4_core_check_s4_get_user($result, $debug = false) {
  $required_values = array('login_id'        => 'string', 
               'user_id'          => 'string',
               'email'          => 'string',
               'first_name'        => 'string',
               'last_name'        => 'string', 
               'restrictions'      => 'array', 
               'constant_registration' => 'number',
            );
  if(!_s4_core_check_array($result, $required_values, $debug)) {
    return false;
  }
  return true;
}

function _s4_core_check_s4_get_user_enrollment($result, $debug) {
  return _s4_core_check_s4_get_courses($result, $debug, false);
}

function _s4_core_check_s4_get_faculty_courses($result) {
  return _s4_core_check_s4_get_courses($result, $debug, false);
}



