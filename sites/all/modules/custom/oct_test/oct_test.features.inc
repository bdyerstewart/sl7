<?php
/**
 * @file
 * oct_test.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function oct_test_ctools_plugin_api() {
  list($module, $api) = func_get_args();
  if ($module == "ds" && $api == "ds") {
    return array("version" => "1");
  }
  list($module, $api) = func_get_args();
  if ($module == "field_group" && $api == "field_group") {
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
function oct_test_views_api() {
  return array("api" => "3.0");
}

/**
 * Implements hook_flag_default_flags().
 */
function oct_test_flag_default_flags() {
  $flags = array();
  // Exported flag: "Completed".
  $flags['completed'] = array(
    'content_type' => 'node',
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
    'link_type' => 'normal',
    'roles' => array(
      'flag' => array(
        0 => 1,
        1 => 2,
      ),
      'unflag' => array(
        0 => 1,
        1 => 2,
      ),
    ),
    'weight' => 0,
    'show_on_form' => 0,
    'access_author' => '',
    'show_on_page' => 0,
    'show_on_teaser' => 0,
    'show_contextual_link' => 0,
    'i18n' => 0,
    'module' => 'oct_test',
    'locked' => array(
      0 => 'name',
    ),
    'api_version' => 2,
  );
  return $flags;

}

/**
 * Implements hook_node_info().
 */
function oct_test_node_info() {
  $items = array(
    'classroom_entry' => array(
      'name' => t('Classroom Entry'),
      'base' => 'node_content',
      'description' => '',
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
    'note' => array(
      'name' => t('Note'),
      'base' => 'node_content',
      'description' => t('User Note'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
    'reminder' => array(
      'name' => t('Reminder'),
      'base' => 'node_content',
      'description' => t('User Reminder'),
      'has_title' => '1',
      'title_label' => t('Description'),
      'help' => '',
    ),
  );
  return $items;
}
