<?php
/**
 * @file
 * user_notes.features.inc
 */

/**
 * Implements hook_views_api().
 */
function user_notes_views_api() {
  return array("api" => "3.0");
}

/**
 * Implements hook_node_info().
 */
function user_notes_node_info() {
  $items = array(
    'classroom_note' => array(
      'name' => t('Note'),
      'base' => 'node_content',
      'description' => t('User Note.'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  return $items;
}
