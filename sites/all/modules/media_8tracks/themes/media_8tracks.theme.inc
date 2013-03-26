<?php
// $Id: media_8tracks.theme.inc,v 1.1.2.1 2010/10/04 22:58:49 aaron Exp $

/**
 * @file media_8tracks/themes/media_8tracks.theme.inc
 *
 * Theme preprocess functions.
 */

/**
 * Template preprocess function for theme('media_8tracks', $media, $options).
 */
function template_preprocess_media_8tracks(&$variables) {
  $variables['width'] = isset($options['width']) ? $options['width'] : media_8tracks_variable_get('width');
  $variables['height'] = isset($options['height']) ? $options['height'] : media_8tracks_variable_get('height');
}
