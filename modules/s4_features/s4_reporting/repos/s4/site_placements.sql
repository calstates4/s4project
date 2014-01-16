SELECT td.name, count(*) as total
FROM field_data_field_site s
LEFT JOIN field_data_field_site_restrict p
		ON p.entity_id = s.entity_id AND p.entity_type = s.entity_type
LEFT JOIN taxonomy_term_data td ON p.field_site_restrict_tid = td.tid
LEFT JOIN field_data_field_course c
	ON c.entity_id = s.entity_id AND c.entity_type = s.entity_type
--IF=:placements_term
	LEFT JOIN field_data_field_term t
		ON t.entity_id = c.field_course_nid 
--END

--IF=:course_subject
LEFT JOIN field_data_field_course_subject cs
	ON cs.entity_id = c.field_course_nid AND cs.entity_type = 'node'
--END

--IF=:placements_start
	LEFT JOIN field_data_field_signup_start_date sd
		ON sd.entity_id = s.entity_id AND sd.entity_type = s.entity_type
--END

	WHERE s.field_site_nid = :nid

--IF=:course_subject
  AND cs.field_course_subject_value IN (:course_subject)
--END

--IF=:placements_term
	AND t.field_term_nid IN (:placements_term)
--END

--IF=:placements_start
	AND sd.field_signup_start_date_value > :placements_start
--END

--IF=:placements_end
	AND sd.field_signup_start_date_value < :placements_end
--END

GROUP BY p.field_site_restrict_tid
