/*
 * This file was generated by iegen on 05/18/2021-20:19.
 * Please do not change it manually.
 */

#include <pybind11/pybind11.h>
#include <pybind11/stl.h>
#include <pybind11/functional.h>

#include "cxx/simple/root.hpp"

namespace py = pybind11;

void bindRoot(py::module& m) {
    using namespace iegen::example;
    py::class_<iegen::example::Root> root(m, "Root");

    root.def(py::init<const std::string &>(), py::arg("_path"));

    root.def_readonly("path", &iegen::example::Root::path);
}