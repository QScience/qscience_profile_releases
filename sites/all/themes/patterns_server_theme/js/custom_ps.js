jQuery(document).ready(function() {
	jQuery('.breadcrumb').css('display', 'none');
	jQuery('.page-header').css('display', 'none');


	//var edit_search=jQuery("#patterns-server-search-form #edit-search");
	//edit_search.css("width", "");
	//var edit_selected=jQuery("#patterns-server-search-form #edit-selected");
	//edit_selected.css("width", "");
	//var edit_submit=jQuery("#patterns-server-search-form #edit-submit");
	//edit_submit.css("width", "");

	//like
	//var liked_link = jQuery(".pattern_row .liked-link");
	//jQuery.each( liked_link , function(ix,ele){
	//	if (jQuery(ele).text() == "Unlike") {
	//		jQuery(ele).addClass('liked-link-t');
	//	}
	//});
    //liked_link.click(function() {
	//	if (jQuery(this).text() == "Like") {
	//		jQuery(this).text("Unlike");
	//		//jQuery(this).css( 'background-image', 'url("../img/unlike01.png" )');
	//		jQuery(this).addClass('liked-link-t');
	//		var liked_times = jQuery(this).parent().prev().prev();
	//		var numb = Number(liked_times.text()) + 1; 
	//		liked_times.children().text(numb);
	//	}
	//	else {
	//		jQuery(this).text("Like");
	//		jQuery(this).removeClass('liked-link-t');
	//		var liked_times = jQuery(this).parent().prev().prev();
	//		var numb = Number(liked_times.text()) - 1; 
	//		liked_times.children().text(numb);
	//	}

    //    var url_div = jQuery(this).attr("href");
    //    url_div += " #one_pattern_div";
    //    jQuery("#one_pattern_div").load(url_div); 
    //    return false;
    //});

	jQuery("#patterns-server-search-form #edit-search").removeClass("edit-search-w");
	jQuery("#patterns-server-search-form #edit-selected").removeClass("edit-selected-w");
	jQuery("#patterns-server-search-form #edit-submit").removeClass("edit-submit-w");

});
