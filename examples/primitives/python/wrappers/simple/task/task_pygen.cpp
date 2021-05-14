#include <pybind11/pybind11.h>
#include <pybind11/stl.h>
#include <pybind11/functional.h>

#include "cxx/simple/task.hpp"

namespace py = pybind11;

void bindPyTask(py::module& m) {
    using namespace iegen::example;
    py::class_<iegen::example::Task, std::shared_ptr<iegen::example::Task>> pytask(m, "PyTask");

    pytask.def(py::init<const std::string &>(), py::arg("title"));


    pytask.def_property_readonly("title", &iegen::example::Task::title);
}