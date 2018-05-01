
var map;
var pos;
var vm_center;
var vm_lat;
var vm_lng;
var vm_zoom;
var marker;
var markers=[];
var image_num = 0;
var refreshmap = 0;
var interval = 10000;
var mess = '';
var infoWindow = null;
var vm_cycles = 25;

(function ($) {
  Drupal.behaviors.visitormap = {
    attach: function (context, settings) {
      var x = 0;
      if( document.getElementById('visitormap_canvas') ){
        vm_cycles = Drupal.settings.vm_vars.vm_cycles;
        interval = Drupal.settings.vm_vars.vm_interval;
        setInterval(function(){
          if (image_num < 8 && refreshmap < vm_cycles){
            visitormap_data(true);
          }
          else {
            image_num = 0;
            refreshmap = 0;
            visitormap_init();
          }
        }, interval);
      }
    }
  };
})(jQuery);

function visitormap_init(){
  //alert(Drupal.settings.vm_vars.vm_center);
  vm_center = Drupal.settings.vm_vars.vm_center;
  //alert(vm_center);
  vm_lat = vm_center.substr(0,vm_center.search(","));
  vm_lng = vm_center.substr(vm_center.search(",")+1);
  vm_zoom = parseInt(Drupal.settings.vm_vars.vm_zoom);
  var myLatlng = new google.maps.LatLng(vm_lat,vm_lng);
  var myOptions = {
      zoom: vm_zoom,
      center: myLatlng,
      mapTypeId: google.maps.MapTypeId.ROADMAP
  };

  map = new google.maps.Map(document.getElementById('visitormap_canvas'), myOptions);
  infoWindow = new google.maps.InfoWindow();
  visitormap_data(false);
}

function visitormap_data(onlynew){
  refreshmap++;
  var imgray = [
    "blue",
    "purple",
    "yellow",
    "green",
    "lblue",
    "pink",
    "black",
    "bpink"
  ];
  var url = window.location.protocol + "//" + window.location.host ;
  url += Drupal.settings.basePath + 'visitormap_data';
  var image = Drupal.settings.vm_vars.vm_image_path + '/red.png'
  if (onlynew){
    url += "/true";
    image = Drupal.settings.vm_vars.vm_image_path + '/' + imgray[image_num] + '.png'
  }
  var out = '';
  jQuery.getJSON( url, function( data ) {
    if (data){
        for (var j=0;j<markers.length;j++){
          if (markers[j].getAnimation() != null) {
            markers[j].setAnimation(null);          
          }
        }
        if (image == Drupal.settings.vm_vars.vm_image_path + '/red.png'){
          msg = '<img src="' + image + '" />' + " shows the most recent 50 visitors";
        }
        else {
          msg = '<img src="' + image + '" />' + " shows new visitors within the last " + (interval/1000) + " seconds";
        }
        jQuery('.vm-click-me').html(msg);
        image_num++;
        for ( var i=0; i<data.length; i++ ){
          pos = new google.maps.LatLng(data[i]['lat'],data[i]['lng']);
          marker = new google.maps.Marker({
            position: pos,
            map: map,
            title: data[i]['city'],
            icon: image
          })
          if (onlynew){
            marker.setAnimation(google.maps.Animation.BOUNCE);
          }
          //mess = pad(data[i]['ip'],30,'.','right')+ "<br />";
          mess = vm_pad(data[i]['city'],30,'.','right')+ "<br />";
          if (data[i]['region'] != '0'){
            mess += vm_pad(data[i]['region'],30,'.','right') + "<br />";
          }
          mess += vm_pad(data[i]['country'],30,'.','right') + "<br />";
          bindInfoWindow(marker, map, infoWindow, mess);  
          marker.setMap(map); 
          markers.push(marker);
        }
    }
  });
}

function bindInfoWindow(marker, map, infoWindow, html) {
    google.maps.event.addListener(marker, 'mouseover', function() {
        infoWindow.setContent(html);
        infoWindow.open(map, marker);
    });
    google.maps.event.addListener(marker, 'mouseout', function() {
        infoWindow.close();
    });

}
function vm_pad(str, len, pad, dir) {
    if (typeof(len) == "undefined") { len = 0; }
    if (typeof(pad) == "undefined") { pad = ' '; }
    if (typeof(dir) == "undefined") { dir = 'right'; }
    if (len + 1 >= str.length) {
        switch (dir){
            case 'left':
                str = Array(len + 1 - str.length).join(pad) + str;
            break;
            case 'both':
                var right = Math.ceil((padlen = len - str.length) / 2);
                var left = padlen - right;
                str = Array(left+1).join(pad) + str + Array(right+1).join(pad);
            break;
            default:
                str = str + Array(len + 1 - str.length).join(pad);
            break;
        } // switch
    }
    return str;
}

