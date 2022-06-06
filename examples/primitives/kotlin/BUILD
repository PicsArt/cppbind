load("@io_bazel_rules_kotlin//kotlin:kotlin.bzl", "kt_jvm_test", "kt_jvm_library")

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

kt_jvm_library(
    name = "kt_examples_library",
    srcs = glob(
        ["src/**/*.kt"],
        exclude = ["**/main.kt"],
    ),
    data = [":libwrapper_jni"],
    visibility = ["//visibility:public"],
)

kt_jvm_test(
    name = "simple",
    srcs = ["src/main/java/com/examples/simple/main.kt"],
    deps = ["kt_examples_library"],
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
    srcs = ["src/main/java/com/examples/operators/main.kt"],
    deps = ["kt_examples_library"],
    jvm_flags = ["-Djava.library.path=kotlin"],
    main_class = "com.examples.operators.OperatorsApp",
)

kt_jvm_test(
    name = "containers",
    srcs = ["src/main/java/com/examples/containers/main.kt"],
    deps = ["kt_examples_library"],
    jvm_flags = ["-Djava.library.path=kotlin"],
    main_class = "com.examples.containers.ContainersApp",
)

kt_jvm_test(
    name = "templates",
    srcs = ["src/main/java/com/examples/templates/main.kt"],
    deps = ["kt_examples_library"],
    jvm_flags = ["-Djava.library.path=kotlin"],
    main_class = "com.examples.templates.TemplatesApp",
)

kt_jvm_test(
    name = "inheritance",
    srcs = ["src/main/java/com/examples/inheritance/main.kt"],
    deps = ["kt_examples_library"],
    jvm_flags = ["-Djava.library.path=kotlin"],
    main_class = "com.examples.inheritance.InheritanceApp",
)

kt_jvm_test(
    name = "forward_decl",
    srcs = ["src/main/java/com/examples/forward_decl/main.kt"],
    deps = ["kt_examples_library"],
    jvm_flags = ["-Djava.library.path=kotlin"],
    main_class = "com.examples.forward_decl.ForwardDeclsApp",
)

kt_jvm_test(
    name = "enums",
    srcs = ["src/main/java/com/examples/enums/main.kt"],
    deps = ["kt_examples_library"],
    jvm_flags = ["-Djava.library.path=kotlin"],
    main_class = "com.examples.enums.EnumsApp",
)

kt_jvm_test(
    name = "getters",
    srcs = ["src/main/java/com/examples/getters/main.kt"],
    deps = ["kt_examples_library"],
    jvm_flags = ["-Djava.library.path=kotlin"],
    main_class = "com.examples.getters.GettersApp",
)

kt_jvm_test(
    name = "overloads",
    srcs = ["src/main/java/com/examples/overloads/main.kt"],
    deps = ["kt_examples_library"],
    jvm_flags = ["-Djava.library.path=kotlin"],
    main_class = "com.examples.overloads.OverloadsApp",
)

kt_jvm_test(
    name = "nullables",
    srcs = ["src/main/java/com/examples/nullables/main.kt"],
    deps = ["kt_examples_library"],
    jvm_flags = ["-Djava.library.path=kotlin"],
    main_class = "com.examples.nullables.NullablesApp",
)

kt_jvm_test(
    name = "shared_ptr",
    srcs = ["src/main/java/com/examples/shared_ptr/main.kt"],
    deps = ["kt_examples_library"],
    jvm_flags = ["-Djava.library.path=kotlin"],
    main_class = "com.examples.shared_ptr.SharedPtrApp",
)

kt_jvm_test(
    name = "misc",
    srcs = ["src/main/java/com/examples/misc/main.kt"],
    deps = ["kt_examples_library"],
    jvm_flags = ["-Djava.library.path=kotlin"],
    main_class = "com.examples.misc.MiscApp",
)

kt_jvm_test(
    name = "extra",
    srcs = ["src/main/java/com/examples/extra/main.kt"],
    deps = ["kt_examples_library"],
    jvm_flags = ["-Djava.library.path=kotlin"],
    main_class = "com.examples.extra.ExtraApp",
)

kt_jvm_test(
    name = "exceptions",
    srcs = ["src/main/java/com/examples/exceptions/main.kt"],
    deps = ["kt_examples_library"],
    jvm_flags = ["-Djava.library.path=kotlin"],
    main_class = "com.examples.exceptions.ExceptionsApp",
)

kt_jvm_test(
    name = "optionals",
    srcs = ["src/main/java/com/examples/optionals/main.kt"],
    deps = ["kt_examples_library"],
    jvm_flags = ["-Djava.library.path=kotlin"],
    main_class = "com.examples.optionals.OptionalsApp",
)

kt_jvm_test(
    name = "globs",
    srcs = ["src/main/java/com/examples/globs/main.kt"],
    deps = ["kt_examples_library"],
    jvm_flags = ["-Djava.library.path=kotlin"],
    main_class = "com.examples.globs.GlobsApp",
)

kt_jvm_test(
    name = "rv_policies",
    srcs = ["src/main/java/com/examples/rv_policies/main.kt"],
    jvm_flags = ["-Djava.library.path=kotlin"],
    deps=["kt_examples_library", "@com_github_jetbrains_kotlin//:kotlin-stdlib-jdk7"],
    main_class = "com.examples.rv_policies.RVPApp",
)

kt_jvm_test(
    name = "nested_types",
    srcs = ["src/main/java/com/examples/nested_types/main.kt"],
    deps = ["kt_examples_library"],
    jvm_flags = ["-Djava.library.path=kotlin"],
    main_class = "com.examples.nested_types.NestedTypesApp",
)

kt_jvm_test(
    name = "typedefs",
    srcs = ["src/main/java/com/examples/typedefs/main.kt"],
    deps = ["kt_examples_library"],
    jvm_flags = ["-Djava.library.path=kotlin"],
    main_class = "com.examples.typedefs.TypedefsApp",
)

kt_jvm_test(
    name = "hashing",
    srcs = ["src/main/java/com/examples/hashing/main.kt"],
    deps = ["kt_examples_library", "@com_github_jetbrains_kotlin//:kotlin-reflect"],
    jvm_flags = ["-Djava.library.path=kotlin"],
    main_class = "com.examples.hashing.HashingApp",
)
