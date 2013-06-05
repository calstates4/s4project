<?php

/**
 * @file
 * Contains a Views field handler to take care of displaying links to entities
 * as fields.
 */

class s4_opportunity_handler_type extends views_handler_field {
  function construct() {
    parent::construct();

    $this->additional_fields['s4_opportunity_id'] = 's4_opportunity_id';
    $this->additional_fields['type'] = 'type';
  }

  function option_definition() {
    $options = parent::option_definition();
    return $options;
  }

  function options_form(&$form, &$form_state) {
    parent::options_form($form, $form_state);

  }

  function query() {
    $this->ensure_my_table();
    $this->add_additional_fields();
  }

  function render($values) {
    $s4_opportunity_id = $values->{$this->aliases['s4_opportunity_id']};
    $opportunity = s4_opportunity_load($s4_opportunity_id);
    $type = s4_opportunity_type_load($opportunity->type);
    return check_plain($type->label);
  }
}
