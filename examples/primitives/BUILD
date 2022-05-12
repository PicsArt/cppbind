config_setting(
    name = "on_linux",
    constraint_values = [
        "@platforms//os:linux",
    ],
)

config_setting(
    name = "on_macos",
    constraint_values = [
        "@platforms//os:macos",
    ],
)

filegroup(
    name = "config_file",
    srcs = ["cppbind_config.cfg"],
    visibility = ["//visibility:public"],
)
