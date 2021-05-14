#include <pybind11/pybind11.h>
#include <pybind11/stl.h>
#include <pybind11/functional.h>

#include "cxx/templates/stack.hpp"
#include "cxx/simple/project.hpp"
#include "cxx/simple/root.hpp"

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
void bindStackRoot(py::module& m) {
    using namespace iegen::example;
    py::class_<iegen::example::Stack<iegen::example::Root>> stackRoot(m, "StackRoot");

    stackRoot.def(py::init<>());

    stackRoot.def(py::init<iegen::example::Root &>(), py::arg("st"));
    stackRoot.def("push", &iegen::example::Stack<iegen::example::Root>::push, py::arg("item"));
    stackRoot.def("pop", &iegen::example::Stack<iegen::example::Root>::pop);
    stackRoot.def("top", &iegen::example::Stack<iegen::example::Root>::top);
    stackRoot.def("empty", &iegen::example::Stack<iegen::example::Root>::empty);
}