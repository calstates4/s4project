<?php

/**
 * Access plugin that provides (reversed) role-based access control.
 */
class s4_core_views_access_role_reverse extends views_plugin_access {
  function access($account) {
    return s4_core_views_check_reverse_view_roles(array_filter($this->options['role']), $this->options['node_type'], $this->view,  $account);
  }

  function get_access_callback() {
    return array('s4_core_views_check_reverse_view_roles', array(array_filter($this->options['role']), $this->options['node_type'], $this->view));
  }

  function summary_title() {
    $count = count($this->options['role']);
    if ($count < 1) {
      return t('No role(s) selected');
    }
    elseif ($count > 1) {
      return t('Multiple roles');
    }
    else {
      $rids = views_ui_get_roles();
      $rid = reset($this->options['role']);
      return check_plain($rids[$rid]);
    }
  }


  function option_definition() {
    $options = parent::option_definition();
    $options['role'] = array('default' => array());
    return $options;
  }

  function options_form(&$form, &$form_state) {
    $form['role'] = array(
      '#type' => 'checkboxes',
      '#title' => t('Reverse roles'),
      '#default_value' => $this->options['role'],
      '#options' => array_map('check_plain', views_ui_get_roles()),
      '#description' => t('Only the checked roles will NOT be able to access this display. Note that users with "access all views" can see any view, regardless of role.'),
    );

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
