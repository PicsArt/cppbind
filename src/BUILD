load("@reqs//:requirements.bzl", "all_requirements")

py_library(
    name = "iegen_library",
    srcs = glob(["iegen/**/*.py"]),
    data = glob(["iegen/config/**/*"]),
    imports = [
        ".",
    ],
    visibility = ["//visibility:public"],
    deps = [
        "//:clang",
    ] + all_requirements,
)
