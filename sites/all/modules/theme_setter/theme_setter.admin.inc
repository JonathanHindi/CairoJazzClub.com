<?php

// $Id: theme_setter.admin.inc,v 1.1.2.1 2008/09/08 11:16:29 Stalski Exp $

/**
 * @file
 * Administrative page callbacks for the theme_setter module.
 */


/**
 * Generates the settings form for the theme_setter module.
 *
 * @param $node by reference
 * @return system_settings_form
 */
function theme_setter_form(&$node) { 
  $types = node_get_types();
  $content_types = array();
  foreach($types as $oType) {
    $content_types[$oType->type] = $oType->name;
  }  
  $roles = user_roles(true);
  
  $form['theme_setter_contenttypes_select'] = array(
    '#type' => 'checkboxes',
    '#options' => $content_types,
    '#title' => t('Select content-types for theme '. variable_get('theme_default', 'minnelli') .'.'),
    '#description' => t('Select the content-types where you want to override the admin theme (show frontend theme)'),
    '#default_value' => variable_get('theme_setter_contenttypes_select', array() ),
  );
  $form['theme_setter_role_select'] = array(
    '#type' => 'checkboxes',
    '#options' => $roles,
    '#title' => t('Choose roles for theme '. variable_get('theme_default', 'minnelli') .'.'),
    '#description' => t('Choose role to override the content-type setting and force the frontend theme.'),
    '#default_value' => variable_get('theme_setter_role_select', array() ),
  );
  $form['theme_setter_override'] = array(
    '#type' => 'checkbox',
    '#title' => t('Override the default content-type setting'),
    '#description' => t('Selecting this box will make sure the roles setting gets priority to the content-type setting. Please give it some thought.'),
    '#default_value' => variable_get('theme_setter_override', array() ),
  );
  return system_settings_form($form);
}

?>