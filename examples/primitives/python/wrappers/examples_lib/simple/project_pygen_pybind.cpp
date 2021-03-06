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

#include "cxx/simple/project.hpp"
#include "cxx/simple/task.hpp"

namespace py = pybind11;

void bindExamplesLibSimpleProjectPygen(py::module& m) {
    {
        using namespace cppbind::example;
        py::class_<cppbind::example::Project> project(m, "Project");
        
        project.def(py::init<const std::string &>(), py::arg("title"));

        project.def_property_readonly("title", &cppbind::example::Project::title, py::return_value_policy::reference_internal);
        project.def("add_task", &cppbind::example::Project::addTask, py::arg("task"));
        project.def("tasks", &cppbind::example::Project::tasks, py::return_value_policy::reference);
        project.def("__eq__", &cppbind::example::Project::equals, py::arg("p"), py::return_value_policy::automatic);
        project.def("__repr__", [](const cppbind::example::Project& self) -> std::string {
            int status;
            const char* name = typeid(self).name();
            std::unique_ptr<char[], std::function<void(char*)>> demangledSymbol(
                __cxxabiv1::__cxa_demangle(name, nullptr, nullptr, &status), free);
            const char * classname = "cppbind::example::Project";
            if (status == 0) {
                classname = demangledSymbol.get();
            }
            char res[96];
            snprintf(res, sizeof(res), "<0x%08zx: %s>", reinterpret_cast<std::size_t>(&self), classname);
            return res;
        });  
    }
} /* bindExamplesLibSimpleProjectPygen */
