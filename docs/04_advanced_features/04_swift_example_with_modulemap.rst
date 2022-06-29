Building Swift bindings with Xcode
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

To generate a modulemap defining CppBind generated bindings as a submodule of the Xcode framework, the user adds another configuration file containing the following configuration:

.. literalinclude:: /../examples/features/modulemap/HelloExample/HelloExample/cxx/modulemap.cppbind.yaml
   :language: yaml

Here we added the required snippets and variables for modulemap generation. 
There are two variables defined in modulemap_variable_definitions.yaml:

.. literalinclude:: /../src/cppbind/config/modulemap_variable_definitions.yaml
   :language: yaml

The first is the full path of the modulemap file, and the second is the export declaration to define imported modules that will be exported.

Additionally **c_wrapper_lib_name** and **cxx_helpers_out_rel_path** should be properly defined.

.. code-block:: yaml

    cxx_helpers_out_rel_path: ''
    c_wrapper_lib_name: <FrameworkName>.<CBindingsSubmoduleName>

Here **cxx_helpers_out_rel_path** is set to an empty string in order to not generate relative includes for CppBind C helpers.

For the complete example, follow the link: `Modulemap Example <https://github.com/PicsArt/cppbind/tree/master/examples/features/modulemap/HelloExample>`_.
