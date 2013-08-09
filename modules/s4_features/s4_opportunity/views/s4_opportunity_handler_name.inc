<?php

/**
 * @file
 * Contains a Views field handler to take care of displaying links to entities
 * as fields.
 */

class s4_opportunity_handler_name extends views_handler_field {
  function construct() {
    parent::construct();

    $this->additional_fields['s4_opportunity_id'] = 's4_opportunity_id';
    $this->additional_fields['type'] = 'type';
  }

  function option_definition() {
    $options = parent::option_definition();

    $options['link'] = array('default' => 0, 'translatable' => TRUE);

    return $options;
  }

  function options_form(&$form, &$form_state) {
    parent::options_form($form, $form_state);

    $form['link'] = array(
      '#type' => 'checkbox',
      '#title' => t('Link to opportunity'),
      '#default_value' => $this->options['link'],
    );
  }

  function query() {
    $this->ensure_my_table();
    $this->add_additional_fields();
  }

  function render($values) {
    $s4_opportunity_id = $values->{$this->aliases['s4_opportunity_id']};
    $opportunity = s4_opportunity_load($s4_opportunity_id);
    if($this->options['link']) {
      return l($opportunity->name, 'opportunity/' . $s4_opportunity_id);
    }
    return $opportunity->name;
  }
}
