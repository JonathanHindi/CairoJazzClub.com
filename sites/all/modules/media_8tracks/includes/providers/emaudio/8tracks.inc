<?php
// $Id: 8tracks.inc,v 1.1.2.2 2010/10/04 23:17:35 aaron Exp $

/**
 * @file
 *  This is an 8tracks provider include file for Embedded Media Video.
 *  Use this as a base for creating new provider files.
 *
 *  When using this, first make the following global replacements:
 *    * Replace 8TRACKS with the name of your provider in all caps.
 *    * Replace 8tracks with the name of your provider in all lower case.
 *    * Replace 8Tracks with the name (to be translated) of your provider in
 *        uppercase.
 *
 *  You then need to go through each function and modify according to the
 *  requirements of your provider's API.
 */

/**
 * hook emaudio_PROVIDER_info
 * This returns information relevant to a specific 3rd party audio provider.
 *
 * @return
 *   A keyed array of strings requested by various admin and other forms.
 *    'provider' => The machine name of the provider. This must be the same as
 *      the base name of this filename, before the .inc extension.
 *    'name' => The translated name of the provider.
 *    'url' => The url to the main page for the provider.
 *    'settings_description' => A description of the provider that will be
 *      posted in the admin settings form.
 *    'supported_features' => An array of rows describing the state of certain
 *      supported features by the provider. These will be rendered in a table,
 *      with the columns being 'Feature', 'Supported', 'Notes'. In general,
 *      the 'Feature' column will give the name of the feature, 'Supported'
 *      will be Yes or No, and 'Notes' will give an optional description or
 *      caveats to the feature.
 */
function emaudio_8tracks_info() {
  $features = array(
    array(t('Autoplay'), t('No'), ''),
    array(t('RSS Attachment'), t('No'), ''),
    array(t('Thumbnails'), t('No'), t('')),
  );
  return array(
    'provider' => '8tracks',
    'name' => t('8Tracks'),
    'url' => MEDIA_8TRACKS_MAIN_URL,
    'settings_description' => t('These settings specifically affect audios displayed from !8tracks. You can also read more about its !api.', array('!8tracks' => l(t('8Tracks.com'), MEDIA_8TRACKS_MAIN_URL), '!api' => l(t("developer's API"), MEDIA_8TRACKS_API_URL))),
    'supported_features' => $features,
  );
}

/**
 *  hook emaudio_PROVIDER_settings
 *  This should return a subform to be added to the emaudio_settings() admin
 *  settings page.
 *
 *  Note that a form field set will already be provided at $form['8tracks'],
 *  so if you want specific provider settings within that field set, you should
 *  add the elements to that form array element.
 */
function emaudio_8tracks_settings() {
  // We'll add a field set of player options here. You may add other options
  // to this element, or remove the field set entirely if there are no
  // user-configurable options allowed by the 8tracks provider.
  module_load_include('inc', 'media_8tracks', 'includes/media_8tracks.admin');
  return media_8tracks_admin_form();
}

/**
 *  hook emaudio_PROVIDER_extract
 *
 *  This is called to extract the audio code from a pasted URL or embed code.
 *
 *  We'll be passed a URL or the embed code from a audio when an editor pastes
 *  that in the field's textfield. We'll need to either pass back an array of
 *  regex expressions to match, or do the matching ourselves and return the
 *  resulting audio code.
 *
 *  @param $parse
 *    An optional string with the pasted URL or embed code.
 *  @return
 *    Either an array of regex expressions to be tested, or a string with the
 *    audio code to be used. If the hook tests the code itself, it should
 *    return either the string of the audio code (if matched), or an empty
 *    array. Otherwise, the calling function will handle testing the embed code
 *    against each regex string in the returned array.
 */
function emaudio_8tracks_extract($parse = '') {
  if (preg_match('@8tracks\.com/(.+)/player_v2"@i', $parse, $matches)) {
    return $matches[1];
  }

  if (preg_match('@8tracks\.com/(.+)@i', $parse, $matches)) {
    $data = emfield_request_xml('8tracks', 'http://8tracks.com/'. $matches[1] .'.xml', array(), TRUE, FALSE, $matches[1]);
    if ($data['MIX'] && $data['MIX']['ID'][0]) {
      return $data['MIX']['ID'][0];
    }
  }
  return array();
}

/**
 *  Implement hook emaudio_PROVIDER_data_version().
 */
function emaudio_8tracks_data_version() {
  return MEDIA_8TRACKS_DATA_VERSION;
}

/**
 *  hook emaudio_PROVIDER_data
 *
 *  Provides an array to be serialised and made available with $item elsewhere.
 *
 *  This data can be used to store any extraneous information available
 *  specifically to the 8tracks provider.
 */
function emaudio_8tracks_data($field, $item) {
  return media_8tracks_metadata($item['value']);
}

/**
 *  hook emaudio_PROVIDER_rss
 *
 *  This attaches a file to an RSS feed.
 */
function emaudio_8tracks_rss($item, $teaser = NULL) {
}

/**
 * hook emaudio_PROVIDER_embedded_link($audio_code)
 * returns a link to view the audio at the provider's site.
 *  @param $code
 *    The string containing the audio code.
 *  @return
 *    A string containing the URL to view the audio at the original provider's site.
 */
function emaudio_8tracks_embedded_link($code) {
  return 'http://www.8tracks.com/'. $code;
}

/**
 * hook emaudio_PROVIDER_thumbnail
 * Returns the external url for a thumbnail of a specific audio.
 *  @param $field
 *    The field of the requesting node.
 *  @param $item
 *    The actual content of the field from the requesting node.
 *  @return
 *    A URL pointing to the thumbnail.
 */
function emaudio_8tracks_thumbnail($field, $item, $formatter, $node, $width, $height, $options = array()) {
  // In this demonstration, we previously retrieved a thumbnail using oEmbed
  // during the data hook.

  return media_8tracks_thumbnail($item['value']);
}

/**
 *  hook emaudio_PROVIDER_audio
 *  This actually displays the full/normal-sized audio we want, usually on the
 *  default page view.
 *  @param $code
 *    The audio code for the audio to embed.
 *  @param $width
 *    The width to display the audio.
 *  @param $height
 *    The height to display the audio.
 *  @param $field
 *    The field info from the requesting node.
 *  @param $item
 *    The actual content from the field.
 *  @return
 *    The html of the embedded audio.
 */
function emaudio_8tracks_audio($embed, $width, $height, $field, $item, &$node, $autoplay, $options = array()) {
  $options['width'] = isset($options['width']) ? $options['width'] : $width;
  $options['height'] = isset($options['height']) ? $options['height'] : $height;
  $options['field'] = isset($options['field']) ? $options['field'] : $field;
  $options['item'] = isset($options['item']) ? $options['item'] : $item;
  $options['node'] = isset($options['node']) ? $options['node'] : $node;
  $options['autoplay'] = isset($options['autoplay']) ? $options['autoplay'] : $autoplay;
  $output = theme('media_8tracks', $embed, $options);
  return $output;
}

/**
 *  hook emaudio_PROVIDER_audio
 *
 *  This actually displays the preview-sized audio we want, commonly for the
 *  teaser.
 *  @param $embed
 *    The audio code for the audio to embed.
 *  @param $width
 *    The width to display the audio.
 *  @param $height
 *    The height to display the audio.
 *  @param $field
 *    The field info from the requesting node.
 *  @param $item
 *    The actual content from the field.
 *  @return
 *    The html of the embedded audio.
 */
function emaudio_8tracks_preview($embed, $width, $height, $field, $item, &$node, $autoplay, $options = array()) {
  $options['width'] = isset($options['width']) ? $options['width'] : $width;
  $options['height'] = isset($options['height']) ? $options['height'] : $height;
  $options['field'] = isset($options['field']) ? $options['field'] : $field;
  $options['item'] = isset($options['item']) ? $options['item'] : $item;
  $options['node'] = isset($options['node']) ? $options['node'] : $node;
  $options['autoplay'] = isset($options['autoplay']) ? $options['autoplay'] : $autoplay;
  $output = theme('media_8tracks', $embed, $options);
  return $output;
}
