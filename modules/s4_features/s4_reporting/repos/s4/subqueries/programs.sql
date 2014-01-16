SELECT GROUP_CONCAT(t.name, ', ')
	FROM field_data_field_site_restrict program
	LEFT JOIN taxonomy_term_data t ON t.tid = program.field_site_restrict_tid
	WHERE program.entity_id = n.nid AND program.revision_id = n.vid AND program.entity_type = 'node'
	GROUP BY n.nid