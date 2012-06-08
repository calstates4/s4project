====================
Installation process
====================

Installing S4 is relatively straightforward. You will need:

1. A database on a server supported by Drupal: Mysql (or Maria DB), SQL Lite, or PostgreSQL
2. An account that has all rights on the database (read more on the Drupal requirements page)
3. A web server with either Apache (reccomended) or Microsoft IIS (look at the above requirements page for more information)
4. Make sure the web server has at least PHP version 5.3
5. Make sure PHP has at least 85M of memory
6. You might want to read our scalability reccomendations as well to make the site more speedy.

Place the downloaded project into your web server and go to the path where you downloaded it. For example, if you placed it in the "signup" directory of your web server, visit "http://myhost.edu/signup." You could also setup a virtual host to give the project it's own domain name.

You will be shown the installation screen. From here, there's just a few forms to fill out:

1. Select the "S4-Student Signup for Service and Stuff" install profile
2. Select English
3. Enter the username, password, and db host information (you need to expand the "Advanced Options" to enter host information)
4. Wait for the installer
5. Enter the "superuser" account - this should only be used for technical administration
6. Visit the new site.

There are a few things that might trip you up, including:

1. `Changing the permission on the files directory <http://drupal.org/node/394704>`_ - The files directory stores any uploaded files to S4, sometimes this directory needs to have permissions setup manually.
2. `Setting up clean URLs <http://drupal.org/getting-started/clean-urls>`_ - Clean URLs means your site's URLS will look like http://mysite.edu/sites/my-site-name, instead of http://mysite.edu/?q=sites/my-site-name.
3. `Setup Cron <http://drupal.org/cron>`_ - Cron is used to do periodic maintenance tasks. For example, when you send emails, they are actually stored to be sent in batches throughout the day so S4 doesn't overwhelm your email server and potentially have it's emails marked as spam. Cron is an important thing to setup to ensrue your site is running smoothly.
4. Tune site performance - Your technical admin should visit ``admin/config/development/performance`` and enable the following settings:
  * Cache pages for anonymous users
  * Aggregate and compress CSS files
  * Aggregate JavaScript files.

Still having problems? You might want to read the `Troubleshooting installation problems page <http://drupal.org/documentation/install/troubleshoot>`_ on Drupal.org.