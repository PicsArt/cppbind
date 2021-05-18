Classes/Structs
^^^^^^^^^^^^^^^
Let's generate wrapper code for the following custom type.

.. literalinclude:: /../examples/primitives/cxx/simple/task.hpp
   :language: cpp
   :start-after: [example]
   :end-before: [example]


In a code above we are exporting all public methods and constructors.

.. note::
    Notice that the title method is marked as a getter, so it
    will be a read-only property for the target language.