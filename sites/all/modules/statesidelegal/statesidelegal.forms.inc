<?php

function statesidelegal_advocate($form, &$form_state)  {
  global $base_path;
  drupal_add_js(
     'jQuery(document).ready(function () {
        jQuery("#edit-submit").click(function(){
            jQuery("#edit-submit").addClass("advocate-no-show");
            jQuery("#edit-submit").removeClass("advocate-show")
            jQuery("#edit-submit2").addClass("advocate-show");
            jQuery("#edit-submit2").removeClass("advocate-no-show")
        });
        jQuery("#edit-submit2").click(function(){
            jQuery("#edit-submit2").addClass("advocate-no-show");
            jQuery("#edit-submit2").removeClass("advocate-show")
            jQuery("#edit-submit").addClass("advocate-show");
            jQuery("#edit-submit").removeClass("advocate-no-show")
        });
      });',
     'inline');

  $click_pic = $base_path . drupal_get_path('theme','state7').'/images/checkbox.gif';
  $unclick_pic = $base_path . drupal_get_path('theme','state7').'/images/uncheckbox.gif';
  $is_advocate = $_SESSION['is_advocate'][0];
  $form['statesidelegal_advocate'] = array(
      '#title' => t('Advocate View'), 
      '#attributes' => array('class' => array('no-mobile')),
  );
  
  $form['statesidelegal_advocate']['submit']['#type'] = 'image_button';
  $form['statesidelegal_advocate']['submit']['#src'] = $click_pic;
  $form['statesidelegal_advocate']['submit2']['#type'] = 'image_button';
  $form['statesidelegal_advocate']['submit2']['#src'] = $unclick_pic;
  if ($is_advocate){
      $form['statesidelegal_advocate']['submit']['#attributes'] = array('class' => array('advocate-show'));
      $form['statesidelegal_advocate']['submit2']['#attributes'] = array('class' => array('advocate-no-show'));
  }
  else {
      $form['statesidelegal_advocate']['submit']['#attributes'] = array('class' => array('advocate-no-show'));
      $form['statesidelegal_advocate']['submit2']['#attributes'] = array('class' => array('advocate-show'));
  }
  
  //$form['statesidelegal_advocate']['submit']['#value'] = 'Include Advocate Articles';
  return $form;
}

function statesidelegal_advocate_validate($form, $form_state) {
  
}
function statesidelegal_advocate_submit($form, $form_state) {
  
  global $base_path;
  $apath = "library/" . $_SESSION['sl_page'][0];
  if($_SESSION['is_advocate'][0]){
      $_SESSION['is_advocate'][0]=false;
      $form['statesidelegal_advocate']['submit']['#src'] = $base_path .'/'.drupal_get_path('theme','state7').
                '/images/uncheckbox.gif';
  }
  else {
      $_SESSION['is_advocate'][0]=true;
      $form['statesidelegal_advocate']['submit']['#src'] = $base_path .'/'.drupal_get_path('theme','state7').
                '/images/checkbox.gif';      
  }
  $form_state['redirect'] = $apath;
}

function statesidelegal_mapfilter($form, &$form_state)  {
  global $base_path;
  $cState = $_SESSION['my_state'][0];
  $cZip = $_SESSION['my_zip'][0];
  $cType = $_SESSION['my_org_type'][0];
  if ($cState == ""){
    if(isset($_SESSION['triage']['my_state'])){
      $cState = $_SESSION['triage']['my_state'];
    }
    else {
      if (isset($_SESSION['smart_ip']['location']['region'])){
        $cState = $_SESSION['smart_ip']['location']['region'];
      }
    }
  }
  $form['statesidelegal_map'] = array(
      '#title' => t('Map Filter'), 
      '#attributes' => array('class' => array('no-mobile')),
  );
  
  $form['state_options'] = array(
    '#type' => 'value',
    '#value' => array(
          'All' => 'All States',
          'Alabama' => 'Alabama',
          'Alaska' => 'Alaska',
          'Arizona' => 'Arizona',
          'Arkansas' => 'Arkansas',
          'California' => 'California',
          'Colorado' => 'Colorado',
          'Connecticut' => 'Connecticut',
          'Delaware' => 'Delaware',
          'District of Columbia' => 'District of Columbia',
          'Florida' => 'Florida',
          'Georgia' => 'Georgia',
          'Hawaii' => 'Hawaii',
          'Idaho' => 'Idaho',
          'Illinois' => 'Illinois',
          'Indiana' => 'Indiana',
          'Iowa' => 'Iowa',
          'Kansas' => 'Kansas',
          'Kentucky' => 'Kentucky',
          'Louisiana' => 'Louisiana',
          'Maine' => 'Maine',
          'Maryland' => 'Maryland',
          'Massachusetts' => 'Massachusetts',
          'Michigan' => 'Michigan',
          'Minnesota' => 'Minnesota',
          'Mississippi' => 'Mississippi',
          'Missouri' => 'Missouri',
          'Montana' => 'Montana',
          'Nebraska' => 'Nebraska',
          'Nevada' => 'Nevada',
          'New Hampshire' => 'New Hampshire',
          'New Jersey' => 'New Jersey',
          'New Mexico' => 'New Mexico',
          'New York' => 'New York',
          'North Carolina' => 'North Carolina',
          'North Dakota' => 'North Dakota',
          'Northern Mariana Islands' => 'Northern Mariana Islands',
          'Ohio' => 'Ohio',
          'Oklahoma' => 'Oklahoma',
          'Oregon' => 'Oregon',
          'Pennsylvania' => 'Pennsylvania',
          'Rhode Island' => 'Rhode Island',
          'South Carolina' => 'South Carolina',
          'South Dakota' => 'SouthDakota',
          'Tennessee' => 'Tennessee',
          'Texas' => 'Texas',
          'Utah' => 'Utah',
          'Vermont' => 'Vermont',
          'Virginia' => 'Virginia',
          'Washington' => 'Washington',
          'West Virginia' => 'West Virginia',
          'Wisconsin' => 'Wisconsin',
          'Wyoming' => 'Wyoming' )
        );
    $form['state_org_types'] = array(
        '#type' => 'value',
        '#value' => array(
            '' => 'All Org Types',
            'LSC'=>'Civil Legal Aid',
            'FLC'=>'Free Legal Clinics at VA Health Facilities',
            'VSA'=>'Veteran Affairs',
            'JAG'=>'Military JAG',
            'LRS'=>'Lawyer Referral',
            'WMN'=>"Women's Network",
            'Other' => 'Other')
        );

    $form['statesidelegal_map']['statesidelegal_zip'] = array(
      '#type' => 'textfield',
      '#size' => 5,
        '#default_value' => $cZip,
      '#attributes' => array('placeholder' => t('Enter zipcode'),'onchange' => 'jQuery("#showmap #map").html("");form.submit("statesidelegal_mapfilter")')
    );

    $form['statesidelegal_map']['search2'] = array(
        '#type' => 'image_button',
        '#id' => 'search2',
        '#src' => 'images/search2.png'
    );
    $form['statesidelegal_map']['statesidelegal_state'] = array(
      '#type' => 'select',
      '#options' => $form['state_options']['#value'],
      '#default_value' => $cState,
      '#attributes' => array('placeholder' => t('Enter state'),'onchange' => 'jQuery("#showmap #map").html("");form.submit("statesidelegal_mapfilter")')
    );
    $form['statesidelegal_map']['search1'] = array(
        '#type' => 'image_button',
        '#id' => 'search1',
        '#src' => 'images/search2.png'
    );
    $form['statesidelegal_map']['statesidelegal_org_type'] = array(
      '#type' => 'select',
      '#options' => $form['state_org_types']['#value'],
      '#default_value' => $cType,
      '#attributes' => array('placeholder' => t('Org type'),'onchange' => 'jQuery("#showmap #map").html("");form.submit("statesidelegal_mapfilter")')
    );
    $form['statesidelegal_map']['search3'] = array(
        '#type' => 'image_button',
        '#id' => 'search3',
        '#src' => 'images/qm.png',
        '#title' => 'Help',
        '#attributes' => array('onclick' => 'return false;')
    );
    $form['statesidelegal_advocate']['submit'] = array(
        '#id' => 'map_submit',
        '#type' => 'submit' );
  return $form;
}
function statesidelegal_mapfilter_validate($form, $form_state) {
  
}
function statesidelegal_mapfilter_submit($form, $form_state) {
  global $base_path;
  if ($form_state['values']['statesidelegal_zip'] == 'Enter zipcode'){
      $cZip = "";
  }
  else {
      $cZip = $form_state['values']['statesidelegal_zip'];
  }
  if ($form_state['values']['statesidelegal_state'] == 'Enter state'){
      $cState = "";
  }
  else {
      $cState = $form_state['values']['statesidelegal_state'];
  }
  if ($form_state['values']['statesidelegal_org_type'] == 'Org type'){
      $cType = "";
  }
  else {
      $cType = $form_state['values']['statesidelegal_org_type'];
  }
  if ($cState == $_SESSION['my_state'][0]){}
  else { $cZip = ""; }
  if ($cZip > ""){
      if ($cZip ==  $_SESSION['my_zip'][0]){}
      else {
        $data = get_location_infos($cZip);
        $cState = $data['state'];
      }
  }
  $_SESSION['my_zip'][0]= $cZip;
  $_SESSION['my_org_type'][0]= $cType;
  $_SESSION['my_state'][0] = $cState;
  $form_state['redirect'] = $base_path . 'statesidemap';
}

function statesidelegal_mapfilter_changed_callback($form, &$form_state){
  statesidelegal_mapfilter_submit($form, $form_state);
}
function statesidevolunteer_mapfilter($form, &$form_state)  {
  global $base_path;
  $cState = $_SESSION['vol_state'][0];
  $cVirtual = $_SESSION['vol_virtual'][0];
  $cZip = $_SESSION['vol_zip'][0];
  $cType = $_SESSION['vol_type'][0];
  $vType["0"] = "*All Volunteer Types";
  $virType["0"] = "*All Work Sites";
  $vKeys = $_SESSION['vol_keys'][0];
  $sql = 'select tid, name 
            from taxonomy_term_data 
            where vid = 23';
  $vTypes = db_query($sql);
  foreach ($vTypes as $vt){
      $vType[$vt->tid] = $vt->name;
  }
  $sql = 'select tid, name 
            from taxonomy_term_data 
            where vid = 25';
  $virTypes = db_query($sql);
  foreach ($virTypes as $vt){
      $virType[$vt->tid] = $vt->name;
  }
  
  if ($cState == ""){
    if (isset($_SESSION['smart_ip']['location']['region'])){
      $cState = $_SESSION['smart_ip']['location']['region'];
    }
  }
  $form['statesidevolunteer_map'] = array(
      '#title' => t('Map Filter'), 
      '#attributes' => array('class' => array('no-mobile')),
  );
  
  $form['vol_state_options'] = array(
    '#type' => 'value',
    '#value' => array(
               'All' => '*All States',
               'AL' => 'Alabama',
               'AK' => 'Alaska',
               'AZ' => 'Arizona',
               'AR' => 'Arkansas',
               'CA' => 'California',
               'CO' => 'Colorado',
               'CT' => 'Connecticut',
               'DE' => 'Delaware',
               'DC' => 'District Of Columbia',
               'FL' => 'Florida',
               'GA' => 'Georgia',
               'HI' => 'Hawaii',
               'ID' => 'Idaho',
               'IL' => 'Illinois',
               'IN' => 'Indiana',
               'IA' => 'Iowa',
               'KS' => 'Kansas',
               'KY' => 'Kentucky',
               'LA' => 'Louisiana',
               'ME' => 'Maine',
               'MD' => 'Maryland',
               'MA' => 'Massachusetts',
               'MI' => 'Michigan',
               'MN' => 'Minnesota',
               'MS' => 'Mississippi',
               'MO' => 'Missouri',
               'MT' => 'Montana',
               'NE' => 'Nebraska',
               'NV' => 'Nevada',
               'NH' => 'New Hampshire',
               'NJ' => 'New Jersey',
               'NM' => 'New Mexico',
               'NY' => 'New York',
               'NC' => 'North Carolina',
               'ND' => 'North Dakota',
               'OH' => 'Ohio',
               'OK' => 'Oklahoma',
               'OR' => 'Oregon',
               'PA' => 'Pennsylvania',
               'RI' => 'Rhode Island',
               'SC' => 'South Carolina',
               'SD' => 'South Dakota',
               'TN' => 'Tennessee',
               'TX' => 'Texas',
               'UT' => 'Utah',
               'VT' => 'Vermont',
               'VA' => 'Virginia',
               'WA' => 'Washington',
               'WV' => 'West Virginia',
               'WI' => 'Wisconsin',
               'WY' => 'Wyoming',
        ));
    $form['state_vol_types'] = array(
        '#type' => 'value',
        '#value' => $vType
        );
    $form['statesidevolunteer_map']['statesidevolunteer_type'] = array(
      '#type' => 'select',
      '#options' => $form['state_vol_types']['#value'],
      '#default_value' => $cType,
      '#attributes' => array('placeholder' => t('Volunteer Type'),'onchange' => 'jQuery("#showmap #map").html("");form.submit("statesidevolunteer_mapfilter")')
    );
    $form['state_vol_virtual'] = array(
        '#type' => 'value',
        '#value' => $virType
        );
    $form['statesidevolunteer_map']['statesidevolunteer_virtype'] = array(
      '#type' => 'select',
      '#options' => $form['state_vol_virtual']['#value'],
      '#default_value' => $cVirtual,
      '#attributes' => array('placeholder' => t('Work Site'),'onchange' => 'jQuery("#showmap #map").html("");form.submit("statesidevolunteer_mapfilter")')
    );
    $form['statesidevolunteer_map']['statesidevolunteer_state'] = array(
      '#type' => 'select',
      '#options' => $form['vol_state_options']['#value'],
      '#default_value' => $cState,
      '#attributes' => array('placeholder' => t('Enter state'),'onchange' => 'jQuery("#showmap #map").html("");form.submit("statesidevolunteer_mapfilter")')
    );

//    $form['statesidevolunteer_map']['statesidevolunteer_keys'] = array(
//      '#type' => 'textfield',
//      '#title' => 'Search for',
//      '#size' => 20,
//      '#default_value' => $vKeys,
//      '#attributes' => array('placeholder' => t('Enter search term'),'onchange' => 'jQuery("#showmap #map").html("");form.submit("statesidelegal_mapfilter")')
//    );

    $form['statesidevolunteer_map']['submit'] = array(
        '#id' => 'map_submit',
        '#type' => 'submit' );
    $form['statesidevolunteer_map']['reset'] = array(
        '#type' => 'submit',
        '#value' => t('Reset'),
  );
    
  return $form;
}
function statesidevolunteer_mapfilter_validate($form, $form_state) {
  
}
function statesidevolunteer_mapfilter_submit($form, $form_state) {
  global $base_path;
  $op = $form_state['values']['op'];
  if ($form_state['values']['statesidevolunteer_state'] == 'Enter state'){
      $cState = "";
  }
  else {
      $cState = $form_state['values']['statesidevolunteer_state'];
  }
  if ($form_state['values']['statesidevolunteer_type'] == 'Volunteer Type'){
      $cType = "";
  }
  else {
      $cType = $form_state['values']['statesidevolunteer_type'];
  }
  if ($form_state['values']['statesidevolunteer_virtype'] == 'Work Site'){
      $cVirtual = "";
  }
  else {
      $cVirtual = $form_state['values']['statesidevolunteer_virtype'];
      if ($cVirtual=="0"){$cVirtual="";}
  }
  if ($form_state['values']['statesidevolunteer_keys'] == 'Enter search term'){
      $vKeys = "";
  }
  else {
      $vKeys = $form_state['values']['statesidevolunteer_keys'];
  }
  if ($cState == $_SESSION['vol_state'][0]){}
  switch ($op) {
    case t('Reset'):
        $cState="";
        $cType="";
        $vKeys="";
        $cVirtual="";
        break;
  }

  $_SESSION['vol_state'][0] = $cState;
  $_SESSION['vol_type'][0] = $cType;
  $_SESSION['vol_virtual'][0] = $cVirtual;
  $_SESSION['vol_keys'][0] = $vKeys;
  $form_state['redirect'] = $base_path . 'volunteermap';
}

function statesidevolunteer_mapfilter_changed_callback($form, &$form_state){
  statesidevolunteer_mapfilter_submit($form, $form_state);
}
function stateside_multi_topics_form($form, &$form_state){
   $form['stateside_multi_topics'] = array(
      '#title' => t(''), 
      '#attributes' => array('class' => array('no-mobile')),
  );
  
}
function statesidelegal_form_alter(&$form, &$form_state, $form_id){
  global $user;
  
  if ($form_id == "group_content_node_form"){
      $alias = $_SERVER['HTTP_REFERER'];
      $nid = db_query('select source from url_alias where alias = :alias',array(':alias'=>$alias))->fetchcolumn();
      $node = node_load($nid);
      $from_group = false;
      if ($node->type == "group"){$from_group = true;}
      if (empty($form['og_group_ref']['und'][0]['default']['#default_value'])){
        if (! $from_group){
            $nid = db_query("select gid from og_membership where entity_type = 'user' and etid = :uid", array(':uid'=>$user->uid))->fetchColumn();
        }
        $form['og_group_ref']['und'][0]['default']['#default_value'] = $nid;
      }
      if (empty($forms['domains']['domains']['default_value'])){
        $forms['domains']['domains']['default_value'] = array('1'=>1,'2'=>1);
      }
      if (user_has_role(5) || $user->uid == 1){          
      }
      else {
          field_group_hide_field_groups($form, array('group_cats'));
          $form['domain']['#access'] = FALSE ;
      }
//      $form['domain']['#states'] = array('invisible' => TRUE);
  }
  //dsm($form_id);  // print form ID to messages
}
function statesidelegal_rate_widget_alter(&$widget, $context) {
    $exclude_pages = array();
    $exclude_pages[] = 'my-groups';
    $thispage = basename($_SERVER['REQUEST_URI']);
    //dsm($thispage);
    if (in_array($thispage,$exclude_pages)){
        $widget->title = '';
    }
}