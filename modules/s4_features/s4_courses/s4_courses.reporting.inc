<?php

function _s4_courses_reporting_general($report_criteria) {
  $totals = array('sections' => array('count' => 0,
                         'title' => t('Sections')),
            'total-courses' => array('count' => 0,
                         'title' => t('Courses')),
            'ud-courses' => array('count' => 0,
                         'title' => t('Upper-division sections')),
            'ld-courses' => array('count' => 0,
                         'title' => t('Lower-division sections')),
            'students' => array('count' => 0,
                         'title' => t('Students')),
            'placements' => array('count' => 0,
                         'title' => t('Placements')),
            'hours' => array('count' => 0,
                      'title' => t('Service hours')),
          );
  $courses = array();
  $course_query = db_select('node', 'n')
                    ->condition('n.type', 'course')
                    ->fields('n', array('nid'));
  $course_query->leftJoin('field_data_field_term', 't', 't.entity_type = :node AND t.entity_id = n.nid', array(':node' => 'node'));
  if($report_criteria['term']) {
    $course_query->condition('t.field_term_nid', $report_criteria['term']->nid);
  }
  else {
    // @todo also add case for time
  }
  $course_query->leftJoin('field_data_field_course_catalog_number', 'num', 'num.entity_type = :node AND num.entity_id = n.nid', array(':node' => 'node'));
  $course_query->fields('num', array('field_course_catalog_number_value'));
  $course_query->leftJoin('field_data_field_course_subject', 's', 's.entity_type = :node AND s.entity_id = n.nid', array(':node' => 'node'));
  $course_query->fields('s', array('field_course_subject_value'));
  $course_query->leftJoin('field_data_field_course_section', 'sect', 'sect.entity_type = s.entity_type AND sect.entity_id = n.nid');
  $course_query->fields('sect', array('field_course_section_value'));
  $course_query->distinct();
  $course_query->orderBy('s.field_course_subject_value')
               ->orderBy('num.field_course_catalog_number_value')
               ->orderBy('sect.field_course_section_value');
  $course_query->distinct();
  $course_result = $course_query->execute()->fetchAll();
  $courses = array();
  foreach($course_result as $course) {
		$totals['sections']['count']++;
		$courses[$course->field_course_subject_value .'-'. $course->field_course_catalog_number_value] = 1;
		if(intval(substr(trim($course->field_course_catalog_number_value), 0, 1)) > 2) {
			$totals['ud-courses']['count']++;
		}
		else {
			$totals['ld-courses']['count']++;
		}
		$query = db_select('field_data_field_course', 'c')
                    ->condition('c.entity_type', 'node')
                    ->condition('c.bundle', 'signup')
                    ->condition('c.deleted', 0)
                    ->condition('c.field_course_nid',  $course->nid)
                    ->fields('c', array('entity_id'));
    $query->leftJoin('field_data_field_signup_hours', 'h', 'h.entity_type = c.entity_type AND h.entity_id = c.entity_id');
    $query->fields('h', array('field_signup_hours_value'));
    $placements = $query->execute()->fetchAll();
    foreach($placements as $placement) {
    	$totals['placements']['count']++;
    	$totals['hours']['count'] += $placement->field_signup_hours_value;
    }
	  $students = db_select('field_data_field_course_students', 'c')
                    ->condition('entity_type', 'node')
                    ->condition('bundle', 'course')
                    ->condition('deleted', 0)
                    ->condition('entity_id',  $course->nid)
                    ->fields('c', array('field_course_students_uid'))
                    ->countQuery()
                    ->execute()
                    ->fetchField();
     if($students) {
     	  $totals['students']['count'] += $students;
     }
  }
  $totals['total-courses']['count'] = count($courses);
    
  return array('totals' => $totals,
       'output' => array(),
      );
}


function _s4_courses_reporting_course_summary($report_criteria) {
  $output = '';
  $course_query = db_select('node', 'n')
                    ->condition('n.type', 'course')
                    ->fields('n', array('nid'));
  $course_query->leftJoin('field_data_field_term', 't', 't.entity_type = :node AND t.entity_id = n.nid', array(':node' => 'node'));
  if($report_criteria['term']) {
    $course_query->condition('t.field_term_nid', $report_criteria['term']->nid);
  }
  else {
    // @todo also add case for time
  }
  $course_query->leftJoin('field_data_field_course_catalog_number', 'num', 'num.entity_type = :node AND num.entity_id = n.nid', array(':node' => 'node'));
  $course_query->fields('num', array('field_course_catalog_number_value'));
  $course_query->leftJoin('field_data_field_course_subject', 's', 's.entity_type = :node AND s.entity_id = n.nid', array(':node' => 'node'));
  $course_query->fields('s', array('field_course_subject_value'));
  $course_query->leftJoin('field_data_field_course_section', 'sect', 'sect.entity_type = s.entity_type AND sect.entity_id = n.nid');
  $course_query->fields('sect', array('field_course_section_value'));
  $course_query->distinct();
  $course_query->orderBy('s.field_course_subject_value')
               ->orderBy('num.field_course_catalog_number_value')
               ->orderBy('sect.field_course_section_value');
  $course_query->distinct();
  $course_result = $course_query->execute()->fetchAll();
  $discipline_header = array(t('Discipline'),
                  t('# Registered'),
                  t('# Placed'),
                  t('% Placed'),
                  t('Hours'),
                  t('Evaluations'),
                  t('% Evaluations'),
                  );
  
  $site_discipline_header = array(t('Site'),
                          t('City'),
                          t('# Placed'),
                          t('Discipline'),
                          );
  
  $course_header = array(t('Course'),
                          t('# Registered'),
                          t('# Placed'),
                          t('% Placed'),
                          t('Hours'),
                          t('Evaluations'),
                          t('% Evaluations'),
                          );
  $site_discipline_rows = array();         
  $discipline_rows = array();
  $course_rows = array();
  foreach($course_result as $course) {
    if(!isset($discipline_rows[$course->field_course_subject_value])) {
      $discipline_rows[$course->field_course_subject_value] = array($course->field_course_subject_value,
                    0,
                    0,
                    0,
                    0,
                    0,
                    0);
    }
    $course_rows[$course->nid] = array($course->field_course_subject_value .' '. $course->field_course_catalog_number_value .' - '. $course->field_course_section_value,
                    0,
                    0,
                    0,
                    0,
                    0,
                    0);
    $course_query = db_select('field_data_field_course', 'c')
			               ->condition('c.entity_type', 'node')
			               ->condition('c.bundle', 'signup')
			               ->condition('c.field_course_nid', $course->nid);
		$course_query->leftJoin('field_data_field_signup_hours', 'h', 'h.entity_type = c.entity_type AND h.entity_id = c.entity_id');
		$course_query->fields('h', array('field_signup_hours_value'));
		$course_query->leftJoin('field_data_field_site', 's', 's.entity_type = c.entity_type AND s.entity_id = c.entity_id');
		$course_query->fields('s', array('field_site_nid'));
		$course_query->leftJoin('field_data_field_form_evaluation_sid', 'e', 'e.entity_type = c.entity_type AND e.entity_id = c.entity_id');
		$course_query->fields('e', array('field_form_evaluation_sid_value'));
		$signups = $course_query->execute()->fetchAll();
		$enrollment = db_select('field_data_field_course_students', 's')
		                    ->condition('s.entity_type', 'node')
		                    ->condition('s.bundle', 'course')
		                    ->condition('s.entity_id', $course->nid)
		                    ->fields('s', array('field_course_students_uid'))
		                    ->countQuery()
		                    ->execute()
		                    ->fetchField();

		$discipline_rows[$course->field_course_subject_value][1] += $enrollment;
		$course_rows[$course->nid][1] = $enrollment;
		foreach($signups as $signup) {
			if(!isset($site_discipline_rows[$signup->field_site_nid])) {
				$query = db_select('node', 'n')
									 ->condition('nid', $signup->field_site_nid);
			  $query->leftJoin('field_data_field_location', 'fl', 'fl.entity_id = n.nid AND fl.bundle = :site', array(':site' => 'site'));
			  $query->leftJoin('location', 'l', 'l.lid = fl.field_location_lid');
			  $query->fields('l', array('city', 'province'));
				$query->fields('n', array('title'));
				$site = $query->execute()
									    ->fetchAssoc();
				$site_discipline_rows[$signup->field_site_nid] = array($site['title'], $site['city'], 1, array());
			}
			else {
				$site_discipline_rows[$signup->field_site_nid][2]++;
				$site_discipline_rows[$signup->field_site_nid][3][$course->field_course_subject_value] = $course->field_course_subject_value;
			}
			$discipline_rows[$course->field_course_subject_value][2]++;
  		$course_rows[$course->nid][2]++;
  		$discipline_rows[$course->field_course_subject_value][4] += $signup->field_signup_hours_value;
  		$course_rows[$course->nid][4] += $signup->field_signup_hours_value;
  		if($signup->field_form_evaluation_sid_value) {
    		$discipline_rows[$course->field_course_subject_value][5]++;
    		$course_rows[$course->nid][5]++;
      }
		}
  }
  foreach($course_rows as &$row) {
    $row[3] = round((($row[2] / $row[1]) * 100), 1) .'%';
    $row[6] = round((($row[5] / $row[2]) * 100), 1) .'%';
  }
  foreach($discipline_rows as &$row) {
    $row[3] = round((($row[2] / $row[1]) * 100), 1) .'%';
    $row[6] = round((($row[5] / $row[2]) * 100), 1) .'%';
  }
  foreach($site_discipline_rows as $r => &$row) {
  	$row[3] = implode(', ', $row[3]);
  }
  
  $output['discipline'] = array(
    '#type' => 'fieldset',
    '#title' => t('Course discipline'),
    '#collapsible' => TRUE,
    '#collapsed' => TRUE,
  );
  
  $output['discipline']['table'] = array(
    '#markup' => theme('table', array('header' => $discipline_header, 'rows' => $discipline_rows)),
  );
  
  $output['courses'] = array(
    '#type' => 'fieldset',
    '#title' => t('Courses'),
    '#collapsible' => TRUE,
    '#collapsed' => TRUE,
  );
  
  $output['courses']['table'] = array(
    '#markup' => theme('table', array('header' => $course_header, 'rows' => $course_rows)),
  );
  
  $output['sites_discipline'] = array(
    '#type' => 'fieldset',
    '#title' => t('Sites by discipline and placements'),
    '#collapsible' => TRUE,
    '#collapsed' => TRUE,
  );
  
  $output['sites_discipline']['table'] = array(
    '#markup' => theme('table', array('header' => $site_discipline_header, 'rows' => $site_discipline_rows)),
  );
  
  return array('totals' => $totals,
         'output' => $output,
        );
}