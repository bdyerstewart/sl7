<?php
/**
 * @file
 * Returns the HTML for a single Drupal page.
 *
 * Complete documentation for this file is available online.
 * @see https://drupal.org/node/1728148
 */
//$menu_out = statesidelegal_output_menu($main_menu); 
$tree = menu_tree_all_data('menu-women-full');
$menu = menu_tree_output($tree);
$menu_out2 = slwomen_output_menu($menu);

global $base_path;
$sql = "SELECT f.filename, n.title, n.nid, b.body_summary as body  
            FROM file_managed f 
            INNER JOIN field_data_node_image i ON i.node_image_fid = f.fid 
            INNER JOIN node n on n.nid = i.entity_id
            LEFT JOIN field_data_body b on b.entity_id = n.nid
            LEFT JOIN field_data_field_weight w on w.entity_id = n.nid
            INNER JOIN domain_access d on d.nid = n.nid
            WHERE n.type='banners'
            AND d.gid = 2
            AND n.status =1
            ORDER BY w.field_weight_value";
$banners = db_query($sql)->fetchAll();
$div_id = 1;
?>

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

    <?php if ($secondary_menu): ?>
      <nav class="header__secondary-menu" id="secondary-menu" role="navigation">
        <?php print theme('links__system_secondary_menu', array(
          'links' => $secondary_menu,
          'attributes' => array(
            'class' => array('links', 'inline', 'clearfix'),
          ),
          'heading' => array(
            'text' => $secondary_menu_heading,
            'level' => 'h2',
            'class' => array('element-invisible'),
          ),
        )); ?>
      </nav>
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
      <?php print render($title_prefix); ?>
      <?php if (false && $title): ?>
        <h1 class="page__title title" id="page-title"><?php print $title; ?></h1>
      <?php endif; ?>
      <?php print render($title_suffix); ?>
      <?php print $messages; ?>
      <?php print render($tabs); ?>
      <?php print render($page['help']); ?>
      <?php if ($action_links): ?>
        <ul class="action-links"><?php print render($action_links); ?></ul>
      <?php endif; ?>
      <?php //print render($page['content']); ?>
    <?php if($banners){print "<div class='banner'>";} ?>
        <?php foreach($banners as $banner) :?>
        <?php $img = $base_path . "sites/default/files/" . $banner->filename ; ?>
        <div class="headwrap<?php print $div_id; $div_id ++; ?> headwrap" style="background-image:url(<?php print $img; ?>)"> 
            <div class="ss-caption" onclick="window.location.href = '<?php print "node/" . $banner->nid ;?>'">
                <?php 
                    $alter = array();
                    $alter['max_length']=300;
                    $alter['word_boundary']=1;
                    $alter['ellipsis']=1;
                    $alter['html'] = 0;
                    $b_url = "node/" . $banner->nid;
                    print "<h2>".$banner->title."</h2>";
                    if ($banner->body){
                        $text = strip_tags(views_trim_text($alter, $banner->body));
                        print $text . "<br /><a class='more' href='" . $b_url . "' >  More on " . $banner->title . " ...</a>";
                    }
                ?>
            </div>
        </div>
    <?php endforeach; ?>
    <?php if($banners){print "</div>";} ?>
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
    jQuery('.banner')
      .after('<div id="banner-pager">')
      .cycle({
        fx: 'fade',
        pause: true,
        pager: '#banner-pager',
        before: slideAction
    });       
    function slideAction() {
        jQuery('#banner-pager a').removeClass('activeSlide');
    }
    jQuery( document ).ready(function() {
        if ( jQuery( window ).width() < 768 ){
            jQuery('#rm-removed ul.rm-removed').css('display','none');
            jQuery('#nav-mobile').css('display','block');
            jQuery('#nav-mobile ul.rm-removed').css('display','block');
        }
        else{
            jQuery('#main-menu').css('display','block');
            jQuery('.banner').css('display','block');
        }
        jQuery('#banner-pager a').wrap('<li class="bp">');
        jQuery('#banner-pager a').html("<i class='fa fa-circle-o'></i><i class='fa fa-circle'></i>");
        jQuery('#banner-pager').wrap('<div class="bp-wrap">');
    });
</script>