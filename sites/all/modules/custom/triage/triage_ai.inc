<?php
function triage_houston($houston_key = NULL) {
  global $base_url;
  $_GET["key"] = $houston_key;
  $results = views_get_view_result('adjusted_search', 'page');
  $key = search_api_extend_srch_guided_path($houston_key, $results, TRUE);
  //dsm($key);
  return $key;
}

function triage_houston_taxonomy() {
  if (taxonomy_vocabulary_machine_name_load('houston_codes')) {
    return;
  }
  $vocabulary = new stdClass();
  $vocabulary->name = 'Houston AI Codes';
  $vocabulary->machine_name = 'houston_codes';
  taxonomy_vocabulary_save($vocabulary);
  $vid = $vocabulary->vid;
  $fld = "field_houston_tid";
  $bundle = $vocabulary->machine_name;
  if (!field_info_field($fld)) {
    field_create_field(array(
      'field_name' => $fld,
      'label' => t('Houston Code ID'),
      'type' => 'text',
    ));
  }
  if (!field_info_instance('taxonomy_term', $fld, $bundle)) {
    $instance = array(
      'field_name' => $fld,
      'entity_type' => 'taxonomy_term',
      'label' => t('Houston Code ID'),
      'bundle' => $bundle,
      'widget' => array('type' => 'text_textfield'),
    );
    field_create_instance($instance);
  }
  $groups = houston_ai_problem_codes()->codeGroups;
  foreach ($groups as $grp) {
    $newterm = new stdClass();
    $newterm->name = $grp->groupName;
    $newterm->vid = $vid;
    taxonomy_term_save($newterm);
    $parent = $newterm->tid;
    $codes = $grp->codes;
    foreach ($codes as $code) {
      $name = str_replace("/"," - ", $code->label);
      $newterm = new stdClass();
      $newterm->name = $name;
      $newterm->vid = $vid;
      $newterm->parent = $parent;
      $newterm->field_houston_tid['und'][0]['value'] = $code->code;
      taxonomy_term_save($newterm);
    }
  }
}
