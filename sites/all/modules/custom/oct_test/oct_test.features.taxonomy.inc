<?php
/**
 * @file
 * oct_test.features.taxonomy.inc
 */

/**
 * Implements hook_taxonomy_default_vocabularies().
 */
function oct_test_taxonomy_default_vocabularies() {
  return array(
    'classroom' => array(
      'name' => 'Classroom',
      'machine_name' => 'classroom',
      'description' => '',
      'hierarchy' => 0,
      'module' => 'nodeorder',
      'weight' => 0,
      'language' => 'und',
      'i18n_mode' => 1,
    ),
  );
}
