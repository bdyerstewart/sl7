<?php
/**
 * @file
 * job_posting.field_group.inc
 */

/**
 * Implements hook_field_group_info().
 */
function job_posting_field_group_info() {
  $export = array();

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_jobinfo|node|job_posting|form';
  $field_group->group_name = 'group_jobinfo';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'job_posting';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Job Info',
    'weight' => '1',
    'children' => array(
      0 => 'body',
      1 => 'field_when',
      2 => 'field_position_dates',
      3 => 'field_requirements',
      4 => 'field_publish_dates',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(
        'description' => '',
        'classes' => '',
        'required_fields' => 1,
      ),
    ),
  );
  $export['group_jobinfo|node|job_posting|form'] = $field_group;

  return $export;
}
