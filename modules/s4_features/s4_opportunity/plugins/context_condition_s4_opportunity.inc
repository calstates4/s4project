<?php

/**
 * Expose node views/node forms of specific node types as a context condition.
 */
class context_condition_s4_opportunity extends context_condition {
  function condition_values() {
    return array(1 => t('Active when viewing an opportunity'));
  }

  function editor_form($context = NULL) {
    $form = parent::editor_form($context);
    $form[1]['#title'] = t('Active when viewing an opportunity');
    $form['#weight'] = -10;
    return $form;
  }

  function execute($value) {
    foreach ($this->get_contexts($value) as $context) {
      if(arg(0) == 'opportunity' && s4_opportunity_load(arg(1))) {
        $this->condition_met($context, $value);
      }
    }
  }
}