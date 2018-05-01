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
 *   comment/reply/12345). **/
    drupal_add_css('http://fonts.googleapis.com/css?family=Droid+Sans:400,700|Oswald:400,700,300', array('group' => CSS_THEME, 'type' => 'external'));
    // Assemble menu from NSMI top categories
    $menu_out = statesidelegal_output_menu($main_menu); 
    // Process page to see what header info will get displayed
    $showtitle = true;
    $header_title = "";
    $header_sub_title = "";
    $header_image = "";
    $myaddr = $_GET;
    //print_r($page);
    if (substr($myaddr['q'],0,4)=='node'){$is_node=true;}
    else {
        $is_node = false;
        $node=array();
    }
    statesidelegal_subhead($page,$title, $node, $header_image, $header_title, $header_sub_title, $showtitle);
   //print_r($node);
?>

<div id="header-wrapper">
        <div id="header">
                <h1><a href="<?php print $base_path ?>" id="logo">Stateside Legal</a></h1>
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
                        <?php if($logged_in) : ?>
                        <li><a href="<?php print $base_path; ?>user/logout">logout</a></li>
                        <li> | </li>
                        <li><a href="<?php print $base_path; ?>user/<?php print $user->uid; ?>">my account</a></li>
                        <?php else : ?>
                        <li><a href="<?php print $base_path; ?>user">login</a></li>
                        <?php endif; ?>
                        <li> | </li>
                        <li><a href="<?php print $base_path; ?>about-us">about us</a></li>
                        <li> | </li>
                        <li><a  id="feedback" href="<?php print $base_path; ?>how-can-we-serve-you-better" >+ feedback</a></li>
                </ul><!-- end top-nav -->
        </div><!-- end header -->
        <div id="nav-wrapper">
            <?php if ($main_menu) print $menu_out; ?>
        </div><!-- end nav-wrapper -->
</div><!-- end header-wrapper -->
<div id="content-wrapper">
        <div id="content">
            <div id="featured-image" style ="background-image: <?php print $header_image; ?>;" >
                    <div id="headings">
                            <h2><?php print $header_title; ?></h2>
                            <h3><?php print $header_sub_title; ?></h3>
                    </div><!-- end headings -->
            </div><!-- end featured image -->


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
                <section>
                        <header>
                                <h3> Topic Library </h3>
                        </header>
                <section>
                <div class="first-col">
                    <section class="topic">
                            <header>
                                    <img src="images/icon1.gif" alt="">
                                    <h4> Taxes (12) </h4>
                            </header>
                            <ul class="gtlist">
                                    <li>Tax Credits</li>
                                    <li>Special rules for service members</li>
                            </ul>
                    </section><!-- end topic -->
                    <section class="topic">
                            <header>
                                    <img src="images/icon2.gif" alt="">
                                    <h4> Social Securiyt(32) </h4>
                            </header>
                            <ul class="gtlist">
                                    <li>Disability</li>
                                    <li>SSi</li>
                                    <li>Retirement</li>	
                            </ul>
                    </section><!-- end topic -->
                    <section class="topic">
                            <header>
                                    <img src="images/icon3.gif" alt="">
                                    <h4> Public Benefits (16) </h4>
                            </header>
                            <ul class="gtlist">
                                    <li>Food Supplements</li>
                                    <li>Fuel Aid</li>
                                    <li>Unemployment Comp</li>
                            </ul>
                    </section><!-- end topic -->
                    <section class="topic">
                            <header>
                                    <img src="images/icon4.gif" alt="">
                                    <h4> Immigration (23) </h4>
                            </header>
                            <ul class="gtlist">
                                    <li>Permenent status and citizenship for service-members and family</li>
                            </ul>
                    </section><!-- end topic -->
                    <section class="topic">
                            <header>
                                    <img src="images/icon5.gif" alt="">
                                    <h4> Housing (9) </h4>
                            </header>
                            <ul class="gtlist">
                                    <li>Foreclosure</li>
                                    <li>Eviction</li>
                                    <li>Leases</li>
                                    <li>Home mortgages</li>
                            </ul>
                    </section><!-- end topic -->
                    <section class="topic">
                            <header>
                                    <img src="images/icon6.gif" alt="">
                                    <h4> Health (17)</h4>
                            </header>
                            <ul class="gtlist">
                                    <li>Medicaid</li>
                                    <li>TRICARE</li>
                                    <li>CHAMPVA</li>
                                    <li>Children's coverage</li>
                            </ul>
                    </section><!-- end topic -->
                    <section class="topic">
                            <header>
                                    <img src="images/icon7.gif" alt="">
                                    <h4> Family Law (13) </h4>
                            </header>
                            <ul class="gtlist">
                                    <li>Divorce</li>
                                    <li>Domestic violence</li>
                                    <li>Child support</li>
                                    <li>SCRA delay of court action</li>
                            </ul>
                    </section><!-- end topic -->

                </div><!-- end first-col -->
                <div class="second-col">
                    <section class="topic">
                            <header>
                                    <img src="images/icon8.gif" alt="">
                                    <h4> Estate Planning (5) </h4>
                            </header>
                            <ul class="gtlist">
                                    <li>Wills</li>
                                    <li>Power of Attorney</li>
                                    <li>Living Wills and other Advance Directives</li>
                            </ul>
                    </section><!-- end topic -->
                    <section class="topic">
                            <header>
                                    <img src="images/icon9.gif" alt="">
                                    <h4> Employment (14) </h4>
                            </header>
                            <ul class="gtlist">
                                    <li>Re-employment after service</li>
                                    <li>Unemployment comp</li>
                            </ul>
                    </section><!-- end topic -->
                    <section class="topic">
                            <header>
                                    <img src="images/icon10.gif" alt="">
                                    <h4> Education </h4>
                            </header>
                            <ul class="gtlist">
                                    <li>GI Bill</li>
                                    <li>Montgomery Bill</li>
                                    <li>Interstate Compact for children</li>
                            </ul>
                    </section><!-- end topic -->
                    <section class="topic">
                            <header>
                                    <img src="images/icon11.gif" alt="">
                                    <h4> Consumer (19) </h4>
                            </header>
                            <ul class="gtlist">
                                    <li>Debt Collection</li>
                                    <li>Interest rate reduction</li>
                                    <li>Fraud</li>
                            </ul>
                    </section><!-- end topic -->
                    <section class="topic">
                            <header>
                                    <img src="images/icon12.gif" alt="">
                                    <h4> Civil Rights (25) </h4>
                            </header>
                            <ul class="gtlist">
                                    <li>Discrimination</li>
                                    <li>Disability Rights</li>
                                    <li>Voting Rights</li>
                            </ul>
                    </section><!-- end topic -->
                    <section class="topic">
                            <header>
                                    <img src="images/icon7.gif" alt="">
                                    <h4> Other (31) </h4>
                            </header>
                            <ul class="gtlist">
                                    <li>Criminal Law</li>
                                    <li>Voting Rights</li>
                            </ul>
                    </section><!-- end topic -->

                </div><!-- end second-col -->
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

