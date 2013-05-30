<?php

/**
 * Helper Functions
 * Attetion: STUPID LOGIC NOT DRY 
 */

function jazz_order_node_load($nid){
	// Load the node with reset flag TRUE
	return node_load($nid, NULL, TRUE);
}

function jazz_order_get_item_id($formId){
	
	// Check if nid exist and numerical value, if yes return it and don't procced.
	$nid = $_GET['nid'];
	if( isset($nid) && is_numeric($nid) && !is_null($nid) && !empty($nid) ) { return $nid; }

	// Required for webform_get_submission to work on done/submission pages
	require_once(drupal_get_path('module', 'webform') . '/includes/webform.submissions.inc');

	// If on submission page
	if( arg(2) == 'submission' ){
		$submissionId = arg(3);
	}

	// if on the confirmation page
	if( arg(2) == 'done' ){
		$submissionId = $_GET['sid'];
	}

	// Get Submission details with $formId, and submissionId
	$submission = webform_get_submission($formId, $submissionId);

	// Get nid index according to form type
	$nid_index = jazz_order_from_nid_index($formId);

	// get nid from the submission data 
	$nid = $submission->data[$nid_index]['value'][0];
	return $nid;

}

function jazz_order_from_nid_index($formId){

	var_dump($formId);
	// Check if it's the t-shirts return 10
	if( $formId == 433 ) return 10;
	
	// Check if it's the cds form return 9
	if( $formId == 499 ) return 9;	

}

function jazz_order_item_load_node($formId, $redirectLink){

	// Get Node ID of Order Item
	$nid = jazz_order_get_item_id($formId);

	// If $nid Load Order Item Node Object
	if( $nid ){ return jazz_order_node_load($nid); }

	// else redirect to redirectLink.
	return drupal_goto($redirectLink);	

}