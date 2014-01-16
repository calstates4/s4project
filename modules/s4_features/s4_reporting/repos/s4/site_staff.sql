--ACCESS=access s4 reporting
select DISTINCT n.nid, n.title, n.status, n.created, n.changed, n.uuid, 
n_site.nid as site_nid, n_site.title as site,
fname.field_first_name_value as first_name,
lname.field_last_name_value as last_name,
(
--INCLUDE=subqueries/programs
) as programs,
(
--INCLUDE=subqueries/site_staff_total_placements
) as total_placements
FROM node n
LEFT JOIN field_data_field_first_name fname
	ON fname.entity_id = n.nid AND fname.entity_type = 'node'
LEFT JOIN field_data_field_last_name lname
	ON lname.entity_id = n.nid AND lname.entity_type = 'node'
LEFT JOIN field_data_field_site site
	ON site.entity_id = n.nid AND site.entity_type = 'node'
LEFT JOIN node n_site
	ON n_site.nid = site.field_site_nid

WHERE n.type = 'coordinator'

--IF=:site
AND site.field_site_nid IN (:site)
--END

--INFO
type[site]=array