SELECT GROUP_CONCAT(total) FROM (
SELECT CONCAT(pbp_td.name, ': ', count(*)) as total
FROM field_data_field_site pbp_s
LEFT JOIN field_data_field_site_restrict pbp_p
		ON pbp_pentity_id = pbp_s.entity_id AND pbp_pentity_type = pbp_s.entity_type
LEFT JOIN taxonomy_term_data pbp_td ON pbp_p.field_site_restrict_tid = pbp_td.tid
--IF=:placements_term
	LEFT JOIN field_data_field_course pbp_c
		ON pbp_c.entity_id = pbp_s.entity_id AND pbp_c.entity_type = pbp_s.entity_type
	LEFT JOIN field_data_field_term pbp_t
		ON pbp_t.entity_id = pbp_c.field_course_nid 
--END

--IF=:placements_start
	LEFT JOIN field_data_field_signup_start_date pbp_sd
		ON pbp_sd.entity_id = pbp_s.entity_id AND pbp_sd.entity_type = pbp_s.entity_type
--END

	WHERE pbp_s.field_site_nid = n.nid

--IF=:placements_term
	AND pbp_t.field_term_nid IN (:placements_term)
--END

--IF=:placements_start
	AND pbp_sd.field_signup_start_date_value > :placements_start
--END

--IF=:placements_end
	AND pbp_sd.field_signup_start_date_value < :placements_end
--END

GROUP BY pbp_p.field_site_restrict_tid
)