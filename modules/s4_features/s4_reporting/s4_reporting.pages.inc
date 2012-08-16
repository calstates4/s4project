<?php


function s4_reporting_term_report($form, &$form_state) {
	drupal_add_css(drupal_get_path('module', 's4_reporting') .'/css/s4_reporting.summary.css');
	drupal_add_js(drupal_get_path('module', 's4_reporting') .'/js/s4_reporting.summary.js');
	$programs = array();
  foreach(taxonomy_get_vocabularies() as $vocabulary) {
    if($vocabulary->machine_name == 'site_restrictions') {
      foreach(taxonomy_get_tree($vocabulary->vid) as $term) {
        $programs[$term->tid] = $term->name;
      }
    }
  }
  
  $form['#attributes'] = array('class' => array('summary-report'));
  	
	$form['program'] = array(
	 '#type' => 'select',
	 '#title' => t('Program'),
	 '#options' => $programs,
	 '#multiple' => TRUE,
	 '#required' => TRUE,
	);
	
  $form['term'] = array(
		'#type' => 'fieldset',
		'#title' => 'Report by term',
	);
	
	$terms = array();
	$query = db_select('node', 'n')
	         ->fields('n', array('nid', 'title'))
	         ->condition('n.status', 1)
	         ->condition('n.type', 'course_term');
	$results = $query->execute()->fetchAll();
	foreach($results as $result) {
		$terms[$result->nid] = $result->title;
	}

	$form['term']['report_term'] = array(
		'#type' => 'select',
		'#title' => 'Report on a single term',
		'#options' => $terms,
		'#attributes' => array('class' => array('chosen'),
							   'style' => 'width: 25%;'),
		'#default_value' => $form_state['storage']['values']['report_term'],
	);
	
	$form['dates'] = array(
		'#type' => 'fieldset',
		'#title' => 'Report by date',
		'#collapsible' => true,
		'#collapsed' => ($form_state['storage']['values']['date_enabled']) ? false : true ,
	);
	
	$form['dates']['date_enabled'] = array(
		'#type' => 'checkbox',
		'#title' => 'Ignore terms and run report for a period of time',
		'#default_value' => $form_state['storage']['values']['date_enabled'],
	);
	
	$form['dates']['date_start'] = array(
		'#type' => 'date',
		'#title' => 'Start date',
		'#default_value' => $form_state['storage']['values']['date_start'],
	);
	
	$form['dates']['date_end'] = array(
		'#type' => 'date',
		'#title' => 'End date',
		'#default_value' => $form_state['storage']['values']['date_end'],
	);
	
	$form['submit'] = array(
		'#type' => 'submit',
		'#value' => 'Run report',
	);
	
	if ($form_state['storage']['results']) {
		$form += $form_state['storage']['results'];
	}
	
	return $form;
}

function s4_reporting_term_report_validate(&$form, $form_state) {
	if ($form_state['values']['date_enabled']) {
		$start = $form_state['values']['date_start'];
		$end = $form_state['values']['date_end'];
		if (mktime(0, 0, 0, $start['month'], $start['day'], $start['year']) >=
		   mktime(0, 0, 0, $end['month'], $end['day'], $end['year'])) {
		   	form_set_error('date_start', t('The start date must be earlier than the end date.'));
		   }
	}
	else {
		if (!count($form_state['values']['report_term'])) {
			form_set_error('report_term', t('You must select at least one term if you are not running this report using dates.'));
		}
	}
}

function s4_reporting_term_report_submit($form, &$form_state) {
	$report_items = array();
	if ($form_state['values']['date_enabled']) {
		$start = $form_state['values']['date_start'];
		$end = $form_state['values']['date_end'];

		$report_items = array('start' => date('Y-m-d', mktime(0, 0, 0, $start['month'], $start['day'], $start['year'])), 
						 	  'end' => date('Y-m-d', mktime(0, 0, 0, $end['month'], $end['day'], $end['year'])),
						 	  'term' => false);
	}
	else {
		$term = node_load($form_state['values']['report_term']);
		$dates = field_get_items('node', $term, 'field_term_date_start');
		$report_items = array('start' => $dates[0]['value'],
							  'end' => $dates[0]['value2'],
							  'term' => $term);
	}
	$report_items['program'] = $form_state['values']['program'];
	
	$output = array();
	$result = module_invoke_all('s4_reporting_term_report', $report_items);
	foreach($result['totals'] as $t => $total) {
		$output['totals'][$t] = array(
			array('header' => TRUE, 'data' => $total['title']),
			$total['count']
		);
		
	}
	$output += $result['output'];
	$header = array(t('Item'), t('Totals'));
	$output['totals'] = array(
		'#markup' => theme('table', array('header' => $header, 'rows' => $output['totals']))
		);	
	$form_state['rebuild'] = TRUE;
	$form_state['storage']['values'] = $form_state['values'];
	$form_state['storage']['results'] = $output;
}


function s4_reporting_object_report($node, $type = 'signup') {
	module_load_include('inc', 'webform', 'includes/webform.report');
	if ($node->type == 'site') {
		if ($type == 'signup') {
			$form = field_get_items('node', $node, 'field_site_form');
			$form = node_load($form[0]['nid']);
		}
		if ($type == 'evaluation') {
			$form = field_get_items('node', $node, 'field_site_eval_form');
			$form = node_load($form[0]['nid']);
		}
		$sids = _s4_reporting_get_site_sids($node, $type);
		if (!count($sids)) {
			return t('<div class="empty"><h3>No @type results yet.</h3></div>', array('@type' => $type));
		}
		return webform_results_analysis($form, $sids);
	}
	if ($node->type == 'course') {
		$forms = array();
		$sids = _s4_reporting_get_course_sids($node, $type);
		if (!is_array($sids) || !count($sids)) {
			return t('<div class="empty"><h3>No @type results yet.</h3></div>', array('@type' => $type));
		}
		foreach($sids as $form => $sids) {
			$form = node_load($form);
			$output .= t('<h3>@form</h3>', array('@form' => $form->title));
			if (count($sids)) {
				$output .= webform_results_analysis($form, $sids);
			}
			else {
				$output .= t('<div class="empty"><h3>No @type results yet.</h3></div>', array('@type' => $type));
			}
		}
		return $output;
	}
}

function _s4_reporting_get_course_sids($node, $type = 'signup') {
	$query = db_select('field_data_field_course', 'c')
			 ->condition('c.entity_type', 'node')
			 ->condition('c.field_course_nid', $node->nid);
	$query->leftJoin('field_data_field_site', 'site', 'c.entity_id = site.entity_id AND site.entity_type = :node', array(':node' => 'node'));
	if ($type == 'signup') {
		$query->leftJoin('field_data_field_site_form', 'form', 'form.entity_id = site.field_site_nid AND form.entity_type = :node', array(':node' => 'node'));
		$query->addField('form', 'field_site_form_nid', 'form');
		$query->leftJoin('field_data_field_form_signup_sid', 'sid', 'sid.entity_id = c.entity_id AND sid.entity_type = :node', array(':node' => 'node'));
		$query->addField('sid', 'field_form_signup_sid_value', 'sid');
	}
	if ($type == 'evaluation') {
		$query->leftJoin('field_data_field_site_eval_form', 'form', 'form.entity_id = site.field_site_nid AND form.entity_type = :node', array(':node' => 'node'));
		$query->addField('form', 'field_site_eval_form_nid', 'form');
		$query->leftJoin('field_data_field_form_evaluation_sid', 'sid', 'sid.entity_id = c.entity_id AND sid.entity_type = :node', array(':node' => 'node'));
		$query->addField('sid', 'field_form_evaluation_sid_value', 'sid');
	}
	$sids = array();
	$result = $query->execute();
	while($row = $result->fetchAssoc()) {
		if ($row['sid']) {
			$sids[$row['form']][] = $row['sid'];
		}
	}
	return $sids;
}

function _s4_reporting_get_site_sids($node, $type = 'signup') {
	$query = db_select('field_data_field_site', 's')
			 ->condition('s.entity_type', 'node')
			 ->condition('s.field_site_nid', $node->nid);
	if ($type == 'signup') {
		$query->leftJoin('field_data_field_form_signup_sid', 'sid', 'sid.entity_id = s.entity_id AND sid.entity_type = :node', array(':node' => 'node'));
		$query->fields('sid', array('field_form_signup_sid_value'));
	}
	if ($type == 'evaluation') {
		$query->leftJoin('field_data_field_form_evaluation_sid', 'sid', 'sid.entity_id = s.entity_id AND sid.entity_type = :node', array(':node' => 'node'));
		$query->fields('sid', array('field_form_evaluation_sid_value'));
	}
	$sids = array();
	$result = $query->execute();
	while($sid = $result->fetchField()) {
		$sids[$sid] = $sid;
	}
	return $sids;
}

function s4_reporting_view_form_report($report_key) {
	module_load_include('inc', 'webform', 'includes/webform.report');
  $data = _s4_reporting_load_form_report($report_key);
  $form = node_load($data['options']['webform']);
  return webform_results_analysis($form, $data['submissions']);
}

function s4_reporting_view_form_report_form($form, $form_state, $report_key) {
  module_load_include('inc', 'webform', 'includes/webform.report');
  module_load_include('inc', 'webform', 'includes/webform.export');
  module_load_include('inc', 'webform', 'includes/webform.components');

  $form = array();
  
  $form['report_key'] = array(
    '#type' => 'hidden',
    '#value' => $report_key,
  );
  
  $form['format'] = array(
    '#type' => 'radios',
    '#title' => t('Export format'),
    '#options' => webform_export_list(),
    '#default_value' => variable_get('webform_export_format', 'delimited'),
  );

  $form['delimiter'] = array(
    '#type' => 'select',
    '#title' => t('Delimited text format'),
    '#description' => t('This is the delimiter used in the CSV/TSV file when downloading report results. Using tabs in the export is the most reliable method for preserving non-latin characters. You may want to change this to another character depending on the program with which you anticipate importing results.'),
    '#default_value' => variable_get('webform_csv_delimiter', '\t'),
    '#options' => array(
      ','  => t('Comma (,)'),
      '\t' => t('Tab (\t)'),
      ';'  => t('Semicolon (;)'),
      ':'  => t('Colon (:)'),
      '|'  => t('Pipe (|)'),
      '.'  => t('Period (.)'),
      ' '  => t('Space ( )'),
    ),
  );
  
  $form['submit'] = array(
    '#type' => 'submit',
    '#value' => t('Download report'),
  );
  
  return $form;
}

function s4_reporting_view_form_report_form_submit($form, $form_state) {
  module_load_include('inc', 'webform', 'includes/webform.report');
  module_load_include('inc', 'webform', 'includes/webform.export');
  module_load_include('inc', 'webform', 'includes/webform.components');
	$table = _s4_reporting_get_form_report_results($form_state['values']['report_key']);
  
  $options = array(
    'delimiter' => ($form_state['values']['delimiter'])
                      ? $form_state['values']['delimiter']
                      : variable_get('webform_csv_delimiter', '\t'),
    'select_keys' => 0,
    'select_format' => 'separate',
  );

  $exporter = webform_export_create_handler($form_state['values']['format'], $options);
  
  $file_name = drupal_tempnam('temporary://', 'form_report_');
  $handle = @fopen($file_name, 'w'); // The @ suppresses errors.
  $exporter->bof($handle);
  dpm($table);
  foreach($table['header'] as $k => $head) {
    if(is_array($head)) {
      $table['header'][$k] = check_plain($head['value']);
    }
  }

  $exporter->add_row($handle, $table['header']);
  foreach($table['rows'] as $row) {
    foreach($row as $r => $d) {
      $row[$r] = strip_tags(str_replace('<br>', "\n", $d));
    }
    $exporter->add_row($handle, $row);
  }
  $exporter->eof($handle);

  // Close the file.
  @fclose($handle);

  $export_name = _webform_safe_name($node->title);
  $exporter->set_headers($export_name);
  @readfile($file_name);  // The @ makes it silent.
  @unlink($file_name);  // Clean up, the @ makes it silent.
  exit();
}

function s4_reporting_view_form_title($report_key) {
  $data = _s4_reporting_load_form_report($report_key);
  $form = node_load($data['options']['webform']);
  return t('Report for @form', array('@form' => check_plain($form->title)));
}


function s4_reporting_view_form_report_responses($report_key) {
	$table = _s4_reporting_get_form_report_results($report_key);

  return theme('table', array('header' => $table['header'], 'rows' => $table['rows']));
}

function _s4_reporting_load_form_report($report_key) {
  $result = db_select('s4_reporting', 'r')
            ->fields('r', array('data'))
            ->condition('report_key', check_plain($report_key))
            ->execute()
            ->fetchField();
  $result = unserialize($result);
  return $result;
}

function _s4_reporting_get_form_report_results($report_key) {
  module_load_include('inc', 'webform', 'includes/webform.report');
	module_load_include('inc', 'webform', 'includes/webform.submissions');
  $data = _s4_reporting_load_form_report($report_key);
  $node = node_load($data['options']['webform']);
  if (isset($_GET['results']) && is_numeric($_GET['results'])) {
    $pager_count = $_GET['results'];
  }

  // Get all the submissions for the node.
  
  $header = theme('webform_results_table_header', array('node' => $node));
  $submissions = webform_get_submissions($node->nid, $header, $pager_count);
  // Generate a row for each submission.
  foreach ($submissions as $sid => $submission) {
    if($data['submissions'][$sid]) {
      $signup = node_load($data['signups'][$sid]);
      $student = field_get_items('node', $signup, 'field_user');
      $student = user_load($student[0]['uid']);
      $site = field_get_items('node', $signup, 'field_site');
      $site = node_load($site[0]['nid']);
      $last_name = field_get_items('user', $student, 'field_last_name');
      $first_name = field_get_items('user', $student, 'field_first_name');
      $site_staff = field_get_items('node', $signup, 'field_coordinator');
      $site_staff = node_load($site_staff[0]['nid']);
      $program = field_get_items('node', $signup, 'field_site_restrict');
      $program = taxonomy_term_load($program[0]['tid']);
      $course = field_get_items('node', $signup, 'field_course');
      $course = node_load($course[0]['nid']);
      $cell[] = t('@first_name @last_name', array('@first_name' => $first_name[0]['value'],
                                                  '@last_name'  => $last_name[0]['value']));
      $cell[] = l($site->title, 'node/'. $site->nid);
      $cell[] = ($site_staff) ? l($site_staff->title, 'node/'. $site_staff->nid) : t('none');
      $cell[] = ($program) ? $program->name : t('none');
      $cell[] = ($course) ? l($course->title, 'node/'. $course->nid) : t('none');
      $cell[] = format_date($submission->submitted, 'small');
      $component_headers = array();
  
      // Generate a cell for each component.
      foreach ($node->webform['components'] as $component) {
        $data = isset($submission->data[$component['cid']]['value']) ? $submission->data[$component['cid']]['value'] : NULL;
        $submission_output = webform_component_invoke($component['type'], 'table', $component, $data);
        if ($submission_output !== NULL) {
          $component_headers[] = check_plain($component['name']);
          $cell[] = $submission_output;
        }
      }
  
      $rows[] = $cell;
      unset($cell);
    }
  }
  if (!empty($component_headers)) {
    $header = array_merge($header, $component_headers);
  }
  $header = array_merge(array(t('Student'),
                              t('Site'),
                              t('Site staff'),
                              t('Program'),
                              t('Course'),
                              ), $header);
  foreach($header as $h => $head) {
    if(in_array($head['data'], array('#', t('IP Address'), t('User')))) {
      unset($header[$h]);
    }
  }
  if (count($rows) == 0) {
    $rows[] = array(array('data' => t('There are no submissions for this form. <a href="!url">View this form</a>.', array('!url' => url('node/' . $node->nid))), 'colspan' => 4));
  }
  return array('header' => $header, 'rows' => $rows);
}