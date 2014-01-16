SELECT COUNT(*) as total
FROM field_data_field_coordinator s

--IF=:placements_term
	LEFT JOIN field_data_field_course c
		ON c.entity_id = s.entity_id AND c.entity_type = s.entity_type
	LEFT JOIN field_data_field_term t
		ON t.entity_id = c.field_course_nid 
--END

--IF=:placements_program
	LEFT JOIN field_data_field_site_restrict p
		ON p.entity_id = s.entity_id AND p.entity_type = s.entity_type
--END

--IF=:placements_start
	LEFT JOIN field_data_field_signup_start_date sd
		ON sd.entity_id = s.entity_id AND sd.entity_type = s.entity_type
--END

	WHERE field_coordinator_nid = n.nid

--IF=:placements_term
	AND t.field_term_nid IN (:placements_term)
--END

--IF=:placements_program
	AND p.field_site_restrict_tid IN (:placements_program)
--END

--IF=:placements_start
	AND sd.field_signup_start_date_value > :placements_start
--END

--IF=:placements_end
	AND sd.field_signup_start_date_value < :placements_end
--END