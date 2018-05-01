<?php

/**
 * @file
 * Classroom modal code
 */

function classroom_permissions_add() {
  classroom_permissions_render();
}

/**
 * Build the Modal Form.
 */
function classroom_permissions_render() {
  $commands = array();

  ctools_include('taxonomy.admin', 'taxonomy', '');
  ctools_include('modal');
  ctools_include('ajax');
  drupal_add_css(drupal_get_path('module', 'classroom_permissions') . '/classroom_permissions.css',
    array(
      'group' => CSS_THEME,
    )
  );
  
  // Get form defaults.
  $taxonomy = array(
    'name' => '',
    'vocabulary_machine_name' => 'classroom',
    'vid' => taxonomy_vocabulary_machine_name_load('classroom')->vid,
  );
  
  $form_state = array(
    'title' => 'Add new Classroom',
    'ajax'  => TRUE,
    'build_info' => array(
      'args'  => array($taxonomy),
    ),
  );

  $commands = ctools_modal_form_wrapper('taxonomy_form_term', $form_state);

  if (!empty($form_state['executed']) && empty($form_state['rebuild'])) {
    // overwrite commands.
    $commands = array();
    ctools_add_js('ajax-responder');
    $commands[] = ctools_modal_command_dismiss();
    $commands[] = ctools_ajax_command_reload();
  }
  
  // add CSS class to Modal-Frame
  $commands[] = ajax_command_invoke('#modalContent', 'addClass', array('custom-module-node', 'custom-module-node-form'));

  print ajax_render($commands);
  exit;
}
