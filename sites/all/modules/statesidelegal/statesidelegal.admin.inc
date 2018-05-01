<?php

require_once DRUPAL_ROOT . '/' . drupal_get_path('module', 'statesidelegal') . '/statesidelegal.forms.inc';

function statesidelegal_term_parent(){
    $info = $_GET;
    $pagevar = explode("/",$info['q']);
    $parent = "none";
    $is_nsmi = 0;
    if ($pagevar[0] == "taxonomy" && $pagevar[1] == "term"){
        $tid = $pagevar[2];
        $tax_ray = taxonomy_get_parents_all($tid);
        $x=-1;
        foreach($tax_ray as $ray){
            $x++;
            //print $x . ". " . $ray->name . "<br />";
        }
        switch ($x) {
            case -1 :
                break;
            case 0 :
                $parent = "self";
                break;
            default :
                $parent = $ray->name;
                break;
        }
        $sql = "SELECT tid from taxonomy_term_data where vid = 13 and tid = :tid";
        if (db_query($sql,array(':tid' => $tid ))->fetchField()){
                $is_nsmi = 1;
            }
//        print "TID: " . $tid . "<br />";
//        print "Is NSMI: " . $is_nsmi . "<br />";
//        print "Parent Term: " . $parent;
    }
//    else {print "Page: " . $title;}

return $parent;    
}
function statesidelegal_nsmi_parent($tid, $give_name=false){
    $parent = '';
    $ret_tid=0;
    $tax_ray = taxonomy_get_parents_all($tid);
    $x=-1;
    foreach($tax_ray as $ray){
        $x++;
    }
    switch ($x) {
        case -1 :
            break;
        case 0 :
            $parent = $ray->name;
            $ret_tid=$ray->tid;
            break;
        default :
            $parent = $ray->name;
            $ret_tid=$ray->tid;
            break;
    }
if ($give_name){return $parent;}
return $ret_tid;
}
function statesidelegal_term_list ($tid){
    $output = "";
    if (!$tid){return $output;}
    $is_advocate = $_SESSION['is_advocate'][0];
    if ($is_advocate){
        $ctypes = array('banners','military','resource','page','advocateresource','advocatelink');
    }
    else {
        $ctypes = array('banners','military','resource','page');
    }
    $this_nsmi = taxonomy_term_load($tid);
    $tbl = 'field_data_taxonomy_vocabulary_13';
    $fld = 'taxonomy_vocabulary_13_tid';
    if ($this_nsmi->vid==24){
        $tbl = 'field_data_field_wws';
        $fld = 'field_wws_tid';
    }
    global $base_path;
    $path = $base_path . "library/";
    $parent = taxonomy_term_load($tid);
    $sql = "SELECT COUNT(*) FROM " . $tbl . " t
            JOIN node n on n.nid = t.entity_id
            WHERE n.type in (:types)
            AND n.status = 1
            AND " . $fld . " = :tid";
    $cnt = db_query($sql, array(':types'=>$ctypes,':tid' => $parent->tid ) )->fetchField();
    if ($cnt>0){
        $output = '<div id="nsmi_cats_block" class="block block-block" ><nav><h4><a href="' . $path . $parent->tid .'">' . $parent->name . "</a>";
    }  
    if ($children = taxonomy_get_children($tid)) {
       if ($output==''){
        $output = '<div id="nsmi_cats_block" class="block block-block" ><nav><h4><a href="' . $path . $parent->tid .'">' . $parent->name . "</a>";
       }
       $output .= "</h4><ul id='side-nav'>";
        foreach ($children as $child) {
            $gc_exist = false;
            $cnt = 0;
            if ($grandchildren = taxonomy_get_children($child->tid)) {
                foreach ($grandchildren as $gcchild) {
                    $gc_cnt = 0;
                    $sql = "SELECT COUNT(*) FROM " . $tbl . " t
                            JOIN node n on n.nid = t.entity_id
                            WHERE n.type in (:types)
                            AND n.status = 1
                            AND " . $fld . " = :tid";
                    $gc_cnt = db_query($sql, array(':types'=>$ctypes,':tid' => $gcchild->tid ) )->fetchField();
                    if ($gc_cnt>0){
                        $gc_exist = true;
                    }
                }
            }
            $sql = "SELECT COUNT(*) FROM " . $tbl . " t
                    JOIN node n on n.nid = t.entity_id
                    WHERE n.type in (:types)
                    AND n.status = 1
                    AND " . $fld . " = :tid";
            $cnt = db_query($sql, array(':types'=>$ctypes,':tid' => $child->tid ) )->fetchField();
            if ($cnt>0 || $gc_exist){
                if ($cnt>0){
                    $output .= '<li><a href="' . $path . $child->tid.'">' . $child->name . " [ " . $cnt . " ]</a></li>" ;
                }
                else {
                    $output .= '<li><a href="#">' . $child->name . "</a></li>" ;                    
                }
                if ($grandchildren = taxonomy_get_children($child->tid)) {
                    foreach ($grandchildren as $gcchild) {
                        $gc_cnt = 0;
                        $sql = "SELECT COUNT(*) FROM " . $tbl . " t
                                JOIN node n on n.nid = t.entity_id
                                WHERE n.type in (:types)
                                AND n.status = 1
                                AND " . $fld . " = :tid";
                        $gc_cnt = db_query($sql, array(':types'=>$ctypes,':tid' => $gcchild->tid ) )->fetchField();
                        if ($gc_cnt>0){
                           $output .= '<li class="lib_grandchildren"><a href="' . $path . $gcchild->tid.'">' . $gcchild->name . " [ " . $gc_cnt . " ]</a></li>" ;
                        }
                    }
                }

            }
        }
        $output .= "</ul></nav></div>";
    }
    return $output;
}
function statesidelegal_update_geo() {
    $sql = "SELECT distinct nid FROM node n
            LEFT JOIN field_data_field_zip z on z.entity_id = n.nid
            LEFT JOIN field_data_field_latitude lat on lat.entity_id = n.nid
            LEFT JOIN field_data_field_longitude lng on lng.entity_id = n.nid
            WHERE n.type = 'organization'
            AND NOT ISNULL(z.field_zip_value) 
            AND z.field_zip_value > ''
            AND (
            ISNULL(lat.field_latitude_value) 
            OR lat.field_latitude_value=0 
            OR ISNULL(lng.field_longitude_value) 
            OR lng.field_longitude_value=0
            )" ;
    $rsAll = db_query($sql);
    foreach ($rsAll as $rs) {
        $node= node_load($rs->nid);
        $zip = '';
        $address='';
        $city='';
        $state='';
        if ($node->field_zip){ $zip = $node->field_zip['und'][0]['value'];}
        if ($node->field_address1){$address = trim($node->field_address1['und'][0]['value']);}
        if ($node->field_city){$city = trim($node->field_city['und'][0]['value']);}
        if ($node->field_state){$state = trim($node->field_state['und'][0]['value']);}
        $zip = substr($zip,0,5);
        $q = 'address=';
        if ($address != ''){ $q .= ',+' . str_replace(" ", "+",$address);}
        if ($city != ''){ $q .= ',+' . str_replace(" ", "+",$city);}
        if ($state != ''){ $q .= ',+' . str_replace(" ", "+",$state);}
        if ($zip != ''){ $q .= ',+' . str_replace(" ", "+",$zip);}
        $q .= ',+us&sensor=true';
        $url = 'http://maps.googleapis.com/maps/api/geocode/json?' . $q ;
        print_r($url);
        $http_reply = drupal_http_request($url);
        print_r($http_reply);
        $location_data = json_decode($http_reply->data);
        print_r($location_data);
        if ($location_data->status != "OK") {
            $infos['status'] = t('Google Map Interface error, please try later');
            continue;
        }
        else {
            $infos['latitude'] = $location_data->results[0]->geometry->location->lat;
            $infos['longitude'] = $location_data->results[0]->geometry->location->lng;
        }
        $latitude = $infos['latitude'];
        $longitude = $infos['longitude'];

        print_r($infos);
        if ($latitude) {
            $node->field_latitude['und'][0]['value'] = $latitude;
            $node->field_longitude['und'][0]['value'] = $longitude;
            node_save($node);
        }
    }

}
function statesidelegal_neworgs($allfiles=false){
    if ($allfiles){
//        $sql = "select nid from node n 
//                inner join field_data_taxonomy_vocabulary_15 t on t.entity_id = n.nid 
//                left join field_data_field_exclude x on x.entity_id = n.nid
//                where t.taxonomy_vocabulary_15_tid = 2749
//                and (
//                   isnull(x.field_exclude_value)
//                   OR x.field_exclude_value=0)"  ;        
//        $delnids = db_query($sql);
//        $nids=array();
//        foreach ($delnids as $thisnid){
//            $nids[] = $thisnid->nid;
//        }
        // Delete all the nodes at once
        //node_delete_multiple($nids);
    }
    else {
        $states = array();
        $ids = array();
        $abbrs = array();
        $ids[] = intval(date("d"));
        $ids[] = intval(date("d")) + 16;

        $sql = "SELECT abbr,name FROM state WHERE state_id in (" . implode(",", $ids) . ")";
        $statelist = db_query($sql);
        foreach( $statelist as $stateitem){
            $states[] = "'" . $stateitem->name ."'";
            $abbrs[] = $stateitem->abbr;
        }

    }
    if ($allfiles){
        $url = "http://lsc.gov/lsc_orgs_rss.xml";
        $terms = simplexml_load_file($url);
        $x = 1;
        foreach($terms as $term) {
            $x++;
            $org_id = $term->Org_ID;
            $off_id = $term->Office_ID;
            //print "Processing: " . $term->Office . "<br />";
            $state = $term->State;
            $sql = "SELECT Name FROM state WHERE Abbr ='" . $state . "'";
            $thisstate = db_query($sql)->fetchField();
            $sql = "SELECT o.entity_id 
                        from field_data_field_org_id o 
                        left join field_data_field_off_id f on f.entity_id = o.entity_id
                        where field_org_id_value = " . $org_id . 
                        " and field_off_id_value = " . $off_id ;
            $nid = db_query($sql)->fetchColumn();
            if (! $nid){
                $node = new stdClass();
                $node->type = 'organization';
                node_object_prepare($node);
            }
            else {
                $node = node_load($nid);
                if ($node->field_exclude_value[$node->language][0]['value']){continue;}
            }
            $node->title    = $term->Parent_Office . " - " . $term->Office;
            $node->language = LANGUAGE_NONE;
            $node->status = 1;
            $node->field_address1[$node->language][0]['value']   = $term->Address_1;
            $node->field_address2[$node->language][0]['value']   = $term->Address_2;
            $node->field_city[$node->language][0]['value']   = $term->City;
            $node->field_state[$node->language][0]['value']   = $thisstate;
            $node->field_zip[$node->language][0]['value']   = $term->Zip_Code;
            $node->field_telephone[$node->language][0]['value']   = $term->Phone;
            $node->field_email[$node->language][0]['value']   = $term->Email;
            $node->field_url[$node->language][0]['value']   = $term->URL;
            $node->taxonomy_vocabulary_15[$node->language][0] = array('tid'=>'2749');
            $node->field_org_id[$node->language][0]['value']  = $org_id;
            $node->field_off_id[$node->language][0]['value']  = $off_id;
            $q = 'us';
            if ($term->Address_1 != ''){ $q .= '+' . $term->Address_1;}
            if ($term->City != ''){ $q .= '+' . $term->City;}
            if ($term->State != ''){ $q .= '+' . $term->State;}
            if ($term->Zip_Code != ''){ $q .= '+' . $term->Zip_Code;}

            $query = array('q' => $q );
            $url = url('http://maps.google.com/maps/geo', array(
                            'query' => $query,
                            'external' => TRUE,
                    ));

            $http_reply = drupal_http_request($url);
            $location_data = json_decode($http_reply->data);
            $latitude = 0;
            $longitude = 0;

            if ($location_data->Status->code != 200) {
                $infos['status'] = t('Google Map Interface error, please try later');
                continue;
            }
            else {
                $infos['latitude'] = $location_data->Placemark[0]->Point->coordinates[1];
                $infos['longitude'] = $location_data->Placemark[0]->Point->coordinates[0];
                $latitude = $infos['latitude'];
                $longitude = $infos['longitude'];
            }
            $node->field_latitude[$node->language][0]['value'] = $latitude;
            $node->field_longitude[$node->language][0]['value'] = $longitude;
            node_save($node); 
        }
    }
    else {
        foreach($abbrs as $abbr){
            $url = "http://lsc.gov/lsc_orgs_rss.xml/" . $abbr;

            $terms = simplexml_load_file($url);
            $x = 1;
            foreach($terms as $term) {
                $x++;
                //print "Processing: " . $term->Office . "<br />";
                $org_id = $term->Org_ID;
                $off_id = $term->Office_ID;
                $state = $term->State;
                $sql = "SELECT Name FROM state WHERE Abbr ='" . $state . "'";
                $thisstate = db_query($sql)->fetchField();
                $sql = "SELECT o.entity_id 
                            from field_data_field_org_id o 
                            left join field_data_field_off_id f on f.entity_id = o.entity_id
                            where field_org_id_value = " . $org_id . 
                            " and field_off_id_value = " . $off_id ;
                $nid = db_query($sql)->fetchColumn();
                if (! $nid){
                    $node = new stdClass();
                    $node->type = 'organization';
                    node_object_prepare($node);
                }
                else {
                    $node = node_load($nid);
                    if ($node->field_exclude_value[$node->language][0]['value']){continue;}
                }
                $node->title    = $term->Parent_Office . " - " . $term->Office;
                $node->language = LANGUAGE_NONE;
                $node->status = 1;
                $node->field_address1[$node->language][0]['value']   = $term->Address_1;
                $node->field_address2[$node->language][0]['value']   = $term->Address_2;
                $node->field_city[$node->language][0]['value']   = $term->City;
                $node->field_state[$node->language][0]['value']   = $thisstate;
                $node->field_zip[$node->language][0]['value']   = $term->Zip_Code;
                $node->field_telephone[$node->language][0]['value']   = $term->Phone;
                $node->field_email[$node->language][0]['value']   = $term->Email;
                $node->field_url[$node->language][0]['value']   = $term->URL;
                $node->taxonomy_vocabulary_15[$node->language][0] = array('tid'=>'2749');
                $node->field_org_id[$node->language][0]['value']  = $org_id;
                $node->field_off_id[$node->language][0]['value']  = $off_id;
                $q = 'us';
                if ($term->Address_1 != ''){ $q .= '+' . $term->Address_1;}
                if ($term->City != ''){ $q .= '+' . $term->City;}
                if ($term->State != ''){ $q .= '+' . $term->State;}
                if ($term->Zip_Code != ''){ $q .= '+' . $term->Zip_Code;}

                $query = array('q' => $q );
                $url = url('http://maps.google.com/maps/geo', array(
                                'query' => $query,
                                'external' => TRUE,
                        ));

                $http_reply = drupal_http_request($url);
                $location_data = json_decode($http_reply->data);
                $latitude = 0;
                $longitude = 0;

                if ($location_data->Status->code != 200) {
                    $infos['status'] = t('Google Map Interface error, please try later');
                    continue;
                }
                else {
                    $infos['latitude'] = $location_data->Placemark[0]->Point->coordinates[1];
                    $infos['longitude'] = $location_data->Placemark[0]->Point->coordinates[0];
                    $latitude = $infos['latitude'];
                    $longitude = $infos['longitude'];
                }
                $node->field_latitude[$node->language][0]['value'] = $latitude;
                $node->field_longitude[$node->language][0]['value'] = $longitude;
                node_save($node); 
            }
        }
    }
}
function statesidelegal_adv_blog($account) {
  $acct = user_load($account->uid); 
  $nm = $acct->profile_fullname;
  if($nm==null){
      $nm = format_username($account);
  }
      
  drupal_set_title($title = t("@name's blog", array('@name' => $nm )), PASS_THROUGH);

  $build = array();

  $query = db_select('node', 'n')->extend('PagerDefault');
  $nids = $query
    ->fields('n', array('nid', 'sticky', 'created'))
    ->condition('type', 'blog')
    ->condition('uid', $account->uid)
    ->condition('status', 1)
    ->orderBy('sticky', 'DESC')
    ->orderBy('created', 'DESC')
    ->limit(variable_get('default_nodes_main', 10))
    ->addTag('node_access')
    ->execute()
    ->fetchCol();

  if (!empty($nids)) {
    $nodes = node_load_multiple($nids);
    $build += node_view_multiple($nodes);
    $build['pager'] = array(
      '#theme' => 'pager',
      '#weight' => 5,
    );
  }
  else {
    if ($account->uid == $user->uid) {
      drupal_set_message(t('You have not created any blog entries.'));
    }
    else {
      drupal_set_message(t('!author has not created any blog entries.', array('!author' => theme('username', array('account' => $account)))));
    }
  }
  drupal_add_feed('blog/' . $account->uid . '/feed', t('RSS - !title', array('!title' => $title)));

  return $build;
}
