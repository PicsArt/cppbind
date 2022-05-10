.. _var-def-label:

Variable Definitions
^^^^^^^^^^^^^^^^^^^^

During the processing of source C++ files IEGEN constructs internal tree-like structure (IR) which consists of entities corresponding to project directories, files, classes, functions, etc.
The entities in IR have parent-child relationship, which is defined via the following hierarchy: **root** -> **directory** -> **file** -> **class** -> **method/property**.
To tell IEGEN that the entity is going to be exposed to the target language, user needs to define API in doxygen comments or under the **type_vars** section as described here: :ref:`external-api-label`.
Project configuration is described through the variables used inside API annotations. Using variables we define which code should be parsed, how the target code should look like, where output should be stored, etc.
Variables must be defined under **var_def** section of project yaml configuration file. IEGEN provides a default list of variables.

.. collapse:: The list of all variables

    |

    .. literalinclude:: /../src/iegen/config/variable_definitions.yaml
       :language: yaml

|

Each variable can have the following properties:

    * **inheritable** indicates whether the value of the variable can be inherited from the parent entity or not.
    * **default** indicates the default value of the variable. The default value is used when the variable isn't explicitly defined by the user and is not inherited from the parent entity.
    * **allowed_on** indicates on which parts of the code (files, classes, etc.) the variable is allowed to be defined. IEGEN complains about definition of a variable on not allowed entity.
    * **required_on** indicates the parts of code (files, classes, methods, etc.) where defining the variable is mandatory.
    * **type** is the type of variable value. If the type is not defined, IEGEN deduces it from the value of the variable. Supported types are str, bool, list and dict. IEGEN complains about definition of a value other than the type of the variable.
    * **description** is an optional property which gives additional information about the variable.
    * **options** is the list of possible values of the variable. If this property is set, user can't define any other value of the variable out of this list.

Values for the property **allowed_on** are divided into groups:

 * | **file_system** - includes **dir** and **file**.
   | **dir** - variable can be defined on a directory.
   | **file** - variable can be defined on a file.
 * **cxx** - includes **class**, **class_template**, **struct**, **struct_template**, **constructor**, **function**, **function_template**, **cxx_method**, **enum** and **field**.
 * | **cmd_line** - includes **cmd_line** and **root**.
   | The above mentioned values are special keywords that show the kind of corresponding entity.
   | Variables which are allowed on **root** are the ones which are common for the whole project.
   | For example, **out_prj_dir** should be defined once and is allowed only on root.
   | There can be also variables that are allowed on root but can be overridden. An example of such variable is **comment_del_regex** which is allowed also on **cxx** and **file_system**.
   | For example, this means it can be defined for the whole project but overridden for a single file.
   | **cmd_line** indicates that the variable is allowed on root but also can be provided/modified through command line arguments.
   | For setting/modifying root variable from command line user needs to provide a value for command line option: ``--target_arch=arm64``.
   | User can also specify platform/language specific value: ``--mac.python.target_arch=arm64``. The value provided by command line will overwrite the one defined in **vars** section.
   | Note that if you use only **root** as a value for **allowed_on** property then the variable cannot be overridden from command line.

If the variable is allowed on all the members of the group then the group can be used as the value of **allowed_on** property.

If user does not specify a value for variable then the default value is being used.
There are predefined system variables which can be used for defining the default value for the variable or assigning a new value.
Here is the list of system variables:

 * **path** - os.path module (mainly used to join paths)
 * **getenv** - os.getenv module (used for getting environment variables)
 * **_current_working_dir** - current working directory
 * **_source_modification_time**: source code modification time
 * **_output_modification_time**: unique datetime-based key which is used for comparing previously generated code with new one
 * **_pure_comment**: doxygen comment without IEGEN API part
 * **_line_number**: line number of the source code which is being processed
 * **_file_fullname**: full path of the file which is being processed
 * **_file_name** - the name of the file which is being processed.
 * **_is_operator** - indicates whether the method is a C++ operator or not.
 * **_object_name** - name of the object which is being processed, e.g. class name, method name, etc.
 * **_iegen_extras_dir** - the path of the directory which contains some IEGEN configuration default files.
 * **_helper_module** - Python helper module for the current target language which contains some helper functions.
 * **get_android_ndk_sysroot** - internal helper function to dynamically construct android ndk sysroot path using android ndk installation path

In **vars** section, as well as in API annotations and variable default values definitions, user can write jinja expressions,
which will be evaluated using system variables and current context variables.
Particularly, when compiling courses on macOS to generate android Kotlin bindings, clang must be provided with **sysroot** and **target** options.
For this purpose we have **target_arch** parameter, which has **x86_64** default value and can be overwritten with command line arguments or within **vars** section.
To use this feature user needs to set **clang_args** variable properly. We have it done in our project default config file:

.. code-block:: yaml

    mac.kotlin.target_arch: x86_64
    mac.kotlin.clang_args:
      - --target={{target_arch}}-none-linux-android
      - --sysroot={{get_android_ndk_sysroot(getenv('ANDROID_NDK'))}}


Now let's go through the key variables:

    - **action** - Indicates what should be generated: class, method, etc. Details are :doc:`here </05_detailed_info/04_gen_actions>`.
    - **file** - Output file name.
    - **file_fullname** - Full path of source file.
    - **package** - Package name which with **package_prefix** is used for generating the final package ({package_prefix}.{package}).
    - **name** - Name of the class, method, etc. If not specified then the original name is used.
    - **argument_label** - Dictionary to define the mapping from function original argument names to argument labels. Currently used only for Swift. See more details here: :ref:`arg-names-and-labels`.
    - **argument_name** - Dictionary to define the mapping from function original argument names to changed argument names. Used to change function argument names for the target language. See more details here: :ref:`arg-names-and-labels`.
    - **interface_name** - When action is gen_interface this will be used as a name for the generated interface.
    - | **interface_class_name** - This variable is the name of the implementation class for the languages which do not support multiple inheritance.
      | It's used with **interface_name**. For example, if we have a class marked with **action: gen_interface**, then for Kotlin we will have an interface named **interface_name** and the implementation class named **interface_class_name**.
    - **include** - Additional includes that will be added in the generated bindings of the target language.
    - | **code_fragment** - Code snippets which will be appended to the target code depending on what was tagged with this variable.
      | For example, if enum is tagged with this variable then code fragment will be appended to the generated enum.
    - | **header_code_fragment** - Code snippets which will be added right before the generated part of the code.
      | For example, if enum is tagged with this variable then code fragment will be added before the generated enum.
    - | **footer_code_fragment** - Code snippets which will be added right after the generated part of the code.
      | For example, if enum is tagged with this variable then code fragment will be added after the generated enum.
    - **include_cxx** - Additional C++ includes which will be added to generated C bindings.
    - **shared_ref** - This variable is to manage how the object will be held. If set to false then the generated binding will create a regular pointer, otherwise a shared pointer.
    - **template** - This variable is used for template types/functions to specify all possible types for template parameters. More details are :doc:`here </03_get_started/06_templates>`.
    - | **is_operator** - This variable is to indicate whether the C++ method is operator or not. Although its default value is True for operators and False otherwise,
      | there might be cases that C++ operator does not have matching operator in the target language or user might want to generate a regular method instead.
      | For such cases this variable can be used to override the default value. More details and use cases can be found :doc:`here </03_get_started/08_operators>`.
    - **is_exception** - To indicate that an exception class should be generated (an object of this class may be thrown in target language).
    - **throws** - This variable is mandatory for all methods. It indicates what type of exceptions method can throw.
    - **bases_list** - This variable is used to define extra types which target type will additionally implement.
    - **nullable_return** - Indicates whether the function can return null value or not. Details are here: :ref:`nullables-label`.
    - **nullable_arg** - The list of arguments which can have null value. Examples are here: :ref:`nullables-label`.
    - **project_dir** - Root directory of C++ source code which is going to be parsed.
    - **project_link** - Link to project source code. The default value is git repo link if it uses git for version control and an empty string otherwise.
    - | **comment_del_regex** - Regular expressions to define which parts of the comment should not go to the generated code. By default, the text between **internal** and **endinternal** doxygen commands will be ignored.
      | If comment contains only **internal** then everything after it will be ignored.
    - **comment** - Target code comment. By default, it's pure comment without parts that match the pattern defined via **comment_del_regex**.
    - **banner_comment** - Banner comment which is used with IEGEN logo as a file header for all IEGEN generated files.
    - **out_prj_dir** - Root directory of project output. All includes and imports will be generated relative to this directory.
    - **run_dir** - Helper parameter used in other variables. Users also can have their custom variables to use within the config file.
    - **cxx_out_dir** - Root directory where all C bindings will be stored.
    - **out_dir** - Directory where generated target language files will be saved.
    - **cxx_base_out_dir** - The directory where IEGEN helper types are being copied. If user does not want to use IEGEN base classes then there's no need to specify this variable.
    - **is_proj_type** - Boolean showing whether the given type is user's type or is the type from standard/3pty lib.
    - **prj_rel_file_name** - Source file name relative to project root directory.
    - **package_prefix** - Package prefix where generated files will be saved.
    - **helpers_package_prefix** - This is a path relative to **out_dir** where helpers from **helpers_dir** are copied.
    - **helpers_out_dir** - Directory where helper/util files must be copied to.
    - **exception_helpers_package** - Package name of standard exception helpers.
    - **exception_file_name** - File name of standard exception helpers.
    - **common_helpers_dir** - Directory containing IEGEN standard helpers.
    - **cxx_helpers_dir** - IEGEN C++ helpers directory.
    - **helpers_dir** - Directory containing IEGEN helpers.
    - **cxx_base_source_dir** - IEGEN internal directory containing base classes.
    - **overloading_postfix** - Postfix to be appended at the end of the generated C binding function name if the function is overloaded.
    - **file_postfix** - Postfix which will be appended to each generated file.
    - **extension** - The extension of generated target language files.
    - **pybind_module** - Package name of the generated pybind package. This variable is only used for Python.
    - **c_wrapper_lib_name** - Library name for generated bindings.
    - **target_arch** - Variable for setting target architecture.
    - **clang_args** - Command line arguments passed to clang.
    - **src_glob** - File glob to define which source code files must be processed by clang.
    - **src_exclude_glob** - Patterns to exclude files from processing list.
    - **include_dirs** - Include directories required for parsing. These directories are passed to clang parser.
    - **extra_headers** - Extra headers to be processed. For example, IEGEN uses this variable to process standard exceptions headers to generate target language bindings for them.
    - **enum_field_name_prefix** - A string which is added as a prefix of enum fields names.
    - **enum_excluded_fields** - A list of enum cases which must not be exposed in the target language.
    - **cxx_out_rel_path** - C output relative path to project output directory. This variable is used for constructing generated C includes.
    - | **full_package** - Full package constructed from package_prefix and package. This variable has different default value construction formula for each language.
      | Note that it's used for Python and Kotlin for target package generation and changing it will affect generated file paths as well.
      | Consider this when changing **c_file_fullname**, **h_file_fullname** and **target_file_fullname**.
    - **c_file_fullname** - Generated cpp file full name.
    - **h_file_fullname** - Generated header file full name.
    - **target_file_fullname** - Generated target language file full name.
    - **pybind_module_filename** - Generated pybind file name containing pybind module code.
    - **c_pybind_filename** - Generated pybind cpp file name containing code which binds all submodules.
    - **h_pybind_filename** - Generated pybind header file name containing includes of all submodules.
    - **descendants** - List of all derived types of current type. For details see :doc:`Object downcasting </04_advanced_features/05_object_downcasting>`.
    - **return_value_policy** - Policy to define return value lifetime and ownership. Details can be found here: :ref:`rv-policies`.
    - **keep_alive** - List containing indices of arguments which lifetimes should be bound to ``this`` object's lifetime. The indices are 1-based. See more details here: :ref:`keep-alive-policy`.
    - **is_c_wrapper_external** - Boolean to define whether the C binding helpers must be included as from external lib or not (generate include within ``<>`` diamonds or not).

.. note::

   The default value and other properties can be easily overridden.
   An example demonstrating this:

   .. code-block:: yaml

       var_def:
          !join
          - !include variable_definitions.yaml
          banner_comment:
              inheritable: false
              default: My custom banner comment
              allowed_on: [ cxx, file_system ]

   Banner comment is overridden here.

.. note::

    It's forbidden to use any other variable that is not listed under **var_def** section.


.. note::

    Each variable can have platform, language specific values. For this purpose variable should be prefixed with platform and/or language, like:

    .. code-block:: yaml

        name: Task
        python.name: PyTask
        mac.name: MacTask
        mac.python.name: MacPyTask

    These are four possible ways to define variable values.
    Note that you cannot have **<language>.<variable>** and **<platform>.<variable>** at the same time.
    In this case the value for **<platform>.<language>.<variable>** is ambiguous and IEGEN will complain about it.
    Another important thing is that default values also can be specified per platform/language. To specify platform/language specific default value
    user needs to use platform and/or language specifier in front of the **default** keyword, e.g: **<platform>.<language>.<default>**.

    There is a priority order when defining platform/language specific values. When user has mixed types of specifications, we pick the one with the highest priority.
    For example, if user specifies values for **mac.python.name**, **python.name**, **name**, we will pick the first one when generating bindings for mac+python.
    It means we pick the maximum specified option.
