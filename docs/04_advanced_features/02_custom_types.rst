Adding a custom type converter
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

Type conversions are described in yaml config files. CppBind supports several primitive and complex types and has default
implementation of type converters for those types: **int**, **char**, **bool**, **enum**, **std::string**, **std::vector**,
user-defined classes/structs, etc. The implementation details about these converters for supported languages can be found `here <https://github.com/PicsArt/cppbind/tree/master/src/cppbind/config/snippets>`_.

Besides of supported types, CppBind also gives an opportunity to write custom type converters for your types.
The config files must be placed under the directory defined by **custom_config_dir** variable.
CppBind includes all files with **\*_types.yaml** name pattern in project default config file.
So either your files must have **_types.yaml** suffix or you need to include your custom type converter config files
under **rules** section in your project config file:

.. code-block:: yaml

    rules:
        swift.type_converters:
            !include your_snippets_dir/your_custom_snippet_file.yaml

Since CppBind finds and merges **rules** which are spread all over the project, you can also have a separate file
where **rules** section can be defined and then merged with other **rules** sections in project config files.
More information about merging mechanism can be found here: :ref:`rules-section-label`.

To write a custom type converter you need to fill the type converter required sections with correct snippets.
The required fields are type information sections and conversion sections from source to target languages.
More information about type converter sections can be found :doc:`here </04_advanced_features/01_snippets>`.

The following is an example of ``nlohmann::json`` converter:

.. tab-set::

    .. tab-item:: Swift

        .. code-block:: yaml

            nlohmann::json:
              custom:
                is_c_pointer_type: True
                tname: JSON
              types:
                swift: String
                c: char *
                sc: UnsafeMutablePointer<CChar>
              converters:
                c_to_cxx: |
                  auto {{target_name}} = nlohmann::json::parse({{name}});
                  free({{name}});
                cxx_to_c: |
                  auto {{name}}_str = {{name}}.dump();
                  auto {{target_name}} = strdup({{name}}_str.c_str());
                swift_to_sc: |
                  let {{target_name}} = strdup({{name}})!
                sc_to_swift: |
                  let {{target_name}} = String(cString: {{name}})
                  defer {
                    {{name}}.deallocate()
                  }

    .. tab-item:: Kotlin

        .. code-block:: yaml

            nlohmann::json:
              custom:
                pname: Object
                tname: JSON
              types:
                kotlin: String
                jni: jstring
                jdk: String
              converters:
                jni_to_cxx: |
                  auto {{target_name}} = nlohmann::json::parse(cppbind::jni_to_string(env, {{name}}));
                cxx_to_jni: |
                  {{target_type_name}} {{target_name}} = cppbind::string_to_jni(env, {{name}}.dump(4));
                kotlin_to_jdk:
                jdk_to_kotlin:
