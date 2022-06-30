# Enums

Now let's generate a binding for an enum. Here is the `Color` enum
definition:

~~~C++
{% 
include "../../examples/primitives/cxx/enums/color.hpp"
start="[example-start]"
end="// [example-end]"
%} 
~~~

As shown in the above example, we can extend enums logic by using the
**code_fragment** variable. Code fragments defined with this variable
are appended to the enum definition. In this example, we added the
custom conversion from enum to string for all three languages. Notice
that for Swift, we have also used the **bases_list** variable to make
the enum implement the `CustomStringConvertible` protocol. We can also
customize enum case field names using the **enum_case_name_prefix**
variable, which can be used to add a user-defined prefix string to enum
field names in the target language.

In cases some of the original enum fields are for internal usage, and
the user doesn't want to expose them in target language bindings, the
**enum_excluded_cases** variable can be used to specify the list of
excluded fields. If those fields are used as a default value for a
function/constructor argument, CppBind skips that default value
generation in target language bindings. If the user has a function that
returns an excluded enum field, CppBind terminates the main program
during the function call and provides the user with an appropriate error
message.

And the Frame struct using it:

~~~C++
{% 
include "../../examples/primitives/cxx/enums/frame.hpp"
start="[example-start]"
end="// [example-end]"
%} 
~~~

!!! Note
    We are generating **property_setter** for public field
    `backgroundColor`. A writable property field corresponds to it in the
    target language. To generate a read-only field, we should use
    **property_getter** instead.

Usage examples:

=== "Kotlin"
    ~~~Java
    {% 
    include "../../examples/primitives/kotlin/src/main/java/com/examples/enums/main.kt" 
    start="[color-usage-start]"
    end="// [color-usage-end]"
    %} 
    ~~~

=== "Python"
    ~~~Python
    {% 
    include "../../examples/primitives/python/src/examples_lib/enums/main.py" 
    start="[color-usage-start]"
    end="# [color-usage-end]"
    %} 
    ~~~

=== "Swift"
    ~~~Swift
    {% 
    include "../../examples/primitives/swift/src/enums/main.swift" 
    start="[color-usage-start]"
    end="// [color-usage-end]"
    %} 
    ~~~

??? "Generated codes for Color and Frame"
    === "Kotlin"
        Here is the generated Kotlin code for Color:
        ~~~Java
        {% 
        include "../../examples/primitives/kotlin/src/main/java/com/examples/enums/color.kt" 
        %} 
        ~~~
        And for Frame:
        ~~~Java
        {% 
        include "../../examples/primitives/kotlin/src/main/java/com/examples/enums/frame.kt" 
        %} 
        ~~~
    === "Python"
        Here is the generated Python code for Color:
        ~~~Python
        {% 
        include "../../examples/primitives/python/src/examples_lib/enums/color_pygen.py" 
        %} 
        ~~~
        And for Frame:
        ~~~Python
        {% 
        include "../../examples/primitives/python/src/examples_lib/enums/frame_pygen.py" 
        %} 
        ~~~
    === "Swift"
        Here is the generated Swift code for Color:
        ~~~Swift
        {% 
        include "../../examples/primitives/swift/src/enums/color.swift" 
        %} 
        ~~~
        And for Frame:
        ~~~Swift
        {% 
        include "../../examples/primitives/swift/src/enums/frame.swift" 
        %} 
        ~~~
