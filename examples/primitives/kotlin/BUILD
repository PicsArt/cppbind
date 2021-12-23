load("@io_bazel_rules_kotlin//kotlin:kotlin.bzl", "kt_jvm_test")

cc_library(
    name = "jni_header_lib",
    hdrs = ["@bazel_tools//tools/jdk:jni_header"] + select({
        "//:on_linux": ["@bazel_tools//tools/jdk:jni_md_header-linux"],
        "//:on_macos": ["@bazel_tools//tools/jdk:jni_md_header-darwin"],
    }),
    includes = [
        ".",
        "../external/bazel_tools/tools/jdk/include",
    ] + select({
        "//:on_linux": ["../external/bazel_tools/tools/jdk/include/linux"],
        "//:on_macos": ["../external/bazel_tools/tools/jdk/include/darwin"],
    }),
    visibility = ["//visibility:public"],
)

cc_library(
    name = "kt_examples_wrapper",
    srcs = glob(["wrappers/**/*.cpp"]),
    hdrs = glob(["wrappers/**/*.h*"]),
    visibility = ["//visibility:public"],
    deps = [
        ":jni_header_lib",
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

cc_binary(
    name = "libwrapper_jni.dylib",
    linkshared = True,
    visibility = ["//visibility:public"],
    deps = [":kt_examples_wrapper"],
)

kt_jvm_test(
    name = "simple",
    srcs = glob(["src/**/*.kt"]),
    data = [":libwrapper_jni"],
    jvm_flags = ["-Djava.library.path=kotlin"],
    main_class = "com.examples.simple.SimpleApp",
)

filegroup(
    name = "libwrapper_jni",
    srcs = select({
        "//:on_linux": ["libwrapper_jni.so"],
        "//:on_macos": ["libwrapper_jni.dylib"],
    }),
    visibility = ["//visibility:public"],
)

kt_jvm_test(
    name = "operators",
    srcs = glob(["src/**/*.kt"]),
    data = [":libwrapper_jni"],
    jvm_flags = ["-Djava.library.path=kotlin"],
    main_class = "com.examples.operators.OperatorsApp",
)

kt_jvm_test(
    name = "containers",
    srcs = glob(["src/**/*.kt"]),
    data = [":libwrapper_jni"],
    jvm_flags = ["-Djava.library.path=kotlin"],
    main_class = "com.examples.containers.ContainersApp",
)

kt_jvm_test(
    name = "templates",
    srcs = glob(["src/**/*.kt"]),
    data = [":libwrapper_jni"],
    jvm_flags = ["-Djava.library.path=kotlin"],
    main_class = "com.examples.templates.TemplatesApp",
)

kt_jvm_test(
    name = "inheritance",
    srcs = glob(["src/**/*.kt"]),
    data = [":libwrapper_jni"],
    jvm_flags = ["-Djava.library.path=kotlin"],
    main_class = "com.examples.inheritance.InheritanceApp",
)

kt_jvm_test(
    name = "forward_decl",
    srcs = glob(["src/**/*.kt"]),
    data = [":libwrapper_jni"],
    jvm_flags = ["-Djava.library.path=kotlin"],
    main_class = "com.examples.forward_decl.ForwardDeclsApp",
)

kt_jvm_test(
    name = "enums",
    srcs = glob(["src/**/*.kt"]),
    data = [":libwrapper_jni"],
    jvm_flags = ["-Djava.library.path=kotlin"],
    main_class = "com.examples.enums.EnumsApp",
)

kt_jvm_test(
    name = "getters",
    srcs = glob(["src/**/*.kt"]),
    data = [":libwrapper_jni"],
    jvm_flags = ["-Djava.library.path=kotlin"],
    main_class = "com.examples.getters.GettersApp",
)

kt_jvm_test(
    name = "overloads",
    srcs = glob(["src/**/*.kt"]),
    data = [":libwrapper_jni"],
    jvm_flags = ["-Djava.library.path=kotlin"],
    main_class = "com.examples.overloads.OverloadsApp",
)

kt_jvm_test(
    name = "nullables",
    srcs = glob(["src/**/*.kt"]),
    data = [":libwrapper_jni"],
    jvm_flags = ["-Djava.library.path=kotlin"],
    main_class = "com.examples.nullables.NullablesApp",
)

kt_jvm_test(
    name = "shared_ptr",
    srcs = glob(["src/**/*.kt"]),
    data = [":libwrapper_jni"],
    jvm_flags = ["-Djava.library.path=kotlin"],
    main_class = "com.examples.shared_ptr.SharedPtrApp",
)

kt_jvm_test(
    name = "misc",
    srcs = glob(["src/**/*.kt"]),
    data = [":libwrapper_jni"],
    jvm_flags = ["-Djava.library.path=kotlin"],
    main_class = "com.examples.misc.MiscApp",
)

kt_jvm_test(
    name = "extra",
    srcs = glob(["src/**/*.kt"]),
    data = [":libwrapper_jni"],
    jvm_flags = ["-Djava.library.path=kotlin"],
    main_class = "com.examples.extra.ExtraApp",
)

kt_jvm_test(
    name = "exceptions",
    srcs = glob(["src/**/*.kt"]),
    data = [":libwrapper_jni"],
    jvm_flags = ["-Djava.library.path=kotlin"],
    main_class = "com.examples.exceptions.ExceptionsApp",
)

kt_jvm_test(
    name = "optionals",
    srcs = glob(["src/**/*.kt"]),
    data = [":libwrapper_jni"],
    jvm_flags = ["-Djava.library.path=kotlin"],
    main_class = "com.examples.optionals.OptionalsApp",
)

kt_jvm_test(
    name = "globs",
    srcs = glob(["src/**/*.kt"]),
    data = [":libwrapper_jni"],
    jvm_flags = ["-Djava.library.path=kotlin"],
    main_class = "com.examples.globs.GlobsApp",
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
