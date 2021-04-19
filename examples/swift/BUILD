load("@build_bazel_rules_swift//swift:swift.bzl", "swift_binary", "swift_library", "swift_test")

swift_library(
    name = "sw_examples_library",
    srcs = glob(["src/**/*.swift"]),
    module_name = "Wrapper",
    visibility = ["//visibility:public"],
    deps = [
        "//swift/wrappers:sw_examples_wrapper",
    ],
)

swift_test(
    name = "classes",
    srcs = ["src/classes/main.swift"],
    deps = [":sw_examples_library"],
)
