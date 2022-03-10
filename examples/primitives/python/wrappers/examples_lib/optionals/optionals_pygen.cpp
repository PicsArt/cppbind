/**
 * ,--.,------. ,----.   ,------.,--.  ,--. 
 * |  ||  .---''  .-.|   |  .---'|  ,'.|  | 
 * |  ||  `--, |  | .---.|  `--, |  |' '  | 
 * |  ||  `---.'  '--'  ||  `---.|  | `   | 
 * `--'`------' `------' `------'`--'  `--' 
 * 
 * This file is generated by iegen on 03/01/2022-11:09.
 * Please do not change it manually.
 */

#include <pybind11/pybind11.h>
#include <pybind11/stl.h>
#include <pybind11/functional.h>

#include "cxx/optionals/optionals.hpp"
#include "cxx/simple/task.hpp"
#include "cxx/enums/color.hpp"
#include "cxx/simple/root.hpp"
#include "cxx/simple/project.hpp"
#include "cxx/getters/person.hpp"

namespace py = pybind11;

void bindExamplesLibOptionalsOptionals(py::module& m) {
    {
        using namespace iegen::example;
        py::class_<iegen::example::Optionals> optionals(m, "Optionals");
        optionals.def("optional_ptr_with_nullptr_default", &iegen::example::Optionals::optionalPtrWithNullptrDefault, py::arg("task") = nullptr, py::return_value_policy::reference);
        optionals.def("optional_ptr_with_null_default", &iegen::example::Optionals::optionalPtrWithNullDefault, py::arg("task") = nullptr, py::return_value_policy::reference);
        optionals.def("optional_int_with_default", &iegen::example::Optionals::optionalIntWithDefault, py::arg("value") = 5, py::return_value_policy::automatic);
        optionals.def("optional_long_with_default", &iegen::example::Optionals::optionalLongWithDefault, py::arg("value") = 7, py::return_value_policy::automatic);
        optionals.def("optional_double_with_default", &iegen::example::Optionals::optionalDoubleWithDefault, py::arg("value") = 9.0, py::return_value_policy::automatic);
        optionals.def("optional_float_with_default", &iegen::example::Optionals::optionalFloatWithDefault, py::arg("value") = 11.0, py::return_value_policy::automatic);
        optionals.def("optional_bool_with_default", &iegen::example::Optionals::optionalBoolWithDefault, py::arg("value") = true, py::return_value_policy::automatic);
        optionals.def("optional_string_with_default", &iegen::example::Optionals::optionalStringWithDefault, py::arg("optional_str") = "abc", py::return_value_policy::automatic);
        optionals.def("optional_char_with_default", &iegen::example::Optionals::optionalCharWithDefault, py::arg("symbol") = ',', py::return_value_policy::automatic);
        optionals.def("optional_char_pointer_with_default", &iegen::example::Optionals::optionalCharPointerWithDefault, py::arg("optional_str") = "def", py::return_value_policy::automatic);
        optionals.def("optional_enum_with_default", &iegen::example::Optionals::optionalEnumWithDefault, py::arg("c") = Color::Red, py::return_value_policy::automatic);
        optionals.def("single_complex_default_value", &iegen::example::Optionals::singleComplexDefaultValue, py::arg("task") = Task("MyTask"), py::return_value_policy::automatic);
        optionals.def("multiple_mixed_default_values", &iegen::example::Optionals::multipleMixedDefaultValues, py::arg("task") = Task("DefaultTask"), py::arg("i") = 1, py::arg("r") = Root("DefaultRoot"), py::return_value_policy::automatic);

        optionals.def(py::init<iegen::example::Task, int, iegen::example::Root>(), py::arg("task") = Task("DefaultTask"), py::arg("i") = 1, py::arg("r") = Root("DefaultRoot"));
        optionals.def("optional_enum_with_default_and_field_prefix", &iegen::example::Optionals::optionalEnumWithDefaultAndFieldPrefix, py::arg("c") = ColorShade::Light, py::return_value_policy::automatic);
        optionals.def("optional_enum_with_internal_default", &iegen::example::Optionals::optionalEnumWithInternalDefault, py::arg("c"), py::return_value_policy::automatic);
        optionals.def("optional_string_view_with_default", &iegen::example::Optionals::optionalStringViewWithDefault, py::arg("optional_str") = "abc", py::return_value_policy::automatic);
        optionals.def("optional_f_d_ptr_with_nullptr_default", &iegen::example::Optionals::optionalFDPtrWithNullptrDefault, py::arg("project") = nullptr, py::return_value_policy::reference);
        optionals.def("optional_shared_ptr_with_nullptr_default", &iegen::example::Optionals::optionalSharedPtrWithNullptrDefault, py::arg("person") = nullptr, py::return_value_policy::automatic);
    }
} /* bindExamplesLibOptionalsOptionals */
