; Make file for videola profile.

core = 7.x
api = 2

;Adding the profiler module
;Profiler is in dev and we can't patch libraries, so including it in the repository for now
;libraries[profiler][download][type] = "get"
;libraries[profiler][download][url] = "http://ftp.drupal.org/files/projects/profiler-7.x-2.x-dev.tar.gz"
;libraries[profiler][destination] = "libraries/profiler"

; Contrib Modules
"projects[auto_nodetitle][subdir] = "contrib"
projects[auto_nodetitle][version] = "7.x-1.0-alpha1"

projects[better_exposed_filters][subdir] = "contrib"
projects[better_exposed_filters][version] = "7.x-1.x-dev"

projects[boxes][subdir] = "contrib"
projects[boxes][version] = "7.x-1.0-beta2"

projects[cck][subdir] = "contrib"
projects[cck][version] = "7.x-2.x-dev"

projects[cck_blocks][subdir] = "contrib"
projects[cck_blocks][version] = "7.x-1.0"

projects[cck_phone][subdir] = "contrib"
projects[cck_phone][version] = "7.x-1.x-dev"

projects[context][subdir] = "contrib"
projects[context][version] = "7.x-3.0-beta1"

projects[context_layouts][subdir] = "contrib"
projects[context_layouts][version] = "7.x-3.0-beta1"

projects[context_ui][subdir] = "contrib"
projects[context_ui][version] = "7.x-3.0-beta1"

projects[ctools][subdir] = "contrib"
projects[ctools][version] = "7.x-1.x-dev"

projects[date][subdir] = "contrib"
projects[date][version] = "7.x-2.0-alpha1"

projects[date_api][subdir] = "contrib"
projects[date_api][version] = "7.x-2.0-alpha1"

projects[date_popup][subdir] = "contrib"
projects[date_popup][version] = "7.x-2.0-alpha1"

projects[date_tools][subdir] = "contrib"
projects[date_tools][version] = "7.x-2.0-alpha1"

projects[date_views][subdir] = "contrib"
projects[date_views][version] = "7.x-2.0-alpha1"

projects[devel][subdir] = "contrib"
projects[devel][version] = "7.x-1.0"

projects[devel_generate][subdir] = "contrib"
projects[devel_generate][version] = "7.x-1.0"

projects[email][subdir] = "contrib"
projects[email][version] = "7.x-1.0-beta1"

projects[entity][subdir] = "contrib"
projects[entity][version] = "7.x-1.0-beta9"

projects[fancybox][subdir] = "contrib"
projects[fancybox][version] = "7.x-1.x-dev"

projects[features][subdir] = "contrib"
projects[features][version] = "7.x-1.0-beta3"

projects[feeds][subdir] = "contrib"
projects[feeds][version] = "7.x-2.0-alpha3"

projects[feeds_import][subdir] = "contrib"
projects[feeds_import][version] = "7.x-2.0-alpha3"

projects[feeds_ui][subdir] = "contrib"
projects[feeds_ui][version] = "7.x-2.0-alpha3"

projects[field_group][subdir] = "contrib"
projects[field_group][version] = "7.x-1.0"

projects[flag][subdir] = "contrib"
projects[flag][version] = "7.x-2.0-beta5"

projects[flag_actions][subdir] = "contrib"
projects[flag_actions][version] = "7.x-2.0-beta5"

projects[gmap][subdir] = "contrib"
projects[gmap][version] = "7.x-1.x-dev"

projects[gmap_location][subdir] = "contrib"
projects[gmap_location][version] = "7.x-1.x-dev"

projects[gmap_macro_builder][subdir] = "contrib"
projects[gmap_macro_builder][version] = "7.x-1.x-dev"

projects[imce][subdir] = "contrib"
projects[imce][version] = "7.x-1.4"

projects[imce_wysiwyg][subdir] = "contrib"
projects[imce_wysiwyg][version] = "7.x-1.x-dev"

projects[insert][subdir] = "contrib"
projects[insert][version] = "7.x-1.0"

projects[job_scheduler][subdir] = "contrib"
projects[job_scheduler][version] = "7.x-2.0-alpha2"

projects[link][subdir] = "contrib"
projects[link][version] = "7.x-1.0-alpha3"

projects[location][subdir] = "contrib"
projects[location][version] = "7.x-3.x-dev"

projects[location_cck][subdir] = "contrib"
projects[location_cck][version] = "7.x-3.x-dev"

projects[location_fax][subdir] = "contrib"
projects[location_fax][version] = "7.x-3.x-dev"

projects[location_generate][subdir] = "contrib"
projects[location_generate][version] = "7.x-3.x-dev"

projects[location_node][subdir] = "contrib"
projects[location_node][version] = "7.x-3.x-dev"

projects[location_phone][subdir] = "contrib"
projects[location_phone][version] = "7.x-3.x-dev"

projects[location_search][subdir] = "contrib"
projects[location_search][version] = "7.x-3.x-dev"

projects[messaging][subdir] = "contrib"
projects[messaging][version] = "7.x-1.0-alpha1"

projects[messaging_htmlmail][subdir] = "contrib"
projects[messaging_htmlmail][version] = "7.x-1.0-alpha1"

projects[messaging_mail][subdir] = "contrib"
projects[messaging_mail][version] = "7.x-1.0-alpha1"

projects[messaging_template][subdir] = "contrib"
projects[messaging_template][version] = "7.x-1.0-alpha1"

projects[nodeaccess_nodereference][subdir] = "contrib"
projects[nodeaccess_nodereference][version] = "7.x-1.12"

projects[nodeaccess_userreference][subdir] = "contrib"
projects[nodeaccess_userreference][version] = "7.x-3.2"

projects[nodeformcols][subdir] = "contrib"
projects[nodeformcols][version] = "7.x-1.x-dev"

projects[nodereference_count][subdir] = "contrib"
projects[nodereference_count][version] = "7.x-1.x-dev"

projects[nodereference_url][subdir] = "contrib"
projects[nodereference_url][version] = "7.x-1.11"

projects[node_reference][subdir] = "contrib"
projects[node_reference][version] = "7.x-2.x-dev"

projects[notifications][subdir] = "contrib"
projects[notifications][version] = "7.x-1.0-alpha1"

projects[notifications_account][subdir] = "contrib"
projects[notifications_account][version] = "7.x-1.0-alpha1"

projects[notifications_content][subdir] = "contrib"
projects[notifications_content][version] = "7.x-1.0-alpha1"

projects[notifications_ui][subdir] = "contrib"
projects[notifications_ui][version] = "7.x-1.0-alpha1"

projects[page_manager][subdir] = "contrib"
projects[page_manager][version] = "7.x-1.x-dev"

projects[pathauto][subdir] = "contrib"
projects[pathauto][version] = "7.x-1.0-beta1"

projects[references][subdir] = "contrib"
projects[references][version] = "7.x-2.x-dev"

projects[s4][subdir] = "contrib"
projects[s4][version] = ""

projects[s4_core][subdir] = "contrib"
projects[s4_core][version] = ""

projects[s4_courses][subdir] = "contrib"
projects[s4_courses][version] = "7.x-1.0"

projects[s4_editor][subdir] = "contrib"
projects[s4_editor][version] = "7.x-1.0"

projects[s4_news][subdir] = "contrib"
projects[s4_news][version] = "7.x-1.0"

projects[s4_pages][subdir] = "contrib"
projects[s4_pages][version] = "1.0"

projects[s4_reporting][subdir] = "contrib"
projects[s4_reporting][version] = "7.x-1.0"

projects[s4_sites][subdir] = "contrib"
projects[s4_sites][version] = "7.x-1.0"

projects[s4_users][subdir] = "contrib"
projects[s4_users][version] = "7.x-1.0"

projects[save_draft][subdir] = "contrib"
projects[save_draft][version] = "7.x-1.4"

projects[strongarm][subdir] = "contrib"
projects[strongarm][version] = "7.x-2.0-beta2"

projects[token][subdir] = "contrib"
projects[token][version] = ""

projects[user_reference][subdir] = "contrib"
projects[user_reference][version] = "7.x-2.x-dev"

projects[views][subdir] = "contrib"
projects[views][version] = "7.x-3.x-dev"

projects[views_bulk_operations][subdir] = "contrib"
projects[views_bulk_operations][version] = "7.x-3.x-dev"

projects[views_calc][subdir] = "contrib"
projects[views_calc][version] = "7.x-1.x-dev"

projects[views_data_export][subdir] = "contrib"
projects[views_data_export][version] = "7.x-3.0-beta4"

projects[views_savedsearches][subdir] = "contrib"
projects[views_savedsearches][version] = "7.x-1.0-dev"

projects[views_ui][subdir] = "contrib"
projects[views_ui][version] = "7.x-3.x-dev"

projects[webform][subdir] = "contrib"
projects[webform][version] = "7.x-3.11"

projects[wysiwyg][subdir] = "contrib"
projects[wysiwyg][version] = "7.x-2.x-dev"


; Libraries
; Download fancybox as a library
libraries[fancybox][download][type] = "get"
libraries[fancybox][download][url] = "http://fancybox.googlecode.com/files/jquery.fancybox-1.3.4.zip"
libraries[fancybox][directory_name] = "fancybox"
libraries[fancybox][destination] = "libraries"

; Download tinyMCE as a library
libraries[tinymce][download][type] = "get"
libraries[tinymce][download][url] = "https://github.com/downloads/tinymce/tinymce/tinymce_3.4.1.zip"
libraries[tinymce][directory_name] = "tinymce"
libraries[tinymce][destination] = "libraries"

; Download the marker manager for gmap
libraries[tinymce][download][type] = "get"
libraries[tinymce][download][url] = "http://gmaps-utility-library-dev.googlecode.com/svn/tags/markerclusterer/1.0/src/markerclusterer_packed.js"
libraries[tinymce][destination] = "modules/contrib/gmap/thirdparty"

; Patches
projects[cck_blocks][patch][] = "http://drupal.org/files/issues/cck_blocks_conten_view-833730-24.patch"
projects[wysiwyg][patch][] = "http://drupal.org/files/issues/wysiwyg-entity-exportables-624018-176_1.patch"