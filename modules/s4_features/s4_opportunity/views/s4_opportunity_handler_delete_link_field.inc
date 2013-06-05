<?php

/**
 * @file
 * Contains a Views field handler to take care of displaying deletes links
 * as fields
 */


class s4_opportunity_handler_delete_link_field extends s4_opportunity_handler_link_field {
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
    
    $text = !empty($this->options['text']) ? $this->options['text'] : t('delete');
    $s4_opportunity_id = $values->{$this->aliases['s4_opportunity_id']};
    
    return l($text, 'admin/content/s4_opportunitys/s4_opportunity/' . $s4_opportunity_id . '/delete');
  }
}
