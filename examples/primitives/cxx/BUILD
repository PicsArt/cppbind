cc_library(
    name = "cc_examples_library",
    srcs = glob(["**/*.cpp"]),
    hdrs = glob([
        "**/*.hpp",
        "**/*.h",
    ]),
    visibility = ["//visibility:public"],
    deps = [
        "@nlohmann_json//:json"
    ],
)

filegroup(
    name = "cc_examples_files",
    srcs = glob([
        "**/*.cpp",
        "**/*.h*",
        "**/*.yaml",
        "**/*.yml",
    ]),
    visibility = ["//visibility:public"],
)
