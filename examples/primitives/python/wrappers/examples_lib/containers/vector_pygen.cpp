/**
 *   ______ .______   .______   .______    __  .__   __.  _______  
 *  /      ||   _  \  |   _  \  |   _  \  |  | |  \ |  | |       \ 
 * |  ,----'|  |_)  | |  |_)  | |  |_)  | |  | |   \|  | |  .--.  |
 * |  |     |   ___/  |   ___/  |   _  <  |  | |  . `  | |  |  |  |
 * |  `----.|  |      |  |      |  |_)  | |  | |  |\   | |  '--'  |
 *  \______|| _|      | _|      |______/  |__| |__| \__| |_______/ 
 * 
 * This file is generated by cppbind on 05/12/2022-10:33.
 * Please do not change it manually.
 */

#include <pybind11/pybind11.h>
#include <pybind11/stl.h>
#include <pybind11/functional.h>

#include "cxx/containers/vector.hpp"

namespace py = pybind11;

void bindExamplesLibContainersVectorPygen(py::module& m) {
    {
        using namespace cppbind::example;
        py::class_<cppbind::example::VectorItem> vectorItem(m, "VectorItem");
        vectorItem.def_readwrite("value", &cppbind::example::VectorItem::value, py::return_value_policy::reference_internal);

        vectorItem.def(py::init<int>(), py::arg("_value"));
    }
    {
        using namespace cppbind::example;
        py::class_<cppbind::example::VectorExamples> vectorExamples(m, "VectorExamples");
        
        vectorExamples.def(py::init<>());
        vectorExamples.def("add_int_vector", &cppbind::example::VectorExamples::addIntVector, py::arg("v"));
        vectorExamples.def("add_obj_vector", &cppbind::example::VectorExamples::addObjVector, py::arg("v"));
        vectorExamples.def("add_string_vector", &cppbind::example::VectorExamples::addStringVector, py::arg("v"));
        vectorExamples.def("get_string_vector", &cppbind::example::VectorExamples::getStringVector, py::return_value_policy::automatic);
        vectorExamples.def("get_obj_vector", &cppbind::example::VectorExamples::getObjVector, py::return_value_policy::reference);
        vectorExamples.def("get_int_vector", &cppbind::example::VectorExamples::getIntVector, py::return_value_policy::automatic);
    }
} /* bindExamplesLibContainersVectorPygen */
