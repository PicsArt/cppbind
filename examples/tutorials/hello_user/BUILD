load("@build_bazel_rules_swift//swift:swift.bzl", "swift_binary", "swift_library", "swift_test")

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
    name = "hello_swift",
    srcs = ["usage/swift/hello_user_usage.swift"],
    deps = [":hello_user_swift_library"],
)
