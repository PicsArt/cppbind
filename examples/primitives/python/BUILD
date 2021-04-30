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
    name = "classes",
    srcs = ["src/classes/main.py"],
    main = "src/classes/main.py",
    python_version = "PY3",
    srcs_version = "PY3",
    visibility = ["//visibility:public"],
    deps = [
        ":py_examples_library",
    ],
)

py_test(
    name = "getters",
    srcs = ["src/getters/main.py"],
    main = "src/getters/main.py",
    python_version = "PY3",
    srcs_version = "PY3",
    visibility = ["//visibility:public"],
    deps = [
        ":py_examples_library",
    ],
)

py_test(
    name = "functionals",
    srcs = ["src/functions/main.py"],
    main = "src/functions/main.py",
    python_version = "PY3",
    srcs_version = "PY3",
    visibility = ["//visibility:public"],
    deps = [
        ":py_examples_library",
    ],
)

py_test(
    name = "inheritance",
    srcs = ["src/inheritance/main.py"],
    main = "src/inheritance/main.py",
    python_version = "PY3",
    srcs_version = "PY3",
    visibility = ["//visibility:public"],
    deps = [
        ":py_examples_library",
    ],
)

py_test(
    name = "templates",
    srcs = ["src/templates/main.py"],
    main = "src/templates/main.py",
    python_version = "PY3",
    srcs_version = "PY3",
    visibility = ["//visibility:public"],
    deps = [
        ":py_examples_library",
    ],
)

filegroup(
    name = "examples_files",
    srcs = glob([
        "src/**/*.py",
        "wrappers/**/*.cpp",
        "wrappers/**/*.hpp",
    ]),
    visibility = ["//visibility:public"],
)
