#include <pybind11/pybind11.h>
#include "examples_pygen.hpp"

namespace py = pybind11;
void bindExamples(py::module& m) {
    py::module_ classes = m.def_submodule("classes", "classes");
    py::module_ classes_task = classes.def_submodule("task", "task");
    bindTask(classes_task);
    py::module_ classes_project = classes.def_submodule("project", "project");
    bindProject(classes_project);
    py::module_ classes_root = classes.def_submodule("root", "root");
    bindRoot(classes_root);
    py::module_ enums = m.def_submodule("enums", "enums");
    py::module_ enums_color = enums.def_submodule("color", "color");
    bindColor(enums_color);
    py::module_ optionals = m.def_submodule("optionals", "optionals");
    py::module_ optionals_optionals = optionals.def_submodule("optionals", "optionals");
    bindOptionals(optionals_optionals);
}