.. cppbind documentation master file, created by
   sphinx-quickstart on Wed Nov 25 12:15:00 2020.
   You can adapt this file completely to your liking, but it should at least
   contain the root `toctree` directive.

.. include:: ../README.rst

.. _supported-languages-label:

Supported languages
~~~~~~~~~~~~~~~~~~~

Currently CppBind supports bindings generation for the following languages:

- Kotlin
- Swift
- Python

Kotlin
------

In order to expose C++ types and functions to Kotlin CppBind uses JNI framework which enables Java/Kotlin code running in JVM
to call a native program. CppBind generates Kotlin API code which is bridged with original C++ code via generated JNI bindings.

Swift
-----

Swift language gives an opportunity to access and use pieces of code written in C. CppBind uses Swift and C interoperability
to create a bridge between Swift and C++ codes. The connection is created via generated C and Swift bindings.

Python
------

To connect Python and C++ code CppBind generates `pybind <https://github.com/pybind/pybind11>`_ code. CppBind also generates Python API which is a wrapper for pybind codes.

.. note::
    Using pybind as an intermediate layer between C++ and Python brings some limitations to CppBind.
    For example, pybind has a support for exceptions which allows CppBind to transfer custom exceptions from C++ to Python
    only as RuntimeError, thus losing the reference to the original exception type. Currently this limitation exists only for Python.
    More detailed information is available :doc:`here </03_get_started/05_exception_handling>`.

    Besides the limitations pybind gives us opportunity to support some more features for Python. For example, currently we have a support
    for callbacks only for Python, but the similar feature is going to be developed for other languages as well.

.. note::
    Since CppBind generates Python API upon generated pybind bindings, we are able to add some logic before calling original
    pybind codes. For example, CppBind does some validations for nullable arguments, does implicit casts between
    provided and expected argument types if possible, supports nested types. Generated Python functions has annotations with type hints
    which gives opportunity to navigate through the code inside IDE tools.

.. toctree::
   :maxdepth: 1
   :glob:
   :caption: First Steps

   /02_first_steps/[0-9]*_*

.. toctree::
   :maxdepth: 2
   :caption: Binding With Examples
   :glob:

   /03_get_started/[0-9]*_*

.. toctree::
   :maxdepth: 2
   :caption: Advanced Topics
   :glob:

   /04_advanced_features/[0-9]*_*

.. toctree::
   :maxdepth: 3
   :caption: Detailed Information
   :glob:

   /05_detailed_info/[0-9]*_*

.. toctree::
   :maxdepth: 1
   :caption: FAQs
   :glob:

   /06_faqs/[0-9]*_*

API Documentation
=================

.. autosummary::
   :toctree:
   :caption: API Documentation
   :recursive:

   cppbind


Indices and tables
==================

* :ref:`genindex`
* :ref:`modindex`
