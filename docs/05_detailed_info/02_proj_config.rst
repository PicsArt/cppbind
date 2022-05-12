Project Configuration
^^^^^^^^^^^^^^^^^^^^^

Project configuration is done in yaml format files which should be placed under project directories.
In yaml files we define parameters which affect generated results and the tool behavior (e.g. input sources and output directories, etc.).
User can have a single or multiple configuration files in yaml format spread across the project.
CppBind looks up at those files by pattern defined in application config file via **context_def_glob** parameter. The default value of **context_def_glob**
parameter is **\**/*cppbind.yaml** which means any file in the project having **cppbind.yaml** suffix.
This means that if you use this default value then you'll need to have a project config file with a name suffixed with **cppbind.yaml**.
This value can be changed in application config file: :doc:`App config </05_detailed_info/01_app_config>`.

.. collapse:: An example of project config file

    |

    .. literalinclude:: /../examples/tutorials/hello_user/cxx/cppbind.yaml
        :language: yaml

|

Project config file can contain six top level main sections:

* var_def

* vars

* rules

* dir_vars

* file_vars

* type_vars

Section **var_def**
~~~~~~~~~~~~~~~~~~~

CppBind project configuration is done by variables written in doxygen API comments. CppBind provides a set of default variables that are defined under **var_def** section.
This section is a mandatory section in project config file and should be defined only once per project.
CppBind will complain about redefinition in multiple config files. More details on variables definitions you can find :doc:`here </05_detailed_info/03_var_def>`.

Section **vars**
~~~~~~~~~~~~~~~~

**vars** is a mandatory section where user sets root level config variables. Here user can set/override variables defined under **var_def** section.
For example, user can set the value of **src_glob** variable, thus controlling which C++ source files must be processed by CppBind.
This section also should be defined only once per project. The full list of default variables provided by CppBind is available :doc:`here </05_detailed_info/03_var_def>`.

Section **rules**
~~~~~~~~~~~~~~~~~

**rules** section is a mandatory section which contains code snippets, type converter snippets and action snippets needed to generate bindings for target languages.
**rules** sections can be spread across the project. We merge them together by platform and language specifications.
This mechanism allows users to have their own custom converters. Merging will allow user to keep custom converter files
in the same directory where the corresponding type is defined.
CppBind can be run only for languages having corresponding snippets under **rules** section. Currently CppBind includes snippets for **Swift**, **Kotlin** and **Python** languages in default rules definition.
In order to disable a language it's enough to remove its snippets from **rules** section.
For more detail see :doc:`Snippets </04_advanced_features/03_snippets>`.

Here is the minimal rules configuration for Swift, Kotlin and Python languages:

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

**Join** and **include** are yaml helpers which allow user to define configuration in different files and then combine them in a single place.

Actually you don't need to care about **rules**, **var_def** sections unless you are writing your own custom type converters.
If you are going to use the default behavior of CppBind with the default converters you can just use a command line utility provided by CppBind to initialize your project config file.
To generate initial configuration user should run **cppbind init** under project directory.
The command will create **cppbind.yaml** file containing the default initial config example.
You may deal with **vars** section to define/override root level configuration variables.
This section defines variables which are common for the whole project, but they can be overridden on the allowed entities (dirs, files, classes, etc.).

Section **dir_vars**
~~~~~~~~~~~~~~~~~~~~

**dir_vars** optional section is used to define variables for specific directories. Here is an example:

.. code-block:: yaml

    dir_vars:
      - dir: "path_of_dir"
        vars:
          python.action: gen_package
          name: simple

In this example **dir_vars** section is used to generate a package for the given directory. The path of the directory must be provided via **dir** key.
We support two types of directory paths: if the path starts with "/", then the path is relative to the CppBind project root directory. Otherwise the path
is being considered as relative to the directory where the config file is located. **vars** subsection is used to define variables.

Section **file_vars**
~~~~~~~~~~~~~~~~~~~~~

Similar to **dir_vars** we also have **file_vars** optional section to define API for specific files. The usage and definition are the same as for directories.
To define file path user needs to use **file** key:

.. code-block:: yaml

    file_vars:
      - file: "path_of_file"
        vars:
          python.code_fragment: fragment_of_some_code

.. _external-api-label:

Section **type_vars**
~~~~~~~~~~~~~~~~~~~~~

**type_vars** optional section is designed to give the user opportunity to describe API annotations outside of the source file.
This section is similar to **dir_vars** and **file_vars** sections but allows user to define API for types/functions.
The main use case of this feature is the generation of bindings for types/functions from the standard library or a third party library.
CppBind uses this feature to generate bindings for standard exceptions. More details can be found :doc:`here </03_get_started/05_exception_handling>`.

To define API annotations we need to use **type** key. CppBind supports two ways to specify the type.
The first way is to specify the full C++ signature of the entity (class, struct, method, property, etc.):

.. code-block:: yaml

    type_vars:
      - type: "NamespaceExample::ClassExample::methodExample(int)"
        vars:
          action: gen_method
          throws: no_throw

CppBind also supports the structure with nested form of definition, where ``::`` symbols are used as the sign of a subsection:

.. code-block:: yaml

    type_vars:
      - type: NamespaceExample
        ::
        - type: ClassExample
          ::
          - type: "anotherMethodExample(std::string)"
            vars:
              action: gen_method
              throws: no_throw

.. note::
    User can define API only once for each type/function. For the same annotation user can have only one type of definition: either with full signature or with nested structure.
    CppBind will report about merge conflicts and redefinitions.

**dir_vars**, **file_vars** and **type_vars** sections also can be spread across the project and CppBind will merge them similar to **rules** section.
