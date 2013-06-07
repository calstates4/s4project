<?php
/**
 * @file
 * s4_opportunity.features.taxonomy.inc
 */

/**
 * Implements hook_taxonomy_default_vocabularies().
 */
function s4_opportunity_taxonomy_default_vocabularies() {
  return array(
    'opportunity_category' => array(
      'name' => 'Opportunity category',
      'machine_name' => 'opportunity_category',
      'description' => 'A general category useful to tag opportunities across types',
      'hierarchy' => '0',
      'module' => 'taxonomy',
      'weight' => '0',
      'rdf_mapping' => array(
        'rdftype' => array(
          0 => 'skos:ConceptScheme',
        ),
        'name' => array(
          'predicates' => array(
            0 => 'dc:title',
          ),
        ),
        'description' => array(
          'predicates' => array(
            0 => 'rdfs:comment',
          ),
        ),
      ),
    ),
  );
}
