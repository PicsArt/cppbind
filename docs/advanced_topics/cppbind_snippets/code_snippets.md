## About CppBind snippets

In order to generate binding codes for a target language, CppBind uses
snippets described in yaml files. CppBind uses the **jinja2** template
language to describe the logic inside snippets. During rendering process
appropriate context is passed to the snippets to be rendered.

There are three types of snippets: **code**, **type converter**, and
**action** snippets. Information about type converter snippets can
be found [here](../../advanced_topics/cppbind_snippets/type_converter_snippets.md).
Action snippets are described [here](../../advanced_topics/cppbind_snippets/action_snippets.md).

## Code snippets structure

Code snippets are used for classes, interfaces, functions, enums,
constructors, property getters/setters, files, directories, etc. A
snippet can be used to generate code into multiple files, such as C/C++
and target language code to implement binding logic between those
languages.

``` yaml
file:
  my_lang:
    file_path: |
      {{"my_lang" + pat_sep + [vars.file]|map('replace', '.', pat_sep)|path_join}}.my_lang
    scopes:
      - body
    content: |
      {{body}}

class:
  my_lang:
    body:
      scopes:
        - body
        - include
      content: |
        public class {{vars.name}} {
            // body of method
            {{body|string|indent}}
        }
```

In the above-described code you can see **file** block which defines
what files are going to be generated. The first level of this section is
**file** and under this level you can see **my_lang** section which is
used to describe file generation properties (path and content) for
**my_lang** dummy language. **class** code block is an example of code
snippets for generating a class for **my_lang** language. When
encountered with `action: gen_class` instruction, CppBind removes `gen`
prefix and searches for **class** section in code snippets. After
finding **class** section CppBind generates appropriate code in the file
defined by **file** section. The same mechanism is used for other
instructions (**gen_interface**, **gen_method**, etc.).

Here we have subsections under **class** parent section: **include**,
**body**, and these subsections are used to group generated code
fragments. There are also **scopes** defining subsections to gather
snippet values from the lower levels and use them in the current
section. For example, we use the function body inside the class. This
mechanism is implemented through the stack-like structure of scopes: the
scopes are like C++ entities (files consist of classes, classes contain
methods, etc.). The following structure allows CppBind to support nested
types: for example, we have **enum** section at the top level of code
snippets but the same snippets are used regardless our enum is nested or
not.

Actual snippets are described under **content** or **unique_content**
sections. **unique_content** section is used to generate unique lines or
code fragment. It is mainly used for `#include` directives to avoid
repetitions. This section can be controlled with special **marker**
variable: CppBind splits the content of rendered **unique_content**
section by **marker**, picks unique tokens and joins them to get the
final result.

## Available variables

CppBind provides predefined variables which can be used in the code
snippets logic. Those variables are mainly related to variables written
in CppBind annotations API, cxx properties and several helper functions/variables/constants.

### API variables

CppBind provides **vars** namespace containing the variables attached to the 
type with CppBind API annotations. The list of the variables available in this
namespace can be found [here](../../main_features/var_def.md).

### CXX structure

CXX related properties are available under **cxx** namespace. The set of those
properties can be different for each kind of element (enum, class/struct, function, arguments, member).
We will start with the description of the common properties, which are available for
all kinds of cxx elements.

#### Common properties

- **kind_name** - the kind name of the cxx element.
    The possible values are: **enum**, **class**, **class_template**,
    **struct**, **struct_template**, **function**, **function_template**,
    **method**, **method_template**, **constructor**, **constructor_template**,
    **field**.
- **name** - the spelling of the cxx element.
- **displayname** - the display name of the cxx element. The display name contains extra
    information about the parameters of a function or template or the arguments of a class
    template specialization. For example, the name/spelling of the `void func_name(int)`
    function is `func_name`, while the display name is `func_name(int)`.
- **source_file_name** - the source file path of the cxx element.
- **is_public** - a boolean property indicating whether the cxx element accessibility is public.
- **is_private** - a boolean property indicating whether the cxx element accessibility is private.
- **is_protected** - a boolean property indicating whether the cxx element accessibility is protected.
- **raw_comment** - the raw comment text associated with the cxx element.
- **namespace** - the namespace of the cxx element.
- **is_abstract** - a boolean property indicating whether the cxx element is an abstract record.
- **is_open** - a boolean property indicating whether the cxx element has **final** specifier.
    The property is `True` when the element doesn't have **final** specifier.
- **parent** - a cxx element corresponding to the parent of the current element.

#### Enum specific properties

- **type_name** - the spelling of the enum.
- **enum_cases** - a list of namespaces containing an information about enum cases.
    Each namespace has the following fields:
    - **name** - the spelling(name) of the enum case.
    - **value** - the value of the enum case.
    - **comment** - Doxygen comments written above the enum case.

#### Class/struct specific properties

- **is_polymorphic** - a boolean property indicating whether the class/struct corresponds to a polymorphic type.
- **has_multiple_base_branches** - a boolean property indicating whether the class/struct
    has multiple base branches in its hierarchy.
- **is_template** - a boolean property indicating whether the class/struct element corresponds to a template.
- **type_name** - the type name of the class/struct.
- **base_types** - a list of the base type elements of the class/struct.
- **ancestors** - a list of the ancestor elements of the class/struct.
- **type** - type information about the class/struct. With the help of this variable
    we can access the properties of cxx type which are described in the **cxx** section
    in [this](type_converter_snippets.md#available-variables) doc.
- **template_parameters** - the list of the template parameters if the class/struct is
    templated (otherwise it's an empty list). For example, for a class/struct declared with
    `template <typename T, typename V>`, the value of this property is `[T, V]`.

#### Function (global function, method, constructor) specific properties

- **is_template** - a boolean property indicating whether the function corresponds to a template.
- **is_static** - a boolean property indicating whether the function is static.
- **is_const** - a boolean property indicating whether the function is a method with **const** specifier.
- **is_overloaded** - a boolean property indicating whether the function is an overloaded method.
- **overridden_elements** - a list of the overridden cxx elements of the method.
- **result_type** - a cxx element corresponding to the function return type. 
- **args** - a list of cxx elements corresponding to the function arguments.
- **template_parameters** - the list of the template parameters if the function is
    templated (otherwise it's an empty list). For example, for a function declared with
    `template <typename T, typename V>`, the value of this property is `[T, V]`.

#### Function argument specific properties

- **name** - the spelling of the function argument. When the argument spelling is empty
    (is not provided in the function declaration), **arg{index}** is used, where **index**
    is 1-based index of the argument (e.g. **arg1**, **arg2**, etc.).
- **default** - the value of the function default argument.
- **default_is_literal** - a boolean property indicating whether the default value is a literal.
- **default_is_nullptr** - a boolean property indicating whether the default value is **nullptr**.
- **type** - the type information of a function argument.

#### Class member specific properties

- **result_type** - type information of the member element.

### Other cxx related variables

CppBind provides other cxx related variables that are not in **cxx** namespace.
These set of variables can also be different for each kind of element.

#### Class/struct specific variables

- **descendants** - a list of the type names of all descendant classes.

#### Function (global function, method, constructor) specific variables

- **overloading_index** - the overloading index of the function
- **template_choice** - the current template choice of the templated function.
- **template_args_postfixes** - the list of names corresponding to the template arguments of
    the cxx type (the values of **name** parameters retrieved from the API annotations).
    These postfixes are used when constructing the name for a template type in the target languages.
    More information about the support of templates and the **name** parameter can be found
    [here](../../main_features/templates.md).
- **setter** - the context of corresponding setter method (is defined only for methods with
    `action: gen_getter` API instruction).

### Other helper variables

CppBind provides several helper functions, variables and constants which
are not related to API variables and cxx properties.

- **banner_logo** - CppBind banner logo constant, which is placed at the top of any generated
    file to indicate that the file is generated by CppBind.
- **new_line** - new line constant to separate contents in jinja snippets with a new line.
- **Error** - a Python module provided by CppBind for logging error messages.
    The available static methods(error levels) are **error**, **critical**, **warning**, **internal**.
- **DoxygenCommentStyle** - a Python enum to define the style of the generated comments.
    The possible enum cases are: **CPP**(makes comments with **///** symbols) and
    **JAVA**(makes comments with ***** symbol).
- **path** - Python **os.path** module to work with paths.
- **pat_sep** - Python **os.sep** constant (os separator).
- **marker** - special constant provided by CppBind which helps to generate snippets with the unique content.
- **ElementKind** - a Python enum containing the kinds of cxx elements. Is mainly used to differentiate
    between template type and non-type parameters: **ElementKind.TEMPLATE_TYPE_PARAMETER** and
    **ElementKind.TEMPLATE_NON_TYPE_PARAMETER**.
- **cppbind_helper** - exposed Python module containing helper utility functions.
- **get_type_converter** - exposed helper function to be able to
    look up type converter by cxx type/type_name.
    This function can be used to call one type converter sections from
    another one.
    For example, if you want to reuse **std::string** converter logic
    inside your own converter, you can do the following:
    `{% set string_converter = get_type_converter('std::string') %}`
    `{{string_converter.c_to_cxx.snippet(...)}}`, where we can pass
    input/output variable names to **snippet** function.
    When the desired type converter is not found, a specific exception
    is thrown. This default behavior can be changed with the help of an
    optional **error** argument: `get_type_converter(type, error=False)`,
    which will return **None** in case of a failure.
- **get_type_info** - exposed helper function to be able to
    look up type info by cxx type/type_name.
    This function can be used to get type information about a specific type.
    For example, if you want to get information about **MyClass** type
    inside your own converter, you can do the following:
    `{% set class_converter = get_type_info('MyClass') %}`
    `{{class_converter.vars.name}}`.
    When the desired type info is not found, a specific exception
    is thrown. This default behavior can be changed with the help of an
    optional **error** argument: `get_type_info(type, error=False)`,
    which will return **None** in case of a failure.
