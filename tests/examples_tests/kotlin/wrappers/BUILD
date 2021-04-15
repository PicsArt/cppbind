cc_library(
    name = "examples_wrapper",
    srcs = glob(["**/*.cpp"]),
    hdrs = glob([
        "**/*.hpp",
        "**/*.h",
    ]),
    visibility = ["//visibility:public"],
    deps = [
        "//:copy_jni_hdr_lib",
        "//examples:examples_cc_library",
    ],
    alwayslink = True,
)

cc_binary(
    name = "libwrapper_jni.so",
    linkshared = True,
    visibility = ["//visibility:public"],
    deps = [":examples_wrapper"],
)
