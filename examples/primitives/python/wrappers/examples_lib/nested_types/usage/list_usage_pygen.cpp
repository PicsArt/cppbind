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

#include "cxx/nested_types/list_usage.hpp"
#include "cxx/nested_types/list.hpp"

namespace py = pybind11;

void bindExamplesLibNestedTypesUsageListUsagePygen(py::module& m) {
    {
        using namespace cppbind::example;
        py::class_<cppbind::example::ListWrapper> listWrapper(m, "ListWrapper");
        
        listWrapper.def(py::init<>());
        listWrapper.def("push_back", &cppbind::example::ListWrapper::push_back, py::arg("item"));

        listWrapper.def_property_readonly("back", &cppbind::example::ListWrapper::back, py::return_value_policy::reference_internal);
        listWrapper.def("__repr__", [](const cppbind::example::ListWrapper& self) -> std::string {
            int status;
            const char* name = typeid(self).name();
            std::unique_ptr<char[], std::function<void(char*)>> demangledSymbol(
                __cxxabiv1::__cxa_demangle(name, nullptr, nullptr, &status), free);
            const char * classname = "cppbind::example::ListWrapper";
            if (status == 0) {
                classname = demangledSymbol.get();
            }
            char res[96];
            snprintf(res, sizeof(res), "<0x%08zx: %s>", reinterpret_cast<std::size_t>(&self), classname);
            return res;
        });  
    }
} /* bindExamplesLibNestedTypesUsageListUsagePygen */
