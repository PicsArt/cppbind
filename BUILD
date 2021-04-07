load("@rules_python//python:packaging.bzl", "py_package", "py_wheel")
load("@reqs//:requirements.bzl", "requirement")

py_library(
    name = "clang",
    srcs = glob(["3pty/clang/**/*.py"]),
)

entry_points = {"console_scripts": [(
    "iegen = iegen.runner:run_package"
)]}

py_library(
    name = "iegen",
    srcs = glob(["src/**/*.py"]),
)

py_wheel(
    name = "iegen",
    # Package data. We're building "iegen-0.0.1-py3-none-any.whl"
    distribution = "iegen",
    entry_points = entry_points,
    python_tag = "py3",
    version = "0.0.1",
    deps = [
        ":clang",
        ":iegen",
        requirement("attrs"),
    ],
)
