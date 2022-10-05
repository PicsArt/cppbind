Type converter snippets are responsible for defining type information
and conversion logic between source and target languages for the given
cxx type.

### nlohmann::json example

Here is an example of `nlohmann::json` type converter for Swift:

``` yaml
nlohmann::json:
  custom:
    is_c_pointer_type: True
    tname: JSON
  types:
    swift: String
    c: char *
    sc: UnsafeMutablePointer<CChar>
  converters:
    c_to_cxx: |
      auto {{target_name}} = nlohmann::json::parse({{name}});
      free({{name}});
    cxx_to_c: |
      auto {{name}}_str = {{name}}.dump();
      auto {{target_name}} = strdup({{name}}_str.c_str());
    swift_to_sc: |
      let {{target_name}} = strdup({{name}})!
    sc_to_swift: |
      let {{target_name}} = String(cString: {{name}})
      defer {
        {{name}}.deallocate()
      }
    cxx_include: |
        #include <string.h>
    sc_cleanup: |
        // do some deallocation/cleanup stuff if needed
```

Here we can see **types** section defining the given cxx type
information. We use the **converters** section to write conversion logic
from source to target languages for the given type. Section key names
should be of the following format: <source language\> + **\_to\_** +
<target language\>: where **c_to_cxx** means that our source is C and
target is cxx. This syntax is not mandatory. The user can use any custom
name and define the source, target, and snippet information under
**source**, **target** and **snippet** subsections:

``` yaml
converters:
    users_custom_key_name:
        source: c
        target: cxx
        snippet: |
            snippet template
```

More information about writing your own type converters can be found
[here](../../advanced_topics/cppbind_snippets/custom_types.md).

### Type converter optional subsections

**custom** optional subsection keeps help information on the given type
for using in snippets. This section is exposed to other sections of type
converter, so it can serve as a space for shareable information.

Conversion logic may require usage of some functions or types which must
be included from standard or third party libraries. For this purpose we
use **cxx_include** optional section to define all required include
directives.

There are cases when you might allocate some data in the conversion
phase which need to be released in a different scope/section only after
its usage (especially in case of nested structures). In the example
above you can see optional **sc_cleanup** section which can be used to
do some deallocations in order not to have memory leakages.

CppBind allows the user to define any custom subsection under the
**converters** section by any name with/without defining source/target
attributes and call that snippet as a function to generate some custom
code fragments.

### Available variables

CppBind provides some predefined variables which can be used inside type
converter snippets logic. Here is the list of the most important exposed
variables:

- **vars** - a namespace containing the variables attached to the
    type with CppBind API annotations. The list of variables available in this namespace can be found
    [here](../../main_features/var_def.md).

- **cxx** - a namespace containing several useful cxx-related
    fields. Here are the available fields: <br />
    **type_name** - cxx type name. <br />
    **unqualified_type_name** - cxx type name without any
    qualification (without `const` and `volatile`). <br />
    **canonical_type** - an object representing canonical type
    information of the given type. <br />
    **pointee_type** - an object representing pointee type
    information of the given type. <br />
    **resolved_type** - cxx pointee type or canonical
    type when the type is a typedef on a pointer/reference. <br />
    **parent_type** - outer type information of the cxx type if
    the type is nested. <br />
    **namespace** - namespace of the cxx type. <br />
    **template_arguments** - a list of namespaces containing the
    template argument cxx type and the kind. The kind field indicates
    whether the template argument is a type or non-type parameter.
    Possible values are **ElementKind.TEMPLATE_TYPE_PARAMETER** and
    **ElementKind.TEMPLATE_NON_TYPE_PARAMETER**. <br />
    **is_pointer** - a boolean variable showing whether the cxx type
    is pointer or not. <br />
    **is_value_type** - a boolean variable showing whether the cxx
    type is of value type (not pointer or reference) or not. <br />
    **is_lval_reference** - a boolean variable showing whether the cxx
    type is an lvalue reference or not. <br />
    **is_rval_reference** - a boolean variable showing whether the cxx
    type is an rvalue reference or not. <br />
    **is_const_qualified** - a boolean variable showing whether the
    cxx type is const qualified or not. <br />
    **is_polymorphic** - a boolean variable showing whether the cxx
    type is polymorphic or not. <br />
    **is_template** - a boolean variable showing whether the cxx type
    is a template or not. <br />
    **is_function_proto** - a boolean variable showing whether the cxx type
    is a function prototype or not. <br />
    **is_typedef** - a boolean variable showing whether the cxx type
    is a typedef to another type or not. <br />
    **is_enum** - a boolean variable showing whether the cxx type
    is an enum or not. <br />
    **is_bool** - a boolean variable showing whether the cxx type
    is a boolean or not. <br />
    **is_long** - a boolean variable showing whether the cxx type
    is long or not. <br />
    **is_float** - a boolean variable showing whether the cxx type
    is float or not. <br />
    **is_char** - a boolean variable showing whether the cxx type
    is char or not. <br />
    **is_uchar** - a boolean variable showing whether the cxx type
    is unsigned char or not.

- **name** - source variable name for which the current type
    converter is called.

- **target_name** - output variable name after the cxx type
    conversion.

- **target_type_name** - the type name of the cxx type corresponding
    to the target language.

- **template_args** - the list of the template arguments of the
    given type. For example, for `std::vector<int>` this variable will contain
    cxx type information of the **int** type.

- **template_args_kinds** - the list of the template argument kinds of the
    given type. For example, for `std::array<int, 2>` this variable be
    **[ElementKind.TEMPLATE_TYPE_PARAMETER, ElementKind.TEMPLATE_NON_TYPE_PARAMETER]**.
    An element inside this list indicates whether the template argument is a
    template type parameter or not.

- **descendants** - the list of types derived from the given type
    (is calculated by CppBind). More can be found
    [here](../../main_features/object_type_preservation.md).

- **has_api** - a boolean variable showing whether the cxx type has CppBind
    API annotations.

- **template_args_postfixes** - the list of names corresponding to
    template arguments of the cxx type.

- **template_choice** - the current template choice for templated types.

- **cppbind_helper** - exposed Python module containing helper utility
    functions.

- **Error** - exposed CppBind module to log some error messages in
    type converter snippets.

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

!!! Note
    Available fields under **cxx** namespace can be accessed via member
    access syntax: `cxx.type_name`. Those fields are calculated by CppBind
    and are read-only. Besides of this usage, CppBind also supports another
    way to access these fields: **cxx_type_name** where **.** is replaced by
    **\_**. The difference between these two mechanisms is that in the
    second case the value of the variable can be altered by the converter
    snippet user when calling the type converter:
    `get_type_converter('int').c_to_cxx.snippet(cxx_type_name='INT')`.

### Type converter search mechanism

When trying to do conversion for a particular type, CppBind starts to
search for type converter snippets. CppBind has a special order for type
converter search process. Suppose, we want to convert `const Task *`
type where Task is a custom type. At first, we will try to find a
converter for `const Task *`. If not found, we will try to find a
converter for unqualified type name: `Task *`. Later we search for
pointee type name, i.e. type name without any sign of pointer or
reference: `Task`. The last candidate is canonical type name, i.e. if
Task is typedef to another type, CppBind will try to get the actual type
name and find a converter for that type. If after the described whole
process no converter is found, CppBind will complain about the usage of
a type with non-existing converter.
