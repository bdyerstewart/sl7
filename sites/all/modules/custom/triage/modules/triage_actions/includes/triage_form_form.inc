<?php
function triage_action_form_form($form, &$form_state,$id){
  $bundle = $_SESSION['triage']['my_bundle'];
  $form_opts = array(
    'none' => 'None',
    'triage_zip_form' => 'Zip Code or Town',
    'triage_pov_form' => 'Income Info',
    'triage_income_form' => 'Income Info with Period',
    'triage_bank_form' => 'Bank Account',
    'triage_status_form' => 'Status or Demographic Group',
    'triage_whois_form' => 'Who is seeking help',
    'triage_followup_form' => 'Additional Factors',
  );
  if ($bundle=='help'){
      $form_opts['triage_print_form'] = 'Print and Email Options';
      $form_opts['triage_suggestion_form'] = 'I Have Another Problem';
      $form_opts['triage_problem_form'] = 'In my own words...';
  } 
  if ($bundle=='node'){
    $form_opts['triage_in_service_area_form'] = 'Service Area';
    $form_opts['triage_location_form'] = 'Service Area and County';
  }
  if ($bundle=='quests'){
    $form_opts['triage_suggestion_form'] = 'Suggestion Form';
    $form_opts['triage_problem_form'] = 'In my own words...';
  }
  $classlist=variable_get('triage_custom_classes','');
  $class_list = explode("\n",$classlist);
  $class_opts = array();
  $act_title = db_query('select title from triage_actions where id = :id', array(':id'=>$id))->fetchColumn();
  foreach($class_list as $class){
    if (substr($class,0,1)=="*"){continue;}
    $break = strpos($class,"~");
    if ($break==false){continue;}
    $key = substr($class,0,$break);
    $display = substr($class,$break+1);
    $class_opts[$key] = $display;
  }
  $region_opts = array(
    'none' => 'None',
    'ta-message-panel' => 'Top Message Panel',
    'ta-main-panel' => 'Main Panel',
    'ta-help-panel' => 'Help Panel',
    'ta-bottom-panel' => 'Bottom Panel',
  );
  if ($bundle=='quests'){
    unset($region_opts['ta-main-panel']);
  }
  // Get status taxonomy for this visibility
  $vid = $_SESSION['triage']['triage_actions_admin_voc'];
  $node = triage_get_page($vid);
  $nid = $node->nid;
  $_SESSION['triage']['triage_page_nid'] = $nid;
  $vid = ta_variable_get('triage_status_voc','',$nid);
  $sql = "select tid,name from taxonomy_term_data where vid = :vid"; 
  $sTypes = db_query($sql,array(':vid'=>$vid));
  $status_opts=array();
  $vals = db_query('select show_status from triage_actions where id = :id and language = :lang',
            array(':id'=>$id,':lang' => $lang))->fetchColumn();
  $status_info_show = explode(",",$vals);
  $vals = db_query('select hide_status from triage_actions where id = :id and language = :lang',
            array(':id'=>$id,':lang' => $lang))->fetchColumn();
  $status_info_hide = explode(",",$vals);
  foreach ($sTypes as $vt){
      $status_opts[$vt->tid] = $vt->name;
  }
  // eof status visibility section
  // Get income eligibility taxonomy for this visibility
  $vid = ta_variable_get('triage_income_eligibility','triage_income_eligibility',$nid);
//  $voc = taxonomy_vocabulary_machine_name_load($voc_name);
//  $vid=$voc->vid;
  $sql = "select tid,name from taxonomy_term_data where vid = :vid";
  $results = db_query($sql,array(':vid' => $vid));
  $vTypes = db_query($sql,array(':vid'=>$vid));
  // Income visibility
  $income_opts=array();
  $vals = db_query('select show_income from triage_actions where id = :id and language = :lang',
            array(':id'=>$id, ':lang' => $lang))->fetchColumn();
  $income_info_show = explode(",",$vals);
  $vals = db_query('select hide_income from triage_actions where id = :id and language = :lang',
          array(':id'=>$id, ':lang' => $lang))->fetchColumn();
  $income_info_hide = explode(",",$vals);
  foreach ($vTypes as $vt){
      $income_opts[$vt->tid] = $vt->name;
  }
  // eof income visibility section
  $action = db_query("select title, 
              display_header, 
              reusable_text, 
              action_text,
              action_text_format,
              trim_length,
              extra,
              classes,
              region,
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
  $form['action_title'] = array(
      '#markup' => "<div class='triage-action-title'>" . $act_title . "</div>",
  );  
  $form['title'] = array(
      '#type' => 'textfield',
      '#title' => t('Title'),
      '#default_value' => $action['title'],
      '#prefix' => "<div class='two-panel'><div class='two-panel'>",
      '#suffix' => "</div>",
  );
  $form['max_chars'] = array(
      '#type' => 'textfield',
      '#title' => t('Length'),
      '#description' => 'Maximum characters allowed',
      '#default_value' => $action['trim_length'],
      '#prefix' => "<div class='two-panel'>",
      '#suffix' => "</div></div>",
      '#states' => array(
          'visible' => array(
              ':input[name=action_text]' => array(
                  'value' => 'triage_suggestion_form'
       ))),
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
      '#name' => 'action_text',
      '#type' => 'select',
      '#title' => t('Form'),
      '#options' => $form_opts,
      '#default_value' => $action['action_text'],
      '#prefix' => "<div class='two-panel'>",
  );
  $form['action_extra'] = array(
      '#type' => 'textfield',
      '#title' => t('Outcome URL'),
      '#description' => t('If the user is not served by this service area, direct them to the URL listed above (e.g. "helpful-info" or "node/1521")'),
      '#default_value' => $action['extra'],
      '#states' => array(
        'visible' => array(
          ':input[name="action_text"]' => array('value' => 'triage_in_service_area_form'),
        ),
      ),
      '#suffix' => "</div>",
  );
  $form['reusable_text'] = array(
      '#type' => 'checkbox',
      '#title' => t('Mandatory'),
      '#description' => t('Check to make entries on this form required'),
      '#default_value' => $action['reusable_text'],
      '#prefix' => "<div class='two-panel'>",
      '#suffix' => "</div>",
  );
  $form['separation3'] = array(
      '#markup' => "<div class='clear-both'></div>",
  ); 
  $form['triage_actions_visibility'] = array(
    '#type' => 'fieldset',
    '#title' => t('Restrict action visibility'),
    '#collapsible' => TRUE,
    '#collapsed' => TRUE,
    '#weight' => 5,
    '#description' => t('Check to know whether the user has the characteristics to see this action item. Note that both checks are always performed.'),
    '#tree' => TRUE,
  );
  $form['triage_actions_visibility']['triage_actions_income_set'] = array(
    '#type' => 'fieldset',
    '#title' => t('Income visibility'),
    '#collapsible' => TRUE,
    '#collapsed' => FALSE,
    '#weight' => 5,
    '#description' => t('Check to know whether the user has the characteristics to see this action item. Note that both checks are always performed.'),
    '#tree' => TRUE,
  );
  $form['triage_actions_visibility']['triage_actions_income_set']['income_qualifications_show'] = array(
    '#type' => 'checkboxes',
    '#title' => t('Show action item to users with checked income qualifications'),
    '#options' => $income_opts,
    '#default_value' => $income_info_show,
    '#prefix' => "<div class='two-panel'>",
    '#suffix' => "</div>",
  );
  $form['triage_actions_visibility']['triage_actions_income_set']['income_qualifications_hide'] = array(
    '#type' => 'checkboxes',
    '#title' => t('Hide action item from users with checked income qualifications'),
    '#options' => $income_opts,
    '#default_value' => $income_info_hide,
    '#prefix' => "<div class='two-panel'>",
    '#suffix' => "</div>",
  );
  $form['triage_actions_visibility']['triage_actions_status_set'] = array(
    '#type' => 'fieldset',
    '#title' => t('Status visibility'),
    '#collapsible' => TRUE,
    '#collapsed' => FALSE,
    '#weight' => 6,
    '#description' => t('Check to know whether the user has the characteristics to see this action item. Note that both checks are always performed.'),
    '#tree' => TRUE,
  );
  $form['triage_actions_visibility']['triage_actions_status_set']['status_qualifications_show'] = array(
    '#type' => 'checkboxes',
    '#title' => t('Show action item to users with group status qualifications'),
    '#options' => $status_opts,
    '#default_value' => $status_info_show,
    '#prefix' => "<div class='two-panel'>",
    '#suffix' => "</div>",
  );
  $form['triage_actions_visibility']['triage_actions_status_set']['status_qualifications_hide'] = array(
    '#type' => 'checkboxes',
    '#title' => t('Hide action item from users with checked income qualifications'),
    '#options' => $status_opts,
    '#default_value' => $status_info_hide,
    '#prefix' => "<div class='two-panel'>",
    '#suffix' => "</div>",
  );
  $form['submit'] = array(
      '#type' => 'submit', 
      '#weight' => 7,
      '#value' => t('Save changes'));
  return $form;
}
function triage_action_form_form_submit($form, &$form_state){
  global $base_url;
  //dsm($form_state);
  $id = $form_state['values']['id'];
  $title = $form_state['values']['title'];
  $max_chars = $form_state['values']['max_chars'];
  $header = $form_state['values']['display_header'];
  $bundle = $form_state['values']['bundle'];
  $region = $form_state['values']['region'];
  $mandatory = $form_state['values']['reusable_text'];
  $extra = $form_state['values']['action_extra'];
  if(is_null($region) || trim($region)==""){
    $region = "ta-main-panel";
  }    
  $classes = $form_state['values']['classes'];  
  $nid = $form_state['values']['action_text'];
  $show_income = _triage_actions_serialize_tids($form_state['values']
            ['triage_actions_visibility']['triage_actions_income_set']['income_qualifications_show']);
  $hide_income = _triage_actions_serialize_tids($form_state['values']
            ['triage_actions_visibility']['triage_actions_income_set']['income_qualifications_hide']);
  $show_status = _triage_actions_serialize_tids($form_state['values']
            ['triage_actions_visibility']['triage_actions_status_set']['status_qualifications_show']);
  $hide_status = _triage_actions_serialize_tids($form_state['values']
            ['triage_actions_visibility']['triage_actions_status_set']['status_qualifications_hide']);
  db_update('triage_actions')
    ->fields(array(
      'title' => $title,
      'display_header' => $header,
      'bundle' => $bundle,
      'show_income' => $show_income,
      'hide_income' => $hide_income,
      'show_status' => $show_status,
      'hide_status' => $hide_status,
      'action_text' => $nid,
      'trim_length' => $max_chars,
      'extra' => $extra,
      'reusable_text' => $mandatory,
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