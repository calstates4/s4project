(function($) {
	$(document).ready(function() {
		if($('#site-map').length) {
			s4Map.init('site-map');
		}
		if($('#site-list-map').length) {
			$(document).scroll(function() {
				var columnTop = $('#content_middle .column').position();
				if($(document).scrollTop() > columnTop.top) {
					$('#site-list-map').css('position', 'fixed').css('top', 0);
				}
				else {
					$('#site-list-map').css('position', 'relative');
				}
			});
			s4Map.init('site-list-map');
			$('.map-link').hide();
			
			var bounds = new google.maps.LatLngBounds();
			$('.map-link').each(function(index, element) {
				if($(this).attr('lat') == 0 && !$(this).attr('lon') == 0 ) {
					$(this).html('&times;').addClass('disabled').show();
					return null;
				}
				var letter = String.fromCharCode("A".charCodeAt(0) + index);
				s4Map.addMarker($(this).attr('lat'), 
								$(this).attr('lon'), 
								false, 
								"http://www.google.com/mapfiles/marker" + letter + ".png");
			  	bounds.extend(new google.maps.LatLng($(this).attr('lat'), $(this).attr('lon')));
			  	$(this).html(letter).show();
			  	$(this).click(function() {
		  		   	s4Map.setCenter($(this).attr('lat'), $(this).attr('lon'));
		  		   	return false;
		  		});
			});
			s4Map.map.fitBounds(bounds);
			
		}
	});

var s4Map = {
	
	map : null,
	
	activeInfoWindow : null,
	
	markers : [ ],
	
	mapID : '',
	
	style : [ ],
	
	lastZoom : 10,
	
	zoomStorage : [ ],
	
	zoomDivider : .4,
	
	maxSize: 70,
	
	minSize: 20,
	
	init : function(mapID) {
		s4Map.lastZoom = Drupal.settings.s4_map.zoom;
		s4Map.mapID = mapID;
		var center = new google.maps.LatLng(Drupal.settings.s4_map.lat, Drupal.settings.s4_map.lon);
		s4Map.map = new google.maps.Map(document.getElementById(mapID),
        				   {'center' : center,
							'zoom' : Drupal.settings.s4_map.zoom,
						    mapTypeId: google.maps.MapTypeId.TERRAIN
						    });
		
		/*var mapStyleType = new google.maps.StyledMapType(
					      s4Map.style, { name : 'Service'} );
		s4Map.map.mapTypes.set('s4', mapStyleType);
		s4Map.map.setMapTypeId('s4');*/
		if($('#' + mapID).hasClass('autofill')) {
			google.maps.event.addListener(s4Map.map, 'idle', s4Map.reloadMap);
		}
	},
	
	setCenter : function(lat, lon) {
		var newCenter = new google.maps.LatLng(lat, lon);
		s4Map.map.setCenter(newCenter);
		s4Map.map.setZoom(15);
	},
	
	reloadMap : function(event) {
		var boundaries = s4Map.map.getBounds();
		if(boundaries === undefined) {
			return null;
		}
		$('#map-loading-indicator').show();
		$.getJSON(Drupal.settings.basePath + 'json/map/sites?lat_min=' + boundaries.getSouthWest().lat() +'&lat_max=' + boundaries.getNorthEast().lat() + '&lon_min=' + boundaries.getSouthWest().lng() + '&lon_max=' + boundaries.getNorthEast().lng() ,function(data) {
			$.each(data.nodes, function(index, element) {
				if(typeof s4Map.markers[element.node.nid] == 'undefined') {
					s4Map.markers[element.node.nid] = 
						s4Map.addCircle(element.node.latitude, element.node.longitude, element.node.hours / (s4Map.maxSize - s4Map.minSize), '<a href="' + element.node.path + '">' + element.node.title + '</a><div class="hours">' + element.node.hours + ' hours by ' + element.node.students + ' students</div>');
				}
			});
			$('#map-loading-indicator').hide();
		});
		if(s4Map.lastZoom != s4Map.map.getZoom()) {
			s4Map.lastZoom = s4Map.map.getZoom();
			$.each(s4Map.markers, function(index, marker) {
				if(typeof marker != 'undefined') {
					s4Map.markers[index].setRadius(s4Map.getCircleSize(marker.get('defaultRadius')));
				}
			});
		}
	},
	
	getCircleSize : function(size) {
		var meters = s4Map.getMetersPerPixels();
		if(size > s4Map.maxSize) {
			return s4Map.maxSize * meters;
		}
		if(size < s4Map.minSize) {
			return s4Map.minSize * meters;
		}
		return size * meters;
	},
	
	getMetersPerPixels : function() {
		if(typeof s4Map.zoomStorage[s4Map.map.getZoom()] == 'undefined') {
			var boundaries = s4Map.map.getBounds();
			var meters = google.maps.geometry.spherical.computeDistanceBetween(boundaries.getSouthWest(), boundaries.getNorthEast());
			var pixels = ($('#' + s4Map.mapID).width() ^ 2) + ($('#' + s4Map.mapID).height() ^ 2);
			s4Map.zoomStorage[s4Map.map.getZoom()] = (meters / pixels);
		}
		return s4Map.zoomStorage[s4Map.map.getZoom()];
	},
	
	addMarker : function(lat, lon, message, icon, shadow) {
		var latLng = new google.maps.LatLng(lat, lon);
		var markerOptions = {
			position: latLng, 
			map: s4Map.map
		};
		if(icon) {
			markerOptions.icon = icon;
		}
		if(shadow) {
			markerOptions.shadow = shadow;
		}
		var marker = new google.maps.Marker(markerOptions);
		if(message) {
			google.maps.event.addListener(marker, 'click', function(e) {
			  	if(s4Map.activeInfoWindow !== null) {
			  		s4Map.activeInfoWindow.close();
			  	}
			  	infoBubble = new InfoBubble({
	          		minWidth: 200,
				    content: '<div class="infowindow-text">' + message + '</div>',
				    borderColor: '#000',
				    backgroundColor: 'rgba(0,0,0,0.8)',
				    borderRadius: '4px',
				    disableAutoPan: true,
				    disableAnimation: true
				});
				s4Map.activeInfoWindow = infoBubble;
			});
		}
		return marker;
	},
	
	addCircle : function(lat, lon, radius, message) {
		var latLng = new google.maps.LatLng(lat, lon);
		var marker = new google.maps.Circle({
			center: latLng,
			fillColor: '#4b8bba',
			fillOpacity: 0.7,
			radius: s4Map.getCircleSize(radius),
			strokeColor: '#4b8bba',
			strokeWeight: 1,
			clickable: true, 
			map: s4Map.map
		});
		marker.set('defaultRadius', radius);
		if(typeof message !== 'undefined') {
			google.maps.event.addListener(marker, 'click', function(e) {
			  	if(s4Map.activeInfoWindow !== null) {
			  		s4Map.activeInfoWindow.close();
			  	}
			  	infoBubble = new InfoBubble({
	          		minWidth: 200,
				    content: '<div class="infowindow-text">' + message + '</div>',
				    borderColor: '#000',
				    backgroundColor: 'rgba(0,0,0,0.8)',
				    borderRadius: '4px',
				    disableAutoPan: true,
				    disableAnimation: true,
				    padding: 20
				});
				$(infoBubble.c).find('img:first').attr('src', Drupal.settings.basePath + Drupal.settings.s4_map_path + '/images/close.png');
				infoBubble.setPosition(marker.getCenter());
				infoBubble.open(s4Map.map);
				s4Map.activeInfoWindow = infoBubble;
			});
		}
		return marker;
	},
	
	resizeCircles : function() {
		var mapZoom = s4Map.map.getZoom();
		$.each(s4Map.markers, function(index, circle) {
		});
	}
}


})(jQuery);