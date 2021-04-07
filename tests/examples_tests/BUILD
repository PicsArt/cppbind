load("@pybind11_bazel//:build_defs.bzl", "pybind_extension")
load("@rules_cc//cc:defs.bzl", "cc_binary")

#genrule(
#    name = "examples_library",
#    srcs = [
#        "//examples/cxx/getters:getter.hpp",
#        "//examples/cxx/classes:room.hpp",
#        "//examples/cxx/overloads/overload.hpp",
#    ],
#    outs = ["getter.hpp"],
#    cmd = "cp $(location //examples/cxx/getters:getter.hpp) $@",
#)

pybind_extension(
    name = "iegen",
    srcs = glob([
        "python/wrappers/**/*.cpp",
        "python/wrappers/**/*.hpp",
    ]),
    deps = [
        "//examples:examples_lib",
    ],
)

py_library(
    name = "wrapper",
    srcs = glob(["python/src/**/*.py"]),
    data = [
        "iegen.so",
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
        ":wrapper",
    ],
)

py_test(
    name = "test_getters",
    srcs = ["python/test_getters.py"],
    main = "python/test_getters.py",
    python_version = "PY3",
    srcs_version = "PY3",
    deps = [
        ":wrapper",
    ],
)
