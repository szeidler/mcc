<?php

/**
 * Implements hook_entity_info().
 */
function mailchimp_campaign_entity_info() {
  $return = array(
    'mailchimp_campaign' => array(
      'label' => t('MailChimp Campaigns'),
      'controller class' => 'EntityAPIController',
      'base table' => 'mailchimp_campaign_node_campaigns',
      'uri callback' => 'mailchimp_campaign_uri',
      'fieldable' => FALSE,
      'entity keys' => array(
        'id' => 'cid',
        'label' => 'label',
      ),
    ),
  );
  return $return;
}

/**
 * Saves a campaign.
 */
function mailchimp_campaign_save($campaign) {
  return entity_get_controller('mailchimp_campaign')->save($campaign);
}

/**
 * Load a campaign by ID.
 */
function mailchimp_campaign_load($cid) {
  $campaign = mailchimp_campaign_load_multiple(array($cid));
  return $campaign ? $campaign[$cid] : FALSE;
}

/**
 * Loads multiple campaigns.
 */
function mailchimp_campaign_load_multiple($campaign_ids = array(), $conditions = array(), $reset = FALSE) {
  if (empty($campaign_ids)) {
    $campaign_ids = FALSE;
  }
  return entity_load('mailchimp_campaign', $campaign_ids, $conditions, $reset);
}
