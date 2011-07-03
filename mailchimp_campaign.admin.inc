<?php

/**
 * Returns sitewide campaign settings form.
 */
function mailchimp_campaign_admin_form($form, &$form_state) {
  module_load_include('inc', 'mailchimp_campaign', 'mailchimp_campaign.settings');
  $defaults = variable_get('mailchimp_campaign', FALSE);
  $form = array();
  $form['mailchimp_campaign'] = array(
    '#type' => 'fieldset',
    '#title' => t('Sitewide default MailChimp campaign settings'),
    '#tree' => TRUE,
    '#description' => t('This setting are the defaults for every node types. Leaving blank this filds will reset the hardcoded MailChimp defaults.'),
  );
  mailchimp_campaign_settings_form(&$form, $defaults);
  $form['#validate'][] = 'mailchimp_campaign_settings_form_validate';

  return system_settings_form($form);
}
