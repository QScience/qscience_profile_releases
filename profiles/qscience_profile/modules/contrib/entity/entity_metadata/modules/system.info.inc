<?php
// $Id: system.info.inc,v 1.1.2.1 2009/12/14 15:51:54 fago Exp $

/**
 * @file
 * Provides info about system-wide entities.
 */

/**
 * Implements hook_entity_property_info() on top of system module.
 * @see entity_metadata_entity_property_info()
 * @see entity_metadata_entity_info_alter()
 */
function entity_metadata_system_entity_property_info() {
  $info = array();

  $properties = &$info['system']['properties'];
  $properties['name'] = array(
    'label' => t("Name"),
    'description' => t("The name of the site."),
    'getter callback' => 'entity_metadata_system_get_properties',
    'sanitize' => 'check_plain',
  );
  $properties['slogan'] = array(
    'label' => t("Slogan"),
    'description' => t("The slogan of the site."),
    'getter callback' => 'entity_metadata_system_get_properties',
    'sanitize' => 'check_plain',
  );
  $properties['mission'] = array(
    'label' => t("Mission"),
    'description' => t("The optional 'mission' of the site."),
    'getter callback' => 'entity_metadata_system_get_properties',
    'sanitize' => 'filter_xss',
  );
  $properties['mail'] = array(
    'label' => t("Email"),
    'description' => t("The administrative email address for the site."),
    'getter callback' => 'entity_metadata_system_get_properties',
  );
  $properties['url'] = array(
    'label' => t("URL"),
    'description' => t("The URL of the site's front page."),
    'getter callback' => 'entity_metadata_system_get_properties',
    'type' => 'uri',
  );
  $properties['login-url'] = array(
    'label' => t("Login page"),
    'description' => t("The URL of the site's login page."),
    'getter callback' => 'entity_metadata_system_get_properties',
    'type' => 'uri',
  );

  // Files.
  $properties = &$info['file']['properties'];
  $properties['fid'] = array(
    'label' => t("File ID"),
    'description' => t("The unique ID of the uploaded file."),
    'type' => 'integer',
  );
  $properties['uid'] = array(
    'label' => t("User ID"),
    'description' => t("The unique ID of the user who owns the file."),
    'type' => 'integer',
  );
  $properties['name'] = array(
    'label' => t("File name"),
    'description' => t("The name of the file on disk."),
    'getter callback' => 'entity_metadata_system_get_file_properties',
  );
  $properties['mime'] = array(
    'label' => t("MIME type"),
    'description' => t("The MIME type of the file."),
    'getter callback' => 'entity_metadata_system_get_file_properties',
    'sanitize' => 'filter_xss',
  );
  $properties['size'] = array(
    'label' => t("File size"),
    'description' => t("The size of the file, in kilobytes."),
    'getter callback' => 'entity_metadata_system_get_file_properties',
    'type' => 'integer',
  );
  $properties['url'] = array(
    'label' => t("URL"),
    'description' => t("The web-accessible URL for the file."),
    'getter callback' => 'entity_metadata_system_get_file_properties',
  );
  $properties['timestamp'] = array(
    'label' => t("Timestamp"),
    'description' => t("The date the file was most recently changed."),
    'type' => 'date',
  );
  $properties['owner'] = array(
    'label' => t("Owner"),
    'description' => t("The user who originally uploaded the file."),
    'type' => 'user',
    'getter callback' => 'entity_metadata_system_get_file_properties',
  );
  return $info;
}