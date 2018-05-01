<?php
function triage_actions_manage() {
    global $base_url;
    $vid = $_SESSION['triage']['triage_actions_admin_voc'];
    $node = triage_get_page($vid);
    $nid = $node->nid;

    drupal_add_js($base_url . "/misc/tabledrag.js", "file");
    $bundle = $_SESSION['triage']['my_bundle'];
    $default_region = 'ta-main-panel';
    $actionTypes = array(
        'text' => 'Custom Text',
        'reuse' => 'Reusable Text',
        'node' => 'Node Content',
        'div' => 'Display Wrapper',
    );
    $region_opts = array(
        'none' => 'None',
        'ta-message-panel' => 'Top Message Panel',
        'ta-main-panel' => 'Main Panel',
        'ta-help-panel' => 'Help Panel',
        'ta-bottom-panel' => 'Bottom Panel',
    );
    switch ($bundle) {
        case 'taxonomy':
            $default_region = 'ta-main-panel';
            break;
        case 'help':
            $default_region = 'ta-help-panel';
            $actionTypes['srch'] = 'Triage Search Results';
            $actionTypes['orgsrch'] = 'Triage Organizational Search Results';
            $actionTypes['form'] = 'User Info Form';
            $actionTypes['func'] = 'Miscellaneous Functions';
            break;
        case 'node':
            $default_region = 'ta-main-panel';
            $actionTypes['form'] = 'User Info Form';
            $actionTypes['group'] = 'Navigation Wrapper';
            break;
        case 'quests':
            unset($region_opts['ta-main-panel']);
            $actionTypes['func'] = 'Miscellaneous Functions';
            $actionTypes['form'] = 'User Info Form';
            break;
    }
//  if ($bundle == 'taxonomy'){
//  }
//  else {
//    $actionTypes['form'] = 'User Info Form';
//    $actionTypes['group'] = 'Navigation Wrapper';
//  }
    $this_tid = $_SESSION['triage']['edit_tid'];
    //$this_tid = 917;
    $items = array();
    $tems = array();
    $form = array();
    $form['#attached']['library'][] = array('system', 'tabledrag');
    $realitems = triage_actions_parent_get_data($bundle, $this_tid);
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
            'text' => $ri->action_text,
            'language' => $ri->language,
            'region' => $ri->region,
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
        'text' => '',
        'language' => 'und',
        'region' => $default_region,
        'type' => 0,
        'enabled' => true,
    );
    $items = json_decode(json_encode($tems), FALSE);
    //dsm($items);
    $form['#tree'] = TRUE;
    $form['act_types'] = array(
        '#type' => 'value',
        '#value' => $actionTypes
    );
    $form['region_types'] = array(
        '#type' => 'value',
        '#value' => $region_opts
    );


    foreach ($items as $item) {
        $attr = array();
        $disable = false;
        if ($item->id > 0) {
            $attr = array(
                'readonly' => 'readonly',
                'class' => array('readonly-input')
            );
            $disable = true;
            $btntext = "Edit";
        } else {
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
        $form['items'][$item->id]['region'] = array(
            '#type' => 'select',
            '#options' => $form['region_types']['#value'],
            '#attributes' => $attr,
            '#disabled' => $disable,
            '#default_value' => $item->region,
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
            '#type' => 'textfield',
            '#default_value' => $item->pid,
            '#size' => 3,
        );
        $form['items'][$item->id]['depth'] = array(
            '#type' => 'hidden',
            '#value' => $item->depth,
        );
        // Operation links
        $form['items'][$item->id]['translate'] = array(
            '#id' => 'trans' . $item->id,
            '#name' => 'trans' . $item->id,
            '#type' => 'submit',
            '#value' => t('Translate'),
            '#attributes' => array(
                'class' => array('trans-row trans-row-' . $item->id)),
            '#submit' => array('triage_actions_translate_submit')
        );
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
                'class' => array('edit-row edit-row-' . $item->id)),
            '#submit' => array('triage_actions_edit_submit')
        );
        // Operation links (to remove rows).
        $form['items'][$item->id]['remove'] = array(
            '#id' => 'del' . $item->id,
            '#name' => 'del' . $item->id,
            '#type' => 'submit',
            '#value' => t('Delete'),
            '#attributes' => array(
                'class' => array('del-row del-row-' . $item->id)),
            '#submit' => array('triage_actions_delete_submit')
        );
    }
    $form['submit'] = array('#type' => 'submit', '#value' => t('Save'));
    $form['preview'] = array(
        '#type' => 'submit',
        '#value' => t('Preview'),
    );
  if (ta_variable_get('triage_use_wrap_templates', false, $nid)) {
    $opts = db_query("select distinct extra from triage_actions where type = 'div'");
    $options = array();
    foreach ($opts as $opt) {
      $options[$opt->extra] = $opt->extra;
    }
    $form['triage_clone_divs_form'] = array(
      '#type' => 'select',
      '#title' => 'Select Display Wrapper Template that you would like to clone',
      '#options' => $options,
      '#default_value' => '',
      '#prefix' => "<div class='triage-clone-divs'>",
    );
    $form['clone'] = array(
      '#type' => 'submit',
      '#attributes' => array(
        'class' => array('triage-action-button')
      ),
      '#value' => t('Clone'),
      '#suffix' => '</div>'
    );
  }
    return $form;
}
function triage_actions_delete_submit($form, &$form_state) {
    global $base_url;
    $id = $form_state['triggering_element']['#id'];
    $id = str_replace("del", '', $id);
    $url = 'triage_actions_delete/' . $id;
    unset($form_state['storage']);
    $form_state['redirect'] = $url;
}
function triage_actions_edit_submit($form, &$form_state) {
    global $language;
    global $base_url;
    $bundle = $_SESSION['triage']['my_bundle'];
    $tid = $_SESSION['triage']['edit_tid'];
    $id = $form_state['triggering_element']['#id'];
    $id = str_replace("btn", '', $id);
    $ray = $form_state['values']['items'][$id];
    if ($id == 0) {
        $id = db_insert('triage_actions')
                ->fields(array(
                    'title' => $ray['title'],
                    'type' => $ray['type'],
                    'weight' => $ray['weight'],
                    'language' => $language->language,
                    'entity_id' => $tid,
                    'bundle' => $bundle,
                    'region' => $ray['region'],
                ))
                ->execute();
    }
    $url = 'taxonomy/actions/' . $id . '/' . $ray['type'] . '/edit';
    unset($form_state['storage']);
    $form_state['redirect'] = $url;
}
function triage_actions_translate_submit($form, &$form_state) {
    global $language;
    global $base_url;
    $bundle = $_SESSION['triage']['my_bundle'];
    $tid = $_SESSION['triage']['edit_tid'];
    $id = $form_state['triggering_element']['#id'];
    $id = str_replace("trans", '', $id);
    $url = 'triage_actions_translate/' . $id;
    unset($form_state['storage']);
    $form_state['redirect'] = $url;
}
function triage_actions_manage_submit($form, &$form_state) {
    //dsm($form_state);
    $template = $form_state['input']['triage_clone_divs_form'];
    if ($form_state['triggering_element']['#value'] == "Clone"){
      if ($template and trim($template) > "") {
        dsm("Cloned " . $template);
        $this_tid = $_SESSION['triage']['edit_tid'];
        $sql = 'drop temporary table if exists display_template';
        db_query($sql);
        $sql = "create temporary table display_template select * from triage_actions where type = 'div' and extra = :extra";
        db_query($sql, array(':extra'=>$template));
        $sql = "update display_template set extra = '' ";
        db_query($sql);
        $sql = 'update display_template set entity_id = :id';
        db_query($sql, array(':id'=>$_SESSION['triage']['edit_tid']));
        $sql = 'update display_template set id = 0';
        db_query($sql);
        db_query('insert into triage_actions select * from display_template');
      }
      return;
    }
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
            $found = db_query('select id from triage_actions where id = :id', array(':id' => $item['id']));
            if ($found) {
                $num_updated = db_update('triage_actions')
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
    if ($_SESSION['triage']['my_bundle'] == 'taxonomy') {
        if ($form_state['triggering_element']['#value'] == "Preview") {
            $this_tid = $_SESSION['triage']['edit_tid'];
            $url = "triage_actions_process/" . $this_tid . "/1";
            $form_state['redirect'] = $url;
        } else {
            $form_state['redirect'] = 'triage_actions_admin';
        }
    } elseif ($_SESSION['triage']['my_bundle'] == 'node') {
        $form_state['redirect'] = '/node/' . $_SESSION['triage']['edit_tid'];
    } else {
        $form_state['redirect'] = '/node/' . $_SESSION['triage']['edit_tid'];
    }
}
function triage_action_admin_actions_form() {
    $vocs = taxonomy_get_vocabularies();
    $default = variable_get('triage_actions_admin_voc', null);
    $options = array();
    foreach ($vocs as $voc) {
        $options[$voc->vid] = $voc->name;
    }
    $form['triage_actions_admin_voc'] = array(
        '#type' => 'select',
        '#options' => $options,
        '#default_value' => $default,
    );
    $form['submit'] = array(
        '#type' => 'submit',
        '#attributes' => array(
            'class' => array('triage-action-button')),
        '#value' => t('Filter')
    );
    return $form;
}
function triage_action_admin_actions_form_submit($form, &$form_state) {
    $_SESSION['triage']['triage_actions_admin_voc'] = $form_state['values']['triage_actions_admin_voc'];
    variable_set('triage_actions_admin_voc', $_SESSION['triage']['triage_actions_admin_voc']);
    $form_state['redirect'] = 'triage_actions_admin';
}
function triage_action_admin_reuse_form() {
    $vocs = taxonomy_get_vocabularies();
    $options = array();
    foreach ($vocs as $voc) {
        $options[$voc->vid] = $voc->name;
    }
    $form['triage_actions_admin_voc'] = array(
        '#type' => 'select',
        '#options' => $options,
        '#attributes' => array(
            'class' => array('triage-action-filter')),
        '#default_value' => $_SESSION['triage']['triage_actions_admin_voc'],
    );
    $form['triage_actions_admin_keyword'] = array(
        '#type' => 'textfield',
        '#default_value' => $_SESSION['triage']['triage_reusable_filter'],
        '#attributes' => array(
            'class' => array('triage-action-filter'),
            'placeholder' => t('Enter filter keyword')),
    );
    $form['reusable_text'] = array(
        '#type' => 'checkbox',
        '#title' => t('Reusable Text Only'),
        '#default_value' => $_SESSION['triage']['triage_reusable_text_only'],
    );
    $form['submit'] = array(
        '#type' => 'submit',
        '#attributes' => array(
            'class' => array('triage-action-button', 'triage-action-filter')),
        '#value' => t('Filter')
    );
    $form['clear'] = array(
        '#type' => 'submit',
        '#attributes' => array(
            'class' => array('triage-action-button')),
        '#value' => t('Clear')
    );
    return $form;
}
function triage_action_admin_reuse_form_submit($form, &$form_state) {
    //dsm($form_state);
    $_SESSION['triage']['triage_actions_admin_voc'] = $form_state['values']['triage_actions_admin_voc'];
    $_SESSION['triage']['triage_reusable_filter'] = $form_state['values']['triage_actions_admin_keyword'];
    $_SESSION['triage']['triage_reusable_text_only'] = $form_state['values']['reusable_text'];
    if ($form_state['triggering_element']['#value'] == "Clear") {
        $_SESSION['triage']['triage_reusable_filter'] = '';
        $_SESSION['triage']['triage_reusable_text_only'] = 0;
    }
    $form_state['redirect'] = 'triage_actions_reuse_editor';
}
function triage_actions_delete_confirm($form, &$form_state, $id = 0, $delete_group = 0) {
    // Always provide entity id in the same form key as in the entity edit form.
    // $delete_group = 1 if we're coming from the reusable text editor, otherwise 0
    $_SESSION['triage']['delete_group'] = $delete_group;
    $num = 0;
    $drop_entity_only = false;
    $form['id'] = array('#type' => 'value', '#value' => $id);
    $reusable = db_query('select id from triage_actions where reusable_text = 1', array(":id" => $id))->fetchColumn();
    if ($reusable) {
        $query = db_select('triage_actions', 'ta');
        $query->fields('ta', array('id'));
        $query->condition('node_ref_nid', $id)
                ->condition('type', 'reuse');
        $result = $query->execute();
        $num = $result->rowCount();
        if ($num > 0) {
            $drop_entity_only = true;
        }
    }
    $title = db_query('select title from triage_actions where id = :id', array(":id" => $id))->fetchColumn();
    $msg = t('Are you sure you want to delete %title?', array('%title' => $title));
    if ($drop_entity_only) {
        $msg = "This text is marked as re-usable and is in use by other entities<br />";
        $msg .= "Deleting it will remove its association with this item only<br />";
        $msg .= "It will continue to be available to other entities as re-usable text<br /><br />";
        $msg .= t('Do you want to delete this instance of %title?', array('%title' => $title));
        if ($delete_group) {
            $msg = "This reusable text is being referenced by " . $num . " other actions<br />";
            $msg .= "All references will also be deleted<br /><br />";
            $msg .= t('Do you want to delete %title?', array('%title' => $title));
        }
    }
    $url = 'triage_actions_reuse_editor';
    return confirm_form($form, $msg, $url, t('This action cannot be undone.'), t('Delete'), t('Cancel')
    );
}
function triage_actions_delete_confirm_submit($form, &$form_state) {
    $delete_group = $_SESSION['triage']['delete_group'];
    //dsm($delete_group);
    $_SESSION['triage']['delete_group'] = 0;
    $bundle = $_SESSION['triage']['my_bundle'];
    $id = $form_state['values']['id'];
    $title = db_query('select title from triage_actions where id = :id', array(":id" => $id))->fetchColumn();
    $drop_entity_only = false;
    $reusable = db_query('select id from triage_actions where reusable_text = 1 and id = :id', array(":id" => $id))->fetchColumn();
    if ($reusable) {
        if ($delete_group) {
        } else {
            $query = db_select('triage_actions', 'ta');
            $query->fields('ta', array('id'));
            $query->condition('node_ref_nid', $id)
                    ->condition('type', 'reuse');
            $result = $query->execute();
            $num = $result->rowCount();
            if ($num > 0) {
                $drop_entity_only = true;
            }
        }
    }
    if ($form_state['values']['confirm']) {
        if ($drop_entity_only && !$delete_group) {
            db_query('update triage_actions set entity_id = 0 where id = :id', array(':id' => $id));
            drupal_set_message(t('Triage Action %title has been removed from this entity but is still available as reusable text.', array('%title' => $title)));
        } else {
            db_query('delete from triage_actions where id = :id', array(':id' => $id));
            if ($delete_group) {
                db_query("delete from triage_actions where type = 'reuse' and node_ref_nid = :id", array(':id' => $id));
                drupal_set_message(t('Triage Action %title and its references have been deleted.', array('%title' => $title)));
            } else {
                drupal_set_message(t('Triage Action %title has been deleted.', array('%title' => $title)));
            }
        }
    }
    if ($delete_group) {
        $url = 'triage_actions_reuse_editor';
    } else {
        if ($bundle == 'taxonomy') {
            $url = '/taxonomy/term/' . $_SESSION['triage']['edit_tid'] . '/actions';
        } else {
            $url = '/node/' . $_SESSION['triage']['edit_tid'] . '/actions';
        }
    }
    $form_state['redirect'] = $url;
}
function triage_clone_divs_form() {
  $opts = db_query("select distinct extra from triage_actions where type = 'div'");
  $options = array();
  $options[' '] = "none";
  foreach ($opts as $opt) {
    $options[$opt->extra] = $opt->extra;
  }
  $form['triage_clone_divs_form'] = array(
    '#type' => 'select',
    '#title' => 'Select Display Wrapper Template that you would like to clone',
    '#options' => $options,
    '#default_value' => $default,
    '#prefix' => "<div class='triage-clone-divs'>",
  );
  $form['submit'] = array(
    '#type' => 'submit',
    '#attributes' => array(
      'class' => array('triage-action-button')),
    '#value' => t('Clone'),
    '#suffix' => '</div>'
  );
  return $form;
}