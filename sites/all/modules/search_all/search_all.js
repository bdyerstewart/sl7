(function ($) {
  Drupal.behaviors.search_all = {
    attach: function (context, settings) {
        $("#search_allsearchresults h2").hover(
            function(){$(this).css("text-decoration","underline");},
            function(){$(this).css("text-decoration","none");}
        );
        $("#search_allsearchresults h2").first().removeClass("searchaccordian");
        $("#search_allsearchresults h2").first().addClass("searchaccordianselect");
        $("#search_allsearchresults h2.searchaccordianselect").next("div").show();
        $("#search_allsearchresults h2.searchaccordian").next("div").hide();
        $("#search_allsearchresults h2").click(function(){
                $("#search_allsearchresults h2").removeClass("searchaccordianselect");
                $("#search_allsearchresults h2").addClass("searchaccordian");
                $("#search_allsearchresults div").hide("slow");
                $("div.searchresults").show();
                $(this).removeClass("searchaccordian");
                $(this).addClass("searchaccordianselect");
                $(this).next("div").show("slow");
        });
        $("#edit-submitkeys").click(function(){
            $("<div/>", {class: "waiting",text: "Searching"}).appendTo("body");
        });
        $("#search-all-advocate #edit-submit").click(function(){
            $("#edit-submit").addClass("advocate-no-show");
            $("#edit-submit").removeClass("advocate-show")
            $("#edit-submit2").addClass("advocate-show");
            $("#edit-submit2").removeClass("advocate-no-show")
            $("<div/>", {class: "waiting",text: "Searching"}).appendTo("body");
            
        });
        $("#edit-submit2").click(function(){
            $("#edit-submit2").addClass("advocate-no-show");
            $("#edit-submit2").removeClass("advocate-show")
            $("#edit-submit").addClass("advocate-show");
            $("#edit-submit").removeClass("advocate-no-show")
            $("<div/>", {class: "waiting",text: "Searching"}).appendTo("body");
        });
        
    }
  };
})(jQuery);