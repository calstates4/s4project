<?php

function _s4_core_help($path) {
	$function_name = '_s4_core_help_'. str_replace('/', '_', $path);
	if(function_exists($function_name)) {
		return $function_name();
	}
	return null;
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