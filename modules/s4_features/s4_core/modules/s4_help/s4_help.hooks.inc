<?php

/**
*  Example implementation of hook_s4_help.
  buttons: [{name: "Next"}],
  description: "description",
  id: "first",
  next: "second",
  overlay: true,
  title: "Welcome to Guiders.js!"
}

{
  attachTo: "#clock",
  description: "description",
  id: "third",
  next: "fourth",
  position: 2,
  title: "You can also advance guiders from custom event handlers.",
  width: 450
}

*/
function s4_help_s4_help($path) {
  return array('s4_homepage' => 
    array('title' => 'Hi, there!',
        'description' => 'This is the homepage!',
        'id' => 'help-box',
        'next' => NULL,
        'attachTo' => '#homebox-add-link',
       )
  );
}