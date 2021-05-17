#include <pybind11/pybind11.h>
#include <pybind11/stl.h>
#include <pybind11/functional.h>

#include "cxx/inheritance/rhombus.hpp"

namespace py = pybind11;

void bindRhombus(py::module& m) {
    using namespace iegen::example;
    py::class_<iegen::example::Rhombus,iegen::example::Parallelogram> rhombus(m, "Rhombus");

    rhombus.def(py::init<double, double>(), py::arg("diagonal1"), py::arg("diagonal2"));
}