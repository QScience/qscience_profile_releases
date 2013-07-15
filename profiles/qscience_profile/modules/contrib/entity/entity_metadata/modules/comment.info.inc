<?php
// $Id: comment.info.inc,v 1.1.2.1 2009/12/14 15:51:54 fago Exp $

/**
 * @file
 * Provides info about the comment entity.
 */

/**
 * Implements hook_entity_property_info() on top of comment module.
 * @see entity_metadata_entity_property_info()
 */
function entity_metadata_comment_entity_property_info() {
  $info = array();
  // Add meta-data about the basic comment properties.
  $properties = &$info['comment']['properties'];

  $properties['cid'] = array(
    'label' => t("Comment ID"),
    'type' => 'integer',
    'description' => t("The unique ID of the comment."),
  );
  $properties['pid'] = array(
    'label' => t("Parent ID"),
    'type' => 'integer',
    'description' => t("The unique ID of the comment's parent, if comment threading is active."),
  );
  $properties['nid'] = array(
    'label' => t("Node ID"),
    'type' => 'integer',
    'description' => t("The unique ID of the node the comment was posted to."),
  );
  $properties['uid'] = array(
    'label' => t("User ID"),
    'type' => 'integer',
    'description' => t("The unique ID of the user who posted the comment."),
  );
  $properties['hostname'] = array(
    'label' => t("IP Address"),
    'description' => t("The IP address of the computer the comment was posted from."),
  );
  $properties['name'] = array(
    'label' => t("Name"),
    'description' => t("The name left by the comment author."),
    'getter callback' => 'entity_metadata_comment_get_properties',
    'setter callback' => 'entity_metadata_verbatim_set',
    'sanitize' => 'filter_xss',
  );
  $properties['mail'] = array(
    'label' => t("Email address"),
    'description' => t("The email address left by the comment author."),
    'getter callback' => 'entity_metadata_comment_get_properties',
    'setter callback' => 'entity_metadata_verbatim_set',
  );
  $properties['homepage'] = array(
    'label' => t("Home page"),
    'description' => t("The home page URL left by the comment author."),
    'sanitize' => 'filter_xss_bad_protocol',
    'setter callback' => 'entity_metadata_verbatim_set',
  );
  $properties['title'] = array(
    'label' => t("Title"),
    'description' => t("The title of the comment."),
    'getter callback' => 'entity_metadata_comment_get_properties',
    'sanitize' => 'filter_xss',
  );
  $properties['body'] = array(
    'label' => t("Content"),
    'description' => t("The formatted content of the comment itself."),
    'getter callback' => 'entity_metadata_comment_get_properties',
    'raw getter callback' => 'entity_metadata_comment_get_raw',
    'setter callback' => 'entity_metadata_verbatim_set',
    'sanitized' => TRUE,
  );
  $properties['url'] = array(
    'label' => t("URL"),
    'description' => t("The URL of the comment."),
    'getter callback' => 'entity_metadata_comment_get_properties',
    'type' => 'uri',
  );
  $properties['edit-url'] = array(
    'label' => t("Edit URL"),
    'description' => t("The URL of the comment's edit page."),
    'getter callback' => 'entity_metadata_comment_get_properties',
    'type' => 'uri',
  );
  $properties['created'] = array(
    'label' => t("Date created"),
    'description' => t("The date the comment was posted."),
    'type' => 'date',
    'setter callback' => 'entity_metadata_verbatim_set',
  );
  $properties['parent'] = array(
    'label' => t("Parent"),
    'description' => t("The comment's parent, if comment threading is active."),
    'type' => 'comment',
    'getter callback' => 'entity_metadata_comment_get_properties',
  );
  $properties['node'] = array(
    'label' => t("Node"),
    'description' => t("The node the comment was posted to."),
    'type' => 'node',
    'getter callback' => 'entity_metadata_comment_get_properties',
  );
  $properties['author'] = array(
    'label' => t("Author"),
    'description' => t("The author of the comment, if they were logged in."),
    'type' => 'user',
    'getter callback' => 'entity_metadata_comment_get_properties',
  );
  return $info;
}

/**
 * Implements hook_entity_property_info_alter() on top of comment module.
 * @see entity_metadata_entity_property_info_alter()
 */
function entity_metadata_comment_entity_property_info_alter(&$info) {
  // Add info about comment module related properties to the node entity.
  $properties = &$info['node']['properties'];

  $properties['comment-count'] = array(
    'label' => t("Comment count"),
    'description' => t("The number of comments posted on a node."),
    'getter callback' => 'entity_metadata_comment_get_node_properties',
  );
  $properties['comment-count-new'] = array(
    'label' => t("New comment count"),
    'description' => t("The number of comments posted on a node since the reader last viewed it."),
    'getter callback' => 'entity_metadata_comment_get_node_properties',
  );
}