load("@io_bazel_rules_kotlin//kotlin:kotlin.bzl", "kt_jvm_library", "kt_jvm_test")

kt_jvm_library(
    name = "kotlin_wrapper",
    srcs = glob([
        "src/**/*.kt",
        "src/**/*.java",
    ]),
    visibility = ["//visibility:public"],
)

kt_jvm_test(
    name = "UsageTest",
    srcs = ["UsageTest.kt"],
    data = ["//tests/examples_tests/kotlin/wrappers:libwrapper_jni.so"],
    jvm_flags = ["-Djava.library.path=tests/examples_tests/kotlin/wrappers"],
    deps = [
        ":kotlin_wrapper",
        "//examples/kotlin:examples_usage_library",
        "@maven//:junit_junit",
    ],
)
