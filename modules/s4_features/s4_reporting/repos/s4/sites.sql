--ACCESS=access s4 reporting
select DISTINCT n.nid, n.title, n.status, n.created, n.changed, n.uuid, wh.state, ws.label,
phone.field_phone_number, phone.field_phone_extension,
email.field_site_email_email,
website.field_website_url,
location.street, location.additional, location.city, location.province, location.postal_code,
district_federal.field_district_federal_value, state_upper.field_district_state_upper_value,
state_lower.field_district_state_lower_value, county.field_county_value,
(
--INCLUDE=subqueries/org_types
) as org_type,
(
--INCLUDE=subqueries/issues_addressed
) as issues_addressed,
	(
--INCLUDE=subqueries/programs
) as programs,
(
--INCLUDE=subqueries/total_placements
) as total_placements
FROM node n 
LEFT JOIN workbench_moderation_node_history wh ON wh.nid = n.nid AND wh.vid = n.vid AND wh.current = 1
LEFT JOIN workbench_moderation_states ws ON ws.name = wh.state
LEFT JOIN field_data_field_phone phone ON phone.entity_id = n.nid AND phone.revision_id = n.vid AND phone.entity_type = 'node'
LEFT JOIN field_data_field_site_email email ON email.entity_id = n.nid AND email.revision_id = n.vid AND email.entity_type = 'node'
LEFT JOIN field_data_field_website website ON website.entity_id = n.nid AND website.revision_id = n.vid AND website.entity_type = 'node'
LEFT JOIN field_data_field_location location_field ON location_field.delta = 0 AND location_field.entity_id = n.nid AND location_field.revision_id = n.vid AND location_field.entity_type = 'node'
LEFT JOIN location ON location.lid = location_field.field_location_lid
LEFT JOIN field_data_field_district_federal district_federal ON district_federal.entity_id = n.nid AND district_federal.revision_id = n.vid AND district_federal.entity_type = 'node'
LEFT JOIN field_data_field_district_state_upper state_upper ON state_upper.entity_id = n.nid AND state_upper.revision_id = n.vid AND state_upper.entity_type = 'node'
LEFT JOIN field_data_field_district_state_lower state_lower ON state_lower.entity_id = n.nid AND state_lower.revision_id = n.vid AND state_lower.entity_type = 'node'
LEFT JOIN field_data_field_county county ON county.entity_id = n.nid AND county.revision_id = n.vid AND county.entity_type = 'node'

WHERE n.type = 'site'

--IF=:state
AND wh.state IN (:state) 
--END

--IF=:programs
AND n.nid IN (
	SELECT program.entity_id
	FROM field_data_field_site_restrict program
	WHERE program.field_site_restrict_tid IN (:programs)
	AND program.entity_type = 'node'
)
--END

--IF=:created_after
AND n.created >= UNIX_TIMESTAMP(STR_TO_DATE(:created_after, '%Y-%m-%d'))
--END

--IF=:name
AND n.title REGEXP :name
--END

--IF=:city
AND location.city IN(:city)
--END

--IF=:county
AND county.field_county_value IN (:county) 
--END

--IF=:issues_addressed
AND n.nid IN (
	SELECT issues.entity_id FROM field_data_field_csu_facility issues
	WHERE issues.field_csu_facility_tid IN (:issues_addressed)
	)
--END

--IF=:org_type
AND n.nid IN (
	SELECT org.entity_id FROM field_data_field_csu_org_type org
	WHERE org.field_csu_org_type_tid IN (:org_type)
	)
--END

--INFO
type[programs]=array
type[city]=array
type[county]=array
type[issues_addressed]=array
