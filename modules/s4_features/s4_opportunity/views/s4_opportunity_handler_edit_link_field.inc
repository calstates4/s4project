<?php

/**
 * @file
 * Contains a Views field handler to take care of displaying edit links
 * as fields
 */


class s4_opportunity_handler_edit_link_field extends views_handler_field {
  function construct() {
    parent::construct();
    $this->additional_fields['type'] = 'type';
  }


  function render($values) {
    $type = $values->{$this->aliases['type']};
    
    //Creating a dummy s4_opportunity to check access against
    $dummy_s4_opportunity = (object) array('type' => $type);
    if (!s4_opportunity_access('edit', $dummy_s4_opportunity)) {
      return;
    }
    
    $text = !empty($this->options['text']) ? $this->options['text'] : t('edit');
    $s4_opportunity_id = $values->{$this->aliases['s4_opportunity_id']};
    
    return l($text, 'opportunity/' . $s4_opportunity_id . '/edit');
  }
}
