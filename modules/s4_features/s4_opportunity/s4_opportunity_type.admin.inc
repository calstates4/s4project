<?php

/**
 * @file
 * s4_opportunity type editing UI.
 */

/**
 * UI controller.
 */
class s4OpportunityTypeUIController extends EntityDefaultUIController {

  /**
   * Overrides hook_menu() defaults.
   */
  public function hook_menu() {
    $items = parent::hook_menu();
		$items[$this->path]['description'] = 'Manage s4_opportunity entity types, including adding
		and removing fields and the display of fields.';
    return $items;
  }
}

/**
 * Generates the s4_opportunity type editing form.
 */
function s4_opportunity_type_form($form, &$form_state, $s4_opportunity_type, $op = 'edit') {

  if ($op == 'clone') {
    $s4_opportunity_type->label .= ' (cloned)';
    $s4_opportunity_type->type = '';
  }

  $form['label'] = array(
    '#title' => t('Label'),
    '#type' => 'textfield',
    '#default_value' => $s4_opportunity_type->label,
    '#description' => t('The human-readable name of this s4_opportunity type.'),
    '#required' => TRUE,
    '#size' => 30,
  );
  // Machine-readable type name.
  $form['type'] = array(
    '#type' => 'machine_name',
    '#default_value' => isset($s4_opportunity_type->type) ? $s4_opportunity_type->type : '',
    '#maxlength' => 32,
//    '#disabled' => $s4_opportunity_type->isLocked() && $op != 'clone',
    '#machine_name' => array(
      'exists' => 's4_opportunity_get_types',
      'source' => array('label'),
    ),
    '#description' => t('A unique machine-readable name for this s4_opportunity type. It must only contain lowercase letters, numbers, and underscores.'),
  );

  $form['data']['#tree'] = TRUE;
  
  $form['data']['students_can_place'] = array(
    '#type' => 'checkbox',
    '#title' => t('Students can be placed with this type of opportunity'),
    '#default_value' => !empty($s4_opportunity_type->data['students_can_place']),
  );

  $online_forms = db_select('node', 'n')
                  ->condition('type', 'webform')
                  ->condition('status', 1)
                  ->fields('n', array('nid', 'title'))
                  ->orderBy('title')
                  ->execute()
                  ->fetchAllKeyed();

  $form['data']['signup_form'] = array(
    '#type' => 'select',
    '#title' => t('Signup form'),
    '#description' => t('Select an !link that students have to complete once they are placed with this type of opportunity', array('!link' => l(t('online form'), 'forms'))),
    '#options' => $online_forms,
    '#empty_option' => t(' - None - '),
    '#default_value' => !empty($s4_opportunity_type->data['signup_form']) ? $s4_opportunity_type->data['signup_form'] : '',
  );

  $form['data']['email_enable'] = array(
    '#type' => 'checkbox',
    '#title' => t('Send email to students when their placement is made'),
    '#default_value' => (!empty($s4_opportunity_type->data['email_enable'])) ? $s4_opportunity_type->data['email_enable'] : 0,
    );

  $form['data']['email_subject'] = array(
    '#type' => 'textfield',
    '#title' => t('Email subject'),
    '#default_value' => (!empty($s4_opportunity_type->data['email_subject']) ? $s4_opportunity_type->data['email_subject'] : ''),
    );

  $form['data']['email_body'] = array(
    '#type' => 'text_format',
    '#title' => t('Email body'),
    '#format' => (!empty($s4_opportunity_type->data['email_body']))
      ? $s4_opportunity_type->data['email_body']['format']
      : FILTER_FORMAT_DEFAULT,
    '#default_value' => (!empty($s4_opportunity_type->data['email_body'])) 
      ? $s4_opportunity_type->data['email_body']['value']
      : '',
  );

  if (module_exists('token')) {
    $form['tokens'] = array(
      '#theme' => 'token_tree',
      '#token_types' => array('s4_opportunity', 'user'),
      '#weight' => $form['field_confirmation_email']['#weight'] + 1,
    );
  };

  $form['actions'] = array('#type' => 'actions');
  $form['actions']['submit'] = array(
    '#type' => 'submit',
    '#value' => t('Save opportunity type'),
    '#weight' => 40,
  );


  return $form;
}

/**
 * Form API submit callback for the type form.
 */
function s4_opportunity_type_form_submit(&$form, &$form_state) {
  $s4_opportunity_type = entity_ui_form_submit_build_entity($form, $form_state);
  $s4_opportunity_type->save();
  s4_opportunity_add_default_fields($s4_opportunity_type->type);
  $form_state['redirect'] = 'admin/structure/s4_opportunity_types';
}

/**
 * Form API submit callback for the delete button.
 */
function s4_opportunity_type_form_submit_delete(&$form, &$form_state) {
  $form_state['redirect'] = 'admin/structure/s4_opportunity_types/manage/' . $form_state['s4_opportunity_type']->type . '/delete';
}