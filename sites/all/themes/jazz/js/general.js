
// Height Based Div Pagination 

jQuery(document).ready(function() {

	limited_height = 620;
	// Next Previous 
	
	// Divide pages
	var break_pages = function(id_div,content_height,outer_h) {
	
	}
	
	// Put Pagination in bottom
	var add_pagination = function (num_of_pages,id_div,limited_height) {
		//alert('Add Pagination: Break It Lol in '+num_of_pages+' pages');
		
		jQuery('#'+id_div+' div.node').css('float','left');
		jQuery('#'+id_div+' div.node').css('overflow','hidden');
		jQuery('#'+id_div+' div.node').css('height',limited_height);

		jQuery('#'+id_div+' div.node div.content').css('overflow','hidden');
				
		pagecounter = 1;
	
		jQuery('.main_content').append('<ul	id="scroller"></ul>');
		
		for(i=1;i<=num_of_pages;i++){
			jQuery('#scroller').append('<li>Page '+i+'</li>');
		}
		jQuery('#scroller li:first').addClass("active");
	
		jQuery('#scroller li').each(function() {
			jQuery(this).attr('uniqueIdentity','sc-page--'+ pagecounter);
			jQuery(this).attr('id','sc-page--'+ pagecounter);
			pagecounter++;
		});

		jQuery('ul#scroller li').click(function(event) {
			//alert('Clicked on Pagination');
			
			// If Clicked on Active Class Do nothing Else Update Pagination
			active_class = jQuery(this).hasClass('active');
			if(active_class == true) { } 
			else {
				jQuery('#scroller li').each(function(){
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
				jQuery('#'+id_div+' div.node div.content').css('marginTop',-margin_adj);
			}
		});
	
	}
	
	// Reset on Each Call
	var reset_page = function(id_div) {
		if(jQuery('.main_content ul#scroller').length) {
			//alert('Reset Page');
			jQuery('#scroller').remove();
			jQuery('#'+id_div+' div.node div.content').css('marginTop',0);
		}
	}
	
	// Which Tab Is active.
	var active_block = function(id_div) {
		//alert("Active Block: "+id_div);

		reset_page(id_div);
		
		// Get Height Of Panel
		content_height = jQuery('#'+id_div+' div.node div.content').height();
		
		content_height +=300;
		
		//alert(content_height);
		
		num_of_pages = 1;
		if(content_height > limited_height) {
			num_of_pages = Math.ceil(content_height / limited_height);
			// Call Pagination
			add_pagination(num_of_pages,id_div,limited_height);
			// break_pages(id_div,content_height,limited_height);
		}
	}
	
	// For When the tabs will be clicked
	jQuery('#tabs-stage-left ul.ui-tabs-nav li a').click( function() {
		//alert("Load When Tab Is Clicked");
		active_block(jQuery(this).attr('href').replace('#',''));
		jQuery('#'+id_div+' div.node div.content').css('marginTop',0);
	});	
	
	// For First Time When Page Is Loaded
	var init = function() {
		//alert("On Load. First Time Only");
		jQuery('#tabs-stage-left div.ui-tabs-panel').each( function() {
			if(jQuery(this).hasClass('.ui-tabs-hide')) { }
			else {
				active_block(jQuery(this).attr('id'));
			}
		});
	}

	// Start Pagination	
	init();

});
	
