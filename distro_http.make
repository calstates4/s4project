; Use this file to build a full distribution including Drupal core and the
; Student Signupinstall profile using the following command:
;
; drush make distro.make <target directory>

api = 2
core = 7.x

projects[drupal][type] = core
projects[drupal][version] = "7"
projects[drupal][patch][] = "http://drupal.org/files/postgresql_index_length-1410102.patch"

; Add Student Signup to the full distribution build.
projects[student_signup][type] = profile
projects[student_signup][version] = 1.x-dev
projects[student_signup][download][type] = git
projects[student_signup][download][url] = https://github.com/calstates4/s4project.git
projects[student_signup][download][branch] = bootstrap-theme