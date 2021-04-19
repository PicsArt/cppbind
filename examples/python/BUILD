genrule(
    name = "py_examples_wrapper",
    srcs = ["//python/wrappers:examples.so"],
    outs = ["examples.so"],
    cmd = "cp $(location //python/wrappers:examples.so) $@",
)

py_library(
    name = "py_examples_library",
    srcs = glob(["src/**/*.py"]),
    data = [
        ":py_examples_wrapper",
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
