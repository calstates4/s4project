<?php

class views_handler_s4_faculty_site_select extends views_handler_field {

	function render($values) {
		$node = menu_get_object();
		$exists = false;
		if(!$sites = field_get_items('node', $values->_field_data['nid']['entity'], 'field_sites')) {
			$sites = array();
		}
		foreach($sites as $site) {
			if(isset($site['nid']) && $site['nid'] == $node->nid) {
				$exists = true;
			}
		}
		if($exists) {
			return '<div class="signup remove course"><div class="icon"></div>' .
				l('Remove from '. $values->node_title, 's4/course-list/remove/'. $values->nid .'/'. $node->nid)
				. '</div>';
		} else {
			return '<div class="signup add course"><div class="icon"></div>' .
				l('Add to '. $values->node_title, 's4/course-list/add/'. $values->nid .'/'. $node->nid)
				. '</div>';
		}
		
	}
	
	function query() {
		
	}
}