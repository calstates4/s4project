; Make file for student_signup profile.

projects[drupal][type] = core
core = 7.x
api = 2

;Adding the profiler module
;Profiler is in dev and we can't patch libraries, so including it in the repository for now
;libraries[profiler][download][type] = "get"
;libraries[profiler][download][url] = "http://ftp.drupal.org/files/projects/profiler-7.x-2.x-dev.tar.gz"
;libraries[profiler][destination] = "libraries/profiler"

; Contrib Modules
projects[auto_nodetitle][subdir] = "contrib"
projects[auto_nodetitle][version] = "1.0-alpha1"

projects[better_exposed_filters][subdir] = "contrib"
projects[better_exposed_filters][version] = "3.0-beta1"

projects[captcha][subdir] = "contrib"
projects[captcha][version] = "1.0-beta2"

projects[cck][subdir] = "contrib"
projects[cck][version] = "2.x-dev"

projects[cck_phone][subdir] = "contrib"
projects[cck_phone][version] = "1.x-dev"

projects[content_access][subdir] = "contrib"
projects[content_access][version] = "1.2-beta1"

projects[context][subdir] = "contrib"
projects[context][version] = "3.0-beta1"

projects[ctools][subdir] = "contrib"
projects[ctools][version] = "1.x-dev"

projects[date][subdir] = "contrib"
projects[date][version] = "2.0-alpha3"

projects[ds][subdir] = "contrib"
projects[ds][version] = "1.4"

projects[email][subdir] = "contrib"
projects[email][version] = "1.0-beta1"

projects[entity][subdir] = "contrib"
projects[entity][version] = "1.0-beta9"

projects[fancybox][subdir] = "contrib"
projects[fancybox][version] = "1.x-dev"

projects[features][subdir] = "contrib"
projects[features][version] = "1.0-beta4"

projects[feeds][subdir] = "contrib"
projects[feeds][version] = "2.x-dev"

projects[feeds_tamper][subdir] = "contrib"
projects[feeds_tamper][version] = "1.0-beta3"

projects[field_display_label][subdir] = "contrib"
projects[field_display_label][version] = "1.2"

projects[field_group][subdir] = "contrib"
projects[field_group][version] = "1.1"

projects[flag][subdir] = "contrib"
projects[flag][version] = "2.0-beta6"

projects[front][subdir] = "contrib"
projects[front][version] = "2.1"

projects[gmap][subdir] = "contrib"
projects[gmap][version] = "1.x-dev"

;projects[Guiders-JS][subdir] = "contrib"
;projects[Guiders-JS][version] = "1.x-dev"

projects[homebox][subdir] = "contrib"
projects[homebox][version] = "2.0-beta6"

projects[imce][subdir] = "contrib"
projects[imce][version] = "1.5"

projects[imce_wysiwyg][subdir] = "contrib"
projects[imce_wysiwyg][version] = "1.0"

projects[insert][subdir] = "contrib"
projects[insert][version] = "1.1"

projects[job_scheduler][subdir] = "contrib"
projects[job_scheduler][version] = "2.0-alpha2"

projects[libraries][subdir] = "contrib"
projects[libraries][version] = "1.0"

projects[link][subdir] = "contrib"
projects[link][version] = "1.0"

projects[location_feeds][subdir] = "contrib"
projects[location_feeds][version] = "1.5"

projects[masquerade][subdir] = "contrib"
projects[masquerade][version] = "1.0-rc4"

projects[messaging][subdir] = "contrib"
projects[messaging][version] = "1.0-alpha1"

projects[nodeaccess_userreference][subdir] = "contrib"
projects[nodeaccess_userreference][version] = "3.5"

projects[nodeformcols][subdir] = "contrib"
projects[nodeformcols][version] = "1.x-dev"

projects[nodereference_count][subdir] = "contrib"
projects[nodereference_count][version] = "1.x-dev"

projects[nodereference_url][subdir] = "contrib"
projects[nodereference_url][version] = "1.11"

projects[notifications][subdir] = "contrib"
projects[notifications][version] = "1.0-alpha1"

projects[options_element][subdir] = "contrib"
projects[options_element][version] = "1.4"

projects[pathauto][subdir] = "contrib"
projects[pathauto][version] = "1.0-beta1"

projects[references][subdir] = "contrib"
projects[references][version] = "2.x-dev"

projects[save_draft][subdir] = "contrib"
projects[save_draft][version] = "1.4"

projects[select_or_other][subdir] = "contrib"
projects[select_or_other][version] = "2.0"

projects[strongarm][subdir] = "contrib"
projects[strongarm][version] = "2.0-beta2"

projects[tac_lite][subdir] = "contrib"
projects[tac_lite][version] = "1.x-dev"

projects[textcaptcha][subdir] = "contrib"
projects[textcaptcha][version] = "1.x-dev"

projects[token][subdir] = "contrib"
projects[token][version] = "1.0-beta2"

projects[view_unpublished][subdir] = "contrib"
projects[view_unpublished][version] = "1.0"

projects[views][subdir] = "contrib"
projects[views][version] = "3.0-rc1"

projects[views_bulk_operations][subdir] = "contrib"
projects[views_bulk_operations][version] = "3.x-dev"

projects[views_calc][subdir] = "contrib"
projects[views_calc][version] = "1.x-dev"

projects[views_data_export][subdir] = "contrib"
projects[views_data_export][version] = "3.0-beta4"

projects[views_dynamic_fields][subdir] = "contrib"
projects[views_dynamic_fields][version] = "1.x-dev"

projects[workbench][subdir] = "contrib"
projects[workbench][version] = "1.1"

projects[workbench_moderation][subdir] = "contrib"
projects[workbench_moderation][version] = "1.1"

projects[webform][subdir] = "contrib"
projects[webform][version] = "3.11"

projects[wysiwyg][subdir] = "contrib"
projects[wysiwyg][version] = "2.1"

;Modules still in development
projects[location][type] = module
projects[location][subdir] = "contrib"
projects[location][version] = "3.x-dev"
projects[location][download][type] = "git"
projects[location][download][url] = "http://git.drupal.org/project/location.git"
projects[location][download][branch] = "7.x-3.x"

projects[matrix][type] = module
projects[matrix][subdir] = "contrib"
projects[matrix][version] = "1.x-dev"
projects[matrix][download][type] = "file"
projects[matrix][download][url] = "http://s4.csumb.edu/hosted_modules/matrix.tar.gz"

projects[views_datasource][type] = module
projects[views_datasource][subdir] = "contrib"
projects[views_datasource][version] = "7.x-dev"
projects[views_datasource][download][type] = "file"
projects[views_datasource][download][url] = "http://s4.csumb.edu/hosted_modules/views_datasource.tar.gz"

projects[views_savedsearches][type] = module
projects[views_savedsearches][subdir] = "contrib"
projects[views_savedsearches][version] = "7.x-dev"
projects[views_savedsearches][download][type] = "file"
projects[views_savedsearches][download][url] = "http://s4.csumb.edu/hosted_modules/views_savedsearches.tar.gz"

; Themes

projects[rubik][subdir] = "contrib"
projects[rubik][version] = "4.0-beta6"

projects[tao][subdir] = "contrib"
projects[tao][version] = "3.0-beta4"

; Fixed Guiders-JS module module
projects[guiders_js_fixed][type] = module
projects[guiders_js_fixed][subdir] = "contrib"
projects[guiders_js_fixed][version] = "1.x-dev"
projects[guiders_js_fixed][download][type] = "git"
projects[guiders_js_fixed][download][url] = "http://git.drupal.org/sandbox/kevee/1355900.git"
projects[guiders_js_fixed][download][branch] = "master"

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
libraries[markerclusterer][download][type] = "get"
libraries[markerclusterer][download][url] = "http://gmaps-utility-library-dev.googlecode.com/svn/tags/markerclusterer/1.0/src/markerclusterer_packed.js"
libraries[markerclusterer][destination] = "modules/contrib/gmap/thirdparty"

; Download the guidersJS library
libraries[guiders][download][type] = "get"
libraries[guiders][download][url] = "https://github.com/jeff-optimizely/Guiders-JS/tarball/master"
libraries[guiders][directory_name] = "guiders"
libraries[guiders][destination] = "libraries"

; Patches
projects[wysiwyg][patch][] = "http://drupal.org/files/issues/wysiwyg-entity-exportables-624018-176_1.patch"
projects[token][patch][] = "http://drupal.org/files/issues/modules_token.92.patch"
projects[nodeformcols][patch][] = "http://drupal.org/files/nodeformcolum_captcha_error.patch"
projects[cck_phone][] = "http://drupal.org/files/cck_phone_feeds_1160186_7.patch"
projects[fancybox][patch][] = "http://drupal.org/files/fancybox_library_sub_folder.patch"
projects[views_dynamic_fields][patch][] = "http://drupal.org/files/views_dynamic_fields_missing_index_1369322_1.patch"