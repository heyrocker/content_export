<?php

function content_export_form($form, &$form_state, $action = NULL) {
  $form['actions']['submit'] = array(
    '#type' => 'submit',
    '#value' => t('Export'),
    '#weight' => 13
  );

  return $form;
}

/**
 * Form submission handler for content_export_form().
 */
function content_export_form_submit($form, &$form_state) {
  $nodes = entity_load_multiple_by_properties('node', array('status' => NODE_PUBLISHED));
  $serializer = drupal_container()->get('serializer');
  foreach ($nodes as $node) {
    $serialized .= $serializer->serialize($node, 'drupal_jsonld');
  }

  print $serialized;
  die();
}
