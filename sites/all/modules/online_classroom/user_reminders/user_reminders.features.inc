<?php
/**
 * @file
 * user_reminders.features.inc
 */

/**
 * Implements hook_views_api().
 */
function user_reminders_views_api() {
  return array("api" => "3.0");
}

/**
 * Implements hook_node_info().
 */
function user_reminders_node_info() {
  $items = array(
    'classroom_reminder' => array(
      'name' => t('Reminder'),
      'base' => 'node_content',
      'description' => t('User Reminder.'),
      'has_title' => '1',
      'title_label' => t('Description'),
      'help' => '',
    ),
  );
  return $items;
}
