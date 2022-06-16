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

#include "cxx/misc/size_buffer.hpp"

namespace py = pybind11;

void bindExamplesLibMiscSizeBufferPygen(py::module& m) {
    {
        using namespace cppbind::example;
        py::class_<cppbind::example::SizeUsage> sizeUsage(m, "SizeUsage");
        sizeUsage.def_static("multiply_by", &cppbind::example::SizeUsage::multiplyBy, py::arg("size"), py::arg("n"), py::return_value_policy::automatic);
        sizeUsage.def_static("double_size_f", &cppbind::example::SizeUsage::doubleSizeF, py::arg("resolution") = SizeF(NAN,NAN), py::return_value_policy::automatic);
        sizeUsage.def("__repr__", [](const cppbind::example::SizeUsage& self) -> std::string {
            int status;
            const char* name = typeid(self).name();
            std::unique_ptr<char[], std::function<void(char*)>> demangledSymbol(
                __cxxabiv1::__cxa_demangle(name, nullptr, nullptr, &status), free);
            const char * classname = "cppbind::example::SizeUsage";
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
        py::class_<cppbind::example::BufferUsage> bufferUsage(m, "BufferUsage");
        
        bufferUsage.def(py::init<>());
        bufferUsage.def("usage1", &cppbind::example::BufferUsage::usage1, py::arg("b"), py::return_value_policy::automatic);
        bufferUsage.def("usage2", &cppbind::example::BufferUsage::usage2, py::return_value_policy::automatic);
        bufferUsage.def("__repr__", [](const cppbind::example::BufferUsage& self) -> std::string {
            int status;
            const char* name = typeid(self).name();
            std::unique_ptr<char[], std::function<void(char*)>> demangledSymbol(
                __cxxabiv1::__cxa_demangle(name, nullptr, nullptr, &status), free);
            const char * classname = "cppbind::example::BufferUsage";
            if (status == 0) {
                classname = demangledSymbol.get();
            }
            char res[96];
            snprintf(res, sizeof(res), "<0x%08zx: %s>", reinterpret_cast<std::size_t>(&self), classname);
            return res;
        });  
    }
} /* bindExamplesLibMiscSizeBufferPygen */