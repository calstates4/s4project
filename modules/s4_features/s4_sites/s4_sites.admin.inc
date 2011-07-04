<?php

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

function s4_sites_import_sites_form() {
	$form = array();
	
	$form['csv_file_fid'] = array(
		'#type' => 'managed_file',
		'#title' => 'CSV file for import',
		'#description' => 'Upload a file in CSV format.',
		'#upload_location' => 'temporary://site_import/',
		'#upload_validators' => array('file_validate_extensions' => array('csv')),
	);
	
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
	while($row = fgetcsv($file)) {
		$batch['operations'][] = array('s4_sites_batch_import_node', array($row, $headers, $fields));
	}
	fclose($file);
  batch_set($batch);
}

function s4_sites_batch_import_node($row, $headers, $fields, &$context) {
	global $user;
	$new_row = array();
	foreach($fields as $name => $field) {
		$new_row[$name] = filter_xss($row[$field['key']]);
	}
	$node = new stdClass();
	$node->type = 'site';
  node_object_prepare($node);
  $node->uid = $user->uid;
  $node->language = LANGUAGE_NONE;
	$node->title = check_plain($new_row['title']);
	$node->location[$node->language] = array(
		0 => array(
			'street' => $new_row['location_street'],
			'additional' => $new_row['location_additional'],
			'city' => $new_row['location_city'],
			'province' => $new_row['location_state'],
			'postal_code' => $new_row['location_postal_code'],
			
		),
	);
	$node->body[$node->language][0]['value'] = $new_row['body'];
	$node->field_phone[$node->language][0]['number'] = intval($new_row['field_phone']);
	if(valid_email_address($new_row['field_site_email'])) {
		$node->field_site_email[$node->language][0]['email'] = $new_row['field_site_email'];
	}
	if(valid_url($new_row['field_website'], true)) {
		$node->field_website[$node->language][0]['url'] = $new_row['field_website'];
	}
	node_save($node);
	$context['message'] = t('Now processing %node', array('%node' => $new_row['title']));
}

function s4_sites_import_batch_finished($success, $results, $operations) {
  if ($success) {
    // Here we do something meaningful with the results.
    $message = count($results) .' processed.';
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