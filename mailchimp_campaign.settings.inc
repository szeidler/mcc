<?php

/**
 * Define constants for MAilChimp template settings.
 *
 * A basic template ID and the MailChimp default sections.
 */
define('MAILCHIMP_CAMPAIGN_DEFAULT_TEMPLATE', '1000188');
define('MAILCHIMP_CAMPAIGN_DEFAULT_TITLE_SECTION', 'header_content');
define('MAILCHIMP_CAMPAIGN_DEFAULT_BODY_SECTION', 'std_content00');

/**
 * Return a form for campaign settings.
 */
function mailchimp_campaign_settings_form(&$form, $defaults) {
  $form['mailchimp_campaign']['list_id'] = array(
    '#type' => 'select',
    '#title' => t('MailChimp list'),
    '#default_value' => $defaults ? $defaults['list_id'] : FALSE,
    '#options' => _mailchimp_campaign_lists_options(),
  );
  $form['mailchimp_campaign']['from_name'] = array(
    '#type' => 'textfield',
    '#title' => t('From name'),
    '#default_value' => $defaults ? $defaults['from_name'] : variable_get('site_name', 'Drupal'),
  );
  $form['mailchimp_campaign']['from_email'] = array(
    '#type' => 'textfield',
    '#title' => t('From email'),
    '#default_value' => $defaults ? $defaults['from_email'] : variable_get('site_mail', FALSE),
  );
  $form['mailchimp_campaign']['template_id'] = array(
    '#type' => 'textfield',
    '#title' => t('Template ID'),
    '#default_value' => $defaults ? $defaults['template_id'] : MAILCHIMP_CAMPAIGN_DEFAULT_TEMPLATE,
    '#description' => t('MailChimp template for the campaign. Leave blank to reset to defauts.'),
  );
  $form['mailchimp_campaign']['title_section'] = array(
    '#type' => 'textfield',
    '#title' => t('Title section'),
    '#default_value' => $defaults ? $defaults['title_section'] : MAILCHIMP_CAMPAIGN_DEFAULT_TITLE_SECTION,
    '#description' => t('Title section in the template. Leave blank to reset to defauts.'),
  );
  $form['mailchimp_campaign']['body_section'] = array(
    '#type' => 'textfield',
    '#title' => t('Body section'),
    '#default_value' => $defaults ? $defaults['body_section'] : MAILCHIMP_CAMPAIGN_DEFAULT_BODY_SECTION,
    '#description' => t('Body section in the template. Leave blank to reset to defauts.'),
  );
}
