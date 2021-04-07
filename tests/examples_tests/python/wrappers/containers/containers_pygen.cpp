#include <pybind11/pybind11.h>
#include <pybind11/stl.h>
#include <pybind11/functional.h>

#include "examples/cxx/containers/containers.hpp"

namespace py = pybind11;

void bindItem(py::module& m) {
    using namespace iegen::example;
    py::class_<iegen::example::Item> item(m, "Item");

    item.def_readwrite("value", &iegen::example::Item::value);

    item.def(py::init<int>(), py::arg("_value"));
}
void bindContainers(py::module& m) {
    using namespace iegen::example;
    py::class_<iegen::example::Containers> containers(m, "Containers");

    containers.def(py::init<>());
    containers.def("add_string_pair", &iegen::example::Containers::addStringPair, py::arg("info"));
    containers.def("add_int_map", &iegen::example::Containers::addIntMap, py::arg("info"));
    containers.def("add_string_map", &iegen::example::Containers::addStringMap, py::arg("info"));
    containers.def("add_int_pair", &iegen::example::Containers::addIntPair, py::arg("info"));
    containers.def("get_string_pair", &iegen::example::Containers::getStringPair);
    containers.def("get_string_map", &iegen::example::Containers::getStringMap);
    containers.def("get_int_map", &iegen::example::Containers::getIntMap);
    containers.def("get_map", &iegen::example::Containers::getMap);
    containers.def("add_int_vector", &iegen::example::Containers::addIntVector, py::arg("v"));
    containers.def("add_string_vector", &iegen::example::Containers::addStringVector, py::arg("v"));
    containers.def("get_string_vector", &iegen::example::Containers::getStringVector);
    containers.def("get_int_vector", &iegen::example::Containers::getIntVector);
}