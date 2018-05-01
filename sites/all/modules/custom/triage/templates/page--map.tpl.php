<?php
$latitude = "38.00"; 
$longitude = "-95.00";
print "Latitude: ". $latitude;

    $sql = "DROP TABLE IF EXISTS statesidesearchfororgs";
    db_query($sql);
    $more_national = false;
    if (!isset($_SESSION['my_state'])) {$_SESSION['my_state'] = array() ;}
    if (!isset($_SESSION['my_zip'])) {$_SESSION['my_zip'] = array() ;}
    if (!isset($_SESSION['my_org_type'])) {$_SESSION['my_org_type'] = array() ;}
    $cState = $_SESSION['my_state'][0];
    $cZip = $_SESSION['my_zip'][0];
    $cType = $_SESSION['my_org_type'][0];
    
    //watchdog('map',$cState.":".$cZip.":".$cType);
    $cLogic = " AND TRUE ";
    if($cType == "LRS"){$cLogic = " AND (tx.name='LRS1' OR tx.name='LRS2')";}
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
    if (!$cState){
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
                if (in_array(strtolower($rs->tag), array('lrs1','lrs2'))){
                    $flag = drupal_get_path('theme','state7'). "/images/redmapmarker.png";
                }
                else {
                    $flag = drupal_get_path('theme','state7'). "/images/bluemapmarker.png";
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
                if ($email > "") {$popUp .= 'Email: ' . $emailLink . '<br />';}
                $popUp .= $addressDetails . $localDetails ;
                if ($localDetails){$popUp .= '<br />';}
                $popUp.= $phone2;
                if (trim($phone2) > ""){$popUp .= '<br />';}
                $stateout .= "<header><img src='" . $flag . "' /><h4>".$displayname."</h4></header>";
                $stateout .= "<p>".$localDetails."</p>";
                $stateout .= "</section>";
          }
          $stateout .= "</section>";
          if (!$zoom || intval($zoom) < 1 ){$zoom = 4;}
    }
    else {
        $zoom = 4 ;
        $latitude = "38.00"; 
        $longitude = "-95.00";
    }
?>


<script type="text/javascript">
    var k = 0;
    var bluemarker = '<?php print drupal_get_path('theme','state7'); ?>/images/bluemapmarker.png';
    var redmarker = '<?php print drupal_get_path('theme','state7'); ?>/images/redmapmarker.png';
    var map;
    var infoWindow = new google.maps.InfoWindow;
    
function initialize(){
        var geocoder = null;
        var address_list_display = "";
        var gmarkers = [];
        var myzoom = <?php print $zoom; ?>;
        var myLatlng = new google.maps.LatLng(<?php print $latitude; ?>,<?php print $longitude; ?>);
        var mapOptions = {
            zoom: myzoom,
            center: myLatlng,
            mapTypeId: google.maps.MapTypeId.ROADMAP
        }
        map = new google.maps.Map(document.getElementById("map"), mapOptions);

    <?php
      $sql = "SELECT count(*)
                    FROM node n
                    LEFT JOIN field_data_field_latitude t on t.entity_id = n.nid
                    LEFT JOIN field_data_field_longitude g on g.entity_id = n.nid 
                    LEFT JOIN field_data_field_state a4 on a4.entity_id = n.nid
                    WHERE n.type = 'organization' 
                    AND ISNULL(g.field_longitude_value)  
                    AND ISNULL(t.field_latitude_value) 
                    AND (a4.field_state_value = 'national' 
                        OR a4.field_state_value = '". $cState . "')";
      $farnumrows = db_query($sql)->fetchField();
      if (!$farnumrows){$farnumrows = 0;}
      $sql = "SELECT n.nid,
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
                    AND ISNULL(g.field_longitude_value)  
                    AND ISNULL(t.field_latitude_value) 
                    AND (a4.field_state_value = 'national' 
                        OR a4.field_state_value = '". $cState . "')";
      $rsAll = db_query($sql);
      $farout = "<section class='national'> ";
      $farout .= "<div id='sidebar' class='post-header'><h5>Additional Help Resource</h5>";
      if ($farnumrows > 0) {
        if ($farnumrows > 8){$more_national = true;}
        $farout .= "<ul class = 'gtlist findhelp'>";
        $num = 0;
        foreach($rsAll as $rs) {
          $num++;
          if ($num > 8){break;}
          //$node = node_load($rs->nid);
          $farout .= "<li>";
          $webPage = str_replace("http://","",$rs->url);
          $phone = $rs->telephone;
          $phone2= $rs->telephone2;
          $farout .= "<strong><a href='http://".$webPage."'>".$rs->title."</a></strong><br />";
          if (trim($phone) > ""){
            $farout .= "&nbsp;&nbsp;Tel: " . $phone ;
          }
          if (trim($phone2) > ""){
            $farout .= "&nbsp;&nbsp;&nbsp;&nbsp;" .$phone2;
            }
          $farout .= "<br />";
        }
        $farout .= "</li>";
      }
      $farout .= "</ul></section>";
      //if search was done center map on search location
      $sql = "SELECT COUNT(*) FROM statesidesearchfororgs";
      $numrows = db_query($sql)->fetchField();
      $sql = "SELECT * FROM statesidesearchfororgs";
      $rsAll = db_query($sql);
      
      if ($numrows > 0) {
          //$stateout = "<section class = 'first-col'>";
          $half = intval($numrows/2);
          $i = 0;
          foreach($rsAll as $rs) {
                $i++;
                //if ($i>6){break;}
                if (in_array(strtolower($rs->tag), array('lrs1','lrs2'))){
                    $flag = drupal_get_path('theme','state7').'/images/redmapmarker.png';
                }
                else {
                    $flag = drupal_get_path('theme','state7').'/images/bluemapmarker.png';
                }
                
		$mapLat = $rs->latitude;
                $mapLng = $rs->longitude;
                if ($mapLat == ""){continue;}
                if ($mapLng == ""){continue;}
                if ($mapLat == 0){continue;}
                if ($mapLng == 0){continue;}
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
                if ($email > "") {$popUp .= 'Email: ' . $emailLink . '<br />';}
                $popUp .= $addressDetails . $localDetails ;
                if ($localDetails){$popUp .= '<br />';}
                $popUp.= $phone2;
                if (trim($phone2) > ""){$popUp .= '<br />';}
	?>
        var myLatLng = new google.maps.LatLng(<?php print $mapLat; ?>,<?php print $mapLng; ?>);
        var myTitle = '<?php print str_replace("'","",$orgname); ?>';
        mess = "<div class='infowin'><strong>" + myTitle + "</strong><hr><?php print $popUp; ?></div>";
        var bds = '<?php print $flag; ?>';
        initializePoint(myLatLng, bds);
        <?php }  } ?>
        jQuery("#load").html("");
        }

        function initializePoint(LatLng, icon) {
            
            var marker = new google.maps.Marker({
                    position: LatLng, 
                    map: map,
                    icon: icon,
                    title: 'Click to zoom in'
                });
            bindInfoWindow(marker, map, infoWindow, mess);
            //drawing the marker
            marker.setMap(map); 
        }

        function bindInfoWindow(marker, map, infoWindow, html) {
            google.maps.event.addListener(marker, 'mouseover', function() {
                infoWindow.setContent(html);
                infoWindow.open(map, marker);
            });
            google.maps.event.addListener(marker, 'mouseout', function() {
                infoWindow.close();
            });
            google.maps.event.addListener(marker, 'click', function() {
                if (map.getZoom()>10){
                    marker.setTitle('Click to zoom in');
                    map.setZoom(<?php print $zoom; ?>);
                }
                else {
                    map.setZoom(11);
                    marker.setTitle('Click to zoom out');
                }
                map.setCenter(marker.getPosition());
                infoWindow.close();
            });

        }
</script>
   <div id="map"> </div>
   <?php 
            $output = "<div class='orgdetails'><section>" . $farout . $stateout . "</section></div>";
            $build = array();
            $build['content'] = array('#markup' => $output);
            $build['pager'] = array('#theme' => 'pager');
            print render($build);

   ?>
    <div id="map_canvas" style ="display:none;"><div>
  <div class="clear"> </div>

<script type="text/javascript" src="https://maps.googleapis.com/maps/api/js?sensor=false"></script>
<script src="<?php print drupal_get_path('theme','state7'); ?>js/jquery.js" type="text/javascript"></script>
<script src="<?php print drupal_get_path('theme','state7'); ?>js/jquery.dropdown.js" type="text/javascript"></script>
<script>
jQuery(document).ready(function(){
   initialize();
 });
 </script>