<?php

/**
 * This field handler aggregates operations that can be done on a s4_opportunity
 * under a single field providing a more flexible way to present them in a view
 */
class s4_opportunity_handler_s4_opportunity_operations_field extends views_handler_field {
  function construct() {
    parent::construct();

    $this->additional_fields['s4_opportunity_id'] = 's4_opportunity_id';
  }

  function query() {
    $this->ensure_my_table();
    $this->add_additional_fields();
  }

  function render($values) {

    $links = menu_contextual_links('s4_opportunity', 'admin/content/s4_opportunitys/s4_opportunity', array($this->get_value($values, 's4_opportunity_id')));
    
    if (!empty($links)) {
      return theme('links', array('links' => $links, 'attributes' => array('class' => array('links', 'inline', 'operations'))));
    }
  }
}
