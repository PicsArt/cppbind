Snippets
^^^^^^^^

To generate wrapper codes for target language we use snippets which are described in YAML files. We use **jinja2** template
language to describe the logic inside snippets. Later we pass appropriate context to these snippets and render them.

We have three types of snippets: `code` snippets, `type converter` snippets and `action` snippets.

Code snippets
~~~~~~~~~~~~~

Code snippets are responsible for generating classes, interfaces, functions, enums, constructors, property getters/setters
and other nodes in wrapper files. For example, `class` section of code snippets describes the structure of class in target langauge.
Also it defines what must be generated in C wrappers for class node.

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

Above described code block is a part of our code snippets for generating swift classes. We have some subsections under `class`
parent section: `include`, `body`, and these subsections are used to group generated code fragments. We also have `scopes` which
we use to gather snippet values from the lower levels and use them in current section: for example we use function body inside class.
Actual snippets are described under `content` or `unique_content` sections. `unique_content` is used to generate code fragment
that has unique lines. This is mainly used for includes to avoid redundant repetitions.

Type converter snippets
~~~~~~~~~~~~~~~~~~~~~~~

Type converter snippets are responsible for defining types for source/target languages and also provide conversions between
source and target for the given cxx type.

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
to write conversion logic from source to target language for the given type. In section key names `_to_` joiner is used
to separate source and target languages: for example `c_to_cxx` means that our source is C and target is cxx. This syntax is not
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

Iegen also gives the user opportunity to define any custom subsection under `converters` section by any name with/without
defining source/target attributes and call that snippet as a function to generate some custom code fragments.

Action snippets
~~~~~~~~~~~~~~~

Action snippets are used to commit some action. Mainly we use it to copy helper and utility files from standard directories
to some output directory. For example we have a C file where we define some structures, we also keep some utility files for
exception handling support, etc.

Here is an example of action snippets for swift target language, where we define source and destination for copy action:

.. code-block:: yaml

    - file:
        files_glob:
          "{{[cxx_helpers_dir, '**/*.h*'] | path_join}}"
        copy_to: |
          {%- set file_rel_name = path.relpath(file_name, cxx_helpers_dir) -%}
          {{path.join(cxx_out_dir, file_rel_name)}}
