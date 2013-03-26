<html xmlns="http://www.w3.org/1999/xhtml" xml:lang="<?php print $language->language ?>" lang="<?php print $language->language ?>">

<head>
<?php global $base_url;?>
<title><?php print $head_title ?></title>
<?php print $head ?>
<?php print $styles ?>
<?php print $scripts ?>
</head>

<body>
<div class="wrapper"><!-- wrapper start -->
<div class="container"><!-- container start -->


<div class="main_content">
<ul class="pagetabs">
   <?php print $tabs;?>  
</ul>
  <?php print $content;?> 
</div>

</div>



        

  </div><!-- container end -->

  </div><!-- wrapper end -->

</body>
</html>

	