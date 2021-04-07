#include <pybind11/pybind11.h>
#include "examples_pygen.hpp"

namespace py = pybind11;
void bindIegenExamples(py::module& m) {
    py::module_ classes = m.def_submodule("classes", "classes");
    py::module_ classes_room = classes.def_submodule("room", "room");
    bindRoom(classes_room);
    py::module_ containers = m.def_submodule("containers", "containers");
    py::module_ containers_containers = containers.def_submodule("containers", "containers");
    bindItem(containers_containers);
    bindContainers(containers_containers);
    py::module_ enums = m.def_submodule("enums", "enums");
    py::module_ enums_color = enums.def_submodule("color", "color");
    bindColor(enums_color);
    py::module_ getters = m.def_submodule("getters", "getters");
    py::module_ getters_getter = getters.def_submodule("getter", "getter");
    bindGetterSetter(getters_getter);
    bindGetterSetterExtended(getters_getter);
    py::module_ operators = m.def_submodule("operators", "operators");
    py::module_ operators_counter = operators.def_submodule("counter", "counter");
    bindCounter(operators_counter);
    py::module_ overloads = m.def_submodule("overloads", "overloads");
    py::module_ overloads_overload = overloads.def_submodule("overload", "overload");
    bindOverload(overloads_overload);
}