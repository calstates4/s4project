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
  $query = db_select('node_revision', 'r')
           ->fields('r', array('nid', 'status'));
  $query->leftJoin('field_data_field_term', 't', 't.entity_id = r.nid AND t.bundle = :course', array(':course' => 'course'));
  $query->fields('t', array('field_term_nid'));
  $query->leftJoin('field_data_field_site_restrict', 'p', 'p.entity_id = r.nid AND p.bundle = :course', array(':course' => 'course'));
  $query->condition('p.field_site_restrict_tid', $report_criteria['program']);
  if ($report_criteria['term']) {
    $query->condition('t.field_term_nid', $report_criteria['term']->nid);
  }
  else {
    $query->condition('r.timestamp', strtotime($report_criteria['start']), '>=')
        ->condition('r.timestamp', strtotime($report_criteria['end']), '<=');
  }
  $query->leftJoin('field_data_field_course_students', 's', 's.entity_id = r.nid AND s.bundle = :course', array(':course' => 'course'));
  $query->leftJoin('field_data_field_user', 'u', 's.field_course_students_uid = u.field_user_uid AND u.bundle = :signup', array(':signup' => 'signup'));
  $query->leftJoin('field_data_field_course', 'c', 'c.field_course_nid = r.nid AND c.bundle = :signup', array(':signup' => 'signup'));

  $query->leftJoin('field_data_field_course_catalog_number', 'cn', 'cn.entity_id = t.entity_id AND cn.bundle = t.bundle');
  $query->leftJoin('field_data_field_signup_hours', 'h', 'h.entity_id = c.entity_id AND h.bundle = c.bundle');
  $query->leftJoin('field_data_field_course_subject', 'su', 'su.entity_id = t.entity_id AND su.bundle = t.bundle');
  $query->fields('h', array('field_signup_hours_value'));
  $query->fields('cn', array('field_course_catalog_number_value'));
  $query->fields('su', array('field_course_subject_value'));
  $query->fields('c', array('entity_id'));
  $query->fields('s', array('field_course_students_uid'));
  $query->leftJoin('node', 'n', 'n.vid = r.vid');
  $query->condition('n.type', 'course');
  $results = $query->execute()->fetchAll();

  foreach($results as $result) {
    $total_courses[$result->field_course_subject_value . $reuslt->field_course_catalog_number_value] = $result->field_course_subject_value . $reuslt->field_course_catalog_number_value;
    $sections[$result->nid] = $result->nid;
    $students[$result->field_course_students_uid] = $result->field_course_students_uid;
    $signups[$result->entity_id] = $result->entity_id;
    if (intval(substr($result->field_course_catalog_number_value, 0, 1)) > 2) {
      $ud_courses[$result->nid] = $result->nid;
    }
    else {
      $ld_courses[$result->nid] = $result->nid;
    }
    $hours[$result->entity_id] = $result->field_signup_hours_value;
  };
  foreach($hours as $hour) {
    $totals['hours']['count'] += $hour;
  }
  $totals['students']['count'] = count($students);
  $totals['sections']['count'] = count($sections);
  $totals['total-courses']['count'] = count($total_courses);
  $totals['placements']['count'] = count($signups);
  $totals['ud-courses']['count'] = count($ud_courses);
  $totals['ld-courses']['count'] = count($ld_courses);
  
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
  
  $course_header = array(t('Course'),
                          t('# Registered'),
                          t('# Placed'),
                          t('% Placed'),
                          t('Hours'),
                          t('Evaluations'),
                          t('% Evaluations'),
                          );
                  
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
  
  return array('totals' => $totals,
         'output' => $output,
        );
}