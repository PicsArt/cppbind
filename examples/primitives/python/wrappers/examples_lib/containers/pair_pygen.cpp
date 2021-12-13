/**
 * ,--.,------. ,----.   ,------.,--.  ,--. 
 * |  ||  .---''  .-.|   |  .---'|  ,'.|  | 
 * |  ||  `--, |  | .---.|  `--, |  |' '  | 
 * |  ||  `---.'  '--'  ||  `---.|  | `   | 
 * `--'`------' `------' `------'`--'  `--' 
 * 
 * This file is generated by iegen on 12/07/2021-12:30.
 * Please do not change it manually.
 */

#include <pybind11/pybind11.h>
#include <pybind11/stl.h>
#include <pybind11/functional.h>

#include "cxx/containers/pair.hpp"

namespace py = pybind11;

void bindIegenExamplePairExamples(py::module& m) {
    using namespace iegen::example;
    py::class_<iegen::example::PairExamples> pairExamples(m, "PairExamples");

    pairExamples.def(py::init<>());
    pairExamples.def("sum_int_pairs", &iegen::example::PairExamples::sumIntPairs, py::arg("p1"), py::arg("p2"));
    pairExamples.def("set_nested_pair", &iegen::example::PairExamples::setNestedPair, py::arg("p"));
    pairExamples.def("get_nested_pair", &iegen::example::PairExamples::getNestedPair);
    pairExamples.def("get_string_pair", &iegen::example::PairExamples::getStringPair);
}