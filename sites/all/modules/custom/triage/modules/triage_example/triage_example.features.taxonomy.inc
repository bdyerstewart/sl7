<?php
/**
 * @file
 * triage_example.features.taxonomy.inc
 */

/**
 * Implements hook_taxonomy_default_vocabularies().
 */
function triage_example_taxonomy_default_vocabularies() {
  return array(
    'maine_triage_status_groups' => array(
      'name' => 'Maine Triage Status Groups',
      'machine_name' => 'maine_triage_status_groups',
      'description' => '',
      'hierarchy' => '0',
      'module' => 'taxonomy',
      'weight' => '0',
      'language' => 'und',
      'i18n_mode' => '1',
    ),
    'me_triage' => array(
      'name' => 'ME Triage',
      'machine_name' => 'me_triage',
      'description' => 'Maine\'s Triage Questions',
      'hierarchy' => '0',
      'module' => 'taxonomy',
      'weight' => '0',
      'language' => 'und',
      'i18n_mode' => '1',
    ),
    'triage_income_eligibility' => array(
      'name' => 'Triage Income Eligibility',
      'machine_name' => 'triage_income_eligibility',
      'description' => 'Eligibility categories using Percent of Poverty Level guidelines',
      'hierarchy' => '0',
      'module' => 'taxonomy',
      'weight' => '0',
      'language' => 'und',
      'i18n_mode' => '0',
    ),
  );
}
