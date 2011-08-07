<?php

function s4_reporting_block_site_summary() {
	$workflow_status = false;
	foreach(taxonomy_get_vocabularies() as $vid => $vocabulary) {
		if($vocabulary->machine_name == 'workflow_status') {
			$workflow_status = taxonomy_get_tree($vid);
		}
	}
	
	$items = array();
	$published = false;
	foreach($workflow_status as $status) {
		$query = db_select('field_data_field_workflow_status', 'f');
		$query->condition('f.field_workflow_status_tid', $status->tid)
			  ->condition('f.entity_type', 'node')
		      ->addExpression('COUNT(entity_id)', 'entity_count');
		$result = $query->execute();
		$count = $result->fetchField();
		if(variable_get('s4_sites_workflow_'. $status->tid, 'none') == 'publish' && !$published) {
			$query = db_select('node', 'n');
			$query->condition('n.type', 'site')
				  ->condition('n.status', 1)
			      ->addExpression('COUNT(nid)', 'node_count');
			$result = $query->execute();
			$published_count = $result->fetchField();
			$count += $published_count;
			$published = true;
		}
		$items[$status->tid] = '<strong>'. $status->name .':</strong> '. $count;
	}
	
	
	
	return array('subject' => 'Site overview',
				 'content' => theme('item_list', array('items' => $items)));
}