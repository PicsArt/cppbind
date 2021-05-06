#include <pybind11/pybind11.h>
#include <pybind11/stl.h>
#include <pybind11/functional.h>

#include "cxx/classes/task.hpp"

namespace py = pybind11;

void bindTask(py::module& m) {
    using namespace iegen::example;
    py::class_<iegen::example::Task> task(m, "Task");

    task.def(py::init<const std::string &>(), py::arg("title"));


    task.def_property_readonly("title", &iegen::example::Task::title);
}