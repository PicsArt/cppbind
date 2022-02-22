/**
 * ,--.,------. ,----.   ,------.,--.  ,--. 
 * |  ||  .---''  .-.|   |  .---'|  ,'.|  | 
 * |  ||  `--, |  | .---.|  `--, |  |' '  | 
 * |  ||  `---.'  '--'  ||  `---.|  | `   | 
 * `--'`------' `------' `------'`--'  `--' 
 * 
 * This file is generated by iegen on 02/16/2022-06:24.
 * Please do not change it manually.
 */

#include <pybind11/pybind11.h>
#include <pybind11/stl.h>
#include <pybind11/functional.h>

#include "cxx/containers/map.hpp"

namespace py = pybind11;

void bindExamplesLibContainersMap(py::module& m) {
    {
        using namespace iegen::example;
        py::class_<iegen::example::MapItem> mapItem(m, "MapItem");
        mapItem.def_readwrite("value", &iegen::example::MapItem::value, py::return_value_policy::reference_internal);

        mapItem.def(py::init<int>(), py::arg("_value"));
    }
    {
        using namespace iegen::example;
        py::class_<iegen::example::MapExamples> mapExamples(m, "MapExamples");
        
        mapExamples.def(py::init<>());
        mapExamples.def("add_string_pair", &iegen::example::MapExamples::addStringPair, py::arg("info"));
        mapExamples.def("add_int_map", &iegen::example::MapExamples::addIntMap, py::arg("info"));
        mapExamples.def("add_string_map", &iegen::example::MapExamples::addStringMap, py::arg("info"));
        mapExamples.def("get_string_map", &iegen::example::MapExamples::getStringMap, py::return_value_policy::automatic);
        mapExamples.def("get_int_map", &iegen::example::MapExamples::getIntMap, py::return_value_policy::automatic);
        mapExamples.def("add_mixed_map", &iegen::example::MapExamples::addMixedMap, py::arg("info"));
        mapExamples.def("get_mixed_map", &iegen::example::MapExamples::getMixedMap, py::return_value_policy::automatic);
    }
} /* bindExamplesLibContainersMap */
