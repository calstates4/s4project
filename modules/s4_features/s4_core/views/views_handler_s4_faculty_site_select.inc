<?php

/**
*  Views handler indicating a user can signup with a site
*/
class views_handler_s4_faculty_site_select extends views_handler_field {

  function render($values) {
    $node = menu_get_object();
    $exists = FALSE;
    if (!$sites = field_get_items('node', $values->_field_data['nid']['entity'], 'field_sites')) {
      $sites = array();
    }
    foreach ($sites as $site) {
      if (isset($site['nid']) && $site['nid'] == $node->nid) {
        $exists = TRUE;
      }
    }
    if ($exists) {
      return l('<i class="icon-remove icon-white"></i> '. t('Remove from @site', array('@site' => $values->node_title)), 's4/course-list/remove/' . $values->nid . '/' . $node->nid, array('html' => TRUE, 'attributes' => array('class' => array('btn btn-danger'))));
    }
    else {
      return l('<i class="icon-plus icon-white"></i> '. t('Add to @site', array('@site' => $values->node_title)), 's4/course-list/add/' . $values->nid . '/' . $node->nid, array('html' => TRUE, 'attributes' => array('class' => array('btn btn-success'))));

    }

  }

  function query() {

  }
}