load("@rules_python//python:packaging.bzl", "py_package", "py_wheel")
load("@reqs//:requirements.bzl", "requirement")

# jni rules
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
    #    includes = ["."],
    visibility = ["//visibility:public"],
)

# iegen wheel generation rules
py_library(
    name = "clang",
    srcs = glob(["3pty/clang/**/*.py"]),
)

entry_points = {"console_scripts": [(
    "iegen = iegen.runner:run_package"
)]}

py_library(
    name = "iegen_library",
    srcs = glob(["src/**/*.py"]),
)

py_wheel(
    name = "iegen",
    # Package data. We're building "iegen-0.0.1-py3-none-any.whl"
    distribution = "iegen",
    entry_points = entry_points,
    python_tag = "py3",
    version = "0.0.1",
    deps = [
        ":clang",
        ":iegen_library",
        requirement("attrs"),
    ],
)
