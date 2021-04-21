load("//:utils.bzl", "untar")

py_binary(
    name = "run_iegen",
    srcs = ["//:iegen_library"],
    legacy_create_init = False,
    main = "src/iegen/runner.py",
    python_version = "PY3",
    srcs_version = "PY3",
    deps = ["//:iegen_library"],
)

genrule(
    name = "runner",
    srcs = [
        "@examples//cxx:cc_examples_files",
        "@examples//:config_file",
    ],
    outs = ["iegen_out.tar.gz"],
    cmd = """
        ln -s external/examples/iegen_config.cfg iegen_config.cfg
        ln -s external/examples/cxx cxx
        $(location :run_iegen) python swift kotlin
        tar -C ./ -cvf $(@D)/iegen_out.tar.gz python swift kotlin
    """,
    tools = [":run_iegen"],
)

untar(
    name = "iegen_out",
    src = "iegen_out.tar.gz",
    out = "iegen_out",
)

py_test(
    name = "test_gen_files",
    srcs = ["test_gen_files.py"],
    data = [
        ":iegen_out",
        ":runner",
        "@examples//kotlin:examples_files",
        "@examples//python:examples_filess",
        "@examples//swift:examples_files",
    ],
    python_version = "PY3",
    srcs_version = "PY3",
)
