load("@build_bazel_rules_swift//swift:swift.bzl", "swift_binary", "swift_library", "swift_test")
load("@pybind11_bazel//:build_defs.bzl", "pybind_extension")
load("@io_bazel_rules_kotlin//kotlin:kotlin.bzl", "kt_jvm_binary")

cc_library(
    name = "hello_user_library",
    srcs = glob(["cxx/**/*.cpp"]),
    hdrs = glob([
        "cxx/**/*.hpp",
        "cxx/**/*.h",
    ]),
    visibility = ["//visibility:public"],
)

cc_library(
    name = "hello_user_swift_wrapper",
    srcs = glob(["swift/**/*.c*"]),
    hdrs = glob(["swift/**/*.h*"]),
    tags = ["swift_module=CWrapper"],
    visibility = ["//visibility:public"],
    deps = [
        ":hello_user_library",
    ],
)

swift_library(
    name = "hello_user_swift_library",
    srcs = glob(
        ["swift/src/**/*.swift"],
    ),
    module_name = "Wrapper",
    visibility = ["//visibility:public"],
    deps = [
        ":hello_user_swift_wrapper",
    ],
)

swift_binary(
    name = "hello_user_swift",
    srcs = ["usage/swift/hello_user_usage.swift"],
    deps = [":hello_user_swift_library"],
)

pybind_extension(
    name = "hello_user",
    srcs = glob([
        "python/**/*.cpp",
        "python/**/*.hpp",
    ]),
    visibility = ["//visibility:public"],
    deps = [
        ":hello_user_library",
    ],
)

py_library(
    name = "hello_user_py_library",
    srcs = glob(["python/src/**/*.py"]),
    data = [
        "hello_user.so",
    ],
    imports = [
        ".",
        "python/src/",
    ],
    srcs_version = "PY3",
    visibility = ["//visibility:public"],
)

py_binary(
    name = "hello_user_python",
    srcs = ["usage/python/hello_user_usage.py"],
    main = "usage/python/hello_user_usage.py",
    python_version = "PY3",
    srcs_version = "PY3",
    visibility = ["//visibility:public"],
    deps = [
        ":hello_user_py_library",
    ],
)

genrule(
    name = "copy_link_jni_md_header",
    srcs = ["@bazel_tools//tools/jdk:jni_md_header-linux"],
    outs = ["jni_md.h"],
    cmd = "cp -f $< $@",
)

genrule(
    name = "copy_link_jni_header",
    srcs = ["@bazel_tools//tools/jdk:jni_header"],
    outs = ["jni.h"],
    cmd = "cp -f $< $@",
)

cc_library(
    name = "copy_jni_hdr_lib",
    hdrs = [
        ":copy_link_jni_header",
        ":copy_link_jni_md_header",
    ],
    includes = ["kotlin/wrappers"],
    visibility = ["//visibility:public"],
)

# kotlin
cc_library(
    name = "hello_user_kt_wrapper",
    srcs = glob(["kotlin/wrappers/**/*.cpp"]),
    hdrs = glob(["kotlin/wrappers/**/*.h*"]),
    visibility = ["//visibility:public"],
    deps = [
        ":copy_jni_hdr_lib",
        ":hello_user_library",
    ],
    alwayslink = True,
)

cc_binary(
    name = "libwrapper_jni.so",
    linkshared = True,
    visibility = ["//visibility:public"],
    deps = [":hello_user_kt_wrapper"],
)

kt_jvm_binary(
    name = "hello_user_kotlin",
    srcs = glob([
        "kotlin/src/**/*.kt",
        "usage/kotlin/**/*.kt",
    ]),
    data = [":libwrapper_jni.so"],
    jvm_flags = ["-Djava.library.path=./"],
    main_class = "hello_user_usage.HelloUserApp",
)
