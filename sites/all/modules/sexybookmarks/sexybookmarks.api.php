<?php
// $Id: sexybookmarks.api.php,v 1.1 2010/02/12 07:06:31 deciphered Exp $
/**
 * @file
 * Hooks provided by the SexyBookmarks module.
 */

/**
 * Inform SexyBookmarks of additional bookmark services.
 *
 * @return
 *   A keyed array.
 */
function hook_sexybookmarks() {
  return array(
    'mymodule_bookmark' => array(
      'title' => 'MyModule Bookmark',
      'description' => t('Share this on !title'),
      'icon' => drupal_get_path('module', 'mymodule') . '/images/icon_bookmark.png',
      'url' => 'http://www.mysite.com/share?url=PERMALINK&title=TITLE',
    ),
    'mymodule_bookmark_french' => array(
      'title' => 'MyModule Bookmark',
      'description' => t('Share this on !title'),
      'url' => 'http://www.mysite.fr/share?url=PERMALINK&title=TITLE',
      'icon' => drupal_get_path('module', 'mymodule') . '/images/icon_bookmark_french.png',
      'language' => t('French'),
    ),
  );
}

/**
 * Inform SexyBookmarks of additional backgrounds.
 *
 * @return
 *   A keyed array.
 */
function hook_sexybackgrounds() {
  return array(
    'mymodule_background' => array(
      'file' => drupal_get_path('module', 'mymodule') . '/images/background.png',
      'margin' => '0',
      'padding' => '26px 0 0 10px',
    ),
  );
}
