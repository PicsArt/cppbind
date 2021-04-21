load("@build_bazel_rules_swift//swift:swift.bzl", "swift_binary", "swift_library", "swift_test")

cc_library(
    name = "sw_examples_wrapper",
    srcs = glob(["wrappers/**/*.c*"]),
    hdrs = glob(["wrappers/**/*.h*"]),
    tags = ["swift_module=CWrapper"],
    visibility = ["//visibility:public"],
    deps = [
        "//cxx:cc_examples_library",
    ],
)

swift_library(
    name = "sw_examples_library",
    srcs = glob(["src/**/*.swift"]),
    module_name = "Wrapper",
    visibility = ["//visibility:public"],
    deps = [
        ":sw_examples_wrapper",
    ],
)

swift_test(
    name = "classes",
    srcs = ["src/classes/main.swift"],
    deps = [":sw_examples_library"],
)

filegroup(
    name = "examples_files",
    srcs = glob([
        "src/**/*.swift",
        "wrappers/**/*.c*",
        "wrappers/**/*.h*",
    ]),
    visibility = ["//visibility:public"],
)
