<?php
/**
 * @file
 * online_classroom.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function online_classroom_ctools_plugin_api() {
  list($module, $api) = func_get_args();
  if ($module == "ds" && $api == "ds") {
    return array("version" => "1");
  }
  list($module, $api) = func_get_args();
  if ($module == "page_manager" && $api == "pages_default") {
    return array("version" => "1");
  }
  list($module, $api) = func_get_args();
  if ($module == "panels" && $api == "layouts") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_views_api().
 */
function online_classroom_views_api() {
  return array("api" => "3.0");
}

/**
 * Implements hook_flag_default_flags().
 */
function online_classroom_flag_default_flags() {
  $flags = array();
  // Exported flag: "Completed".
  $flags['completed'] = array(
    'entity_type' => 'node',
    'title' => 'Completed',
    'global' => 0,
    'types' => array(
      0 => 'classroom_entry',
    ),
    'flag_short' => 'Complete',
    'flag_long' => '',
    'flag_message' => '',
    'unflag_short' => 'Reset',
    'unflag_long' => '',
    'unflag_message' => '',
    'unflag_denied_text' => '',
    'link_type' => 'toggle',
    'weight' => 0,
    'show_in_links' => array(
      'full' => 0,
      'teaser' => 0,
      'rss' => 0,
      'search_index' => 0,
      'search_result' => 0,
      'token' => 0,
      'revision' => 0,
    ),
    'show_as_field' => 0,
    'show_on_form' => 0,
    'access_author' => '',
    'show_contextual_link' => 0,
    'i18n' => 0,
    'api_version' => 3,
    'module' => 'online_classroom',
    'locked' => array(
      0 => 'name',
    ),
  );
  return $flags;

}

/**
 * Implements hook_node_info().
 */
function online_classroom_node_info() {
  $items = array(
    'classroom_entry' => array(
      'name' => t('Classroom Entry'),
      'base' => 'node_content',
      'description' => t('Classroom entries for Online Classrooms.'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  return $items;
}
