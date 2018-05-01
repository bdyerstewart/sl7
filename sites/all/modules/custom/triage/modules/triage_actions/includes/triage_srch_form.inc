<?php
function triage_action_srch_form($form, &$form_state,$id){
  $bundle = $_SESSION['triage']['my_bundle'];
  $type_vals = variable_get('triage_search_types',array());
  $type_opts = array();
  foreach($type_vals as $key => $val){
    if ($val) {
      $type_opts[$key] = $key ;
    }
  }
  $region_opts = array(
    'none' => 'None',
    'ta-message-panel' => 'Top Message Panel',
    'ta-main-panel' => 'Main Panel',
    'ta-help-panel' => 'Help Panel',
    'ta-bottom-panel' => 'Bottom Panel',
  );
  $view_opts  = array(
    'trim' => 'Trimmed',
  );
  $views = entity_get_info('node');
  $view_modes = $views['view modes'];
  foreach($view_modes as $key => $val){
      $view_opts[$key] = $val['label'];
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
  // Get status taxonomy for this visibility
  $vid = $_SESSION['triage']['triage_actions_admin_voc'];
  $node = triage_get_page($vid);
  $nid = $node->nid;
  $_SESSION['triage']['triage_page_nid'] = $nid;
  $vid = ta_variable_get('triage_status_voc','',$nid);
  $sql = "select tid,name from taxonomy_term_data where vid = :vid"; 
  $sTypes = db_query($sql,array(':vid'=>$vid));
  $status_opts=array();
  $vals = db_query('select show_status from triage_actions where id = :id',
            array(':id'=>$id))->fetchColumn();
  $status_info_show = explode(",",$vals);
  $vals = db_query('select hide_status from triage_actions where id = :id',
            array(':id'=>$id))->fetchColumn();
  $status_info_hide = explode(",",$vals);
  foreach ($sTypes as $vt){
      $status_opts[$vt->tid] = $vt->name;
  }
  // eof status visibility section
  // Get income eligibility taxonomy for this visibility
  $vid = ta_variable_get('triage_income_eligibility','triage_income_eligibility',$nid);
  $sql = "select tid,name from taxonomy_term_data where vid = :vid";
  $results = db_query($sql,array(':vid' => $vid));
  $vTypes = db_query($sql,array(':vid'=>$vid));
  // Income visibility
  $income_opts=array();
  $vals = db_query('select show_income from triage_actions where id = :id',
            array(':id'=>$id))->fetchColumn();
  $income_info_show = explode(",",$vals);
  $vals = db_query('select hide_income from triage_actions where id = :id',
          array(':id'=>$id))->fetchColumn();
  $income_info_hide = explode(",",$vals);
  foreach ($vTypes as $vt){
      $income_opts[$vt->tid] = $vt->name;
  }
  // eof income visibility section
  // County visibility section
  $county_opts=  triage_county_data();
  $vals = db_query('select show_county from triage_actions where id = :id',
            array(':id'=>$id))->fetchColumn();
  $county_info_show = explode(",",$vals);
  $vals = db_query('select hide_county from triage_actions where id = :id',
          array(':id'=>$id))->fetchColumn();
  $county_info_hide = explode(",",$vals);  
  // eof county visibility section
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
      '#type' => 'checkboxes',
      '#title' => t('Content Type to Include in Search'),
      '#options' => $type_opts,
      '#default_value' => explode(",", $action['action_text']),
      '#prefix' => "<div class='two-panel'>",
      '#suffix' => "</div>",
  );
  $form['separation3'] = array(
      '#markup' => "<div class='clear-both'></div>",
  );  
  $form['node_view_opt'] = array(
      '#type' => 'select',
      '#title' => t('Results Display View'),
      '#options' => $view_opts,
      '#default_value' => $action['node_view_opt'],
      '#prefix' => "<div class='two-panel'>",
      '#suffix' => "</div>",
  );  
  $form['trim_length'] = array(
      '#type' => 'textfield',
      '#title' => t('Length in characters to trim embedded node content'),
      '#default_value' => $action['trim_length'],
      '#prefix' => "<div class='two-panel'>",
      '#suffix' => "</div>",
  );
  $form['separation4'] = array(
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
  $form['triage_actions_visibility']['triage_actions_county_set'] = array(
    '#type' => 'fieldset',
    '#title' => t('County visibility'),
    '#collapsible' => TRUE,
    '#collapsed' => FALSE,
    '#weight' => 6,
    '#description' => t('Check to know whether the user resides in the county to see this action item. Note that both checks are always performed.'),
    '#tree' => TRUE,
  );
  $form['triage_actions_visibility']['triage_actions_county_set']['county_qualifications_show'] = array(
    '#type' => 'checkboxes',
    '#title' => t('Show action item to users in checked counties'),
    '#options' => $county_opts,
    '#default_value' => $county_info_show,
    '#prefix' => "<div class='two-panel'>",
    '#suffix' => "</div>",
  );
  $form['triage_actions_visibility']['triage_actions_county_set']['county_qualifications_hide'] = array(
    '#type' => 'checkboxes',
    '#title' => t('Hide action item from users in checked counties'),
    '#options' => $county_opts,
    '#default_value' => $county_info_hide,
    '#prefix' => "<div class='two-panel'>",
    '#suffix' => "</div>",
  );
  $form['submit'] = array(
      '#type' => 'submit', 
      '#weight' => 7,
      '#value' => t('Save changes'));
  return $form;
}
function triage_action_srch_form_submit($form, &$form_state){
  global $base_url;
  //dsm($form_state);
  $id = $form_state['values']['id'];
  $title = $form_state['values']['title'];
  $header = $form_state['values']['display_header'];
  $bundle = $form_state['values']['bundle'];
  $region = $form_state['values']['region'];
  $nvo = $form_state['values']['node_view_opt'];
  $len = $form_state['values']['trim_length'];  
  if (!is_int($len)){$len = 0;}
  if(is_null($region) || trim($region)==""){
    $region = "ta-main-panel";
  }    
  $show_income = _triage_actions_serialize_tids($form_state['values']
            ['triage_actions_visibility']['triage_actions_income_set']['income_qualifications_show']);
  $hide_income = _triage_actions_serialize_tids($form_state['values']
            ['triage_actions_visibility']['triage_actions_income_set']['income_qualifications_hide']);
  $show_status = _triage_actions_serialize_tids($form_state['values']
            ['triage_actions_visibility']['triage_actions_status_set']['status_qualifications_show']);
  $hide_status = _triage_actions_serialize_tids($form_state['values']
            ['triage_actions_visibility']['triage_actions_status_set']['status_qualifications_hide']);
  $show_county = _triage_actions_serialize_tids($form_state['values']
            ['triage_actions_visibility']['triage_actions_county_set']['county_qualifications_show']);
  $hide_county = _triage_actions_serialize_tids($form_state['values']
            ['triage_actions_visibility']['triage_actions_county_set']['county_qualifications_hide']);
  $classes = $form_state['values']['classes'];
  $text = _triage_actions_serialize_tids($form_state['values']['action_text']);
  db_update('triage_actions')
    ->fields(array(
      'title' => $title,
      'display_header' => $header,
      'bundle' => $bundle,
      'action_text' => $text,
      'node_view_opt' => $nvo,
      'trim_length' => $len,
      'show_income' => $show_income,
      'hide_income' => $hide_income,
      'show_status' => $show_status,
      'hide_status' => $hide_status,
      'show_county' => $show_county,
      'hide_county' => $hide_county,
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