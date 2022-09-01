# Snippets

In order to generate binding codes for a target language, CppBind uses
snippets described in yaml files. CppBind uses the **jinja2** template
language to describe the logic inside snippets. During rendering process
appropriate context is passed to the snippets to be rendered.

There are three types of snippets: **code**, **type converter**, and
**action** snippets.

## Code snippets

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

## Type converter snippets

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
[here](../04_advanced_features/02_custom_types.md).

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

### Exposed variables

CppBind provides some predefined variables which can be used inside type
converter snippets logic. Here is the list of the most important exposed
variables:

-   **vars** - a namespace containing the variables attached to the
    type with CppBind API annotations. The list of variables available in this namespace can be found
    [here](../03_get_started/09_var_def.md).

-   **cxx** - a namespace containing several useful cxx-related
    fields. Here are the available fields: <br />
    **type_name** - cxx type name. <br />
    **pointee_name** - cxx pointee type name (the name without pointer
    or reference sign). <br />
    **canonical_type** - an object representing canonical type
    information of the given type. <br />
    **is_pointer** - a boolean
    variable showing whether the cxx type
    is pointer or not. <br />
    **is_value_type** - a boolean variable showing whether the cxx
    type is of value type (not pointer or reference) or not. <br />
    **is_lval_reference** - a boolean variable showing whether the cxx
    type is an lvalue reference or not. <br />
    **is_rval_reference** - a boolean variable showing whether the cxx
    type is an rvalue reference or not. <br />
    **unqualified_resolved_type_name** - cxx type name or canonical
    type name when the type is a typedef on a pointer/reference. <br />
    **unqualified_type_name** - cxx type name without any
    qualification (without `const` and `volatile`). <br />
    **unqualified_canonical_type_name** - canonical type name of the
    cxx type without any qualifiers and pointers/references. <br />
    **is_const_qualified** - a boolean variable showing whether the
    cxx type is const qualified or not. <br />
    **namespace** - namespace of the cxx type. <br />
    **is_open** - a boolean variable showing whether the cxx type is
    open (not final) or not (open for being derived from). <br />
    **is_abstract** - a boolean showing whether the cxx type is
    abstract or not. <br />
    **kind_name** - the kind name of the cxx type. <br />
    **displayname** - the display name of the cxx type. <br />
    **is_polymorphic** - a boolean variable showing whether the cxx
    type is polymorphic or not. <br />
    **has_multiple_base_branches** - a boolean variable showing
    whether the cxx type has multiple base branches in its hierarchy
    or not. 

-   **name** - source variable name for which the current type
    converter is called.

-   **target_name** - output variable name after the cxx type
    conversion.

-   **target_type_name** - the type name of the cxx type corresponding
    to the target language.

-   **args** - the list of converters of the template arguments of the
    given type for a particular section (e.g. for **c_to_cxx**).
    For example, for `std::vector<int>` this variable will contain
    **int** converter.

-   **descendants** - the list of types derived from the given type
    (is calculated by CppBind). More can be found
    [here](../04_advanced_features/05_object_type_preservation.md).

-   **template_args_postfixes** - the list of names corresponding to
    template arguments of the cxx type.

-   **parent_type_info** - outer type information of the cxx type if
    the type is nested.

-   **helper** - exposed Python module containing helper utility
    functions.

-   **Error** - exposed CppBind module to log some error messages in
    type converter snippets.

-   **make_type_converter** - exposed helper function to be able to
    create type converter by type name.
    This function can be used to call one type converter sections from
    another one.
    For example, if you want to reuse **std::string** converter logic
    inside your own converter, you can do the following:
    `{% set string_converter = make_type_converter('std::string') %}`
    `{{string_converter.c_to_cxx.snippet(...)}}`, where we can pass
    input/output variable names to **snippet** function.

!!! Note
    Available fields under **cxx** namespace can be accessed via member
    access syntax: `cxx.type_name`. Those fields are calculated by CppBind
    and are read-only. Besides of this usage, CppBind also supports another
    way to access these fields: **cxx_type_name** where **.** is replaced by
    **\_**. The difference between these two mechanisms is that in the
    second case the value of the variable can be altered by the converter
    snippet user when calling the type converter:
    `make_type_converter('int').c_to_cxx.snippet(cxx_type_name='INT')`.

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

## Action snippets

Action snippets are used to commit an action. Mainly we use it to copy
helper and utility files from standard directories to output
directories. For example, we have a C file where we define structures,
keep utility files for exception handling support, etc.

Here is an example of action snippets for Swift target language, where
we define the source and destination for copy action:

``` yaml
- file:
    files_glob:
      "{{[cxx_helpers_dir, '**/*.h*'] | path_join}}"
    copy_to: |
      {%- set file_rel_name = path.relpath(file_name, cxx_helpers_dir) -%}
      {{path.join(cxx_out_dir, file_rel_name)}}

    variables:
        helper_includes: |
          {%- set file_rel_name = path.relpath(file_name, vars.helpers_dir) -%}
          {{path.splitext(file_rel_name)[0].replace(pat_sep, '.')}}
```

Action is described by a pair of special keys showing the action object
and purpose. For example, action can describe the copy(action) operation
of a file(object). We have a list of supported actions:


<center>Actions</center>
<center>

| Action keys    | Purpose of action                                                              |
| :----------    | :---------------------------------------------------------------------------   |
| file/copy_to   |  Copy input files described by **files_glob** glob pattern to the destination  |
| file/render_to |  Render input template files with root context and copy to the destination     |

</center>

**Variables** section defines variables connected to the given action
and then uses it in code snippets. For example, we define variables to
generate `#include` directives in C bindings.
