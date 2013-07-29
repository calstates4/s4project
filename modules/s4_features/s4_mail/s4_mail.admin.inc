<?php

/**
 * Admin settings form.
 */

function s4_mail_admin_form() {
	$form = array();

	$form['s4_mail_debug'] = array(
		'#type' => 'checkbox',
		'#title' => t('Turn on debugging'),
		'#description' => t('When enabled, emails are displayed instead of being sent.'),
		'#default_value' => variable_get('s4_mail_debug', FALSE),
	);

	return system_settings_form($form);
}