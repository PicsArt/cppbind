# New language bindings generation

CppBind allows users to add a new supported language if they already
have code and type converter snippets (look
[here](../04_advanced_features/01_snippets.md)
for more detailed information about snippets usage). CppBind deduces the
list of supported languages from the **rules** section info defined
inside project config files. Thus, to add a new language to that list,
users need to make their own code snippets, type converter snippets and
define them under the **rules** section. To add a new language, the user
doesn't need to change the CppBind source code; it can be done by
project config files.

Here are the examples for snippets and config files for virtual
**my_lang** language:

~~~Yaml
{% 
include "../../examples/tests/my_lang_snippets/code_snippets.yaml"
%} 
~~~

~~~Yaml
{% 
include "../../examples/tests/my_lang_snippets/types.yaml"
%} 
~~~

The above-described snippet files have minimum content to generate dummy
bindings for class and function.

~~~Yaml
{% 
include "../../examples/tests/my_lang_cppbind.yaml"
%} 
~~~

Here we included code snippets, type converter snippets, variable
definitions, and defined some variables for the root node.

After these preparations, the tool is ready to be run for a new
**my_lang** language. If the user wants to generate meaningful bindings
with the correct target language syntax, they need to define accurate
code snippets for class, function, and other cxx entities, and also must
define type converter snippets for all the types that the user wants to
use.
