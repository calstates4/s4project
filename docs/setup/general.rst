================
General S4 setup
================

These are general settings that affect everyone using the same instance of S4, and should be completed by a technical administrator.

Site-wide settings
------------------

To rename your website, click on **Site settings** then **Site name** under "General configuration, or going to ``admin/config/system/site-information``. From this form you can rename the site, and change the email address the site uses to send generic messages. You should not change the site homepage from the deafult "homepage."


Adding CAPTCHA protection to the site proposal form
---------------------------------------------------

If you plan on allowing anyone to propose a new site (see below if you want to disable this feature), you should protect that form with a `CAPTCHA <http://en.wikipedia.org/wiki/CAPTCHA>`_. S4 uses a text-based CAPTCHA, which is usually easier to use and more accessible than the messy image-based CAPTCHAs people are usually frustrated by. The CAPTCHA does require a free API key, which can be found at `textcaptcha.com <http://textcaptcha.com/register>`_. Once you have  akey, enter it at the form located at ``People > CAPTCHA > Text CAPTCHA`` or ``admin/config/people/captcha/textcaptcha``.

If you wish to use a different CAPTCHA solution, you can `download and install other CAPTCHA modules <http://drupal.org/project/captcha>`_ for your website (see :ref:`drupal`).

Turning off allowing anyone to propose a site
---------------------------------------------

By default, S4 allows anyone to propose a site to any program, which can greatly speed up the registration process for new sites. These proposed sites still have to go through the approval process (see :ref:`approval`), but some departments do not want to allow anyone to register a site. To turn this off, your *Technical Administrator* can go to ``People > Permissions > Roles > Anonymous`` or ``admin/people/permissions/1`` and uncheck the option **Site: Create new content**.