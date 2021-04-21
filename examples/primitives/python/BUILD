load("@pybind11_bazel//:build_defs.bzl", "pybind_extension")

pybind_extension(
    name = "examples",
    srcs = glob([
        "**/*.cpp",
        "**/*.hpp",
    ]),
    visibility = ["//visibility:public"],
    deps = [
        "//cxx:cc_examples_library",
    ],
)

py_library(
    name = "py_examples_library",
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
    name = "main",
    srcs = ["src/classes/main.py"],
    python_version = "PY3",
    srcs_version = "PY3",
    visibility = ["//visibility:public"],
    deps = [
        ":py_examples_library",
    ],
)

filegroup(
    name = "examples_filess",
    srcs = glob([
        "src/**/*.py",
        "wrappers/**/*.cpp",
        "wrappers/**/*.hpp",
    ]),
    visibility = ["//visibility:public"],
)
