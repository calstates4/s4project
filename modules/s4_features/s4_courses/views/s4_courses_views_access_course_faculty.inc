<?php

/**
 * Access plugin that grants access if the current course contains the user as a faculty.
 */
class s4_courses_views_access_course_faculty extends views_plugin_access {
  function access($account) {
    return s4_courses_views_check_faculty_access($this->view,  $account);
  }

  function get_access_callback() {
    return array('s4_courses_views_check_faculty_access', array($this->view);
  }

  function summary_title() {
    return t('User is faculty');
  }


  function option_definition() {
    $options = parent::option_definition();
    return $options;
  }

  function options_form(&$form, &$form_state) {

  }

  function options_validate(&$form, &$form_state) {
    if (!array_filter($form_state['values']['access_options']['role'])) {
      form_error($form['role'], t('You must select at least one role if type is "by role"'));
    }
  }

  function options_submit(&$form, &$form_state) {
    // I hate checkboxes.
    $form_state['values']['access_options']['role'] = array_filter($form_state['values']['access_options']['role']);
    $form_state['values']['access_options']['node_type'] = $form_state['values']['access_options']['node_type'];
  }
}
