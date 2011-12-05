<?php

/**
*	Field mappings so that users can use different headers than what is defined here.
*/
function s4_sites_import_field_mapping() {
	return array('title' => array(
										'description' => 'Title',
										'csv' => 'title'),
							'body' => array(
										'description' => 'Description',
										'csv' => 'description'),
							'location_street' => array(
										'description' => 'Street address',
										'csv' => 'address_street'),
							'location_additional' => array(
										'description' => 'Additional address',
										'csv' => 'address_street_2'),
							'location_city' => array(
										'description' => 'City',
										'csv' => 'city'),
							'location_state' => array(
										'description' => 'State',
										'csv' => 'state'),
							'location_postal_code' => array(
										'description' => 'Zip or postal code',
										'csv' => 'postal_code'),
							'field_phone' => array(
										'description' => 'Phone number',
										'csv' => 'phone',
										'value' => 'number'),
							'field_site_email' => array(
										'description' => 'Email address',
										'csv' => 'email',
										'value' => 'email'),
							'field_website' => array(
										'description' => 'Web address',
										'csv' => 'web_url',
										'value' => 'url'),
							);
}

/**
*	Form to import sites via a CSV file using the Batch API
*/
function s4_sites_import_sites_form() {
	$form = array();
	
	$form['csv_file_fid'] = array(
		'#type' => 'managed_file',
		'#title' => 'CSV file for import',
		'#description' => 'Upload a file in CSV format.',
		'#upload_location' => 'temporary://site_import/',
		'#upload_validators' => array('file_validate_extensions' => array('csv')),
	);
	
	
	$restrict = false;
	$workflow = false;
	foreach(taxonomy_get_vocabularies() as $vid => $vocabulary) {
		if($vocabulary->machine_name == 'site_restrictions') {
			$restrict = taxonomy_get_tree($vid);
		}
	}
	
	if($restrict) {
		$restrict_options = array();
		foreach($restrict as $tid => $term) {
			$restrict_options[$term->tid] = $term->name;
		}
		$form['default_restrict'] = array(
			'#type' => 'checkboxes',
			'#title' => 'Default site restrictions',
			'#options' => $restrict_options,
		);
	}
	
	if($workflow) {
		$workflow_options = array();
		foreach($workflow as $tid => $term) {
			$workflow_options[$term->tid] = $term->name;
		}
		$form['default_status'] = array(
			'#type' => 'checkboxes',
			'#title' => 'Default site status',
			'#options' => $workflow_options,
		);
	}
	
	$form['mapping'] = array(
		'#type' => 'fieldset',
		'#title' => 'Field mapping',
	);
	
	
	foreach(s4_sites_import_field_mapping() as $name => $field) {
		$form['mapping'][$name] = array(
			'#type' => 'textfield',
			'#title' => 'Field name for "' . $field['description'] . '"',
			'#default_value' => $field['csv']
		);
	}
		
	$form['submit'] = array(
		'#type' => 'submit',
		'#value' => 'Import sites',
	);
	
	return $form;

}

/**
*	Import sites form validation callback
*/
function s4_sites_import_sites_form_validate($form, $form_state) {
	foreach(s4_sites_import_field_mapping() as $name => $field) {
		if(!$form_state['values'][$name]) {
			form_set_error($name, t('The field mapping for @field cannot be blank. If your file does not include this field, just leave the default and it will be skipped.', array('@field' => $field['description'])));
		}
	}
	if (!isset($form_state['values']['csv_file_fid']) || !is_numeric($form_state['values']['csv_file_fid'])) {
    form_set_error('csv_file_fid', t('Please select a file to upload.'));
  }
}

/**
*	Submit callback for importing sites. We go through each row of the CSV and setup a Batch API call.
*/
function s4_sites_import_sites_form_submit($form, $form_state) {
	$file = file_load($form_state['values']['csv_file_fid']);
	$file = fopen(file_stream_wrapper_get_instance_by_uri($file->uri)->realpath(), 'r');
	$batch = array('finished' => 's4_sites_import_batch_finished',
    'title' => t('Importing sites'),
    'init_message' => t('Site import is starting.'),
    'progress_message' => t('Processed @current out of @total.'),
    'error_message' => t('The import batch has encountered an error.'),
    'file' => drupal_get_path('module', 's4_sites') . '/s4_sites.admin.inc',
  );
	$headers = fgetcsv($file);
	$fields = s4_sites_import_field_mapping();
	foreach($fields as $name => $field) {
		$fields[$name]['csv'] = $form_state['values'][$name];
		foreach($headers as $key => $header) {
			if($header == $fields[$name]['csv']) {
				$fields[$name]['key'] = $key;
			}
		}
	}
	
	$extra = array();
	if($form_state['values']['default_restrict']) {
		$i = 0;
		foreach($form_state['values']['default_restrict'] as $tid => $value) {
			if($value) {
				$extra['default_restrict'][$i]['tid'] = $value;
				$i++;
			}
		}
		
	}
	if($form_state['values']['default_status']) {
		$i = 0;
		foreach($form_state['values']['default_status'] as $tid => $value) {
			if($value) {
				$extra['default_status'][$i]['tid'] = $value;
				$i++;
			}
		}
		
	}
	while($row = fgetcsv($file)) {
		$batch['operations'][] = array('s4_sites_batch_import_node', array($row, $headers, $fields, $extra));
	}
	fclose($file);
  batch_set($batch);
}

/**
*	Batch callback where we take each row in the CSV and create a new node
*/
function s4_sites_batch_import_node($row, $headers, $fields, $extra, &$context) {
	global $user;
	$new_row = array();
	foreach($fields as $name => $field) {
		$new_row[$name] = check_plain($row[$field['key']]);
	}
	
	$node = new stdClass();
	$node->type = 'site';
    node_object_prepare($node);
    $node->uid = $user->uid;
    $node->language = LANGUAGE_NONE;
	$node->title = $new_row['title'];
	$location = array(
			'street' => $new_row['location_street'],
			'additional' => $new_row['location_additional'],
			'city' => $new_row['location_city'],
			'province' => $new_row['location_state'],
			'postal_code' => $new_row['location_postal_code'],
			
		);
	$node->field_location[$node->language][0]['lid'] = location_save($location);
	$node->body[$node->language][0]['value'] = $new_row['body'];
	$node->field_phone[$node->language][0]['number'] = intval($new_row['field_phone']);
	if(valid_email_address($new_row['field_site_email'])) {
		$node->field_site_email[$node->language][0]['email'] = $new_row['field_site_email'];
	}
	if(valid_url($new_row['field_website'], true)) {
		$node->field_website[$node->language][0]['url'] = $new_row['field_website'];
	}
	if($extra['default_restrict']) {
		$node->field_site_restrict[$node->language][0]['tid'] = $extra['default_restrict'];
	}
	if($extra['default_status']) {
		$node->field_workflow_status[$node->language][0]['tid'] = $extra['default_status'];
	}
	if(isset($extra['status'])) {
		$node->status = $extra['status'];
	}
	node_save($node);
	$context['message'] = t('Now processing %node', array('%node' => $new_row['title']));
	$context['results'][] = $node->nid;
}

/**
*	Finished callback for the batch import
*/
function s4_sites_import_batch_finished($success, $results, $operations) {
  if ($success) {
    // Here we do something meaningful with the results.
    $message = count($results) .' sites imported.';
    $message .= theme('item_list', $results);
  }
  else {
    // An error occurred.
    // $operations contains the operations that remained unprocessed.
    $error_operation = reset($operations);
    $message = t('An error occurred while processing %error_operation with arguments: @arguments', array('%error_operation' => $error_operation[0], '@arguments' => print_r($error_operation[1], TRUE)));
  }
  drupal_set_message($message);
}

/**
*  General administration form
*/
function s4_sites_admin_form() {
	$form = array();
	$workflow_status = false;
	foreach(taxonomy_get_vocabularies() as $vid => $vocabulary) {
		if($vocabulary->machine_name == 'workflow_status') {
			$workflow_status = taxonomy_get_tree($vid);
		}
	}
	
	$default_options = array();
	foreach($workflow_status as $status) {
		$default_options[$status->tid] = $status->name;
	}
	
	$form['s4_sites_workflow_default_state'] = array(
		'#type' => 'radios',
		'#title' => 'Select the default state when non-staff members create a site',
		'#options' => $default_options,
		'#default_value' => variable_get('s4_sites_workflow_default_state', 0),
	);
	
	foreach($workflow_status as $status) {
		$form['s4_sites_workflow_'. $status->tid] = array(
			'#type' => 'select',
			'#title' => t('Action to perform on @name', array('@name' => $status->name)),
			'#options' => array(
				'none' => 'Do nothing',
				'publish' => 'Make site available (publish)',
				'unpublish' => 'Remove site (unpublish)',
			),
			'#default_value' => variable_get('s4_sites_workflow_'. $status->tid, 'none'),
		);
	}
	
	return system_settings_form($form);
}

function s4_sites_test_import_sites() {
	$workflow_status = false;
	foreach(taxonomy_get_vocabularies() as $vid => $vocabulary) {
		if($vocabulary->machine_name == 'workflow_status') {
			$workflow_status = taxonomy_get_tree($vid);
		}
	}
	$extra = array();
	foreach($workflow_status as $status) {
		if(variable_get('s4_sites_workflow_'. $status->tid, 'none') == 'publish') {
			$extra['default_status'] = $status->tid;
		}
	}
	$file = fopen(drupal_get_path('module', 's4_sites') .'/tests/sites.csv', 'r');
	$headers = fgetcsv($file);
	$fields = s4_sites_import_field_mapping();
	foreach($headers as $k => $h) {
		foreach($fields as $name => $field) {
			if($field['csv'] == trim($h)) {
				$fields[$name]['key'] = $k;
			}
		}
	}
	$context = array();
	$extra = array('status' => NODE_PUBLISHED);
	while($row = fgetcsv($file)) {
		s4_sites_batch_import_node($row, $headers, $fields, $extra, $context);
	}
	fclose($file);
	foreach($context['results'] as $node) {
		$node = node_load($node);
		$node->status = 1;
		node_save($node);
	}
}
