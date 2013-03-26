
// Height Based Div Pagination 

jQuery(document).ready(function() {

	limited_height = 742;
	// Next Previous 
	
	jQuery('ul#scroller-band li').live('click',function(event) {
		//alert('Clicked on Pagination');
		
		// If Clicked on Active Class Do nothing Else Update Pagination
		active_class = jQuery(this).hasClass('active');
		if(active_class == true) { } 
		else {
			jQuery('#scroller-band li').each(function(){
				if(jQuery(this).hasClass('active')){
					previous_active_li = jQuery(this).attr('id');
				}
			});
			//alert(previous_active_li);
			//alert(jQuery('#'+previous_active_li).attr('class'));
			jQuery('#'+previous_active_li).removeClass('active');
			jQuery(this).addClass('active');
			
			current_active_li = jQuery(this).attr('id');		
			cid_array = current_active_li.split('--');
			
			cid_array_sec = cid_array[1];
			
			margin_adj = (cid_array_sec - 1) * limited_height;
			//alert("margin to adjust is"+margin_adj);
			//ui_height = jQuery('#stage .panel-col-first .ui-tabs-nav').height();
			//alert(ui_height);
			jQuery('#kill-bill-id').css('marginTop',-margin_adj);
		}
	});	
	
	// Put Pagination in bottom
	 function add_pagination_band(num_of_pages,id_div,limited_height) {
		//alert('Add Pagination: Break It Lol in '+num_of_pages+' pages');
		
		
		jQuery('#'+id_div).css('float','left');
		jQuery('#'+id_div).css('overflow','hidden');
		jQuery('#'+id_div).css('height',limited_height);

		jQuery('#'+id_div+' #kill-bill-id').css('overflow','hidden');		
		
		pagecounter = 1;
	
		jQuery('.main_content').append('<ul	id="scroller-band"></ul>');
		
		for(i=1;i<=num_of_pages;i++){
			jQuery('#scroller-band').append('<li>Page '+i+'</li>');
		}
		jQuery('#scroller-band li:first').addClass("active");
	
		jQuery('#scroller-band li').each(function() {
			jQuery(this).attr('uniqueIdentity','sc-page--'+ pagecounter);
			jQuery(this).attr('id','sc-page--'+ pagecounter);
			pagecounter++;
		});
	}
	
	// For First Time When Page Is Loaded
	function init_band() {
		//alert("On Load. First Time Only");
	
		// Get Height Of Panel
		content_height = jQuery('#band_node div.panel-col').height();
	
		jQuery('#band_node div.panel-col').attr('id','kill-bill-papa');
	
		jQuery('#band_node div.panel-col div:first').attr('id','kill-bill-id');
	
		//content_height +=300;
	
		//alert(content_height);
	
		num_of_pages = 1;
		if(content_height > limited_height) {
			num_of_pages = Math.ceil(content_height / limited_height);
			// Call Pagination
			add_pagination_band(num_of_pages, 'kill-bill-papa', limited_height);
			// break_pages(id_div,content_height,limited_height);
		}
	}

	// Start Pagination	
	init_band();

});
	
