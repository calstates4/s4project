[![Build Status](https://secure.travis-ci.org/kevee/csu_student_signup.png?branch=master)](http://travis-ci.org/kevee/csu_student_signup)

Introduction 
============
Students need to sign up for lots of things besides courses. Things like service learning, teacher education, or social work programs all need to track students outside the scope of a course or even a semester. The Signup Project will provide a way for a campus to track the relationships between community partners, site coordinators, students, faculty, courses, and programs; while being simple to maintain and easy (even fun!) to use.

This project is a collaboration between the CSUMB Web Services department and the Center for Community Engagement, at the Cal State Chancellor's office.

Documentation
=============
You can read **[full documentation on the S4 project](http://s4.readthedocs.org/en/latest/)**, hosted by readthedocs.org.

Installation
============

Requirements
------------
You should ensure that you have a system supported by Drupal version 7. You will also need a database supported by Drupal as well. Learn more about these minimum install requirements here:
http://drupal.org/requirements

Before installation, make a database for this application and create a user who has read/write/create privileges on that database only.

In addition, you should increase your web server PHP memory limit to at least 80M.

Installation process
--------------------
Once you have unpacked the site and created a database, go to the url mysite.com/install.php, make sure to select the "S4-Student signup for service and stuff" installation profile on the first screen. The installer will walk you through the setup process.

Note about Git repository
-------------------------
If you are checking out from GIT, this is not a complete site, it requires using Drush to build the make file. If you have downloaded the packaged version of the app, just put it in your app server, and visit mysite.edu/install.php and make sure to select the S4 install profile on the first screen.


