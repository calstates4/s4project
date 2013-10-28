<?php

function s4_reporting_block_site_summary() {
	$states = workbench_moderation_states();
	$items = array();
	foreach($states as $state) {
		$query = db_select('workbench_moderation_node_history', 'h');
		$query->leftJoin('node', 'n', 'n.nid = h.nid AND n.vid = h.vid');
		$query->condition('h.state', $state->name)
			    ->condition('n.status', 1)
			    ->condition('h.current', 1)
			    ->condition('n.type', 'site')
		      	->addExpression('COUNT(h.nid)', 'entity_count');
		$result = $query->execute();
		$count = $result->fetchField();
		$items[$state->name] = array('<strong>'. $state->label .':</strong>',
		  l($count, 'site-list/manage/', array('query' => array('status' => $state->name, 'state' => 1)))
		  );
	}
	$header = array(t('Status'), t('Count'));
	$count = db_select('node', 'n')
	           ->condition('status', 0)
	           ->condition('type', 'site')
	           ->countQuery()
	           ->execute()
	           ->fetchField();
  
  $items[] = array(array('header' => TRUE,
                         'data' => t('Inactive sites')
                         ),
                   array('header' => TRUE,
                         'data' => t('Count')
                         )
                    );
  $items[] = array('<strong>' . t('Inactive sites:') .'</strong>',
                   l($count, 'site-list/manage/', array('query' => array('state' => 0)))
                   );
	return array('subject' => t('Site overview'),
				 'content' => theme('table', array('header' => $header, 'rows' => $items,
				 									  'attributes' => array('class' => array('table-bordered')))));
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
	foreach(taxonomy_get_vocabularies() as $vocabulary) {
    if($vocabulary->machine_name == 'site_restrictions') {
    	$program_vocabulary = $vocabulary;
    	continue;
    }
  }
	foreach($terms as $term) {
		$nid = db_select('field_data_field_term_code', 'c')
				 ->condition('field_term_code_value', $term)
				 ->fields('c', array('entity_id'))
				 ->execute()
				 ->fetchField();
		$term = node_load($nid);

		$output .= t('<h4>@title</h4>', array('@title' => $term->title ));
		foreach(taxonomy_get_tree($program_vocabulary->vid) as $program) {
			$items = array();
		  $output .= t('<h5>@title</h5>', array('@title' => $program->name));
			$query = db_select('field_data_field_term', 't');
			$query->condition('t.entity_type', 'node')
					  ->condition('t.field_term_nid', $term->nid)
				    ->fields('t', array('entity_id'))
				    ->distinct();
			$query->leftJoin('field_data_field_site_restrict', 'r', 'r.entity_id = t.entity_id AND r.entity_type = t.entity_type');
			$query->condition('r.field_site_restrict_tid', $program->tid);
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

			$items[] = t('<strong>Sections: </strong> @total', array('@total' => $total)); 
			$items[] = t('<strong>Enrollments: </strong> @students', array('@students' => $students));
			if ($students) {
				//Preventing division by zero error
				$items[] = t('<strong>Total placements: </strong> @placements', array('@placements' => $signups)) . ' (' . round(($signups / $students) * 100, 2) .'%)';
			}
			$output .= theme('item_list', array('items' => $items));
		}
	}
	$result =  array('subject' => 'Course overview',
				 'content' => $output);
	cache_set('s4_erporting_courses', $result, 'cache', time() + (3 * 60));
	return $result;
}

function s4_reporting_block_frontpage_demographics() {
  $field = field_info_field('field_site_demographics');
  $settings = unserialize($field['settings']['settings']);
  $totals = db_query('select field_site_demographics_row, avg(field_site_demographics_value) from field_data_field_site_demographics group by field_site_demographics_row');
}