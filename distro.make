; Use this file to build a full distribution including Drupal core and the
; Student Signupinstall profile using the following command:
;
; drush make distro.make <target directory>

api = 2
core = 7.x

projects[drupal][type] = core
projects[drupal][version] = "7"

; Add Student Signup to the full distribution build.
projects[student_signup][type] = profile
projects[student_signup][version] = 1.x-dev
projects[student_signup][download][type] = git
projects[student_signup][download][url] = git://github.com/kevee/csu_student_signup.git 
projects[student_signup][download][branch] = main