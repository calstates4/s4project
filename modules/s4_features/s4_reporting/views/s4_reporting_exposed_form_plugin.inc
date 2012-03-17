<?php
/**
 * @file
 * Provides an Better Exposed Filters exposed form plugin for View 3.x.
 */
class s4_reporting_exposed_form_plugin extends views_plugin_exposed_form_basic {

  function summary_title() {
    return t('S4 Reporting style');
  }

  function option_definition() {
    $options = parent::option_definition();
    
    $options['s4_reporting'] = array('default' => array());
    
	return $options;
  }

  function options_form(&$form, &$form_state) {
    parent::options_form($form, $form_state);
    $groups = explode("\n", $this->options['s4_reporting']['groups']);
    array_walk($groups, 'trim');
    foreach ($this->display->handler->get_handlers('filter') as $label => $filter) {
      if (!$filter->options['exposed']) {
        continue;
      }
      $form['s4_reporting']['group-'. $label] = array(
      	'#type' => 'select',
      	'#title' => 'Group for '. $label,
      	'#options' => $groups,
      	'#default_value' => $this->options['s4_reporting']['group-'. $label]
      );
    }
    $form['s4_reporting']['groups'] = array(
    	'#type' => 'textarea',
    	'#title' => 'Groups',
    	'#description' => 'Enter a list of groups to include in this form',
    	'#default_value' => $this->options['s4_reporting']['groups'],
    );
  }

  /*
   * Tweak the exposed filter form to show Better Exposed Filter options.
   */
  function exposed_form_alter(&$form, &$form_state) {
	
	drupal_add_css(drupal_get_path('module', 's4_reporting') .'/css/s4_reporting.views.css');
    $form['#theme'] = array();
    $form['filters'] = array(
		'#type' => 'vertical_tabs',
		'#weight' => -10,
	);
	$groups = explode("\n", $this->options['s4_reporting']['groups']);
    array_walk($groups, 'trim');
    foreach($groups as $key => $group) {
		$form['filters'][$key] = array(
			'#type' => 'fieldset',
			'#title' => $group,
		);
	}
	$fields = $this->options['s4_reporting'];
	unset($fields['groups']);
	foreach($fields as $field => $group) {
		$field = str_replace('group-', '', $field);
		if (is_array($form[$field])) {
			$form['filters'][$group][$field] = $form[$field] + 
				array('#title' => $form['#info']['filter-'. $field]['label']);
			unset($form[$field]);
		}
	}
  } 
}