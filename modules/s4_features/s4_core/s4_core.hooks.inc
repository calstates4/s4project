<?php

/**
*  Returns a list of links and descriptions for the S4 Site Configuration page
*/
function hook_s4_site_configuration() {
  return array(
    'test_link' => array(
      'group' => t('My group'),
      'title' => t('My settings option'),
      'href'  => 'settings/mysettings',
      'description' => t('Description of my setting page'),
    ),
  );
}
