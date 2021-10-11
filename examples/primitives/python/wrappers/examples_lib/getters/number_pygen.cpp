/**
 * ,--.,------. ,----.   ,------.,--.  ,--. 
 * |  ||  .---''  .-.|   |  .---'|  ,'.|  | 
 * |  ||  `--, |  | .---.|  `--, |  |' '  | 
 * |  ||  `---.'  '--'  ||  `---.|  | `   | 
 * `--'`------' `------' `------'`--'  `--' 
 * 
 * This file is generated by iegen on 09/23/2021-13:55.
 * Please do not change it manually.
 */

#include <pybind11/pybind11.h>
#include <pybind11/stl.h>
#include <pybind11/functional.h>

#include "cxx/getters/number.hpp"

namespace py = pybind11;

void bindIegenExampleNumberInt(py::module& m) {
    using namespace iegen::example;
    py::class_<iegen::example::Number<int>> numberInt(m, "NumberInt");

    numberInt.def(py::init<const int &>(), py::arg("n"));
    numberInt.def("__int__", &iegen::example::Number<int>::toInt);

    numberInt.def_readwrite("num", &iegen::example::Number<int>::num);
}
void bindIegenExampleNumberFloat(py::module& m) {
    using namespace iegen::example;
    py::class_<iegen::example::Number<double>> numberFloat(m, "NumberFloat");

    numberFloat.def(py::init<const double &>(), py::arg("n"));
    numberFloat.def("__int__", &iegen::example::Number<double>::toInt);

    numberFloat.def_readwrite("num", &iegen::example::Number<double>::num);
}