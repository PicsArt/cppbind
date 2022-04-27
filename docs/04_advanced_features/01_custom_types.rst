Custom Types
^^^^^^^^^^^^

Type conversions are described in yaml config files. There are predefined basic and complex types. User can also have custom types configuration.
The files containing this configuration must be of pattern **\*_types.yaml**  and placed under **custom_config_dir** directory.
Following is an example of converter for nlohmann::json from cxx to Kotlin and vice versa.

  .. code-block:: yaml

    nlohmann::json:
      custom:
        pname: json
      kotlin:
        type_info: String
      jni:
        type_info: jstring
      jdk:
        type_info: String
      jni_to_cxx: |
        auto {{target_name}} = nlohmann::json::parse(iegen::jni_to_string(env, {{name}}))
      cxx_to_jni: |
        {{target_type_name}} {{target_name}} = iegen::string_to_jni(env, {{name}}.dump(4));
      kotlin_to_jdk:
      jdk_to_kotlin: