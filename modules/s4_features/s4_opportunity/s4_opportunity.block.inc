<?php

function s4_opportunity_create_form($form_state) {
	$form = array();

	$options = array();

	foreach (s4_opportunity_get_types() as $type) {
		if(user_access('administer opportunities') || user_access('edit any ' . $type->type .' s4_opportunity')) {
			$options[$type->type] = check_plain($type->label);
		}
	}

	$site = node_load(arg(1));

	$form['site'] = array(
		'#type' => 'value',
		'#value' => $site->nid
		);

	$form['types'] = array(
		'#type' => 'select',
		'#title' => t('Select type of opportunity'),
		'#options' => $options,
		);

	$form['submit'] = array(
		'#type' => 'submit',
		'#value' => t('Create'),
		'#html' => TRUE,
		'#attributes' => array('class' => array('btn', 'btn-success'))
		);

	return $form;
}

function s4_opportunity_create_form_submit($form, $form_state) {
	drupal_goto('opportunities/add/' . $form_state['values']['types'], array('query' => array('field_opportunity_sites' => $form_state['values']['site'])));
}

function s4_opportunity_block_start() {
	$types = s4_opportunity_get_types();
	$type_list = array();
	foreach($types as $k => $type) {
		if(user_access('create any '. $type->type .' s4_opportunity')) {
			$type_list[] = $type->label;
		}
	}
	if(!count($type_list)) {
		return false;
	}
	$type_list = (count($type_list) == 1) ? $type_list[0] : implode(',', $type_list);
	$message = variable_get('s4_opportunity_begin_message', array('format' => FILTER_FORMAT_DEFAULT, 'value' => t('Start a new @types.', array('@types' => $type_list))));
	$output = check_markup($message['value'], $message['format']);
	$output .= '<p>';
	$output .= l('Start', 'opportunities/create', array('attributes' => array('class' => array('btn', 'btn-primary'))));
	$output .= '</p>';
	return $output;
}


function s4_opportunity_create_progress() {
  drupal_add_css(drupal_get_path('module', 's4_core') . '/css/status.css');
  $status = array();
  $create = $_SESSION['s4_opportunity_create'];
  if($create['type']) {
	  $type = s4_opportunity_type_load($create['type']);
	  $status['type'] = array('data'  => 'Type',
	            'id'     => 'status-type',
	            'class'  => array('done'),
	            'href'  => null,
	            'selection' => '<div class="selection label label-info">' . $type->label .'</div>',
	            );
  }
  else {
  	$status['type'] = array('data'  => 'Type',
	            'id'     => 'status-type',
	            'class'  => array(),
	            'href'  => null,
	            );
  }

  if($create['site']) {
	  $site = node_load($create['site']);
	  $status['site'] = array('data'  => 'Site',
	            'id'     => 'status-type',
	            'class'  => array('done'),
	            'href'  => null,
	            'selection' => '<div class="selection label label-info">' . $site->title .'</div>',
	            );
  }
  else {
  	$status['site'] = array('data'  => 'Site',
	            'id'     => 'status-type',
	            'class'  => array(),
	            'href'  => null,
	            );
  }

  if($create['site_staff']) {
	  $site = node_load($create['site_staff']);
	  $status['site_staff'] = array('data'  => 'Site staff',
	            'id'     => 'status-type',
	            'class'  => array('done'),
	            'href'  => null,
	            'selection' => '<div class="selection label label-info">' . $site->site_staff .'</div>',
	            );
  }
  else {
  	$status['site_staff'] = array('data'  => 'Site staff',
	            'id'     => 'status-type',
	            'class'  => array(),
	            'href'  => null,
	            );
  }

  if($create['opportunity']) {
	  $opportunity = node_load($create['opportunity']);
	  $status['opportunity'] = array('data'  => 'Opportunity',
	            'id'     => 'status-type',
	            'class'  => array('done'),
	            'href'  => null,
	            'selection' => '<div class="selection label label-info">' . $opportunity->name .'</div>',
	            );
  }
  else {
  	$status['opportunity'] = array('data'  => 'Opportunity',
	            'id'     => 'status-type',
	            'class'  => array(),
	            'href'  => null,
	            );
  }

  if($create['students']) {
	  $opportunity = node_load($create['opportunity']);
	  $status['students'] = array('data'  => 'Students',
	            'id'     => 'status-type',
	            'class'  => array('done'),
	            'href'  => null,
	            'selection' => '<div class="selection label label-info">' . $opportunity->name .'</div>',
	            );
  }
  else {
  	$status['students'] = array('data'  => 'Students',
	            'id'     => 'status-type',
	            'class'  => array(),
	            'href'  => null,
	            );
  }

  $number = 1;
  foreach ($status as $key => $stat) {
    $status[$key]['data'] = '<div class="arrow-body"><span class="number">' . ($number) . '</span>' . $stat['data'] . '</div>';
    if (isset($stat['href'])) {
      $status[$key]['data'] = l($status[$key]['data'], $stat['href'], array('html' => TRUE));
      $status[$key]['class'][] = 'clickable';
      unset($status[$key]['href']);
    }
    if (isset($stat['selection'])) {
      $status[$key]['data'] .= $stat['selection'];
      unset($status[$key]['selection']);
    }
    $status[$key]['class'][] = 'span' . floor(11 / count($status));
    $status[$key]['data'] .= '<span class="arrow"></span>';
    $number++;
  }
  $status[] = array('data' => '<div>Done!</div>',
            'class' => array('span1', 'complete', $finished));
  return theme('item_list', array('items' => $status, 'attributes' => array('class' => array('user-signup-status', 'row'))));

}