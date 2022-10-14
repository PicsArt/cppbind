CppBind uses either a raw pointer or a shared pointer 
for managing the underlying C++ object.
This means a class can only be associated with only one of them.
By default, a raw pointer is used.
This behaviour can be changed by using a variable called **shared_ref**.

### Shared pointers

If the type is marked with **shared_ref: True**, then the underlying C++ objects of this type are managed by shared pointers.
Whenever an object of such type is returned, the reference counter is incremented, and the ownership is given to the 
target language. This means the reference counter is decremented whenever the wrapper object is deallocated.
The instances can be returned by value or wrapped with `std::shared_ptr`.
A reference or a pointer can be returned only if the type is inherited from `std::enable_shared_from_this`,
otherwise, CppBind raises an error.
There are no restrictions on function arguments having a type marked as **shared_ref: True**.

Let's see an example on how instances of type with **shared_ref: True** can be returned:

~~~C++
  {% 
    include "../../examples/primitives/cxx/inheritance/shapes.hpp"
    start="[example-start]"
    end="// [example-end]"
  %} 
~~~

In this example, we have different types marked with **shared_ref: True**, which are directly or indirectly inherited from `std::enable_shared_from_this`.
These types have different methods returning `this` by value, reference, pointer or shared pointer.

And here's a small usage example:

=== "Kotlin"
    ~~~Java
    {% 
    include "../../examples/primitives/kotlin/src/main/java/com/examples/inheritance/main.kt" 
    start="[enable-shared-from-this-usage-start]"
    end="// [enable-shared-from-this-usage-end]"
    %} 
    ~~~

=== "Python"
    ~~~Python
    {% 
    include "../../examples/primitives/python/src/examples_lib/inheritance/main.py" 
    start="[enable-shared-from-this-usage-start]"
    end="# [enable-shared-from-this-usage-end]"
    %} 
    ~~~

=== "Swift"
    ~~~Swift
    {% 
    include "../../examples/primitives/swift/src/inheritance/main.swift" 
    start="[enable-shared-from-this-usage-start]"
    end="// [enable-shared-from-this-usage-end]"
    %} 
    ~~~

### Raw pointers

When the type is marked with **shared_ref: False** the underlying C++ object is kept as a raw pointer.
For such types, shared pointers are not supported, i.e., function arguments and return values cannot be shared pointers.

!!! Note
    Users must be careful when returning a reference or a pointer of a type marked with **shared_ref: False**.
    For these cases, the ownership is given to C++. To make sure the returned object is not deallocated while
    its wrapper object is alive, the return value policy must be properly specified.
    More on return value policies can be found [here](functions.md#return-value-policies).
