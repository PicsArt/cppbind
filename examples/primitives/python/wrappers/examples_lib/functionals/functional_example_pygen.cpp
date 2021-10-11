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

#include "cxx/functionals/functional_example.hpp"

namespace py = pybind11;

void bindIegenExampleFunctionalExamples(py::module& m) {
    using namespace iegen::example;
    py::class_<iegen::example::FunctionalExamples, std::shared_ptr<iegen::example::FunctionalExamples>> functionalExamples(m, "FunctionalExamples");

    functionalExamples.def(py::init<>());
    functionalExamples.def_static("gen_func_to_increment_result", &iegen::example::FunctionalExamples::genFuncToIncrementResult, py::arg("f"));
}