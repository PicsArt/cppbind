#include <pybind11/pybind11.h>
#include "hello_user.hpp"

namespace py = pybind11;
void bindHelloUser(py::module& m) {
    py::module_ hello = m.def_submodule("hello", "hello");
    py::module_ hello_hello_user = hello.def_submodule("hello_user", "hello_user");
    bindUserInfo(hello_hello_user);
    bindHost(hello_hello_user);
}