<?php

function triage_theme($existing, $type, $theme, $path) {
  $bds = '';
  return array(
    'triage_org_filters_list' => array(
      'render element' => 'form',
    ),
  );
}

function triage_org_filters($nid = NULL, $bundle = 'node') {
  $_SESSION['triage']['org_filter']['nid'] = $nid;
  $_SESSION['triage']['org_filter']['bundle'] = $bundle;
  $form = drupal_get_form('triage_org_filters_list', $nid, $bundle);
  return render($form);
}

function triage_org_filters_list($form, &$form_state, $nid = NULL, $bundle = 'node') {
  $nid = $_SESSION['triage']['org_filter']['nid'];
  $bundle = $_SESSION['triage']['org_filter']['bundle'];
  global $base_url;
  drupal_add_js($base_url . "/misc/tabledrag.js", "file");
  $actionTypes = array(
    'include' => 'Include',
    'exclude' => 'Exclude',
  );
  $items = array();
  $tems = array();
  $form = array();
  $form['#attached']['library'][] = array('system', 'tabledrag');
  $form['#theme'] = 'triage_org_filters_list';
  $realitems = triage_get_org_tree($nid, $bundle);
  foreach ($realitems as $ri) {
    $depth = 0;
    if ($ri->pid > 0) {
      $depth = 1;
    }
    $tems[] = array(
      'id' => $ri->id,
      'pid' => $ri->pid,
      'title' => $ri->title,
      'depth' => $ri->depth,
      'weight' => $ri->weight,
      'type' => $ri->type,
      'enabled' => $ri->enabled,
    );
  }
  $tems[] = array(
    'id' => 0,
    'pid' => 0,
    'title' => '',
    'weight' => 0,
    'depth' => 0,
    'type' => 0,
    'enabled' => $ri->enabled,
  );
  $items = json_decode(json_encode($tems), FALSE);
  //dsm($items);
  $form['#tree'] = TRUE;
  $form['act_types'] = array(
    '#type' => 'value',
    '#value' => $actionTypes
  );
  foreach ($items as $item) {
    $attr = array();
    $disable = FALSE;
    if ($item->id > 0) {
      $attr = array(
        'readonly' => 'readonly',
        'class' => array('readonly-input')
      );
      $disable = TRUE;
      $btntext = "Edit";
    }
    else {
      $btntext = "Add";
      $item->type = 'text';
    }
    // Textfield to hold content id.
    $form['items'][$item->id]['id'] = array(
      '#type' => 'hidden',
      '#size' => 3,
      '#default_value' => $item->id,
      '#disabled' => TRUE,
    );
    $form['items'][$item->id]['type'] = array(
      '#type' => 'hidden',
      '#default_value' => $item->type,
    );
//    $form['items'][$item->id]['region'] = array(
//      '#type' => 'hidden',
//      '#default_value' => $item->region,
//    );
    $form['items'][$item->id]['bundle'] = array(
      '#type' => 'hidden',
      '#default_value' => $bundle,
    );
    $form['items'][$item->id]['title'] = array(
      '#type' => 'textfield',
      '#size' => 40,
      '#attributes' => $attr,
      '#default_value' => check_plain($item->title),
      '#group' => 'items',
    );
    // Caption for the itemshow.
    $form['items'][$item->id]['type'] = array(
      '#type' => 'select',
      '#options' => $form['act_types']['#value'],
      '#attributes' => $attr,
      '#disabled' => $disable,
      '#default_value' => $item->type,
    );
    // This field is invisible, but contains sort info (weights).
    $form['items'][$item->id]['weight'] = array(
      '#type' => 'weight',
      '#title' => t('Weight'),
      '#title_display' => 'invisible',
      '#default_value' => $item->weight,
    );
    $form['items'][$item->id]['pid'] = array(
      '#type' => 'hidden',
      '#default_value' => $item->pid,
      '#size' => 3,
    );
    $form['items'][$item->id]['depth'] = array(
      '#type' => 'hidden',
      '#value' => $item->depth,
    );
    // Operation links
    $form['items'][$item->id]['enabled'] = array(
      '#type' => 'checkbox',
      '#default_value' => $item->enabled,
    );
    $form['items'][$item->id]['edit'] = array(
      '#id' => 'btn' . $item->id,
      '#name' => 'btn' . $item->id,
      '#type' => 'submit',
      '#value' => t($btntext),
      '#attributes' => array(
        'class' => array('edit-row edit-row-' . $item->id)
      ),
      '#submit' => array('triage_org_filter_edit_submit')
    );
    // Operation links (to remove rows).
    $form['items'][$item->id]['remove'] = array(
      '#id' => 'del' . $item->id,
      '#name' => 'del' . $item->id,
      '#type' => 'submit',
      '#value' => t('Delete'),
      '#attributes' => array(
        'class' => array('del-row del-row-' . $item->id)
      ),
      '#submit' => array('triage_org_filter_delete_submit')
    );
  }
  $form['submit'] = array('#type' => 'submit', '#value' => t('Save'));
  $form['preview'] = array(
    '#type' => 'submit',
    '#value' => t('Preview'),
  );
  return $form;
}

function triage_org_filter_delete_submit($form, &$form_state) {
  global $base_url;
  $id = $form_state['triggering_element']['#id'];
  $id = str_replace("del", '', $id);
  $url = 'triage_org_filter_delete/' . $id;
  unset($form_state['storage']);
  $form_state['redirect'] = $url;
}

function triage_org_filter_edit_submit($form, &$form_state) {
  $nid = $_SESSION['triage']['org_filter']['nid'];
  $bundle = $_SESSION['triage']['org_filter']['bundle'];
  global $base_url;
  $id = $form_state['triggering_element']['#id'];
  $id = str_replace("btn", '', $id);
  $ray = $form_state['values']['items'][$id];
  if ($id == 0) {
    $id = db_insert('triage_org_conditions')
      ->fields(array(
        'title' => $ray['title'],
        'type' => $ray['type'],
        'weight' => $ray['weight'],
        'entity_id' => $nid,
        'bundle' => $bundle,
      ))
      ->execute();
  }
  $url = 'triage_org_filter/' . $id . '/edit';
  unset($form_state['storage']);
  $form_state['redirect'] = $url;
}

function triage_org_filters_list_manage_submit($form, &$form_state) {
  //dsm($form_state);
  $items = array();
  foreach ($form_state['values']['items'] as $item) {
    $items[] = array(
      'id' => $item['id'],
      'title' => $item['title'],
      'type' => $item['type'],
      'weight' => $item['weight'],
      'pid' => $item['pid'],
      'bundle' => $item['bundle'],
      'enabled' => $item['enabled'],
    );
  }
  if (!empty($items)) {
    usort($items, '_triage_actions_arraysort');
    foreach ($items as $item) {
      $found = db_query('select id from triage_org_conditions where id = :id', array(':id' => $item['id']));
      if ($found) {
        $num_updated = db_update('triage_org_conditions')
          ->fields(array(
            'weight' => $item['weight'],
            'pid' => $item['pid'],
            'enabled' => $item['enabled'],
          ))
          ->condition('id', $item['id'])
          ->execute();
      }
    }
  }
  drupal_set_message(t('Actions have been saved.'));
  $form_state['redirect'] = '/node/' . $_SESSION['triage']['org_filter']['nid'];
}

// Theme function for triage_actions_manage().
function theme_triage_org_filters_list($variables) {
  $_SESSION['triage']['triage_return_to'] = current_path();
  $my_return = array('path' => current_path());
  drupal_add_js(array('my_return' => $my_return), 'setting');
  global $base_url;
  $output = '';
  $bundle = 'node';
  $form = $variables['form'];
  $rows = array();
  foreach (element_children($form['items']) as $id) {
    $label = "Edit";
    $actid = $form['items'][$id]['id']['#value'];
    if ($actid == 0) {
      $label = "Add";
    }
    $type = $form['items'][$id]['type']['#value'];
    $form['items'][$id]['weight']['#attributes']['class'] = array('triage-order-weight');
//    $form['items'][$id]['id']['#attributes']['class'] = array('triage-order-id');
//    $form['items'][$id]['pid']['#attributes']['class'] = array('triage-order-pid');
    $indent = theme('indentation', array('size' => $form['items'][$id]['depth']['#value']));
    unset($form['items'][$id]['depth']);
    //unset($form['items'][$id]['edit']);
    $class = array('draggable');
    // We can add the 'tabledrag-root' class to a row in order to indicate
    // that the row may not be nested under a parent row.  In our sample data
    // for this example, the description for the item with id '8' flags it as
    // a 'root' item which should not be nested.
    if (in_array($form['items'][$id]['type']['#value'], array('group'))) {
      $class[] = 'tabledrag-root';
    }
    // We can add the 'tabledrag-leaf' class to a row in order to indicate
    // that the row may not contain child rows.  In our sample data for this
    // example, the description for the item with id '9' flags it as a 'leaf'
    // item which can not contain child items.
    if (in_array($form['items'][$id]['type']['#value'], array(
      'text',
      'reuse'
    ))) {
      $class[] = 'tabledrag-leaf';
    }
    $rows[] = array(
      'data' => array(
        $indent . drupal_render($form['items'][$id]['title']),
        drupal_render($form['items'][$id]['type']),
        drupal_render($form['items'][$id]['enabled']),
        drupal_render($form['items'][$id]['weight']),
//        drupal_render($form['items'][$id]['id']),
//        drupal_render($form['items'][$id]['pid']),
        drupal_render($form['items'][$id]['edit']),
        drupal_render($form['items'][$id]['remove']),
      ),
      'class' => $class,
    );
  }
  $header = array(
    t('Title'),
    t('Type'),
    t('Enabled'),
    t('Weight'),
    array('data' => t('Operations'), 'colspan' => 3),
  );
  $output .= "<div id='triage-filters'>";
  $output .= theme('table', array(
    'header' => $header,
    'rows' => $rows,
    'attributes' => array('id' => 'triage-order')
  ));
  $output .= drupal_render_children($form) . "</div>";
  if ($bundle == 'node') {
    $output .= "</div>";
  }
  //drupal_add_tabledrag('triage-order', 'match', 'parent', 'triage-order-pid', 'triage-order-pid', 'triage-order-id', TRUE);
  drupal_add_tabledrag('triage-order', 'order', 'sibling', 'triage-order-weight');
  return $output;
}

function triage_get_org_tree($nid = NULL, $bundle = 'node') {
  $query = db_select('triage_org_conditions', 'o');
  $query->fields('o', array("id", "pid", "title", "weight", "type", "enabled"));
  $query->condition('o.entity_id', $nid);
  $query->condition('o.bundle', $bundle);
  $query->orderBy(('o.weight'));
  //triage_dpq($query);
  $rootnodes = $query->execute()->fetchAll();
  // Initialize a variable to store our ordered tree structure.
  $itemtree = array();
  // Depth will be incremented in our _get_tree() function for the first
  // parent item, so we start it at -1.
  $depth = -1;
  // Loop through the root nodes, and add their trees to the array.
  foreach ($rootnodes as $parent) {
    triage_org_filter_tree($parent, $itemtree, $depth, $bundle, $nid);
  }
  return $itemtree;

}

function triage_org_filter_tree($parentitem, &$itemtree = array(), &$depth = 0, $bundle, $nid) {
  // Increase our $depth value by one.
  $depth++;
  // Set the current tree 'depth' for this item, used to calculate indentation.
  $parentitem->depth = $depth;
  // Add the parent item to the tree.
  $itemtree[$parentitem->id] = $parentitem;
  // Retrieve each of the children belonging to this parent.
  $query = db_select('triage_org_conditions', 'o');
  $query->fields('o', array("id", "pid", "title", "weight", "type", "enabled"));
  $query->condition('o.bundle', $bundle)
    ->condition('o.pid', $parentitem->id)
    ->orderBy('o.weight', 'ASC');
//  dsm(triage_dpq($query));
  $children = $query->execute()->fetchAll();
  foreach ($children as $child) {
    // Make sure this child does not already exist in the tree, to avoid loops.
    if (!in_array($child->id, array_keys($itemtree))) {
      // Add this child's tree to the $itemtree array.
      triage_org_filter_tree($child, $itemtree, $depth, $bundle, $nid);
    }
  }
  // Finished processing this tree branch.  Decrease our $depth value by one
  // to represent moving to the next branch.
  $depth--;
}

function triage_org_filter_form($form, &$form_state, $id = 0) {
  $multiselectpath = drupal_get_path('module', 'multiselect');
  $term_reference_tree_path = drupal_get_path('module', 'term_reference_tree');
  $triage_vid = taxonomy_vocabulary_machine_name_load(variable_get('triage_default_voc', "mi_triage"))->vid;
  $ta_node = triage_get_page($triage_vid);
  $ta_nid = $ta_node->nid;
  $legal_cats = ta_variable_get('triage_legal_categories', '', $ta_nid);
  $state = ta_variable_get('triage_state', '', $ta_nid);
  $nid = $_SESSION['triage']['org_filter']['nid'];
  $bundle = $_SESSION['triage']['org_filter']['bundle'];
  $_SESSION['triage']['triage_page_nid'] = $ta_nid;
  $act_title = db_query('select title from triage_org_conditions where id = :id', array(':id' => $id))->fetchColumn();
  $type = "";

  // BEGIN legal problem visibility section
  $vals = db_query('select legal_problem from triage_org_conditions where id = :id', array(':id' => $id))->fetchColumn();
  $lps = explode(",", $vals);
  $legal_problem_info = array();
  foreach($lps as $lp){
    $legal_problem_info[$lp] = $lp;
  }
  // END legal problem visibility section

  // BEGIN status visibility section
  $vid = ta_variable_get('triage_status_voc', '', $ta_nid);
  $sql = 'select tid, name from taxonomy_term_data where vid = :vid';
  $status_opts = db_query($sql, array(':vid'=>$vid))->fetchAllKeyed();
  $vals = db_query('select status_filter from triage_org_conditions where id = :id', array(':id' => $id))->fetchColumn();
  $status_info = explode(",", $vals);
  // END status visibility section

  // BEGIN income visibility section
  $vid = ta_variable_get('triage_income_eligibility', 'triage_income_eligibility', $ta_nid);
  $sql = 'select tid, name from taxonomy_term_data where vid = :vid';
  $income_opts = db_query($sql, array(':vid'=>$vid))->fetchAllKeyed();
  $vals = db_query('select income_filter from triage_org_conditions where id = :id', array(':id' => $id))->fetchColumn();
  $income_info = $vals;
  // END income visibility section

  // BEGIN County visibility section
  $county_opts = triage_county_data($state);
  $vals = db_query('select county_filter from triage_org_conditions where id = :id', array(':id' => $id))->fetchColumn();
  $county_info = explode(",", $vals);
  // END county visibility section

  $action = db_query("select * from triage_org_conditions where id=:id",array(":id" => $id))->fetchAssoc();
  $form['action_title'] = array(
    '#markup' => "<div class='triage-action-title'>" . $act_title . "</div>",
  );
  $form['id'] = array(
    '#type' => 'hidden',
    '#default_value' => $id,
  );
  $form['bundle'] = array(
    '#type' => 'hidden',
    '#default_value' => $bundle,
  );
  $form['triage_org_filter'] = array(
    '#type' => 'vertical_tabs',
  );
  $form['triage_org_filter']['general_info'] = array(
    '#type' => 'fieldset',
    '#title' => t('ID Info'),
    '#collapsible' => TRUE,
    '#collapsed' => FALSE,
    '#weight' => 0,
    '#description' => t('Title and kind of qualifier'),
    '#tree' => TRUE,
    '#group' => 'triage_org_filter',
  );

  $form['triage_org_filter']['general_info']['triage_org_filter_title'] = array(
    '#type' => 'textfield',
    '#title' => t('Title'),
    '#description' => 'Administrative reference to filter',
    '#default_value' => $action['title'],
    '#prefix' => "<div class='two-panel'>",
    '#suffix' => "</div>",
  );
  $form['triage_org_filter']['general_info']['triage_org_filter_type'] = array(
    '#type' => 'select',
    '#title' => t('Kind of filter'),
    '#options' => array('include'=>'include','exclude'=>'exclude'),
    '#default_value' => $action['type'],
    '#prefix' => "<div class='two-panel'>",
    '#suffix' => "</div>",
  );
  $form['triage_org_filter']['general_info']['separation1'] = array(
    '#markup' => "<div class='clear-both'></div>",
  );


  $form['triage_org_filter']['triage_legal_problem_set'] = array(
    '#type' => 'fieldset',
    '#title' => t('Relevant Legal Problems'),
    '#collapsible' => TRUE,
    '#collapsed' => FALSE,
    '#weight' => 1,
    '#description' => t('Legla Problems served by organization.'),
    '#tree' => TRUE,
    '#group' => 'triage_org_filter',
  );

  $form['triage_org_filter']['triage_legal_problem_set']['tree'] = array(
    '#title' => t('Legal Issues Served'),
    '#name' => 'legal_problems',
    '#type' => 'checkbox_tree',
    '#default_value' => $legal_problem_info,
    '#cascading_selection' => true,
    '#max_choices' => 999,
    '#max_depth' => 999,
    '#field_name' => 'custom_name',
    '#leaves_only' => 0,
    '#start_minimized' => TRUE,
    '#depth' => 0,
    '#vocabulary' => taxonomy_vocabulary_load($legal_cats),
    '#parent_tid' => 0,
    '#value_key' => 'tid',
    '#select_parents' => TRUE,
    '#attached' => array(
      'js' => array($term_reference_tree_path . '/term_reference_tree.js'),
      'css' => array($term_reference_tree_path . '/term_reference_tree.css')
    ),
    '#attributes' => array('class' => array('field-widget-term-reference-tree')),
    '#element_validate' => array('_term_reference_tree_widget_validate'),
    '#value' => $legal_problem_info,
    '#filter_view' => '',
    '#token_display' => ''
  );
  $form['triage_org_filter']['triage_actions_income_set'] = array(
    '#type' => 'fieldset',
    '#title' => t('Income visibility'),
    '#collapsible' => TRUE,
    '#collapsed' => TRUE,
    '#weight' => 2,
    '#description' => t('Income Criteria'),
    '#tree' => TRUE,
    '#group' => 'triage_org_filter',
  );
  $form['triage_org_filter']['triage_actions_income_set']['income_show'] = array(
    '#type' => 'textfield',
    '#maxlength' => 4,
    '#title' => t('Set % of Poverty Guidelines at or below which service is provided'),
    '#default_value' => $income_info,
  );
  $form['triage_org_filter']['triage_actions_status_set'] = array(
    '#type' => 'fieldset',
    '#title' => t('Status visibility'),
    '#collapsible' => TRUE,
    '#collapsed' => TRUE,
    '#weight' => 3,
    '#description' => t('Select Status items that are part of this qualification'),
    '#tree' => TRUE,
    '#group' => 'triage_org_filter',
  );
  $form['triage_org_filter']['triage_actions_status_set']['status_show'] = array(
    '#type' => 'checkboxes',
    '#title' => t('Show action item to users with group status qualifications'),
    '#options' => $status_opts,
    '#default_value' => $status_info,
  );
  $form['triage_org_filter']['triage_actions_county_set'] = array(
    '#type' => 'fieldset',
    '#title' => t('County visibility'),
    '#collapsible' => TRUE,
    '#collapsed' => TRUE,
    '#weight' => 4,
    '#description' => t('Choose counties that apply'),
    '#tree' => TRUE,
    '#group' => 'triage_org_filter',
  );
  $form['triage_org_filter']['triage_actions_county_set']['county_info'] = array(
    '#type' => 'multiselect',
    '#name' => 'counties',
    '#title' => t('Select relevant counties'),
    '#options' => $county_opts,
    '#required' => FALSE,
    '#default_value' => $county_info,
    '#attached' => array(
      'js' => array($multiselectpath . '/multiselect.js'),
      'css' => array($multiselectpath . '/multiselect.css')
    ),
    '#size' => 15,
  );
  $form['submit'] = array(
    '#type' => 'submit',
    '#weight' => 7,
    '#value' => t('Save changes'),
    '#submit' => array('triage_org_filter_submit'),
  );
  return $form;
}

/**
 * Implements hook_form_alter().
 */
function _triage_org_county_validate(&$element, &$form_state) {
  $bds = '';
}
function _triage_org_tree_widget_validate(&$element, &$form_state) {
  $items = _term_reference_tree_flatten($element, $form_state);
  //return true;

  $value = array();

  if (isset($element['#max_choices']) && $element['#max_choices'] != 1) {
    foreach ($items as $child) {
      if (!empty($child['#value'])) {
        array_push($value, array($element['#value_key'] => $child['#value']));

        // If the element is leaves only and select parents is on, then automatically
        // add all the parents of each selected value.
        if ($element['#select_parents'] && $element['#leaves_only']) {
          foreach ($child['#parent_values'] as $parent_tid) {
            if (!in_array(array($element['#value_key'] => $parent_tid), $value)) {
              array_push($value, array($element['#value_key'] => $parent_tid));
            }
          }
        }
      }
    }
  }
  else {
    // If it's a tree of radio buttons, they all have the same value, so we can just
    // grab the value of the first one.
    if (count($items) > 0) {
      $child = reset($items);
      if (!empty($child['#value'])) {
        array_push($value, array($element['#value_key'] => $child['#value']));
      }
    }
  }
  $element['#value'] = $value;
  $bds = '';
  return true;
}
function triage_org_filter_submit($form, &$form_state) {
  $bds = '';
  global $base_url;
  $probs = $form_state['values']['triage_legal_problem_set']['tree'];
  $prob = array();
  foreach($probs as $pr){
    $prob[] = $pr['tid'];
  }
  $problem_areas = _triage_actions_serialize_tids($prob);
  $id = $form_state['values']['id'];
  $title = $form_state['values']['general_info']['triage_org_filter_title'];
  $type = $form_state['values']['general_info']['triage_org_filter_type'];
  $bundle = $form_state['values']['bundle'];
  $income = $form_state['values']['triage_actions_income_set']['income_show'];
  $status = _triage_actions_serialize_tids($form_state['values']['triage_actions_status_set']['status_show']);
  $counties = _triage_actions_serialize_tids($form_state['input']['counties']);
  db_update('triage_org_conditions')
    ->fields(array(
      'title' => $title,
      'type' => $type,
      'legal_problem' => $problem_areas,
      'income_filter' => $income,
      'status_filter' => $status,
      'county_filter' => $counties,
      'bundle' => $bundle,
    ))
    ->condition('id', $id)
    ->execute();
  switch ($bundle) {
    case 'node':
      $url = '/node/' . $_SESSION['triage']['org_filter']['nid'] . '/triage_org_filter';
      break;
    default:
      $url = $base_url;
  }
  $form_state['redirect'] = $url;
}
function triage_org_filter_delete_confirm($form, &$form_state, $id = 0) {
  $form['id'] = array('#type' => 'value', '#value' => $id);
  $title = db_query('select title from triage_org_conditions where id = :id', array(":id" => $id))->fetchColumn();
  $msg = t('Are you sure you want to delete %title?', array('%title' => $title));
  $url = '';
  return confirm_form($form, $msg, $url, t('This action cannot be undone.'), t('Delete'), t('Cancel')
  );
}
function triage_org_filter_delete_confirm_submit($form, &$form_state) {
  $nid = $_SESSION['triage']['org_filter']['nid'];
  $bundle = $_SESSION['triage']['org_filter']['bundle'];
  $id = $form_state['values']['id'];
  $title = db_query('select title from triage_org_conditions where id = :id', array(":id" => $id))->fetchColumn;
  if ($form_state['values']['confirm']) {
    db_query('delete from triage_org_conditions where id = :id', array(':id' => $id));
    drupal_set_message(t('Triage Org Condition %title has been deleted.', array('%title' => $title)));
  }
  $url = '/node/' . $nid . '/triage_org_filter';
  $form_state['redirect'] = $url;
}


