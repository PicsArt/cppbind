#include <pybind11/pybind11.h>
#include <pybind11/stl.h>
#include <pybind11/functional.h>

#include "examples/cxx/overloads/overload.hpp"

namespace py = pybind11;

void bindOverloadedFunctions(py::module& m) {
    using namespace iegen::example;
    py::class_<iegen::example::OverloadedFunctions, std::shared_ptr<iegen::example::OverloadedFunctions>> overloadedfunctions(m, "OverloadedFunctions");

    overloadedfunctions.def(py::init<>());
    overloadedfunctions.def("concatenate", py::overload_cast<std::string, std::string>(&iegen::example::OverloadedFunctions::concatenate), py::arg("first"), py::arg("second"));
    overloadedfunctions.def("concatenate", py::overload_cast<std::string, std::string, std::string>(&iegen::example::OverloadedFunctions::concatenate), py::arg("first"), py::arg("second"), py::arg("third"));
}