<?php
function triage_zip_form($form, &$form_state){
  $cinfo = '';
  $state = $_SESSION['triage']['triage_state_id'];
  $zipmsg = 'Enter zipcode or town';
  if (trim($state) == ''){$zipmsg = "Enter Zip";}
  $cZip = $_SESSION['triage']['my_zip'];
  if ($cZip > ''){
    $cinfo .= $_SESSION['triage']['my_town'] . " " . $_SESSION['triage']['my_zip'];
    $cinfo .= " " . " ~ County: " . $_SESSION['triage']['my_county'];
  }
  $form['triage_real'] = array(
      '#type' => 'hidden',
      '#default_value' => 0,
  );  
  $form['triage_zip'] = array(
    '#title' => t("Enter zipcode where your legal issue is"),
      '#type' => 'textfield',
      '#size' => 20,
      '#maxlength' => 5,
      '#default_value' => $cZip,
      '#attributes' => array(
          'placeholder' => t($zipmsg),
          'class' => array('triage-input')),
      '#ajax' => array(
          'callback' => 'triage_get_zip',
          'progress' => 'throbber',
          'event' => 'blur',
      )
  );  
  $form['zip_text'] = array(
      '#type' => 'markup',
      '#markup' => "<div id='triage_city'>" . $cinfo . "</div>",
  );
  return $form;
}
function triage_in_service_area_form($form, &$form_state){
  $nid = $_SESSION['triage']['triage_page_nid'];
  $state = $_SESSION['triage']['triage_state_id'];
  $state = triage_state_name($state);
  $val = $_SESSION['triage']['triage_non_service_area'];
  $canServe = $_SESSION['triage']['triage_in_service_area'];
  $text1 = t(ta_variable_get('triage_location_text1','',$nid));
  $text2 = t(ta_variable_get('triage_location_text2','',$nid));
  if (trim($text1)==""){
    $opts = array(
      '0' => t('I live in ' . $state . ' AND my legal problem is based in ' . $state),
      '1' => t('I live outside of ' . $state . ' OR my legal problem is based outside of ' . $state),
    );
  }
  else {
    $opts = array(
      '0' => $text1,
      '1' => $text2,
    );
  }
  $form['service_area_text'] = array(
      '#type' => 'markup',
      '#markup' => "<div class='markup'>" . t(" ") . "</div>",
  );  
  $form['triage_area'] = array(
      '#type' => 'radios',
      '#attributes' => array(
          'class' => array('triage-input')),
      '#default_value' => $val,
      '#options' => $opts,
  );  
  return $form;
}
function triage_location_form($form, &$form_state){
  $who_provider = $_SESSION['triage']['triage_who_is'];
  $who_text = "I am here to help: ";
  $who_text2 = "You are trying to find help for someone else. Please answer the rest of these questions as if you are that person.";
  $who_opts = array(
    '0' => 'Myself',
    '1' => 'Someone Else',
  );

  $sql = "SELECT title ,nid FROM node WHERE status = '1' AND type = 'county'";
  $counties = db_query($sql);
  $choices=array();
  $flags = flag_get_user_flags('node');
  if (isset($flags['county'])) {
    $county = array_shift($flags['county']);
    $county_nid = $county->entity_id;
    $node = node_load($county_nid);
    $_SESSION['triage']['my_county'] = $node->title;
    $_SESSION['triage']['triage_in_service_area'] = '1';
  }
  $thiscounty = $_SESSION['triage']['my_county'];
  $choices[''] = '- COUNTY -';
  foreach ($counties as $county){
      $choices[$county->title] = $county->title;
  }
  $nid = $_SESSION['triage']['triage_page_nid'];
  $val = $_SESSION['triage']['triage_non_service_area'];
  $canServe = $_SESSION['triage']['triage_in_service_area'];
  $thishelp = $_SESSION['triage']['triage_kind_of_help'];
  $text1 = t(ta_variable_get('triage_location_text1','',$nid));
  $text2 = t(ta_variable_get('triage_location_text2','',$nid));
  $tp_help = ta_variable_get('triage_kind_of_help','',$nid);
  $help_opt = db_query('select tid, name from taxonomy_term_data where vid = :vid order by weight',array(':vid'=>$tp_help))->fetchAllKeyed();
  $opts = array(
    '1' => t('Yes'),
    '0' => t('No'),
  );
  $form['triage_info'] = array(
      '#type' => 'form',
      '#prefix' => "<div class='triage-info'><div class='who-container'>",
  );
  $form['triage_who'] = array(
    '#type' => 'radios',
    '#name' => 'triage_who',
    '#attributes' => array(
      'class' => array('triage-input')),
    '#default_value' => $who_provider,
    '#options' => $who_opts,
    '#prefix' => "<div class='whois markup'>" . t($who_text) ."</div>",
  );
  $form['triage_whois'] = array(
    '#type' => 'container',
    '#states' => array(
      'visible' => array(
        ':input[name="triage_who"]' => array('value' => '1'),
      )),
    '#suffix' => '</div>',
  );
  $form['triage_whois']['provider_text'] = array(
    '#type' => 'markup',
    '#markup' => "<div class='whois markup'>" . t($who_text2) . "</div>",
  );
  $form['triage_area_cont'] = array(
    '#type' => 'container',
    '#states' => array(
      'visible' => array(
        ':input[name="triage_who"]' => array(
          array('value' => '0'),
          array('value' => '1'),
        ),
      )),
    //'#suffix' => '</div>',
  );

  $form['triage_area_cont']['triage_area_info'] = array(
      '#type' => 'radios',
      '#name' => 'triage_area_info',
      '#attributes' => array(
          'class' => array('triage-input','location')),
      '#default_value' => $canServe,
      '#options' => $opts,
      '#prefix' => "<div class='triage-location'>",
      '#suffix' => "<div class='markup'>" . t($text1) . "</div>",
  );

//  $form['service_area_text'] = array(
//      '#type' => 'markup',
//      '#markup' => "<div class='markup'>" . t($text1) . "</div>",
//      '#suffix' => '</div>',
//  );

  $form['triage_hold_county'] = array(
    '#type' => 'container',
    '#states' => array(
      'visible' => array(
        ':input[name="triage_area_info"]' => array('value' => '1'),
      )),
    '#suffix' => '</div>',
  );
  $form['triage_hold_county']['triage_county'] = array(
    '#type' => 'select',
    '#name' => 'triage_county',
    '#options' => $choices,
    '#title' => t($text2),  
    '#default_value' => $thiscounty,
    '#attributes' => array(
        'class' => array('triage-input'),
        'rel' => array('triage_county'),        
    ),
    '#prefix' => "<div class='triage-county'>",
  );
  $form['triage_hold_county']['triage_container'] = array(
    '#type' => 'container',  
    '#states' => array(
        'visible' => array(
          ':input[name="triage_area_info"]' => array('value' => '1'),
    )), 
    '#suffix' => "</div>",
  );
  $form['triage_kind_of_help'] = array(
    '#type' => 'select',
    '#options' => $help_opt,
    '#title' => t('What I want the most is...'),
    '#default_value' => $thishelp,
    '#attributes' => array(
        'class' => array('triage-input'),
        'rel' => array('triage_kind_of_help'),        
    ),
    '#states' => array(
      'invisible' => array(
        ':input[name="triage_county"]' => array('value' => ''),
      ),
        'visible' => array(
          ':input[name="triage_area"]' => array('value' => '1'),
     )),
    '#prefix' => "<div class='triage-kind-help'>",
    '#suffix' => "</div></div>",
  );

  return $form;
}
function triage_pov_form($form, &$form_state){
  $size = $_SESSION['triage']['my_house_size'];
  $income = $_SESSION['triage']['my_house_income'];
  $form['triage_real'] = array(
      '#type' => 'hidden',
      '#default_value' => 0,
  );  
  $form['triage_household'] = array(
    '#type' => 'textfield',
    '#title' => t('# People in Household'),
    '#size' => 2,
    '#prefix' => "<div class='triage-house-size'>",
    '#attributes' => array(
          'class' => array('triage-input')),
    '#suffix' => "</div>",
    '#default_value' => $size,
  );
  $form['triage_income'] = array(
    '#type' => 'textfield',
    '#title' => t('MONTHLY Income'),
    '#size' => 6,
    '#field_prefix' => t('$'),
    '#prefix' => "<div class='triage-house-income'>",
    '#suffix' => "</div>",
    '#attributes' => array(
          'class' => array('triage-input','triage-income')),
    '#default_value' => $_SESSION['triage']['my_house_income'],
  );
  return $form;
}
function triage_income_form($form, &$form_state){
  $size = $_SESSION['triage']['my_house_size'];
  $numpeople = array();
  for( $i= 0 ; $i <= 15 ; $i++ ){
    $numpeople[$i] = $i;
  }
  if ($size > 0){$size = $size - 1;}
  $status = $_SESSION['triage']['triage_live_alone'];
  $my_benefits = $_SESSION['triage']['my_benefits'];
  //watchdog('bds','s: '. $status);
  $text =  "Include your spouse/partner (unless you are seeking help with a divorce), 
            your children, and any other adults who live with you that you support.";
  $inc_text = "Include income from all people in your household. If you are seeking help with a divorce or separation, 
              don’t include that person’s income.";
  if($size > 1){$status = false;}
  $income = $_SESSION['triage']['my_house_income'];
  $nid = $_SESSION['triage']['triage_page_nid'];
  $vid = ta_variable_get('triage_public_benefits','',$nid);
  $benefits = db_query("SELECT tid, name FROM {taxonomy_term_data} WHERE vid = :vid", array(':vid' => $vid))->fetchAllKeyed();
  $period = $_SESSION['triage']['triage_income_period'];
  $inctitle = trim($period . " Income");
  $opts = array();
  $opts['Weekly'] = 'Week';
  $opts['Bi-Weekly'] = 'Two Weeks';
  $opts['Monthly'] = 'Month';
  $opts['Annual'] = 'Year';
  $form['triage_real'] = array(
      '#type' => 'hidden',
      '#default_value' => 0,
  );
  $form['triage_live_alone'] = array(
    '#type' => 'radios',
    '#options' => array(
      '0' => 'I live alone',
      '1' => 'I live with other people',
    ),
    '#name' => 'triage_live_alone',
    '#default_value' => $status,
    '#attributes' => array(
      'class' => array('triage-input who-live'),
      'rel' => array('triage_status'),
    ),
  );
  $form['house_cont'] = array(
    '#type' => 'container',
    '#states' => array(
      'visible' => array(
        ':input[name="triage_live_alone"]' => array('value' => '1'),
      )),
  );
  $form['house_cont']['triage_household'] = array(
    '#type' => 'select',
    '#options' => $numpeople,
    '#title' => '',
    '#prefix' => "<div class='triage-household f-left'><div class='f-left'>I live with </div>",
    '#attributes' => array(
          'placeholder' => '#',
          'class' => array('triage-input f-left')),
    '#suffix' => "<div class='f-left'> other person(s)</div><div class='house_text'>" . $text .  "</div></div>",
    '#default_value' => $size,
  );
  $form['triage_clear']= array(
    '#type' => 'markup',
    '#markup' => "<div class='clear-both'> </div>",
  );
  $form['triage_income'] = array(
    '#type' => 'textfield',
    '#title' => t('My Income is '),
    '#name' => 'triage_income',
    '#size' => 6,
    '#field_prefix' => t('$'),
    '#prefix' => "<div class='triage-household-income'>",
    '#suffix' => "</div>",
    '#attributes' => array(
      'class' => array('triage-input','triage-income'),
      'placeholder' => '$$$'),
    '#default_value' => $_SESSION['triage']['my_house_income'],
  );
  $form['triage_income_period'] = array(
      '#type' => 'radios',
      '#title' => 'every',
      '#name' => 'triage_income_period',
      '#attributes' => array(
          'class' => array('triage-input')),
      '#default_value' => $period,
      '#options' => $opts,
      '#prefix' => "<div class='triage-income_period'>",
      '#suffix' => "</div>",
    '#states' => array(
      'invisible' => array(
        ':input[name="triage_income"]' => array('value' => ''),
      )),
  );
  $form['income_cont'] = array(
      '#type' => 'container',
      '#states' => array(
        'visible' => array(
          ':input[name="triage_income_period"]' => array(
            array('value' => 'Weekly'),
            array('value' => 'Bi-Weekly'),
            array('value' =>'Monthly'),
            array('value' =>'Annual' ),
          ))),
  );
  $form['triage_clear2']= array(
      '#type' => 'markup',
      '#markup' => "<div class='clear-both'> </div>",
  );
  $form['triage_extra'] = array(
    '#type' => 'container',
    '#states' => array(
      'visible' => array(
        ':input[name="triage_live_alone"]' => array('value' => '1'),
      )),
  );
  $form['triage_extra']['triage_clear']= array(
      '#type' => 'markup',
      '#markup' => "<div class='house_text'>" . $inc_text . "</div>",
  );
  $form['triage_last_info'] = array(
    '#type' => 'container',
    '#states' => array(
      'visible' => array(
        ':input[name="triage_live_alone"]' => array('value' => '3'),
      )),
  );
  $form['triage_last_info']['triage_benefits'] = array(
    '#type' => 'checkboxes',
    '#options' => $benefits,
    '#title' => t('Do you receive any of the following? Check all that apply.'),
    '#default_value' => $my_benefits,
    '#attributes' => array(
      'class' => array('triage-input'),
      'rel' => array('triage_status'),
    ),
  );

  return $form;
}
function triage_followup_form($form, &$form_state){
  $factor_default_text = "Check all that apply so we can find the best resources for you.<br /><hr>";
  $ans = $_SESSION['triage']['factors'];
  $nid = $_SESSION['triage']['triage_page_nid'];
  $vid = ta_variable_get('triage_factors','',$nid);
  $opts = db_query("SELECT tid, name FROM {taxonomy_term_data} WHERE vid = :vid",
            array(':vid' => $vid))->fetchAllKeyed();
  $text = ta_variable_get('triage_factos_text', $factor_default_text, $nid);
  $form['triage_factors'] = array(
    '#type' => 'checkboxes',
    '#title' => t($text),
    '#options' => $opts,
    '#default_value' => $ans,
    '#attributes' => array(
      'class' => array('triage-input'),
      'rel' => array('triage_followup'),
    ),
  );
  return $form;
}
function triage_bank_form($form, &$form_state){
  $bank = $_SESSION['triage']['triage_bank_amt'];
  $form['triage_bank_amt'] = array(
    '#type' => 'textfield',
    '#title' => t('How much money do you have in the bank?'),
    '#precision' => 6,
    '#decimals' => 0,
    '#field_prefix' => t('$'),
    '#prefix' => "<div class='triage-bank_amt'>",
    '#suffix' => "</div>",
    '#default_value' => $bank,
    '#attributes' => array(
        'class' => array('triage-input'),
        'rel' => array('triage_bank_amt'),
    ),
    '#ajax' => array(
      'callback' => 'triage_get_bank',
      'progress' => 'throbber',
      'event' => 'change',
      )
  );
  return $form;
}
function triage_status_form($form, &$form_state){
  global $base_url;
  global $language;
  $default_lang = language_default();
  $lang = $language->language;
  $form = array();
  $status = $_SESSION['triage']['triage_status'];
  $nid = $_SESSION['triage']['triage_page_nid'];
  if ($nid==0){return false;}
  $tp_status_table = ta_variable_get('triage_status_table','',$nid);
  if ($tp_status_table==''){return false;}
  $tp_status_field = $tp_status_table . "_tid";
  $tp_status_table = "field_data_" . $tp_status_table;
  // Get status taxonomy for this show/hide display
  $vid = ta_variable_get('triage_status_voc','',$nid);
  $vTypes = db_query("select tid from taxonomy_term_data where vid = :vid and ( (language = :lang) OR (language = 'und') ) order by weight",
                  array(':vid'=>$vid,':lang'=>$lang));
  $choices=array();
  foreach ($vTypes as $vt){
      $term = taxonomy_term_load($vt->tid);
      if (module_exists('i18n_taxonomy')) { //To not break your site if module is not installed
          $term = i18n_taxonomy_localize_terms($term); // The important part!
      }            
      $choices[$term->tid] = $term->name;
  }
  $form['triage_real'] = array(
      '#type' => 'hidden',
      '#default_value' => 0,
  );
  $form['triage_status'] = array(
    '#type' => 'checkboxes',
    '#options' => $choices,
    //'#title' => t('Do any of these statements apply to you?'),  
    '#default_value' => $status,
    '#attributes' => array(
        'class' => array('triage-input'),
        'rel' => array('triage_status'),
    ),
  );
  return $form;
}
function triage_print_form($form, &$form_state){
   $form['triage_print_email'] = array(
    '#type' => 'textfield',
    '#title' => t('Print or email this to yourself'),
    '#size' => 25,
    '#prefix' => "<div class='triage-print-email'>",
    '#attributes' => array(
          'class' => array('triage-input'),
          'placeholder'=> t('Email Address'),
        ),
    '#suffix' => "</div>",
  );
  $form['print'] = array(
      '#type' => 'submit', 
      '#prefix' => "<div class='ta-print-buttons'>",
      '#suffix' => "</div>",
      '#value' => t('Print'));
  $form['email'] = array(
      '#type' => 'submit', 
      '#prefix' => "<div class='ta-print-buttons'>",
      '#suffix' => "</div>",
      '#value' => t('Email'),
  );
  return $form;
}
function triage_print_form_validate($form, &$form_state){
    if ($form_state['triggering_element']['#value']=='Email'){
        if($form_state['values']['triage_print_email']==''){
            form_set_error('triage_print_email', t('Email address must be filled in.'));
            return false;
        }
        else {
            $_SESSION['triage']['triage_send_to'] = $form_state['values']['triage_print_email'];
        }
    }
    return true;
}
function triage_print_form_submit($form, &$form_state){
    global $base_url;
    if ($form_state['triggering_element']['#value']=='Email'){
        $cp = arg(0) . "/" . arg(1) . "/3";
        $form_state['redirect'] = $cp;
    }
    else {
        $cp = "print/" . $cp = arg(0) . "/" . arg(1) . "/4";;        
        $form_state['redirect'] = $cp;
    }
}
function triage_summary_form($form_state) {
  $form = array();
  $vTypes = db_query('select distinct vid from triage_log where vid > 0');
  $vTypes = array();
  $sql = "select nid, value
              from ta_variable
              where name = 'triage_vocabulary'
              and nid > 0";
  $vals = db_query($sql)->fetchAll();
  $nid = 0;
  foreach ($vals as $val) {
    $vTypes[] = unserialize($val->value);
  }

  $choices=array();
  foreach ($vTypes as $vt){
      $voc = taxonomy_vocabulary_load($vt);
      if ($voc) {
        $choices[$voc->vid] = $voc->name;
      }
  }
  if (!isset($_SESSION['triage']['triage_summary_voc'])){
      $thisvoc = db_query('select distinct vid from triage_log where vid > 0 and ! vid ==null')->fetchColumn();
      $_SESSION['triage']['triage_summary_voc'] = $thisvoc;
  }
  else {
      $thisvoc = $_SESSION['triage']['triage_summary_voc'];
  }
  $session = $_SESSION['triage']['triage_summary_report'];
  if (empty($session[0])){
    $year = date("Y");
    $session[0] = date("Y-m-d H:i:s", mktime(0, 0, 0, 1, 1, $year));
    $_SESSION['triage']['triage_summary_report'][0] = $session[0];
  }
  if (empty($session[1])){
    $session[1] = date("Y-m-d H:i:s");
    $_SESSION['triage']['triage_summary_report'][1] = $session[1];
  }
  if (!isset($session[2])){
    $session[2] = true;
    $_SESSION['triage']['triage_summary_report'][2] = $session[2];
  }
  if (!isset($session[3])){
    $session[3] = '2';
    $_SESSION['triage']['triage_summary_report'][3] = $session[3];
  }
  $sdate = $session[0];
  $edate = $session[1];
  $show_summary = $session[2];
  $author = $session[3];
  $form['filter'] = array(
    '#type' => 'fieldset',
    '#title' => t('Filter Results'),
    '#collapsible' => TRUE, // Added
    '#prefix' => '<div class="date_inline">',
    '#suffix' => '</div">',
   );
  $form['filter']['start'] = array(
    '#type' => 'date_popup',
    '#title' => t('Start'),
    '#default_value' => $sdate,
    '#date_format' => 'Y-m-d',
    '#date_year_range' => '-100:+0',
  );
  $form['filter']['end'] = array(
    '#type' => 'date_popup',
    '#title' => t('End'),
    '#default_value' => $edate,
    '#date_format' => 'Y-m-d',
    '#date_year_range' => '-100:+0',
  );
  $form['filter']['summary'] = array(
    '#type' => 'checkbox', 
    '#default_value' => $show_summary,
    '#title' => t('Show Summary Only'),
    '#attributes' => array('class' => 'summary_checkbox'),
  );
  $form['filter']['summary_voc'] = array(
    '#type' => 'select',
    '#title' => 'Triage Vocabulary',
    '#options' => $choices,
    //'#title' => t('Do any of these statements apply to you?'),  
    '#default_value' => $thisvoc,
    '#attributes' => array(
        'class' => array('summary_voc'),
    ),
  );
  $form['filter']['summary_author'] = array(
    '#type' => 'select',
    '#title' => 'Triage Seeker',
    '#options' => array('0'=>'Self','1'=>'Other','2'=>'No Filter'),
    //'#title' => t('Do any of these statements apply to you?'),
    '#default_value' => $author,
    '#attributes' => array(
      'class' => array('summary_voc'),
    ),
  );
  $form['filter']['filter'] = array(
    '#type' => 'submit',
    '#value' => t('Filter'),
  );
  $form['filter']['reset'] = array(
    '#type' => 'submit',
    '#value' => t('Reset'),
  );
  $form['filter']['excel'] = array(
        '#type' => 'submit',
        '#value' => t('Excel'),
        '#suffix' => '</div></div>',
  );
  
  return $form;
}
function triage_summary_form_validate($form, $form_state) {}
function triage_summary_form_submit($form, &$form_state) {
  /*
   * Store form info into session variables
   */
    //dsm($form_state);
    $op = $form_state['values']['op'];
    switch ($op) {
      case t('Filter'):
        $dstart = $form_state['values']['start'];
        $dend = $form_state['values']['end'] ;
        $summary = $form_state['values']['summary'];
        $thisvoc = $form_state['values']['summary_voc'];
        $author = $form_state['values']['summary_author'];
        break;
      case t('Reset'):
        $year = date("Y");
        $dstart = date("Y-m-d H:i:s",mktime(0,0,0,1,1,$year));
        $dend = date("Y-m-d H:i:s");
        $summary = false;
        $thisvoc = db_query('select distinct vid from triage_log where vid > 0')->fetchColumn();
        $_SESSION['triage']['triage_summary_voc'] = $thisvoc;
        break;
    case t('Excel'):
        drupal_goto('triage_summary_excel');
        break;    
    }
    $_SESSION['triage']['triage_summary_report'][0] = $dstart;
    $_SESSION['triage']['triage_summary_report'][1] = $dend;
    $_SESSION['triage']['triage_summary_report'][2] = $summary;
    $_SESSION['triage']['triage_summary_report'][3] = $author;
    $_SESSION['triage']['triage_summary_voc'] = $thisvoc;
    return 'admin/reports/triage_summary' ;
  }
function triage_suggestion_form($form, &$form_state) {
  $form['triage_suggestion'] = array(
    '#type' => 'textfield',
    '#size' => 50,
//    '#title' => t('Give a brief description of your legal problem'),
    '#title' => t('Write what you want to look for here.'),
    '#attributes' => array(
              'placeholder' => t('Enter search term')),
  );  
  $form['submit'] = array(
      '#type' => 'submit', 
      '#id' => 'triage_suggestion_submit',
      '#weight' => 7,
      '#value' => t('Search'));
  return $form;
}
function triage_suggestion_form_submit($form, &$form_state) {
  global $base_url;
  $nid = $_SESSION['triage']['triage_page_nid'];
  $vid = ta_variable_get('triage_vocabulary','',$nid);
  $voc = taxonomy_vocabulary_load($vid);
  $tid = $_SESSION['triage']['triage_final_tid'];
  $text = $form_state['values']['triage_suggestion'];
  $form_state['values']['triage_suggestion']='';
  db_insert('triage_suggestions')
    ->fields(array(
      'text' => $text,
      'created' => REQUEST_TIME,
      'tid' => $tid,
      'ip' => ip_address(),
    ))
    ->execute();
  $_SESSION['triage']['triage_make_suggestion'] = FALSE;
//  $text = search_all_simplify($text);
//  $text = search_all_extraneous($text);
  $form_state['redirect'] = $base_url . "/search_all/" . $text;
}
function triage_change_form($form, &$from_state){
  $change_it = $_SESSION['triage']['triage_change_info'];
  $form['triage_change_info'] = array(
    '#id' => 'triage_change_info',
    '#type' => 'checkbox', 
    '#title' => t('Change Personal Info'),
  );
  return $form;
}
function triage_change_it($val = false){
    $_SESSION['triage']['triage_change_info'] = $val;
    //watchdog('bw',$_SESSION['triage']['triage_change_info']);
}
function triage_suggestionfilter_form($form_state) {
  $form = array();
  $vTypes = db_query('select distinct vid from triage_log');
  $choices=array();
  foreach ($vTypes as $vt){
      $voc = taxonomy_vocabulary_load($vt->vid);
      $choices[$voc->vid] = $voc->name;
  }
  if (!isset($_SESSION['triage']['triage_summary_voc'])){
      $thisvoc = db_query('select distinct vid from triage_log')->fetchColumn();
      $_SESSION['triage']['triage_summary_voc'] = $thisvoc;
  }
  $session = $_SESSION['triage']['triage_suggestions_report'];
  if (empty($session[0])){
    $year = date("Y");
    $session[0] = date("Y-m-d H:i:s", mktime(0, 0, 0, 1, 1, $year));
    $_SESSION['triage']['triage_suggestions_report'][0] = $session[0];
  }
  if (empty($session[1])){
    $session[1] = date("Y-m-d H:i:s");
    $_SESSION['triage']['triage_suggestions_report'][1] = $session[1];
  }
  if (!isset($session[2])){
    $session[2] = true;
    $_SESSION['triage']['triage_suggestions_report'][2] = $session[2];
  }
  $sdate = $session[0];
  $edate = $session[1];
  $show_summary = $session[2];
  $form['filter'] = array(
    '#type' => 'fieldset',
    '#title' => t('Filter Results'),
    '#collapsible' => TRUE, // Added
    '#prefix' => '<div class="date_inline">',
    '#suffix' => '</div">',
   );
  $form['filter']['start'] = array(
    '#type' => 'date_popup',
    '#title' => t('Start'),
    '#default_value' => $sdate,
    '#date_format' => 'Y-m-d',
    '#date_year_range' => '-100:+0',
  );
  $form['filter']['end'] = array(
    '#type' => 'date_popup',
    '#title' => t('End'),
    '#default_value' => $edate,
    '#date_format' => 'Y-m-d',
    '#date_year_range' => '-100:+0',
  );
  $form['filter']['filter'] = array(
    '#type' => 'submit',
    '#value' => t('Filter'),
  );
  $form['filter']['reset'] = array(
    '#type' => 'submit',
    '#value' => t('Reset'),
  );  
  return $form;
}
function triage_suggestionfilter_form_submit($form, &$form_state) {
  /*
   * Store form info into session variables
   */
    $op = $form_state['values']['op'];
    switch ($op) {
      case t('Filter'):
        $dstart = $form_state['values']['start'];
        $dend = $form_state['values']['end'] ;
        break;
      case t('Reset'):
        $year = date("Y");
        $dstart = date("Y-m-d H:i:s",mktime(0,0,0,1,1,$year));
        $dend = date("Y-m-d H:i:s");
        break;
    }
    $_SESSION['triage']['triage_suggestions_report'][0] = $dstart;
    $_SESSION['triage']['triage_suggestions_report'][1] = $dend;
    $_SESSION['triage']['triage_suggestions_report'][2] = $summary;
    return 'admin/reports/triage_suggestions' ;
}
function triage_problem_form($form, &$form_state){
  $form['triage_problem'] = array(
    '#type' => 'textarea',
  );
  $form['submit'] = array(
    '#type' => 'submit',
    '#id' => 'triage_problem_submit',
    '#value' => t('Continue'),
  );
  return $form;

}
function triage_problem_form_submit($form, &$form_state) {
  global $base_url;
  $voc_name = variable_get('triage_default_voc', "me_triage");
  $problem = $form_state['values']['triage_problem'];
  $location = "Vermont";
  if ($_SESSION['triage']['my_zip'] > ''){
    $location = $_SESSION['triage']['my_zip'];
  }
  $key = houston_ai_classify($location, $problem)->code->label;
  if($key == 'Not classified'){
    dsm("We are unable to suggest a legal issue. Try the categories below.");
  }
  else {
    $data = search_api_extend_houston($key);
    $url = $base_url . "/triage/" . $voc_name . "/" . $data['triage_path'];
    $form_state['redirect'] = $url;
  }
}
