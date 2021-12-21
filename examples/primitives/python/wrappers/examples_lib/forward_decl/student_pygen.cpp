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

#include "cxx/forward_decl/student.hpp"
#include "cxx/forward_decl/teacher.hpp"

namespace py = pybind11;

void bindIegenExampleStudent(py::module& m) {
    using namespace iegen::example;
    py::class_<iegen::example::Student, std::shared_ptr<iegen::example::Student>> student(m, "Student");

    student.def(py::init<const std::string &>(), py::arg("st_name"));

    student.def(py::init<const std::vector<Teacher *> &>(), py::arg("teachers"));
    student.def("add_teacher", &iegen::example::Student::addTeacher, py::arg("t"));
    student.def("teachers", &iegen::example::Student::teachers);

    student.def_readwrite("name", &iegen::example::Student::name);
}
