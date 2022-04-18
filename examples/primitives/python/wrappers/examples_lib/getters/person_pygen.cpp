/**
 * ,--.,------. ,----.   ,------.,--.  ,--. 
 * |  ||  .---''  .-.|   |  .---'|  ,'.|  | 
 * |  ||  `--, |  | .---.|  `--, |  |' '  | 
 * |  ||  `---.'  '--'  ||  `---.|  | `   | 
 * `--'`------' `------' `------'`--'  `--' 
 * 
 * This file is generated by iegen on 04/12/2022-06:07.
 * Please do not change it manually.
 */

#include <pybind11/pybind11.h>
#include <pybind11/stl.h>
#include <pybind11/functional.h>

#include "cxx/getters/person.hpp"

namespace py = pybind11;

void bindExamplesLibGettersPersonPygen(py::module& m) {
    {
        using namespace iegen::example;
        py::class_<iegen::example::Person, std::shared_ptr<iegen::example::Person>> person(m, "Person");
        
        person.def(py::init<const std::string &, const std::string &, int>(), py::arg("name"), py::arg("email"), py::arg("age"));

        person.def_property("name", py::cpp_function(&iegen::example::Person::fullName, py::return_value_policy::reference_internal), &iegen::example::Person::setFullName);
        person.def_readonly("email", &iegen::example::Person::_email, py::return_value_policy::reference_internal);
        person.def_readwrite("age", &iegen::example::Person::_age, py::return_value_policy::reference_internal);
    }
} /* bindExamplesLibGettersPersonPygen */
