<?php

/**
 * @file
 * Contains a Views field handler to take care of displaying deletes links
 * as fields
 */


class s4_opportunity_handler_delete_link_field extends views_handler_field {
  function construct() {
    parent::construct();
    $this->additional_fields['type'] = 'type';
  }


  function render($values) {

    $text = !empty($this->options['text']) ? $this->options['text'] : t('delete');
    $s4_opportunity_id = $values->s4_opportunity_id;
    
    return l($text, 'admin/content/s4_opportunitys/s4_opportunity/' . $s4_opportunity_id . '/delete', array('attributes' => array('class' => array('btn btn-small btn-danger'))));
  }

  function query() {

  }
}
