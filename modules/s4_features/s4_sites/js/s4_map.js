(function($) {
	Drupal.s4 = {
		map : {
			marker : false
		}
	};
	$(document).ready(function() {
		if(!$('.map-link').length) {
			return null;
		}
		$(document).scroll(function() {
			var columnTop = $('#content_middle .column').position();
			if($(document).scrollTop() > columnTop.top) {
				$('#block-boxes-site-search-map').css('position', 'fixed').css('top', 0);
			}
			else {
				$('#block-boxes-site-search-map').css('position', 'relative');
			}
		});
		
		var map = Drupal.gmap.getMap('site-map');
		map.bind('maptypechange', function() {
			addMapIcons();
			
		});
	});
	
	var addMapIcons = function() {
		$('.map-link').hide();
		var map = Drupal.gmap.getMap('site-map');
		var bounds = new GLatLngBounds(); 
		var baseIcon = new GIcon(G_DEFAULT_ICON);
		baseIcon.shadow = "http://www.google.com/mapfiles/shadow50.png";
		baseIcon.iconSize = new GSize(20, 34);
		baseIcon.shadowSize = new GSize(37, 34);
		baseIcon.iconAnchor = new GPoint(9, 34);
		$('.map-link').each(function(index, element) {
				if(!$(this).attr('lat') && !$(this).attr('lon')) {
					$(this).html('&times;');
					return null;
				}
				var letter = String.fromCharCode("A".charCodeAt(0) + index);
			  	$(this).html(letter);
			  	var letteredIcon = new GIcon(baseIcon);
			  	letteredIcon.image = "http://www.google.com/mapfiles/marker" + letter + ".png";
				var point = new GLatLng($(this).attr('lat'), $(this).attr('lon'));
				bounds.extend(point);
				Drupal.s4.map.marker = new GMarker(point, { icon:letteredIcon });
				map.map.addOverlay(Drupal.s4.map.marker);
				$(this).show()
					   .click(function() {
					   		var point = new GLatLng($(this).attr('lat'), $(this).attr('lon'));
					   		map.map.setCenter(point, 15);
					   		return false;
					   });
			});
			var zoom = map.map.getBoundsZoomLevel(bounds);
			map.map.setZoom((zoom > 15) ? 15 : zoom); 
	        map.map.setCenter(bounds.getCenter()); 
	}
})(jQuery);