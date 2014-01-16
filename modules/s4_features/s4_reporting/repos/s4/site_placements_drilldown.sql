SELECT DISTINCT s.entity_id, users.uid, users.name, 
fname.field_first_name_value, lname.field_last_name_value,
c.field_course_nid as course_id,
cs.field_course_subject_value, cnum.field_course_catalog_number_value,
csection.field_course_section_value, staff_node.nid as staff_id,
staff_node.title as staff,
site_node.nid as site_id, site_node.title as site_title
FROM field_data_field_site s
LEFT JOIN node n
	ON n.nid = s.entity_id AND s.entity_type = 'node'
LEFT JOIN field_data_field_site_restrict p
		ON p.entity_id = s.entity_id AND p.entity_type = s.entity_type
LEFT JOIN taxonomy_term_data td
	ON p.field_site_restrict_tid = td.tid
LEFT JOIN field_data_field_course c
	ON c.entity_id = s.entity_id AND c.entity_type = s.entity_type
LEFT JOIN field_data_field_term t
	ON t.entity_id = c.field_course_nid 
LEFT JOIN field_data_field_signup_start_date sd
	ON sd.entity_id = s.entity_id AND sd.entity_type = s.entity_type
LEFT JOIN field_data_field_user u
	ON u.entity_id = s.entity_id AND u.entity_type = s.entity_type
LEFT JOIN users
	ON users.uid = u.field_user_uid
LEFT JOIN field_data_field_first_name fname
	ON fname.entity_id = users.uid AND fname.entity_type = 'user'
LEFT JOIN field_data_field_last_name lname
	ON lname.entity_id = users.uid AND lname.entity_type = 'user'
LEFT JOIN field_data_field_sis_id sis_id
	ON sis_id.entity_id = users.uid AND sis_id.entity_type = 'user'
LEFT JOIN field_data_field_course_subject cs
	ON cs.entity_id = c.field_course_nid AND cs.entity_type = 'node'
LEFT JOIN field_data_field_course_catalog_number cnum
	ON cnum.entity_id = c.field_course_nid AND cnum.entity_type = 'node'
LEFT JOIN field_data_field_course_section csection
	ON csection.entity_id = c.field_course_nid AND csection.entity_type = 'node'
LEFT JOIN field_data_field_coordinator staff
  ON staff.entity_id = s.entity_id AND staff.entity_type = s.entity_type
LEFT JOIN node staff_node
  ON staff_node.nid = staff.field_coordinator_nid
LEFT JOIN node site_node
  ON site_node.nid = s.field_site_nid

WHERE n.type = 'signup'

--IF=:nid
AND s.field_site_nid = :nid
--END

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
