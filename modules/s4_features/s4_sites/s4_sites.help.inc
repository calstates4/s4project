<?php

function _s4_sites_help($path) {
	$function_name = '_s4_core_help_'. str_replace(array('/', '-'), '_', $path);
	$node = menu_get_object();
	if($node && property_exists($node, 'type') && arg(2) != 'edit') {
		$function_name = '_s4_core_help_node_view_'. $node->type;
	}
	if(function_exists($function_name)) {
		return $function_name();
	}
	return null;
}

function _s4_core_help_node_view_site() {
	global $user;
	$node = menu_get_object();
	$help = array('overview' => array(
								'description' => t('This is a site overview page for %title, which can include a description of the site, as well as hours, demographics, and locations.', array('%title' => $node->title)),
								'title' => 'Site overview page',
								'overlay' => true,
								)
				);
	if(s4_core_user_can_signup($user)) {
		$help['signup'] = array(
						'description' => 'Click this link to sign up with this site.',
						'title' => 'Sign up with this site',
						'attachTo' => '#block-s4-core-user-site-signup',
						'position' => 9,
					);
	}
	return $help;
}