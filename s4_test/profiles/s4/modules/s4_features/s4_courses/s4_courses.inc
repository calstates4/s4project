<?php

class Notifications_Course_Subscription extends Notifications_Subscription_Simple {  
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
      return t('Signups in @course', array('@course' => $node->title));
    }
  }  
}

class Notifications_Course_Signup_Post_Event extends Notifications_Event {
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
      watchdog('action', 'Triggered notifications for  @type %title..', 
      	array('%title' => $node->title));
    }
    return $result;
  }
}

class Notifications_Signup extends Notifications_Drupal_Object {
  public $type = 'signup';
    
  public function get_title() {
    return t('Course signup');
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