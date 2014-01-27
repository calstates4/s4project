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

projects[captcha][subdir] = "contrib"
projects[captcha][version] = "1.x-dev"

projects[cck][subdir] = "contrib"
projects[cck][version] = "2.x-dev"

projects[cck_phone][subdir] = "contrib"
projects[cck_phone][version] = "1.x-dev"

projects[content_access][subdir] = "contrib"
projects[content_access][version] = "1.2-beta1"

projects[context][subdir] = "contrib"
projects[context][version] = "3.0-beta6"

projects[ctools][subdir] = "contrib"
projects[ctools][version] = "1.x-dev"

projects[date][subdir] = "contrib"
projects[date][version] = "2.6"

projects[ds][subdir] = "contrib"
projects[ds][version] = "1.7"

projects[edit_limit][subdir] = "contrib"
projects[edit_limit][version] = "1.0-beta4"

projects[email][subdir] = "contrib"
projects[email][version] = "1.2"

projects[entity][subdir] = "contrib"
projects[entity][version] = "1.0"

projects[entityreference][subdir] = "contrib"
projects[entityreference][version] = "1.0"

projects[entityreference_prepopulate][subdir] = "contrib"
projects[entityreference_prepopulate][version] = "1.3"

projects[features][subdir] = "contrib"
projects[features][version] = "1.0-beta4"

projects[feeds][subdir] = "contrib"
projects[feeds][version] = "2.x-dev"

projects[feeds_tamper][subdir] = "contrib"
projects[feeds_tamper][version] = "1.0-beta3"

projects[field_display_label][subdir] = "contrib"
projects[field_display_label][version] = "1.2"

projects[field_lock][subdir] = "contrib"
projects[field_lock][version] = "1.0"

projects[field_group][subdir] = "contrib"
projects[field_group][version] = "1.1"

projects[field_collection][subdir] = "contrib"
projects[field_collection][version] = "1.0-beta3"

projects[field_collection_table][subdir] = "contrib"
projects[field_collection_table][version] = "1.0-beta1"

projects[flag][subdir] = "contrib"
projects[flag][version] = "3.0"

projects[forena][subdir] = "contrib"
projects[forena][version] = "3.12"

projects[gmap][subdir] = "contrib"
projects[gmap][version] = "1.x-dev"

projects[insert][subdir] = "contrib"
projects[insert][version] = "1.1"

projects[job_scheduler][subdir] = "contrib"
projects[job_scheduler][version] = "2.0-alpha2"

projects[libraries][subdir] = "contrib"
projects[libraries][version] = "1.0"

projects[location][subdir] = "contrib"
projects[location][version] = "3.0-alpha1"

projects[login_destination][subdir] = "contrib"
projects[login_destination][version] = "1.0"

projects[link][subdir] = "contrib"
projects[link][version] = "1.0"

projects[location_feeds][subdir] = "contrib"
projects[location_feeds][version] = "1.5"

projects[matrix][subdir] = "contrib"
projects[matrix][version] = "2.x-dev"

projects[masquerade][subdir] = "contrib"
projects[masquerade][version] = "1.0-rc4"

projects[nodeaccess_userreference][subdir] = "contrib"
projects[nodeaccess_userreference][version] = "3.5"

projects[nodeformcols][subdir] = "contrib"
projects[nodeformcols][version] = "1.x-dev"

projects[nodereference_count][subdir] = "contrib"
projects[nodereference_count][version] = "1.x-dev"

projects[nodereference_url][subdir] = "contrib"
projects[nodereference_url][version] = "1.11"

projects[options_element][subdir] = "contrib"
projects[options_element][version] = "1.9"

projects[office_html][subdir] = "contrib"
projects[office_html][version] = "1.0-alpha1"

projects[pathauto][subdir] = "contrib"
projects[pathauto][version] = "1.0-beta1"

projects[references][subdir] = "contrib"
projects[references][version] = "2.x-dev"

projects[relation][subdir] = "contrib"
projects[relation][version] = "1.0-rc4"

projects[select_or_other][subdir] = "contrib"
projects[select_or_other][version] = "2.0"

projects[signaturefield][subdir] = "contrib"
projects[signaturefield][version] = "1.x-dev"

projects[strongarm][subdir] = "contrib"
projects[strongarm][version] = "2.0"

projects[textcaptcha][subdir] = "contrib"
projects[textcaptcha][version] = "1.2"

projects[token][subdir] = "contrib"
projects[token][version] = "1.5"

projects[uuid][subdir] = "contrib"
projects[uuid][version] = "1.0-alpha4"

projects[view_unpublished][subdir] = "contrib"
projects[view_unpublished][version] = "1.0"

projects[views][subdir] = "contrib"
projects[views][version] = "3.7"

projects[views_bulk_operations][subdir] = "contrib"
projects[views_bulk_operations][version] = "3.1"

projects[views_data_export][subdir] = "contrib"
projects[views_data_export][version] = "3.0-beta6"

projects[views_export_xls][subdir] = "contrib"
projects[views_export_xls][version] = "1.0"

projects[views_datasource][subdir] = "contrib"
projects[views_datasource][version] = "1.x-dev"

projects[views_dynamic_fields][subdir] = "contrib"
projects[views_dynamic_fields][version] = "1.x-dev"

projects[views_exposed_groups][subdir] = "contrib"
projects[views_exposed_groups][version] = "1.0"

projects[views_savedsearches][subdir] = "contrib"
projects[views_savedsearches][version] = "1.0-beta1"

projects[workbench][subdir] = "contrib"
projects[workbench][version] = "1.1"

projects[workbench_moderation][subdir] = "contrib"
projects[workbench_moderation][version] = "1.1"

projects[workbench_moderation_notes][subdir] = "contrib"
projects[workbench_moderation_notes][version] = "1.x-dev"

projects[webform][subdir] = "contrib"
projects[webform][version] = "3.19"

projects[webform_table_element][subdir] = "contrib"
projects[webform_table_element][version] = "1.7"

projects[wysiwyg][subdir] = "contrib"
projects[wysiwyg][version] = "2.1"

projects[wysiwyg_ckeditor][subdir] = "contrib"
projects[wysiwyg_ckeditor][version] = "1.x-dev"

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

; Download the marker manager for gmap
libraries[markerclusterer][download][type] = "get"
libraries[markerclusterer][download][url] = "http://gmaps-utility-library-dev.googlecode.com/svn/tags/markerclusterer/1.0/src/markerclusterer_packed.js"
libraries[markerclusterer][destination] = "modules/contrib/gmap/thirdparty"

; Download Signature Pad as a library
libraries[signature-pad][download][type] = "git"
libraries[signature-pad][download][url] = "https://github.com/thomasjbradley/signature-pad.git"
libraries[signature-pad][download][revision] = "f1d8798886a81b50816206080fe36ea39602f4b9"
libraries[signature-pad][directory_name] = "signature-pad"
libraries[signature-pad][destination] = "libraries"

; Patches
projects[wysiwyg][patch][] = "http://drupal.org/files/issues/wysiwyg-entity-exportables-624018-176_1.patch"
projects[cck_phone][patch][] = "http://drupal.org/files/cck_phone_feeds_1160186_7.patch"
projects[workbench_moderation][patch][] = "http://drupal.org/files/workbench_moderation_feeds-1470528-1.patch"
projects[views_data_export][patch][] = "http://drupal.org/files/views_data_export_exposed_input_0.patch"
