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

#include "cxx/nullables/nullable_utils.hpp"

namespace py = pybind11;

void bindExamplesLibNullablesNullableUtilsPygen(py::module& m) {
    {
        using namespace iegen::example::nullable;
        py::class_<iegen::example::nullable::NumberInt, std::shared_ptr<iegen::example::nullable::NumberInt>> numberInt(m, "NumberInt");
        
        numberInt.def(py::init<int>(), py::arg("val_"));
        numberInt.def_readonly("value", &iegen::example::nullable::NumberInt::value, py::return_value_policy::reference_internal);
    }
    {
        using namespace iegen::example::nullable;
        py::class_<iegen::example::nullable::NumberDouble> numberDouble(m, "NumberDouble");
        
        numberDouble.def(py::init<double>(), py::arg("val_"));
        numberDouble.def_readonly("value", &iegen::example::nullable::NumberDouble::value, py::return_value_policy::reference_internal);
    }
    {
        using namespace iegen::example::nullable;
        py::class_<iegen::example::nullable::Utils, std::shared_ptr<iegen::example::nullable::Utils>> utils(m, "Utils");
        
        utils.def(py::init<iegen::example::nullable::NumberDouble *>(), py::arg("num"));
        utils.def_static("max", py::overload_cast<iegen::example::nullable::NumberDouble *, iegen::example::nullable::NumberDouble *>(&iegen::example::nullable::Utils::max), py::arg("first"), py::arg("second"), py::return_value_policy::reference);
        utils.def_static("max", py::overload_cast<std::shared_ptr<NumberInt>, std::shared_ptr<NumberInt>>(&iegen::example::nullable::Utils::max), py::arg("first"), py::arg("second"), py::return_value_policy::automatic);
        utils.def_static("check_nonnull_arg", &iegen::example::nullable::Utils::checkNonnullArg, py::arg("number"));
        utils.def_static("check_nonnull_return", &iegen::example::nullable::Utils::checkNonnullReturn, py::return_value_policy::reference);

        utils.def_property("nullable", py::cpp_function(&iegen::example::nullable::Utils::nullable, py::return_value_policy::reference), &iegen::example::nullable::Utils::setNullable);

        utils.def_property("non_null", py::cpp_function(&iegen::example::nullable::Utils::nonNull, py::return_value_policy::reference), &iegen::example::nullable::Utils::setNonNull);
        utils.def_readwrite("num_double", &iegen::example::nullable::Utils::numDouble, py::return_value_policy::reference);
        utils.def_readwrite("num_int", &iegen::example::nullable::Utils::numInt, py::return_value_policy::reference_internal);
    }
} /* bindExamplesLibNullablesNullableUtilsPygen */
