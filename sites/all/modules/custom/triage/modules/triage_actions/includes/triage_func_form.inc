<?php
function triage_action_func_form($form, &$form_state,$id){
  $bundle = $_SESSION['triage']['my_bundle'];
  if ($bundle == 'help'){
    $form_opts = array(
      'none' => 'None',
      'triagepath' => 'Legal Problem Answers',
      'triagequests' => 'Answers to Preliminary Questions',
      'triagedesc' => 'Question description, help and info',
      'triage_language' => 'Translation Block',
    );
    $region_opts = array(
      'none' => 'None',
      'ta-message-panel' => 'Top Message Panel',
      'ta-main-panel' => 'Main Panel',
      'ta-help-panel' => 'Help Panel',
      'ta-bottom-panel' => 'Bottom Panel',
    );
  }
  if ($bundle == 'quests'){
    $form_opts = array(
      'none' => 'None',
      'triagequests' => 'Answers to Preliminary Questions',
      'triage_restart' => 'Restart Button',
      'triagedesc' => 'Question description, help and info',
      'triage_language' => 'Translation Block',
    );
    $region_opts = array(
      'none' => 'None',
      'ta-message-panel' => 'Top Message Panel',
      'ta-help-panel' => 'Help Panel',
      'ta-bottom-panel' => 'Bottom Panel',
    );
  }
  $classlist=variable_get('triage_custom_classes','');
  $class_list = explode("\n",$classlist);
  $class_opts = array();
  foreach($class_list as $class){
    if (substr($class,0,1)=="*"){continue;}
    $break = strpos($class,"~");
    if ($break==false){continue;}
    $key = substr($class,0,$break);
    $display = substr($class,$break+1);
    $class_opts[$key] = $display;
  }
  $print_opts = array(
    '' => 'Show on all',
    'print_only' => 'Print Only',
    'non_print' => 'Exclude from Print',
  );  
  // eof status visibility section
  $action = db_query("select title, 
              display_header, 
              reusable_text, 
              action_text,
              action_text_format,
              extra,
              classes,
              region,
              node_view_opt,
              node_ref_nid
              from triage_actions 
              where id=:id",array(":id"=>$id))->fetchAssoc();
  $form['id'] = array(
      '#type' => 'hidden',
      '#default_value' => $id,
  );
  $form['bundle'] = array(
      '#type' => 'hidden',
      '#default_value' => $bundle,
  );
  $form['title'] = array(
      '#type' => 'textfield',
      '#title' => t('Title'),
      '#default_value' => $action['title'],
      '#prefix' => "<div class='two-panel'>",
      '#suffix' => "</div>",
  );
  $form['display_header'] = array(
      '#type' => 'textfield',
      '#description' => 'Display header takes precedence over title in display.  Enter &#60;none&#62; for no title/display header',
      '#title' => t('Display Header'),
      '#default_value' => $action['display_header'],
      '#prefix' => "<div class='two-panel'>",
      '#suffix' => "</div>",
  );
  $form['separation1'] = array(
      '#markup' => "<div class='clear-both'></div>",
  ); 
  $form['region'] = array(
      '#type' => 'select',
      '#title' => t('Region where item should be display'),
      '#options' => $region_opts,
      '#default_value' => $action['region'],
      '#prefix' => "<div class='two-panel'>",
      '#suffix' => "</div>",
  );
  $form['classes'] = array(
      '#type' => 'select',
      '#title' => t('Classes'),
      '#options' => $class_opts,
      '#default_value' => $action['classes'],
      '#prefix' => "<div class='two-panel'>",
      '#suffix' => "</div>",
  );
  $form['separation2'] = array(
      '#markup' => "<div class='clear-both'></div>",
  );
  $form['action_text'] = array(
      '#type' => 'select',
      '#title' => t('Function or Form'),
      '#options' => $form_opts,
      '#default_value' => $action['action_text'],
      '#prefix' => "<div class='two-panel'>",
      '#suffix' => "</div>",
  );
  $form['extra'] = array(
      '#type' => 'textfield',
      '#description' => 'Text, if any, to introduce list of answers, e.g. <em>You Said:</em>',
      '#title' => t('Introductory Phrase'),
      '#default_value' => $action['extra'],
      '#states' => array(
        'visible' => array(
          ':input[name="action_text"]' => array('value' => 'triagepath'),
        ),
      ),
      '#prefix' => "<div class='two-panel'>",
      '#suffix' => "</div>",
  );
  $form['separation3'] = array(
      '#markup' => "<div class='clear-both'></div>",
  );  
  if ($bundle == 'help'){
    $form['print_visibility'] = array(
        '#type' => 'select',
        '#title' => t('Print Visibility'),
        '#options' => $print_opts,
        '#default_value' => $action['node_view_opt'],
        '#prefix' => "<div class='two-panel'>",
        '#suffix' => "</div>",
    );
  }
  $form['separation4'] = array(
      '#markup' => "<div class='clear-both'></div>",
  );
  $form['submit'] = array(
      '#type' => 'submit', 
      '#weight' => 7,
      '#value' => t('Save changes'));
  return $form;
}
function triage_action_func_form_submit($form, &$form_state){
  global $base_url;
  //dsm($form_state);
  $id = $form_state['values']['id'];
  $title = $form_state['values']['title'];
  $header = $form_state['values']['display_header'];
  $bundle = $form_state['values']['bundle'];
  $region = $form_state['values']['region'];
  $print = $form_state['values']['print_visibility'];
  if(is_null($region) || trim($region)==""){
    $region = "ta-main-panel";
  }    
  $classes = $form_state['values']['classes'];  
  $text = $form_state['values']['action_text'];
  $extra = $form_state['values']['extra'];
  db_update('triage_actions')
    ->fields(array(
      'title' => $title,
      'display_header' => $header,
      'bundle' => $bundle,
      'action_text' => $text,
      'extra' => $extra,
      'node_view_opt' => $print,
      'region' => $region,
      'classes' => $classes,
    ))
    ->condition('id',$id)
    ->execute();
  switch ($bundle){
    case 'taxonomy':
      $url = $return_dest;
      break;
    case 'node':
      $url = '/node/' . $_SESSION['triage']['edit_tid'] . '/triage_build';
      break;
    case 'help':
      $url = '/node/' . $_SESSION['triage']['edit_tid'] . '/triage_build/actions_out';
      break;
    case 'quests':
      $url = '/node/' . $_SESSION['triage']['edit_tid'] . '/triage_build/actions_questions';
      break;
  }
  $form_state['redirect'] = $url;
}