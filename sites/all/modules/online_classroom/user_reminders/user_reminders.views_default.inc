<?php
/**
 * @file
 * user_reminders.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function user_reminders_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'reminders';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Reminders';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'role';
  $handler->display->display_options['access']['role'] = array(
    2 => '2',
  );
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['columns'] = array(
    'title' => 'title',
    'field_reminder_date' => 'field_reminder_date',
    'delete_node' => 'delete_node',
  );
  $handler->display->display_options['style_options']['default'] = 'field_reminder_date';
  $handler->display->display_options['style_options']['info'] = array(
    'title' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_reminder_date' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'delete_node' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
  );
  /* Header: Global: Text area */
  $handler->display->display_options['header']['area']['id'] = 'area';
  $handler->display->display_options['header']['area']['table'] = 'views';
  $handler->display->display_options['header']['area']['field'] = 'area';
  $handler->display->display_options['header']['area']['label'] = 'Intro';
  $handler->display->display_options['header']['area']['content'] = '<p>You can view the current reminders you have created below</p>';
  $handler->display->display_options['header']['area']['format'] = 'full_html';
  /* No results behavior: Global: Text area */
  $handler->display->display_options['empty']['area']['id'] = 'area';
  $handler->display->display_options['empty']['area']['table'] = 'views';
  $handler->display->display_options['empty']['area']['field'] = 'area';
  $handler->display->display_options['empty']['area']['label'] = 'No Results';
  $handler->display->display_options['empty']['area']['empty'] = TRUE;
  $handler->display->display_options['empty']['area']['content'] = '<h4 style="text-align:center;margin-top:10px;">You currently don\'t have any active reminders</h4>';
  $handler->display->display_options['empty']['area']['format'] = 'full_html';
  /* Field: Content: Date */
  $handler->display->display_options['fields']['field_reminder_date']['id'] = 'field_reminder_date';
  $handler->display->display_options['fields']['field_reminder_date']['table'] = 'field_data_field_reminder_date';
  $handler->display->display_options['fields']['field_reminder_date']['field'] = 'field_reminder_date';
  $handler->display->display_options['fields']['field_reminder_date']['label'] = 'Reminder Date';
  $handler->display->display_options['fields']['field_reminder_date']['settings'] = array(
    'format_type' => 'short',
    'fromto' => 'both',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
  );
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = 'Description';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['title']['link_to_node'] = FALSE;
  /* Field: Content: Delete link */
  $handler->display->display_options['fields']['delete_node']['id'] = 'delete_node';
  $handler->display->display_options['fields']['delete_node']['table'] = 'views_entity_node';
  $handler->display->display_options['fields']['delete_node']['field'] = 'delete_node';
  $handler->display->display_options['fields']['delete_node']['label'] = '';
  $handler->display->display_options['fields']['delete_node']['element_label_colon'] = FALSE;
  /* Contextual filter: Content: Author uid */
  $handler->display->display_options['arguments']['uid']['id'] = 'uid';
  $handler->display->display_options['arguments']['uid']['table'] = 'node';
  $handler->display->display_options['arguments']['uid']['field'] = 'uid';
  $handler->display->display_options['arguments']['uid']['default_action'] = 'default';
  $handler->display->display_options['arguments']['uid']['default_argument_type'] = 'current_user';
  $handler->display->display_options['arguments']['uid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['uid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['uid']['summary_options']['items_per_page'] = '25';
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'classroom_reminder' => 'classroom_reminder',
  );
  /* Filter criterion: Content: Date (field_reminder_date) */
  $handler->display->display_options['filters']['field_reminder_date_value']['id'] = 'field_reminder_date_value';
  $handler->display->display_options['filters']['field_reminder_date_value']['table'] = 'field_data_field_reminder_date';
  $handler->display->display_options['filters']['field_reminder_date_value']['field'] = 'field_reminder_date_value';
  $handler->display->display_options['filters']['field_reminder_date_value']['operator'] = '>=';
  $handler->display->display_options['filters']['field_reminder_date_value']['granularity'] = 'second';
  $handler->display->display_options['filters']['field_reminder_date_value']['default_date'] = 'now';

  /* Display: Reminder Dashboard */
  $handler = $view->new_display('page', 'Reminder Dashboard', 'page_1');
  $handler->display->display_options['path'] = 'user/%/reminders';
  $handler->display->display_options['menu']['type'] = 'tab';
  $handler->display->display_options['menu']['title'] = 'Reminders';
  $handler->display->display_options['menu']['weight'] = '0';
  $handler->display->display_options['menu']['context'] = 0;
  $translatables['reminders'] = array(
    t('Master'),
    t('more'),
    t('Apply'),
    t('Reset'),
    t('Sort by'),
    t('Asc'),
    t('Desc'),
    t('Intro'),
    t('<p>You can view the current reminders you have created below</p>'),
    t('No Results'),
    t('<h4 style="text-align:center;margin-top:10px;">You currently don\'t have any active reminders</h4>'),
    t('Reminder Date'),
    t('Description'),
    t('All'),
    t('Reminder Dashboard'),
  );
  $export['reminders'] = $view;

  return $export;
}
