<?php
function triage_action_text_form($form, &$form_state,$id=0, $lang = 'en'){
  global $language;
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
  if ($bundle == 'quests'){
    $region_opts = array(
      'none' => 'None',
      'ta-message-panel' => 'Top Message Panel',
      'ta-help-panel' => 'Help Panel',
      'ta-bottom-panel' => 'Bottom Panel',
    );    
  }
  else {
    $region_opts = array(
      'none' => 'None',
      'ta-message-panel' => 'Top Message Panel',
      'ta-main-panel' => 'Main Panel',
      'ta-help-panel' => 'Help Panel',
      'ta-bottom-panel' => 'Bottom Panel',
    );
  }
  $print_opts = array(
    '' => 'Show on all',
    'print_only' => 'Print Only',
    'non_print' => 'Exclude from Print',
  );
  $sql = 'select id from triage_actions where id = :id and language = :lang';
  $onfile = db_query($sql, array(':id'=>$id,':lang' => $lang))->fetchColumn();
  if (! $onfile){
    $sql = "drop temporary table if exists bds_action";
    db_query($sql);
    $sql = "create temporary table bds_action select * from triage_actions where id = :id limit 1";
    db_query($sql, array(':id'=>$id));
    $sql = "update bds_action set language=:lang";
    db_query($sql, array(':lang'=>$lang));
    $info = db_query("insert into triage_actions select * from bds_action");
  }
  $language->language = $lang;
  $langs = i18n_element_language_select();
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
    // County visibility section
  $county_opts=  triage_county_data();
  $vals = db_query('select show_county from triage_actions where id = :id and language = :lang',
            array(':id'=>$id, ':lang' => $lang))->fetchColumn();
  $county_info_show = explode(",",$vals);
  $vals = db_query('select hide_county from triage_actions where id = :id and language = :lang',
          array(':id'=>$id, ':lang' => $lang))->fetchColumn();
  $county_info_hide = explode(",",$vals);
  // eof county visibility section
  // Get status taxonomy for this visibility
  $vid = $_SESSION['triage']['triage_actions_admin_voc'];
  $sql = 'select tid, name 
                from taxonomy_term_data 
                where vid = :vid
                and tid in 
                (select tid 
                  from taxonomy_term_hierarchy 
                  where parent = 0)
                order by 2';
  $vals = db_query('select show_tax from triage_actions where id = :id and language = :lang',
            array(':id'=>$id,':lang' => $lang))->fetchColumn();
  $tax_show = explode(",",$vals);
  $vals = db_query('select hide_tax from triage_actions where id = :id and language = :lang',
            array(':id'=>$id,':lang' => $lang))->fetchColumn();
  $tax_hide = explode(",",$vals);
  $tax_opts = array();
  $taxes = db_query($sql, array(':vid' => $vid));
  foreach ($taxes as $tax){
      $tax_opts[$tax->tid] = $tax->name;
  }
  if($benvid) {
    $vals = db_query('select show_benefits from triage_actions where id = :id',
      array(':id' => $id))->fetchColumn();
    $benefits_info_show = explode(",", $vals);
    $vals = db_query('select hide_benefits from triage_actions where id = :id',
      array(':id' => $id))->fetchColumn();
    $benefits_info_hide = explode(",", $vals);
  }

  // eof status visibility section
  $bundle = $_SESSION['triage']['my_bundle'];
  $action = db_query("select title, 
                        display_header, 
                        reusable_text, 
                        action_text,
                        action_text_format,
                        extra,
                        classes,
                        region,
                        intake_elig
                        from triage_actions 
                        where id=:id
                        and language = :lang",
            array(
                ":id"=>$id,
                ":lang"=>$lang)
          )->fetchAssoc();
  $form['action_title'] = array(
      '#markup' => "<div class='triage-action-title'>" . $act_title . "</div>",
  );
  $form['language'] = array(
      '#markup' => "<h3'>" . $language->name . "</h3>",
  );   
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
      '#description' => 'Title can be administrative or used as the display title',
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
  $form['separation0'] = array(
      '#markup' => "<div class='clear-both'></div>",
  ); 
  $form['main_text'] = array(
    '#type' => 'text_format',
    '#title' => t('Text'),
    '#default_value' => $action['action_text'],
    '#rows' => 3,
    '#format' => $action['action_text_format'],
    '#suffix' => "<div style='margin-bottom:10px;'></div>",
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
  $form['separation1'] = array(
      '#markup' => "<div class='clear-both'></div>",
  );
  $form['reusable_text'] = array(
      '#type' => 'checkbox',
      '#title' => t('Include in Reusable Text Lists'),
      '#default_value' => $action['reusable_text'],
      '#prefix' => "<div class='two-panel'>",
      '#suffix' => "</div>",
  );
  $form['intake_elig'] = array(
      '#type' => 'checkbox',
      '#title' => t('Shown to Intake Eligible Only'),
      '#default_value' => $action['intake_elig'],
      '#prefix' => "<div class='two-panel'>",
      '#suffix' => "</div>",
  );
  $form['language'] = array(
      '#type' => 'select',
      '#title' => t('Language'),
      '#options' => $langs['#options'],
      '#disabled' => true,
      '#default_value' => $language->language,
      '#prefix' => "<div class='two-panel'>",
      '#suffix' => "</div>",
 );
  $form['separation2'] = array(
      '#markup' => "<div class='clear-both'></div>",
  );
  if ($bundle == 'help'){
    $form['print_visibility'] = array(
        '#type' => 'select',
        '#title' => t('Print Visibility'),
        '#options' => $print_opts,
        '#default_value' => $action['extra'],
        '#prefix' => "<div class='two-panel'>",
        '#suffix' => "</div>",
    );
  }
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
  $form['triage_actions_visibility']['triage_actions_tax_set'] = array(
    '#type' => 'fieldset',
    '#title' => t('Taxonomy visibility'),
    '#collapsible' => TRUE,
    '#collapsed' => FALSE,
    '#weight' => 6,
    '#description' => t('Check to know whether the user resides in the county to see this action item. Note that both checks are always performed.'),
    '#tree' => TRUE,
  );
  $form['triage_actions_visibility']['triage_actions_tax_set']['tax_show'] = array(
    '#type' => 'checkboxes',
    '#title' => t('Show action item for taxonomies'),
    '#options' => $tax_opts,
    '#default_value' => $tax_show,
    '#prefix' => "<div class='two-panel'>",
    '#suffix' => "</div>",
  );
  $form['triage_actions_visibility']['triage_actions_tax_set']['tax_hide'] = array(
    '#type' => 'checkboxes',
    '#title' => t('Hide action item for taxonomies'),
    '#options' => $tax_opts,
    '#default_value' => $tax_hide,
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
function triage_action_text_form_submit($form, &$form_state){
  global $base_url;
  global $language;
  //dsm($form_state);
  $id = $text = $form_state['values']['id'];
  $text = $form_state['values']['main_text']['value'];
  $format = $form_state['values']['main_text']['format'];
  $title = $form_state['values']['title'];
  $header = $form_state['values']['display_header'];
  $reuse = $form_state['values']['reusable_text'];
  $intake = $form_state['values']['intake_elig'];
  $bundle = $form_state['values']['bundle'];
  $extra = $form_state['values']['print_visibility'];
  $lang = $form_state['values']['language'];
  $region = $form_state['values']['region'];
  $classes = $form_state['values']['classes'];
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
  $show_tax = _triage_actions_serialize_tids($form_state['values']
            ['triage_actions_visibility']['triage_actions_tax_set']['tax_show']);
  $hide_tax = _triage_actions_serialize_tids($form_state['values']
            ['triage_actions_visibility']['triage_actions_tax_set']['tax_hide']);
  $show_ben = _triage_actions_serialize_tids($form_state['values']
            ['triage_actions_visibility']['triage_actions_benefits_set']['benefits_qualifications_show']);
  $hide_ben = _triage_actions_serialize_tids($form_state['values']
            ['triage_actions_visibility']['triage_actions_benefits_set']['benefits_qualifications_hide']);
  db_update('triage_actions')
    ->fields(array(
      'action_text' => $text,
      'action_text_format' => $format,
      'title' => $title,
      'display_header' => $header,
      'reusable_text' => $reuse,
      'intake_elig' => $intake,
      'show_income' => $show_income,
      'hide_income' => $hide_income,
      'show_status' => $show_status,
      'hide_status' => $hide_status,
      'show_county' => $show_county,
      'hide_county' => $hide_county,
      'show_tax' => $show_tax,
      'hide_tax' => $hide_tax,
      'show_benefits' => $show_ben,
      'hide_benefits' => $hide_ben,
      'extra' => $extra,
      'bundle' => $bundle,
      'language' => $lang,
      'region' => $region,
      'classes' => $classes,
    ))
    ->condition('id',$id)
    ->condition('language',$lang)
    ->execute();
  switch ($bundle){
    case 'taxonomy':
      $url = '/triage_actions_reuse_editor';
      if($_SESSION['triage']['edit_tid']){
        $url = '/taxonomy/term/' . $_SESSION['triage']['edit_tid'] . '/actions';
      }
      
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
function _triage_actions_serialize_tids($checks){
  $tids = array();
  foreach ($checks as $tid) {
    if (! $tid==0) {
      $tids[] = $tid;
    }
  }
  return implode(',', $tids);
}