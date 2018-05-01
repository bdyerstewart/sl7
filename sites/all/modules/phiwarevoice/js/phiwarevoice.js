function phiwarevoice_popup(url) {
        var thispage = document.URL;
        jQuery.post("statesideclicktrack.php", {page: thispage} );
	window.open(url, 'PhiwareVoice', 'toolbar=no,status=no,width=400,height=100,scrollbars=no,menubar=no');
}