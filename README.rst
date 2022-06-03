.. figure:: https://github.com/PicsArt/cppbind/tree/master/docs/_static/img/cppbind-logo.svg
   :width: 450px
   :height: 150px
   :target: #

Introduction
~~~~~~~~~~~~

CppBind is a software development tool that automates language bindings generation between C++ and other languages. 
It works by annotating C++ code to indicate parts desired to expose to all supported target languages.
The current version of the tool supports bindings with **Swift**, **Kotlin**, and **Python**, while support for new languages can be added relatively easily.

Manually developing bindings is complex, time-consuming, and error-prone, especially for large-scale projects requiring frequent changes. 
To develop manual bindings, one should be knowledgeable in both C++ and the target language to implement types serialization from one language to another, function and method mapping, and more. 
To overcome these challenges, we introduce CppBind.


CppBind main highlights:
========================

- Generates binding wrappers for multiple languages (Python, Swift, and Kotlin);
- Allows using language-agnostic annotations for all supported languages;
- Supports a rich set of C++ features;
- Provides the ability to add support for other languages;
- Can be used to generate bindings for third-party C++ libraries.

Features
~~~~~~~~

CppBind generates bindings for C++ types and entities like classes, methods, global functions, enums, nested structures, templates, etc. The list of the main features of CppBind is following:

- `Functions <https://cppbind.io/03_get_started/01_functions.html>`_
    - `Global functions <https://cppbind.io/03_get_started/01_functions.html#global-functions>`_
    - `Overloaded functions <https://cppbind.io/03_get_started/01_functions.html#overloaded-methods>`_
    - `Optional arguments <https://cppbind.io/03_get_started/01_functions.html#nullable-arguments>`_
    - `Default arguments <https://cppbind.io/03_get_started/01_functions.html#default-arguments>`_
    - `Return value’s lifetime and ownership management <https://cppbind.io/03_get_started/01_functions.html#return-value-policies>`_
    - `Controlling function arguments’ lifetime <https://cppbind.io/03_get_started/01_functions.html#keep-alive-policy>`_
-  `OOP <https://cppbind.io/03_get_started/02_classes.html>`_
    - `Classes and structs <https://cppbind.io/03_get_started/02_classes.html>`_
    - `Nested types <https://cppbind.io/03_get_started/02_classes.html#nested-types>`_
    - `C++ classes/structs as target language interfaces <https://cppbind.io/03_get_started/02_classes.html>`_
    - `Enumerations <https://cppbind.io/03_get_started/03_enums.html>`_
    - `Inheritance <https://cppbind.io/03_get_started/04_inheritance.html>`_
        - `Single inheritance <https://cppbind.io/03_get_started/04_inheritance.html#single-inheritance>`_
        - `Multiple inheritance through the target language interfaces <https://cppbind.io/03_get_started/04_inheritance.html#multiple-inheritance>`_
    - `Object type preservation <https://cppbind.io/04_advanced_features/05_object_type_preservation.html>`_
    - `Static methods <https://cppbind.io/03_get_started/01_functions.html#static-methods>`_
    - `Method overloading <https://cppbind.io/03_get_started/01_functions.html#overloaded-methods>`_
    - `Converting getters/setters to target language properties <https://cppbind.io/03_get_started/01_functions.html>`_
    - `Operator overloading <https://cppbind.io/03_get_started/08_operators.html>`_
        - `Overloading subscript operator <https://cppbind.io/03_get_started/08_operators.html#overloading-subscript-operator>`_
    - `Templates <https://cppbind.io/03_get_started/06_templates.html>`_
        - `Template classes <https://cppbind.io/03_get_started/06_templates.html#class-templates>`_
        - `Template methods and functions <https://cppbind.io/03_get_started/06_templates.html>`_
        - `Converting getters/setters with template parameters to target language properties <https://cppbind.io/03_get_started/06_templates.html#template-getters-setters>`_
    - `Exception handling <https://cppbind.io/03_get_started/05_exception_handling.html>`_
    - `Standard library types (std::shared_ptr, std::vector, std::map, etc.) <https://github.com/PicsArt/cppbind/tree/master/examples/primitives/cxx/containers>`_
    - `Custom type conversions <https://cppbind.io/04_advanced_features/02_custom_types.html>`_
    - `Intelligent code completion <https://en.wikipedia.org/wiki/Intelligent_code_completion>`_

Usage
~~~~~

CppBind instructions are controlled using annotations. There are two prominent use cases for annotating C++ source files: either you are the source code owner, or it’s from a third-party/standard library. CppBind annotations are specified directly in the source files in the first case. In the second case, separate config files can be used. The second use case works well for binding third-party C++ libraries.

- To configure a project with self-owned files, you can read our “Hello User” `tutorial <https://cppbind.io/02_first_steps/04_hello_user.html>`__.
- To configure a project with third-party/standard library files, you can read our “Array”  `tutorial <https://cppbind.io/02_first_steps/05_array_tutorial.html>`__.

Above-described usages can also be mixed: annotations for self-owned files are written inside those files, while third-party/standard library files are annotated via separate config files.

Installation
~~~~~~~~~~~~

There are some required steps to install and use CppBind. The installation steps are described `here <https://cppbind.io/02_first_steps/02_installation.html>`_.

License
~~~~~~~

CppBind is provided under the MIT license that can be found in the `LICENSE <https://github.com/PicsArt/cppbind/blob/master/LICENSE>`_  file. By using, distributing, or contributing to this project, you agree to the terms and conditions of this license.

How to contribute to CppBind?
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

If you like CppBind and would like to contribute to this open-source project, please check the `Contribution guide <https://github.com/PicsArt/cppbind/blob/master/docs/CONTRIBUTING.md>`_.
