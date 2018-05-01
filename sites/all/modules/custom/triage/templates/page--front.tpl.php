<?php
//    dsm($page);
/**
 * @file
 * Default theme implementation to display a single Drupal page.
 *
 * The doctype, html, head and body tags are not in this template. Instead they
 * can be found in the html.tpl.php template in this directory.
 *
 * Available variables:
 *
 * General utility variables:
 * - $base_path: The base URL path of the Drupal installation. At the very
 *   least, this will always default to /.
 * - $directory: The directory the template is located in, e.g. modules/system
 *   or themes/bartik.
 * - $is_front: TRUE if the current page is the front page.
 * - $logged_in: TRUE if the user is registered and signed in.
 * - $is_admin: TRUE if the user has permission to access administration pages.
 *
 * Site identity:
 * - $front_page: The URL of the front page. Use this instead of $base_path,
 *   when linking to the front page. This includes the language domain or
 *   prefix.
 * - $logo: The path to the logo image, as defined in theme configuration.
 * - $site_name: The name of the site, empty when display has been disabled
 *   in theme settings.
 * - $site_slogan: The slogan of the site, empty when display has been disabled
 *   in theme settings.
 *
 * Navigation:
 * - $main_menu (array): An array containing the Main menu links for the
 *   site, if they have been configured.
 * - $secondary_menu (array): An array containing the Secondary menu links for
 *   the site, if they have been configured.
 * - $breadcrumb: The breadcrumb trail for the current page.
 *
 * Page content (in order of occurrence in the default page.tpl.php):
 * - $title_prefix (array): An array containing additional output populated by
 *   modules, intended to be displayed in front of the main title tag that
 *   appears in the template.
 * - $title: The page title, for use in the actual HTML content.
 * - $title_suffix (array): An array containing additional output populated by
 *   modules, intended to be displayed after the main title tag that appears in
 *   the template.
 * - $messages: HTML for status and error messages. Should be displayed
 *   prominently.
 * - $tabs (array): Tabs linking to any sub-pages beneath the current page
 *   (e.g., the view and edit tabs when displaying a node).
 * - $action_links (array): Actions local to the page, such as 'Add menu' on the
 *   menu administration interface.
 * - $feed_icons: A string of all feed icons for the current page.
 * - $node: The node object, if there is an automatically-loaded node
 *   associated with the page, and the node ID is the second argument
 *   in the page's path (e.g. node/12345 and node/12345/revisions, but not
 *   comment/reply/12345). * */
global $language;
$language->language = "en";

drupal_add_css('http://fonts.googleapis.com/css?family=Droid+Sans:400,700|Oswald:400,700,300', array('group' => CSS_THEME, 'type' => 'external'));
$menu_out = statesidelegal_output_menu($main_menu);
//$sql = "SELECT f.filename, n.title, n.nid, b.body_summary as body  
//            FROM file_managed f 
//            INNER JOIN field_data_node_image i ON i.node_image_fid = f.fid 
//            INNER JOIN node n on n.nid = i.entity_id
//            LEFT JOIN field_data_body b on b.entity_id = n.nid
//            LEFT JOIN field_data_field_weight w on w.entity_id = n.nid
//            INNER JOIN domain_access d on d.nid = n.nid
//            WHERE n.type='banners'
//            AND d.gid = 1
//            AND n.status =1
//            ORDER BY w.field_weight_value";
$sql = "SELECT f.filename, n.title, n.nid, b.body_summary as body  
            FROM file_managed f 
            INNER JOIN field_data_node_image i ON i.node_image_fid = f.fid 
            INNER JOIN node n on n.nid = i.entity_id
            LEFT JOIN field_data_body b on b.entity_id = n.nid
            LEFT JOIN field_data_field_weight w on w.entity_id = n.nid
            INNER JOIN domain_access d on d.nid = n.nid
            WHERE n.type='banners'
            AND d.gid = 1
            AND n.status =1
            ORDER BY w.field_weight_value";
$banners = db_query($sql)->fetchAll();
$div_id = 1;
$alter['html'] = TRUE;
$alter['max_length'] = 500;
global $base_url;
global $user;
$vol_coor = false;
if (in_array('volunteer_coordinator', $user->roles)){$vol_coor=true;}
$mtag = metatag_metatags_view('global:frontpage', array()); 
render($mtag);
?>
<div id="header-wrapper">
    <div id="header">
       <h1><a href="home" id="logo">Stateside Legal</a></h1>
        <?php if ($site_slogan): ?>
            <h2 id="tagline"><?php print $site_slogan; ?></h2>
        <?php endif; ?>
        <div id="social">
            <!-- AddThis Follow BEGIN -->
            <div class="addthis_toolbox addthis_32x32_style addthis_default_style">
                <a href="http://statesidelegal.org/rss.xml">
                    <img width="32" height="32" title="Subscribe to RSS" alt="Syndicate content" src="http://statesidelegal.org/misc/feed.png"/>
                </a>
               <a class="addthis_button_facebook_follow" addthis:userid="StatesideLegal"></a>
                <a class="addthis_button_twitter_follow" addthis:userid="statesidelegal"></a>
            </div>
            <script type="text/javascript" src="http://s7.addthis.com/js/300/addthis_widget.js#pubid=ra-4db0834c5c659d89"></script>
            <!-- AddThis Follow END -->        
        </div><!-- end social -->
        <ul id="top-nav">
            <?php if($logged_in) : ?>
                <li><a href="<?php print $base_path; ?>user/logout">logout</a></li>
                    <?php if($vol_coor) : ?>
                        <li> | </li>
                        <li><a href="<?php print $base_path; ?>volunteer-posts">my listings</a></li>
                    <?php endif; ?>
                <li> | </li>
                <li><a href="<?php print $base_path; ?>user/<?php print $user->uid; ?>">my account</a></li>
            <?php else : ?>
                <li><a href="<?php print $base_path; ?>user">login</a></li>
            <?php endif; ?>
            <?php if(user_has_role(11)) : ?>
                <li> | </li>
                <li><a href="<?php print $base_path . 'my-groups'; ?>">my groups</a></li>
            <?php endif; ?>
            <li> | </li>
            <li><a href="<?php print $base_path; ?>about-us">about us</a></li>
            <li> | </li>
            <li><a href="<?php print $base_path; ?>links">links</a></li>
            <li> | </li>
            <li><a  id="feedback" href="<?php print $base_path; ?>how-can-we-serve-you-better" >+ feedback</a></li>
        </ul><!-- end top-nav -->
    </div><!-- end header -->
    <div id="nav-wrapper">
        <a class="nav-toggle" href="#"><?php print "<i class='fa fa-bars'></i> " . t("Menu"); ?></a>
        <?php if ($main_menu) print $menu_out; ?>
    </div><!-- end nav-wrapper -->
    <?php if($banners){
        print "<div id='prev'></div><div id='next'></div>";
        print "<div id='bannerframe'>";} ?>
    <?php foreach($banners as $banner) :?>
        <?php $img = $base_path . "sites/default/files/" . $banner->filename ; ?>
        <div class="headwrap<?php print $div_id; $div_id ++; ?> headwrap" style="background-image:url(<?php print $img; ?>)"> 
            <div class="ss-caption" onclick="window.location.href = '<?php print "node/" . $banner->nid ;?>'">
                <?php 
                    $b_url = "node/" . $banner->nid;
                    print "<h2>".$banner->title."</h2>";
                    if ($banner->body){
                        $text = strip_tags(views_trim_text($alter, $banner->body));
                        print "<p>". $text . "<br /><a class='more' href='" . $b_url . "' >  More on " . $banner->title . " ...</a></p>";
                    }
                ?>
            </div>
        </div>
    <?php endforeach; ?>
    <?php if($banners){print "</div>";} ?>
        
    </div><!-- end header-wrapper -->
<?php //print $messages; ?>
<?php if ($page['highlighted']) : ?>
    <div id="searchbar-wrapper">
        <?php print render($page['highlighted']); ?>
    </div><!-- end searchbar-wrapper -->
<?php endif; ?>


<div id="content-wrapper">
    <div id="content">
        <div class="l-col">
            <?php if ($page['triptych_first']) : ?>
                <?php print render($page['triptych_first']); ?>
            <?php endif; ?>
        </div><!-- end l-col -->
        <div class="m-col" id="featured">
            <div class="post-header">
                <h3 class="title">Featured </h3>
            </div><!-- end post-header -->
            <?php if ($page['triptych_middle']) : ?>
                <?php print render($page['triptych_middle']); ?>
            <?php endif; ?>
        </div><!-- end m-col -->
        <div class="r-col">
            <div class="post-header">
                <h3 class="title">Advocate Networks</h3>
            </div><!-- end post-header -->
            <?php
                $block = module_invoke('block', 'block_view', '47');
                print render($block['content']);
            ?>
            <div class="post-header">
                <h3 class="title">News &amp; Media <a href="militarynews" class="more">View All</a></h3>
            </div><!-- end post-header -->
            <?php if ($page['triptych_last']) : ?>
                <?php print render($page['triptych_last']); ?>
            <?php endif; ?>
        </div><!-- end r-col -->
    </div><!-- end content -->
</div><!-- end content-wrapper -->
<div id="footer-wrapper">
    <div id="footer">
        <?php if ($page['footer']): ?>
            <?php print render($page['footer']); ?>
        <?php endif; ?>                    
    </div><!-- end footer -->
</div><!-- end footer-wrapper -->
<script type="text/javascript">
    jQuery("body.front .browse-topics.advocates a").removeClass("hover");
    jQuery("body.front .browse-topics.advocates ul").css('visibility', 'hidden');
    jQuery('#bannerframe').cycle({
        fx: 'fade',
        prev: '#prev', 
        next: '#next', 
        pause: true,
        before: slideAction
    });       
    function slideAction(){
        
    }
    window.setTimeout(function() {
        jQuery("body.front .browse-topics.library a").removeClass("hover");
        jQuery("body.front .browse-topics.library ul").css('visibility', 'hidden');
    }, 2500);
</script>