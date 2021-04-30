#include <pybind11/pybind11.h>
#include <pybind11/stl.h>
#include <pybind11/functional.h>

#include "cxx/templates/stack.hpp"
#include "cxx/simple/project.hpp"
#include "cxx/simple/task.hpp"

namespace py = pybind11;

void bindStackProject(py::module& m) {
    using namespace iegen::example;
    py::class_<iegen::example::Stack<iegen::example::Project>> stackProject(m, "StackProject");

    stackProject.def(py::init<>());

    stackProject.def(py::init<iegen::example::Project &>(), py::arg("st"));
    stackProject.def("push", &iegen::example::Stack<iegen::example::Project>::push, py::arg("item"));
    stackProject.def("pop", &iegen::example::Stack<iegen::example::Project>::pop);
    stackProject.def("top", &iegen::example::Stack<iegen::example::Project>::top);
    stackProject.def("empty", &iegen::example::Stack<iegen::example::Project>::empty);
}
void bindStackTask(py::module& m) {
    using namespace iegen::example;
    py::class_<iegen::example::Stack<iegen::example::Task>> stackTask(m, "StackTask");

    stackTask.def(py::init<>());

    stackTask.def(py::init<iegen::example::Task &>(), py::arg("st"));
    stackTask.def("push", &iegen::example::Stack<iegen::example::Task>::push, py::arg("item"));
    stackTask.def("pop", &iegen::example::Stack<iegen::example::Task>::pop);
    stackTask.def("top", &iegen::example::Stack<iegen::example::Task>::top);
    stackTask.def("empty", &iegen::example::Stack<iegen::example::Task>::empty);
}