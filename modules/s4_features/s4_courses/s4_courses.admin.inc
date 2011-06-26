<?php

function s4_courses_admin_form() {
  $form = array();
  
  $values = variable_get('s4_courses_term_codes', array());
  foreach($values as $key => $value) {
    $term_values[] = $key .'|'. $value;
  }
  
  $form['s4_courses_term_codes'] = array(
    '#type' => 'textarea',
    '#title' => 'Term codes',
    '#description' => 'Enter the numerical types of terms available on your campus, one per line, with the number, followed by a pipe "|" and then the name of the term (i.e. "2|Spring")',
    '#default_value' => implode("\n", $term_values),
  );
  
  $form['s4_courses_limit_subject'] = array(
    '#type' => 'textarea',
    '#title' => 'Limit S4 to these subject codes',
    '#description' => 'If your import tool is not filtering out courses for S4, you can list all subject codes (like the "ENG" in "ENG 101") that should be allowed to be merged into the system.',
    '#default_value' => implode("\n", variable_get('s4_courses_limit_subject', array())),
  );
  
  $form['s4_courses_update_frequency'] = array(
    '#type' => 'select',
    '#title' => 'Update freqency for large requests',
    '#description' => 'Requests for terms and course information can take a long time, and change infrequently. Select the frequency which which this site should check for updates.',
    '#options' => array((30 * 60) => '30 minutes',
              (1 * 60 * 60) => '1 hour',
              (2 * 60 * 60) => '2 hours',
              (6 * 60 * 60) => '6 hours',
              (12 * 60 * 60) => '12 hours',
              (24 * 60 * 60) => '1 day',
    
    ),
    '#default_value' => variable_get('s4_courses_update_frequency', (2 * 60 * 60)),
  );
  
  $form['submit'] = array(
    '#type' => 'submit',
    '#value' => 'Save configuration',
  );
  
  return $form;
}

function s4_courses_admin_form_submit($form, $form_state) {
  foreach(explode("\n", $form_state['input']['s4_courses_term_codes']) as $code) {
    $code = explode('|', trim($code));
    if($code[0] == $requested_code) {
      return $code[1];
    }
    $term_codes[$code[0]] = $code[1];
  }
  variable_set('s4_courses_term_codes', $term_codes);
  variable_set('s4_courses_limit_subject', explode("\n", $form_state['input']['s4_courses_limit_subject']));
}