load("@io_bazel_rules_kotlin//kotlin:kotlin.bzl", "kt_jvm_test")

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
    srcs = glob(["wrappers/**/*.cpp"]),
    hdrs = glob(["wrappers/**/*.h*"]),
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

kt_jvm_test(
    name = "classes",
    srcs = glob(["src/**/*.kt"]),
    data = [":libwrapper_jni.so"],
    jvm_flags = ["-Djava.library.path=kotlin"],
    main_class = "com.examples.classes.ClassesApp",
)

kt_jvm_test(
    name = "operators",
    srcs = glob(["src/**/*.kt"]),
    data = [":libwrapper_jni.so"],
    jvm_flags = ["-Djava.library.path=kotlin"],
    main_class = "com.examples.operators.OperatorsApp",
)

kt_jvm_test(
    name = "containers",
    srcs = glob(["src/**/*.kt"]),
    data = [":libwrapper_jni.so"],
    jvm_flags = ["-Djava.library.path=kotlin"],
    main_class = "com.examples.containers.ContainersApp",
)

filegroup(
    name = "examples_files",
    srcs = glob([
        "src/**/*.kt",
        "wrappers/**/*.c*",
        "wrappers/**/*.h*",
    ]),
    visibility = ["//visibility:public"],
)
