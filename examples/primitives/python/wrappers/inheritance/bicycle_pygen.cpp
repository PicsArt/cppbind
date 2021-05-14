#include <pybind11/pybind11.h>
#include <pybind11/stl.h>
#include <pybind11/functional.h>

#include "cxx/inheritance/bicycle.hpp"

namespace py = pybind11;

void bindBicycle(py::module& m) {
    using namespace iegen::example;
    py::class_<iegen::example::Bicycle, std::shared_ptr<iegen::example::Bicycle>,iegen::example::Vehicle> bicycle(m, "Bicycle");

    bicycle.def(py::init<int>(), py::arg("numberOfSeats"));
}