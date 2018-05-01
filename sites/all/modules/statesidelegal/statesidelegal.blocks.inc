<?php

require_once DRUPAL_ROOT . '/' . drupal_get_path('module', 'statesidelegal') . '/statesidelegal.forms.inc';
require_once DRUPAL_ROOT . '/' . drupal_get_path('module', 'statesidelegal') . '/statesidelegal.admin.inc';

function statesidelegal_block_info() {
  $blocks['statesidelegal_sidebar_terms'] = array(
    'info' => t('Stateside NSMI Cats Box'), //The name that will appear in the block list.
    'cache' => DRUPAL_NO_CACHE, 
  );
  $blocks['statesidelegal_subscriptions'] = array(
    'info' => t('Stateside Subscription block'), //The name that will appear in the block list.
    'cache' => DRUPAL_NO_CACHE, 
  );
  $blocks['statesidelegal_blogger'] = array(
    'info' => t('Stateside Blogger Info'), //The name that will appear in the block list.
    'cache' => DRUPAL_NO_CACHE, 
  );
  $blocks['statesidelegal_bloggerlist'] = array(
    'info' => t('Stateside Blog Author Info'), //The name that will appear in the block list.
    'cache' => DRUPAL_NO_CACHE, 
  );
  $blocks['statesidelegal_blog_topics'] = array(
    'info' => t('Stateside Blog Topics'), //The name that will appear in the block list.
    'cache' => DRUPAL_NO_CACHE, 
  );
  $blocks['statesidelegal_sidebar_terms'] = array(
    'info' => t('Stateside NSMI Cats Box'), //The name that will appear in the block list.
    'cache' => DRUPAL_NO_CACHE, 
  );
  $blocks['statesidelegal_wws_terms'] = array(
    'info' => t('Stateside WWS Cats Box'), //The name that will appear in the block list.
    'cache' => DRUPAL_NO_CACHE, 
  );
  $blocks['statesidelegal_footer'] = array(
    'info' => t('Stateside Footer'), //The name that will appear in the block list.
    'cache' => DRUPAL_NO_CACHE, 
  );
  $blocks['statesidevolunteer'] = array(
    'info' => t('Stateside Volunteer Map'), //The name that will appear in the block list.
    'cache' => DRUPAL_NO_CACHE, 
  );
  $blocks['statesidevolmini'] = array(
    'info' => t('Stateside Volunteer Map - Mini'), //The name that will appear in the block list.
    'cache' => DRUPAL_NO_CACHE, 
  );
  $blocks['statesidevolunteer_filter'] = array(
    'info' => t('Stateside Volunteer Filter'), //The name that will appear in the block list.
    'cache' => DRUPAL_NO_CACHE, 
  );
  $blocks['statesidevolunteer_block'] = array(
    'info' => t('Stateside Volunteer List'), //The name that will appear in the block list.
    'cache' => DRUPAL_NO_CACHE, 
  );
  $blocks['stateside_make_topic_block'] = array(
    'info' => t('Library Topics'), //The name that will appear in the block list.
    'cache' => DRUPAL_NO_CACHE, 
  );
  $blocks['stateside_make_topic_block2'] = array(
    'info' => t('Library Topics'), //The name that will appear in the block list.
    'cache' => DRUPAL_NO_CACHE, 
  );
  $blocks['stateside_og_request_block'] = array(
    'info' => t('OG Requests for Membership'), //The name that will appear in the block list.
    'cache' => DRUPAL_NO_CACHE, 
  );
//  $blocks['stateside_subtopic_block'] = array(
//    'info' => t('Stateside Subtopics'), //The name that will appear in the block list.
//    'cache' => DRUPAL_NO_CACHE, 
//  );
  return $blocks;
}  
function statesidelegal_block_view($delta = '') {
  global $user;
  global $base_path;
  global $base_url;
  $block = "";
  $ctext = "";
  switch($delta){
    case 'statesidelegal_sidebar_terms':
      $this_tid = $_SESSION['my_tid'][0];
      $ctext .= statesidelegal_term_list($this_tid);
      if ($this_tid==0){
        $sql = "select t.name, t.tid 
                    from taxonomy_term_data t 
                    inner join taxonomy_term_hierarchy h on h.tid = t.tid 
                    where h.parent = 0 and t.vid = 13 order by weight";
        $results = db_query($sql);
        $path = $base_path . "topics";
        $ctext = "<div id='nsmi_cats_block' class='block block-block'><nav><h4><a href='" . $path . "'> Topic Index</a></h4>";
        $ctext .= '<ul id="side-nav">';
        foreach ($results as $result) {
            $ctext .= '<li><a href="' . $path . $result->tid .'">' . $result->name . '</a></li>';
        }
        $ctext .= "</ul></nav></div>";
      }
      $block['content'] = $ctext;
      break;
    case 'statesidelegal_wws_terms':
      $this_tid = $_SESSION['wws_tid'][0];
      $this_tid = 3260;
      $this_nsmi = taxonomy_term_load($this_tid);
      if ($this_nsmi->vid==24){
        $ctext .= statesidelegal_term_list($this_tid);
      }
      if ($this_tid==0){$ctext = "";}
      $block['content'] = $ctext;
      break;
    case 'statesidevolunteer':
      $mapcontent = '';
//      if ($user->uid==0){$block['content'] = ""; break;}
      ob_start(); // start buffer
//      include ("./". drupal_get_path("module","statesidelegal")."/statesidevolunteermap.php");
      include ("./". drupal_get_path("module","statesidelegal")."/statesidevolunteermap.php");
      $mapcontent .= ob_get_contents(); // assign buffer contents to variable
      ob_end_clean(); // end buffer and remove buffer contents
      $block['content'] = $mapcontent ."</div></div>";
      break;
    case 'statesidevolmini':
      $mapcontent = '<div id="mini-map"><a title="Click for full size" href="' . $base_path . 'volunteermap"><h2>Go to Volunteer Map</h2></a></div>';
      ob_start(); // start buffer
      include ("./". drupal_get_path("module","statesidelegal")."/statesidevolunteermapmini.php");
      $mapcontent .= ob_get_contents(); // assign buffer contents to variable
      ob_end_clean(); // end buffer and remove buffer contents
      $block['content'] = $mapcontent ."</div></div>";
      break;
    case 'statesidevolunteer_filter':
//      if ($user->uid==0){$block['content'] = ""; break;}
      $form = drupal_get_form("statesidevolunteer_mapfilter");
      $mapcontent = '<div id="volunteersearch">' ;
      $mapcontent .= "<div class='filter-text'>Filter the map: </div>";
      $mapcontent .=  drupal_render($form) . '</div>' ;
      $block['content'] = $mapcontent ;
      break;
    case 'statesidevolunteer_block':
//      if ($user->uid==0){$block['content'] = ""; break;}
      $content = "<div id='vol_list'>";
      $zoom = 4;
      stateside_vol_info('volunteerpost2',$zoom);

      $keys = $_SESSION['vol_keys'][0];
      $num = 10;
      if (isset($_REQUEST['page'])){
        $from=$_REQUEST['page'];
      }
      else {$from = 0;}
      if (!$from){$from = 0;}
      else {$from = $from * $num;}
    // Get array of cleaned up keywords
    $query = db_select('search_index', 'i', array('target' => 'slave'))->extend('search_allQuery');
    $query->SearchExpression($keys,'statesidesearch');
    $query->parseSearchExpression();
    $mywords = $query->words;
    $db_or = db_or();
    $jrquery = db_select('search_api_db_jobposts_search_api_aggregation_1','jr');
    $jrquery->addField('jr', 'item_id', 'nid');
    $jrquery->addField('jr', 'word');
    $jrquery->condition('word',$keys);
    // Get a reference to current conditions
    $conditions =& $jrquery->conditions();
    // Reset the condition array. It needs a default #conjunction for which AND is fine
    $conditions = array('#conjunction' => 'AND');
    $db_or->condition('word',$keys);
    foreach($mywords as $word){
        $wrd =  '%' . preg_replace('!\*+!', '%', $word) . '%';
        $db_or->condition('word', $wrd , 'LIKE');
    }
    $jrquery->condition($db_or);
    $jtquery = db_select('search_api_db_node_body_value','jt');
    $jtquery->addJoin("inner", "node", "n", "n.nid = jt.item_id");
    $jtquery->addField('jt', 'item_id', 'nid');
    $jtquery->addField('jt', 'word');
    $jtquery->condition('n.type','job_posting');
    $jtquery->condition($db_or);
    $jrquery->union($jtquery);
    $subquery = db_select($jrquery,'sub');
    $subquery->addField("sub",'nid');
    $subquery->condition($db_or);

    $query = db_select('volunteerpost2', 'sl');
    $query->fields("sl",array(
        "nid",
        "name",
        "latitude",
        "longitude",
        "title",
        "address1",
        "address2",
        "telephone",
        "telephone2",
        "city",
        "state",
        "zip",
        "url",
        "tag",
        "startdate",
        "enddate",
        "email"
    ));
    if ($keys){
        $query->condition("sl.nid",$subquery,"IN");
    }
    $query->orderBy('title');
    $total = $query->countQuery()->execute()->fetchField();
    $query->range($from,$num);
      
      
      $rsAll = $query->execute();
      pager_default_initialize($total,10);
      $class = 'odd';
      foreach($rsAll as $rs) {
            $sdate = $rs->startdate;
            $edate = $rs->enddate;
            if ($sdate==$edate){$edate = 0;}
            $now = time();
            if ($sdate > 0 && $sdate > $now){continue;}
            if ($edate > 0 && $edate < $now){continue;}
          
          if ($class=='odd'){
            $class = 'even';
            $content .= "<div class='vol-block odd'>";
          }
          else {
            $class = 'odd';
            $content .= "<div class='vol-block even'>";
          }
          $content .= "<div class='vol-item'>";
          $content .=  "<a href='node/".$rs->nid . "'>".$rs->title . "</a><br />" ;
          if ($rs->url){
              $webPage = str_replace("http://","",$rs->url);
              $content .= "<a href='http://".$webPage."'>".$rs->name . "</a><br />";
          }
          else {
              $content .= $rs->name . "<br />";
          }
          $content .= "</div>";
          $content .=  $rs->city . ", " . $rs->state . "<br />";
          $content .= "</div>";
          $content .=  "<hr />";
      }
      $content .= "</div>";
      $content .= theme('pager',array('quantity',$total));
      
      $block['content'] = $content;
      break;
    case 'statesidelegal_bloggerlist':
      $ctext .= "<div id='sl_blogger_list'>";
      $sql = "SELECT n.value as name, b.value as bio, u.uid FROM users u
                LEFT JOIN users_roles r on r.uid = u.uid
                LEFT JOIN profile_value n on n.uid = u.uid and n.fid = 1
                LEFT JOIN profile_value b on b.uid = u.uid and b.fid = 2
                WHERE r.rid in 
                    (SELECT rid FROM role WHERE name = 'blogger')
                ORDER BY 1";
      $results = db_query($sql);
      $ctext .= "<h1>Our Bloggers</h1>";
      foreach($results as $result){
          $ctext .= "<h2>".$result->name."</h2>";
          $ctext .= "<div>".$result->bio;
          $ctext .= "<a class='ask-button' href='" . $base_url . "/adv_blog/" . 
                        $result->uid . "'>See all posts by " . $result->name . "</a></div>";
      }
      $ctext .= "</div>";
      $block['subject'] = "";
      $block['content'] = $ctext;
      break;
    case 'statesidelegal_blog_topics':
      $ctext = "";
      $sql = "SELECT name, tid
                FROM taxonomy_term_data td 
                WHERE tid IN
                    (SELECT field_blog_topic_tid 
                        from field_data_field_blog_topic 
                        WHERE bundle = 'blog')
                GROUP BY 1";
      $results = db_query($sql);
      if ($results){
          $ctext .= "<div class='sl-blog-topics'>";
          $ctext .= "<ul class='blog-topics'>";
          foreach($results as $myresult){
              $ctext .= "<li><a href='taxonomy/term/" . $myresult->tid . "'>"  . ucfirst($myresult->name) . "</a></li>";
          }
          $ctext .= "</ul></div>";
          $block['subject'] = "Advocate Blog Topics";
          $block['content'] = $ctext;
      }
      break;
    case 'statesidelegal_blogger':
      $ctext="";
      if (arg(0) == 'node' && is_numeric(arg(1))) {
        $thisnode = node_load(arg(1));
      }
      else {return $block;}
      $this_user = user_load($thisnode->uid);
      if ($this_user){
          $ctext .= $this_user->profile_bio;
          $ctext .= "<a class='ask-button' href='" . $base_url . "/blog/" . $this_user->uid . "'>See all posts by this author</a>";
          $block['subject'] = "Author ". $this_user->profile_fullname;
          $block['content'] = $ctext;
          
      }
      break;   
    case 'statesidelegal_subscriptions':
      if (!user_access('create subscriptions')) {
        $text = '<div clsas="subscribe_login">' . 
                '<h4>You must be logged in to subscribe to Stateside content</h4>
                    <a href="/user/login?destination=node/72421%23comment-form">Log in</a>
                    or <a href="/user/register?destination=node/72421%23comment-form">register</a>
                    to post comments</div>';
        $block['subject'] = t('Subscribe');
        $block['content'] = $text;
        return $block;
      }
      $list = notifications_subscription_list('page subscriptions')
        ->filter_option('subscriptions_block');
      if ($list->count()) {
        $block['subject'] = t('Subscriptions');
        $display = variable_get('notifications_ui_block_display', 'links');
        $block['content'] = drupal_get_form('notifications_subscription_list_form', 'checkboxes', $list);
      }
      break;     
    case 'statesidelegal_footer':
      $ctext .= statesidelegal_getfooter();
      $block['content'] = $ctext;
      break;
    case 'stateside_make_topic_block':
      $ctext = "<div class='topic-wrapper'><h2><a class='topic-head' href='#' onclick='stateside_topictoggle();'>Library</a></h2>";
      $ctext .= stateside_maketopics();
      $ctext .= "</div>";
      $ctext .= stateside_makesubs();
      $block['content'] = $ctext;
      break;
    case 'stateside_make_topic_block2':
      $ctext = "<div class='topic-wrapper'><h2><a class='topic-head' href='#' onclick='stateside_topictoggle();'>Library</a></h2>";
      $ctext .= stateside_maketopics();
      $ctext .= "</div>";
      $ctext .= stateside_makesubs();      
      $block['content'] = $ctext;
      break;
    case 'stateside_og_request_block':
      $ctext = statesidelegal_og_pending_requests();
      $block['content'] = $ctext;
      break;
  }
  
  return $block;
}

function statesidelegal_getfooter(){
global $base_path;
global $base_url;
$out = '<div id="f-left">';
$out .= '<div id="copyright">';
$out .= '<p> &copy; <strong> Stateside Legal </strong> All rights reserved.</p>';
//$out .= '<p><a href="' . $base_path . 'website-use-agreement">Terms of Use</a>';
//$out .= '<a href="' . $base_path . 'website-privacy-policy">Privacy Policy</a></p>';
$out .= '</div><!-- end copyright -->';
$out .= '<a href="' . $base_path . 'how-can-we-serve-you-better" class="red-button"> + Feedback </a>';
$out .= '<div id="footer-logos">';
//$out .= '<div id="sponsor-label">With support from</div>';
//$out .= '<img id="sponsor" src="' . $base_url . "/" . drupal_get_path('theme', 'state7') . '/images/gd.png" alt="General Dynamics" title="General Dynamics"/>';
$out .= '<img src="' . $base_url . "/" . drupal_get_path('theme', 'state7') . '/images/statesidelogo.gif" alt="StatesideLegal" title="Stateside Legal"/>';
$out .= '<a href="http://www.whitehouse.gov/joiningforces"><img src="' . $base_url . "/" . drupal_get_path('theme', 'state7') . '/images/joiningforces.gif" alt="Joining Forces logo" title="Joining Forces" /></a>';
$out .= '<a href="http://www.lsc.gov"><img src="' . $base_url . "/" . drupal_get_path('theme', 'state7') . '/images/lsc.gif" alt="LSC logo" title="Legal Services Corporation" /></a>';
$out .= '</div><!-- end footer-logos -->';
$out .= '<div class="footer-logos2">';
$out .= '<a href="http://www.vetsprobono.org/"><img src="' . $base_url . "/" . drupal_get_path('theme', 'state7') . '/images/VeteransConsortium.png" alt="Veterans Consortium" title="Veterans Consortium"/></a>';
$out .= "</div>";
//$out .= '<div id="copyright">';
//$out .= '<p> &copy; <strong> Stateside Legal </strong> All rights reserved.<br />';
//$out .= '<a href="' . $base_path . 'website-use-agreement">Terms of Use</a>';
//$out .= '<a href="' . $base_path . 'website-privacy-policy">Privacy Policy</a></p>';
//$out .= '</div><!-- end copyright -->';
$out .= '</div><!-- end f-left -->';
$out .= '<div id="f-right">';
$out .= statesidelegal_footer_menu();
$out .= '<div class="list-col-2">';
$out .= '<ul>';
$out .= '<li><a href="' . $base_path . 'statesidemap">Find Local Help</a></li>';
$out .= '<li><a href="' . $base_path . 'advocate-network">Advocates</a>';
$out .= '<ul>';
$out .= '<li><a href="' . $base_path . 'advocate-information">Welcome</a></li>';
$out .= '<li><a href="' . $base_path . 'Advocate-Tool-Kit">Advocate Tool Kits</a></li>';
$out .= '<li><a href="' . $base_path . 'blog">Advocate Blogs</a></li>';
$out .= '<li><a href="' . $base_path . 'advocate-training-resources-and-other-tools">More Resources</a></li>';
$out .= '</ul>';
$out .= '</li>';
$out .= '</ul>';
$out .= '</div><!-- end list-col-2 -->';
$out .= '<div class="list-col-3">';
$out .= '<ul>';
$out .= '<li><a href="' . $base_path . 'interactive-forms-directory">Form Letters</a>';
$out .= '<ul>';
$out .= '<li><a href="' . $base_path . 'interactive-forms-directory#active">Active Service Members</a></li>';
$out .= '<li><a href="' . $base_path . 'interactive-forms-directory#estate">Estate Planning  /</a>';
$out .= '<a href="' . $base_path . 'interactive-forms-directory#veterans">VA</a></li>';
$out .= '</ul>';
$out .= '</li>';
$out .= '<li><a href="' . $base_path . 'links">Links</a>';
$out .= '<ul>';
$out .= '<li><a href="' . $base_path . 'links#proof">Proof of Military Service</a></li>';
$out .= '<li><a href="' . $base_path . 'links#legal">Legal/Advocacy Services</a></li>';
$out .= '</ul>';
$out .= '</li>';
$out .= '</ul>';
$out .= '</div><!-- end list-col-3 -->';
$out .= '<div class="list-col-4">';
$out .= '<ul>';
$out .= '<li><a href="#">Help Us</a>';
$out .= '<ul>';
$out .= '<li><a href="https://npo.networkforgood.org/Donate/Donate.aspx?npoSubscriptionId=1004836&code=PTLA%20General">Donate</a></li>';
$out .= '<li><a href="volunteer">New Volunteers</a></li>';
$out .= "</ul><ul class='terms-of-use'>";
$out .= '<li><a href="' . $base_path . 'website-use-agreement">Terms of Use</a></li>';
$out .= '<li><a href="' . $base_path . 'website-privacy-policy">Privacy Policy</a></li>';
$out .= '</ul>';
$out .= '</li>';
$out .= '</ul>';
$out .= '</div><!-- end list-col-4 -->';
$out .= '</div><!-- end f-right -->    ';
return $out;
}
function stateside_maketopics(){
    global $base_url;
    $out = "<div id='topic-list'>";
    $sql = "SELECT td.tid AS tid
                FROM taxonomy_term_data td 
                LEFT JOIN taxonomy_vocabulary tv ON td.vid = tv.vid 
                LEFT JOIN taxonomy_term_hierarchy th ON td.tid = th.tid 
                WHERE tv.machine_name = 'women_who_serve'
                AND th.parent = '0' " ;
    $tid = db_query($sql)->fetchColumn();
    $term = taxonomy_term_load($tid);
    $uri = $term->field_icon_image['und'][0]['uri'];
    //dsm($uri);
    if ($uri){
        $url = image_style_url('thumbnail', $uri);
        $img = "<img class='topic-icon-" . $term->tid . "' src='" . $url . "' />";
        $out .= "<div class='wmn-topic wmntopic-id-". $term->tid . "' >";
        $out .= "<a id='topic-" . $term->tid . "' class='wmn-title' href='#' onclick='stateside_topicslide(" . $term->tid . ")'>";
        $out .= $img . "<span class='wmn-title-text'>Women's Issues</span></a></div>";
        $out .= "<div style='border-bottom: 1px solid #fff;padding-bottom:10px;clear:both;margin-bottom: 10px;'> </div>";
    }
    $uri = null;
    $sql = "SELECT td.tid AS tid
                FROM taxonomy_term_data td 
                LEFT JOIN taxonomy_vocabulary tv ON td.vid = tv.vid 
                LEFT JOIN taxonomy_term_hierarchy th ON td.tid = th.tid 
                WHERE tv.machine_name = 'vocabulary_13'
                AND th.parent = '0' " ;
    $results = db_query($sql);
    foreach($results as $result){
        $term = taxonomy_term_load($result->tid);
        if(isset($term->node_image['und'])){
            $uri = $term->node_image['und'][0]['uri'];
            if ($uri){
                $url = image_style_url('thumbnail', $uri);
                $img = "<img class='topic-icon-" . $term->tid . "' src='" . $url . "' />";
                $out .= "<div class='topic-icons topic-id-". $term->tid . "' >";
                $out .= "<a id='topic-" . $term->tid . "' href='#' onclick='stateside_topicslide(" . $term->tid . ")'>";
                $out .= $img . "</a></div>";
            }
        }
    }
    $out .= "</div>";
    return $out;
}
function statesidelegal_og_pending_requests($group_type = 'node') {

  //Get all the groups the user belongs to
  $user_groups = og_get_groups_by_user();

  // Load the whole shebang as entities so we have everything
  $groups = entity_load($group_type,$user_groups[$group_type]);

  $og_pending = '';

  foreach($groups as $gid=>$group) {
    // Check if the user can approve subscriptions
    if (og_user_access($group_type, $gid, 'approve and deny subscription ')) {

      $query = db_query('SELECT etid
                            FROM {og_membership}
                            WHERE gid = :gid
                            AND state = 2',
          array(':gid' => $gid));

      $result = $query->fetchAllKeyed();

      if (!empty($result)) {
        $link = l($groups[$gid]->title. ' ('.count($result).')', 'group/node/'.$gid.'/admin/people');
        $og_pending = '<li>'. $link .'</li>';
      }
    }
  }

  if(!empty($og_pending)) {
    return '<ul>'. $og_pending .'</ul>';
  }
}