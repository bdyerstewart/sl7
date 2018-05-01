<?php
/**
 * @file
 * oct_test.field_group.inc
 */

/**
 * Implements hook_field_group_info().
 */
function oct_test_field_group_info() {
  $export = array();

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_add_options|node|selfhelp_guide|referenced';
  $field_group->group_name = 'group_add_options';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'selfhelp_guide';
  $field_group->mode = 'referenced';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Additional Options',
    'weight' => '3',
    'children' => array(
      0 => 'field_audio',
      1 => 'additional_items',
      2 => 'audio_download',
      3 => 'get_a_pdf',
      4 => 'related_box',
    ),
    'format_type' => 'div',
    'format_settings' => array(
      'label' => 'Additional Options',
      'instance_settings' => array(
        'classes' => '',
        'description' => '',
        'show_label' => '0',
        'label_element' => 'h3',
        'effect' => 'none',
        'speed' => 'fast',
      ),
      'formatter' => 'open',
    ),
  );
  $export['group_add_options|node|selfhelp_guide|referenced'] = $field_group;

  return $export;
}