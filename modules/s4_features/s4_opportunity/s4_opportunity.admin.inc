<?php

/**
 * @file
 * s4_opportunity editing UI.
 *
 * We make very little use of the EntityAPI interface for this - preferring instead to use
 * views. That offers more flexibility to change a UI that will, more often than not,
 * be end-user facing.
 */

/**
 * UI controller.
 */
class s4OpportunityUIController extends EntityDefaultUIController {

  /**
   * Overrides hook_menu() defaults. Main reason for doing this is that
   * parent class hook_menu() is optimized for entity type administration.
   */
  public function hook_menu() {
    
    $items = array();
    $id_count = count(explode('/', $this->path));
    $wildcard = isset($this->entityInfo['admin ui']['menu wildcard']) ? $this->entityInfo['admin ui']['menu wildcard'] : '%' . $this->entityType;

    $items[$this->path] = array(
      'title' => 'Opportunities',
      'description' => 'Add edit and update opportunities.',
      'page callback' => 'system_admin_menu_block_page',
      'access arguments' => array('access administration pages'),
      'file path' => drupal_get_path('module', 'system'),
      'file' => 'system.admin.inc',
    );
    
    // Change the overview menu type for the list of opportunities.
    $items[$this->path]['type'] = MENU_LOCAL_TASK;
    
    // Change the add page menu to multiple types of entities
    $items[$this->path . '/add'] = array(
      'title' => 'Add an opportunity',
      'description' => 'Add a new s4_opportunity',
      'page callback'  => 's4_opportunity_add_page',
      'access callback'  => 's4_opportunity_access',
      'access arguments' => array('edit'),
      'type' => MENU_NORMAL_ITEM,
      'weight' => 20,
      'file' => 's4_opportunity.admin.inc',
      'file path' => drupal_get_path('module', $this->entityInfo['module'])

    );
    
    // Add menu items to add each different type of entity.
    foreach (s4_opportunity_get_types() as $type) {
      $items['opportunities/add/' . $type->type] = array(
        'title' => 'Add ' . $type->label,
        'page callback' => 's4_opportunity_form_wrapper',
        'page arguments' => array(s4_opportunity_create(array('type' => $type->type))),
        'access callback' => 's4_opportunity_access',
        'access arguments' => array('edit', 'edit ' . $type->type),
        'file' => 's4_opportunity.admin.inc',
        'file path' => drupal_get_path('module', $this->entityInfo['module'])
      );
    }

    // Loading and editing s4_opportunity entities
    $items['opportunity/' . $wildcard .'/edit'] = array(
      'page callback' => 's4_opportunity_form_wrapper',
      'page arguments' => array(1),
      'access callback' => 's4_opportunity_access',
      'access arguments' => array('edit', $id_count + 1),
      'weight' => 0,
      'file' => 's4_opportunity.admin.inc',
      'file path' => drupal_get_path('module', $this->entityInfo['module']),
      'type' => MENU_LOCAL_TASK
    );
    
    $items['opportunity/' . $wildcard . '/delete'] = array(
      'title' => 'Delete',
      'page callback' => 's4_opportunity_delete_form_wrapper',
      'page arguments' => array(1),
      'access callback' => 's4_opportunity_access',
      'access arguments' => array('edit', 1),
      'type' => MENU_LOCAL_TASK,
      'context' => MENU_CONTEXT_INLINE,
      'weight' => 10,
      'file' => 's4_opportunity.admin.inc',
      'file path' => drupal_get_path('module', $this->entityInfo['module'])
    );
    
    // Menu item for viewing s4_opportunitys
    $items['opportunity/' . $wildcard] = array(
      //'title' => 'Title',
      'title callback' => 's4_opportunity_page_title',
      'title arguments' => array(1),
      'page callback' => 's4_opportunity_page_view',
      'page arguments' => array(1),
      'access callback' => 's4_opportunity_access',
      'access arguments' => array('view', 1),
      'type' => MENU_LOCAL_TASK,
    );

    // Menu item for viewing s4_opportunitys
    $items['opportunity/' . $wildcard .'/view'] = array(
      'title' => 'View',
      'type' => MENU_DEFAULT_LOCAL_TASK,
      'weight' => -1
    );

    return $items;
  }
  
  
  /**
   * Create the markup for the add s4_opportunity Entities page within the class
   * so it can easily be extended/overriden.
   */ 
  public function addPage() {
    $item = menu_get_item();
    $content = system_admin_menu_block($item);

    if (count($content) == 1) {
      $item = array_shift($content);
      drupal_goto($item['href']);
    }    
        
    return theme('s4_opportunity_add_list', array('content' => $content));
  }
  
}


/**
 * Form callback wrapper: create or edit a s4_opportunity.
 *
 * @param $s4_opportunity
 *   The s4_opportunity object being edited by this form.
 *
 * @see s4_opportunity_edit_form()
 */
function s4_opportunity_form_wrapper($s4_opportunity) {
  // Add the breadcrumb for the form's location.
  s4_opportunity_set_breadcrumb();
  drupal_set_title($s4_opportunity->name);
  return drupal_get_form('s4_opportunity_edit_form', $s4_opportunity);
}


/**
 * Form callback wrapper: delete a s4_opportunity.
 *
 * @param $s4_opportunity
 *   The s4_opportunity object being edited by this form.
 *
 * @see s4_opportunity_edit_form()
 */
function s4_opportunity_delete_form_wrapper($s4_opportunity) {
  // Add the breadcrumb for the form's location.
  //s4_opportunity_set_breadcrumb();
  return drupal_get_form('s4_opportunity_delete_form', $s4_opportunity);
}


/**
 * Form callback: create or edit a s4_opportunity.
 *
 * @param $s4_opportunity
 *   The s4_opportunity object to edit or for a create form an empty s4_opportunity object
 *     with only a s4_opportunity type defined.
 */
function s4_opportunity_edit_form($form, &$form_state, $s4_opportunity) {
  // Add the default field elements.

  $type = s4_opportunity_type_load($s4_opportunity->type);
  $form['name'] = array(
    '#type' => 'textfield',
    '#title' => t('@type Name', array('@type' => $type->label)),
    '#default_value' => isset($s4_opportunity->name) ? $s4_opportunity->name : '',
    '#maxlength' => 255,
    '#required' => TRUE,
    '#weight' => -5,
  );

  $form['status'] = array(
    '#type' => 'checkbox',
    '#title' => t('Active'),
    '#description' => t('Active @types are available for students to be placed with. Inactive @types are only visible to department staff.', array('@types' => check_plain($type->label))),
    '#default_value' => isset($s4_opportunity->status) ? $s4_opportunity->status : 0,
    '#maxlength' => 255,
    '#weight' => -4,
  );

  if(!user_access('administer opportunities')) {
    $form['status']['#access'] = FALSE;
  }
  
  $form['data']['#tree'] = TRUE;

  // Add the field related form elements.
  $form_state['s4_opportunity'] = $s4_opportunity;
  field_attach_form('s4_opportunity', $s4_opportunity, $form, $form_state);

  $form['actions'] = array(
    '#type' => 'container',
    '#attributes' => array('class' => array('form-actions')),
    '#weight' => 400,
  );

  // We add the form's #submit array to this button along with the actual submit
  // handler to preserve any submit handlers added by a form callback_wrapper.
  $submit = array();

  if (!empty($form['#submit'])) {
    $submit += $form['#submit'];
  }
  $form['actions']['submit'] = array(
    '#type' => 'submit',
    '#value' => t('Save @type', array('@type' => check_plain($type->label))),
    '#submit' => $submit + array('s4_opportunity_edit_form_submit'),
  );
  
  if (!empty($s4_opportunity->name)) {
    $form['actions']['delete'] = array(
      '#type' => 'submit',
      '#value' => t('Delete @type', array('@type' => check_plain($type->label))),
      '#suffix' => l(t('Cancel'), 'admin/content/opportunities'),
      '#submit' => $submit + array('s4_opportunity_form_submit_delete'),
      '#weight' => 45,
    );
  }

  // We append the validate handler to #validate in case a form callback_wrapper
  // is used to add validate handlers earlier.
  $form['#validate'][] = 's4_opportunity_edit_form_validate';
  return $form;
}


/**
 * Form API validate callback for the s4_opportunity form
 */
function s4_opportunity_edit_form_validate(&$form, &$form_state) {
  $s4_opportunity = $form_state['s4_opportunity'];
  
  // Notify field widgets to validate their data.
  field_attach_form_validate('s4_opportunity', $s4_opportunity, $form, $form_state);
}


/**
 * Form API submit callback for the s4_opportunity form.
 * 
 * @todo remove hard-coded link
 */
function s4_opportunity_edit_form_submit(&$form, &$form_state) {
  
  $s4_opportunity = entity_ui_controller('s4_opportunity')->entityFormSubmitBuildEntity($form, $form_state);
  // Save the s4_opportunity and go back to the list of opportunities
  $s4_opportunity->status = $form_state['values']['status'];
  // Add in created and changed times.
  if ($s4_opportunity->is_new = isset($s4_opportunity->is_new) ? $s4_opportunity->is_new : 0){
    $s4_opportunity->created = time();
  }

  $s4_opportunity->changed = time();
  
  $s4_opportunity->save();
  $site = field_get_items('s4_opportunity', $s4_opportunity, 'field_opportunity_sites');
  $form_state['redirect'] = ($site[0]['target_id']) ? 'node/'. $site[0]['target_id'] .'/opportunities' : 'site';
}

/**
 * Form API submit callback for the delete button.
 * 
 * @todo Remove hard-coded path
 */
function s4_opportunity_form_submit_delete(&$form, &$form_state) {
  $form_state['redirect'] = 'admin/content/opportunities/s4_opportunity/' . $form_state['s4_opportunity']->s4_opportunity_id . '/delete';
}


/**
 * Form callback: confirmation form for deleting a s4_opportunity.
 *
 * @param $s4_opportunity
 *   The s4_opportunity to delete
 *
 * @see confirm_form()
 */
function s4_opportunity_delete_form($form, &$form_state, $s4_opportunity) {
  $form_state['s4_opportunity'] = $s4_opportunity;

  $form['#submit'][] = 's4_opportunity_delete_form_submit';
  $type = s4_opportunity_type_load($s4_opportunity->type);

  $form = confirm_form($form,
    t('Are you sure you want to delete %type %name?', array('%type' => $type->label, 
      '%name' => $s4_opportunity->name)),
    'admin/content/opportunities/s4_opportunity',
    '<p>' . t('This action cannot be undone.') . '</p>',
    t('Delete'),
    t('Cancel'),
    'confirm'
  );
  
  return $form;
}

/**
 * Submit callback for s4_opportunity_delete_form
 */
function s4_opportunity_delete_form_submit($form, &$form_state) {
  $s4_opportunity = $form_state['s4_opportunity'];

  s4_opportunity_delete($s4_opportunity);

  drupal_set_message(t('%name has been deleted.', array('%name' => $s4_opportunity->name)));
  watchdog('s4_opportunity', 'Deleted opportunity %name.', array('%name' => $s4_opportunity->name));

  $form_state['redirect'] = 'admin/content/opportunities';
}



/**
 * Page to add s4_opportunity Entities.
 *
 * @todo Pass this through a proper theme function
 */
function s4_opportunity_add_page() {
  $controller = entity_ui_controller('s4_opportunity');
  return $controller->addPage();
}


/**
 * Displays the list of available s4_opportunity types for s4_opportunity creation.
 *
 * @ingroup themeable
 */
function theme_s4_opportunity_add_list($variables) {
  $content = $variables['content'];
  $output = '';
  if ($content) {
    $output = '<dl class="s4_opportunity-type-list">';
    foreach ($content as $item) {
      $output .= '<dt>' . l($item['title'], $item['href']) . '</dt>';
      $output .= '<dd>' . filter_xss_admin($item['description']) . '</dd>';
    }
    $output .= '</dl>';
  }
  else {
    if (user_access('administer s4_opportunity types')) {
      $output = '<p>' . t('Opportunities cannot be added because you have not created any s4_opportunity types yet. Go to the <a href="@create-s4_opportunity-type">s4_opportunity type creation page</a> to add a new s4_opportunity type.', array('@create-s4_opportunity-type' => url('admin/structure/s4_opportunity_types/add'))) . '</p>';
    }
    else {
      $output = '<p>' . t('No s4_opportunity types have been created yet for you to use.') . '</p>';
    }
  }

  return $output;
}

/**
 * Sets the breadcrumb for administrative s4_opportunity pages.
 */
function s4_opportunity_set_breadcrumb() {
  $breadcrumb = array(
    l(t('Home'), '<front>'),
    l(t('Administration'), 'admin'),
    l(t('Content'), 'admin/content'),
    l(t('opportunities'), 'admin/content/opportunities'),
  );

  drupal_set_breadcrumb($breadcrumb);
}

function s4_opportunity_admin_form() {
  $form = array();

  $form['s4_opportunity_begin_subject'] = array(
    '#type' => 'textfield',
    '#title' => t('Subject of the create an opportunity block'),
    '#default_value' => variable_get('s4_opportunity_begin_subject', t('Start a new opportunity'))
    );

  $message = variable_get('s4_opportunity_begin_message', array('format' => filter_default_format(), 'value' => ''));
  $form['s4_opportunity_begin_message'] = array(
    '#type' => 'text_format',
    '#title' => t('Message for users when beginning to create an opportunity.'),
    '#text_format' => $message['format'],
    '#default_value' => $message['value']
    );

  return system_settings_form($form);
}

/**
 * Form to disable fields in a site when being created in the context of an opportunity workflow.
 */
function s4_opportunity_admin_site_fields_form() {
  $form = array();

  $fields = field_info_instances('node', 'site');
  $options = array();
  foreach($fields as $field_name => $field) {
    if($field['s4_sites_field_access']) {
      $options[$field_name] = $field['label'];
    }
  }

  $form['s4_opportunity_site_disabled_fields'] = array(
    '#type' => 'checkboxes',
    '#title' => t('Check fields that should be disabled when creating a new site as part of an opportunity'),
    '#options' => $options,
    '#default_value' => variable_get('s4_opportunity_site_disabled_fields', array())
    );

  return system_settings_form($form);
}
