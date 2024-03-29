/**
 *   ______ .______   .______   .______    __  .__   __.  _______  
 *  /      ||   _  \  |   _  \  |   _  \  |  | |  \ |  | |       \ 
 * |  ,----'|  |_)  | |  |_)  | |  |_)  | |  | |   \|  | |  .--.  |
 * |  |     |   ___/  |   ___/  |   _  <  |  | |  . `  | |  |  |  |
 * |  `----.|  |      |  |      |  |_)  | |  | |  |\   | |  '--'  |
 *  \______|| _|      | _|      |______/  |__| |__| \__| |_______/ 
 * 
 * This file is generated by cppbind on 08/22/2022-08:59.
 * Please do not change it manually.
 */

#include <cxxabi.h>
#include <memory>
#include <pybind11/pybind11.h>
#include <pybind11/stl.h>
#include <pybind11/functional.h>

#include "cxx/misc/yaml_example.hpp"

namespace py = pybind11;

void bindExamplesLibMiscYamlExamplePygen(py::module& m) {
    {
        using namespace cppbind::example;
        py::class_<cppbind::example::WithExternalAPIComments> withExternalAPIComments(m, "WithExternalAPIComments");
        
        withExternalAPIComments.def(py::init<std::string>(), py::arg("s"));
        withExternalAPIComments.def_static("ret_int", &cppbind::example::WithExternalAPIComments::retInt, py::arg("n"), py::return_value_policy::automatic);

        withExternalAPIComments.def_property("str", py::cpp_function(&cppbind::example::WithExternalAPIComments::str, py::return_value_policy::reference_internal), &cppbind::example::WithExternalAPIComments::setStr);
        withExternalAPIComments.def_static("max", &cppbind::example::WithExternalAPIComments::max<int>, py::arg("a"), py::arg("b"), py::return_value_policy::automatic);
        withExternalAPIComments.def_static("max", &cppbind::example::WithExternalAPIComments::max<std::string>, py::arg("a"), py::arg("b"), py::return_value_policy::automatic);
        withExternalAPIComments.def("__repr__", [](const cppbind::example::WithExternalAPIComments& self) -> std::string {
            int status;
            const char* name = typeid(self).name();
            std::unique_ptr<char[], std::function<void(char*)>> demangledSymbol(
                __cxxabiv1::__cxa_demangle(name, nullptr, nullptr, &status), free);
            const char * classname = "cppbind::example::WithExternalAPIComments";
            if (status == 0) {
                classname = demangledSymbol.get();
            }
            char res[96];
            snprintf(res, sizeof(res), "<0x%08zx: %s>", reinterpret_cast<std::size_t>(&self), classname);
            return res;
        });  
    }
    {
        using namespace cppbind::example;
        py::class_<cppbind::example::Adder<int>> adderInt(m, "AdderInt");
        adderInt.def_static("add", &cppbind::example::Adder<int>::add, py::arg("a"), py::arg("b"), py::return_value_policy::automatic);
        adderInt.def("__repr__", [](const cppbind::example::Adder<int>& self) -> std::string {
            int status;
            const char* name = typeid(self).name();
            std::unique_ptr<char[], std::function<void(char*)>> demangledSymbol(
                __cxxabiv1::__cxa_demangle(name, nullptr, nullptr, &status), free);
            const char * classname = "cppbind::example::Adder<int>";
            if (status == 0) {
                classname = demangledSymbol.get();
            }
            char res[96];
            snprintf(res, sizeof(res), "<0x%08zx: %s>", reinterpret_cast<std::size_t>(&self), classname);
            return res;
        });  
    }
    {
        using namespace cppbind::example;
        py::class_<cppbind::example::Adder<double>> adderDouble(m, "AdderDouble");
        adderDouble.def_static("add", &cppbind::example::Adder<double>::add, py::arg("a"), py::arg("b"), py::return_value_policy::automatic);
        adderDouble.def("__repr__", [](const cppbind::example::Adder<double>& self) -> std::string {
            int status;
            const char* name = typeid(self).name();
            std::unique_ptr<char[], std::function<void(char*)>> demangledSymbol(
                __cxxabiv1::__cxa_demangle(name, nullptr, nullptr, &status), free);
            const char * classname = "cppbind::example::Adder<double>";
            if (status == 0) {
                classname = demangledSymbol.get();
            }
            char res[96];
            snprintf(res, sizeof(res), "<0x%08zx: %s>", reinterpret_cast<std::size_t>(&self), classname);
            return res;
        });  
    }
    {
        using namespace cppbind::example;
        py::enum_<cppbind::example::color>(m, "color")
            .value("RED", cppbind::example::color::RED)
            .value("GREEN", cppbind::example::color::GREEN)
            .value("BLUE", cppbind::example::color::BLUE);
    }
} /* bindExamplesLibMiscYamlExamplePygen */
