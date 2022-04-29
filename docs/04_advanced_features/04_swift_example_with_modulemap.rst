Building Swift bindings with Xcode
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

In order to generate a modulemap for defining IEGEN generated bindings as a submodule of Xcode framework user needs to add another configuration file containing the following configuration:

.. literalinclude:: /../examples/features/modulemap/HelloExample/HelloExample/cxx/modulemap.iegen.yaml
   :language: yaml

Here we add required snippets and variables for modulemap generation.
There are two variables defined in modulemap_variable_definitions.yaml:

.. literalinclude:: /../src/iegen/config/modulemap_variable_definitions.yaml
   :language: yaml

The first is the full path of modulemap file and the second one is the export declaration to define which imported modules will be exported.

Additionally **c_wrapper_lib_name** and **cxx_out_rel_path** should be properly defined.

.. code-block:: yaml

    cxx_out_rel_path: ''
    c_wrapper_lib_name: <FrameworkName>.<CBindingsSubmoduleName>

Here **cxx_out_rel_path** is set to an empty string to not generate a relative includes for IEGEN C helpers.

For the full example follow the link: `Modulemap Example <https://github.com/PicsArt/iegen/tree/master/examples/features/modulemap/HelloExample>`_.
