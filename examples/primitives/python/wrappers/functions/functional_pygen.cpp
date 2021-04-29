#include <pybind11/pybind11.h>
#include <pybind11/stl.h>
#include <pybind11/functional.h>

#include "cxx/functions/functional.hpp"

namespace py = pybind11;

void bindFunctionalExamples(py::module& m) {
    using namespace iegen::example;
    py::class_<iegen::example::FunctionalExamples, std::shared_ptr<iegen::example::FunctionalExamples>> functionalexamples(m, "FunctionalExamples");

    functionalexamples.def(py::init<>());
    functionalexamples.def_static("gen_func_to_increment_result", &iegen::example::FunctionalExamples::genFuncToIncrementResult, py::arg("f"));
}