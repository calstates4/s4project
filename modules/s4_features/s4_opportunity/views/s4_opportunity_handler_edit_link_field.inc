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

    $text = !empty($this->options['text']) ? $this->options['text'] : t('edit');
    $s4_opportunity_id = $values->s4_opportunity_id;
    
    return l($text, 'opportunity/' . $s4_opportunity_id . '/edit', array('attributes' => array('class' => array('btn btn-small btn-info'))));
  }

  function query() {

  }
}
