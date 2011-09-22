<?php

function _s4_core_help($path) {
	$function_name = '_s4_core_help_'. str_replace(array('/', '-'), '_', $path);
	if(function_exists($function_name)) {
		return $function_name();
	}
	return null;
}

function _s4_core_help_homepage() {
	global $user;
	if(s4_core_user_can_signup($user)) {
		return array('home' => array(
						'description' => 'This is your homepage, where you can find courses you are enrolled in as well as any historical sites you served at.',
						'title' => 'Your home page',
						'overlay' => TRUE,
					),
					'progress' => array(
					 	'description' => 'These arrows show what steps you need to complete signing up for service. They turn green and provide additional information as you complete them. Depending on the site or course you choose, you might need to complete additional steps',
					 	'title' => 'Progress bar',
					 	'attachTo' => '#block-s4-core-user-progress',
					 	'position' => 6,
					 ),
					 'courses' => array(
					 	'description' => 'Your faculty member may restrict your service to certain sites, so first start with selecting the course you are signing up for service with',
					 	'title' => 'Select a course',
					 	'attachTo' => '.view-user-courses table',
					 	'position' => 12,
					 ),
					);
	}
}

function _s4_core_help_site_list() {
	global $user;
	
	$help = array('start' => array(
						'description' => 'This page provides a searchable list of sites that we work with. You can browse a list or perform a search.',
						'title' => 'The site listing page',
						'overlay' => TRUE,
					),
					'map-link' => array(
					 	'description' => 'Use these letters to jump to a quick view of the location of a site within the map to the right.',
					 	'title' => 'View in map',
					 	'attachTo' => '.map-link:first',
					 	'position' => 6,
					 ),
					 'filter' => array(
					 	'description' => 'Use these search criteria to narrow down your search for a site.',
					 	'title' => 'Search for a site',
					 	'attachTo' => '.view-sites .views-exposed-form',
					 	'position' => 12,
					 ),
					);
	if(s4_core_user_can_signup($user)) {
		$help['view-site'] = array(
			'description' => 'To select a site for service, click it\'s name to view more information.',
			'title' => 'Selecting a site',
			'attachTo' => '.views-row-1',
			'position' => 12,
		);
	}
	return $help;
}

function _s4_core_help_home() {
	global $user;
	$staff = false;
	foreach($user->roles as $role) {
		if($role == 'staff') {
			$staff = true;
		}
	}
	if(!$staff) {
		return null;
	}
	return array('main' => array(
								 'description' => 'This is your homepage. You can customize it to your liking to keep tabs on everything happening throughout the site',
								 'overlay' => TRUE,
								 'title' => 'The home page'
								 ),
				 'add-box' => array(
				 					'description' => 'Click here to add new boxes to your homepage',
				 					'title' => 'Add more boxes',
				 					'attachTo' => '#homebox-add-link',
				 					'position' => 3,
				 					),
				 'move-box' => array(
							 	'description' => 'Use these buttons to remove or minimize boxes on your homepage. You can also drag the top of each box to reorder their positon.',
							 	'title' => 'Moving and removing boxes',
							 	'attachTo' => '.portlet-icon:first',
							 	'position' => 6,
				 ),
				 'site-settings' => array(
				 				'description' => 'The site settings link will let you setup your site\'s colors, name, logo, and SIS integration',
				 				'title' => 'Site settings',
				 				'attachTo' => '.s4-site-settings',
				 				'position' => 6,
				 ),
				 'masquerade' => array(
							 	'description' => 'The masquerade tool lets you switch to any other user\'s account to see exactly what they see in the site.',
							 	'title' => 'Masquerade as other users',
							 	'attachTo' => '.block-masquerade',
							 	'position' => 12,
				 ),
				);
}