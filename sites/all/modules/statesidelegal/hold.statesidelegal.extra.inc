<?php
/**
 * Created by PhpStorm.
 * User: bds
 * Date: 10/27/16
 * Time: 10:23 AM
 */
function stateside_extra_notify($nid=0){
  global $base_url;
  if ($nid > 0) {
    $node = node_load($nid);
    $teaser = render(field_view_field('node', $node, 'body', array(
      'label'=>'hidden',
      'type' => 'text_summary_or_trimmed',
      'settings'=>array('trim_length' => 500),
    )));
    $groups = db_query("select gid from og_membership where entity_type = 'node' and etid=:nid", array(":nid" => $nid))->fetchCol(0);
    $qry = db_select('og_membership', 'og');
    print render($teaser);    $qry->addField('og', 'etid', 'uid');
    $qry->addField('og', 'gid');
    $qry->innerJoin('notifications_subscription', 'n', 'n.uid = og.etid');
    $qry->condition('og.entity_type', 'user')
      ->condition('og.gid', $groups, "IN")
      ->condition('n.type', 'group_content')
      ->groupBy('og.etid');
    $ids = $qry->execute();
    //dsm($qry->execute()->fetchCol(0));
    foreach ($ids as $id) {
      $send_to = user_load($id->uid)->mail;
      $gname = db_query("select title from node where nid=:gid", array(":gid" => $id->gid))->fetchColumn();
      if ($send_to > ''){
      //if ($send_to == 'info@bdsworks.org') {
        $url = $base_url . "/node/" . $nid;
        $output = "<div class='site-name'><h3>" . variable_get('site_name') . "</h3></div>";
        $output .= "<div class='og-new-content'>" . $gname . " has new content<br/>";
        $output .= "<p><a href='" . $url . "'>" . $node->title . "</a></p>";
        $output .= "<div style='font-size: 85%; margin-left: 10px;'>" . $teaser . "</div></div>";
        $msg = "Email to " . $send_to . " failed";
        mailsystem_set(array(
          'statesidelegal' => 'HTMLMailSystem', // All messages sent by $module.
        ));
        $success = stateside_extra_mail('default_from', $send_to, 'New Content at Stateside Legal', $output);
        if ($success) {
          $msg = "Email to " . $send_to . " was successfully sent as part of group subscription";
        } else {
          $msg = "Email to " . $send_to . " was not sent as part of group subscription";
        }
        watchdog('subscription_email', $msg);
      }
    }
  }
}
function stateside_extra_mail($from = 'default_from', $to, $subject, $message) {
  $my_module = 'statesidelegal';
  $my_mail_token = microtime();
  if ($from == 'default_from') {
    // Change this to your own default 'from' email address.
    $from = variable_get('site_mail', 'brian@bdsworks.org');
  }
  $message = array(
    'id' => $my_module . '_' . $my_mail_token,
    'to' => $to,
    'subject' => $subject,
    'body' => array($message),
    'headers' => array(
      'From' => $from,
      'Sender' => $from,
      'Return-Path' => $from,
    ),
  );
  $system = drupal_mail_system($my_module, $my_mail_token);
  $message = $system->format($message);
  if ($system->mail($message)) {
    return TRUE;
  }
  else {
    return FALSE;
  }
}
function statesidelegal_form_organization_node_form_alter(&$form, &$form_state, $form_id) {
  $_SESSION['org_state'] = '';
  $form['field_counties_served']['#prefix'] = "<div id='counties-wrapper'> " ;
  $form['field_counties_served']['#suffix'] = "</div>";
  $selected = isset($form_state['values']['field_states_served']['und'][0]['tid']) ? $form_state['values']['field_states_served']['und'][0]['tid'] : '';
  $_SESSION['org_state'] = $selected;
  $opts = statesidelegal_get_counties($selected);
  $form['field_counties_served']['und']['#options'] = $opts;
  $form['field_counties_served']['und']['#attributes'] = array('class' => array('sl-counties'));
  $form['domain']['domains']['#required'] = false;
}
function statesidelegal_get_counties($tid = null){
  if (is_null($tid) || is_array($tid) || $tid==''){
    $bds = $_GET['q'];
    $nid = str_replace('node/', '', $bds);
    $nid = str_replace('/edit', '', $nid);
    $node = node_load($nid);
    if ($node && ($_SESSION['org_state']=='')) {
      $tid = $node->field_states_served['und'][0]['tid'];
      $_SESSION['org_state'] = $tid;
    }
    else {
      if (isset($_SESSION['org_state'])){
        $tid = $_SESSION['org_state'];
      }
    }
  }
  $state = taxonomy_term_load($tid)->name;
  $opts = db_query("SELECT id, county_name FROM bdscounty_fips WHERE state_name = :state order by 2",
    array(':state' => $state))->fetchAllKeyed();
  return $opts;
}
function statesidelegal_counties($tid = null){
  $_SESSION['org_state'] = $tid;
  $opts = statesidelegal_get_counties($tid);
  return drupal_json_output($opts);
}