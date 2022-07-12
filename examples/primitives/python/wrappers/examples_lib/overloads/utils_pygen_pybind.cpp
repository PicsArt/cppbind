/**
 *   ______ .______   .______   .______    __  .__   __.  _______  
 *  /      ||   _  \  |   _  \  |   _  \  |  | |  \ |  | |       \ 
 * |  ,----'|  |_)  | |  |_)  | |  |_)  | |  | |   \|  | |  .--.  |
 * |  |     |   ___/  |   ___/  |   _  <  |  | |  . `  | |  |  |  |
 * |  `----.|  |      |  |      |  |_)  | |  | |  |\   | |  '--'  |
 *  \______|| _|      | _|      |______/  |__| |__| \__| |_______/ 
 * 
 * This file is generated by cppbind on 07/06/2022-11:52.
 * Please do not change it manually.
 */

#include <cxxabi.h>
#include <memory>
#include <pybind11/pybind11.h>
#include <pybind11/stl.h>
#include <pybind11/functional.h>

#include "cxx/overloads/utils.hpp"

namespace py = pybind11;

void bindExamplesLibOverloadsUtilsPygen(py::module& m) {
    {
        using namespace cppbind::example;
        py::class_<cppbind::example::Utils, std::shared_ptr<cppbind::example::Utils>> utils(m, "Utils");
        
        utils.def(py::init<>());
        utils.def_static("sum", py::overload_cast<int, int>(&cppbind::example::Utils::sum), py::arg("first"), py::arg("second"), py::return_value_policy::automatic);
        utils.def_static("sum", py::overload_cast<float, float>(&cppbind::example::Utils::sum), py::arg("first"), py::arg("second"), py::return_value_policy::automatic);
        utils.def("concatenate", py::overload_cast<std::string, std::string>(&cppbind::example::Utils::concatenate), py::arg("first"), py::arg("second"), py::return_value_policy::automatic);
        utils.def("concatenate", py::overload_cast<std::string, std::string, std::string>(&cppbind::example::Utils::concatenate), py::arg("first"), py::arg("second"), py::arg("third"), py::return_value_policy::automatic);
        utils.def_static("minus", py::overload_cast<int, int>(&cppbind::example::Utils::sub), py::arg("first"), py::arg("second"), py::return_value_policy::automatic);
        utils.def_static("minus", py::overload_cast<float, float>(&cppbind::example::Utils::sub), py::arg("first"), py::arg("second"), py::return_value_policy::automatic);
        utils.def("sum_lists", py::overload_cast<cppbind::example::Utils::ArrayInt, cppbind::example::Utils::ArrayInt>(&cppbind::example::Utils::sum), py::arg("first"), py::arg("second"), py::return_value_policy::automatic);
        utils.def("sum_lists", py::overload_cast<std::array<float, 4>, std::array<float, 4>>(&cppbind::example::Utils::sum), py::arg("first"), py::arg("second"), py::return_value_policy::automatic);
        utils.def("__repr__", [](const cppbind::example::Utils& self) -> std::string {
            int status;
            const char* name = typeid(self).name();
            std::unique_ptr<char[], std::function<void(char*)>> demangledSymbol(
                __cxxabiv1::__cxa_demangle(name, nullptr, nullptr, &status), free);
            const char * classname = "cppbind::example::Utils";
            if (status == 0) {
                classname = demangledSymbol.get();
            }
            char res[96];
            snprintf(res, sizeof(res), "<0x%08zx: %s>", reinterpret_cast<std::size_t>(&self), classname);
            return res;
        });  
    }
} /* bindExamplesLibOverloadsUtilsPygen */
