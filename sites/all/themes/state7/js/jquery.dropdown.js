jQuery(function(){

    jQuery("body.front .browse-topics.library a").addClass("hover");
    jQuery("body.front .browse-topics.library ul").css('visibility', 'visible');

    jQuery("input[placeholder]").each(function () {
            var $this = jQuery(this);
            if($this.val() == ""){
                $this
                .val($this.attr("placeholder"))
                .focus(function(){
                    if($this.val() == $this.attr("placeholder")) {
                        $this.val("");
                    }
                })
                .blur(function(){
                    if($this.val() == "") {
                        $this.val($this.attr("placeholder"));
                    }
                });
            }
    });
    
    jQuery("#nav li").hover(function(){
    
        jQuery('a:first', this).addClass("hover");
        jQuery('ul:first',this).css('visibility', 'visible');
    
    }, function(){
    
        jQuery('a:first', this).removeClass("hover");
        jQuery('ul:first',this).css('visibility', 'hidden');
    
    });

    jQuery("nav li ul li a").hover(function(){

         jQuery(this).append("<span class='gt'> &gt; </span> ");
    }, function(){

    });

});