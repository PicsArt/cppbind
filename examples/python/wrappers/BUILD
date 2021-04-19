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
