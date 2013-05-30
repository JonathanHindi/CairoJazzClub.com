<?php

/**
 * Helper Functions
 */

function jazz_order_node_load($nid){

	return node_load($nid, NULL, TRUE);
}

function jazz_order_get_item_id($formId){
	
	// Check if nid exist and numerical value
	$nid = $_GET['nid'];
	if( isset($nid) && is_numeric($nid) && !is_null($nid) && !empty($nid) ) { return $nid; }

	require_once(drupal_get_path('module', 'webform') . '/includes/webform.submissions.inc');

	if( arg(2) == 'submission' ){
		$submissionId = arg(3);
		$submission = webform_get_submission($formId, $submissionId);
		$nid = $submission->data[9]['value'][0];
		return $nid;
	}

	if( arg(2) == 'done' ){
		$submissionId = $_GET['sid'];
		$submission = webform_get_submission($formId, $submissionId);
		$nid = $submission->data[9]['value'][0];
		return $nid;
	}

	return false;
}

function jazz_order_item_load_node($formId, $redirectLink){

	// Get Node ID of Order Item
	$nid = jazz_order_get_item_id($formId);

	// If $nid Load Order Item Node Object
	if( $nid ){ return jazz_order_node_load($nid); }

	return drupal_goto($redirectLink);	

}