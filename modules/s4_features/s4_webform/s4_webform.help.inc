<?php

function _s4_webform_help($path) {
	$node = menu_get_object();
	if (!$node) {
	 return null;
	}
	if ($node->type == 'webform' && !arg(2) && node_access('update', $node)) {
		return _s4_webform_help_view();
	}
	if (arg(0) == 'node' && arg(2) == 'webform' && !arg(3)) {
		return _s4_webform_webform_view();
	}
	return null;
}

function _s4_webform_help_view() {
	return array('home' => array(
						'description' => 'This is a preview of the form template as other users will see it. From here, you can add questions or edit general settings of the form.',
						'title' => 'Form templates',
						'overlay' => TRUE,
					),
					'edit-tab' => array(
					 	'description' => 'Use this tab to edit the general settings of the form - the name and the instructions.',
					 	'title' => 'Edit tab',
					 	'attachTo' => '.tabs li:nth-child(2)',
					 	'position' => 6,
					 ),
					 'edit-form-tab' => array(
					 	'description' => 'Your faculty member may restrict your service to certain sites, so first start with selecting the course you are signing up for service with',
					 	'title' => 'Edit form tab',
					 	'attachTo' => '.tabs li:nth-child(2)',
					 	'position' => 6,
					 ),
					);
}

function _s4_webform_webform_view() {
	return array('home' => array(
						'description' => 'In this page you can manage which questions are available in your form template. Here you can edit an existing question, add a new question, or reorganize the way your template is ordered.',
						'title' => 'Edit form templates',
						'overlay' => TRUE,
					),
					'reorder' => array(
					 	'description' => 'To reorder questions, drag them up and down using these handles. Once your questions are in the right order, click the "Save" button.',
					 	'title' => 'Reordering questions',
					 	'attachTo' => '.tabledrag-handle:first',
					 	'position' => 3,
					 ),
					 'operations' => array(
					 	'description' => 'You can edit an existing question, clone a question to reuse it, or delete the question from the form.',
					 	'title' => 'Edit, copy, or delete questions',
					 	'attachTo' => '#webform-components tr:first th:nth-child(6)',
					 	'position' => 9,
					 ),
					 'addquestion' => array(
					 	'description' => 'To add a new question, type in its name, select the type of question it is, then click the "Save" button below.',
					 	'title' => 'Adding new questions',
					 	'attachTo' => '#edit-add-name',
					 	'position' => 12,
					 ),
					);
}