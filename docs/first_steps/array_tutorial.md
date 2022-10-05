# "Array" tutorial

["Hello user"](../first_steps/hello_user.md)
tutorial shows how to annotate source files to tell CppBind
what to expose in target languages. Let's examine the case of using a
third-party library. In this case it's impossible to modify source
files, so you can't just write CppBind API annotations inside
class/function doxygen style comments. CppBind offers another mechanism
for writing annotations in this scenario: it's possible to write
annotations in separate config yaml files.

Let's consider we have an `Array` class which is declared in a
third-party library:

~~~C++
{% include "../../examples/tutorials/array/cxx/array.hpp" %}
~~~

In order to generate bindings, as a first step you need to configure
your project. You can use the default configuration provided by CppBind
with running `cppbind init` command in your project root directory.

??? "The content of default config file provided by CppBind"
    ~~~Yaml
    {% include "../../src/cppbind/config/cppbind.yaml" %}
    ~~~

Above provided default config file can be changed later to fit the
requirements of your project. For example, we can consider the change of
the **src_glob** variable. It defines the list of the files processed by
CppBind. **src_glob** default value corresponds to all the header files
in the project. For this tutorial's case, we have changed the value of
**src_glob** variable in the project config file, since our C++ source
file is located under **cxx** directory: `src_glob: ["cxx/array.cpp"]`.
More information about CppBind variables can be 
[here](../main_features/var_def.md).

!!! Note
    When generating bindings on the macOS platform for Kotlin, you need the
    **ANDROID_NDK** environment variable to be set. It should point to the
    directory where android NDK is installed. CppBind requires
    **ANDROID_NDK** environment variable to populate the correct clang
    arguments.

After project configuration is done, you need to annotate your source
code with CppBind API annotations. Third-party library source code
annotation should need to be done separately, in a new yaml config file:

~~~Yaml
{% include "../../examples/tutorials/array/cxx/array.cppbind.yaml" %}
~~~

In the above-mentioned yaml config file you can find API instructions
for `Array` class. API instructions are associated with the appropriate
entity with the help of C++ signature which are written in front of the
**type** key. Writing instructions in config file has the same effect as
writing them in doxygen style comments. More detailed information about
this mechanism can be found here: [Section type_vars](../configuration/proj_config.md#section-type_vars).

To make written API annotations available for CppBind we use project
config files merging feature: **type_vars** sections of project config
files can be spread all over the project directories and merged together
by CppBind. By default, CppBind searches files with **cppbind.yaml**
suffix under project directories and merges **type_vars** sections
defined in those files. In our tutorial, we have written API annotations
for the "Array" class in the file named **array.cppbind.yaml**. To
change the name pattern of the project config files, you should modify
**context_def_glob** application variable (more details can be found
[here](../configuration/app_config.md).
Another way to include API annotations written in a separate file is
including the file in the project config file, under **type_vars**
section (the same way as it's done for std_exc_api.yaml file in default
config file).

After project configuration is done and annotation config file is
written, you should run CppBind command line to generate bindings:
`cppbind koltin swift python`.

??? "Generated bindings"
    === "Kotlin"
        ~~~Java
        {% include "../../examples/tutorials/array/kotlin/src/main/java/example_lib/array/array.kt" %}
        ~~~
    === "Python"
        ~~~Python
        {% include "../../examples/tutorials/array/python/src/example_lib/array/array.py" %}
        ~~~
    === "Swift"
        ~~~Swift
        {% include "../../examples/tutorials/array/swift/src/example_lib/array/array.swift" %}
        ~~~

Finally, after generating bindings, you should include them along with
C++ source codes in your project build. In our tutorial we use bazel to
build the project. Bazel setups and rules for "Array" tutorial can be
found [here](https://github.com/PicsArt/cppbind/tree/master/examples/tutorials/array).

After project build setup you can write usage examples and run them:

=== "Kotlin"
    ~~~Java
    {% include "../../examples/tutorials/array/usage/kotlin/array_usage.kt" %}
    ~~~
=== "Python"
    ~~~Python
    {% include "../../examples/tutorials/array/usage/python/array_usage.py" %}
    ~~~
=== "Swift"
    ~~~Swift
    {% include "../../examples/tutorials/array/usage/swift/array_usage.swift" %}
    ~~~

So, with the help of annotations written in a separate config file, we
have achieved our goal: we have exposed several types and functions from
a third-party library to all supported target languages.
