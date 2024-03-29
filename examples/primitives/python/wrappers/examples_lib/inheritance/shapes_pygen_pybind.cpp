/**
 *   ______ .______   .______   .______    __  .__   __.  _______  
 *  /      ||   _  \  |   _  \  |   _  \  |  | |  \ |  | |       \ 
 * |  ,----'|  |_)  | |  |_)  | |  |_)  | |  | |   \|  | |  .--.  |
 * |  |     |   ___/  |   ___/  |   _  <  |  | |  . `  | |  |  |  |
 * |  `----.|  |      |  |      |  |_)  | |  | |  |\   | |  '--'  |
 *  \______|| _|      | _|      |______/  |__| |__| \__| |_______/ 
 * 
 * This file is generated by cppbind on 10/07/2022-06:25.
 * Please do not change it manually.
 */

#include <cxxabi.h>
#include <memory>
#include <pybind11/pybind11.h>
#include <pybind11/stl.h>
#include <pybind11/functional.h>

#include "cxx/inheritance/shapes.hpp"

namespace py = pybind11;

void bindExamplesLibInheritanceShapesPygen(py::module& m) {
    {
        using namespace cppbind::example;
        py::class_<cppbind::example::Shape, std::shared_ptr<cppbind::example::Shape>> shape(m, "Shape");
        shape.def("area", &cppbind::example::Shape::area, py::return_value_policy::automatic);
        shape.def("this_object", &cppbind::example::Shape::thisObject, py::return_value_policy::automatic);
        shape.def("__repr__", [](const cppbind::example::Shape& self) -> std::string {
            int status;
            const char* name = typeid(self).name();
            std::unique_ptr<char[], std::function<void(char*)>> demangledSymbol(
                __cxxabiv1::__cxa_demangle(name, nullptr, nullptr, &status), free);
            const char * classname = "cppbind::example::Shape";
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
        py::class_<cppbind::example::Circle, std::shared_ptr<cppbind::example::Circle>, cppbind::example::Shape> circle(m, "Circle");
        circle.def_static("create", &cppbind::example::Circle::create, py::arg("r"), py::return_value_policy::automatic);
        circle.def("area", &cppbind::example::Circle::area, py::return_value_policy::automatic);
        circle.def("increment_radius", &cppbind::example::Circle::incrementRadius, py::arg("value") = 1.0, py::return_value_policy::automatic);  
    }
    {
        using namespace cppbind::example;
        py::class_<cppbind::example::RegularTriangle, std::shared_ptr<cppbind::example::RegularTriangle>> regularTriangle(m, "RegularTriangle");
        
        regularTriangle.def(py::init<double>(), py::arg("side"));
        regularTriangle.def("area", &cppbind::example::RegularTriangle::area, py::return_value_policy::automatic);
        regularTriangle.def("increment_side", &cppbind::example::RegularTriangle::incrementSide, py::arg("value") = 1.0, py::return_value_policy::automatic);
        regularTriangle.def("multiply_side", &cppbind::example::RegularTriangle::multiplySide, py::arg("value") = 1.0, py::return_value_policy::automatic);
        regularTriangle.def("__repr__", [](const cppbind::example::RegularTriangle& self) -> std::string {
            int status;
            const char* name = typeid(self).name();
            std::unique_ptr<char[], std::function<void(char*)>> demangledSymbol(
                __cxxabiv1::__cxa_demangle(name, nullptr, nullptr, &status), free);
            const char * classname = "cppbind::example::RegularTriangle";
            if (status == 0) {
                classname = demangledSymbol.get();
            }
            char res[96];
            snprintf(res, sizeof(res), "<0x%08zx: %s>", reinterpret_cast<std::size_t>(&self), classname);
            return res;
        });  
    }
} /* bindExamplesLibInheritanceShapesPygen */
