#include <pybind11/pybind11.h>
#include <pybind11/stl.h>
#include <pybind11/functional.h>

#include "cxx/templates/stack.hpp"
#include "cxx/classes/project.hpp"
#include "cxx/classes/task.hpp"

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
void bindStackPyTask(py::module& m) {
    using namespace iegen::example;
    py::class_<iegen::example::Stack<iegen::example::Task>> stackPytask(m, "StackPyTask");

    stackPytask.def(py::init<>());

    stackPytask.def(py::init<iegen::example::Task &>(), py::arg("st"));
    stackPytask.def("push", &iegen::example::Stack<iegen::example::Task>::push, py::arg("item"));
    stackPytask.def("pop", &iegen::example::Stack<iegen::example::Task>::pop);
    stackPytask.def("top", &iegen::example::Stack<iegen::example::Task>::top);
    stackPytask.def("empty", &iegen::example::Stack<iegen::example::Task>::empty);
}