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

CppBind provides some predefined variables which can be used inside code
snippets logic. Those variables are mainly related to variables written
in CppBind annotations API, cxx properties and some helper functions/variables/constants.

### API variables

### CXX structure

### Other variables
