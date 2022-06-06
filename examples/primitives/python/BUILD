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
        "buffer.so",
        "examples.so",
    ],
    imports = [
        ".",
        "src/",
    ],
    srcs_version = "PY3",
    visibility = ["//visibility:public"],
)

# third party buffer
pybind_extension(
    name = "buffer",
    srcs = ["wrappers/examples_lib/misc/buffer.cpp"],
    visibility = ["//visibility:public"],
    deps = [
        "//cxx:cc_examples_library",
    ],
)

py_test(
    name = "simple",
    srcs = ["src/examples_lib/simple/main.py"],
    main = "src/examples_lib/simple/main.py",
    python_version = "PY3",
    srcs_version = "PY3",
    visibility = ["//visibility:public"],
    deps = [
        ":py_examples_library",
    ],
)

py_test(
    name = "getters",
    srcs = ["src/examples_lib/getters/main.py"],
    main = "src/examples_lib/getters/main.py",
    python_version = "PY3",
    srcs_version = "PY3",
    visibility = ["//visibility:public"],
    deps = [
        ":py_examples_library",
    ],
)

py_test(
    name = "functionals",
    srcs = ["src/examples_lib/functionals/main.py"],
    main = "src/examples_lib/functionals/main.py",
    python_version = "PY3",
    srcs_version = "PY3",
    visibility = ["//visibility:public"],
    deps = [
        ":py_examples_library",
    ],
)

py_test(
    name = "inheritance",
    srcs = ["src/examples_lib/inheritance/main.py"],
    main = "src/examples_lib/inheritance/main.py",
    python_version = "PY3",
    srcs_version = "PY3",
    visibility = ["//visibility:public"],
    deps = [
        ":py_examples_library",
    ],
)

py_test(
    name = "templates",
    srcs = ["src/examples_lib/templates/main.py"],
    main = "src/examples_lib/templates/main.py",
    python_version = "PY3",
    srcs_version = "PY3",
    visibility = ["//visibility:public"],
    deps = [
        ":py_examples_library",
    ],
)

py_test(
    name = "containers",
    srcs = ["src/examples_lib/containers/main.py"],
    main = "src/examples_lib/containers/main.py",
    python_version = "PY3",
    srcs_version = "PY3",
    visibility = ["//visibility:public"],
    deps = [
        ":py_examples_library",
    ],
)

py_test(
    name = "forward_decl",
    srcs = ["src/examples_lib/forward_decl/main.py"],
    main = "src/examples_lib/forward_decl/main.py",
    python_version = "PY3",
    srcs_version = "PY3",
    visibility = ["//visibility:public"],
    deps = [
        ":py_examples_library",
    ],
)

py_test(
    name = "operators",
    srcs = ["src/examples_lib/operators/main.py"],
    main = "src/examples_lib/operators/main.py",
    python_version = "PY3",
    srcs_version = "PY3",
    visibility = ["//visibility:public"],
    deps = [
        ":py_examples_library",
    ],
)

py_test(
    name = "overloads",
    srcs = ["src/examples_lib/overloads/main.py"],
    main = "src/examples_lib/overloads/main.py",
    python_version = "PY3",
    srcs_version = "PY3",
    visibility = ["//visibility:public"],
    deps = [
        ":py_examples_library",
    ],
)

py_test(
    name = "optionals",
    srcs = ["src/examples_lib/optionals/main.py"],
    main = "src/examples_lib/optionals/main.py",
    python_version = "PY3",
    srcs_version = "PY3",
    visibility = ["//visibility:public"],
    deps = [
        ":py_examples_library",
    ],
)

py_test(
    name = "nullables",
    srcs = ["src/examples_lib/nullables/main.py"],
    main = "src/examples_lib/nullables/main.py",
    python_version = "PY3",
    srcs_version = "PY3",
    visibility = ["//visibility:public"],
    deps = [
        ":py_examples_library",
    ],
)

py_test(
    name = "shared_ptr",
    srcs = ["src/examples_lib/shared_ptr/main.py"],
    main = "src/examples_lib/shared_ptr/main.py",
    python_version = "PY3",
    srcs_version = "PY3",
    visibility = ["//visibility:public"],
    deps = [
        ":py_examples_library",
    ],
)

py_test(
    name = "misc",
    srcs = ["src/examples_lib/misc/main.py"],
    main = "src/examples_lib/misc/main.py",
    python_version = "PY3",
    srcs_version = "PY3",
    visibility = ["//visibility:public"],
    deps = [
        ":py_examples_library",
    ],
)

py_test(
    name = "extra",
    srcs = ["src/examples_lib/extra/main.py"],
    main = "src/examples_lib/extra/main.py",
    python_version = "PY3",
    srcs_version = "PY3",
    visibility = ["//visibility:public"],
    deps = [
        ":py_examples_library",
    ],
)

py_test(
    name = "enums",
    srcs = ["src/examples_lib/enums/main.py"],
    main = "src/examples_lib/enums/main.py",
    python_version = "PY3",
    srcs_version = "PY3",
    visibility = ["//visibility:public"],
    deps = [
        ":py_examples_library",
    ],
)

py_test(
    name = "globs",
    srcs = ["src/examples_lib/globs/main.py"],
    main = "src/examples_lib/globs/main.py",
    python_version = "PY3",
    srcs_version = "PY3",
    visibility = ["//visibility:public"],
    deps = [
        ":py_examples_library",
    ],
)

py_test(
    name = "rv_policies",
    srcs = ["src/examples_lib/rv_policies/main.py"],
    main = "src/examples_lib/rv_policies/main.py",
    python_version = "PY3",
    srcs_version = "PY3",
    visibility = ["//visibility:public"],
    deps = [
        ":py_examples_library",
    ],
)

py_test(
    name = "typedefs",
    srcs = ["src/examples_lib/typedefs/main.py"],
    main = "src/examples_lib/typedefs/main.py",
    python_version = "PY3",
    srcs_version = "PY3",
    visibility = ["//visibility:public"],
    deps = [
        ":py_examples_library",
    ],
)

py_test(
    name = "nested_types",
    srcs = ["src/examples_lib/nested_types/main.py"],
    main = "src/examples_lib/nested_types/main.py",
    python_version = "PY3",
    srcs_version = "PY3",
    visibility = ["//visibility:public"],
    deps = [
        ":py_examples_library",
    ],
)

py_test(
    name = "hashing",
    srcs = ["src/examples_lib/hashing/main.py"],
    main = "src/examples_lib/hashing/main.py",
    python_version = "PY3",
    srcs_version = "PY3",
    visibility = ["//visibility:public"],
    deps = [
        ":py_examples_library",
    ],
)
