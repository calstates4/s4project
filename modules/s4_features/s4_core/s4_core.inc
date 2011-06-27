<?php

class Notifications_Document_Expiration extends Notifications_Subscription_Simple {  
  /**
   * Set all the fields we can from node
   */
  public function set_node($node) {
    $node_mapping = array(
      'node:nid' => $node->nid,
      'node:type' => $node->type,
      'node:uid' => $node->uid,
    );
    foreach ($node_mapping as $index => $value) {
      if ($field = $this->get_field($index)) {
        $field->set_value($value);
      }
    }
    return $this;
  }
  /**
   * Get name
   */
  function get_name() {
    if (isset($this->name)) {
      return $this->name;
    }
    else {
      $node = node_load($this->get_field('node:nid')->value);
      return t('Document @document expires', array('@document' => $node->title));
    }
  }  
}

class Notification_Document_Expires_Event extends Notifications_Event {
  public function set_object($object) {
    if ($object->type == 'node') {
      $this->oid = $object->get_value();
    }
    return parent::set_object($object);
  }
  /**
   * Get node object
   */
  public function get_node() {
    return node_load($this->get_object('node')->value);
  }
  /**
   * Trigger node event
   */
  public function trigger() {
    $node = $this->get_node();
    if ($result = parent::trigger()) {
      watchdog('action', 'Triggered notifications for document expiration on %title..', 
        array('%title' => $node->title));
    }
    return $result;
  }
}

class Notifications_Document extends Notifications_Drupal_Object {
  public $type = 'document';
    
  public function get_title() {
    return t('Document');
  }
  
  /**
   * Load related object or data
   */
  public static function object_load($value) {  
    return node_type_get_type($value);
  }
  /**
   * Get object name, unfiltered string
   */
  public static function object_name($object) {
    return $object->name;
  }
  /**
   * Get object key
   */
  public static function object_value($object) {
    return $object->type;
  }
}

class Notification_Document_Expires_Template extends Notifications_Node_Event_Template {
  public function get_title() {
    return t('Template for document expiration');
  }  
  public function digest_fields() {
    return array('node:nid');
  }
  public function digest_line($field, $options = array()) {
    switch ($field) {
      case 'node:nid':
        return t('The file [node:name] is about to expire.', array(), $options);
    }    
  } 
  function default_text($type, $options) {
    dvm($type);
    switch ($type) {
      case 'subject':
        return array(
          '#tokens' => TRUE,
          '#markup' => t('File [node:title] is about to expire', array(), $options)
        );
      case 'content':
        return array(
          '#type' => 'messaging_template_text', '#tokens' => TRUE,
          'header' => t('The file [node:title] is about to expire', array(), $options),
          'teaser' => '[node:summary]',
          'more' => array(
            '#type' => 'messaging_link',
            '#text' => t('View the file', array(), $options),
            '#url' => '[node:url]',        
          ),
        );
      case 'digest':
        return array(
          '#tokens' => TRUE,
          'title' => '[node:title] is about to expire',
          'more' => t('view the file [node:url]', array(), $options),
        );
      default:
        return parent::default_text($type, $options);
    }
  } 
}