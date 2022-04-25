.. iegen documentation master file, created by
   sphinx-quickstart on Wed Nov 25 12:15:00 2020.
   You can adapt this file completely to your liking, but it should at least
   contain the root `toctree` directive.

IEGEN
=====
**Welcome to IEGEN's documentation!**

Introduction
------------

IEGEN is a C++ bindings generation tool. For supported languages please refer to :ref:`supported-languages-label`. The tool can be easily extended for other languages as well. Also, it can be customized to have generated bindings better feet to your needs.

.. toctree::
   :maxdepth: 1
   :glob:
   :caption: Introduction

   /01_introduction/[0-9]*_*


First Steps
-----------

Are you writing C++ libraries and want to be able to use them in various platforms using various languages then IEGEN can be very handy tool for you.

:doc:`Installation </02_first_steps/02_installation>` |
:doc:`Tutorial </02_first_steps/03_hello_user>`

.. toctree::
   :maxdepth: 1
   :glob:
   :caption: First Steps
   :hidden:

   /02_first_steps/[0-9]*_*

Binding With Examples
---------------------

Let's start with :ref:`Basic example`.

.. toctree::
   :maxdepth: 2
   :caption: Binding With Examples
   :glob:

   /03_get_started/[0-9]*_*

Advanced Topics
---------------

.. toctree::
   :maxdepth: 2
   :hidden:
   :caption: Advanced Topics
   :glob:

   /04_advanced_features/[0-9]*_*

Detailed Information
--------------------

.. toctree::
   :maxdepth: 2
   :hidden:
   :caption: Detailed Information
   :glob:

   /05_detailed_info/[0-9]*_*

FAQs
----

.. toctree::
   :maxdepth: 1
   :hidden:
   :caption: FAQs
   :glob:

   /06_faqs/[0-9]*_*

API Documentation
=================

.. autosummary::
   :toctree:
   :caption: API Documentation
   :recursive:

   iegen


Indices and tables
------------------

* :ref:`genindex`
* :ref:`modindex`
* :ref:`search`


License
------------------
IEGEN is provided under a MIT license that can be found in the `LICENSE <https://github.com/PicsArt/iegen/blob/master/LICENSE>`_ file.
By using, distributing, or contributing to this project, you agree to the terms and conditions of this license.