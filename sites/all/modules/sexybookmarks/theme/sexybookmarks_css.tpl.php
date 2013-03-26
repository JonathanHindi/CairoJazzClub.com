<?php
// $Id: sexybookmarks_css.tpl.php,v 1.1 2010/02/12 07:06:32 deciphered Exp $
/**
 * @file
 * Theme for SexyBookmarks dynamic CSS.
 *
 * Available variables:
 * - $settings: An array containing SexyBookmarks settings.
 *
 * Each $bookmark in $settings['bookmarks'] contains:
 * - $bookmark['title']: The title of the bookmark service.
 * - $bookmark['description']: The description of the bookmark service.
 * - $bookmark['url']: The URL of the bookmark service.
 * - $bookmark['icon']: The path to the SexyBookmarks icon for the bookmark
 *   service.
 */
?>
/* $Id: sexybookmarks_css.tpl.php,v 1.1 2010/02/12 07:06:32 deciphered Exp $ */

DIV.sexybookmarks
{
<?php if (isset($settings['background']['file'])) : ?>
  background-image: url('<?php print $settings['background']['file']; ?>');
  background-repeat: no-repeat;
<?php endif; ?>
  clear: both;
<?php if ($settings['general']['expand']) : ?>
  height: 29px;
<?php endif; ?>
<?php if (isset($settings['background']['margin'])) : ?>
  margin: <?php print $settings['background']['margin']; ?>;
<?php else: ?>
  margin: 20px 0;
<?php endif; ?>
<?php if ($settings['general']['expand']) : ?>
  overflow: hidden;
<?php endif; ?>
<?php if (isset($settings['background']['padding'])) : ?>
  padding: <?php print $settings['background']['padding']; ?>;
<?php endif; ?>
<?php if ($settings['general']['expand']) : ?>
  position: relative;
}
DIV.sexybookmarks-inner
{
  position: absolute;
<?php endif; ?>
}

DIV.sexybookmarks A
{
  background-position: 0 bottom;
  border: 0;
  display: block;
  float: left;
  height: 29px;
  text-decoration: none;
  width: 60px;
}
DIV.sexybookmarks A:hover
{
  background-position: 0 top;
}
DIV.sexybookmarks A SPAN
{
  display: none;
}

<?php foreach ($settings['bookmarks'] as $key => $bookmark) : ?>
DIV.sexybookmarks A.sexy-<?php print $key; ?> { background-image: url('<?php print $bookmark['icon']; ?>') }
<?php endforeach;
