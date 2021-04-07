load("@bazel_tools//tools/build_defs/repo:http.bzl", "http_archive")

http_archive(
    name = "rules_python",
    sha256 = "778197e26c5fbeb07ac2a2c5ae405b30f6cb7ad1f5510ea6fdac03bded96cc6f",
    url = "https://github.com/bazelbuild/rules_python/releases/download/0.2.0/rules_python-0.2.0.tar.gz",
)

## pybind
rules_pybind_sha = "26973c0ff320cb4b39e45bc3e4297b82bc3a6c09"

http_archive(
    name = "pybind11_bazel",
    strip_prefix = "pybind11_bazel-%s" % rules_pybind_sha,
    urls = ["https://github.com/pybind/pybind11_bazel/archive/%s.zip" % rules_pybind_sha],
)

pybind_version = "2.6.2"

http_archive(
    name = "pybind11",
    build_file = "@pybind11_bazel//:pybind11.BUILD",
    strip_prefix = "pybind11-%s" % pybind_version,
    urls = ["https://github.com/pybind/pybind11/archive/v%s.tar.gz" % pybind_version],
)

load("@pybind11_bazel//:python_configure.bzl", "python_configure")

python_configure(name = "local_config_python")

load("@rules_python//python:pip.bzl", "pip_install")

# Create a central repo that knows about the dependencies needed for
# requirements.txt.
pip_install(
    name = "reqs",
    requirements = "//:requirements.txt",
)
