<?php
function triage_action_node_form($form, &$form_state,$id){
  $bundle = $_SESSION['triage']['my_bundle'];
  //dsm($bundle);
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
  $view_opts  = array(
    'trim' => 'Trimmed',
  );
  $views = entity_get_info('node');
  $view_modes = $views['view modes'];
  foreach($view_modes as $key => $val){
      $view_opts[$key] = $val['label'];
  }
  // Get status taxonomy for this visibility
  $vid = $_SESSION['triage']['triage_actions_admin_voc'];
  $node = triage_get_page($vid);
  $nid = $node->nid;
  $_SESSION['triage']['triage_page_nid'] = $nid;

  // Public Benefits options
  $benvid = ta_variable_get('triage_public_benefits','',$nid);
  $ben_opts = db_query('select tid, name from taxonomy_term_data where vid = :vid',array(':vid'=>$benvid))->fetchAllKeyed();

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
//  $voc = taxonomy_vocabulary_machine_name_load($voc_name);
//  $vid=$voc->vid;
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
  if($benvid) {
    $vals = db_query('select show_benefits from triage_actions where id = :id',
      array(':id' => $id))->fetchColumn();
    $benefits_info_show = explode(",", $vals);
    $vals = db_query('select hide_benefits from triage_actions where id = :id',
      array(':id' => $id))->fetchColumn();
    $benefits_info_hide = explode(",", $vals);
  }
  $action = db_query("select title, 
              display_header, 
              reusable_text, 
              action_text,
              action_text_format,
              node_view_opt,
              node_ref_nid,
              trim_length,
              classes,
              region
              from triage_actions 
              where id=:id",array(":id"=>$id))->fetchAssoc();
  $mytitle = triage_get_title($action['node_ref_nid']);
  $form['id'] = array(
      '#type' => 'hidden',
      '#default_value' => $id,
  );
  $form['bundle'] = array(
      '#type' => 'hidden',
      '#default_value' => $bundle,
  );
  $form['mytitle'] = array(
      '#type' => 'hidden',
      '#default_value' => $mytitle,
  );
  $form['action_title'] = array(
      '#markup' => "<div class='triage-action-title'>" . $act_title . "</div>",
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
      '#title' => t('Display Header'),
      '#description' => 'Display header takes precedence over title in display.  Enter &#60;none&#62; for no title/display header',
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
  $form['node_ref_nid'] = array(
      '#type' => 'textfield',
      '#title' => t('Node Title'),
      '#autocomplete_path' => 'triage_node_title_autocomplete',
      '#default_value' => $action['node_ref_nid'],
      '#suffix' => '<div class="triage-form-node-title">' . $mytitle . '</div>',
  );
  $form['separation3'] = array(
      '#markup' => "<div class='clear-both'></div>",
  );
  $form['node_view_opt'] = array(
      '#type' => 'select',
      '#title' => t('Embedded Node View'),
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
    '#collapsed' => TRUE,
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
    '#collapsed' => TRUE,
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
    '#collapsed' => TRUE,
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
  // Public Benefits Visibility
  if($benvid) {
    $form['triage_actions_visibility']['triage_actions_benefits_set'] = array(
      '#type' => 'fieldset',
      '#title' => t('Public Benefits visibility'),
      '#collapsible' => TRUE,
      '#collapsed' => TRUE,
      '#weight' => 6,
      '#description' => t('Public Benefits Visibility. Note that both checks are always performed.'),
      '#tree' => TRUE,
    );
    $form['triage_actions_visibility']['triage_actions_benefits_set']['benefits_qualifications_show'] = array(
      '#type' => 'checkboxes',
      '#title' => t('Show action item to users with checked benefits'),
      '#options' => $ben_opts,
      '#default_value' => $benefits_info_show,
      '#prefix' => "<div class='two-panel'>",
      '#suffix' => "</div>",
    );
    $form['triage_actions_visibility']['triage_actions_benefits_set']['benefits_qualifications_hide'] = array(
      '#type' => 'checkboxes',
      '#title' => t('Hide action item from users with checked benefits'),
      '#options' => $ben_opts,
      '#default_value' => $benefits_info_hide,
      '#prefix' => "<div class='two-panel'>",
      '#suffix' => "</div>",
    );
  }
  $form['submit'] = array(
      '#type' => 'submit', 
      '#weight' => 7,
      '#value' => t('Save changes'));
  return $form;
}
function triage_get_title($nid = 0, $js = false){
    if ($nid == 0){return '';}
    if ($js){
        return drupal_json_output(db_query('select title from node where nid = :nid',array(":nid"=>$nid))->fetchColumn());
    }
    else {
     return db_query('select title from node where nid = :nid',array(":nid"=>$nid))->fetchColumn();
    }
}
function triage_action_node_form_submit($form, &$form_state){
  global $base_url;
  //dsm($form_state);
  $id = $form_state['values']['id'];
  $title = $form_state['values']['title'];
  $header = $form_state['values']['display_header'];
  $bundle = $form_state['values']['bundle'];
  $nid = $form_state['values']['node_ref_nid'];
  $nid = intval($nid);
  if (!is_int($nid)){$nid = 0;}
  $nvo = $form_state['values']['node_view_opt'];
  $len = $form_state['values']['trim_length'];
  $classes = $form_state['values']['classes'];
  $region = $form_state['values']['region'];
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
  $show_ben = _triage_actions_serialize_tids($form_state['values']
            ['triage_actions_visibility']['triage_actions_benefits_set']['benefits_qualifications_show']);
  $hide_ben = _triage_actions_serialize_tids($form_state['values']
            ['triage_actions_visibility']['triage_actions_benefits_set']['benefits_qualifications_hide']);
  db_update('triage_actions')
    ->fields(array(
      'title' => $title,
      'display_header' => $header,
      'bundle' => $bundle,
      'node_ref_nid' => $nid,
      'node_view_opt' => $nvo,
      'trim_length' => $len,
      'show_income' => $show_income,
      'hide_income' => $hide_income,
      'show_status' => $show_status,
      'hide_status' => $hide_status,
      'show_county' => $show_county,
      'hide_county' => $hide_county,
      'show_benefits' => $show_ben,
      'hide_benefits' => $hide_ben,
      'classes' => $classes,
      'region' => $region,
    ))
    ->condition('id',$id)
    ->execute();
  switch ($bundle){
    case 'taxonomy':
      $url = '/taxonomy/term/' . $_SESSION['triage']['edit_tid'] . '/actions';
      break;
    case 'node':
      $url = '/node/' . $_SESSION['triage']['edit_tid'] . '/actions';
      break;
    case 'help':
      $url = '/node/' . $_SESSION['triage']['edit_tid'] . '/actions_out';
      break;
  }
  $form_state['redirect'] = $url;
}