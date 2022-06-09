/**
 *   ______ .______   .______   .______    __  .__   __.  _______  
 *  /      ||   _  \  |   _  \  |   _  \  |  | |  \ |  | |       \ 
 * |  ,----'|  |_)  | |  |_)  | |  |_)  | |  | |   \|  | |  .--.  |
 * |  |     |   ___/  |   ___/  |   _  <  |  | |  . `  | |  |  |  |
 * |  `----.|  |      |  |      |  |_)  | |  | |  |\   | |  '--'  |
 *  \______|| _|      | _|      |______/  |__| |__| \__| |_______/ 
 * 
 * This file is generated by cppbind on 06/06/2022-05:22.
 * Please do not change it manually.
 */

#include <cxxabi.h>
#include <memory>
#include <pybind11/pybind11.h>
#include <pybind11/stl.h>
#include <pybind11/functional.h>

#include "cxx/functionals/functional_example.hpp"

namespace py = pybind11;

void bindExamplesLibFunctionalsFunctionalExamplePygen(py::module& m) {
    {
        using namespace cppbind::example;
        py::class_<cppbind::example::FunctionalExamples, std::shared_ptr<cppbind::example::FunctionalExamples>> functionalExamples(m, "FunctionalExamples");
        
        functionalExamples.def(py::init<>());
        functionalExamples.def_static("gen_func_to_increment_result", &cppbind::example::FunctionalExamples::genFuncToIncrementResult, py::arg("f"), py::return_value_policy::automatic);
        functionalExamples.def("__repr__", [](const cppbind::example::FunctionalExamples& self) -> std::string {
            int status;
            const char* name = typeid(self).name();
            std::unique_ptr<char[], std::function<void(char*)>> demangledSymbol(
                __cxxabiv1::__cxa_demangle(name, nullptr, nullptr, &status), free);
            const char * classname = "cppbind::example::FunctionalExamples";
            if (status == 0) {
                classname = demangledSymbol.get();
            }
            char res[96];
            snprintf(res, sizeof(res), "<0x%08zx: %s>", reinterpret_cast<std::size_t>(&self), classname);
            return res;
        });  
    }
} /* bindExamplesLibFunctionalsFunctionalExamplePygen */
