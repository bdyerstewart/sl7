<?php
function triage_summary(){
  //get ips to exclude from report - testing, admin, etc
  $noips = explode("\n", variable_get('triage_exclude_ips', ""));
  $thisvid = $_SESSION['triage']['triage_summary_voc'];
  $tp_node = triage_get_page($thisvid);
  $nid = $tp_node->nid;  
  $totalsteps = triage_num_steps($nid);
  //dsm($numsteps);
  $spacer = '&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;';
  $form = drupal_get_form('triage_summary_form');
  $out = drupal_render($form);
  $dmystart = strtotime($_SESSION['triage']['triage_summary_report'][0]);
  $dmyend = strtotime($_SESSION['triage']['triage_summary_report'][1])+86399;
  $summary_only = $_SESSION['triage']['triage_summary_report'][2];
  $vocname = taxonomy_vocabulary_load($thisvid)->name;
  if (! $vocname){$vocname = "No Records Yet";}
  $extra = ' ';
  if ($summary_only){$extra = " Summary ";}
  $out .= "<div><h2>Triage" . $extra . "Report - " .$vocname ."</h2>";
  $count = 0;
  $no_count = 0;
  $oos_count = 0;
  $intake_count = 0;
  if ($summary_only){
    $query = db_select('triage_log','l');
    $query->fields('l', array(
        'id','completed','time','zipcode','county','pov','status','steps','history','last_stop','intake_elig','other_cat','tid','factors','help'));
    $query->condition('l.time',array($dmystart,$dmyend),'BETWEEN');
    $query->condition('l.ip',$noips,'NOT IN');
    $query->condition('l.vid', $thisvid);    
    if (variable_get('triage_nonservice', false)){
        $no_query = clone $query;
        $no_query->isNull('l.non_service_area');
        $no_count = $no_query->countQuery()->execute()->fetchField();


        $oos_query = clone $query;
        $oos_query->condition('l.non_service_area',1);
        $oos_count = $oos_query->countQuery()->execute()->fetchField();
    }
    $cnt_query = clone $query;
    $total_count = $cnt_query->countQuery()->execute()->fetchField();
    $out .= "Total Triage Runs: " . ($total_count) . "<br /><hr />";
    $email_query = clone $query;    
    $email_query->condition('l.email',1);
    $email_count = $email_query->countQuery()->execute()->fetchField();
    if (variable_get('triage_nonservice', false)){
        $query->condition('l.non_service_area',0);
    }
    $cnt_query = clone $query;    
    $cnt_query->condition('l.completed',1);
    $complete_count = $cnt_query->countQuery()->execute()->fetchField();
    $intake_query = clone $query;
    $intake_query->condition('l.intake_elig',1);
    $intake_count = $intake_query->countQuery()->execute()->fetchField();
    if (variable_get('triage_nonservice', false)){
        $out .= "Left without answering 1st question: " . $no_count . "<br />";
        if (variable_get('triage_nonservice', false)){
            $out .= "Out of Service Area: " . $oos_count . "<br />";
        }
    }
    $out .= "Completed Runs: " . $complete_count . "<br />";
    $out .= "Given Online Intake Link: " . $intake_count . "<br />";
    $out .= "Sent Results via Email: " . $email_count . "<br />";
    $cnt_query2 = clone $query;
    $or = db_or();
    $or->condition('l.completed',0);
    $or->condition('l.completed',null);
    $cnt_query2->condition($or);
    //dsm(dpq2($cnt_query2, true));
    $inc_count = $cnt_query2->countQuery()->execute()->fetchField();
    $out .= "Incomplete Runs: " . ($inc_count) . "<br />";
    //By County
    if (variable_get('triage_use_county', false)){
        $rows = array();
        $headers = array(
          array('data' => t('County&nbsp;&nbsp;'), 'field' => 'county'),
          array('data' => t('Number&nbsp;of&nbsp;Triage&nbsp;Runs'), 'field' => 'count'),
          array('data' => t('Complete&nbsp;Runs')),
          array('data' => t('Incomplete&nbsp;Runs')),
        );  
        $cnt_query = clone $query;
        $cnt_query->addExpression('COUNT(l.county)', 'count');
        $cnt_query->groupBy('l.county');
        $cnt_query->extend('TableSort')->orderByHeader($headers);
        //$bds = dpq2($cnt_query,TRUE);
        $results = $cnt_query->execute();
        foreach ($results as $result) {
          $result->county = trim($result->county);
          if ($result->count ==0){
            continue;
          }
          $complete_query = clone $query;
          $complete_query->condition('l.completed',1);
          $complete_query->condition('l.county',trim($result->county));
          $complete = $complete_query->countQuery()->execute()->fetchField();
          //$bds = dpq2($complete_query,TRUE);
          $incomplete_query = clone $query;
          $or = db_or();
          $or->condition('l.completed',0);
          $or->condition('l.completed',null);
          $incomplete_query->condition($or);
          $incomplete_query->condition('l.county',trim($result->county));
          $incomplete = $incomplete_query->countQuery()->execute()->fetchField();
          $rows[] = array(
            trim($result->county),
            $spacer.$result->count,
            $spacer.$complete,
            $spacer.$incomplete,
          );
        }
        $table = theme('table', array(
                    'header' => $headers,
                    'rows' => $rows,
                    'attributes' => array('class' => array('triage_table'))
                ));
        $out .= theme('ctools_collapsible',array(
            'handle' => '<h3>By County:</h3>', 
            'content' => $table,
          )
        );
    }

    // By Kind of Help Sought
    // Get kind of help taxonomy
    $help_vid = ta_variable_get('triage_kind_of_help', '', $nid);
    if($help_vid) {
      $rows = array();
      $headers = array(
        array('data' => t('Help Sought&nbsp;&nbsp;'), 'field' => 'status'),
        array('data' => t('Number&nbsp;of&nbsp;Triage&nbsp;Runs')),
        array('data' => t('% of Runs'))
      );
      $help_query = clone $query;
      $help_query->condition('l.help', '', '>');
      $help_num = $help_query->countQuery()->execute()->fetchField();
      //dsm(dpq2($status_query, true));
      //dsm($vid);
      $helpvals = db_query('select name from taxonomy_term_data where vid = :vid', array(':vid' => $help_vid))->fetchCol();
      //dsm($statvals);
      foreach ($helpvals as $help) {
        $factray = explode(',', $help);
        //dsm($statray);
        $temp_query = clone $help_query;
        $temp_query->condition('l.help', '%' . $help . '%', 'LIKE');
        //dsm(dpq_triage($temp_query, true));
        $num = $temp_query->countQuery()->execute()->fetchField();
        $rows[] = array(
          $help,
          $spacer . $num,
          $spacer . round($num * 100 / $help_num, 2) . '%'
        );
      }

      $table = theme('table', array(
        'header' => $headers,
        'rows' => $rows,
        'attributes' => array('class' => array('triage_table'))
      ));
      $out .= theme('ctools_collapsible', array(
          'handle' => '<h3>By Kind of Help Sought:</h3>',
          'content' => '<h6>Number of runs with Kind of Help entered: ' . $help_num . '</h6>' . $table,
        )
      );
    }

    // By Status
    $rows = array();
    $headers = array(
      array('data' => t('Status&nbsp;&nbsp;'), 'field' => 'status'),
      array('data' => t('Number&nbsp;of&nbsp;Triage&nbsp;Runs')),
      array('data' => t('% of Runs'))
    );  
    $status_query = clone $query;
    $status_query->condition('l.status','','>');
    $stat_num = $status_query->countQuery()->execute()->fetchField();
    //dsm(dpq2($status_query, true));
    // Get status taxonomy for this show/hide display
    $vid = ta_variable_get('triage_status_voc', '', $nid);
    //dsm($vid);
    $statvals = db_query('select name from taxonomy_term_data where vid = :vid',array(':vid'=>$vid))->fetchCol();
    //dsm($statvals);
    foreach($statvals as $stat){
        $statray = explode(',',$stat);
        //dsm($statray);
        $temp_query = clone $status_query;
        $temp_query->condition('l.status','%'.$stat.'%','LIKE');
        //dsm(dpq_triage($temp_query, true));
        $num = $temp_query->countQuery()->execute()->fetchField();
        $rows[] = array(
          $stat,
          $spacer.$num,
          $spacer.round($num*100/$stat_num,2) . '%'
        );
    }
    
    $table = theme('table', array(
                'header' => $headers,
                'rows' => $rows,
                'attributes' => array('class' => array('triage_table'))
            ));
    $out .= theme('ctools_collapsible',array(
        'handle' => '<h3>By Status:</h3>', 
        'content' => '<h6>Number of runs with Status entered: ' . $stat_num .'</h6>' .$table,
      )
    );

    // By Other Factors
    // Get factor taxonomy
    $fact_vid = ta_variable_get('triage_factors', '', $nid);
    if($fact_vid) {
      $rows = array();
      $headers = array(
        array('data' => t('Factor&nbsp;&nbsp;'), 'field' => 'status'),
        array('data' => t('Number&nbsp;of&nbsp;Triage&nbsp;Runs')),
        array('data' => t('% of Runs'))
      );
      $factor_query = clone $query;
      $factor_query->condition('l.factors', '', '>');
      $fact_num = $factor_query->countQuery()->execute()->fetchField();
      //dsm(dpq2($status_query, true));
      //dsm($vid);
      $factvals = db_query('select name from taxonomy_term_data where vid = :vid', array(':vid' => $fact_vid))->fetchCol();
      //dsm($statvals);
      foreach ($factvals as $fact) {
        $factray = explode(',', $fact);
        //dsm($statray);
        $temp_query = clone $factor_query;
        $temp_query->condition('l.factors', '%' . $fact . '%', 'LIKE');
        //dsm(dpq_triage($temp_query, true));
        $num = $temp_query->countQuery()->execute()->fetchField();
        $rows[] = array(
          $fact,
          $spacer . $num,
          $spacer . round($num * 100 / $fact_num, 2) . '%'
        );
      }

      $table = theme('table', array(
        'header' => $headers,
        'rows' => $rows,
        'attributes' => array('class' => array('triage_table'))
      ));
      $out .= theme('ctools_collapsible', array(
          'handle' => '<h3>By Factors:</h3>',
          'content' => '<h6>Number of runs with Factors entered: ' . $fact_num . '</h6>' . $table,
        )
      );
    }
    //By Steps
    $rows = array();
    $headers = array(
      array('data' => t('Steps&nbsp;&nbsp;'), 'field' => 'county'),
      array('data' => t('Number&nbsp;of&nbsp;Triage&nbsp;Runs'), 'field' => 'count'),
      array('data' => t('Complete&nbsp;Runs')),
      array('data' => t('Incomplete&nbsp;Runs')),
    );  
    $cnt_query = clone $query;
    $cnt_query->addExpression('COUNT(l.steps)', 'count');
    $cnt_query->orderBy('l.steps');
    $cnt_query->groupBy('l.steps');
    $cnt_query->extend('TableSort')->orderByHeader($headers);
    $results = $cnt_query->execute();
    foreach ($results as $result) {
//      if ($result->steps==""){continue;}
      $complete_query = clone $query;
      $complete_query->condition('l.completed',1);
      $complete_query->condition('l.steps',$result->steps);
      $complete = $complete_query->countQuery()->execute()->fetchField();
      $incomplete_query = clone $query;
      $or = db_or();
      $or->condition('l.completed',0);
      $or->condition('l.completed',null);
      $incomplete_query->condition($or);
      $incomplete_query->condition('l.steps',$result->steps);
      $incomplete = $incomplete_query->countQuery()->execute()->fetchField();
      if($result->steps =="0" || $result->steps == ""){
          $incomplete = $result->count;
          $complete = 0;
      }
      if($result->steps == ""){
        $incomplete = 0;          
      }
      $rows[] = array(
        $result->steps,
        $spacer.$result->count,
        $spacer.$complete,
        $spacer.$incomplete,
      );
    }
    $table = theme('table', array(
                'header' => $headers,
                'rows' => $rows,
                'attributes' => array('class' => array('triage_table'))
            ));
    $out .= theme('ctools_collapsible',array(
        'handle' => '<h3>By Steps:</h3>', 
        'content' => $table,
      )
    );
    // Referred to Intake, by Problem
    $legal_rows = array();
    $legal_headers = array(
      array('data' => t('Number&nbsp;of&nbsp;Intake&nbsp;Referrals'), 'field' => 'count', 'sort' => 'desc'),
      array('data' => t('Legal&nbsp;Problem&nbsp;&nbsp;&nbsp;'), 'field' => 'last_stop'),
      array('data' => t('Case Code'), 'field' => 'other_cat'),
    );  
    $legal_query = clone $query;
    $legal_query->addExpression('COUNT(l.last_stop)', 'count');
    $legal_query->condition('l.intake_elig',1);
    $legal_query->groupBy('l.last_stop');
    $legal_query->extend('TableSort')->orderByHeader($legal_headers);
    $legal_results = $legal_query->execute();
    foreach ($legal_results as $lresult) {
      $legal_rows[] = array(
        $lresult->count,
        $spacer.$lresult->last_stop,
        $spacer.$lresult->other_cat,
      );
    }
    $table1 = theme('table', array(
                'header' => $legal_headers,
                'rows' => $legal_rows,
                'attributes' => array('class' => array('triage_table'))));
    $out .= theme('ctools_collapsible',array(
        'handle' => '<h3>Referred to Intake, By Legal Problem:</h3>', 
        'content' => $table1,
      )
    );
    // 
    // By Legal Problem
    $legal_rows = array();
    $legal_headers = array(
      array('data' => t('Number&nbsp;of&nbsp;Triage&nbsp;Runs'), 'field' => 'count', 'sort' => 'desc'),
      array('data' => t('Legal&nbsp;Problem&nbsp;&nbsp;&nbsp;'), 'field' => 'last_stop'),
    );  
    $legal_query = clone $query;
    $legal_query->addExpression('COUNT(l.last_stop)', 'count');
    $legal_query->condition('l.completed',1);
    $legal_query->groupBy('l.last_stop');
    $legal_query->extend('TableSort')->orderByHeader($legal_headers);
    $legal_results = $legal_query->execute();
    foreach ($legal_results as $lresult) {
      $legal_rows[] = array(
        $lresult->count,
        $spacer.$lresult->last_stop,
      );
    }
    $table1 = theme('table', array(
                'header' => $legal_headers,
                'rows' => $legal_rows,
                'attributes' => array('class' => array('triage_table'))));
    $out .= theme('ctools_collapsible',array(
        'handle' => '<h3>By Legal Problem (completed runs only):</h3>', 
        'content' => $table1,
      )
    );
    // By Legal Category
    $vid = $thisvid;
    $cquery = db_select('taxonomy_term_data', 't');
        $cquery->addField('t', 'tid');
        $cquery->addField('t', 'name');
        $cquery->innerJoin('taxonomy_vocabulary', 'v', 'v.vid=t.vid');
        $cquery->innerJoin('taxonomy_term_hierarchy', 'h', 'h.tid=t.tid');
        $cquery->condition('h.parent', 0)
                ->condition('v.vid', $vid)
                ->orderBy('t.name');
    $results = $cquery->execute();
    $cat_rows = array();
    $cat_headers = array(
      array('data' => t('Legal&nbsp;Category&nbsp;&nbsp;&nbsp;'), 'field' => 'name'),
      array('data' => t('Number&nbsp;of&nbsp;Triage&nbsp;Runs'), 'field' => 'count'),
    );  

    foreach ($results as $result){
        $parent = $result->tid;
        $name = $result->name;
        $kids = triage_get_children_all($parent);
        $srch = array();
        foreach($kids as $kid){
            $srch[] = $kid->tid;
        }
        $cat_query = clone $query;
        $cat_query->addExpression('COUNT(*)', 'count');
        $cat_query->condition('l.completed',1);
//        $cat_query->condition('l.steps',$totalsteps);
        if (count($srch)>0){
        $cat_query->condition('l.tid',$srch,'IN');
        }
        $cat_results = $cat_query->execute()->fetchAssoc();
        $cat_rows[] = array(
            $name,
            $cat_results['count'],
        );        
    }
    $table3 = theme('table', array(
                'header' => $cat_headers,
                'rows' => $cat_rows,
                'attributes' => array('class' => array('triage_table'))));
    $out .= theme('ctools_collapsible',array(
        'handle' => '<h3>By Legal Category (completed runs only):</h3>', 
        'content' => $table3,
      )
    );
    
    //Income Breakdown
    if (variable_get('triage_use_income', false)){
    $atriagedata = array();
    $atotal = 0;
    $inc_headers = array(
      array('data' => t('Percent of Poverty')),
      array('data' => t('Incomplete&nbsp;&nbsp;&nbsp;')),
      array('data' => t('Complete&nbsp;&nbsp;&nbsp;')),
    );  
    $inc_rows = array();
    $cnt_query = clone $query;
    $or = db_or();
    $or->condition('l.completed',0);
    $or->condition('l.completed',null);
    $cnt_query->condition($or);
    $cnt_query->condition('l.pov',0,'<');
    $count1 = $cnt_query->countQuery()->execute()->fetchField();
    $cnt_query = clone $query;
    $cnt_query->condition('l.completed',1);
    $cnt_query->condition('l.pov',0,'<');
    $count2 = $cnt_query->countQuery()->execute()->fetchField();
    $inc_rows[] = array(
        'No Income Recorded',
        $spacer.$count1,
        $spacer.$count2,
    );   
    $cnt_query = clone $query;
    $or = db_or();
    $or->condition('l.completed',0);
    $or->condition('l.completed',null);
    $cnt_query->condition($or);
    $cnt_query->condition('l.pov',array(0,100),'BETWEEN');
    $count1 = $cnt_query->countQuery()->execute()->fetchField();
    $cnt_query = clone $query;
    $cnt_query->condition('l.completed',1);
    $cnt_query->condition('l.pov',array(0,100),'BETWEEN');
    $count2 = $cnt_query->countQuery()->execute()->fetchField();
    $inc_rows[] = array(
        'Under 100%',
        $spacer.$count1,
        $spacer.$count2,
    );
    $atotal = $atotal + $count2;
    $atriagedata[] = $count2;
    $cnt_query = clone $query;
    $or = db_or();
    $or->condition('l.completed',0);
    $or->condition('l.completed',null);
    $cnt_query->condition($or);
    $cnt_query->condition('l.pov',array(100,200),'BETWEEN');
    $count1 = $cnt_query->countQuery()->execute()->fetchField();
    $cnt_query = clone $query;
    $cnt_query->condition('l.completed',1);
    $cnt_query->condition('l.pov',array(100,200),'BETWEEN');
    $count2 = $cnt_query->countQuery()->execute()->fetchField();
    $inc_rows[] = array(
        '100% to 200%',
        $spacer.$count1,
        $spacer.$count2,
      );
    $atotal = $atotal + $count2;
    $atriagedata[] = $count2;
    $cnt_query = clone $query;
    $or = db_or();
    $or->condition('l.completed',0);
    $or->condition('l.completed',null);
    $cnt_query->condition($or);
    $cnt_query->condition('l.pov',array(200,300),'BETWEEN');
    $count1 = $cnt_query->countQuery()->execute()->fetchField();
    $cnt_query = clone $query;
    $cnt_query->condition('l.completed',1);
    $cnt_query->condition('l.pov',array(200,300),'BETWEEN');
    $count2 = $cnt_query->countQuery()->execute()->fetchField();
    $inc_rows[] = array(
        '200% to 300%',
        $spacer.$count1,
        $spacer.$count2,
    );
    $atotal = $atotal + $count2;
    $atriagedata[] = $count2;
    $cnt_query = clone $query;
    $or = db_or();
    $or->condition('l.completed',0);
    $or->condition('l.completed',null);
    $cnt_query->condition($or);
    $cnt_query->condition('l.pov',300,'>');
    $count1 = $cnt_query->countQuery()->execute()->fetchField();
    $cnt_query = clone $query;
    $cnt_query->condition('l.completed',1);
    $cnt_query->condition('l.pov',300,'>');
    $count2 = $cnt_query->countQuery()->execute()->fetchField();
    $inc_rows[] = array(
        'Over 300%',
        $spacer.$count1,
        $spacer.$count2,
    );
    $atotal = $atotal + $count2;
    $atriagedata[] = $count2;
    $table2 = theme('table', array(
                'header' => $inc_headers,
                'rows' => $inc_rows,
                'attributes' => array('class' => array('triage_table'))
            ));
    $out .= theme('ctools_collapsible',array(
        'handle' => '<h3>By Percent of Poverty Level: </h3>', 
        'content' => $table2,
      )
    );
    $atriagedata[0] = round(($atriagedata[0]/$atotal)*100,1);
    $atriagedata[1] = round(($atriagedata[1]/$atotal)*100,1);
    $atriagedata[2] = round(($atriagedata[2]/$atotal)*100,1);
    $atriagedata[3] = round(($atriagedata[3]/$atotal)*100,1);
    $out .= "</div>";  
    $chart = array(
    '#type' => 'chart',
    '#title' => t('Proportion of completed triage searches by income level'),
    '#chart_type' => 'pie',
    '#chart_library' => 'highcharts', // Allowed values: 'google' or 'highcharts'
    '#title_font_size' => 25,
    '#legend_position' => 'bottom',
    '#data_labels' => TRUE,
    '#tooltips' => TRUE,
    '#font_size' => 20,
  );
  $chart['pie_data'] = array(
    '#type' => 'chart_data',
    '#title' => t('Income Levels'),
    '#labels' => array('less than 100% POV', '100% - 200% POV','200% - 300% POV','more than 300% POV'),
    '#data' => $atriagedata,
  );

  $example['chart'] = $chart;

   $out .= "<div>" . drupal_render($example) . "</div>";
  }
  }
  // Simple Listing ---------------------------------------------------------------
  else {
    $headers = array(
      array('data' => t('Completed'), 'field' => 'completed'),
      array('data' => t('Date/Time'), 'field' => 'time'),
      array('data' => t('Zip Code'), 'field' => 'zipcode'),
      array('data' => t('County&nbsp;&nbsp;'), 'field' => 'county'),
      array('data' => t('%&nbsp;Poverty&nbsp;&nbsp;'), 'field' => 'pov'),
      array('data' => t('Steps&nbsp;&nbsp;'), 'field' => 'steps'),
      array('data' => t('Status&nbsp;&nbsp;'), 'field' => 'status'),
      array('data' => t('History&nbsp;&nbsp;'), 'field' => 'history'),
      array('data' => t('IP&nbsp;&nbsp;'), 'field' => 'ip'),
    );  
    $query = db_select('triage_log','l')->extend('PagerDefault');
    $query->fields('l', array(
        'completed','time','zipcode','county','pov','status','steps','history','ip'));
    $query->condition('l.time',array($dmystart,$dmyend),'BETWEEN');
    $query->condition('l.vid', $thisvid);
    $cnt_query = clone $query;
    $query->extend('TableSort')->orderByHeader($headers);
    $results = $query->limit(25)->execute();
    $count = $cnt_query->countQuery()->execute()->fetchField();
    $out .= "Records in set: " . $count . "<br /><hr />";
    $rows = array();
    foreach ($results as $result) {
      $spacer = '&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;';
      $rows[] = array(
        $result->completed,
        date ("Y-m-d H:i:s", $result->time),
        $spacer.$result->zipcode,
        $spacer.$result->county,
        $spacer.$result->pov,
        $spacer.$result->steps,
        $spacer.$result->status,
        $spacer.$result->history,
        $spacer.$result->ip,
      );
    }
    $out .= theme('table', array(
                'header' => $headers,
                'rows' => $rows,
                'attributes' => array('class' => array('triage_table'))
            ));
    $out .= "</div>"; 
    $out .= theme('pager', array('tags' => array()));
  }
  return $out;
}
function triage_summary_excel(){
    $dmystart = strtotime($_SESSION['triage']['triage_summary_report'][0]);
    $dmyend = strtotime($_SESSION['triage']['triage_summary_report'][1]);
    $filename = 'triage_data';
    $filename.= "_" . date("m-d-Y",time()) . ".csv";
    $sql = "select * from triage_log 
            where time between :start AND :end";    
    $results = db_query($sql, array(":start"=>$dmystart, ":end"=>$dmyend));
    $getkeys = db_query('select * from triage_log')->fetchAssoc();
    $keys = array_keys($getkeys);
    //dsm($keys);
    //$count = $results->rowCount();
    $out .= "Records in set: " . $count . "<br /><hr />";
    $out .= "Data exported to Excel File";
    $GLOBALS['devel_shutdown'] = TRUE;

     // Set the headers to indicate this is a CSV file.
     header('Content-type: text/csv; charset=UTF-8');
     header('Content-Disposition: attachment; filename=' . $filename);
     header('Pragma: no-cache');
     header('Expires: 0');

     // Create a file.
     $output = fopen('php://output', 'w');

     // Column names.
     fputcsv ($output, $keys);

     // Loop through the rows.
     foreach ($results as $row) {
       fputcsv($output, (array) $row);
     }

     fclose($output);    
}
function triage_suggestions(){  
  global $base_url;
  $spacer = '&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;';
  $form = drupal_get_form('triage_suggestionfilter_form');
  $out = drupal_render($form);
  $out .= "<h4>Additional User Problems</h4>";
  $out .= "<div class='suggestions-report'>";
  $dmystart = strtotime($_SESSION['triage']['triage_suggestions_report'][0]);
  $dmyend = strtotime($_SESSION['triage']['triage_suggestions_report'][1])+86399;
  $query = db_select('triage_suggestions','l');
  $query->fields('l', array('created','text','tid'));
  $query->condition('l.created',array($dmystart,$dmyend),'BETWEEN');
  $query->condition('l.text','',">");
  $query->orderBy('l.created','DESC');
//  $query->condition('l.ip',$noips,'NOT IN');
  $results = $query->execute();
  $rows = array();
  $headers = array(
    array('data' => t('Date&nbsp;&nbsp;')),
    array('data' => t('Endpoint&nbsp;&nbsp;')),
    array('data' => t('Problem or Suggestion')),
  );  
  foreach($results as $result){
      $term = taxonomy_term_load($result->tid);
      $rows[] = array(
        date("F j, Y", $result->created),
        $spacer.$term->name . " (" . $term->tid . ")",
        $spacer. "<a href='" . $base_url . "/search_all/".$result->text . "'>" . $result->text . "</a>",
      );
  }
  $table = theme('table', array(
                'header' => $headers,
                'rows' => $rows,
                'attributes' => array('class' => array('triage_table'))));
  $out .= theme('ctools_collapsible',array(
              'handle' => '<h3>Additional Problems or Suggestions</h3>', 
              'content' => $table,
           )
  );
  $out .= "</div>";
  return $out;
}