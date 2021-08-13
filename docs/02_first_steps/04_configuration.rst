Configuration
=============

IEGEN's configuration is described in yaml format files which should be placed under source code directories
and iegen_config.cfg file which should be placed under current working directory.
Configuration is used to define input and output sources as well as to define parameters which will affect on generated results and tool behaviour.

iegen_config.cfg contains the following main sections.

* Application_
* API_
* Log_


Configuration Example
^^^^^^^^^^^^^^^^^^^^^
Let's now go through the sections and config parameters.

.. code-block:: ini

    [APPLICATION]
    ;context_def_glob = **/*iegen.yaml
    rule = rules/snippets.py
    ;custom_config_dir = ''
    all_languages = kotlin, swift, python
    all_platforms = android, ios, linux, mac, win

    [API]
    parser_start = __API__

    [LOG]
    log_file =
    level = INFO

.. note::
   If required parameter is missing from your configuration IEGEN default value for that parameter will be used.

.. note::
   Keys in sections are case-insensitive and stored in lowercase.

APPLICATION
^^^^^^^^^^^

The APPLICATION section defines parameter's related the whole application.
Let's go over parameters from this section.

  - **custom_config_dir** - Directory containing user defined configuration files in yaml format. See section.
  - **context_def_glob**  - Pattern of yaml files where other all other configuration is defined. This parameter is mandatory.
  - **rule** - Here we define jinja templates contexts. If user does not want to generate custom code then there's no need specify this parameter.
  - **all_languages** - Supported languages.
  - **all_platforms** - Supported platforms.

API
^^^

  - **parser_start** - Tag in the doxygen comment after which everything is considered as instructions for iegen.

LOG
^^^

  - **log_file** - Log file.
  - **level** - Log level.


All parameters except **context_def_glob** are not mandatory.

All other configuration like where should be generated output files, what arguments should be passed to parser etc. should be described in yaml
files which path should be defined with **context_def_glob** parameter in iegen_config.cfg file.

Now let's go through the yaml configuration. User can have a single or multiple yaml configuration files spread across the project.
There are five main sections:
 * rules
 * vars
 * var_def
 * dir_vars
 * type_vars

Rules, vars and var_def should be defined only once per project.
To generate minimal yaml config file run `iegen init` under project directory.
This will create `iegen.yaml` file with minimal config example.


Rules contain code snippets, actions, type converter snippets.
This is the minimal rules configuration that each project should have:

.. code-block:: yaml

    rules:
      kotlin.code_snippets:
        !join
        - !include kotlin/code_snippets.yaml
      python.code_snippets:
        !join
        - !include python/code_snippets.yaml
      swift.code_snippets:
        !join
        - !include swift/code_snippets.yaml

      kotlin.type_converters:
        !join
        - !include "kotlin/*_types.yaml"
      python.type_converters:
        !join
        - !include "python/*_types.yaml"
      swift.type_converters:
        !join
        - !include "swift/*_types.yaml"

      kotlin.actions:
        !join
        - !include kotlin/actions.yaml
      python.actions:
        !join
        - !include python/actions.yaml
      swift.actions:
        !join
        - !include swift/actions.yaml

**Join** and **include** are helper constructs which allow defining configuration in different files and then combining them in a single place.

In **vars** section we define project's main configuration. Here we can have variables that are common for the whole project
and variables that can be overridden per directory or file or even for a piece of code.

All variables are described in **var_def** section.
More details on variables definitions here :doc:`Variable Definitions </02_first_steps/05_variable_definitions>`.
