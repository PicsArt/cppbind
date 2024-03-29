/**
 *   ______ .______   .______   .______    __  .__   __.  _______  
 *  /      ||   _  \  |   _  \  |   _  \  |  | |  \ |  | |       \ 
 * |  ,----'|  |_)  | |  |_)  | |  |_)  | |  | |   \|  | |  .--.  |
 * |  |     |   ___/  |   ___/  |   _  <  |  | |  . `  | |  |  |  |
 * |  `----.|  |      |  |      |  |_)  | |  | |  |\   | |  '--'  |
 *  \______|| _|      | _|      |______/  |__| |__| \__| |_______/ 
 * 
 * This file is generated by cppbind on 07/07/2022-10:39.
 * Please do not change it manually.
 */

#include <cxxabi.h>
#include <memory>
#include <pybind11/pybind11.h>
#include <pybind11/stl.h>
#include <pybind11/functional.h>

#include "cxx/globs/utils.h"

namespace py = pybind11;

void bindExamplesLibGlobsTemplateoverloadedutilsPygen(py::module& m) {
    {
        m.def("merge_int", &::merge<int>, py::arg("first"), py::arg("second"), py::return_value_policy::automatic);
    }
    {
        m.def("merge_string", &::merge<std::string>, py::arg("first"), py::arg("second"), py::return_value_policy::automatic);
    }
    {
        m.def("sum", py::overload_cast<ArrayInt, ArrayInt>(&::sum), py::arg("first"), py::arg("second"), py::return_value_policy::automatic);
    }
    {
        m.def("sum1", py::overload_cast<std::array<float, 4>, std::array<float, 4>>(&::sum), py::arg("first"), py::arg("second"), py::return_value_policy::automatic);
    }
} /* bindExamplesLibGlobsTemplateoverloadedutilsPygen */
