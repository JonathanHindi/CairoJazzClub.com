<?php
// $Id: sexybookmarks_admin_css.tpl.php,v 1.1 2010/02/12 07:06:32 deciphered Exp $
/**
 * @file
 * Theme for SexyBookmarks dynamic admin CSS.
 *
 * Available variables:
 * - $bookmarks: A string containing the exported module name.
 *
 * Each $bookmark in $bookmarks contains:
 * - $bookmark['title']: The title of the bookmark service.
 * - $bookmark['description']: The description of the bookmark service.
 * - $bookmark['url']: The URL of the bookmark service.
 * - $bookmark['icon']: The path to the SexyBookmarks icon for the bookmark
 *   service.
 */
?>
/* $Id: sexybookmarks_admin_css.tpl.php,v 1.1 2010/02/12 07:06:32 deciphered Exp $ */

#sexybookmarks DIV.links
{
  float: right;
}

#sexybookmarks DIV.form-item
{
  height: 45px;
  margin: 12px 2px;
}

#sexybookmarks DIV.form-item,
#sexybookmarks DIV.form-item LABEL
{
  cursor: move;
  float: left;
  padding: 0;
  text-align: center;
  width: 60px;
}

#sexybookmarks DIV.form-item LABEL
{
  height: 40px;
}

#sexybookmarks DIV.form-item INPUT
{
  margin-top: 30px;
}

<?php foreach ($bookmarks as $key => $bookmark) : ?>
#sexybookmarks #edit-bookmarks-<?php print $key; ?>-wrapper LABEL { background-image: url('<?php print $bookmark['icon']; ?>') }
<?php endforeach; ?>

#sexybackgrounds .form-radios DIV.form-item
{
  display: inline-block;
  padding: 0 10px 10px 0;
}
