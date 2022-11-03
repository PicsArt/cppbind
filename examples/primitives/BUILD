config_setting(
    name = "on_linux",
    constraint_values = [
        "@platforms//os:linux",
    ],
)

config_setting(
    name = "on_macos",
    constraint_values = [
        "@platforms//os:macos",
    ],
)

filegroup(
    name = "config_file",
    srcs = ["cppbind_config.cfg"],
    visibility = ["//visibility:public"],
)


load("@hedron_compile_commands//:refresh_compile_commands.bzl", "refresh_compile_commands")

refresh_compile_commands(
    name = "compile_commands",
    targets = [
      "//cxx:cc_examples_library",
      "//kotlin:libwrapper_jni.so",
      "//swift:sw_examples_wrapper",
      "//python:examples"
    ]
)
