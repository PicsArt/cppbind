/**
 * ,--.,------. ,----.   ,------.,--.  ,--. 
 * |  ||  .---''  .-.|   |  .---'|  ,'.|  | 
 * |  ||  `--, |  | .---.|  `--, |  |' '  | 
 * |  ||  `---.'  '--'  ||  `---.|  | `   | 
 * `--'`------' `------' `------'`--'  `--' 
 * 
 * This file is generated by iegen on 07/22/2021-09:04.
 * Please do not change it manually.
 */

#include <pybind11/pybind11.h>
#include <pybind11/stl.h>
#include <pybind11/functional.h>

#include "cxx/optionals/optionals.hpp"
#include "cxx/simple/task.hpp"
#include "cxx/simple/project.hpp"
#include "cxx/getters/person.hpp"
#include "cxx/enums/color.hpp"

namespace py = pybind11;

void bindIegenExampleOptionals(py::module& m) {
    using namespace iegen::example;
    py::class_<iegen::example::Optionals> optionals(m, "Optionals");

    optionals.def(py::init<>());
    optionals.def("optional_ptr_with_nullptr_default", &iegen::example::Optionals::optionalPtrWithNullptrDefault, py::arg("task") = nullptr);
    optionals.def("optional_f_d_ptr_with_nullptr_default", &iegen::example::Optionals::optionalFDPtrWithNullptrDefault, py::arg("project") = nullptr);
    optionals.def("optional_shared_ptr_with_nullptr_default", &iegen::example::Optionals::optionalSharedPtrWithNullptrDefault, py::arg("person") = nullptr);
    optionals.def("optional_int_with_default", &iegen::example::Optionals::optionalIntWithDefault, py::arg("value") = 5);
    optionals.def("optional_long_with_default", &iegen::example::Optionals::optionalLongWithDefault, py::arg("value") = 7);
    optionals.def("optional_double_with_default", &iegen::example::Optionals::optionalDoubleWithDefault, py::arg("value") = 9.0);
    optionals.def("optional_float_with_default", &iegen::example::Optionals::optionalFloatWithDefault, py::arg("value") = 11.0);
    optionals.def("optional_bool_with_default", &iegen::example::Optionals::optionalBoolWithDefault, py::arg("value") = true);
    optionals.def("optional_string_with_default", &iegen::example::Optionals::optionalStringWithDefault, py::arg("optional_str") = "abc");
    optionals.def("optional_char_with_default", &iegen::example::Optionals::optionalCharWithDefault, py::arg("symbol") = ',');
    optionals.def("optional_char_pointer_with_default", &iegen::example::Optionals::optionalCharPointerWithDefault, py::arg("optional_str") = "def");
    optionals.def("optional_enum_with_default", &iegen::example::Optionals::optionalEnumWithDefault, py::arg("c") = iegen::example::Color::Red);
}