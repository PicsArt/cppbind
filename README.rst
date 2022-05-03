TODO: [LOGO]

IEGEN
^^^^^

Description
~~~~~~~~~~~

IEGEN is a software development tool that generates bindings between C++ and other languages. This innovative solution helps developers bridge a code written in a programming language with C++ code. It is an error-prone and complex process to accomplish the bridging process manually, especially for large projects — every time new changes are required. Moreover, developers must learn many things about C APIs that connect the target language with C++.

IEGEN automates the process and solves the problems mentioned above.

The list of currently supported languages and additional information on their specifications can be found `here <https://iegen.picsart.com/master/index.html#supported-languages-label>`_. The tool can be extended to other languages as well. Also, it can be customized to generate bindings better fitting your needs.

Table of contents
~~~~~~~~~~~~~~~~~

* Installation_
* Usage_
* Tutorial_
* Credits_
* License_
* Features_
* `How to contribute`_

Installation
~~~~~~~~~~~~

There are some required steps to install and use IEGEN. The installation steps are described `here <https://iegen.picsart.com/master/02_first_steps/02_installation.html>`_.

Usage
~~~~~

After installing IEGEN, it is run through the command-line interface (CLI).
IEGEN CLI options are described `here <https://iegen.picsart.com/master/05_detailed_info/05_command_line_interface.html>`_.

Tutorial
~~~~~~~~

To configure and run IEGEN, read our tutorial example, which is called “Hello User.” This tutorial will help you learn about the basic usage of IEGEN and configure it for your project.

- Tutorial documentation: `"Hello User" doc <https://iegen.picsart.com/master/02_first_steps/03_hello_user.html>`_
- Tutorial GitHub sources: `"Hello User" GitHub <https://github.com/PicsArt/iegen/tree/master/examples/tutorials/hello_user>`_

Credits
~~~~~~~

The IEGEN tool is developed and open-sourced by PicsArt, Inc.

License
~~~~~~~

IEGEN is provided under the MIT license that can be found in the `LICENSE <https://github.com/PicsArt/iegen/blob/master/LICENSE>`_ file.
By using, distributing, or contributing to this project, you agree to the terms and conditions of this license.

Features
~~~~~~~~

IEGEN supports the generation of bindings for many types of entities from C++ source code.
For example, you can expose classes, methods, global functions, enums, exception types, nested structures,
template types, etc., to the target language. Here is the list of the most important features of IEGEN:

- `Classes and structs <https://iegen.picsart.com/master/03_get_started/02_classes.html>`_
- `Interfaces <https://iegen.picsart.com/master/03_get_started/02_classes.html>`_
- `Nested types <https://iegen.picsart.com/master/03_get_started/02_classes.html#nested-types>`_
- `Methods <https://iegen.picsart.com/master/03_get_started/01_functions.html>`_
- `Static and overloaded functions <https://iegen.picsart.com/master/03_get_started/01_functions.html#static-and-overloaded-methods>`_
- `Operator overloading <https://iegen.picsart.com/master/03_get_started/08_operators.html>`_
- `Single and multiple inheritance <https://iegen.picsart.com/master/03_get_started/04_inheritance.html>`_
- `Enumerations <https://iegen.picsart.com/master/03_get_started/03_enums.html>`_
- `Templates <https://iegen.picsart.com/master/03_get_started/06_templates.html>`_
- `Exception handling <https://iegen.picsart.com/master/03_get_started/05_exception_handling.html>`_
- `Return value policy, keep alive policy <https://iegen.picsart.com/master/03_get_started/01_functions.html#return-value-policies>`_
- `Default arguments <https://iegen.picsart.com/master/03_get_started/01_functions.html#default-arguments>`_
- `Nullables <https://iegen.picsart.com/master/03_get_started/01_functions.html#nullable-arguments>`_
- `Object type preservation <https://iegen.picsart.com/master/04_advanced_features/05_object_downcasting.html>`_
- `Properties and data accessors <https://iegen.picsart.com/master/03_get_started/01_functions.html>`_
- `Standard library types (std::vector, std::map, etc.) <https://github.com/PicsArt/iegen/tree/master/examples/primitives/cxx/containers>`_
- `Shared pointers <https://iegen.picsart.com/master/05_detailed_info/03_var_def.html#:~:text=generated%20C%20bindings.-,shared_ref,-%2D%20This%20variable%20is>`_
- `Full featured code assistance <https://en.wikipedia.org/wiki/Intelligent_code_completion>`_

How to contribute
~~~~~~~~~~~~~~~~~

To contribute to this project, follow the rules described in the `Contribution guide <https://github.com/PicsArt/iegen/blob/master/docs/CONTRIBUTING.md>`_.
