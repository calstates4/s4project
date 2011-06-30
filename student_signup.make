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
projects[better_exposed_filters][version] = "1.x-dev"

projects[boxes][subdir] = "contrib"
projects[boxes][version] = "1.0-beta2"

projects[cck][subdir] = "contrib"
projects[cck][version] = "2.x-dev"

projects[cck_phone][subdir] = "contrib"
projects[cck_phone][version] = "1.x-dev"

projects[context][subdir] = "contrib"
projects[context][version] = "3.0-beta1"

projects[ctools][subdir] = "contrib"
projects[ctools][version] = "1.x-dev"

projects[date][subdir] = "contrib"
projects[date][version] = "2.0-alpha3"

projects[email][subdir] = "contrib"
projects[email][version] = "1.0-beta1"

projects[entity][subdir] = "contrib"
projects[entity][version] = "1.0-beta9"

projects[fancybox][subdir] = "contrib"
projects[fancybox][version] = "1.x-dev"

projects[features][subdir] = "contrib"
projects[features][version] = "1.0-beta3"

projects[feeds][subdir] = "contrib"
projects[feeds][version] = "2.0-alpha3"

projects[field_group][subdir] = "contrib"
projects[field_group][version] = "1.0"

projects[flag][subdir] = "contrib"
projects[flag][version] = "2.0-beta5"

projects[gmap][subdir] = "contrib"
projects[gmap][version] = "1.x-dev"

projects[imce][subdir] = "contrib"
projects[imce][version] = "1.4"

projects[imce_wysiwyg][subdir] = "contrib"
projects[imce_wysiwyg][version] = "1.x-dev"

projects[insert][subdir] = "contrib"
projects[insert][version] = "1.0"

projects[job_scheduler][subdir] = "contrib"
projects[job_scheduler][version] = "2.0-alpha2"

projects[link][subdir] = "contrib"
projects[link][version] = "1.0-alpha3"

projects[messaging][subdir] = "contrib"
projects[messaging][version] = "1.0-alpha1"

projects[nodeaccess_nodereference][subdir] = "contrib"
projects[nodeaccess_nodereference][version] = "1.15"

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

projects[pathauto][subdir] = "contrib"
projects[pathauto][version] = "1.0-beta1"

projects[save_draft][subdir] = "contrib"
projects[save_draft][version] = "1.4"

projects[strongarm][subdir] = "contrib"
projects[strongarm][version] = "2.0-beta2"

projects[token][subdir] = "contrib"
projects[token][version] = "1.0-beta2"

projects[views][subdir] = "contrib"
projects[views][version] = "3.x-dev"

projects[views_bulk_operations][subdir] = "contrib"
projects[views_bulk_operations][version] = "3.x-dev"

projects[views_calc][subdir] = "contrib"
projects[views_calc][version] = "1.x-dev"

projects[views_data_export][subdir] = "contrib"
projects[views_data_export][version] = "3.0-beta4"

projects[webform][subdir] = "contrib"
projects[webform][version] = "3.11"

projects[wysiwyg][subdir] = "contrib"
projects[wysiwyg][version] = "2.1"

;Modules still in development

projects[cck_blocks][type] = module
projects[cck_blocks][subdir] = "contrib"
projects[cck_blocks][version] = "1.x-dev"
projects[cck_blocks][download][type] = "file"
projects[cck_blocks][download][url] = "http://s4.csumb.edu/hosted_modules/cck_blocks.tar.gz"
	
projects[location][type] = module
projects[location][subdir] = "contrib"
projects[location][version] = "3.x-dev"
projects[location][download][type] = "git"
projects[location][download][url] = "http://git.drupal.org/project/location.git"
projects[location][download][branch] = "7.x-3.x"

projects[references][type] = module
projects[references][subdir] = "contrib"
projects[references][version] = "2.x-dev"
projects[references][download][type] = "git"
projects[references][download][url] = "http://git.drupal.org/project/references.git"
projects[references][download][branch] = "7.x-2.x"

projects[views_savedsearches][type] = module
projects[views_savedsearches][subdir] = "contrib"
projects[views_savedsearches][version] = "7.x-dev"
projects[views_savedsearches][download][type] = "file"
projects[views_savedsearches][download][url] = "http://s4.csumb.edu/hosted_modules/views_savedsearches.tar.gz"

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

; Patches
projects[wysiwyg][patch][] = "http://drupal.org/files/issues/wysiwyg-entity-exportables-624018-176_1.patch"
projects[token][patch][] = "http://drupal.org/files/issues/modules_token.92.patch"
