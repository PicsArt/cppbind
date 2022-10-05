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
