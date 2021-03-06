/**
 *   ______ .______   .______   .______    __  .__   __.  _______  
 *  /      ||   _  \  |   _  \  |   _  \  |  | |  \ |  | |       \ 
 * |  ,----'|  |_)  | |  |_)  | |  |_)  | |  | |   \|  | |  .--.  |
 * |  |     |   ___/  |   ___/  |   _  <  |  | |  . `  | |  |  |  |
 * |  `----.|  |      |  |      |  |_)  | |  | |  |\   | |  '--'  |
 *  \______|| _|      | _|      |______/  |__| |__| \__| |_______/ 
 * 
 * This file is generated by cppbind on 06/09/2022-13:25.
 * Please do not change it manually.
 */

#include <cxxabi.h>
#include <memory>
#include <pybind11/pybind11.h>
#include <pybind11/stl.h>
#include <pybind11/functional.h>

#include "cxx/nested_types/list.hpp"

namespace py = pybind11;

void bindExamplesLibNestedTypesListPygen(py::module& m) {
    {
        using namespace cppbind::example;
        py::class_<cppbind::example::List> list(m, "List");
        {
            py::class_<cppbind::example::List::Item> item(m, "Item");
            {
                py::class_<cppbind::example::List::Item::Value> value(m, "Value");
                value.def_readwrite("value", &cppbind::example::List::Item::Value::value, py::return_value_policy::reference_internal);

                value.def(py::init<int>(), py::arg("_value"));
                value.def("__repr__", [](const cppbind::example::List::Item::Value& self) -> std::string {
                    int status;
                    const char* name = typeid(self).name();
                    std::unique_ptr<char[], std::function<void(char*)>> demangledSymbol(
                        __cxxabiv1::__cxa_demangle(name, nullptr, nullptr, &status), free);
                    const char * classname = "cppbind::example::List::Item::Value";
                    if (status == 0) {
                        classname = demangledSymbol.get();
                    }
                    char res[96];
                    snprintf(res, sizeof(res), "<0x%08zx: %s>", reinterpret_cast<std::size_t>(&self), classname);
                    return res;
                });  
            }
            item.def_readwrite("value", &cppbind::example::List::Item::value, py::return_value_policy::reference_internal);

            item.def(py::init<cppbind::example::List::Item::Value *>(), py::arg("v"));  
        }

        list.def(py::init<>());
        list.def("push_back", &cppbind::example::List::push_back, py::arg("item"));
        list.def("pop_back", &cppbind::example::List::pop_back);

        list.def_property_readonly("back", &cppbind::example::List::back, py::return_value_policy::reference);  
    }
} /* bindExamplesLibNestedTypesListPygen */
