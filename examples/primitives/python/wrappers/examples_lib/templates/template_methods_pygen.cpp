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

#include "cxx/templates/template_methods.hpp"
#include "cxx/simple/project.hpp"
#include "cxx/simple/root.hpp"

namespace py = pybind11;

void bindIegenExampleTemplateMethods(py::module& m) {
    using namespace iegen::example;
    py::class_<iegen::example::TemplateMethods> templateMethods(m, "TemplateMethods");

    templateMethods.def(py::init<>());
    templateMethods.def("max", &iegen::example::TemplateMethods::max<int>, py::arg("arg0"), py::arg("arg1"));
    templateMethods.def("max", &iegen::example::TemplateMethods::max<std::string>, py::arg("arg0"), py::arg("arg1"));
    templateMethods.def("make_pair", &iegen::example::TemplateMethods::makePair<iegen::example::Project, iegen::example::Project>, py::arg("arg0"), py::arg("arg1"));
    templateMethods.def("make_pair", &iegen::example::TemplateMethods::makePair<iegen::example::Root, iegen::example::Project>, py::arg("arg0"), py::arg("arg1"));
}