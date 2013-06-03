<?php

/**
*  Views handler to render links to all locations in a site
*/
class views_handler_s4_site_locations extends views_handler_field {

  function render($values) {
    $site = node_load($values->nid);
    $locations = field_get_items('node', $site, 'field_location');
    if (!is_array($locations) || count($locations) == 0) {
      return NULL;
    }
    foreach ($locations as $location) {
      if (floatval($location['latitude']) != 0 && floatval($location['longitude']) != 0) {
        $output[] = '<div class="map-link-wrapper hidden-phone">
            <a href="#" class="map-link" lat="' .
            $location['latitude'] . '" lon="' . $location['longitude'] . '"></a><span class="arrow"></span></div>';
      }
    }
    if (count($output)) {
      return theme('item_list', array('items' => $output));
    }
    return NULL;
  }

  function query() {

  }
}