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

/**
 * Loads campaigns attached to specific nodes.
 */
function mailchimp_campaign_load_by_nid($nid, $vid = FALSE) {
  $query = new EntityFieldQuery();
  $entities = $query->entityCondition('entity_type', 'mailchimp_campaign')
    ->propertyCondition('nid', $nid);

  if ($vid) {
    $entities = $entities->propertyCondition('vid', $vid);
  }

  $entities = $entities->propertyOrderBy('update_time', 'DESC')
    ->execute();

  foreach ($entities['mailchimp_campaign'] as $entity) {
    $campaign_ids[] = $entity->cid;
  }
  return mailchimp_campaign_load_multiple($campaign_ids);
}

/**
 * Delete a campaign.
 */
function mailchimp_campaign_delete($cid) {
  return mailchimp_campaign_delete_multiple(array($cid));
}

/**
 * Delete multiple campaigns.
 */
function mailchimp_campaign_delete_multiple($campaign_ids) {
  return entity_get_controller('mailchimp_campaign')->delete($campaign_ids);
}
