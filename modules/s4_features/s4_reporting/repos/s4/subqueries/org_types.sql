SELECT GROUP_CONCAT(t.name, ', ')
	FROM field_data_field_csu_org_type org
	LEFT JOIN taxonomy_term_data t ON t.tid = org.field_csu_org_type_tid
	WHERE org.entity_id = n.nid AND org.revision_id = n.vid AND org.entity_type = 'node'
	GROUP BY n.nid
	