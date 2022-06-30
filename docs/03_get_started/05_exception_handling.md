# Exception handling

CppBind supports exception handling by catching thrown exception objects
in C++ and rethrowing them in a target language. The user must specify
the list of possible thrown exception classes in **throws** variable.
Let's take a look at the following example demonstrating exception
handling:

!!! Note
    CppBind uses **pybind** library to generate Python bindings, which
    already has own mechanism for exception handling. Pybind translates C++
    standard exceptions to their Python analogs using an exception
    correspondence [map](https://pybind11.readthedocs.io/en/stable/advanced/exceptions.html#built-in-c-to-python-exception-translation).
    Pybind translates all user-defined exceptions to Python
    **RuntimeError**. This also sets some constraints on CppBind, so
    currently, CppBind doesn't support Python exceptions as it's done for
    other target languages. The user-defined exceptions list is not relevant
    for Python, and is ignored. The user still must define the **throws**
    variable with a placeholder value. **no_throw** value works fine in this
    case. This requirement keeps API annotations style convenient between
    all target languages.

~~~C++
{% 
include "../../examples/primitives/cxx/exceptions/exceptions.hpp"
start="[throw-example-start]"
end="// [throw-example-end]"
%} 
~~~

**throws** variable is mandatory for methods, constructors, and
functions (also for getters and setters). If a method doesn't throw an
exception, the user must set the variable to a special **no_throw**
value. This is done as a requirement so that the user does not forget
about the ability of a method to throw an exception. An example of an
empty exception list looks like this:

~~~C++
{% 
include "../../examples/primitives/cxx/exceptions/exceptions.hpp"
start="[no-throw-example-start]"
end="// [no-throw-example-end]"
%} 
~~~

!!! Note
    The order of listed exception classes in the **throws** variable is
    important. CppBind preserves user-defined order when catching/rethrowing
    exceptions.

!!! Note
    Swift language doesn't support exception throwing from getter/setter,
    so the user should set the value of the **throws** variable to
    **no_throw** for getter/setter functions. CppBind will give an error
    otherwise.

The **throws** list accepts API annotated standard and user-defined
exception classes. On a target language side, CppBind keeps
correspondence between those classes. CppBind generates bindings for
standard exceptions by providing binding predefined rules for
std::exception and its descendant classes. The binding rules for
standard exceptions are defined in "std_exc_api.yaml" config file,
which looks like this:

??? "CppBind API config for standard exceptions"
    ~~~Yaml
    {% 
    include "../../src/cppbind/config/std_exc/std_exc_api.yaml"
    %} 
    ~~~

!!! Note
    Since CppBind generate try/catch blocks in C bindings for catching an
    exception, it uses C++ std exception classes, and therefore we need to
    include the header files where std exceptions are defined. Those header
    files are included via the **include_cxx** variable (see the example
    above). Here is the list of required includes:

``` cpp
#include <stdexcept>
#include <new>
#include <typeinfo>
```

If a user-defined exception is derived from std::exception, it is
automatically throwable in a target language. If the user wants a class
to be throwable in a target language and not to be derived from
std::exception, the **is_exception** variable for that class must be set
to True (default value is **False**).

!!! Note
    User-defined exception classes must have a copy constructor since
    CppBind copies the exception object before rethrowing it in a target
    language. CppBind needs a copy object since the original exception
    object is deleted when its lifetime is ended.

If CppBind catches an exception not from the user-defined list, it
throws an unexpected exception and calls an uncaught exception handler
callback. CppBind defines `ExceptionHandler` class in a utility package
(one for each target language) to handle uncaught exceptions. The
default handler aborts program execution immediately, but the user can
set a custom callback, which will be called when an unhandled exception
is detected, to change this behaviour. The mentioned package looks like
following:

=== "Kotlin"
    ~~~Java
    {% 
    include "../../examples/primitives/kotlin/src/main/java/com/examples/cppbind/exceptionUtils.kt" 
    %} 
    ~~~

=== "Swift"
    ~~~Swift
    {% 
    include "../../examples/primitives/swift/src/cppbind/exceptionUtils.swift" 
    %} 
    ~~~

CppBind always catches std::exception before catching all (catch(\...))
exceptions to have a more informative error message when the exception
class is derived from std::exception.

After generating bindings for a target language, we can call methods
that can throw an exception and test results with catch blocks:

=== "Kotlin"
    ~~~Java
    {% 
    include "../../examples/primitives/kotlin/src/main/java/com/examples/exceptions/main.kt" 
    start="[exceptions-usage-start]"
    end="// [exceptions-usage-end]"
    %} 
    ~~~

=== "Swift"
    ~~~Swift
    {% 
    include "../../examples/primitives/swift/src/exceptions/main.swift" 
    start="[exceptions-usage-start]"
    end="// [exceptions-usage-end]"
    %} 
    ~~~

!!! Note
    In the last usage example, you can notice that we called the custom
    exception class `SimpleChildException` method `errNum` when an exception
    was caught. As the custom exception class and its methods have API
    annotations, we have corresponding bindings generated, and thus we can
    use class methods.

??? "Binding codes when "throws" exception list is not empty"
    === "Kotlin"
        ~~~Java
        {% 
        include "../../examples/primitives/kotlin/src/main/java/com/examples/exceptions/throw_exceptions.kt" 
        %} 
        ~~~
    === "Swift"
        ~~~Swift
        {% 
        include "../../examples/primitives/swift/src/exceptions/throw_exceptions.swift" 
        %} 
        ~~~


??? "Binding codes when exception list is empty (throws=True)"
    === "Kotlin"
        ~~~Java
        {% 
        include "../../examples/primitives/kotlin/src/main/java/com/examples/exceptions/no_throw_exceptions.kt" 
        %} 
        ~~~
        !!! Note
            For Kotlin we rethrow caught exception from C binding via JNI special functions. 
            It means that exception handling section of code is written in C binding file.
            [Here](https://github.com/PicsArt/cppbind/tree/master/examples/primitives/kotlin/wrappers/com/examples/exceptions/throw_exceptions.cpp)
            is an example of C binding file.
    === "Swift"
        ~~~Swift
        {% 
        include "../../examples/primitives/swift/src/exceptions/no_throw_exceptions.swift" 
        %} 
        ~~~
