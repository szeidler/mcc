<?php

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
    '#default_value' => $defaults ? $defaults['template_id'] : '1000188',
    '#description' => t('MailChimp template for the campaign. Leave blank to reset to defauts.'),
  );
  $form['mailchimp_campaign']['title_section'] = array(
    '#type' => 'textfield',
    '#title' => t('Title section'),
    '#default_value' => $defaults ? $defaults['title_section'] : 'header_content',
    '#description' => t('Title section in the template. Leave blank to reset to defauts.'),
  );
  $form['mailchimp_campaign']['body_section'] = array(
    '#type' => 'textfield',
    '#title' => t('Body section'),
    '#default_value' => $defaults ? $defaults['body_section'] : 'std_content00',
    '#description' => t('Body section in the template. Leave blank to reset to defauts.'),
  );
}
