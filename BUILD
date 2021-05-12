load("@rules_python//python:packaging.bzl", "py_package", "py_wheel")
load("@reqs//:requirements.bzl", "all_requirements")

# iegen wheel generation rules
py_library(
    name = "clang",
    srcs = glob(["3pty/clang/**/*.py"]),
    imports = ["3pty/"],
    visibility = ["//visibility:public"],
)

entry_points = {"console_scripts": [(
    "iegen = iegen.runner:run_package"
)]}

py_wheel(
    name = "iegen",
    # Package data. We're building "iegen-0.0.1-py3-none-any.whl"
    distribution = "iegen",
    entry_points = entry_points,
    python_tag = "py3",
    version = "0.0.1",
    deps = [
        ":clang",
        "//src:iegen_library",
    ],
)
