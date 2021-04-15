load("@pybind11_bazel//:build_defs.bzl", "pybind_extension")
load("@rules_cc//cc:defs.bzl", "cc_binary")

pybind_extension(
    name = "examples",
    srcs = glob([
        "wrappers/**/*.cpp",
        "wrappers/**/*.hpp",
    ]),
    deps = [
        "//examples:examples_cc_library",
    ],
)

py_library(
    name = "examples_wrapper",
    srcs = glob(["src/**/*.py"]),
    data = [
        "examples.so",
    ],
    imports = [
        ".",
        "src/",
    ],
    srcs_version = "PY3",
    visibility = ["//visibility:public"],
)

py_test(
    name = "test_usage",
    srcs = ["test_usage.py"],
    main = "test_usage.py",
    python_version = "PY3",
    srcs_version = "PY3",
    deps = [
        ":examples_wrapper",
        "//examples/python:examples_usage_library",
    ],
)

py_test(
    name = "test_containers",
    srcs = ["test_containers.py"],
    main = "test_containers.py",
    python_version = "PY3",
    srcs_version = "PY3",
    deps = [
        ":examples_wrapper",
    ],
)

py_test(
    name = "test_getters",
    srcs = ["test_getters.py"],
    main = "test_getters.py",
    python_version = "PY3",
    srcs_version = "PY3",
    deps = [
        ":examples_wrapper",
    ],
)

py_test(
    name = "test_enums",
    srcs = ["test_enums.py"],
    main = "test_enums.py",
    python_version = "PY3",
    srcs_version = "PY3",
    deps = [
        ":examples_wrapper",
    ],
)

py_test(
    name = "test_operators",
    srcs = ["test_operators.py"],
    main = "test_operators.py",
    python_version = "PY3",
    srcs_version = "PY3",
    deps = [
        ":examples_wrapper",
    ],
)

py_test(
    name = "test_overloaded_functions",
    srcs = ["test_overloaded_functions.py"],
    main = "test_overloaded_functions.py",
    python_version = "PY3",
    srcs_version = "PY3",
    deps = [
        ":examples_wrapper",
    ],
)

py_test(
    name = "test_templates",
    srcs = ["test_templates.py"],
    main = "test_templates.py",
    python_version = "PY3",
    srcs_version = "PY3",
    deps = [
        ":examples_wrapper",
    ],
)

py_test(
    name = "test_gen_files",
    srcs = ["test_gen_files.py"],
    main = "test_gen_files.py",
    python_version = "PY3",
    srcs_version = "PY3",
    deps = [
        ":examples_wrapper",
        "//examples/python:examples_usage_library",
    ],
)
