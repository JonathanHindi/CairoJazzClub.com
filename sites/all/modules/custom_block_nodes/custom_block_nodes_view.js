jQuery(document).ready(function() {
	//alert("fggfd");
	row_h = jQuery('.view-id-ex .views-row').height();
	num_rows = jQuery('#edit-height-rem').val();
	//total_h = row_h*num_rows;
	total_h = 45*num_rows;
	//alert(total_h);
	jQuery('#edit-occupied-height').val(total_h);
	max_height = 900;
	rem_h = max_height - total_h;
	//alert(rem_h);
	jQuery('#edit-reamining-height').val(rem_h);
});
