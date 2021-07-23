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
    name = "simple",
    srcs = glob(["src/**/*.kt"]),
    data = [":libwrapper_jni.so"],
    jvm_flags = ["-Djava.library.path=kotlin"],
    main_class = "com.examples.simple.SimpleApp",
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

kt_jvm_test(
    name = "templates",
    srcs = glob(["src/**/*.kt"]),
    data = [":libwrapper_jni.so"],
    jvm_flags = ["-Djava.library.path=kotlin"],
    main_class = "com.examples.templates.TemplatesApp",
)

kt_jvm_test(
    name = "inheritance",
    srcs = glob(["src/**/*.kt"]),
    data = [":libwrapper_jni.so"],
    jvm_flags = ["-Djava.library.path=kotlin"],
    main_class = "com.examples.inheritance.InheritanceApp",
)

kt_jvm_test(
    name = "forward_decl",
    srcs = glob(["src/**/*.kt"]),
    data = [":libwrapper_jni.so"],
    jvm_flags = ["-Djava.library.path=kotlin"],
    main_class = "com.examples.forward_decl.ForwardDeclsApp",
)

kt_jvm_test(
    name = "enums",
    srcs = glob(["src/**/*.kt"]),
    data = [":libwrapper_jni.so"],
    jvm_flags = ["-Djava.library.path=kotlin"],
    main_class = "com.examples.enums.EnumsApp",
)

kt_jvm_test(
    name = "getters",
    srcs = glob(["src/**/*.kt"]),
    data = [":libwrapper_jni.so"],
    jvm_flags = ["-Djava.library.path=kotlin"],
    main_class = "com.examples.getters.GettersApp",
)

kt_jvm_test(
    name = "overloads",
    srcs = glob(["src/**/*.kt"]),
    data = [":libwrapper_jni.so"],
    jvm_flags = ["-Djava.library.path=kotlin"],
    main_class = "com.examples.overloads.OverloadsApp",
)

kt_jvm_test(
    name = "nullables",
    srcs = glob(["src/**/*.kt"]),
    data = [":libwrapper_jni.so"],
    jvm_flags = ["-Djava.library.path=kotlin"],
    main_class = "com.examples.nullables.NullablesApp",
)

kt_jvm_test(
    name = "shared_ptr",
    srcs = glob(["src/**/*.kt"]),
    data = [":libwrapper_jni.so"],
    jvm_flags = ["-Djava.library.path=kotlin"],
    main_class = "com.examples.shared_ptr.SharedPtrApp",
)

kt_jvm_test(
    name = "misc",
    srcs = glob(["src/**/*.kt"]),
    data = [":libwrapper_jni.so"],
    jvm_flags = ["-Djava.library.path=kotlin"],
    main_class = "com.examples.misc.MiscApp",
)

kt_jvm_test(
    name = "exceptions",
    srcs = glob(["src/**/*.kt"]),
    data = [":libwrapper_jni.so"],
    jvm_flags = ["-Djava.library.path=kotlin"],
    main_class = "com.examples.exceptions.ExceptionsApp",
)

kt_jvm_test(
    name = "optionals",
    srcs = glob(["src/**/*.kt"]),
    data = [":libwrapper_jni.so"],
    jvm_flags = ["-Djava.library.path=kotlin"],
    main_class = "com.examples.optionals.OptionalsApp",
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
