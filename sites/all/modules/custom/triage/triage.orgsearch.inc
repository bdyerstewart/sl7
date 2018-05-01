<?php

function triage_orgfind($tid = 0, $item, $titl = '', $orgtype = NULL) {
  $output = '';
  $nvo = 'teaser';
  $len = 350;
  $types = explode(",", $item->action_text);
  if ($item->node_view_opt > '') {
    $nvo = $item->node_view_opt;
  }
  $status = array();
  if ($_SESSION['triage']['triage_status']) {
    $status = array_values($_SESSION['triage']['triage_status']);
  }

}

function triage_orgsearch($tid = 0, $item, $titl = '', $orgtype = NULL) {
  if( ! $_SESSION['triage']['my_tid'] ){
    return "";
  }
  $output = '';
  $nvo = 'teaser';
  $len = 350;
  $types = explode(",", $item->action_text);
  if ($item->node_view_opt > '') {
    $nvo = $item->node_view_opt;
  }
  // Set user search variables
  // County and POV are single value variables
  $county = $_SESSION['triage']['my_county'];
  $pov = triage_percent_pov();
  // Status and Legal Problem are potentially multivalue variables
  $status = array(0);
  if ($_SESSION['triage']['triage_status']) {
    $status = array_values($_SESSION['triage']['triage_status']);
  }
  if (!$status) {
    $status = array();
    $status[] = 0;
  }
  $tbl = variable_get('triage_orgsearch_field', '');
  $cnty = variable_get('triage_orgcounty_field', '');
  $inctbl = variable_get('triage_orgincome_field', '');
  $sttbl = variable_get('triage_status_field', '');
  $ogtbl = variable_get('triage_orgtype_field', '');
  $fld = $tbl . "_tid";
  $fld2 = $cnty . "_nid";
  $fld5 = $ogtbl . "_tid";
  $stfld = $sttbl . "_tid";
  if ($tbl == '') {
    return '';
  }
  $tbl = 'field_data_' . $tbl;
  $tbl2 = 'field_data_' . $cnty;
  $tbl3 = 'field_data_' . $inctbl;
  $tbl4 = 'field_data_' . $sttbl;
  $tbl5 = 'field_data_' . $ogtbl;
  $query = db_select('node', 'n');
  $query->addField('n', 'nid');
  $query->distinct();
  if ($titl !== "DV Shelter") {
    $query->LeftJoin($tbl, 't', 't.entity_id=n.nid');
    $query->condition('t.' . $fld, $tid);
  }
  if (count($types) > 0) {
    $query->condition('n.type', ($types), "IN");
  }
  if ($cnty) {
    $mycnty = $_SESSION['triage']['my_county'];
    if ($mycnty) {
      $cntynid = db_query("select nid from node where type='county' and title=:title", array(':title' => $mycnty))->fetchColumn();
      if ($cntynid) {
        $query->innerJoin($tbl2, 'c', 'c.entity_id=n.nid');
        $query->condition('c.' . $fld2, $cntynid);
      }
    }
  }
  if ($ogtbl) {
    if ($orgtype) {
      $query->innerJoin($tbl5, 'o', 'o.entity_id=n.nid');
      $query->condition('o.' . $fld5, $orgtype, 'IN');
    }
  }
  //watchdog('bds-triage',dpq_triage($query, TRUE));
  $results = $query->execute()->fetchCol();
  $nids = array();

  foreach ($results as $nid) {
    if ($titl !== "DV Shelter") {
      $query = db_select('field_data_field_income_visibility', 'v');
      $query->condition('v.entity_id', $nid);
      $query->addField('v', 'field_income_visibility_value');
      $inc = $query->execute()->fetchColumn();
      if ($inc && $pov) {
        if ($inc < $pov) {
          continue;
        }
      }
      else {
        if ($inctbl) {
          $incfld = $inctbl . "_tid";
          $query = db_select($tbl3, "i");
          $query->condition('i.entity_id', $nid);
          $query->innerJoin('taxonomy_term_data', 't', 't.tid = i.' . $incfld);
          $query->addField('t', 'tid');
          $inc_elig_tid = $query->execute()->fetchColumn();
          if ($inc_elig_tid) {
            if (!in_array($inc_elig_tid, $_SESSION['triage']['triage_eligibility'])) {
              continue;
            }
          }
        }
      }
    }
    if ($sttbl) {
      $query = db_select($tbl4, 's');
      $query->condition('s.entity_id', $nid);
      $query->addField('s', $stfld);
      $stat = $query->execute()->fetchCol();
      if ($stat) {
        if (!array_intersect($stat, $status)) {
          continue;
        }
      }
      else {
        if ($titl == "DV Shelter") {
          continue;
        }
      }
    }
    $nids[] = $nid;
  }

  if ($titl !== "DV Shelter") {
    // Then we go get a list of nids from triage_org_conditions table
    $nonids = array();
    $filter = ' true ';
    if ($pov) {
      $filter = " (income_filter >= " . $pov . "  OR income_filter = 0) ";
    }
    // first get the excludes
    if ($county) {
      $sql = "select id 
              from triage_org_conditions 
              where $filter 
              and find_in_set(:td, legal_problem)
              and find_in_set(:cnty, county_filter)
              and type='exclude'";
      $ids = db_query($sql, array(
        ':td' => $tid,
        ':cnty' => $county
      ))->fetchCol();
    }
    else {
      $sql = "select id 
              from triage_org_conditions 
              where $filter
              and find_in_set(:td, legal_problem)
              and county_filter = ''
              and type='exclude'";
      $ids = db_query($sql, array(':td' => $tid))->fetchCol();
    }
    //dsm($ids);
    foreach ($ids as $id) {
      $record = db_query('select * from triage_org_conditions where id = :id', array(':id' => $id))->fetchAssoc();
      if ($record['status_filter']) {
        $stats = explode(",", $record['status_filter']);
        if (array_intersect($stats, $status)) {
          $nonids[] = $record['entity_id'];
        }
      }
      else {
        $nonids[] = $record['entity_id'];
      }
    }

    // Then get the includes
    if ($county) {
      $sql = "select id 
              from triage_org_conditions 
              where $filter 
              and find_in_set(:td, legal_problem)
              and find_in_set(:cnty, county_filter)
              and type='include'";
      $ids = db_query($sql, array(
        ':td' => $tid,
        ':cnty' => $county
      ))->fetchCol();
    }
    else {
      $sql = "select id 
              from triage_org_conditions 
              where $filter
              and find_in_set(:td, legal_problem)
              and county_filter = ''
              and type='include'";
      $ids = db_query($sql, array(':td' => $tid))->fetchCol();
    }
    //dsm($ids);
    foreach ($ids as $id) {
      $record = db_query('select * from triage_org_conditions where id = :id', array(':id' => $id))->fetchAssoc();
      if ($record['status_filter']) {
        $stats = explode(",", $record['status_filter']);
        if (array_intersect($stats, $status)) {
          if (!in_array($record['entity_id'], $nonids)) {
            $nids[] = $record['entity_id'];
          }
        }
      }
      else {
        if (!in_array($record['entity_id'], $nonids)) {
          $nids[] = $record['entity_id'];
        }
      }
    }
    if (count($nids) == 0) {
      return '';
    }
  }
  //dsm($nids);
  $ogtbl = variable_get('triage_orgtype_field', '');
  $og_fld = $ogtbl . "_tid";
  $og_tbl = 'field_data_' . $ogtbl;
  $wt_table = 'field_weight';
  $wt_field = $wt_table . "_value";
  $wt_table = "field_data_" . $wt_table;
  $query = db_select('node', 'n');
  $query->addField('n', 'nid');
  $query->condition('n.nid', $nids, "IN");
  if (count($nonids) > 0) {
    $query->condition('n.nid', $nonids, "NOT IN");
  }
  if (db_table_exists($wt_table)) {
    $query->LeftJoin($wt_table, 'w', 'w.entity_id =n.nid');
  }
  $query->distinct();

  if (count($types) > 0) {
    $query->condition('n.type', ($types), "IN");
  }
  if ($ogtbl) {
    if ($orgtype) {
      $query->innerJoin($og_tbl, 'o', 'o.entity_id=n.nid');
      $query->condition('o.' . $og_fld, $orgtype, 'IN');
    }
  }
  if (db_table_exists($wt_table)) {
    $query->orderBy('n.sticky', 'DESC')->orderBy('w.' . $wt_field);
  }
  else {
    $query->orderBy('n.sticky', 'DESC');
  }
  //dpq_triage($query);
  $results = $query->execute()->fetchCol();

  $nodeview = $nvo;
  if (is_null($nvo) || is_int($nvo)) {
    $nodeview = 'teaser';
  }
  if ($nvo == 'trim') {
    $nodeview = 'full';
  }
  $master_count = 0;
  $no_generic = FALSE;
  foreach ($results as $nid) {
    $sql = 'select entity_id from field_data_field_organization_type 
              where entity_id = :nid 
              and field_organization_type_tid = 1';
    $find = db_query($sql, array(':nid' => $nid))->fetchColumn();
    if ($find) {
      $no_generic = TRUE;
    }
  }
  foreach ($results as $nid) {
    if ($nid == 792 && $no_generic) {
      continue;
    }
    if (in_array($nid, $_SESSION['triage']['end_nodes'])) {
      continue;
    }
    else {
      $_SESSION['triage']['end_nodes'][] = $nid;
    }
    $master_count++;
    $node = node_load($nid);
    $build = node_view($node, $nodeview);
    if ($nvo == 'trim') {
      //$txt = strip_tags($build['body'][0]["#markup"]);
      $config = array(
        'safe' => 1,
        'elements' => '-img',
      );
      $txt = htmLawed($build['body'][0]["#markup"], $config);
      //dsm($txt);
      $txt1 = mb_strimwidth($txt, 0, $len, "...");
      //dsm($txt1);
      $build['body'][0]["#markup"] = $txt1;

    }
    unset($build['links']['blog']);
    unset($build['links']['comment']);
    //$build['links']['node']['#links'] = $lnk;
    $build['body']['#object']->title = $node->title;
    unset($build['print_links']);
    //dsm($build);
    $class = $item->classes;
    if ($nvo == 'triage_view_mode') {
      $class .= ' triage-remove-a ';
    }
    if ($class == "none") {
      $output .= "<div class='triage-action-item'>";
    }
    else {
      $output .= "<div class='triage-action-item " . $class . "'>";
    }
    $output .= drupal_render($build);
    if ($nvo == 'trim') {
      $output .= "<ul class='links inline'><li class='node-readmore'>" . l('Read More', 'node/' . $nid) . "</li><ul>";
    }
    $output .= "</div>";
  }
  if ($results) {
    if ($titl > '') {
      $output = "<h4>" . $titl . '</h4>' . $output;
    }
  }
  if ($master_count == 0) {
    $output = '';
  }
  return $output;
}

function triage_orgsearch_sl($tid = 0, $item, $titl = '') {
  $endterm = taxonomy_term_load($tid);
  $triage_voc = $endterm->vid;
  $output = '';
  $nvo = 'teaser';
  $len = 350;
  $types = explode(",", $item->action_text);
  if ($item->node_view_opt > '') {
    $nvo = $item->node_view_opt;
  }
  $srchtbl = variable_get('triage_orgsearch_field', '');
  $cnty = variable_get('triage_orgcounty_field', '');
  $inc = variable_get('triage_orgincome_field', '');
  $srchfld = $srchtbl . "_tid";
  $cntyfld = $cnty . "_value";
  $inctype = 'taxonomy_term_reference';
  if ($inc) {
    $inctype = db_query('select type from field_config where field_name = :fn', array(':fn' => $inc))->fetchcolumn();
  }
  if ($inctype == 'taxonomy_term_reference') {
    $incfld = $inc . "_tid";
  }
  else {
    $incfld = $inc . "_value";
  }

  if ($srchtbl == '') {
    return '';
  }
  $srchtbl = 'field_data_' . $srchtbl;
  $cntytbl = 'field_data_' . $cnty;
  $inctbl = 'field_data_' . $inc;

  $valquery = db_select($srchtbl, 'x');
  $valquery->addField("x", $srchfld, 'tid');
  $valquery->condition('x.entity_id', $tid);
  $valquery->condition('x.entity_type', 'taxonomy_term');
  $valset = $valquery->execute()->fetchAll();
  watchdog('bdsorg',serialize($valset));


  $query = db_select('node', 'n');
  $query->addField('n', 'nid');
  $query->innerJoin('field_data_field_active', 'a', 'a.entity_id = n.nid');
  $query->innerJoin($srchtbl, 's', 's.entity_id = n.nid');
  $query->condition('s.' . $srchfld, $valquery, "IN");
  $query->condition('s.entity_type', 'node');
  $query->condition('a.field_active_value', 1);
  if (count($types) > 0) {
    $query->condition('n.type', ($types), "IN");
  }
  if ($cnty) {
    $mycnty = $_SESSION['triage']['my_county'];
    $my_state = $_SESSION['triage']['my_state'];
    if ($mycnty && $my_state) {
      $cntynid = db_query("select id from bdscounty_fips where state_name=:state and county_name=:cn", array(
        ':state' => $my_state,
        ':cn' => $mycnty
      ))->fetchColumn();
      if ($cntynid) {
        $query->leftJoin($cntytbl, 'c', 'c.entity_id=n.nid');
        $query->leftJoin("field_data_field_states_served", 'ss', 'ss.entity_id=n.nid');
        $db_or = db_or();
        $db_or->condition('c.' . $cntyfld, $cntynid);
        $db_or->condition('ss.field_states_served_tid', 4198);
        $query->condition($db_or);
      }
      else{
        $query->leftJoin("field_data_field_states_served", 'ss', 'ss.entity_id=n.nid');
        $query->condition('ss.field_states_served_tid', 4198);
      }
    }
    else{
      $query->leftJoin("field_data_field_states_served", 'ss', 'ss.entity_id=n.nid');
      $query->condition('ss.field_states_served_tid', 4198);
    }
  }
  else{
    $query->leftJoin("field_data_field_states_served", 'ss', 'ss.entity_id=n.nid');
    $query->condition('ss.field_states_served_tid', 4198);
  }
  if($inctype !== 'taxonomy_term_reference') {
    if ($inc) {
      $pov = $_SESSION['triage']['triage_percent_pov'];
      if ($pov > 0) {
        $query->leftJoin($inctbl, 'i', 'i.entity_id = n.nid');
        $db_or = db_or();
        $db_or->condition('i.' . $incfld, $pov, '>=');
        $db_or->condition('i.' . $incfld, 0);
        $db_or->condition('i.' . $incfld, null);
        $db_or->condition('i.' . $incfld, "");
        $query->condition($db_or);
      }
    }
  }

  $query->groupBy('n.nid');
  watchdog('bds_sql', dpq_triage($query, TRUE));
  $results = $query->execute()->fetchCol();

  $nodeview = $nvo;
  if (is_null($nvo) || is_int($nvo)) {
    $nodeview = 'teaser';
  }
  if ($nvo == 'trim') {
    $nodeview = 'full';
  }
  $master_count = 0;
  foreach ($results as $nid) {
    if ($inctype == 'taxonomy_term_reference') {
      if ($inc) {
        $query = db_select($inctbl, "i");
        $query->condition('i.entity_id', $nid);
        $query->innerJoin('taxonomy_term_data', 't', 't.tid = i.' . $incfld);
        $query->addField('t', 'tid');
        $inc_elig_tid = $query->execute()->fetchColumn();
        if ($inc_elig_tid) {
          if (!in_array($inc_elig_tid, $_SESSION['triage']['triage_eligibility'])) {
            continue;
          }
        }
      }
    }
    $master_count++;
    $node = node_load($nid);
    $build = node_view($node, $nodeview);
    if ($nvo == 'trim') {
      $config = array(
        'safe' => 1,
        'elements' => '-img',
      );
      $txt = htmLawed($build['body'][0]["#markup"], $config);
      $txt1 = mb_strimwidth($txt, 0, $len, "...");
      $build['body'][0]["#markup"] = $txt1;

    }
    unset($build['links']['blog']);
    unset($build['links']['comment']);
    $build['body']['#object']->title = $node->title;
    unset($build['print_links']);
    $class = $item->classes;
    if ($nvo == 'triage_view_mode') {
      $class .= ' triage-remove-a ';
    }
    if ($class == "none") {
      $output .= "<div class='triage-action-item'>";
    }
    else {
      $output .= "<div class='triage-action-item " . $class . "'>";
    }
    $output .= drupal_render($build);
    if ($nvo == 'trim') {
      $output .= "<ul class='links inline'><li class='node-readmore'>" . l('Read More', 'node/' . $nid) . "</li><ul>";
    }
    $output .= "</div>";
  }
  if ($results) {
    if ($titl > '') {
      $output = "<h4>" . $titl . '</h4>' . $output;
    }
  }
  if ($master_count == 0) {
    $output = '';
  }
  return $output;

}