load("@build_bazel_rules_swift//swift:swift.bzl", "swift_library", "swift_test")
load("@pybind11_bazel//:build_defs.bzl", "pybind_extension")
load("@io_bazel_rules_kotlin//kotlin:kotlin.bzl", "kt_jvm_library", "kt_jvm_test")

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

cc_library(
    name = "array_library",
    srcs = glob(["cxx/**/*.cpp"]),
    hdrs = glob([
        "cxx/**/*.hpp",
        "cxx/**/*.h",
    ]),
    visibility = ["//visibility:public"],
)

# swift

cc_library(
    name = "array_swift_wrapper",
    srcs = glob(["swift/**/*.c*", "swift/**/*.hpp"]),
    hdrs = glob(["swift/**/*.h"]),
    tags = ["swift_module=CWrapper"],
    visibility = ["//visibility:public"],
    deps = [
        ":array_library",
    ],
)

swift_library(
    name = "array_swift_library",
    srcs = glob(
        ["swift/src/**/*.swift"],
    ),
    module_name = "Wrapper",
    visibility = ["//visibility:public"],
    deps = [
        ":array_swift_wrapper",
    ],
)

swift_test(
    name = "array_swift",
    srcs = ["usage/swift/array_usage.swift"],
    deps = [":array_swift_library"],
)

# python

pybind_extension(
    name = "pybind_example_lib",
    srcs = glob([
        "python/**/*.cpp",
        "python/**/*.h",
    ]),
    visibility = ["//visibility:public"],
    deps = [
        ":array_library",
    ],
)

py_library(
    name = "array_py_library",
    srcs = glob(["python/src/**/*.py"]),
    data = [
        "pybind_example_lib.so",
    ],
    imports = [
        ".",
        "python/src/",
    ],
    srcs_version = "PY3",
    visibility = ["//visibility:public"],
)

py_test(
    name = "array_python",
    srcs = ["usage/python/array_usage.py"],
    main = "usage/python/array_usage.py",
    python_version = "PY3",
    srcs_version = "PY3",
    visibility = ["//visibility:public"],
    deps = [
        ":array_py_library",
    ],
)

# kotlin

cc_library(
    name = "jni_header_lib",
    hdrs = ["@bazel_tools//tools/jdk:jni_header"] + select({
        ":on_linux": ["@bazel_tools//tools/jdk:jni_md_header-linux"],
        ":on_macos": ["@bazel_tools//tools/jdk:jni_md_header-darwin"],
    }),
    includes = [
        "kotlin/wrappers",
        "external/bazel_tools/tools/jdk/include/",
    ] + select({
        ":on_linux": ["external/bazel_tools/tools/jdk/include/linux"],
        ":on_macos": ["external/bazel_tools/tools/jdk/include/darwin"],
    }),
    visibility = ["//visibility:public"],
)

cc_library(
    name = "array_kt_wrapper",
    srcs = glob(["kotlin/wrappers/**/*.cpp"]),
    hdrs = glob(["kotlin/wrappers/**/*.h*"]),
    visibility = ["//visibility:public"],
    deps = [
        ":array_library",
        ":jni_header_lib",
    ],
    alwayslink = True,
)

cc_binary(
    name = "libwrapper_jni.so",
    linkshared = True,
    visibility = ["//visibility:public"],
    deps = [":array_kt_wrapper"],
)

cc_binary(
    name = "libwrapper_jni.dylib",
    linkshared = True,
    visibility = ["//visibility:public"],
    deps = [":array_kt_wrapper"],
)

kt_jvm_library(
    name = "kt_examples_library",
    srcs = glob(
        ["kotlin/src/**/*.kt"],
        exclude = ["**/array_usage.kt"],
    ),
    data = select({
        ":on_linux": ["libwrapper_jni.so"],
        ":on_macos": ["libwrapper_jni.dylib"],
    }),
    visibility = ["//visibility:public"],
)

kt_jvm_test(
    name = "array_kotlin",
    srcs = ["usage/kotlin/array_usage.kt"],
    deps = ["kt_examples_library"],
    jvm_flags = ["-Djava.library.path=."],
    main_class = "array_usage.ArrayUsageApp",
)
