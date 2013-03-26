<?php
// $Id: sexybookmarks.inc,v 1.2 2010/02/23 06:53:23 deciphered Exp $
/**
 * @file
 * Contains bookmark services and backgrounds for the SexyBookmarks module.
 */

/**
 * Implements hook_sexybookmarks().
 */
function sexybookmarks_sexybookmarks() {
  global $language;

  $tld = '.com';
  switch ($language->language) {
    case 'de':
      $tld = '.de';
      break;

    case 'zh-hans':
    case 'zh-hant':
      $tld = '.cn';
      break;

    case 'es':
      $tld = '.es';
      break;

    case 'fr':
      $tld = '.fr';
      break;

    case 'ru':
      $tld = '.ru';
      break;
  }

  return array(
    'scriptstyle' => array(
      'title' => 'Script & Style',
      'description' => t('Submit this to !title'),
      'url' => 'http://scriptandstyle.com/submit?url={PERMALINK}&title={TITLE}',
    ),
    'blinklist' => array(
      'title' => 'Blinklist',
      'description' => t('Share this on !title'),
      'url' => 'http://www.blinklist.com/index.php?Action=Blink/addblink.php&Url={PERMALINK}&Title={TITLE}',
    ),
    'delicious' => array(
      'title' => 'Delicious',
      'description' => t('Share this on !title'),
      'url' => 'http://del.icio.us/post?url={PERMALINK}&title={TITLE}',
    ),
    'digg' => array(
      'title' => 'Digg',
      'description' => t('Digg this!'),
      'url' => 'http://digg.com/submit?phase=2&url={PERMALINK}&title={TITLE}',
    ),
    'diigo' => array(
      'title' => 'Diigo',
      'description' => t('Post this on !title'),
      'url' => 'http://www.diigo.com/post?url={PERMALINK}&title={TITLE}&desc={SEXY_TEASER}',
    ),
    'reddit' => array(
      'title' => 'Reddit',
      'description' => t('Share this on !title'),
      'url' => 'http://reddit.com/submit?url={PERMALINK}&title={TITLE}',
    ),
    'yahoobuzz' => array(
      'title' => 'Yahoo! Buzz',
      'description' => t('Buzz up!'),
      'url' => 'http://buzz.yahoo.com/submit/?submitUrl={PERMALINK}&submitHeadline={TITLE}&submitSummary={SEXY_TEASER}&submitCategory={YAHOOCATEGORY}&submitAssetType={YAHOOMEDIATYPE}',
      'settings' => array(
        'YAHOOCATEGORY' => array(
          '#title' => t('Default content category'),
          '#type' => 'select',
          '#options' => array(
            'entertainment' => t('Entertainment'),
            'lifestyle' => t('Lifestyle'),
            'health' => t('Health'),
            'usnews' => t('U.S. News'),
            'business' => t('Business'),
            'politics' => t('Politics'),
            'science' => t('Sci/Tech'),
            'world_news' => t('World'),
            'sports' => t('Sports'),
            'travel' => t('Travel'),
          ),
        ),
        'YAHOOMEDIATYPE' => array(
          '#title' => t('Default media type'),
          '#type' => 'select',
          '#options' => array(
            'text' => t('Text'),
            'image' => t('Image'),
            'audio' => t('Audio'),
            'video' => t('Video'),
          ),
        ),
      ),
    ),
    'stumbleupon' => array(
      'title' => 'Stumbleupon',
      'description' => t('Stumble upon something good? Share it on !title'),
      'url' => 'http://www.stumbleupon.com/submit?url={PERMALINK}&title={TITLE}',
    ),
    'technorati' => array(
      'title' => 'Technorati',
      'description' => t('Share this on !title'),
      'url' => 'http://technorati.com/faves?add={PERMALINK}',
    ),
    'mixx' => array(
      'title' => 'Mixx',
      'description' => t('Share this on !title'),
      'url' => 'http://www.mixx.com/submit?page_url={PERMALINK}&title={TITLE}',
    ),
    'myspace' => array(
      'title' => 'MySpace',
      'description' => t('Post this to !title'),
      'url' => 'http://www.myspace.com/Modules/PostTo/Pages/?u={PERMALINK}&t={TITLE}',
    ),
    'designfloat' => array(
      'title' => 'DesignFloat',
      'description' => t('Submit this to !title'),
      'url' => 'http://www.designfloat.com/submit.php?url={PERMALINK}&title={TITLE}',
    ),
    'facebook' => array(
      'title' => 'Facebook',
      'description' => t('Share this on !title'),
      'url' => 'http://www.facebook.com/share.php?v=4&src=bm&u={PERMALINK}&t={TITLE}',
    ),
    'twitter' => array(
      'title' => 'Twitter',
      'description' => t('Tweet this!'),
      'url' => 'http://twitter.com/home?status={SHORT_TITLE}+-+{FETCH_URL}{POST_BY}&source=shareaholic',
      'settings' => array(
        'POST_BY' => array(
          '#type' => 'textfield',
          '#title' => t('Twitter ID'),
        ),
      ),
      'theme' => array(
        'POST_BY' => '+(via+@{VALUE})',
      ),
    ),
    'mail' => array(
      'title' => t("an 'Email to a Friend' link"),
      'description' => t('Email this to a friend?'),
      'url' => 'mailto:?subject=%22{TITLE}%22&body=' . urlencode(t('I thought this article might interest you.')) . '%0A%0A%22{POST_SUMMARY}%22%0A%0A' . urlencode(t('You can read the full article here')) . '%3A%20{PERMALINK}',
    ),
    'tomuse' => array(
      'title' => 'ToMuse',
      'description' => t('Suggest this article to !title'),
      'url' => 'mailto:tips@tomuse.com?subject=' . urlencode(t('New tip submitted via the SexyBookmarks Plugin!')) . '&body=' . urlencode(t('I would like to submit this article')) . '%3A%20%22{TITLE}%22%20' . urlencode(t('for possible inclusion on ToMuse.')) . '%0A%0A%22{POST_SUMMARY}%22%0A%0A' . urlencode(t('You can read the full article here')) . '%3A%20{PERMALINK}',
    ),
    //'comfeed' => array(
    //  'title' => t("a 'Subscribe to Comments' link"),
    //  'description' => t('Subscribe to the comments for this post?'),
    //  'url' => '{PERMALINK}',
    //),
    'linkedin' => array(
      'title' => 'LinkedIn',
      'description' => t('Share this on !title'),
      'url' => 'http://www.linkedin.com/shareArticle?mini=true&url={PERMALINK}&title={TITLE}&summary={POST_SUMMARY}&source={SITE_NAME}',
    ),
    'newsvine' => array(
      'title' => 'Newsvine',
      'description' => t('Seed this on !title'),
      'url' => 'http://www.newsvine.com/_tools/seed&save?u={PERMALINK}&h={TITLE}',
    ),
    'google' => array(
      'title' => 'Google Bookmarks',
      'description' => t('Add this to !title'),
      'url' => 'http://www.google.com/bookmarks/mark?op=add&bkmk={PERMALINK}&title={TITLE}',
    ),
    'googlereader' => array(
      'title' => 'Google Reader',
      'description' => t('Add this to !title'),
      'url' => 'http://www.google.com/reader/link?url={PERMALINK}&title={TITLE}&srcUrl={PERMALINK}&srcTitle={TITLE}&snippet={POST_SUMMARY}',
    ),
    'misterwong' => array(
      'title' => 'Mister Wong',
      'description' => t('Add this to !title'),
      'url' => 'http://www.mister-wong' . $tld . '/addurl/?bm_url={PERMALINK}&bm_description={TITLE}&plugin=sexybookmarks',
    ),
    'izeby' => array(
      'title' => 'Izeby',
      'description' => t('Add this to !title'),
      'url' => 'http://izeby.com/submit.php?url={PERMALINK}',
    ),
    'tipd' => array(
      'title' => 'Tipd',
      'description' => t('Share this on !title'),
      'url' => 'http://tipd.com/submit.php?url={PERMALINK}',
    ),
    'pfbuzz' => array(
      'title' => 'PFBuzz',
      'description' => t('Share this on !title'),
      'url' => 'http://pfbuzz.com/submit?url={PERMALINK}&title={TITLE}',
    ),
    'friendfeed' => array(
      'title' => 'FriendFeed',
      'description' => t('Share this on !title'),
      'url' => 'http://www.friendfeed.com/share?title={TITLE}&link={PERMALINK}',
    ),
    'blogmarks' => array(
      'title' => 'BlogMarks',
      'description' => t('Mark this on !title'),
      'url' => 'http://blogmarks.net/my/new.php?mini=1&simple=1&url={PERMALINK}&title={TITLE}',
    ),
    'twittley' => array(
      'title' => 'Twittley',
      'description' => t('Submit this to !title'),
      'url' => 'http://twittley.com/submit/?title={TITLE}&url={PERMALINK}&desc={POST_SUMMARY}&pcat={TWITT_CAT}&tags={DEFAULT_TAGS}',
      'settings' => array(
        'TWITT_CAT' => array(
          '#title' => t('Primary content category'),
          '#type' => 'select',
          '#options' => array(
            'Technology' => t('Technology'),
            'World &amp; Business' => t('World & Business'),
            'Science' => t('Science'),
            'Gaming' => t('Gaming'),
            'Lifestyle' => t('Lifestyle'),
            'Entertainment' => t('Entertainment'),
            'Sports' => t('Sports'),
            'Offbeat' => t('Offbeat'),
            'Internet' => t('Internet'),
          ),
        ),
        'DEFAULT_TAGS' => array(
          '#title' => t('Default tags'),
          '#type' => 'textfield',
          '#description' => t('Enter a comma separated list of general tags which describe your site\'s posts as a whole. Try not to be too specific, as one post may fall into different *tag categories* than other posts.')
        ),
      ),
    ),
    'fwisp' => array(
      'title' => 'Fwisp',
      'description' => t('Share this on !title'),
      'url' => 'http://fwisp.com/submit?url={PERMALINK}',
    ),
    'designmoo' => array(
      'title' => 'DesignMoo',
      'description' => t('Moo this on !title'),
      'url' => 'http://designmoo.com/submit?url={PERMALINK}&title=TITLE&body={POST_SUMMARY}',
    ),
    'bobrdobr' => array(
      'title' => 'BobrDobr',
      'description' => t('Share this on !title'),
      'url' => 'http://bobrdobr.ru/addext.html?url={PERMALINK}&title={TITLE}',
      'language' => t('Russian'),
    ),
    'yandex' => array(
      'title' => 'Yandex.Bookmarks',
      'description' => t('Add this to !title'),
      'url' => 'http://zakladki.yandex.ru/userarea/links/addfromfav.asp?bAddLink_x=1&lurl={PERMALINK}&lname={TITLE}',
      'language' => t('Russian'),
    ),
    'memoryru' => array(
      'title' => 'Memory.ru',
      'description' => t('Add this to !title'),
      'url' => 'http://memori.ru/link/?sm=1&u_data[url]={PERMALINK}&u_data[name]={TITLE}',
      'language' => t('Russian'),
    ),
    '100zakladok' => array(
      'title' => '100 bookmarks',
      'description' => t('Add this to !title'),
      'url' => 'http://www.100zakladok.ru/save/?bmurl={PERMALINK}&bmtitle={TITLE}',
      'language' => t('Russian'),
    ),
    'moemesto' => array(
      'title' => 'MyPlace',
      'description' => t('Add this to !title'),
      'url' => 'http://moemesto.ru/post.php?url={PERMALINK}&title={TITLE}',
      'language' => t('Russian'),
    ),
    'hackernews' => array(
      'title' => 'Hacker News',
      'description' => t('Submit this to !title'),
      'url' => 'http://news.ycombinator.com/submitlink?u={PERMALINK}&t={TITLE}',
    ),
    'printfriendly' => array(
      'title' => 'Print Friendly',
      'description' => t('Send this page to !title'),
      'url' => 'http://www.printfriendly.com/print?url={PERMALINK}',
    ),
    'designbump' => array(
      'title' => 'Design Bump',
      'description' => t('Bump this on !title'),
      'url' => 'http://designbump.com/submit?url={PERMALINK}&title={TITLE}&body={POST_SUMMARY}',
    ),
    'ning' => array(
      'title' => 'Ning',
      'description' => t('Add this to !title'),
      'url' => 'http://bookmarks.ning.com/addItem.php?url={PERMALINK}&T={TITLE}',
    ),
    'identica' => array(
      'title' => 'Identica',
      'description' => t('Post this to !title'),
      'url' => 'http://identi.ca//index.php?action=newnotice&status_textarea=Reading:+&quot;{SHORT_TITLE}&quot;+-+from+{FETCH_URL}',
    ),
    'xerpi' => array(
      'title' => 'Xerpi',
      'description' => t('Save this to !title'),
      'url' => 'http://www.xerpi.com/block/add_link_from_extension?url={PERMALINK}&title={TITLE}',
    ),
    'wikio' => array(
      'title' => 'Wikio',
      'description' => t('Share this on !title'),
      'url' => 'http://www.wikio.com/sharethis?url={PERMALINK}&title={TITLE}',
    ),
    'techmeme' => array(
      'title' => 'TechMeme',
      'description' => t('Tip this to !title'),
      'url' => 'http://twitter.com/home/?status=Tip+@Techmeme+{PERMALINK}+&quot;{TITLE}&quot;',
    ),
    'sphinn' => array(
      'title' => 'Sphinn',
      'description' => t('Sphinn this on !title'),
      'url' => 'http://sphinn.com/index.php?c=post&m=submit&link={PERMALINK}',
    ),
    'posterous' => array(
      'title' => 'Posterous',
      'description' => t('Post this to !title'),
      'url' => 'http://posterous.com/share?linkto={PERMALINK}&title={TITLE}&selection={POST_SUMMARY}',
    ),
    'globalgrind' => array(
      'title' => 'Global Grind',
      'description' => t('Grind this! on !title'),
      'url' => 'http://globalgrind.com/submission/submit.aspx?url={PERMALINK}&type=Article&title={TITLE}',
    ),
    'pingfm' => array(
      'title' => 'Ping.fm',
      'description' => t('Ping this on !title'),
      'url' => 'http://ping.fm/ref/?link={PERMALINK}&title={TITLE}&body={POST_SUMMARY}',
    ),
    'nujij' => array(
      'title' => 'NUjij',
      'description' => t('Submit this to !title'),
      'url' => 'http://nujij.nl/jij.lynkx?t={TITLE}&u={PERMALINK}&b={POST_SUMMARY}',
      'language' => t('Dutch'),
    ),
    'ekudos' => array(
      'title' => 'eKudos',
      'description' => t('Submit this to !title'),
      'url' => 'http://www.ekudos.nl/artikel/nieuw?url={PERMALINK}&title={TITLE}&desc={POST_SUMMARY}',
      'language' => t('Dutch'),
    ),
    'netvouz' => array(
      'title' => 'Netvouz',
      'description' => t('Submit this to !title'),
      'url' => 'http://www.netvouz.com/action/submitBookmark?url={PERMALINK}&title={TITLE}&popup=no',
    ),
    'netvibes' => array(
      'title' => 'Netvibes',
      'description' => t('Submit this to !title'),
      'url' => 'http://www.netvibes.com/share?title={TITLE}&url={PERMALINK}',
    ),
    'fleck' => array(
      'title' => 'Fleck',
      'description' => t('Share this on !title'),
      'url' => 'http://beta3.fleck.com/bookmarklet.php?url={PERMALINK}&title={TITLE}',
    ),
    'blogospherenews' => array(
      'title' => 'Blogosphere News',
      'description' => t('Share this on !title'),
      'url' => 'http://www.blogospherenews.com/submit.php?url={PERMALINK}&title={TITLE}',
    ),
    'webblend' => array(
      'title' => 'Web Blend',
      'description' => t('Blend this!'),
      'url' => 'http://thewebblend.com/submit?url={PERMALINK}&title={TITLE}&body={POST_SUMMARY}',
    ),
    'wykop' => array(
      'title' => 'Wykop',
      'description' => t('Add this to !title!'),
      'url' => 'http://www.wykop.pl/dodaj?url={PERMALINK}&title={TITLE}',
      'language' => t('Polish'),
    ),
    'blogengage' => array(
      'title' => 'BlogEngage',
      'description' => t('Engage with this article!'),
      'url' => 'http://www.blogengage.com/submit.php?url={PERMALINK}',
    ),
    'hyves' => array(
      'title' => 'Hyves',
      'description' => t('Share this on !title'),
      'url' => 'http://www.hyves.nl/profilemanage/add/tips/?name={TITLE}&text={POST_SUMMARY}+-+{PERMALINK}&rating=5',
    ),
    'pusha' => array(
      'title' => 'Pusha',
      'description' => t('Push this on !title'),
      'url' => 'http://www.pusha.se/posta?url={PERMALINK}&title={TITLE}',
      'language' => t('Swedish'),
    ),
    'hatena' => array(
      'title' => 'Hatena Bookmarks',
      'description' => t('Bookmarks this on !title'),
      'url' => 'http://b.hatena.ne.jp/add?mode=confirm&url={PERMALINK}&title={TITLE}',
      'language' => t('Japanese'),
    ),
    'mylinkvault' => array(
      'title' => 'MyLinkVault',
      'description' => t('Store this link on !title'),
      'url' => 'http://www.mylinkvault.com/link-page.php?u={PERMALINK}&n={TITLE}',
    ),
    'slashdot' => array(
      'title' => 'SlashDot',
      'description' => t('Submit this to !title'),
      'url' => 'http://slashdot.org/bookmark.pl?url={PERMALINK}&title={TITLE}',
    ),
    'squidoo' => array(
      'title' => 'Squidoo',
      'description' => t('Add to a lense on !title'),
      'url' => 'http://www.squidoo.com/lensmaster/bookmark?{PERMALINK}',
    ),
    'propeller' => array(
      'title' => 'Propeller',
      'description' => t('Submit this story to !title'),
      'url' => 'http://www.propeller.com/submit/?url={PERMALINK}',
    ),
    'faqpal' => array(
      'title' => 'FAQpal',
      'description' => t('Submit this to !title'),
      'url' => 'http://www.faqpal.com/submit?url={PERMALINK}',
    ),
    'evernote' => array(
      'title' => 'Evernote',
      'description' => t('Clip this to !title'),
      'url' => 'http://www.evernote.com/clip.action?url={PERMALINK}&title={TITLE}',
    ),
    'meneame' => array(
      'title' => 'Meneame',
      'description' => t('Submit this to !title'),
      'url' => 'http://meneame.net/submit.php?url={PERMALINK}',
      'language' => t('Spanish'),
    ),
    'bitacoras' => array(
      'title' => 'Bitacoras',
      'description' => t('Submit this to !title'),
      'url' => 'http://bitacoras.com/anotaciones/{PERMALINK}',
      'language' => t('Spanish'),
    ),
    'jumptags' => array(
      'title' => 'JumpTags',
      'description' => t('Submit this link to !title'),
      'url' => 'http://www.jumptags.com/add/?url={PERMALINK}&title={TITLE}',
    ),
    'bebo' => array(
      'title' => 'Bebo',
      'description' => t('Share this on !title'),
      'url' => 'http://www.bebo.com/c/share?Url={PERMALINK}&Title={TITLE}',
    ),
    'n4g' => array(
      'title' => 'N4G',
      'description' => t('Submit tip to !title'),
      'url' => 'http://www.n4g.com/tips.aspx?url={PERMALINK}&title={TITLE}',
    ),
    'strands' => array(
      'title' => 'Strands',
      'description' => t('Submit this to !title'),
      'url' => 'http://www.strands.com/tools/share/webpage?title={TITLE}&url={PERMALINK}',
    ),
    'orkut' => array(
      'title' => 'Orkut',
      'description' => t('Promote this on !title'),
      'url' => 'http://promote.orkut.com/preview?nt=orkut.com&tt={TITLE}&du={PERMALINK}&cn={POST_SUMMARY}',
    ),
    'tumblr' => array(
      'title' => 'Tumblr',
      'description' => t('Share this on !title'),
      'url' => 'http://www.tumblr.com/share?v=3&u={PERMALINK}&t={TITLE}',
    ),
    'stumpedia' => array(
      'title' => 'Stumpedia',
      'description' => t('Add this to !title'),
      'url' => 'http://www.stumpedia.com/submit?url={PERMALINK}&title={TITLE}',
    ),
    'current' => array(
      'title' => 'Current',
      'description' => t('Post this to !title'),
      'url' => 'http://current.com/clipper.htm?url={PERMALINK}&title={TITLE}',
    ),
    'blogger' => array(
      'title' => 'Blogger',
      'description' => t('Blog this on !title'),
      'url' => 'http://www.blogger.com/blog_this.pyra?t&u={PERMALINK}&n={TITLE}&pli=1',
    ),
    'plurk' => array(
      'title' => 'Plurk',
      'description' => t('Share this on !title'),
      'url' => 'http://www.plurk.com/m?content={TITLE}+-+{PERMALINK}&qualifier=shares',
    ),
    'dzone' => array(
      'title' => 'DZone',
      'description' => t('Add this to !title'),
      'url' => 'http://www.dzone.com/links/add.html?url={PERMALINK}&title={TITLE}&description={POST_SUMMARY}',
    ),
    'kaevur' => array(
      'title' => 'Kaevur',
      'description' => t('Share this on !title'),
      'url' => 'http://kaevur.com/submit.php?url={PERMALINK}',
      'language' => t('Estonian'),
    ),
    'virb' => array(
      'title' => 'Virb',
      'description' => t('Share this on !title'),
      'url' => 'http://virb.com/share?external&v=2&url={PERMALINK}&title={TITLE}',
    ),
    'boxnet' => array(
      'title' => 'Box.net',
      'description' => t('Add this link to !title'),
      'url' => 'https://www.box.net/api/1.0/import?url={PERMALINK}&name={TITLE}&description={POST_SUMMARY}&import_as=link',
    ),
    'oknotizie' => array(
      'title' => 'OkNotizie',
      'description' => t('Share this on !title'),
      'url' => 'http://oknotizie.virgilio.it/post?url={PERMALINK}&title={TITLE}',
      'language' => t('Italian'),
    ),
    'bonzobox' => array(
      'title' => 'BonzoBox',
      'description' => t('Add this to !title'),
      'url' => 'http://bonzobox.com/toolbar/add?pop=1&u={PERMALINK}&t={TITLE}&d={POST_SUMMARY}',
    ),
    'plaxo' => array(
      'title' => 'Plaxo',
      'description' => t('Share this on !title'),
      'url' => 'http://www.plaxo.com/?share_link={PERMALINK}',
    ),
    'springpad' => array(
      'title' => 'SpringPad',
      'description' => t('Spring this on !title'),
      'url' => 'http://springpadit.com/clip.action?body={POST_SUMMARY}&url={PERMALINK}&format=microclip&title={TITLE}&isSelected=true',
    ),
    'zabox' => array(
      'title' => 'Zabox',
      'description' => t('Box this on !title'),
      'url' => 'http://www.zabox.net/submit.php?url={PERMALINK}',
    ),
    'viadeo' => array(
      'title' => 'Viadeo',
      'description' => t('Share this on !title'),
      'url' => 'http://www.viadeo.com/shareit/share/?url={PERMALINK}&title={TITLE}&urlaffiliate=31138',
    ),
  );
}

/**
 * Implememnts hook_sexybackgrounds().
 */
function sexybookmarks_sexybackgrounds() {
  return array(
    'share-enjoy' => array(
      'padding' => '26px 0 0 10px',
    ),
    'share-german' => array(
      'padding' => '35px 0 0 20px',
    ),
    'share-knowledge' => array(
      'padding' => '35px 0 0 10px',
    ),
    'share-love-hearts' => array(
      'padding' => '26px 0 0 10px',
    ),
    'share-wealth' => array(
      'margin' => '0 0 0 15px',
      'padding' => '35px 0 0 20px',
    ),
    'sharing-caring' => array(
      'padding' => '26px 0 0 10px',
    ),
    'sharing-caring-hearts' => array(
      'padding' => '26px 0 0 10px',
    ),
    'sharing-sexy' => array(
      'padding' => '28px 0 0 10px',
    ),
  );
}
