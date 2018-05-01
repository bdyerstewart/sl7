<?php 

    global $base_path;
    global $base_url;
    $keys = $_SESSION['vol_keys'][0];

    // Get array of cleaned up keywords
    $query = db_select('search_index', 'i', array('target' => 'slave'))->extend('search_allQuery');
    $query->SearchExpression($keys,'statesidesearch');
    $query->parseSearchExpression();
    $mywords = $query->words;
    $db_or = db_or();
    $jrquery = db_select('search_api_db_jobposts_search_api_aggregation_1','jr');
    $jrquery->addField('jr', 'item_id', 'nid');
    $jrquery->addField('jr', 'word');
    $jrquery->condition('word',$keys);
    // Get a reference to current conditions
    $conditions =& $jrquery->conditions();
    // Reset the condition array. It needs a default #conjunction for which AND is fine
    $conditions = array('#conjunction' => 'AND');
    $db_or->condition('word',$keys);
    foreach($mywords as $word){
        $wrd =  '%' . preg_replace('!\*+!', '%', $word) . '%';
        $db_or->condition('word', $wrd , 'LIKE');
    }
    $jrquery->condition($db_or);
    $jtquery = db_select('search_api_db_node_body_value','jt');
    $jtquery->addJoin("inner", "node", "n", "n.nid = jt.item_id");
    $jtquery->addField('jt', 'item_id', 'nid');
    $jtquery->addField('jt', 'word');
    $jtquery->condition('n.type','job_posting');
    $jtquery->condition($db_or);
    $jrquery->union($jtquery);
    $subquery = db_select($jrquery,'sub');
    $subquery->addField("sub",'nid');
    $subquery->condition($db_or);
    
    $cState = "";
    $markers = array();
    $options=array();
    $options['zoom']=4;
    $options['latitude'] = "38.00";
    $options['longitude'] = "-95.00";
    stateside_vol_info('volunteerpost',$options);
    $query = db_select('volunteerpost', 'sl');
    $query->fields("sl",array(
        "nid",
        "name",
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
        "startdate",
        "enddate",
        "email"
    ));
    if ($keys){
        $query->condition("sl.nid",$subquery,"IN");
    }
    $query->orderBy('title');
    $numlist = $query->countQuery()->execute()->fetchField();;
    $rsList = $query->execute();
    if ($numlist > 0) {
          $i = 0;
          foreach($rsList as $rs) {
                $sdate = $rs->startdate;
                $edate = $rs->enddate;
                if ($sdate==$edate){$edate = 0;}
                $now = time();
                //$days30 = 30*60*60*24;
                if ($sdate > 0 && $sdate > $now ){continue;}
                if ($edate > 0 && $edate < $now){continue;}
                $i++;
                $org_name = $rs->name;
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
                $popUp = "<div class='mapinfo'>";
                $popUp .= "<a href='node/" . $rs->nid . "'>" . $orgname ."</a><br />";
                if ($rs->url){
                    $popUp .= "<a href='http://" . $webPage . "'>" . $org_name . "</a><br />";
                }
                else {
                    $popUp .= $org_name . "<br />";
                }
                $popUp .= $addressDetails . $localDetails ;
                if ($localDetails){$popUp .= '<br />';}
                $popUp .= "</div>";
                $markers[$i] = array(
                    'latitude' => $rs->latitude,
                    'longtitude' => $rs->longitude,
                    'title' => $org_name,
                    'popup' => $popUp,
                    'marker' => null,
                );
          }
      }
  $settings = array();
  $settings['markers'] = $markers;
  drupal_add_js($settings, 'setting');
  if (!$options['zoom'] || intval($options['zoom']) < 1 ){$options['zoom'] = 4;}
    
?>

<html>
<head>
<script type="text/javascript" src="https://maps.googleapis.com/maps/api/js?sensor=false"></script>
<script type="text/javascript">
    var k = 0;
    var bluemarker = '<?php print drupal_get_path('theme','state7'); ?>/images/bluemapmarker.png';
    var redmarker = '<?php print drupal_get_path('theme','state7'); ?>/images/redmapmarker.png';
    var map;
    var infoWindow = new google.maps.InfoWindow;
    
function mapinit(){
        var geocoder = null;
        var address_list_display = "";
        var icon = bluemarker;
        var markers = Drupal.settings.markers;
        var myzoom = <?php print $options['zoom']; ?>;
        var myLatlng = new google.maps.LatLng(<?php print $options['latitude']; ?>,<?php print $options['longitude']; ?>);
        var mapOptions = {
            zoom: myzoom,
            center: myLatlng,
            mapTypeId: google.maps.MapTypeId.ROADMAP
        }
        map = new google.maps.Map(document.getElementById("volmap"), mapOptions);
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
/*  #map{
      width: 655px;
      height: 550px;
  }*/
  div.infowin {
    font-size: 70%;
  }  
</style>
</head>
  <body onload="mapinit()">
  <div id="volmap"> </div>
  <div id="map_canvas" style ="display:none;"><div>
  <div class="clear"> </div>

</body>
</html>