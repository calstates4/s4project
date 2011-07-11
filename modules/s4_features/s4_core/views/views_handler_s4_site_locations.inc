<?php

/**
*	Views handler to render links to all locations in a site
*/
class views_handler_s4_site_locations extends views_handler_field {

  function render($values) {
    $site = node_load($values->nid);
    $locations = field_get_items('node', $site, 'field_location');
    foreach($locations as $location) {
    	if($location['latitude'] && $location['longitude']) {
	    	$output[] = '<div class="map-link-wrapper">
    				<span><div class="map-pointer"></div>
    				<a href="#" class="map-link" lat="' .
    				$location['latitude'] .'" lon="'. $location['longitude'] .'"></a></span></div>';
    	}
    }
    if(count($output)) {
    	return theme('item_list', array('items' => $output));
    }
    return null;
  }
  
  function query() {
    
  }
}