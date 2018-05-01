<?php
    
    global $base_url;
    $breadcrumb = '';
    $breadcrumb .= "<a href='" . $base_url . "/my-groups'>Home</a>";
    if (isset($node)){
        if ($node->type == "group_content"){
            $grp = $node->og_group_ref['und'][0]['target_id'];
            $grpnm = db_query('select title from node where nid = :nid',array(':nid'=>$grp))->fetchColumn();
            $breadcrumb .= "<a href='" . $base_url . "/node/" . $grp . "'> > " . $grpnm . "</a>";
        }
    }
    $breadcrumb = "<div class='breadcrumb'>" . $breadcrumb . "</div>";
?>
  <?php print render($page['header']); ?>

  <div id="wrapper">
    <div id="container" class="clearfix">

      <div id="header">
        <div id="logo-floater">
        <?php if ($logo || $site_title): ?>
          <?php if ($title): ?>
            <div id="branding"><strong><a href="<?php print $front_page ?>">
            <?php if ($logo): ?>
              <img src="<?php print $logo ?>" alt="<?php print $site_name_and_slogan ?>" title="<?php print $site_name_and_slogan ?>" id="logo" />
            <?php endif; ?>
            <?php print $site_html ?>
            </a></strong></div>
          <?php else: /* Use h1 when the content title is empty */ ?>
            <h1 id="branding"><a href="<?php print $front_page ?>">
            <?php if ($logo): ?>
              <img src="<?php print $logo ?>" alt="<?php print $site_name_and_slogan ?>" title="<?php print $site_name_and_slogan ?>" id="logo" />
            <?php endif; ?>
            <?php print $site_html ?>
            </a></h1>
        <?php endif; ?>
        <?php endif; ?>
        </div>

        <?php if ($primary_nav): print $primary_nav; endif; ?>
        <?php if ($secondary_nav): print $secondary_nav; endif; ?>
      </div> <!-- /#header -->

      <?php if ($page['sidebar_first']): ?>
        <div id="sidebar-first" class="sidebar">
          <?php print render($page['sidebar_first']); ?>
        </div>
      <?php endif; ?>

      <div id="center">
          <div id="squeeze">
          <ul id="top-nav">
            <?php if($logged_in) : ?>
                <li><a href="<?php print $base_path; ?>user/logout">Logout</a></li>
                <li> | </li>
                <li><a href="<?php print $base_path; ?>user/<?php print $user->uid; ?>">My Account</a></li>
            <?php else : ?>
                <li><a href="<?php print $base_path; ?>user">Login</a></li>
            <?php endif; ?>
            <li> | </li>
            <li><a href="<?php print $base_path; ?>">Return to Statesidelegal Home</a></li>
            <li> | </li>
            <li><a  id="feedback" href="<?php print $base_path; ?>how-can-we-serve-you-better" >Feedback</a></li>
        </ul><!-- end top-nav -->
              
              <div class="right-corner"><div class="left-corner">
          <?php print $breadcrumb; ?>
          <?php if ($page['highlighted']): ?><div id="highlighted"><?php print render($page['highlighted']); ?></div><?php endif; ?>
          <a id="main-content"></a>
          <?php if ($tabs): ?><div id="tabs-wrapper" class="clearfix"><?php endif; ?>
          <?php print render($title_prefix); ?>
          <?php if ($title): ?>
            <h1<?php print $tabs ? ' class="with-tabs"' : '' ?>><?php print $title ?></h1>
          <?php endif; ?>
          <?php print render($title_suffix); ?>
          <?php if ($tabs): ?><?php print render($tabs); ?></div><?php endif; ?>
          <?php print render($tabs2); ?>
          <?php print $messages; ?>
          <?php print render($page['help']); ?>
          <?php if ($action_links): ?><ul class="action-links"><?php print render($action_links); ?></ul><?php endif; ?>
          <div class="clearfix">
            <?php print render($page['content']); ?>
          </div>
          <?php print $feed_icons ?>
          <?php print render($page['footer']); ?>
      </div></div></div></div> <!-- /.left-corner, /.right-corner, /#squeeze, /#center -->

      <?php if ($page['sidebar_second']): ?>
        <div id="sidebar-second" class="sidebar">
          <?php print render($page['sidebar_second']); ?>
        </div>
      <?php endif; ?>

    </div> <!-- /#container -->
  </div> <!-- /#wrapper -->
