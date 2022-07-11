/**
 *   ______ .______   .______   .______    __  .__   __.  _______  
 *  /      ||   _  \  |   _  \  |   _  \  |  | |  \ |  | |       \ 
 * |  ,----'|  |_)  | |  |_)  | |  |_)  | |  | |   \|  | |  .--.  |
 * |  |     |   ___/  |   ___/  |   _  <  |  | |  . `  | |  |  |  |
 * |  `----.|  |      |  |      |  |_)  | |  | |  |\   | |  '--'  |
 *  \______|| _|      | _|      |______/  |__| |__| \__| |_______/ 
 * 
 * This file is generated by cppbind on 06/20/2022-07:24.
 * Please do not change it manually.
 */

#include <cxxabi.h>
#include <memory>
#include <pybind11/pybind11.h>
#include <pybind11/stl.h>
#include <pybind11/functional.h>

#include "cxx/templates/stack_usage.hpp"
#include "cxx/templates/stack.hpp"
#include "cxx/simple/project.hpp"

namespace py = pybind11;

void bindExamplesLibTemplatesStackUsagePygen(py::module& m) {
    {
        using namespace cppbind::example;
        py::class_<cppbind::example::StackUsage> stackUsage(m, "StackUsage");
        
        stackUsage.def(py::init<>());
        stackUsage.def("first_item_of_specialized_stack", &cppbind::example::StackUsage::firstItemOfSpecializedStack, py::arg("p"), py::return_value_policy::reference);
        stackUsage.def("first_item_of_typedef_of_specialized_stack", &cppbind::example::StackUsage::firstItemOfTypedefOfSpecializedStack, py::arg("p"), py::return_value_policy::reference);
        stackUsage.def("first_item_of_template_stack", &cppbind::example::StackUsage::firstItemOfTemplateStack<cppbind::example::Project>, py::arg("p"), py::return_value_policy::reference);
        stackUsage.def("first_item_of_specialized_stack_with_typedef_arg", &cppbind::example::StackUsage::firstItemOfSpecializedStackWithTypedefArg, py::arg("p"), py::return_value_policy::reference);
        stackUsage.def("__repr__", [](const cppbind::example::StackUsage& self) -> std::string {
            int status;
            const char* name = typeid(self).name();
            std::unique_ptr<char[], std::function<void(char*)>> demangledSymbol(
                __cxxabiv1::__cxa_demangle(name, nullptr, nullptr, &status), free);
            const char * classname = "cppbind::example::StackUsage";
            if (status == 0) {
                classname = demangledSymbol.get();
            }
            char res[96];
            snprintf(res, sizeof(res), "<0x%08zx: %s>", reinterpret_cast<std::size_t>(&self), classname);
            return res;
        });  
    }
} /* bindExamplesLibTemplatesStackUsagePygen */
