<?php

/**
 * @file
 * Class definition of CRMFeedsCourseEnrollmentProcessor.
 */
 
/**
 * Creates relations from feed items.
 */
class S4CourseFaculyProcessor extends FeedsProcessor {
  /**
   * Define entity type.
   */
  public function entityType() {
    return 'node_reference';
  }

  /**
   * Implements parent::entityInfo().
   */
  protected function entityInfo() {
    $info = parent::entityInfo();
    $info['label plural'] = t('Faculty assignments');
    return $info;
  }

  /**
   * Creates a new enrollment relation in memory and returns it.
   */
  public function newReference(FeedsSource $source, $item) {
    $course = node_load($item['course']);
    $existing = field_get_items('node', $course, 'field_course_faculty');
    if($existing && is_array($existing)) {
      foreach ($existing as $existing_faculty) {
        if ($existing_faculty['uid'] == $item['user']) {
          return;
        }
      }
    }
    $course->field_course_faculty[$course->language][] = array('uid' => $item['user']);
    node_save($course); 
    return $course;
  }
  
  protected function newEntity(FeedsSource $source) {
  
    return NULL;
  }
  
  private function getTargetEntity($id, $type) {
    if($type == 'user') {
      return db_select('field_data_field_sis_id', 's')
                ->condition('s.field_sis_id_value', $id)
                ->fields('s', array('entity_id'))
                ->execute()
                ->fetchField();
    }
    return db_select('feeds_item', 'i')
             ->condition('i.entity_type', $type)
             ->condition('i.guid', $id)
             ->fields('i', array('entity_id'))
             ->execute()
             ->fetchField();
  }
  
  public function process(FeedsSource $source, FeedsParserResult $parser_result) {
    $state = $source->state(FEEDS_PROCESS);
    $mappings = $this->config['mappings'];
    
    foreach ($mappings as $map) {
      if ($map['target'] == 'sis_id') {
        $sis_id_key = $map['source'];
      }
      if ($map['target'] == 'course_id') {
        $course_id_key = $map['source'];
      }
    }
    
    while ($item = $parser_result->shiftItem()) {
      $item['course'] = $this->getTargetEntity($item[$course_id_key], 'node');
      $item['user'] = $this->getTargetEntity($item[$sis_id_key], 'user');
      if ($item['course'] && $item['user']) {        
        try {
          $entity = $this->newReference($source, $item);

          // Track progress.
          if ($entity) {
            $state->updated++;
          }
        }
        catch (Exception $e) {
          $state->failed++;
          drupal_set_message($e->getMessage(), 'warning');
          $message = $e->getMessage();
          $message .= '<h3>Original item</h3>';
          $message .= '<pre>' . var_export($item, TRUE) . '</pre>';
          $message .= '<h3>Entity</h3>';
          $message .= '<pre>' . var_export($entity, TRUE) . '</pre>';
          $source->log('import', $message, array(), WATCHDOG_ERROR);
        }
      }
    }

    // Set messages if we're done.
    if ($source->progressImporting() != FEEDS_BATCH_COMPLETE) {
      return;
    }
    $info = $this->entityInfo();
    $tokens = array(
      '@entity' => strtolower($info['label']),
      '@entities' => strtolower($info['label plural']),
    );
    $messages = array();
    if ($state->created) {
      $messages[] = array(
       'message' => format_plural(
          $state->created,
          'Created @number @entity.',
          'Created @number @entities.',
          array('@number' => $state->created) + $tokens
        ),
      );
    }
    if ($state->updated) {
      $messages[] = array(
       'message' => format_plural(
          $state->updated,
          'Updated @number @entity.',
          'Updated @number @entities.',
          array('@number' => $state->updated) + $tokens
        ),
      );
    }
    if ($state->failed) {
      $messages[] = array(
       'message' => format_plural(
          $state->failed,
          'Failed importing @number @entity.',
          'Failed importing @number @entities.',
          array('@number' => $state->failed) + $tokens
        ),
        'level' => WATCHDOG_ERROR,
      );
    }
    if (empty($messages)) {
      $messages[] = array(
        'message' => t('There are no new @entities.', array('@entities' => strtolower($info['label plural']))),
      );
    }
    foreach ($messages as $message) {
      drupal_set_message($message['message']);
      $source->log('import', $message['message'], array(), isset($message['level']) ? $message['level'] : WATCHDOG_INFO);
    }
  }

  /**
   * Loads an existing enrollment relation.
   *
   * If the update existing method is not FEEDS_UPDATE_EXISTING, only the enrollment relation
   * table will be loaded, foregoing the relation_load API for better performance.
   */
  protected function entityLoad(FeedsSource $source, $relation_id) {
    if ($this->config['update_existing'] == FEEDS_UPDATE_EXISTING) {
      $relation = relation_load($relation_id, NULL, TRUE);
    }
    else {
      // We're replacing the existing enrollment relation. Only save the absolutely necessary.
      $relation = db_query("SELECT created, rid, vid, type FROM {node} WHERE rid = :rid", array(':rid' => $relation_id))->fetchObject();
      $relation->uid = $this->config['author'];
    }
    // Populate properties that are set by enrollment relation_object_prepare().
    return $relation;
  }

  /**
   * Save a enrollment relation.
   */
  public function entitySave($entity) {
    relation_save($entity);
  }

  /**
   * Delete a series of relations.
   */
  protected function entityDeleteMultiple($relation_ids) {
    relation_multiple_delete($relation_ids);
  }

  /**
   * Implement expire().
   *
   * @todo: move to processor stage?
   */
  public function expire($time = NULL) {
    if ($time === NULL) {
      $time = $this->expiryTime();
    }
    if ($time == FEEDS_EXPIRE_NEVER) {
      return;
    }
    $count = $this->getLimit();
    $relations = db_query_range("SELECT c.nid FROM {node} c JOIN {feeds_item} fi ON fi.entity_type = 'relation' AND c.nid = fi.entity_id WHERE fi.id = :id AND c.created < :created", 0, $count, array(':id' => $this->id, ':created' => REQUEST_TIME - $time));
    $relation_ids = array();
    foreach ($relations as $relation) {
      $relation_ids[$relation->rid] = $relation->rid;
    }
    $this->entityDeleteMultiple($relation_ids);
    if (db_query_range("SELECT 1 FROM {node} c JOIN {feeds_item} fi ON fi.entity_type = 'relation' AND c.nid = fi.entity_id WHERE fi.id = :id AND c.created < :created", 0, 1, array(':id' => $this->id, ':created' => REQUEST_TIME - $time))->fetchField()) {
      return FEEDS_BATCH_ACTIVE;
    }
    return FEEDS_BATCH_COMPLETE;
  }

  /**
   * Return expiry time.
   */
  public function expiryTime() {
    return $this->config['expire'];
  }
  
  /**
   * Override parent::configDefaults().
   */
  public function configDefaults() {
    return array(
      'expire' => FEEDS_EXPIRE_NEVER,
      'author' => 0,
    ) + parent::configDefaults();
  }

  /**
   * Override parent::configForm().
   */
  public function configForm(&$form_state) {
    $form = parent::configForm($form_state);
    
    $author = user_load($this->config['author']);
    
    return $form;
  }

  /**
   * Override parent::configFormValidate().
   */
  public function configFormValidate(&$values) {
    if ($author = user_load_by_name($values['author'])) {
      $values['author'] = $author->uid;
    }
    else {
      $values['author'] = 0;
    }
  }

  /**
   * Reschedule if expiry time changes.
   */
  public function configFormSubmit(&$values) {
    if ($this->config['expire'] != $values['expire']) {
      feeds_reschedule($this->id);
    }
    parent::configFormSubmit($values);
  }

  /**
   * Override setTargetElement to operate on a target item that is a enrollment relation.
   */
  public function setTargetElement(FeedsSource $source, $target_relation, $target_element, $value) {
    switch ($target_element) {
      case 'created':
        $target_relation->created = feeds_to_unixtime($value, REQUEST_TIME);
        break;
      case 'feeds_source':
        // Get the class of the feed enrollment relation importer's fetcher and set the source
        // property. See feeds_enrollment relation_update() how $relation->feeds gets stored.
        if ($id = feeds_get_importer_id('enrollment')) {
          $class = get_class(feeds_importer($id)->fetcher);
          $target_relation->feeds[$class]['source'] = $value;
          // This effectively suppresses 'import on submission' feature.
          // See feeds_enrollment relation_insert().
          $target_relation->feeds['suppress_import'] = TRUE;
        }
        break;
      default:
        parent::setTargetElement($source, $target_relation, $target_element, $value);
        break;
    }
  }

  /**
   * Return available mapping targets.
   */
  public function getMappingTargets() {
    $targets = parent::getMappingTargets();
    
    $targets += array(
      'status' => array(
        'name' => t('Published status'),
        'description' => t('Whether a enrollment relation is published or not. 1 stands for published, 0 for not published.'),
      ),
      'created' => array(
        'name' => t('Published date'),
        'description' => t('The UNIX time when a enrollment relation has been created.'),
      ),
      'sis_id' => array(
        'name' => t('SIS ID'),
        'description' => t('The ID of the faculty.'),
      ),
      'course_id' => array(
        'name' => t('Course Unique ID'),
        'description' => t('Unique code for the course (like term + number + section).'),
      ),
    );

    // If the target content type is a Feed enrollment relation, expose its source field.
    if ($id = feeds_get_importer_id('enrollment')) {
      $name = feeds_importer($id)->config['name'];
      $targets['feeds_source'] = array(
        'name' => t('Feed source'),
        'description' => t('The relation created by this processor is a Feed Node, it represents a source itself. Depending on the fetcher selected on the importer "@importer", this field is expected to be for example a URL or a path to a file.', array('@importer' => $name)),
        'optional_unique' => TRUE,
      );
    }

    // Let other modules expose mapping targets.
    self::loadMappers();
    feeds_alter('feeds_processor_targets', $targets, 'relation', 'enrollment');

    return $targets;
  }

  /**
   * Get rid of an existing feed item enrollment relation if available.
   */
  protected function existingEntityId(FeedsSource $source, FeedsParserResult $result) {
    if ($relation_id = parent::existingEntityId($source, $result)) {
      return $relation_id;
    }

    // Iterate through all unique targets and test whether they do already
    // exist in the database.
    foreach ($this->uniqueTargets($source, $result) as $target => $value) {
      switch ($target) {
        case 'rid':
          $relation_id = db_query("SELECT rid FROM {node} WHERE rid = :rid", array(':rid' => $value))->fetchField();
          break;
        case 'feeds_source':
          if ($id = feeds_get_importer_id('enrollment')) {
            $relation_id = db_query("SELECT fs.feed_rid FROM {node} c JOIN {feeds_source} fs ON c.nid = fs.feed_rid WHERE fs.id = :id AND fs.source = :source", array(':id' => $id, ':source' => $value))->fetchField();
          }
          break;
      }
      if ($relation_id) {
        // Return with the first rid found.
        return $relation_id;
      }
    }
    return 0;
  }
}
