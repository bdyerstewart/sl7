<?php
/**
 * @file
 * user_reminders.features.field_instance.inc
 */

/**
 * Implements hook_field_default_field_instances().
 */
function user_reminders_field_default_field_instances() {
  $field_instances = array();

  // Exported field_instance: 'node-classroom_reminder-field_reminder_date'
  $field_instances['node-classroom_reminder-field_reminder_date'] = array(
    'bundle' => 'classroom_reminder',
    'deleted' => 0,
    'description' => 'Date and time to send reminder',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'date',
        'settings' => array(
          'format_type' => 'long',
          'fromto' => 'both',
          'multiple_from' => '',
          'multiple_number' => '',
          'multiple_to' => '',
        ),
        'type' => 'date_default',
        'weight' => 0,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_reminder_date',
    'label' => 'Date',
    'required' => 1,
    'settings' => array(
      'default_value' => 'strtotime',
      'default_value2' => 'same',
      'default_value_code' => '+1 hour',
      'default_value_code2' => '',
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'date',
      'settings' => array(
        'increment' => 15,
        'input_format' => 'm/d/Y - g:i:sa',
        'input_format_custom' => '',
        'label_position' => 'above',
        'text_parts' => array(),
        'year_range' => '-0:+3',
      ),
      'type' => 'date_popup',
      'weight' => -4,
    ),
  );

  // Translatables
  // Included for use with string extractors like potx.
  t('Date');
  t('Date and time to send reminder');

  return $field_instances;
}
