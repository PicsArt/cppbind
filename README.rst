TODO: [LOGO]

IEGEN
^^^^^

Description
~~~~~~~~~~~

IEGEN is a tool which generates bindings between C++ and other languages.
The list of currently supported languages and additional information about their specifications
can be found here: `Supported languages <https://iegen.picsart.com/master/index.html#supported-languages-label>`_.
The tool can be extended for other languages as well.
Also, it can be customized to generate bindings better fitting to your needs.

Table of contents
~~~~~~~~~~~~~~~~~

* Motivation_
* Installation_
* Usage_
* Tutorial_
* Credits_
* License_
* Features_
* `How to contribute`_

Motivation
~~~~~~~~~~

Sometimes it is necessary to bridge a code written in some languages with C++ code and doing this manually
for large projects is very difficult and error-prone. Developers need to learn lots of things about C APIs
which connects target language with C++. Also, it is difficult and error-prone to do manual changes to the big code
every time new changes are needed. IEGEN will automate the process and will solve above-mentioned problems.

Installation
~~~~~~~~~~~~

There are some required steps to install IEGEN and to be ready to use it.
The installation steps are described here: `Installation steps <https://iegen.picsart.com/master/02_first_steps/02_installation.html>`_.

Usage
~~~~~

After installing IEGEN it can be run via command line interface (CLI).
IEGEN CLI options are described here: `IEGEN CLI <https://iegen.picsart.com/master/05_detailed_info/05_command_line_interface.html>`_.

Tutorial
~~~~~~~~

To be able to configure and run IEGEN you can read our tutorial example which is called "Hello User".
This tutorial will help you to learn about the basic usage of IEGEN and be ready to configure it for your project.

- Tutorial documentation: `"Hello User" doc <https://iegen.picsart.com/master/02_first_steps/03_hello_user.html>`_
- Tutorial github sources: `"Hello User" github <https://github.com/PicsArt/iegen/tree/master/examples/tutorials/hello_user>`_

Credits
~~~~~~~

IEGEN tool is developed and open-sourced by PicsArt, Inc.

License
~~~~~~~

IEGEN is provided under a MIT license that can be found in the `LICENSE <https://github.com/PicsArt/iegen/blob/master/LICENSE>`_ file.
By using, distributing, or contributing to this project, you agree to the terms and conditions of this license.

Features
~~~~~~~~

IEGEN supports the generation of bindings for many types of entities from C++ source code.
For example, you can expose the following entities to the target language:

- `classes/nested structures <https://iegen.picsart.com/master/03_get_started/02_classes.html>`_
- `methods/functions/properties <https://iegen.picsart.com/master/03_get_started/01_functions.html>`_
- `classes involved in inheritance <https://iegen.picsart.com/master/03_get_started/04_inheritance.html>`_
- `enums <https://iegen.picsart.com/master/03_get_started/03_enums.html>`_
- `template classes/methods/functions <https://iegen.picsart.com/master/03_get_started/06_templates.html>`_
- `exception types <https://iegen.picsart.com/master/03_get_started/05_exception_handling.html>`_

How to contribute
~~~~~~~~~~~~~~~~~

To contribute to this project follow the rules described in the `Contribution guide <TODO: contribution_guide_link>`_.
