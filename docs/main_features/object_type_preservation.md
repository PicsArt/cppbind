# Object type preservation

Having an inheritance tree makes it possible to keep a subtype object as
a base type object. If we construct base type object in the target
bindings, we will lose the information about object's actual type. To
deal with this problem, CppBind does object type preservation when
constructing an object of the user-defined type. After that, saved type
information is used to recover the original object in C bindings and
construct the object in target language bindings with the correct type.

To implement this feature, CppBind keeps track of the descendant
classes/structs for each class/struct. We pass the object's actual type
information from C bindings to target language binding, where the object
construction process is done. CppBind allows the user to define the list
of descendants via the **descendants** variable for each class,
otherwise using the deduced one. In the target language bindings, the
object construction with the actual type is done with switch-case blocks
where we compare preserved type information with the possible descendant
subtypes.

!!! Note
    Currently, CppBind has some limitations when calculating the list of
    descendants in case of class templates: it is not able to separate descendants
    per instantiation of the class template. That's why there are redundant descendants
    in the list, which leads to the generation of unreachable if/else branches.

Here is an example of a base class with a user-defined list of
descendant classes:

~~~C++
{% 
include "../../examples/primitives/cxx/templates/container.hpp"
start="[example-start]"
end="// [example-end]"
%} 
~~~

??? "Implementation part of above-described process in target language bindings (the main logic is inside "cppbindConstructObject" method)"
    === "Kotlin"
        ~~~Java
        {% 
        include "../../examples/primitives/kotlin/src/main/java/com/examples/templates/container.kt" 
        %} 
        ~~~
    === "Python"
        !!! Note
            Object type preservation process for Python is done by pybind.
    === "Swift"
        ~~~Swift
        {% 
        include "../../examples/primitives/swift/src/templates/container.swift" 
        %} 
        ~~~
