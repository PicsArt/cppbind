# "Hello user" tutorial

Introducing the most basic usage of CppBind. Assuming you wrote a
library that greets its user. And, of course, you don't want to
restrict it only to C++ users. You want to make it available for other
language programs as well.

Let's consider following C++ code:

``` cpp
#include <string>

/**
 * Structure to describe user.
 */
struct UserInfo {

    /**
     * Creates user
     */
    UserInfo(const std::string& user_name, unsigned int user_age) : age(user_age), name(user_name) {}
    /**
     * Age of user.
     */
    unsigned int age = 0;
    /**
     * Name of user.
     */
    std::string name;
    /**
     * Some wishes of the user.
     */
    bool want_a_drink = false;
};

/**
 * Host class.
 */
class Host {
public:
    /**
     * Creates host
     */
    Host() = default;
    /**
     * Greeting function.
     */
    std::string hello(const UserInfo& user) {
        return (user.age > 21 ? "Hello ": "Hi ") + user.name;
    }
    /**
     * Welcome function.
     */
    std::string welcome(const UserInfo& user) {
        if (!user.want_a_drink)
            return "Welcome " + user.name + "! Let me know if you want something.";
        return "Welcome " + user.name + "! Do you want cap of " + (user.age > 21 ? "beer?": "juice?");
    }
};
```

To use this from another language, you need to create a binding from
your C++ library to the target language. We are going to generate the
bindings with CppBind.

In the code above, you need to export the `UserInfo` structure with
`age` and `name` properties and the `Host` class with its methods. In
order to generate bindings, as a first step you need to configure your
project. You can use the default configuration provided by CppBind with
running `cppbind init` command in your project root directory. This will
create a **cppbind.yaml** file containing the following configuration:

??? "CppBind default configuration"
    ~~~Yaml
    {% include "../../src/cppbind/config/cppbind.yaml" %}
    ~~~

Above provided default config file can be changed later to fit the
requirements of your project. For example, we can consider the change of
the **src_glob** variable. This variable defines the source files which
are going to be processed by CppBind. The default value of this variable
corresponds to all header files in the project. In our example we have
changed the value of **src_glob**, since our source files are located
under **cxx** directory. More information about CppBind variables can be
found [here](../03_get_started/09_var_def.md).

!!! Note
    When generating bindings on the macOS platform for Kotlin, you need the
    **ANDROID_NDK** environment variable to be set. It should point to the
    directory where android NDK is installed. CppBind requires
    **ANDROID_NDK** environment variable to populate the correct clang
    arguments.

After project configuration is done, you need to add CppBind
instructions and parameters in the doxygen style comments of your C++
code.

~~~C++ hl_lines="5 6 7 13 14 15 20 21 26 27 32 33 40 41 42 48 49 50 55 56 57 64 65 66"
{% include "../../examples/tutorials/hello_user/cxx/hello_user.hpp" %}
~~~

Here we have just added the **\_\_API\_\_** tag to start CppBind
annotation for this particular method and added the instruction
**action: gen_method**, which tells CppBind that a binding needs to be
generated for this method. For the complete list of available
instructions, see [Generation instructions](../03_get_started/08_gen_actions.md).

You can notice the usage of the **throws** variable in API comments.
There are variables which are required on some entities. In this case,
the **throws** variable is required on all methods/constructors. This
requirement is added to ensure that the user hasn't forgotten to
mention possible exceptions that the method/constructor can throw. More
details can be found [here](../03_get_started/05_exception_handling.md).

That is it. You should be able to use it from your codes written in
target languages. Here are usage examples for Kotlin, Python, and Swift.

=== "Kotlin"
    ~~~Java
    {% include "../../examples/tutorials/hello_user/usage/kotlin/hello_user_usage.kt" %}
    ~~~

=== "Python"
    ~~~Python
    {% include "../../examples/tutorials/hello_user/usage/python/hello_user_usage.py" %}
    ~~~

=== "Swift"
    ~~~Swift
    {% include "../../examples/tutorials/hello_user/usage/swift/hello_user_usage.swift" %}
    ~~~

The above-described steps are applicable for all the new classes and
functions you want to expose to other languages. Besides that, you need
to configure the CppBind project file once to use the tool. To know more
about the CppBind configuration, continue reading.

After generating bindings, you should include them with C++ source codes
in your project build. In our tutorial, we use Bazel to build the
project.

Bazel setups and rules for the "Hello user" tutorial can be found
[here](https://github.com/PicsArt/cppbind/tree/master/examples/tutorials/hello_user).
