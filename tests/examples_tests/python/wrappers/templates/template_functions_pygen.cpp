#include <pybind11/pybind11.h>
#include <pybind11/stl.h>
#include <pybind11/functional.h>

#include "examples/cxx/templates/template_functions.hpp"
#include "examples/cxx/classes/task.hpp"
#include "examples/cxx/classes/project.hpp"

namespace py = pybind11;

void bindTemplateFunctions(py::module& m) {
    using namespace iegen::example;
    py::class_<iegen::example::TemplateFunctions> templatefunctions(m, "TemplateFunctions");

    templatefunctions.def(py::init<>());
    templatefunctions.def("max", &iegen::example::TemplateFunctions::max<int>, py::arg("arg0"), py::arg("arg1"));
    templatefunctions.def("max", &iegen::example::TemplateFunctions::max<std::string>, py::arg("arg0"), py::arg("arg1"));
    templatefunctions.def("make_pair", &iegen::example::TemplateFunctions::makePair<iegen::example::Project, iegen::example::Project>, py::arg("arg0"), py::arg("arg1"));
    templatefunctions.def("make_pair", &iegen::example::TemplateFunctions::makePair<iegen::example::Task, iegen::example::Project>, py::arg("arg0"), py::arg("arg1"));
}