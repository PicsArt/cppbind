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
    srcs = glob(
        ["src/**/*.swift"],
        exclude = ["**/main.swift"],
    ),
    module_name = "Wrapper",
    visibility = ["//visibility:public"],
    deps = [
        ":sw_examples_wrapper",
    ],
)

swift_test(
    name = "simple",
    srcs = ["src/simple/main.swift"],
    deps = [":sw_examples_library"],
)

swift_test(
    name = "containers",
    srcs = ["src/containers/main.swift"],
    deps = [":sw_examples_library"],
)

swift_test(
    name = "templates",
    srcs = ["src/templates/main.swift"],
    deps = [":sw_examples_library"],
)

swift_test(
    name = "inheritance",
    srcs = ["src/inheritance/main.swift"],
    deps = [":sw_examples_library"],
)

swift_test(
    name = "forward_decl",
    srcs = ["src/forward_decl/main.swift"],
    deps = [":sw_examples_library"],
)

swift_test(
    name = "enums",
    srcs = ["src/enums/main.swift"],
    deps = [":sw_examples_library"],
)

swift_test(
    name = "getters",
    srcs = ["src/getters/main.swift"],
    deps = [":sw_examples_library"],
)

swift_test(
    name = "operators",
    srcs = ["src/operators/main.swift"],
    deps = [":sw_examples_library"],
)

swift_test(
    name = "overloads",
    srcs = ["src/overloads/main.swift"],
    deps = [":sw_examples_library"],
)

swift_test(
    name = "shared_ptr",
    srcs = ["src/shared_ptr/main.swift"],
    deps = [":sw_examples_library"],
)

swift_test(
    name = "exceptions",
    srcs = ["src/exceptions/main.swift"],
    deps = [":sw_examples_library"],
)

swift_test(
    name = "misc",
    srcs = ["src/misc/main.swift"],
    deps = [":sw_examples_library"],
)

swift_test(
    name = "extra",
    srcs = ["src/extra/main.swift"],
    deps = [":sw_examples_library"],
)

swift_test(
    name = "nullables",
    srcs = ["src/nullables/main.swift"],
    deps = [":sw_examples_library"],
)

swift_test(
    name = "optionals",
    srcs = ["src/optionals/main.swift"],
    deps = [":sw_examples_library"],
)

swift_test(
    name = "globs",
    srcs = ["src/globs/main.swift"],
    deps = [":sw_examples_library"],
)

swift_test(
    name = "nested_types",
    srcs = ["src/nested_types/main.swift"],
    deps = [":sw_examples_library"],
)

swift_test(
    name = "rv_policies",
    srcs = ["src/rv_policies/main.swift"],
    deps = [":sw_examples_library"],
)

swift_test(
    name = "typedefs",
    srcs = ["src/typedefs/main.swift"],
    deps = [":sw_examples_library"],
)

swift_test(
    name = "hashing",
    srcs = ["src/hashing/main.swift"],
    deps = [":sw_examples_library"],
)
