<?php

/**
 * Access plugin that provides role-based access control.
 */
class s4_core_views_access_node_type_permission extends views_plugin_access {
  function access($account) {
    return s4_core_views_check_node_type_permission($this->options['permission'], $this->options['node_type'], $this->view,  $account);
  }

  function get_access_callback() {
    return array('s4_core_views_check_node_type_permission', array($this->options['permission'], $this->options['node_type'], $this->view));
  }

  function summary_title() {
    if(!$this->options['permission']) {
      return t('No permission set');
    }
    return $this->options['permission'];
  }


  function option_definition() {
    $options = parent::option_definition();
    $options['permission'] = array('default' => '');
    $options['node_type'] = array('default' => '');
    return $options;
  }

  function options_form(&$form, &$form_state) {
    $perms = array();
    $module_info = system_get_info('module');

    // Get list of permissions
    foreach (module_implements('permission') as $module) {
      $permissions = module_invoke($module, 'permission');
      foreach ($permissions as $name => $perm) {
        $perms[$module_info[$module]['name']][$name] = strip_tags($perm['title']);
      }
    }

    asort($perms);
    
    $form['permission'] = array(
      '#type' => 'select',
      '#title' => t('Permission'),
      '#default_value' => $this->options['permission'],
      '#options' => $perms,
      '#description' => t('Only the checked roles will be able to access this display. Note that users with "access all views" can see any view, regardless of role.'),
    );
    
    $form['node_type'] = array(
      '#type' => 'textfield',
      '#title' => t('Node type'),
      '#default_value' => $this->options['node_type'],
      '#description' => 'Enter the machine name of the node type this should be active on',
    );
  }

  function options_validate(&$form, &$form_state) {

  }

  function options_submit(&$form, &$form_state) {
    
  }
}
