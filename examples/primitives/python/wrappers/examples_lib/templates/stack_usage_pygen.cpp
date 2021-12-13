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

#include "cxx/templates/stack_usage.hpp"
#include "cxx/templates/stack.hpp"
#include "cxx/simple/project.hpp"

namespace py = pybind11;

void bindIegenExampleStackUsage(py::module& m) {
    using namespace iegen::example;
    py::class_<iegen::example::StackUsage> stackUsage(m, "StackUsage");

    stackUsage.def(py::init<>());
    stackUsage.def("first_item_of_specialized_stack", &iegen::example::StackUsage::firstItemOfSpecializedStack, py::arg("p"));
    stackUsage.def("first_item_of_template_stack", &iegen::example::StackUsage::firstItemOfTemplateStack<iegen::example::Project>, py::arg("arg0"));
}