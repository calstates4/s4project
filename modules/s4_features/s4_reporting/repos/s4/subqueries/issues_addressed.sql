SELECT GROUP_CONCAT(t.name, ', ')
	FROM field_data_field_csu_facility issues
	LEFT JOIN taxonomy_term_data t ON t.tid = issues.field_csu_facility_tid
	WHERE issues.entity_id = n.nid AND issues.revision_id = n.vid AND issues.entity_type = 'node'
	GROUP BY n.nid
	