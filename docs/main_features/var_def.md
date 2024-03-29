# Variable definitions

While processing source C++ files, CppBind constructs an internal
tree-like structure (IR) which consists of entities corresponding to
project directories, files, classes, functions, etc. The entities in IR
have parent-child relationship defined via the following hierarchy:
**root** -\> **directory** -\> **file** -\> **class** -\>
**method/property**. To tell CppBind that the entity will be exposed to
the target language, the user defines API in doxygen style comments or
under the **type_vars** section as described here:
[Section type_vars](../configuration/proj_config.md#section-type_vars).
Project configuration is described through the variables used inside API
annotations. Using variables allows defining the following: which code
should be parsed, how the target code should look, where output should
be stored, etc. Variables must be defined under the **var_def** section
of the project yaml configuration file. CppBind provides a default list
of variables.

??? "The list of all variables"
    ~~~Yaml
    {% 
    include "../../src/cppbind/config/variable_definitions.yaml" 
    %} 
    ~~~

Each variable has the following properties:

-   **inheritable** indicates whether the variable's value can be
    inherited from the parent entity or not.
-   **default** indicates the default value of the variable. The default
    value is used when the variable isn't explicitly defined by the
    user and is not inherited from the parent entity.
-   **allowed_on** indicates parts of the code (files, classes, etc.)
    where the variable is allowed to be defined. CppBind complains about
    the definition of a variable on a disallowed entity.
-   **required_on** indicates the parts of code (files, classes,
    methods, etc.) where defining the variable is mandatory.
-   **type** is the type of variable value. Supported types are
    str, bool, list, and dict. If the type is not defined explicitly,
    CppBind sets it to str. CppBind complains about the definition of
    a value other than the variable type.
-   **description** is an optional property that gives additional
    information on the variable.
-   **options** is the list of possible values of the variable. If this
    property is set, the user can't define any other value of the
    variable out of this list.

Values for the property **allowed_on** are divided into groups:

- **file_system** - includes **dir** and **file**.
    **dir** - variable can be defined on a directory.
    **file** - variable can be defined on a file.

- **cxx_method** - includes **method** and **method_template**.

- **cxx_constructor** - includes **constructor** and **constructor_template**.

- **cxx_function** - includes **function** and **function_template**.

- **cxx** - includes **class**, **class_template**, **struct**,
    **struct_template**, **constructor**, **constructor_template**, **function**,
    **function_template**, **method**, **method_template**, **enum** and **field**.

- **cmd_line** - includes **cmd_line** and **root**.
    The values mentioned above are special keywords that show the kind
    of corresponding entity.
    Variables allowed on **root** are the ones common for the whole
    project.
    For example, **out_prj_dir** should be defined once and is allowed
    only on root.
    There can also be variables allowed on the root but can be
    overridden. An example of such variable is **comment_del_regex**
    which is allowed also on **cxx** and **file_system**.
    For example, it can be defined for the whole project but
    overridden for a single file.
    **cmd_line** indicates that the variable is allowed on the root
    and can be provided/modified through command-line arguments.
    For setting/modifying root variable from the command-line, the
    user needs to provide a value for the command-line option:
    `--target_arch=arm64`.
    User can also specify platform/language-specific value:
    `--mac.python.target_arch=arm64`. The value provided by the
    command-line overwrites the one defined in the **vars** section.
    Note that if you use only **root** as a value for the
    **allowed_on** property, the variable cannot be overridden from
    the command-line.

If the variable is allowed on all the group members, then the group can
be used as the value of the **allowed_on** property. If a variable
doesn't have **allowed_on** property, then it's allowed on all
entities.

If the user does not specify a value for a variable, then the default
value is used. There are predefined variables that can be used to
define the default value for the variable or assign a new value. Here is
the list of that variables:

- **path** - os.path module (mainly used to join paths).
- **getenv** - os.getenv module (used for getting environment
    variables).
- **\_object_kind** - kind of the processed object, e.g root, dir,
    class etc.
- **\_current_working_dir** - current working directory.
- **\_source_modification_time** - source code modification time.
- **\_output_modification_time** - unique datetime-based key which is
    used for comparing previously generated code with the new one.
- **\_pure_comment** - doxygen style comment without CppBind API part.
- **\_line_number** - the line number of the processed source code.
- **source_file_fullname** - full path of the processed file.
- **\_file_name** - the name of the processed file.
- **\_is_operator** - indicates whether the method is a C++ operator
    or not.
- **\_object_name** - the name of the processed object, e.g., class
    name, method name, etc.
- **\_cppbind_extras_dir** - the path of the directory containing
    CppBind configuration default files.
- **cppbind_helper** - Python helper module containing helper utility functions.
- **\_get_git_repo_url** - Python helper function to get the git repo URL
    corresponding to the directory passed as an argument to this function.
- **get_android_ndk_sysroot** - internal helper function to
    dynamically construct android ndk sysroot path using android ndk
    installation path.

The variables which are defined before the definition of the current variable
also can be used in the default value definition.
In case the variable is inheritable, its parent entity context (available variables)
is also available when defining the default value of the variable.

Users can write jinja expressions in the **vars** section, API
annotations, and variable default values definitions. Those expressions
are being evaluated with the help of the system and current context
variables. Mainly, when compiling courses on macOS to generate android
Kotlin bindings, clang must be provided with **sysroot** and **target**
options. For this purpose, there is a **target_arch** parameter with
**x86_64** default value, and it can be overwritten with command-line
arguments or within the **vars** section. To use this feature user needs
to set the **clang_args** variable properly. We have it done in our
project default config file:

``` yaml
mac.kotlin.target_arch: x86_64
mac.kotlin.clang_args:
  - --target={{target_arch}}-none-linux-android
  - --sysroot={{get_android_ndk_sysroot(getenv('ANDROID_NDK'))}}
```

Now let's go through the key variables:

- **action** - indicates what should be generated: class, method, etc.
    Details are [here](../main_features/gen_actions.md).

- **file** - output file name.

- **package** - package name which is used with **package_prefix** to
    generate the final package ({package_prefix}.{package}).

- **name** - name of the class, method, etc. If not specified, then
    the original name is used.

- **argument_label** - dictionary to define the mapping from function
    original argument names to argument labels. Currently used only for
    Swift. See more details here: 
    [Custom argument names and labels](../main_features/functions.md#custom-argument-names-and-labels).

- **argument_name** - dictionary to define the mapping from function
    original argument names to changed argument names. Used to change
    function argument names for the target language. See more details
    here: [Custom argument names and labels](../main_features/functions.md#custom-argument-names-and-labels).

- **interface_name** - name for the generated interface when action is
    **gen_interface**.

- **interface_impl_class_name** - implementation class's name for
    the languages that do not support multiple inheritance.
    It's used with **interface_name**. For example, if we have a
    class marked with **action: gen_interface**, then for Kotlin there
    is an interface named **interface_name** and the implementation
    class named **interface_class_name**.

- **include** - additional includes added in the generated bindings of
    the target language.

- **code_fragment** - code snippets appended to the target code
    depending on what was tagged with this variable.
    For example, if an enum is tagged with this variable, the code
    fragment is appended to the generated enum.

- **header_code_fragment** - Code snippets added right before the
    generated part of the code.
    For example, if an enum is tagged with this variable, a code
    fragment is added before the generated enum.

- **footer_code_fragment** - code snippets added right after the
    generated part of the code.
    For example, if an enum is tagged with this variable, a code
    fragment is added after the generated enum.

- **include_cxx** - additional C++ includes added to generated C
    bindings.

- **shared_ref** - variable to define how the underlying C++ object is managed. If set
    to false, the underlying object is kept as a raw pointer, otherwise it is managed by a shared pointer.
    More on memory management can be found [here](memory_management.md).

- **template** - variable for template types/functions to specify all
    possible types for template parameters. More details are
    [here](../main_features/templates.md).

- **is_operator** - variable to indicate whether the C++ method is
    an operator or not. Although its default value is True for
    operators and False otherwise,
    there might be cases the C++ operator does not have a matching
    operator in the target language, or the user wants to generate a
    regular method instead.
    For such cases, this variable can be used to override the default
    value. More details and use cases can be found
    [here](../main_features/operators.md).

- **is_exception** - indicates an exception class that should be
    generated (an object of this class may be thrown in the target
    language).

- **throws** - mandatory variable for all methods. It indicates what
    type of exceptions method can throw.

- **bases_list** - variable to define extra types that are
    additionally implemented by the target type.

- **nullable_return** - indicates whether the function can return null
    value or not. Details are here: [Nullable arguments](../main_features/functions.md#nullable-arguments).

- **nullable_arg** - list of arguments that can have null value.
    Examples are here: [Nullable arguments](../main_features/functions.md#nullable-arguments).

- **project_dir** - root directory of C++ source code, which will be
    parsed.

- **project_link** - link to project source code. The default value is
    the git repo link if it uses git for version control and an empty
    string.

- **comment_del_regex** - regular expressions to define parts of the
    comment that should not go to the generated code. The text between
    **internal** and **endinternal** doxygen commands will be ignored
    by default.
    If the comment contains only **internal**, then everything after
    it is ignored.

- **banner_comment** - banner comment used with the CppBind logo as a
    file header for all CppBind generated files.

- **out_prj_dir** - root directory of project output. All includes and
    imports are generated relative to this directory.

- **cxx_out_dir** - root directory where all C bindings is stored.

- **out_dir** - directory where generated target language files is
    saved.

- **is_proj_type** - boolean showing whether the given type is the
    user's type or from standard/3pty lib.

- **enable_source_link_in_comment** - boolean variable to define
    whether source link information should be present in the comments of
    generated code or not.

- **comment** - target code comment. By default, it's a pure comment
    without parts that match the pattern defined via
    **comment_del_regex**.

- **prj_rel_file_name** - source file name relative to project root
    directory.

- **package_prefix** - package prefix where generated files is saved.

- **helpers_package_prefix** - path relative to **out_dir** where
    target language helpers are copied from **helpers_dir**.

- **helpers_out_dir** - directory where helper/util files are
    copied. The default value is based on **helpers_package_prefix**,
    when setting the value for this variable consider updating the
    value of **helpers_package_prefix** as well, otherwise Python
    imports would be broken.

- **cxx_helpers_out_dir** - directory where C helper/util files are copied.
    The default value is **cxx_out_dir**.

- **exception_helpers_package** - package name of standard exception
    helpers.

- **exception_file_name** - file name of standard exception helpers.

- **cxx_helpers_dir** - CppBind C++ helpers directory.

- **helpers_dir** - directory containing CppBind helpers.

- **overloading_postfix** - postfix appended at the end of the
    generated C binding function name if the function is overloaded.

- **file_postfix** - postfix appended to each generated file.

- **pybind_module** - package name of the generated pybind package.
    This variable is only used for Python.

- **c_wrapper_lib_name** - library name for generated bindings.

- **target_arch** - variable for setting target architecture.

- **clang_args** - command-line arguments passed to clang.

- **src_glob** - file glob to define source code files that must be
    processed by clang.

- **src_exclude_glob** - patterns to exclude files from processing
    list.

- **include_dirs** - include directories required for parsing. These
    directories are passed to the clang parser.

- **extra_headers** - extra headers to be processed. For example,
    CppBind uses this variable to process standard exception headers to
    generate target language bindings.

- **enum_case_name_prefix** - string which is added as a prefix of
    enum fields names.

- **enum_excluded_cases** - list of enum cases that must not be
    exposed in the target language.

- **cxx_helpers_out_rel_path** - C helpers output relative path to project
    output directory. This variable is used for constructing generated C
    includes.

- **full_package** - full package constructed from package_prefix
    and package. For each target language the construction formula for
    default value is different.
    Note that it's used for Python and Kotlin for target package
    generation and changing it affects generated file paths as well.
    This variable needs to be synchronized with **c_file_fullname**,
    **h_file_fullname** and **file_fullname**.

- **c_file_fullname** - generated cpp file full name.

- **h_file_fullname** - generated header file full name.

- **file_fullname** - generated target language file full name. The
    value of this variable must be synchronized with **full_package**
    to correctly generate Python and Kotlin packages.
    **Note:** Currently, it is not used for Python which means
    updating it won't affect on the generated code, instead
    **full_package** is used for file full name generation.

- **pybind_module_filename** - generated pybind file name containing
    pybind module code.

- **c_pybind_filename** - generated pybind cpp file name containing
    code which binds all submodules.

- **h_pybind_filename** - generated pybind header file name containing
    includes of all submodules.

- **descendants** - list of all derived types of current type. Details
    can be found [here](../main_features/object_type_preservation.md).

- **return_value_policy** - policy to define return value lifetime and
    ownership. Details can be found here:
    [Return value policies](../main_features/functions.md#return-value-policies).

- **keep_alive** - list containing indices of arguments whose
    lifetimes should be bound to `this` object's lifetime. The indices
    are 1-based. See more details here:
    [Keep alive policy](../main_features/functions.md#keep-alive-policy).

- **is_c\_wrapper_external** - boolean to define whether the C binding
    helpers must be included as from external lib or not (generate
    include within `<>` diamonds or not).

- **hash_method** - the name of hash method in C++. If users have
    annotated a method with this name then in each target language an
    appropriate hash method will be generated. The variable is allowed
    on **root** and should be defined once per project.

- **equals_method** - the name of equals method in C++. If users have
    annotated a method with this name then in each target language an
    appropriate equals method/operator will be generated. The variable
    is allowed on **root** and should be defined once per project.

- **tostring_method** - the name of toSting method in C++. If users
    have annotated a method with this name then in each target language an
    appropriate string converting method will be generated. The variable is
    allowed on **root** and should be defined once per project. 

- **is_overridden** - variable to allow users to define whether the method 
    is overridden or not in the target language. If this variable is not specified
    then CPPBind will detect if the method is overridden in C++ 
    and apply it to the target language. This variable might be useful when 
    the name of the method is changed in a way that makes it overridden in the target language.
    In that case the user should explicitly set the value of **is_overridden** to **True**.
    See **ElectricBicycle** class example here:
    [is_overridden example](../main_features/inheritance.md#single-inheritance).

!!! Note
    The default value and other properties can be easily overridden.
    An example demonstrating this:

    ``` yaml
    var_def:
    !join
    - !include variable_definitions.yaml
    banner_comment:
        inheritable: false
        default: My custom banner comment
        allowed_on: [ cxx, file_system ]
    ```

    Banner comment is overridden here.

!!! Note
    It's forbidden to use any other variable that is not listed under the
    **var_def** section.

!!! Note
    Each variable can have a platform and language-specific values. For this
    purpose, the variable should be prefixed with platform and/or language,
    like:

    > ``` yaml
    > name: Task
    > python.name: PyTask
    > mac.name: MacTask
    > mac.python.name: MacPyTask
    > ```
    >
    > These are four possible ways to define variable values. Note that you
    > cannot have **<language\>.<variable\>** and
    > **<platform\>.<variable\>** at the same time. In this case the value
    > for **<platform\>.<language\>.<variable\>** is ambiguous and
    > CppBind complains about it. Another important thing is that default
    > values also can be specified per platform/language. To specify
    > platform/language-specific default value user needs to use platform
    > and/or language specifier in front of the **default** keyword, e.g:
    > **<platform\>.<language\>.<default\>**.
    >
    > There is a priority order when defining platform/language-specific
    > values. When the user has mixed types of specifications, we pick the
    > one with the highest priority. For example, if the user specifies
    > values for **mac.python.name**, **python.name**, **name**, we pick the
    > first one when generating bindings for mac+python. It means we pick
    > the maximum specified option.
