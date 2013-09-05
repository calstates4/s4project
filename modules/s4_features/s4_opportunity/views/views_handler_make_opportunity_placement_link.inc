<?php

class views_handler_make_opportunity_placement_link extends views_handler_field {

  function render($values) {
    $links = array();
    $uid = (isset($values->uid)) ? $values->uid : $values->users_field_data_field_course_students_uid;
    $destination = drupal_get_destination();
    $destination['modal'] = 'modal';
    $links[] = l(t('Place with site'), 'signup/create/'. $uid, array('query' => array('modal' => 'modal'), 'attributes' => array('class' => array('iframe-modal'), 'data-modal-title' => t('Place @first @last', array('@first' => $values->field_data_field_first_name_field_first_name_value, '@last' => $values->field_data_field_last_name_field_last_name_value)))));

	  $types = s4_opportunity_get_types();
	  if(count($types)) {
	  	$links[] = array('data' => '', 'class' => array('divider'));
	  }
	  else {
	  	return $links[0];
	  }
	  foreach($types as $type) {
	  	$links[] = l($type->label, 'opportunities/place/'. $type->type .'/'. $uid, array('query' => array('modal' => 'modal'), 'attributes' => array('class' => array('iframe-modal'), 'data-modal-title' => t('Place @first @last in @type', array('@first' => $values->field_data_field_first_name_field_first_name_value, '@last' => $values->field_data_field_last_name_field_last_name_value, '@type' => $type->label)))));
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