<html xmlns="http://www.w3.org/1999/xhtml" xml:lang="<?php print $language->language ?>" lang="<?php print $language->language ?>">

<head>

<meta content="IE=edge" http-equiv="X-UA-Compatible" />

<base target="_parent" />
<?php
if ($_GET["format"] == "simple") {
  include ('simple.tpl.php');
  return;
}
?>
<?php global $base_url;?>
<title><?php print $head_title ?></title>
<?php print $head ?>
<?php print $styles ?>
<?php print $scripts ?>


<script type="text/javascript" language="Javascript">
       
  var PopupWarning = {
	init : function(URL)
	{			
		var is_chrome = navigator.userAgent.toLowerCase().indexOf('chrome') > -1;
		if (!is_chrome)
		{
			if(this.popups_are_disabled(URL) == true)
			{ 			
				 alert("Please enable popups for this site to open our music player.");
			}
		}
		else
		{
			this.chrome_popup_test(URL);
		}
	},


	chrome_popup_test : function(URL)
	{
		myPopup = window.open(URL, "popup", "toolbar=0,scrollbars=0,location=0,statusbar=0,menubar=0,resizable=0,width=350,height=200,left = 0,top = 0");
		myPopup.onload = function() {
        setTimeout(function() {
            if (myPopup.screenX === 0) {
                alert("Please enable popups for this site to open our music player.");
            }
        }, 0);
		};
	},
	
	popups_are_disabled : function(URL)
	{
			var popup = window.open(URL, "popup", "toolbar=0,scrollbars=0,location=0,statusbar=0,menubar=0,resizable=0,width=350,height=200,left = 0,top = 0");
			
			if(!popup || popup.closed || typeof popup == 'undefined' || typeof popup.closed=='undefined')
			{
				return true;
			}
			window.focus();
			popup.blur();		
			return false;
	},

  };
  
function popUp(URL) {
	PopupWarning.init(URL);
}
// End -->
</script>
<script type="text/javascript">

  var _gaq = _gaq || [];
  _gaq.push(['_setAccount', 'UA-7825419-12']);
  _gaq.push(['_setDomainName', '.cairojazzclub.com']);
  _gaq.push(['_trackPageview']);

  (function() {
    var ga = document.createElement('script'); ga.type = 'text/javascript'; ga.async = true;
    ga.src = ('https:' == document.location.protocol ? 'https://ssl' : 'http://www') + '.google-analytics.com/ga.js';
    var s = document.getElementsByTagName('script')[0]; s.parentNode.insertBefore(ga, s);
  })();

</script>
</head>


<?php if (drupal_is_front_page()) { ?>
<body class="<?php print $body_classes; ?>" onLoad="javascript:popUp('<?php print $base_url;?>/playlist_player')">
<div class="wrapper"><!-- wrapper start -->
<div class="container"><!-- container start -->
  <div style="height:452px;" class="header"><!-- header start -->
<?php print $header ?></div><!-- header end -->
<div class="home-modules-container">
<?php print $featured ?>
</div>
    <div class="footer"><!-- footer start -->
   <?php print $footer ?>
   <div class="music-player specialbox">
   <a href="javascript:popUp('<?php print $base_url;?>/playlist_player')">
   <img src="<?php print base_path().path_to_theme();?>/images/player.png" />Launch CJC music player</a></div>
    <div class="music-player">
   <a href="http://www.youtube.com/user/cairojazzclub7?blend=11&ob=5" target="_blank">
   <img src="<?php print base_path().path_to_theme();?>/images/youtube.jpg" /></a></div>
       <div class="music-player">
   <a href="http://twitter.com/CairoJazzClub" target="_blank">
   <img src="<?php print base_path().path_to_theme();?>/images/twitter.jpg" /></a></div>
       <div class="music-player">
   <a href="http://www.facebook.com/groups/2252248865/?ref=ts" target="_blank">
   <img src="<?php print base_path().path_to_theme();?>/images/facebook.jpg" /></a></div>
<div class="social-bookmarks"><a href="http://www.cairojazzclub.com"><img width="61" height="35" border="0" alt="Cairo Jazz Club" style="text-align:center;" src="<?php print base_path().path_to_theme();?>/images/cairo-jazz-club-piper.png"></a>
  </div>
    	
    </div><!-- footr end -->
<div class="credits">Copyright &copy; 2011
<a href="<?php print base_path();?>">Cairo Jazz Club LLC</a> | Designed by <a target="_blank" title="Zanad.TV" href="http://www.zanad.tv/">zanad.tv</a> | Developed by
<a target="_blank" title="Artology Studio Your Graphic Desgn and Development Partner in Egypt" href="http://www.artologystudio.com/">Artology Studio</div>
      <!--<a href="#" onclick="return hs.htmlExpand(this)">Open Popup</a>
       <div id="dragged_popup" class="highslide-maincontent">
<?php print views_embed_view('playlist',$display_id = 'default');?>
</div>-->
<!--<div class="highslide-maincontent">
	<h3>Lorem ipsum</h3>
	Lorem ipsum dolor sit amet, consectetuer adipiscing elit. Aliquam dapibus leo quis nisl. In lectus. Vivamus consectetuer pede in nisl. Mauris cursus pretium mauris. Suspendisse condimentum mi ac tellus. Pellentesque habitant morbi tristique senectus et netus et malesuada fames ac turpis egestas. Donec sed enim. Ut vel ipsum. Cras consequat velit et justo. Donec mollis, mi at tincidunt vehicula, nisl mi luctus risus, quis scelerisque arcu nibh ac nisi. Sed risus. Curabitur urna. Aliquam vitae nisl. Quisque imperdiet semper justo. Pellentesque nonummy pretium tellus.
</div> -->
 <?php  } else {?>
 <body>
<div class="wrapper"><!-- wrapper start -->
<div class="container"><!-- container start -->
<div style="height:192px;" class="header"><!-- header start -->
<?php print $header ?>
</div><!-- header end -->
<div class="nav">
<?php print $left ?>
</div>
	<input type='hidden' id='current_page' />
	<input type='hidden' id='show_per_page' />
	<div class="main_content">
		<div id="main_content_script" style="float:left;">
			<?php if($tabs) : ?>
      <?php if ($show_messages && $messages): print $messages; endif; ?>
      <ul class="pagetabs">
				<?php print $tabs;?>  
			</ul>
      <?php endif; ?>
				<?php print $content;?> 
		</div>
		<div id='page_navigation'></div>
	</div>
<div class="modules-right">
<?php print $right ?>
 </div>
</div>
<div class="clear"></div>

    <div class="footer"><!-- footer start -->
   <?php print $footer ?>
   <div class="music-player specialbox">
   <a href="javascript:popUp('<?php print $base_url;?>/playlist_player')">
   <img src="<?php print base_path().path_to_theme();?>/images/player.png" />Launch CJC music player</a></div>
    <div class="music-player">
   <a href="http://www.youtube.com/user/cairojazzclub7?blend=11&ob=5" target="_blank">
   <img src="<?php print base_path().path_to_theme();?>/images/youtube.jpg" /></a></div>
       <div class="music-player">
   <a href="http://twitter.com/CairoJazzClub" target="_blank">
   <img src="<?php print base_path().path_to_theme();?>/images/twitter.jpg" /></a></div>
       <div class="music-player">
   <a href="http://www.facebook.com/groups/2252248865/?ref=ts" target="_blank">
   <img src="<?php print base_path().path_to_theme();?>/images/facebook.jpg" /></a></div>
<div class="social-bookmarks"><a href="http://www.cairojazzclub.com"><img width="61" height="35" border="0" alt="Cairo Jazz Club" style="text-align:center;" src="<?php print base_path().path_to_theme();?>/images/cairo-jazz-club-piper.png"></a>
  </div>
    	
    </div><!-- footr end -->
 
<div class="credits">Copyright &copy; 2011
<a href="<?php print base_path()?>">Cairo Jazz Club LLC</a> | Designed by <a target="_blank" title="Zanad.TV" href="http://www.zanad.tv/">zanad.tv</a> | Developed by
<a target="_blank" title="Artology Studio Your Graphic Desgn and Development Partner in Egypt" href="http://www.artologystudio.com/">Artology Studio</a></div>
    
  </div><!-- container end -->

  </div><!-- wrapper end -->
<?php } ?>
</body>
</html>	
