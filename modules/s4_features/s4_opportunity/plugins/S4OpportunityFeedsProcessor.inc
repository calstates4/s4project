<?php

/**
 * @file
 * Class definition of S4OpportunityFeedsProcessor.
 */
 
/**
 * Creates opportunities from feed items.
 */
class S4OpportunityFeedsProcessor extends FeedsProcessor {
  /**
   * Define entity type.
   */
  public function entityType() {
    return 's4_opportunity';
  }

  /**
   * Implements parent::entityInfo().
   */
  protected function entityInfo() {
    $info = parent::entityInfo();
    $info['label plural'] = t('Opportunities');
    return $info;
  }

  /**
   * Creates a new opportunity opportunity in memory and returns it.
   */
  public function newActivity(FeedsSource $source, $item) {
      $opportunity = entity_create('s4_opportunity', array(
                      'type' => $this->config['opportunity_type']));
      if ($item['author_name']) {
        $author = db_select('users', 'u')
                  ->fields('u', array('uid'))
                  ->condition('u.name', $item['author_name'])
                  ->execute()
                  ->fetchField();
        if ($author) {
          $opportunity->uid = $author;
        }
      }
      return $opportunity;
  }
  
  protected function newEntity(FeedsSource $source) {
  
    return NULL;
  }
  
  private function getTargetEntity($id, $type) {
    return db_select('feeds_item', 'i')
             ->condition('i.entity_type', $type)
             ->condition('i.guid', $id)
             ->fields('i', array('entity_id'))
             ->execute()
             ->fetchField();
  }
  
  public function process(FeedsSource $source, FeedsParserResult $parser_result) {
    $state = $source->state(FEEDS_PROCESS);
    while ($item = $parser_result->shiftItem()) {
      if (!($entity_id = $this->existingEntityId($source, $parser_result)) ||
           ($this->config['update_existing'] != FEEDS_SKIP_EXISTING)) {

        // Only proceed if item has actually changed.
        $hash = $this->hash($item);
        if (!empty($entity_id) && $hash == $this->getHash($entity_id)) {
          continue;
        }
        
        try {
          // Assemble opportunity, map item to it, save.
          if (empty($entity_id)) {
            $entity = $this->newActivity($source, $item);
            $this->newItemInfo($entity, $source->feed_nid, $hash);
          }
          else {
            $entity = $this->entityLoad($source, $entity_id);
            // The feeds_item table is always updated with the info for the most recently processed entity.
            // The only carryover is the entity_id.
            $this->newItemInfo($entity, $source->feed_nid, $hash);
            $entity->feeds_item->entity_id = $entity_id;
          }
          $this->map($source, $parser_result, $entity);
          $this->entityValidate($entity);
          $this->entitySave($entity);

          // Track progress.
          if (empty($entity_id)) {
            $state->created++;
          }
          else {
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
   * Loads an existing opportunity opportunity.
   *
   * If the update existing method is not FEEDS_UPDATE_EXISTING, only the opportunity opportunity
   * table will be loaded, foregoing the s4_opportunity_load API for better performance.
   */
  protected function entityLoad(FeedsSource $source, $opportunity_id) {
    if ($this->config['update_existing'] == FEEDS_UPDATE_EXISTING) {
      $opportunity = s4_opportunity_load($opportunity_id, NULL, TRUE);
    }
    else {
      // We're replacing the existing opportunity opportunity. Only save the absolutely necessary.
      $opportunity = db_query("SELECT created, s4_opportunity_id, vid, type FROM {s4_opportunity} WHERE s4_opportunity_id = :opportunity_id", array(':opportunity_id' => $opportunity_id))->fetchObject();
    }
    // Populate properties that are set by opportunity opportunity_object_prepare().
    if ($this->config['update_existing'] == FEEDS_UPDATE_EXISTING) {
      $opportunity->log = 'Updated by S4OpportunityFeedsProcessor';
    }
    else {
      $opportunity->log = 'Replaced by S4OpportunityFeedsProcessor';
    }
    return $opportunity;
  }

  /**
   * Save a opportunity opportunity.
   */
  public function entitySave($entity) {
    $contact = s4_opportunity_load($entity->s4_opportunity_id);
    s4_opportunity_save($entity);
  }

  /**
   * Delete a series of opportunities.
   */
  protected function entityDeleteMultiple($opportunity_ids) {
    s4_opportunity_multiple_delete($opportunity_ids);
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
    $opportunities = db_query_range("SELECT c.opportunity_id FROM {s4_opportunity} c JOIN {feeds_item} fi ON fi.entity_type = 's4_opportunity' AND c.s4_opportunity_id = fi.entity_id WHERE fi.id = :id AND c.created < :created", 0, $count, array(':id' => $this->id, ':created' => REQUEST_TIME - $time));
    $opportunity_ids = array();
    foreach ($opportunities as $opportunity) {
      $opportunity_ids[$opportunity->s4_opportunity_id] = $opportunity->s4_opportunity_id;
    }
    $this->entityDeleteMultiple($opportunity_ids);
    if (db_query_range("SELECT 1 FROM {s4_opportunity} c JOIN {feeds_item} fi ON fi.entity_type = 's4_opportunity' AND c.s4_opportunity_id = fi.entity_id WHERE fi.id = :id AND c.created < :created", 0, 1, array(':id' => $this->id, ':created' => REQUEST_TIME - $time))->fetchField()) {
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
   * Overopportunity_ide parent::configDefaults().
   */
  public function configDefaults() {
    return array(
      'expire' => FEEDS_EXPIRE_NEVER,
      'author' => 0,
      'opportunity_type' => 'note',
    ) + parent::configDefaults();
  }

  /**
   * Overopportunity_ide parent::configForm().
   */
  public function configForm(&$form_state) {
    $form = parent::configForm($form_state);
    
    $author = user_load($this->config['author']);
    
    $opportunity_types = crm_core_opportunity_types();
    $types = array();
    foreach ($opportunity_types as $type) {
      $types[$type->type] = $type->label;
    }
    $form['opportunity_type'] = array(
      '#type' => 'select',
      '#title' => t('Opportunity type'),
      '#description' => t('Select the type of opportunities to create.', array('!feed_id' => $this->id)),
      '#options' => $types,
      '#default_value' => $this->config['opportunity_type'],
    );
    $period = drupal_map_assoc(array(FEEDS_EXPIRE_NEVER, 3600, 10800, 21600, 43200, 86400, 259200, 604800, 2592000, 2592000 * 3, 2592000 * 6, 31536000), 'feeds_format_expire');
    $form['expire'] = array(
      '#type' => 'select',
      '#title' => t('Expire opportunities'),
      '#options' => $period,
      '#description' => t('Select after how much time opportunities should be deleted. The opportunity opportunity\'s published date will be used for determining the opportunity opportunity\'s age, see Mapping settings.'),
      '#default_value' => $this->config['expire'],
    );
    $form['update_existing']['#options'] = array(
      FEEDS_SKIP_EXISTING => 'Do not update existing opportunities',
      FEEDS_REPLACE_EXISTING => 'Replace existing opportunities',
      FEEDS_UPDATE_EXISTING => 'Update existing opportunities (slower than replacing them)',
    );
    return $form;
  }

  /**
   * Overopportunity_ide parent::configFormValidate().
   */
  public function configFormValidate(&$values) {

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
   * Overopportunity_ide setTargetElement to operate on a target item that is a opportunity opportunity.
   */
  public function setTargetElement(FeedsSource $source, $target_opportunity, $target_element, $value) {
    switch ($target_element) {
      case 'created':
        $target_opportunity->created = feeds_to_unixtime($value, REQUEST_TIME);
        break;
      case 'feeds_source':
        // Get the class of the feed opportunity opportunity importer's fetcher and set the source
        // property. See feeds_opportunity opportunity_update() how $opportunity->feeds gets stored.
        if ($id = feeds_get_importer_id('s4_opportunity')) {
          $class = get_class(feeds_importer($id)->fetcher);
          $target_opportunity->feeds[$class]['source'] = $value;
          // This effectively suppresses 'import on submission' feature.
          // See feeds_opportunity opportunity_insert().
          $target_opportunity->feeds['suppress_import'] = TRUE;
        }
        break;
      default:
        parent::setTargetElement($source, $target_opportunity, $target_element, $value);
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
        'description' => t('Whether a opportunity opportunity is published or not. 1 stands for published, 0 for not published.'),
      ),
      'created' => array(
        'name' => t('Published date'),
        'description' => t('The UNIX time when a opportunity opportunity has been created.'),
      ),
      'student_id' => array(
        'name' => t('Student ID'),
        'description' => t('The ID of the student.'),
      ),
      'author_name' => array(
        'name' => t('Author username'),
        'description' => t('The username of the author.'),
      ),
    );

    // If the target content type is a Feed opportunity opportunity, expose its source field.
    if ($id = feeds_get_importer_id('s4_opportunity')) {
      $name = feeds_importer($id)->config['name'];
      $targets['feeds_source'] = array(
        'name' => t('Feed source'),
        'description' => t('The activity created by this processor is a Feed Node, it represents a source itself. Depending on the fetcher selected on the importer "@importer", this field is expected to be for example a URL or a path to a file.', array('@importer' => $name)),
        'optional_unique' => TRUE,
      );
    }

    // Let other modules expose mapping targets.
    self::loadMappers();
    feeds_alter('feeds_processor_targets', $targets, 's4_opportunity', $this->config['opportunity_type']);

    return $targets;
  }

  /**
   * Get opportunity_id of an existing feed item opportunity opportunity if available.
   */
  protected function existingEntityId(FeedsSource $source, FeedsParserResult $result) {
    if ($opportunity_id = parent::existingEntityId($source, $result)) {
      return $opportunity_id;
    }

    // Iterate through all unique targets and test whether they do already
    // exist in the database.
    foreach ($this->uniqueTargets($source, $result) as $target => $value) {
      switch ($target) {
        case 's4_opportunity_id':
          $opportunity_id = db_query("SELECT s4_opportunity_id FROM {s4_opportunity} WHERE s4_opportunity_id = :opportunity_id", array(':opportunity_id' => $value))->fetchField();
          break;
        case 'feeds_source':
          if ($id = feeds_get_importer_id('s4_opportunity')) {
            $opportunity_id = db_query("SELECT fs.feed_opportunity_id FROM {s4_opportunity} c JOIN {feeds_source} fs ON c.s4_opportunity_id = fs.feed_opportunity_id WHERE fs.id = :id AND fs.source = :source", array(':id' => $id, ':source' => $value))->fetchField();
          }
          break;
      }
      if ($opportunity_id) {
        // Return with the first opportunity_id found.
        return $opportunity_id;
      }
    }
    return 0;
  }
}
