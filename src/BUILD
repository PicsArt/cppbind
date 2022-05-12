load("@reqs//:requirements.bzl", "all_requirements")

py_library(
    name = "cppbind_library",
    srcs = glob(["cppbind/**/*.py"]),
    data = glob(["cppbind/config/**/*"]),
    imports = [
        ".",
    ],
    visibility = ["//visibility:public"],
    deps = [
        "//:clang",
    ] + all_requirements,
)
