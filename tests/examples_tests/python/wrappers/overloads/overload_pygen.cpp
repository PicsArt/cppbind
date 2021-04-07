#include <pybind11/pybind11.h>
#include <pybind11/stl.h>
#include <pybind11/functional.h>

#include "examples/cxx/overloads/overload.hpp"

namespace py = pybind11;

void bindOverload(py::module& m) {
    using namespace iegen::example;
    py::class_<iegen::example::Overload, std::shared_ptr<iegen::example::Overload>> overload(m, "Overload");

    overload.def(py::init<>());
    overload.def("concatenate", py::overload_cast<std::string, std::string>(&iegen::example::Overload::concatenate), py::arg("first"), py::arg("second"));
    overload.def("concatenate", py::overload_cast<std::string, std::string, std::string>(&iegen::example::Overload::concatenate), py::arg("first"), py::arg("second"), py::arg("third"));
}