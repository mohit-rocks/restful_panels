<?php

/**
 * @file
 * Contains \Drupal\restful_panels\Plugin\resource\Panels_display__1_0.
 */

namespace Drupal\restful_panels\Plugin\resource;
use Drupal\restful\Plugin\resource\Resource;

/**
 * @package Drupal\restful_panels\Plugin\resource
 *
 * @Resource(
 *   name = "panels:1.0",
 *   resource = "panels_display",
 *   label = "Panels",
 *   description = "Export the Panels.",
 *   authenticationTypes = TRUE,
 *   authenticationOptional = TRUE,
 *   dataProvider = {
 *     "entityType": "user",
 *     "bundles": {
 *       "user"
 *     },
 *   },
 *   majorVersion = 1,
 *   minorVersion = 0
 * )
 */
class Panels_display__1_0 extends Resource implements ResourceInterface {

  /**
   * {@inheritdoc}
   */
  protected function publicFields() {
    $public_fields = parent::publicFields();

    $public_fields['did'] = array();
    $public_fields['layout'] = array();
    $public_fields['content'] = array();

    return $public_fields;
  }

  /**
   * @inheritDoc
   */
  public function index($path) {
    $result = db_select('panels_display', 'd')
      ->fields('d')
      ->execute();

    $return = array();
    foreach ($result as $row) {
      $return[] = array(
        'display_id' => $row->did,
        'layout' => $row->layout,
      );
    }

    return $return;
  }

}
