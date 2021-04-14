load("@pybind11_bazel//:build_defs.bzl", "pybind_extension")
load("@rules_cc//cc:defs.bzl", "cc_binary")

pybind_extension(
    name = "examples",
    srcs = glob([
        "python/wrappers/**/*.cpp",
        "python/wrappers/**/*.hpp",
    ]),
    deps = [
        "//examples:examples_cc_library",
    ],
)

py_library(
    name = "examples_wrapper",
    srcs = glob(["python/src/**/*.py"]),
    data = [
        "examples.so",
    ],
    imports = [
        ".",
        "python/src/",
    ],
    srcs_version = "PY3",
    visibility = ["//visibility:public"],
)

py_test(
    name = "test_containers",
    srcs = ["python/test_containers.py"],
    main = "python/test_containers.py",
    python_version = "PY3",
    srcs_version = "PY3",
    deps = [
        ":examples_wrapper",
    ],
)

py_test(
    name = "test_getters",
    srcs = ["python/test_getters.py"],
    main = "python/test_getters.py",
    python_version = "PY3",
    srcs_version = "PY3",
    deps = [
        ":examples_wrapper",
    ],
)

py_test(
    name = "test_enums",
    srcs = ["python/test_enums.py"],
    main = "python/test_enums.py",
    python_version = "PY3",
    srcs_version = "PY3",
    deps = [
        ":examples_wrapper",
    ],
)

py_test(
    name = "test_operators",
    srcs = ["python/test_operators.py"],
    main = "python/test_operators.py",
    python_version = "PY3",
    srcs_version = "PY3",
    deps = [
        ":examples_wrapper",
    ],
)

py_test(
    name = "test_overloaded_functions",
    srcs = ["python/test_overloaded_functions.py"],
    main = "python/test_overloaded_functions.py",
    python_version = "PY3",
    srcs_version = "PY3",
    deps = [
        ":examples_wrapper",
    ],
)

py_test(
    name = "test_templates",
    srcs = ["python/test_templates.py"],
    main = "python/test_templates.py",
    python_version = "PY3",
    srcs_version = "PY3",
    deps = [
        ":examples_wrapper",
    ],
)

py_test(
    name = "test_gen_files",
    srcs = ["python/test_gen_files.py"],
    main = "python/test_gen_files.py",
    python_version = "PY3",
    srcs_version = "PY3",
    deps = [
        ":examples_wrapper",
        "//examples:examples_py_library",
    ],
)
