--ACCESS=access s4 reporting
SELECT DISTINCT n.nid, n.title FROM node n WHERE n.type = 'course_term' AND n.status = 1 ORDER BY title DESC