/**
 *   ______ .______   .______   .______    __  .__   __.  _______  
 *  /      ||   _  \  |   _  \  |   _  \  |  | |  \ |  | |       \ 
 * |  ,----'|  |_)  | |  |_)  | |  |_)  | |  | |   \|  | |  .--.  |
 * |  |     |   ___/  |   ___/  |   _  <  |  | |  . `  | |  |  |  |
 * |  `----.|  |      |  |      |  |_)  | |  | |  |\   | |  '--'  |
 *  \______|| _|      | _|      |______/  |__| |__| \__| |_______/ 
 * 
 * This file is generated by cppbind on 06/28/2022-09:40.
 * Please do not change it manually.
 */

#include <cxxabi.h>
#include <memory>
#include <pybind11/pybind11.h>
#include <pybind11/stl.h>
#include <pybind11/functional.h>

#include "cxx/globs/utils.h"
#include "cxx/simple/task.hpp"
#include "cxx/simple/root.hpp"

namespace py = pybind11;

void bindExamplesLibGlobsComplexdefaultsPygen(py::module& m) {
    {
        m.def("single_complex_default_value", &::singleComplexDefaultValue, py::arg("task") = cppbind::example::Task("MyTask"), py::return_value_policy::automatic);
    }
    {
        m.def("multiple_mixed_default_values", &::multipleMixedDefaultValues, py::arg("task") = cppbind::example::Task("DefaultTask"), py::arg("i") = 1, py::arg("r") = cppbind::example::Root("DefaultRoot"), py::return_value_policy::automatic);
    }
} /* bindExamplesLibGlobsComplexdefaultsPygen */
