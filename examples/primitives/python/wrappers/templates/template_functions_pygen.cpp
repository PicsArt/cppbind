#include <pybind11/pybind11.h>
#include <pybind11/stl.h>
#include <pybind11/functional.h>

#include "cxx/templates/template_functions.hpp"
#include "cxx/simple/project.hpp"
#include "cxx/simple/task.hpp"

namespace py = pybind11;

void bindTemplateMethods(py::module& m) {
    using namespace iegen::example;
    py::class_<iegen::example::TemplateMethods> templatemethods(m, "TemplateMethods");

    templatemethods.def(py::init<>());
    templatemethods.def("max", &iegen::example::TemplateMethods::max<int>, py::arg("arg0"), py::arg("arg1"));
    templatemethods.def("max", &iegen::example::TemplateMethods::max<std::string>, py::arg("arg0"), py::arg("arg1"));
    templatemethods.def("make_pair", &iegen::example::TemplateMethods::makePair<iegen::example::Project, iegen::example::Project>, py::arg("arg0"), py::arg("arg1"));
    templatemethods.def("make_pair", &iegen::example::TemplateMethods::makePair<iegen::example::Task, iegen::example::Project>, py::arg("arg0"), py::arg("arg1"));
}