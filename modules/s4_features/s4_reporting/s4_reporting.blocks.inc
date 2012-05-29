<?php

function s4_reporting_block_site_summary() {
	$states = workbench_moderation_states();
	foreach($states as $state) {
		$query = db_select('workbench_moderation_node_history', 'h');
		$query->leftJoin('node', 'n', 'n.nid = h.nid');
		$query->condition('h.current', 1)
			    ->condition('h.state', $state->name)
			    ->condition('n.type', 'site')
		      	->addExpression('COUNT(h.nid)', 'entity_count');
		$result = $query->execute();
		$count = $result->fetchField();
		$items[$state->name] = '<strong>'. $state->label .':</strong> '. l($count, 'site-list/manage/', array('query' => array('status[]' => $state->name)));
	}

	return array('subject' => 'Site overview',
				 'content' => theme('item_list', array('items' => $items)));
}

function s4_reporting_block_course_summary() {
	if (!module_exists('s4_courses')) {
		return null;
	}
	if ($cache = cache_get('s4_erporting_courses')) {
		return $cache->data;
	}
	$terms = _s4_courses_get_current_terms();

	$output = '';
	foreach($terms as $term) {
		$items = array();
		$nid = db_select('field_data_field_term_code', 'c')
				 ->condition('field_term_code_value', $term)
				 ->fields('c', array('entity_id'))
				 ->execute()
				 ->fetchField();
		$term = node_load($nid);

		$output .= t('<h4>@title</h4>', array('@title' => $term->title ));

		$query = db_select('field_data_field_term', 't');
		$query->condition('entity_type', 'node')
				 ->condition('field_term_nid', $term->nid)
			     ->fields('t', array('entity_id'));
		$result = $query->execute();
		$total = 0;
		$signups = 0;
		$students = 0;
		while($course = $result->fetchField()) {
			$query = db_select('field_data_field_course', 'c')
					 ->condition('c.field_course_nid', $course);
			$query->addExpression('COUNT(c.entity_id)', 'entity_id');
			$result_signups = $query->execute();
			$signups += $result_signups->fetchField();

			$query = db_select('field_data_field_course_students', 's')
					 ->condition('s.entity_id', $course);
			$query->addExpression('COUNT(s.field_course_students_uid)', 'uid');
			$result_students = $query->execute();
			$students += $result_students->fetchField();

			$total++;
		}

		$items[] = '<strong>Courses: </strong>' .l($total, 'courses');
		$items[] = '<strong>Students: </strong>' .l($students, 'students');
		if ($students) {
			//Preventing division by zero error
			$items[] = '<strong>Total signups: </strong>' .l($signups, 'students') . ' (' . round(($signups / $students) * 100, 2) .'%)';
		}
		$output .= theme('item_list', array('items' => $items));
	}
	$result =  array('subject' => 'Course overview',
				 'content' => $output);
	cache_set('s4_erporting_courses', $result, 'cache', time() + (3 * 60));
	return $result;
}