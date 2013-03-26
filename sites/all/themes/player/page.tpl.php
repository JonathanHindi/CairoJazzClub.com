<html xmlns="http://www.w3.org/1999/xhtml" xml:lang="<?php print $language->language ?>" lang="<?php print $language->language ?>">

<head>
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
</head>

<body>
<div class="wrapper"><!-- wrapper start -->



       <?php print $content ?>  

  </div><!-- container end -->



</body>
</html>

	