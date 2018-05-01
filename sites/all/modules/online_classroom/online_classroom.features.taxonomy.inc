<?php
/**
 * @file
 * online_classroom.features.taxonomy.inc
 */

/**
 * Implements hook_taxonomy_default_vocabularies().
 */
function online_classroom_taxonomy_default_vocabularies() {
  return array(
    'classroom' => array(
      'name' => 'Classroom',
      'machine_name' => 'classroom',
      'description' => '',
      'hierarchy' => 0,
      'module' => 'nodeorderplus',
      'weight' => 0,
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
