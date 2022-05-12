Snippets
^^^^^^^^

To generate binding codes for target language we use snippets which are described in YAML files. We use **jinja2** template
language to describe the logic inside snippets. Later we pass appropriate context to these snippets and render them.

We have three types of snippets: `code` snippets, `type converter` snippets and `action` snippets.

Code snippets
~~~~~~~~~~~~~

Code snippets are called for classes, interfaces, functions, enums, constructors, property getters/setters, files, directories, etc.
User can use them to generate multiple files. For example, user can generate C/C++ code and target language code to implement some binding logic
between those languages.

.. code-block:: yaml

    class:
      swift:
        include:
          unique_content: |
            {{marker if include}}{{include|format_list("import {}")|join_unique}}
        body:
          scopes:
            - head
            - properties
            - body
            - private_external
          content: |
            public class {{name}}{{template_suffix}} {{': ' + bases_specifiers|join(', ') if bases_specifiers}}
                                    {%- if ctx.is_exception and not helper.Exceptions.has_exc_base(ctx) -%}
                                    {{', ' if bases_specifiers else ' : Error'}}
                                    {%- endif %} {

Above described code block is a part of our code snippets for generating Swift classes. We have some subsections under `class`
parent section: `include`, `body`, and these subsections are used to group generated code fragments. We also have `scopes` which
we use to gather snippet values from the lower levels and use them in current section: for example, we use function body inside class.
Actual snippets are described under `content` or `unique_content` sections. `unique_content` is used to generate unique lines or
code fragment defined by marker. This is mainly used for includes to avoid redundant repetitions.

Type converter snippets
~~~~~~~~~~~~~~~~~~~~~~~

Type converter snippets are responsible for defining type information for the target language and also provide conversions between
source and target languages for the given cxx type.

Here is an example of type converter for `char *`:

.. code-block:: yaml

    char *:
      custom:
        is_c_pointer_type: True
      types:
        swift: String
        c: const char *
        sc: UnsafePointer<CChar>?
      converters:
        c_to_cxx:
        cxx_to_c:
        swift_to_sc: |
          let {{target_name}} = {{name}}.cString(using: String.Encoding.utf8){{'!' if not nullable|default(False)}}
        sc_to_swift: |
          let {{target_name}} = String(cString: {{name}}{{'!' if nullable|default(False)}})

Here we can see **types** section which is used to define type information for the given cxx type. We use **converters** section
to write conversion logic from source to target language for the given type. Section key names should be of the following format:
<source language> + `_to_` + <target language>: for example, `c_to_cxx` means that our source is C and target is cxx. This syntax is not
mandatory: user can have any custom name and define source, target and snippet information under `source`, `target` and `snippet`
subsection:

.. code-block:: yaml

    converters:
        users_custom_key_name:
            source: c
            target: cxx
            snippet: |
                snippet template

**custom** field is used to keep some helper information for the given type for using in snippets.

CppBind also gives the user opportunity to define any custom subsection under `converters` section by any name with/without
defining source/target attributes and call that snippet as a function to generate some custom code fragments.

Action snippets
~~~~~~~~~~~~~~~

Action snippets are used to commit some action. Mainly we use it to copy helper and utility files from standard directories
to some output directories. For example, we have a C file where we define some structures, we also keep some utility files for
exception handling support, etc.

Here is an example of action snippets for Swift target language, where we define source and destination for copy action:

.. code-block:: yaml

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

An action is described by a pair of special keys that show the action object and the purpose of the action.
For example, action can describe the copy(action) operation of a file(object).
We have a list of supported actions:

.. list-table:: Actions
    :widths: 25 75
    :header-rows: 1

    * - Action keys
      - Purpose of action
    * - file/copy_to
      - Copy input files described by **files_glob** glob pattern to the destination
    * - file/render_to
      - Render input template files with root context and copy to the destination

**Variables** section is used to define some variables which are connected to the given action and then use it in code snippets.
For example, we define variables to generate ``#include`` directives in C bindings.
