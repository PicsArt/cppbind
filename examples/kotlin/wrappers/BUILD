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
    includes = ["."],
    visibility = ["//visibility:public"],
)

cc_library(
    name = "kt_examples_wrapper",
    srcs = glob(["**/*.cpp"]),
    hdrs = glob([
        "**/*.hpp",
        "**/*.h",
    ]),
    visibility = ["//visibility:public"],
    deps = [
        ":copy_jni_hdr_lib",
        "//cxx:cc_examples_library",
    ],
    alwayslink = True,
)

cc_binary(
    name = "libwrapper_jni.so",
    linkshared = True,
    visibility = ["//visibility:public"],
    deps = [":kt_examples_wrapper"],
)
