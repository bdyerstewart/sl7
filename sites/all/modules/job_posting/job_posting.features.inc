<?php
/**
 * @file
 * job_posting.features.inc
 */

/**
 * Implements hook_node_info().
 */
function job_posting_node_info() {
  $items = array(
    'job_posting' => array(
      'name' => t('Job Posting'),
      'base' => 'node_content',
      'description' => t('Volunteer job position, including dates, location, level of training needed,contact info'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  return $items;
}
