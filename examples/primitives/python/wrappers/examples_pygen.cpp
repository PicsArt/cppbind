#include <pybind11/pybind11.h>
#include "examples_pygen.hpp"

namespace py = pybind11;
void bindExamples(py::module& m) {
    py::module_ extra = m.def_submodule("extra", "extra");
    py::module_ extra_object = extra.def_submodule("object", "object");
    bindObject(extra_object);
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
    py::module_ operators = m.def_submodule("operators", "operators");
    py::module_ operators_counter = operators.def_submodule("counter", "counter");
    bindCounter(operators_counter);
    py::module_ overloads = m.def_submodule("overloads", "overloads");
    py::module_ overloads_overload = overloads.def_submodule("overload", "overload");
    bindOverloadedFunctions(overloads_overload);
    py::module_ templates = m.def_submodule("templates", "templates");
    py::module_ templates_addressable = templates.def_submodule("addressable", "addressable");
    bindAddressableRoot(templates_addressable);
    py::module_ templates_component = templates.def_submodule("component", "component");
    bindComponent(templates_component);
    py::module_ templates_stack = templates.def_submodule("stack", "stack");
    bindStackProject(templates_stack);
    bindStackTask(templates_stack);
    py::module_ templates_stack_usage = templates.def_submodule("stack_usage", "stack_usage");
    bindStackUsage(templates_stack_usage);
    py::module_ templates_template_functions = templates.def_submodule("template_functions", "template_functions");
    bindTemplateFunctions(templates_template_functions);
}