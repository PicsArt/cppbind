.. iegen documentation master file, created by
   sphinx-quickstart on Wed Nov 25 12:15:00 2020.
   You can adapt this file completely to your liking, but it should at least
   contain the root `toctree` directive.

IEGEN
=====
**Welcome to IEGEN's documentation!**

Introduction
------------

IEGEN is a C++ bindings generation tool. For supported languages please refer to :ref:`features:Supported Languages`. The tool can be easily extended for other languages as well. Also, it can be customized to have generated bindings better feet to your needs.

.. toctree::
   :maxdepth: 1

   /01_introduction/getting-started-with-iegen
   about
   api


First Steps
-----------

Are you writing C++ libraries and want to be able to use it in various platforms using various languages then iegen can be very handy tool for you.

:doc:`Installation </02_get_started/02_installation>` | 
:doc:`Configuration </configuration>`

.. toctree::
   :maxdepth: 1
   :glob:
   :caption: First steps
   :hidden:

   /02_get_started/[0-9]*_*


.. toctree::
   :maxdepth: 2
   :hidden:

   /features

Let's start with :ref:`Basic example`.

.. toctree::
   :maxdepth: 2
   :caption: Getting started with
   :glob:

   /02_get_started/languages/**/*_getting-started-with-*


Tutorials
---------

Advance Topics
--------------

.. toctree::
   :maxdepth: 2
   :hidden:
   :caption: Advanced Features

   /user.guide
   /01_introduction/configuration
   /features

Examples
--------

User Gide
---------
:doc:`User Gide </user.guide>`

Developer Gide
--------------
:doc:`Developer Gide </developer.guide>`

Code Documentation
------------------

Indices and tables
------------------

* :ref:`genindex`
* :ref:`modindex`
* :ref:`search`
