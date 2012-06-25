.. _samplequeries:

==============
Sample Queries
==============

The following queries are samples and are being used in production at Cal State Monterey Bay to integrate data with our S4 installation. While these are being parsed through our own REST wrapper around CMS, these could instead be used to generate a batch file for the feeds mechanism to pick up.

**Danger:** These queries are written with a number of assumptions about Cal State Monterey Bay, and will most definately need to be tweaked to fit your campus' use case. We have added notes within the queries to indicate things that need to probably be changed.

**More danger:** Because we have a REST wrapper around CMS, our table names may be different than your campus, however, there's not shared data dictionary within the CSU so you're just going to have to figure it out.

Terms
=====

This is the simplest query, it only selects term data for "major" terms (session code 1) and uses the STRM as the global unique identifier. Note that we convert the dates to a S4-friendly (MySQL) format, but that format will be chagned to whatever type your own database uses on the fly::

  SELECT DISTINCT strm, 
                  descr, 
                  To_char(term_begin_dt, 'YYYY-MM-DD') AS start_date, 
                  To_char(term_end_dt, 'YYYY-MM-DD')   AS end_date 
  FROM   ps_term_tbl 
  WHERE  term_begin_dt <= SYSDATE 
         AND session_code = '1' 
         AND strm > 2013 
  ORDER  BY strm 
  
Courses
=======

This query is pulling all courses with a specific "SL" attribute, and also adds the "CHHS" program designation based on the courses' subject code. If you want more programs based on subject code, just expand the WHERE statement and fiddle with the conditionals::
  
  SELECT Concat(c.strm, c.class_nbr) AS course_id, 
         c.strm, 
         c.subject, 
         c.catalog_nbr, 
         c.class_section, 
         c.descr, 
         CASE 
           WHEN c.class_stat = 'X' THEN 0 
           ELSE 1 
         END                         AS class_status, 
         CASE 
           WHEN subject = 'CHHS' THEN 'Collaborative Health and Human Services' 
           ELSE 'Service Learning' 
         END                         AS programs 
  FROM   mb_ps_class_tbl c 
         left join mb_ps_class_attribute a 
                ON a.crse_id = c.crse_id 
                   AND a.crse_offer_nbr = c.crse_offer_nbr 
                   AND a.strm = c.strm 
                   AND a.crse_attr = 'CSLI' 
  WHERE  a.crse_attr_value = 'Y' 
         AND c.strm = (SELECT Min(strm) 
                       FROM   mb_ps_term_tbl 
                       WHERE  term_begin_dt >= SYSDATE 
                              AND session_code = '1') 

Users
=====

A union of multiple queries to pick up students in specific programs, students enrolled currently in specific types of courses, and fauclty assigned to specific types of courses::

  SELECT x.external_system_id                             AS login_id, 
         x.emplid                                         AS user_id, 
         em.email_addr                                    AS email, 
         n.first_name, 
         n.last_name, 
         (SELECT DISTINCT CASE 
                            WHEN p.acad_plan = 'MSW____MPB' THEN 
                            'Master of Social Work' 
                            ELSE NULL 
                          END AS program 
          FROM   mb_ps_acad_plan_mv p 
          WHERE  p.emplid = x.emplid 
                 AND p.effseq = 1 
                 AND p.effdt = (SELECT Max(p2.effdt) 
                                FROM   mb_ps_acad_plan_mv p2 
                                WHERE  p2.emplid = p.emplid 
                                       AND p.effseq = 1)) AS program 
  FROM   mb_ps_external_system x 
         left join mb_ps_email_addresses em 
                ON em.emplid = x.emplid 
         left join mb_ps_names n 
                ON n.emplid = x.emplid 
                   AND n.name_type = 'PRI' 
  WHERE  x.external_system = 'LS3' 
         AND em.e_addr_type = 'OCMP' 
         AND n.effdt = (SELECT Max(n2.effdt) 
                        FROM   mb_ps_names n2 
                        WHERE  n2.emplid = n.emplid 
                               AND n2.name_type = 'PRI') 
         AND x.emplid IN (SELECT i.emplid 
                          FROM   mb_ps_class_instr i 
                          WHERE  i.strm = (SELECT Min(strm) 
                                           FROM   mb_ps_term_tbl 
                                           WHERE  term_begin_dt >= SYSDATE 
                                                  AND session_code = '1') 
                                 AND i.crse_id IN (SELECT c.crse_id 
                                                   FROM   mb_ps_class_tbl c 
                                     left join mb_ps_class_attribute 
                                               a 
                                            ON a.crse_id = c.crse_id 
                                               AND a.crse_offer_nbr 
                                                   = 
                                                   c.crse_offer_nbr 
                                               AND a.strm = c.strm 
                                               AND a.crse_attr = 
                                                   'CSLI' 
                                                   WHERE  a.crse_attr_value = 'Y' 
                                                          AND c.strm = i.strm) 
                          UNION 
                          SELECT e.emplid 
                          FROM   mb_ps_stdnt_enrl e 
                          WHERE  e.strm = (SELECT Min(strm) 
                                           FROM   mb_ps_term_tbl 
                                           WHERE  term_begin_dt >= SYSDATE 
                                                  AND session_code = '1') 
                                 AND e.class_nbr IN (SELECT c.class_nbr 
                                                     FROM   mb_ps_class_tbl c 
                                     left join mb_ps_class_attribute a 
                                            ON a.crse_id = c.crse_id 
                                               AND a.crse_offer_nbr = 
                                                   c.crse_offer_nbr 
                                               AND a.strm = c.strm 
                                               AND a.crse_attr = 
                                                   'CSLI' 
                                                     WHERE 
                                     a.crse_attr_value = 'Y' 
                                     AND c.strm = e.strm) 
                          UNION 
                          SELECT DISTINCT s.emplid 
                          FROM   mb_ps_acad_plan_mv s 
                          WHERE  s.acad_plan = 'MSW____MPB' 
                                 AND s.effseq = 1 
                                 AND s.effdt = (SELECT Max(effdt) 
                                                FROM   mb_ps_acad_plan_mv s2 
                                                WHERE  s2.emplid = s.emplid 
                                                       AND s2.effseq = 1)) 

Enrollment
==========

CMS PeopleSoft has a really terrible lack of consistency when it comes to course unique identifiers, so we have to build our own by getting course number from toerh class table::

  SELECT Concat(e.strm, e.class_nbr)                   AS course_id, 
         e.emplid                                      AS user_id, 
         CASE 
           WHEN stdnt_enrl_status = 'E' THEN 1 
           ELSE 0 
         END                                           AS status, 
         Concat(e.emplid, Concat(e.strm, e.class_nbr)) AS enrollment_id 
  FROM   mb_ps_stdnt_enrl e 
  WHERE  e.strm = (SELECT Min(strm) 
                   FROM   mb_ps_term_tbl 
                   WHERE  term_begin_dt >= SYSDATE 
                          AND session_code = '1') 
         AND e.class_nbr IN (SELECT c.class_nbr 
                             FROM   mb_ps_class_tbl c 
                                    left join mb_ps_class_attribute a 
                                           ON a.crse_id = c.crse_id 
                                              AND a.crse_offer_nbr = 
                                                  c.crse_offer_nbr 
                                              AND a.strm = c.strm 
                                              AND a.crse_attr = 'CSLI' 
                             WHERE  a.crse_attr_value = 'Y' 
                                    AND c.strm = e.strm) 

Faculty assignments
===================

Again we reconstruct the unique course ID consisting of the term code and the course number::

  SELECT Concat(i.strm, (SELECT class_nbr 
                         FROM   mb_ps_class_tbl 
                         WHERE  strm = i.strm 
                                AND crse_id = i.crse_id 
                                AND class_section = i.class_section))         AS 
         course_id, 
         i.emplid                                                             AS 
         user_id, 
         1                                                                    AS 
         status, 
         Concat(Concat(i.emplid, Concat(i.strm, i.crse_id)), i.class_section) AS 
         assignment_id 
  FROM   mb_ps_class_instr i 
  WHERE  i.strm = (SELECT Min(strm) 
                   FROM   mb_ps_term_tbl 
                   WHERE  term_begin_dt >= SYSDATE 
                          AND session_code = '1') 
         AND i.crse_id IN (SELECT c.crse_id 
                           FROM   mb_ps_class_tbl c 
                                  left join mb_ps_class_attribute a 
                                         ON a.crse_id = c.crse_id 
                                            AND a.crse_offer_nbr = 
                                                c.crse_offer_nbr 
                                            AND a.strm = c.strm 
                                            AND a.crse_attr = 'CSLI' 
                           WHERE  a.crse_attr_value = 'Y' 
                                  AND c.strm = i.strm) 