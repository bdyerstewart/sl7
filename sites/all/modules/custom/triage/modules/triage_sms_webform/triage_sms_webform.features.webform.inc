<?php
/**
 * @file
 * triage_sms_webform.features.webform.inc
 */

/**
 * Implements hook_webform_defaults().
 */
function triage_sms_webform_webform_defaults() {
$webforms = array();
  $webforms['sms_test'] = array(
  'title' => 'SMS Form',
  'log' => '',
  'status' => 0,
  'comment' => 1,
  'promote' => 0,
  'sticky' => 0,
  'vuuid' => '86d1b2a1-9662-49cf-b9cf-03d7c34a657d',
  'type' => 'webform',
  'language' => 'en',
  'tnid' => 0,
  'translate' => 0,
  'uuid' => 'fc406eea-9268-40a9-ab11-90a6396614db',
  'taxonomy_vocabulary_1' => array(
    'und' => array(
      0 => array(
        'tid' => 2,
      ),
    ),
  ),
  'body' => array(),
  'upload' => array(),
  'field_legalease_code' => array(),
  'rdf_mapping' => array(
    'rdftype' => array(
      0 => 'sioc:Item',
      1 => 'foaf:Document',
    ),
    'title' => array(
      'predicates' => array(
        0 => 'dc:title',
      ),
    ),
    'created' => array(
      'predicates' => array(
        0 => 'dc:date',
        1 => 'dc:created',
      ),
      'datatype' => 'xsd:dateTime',
      'callback' => 'date_iso8601',
    ),
    'changed' => array(
      'predicates' => array(
        0 => 'dc:modified',
      ),
      'datatype' => 'xsd:dateTime',
      'callback' => 'date_iso8601',
    ),
    'body' => array(
      'predicates' => array(
        0 => 'content:encoded',
      ),
    ),
    'uid' => array(
      'predicates' => array(
        0 => 'sioc:has_creator',
      ),
      'type' => 'rel',
    ),
    'name' => array(
      'predicates' => array(
        0 => 'foaf:name',
      ),
    ),
    'comment_count' => array(
      'predicates' => array(
        0 => 'sioc:num_replies',
      ),
      'datatype' => 'xsd:integer',
    ),
    'last_activity' => array(
      'predicates' => array(
        0 => 'sioc:last_activity_date',
      ),
      'datatype' => 'xsd:dateTime',
      'callback' => 'date_iso8601',
    ),
  ),
  'path' => array(
    'pathauto' => 1,
  ),
  'webform' => array(
    'confirmation' => '',
    'teaser' => 0,
    'submit_text' => 'Send text message',
    'submit_limit' => -1,
    'submit_interval' => -1,
    'additional_validate' => NULL,
    'additional_submit' => NULL,
    'confirmation_format' => 2,
    'submit_notice' => 1,
    'allow_draft' => 0,
    'redirect_url' => '<none>',
    'block' => 1,
    'status' => 1,
    'auto_save' => 0,
    'total_submit_limit' => -1,
    'total_submit_interval' => -1,
    'machine_name' => 'sms_test',
    'record_exists' => TRUE,
    'roles' => array(
      0 => 1,
      1 => 2,
    ),
    'emails' => array(),
    'components' => array(
      'sms_test__title' => array(
        'form_key' => 'title',
        'name' => 'Title',
        'type' => 'markup',
        'value' => '<p>Enter cell phone number to receive text message with link to your results</p>',
        'extra' => array(
          'conditional_operator' => '=',
          'format' => 2,
          'private' => 0,
          'conditional_component' => '',
          'conditional_values' => '',
        ),
        'mandatory' => 0,
        'weight' => 1,
        'machine_name' => 'sms_test__title',
        'page_num' => 1,
      ),
      'sms_test__cell_phone' => array(
        'form_key' => 'cell_phone_number',
        'name' => 'Cell phone#',
        'type' => 'textfield',
        'value' => '',
        'extra' => array(
          'title_display' => 'before',
          'private' => 0,
          'width' => 14,
          'disabled' => 0,
          'unique' => 0,
          'maxlength' => 14,
          'conditional_operator' => '=',
          'encrypt' => 0,
          'field_prefix' => '',
          'field_suffix' => '',
          'description' => '',
          'attributes' => array(),
          'conditional_component' => '',
          'conditional_values' => '',
        ),
        'mandatory' => 0,
        'weight' => 2,
        'machine_name' => 'sms_test__cell_phone',
        'page_num' => 1,
      ),
    ),
  ),
  'cid' => 0,
  'last_comment_name' => NULL,
  'last_comment_uid' => 1,
  'comment_count' => 0,
  'print_display' => 1,
  'print_display_comment' => 0,
  'print_display_urllist' => 1,
  'name' => 'admin',
  'picture' => 0,
  'data' => 'a:4:{s:7:"contact";i:0;s:13:"form_build_id";s:37:"form-2a65a612565acacdeeae78171ae3d4ce";s:5:"block";a:3:{s:5:"block";a:1:{i:13;i:1;}s:5:"views";a:1:{s:12:"news-block_1";i:1;}s:5:"forum";a:1:{s:3:"new";i:1;}}s:7:"overlay";i:1;}',
  'webform_features_author' => 'admin',
  'webform_features_revision_author' => 'admin',
);
return $webforms;
}
