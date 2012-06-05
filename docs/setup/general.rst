================
General S4 setup
================

These are general settings that affect everyone using the same instance of S4, and should be completed by a technical administrator.

Site-wide settings
------------------

To rename your website, click on **Site settings** then **Site name** under "General configuration, or going to ``admin/config/system/site-information``. From this form you can rename the site, and change the email address the site uses to send generic messages. You should not change the site homepage from the deafult "homepage."

The rest of your general site configuration can be found by going to **Site settings** then selecting **General configuration**. From here you can tweak the basic behavior of S4:

1. **Signing up with a site staff** - You can disable signing up with a site staff, which is useful if no programs on your campus use site staff for anything other than contact tracking (see :ref:`site-staff`).
2. **Enable registering as part of a course** - When disabled, registration is only avaialble to students who are part of a program, useful of no programs are using courses to track student service.
3. **Default length of service** - The number of days a typical signup will last. When a student registers with a site as part of a course, their last day is automatically the last day of the term (semester, etc.) the course belongs to. This can be tweaked on a per-course basis.
4. **Authentication** - When you setup authentication, you need to select which authentication method different users should use. This is used to generate the login links on the homepage (see :ref:`authentication`). The **Custom message* is displayed next to the login form (which users don't see if you use Shibboleth or CAS, as they are redirected to your single-signon page), and is useful to let users who might be logging in via LDAP that they should use their campus ID and hwo to change their password, etc.
5. **Welcome message** - Displayed on the right-hand side of the homepage for users who aren't logged in.
6. **Statistics message** - Displayed above the login information on the left-side of the website's homepage, the statistics message uses tokens (see :ref:`tokens`) to build a nice message illustrating the impact of your programs.
7. **Lead time for evaluation reminders** - How many days before a student's signup expires when an evaluation email should be sent out. While programs have control over the messaging of evaluation reminders, all programs have to have the same lead-time for sending evaluation email reminders (see :ref:`program-options`).

Adding CAPTCHA protection to the site proposal form
---------------------------------------------------

If you plan on allowing anyone to propose a new site (see below if you want to disable this feature), you should protect that form with a `CAPTCHA <http://en.wikipedia.org/wiki/CAPTCHA>`_. S4 uses a text-based CAPTCHA, which is usually easier to use and more accessible than the messy image-based CAPTCHAs people are usually frustrated by. The CAPTCHA does require a free API key, which can be found at `textcaptcha.com <http://textcaptcha.com/register>`_. Once you have  akey, enter it at the form located at ``People > CAPTCHA > Text CAPTCHA`` or ``admin/config/people/captcha/textcaptcha``.

If you wish to use a different CAPTCHA solution, you can `download and install other CAPTCHA modules <http://drupal.org/project/captcha>`_ for your website (see :ref:`drupal`).

Turning off allowing anyone to propose a site
---------------------------------------------

By default, S4 allows anyone to propose a site to any program, which can greatly speed up the registration process for new sites. These proposed sites still have to go through the approval process (see :ref:`approval`), but some departments do not want to allow anyone to register a site. To turn this off, your *Technical Administrator* can go to ``People > Permissions > Roles > Anonymous`` or ``admin/people/permissions/1`` and uncheck the option **Site: Create new content**.