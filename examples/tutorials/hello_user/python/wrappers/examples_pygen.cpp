#include <pybind11/pybind11.h>
#include "examples_pygen.hpp"

namespace py = pybind11;
void bindExamples(py::module& m) {
    py::module_ undefined = m.def_submodule("undefined", "undefined");
    py::module_ undefined_hello_user = undefined.def_submodule("hello_user", "hello_user");
    bindUserInfo(undefined_hello_user);
    bindHost(undefined_hello_user);
}