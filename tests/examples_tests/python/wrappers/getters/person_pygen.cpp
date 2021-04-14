#include <pybind11/pybind11.h>
#include <pybind11/stl.h>
#include <pybind11/functional.h>

#include "examples/cxx/getters/person.hpp"

namespace py = pybind11;

void bindPerson(py::module& m) {
    using namespace iegen::example;
    py::class_<iegen::example::Person, std::shared_ptr<iegen::example::Person>> person(m, "Person");

    person.def(py::init<const std::string &>(), py::arg("name"));


    person.def_property("full_name", &iegen::example::Person::fullName, &iegen::example::Person::setFullName);
}