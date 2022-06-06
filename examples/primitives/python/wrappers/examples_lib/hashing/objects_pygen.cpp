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

#include "cxx/hashing/objects.hpp"

namespace py = pybind11;

void bindExamplesLibHashingObjectsPygen(py::module& m) {
    {
        using namespace cppbind::example;
        py::class_<cppbind::example::Object1> object1(m, "Object1");
        
        object1.def(py::init<int>(), py::arg("value") = 0);

        object1.def_property_readonly("value", &cppbind::example::Object1::value, py::return_value_policy::reference_internal);
        object1.def("__hash__", &cppbind::example::Object1::hash, py::return_value_policy::automatic);
        object1.def("__eq__", &cppbind::example::Object1::equals, py::arg("other"), py::return_value_policy::automatic);
        object1.def("__str__", &cppbind::example::Object1::toString, py::return_value_policy::automatic);
        object1.def("__repr__", [](const cppbind::example::Object1& self) -> std::string {
            int status;
            const char* name = typeid(self).name();
            std::unique_ptr<char[], std::function<void(char*)>> demangledSymbol(
                __cxxabiv1::__cxa_demangle(name, nullptr, nullptr, &status), free);
            const char * classname = "cppbind::example::Object1";
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
        py::class_<cppbind::example::Object2> object2(m, "Object2");
        
        object2.def(py::init<>());
        object2.def("__repr__", [](const cppbind::example::Object2& self) -> std::string {
            int status;
            const char* name = typeid(self).name();
            std::unique_ptr<char[], std::function<void(char*)>> demangledSymbol(
                __cxxabiv1::__cxa_demangle(name, nullptr, nullptr, &status), free);
            const char * classname = "cppbind::example::Object2";
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
        py::class_<cppbind::example::Object3, std::shared_ptr<cppbind::example::Object3>> object3(m, "Object3");
        
        object3.def(py::init<int>(), py::arg("value") = 0);

        object3.def_property_readonly("value", &cppbind::example::Object3::value, py::return_value_policy::reference_internal);
        object3.def("__hash__", &cppbind::example::Object3::hash, py::return_value_policy::automatic);
        object3.def("__eq__", &cppbind::example::Object3::equals, py::arg("other"), py::return_value_policy::automatic);
        object3.def("__str__", &cppbind::example::Object3::toString, py::return_value_policy::automatic);
        object3.def("__repr__", [](const cppbind::example::Object3& self) -> std::string {
            int status;
            const char* name = typeid(self).name();
            std::unique_ptr<char[], std::function<void(char*)>> demangledSymbol(
                __cxxabiv1::__cxa_demangle(name, nullptr, nullptr, &status), free);
            const char * classname = "cppbind::example::Object3";
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
        py::class_<cppbind::example::Object4, std::shared_ptr<cppbind::example::Object4>> object4(m, "Object4");
        
        object4.def(py::init<>());
        object4.def("__repr__", [](const cppbind::example::Object4& self) -> std::string {
            int status;
            const char* name = typeid(self).name();
            std::unique_ptr<char[], std::function<void(char*)>> demangledSymbol(
                __cxxabiv1::__cxa_demangle(name, nullptr, nullptr, &status), free);
            const char * classname = "cppbind::example::Object4";
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
        py::class_<cppbind::example::ExtendedObject1, cppbind::example::Object1> extendedObject1(m, "ExtendedObject1");
        
        extendedObject1.def(py::init<int>(), py::arg("value") = 0);
        extendedObject1.def("__hash__", &cppbind::example::ExtendedObject1::hash, py::return_value_policy::automatic);  
    }
    {
        using namespace cppbind::example;
        py::class_<cppbind::example::ExtendedObject2, cppbind::example::Object2> extendedObject2(m, "ExtendedObject2");
        
        extendedObject2.def(py::init<>());  
    }
    {
        using namespace cppbind::example;
        py::class_<cppbind::example::ExtendedObject3, std::shared_ptr<cppbind::example::ExtendedObject3>, cppbind::example::Object3> extendedObject3(m, "ExtendedObject3");
        
        extendedObject3.def(py::init<int>(), py::arg("value") = 0);  
    }
    {
        using namespace cppbind::example;
        py::class_<cppbind::example::ExtendedObject4, std::shared_ptr<cppbind::example::ExtendedObject4>, cppbind::example::Object4> extendedObject4(m, "ExtendedObject4");
        
        extendedObject4.def(py::init<>());  
    }
} /* bindExamplesLibHashingObjectsPygen */
