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
    // Process page to see what header info will get displayed
    $lat1 = "43.6614";
    $long1 = "-70.2558";
    $page['sidebar_first']=null;
    $tree = menu_tree_all_data('menu-women-full');
    $menu = menu_tree_output($tree);
    $menu_out2 = slwomen_output_menu($menu);
    
?>
<script type="text/javascript">
    jQuery("body").removeClass('one-sidebar');
    jQuery("body").removeClass('sidebar-first');
    jQuery("body").addClass('no-sidebars');
</script>
<div id="statesidepopup">  
        <a id="statesidepopupClose">x</a>  
        <h1>Info on Organization Types</h1>  
        <div id="contactArea">  
            <h6>Civil Legal Aid Offices</h6>
            <p>Free legal help for all people with <a href="http://www.statesidelegal.org/federal-poverty-level-guidelines">low incomes</a><br />
            Specialities: housing, family, consumer and public benefits. Referrals for help 
            with other kinds of legal problems.</p>
            <h6>State Veterans Affairs Offices</h6>
            <p>Free non-lawyer advocates for veterans. Specialties: VA disability and other 
            VA-related claims. May also provide referrals to local Veteran Service Organizations 
            for non-lawyer help with VA claims.</p>
            <h6>JAG and Military Legal Assistance Officers</h6>
            <p>Free legal help for active duty military, including activated Reserve and 
            National Guard. Not specific to branch of service. Specialties: deployment-related 
            issues.</p>
            <h6>State Bar Lawyer Referral Offices</h6>
            <p>Free information and referral to a local lawyer who handles your type of case. 
            <p>Lawyers will charge for their services. Specialities: Wide range of legal matters; 
            some specialize in VA issues.</p>
            <h6>Other</h6>
            <p>Includes law school clinics, locally-funded legal aid and pro bono projects.</p>
            
        </div>  
    </div>  
    <div id="backgroundPopup"></div>                  
<div id="page">

  <header class="header" id="header" role="banner">

    <?php if ($logo): ?>
      <a href="<?php print $front_page; ?>" title="<?php print t('Home'); ?>" rel="home" class="header__logo" id="logo"><img src="<?php print $logo; ?>" alt="<?php print t('Home'); ?>" class="header__logo-image" /></a>
    <?php endif; ?>

    <?php if ($site_name || $site_slogan): ?>
      <div class="header__name-and-slogan" id="name-and-slogan">
        <?php if ($site_name): ?>
          <h1 class="header__site-name" id="site-name">
            <a href="<?php print $front_page; ?>" title="<?php print t('Home'); ?>" class="header__site-link" rel="home"><span><?php print $site_name; ?></span></a>
          </h1>
        <?php endif; ?>

        <?php if ($site_slogan): ?>
          <div class="header__site-slogan" id="site-slogan"><?php print $site_slogan; ?></div>
        <?php endif; ?>
      </div>
    <?php endif; ?>
    <?php print render($page['header']); ?>

  </header>

  <div id="main">

          <div id="navigation">
            <?php if ($main_menu): ?>
              <nav id="main-menu" role="navigation" tabindex="-1">
                <?php
                // This code snippet is hard to modify. We recommend turning off the
                // "Main menu" on your sub-theme's settings form, deleting this PHP
                // code block, and, instead, using the "Menu block" module.
                // @see https://drupal.org/project/menu_block
                print theme('links__system_main_menu', array(
                  'links' => $main_menu,
                  'attributes' => array(
                    'class' => array('links', 'inline', 'clearfix'),
                  ),
                  'heading' => array(
                    'text' => t('Main menu'),
                    'level' => 'h2',
                    'class' => array('element-invisible'),
                  ),
                )); ?>
                <div id="nav-wrapper">
                    <div id ="nav-mobile">
                        
                        <?php print $menu_out2; ?>
                    </div>
                </div><!-- end nav-wrapper -->
              </nav>
            <?php endif; ?>
      <?php print render($page['navigation']); ?>

    </div>

    <div id="content" class="column" role="main">
      <?php print render($page['highlighted']); ?>
      <?php print $breadcrumb; ?>
      <a id="main-content"></a>
      <?php print $messages; ?>
      <?php print render($tabs); ?>
      <?php print render($page['help']); ?>
      <?php if ($action_links): ?>
        <ul class="action-links"><?php print render($action_links); ?></ul>
      <?php endif; ?>
      <?php print render($page['content']); ?>
      <?php print $feed_icons; ?>
    </div>


    <?php
      // Render the sidebars to see if there's anything in them.
      $sidebar_first  = render($page['sidebar_first']);
      $sidebar_second = render($page['sidebar_second']);
    ?>

    <?php if ($sidebar_first || $sidebar_second): ?>
      <aside class="sidebars">
        <?php print $sidebar_first; ?>
        <?php print $sidebar_second; ?>
      </aside>
    <?php endif; ?>

  </div>

  <?php print render($page['footer']); ?>

</div>

<?php print render($page['bottom']); ?>
<script type="text/javascript">
    jQuery( document ).ready(function() {
        if ( jQuery( window ).width() <= 768 ){
            jQuery('#rm-removed ul.rm-removed').css('display','none');
            jQuery('#nav-mobile').css('display','block');
            jQuery('#nav-mobile ul.rm-removed').css('display','block');
        }
        else{
            jQuery('#main-menu').css('display','block');
        }
    });

</script>