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
drupal_add_css('http://fonts.googleapis.com/css?family=Droid+Sans:400,700|Oswald:400,700,300', array('group' => CSS_THEME, 'type' => 'external'));
drupal_add_js('../js/jquery.js' );
$menu_out = statesidelegal_output_menu($main_menu);
$sql = "SELECT f.filename  
            FROM file_managed f 
            INNER JOIN field_data_node_image i ON i.node_image_fid = f.fid 
            WHERE i.bundle = 'banners' 
            AND i.entity_id IN 
                (SELECT nid FROM node 
                    WHERE type = 'banners' AND status = 1)";
$banners = db_query($sql)->fetchAll();
$div_id = 1;

?>
<div id="header-wrapper">
    <div id="header">
       <h1><a href="home" id="logo">Stateside Legal</a></h1>
        <?php if ($site_slogan): ?>
            <h2 id="tagline"><?php print $site_slogan; ?></h2>
        <?php endif; ?>
        <ul id="social">
            <li><a id="facebook" href="#">Facebook</a></li>
            <li><a id="twitter" href="#">Twitter</a></li>
            <li><a id="flickr" href="#">Flickr</a></li>
            <li><a id="youtube" href="#">Youtube</a></li>
        </ul><!-- end social -->
        <ul id="top-nav">
            <li><a href="<?php print $base_path; ?>about-us">about us</a></li>
            <li> | </li>
            <li><a  id="feedback" href="<?php print $base_url; ?>how-can-we-serve-you-better" >+ feedback</a></li>
        </ul><!-- end top-nav -->
    </div><!-- end header -->
    <div id="nav-wrapper">
        <?php if ($main_menu) print $menu_out; ?>
    </div><!-- end nav-wrapper -->
    <?php if($banners){print "<div id='bannerframe'>";} ?>
    <!-- Slideshow -->
    <div id="slideshow">
        <div id="slides">
                <div class="slides_container">
                    <?php foreach($banners as $banner) :?>
                        <?php $img = $base_path . "sites/default/files/" . $banner->filename ; ?>
                        <div class="slide" style="background-image:url(<?php print $img; ?>)"> </div>
                    <?php endforeach; ?>
                </div>
        </div>
    </div>
    <?php if($banners){print "</div>";} ?>
        
    </div><!-- end header-wrapper -->
<?php print $messages; ?>
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
                <h3 class="title">Featured <a href="#" class="more">View All</a></h3>
            </div><!-- end post-header -->
            <?php if ($page['triptych_middle']) : ?>
                <?php print render($page['triptych_middle']); ?>
            <?php endif; ?>
        </div><!-- end m-col -->
        <div class="r-col">
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
        <div id="f-left">
            <div id="copyright">
                <p> &copy; <strong> Stateside Legal </strong> All rights reserved.</p>
                <p><a href="#"> Terms of Use </a> <a href="#"> Privacy Policy </a></p>
            </div><!-- end copyright -->
            <a href="<?php print $base_path; ?>how-can-we-serve-you-better" class="red-button"> + Feedback </a>
            <div id="footer-logos">
                <img src="./<?php print drupal_get_path('theme', 'state7'); ?>/images/joiningforces.gif" alt="" title="">
                <img src="./<?php print drupal_get_path('theme', 'state7'); ?>/images/lsc.gif" alt="" title="">
            </div><!-- end footer-logos -->
        </div><!-- end f-left -->
        <div id="f-right">
            <div class="list-col-1">
                <ul>
                    <li>
                        <a href="#">Browse Topics</a>
                        <ul>
                            <li class="list-col-1-1"><a href="#">Taxes</a></li>
                            <li class="list-col-1-1"><a href="#">Social Security</a></li>
                            <li class="list-col-1-1"><a href="#">Public Benefits</a></li>
                            <li class="list-col-1-1"><a href="#">Immigration</a></li>
                            <li class="list-col-1-1"><a href="#">Housing</a></li>
                            <li class="list-col-1-1"><a href="#">Health</a></li>
                            <li class="list-col-1-1"><a href="#">Family Law</a></li>
                            <li class="list-col-1-2"><a href="#">Estate Planning</a></li>
                            <li class="list-col-1-2"><a href="#">Employement</a></li>
                            <li class="list-col-1-2"><a href="#">Education</a></li>
                            <li class="list-col-1-2"><a href="#">Consumer</a></li>
                            <li class="list-col-1-2"><a href="#">Civil Rights</a></li>
                            <li class="list-col-1-2"><a href="#">Other</a></li>
                        </ul>
                    </li>
                </ul>
            </div><!-- end list-col-1 -->
            <div class="list-col-2">
                <ul>
                    <li><a href="#">Find Local Help</a></li>
                    <li>
                        <a href="#">Advocates</a>
                        <ul>
                            <li><a href="#">Advocate Tool Kit</a></li>
                            <li><a href="#">Training Tool Kit</a></li>
                        </ul>
                    </li>
                </ul>
            </div><!-- end list-col-2 -->
            <div class="list-col-3">
                <ul>
                    <li>
                        <a href="#">Form Letters</a>
                        <ul>
                            <li><a href="#">Active Service Members</a></li>
                            <li><a href="#">Estate Planning</a></li>
                        </ul>
                    </li>
                    <li>
                        <a href="#">Links</a>
                        <ul>
                            <li><a href="#">Proof of Military Service</a></li>
                            <li><a href="#">Legal/Advocacy Services</a></li>
                        </ul>
                    </li>
                </ul>
            </div><!-- end list-col-3 -->
            <div class="list-col-4">
                <ul>
                    <li>
                        <a href="#">Help Us</a>
                        <ul>
                            <li><a href="#">Donate</a></li>
                            <li><a href="#">New Volunteers</a></li>
                        </ul>
                    </li>
                </ul>
            </div><!-- end list-col-4 -->
        </div><!-- end f-right -->
    </div><!-- end footer -->
</div><!-- end footer-wrapper -->
<?php 
    drupal_add_js("jQuery(document).ready(function () {
             jQuery('#bannerframe').cycle({
		fx: 'fade' });
             })",
            'inline');
?>


