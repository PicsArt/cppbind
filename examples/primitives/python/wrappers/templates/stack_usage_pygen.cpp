#include <pybind11/pybind11.h>
#include <pybind11/stl.h>
#include <pybind11/functional.h>

#include "cxx/templates/stack_usage.hpp"
#include "cxx/simple/project.hpp"

namespace py = pybind11;

void bindStackUsage(py::module& m) {
    using namespace iegen::example;
    py::class_<iegen::example::StackUsage> stackusage(m, "StackUsage");

    stackusage.def(py::init<>());
    stackusage.def("first_item_of_specialized_stack", &iegen::example::StackUsage::firstItemOfSpecializedStack, py::arg("p"));
    stackusage.def("first_item_of_template_stack", &iegen::example::StackUsage::firstItemOfTemplateStack<iegen::example::Project>, py::arg("arg0"));
}