<?php

/**
 * @file
 * Form and form validation for campaign settings.
 */

/**
 * Define constants for MAilChimp template settings.
 *
 * A basic template ID and the MailChimp default sections.
 */
define('MCC_DEFAULT_TEMPLATE', '1000188');
define('MCC_DEFAULT_TITLE_SECTION', 'header_content');
define('MCC_DEFAULT_BODY_SECTION', 'std_content00');

/**
 * Return a form for general campaign settings.
 */
function mcc_settings_form(&$form, $defaults) {
  $form['mcc']['list_id'] = array(
    '#type' => 'select',
    '#title' => t('MailChimp list'),
    '#default_value' => $defaults ? $defaults['list_id'] : -1,
    '#options' => _mcc_lists_options(),
    '#required' => TRUE,
  );
  $form['mcc']['from_name'] = array(
    '#type' => 'textfield',
    '#title' => t('From name'),
    '#default_value' => $defaults ? $defaults['from_name'] : variable_get('site_name', 'Drupal'),
  );
  $form['mcc']['from_email'] = array(
    '#type' => 'textfield',
    '#title' => t('From email'),
    '#default_value' => $defaults ? $defaults['from_email'] : variable_get('site_mail', FALSE),
  );
  $form['mcc']['test_recipient_email'] = array(
    '#type' => 'textfield',
    '#title' => t('Test email address'),
    '#description' => t('Email address for campaign testing'),
    '#default_value' => $defaults ? $defaults['test_recipient_email'] : variable_get('site_mail', FALSE),
  );
  $form['mcc']['template_id'] = array(
    '#type' => 'textfield',
    '#title' => t('Template ID'),
    '#default_value' => $defaults ? $defaults['template_id'] : MCC_DEFAULT_TEMPLATE,
    '#description' => t('MailChimp template for the campaign. Leave blank to reset to defaults.'),
  );
  $form['mcc']['title_section'] = array(
    '#type' => 'textfield',
    '#title' => t('Title section'),
    '#default_value' => $defaults ? $defaults['title_section'] : MCC_DEFAULT_TITLE_SECTION,
    '#description' => t('Title section in the template. Leave blank to reset to defaults.'),
  );
  $form['mcc']['body_section'] = array(
    '#type' => 'textfield',
    '#title' => t('Body section'),
    '#default_value' => $defaults ? $defaults['body_section'] : MCC_DEFAULT_BODY_SECTION,
    '#description' => t('Body section in the template. Leave blank to reset to defaults.'),
  );
  $form['mcc']['use_conversation'] = array(
    '#type' => 'checkbox',
    '#title' => t('Use MailChimp Conversation feature to manage out-of-office replies'),
    '#default_value' => $defaults ? $defaults['use_conversation'] : FALSE,
  );
  $form['mcc']['authenticate'] = array(
    '#type' => 'checkbox',
    '#title' => t('Authenticate campaign'),
    '#default_value' => $defaults ? $defaults['authenticate'] : FALSE,
  );
  $form['mcc']['auto_footer'] = array(
    '#type' => 'checkbox',
    '#title' => t('Automatically append MailChimp’s default footer to the campaign'),
    '#default_value' => $defaults ? $defaults['auto_footer'] : FALSE,
  );
  $form['mcc']['inline_css'] = array(
    '#type' => 'checkbox',
    '#title' => t('Automatically inline the CSS included with the campaign content'),
    '#default_value' => $defaults ? $defaults['inline_css'] : FALSE,
  );
  $form['mcc']['auto_tweet'] = array(
    '#type' => 'checkbox',
    '#title' => t('Automatically tweet a link to the campaign archive page when the campaign is sent'),
    '#default_value' => $defaults ? $defaults['auto_tweet'] : FALSE,
  );
}

/**
 * Validate general campaign settings form.
 */
function mcc_settings_form_validate($form, &$form_state) {
  if (isset($form_state['defaults'])) {
    $defaults = $form_state['defaults'];
  }
  else {
    $defaults = FALSE;
  }
  $values = $form_state['values']['mcc'];

  if ($values['from_name'] == '') {
    $form_state['values']['mcc']['from_name'] = $defaults ? $defaults['from_name'] : variable_get('site_name', 'Drupal');
  }

  if ($values['from_email'] == '') {
    $form_state['values']['mcc']['from_email'] = $defaults ? $defaults['from_email'] : variable_get('site_mail', FALSE);
  }
  elseif (!valid_email_address($values['from_email'])) {
    form_set_error('mcc][from_email', t('From email is not valid.'));
  }

  if ($values['test_recipient_email'] == '') {
    $form_state['values']['mcc']['test_recipient_email'] = $defaults ? $defaults['test_recipient_email'] : variable_get('site_mail', FALSE);
  }
  elseif (!valid_email_address($values['test_recipient_email'])) {
    form_set_error('mcc][test_recipient_email', t('Test email address is not valid.'));
  }

  if ($values['template_id'] == '') {
    $form_state['values']['mcc']['template_id'] = $defaults ? $defaults['template_id'] : MCC_DEFAULT_TEMPLATE;
  }
  elseif (!is_numeric($values['template_id'])) {
    form_set_error('mcc][template_id', t('Template ID must be numeric.'));
  }

  if ($values['title_section'] == '') {
    $form_state['values']['mcc']['title_section'] = $defaults ? $defaults['title_section'] : MCC_DEFAULT_TITLE_SECTION;
  }
  elseif (!preg_match('/^[a-zA-Z0-9_]*$/', $values['title_section'])) {
    form_set_error('mcc][title_section', t('Not valid title section.'));
  }

  if ($values['body_section'] == '') {
    $form_state['values']['mcc']['body_section'] = $defaults ? $defaults['body_section'] : MCC_DEFAULT_BODY_SECTION;
  }
  elseif (!preg_match('/^[a-zA-Z0-9_]*$/', $values['body_section'])) {
    form_set_error('mcc][body_section', t('Not valid body section.'));
  }
}
