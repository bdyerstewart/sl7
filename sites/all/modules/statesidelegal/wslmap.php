<?php

if (!defined('DRUPAL_ROOT')){
    if ($_SERVER['SERVER_NAME']=="localhost"){
        define('DRUPAL_ROOT', '/Users/bds/Sites/State7');
    }
    else {
        chdir('/home/state7/www');
        define('DRUPAL_ROOT', getcwd());
    }
//}
require_once DRUPAL_ROOT . '/includes/bootstrap.inc';
drupal_bootstrap(DRUPAL_BOOTSTRAP_FULL);

global $base_path;
global $base_url;
$latitude = "38.00"; 
$longitude = "-95.00";


    $sql = "DROP TABLE IF EXISTS statesidesearchfororgs";
    db_query($sql);
    $more_national = false;
    if (!isset($_SESSION['my_state'])) {$_SESSION['my_state'] = array("") ;}
    if (!isset($_SESSION['my_zip'])) {$_SESSION['my_zip'] = array("") ;}
    if (!isset($_SESSION['my_org_type'])) {$_SESSION['my_org_type'] = array("") ;}
    $cState = $_SESSION['my_state'][0];
    //$cState = "Maine";
    $cZip = $_SESSION['my_zip'][0];
    $cType = $_SESSION['my_org_type'][0];
    
    //watchdog('map',$cState.":".$cZip.":".$cType);
    $cLogic = " AND TRUE ";
    if($cType == "LRS"){$cLogic = " AND tx.name='LRS' ";}
    else {
        if ($cType > ""){
            $cLogic = " AND tx.name = '" . $cType . "'";
        }
    }
    if ($cZip > ""){
        $data = get_location_infos($cZip);
        $zoom = 10;
        $cState = $data['state'];
        $_SESSION['my_state'][0]=$cState;
        $latitude = $data['latitude'];
        $longitude = $data['longitude'];
    }
    else {
        if ($cState == "" || $cState == "All"){
            $zoom = 4;
            $latitude = "38.00"; 
            $longitude = "-95.00";
        }
        else {
            $data = get_location_infos($cState, true);
            $zoom = $data['zoom'];
            $latitude = $data['latitude'];
            $longitude = $data['longitude'];
        }
    }
    if ($cState==""){
         if (isset($_SESSION['smart_ip']['location']['region'])){
             $cState = $_SESSION['smart_ip']['location']['region'];
             $data = get_location_infos($cState, true);
             $zoom = $data['zoom'];
             $latitude = $data['latitude'];
             $longitude = $data['longitude'];
         }
    }
    $cState = str_replace("_","",$cState);
    $cState = str_replace("-","",$cState);
    if (!$cState || $cState==" "){$cState = "All";}
    $markers = array();
    $options=array();
    $options['zoom']=4;
    $options['latitude'] = "38.00";
    $options['longitude'] = "-95.00";    
    if ($cState=="All") {
        $sql = "CREATE Temporary Table statesidesearchfororgs
                    SELECT n.nid,
                        n.title,
                        tx.name as tag,
                        t.field_latitude_value as latitude, 
                        g.field_longitude_value as longitude,
                        a1.field_address1_value as address1,
                        a2.field_address2_value as address2,
                        a3.field_city_value as city,
                        a4.field_state_value as state,
                        a5.field_zip_value as zip,
                        a6.field_telephone_value as telephone,
                        a7.field_telephone2_value as telephone2,
                        a8.field_email_value as email,
                        a9.field_url_value as url
                    FROM node n
                    LEFT JOIN field_data_field_address1 a1 on a1.entity_id = n.nid
                    LEFT JOIN field_data_field_address2 a2 on a2.entity_id = n.nid
                    LEFT JOIN field_data_field_city a3 on a3.entity_id = n.nid
                    LEFT JOIN field_data_field_state a4 on a4.entity_id = n.nid
                    LEFT JOIN field_data_field_zip a5 on a5.entity_id = n.nid
                    LEFT JOIN field_data_field_telephone a6 on a6.entity_id = n.nid
                    LEFT JOIN field_data_field_telephone2 a7 on a7.entity_id = n.nid
                    LEFT JOIN field_data_field_email a8 on a8.entity_id = n.nid
                    LEFT JOIN field_data_field_url a9 on a9.entity_id = n.nid
                    LEFT JOIN field_data_field_latitude t on t.entity_id = n.nid
                    LEFT JOIN field_data_field_longitude g on g.entity_id = n.nid 
                    LEFT JOIN field_data_field_state s on s.entity_id = n.nid
                    LEFT JOIN field_data_taxonomy_vocabulary_15 vc on vc.entity_id = n.nid
                    LEFT JOIN taxonomy_term_data tx on tx.tid = vc.taxonomy_vocabulary_15_tid
                    WHERE n.type = 'organization'
                    AND NOT ISNULL(g.field_longitude_value) 
                    AND NOT ISNULL(t.field_latitude_value) " . $cLogic . "
                    ORDER BY a4.field_state_value, n.title ";
        $latitude = "38.00"; 
        $longitude = "-95.00";
    }
    else {
        $gState = $cState;
        if ($gState=="Washington"){
            $gState = "Washington+State";
        }
        $sql = "CREATE Temporary Table statesidesearchfororgs
                    SELECT n.nid,
                        n.title,
                        tx.name as tag,
                        t.field_latitude_value as latitude, 
                        g.field_longitude_value as longitude,
                        a1.field_address1_value as address1,
                        a2.field_address2_value as address2,
                        a3.field_city_value as city,
                        a4.field_state_value as state,
                        a5.field_zip_value as zip,
                        a6.field_telephone_value as telephone,
                        a7.field_telephone2_value as telephone2,
                        a8.field_email_value as email,
                        a9.field_url_value as url
                    FROM node n
                    LEFT JOIN field_data_field_address1 a1 on a1.entity_id = n.nid
                    LEFT JOIN field_data_field_address2 a2 on a2.entity_id = n.nid
                    LEFT JOIN field_data_field_city a3 on a3.entity_id = n.nid
                    LEFT JOIN field_data_field_state a4 on a4.entity_id = n.nid
                    LEFT JOIN field_data_field_zip a5 on a5.entity_id = n.nid
                    LEFT JOIN field_data_field_telephone a6 on a6.entity_id = n.nid
                    LEFT JOIN field_data_field_telephone2 a7 on a7.entity_id = n.nid
                    LEFT JOIN field_data_field_email a8 on a8.entity_id = n.nid
                    LEFT JOIN field_data_field_url a9 on a9.entity_id = n.nid
                    LEFT JOIN field_data_field_latitude t on t.entity_id = n.nid
                    LEFT JOIN field_data_field_longitude g on g.entity_id = n.nid 
                    LEFT JOIN field_data_field_state s on s.entity_id = n.nid
                    LEFT JOIN field_data_taxonomy_vocabulary_15 vc on vc.entity_id = n.nid
                    LEFT JOIN taxonomy_term_data tx on tx.tid = vc.taxonomy_vocabulary_15_tid
                    WHERE n.type = 'organization' 
                    AND NOT ISNULL(g.field_longitude_value)  
                    AND NOT ISNULL(t.field_latitude_value)" . $cLogic . "
                    AND s.field_state_value ='" . $cState . "'";
    }
    
    db_query($sql);
    $query = db_select('statesidesearchfororgs', 'sl')->extend('PagerDefault')->extend('TableSort');
    $query->fields("sl",array(
        "nid",
        "latitude",
        "longitude",
        "title",
        "address1",
        "address2",
        "telephone",
        "telephone2",
        "city",
        "state",
        "zip",
        "url",
        "tag",
        "email"
    ));
    $query->orderBy('title');
    $numlist = $query->countQuery()->execute()->fetchField();;
    $query->limit(12);
    if($numlist > 12){$numlist = 12;}
    $rsList = $query->execute();
    if ($numlist > 0) {
          $stateout = "<section class = 'first-col'>";
          $half = intval($numlist/2);
          $i = 0;
          foreach($rsList as $rs) {
                $i++;
                if ($i == $half + 1){
                    $stateout .= "</section>";
                    $stateout .= "<section class = 'second-col'>";
                }
                $stateout .= "<section class = 'map-result'>";
                if (strtolower($rs->tag)=='lrs'){
                    $flag = drupal_get_path('theme','state7'). "/images/redmapmarker.png";
//                    $flag = "redmapmarker.png";
                }
                else {
                    $flag = drupal_get_path('theme','state7'). "/images/bluemapmarker.png";
//                    $flag = "bluemapmarker.png";
                }
		$mapLat = $rs->latitude;
                $mapLng = $rs->longitude;
                $orgname = $rs->title;
                $displayname = $orgname;
                $address1 = $rs->address1;
                $address2 = $rs->address2;
                $city = $rs->city;
                $state = $rs->state;
                $postalCode = $rs->zip;
                $phone = $rs->telephone;
                $phone2= $rs->telephone2;
                $email = $rs->email;
                $emailLink = "<a href='mailto:".$email."'>".$email."</a>";
                $webPage = str_replace("http://","",$rs->url);
                $webPageLink = "<a href='http://".$webPage." ' target='_blank''>".$webPage."</a>";
                if ($rs->url){$displayname = "<a href='http://".$webPage." ' target='_blank''>".$orgname."</a>";}
                $fullName = $orgname;
                $addressDetails = "";
                if(trim($address1) > ""){$addressDetails .=  $address1.'<br />';}
                if(trim($address2) > ""){$addressDetails .=  $address2.'<br />';}
                $localDetails = $city;
                if(trim($city) > ""){ $localDetails .= ', ';}
                $localDetails .= $state.' '.$postalCode;
                $listdetails = $localDetails;
                if (trim($phone) > ""){$localDetails .= '<br />';}
                $localDetails .= $phone;
                //$popUp = $fullName.'<br />';
                $popUp = "";
                //if ($email > "") {$popUp .= 'Email: ' . $emailLink . '<br />';}
                $popUp .= $addressDetails . $localDetails ;
                if ($localDetails){$popUp .= '<br />';}
                $popUp.= $phone2;
                if (trim($phone2) > ""){$popUp .= '<br />';}
                $markers[$i] = array(
                    'latitude' => $rs->latitude,
                    'longtitude' => $rs->longitude,
                    'title' => $orgname,
                    'popup' => $popUp,
                    'marker' => null,
                );

                $stateout .= "<header><img src='" . $flag . "' /><h4>".$displayname."</h4></header>";
                $stateout .= "<p>".$localDetails."</p>";
                $stateout .= "</section>";
          }
          $settings = array();
          $settings['markers'] = $markers;
          drupal_add_js($settings, 'setting');
          if (!$options['zoom'] || intval($options['zoom']) < 1 ){$options['zoom'] = 4;}
          
          $stateout .= "</section>";
//          if (!$zoom || intval($zoom) < 1 ){$zoom = 4;}
    }
?>

<html>
<head>
<script type="text/javascript" src="https://maps.googleapis.com/maps/api/js?sensor=false"></script>
<script type="text/javascript">
    var k = 0;
    var bluemarker = '<?php print $base_url . "/" . drupal_get_path('theme','state7'); ?>/images/bluemapmarker.png';
    var redmarker = '<?php print $base_url . "/" . drupal_get_path('theme','state7'); ?>/images/redmapmarker.png';
    var map;
    var infoWindow = new google.maps.InfoWindow({maxWidth:350});
    
    function mapinit(){
        var geocoder = null;
        var address_list_display = "";
        var icon = bluemarker;
        var markers = <?php print $markers; ?>;
        var myzoom = <?php print $options['zoom']; ?>;
        var myLatlng = new google.maps.LatLng(<?php print $options['latitude']; ?>,<?php print $options['longitude']; ?>);
        var mapOptions = {
            zoom: myzoom,
            center: myLatlng,
            mapTypeId: google.maps.MapTypeId.ROADMAP
        }
        map = new google.maps.Map(document.getElementById("map"), mapOptions);
        jQuery.each(markers, function(index, value) {
            var latlng = new google.maps.LatLng(value.latitude, value.longtitude);
            var mess = value.popup
            var marker = new google.maps.Marker({
                position : latlng,
                map : map,
                icon: icon,
                title : value.title
                });
            Drupal.settings.markers[index].marker = marker;
            bindInfoWindow(marker, map, infoWindow, mess);
            marker.setMap(map); 
        });
     }

    function bindInfoWindow(marker, map, infoWindow, html) {
            google.maps.event.addListener(marker, 'click', function() {
                infoWindow.setContent(html);
                infoWindow.open(map, marker);
            });
    }   
</script>
<style>
  .orgLeft {
    float:left;
    margin: 0 10px 0 10px;
  }

  .orgRight {
    float:left;
  }
  #map{
      width: 100%;
      height: 100%;
  }
  div.infowin {
    font-size: 70%;
  }  
</style>
</head>
  <body onload="mapinit()">
  <?php print $state_out; ?>;
  <div id="map"> </div>
  <div id="map_canvas" style ="display:none;" ><div>
  <div class="clear"> </div>
