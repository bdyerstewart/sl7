jQuery(function(){
    jQuery("#sl_searchresults h2").hover(
        function(){jQuery(this).css("text-decoration","underline");},
        function(){jQuery(this).css("text-decoration","none");}
    );
    jQuery("#sl_searchresults h2").first().removeClass("searchaccordian");
    jQuery("#sl_searchresults h2").first().addClass("searchaccordianselect")
    jQuery("#sl_searchresults h2.searchaccordianselect").next("div").show();
//    jQuery("#sl_searchresults h2.searchaccordian").next("div").hide();
    jQuery("#sl_searchresults h2").click(function(){
            jQuery("#sl_searchresults h2").removeClass("searchaccordianselect");
            jQuery("#sl_searchresults h2").addClass("searchaccordian");
            jQuery("#sl_searchresults div").hide("slow")
            jQuery("div.searchresults").show();
            jQuery(this).removeClass("searchaccordian");
            jQuery(this).addClass("searchaccordianselect");
            jQuery(this).next("div").show("slow");
    });
});