/**
 *   ______ .______   .______   .______    __  .__   __.  _______  
 *  /      ||   _  \  |   _  \  |   _  \  |  | |  \ |  | |       \ 
 * |  ,----'|  |_)  | |  |_)  | |  |_)  | |  | |   \|  | |  .--.  |
 * |  |     |   ___/  |   ___/  |   _  <  |  | |  . `  | |  |  |  |
 * |  `----.|  |      |  |      |  |_)  | |  | |  |\   | |  '--'  |
 *  \______|| _|      | _|      |______/  |__| |__| \__| |_______/ 
 * 
 * This file is generated by cppbind on 07/19/2022-13:00.
 * Please do not change it manually.
 */

#include <cxxabi.h>
#include <memory>
#include <pybind11/pybind11.h>
#include <pybind11/stl.h>
#include <pybind11/functional.h>

#include "cxx/basic_types/short.hpp"

namespace py = pybind11;

void bindExamplesLibBasicTypesShortPygen(py::module& m) {
    {
        using namespace cppbind::example;
        m.def("add", py::overload_cast<std::int16_t, std::int16_t>(&cppbind::example::add), py::arg("a"), py::arg("b"), py::return_value_policy::automatic);
    }
    {
        using namespace cppbind::example;
        m.def("add1", py::overload_cast<std::vector<short>, short>(&cppbind::example::add), py::arg("v"), py::arg("a"), py::return_value_policy::automatic);
    }
    {
        using namespace cppbind::example;
        m.def("add2", py::overload_cast<std::pair<short, short>, std::pair<short, short>>(&cppbind::example::add), py::arg("p1"), py::arg("p2"), py::return_value_policy::automatic);
    }
} /* bindExamplesLibBasicTypesShortPygen */
