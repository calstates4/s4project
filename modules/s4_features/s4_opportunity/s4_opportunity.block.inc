<?php

function s4_opportunity_create_form($form_state) {
	$form = array();
	$site = node_load(check_plain(arg(1)));
	$links = array();
	
	foreach (s4_opportunity_get_types() as $type) {
		if(user_access('administer opportunities') || user_access('edit any ' . $type->type .' s4_opportunity')) {
			$links[$type->type] = l(check_plain($type->label), 'opportunities/add/'. $type->type, array('query' => array('field_opportunity_sites' => $site->nid)));
		}
	}
	if(!count($links)) {
		return;
	}
	$output = '<div class="btn-group">';
  $output .= '<a class="btn btn-success dropdown-toggle" data-toggle="dropdown" href="#">
    <i class="icon-plus icon-white"></i> '. t('Add') .'
    <span class="caret"></span>
  </a>';

  $output .= theme('item_list', array('items' => $links, 'attributes' => array('class' => array('dropdown-menu'))));
      $output .= '</div>';

	return $output;
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
	$output .= l('Start', 'opportunities/create', array('attributes' => array('class' => array('btn', 'btn-primary', 'btn-large'))));
	$output .= '</p>';
	return $output;
}


function s4_opportunity_create_progress() {
  global $user;
  drupal_add_css(drupal_get_path('module', 's4_core') . '/css/status.css');
  $status = array();
  $create = $_SESSION['s4_opportunity_create'];
  if($create['type']) {
	  $type = s4_opportunity_type_load($create['type']);
	  $opportunity_label = $type->label;
	  $status['type'] = array('data'  => t('Type'),
	            'id'     => 'status-type',
	            'class'  => array('done'),
	            'href'  => null,
	            'selection' => '<div class="selection label label-info">' . $type->label .'</div>',
	            );
  }
  else {
  	$opportunity_label = t('Opportunity');
  	$status['type'] = array('data'  => t('Type'),
	            'id'     => 'status-type',
	            'class'  => array(),
	            'href'  => null,
	            );
  }

  if($create['site']) {
	  $site = node_load($create['site']);
	  $status['site'] = array('data'  => t('Site'),
	            'id'     => 'status-type',
	            'class'  => array('done'),
	            'href'  => null,
	            'selection' => '<div class="selection label label-info">' . $site->title .'</div>',
	            );
  }
  else {
  	$status['site'] = array('data'  => t('Site'),
	            'id'     => 'status-type',
	            'class'  => array(),
	            'href'  => null,
	            );
  }

  if($create['site_staff']) {
	  $site = node_load($create['site_staff']);
	  $status['site_staff'] = array('data'  => t('Site staff'),
	            'id'     => 'status-type',
	            'class'  => array('done'),
	            'href'  => null,
	            'selection' => '<div class="selection label label-info">' . $site->site_staff .'</div>',
	            );
  }
  else {
  	$status['site_staff'] = array('data'  => t('Site staff'),
	            'id'     => 'status-type',
	            'class'  => array(),
	            'href'  => null,
	            );
  }
  if($create['opportunity']) {
	  $opportunity = node_load($create['opportunity']);
	  $status['opportunity'] = array('data'  => $opportunity_label,
	            'id'     => 'status-type',
	            'class'  => array('done'),
	            'href'  => null,
	            'selection' => '<div class="selection label label-info">' . $opportunity->name .'</div>',
	            );
  }
  else {
  	$status['opportunity'] = array('data'  => $opportunity_label,
	            'id'     => 'status-type',
	            'class'  => array(),
	            'href'  => null,
	            );
  }
  $result = views_get_view_result('s4_opportunities_create', 'page_2', $user->uid);
  if(count($result)) {
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
	}
	else {
		if($create['course']) {
		  $course = node_load($create['course']);
		  $status['course'] = array('data'  => 'Course',
		            'id'     => 'status-type',
		            'class'  => array('done'),
		            'href'  => null,
		            'selection' => '<div class="selection label label-info">' . $course->name .'</div>',
		            );
	  }
	  else {
	  	$status['course'] = array('data'  => 'Course',
		            'id'     => 'status-type',
		            'class'  => array(),
		            'href'  => null,
		            );
	  }
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

function _s4_opportunity_block_placement_approval($placement) {
	$endpoints = field_get_items('relation', $placement, 'endpoints');
	$opportunity = s4_opportunity_load($endpoints[1]['entity_id']);
	$type = s4_opportunity_type_load($opportunity->type);
	if(!$type->data['faculty_approve'] && !$type->data['site_staff_approve'] && !$type->data['require_approval']) {
		return '<p class="lead">'. t('Approal not required.') .'</p>';
	}
	$approvals = s4_opportunity_get_placement_approvals($opportunity, $placement);

  $header = array(t('Type'), t('Name'), t('Status'), t('More'));
  $rows = array();
  $types = array('faculty_approve' => array('approve' => 'faculty',
  																		'type' => t('Faculty')),
  								'site_staff_approve' => array('approve' => 'site_staff',
  																		'type' => t('Site staff')),
  								'require_approval' => array('approve' => 'approver',
  																		'type' => t('Department')),
  				    );
	foreach($types as $type_name => $approval_type) {
	  if($type->data[$type_name]) {
	    if(!isset($approvals[$approval_type['approve']]) || !count($approvals[$approval_type['approve']])) {
	    	$rows[] = array($approval_type['type'], '', '<span class="label label-important">'. t('Not approved') .'</span>', '');
	    }
	    else {
	    	foreach($approvals[$approval_type['approve']] as $approval) {
		    	$label = field_get_items('relation', $approval, 'field_approved');
		    	$label = ($label[0]['value'])
		    		? '<span class="label label-success">'. t('Approved') .'</span>'
		    		: '<span class="label label-important">'. t('Denied') .'</span>';
	    		$endpoints = field_get_items('relation', $approval, 'endpoints');
	    		if($endpoints[0]['entity_type'] == 'user') {
	    			$user = user_load($endpoints[0]['entity_id']);
	    			$first_name = field_get_items('user', $user, 'field_first_name');
	    			$last_name = field_get_items('user', $user, 'field_last_name');
	    			$name = l($first_name[0]['value'] .' '. $last_name[0]['value'], 'user/' . $user->uid);
	    		}
	    		if($endpoints[0]['entity_type'] == 'node') {
	    			$node = node_load($endpoints[0]['entity_id']);
	    			$first_name = field_get_items('node', $node, 'field_first_name');
	    			$last_name = field_get_items('node', $node, 'field_last_name');
	    			$name = l($first_name[0]['value'] .' '. $last_name[0]['value'], 'node/' . $node->uid);
	    		}
	    		
	    		$rows[] = array($approval_type['type'],
	    							$name,
	    							$label,
	    							l(t('More'), 'relation/'. $approval->rid));
	    	}
	    }
	  }
	}
  return theme('table', array('header' => $header, 'rows' => $rows));
}

function _s4_opportunity_block_placement_form($placement) {
	$output = s4_webform_render_submission('field_form_signup_sid', $placement, 'relation');
	return $output['content'];
}