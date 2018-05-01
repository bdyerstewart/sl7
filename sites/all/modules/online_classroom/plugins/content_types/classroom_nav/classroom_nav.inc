<?php

/**
 * Plugins are described by creating a $plugin array which will be used
 * by the system that includes this file.
 */
$plugin = array(
  'single' => TRUE,
  'title' => t('Classroom Navigation'),
  'icon' => 'icon_core_block_menu.png',
  'description' => t('Navigation for classrooms'),
  'required context' => array (
    new ctools_context_required(t('Term'), array('term', 'taxonomy_term')),
    new ctools_context_optional(t('Node'), 'node'),
  ),
  'category' => array(t('Classrooms'), -9),
  'edit form' => 'classroom_nav_content_type_edit_form',
  'render callback' => 'classroom_nav_content_type_render',
  'defaults' => array(
    'prev_txt' => '',
    'next_txt' => '',
  ),
);

/**
 * Render the custom content type.
 */
function classroom_nav_content_type_render($subtype, $conf, $panel_args, $context) {
  if (empty($context)) {
    return;
  }
  $tid = '';
  $nid = '';
  foreach ($context as $input) {
    if (isset($input->data->tid)) {
      $tid = $input->data->tid;
    }
    else if (isset($input->data->nid)) {
      $nid = $input->data->nid;
    }
  }
  
  if ($nid !== '') {
    $output = classroom_nav_render_classroom_navigation($tid, $nid, $conf);
  } else {
    $view = views_get_view('classroom_steps');
    $view->preview('panel_pane_3', array($tid));
    $nid = $view->result[0]->nid;
    $output = classroom_nav_render_classroom_navigation($tid, $nid, $conf);
  }
  
  // Build the content type block.
  $block = new stdClass();
  $block->delta = 'form';
  $block->title = '';

  $block->content = $output;

  return $block;
}

/**
 * Returns an edit form for custom type settings.
 */
function classroom_nav_content_type_edit_form($form, &$form_state) {
  $conf = $form_state['conf'];
  
  $form['prev_txt'] = array(
    '#type' => 'textfield',
    '#title' => t('Previous Button Text'),
    '#default_value' => t($conf['prev_txt']),
  );
  
  $form['next_txt'] = array(
    '#type' => 'textfield',
    '#title' => t('Next Button Text'),
    '#default_value' => t($conf['next_txt']),
  );
  
  return $form;
}

/**
 * Submit handler for search form.
 */
function classroom_nav_content_type_edit_form_submit($form, &$form_state) {
  // Copy everything from our defaults.
  foreach (array_keys($form_state['plugin']['defaults']) as $key) {
    $form_state['conf'][$key] = $form_state['values'][$key];
  }
}

/**
 * Returns navigation
 */
function classroom_nav_render_classroom_navigation($tid, $nid, &$conf) {
  if ($tid == '' || $nid == '') {
    return;
  }
  $node_ids = taxonomy_select_nodes($tid, FALSE, FALSE, array('t.weight' => 'ASC'));
  $result = node_load_multiple($node_ids);
  $ordered_nids = array();
  foreach ($result as $node) {
    $ordered_nids[] = $node->nid;
  }
  
  $key = array_search($nid, $ordered_nids);
  $neighbors = array_neighbor($ordered_nids, $key);
  $prev_id = $ordered_nids[$neighbors[0]];
  $next_id = $ordered_nids[$neighbors[1]];
  
  $prev_btn = theme('html_tag', array(
    'element' => array(
      '#tag' => 'div',
      '#attributes' => array(
        'class' => 'classroom-previous-navigation',
      ),
      '#value' => l(t($conf['prev_txt']), 'classroom/'.$tid.'/'.$prev_id, array(
        'attributes' => array(
          'class' => array('classroom-previous-button'), 
          'title' => 'Previous Step',
          'rel' => $tid.'/'.$prev_id,
        )
      )),
    ),
  ));
  $next_btn = theme('html_tag', array(
    'element' => array(
      '#tag' => 'div',
      '#attributes' => array(
        'class' => 'classroom-next-navigation',
      ),
      '#value' => l(t($conf['next_txt']), 'classroom/'.$tid.'/'.$next_id, array(
        'attributes' => array(
          'class' => array('classroom-next-button'), 
          'title' => 'Next Step',
          'rel' => $tid.'/'.$next_id,
        )
      )),
    ),
  ));
  
  $output = theme('html_tag', array(
    'element' => array(
      '#tag' => 'div',
      '#attributes' => array(
        'class' => 'classroom-navigation-wrapper',
        ),
      '#value' => $prev_btn . $next_btn,
    ),
  ));
  
  return $output;
}

/**
 * Returns the neighbors in an array.
 */
function array_neighbor($arr, $key) {
  $keys = array_keys($arr);
  $keyIndexes = array_flip($keys);

  $return = array();
  if (isset($keys[$keyIndexes[$key]-1])) {
    $return[] = $keys[$keyIndexes[$key]-1];
  }
  else {
    $return[] = $keys[sizeof($keys)-1];
  }

  if (isset($keys[$keyIndexes[$key]+1])) {
    $return[] = $keys[$keyIndexes[$key]+1];
  }
  else {
    $return[] = $keys[0];
  }

  return $return;
}
