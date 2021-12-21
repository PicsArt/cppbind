/**
 * ,--.,------. ,----.   ,------.,--.  ,--. 
 * |  ||  .---''  .-.|   |  .---'|  ,'.|  | 
 * |  ||  `--, |  | .---.|  `--, |  |' '  | 
 * |  ||  `---.'  '--'  ||  `---.|  | `   | 
 * `--'`------' `------' `------'`--'  `--' 
 * 
 * This file is generated by iegen on 12/21/2021-09:31.
 * Please do not change it manually.
 */

#include <pybind11/pybind11.h>
#include <pybind11/stl.h>
#include <pybind11/functional.h>

#include "cxx/templates/pair.hpp"
#include "cxx/overloads/employee.hpp"
#include "cxx/forward_decl/student.hpp"

namespace py = pybind11;

void bindIegenExamplePairEmployee(py::module& m) {
    using namespace iegen::example;
    py::class_<iegen::example::Pair<std::string, std::shared_ptr<iegen::example::Employee>>> pairEmployee(m, "PairEmployee");

    pairEmployee.def(py::init<const std::string &, const std::shared_ptr<iegen::example::Employee> &>(), py::arg("first"), py::arg("second"));


    pairEmployee.def_property_readonly("first", &iegen::example::Pair<std::string, std::shared_ptr<iegen::example::Employee>>::first);


    pairEmployee.def_property_readonly("second", &iegen::example::Pair<std::string, std::shared_ptr<iegen::example::Employee>>::second);
}
void bindIegenExamplePairStudent(py::module& m) {
    using namespace iegen::example;
    py::class_<iegen::example::Pair<std::string, std::shared_ptr<iegen::example::Student>>> pairStudent(m, "PairStudent");

    pairStudent.def(py::init<const std::string &, const std::shared_ptr<iegen::example::Student> &>(), py::arg("first"), py::arg("second"));


    pairStudent.def_property_readonly("first", &iegen::example::Pair<std::string, std::shared_ptr<iegen::example::Student>>::first);


    pairStudent.def_property_readonly("second", &iegen::example::Pair<std::string, std::shared_ptr<iegen::example::Student>>::second);
}
