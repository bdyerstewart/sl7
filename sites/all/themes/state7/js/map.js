function initialize() {
  var myLatlng = new google.maps.LatLng(43.6614, -70.2558);
  var mapOptions = {
    zoom: 15,
    center: myLatlng,
    mapTypeId: google.maps.MapTypeId.ROADMAP
  }
  var map = new google.maps.Map(document.getElementById("map"), mapOptions);

  var bluemarker = 'images/bluemapmarker.png';
  var redmarker = 'images/redmapmarker.png';

  var myLatLng1 = new google.maps.LatLng(43.6614, -70.2558);
  var marker1 = new google.maps.Marker({
      position: myLatLng1,
      map: map,
      icon: bluemarker
  });
  var myLatLng2 = new google.maps.LatLng(43.6543266, -70.2636779);
  var marker2 = new google.maps.Marker({
      position: myLatLng2,
      map: map,
      icon: redmarker
  });
}