Variable Definitions
^^^^^^^^^^^^^^^^^^^^

Project configuration is described through the variables. Using variables we define which code should be parsed, how the target code should look like, where output should be stored, etc.
Let's go through the variables definitions and see how they are used.
Here is the list of variables:

.. literalinclude:: /../src/iegen/config/variable_definitions.yaml
   :language: yaml

Each variable has the following properties.

    * **inheritable** indicates whether variable is inherited from its parent or not.
    * **default** indicates the default value of variable.
    * **allowed_on** indicates on which parts of the code (files, classes, etc.) the variable is allowed to be used.
    * **required_on** indicates where the attribute is required on a specific parts of code (files, classes, methods, etc.).
    * **type** is the type of variable value. The default type is string (str). Other supported types are bool, list and dict.
    * **description** is an information to describe the purpose of the variable.

Values for the property **allowed_on** are divided into groups:

 * **file_system** - including **dir** and **file**.
 * **cxx** - including **class**, **class_template**, **struct**, **struct_template**, **constructor**, **function**, **function_template**, **cxx_method**, **enum** and **field**.
 * | **cmd_line** - including **cmd_line** and **root**.
   | Variables which are allowed on **root** are the ones which are common for the whole project.
   | For example **out_prj_dir** should be defined once and is allowed only on root.
   | There can be also variables that are allowed on root but can be overridden. An example of such variable is **comment_del_regex** which is allowed also on **cxx** and **file_system**.
   | For example this means it can be defined for the whole project but overridden for a single file.
   | **cmd_line** indicates that the variable is allowed on root but also can be provided/modified through command line arguments.
   | For setting/modifying root context value from command line user need to provide a value for command line option: `--target_arch=arm64`.
   | User can also specify platform/language specific value: `--mac.python.target_arch=arm64`. The value provided by command line will overwrite the one defined in `vars` section.
   | Note that if you use only **root** as a value for **allowed_on** property then the variable cannot be overridden from the command line.

If all values of the group are allowed then the group can be used instead.

If user does not specify a value for variable then the default value is being used.
There are predefined system variables which can be used for defining the default value for the variable.
Here is the list of system variables:

 * **_output_modification_time**: Unique key which is used for comparing previously generated code with new one
 * **_source_modification_time**: Source code modification time
 * **path** - os.path module (mainly used to join paths)
 * **getenv** - os.getenv module (used for getting environment variables)
 * **_current_working_dir** - current working directory
 * **_pure_comment**: doxygen comment without iegen API part
 * **_line_number**: line number of the source code which is being processed
 * **_file_full_name**: full path of the file which is being processed
 * **_is_operator** - indicates whether the method is a c++ operator or not.
 * **_object_name** - name of the project which is being processed, e.g. class name, method name etc.
 * **_file_name** - full name of the file which is being processed.
 * **get_android_ndk_sysroot** - internal function to dynamically construct android ndk sysroot path using android ndk installation path (retrieved from environment variable) and host platform value

In **vars** section, as well as in API annotations and variable default values definitions, user can write jinja expressions,
which will be evaluated using system variables and current context variables.
Particularly, when compiling courses on mac os to generate android kotlin wrappers, clang must be provided with **sysroot** and **target** options.
For this purpose we have **target_arch** parameter, which has `x86_64` default value and can be overwritten with command line arguments or within `vars` section.
To use this feature user need to set **clang_args** variable properly. We have it done in our project default config file:

.. code-block:: yaml

    mac.kotlin.target_arch: x86_64
    mac.kotlin.clang_args:
      - --target={{target_arch}}-none-linux-android
      - --sysroot={{get_android_ndk_sysroot(getenv('ANDROID_NDK'))}}


Now let's go through the variables one by one:

    - *action* - Indicates what should be generated: class, method, etc. Details are :doc:`here </02_first_steps/06_api_configuration>`
    - *file* - Output file name.
    - *file_full_name* - Full path of source file.
    - *package* - Package name which with **package_prefix** is used for generating the final package ({package_prefix}.{package}).
    - *name* - Name of the class, method etc. If not specified then the original name is used.
    - *interface_name* - When action is gen_interface this will be used as a name for the generated interface.
    - | *interface_class_name* - This variable is the name of the implementation class for the languages which do not support multiple inheritance.
      | It's used with **interface_name**. Let's assume we have marked Animal class with **action: gen_interface**.
      | For kotlin we will have an interface named **interface_name** and the implementation class named **interface_class_name**.
    - *include* - Additional includes that will be added in the generated file.
    - | *code_fragment* - Code snippets which will be appended to the target code depending on what was tagged with this variable.
      | For example if enum is tagged with this variable then code fragment will be appended to the generated enum.
    - *include_cxx* - Additional c++ includes which will be added to generated C wrappers.
    - *shared_ref* - This variable is to manage how the object will be hold. If set to false then the generated wrapper will create a regular pointer, otherwise a shared pointer.
    - *template* - This variable is used for template types/functions to specify all possible types for template parameters. More details are here: :doc:`Templates </03_get_started/06_templates>`.
    - | *is_operator* - This variable is to indicate whether the c++ method is operator or not. Although its default value is True for operators and False otherwise,
      | there might be cases that c++ operator does not have matching operator in the target language or user might want to generate a regular method instead.
      | For such cases this variable can be used to override the default value. More details and use cases you can find here :doc:`Operators </03_get_started/08_operators>.`
    - *is_exception* - To indicate that an exception class should be generated (an object of this class may be thrown in target language).
    - *throws* - This variable is mandatory for all methods. It indicates what type of exceptions method can throw.
    - *bases_list* - This variable is used to define extra types which target type will additionally implement.
    - *nullable_return* - Indicates whether the function can return null value or not. Details are here :doc:`Nullable values </03_get_started/07_nullables>`.
    - *nullable_arg* - The arguments which can be null, should be marked with this variable. Examples are here :doc:`Nullable values </03_get_started/07_nullables>`.
    - *project_dir* - Root directory of code which is going to be parsed.
    - *project_link* - Project source code link. The default value is git repo link if it uses git for version control and an empty string otherwise.
    - | *comment_del_regex* - Regex to delete unwanted pure comment parts. By default the text between \internal and \endinternal will be ignored.
      | Or if no \endinternal is specified then the text after \internal will be ignored.
    - *comment* - Target code comment. By default it's pure comment without parts that match the pattern defined via **comment_del_regex**.
    - *banner_comment* - Banner comment which is used with IEGEN logo as a file header for all iegen generated files.
    - *out_prj_dir* - Root directory of your output project. All includes and imports will be generated relative to this directory.
    - *run_dir* - Helper parameter used in other variables. Users also can have their custom variables to use within the config file.
    - *cxx_out_dir* - Root directory where all C wrappers will be stored.
    - *out_dir* - Directory where output files will be saved.
    - *cxx_base_out_dir* - The directory where iegen base classes are copied. If user does not want to use iegen base classes then there's no need to specify this variable.
    - *package_prefix* - Package prefix where generated files will be saved.
    - *helpers_package_prefix* - This is a path relative to **out_dir** where python helpers from **helpers_dir** are copied.
    - *helpers_include_prefix* - The generated python code might be used as a submodule. In this case we have to attach appropriate prefix to helper includes. This parameter is used for this purpose.
    - *common_helpers_dir* - This directory containing iegen standard helper files per language.
    - *cxx_helpers_dir* - Iegen c++ helpers directory. Might be different per language.
    - *helpers_dir* - Directory containing iegen helpers. This is different for each language.
    - *cxx_base_source_dir* - Iegen internal directory containing base classes.
    - *file_postfix* - Postfix which will be appended to each generated file.
    - *extension* - Target language file extension.
    - *pybind_module* - Package name of the generated pybind package. This variable is only used for python.
    - *c_wrapper_lib_name* - Library name for generated wrappers.
    - *clang_args* - Arguments passed to clang.
    - *src_glob* - File glob to define which source code files must be processed by clang.
    - *src_exclude_glob* - Patterns to exclude files from processing list.
    - *include_dirs* - Include directories required for parsing. These directories are passed to clang parser.
    - *extra_headers* - Extra headers to be processed. For example standard exceptions headers which are required to generate target language bindings for them.
    - *target_arch* - Variable for setting target architecture.
    - *enum_field_name_prefix* - A string which is added as a prefix of enum fields names.
    - *enum_excluded_fields* - A list of enum field names which must be not exposed in target language.

.. note::

   The default value and other properties can easily be overridden.
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

    Each variable can have platform, language specific values. For this purpose variable should prefixed with platform and/or language, like:

    .. code-block:: yaml

        name: Task
        python.name: PyTask
        mac.name: MacTask
        mac.python.name: MacPyTask

    These are four possible ways to define variable values.
    Note that you cannot have `<language>.<variable>` and `<platform>.<variable>` at the same time.
    In this case the value for `<platform>.<language>.<variable>` is ambiguous and iegen will complain about it.
    Another important thing is that default values also can be specified per platform/language. To specify platform/language specific value for
    default value, user need to use platform and/or language specifier in front of the `default` keyword, e.g: `<platform>.<language>.<default>`.

    There is a priority order when defining platform/language specific values. When user has mixed types of specifications we pick the one with the highest priority.
    For example, if the user specifies values for `mac.python.name`, `python.name`, `name`, we will pick the first one when generating wrappers for mac+python.
    It means we pick the maximum specified option.
