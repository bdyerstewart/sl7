<?php
    //dsm($page['sidebar_first']['quicktabs_sidebar_topics']['content']['container']['divs']);
    //dsm($page['sidebar_first']);
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
 *   comment/reply/12345). **
 * 
 */
    //dsm($maine_menu);
    $myaddr = $_GET;
    if(strpos("triage/va_triage", $myaddr ) === false){
        global $language;
        $language->language = "en";
    }
    drupal_add_css('http://fonts.googleapis.com/css?family=Droid+Sans:400,700|Oswald:400,700,300', array('group' => CSS_THEME, 'type' => 'external'));
    // Assemble menu from NSMI top categories
    $menu_out = statesidelegal_output_menu($main_menu); 
    // Process page to see what header info will get displayed
    $showtitle = true;
    $header_title = "";
    $header_sub_title = "";
    $header_image = "";
    //print_r($page);
    if (substr($myaddr['q'],0,4)=='node'){
        $is_node=true;
        if (substr($myaddr['q'],0,8)=='node/add'){
            $is_node = false;
            $node=array();
        }
    }
    else {
        $is_node = false;
        $node=array();
    }
    statesidelegal_subhead($page,$title, $node, $header_image, $header_title, $header_sub_title, $showtitle, $breadcrumb);
    global $user;
    $vol_coor = false;
    if (in_array('volunteer_coordinator', $user->roles)){$vol_coor=true;}
    $local_server = false;
    $whitelist = array(
      '127.0.0.1',
      '::1'
    );
    if(in_array($_SERVER['REMOTE_ADDR'], $whitelist)){
      $local_server = true;
    }

?>

<!--[if IE]>
    <style type="text/css">
        #headings{
            background-image: url('../images/ie-gradient2.png');
            background-repeat: repeat-y;
        }
    </style>
<![endif]-->

<div id="header-wrapper">
        <div id="header">
                <h1><a href="<?php print $base_path ?>" id="logo">Stateside Legal</a></h1>
                <?php if ($site_slogan): ?>
                    <h2 id="tagline"><?php print $site_slogan; ?></h2>
                <?php endif; ?>
                <div id="social">
                    <!-- AddThis Follow BEGIN -->
                    <?php if (! $local_server): ?>
                    <div class="addthis_toolbox addthis_32x32_style addthis_default_style">
                        <a href="http://statesidelegal.org/rss.xml">
                            <img width="32" height="32" title="Syndicate" alt="Syndicate content" src="http://statesidelegal.org/misc/feed.png"/>
                        </a>
                    <a class="addthis_button_facebook_follow" addthis:userid="StatesideLegal"></a>
                        <a class="addthis_button_twitter_follow" addthis:userid="statesidelegal"></a>
                    </div>
                    <script type="text/javascript" src="http://s7.addthis.com/js/300/addthis_widget.js#pubid=ra-4db0834c5c659d89"></script>
                    <?php endif; ?>
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
</div><!-- end header-wrapper -->
<div id="content-wrapper">
        <div id="content">
          <?php if($node->nid == 5929) : ?>

          <?php else: ?>
            <div id="featured-image" style ="background-image: <?php print $header_image; ?>;" >
                    <div id="headings">
                            <h2><?php print $header_title; ?></h2>
                            <h3><?php print $header_sub_title; ?></h3>
                    </div><!-- end headings -->
            </div><!-- end featured image -->
          <?php endif; ?>

            <?php print $messages; ?>

            <div id="main-content">
                <?php if ($page['highlighted']) : ?>
                    <div id="searchbar-wrapper">
                        <?php print render($page['highlighted']); ?>
                    </div><!-- end searchbar-wrapper -->
                <?php endif; ?>
                <?php if ($breadcrumb): ?>
                <div id="breadcrumb" ><?php print $breadcrumb; ?></div>
                <?php endif; ?>

                <?php print render($title_prefix); ?>
                <?php if ($title && $showtitle): ?>
                    <?php if($is_node): ?>
                        <?php switch($node->type) : 
                            case "jimsmailbag": ?>
                                <section class="blogpost">
                                    <header>
                                    <h3 class="title" id="page-title"><?php print $title; ?></h3>
                            <?php break; ?>
                            <?php default: ?>       
                                <h1 class="title" id="page-title"><?php print $title; ?></h1>
                        <?php endswitch ; ?>
                     <?php else: ?>
                            <h1 class="title" id="page-title"><?php print $title; ?></h1>
                     <?php endif; ?>
                <?php endif; ?>
                <?php print render($title_suffix); ?>
                <?php if($is_node): ?>
                    <?php switch($node->type) : 
                        case "jimsmailbag": ?>
                            </header>
                        <?php break; ?>
                        <?php default: ;?>
                    <?php endswitch ; ?>
                <?php endif; ?>
                <?php if ($tabs): ?><div class="tabs"><?php print render($tabs); ?></div><?php endif; ?>
                <?php print render($page['help']); ?>
                <?php if ($action_links): ?><ul class="action-links"><?php print render($action_links); ?></ul><?php endif; ?>
                <?php print render($page['content']); ?>
                <?php print $feed_icons; ?>
                <?php if($is_node): ?>
                    <?php switch($node->type) : 
                        case "jimsmailbag": ?>
                            </section>
                            <?php break; ?>
                        <?php default: ;?>
                    <?php endswitch ; ?>  
                <?php endif; ?>
            </div><!-- end main-content -->
                <div id="sidebar">
                    <?php if ($page['sidebar_first']): ?>
                        <div id="sidebar-first" class="column sidebar"><div class="section">
                            <?php print render($page['sidebar_first']); ?>
                        </div></div> <!-- /.section, /#sidebar-first -->
                    <?php endif; ?>
                </div><!-- end-sidebar -->
                <div class="clearfix">&nbsp;</div>
        </div><!-- end content -->
</div><!-- end content-wrapper -->
</div><!-- end header-wrapper -->
<div id="footer-wrapper">
    <div id="footer">
        <?php if ($page['footer']): ?>
            <?php print render($page['footer']); ?>
        <?php endif; ?>                    
    </div><!-- end footer -->
</div><!-- end footer-wrapper -->
<script type="text/javascript">
      resize_to_fit('div#headings', 'h2');
</script>