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
        'id' => 'id',
      ),
    ),
  );
  return $return;
}
