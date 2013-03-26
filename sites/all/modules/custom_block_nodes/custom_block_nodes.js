jQuery(document).ready(function() {
	//alert("shiks");
	jQuery('#edit-node-checkboxes-wrapper #edit-node-checkboxes').change(function() {
//		alert('nidfd');
      var multipleValues = jQuery("#edit-node-checkboxes").val() || [];
	  for(i=0;i<multipleValues.length;i++) {
	  	multipleValues[i] = 'node/'+multipleValues[i];
	  }
      jQuery('#block-admin-configure .clear-block #edit-pages').val(multipleValues.join("\n"));		
	});
	
	al_sel = jQuery('#block-admin-configure .clear-block #edit-pages').val().split('\n');

	alert(al_sel);
		
	jQuery('#edit-node-checkboxes option').each(function() {
		for(j=0;j<al_sel.length;j++) {
			al_sel[j] = al_sel[j].replace('node/','');
			if(al_sel[j] == jQuery(this).attr('value')) {
				jQuery(this).attr('selected','selected');
			}
		}
	});
	
//	alert(al_sel);
//	alert(isArray(al_sel));
//	alert(al_sel.replace('node',' '));
/*	
    function displayVals() {
      var singleValues = $("#single").val();
      var multipleValues = $("#multiple").val() || [];
      $("p").html("<b>Single:</b> " + 
                  singleValues +
                  " <b>Multiple:</b> " + 
                  multipleValues.join(", "));
    }

    $("select").change(displayVals);
    displayVals();
    
    
	jQuery('#block-admin-configure .column-main .form-checkboxes .form-checkbox').click(function(event) {
		//alert('checkbox clicked');
		if(jQuery(this).is(':checked')) {
			//alert('Not Checked Before');
			
			checkbox_sel = jQuery(this).val();
			if(jQuery('#block-admin-configure .clear-block #edit-pages').val() === '') {
				jQuery('#block-admin-configure .clear-block #edit-pages').val('node/'+checkbox_sel);
			} 
			else {
				jQuery('#block-admin-configure .clear-block #edit-pages').val(jQuery('#block-admin-configure .clear-block #edit-pages').val()+ '\nnode/'+checkbox_sel);
			}
		}
		else {
			//alert('Checked Before');

			checkbox_sel = jQuery(this).val();
			if(jQuery('#block-admin-configure .clear-block #edit-pages').val() === '') {
				//jQuery('#block-admin-configure .clear-block #edit-pages').val('node/'+checkbox_sel);
			} 
			else {
				var rep = 'node/'+checkbox_sel;
				//alert(rep);
				var str = jQuery('#block-admin-configure .clear-block #edit-pages').val();

	jQuery('#block-admin-configure .clear-block #edit-pages').val(jQuery('#block-admin-configure .clear-block #edit-pages').val().replace(rep,''));
//				alert(str.replace(rep,''));	//.replace(rep,'');
				//alert('kill ie');
			}
		}
	});
*/
});
