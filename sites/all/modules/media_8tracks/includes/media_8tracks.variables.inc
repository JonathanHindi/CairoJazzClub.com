<?php
// $Id: media_8tracks.variables.inc,v 1.1.2.1 2010/10/04 22:58:49 aaron Exp $

/**
 * @file media_8tracks/includes/media_8tracks.variables.inc
 * Contains the variables and defaults used by Media: 8Tracks.
 */

/**
 * The variable namespace for Media: 8Tracks.
 */
define('MEDIA_8TRACKS_NAMESPACE', 'media_8tracks__');

/**
 * This is the main URL for 8Tracks.
 */
define('MEDIA_8TRACKS_MAIN_URL', 'http://www.8tracks.com/');

/**
 * This is the URL to the API of 8Tracks.
 */
define('MEDIA_8TRACKS_API_INFO', 'http://docs.google.com/Doc?id=dg9292rd_8dxfvfjgp');

/**
 * This defines the version of the content data array that we serialize
 * in data(). If we change the expected keys of that array,
 * we must increment this value, which will allow older content to be updated
 * to the new version automatically.
 */
define('MEDIA_8TRACKS_DATA_VERSION', 2);

/**
 * Wrapper for variable_get() that uses the Media: 8Tracks variable registry.
 *
 * @param string $name
 *  The variable name to retrieve. Note that it will be namespaced by
 *  pre-pending MEDIA_8TRACKS_NAMESPACE, as to avoid variable collisions
 *  with other modules.
 * @param unknown $default
 *  An optional default variable to return if the variable hasn't been set
 *  yet. Note that within this module, all variables should already be set
 *  in the media_8tracks_variable_default() function.
 * @return unknown
 *  Returns the stored variable or its default.
 *
 * @see media_8tracks_variable_set()
 * @see media_8tracks_variable_del()
 * @see media_8tracks_variable_default()
 */
function media_8tracks_variable_get($name, $default = NULL) {
  // Allow for an override of the default.
  // Useful when a variable is required (like $path), but namespacing still desired.
  if (!isset($default)) {
    $default = media_8tracks_variable_default($name);
  }
  // Namespace all variables
  $variable_name = MEDIA_8TRACKS_NAMESPACE . $name;
  return variable_get($variable_name, $default);
}

/**
 * Wrapper for variable_set() that uses the Media: 8Tracks variable registry.
 *
 * @param string $name
 *  The variable name to set. Note that it will be namespaced by
 *  pre-pending MEDIA_8TRACKS_NAMESPACE, as to avoid variable collisions with
 *  other modules.
 * @param unknown $value
 *  The value for which to set the variable.
 * @return unknown
 *  Returns the stored variable after setting.
 *
 * @see media_8tracks_variable_get()
 * @see media_8tracks_variable_del()
 * @see media_8tracks_variable_default()
 */
function media_8tracks_variable_set($name, $value) {
  $variable_name = MEDIA_8TRACKS_NAMESPACE . $name;
  return variable_set($variable_name, $value);
}

/**
 * Wrapper for variable_del() that uses the Media: 8Tracks variable registry.
 *
 * @param string $name
 *  The variable name to delete. Note that it will be namespaced by
 *  pre-pending MEDIA_8TRACKS_NAMESPACE, as to avoid variable collisions with
 *  other modules.
 *
 * @see media_8tracks_variable_get()
 * @see media_8tracks_variable_set()
 * @see media_8tracks_variable_default()
 */
function media_8tracks_variable_del($name) {
  $variable_name = MEDIA_8TRACKS_NAMESPACE . $name;
  variable_del($variable_name);
}

/**
 * The default variables within the Media: 8Tracks namespace.
 *
 * @param string $name
 *  Optional variable name to retrieve the default. Note that it has not yet
 *  been pre-pended with the MEDIA_8TRACKS_NAMESPACE namespace at this time.
 * @return unknown
 *  The default value of this variable, if it's been set, or NULL, unless
 *  $name is NULL, in which case we return an array of all default values.
 *
 * @see media_8tracks_variable_get()
 * @see media_8tracks_variable_set()
 * @see media_8tracks_variable_del()
 */
function media_8tracks_variable_default($name = NULL) {
  static $defaults;

  if (!isset($defaults)) {
    $defaults = array(
      'width' => 300,
      'height' => 250,
    );
  }

  if (!isset($name)) {
    return $defaults;
  }

  if (isset($defaults[$name])) {
    return $defaults[$name];
  }
}

/**
 * Return the fully namespaced variable name.
 *
 * @param string $name
 *  The variable name to retrieve the namespaced name.
 * @return string
 *  The fully namespace variable name, prepended with
 *  MEDIA_8TRACKS_NAMESPACE.
 */
function media_8tracks_variable_name($name) {
  return MEDIA_8TRACKS_NAMESPACE . $name;
}
