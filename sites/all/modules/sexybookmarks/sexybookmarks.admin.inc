<?php
// $Id: sexybookmarks.admin.inc,v 1.3 2010/04/07 10:31:22 deciphered Exp $
/**
 * @file
 * Contains core functions for the SexyBookmarks module.
 */

function sexybookmarks_admin($form_state) {
  $form = array('#tree' => TRUE);
  $settings = _sexybookmarks_get_settings();
  $bookmarks = module_invoke_all('sexybookmarks');

  // Flush cached CSS.
  if (empty($settings) || count(array_diff(array_keys($bookmarks), array_keys($settings['bookmarks']))) > 0) {
    file_delete(file_directory_path() . '/css/sexybookmarks.admin.css');
  }

  // Bookmark settings.
  $links = array(
    l(t('All'), 'admin/settings/sexybookmarks', array('fragment' => 'sel-all', 'attributes' => array('id' => 'sel-all'))),
    l(t('None'), 'admin/settings/sexybookmarks', array('fragment' => 'sel-none', 'attributes' => array('id' => 'sel-none'))),
    l(t('Most Popular'), 'admin/settings/sexybookmarks', array('fragment' => 'sel-pop', 'attributes' => array('id' => 'sel-pop'))),
  );
  $form['bookmarks'] = array(
    '#type' => 'fieldset',
    '#title' => t('Enabled Networks'),
    '#description' => '<div class="links"><strong>' . t('Select') . ':</strong> ' . implode(' | ', $links) . '</div>' . t('Select the Networks to display. Drag to reorder.'),
    '#attributes' => array(
      'id' => 'sexybookmarks'
    ),
  );

  ksort($bookmarks);
  foreach ($bookmarks as $key => $bookmark) {
    $icon = isset($bookmark['icon']) ? $bookmark['icon']
      : drupal_get_path('module', 'sexybookmarks') . '/images/icons/' . $key . '.png';
    if (file_exists($icon)) {
      $form['bookmarks'][$key] = array(
        '#type' => 'checkbox',
        '#title' => $bookmark['title'],
        '#default_value' => isset($settings['bookmarks'][$key]) ? $settings['bookmarks'][$key] : 0,
      );
      if (isset($bookmark['language'])) {
        $form['language'][$key] = array(
          '#type' => 'hidden',
          '#value' => $bookmark['language'],
        );
      }
    }
  }

  // Bookmark sorting.
  if (!empty($settings)) {
    $sorted_bookmarks = array();
    foreach ($settings['bookmarks'] as $key => $value) {
      $sorted_bookmarks[$key] = $form['bookmarks'][$key];
      unset($form['bookmarks'][$key]);
    }
    $form['bookmarks'] = array_merge($sorted_bookmarks, $form['bookmarks']);
  }
  $form['sort'] = array(
    '#type' => 'hidden',
    '#title' => 'sort',
  );

  // Backgrounds settings.
  $form['backgrounds'] = array(
    '#type' => 'fieldset',
    '#title' => t('Background image options'),
    '#attributes' => array(
      'id' => 'sexybackgrounds'
    ),
  );
  $backgrounds = module_invoke_all('sexybackgrounds');
  ksort($backgrounds);
  foreach ($backgrounds as $key => $background) {
    $background = isset($background['file']) ? $background['file']
      : drupal_get_path('module', 'sexybookmarks') . '/images/backgrounds/' . $key . '.png';
    $backgrounds[$key] = theme('image', $background);
    if (!file_exists($background)) {
      unset($backgrounds[$key]);
    }
  }
  $form['backgrounds']['enabled'] = array(
    '#type' => 'checkbox',
    '#title' => t('Use a background image'),
    '#default_value' => isset($settings['background']['enabled']) ? $settings['background']['enabled'] : 0,
  );
  $form['backgrounds']['background'] = array(
    '#type' => 'radios',
    '#options' => $backgrounds,
    '#default_value' => isset($settings['background']['background']) ? $settings['background']['background'] : 'sharing-sexy',
  );

  // Menu placement settings.
  $form['display'] = array(
    '#type' => 'fieldset',
    '#title' => t('Menu placement'),
  );
  $form['display']['types'] = array(
    '#type' => 'checkboxes',
    '#title' => t('Content types'),
    '#options' => node_get_types('names'),
    '#default_value' => isset($settings['display']['types']) ? $settings['display']['types'] : array(),
  );
  $form['display']['location'] = array(
    '#type' => 'checkboxes',
    '#title' => t('Menu location (in relation to content)'),
    '#options' => array(
      'above' => t('Above content'),
      'below' => t('Below content'),
    ),
    '#default_value' => isset($settings['display']['location']) ? $settings['display']['location'] : array('below' => TRUE),
    '#attributes' => array(
      'class' => 'container-inline'
    ),
  );
  $form['display']['node'] = array(
    '#type' => 'select',
    '#title' => t('Display in nodes'),
    '#options' => array(
      t('Teaser view'),
      t('Full-page view'),
      t('Teaser and full-page view'),
    ),
    '#default_value' => isset($settings['display']['node']) ? $settings['display']['node'] : 0,
  );

  // General functionality options.
  $form['general'] = array(
    '#type' => 'fieldset',
    '#title' => t('General options'),
  );
  $form['general']['nofollow'] = array(
    '#type' => 'radios',
    '#title' => t('Add nofollow to the links'),
    '#options' => array(
      1 => t('Yes'),
      0 => t('No'),
    ),
    '#default_value' => isset($settings['general']['nofollow']) ? $settings['general']['nofollow'] : 1,
    '#attributes' => array(
      'class' => 'container-inline'
    ),
  );
  $form['general']['window'] = array(
    '#type' => 'radios',
    '#title' => t('Open links in new window'),
    '#options' => array(
      1 => t('Yes'),
      0 => t('No'),
    ),
    '#default_value' => isset($settings['general']['window']) ? $settings['general']['window'] : 1,
    '#attributes' => array(
      'class' => 'container-inline'
    ),
  );
  $form['general']['expand'] = array(
    '#type' => 'radios',
    '#title' => t('Animate-expand multi-lined bookmarks'),
    '#options' => array(
      1 => t('Yes'),
      0 => t('No'),
    ),
    '#default_value' => isset($settings['general']['expand']) ? $settings['general']['expand'] : 1,
    '#attributes' => array(
      'class' => 'container-inline'
    ),
  );

  // Additional settings.
  $form['extra'] = array(
    '#type' => 'fieldset',
    '#title' => t('Additional settings'),
  );
  foreach ($bookmarks as $id => $bookmark) {
    if (isset($bookmark['settings'])) {
      $form['extra'][$id] = array(
        '#type' => 'fieldset',
        '#title' => t('!title settings', array('!title' => $bookmark['title'])),
      );
      foreach ($bookmark['settings'] as $key => $setting) {
        $form['extra'][$id][strtolower($key)] = array_merge(
          $setting, array(
            '#default_value' => isset($settings['extra'][$id][strtolower($key)]) ? $settings['extra'][$id][strtolower($key)] : '',
          )
        );
      }
    }
  }

  // Buttons.
  $form['submit'] = array(
    '#type' => 'submit',
    '#value' => t('Save changes'),
  );

  return $form;
}

function theme_sexybookmarks_admin($form) {
  // Add CSS.
  _sexybookmarks_add_css(file_directory_path() . '/css/sexybookmarks.admin.css');

  // Add JavaScript.
  jquery_ui_add(array('ui.sortable'));
  drupal_add_js(drupal_get_path('module', 'sexybookmarks') . '/js/sexybookmarks.admin.js');

  // Modify bookmarks.
  $search = $replace = array();
  foreach (element_children($form['bookmarks']) as $key) {
    $search[] = 'for="edit-bookmarks-' . $key . '"';
    $replace[] = 'for="edit-bookmarks-' . $key . '" title="' . t('Check this box to include !title in your bookmarking menu!language', array(
      '!title' => $form['bookmarks'][$key]['#title'],
      '!language' => isset($form['language'][$key]) ? ' (' . $form['language'][$key]['#value'] . ')' : ''
    )) . '"';
    $form['bookmarks'][$key]['#title'] = '';
  }

  // SexyBookmarks logo.
  $output = theme('image', drupal_get_path('module', 'sexybookmarks') . '/images/sexy-logo.png');

  $output .= drupal_render($form);
  $output = str_replace($search, $replace, $output);

  return $output;
}

function sexybookmarks_admin_submit($form, &$form_state) {
  // Sort bookmarks.
  if (!empty($form_state['values']['sort'])) {
    $sort = explode(',', preg_replace('/edit-bookmarks-(.*?)-wrapper/', '\\1', $form_state['values']['sort'], -1));
    $sorted_bookmarks = array();
    foreach ($sort as $key) {
      $sorted_bookmarks[$key] = $form_state['values']['bookmarks'][$key];
    }
    $form_state['values']['bookmarks'] = $sorted_bookmarks;
    unset($form_state['values']['sort']);
  }

  // Save settings.
  drupal_set_message(t('Your changes have been saved successfully!'));
  variable_set('sexybookmarks', serialize(array(
    'background' => $form_state['values']['backgrounds'],
    'bookmarks' => $form_state['values']['bookmarks'],
    'display' => $form_state['values']['display'],
    'general' => $form_state['values']['general'],
    'extra' => $form_state['values']['extra'],
  )));

  // Delete cached CSS.
  file_delete(file_directory_path() . '/css/sexybookmarks.css');
}
