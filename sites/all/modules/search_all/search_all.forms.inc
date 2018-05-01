<?php

function search_all_keyform($form, &$form_state)  {
  //$form_default = t('Enter keyword or phrase');
  drupal_add_js(
     'jQuery(document).ready(function () {
        jQuery("#edit-submitkeys").click(function(){
            jQuery("<div/>", {
            class: "waiting",
            text: "Searching"}).appendTo("body");
        });
      });',
     'inline');
    
  $form['search_all_key'] = array(
      '#title' => t('Search Box'), 
      '#attributes' => array('class' => array('no-mobile')),
  );
  $form['search_all_key']['search_all_term'] = array(
      '#type' => 'textfield',
      '#size' => 50,
      '#attributes' => array(
              'placeholder' => t('Enter search term')),
  );
  $form['search_all_key']['submitkeys'] = array(
    '#type' => 'submit',
    '#value' => "",
    '#weight' => 19,
  );    
  return $form;
}

function search_all_keyform_validate($form, $form_state) {
  
}
function search_all_keyform_submit($form, &$form_state){
  $search_all_key = search_simplify($form_state['values']['search_all_term']);
  $form_state['redirect'] = 'search_all/' . $search_all_key;
}

function search_all_advocate($form, &$form_state)  {
  global $base_path;
  drupal_add_js(
     'jQuery(document).ready(function () {
        jQuery("#edit-submit").click(function(){
            jQuery("#edit-submit").addClass("advocate-no-show");
            jQuery("#edit-submit").removeClass("advocate-show")
            jQuery("#edit-submit2").addClass("advocate-show");
            jQuery("#edit-submit2").removeClass("advocate-no-show")
            jQuery("<div/>", {class: "waiting",text: "Searching"}).appendTo("body");
            
        });
        jQuery("#edit-submit2").click(function(){
            jQuery("#edit-submit2").addClass("advocate-no-show");
            jQuery("#edit-submit2").removeClass("advocate-show")
            jQuery("#edit-submit").addClass("advocate-show");
            jQuery("#edit-submit").removeClass("advocate-no-show")
            jQuery("<div/>", {class: "waiting",text: "Searching"}).appendTo("body");
        });
      });',
     'inline');

  $click_pic = $base_path . drupal_get_path('module','search_all').'/images/checkbox.gif';
  $unclick_pic = $base_path . drupal_get_path('module','search_all').'/images/uncheckbox.gif';
  $is_advocate = $_SESSION['is_advocate'][0];
  $form['search_all_advocate'] = array(
      '#title' => t('Advocate View'), 
      '#attributes' => array('class' => array('no-mobile')),
  );
  
  $form['search_all_advocate']['submit']['#type'] = 'image_button';
  $form['search_all_advocate']['submit']['#src'] = $click_pic;
  $form['search_all_advocate']['submit2']['#type'] = 'image_button';
  $form['search_all_advocate']['submit2']['#src'] = $unclick_pic;
  if ($is_advocate){
      $form['search_all_advocate']['submit']['#attributes'] = array('class' => array('advocate-show'));
      $form['search_all_advocate']['submit2']['#attributes'] = array('class' => array('advocate-no-show'));
  }
  else {
      $form['search_all_advocate']['submit']['#attributes'] = array('class' => array('advocate-no-show'));
      $form['search_all_advocate']['submit2']['#attributes'] = array('class' => array('advocate-show'));
  }
  
  //$form['search_all_advocate']['submit']['#value'] = 'Include Advocate Articles';
  return $form;
}

function search_all_advocate_validate($form, $form_state) {
  
}
function search_all_advocate_submit($form, $form_state) {
  
  global $base_path;
  $apath = "library" ;
  if($_SESSION['is_advocate'][0]){
      $_SESSION['is_advocate'][0]=false;
      $form['search_all_advocate']['submit']['#src'] = $base_path .'/'.drupal_get_path('module','search_all').
                '/images/uncheckbox.gif';
  }
  else {
      $_SESSION['is_advocate'][0]=true;
      $form['search_all_advocate']['submit']['#src'] = $base_path .'/'.drupal_get_path('module','search_all').
                '/images/checkbox.gif';      
  }
  $form_state['redirect'] = $apath;
}

