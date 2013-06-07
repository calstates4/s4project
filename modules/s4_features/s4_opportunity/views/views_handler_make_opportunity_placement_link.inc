<?php

class views_handler_make_opportunity_placement_link extends views_handler_field {

  function render($values) {
    $links = array();
    $links[] = l(t('Place with site'), 'signup/create/'. $values->uid, array('query' => drupal_get_destination()));

	  $types = s4_opportunity_get_types();
	  if(count($types)) {
	  	$links[] = array('data' => '', 'class' => array('divider'));
	  }
	  else {
	  	return $links[0];
	  }
	  foreach($types as $type) {
	  	$links[] = l($type->label, 'opportunities/place/'. $type->type .'/'. $values->uid, array('query' => drupal_get_destination()));
	  }
	  return '<div class="btn-group">
		  <a class="btn dropdown-toggle" data-toggle="dropdown" href="#">
		    '. t('Place') .'
		    <span class="caret"></span>
		  </a>
		  '. theme('item_list', array('items' => $links, 'attributes' => array('class' => array('dropdown-menu')))) .'
		</div>';

	}

  function query() {

  }
}