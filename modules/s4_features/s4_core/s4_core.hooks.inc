<?php


function hook_s4_get_term($start_date, $end_date) {
	return array(
		array('term_title' => 'Fall 2010',
			  'term_code'  => '2104',
			  'start_date' => strtotime('2011-09-01'),
			  'end_date'   => strtotime('2011-12-01'),
		),
		array('term_title' => 'Spring 2010',
			  'term_code'  => '2102',
			  'start_date' => strtotime('2011-02-01'),
			  'end_date'   => strtotime('2011-06-01'),
		),
	);
}

/**
*  Arguments
*  
*  term - A term code. Terms are identified in advance in S4 manually, 
*  and it stores a list of terms and when those terms are "active." Only 
*  active terms are synced with the SIS actively, and past terms are synced 
*  periodically, while future terms are not synced at all. Within a terms' 
*  setup form, the user must enter the term ID, which will appear here.
*  
*  Results
*  
*  subject - The subject code (optional)
*  catalog_number - the catalog number (the "101" in "SPAN 101")
*  section - The section number
*  title - The course title
*  status - Boolean value - either 1 for "open or active" and 0 for "cancelled"
*  faculty - A listing of all faculty assigned to the course:
*			login_id - the authentication username used to login
*			user_id - the unique ID used to look up other info in your sis
*/
function hook_s4_get_courses($term) {
	return array(
		array('subject' => 'SBS',
			  'catalog_number' => '300',
			  'section' => 3,
			  'title' => 'Introduction to pedantism',
			  'status' => 1,
			  'faculty' => array(
			  		array(
			  			'login_id' => 'jose1000',
			  			'user_id' => '000123472',
			  			'email' => 'joseph@campus.edu',
			  			'first_name' => 'Joseph',
			  			'last_name' => 'Conrad',
			  			'restrictions' => array(),
			  			'constant_registration' => FALSE,
			  		),
			  ),
			  'students' => array(
			  		array(
			  			'login_id' => 'student1234',
			  			'user_id' => '000123472',
			  			'email' => 'student@campus.edu',
			  			'first_name' => 'Joey',
			  			'last_name' => 'Student',
			  			'restrictions' => array(),
			  			'constant_registration' => FALSE,
			  		),
			  ),
	);
}

/**
*  Given a login ID (S4 creates accounts on the fly based on your campus' 
*  Shibboleth/CAS/LDAP authentication system, this will return the unique 
*  user_id from your SIS, along with basic user information. Each login ID 
*  should be unique on your campus. The login ID can be an email address.
*  
*  Arguments
*  
*  login-id - The unique ID the user used to login. This ID is usually from your campus directory
*  Results
*  
*  A single result containing a user's information
*  
*  login_id - The username used by this user to login to the campus directory
*  user_id - The unique ID for the user in the SIS (in CSUs this is the "emplid")
*  email - The email address for the user
*  first_name - The user's first name
*  last_name - The user's last name
*  restrictions - If your S4 system has per-user-attribute restrictions, provide a 
*  list of all site restrictions this user has access to. This is useful if you want 
*  only students with a specific major to access ceratin sites.
*  constant_registration - A boolean value indicating if this user can always register 
*  for a site regardless of whether they are part of a course. This is useful if you 
*  want to include some logic saying "students who are teacher ed students can always register."  
*/
function hook_s4_get_user($login_id) {
	return array(
		'login_id' => 'jose1000',
		'user_id' => '000123472',
		'email' => 'joseph@campus.edu',
		'first_name' => 'Joseph',
		'last_name' => 'Conrad',
		'restrictions' => array(),
		'constant_registration' => FALSE,
	);
}