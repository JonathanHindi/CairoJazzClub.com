<?php
// $Id: media-8tracks.tpl.php,v 1.1.2.1 2010/10/04 22:58:49 aaron Exp $

/**
 * @file media_8tracks/themes/media-8tracks.tpl.php
 *
 * Template file for theme('media_8tracks', $media, $options).
 */

?>
<object classid="clsid:D27CDB6E-AE6D-11cf-96B8-444553540000" codebase="http://download.macromedia.com/pub/shockwave/cabs/flash/swflash.cab#version=9,0,28,0" width="<?php print $width; ?>" height="<?php print $height; ?>"><param name="movie" value="http://8tracks.com/mixes/<?php print $media; ?>/player_v3"><param name="allowscriptaccess" value="always"><embed src="http://8tracks.com/mixes/<?php print $media; ?>/player_v3" pluginspage="http://www.adobe.com/shockwave/download/download.cgi?P1_Prod_Version=ShockwaveFlash" type="application/x-shockwave-flash" width="<?php print $width; ?>" height="<?php print $height; ?>" allowscriptaccess="always" ></embed></object>
