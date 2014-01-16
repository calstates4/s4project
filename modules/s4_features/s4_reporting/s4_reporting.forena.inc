<?php

function s4_reporting_forena_groups() {
	return array(
		'sites' => array(
			'site_group' => array(
				'title' => t('Site'),
				'fields' => array(
					'programs',
					'name',
					'state',
					'created_after',
					'issues_addressed',
					'org_type'
				)
			),
			'location_group' => array(
				'title' => t('Location'),
				'fields' => array(
					'city',
					'county',
				)
			),
			'placements_group' => array(
				'title' => t('Placements'),
				'fields' => array(
					'placements_term',
					'placements_program',
					'placements_start',
					'placements_end'
				)
			),
			'fields_group' => array(
				'title' => t('Fields'),
				'auto_fields' => TRUE
			)
		),
		'site' => array(
			'course_group' => array(
				'title' => t('Placement course'),
				'fields' => array(
					'course_subject',
				),
			),
			'placements_group' => array(
				'title' => t('Placements'),
				'fields' => array(
					'placements_term',
					'placements_program',
					'placements_start',
					'placements_end'
				)
			)
		),
		'site_staff' => array(
			'site_staff_group' => array(
				'title' => t('Site staff'),
				'fields' => array(
					'site',
					),
				),
			'placements_group' => array(
				'title' => t('Placements'),
				'fields' => array(
					'placements_term',
					'placements_program',
					'placements_start',
					'placements_end'
				)
			)
		),
		'placements' => array(
			'course_group' => array(
				'title' => t('Course'),
				'fields' => array(
					'course_subject',
					'placements_term',
				),
			),
			'placements_group' => array(
				'title' => t('Placement'),
				'fields' => array(
					'placements_program',
					'placements_start',
					'placements_end'
				)
			)
		),
	);
}