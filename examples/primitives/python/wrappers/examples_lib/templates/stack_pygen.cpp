/**
 *   ______ .______   .______   .______    __  .__   __.  _______  
 *  /      ||   _  \  |   _  \  |   _  \  |  | |  \ |  | |       \ 
 * |  ,----'|  |_)  | |  |_)  | |  |_)  | |  | |   \|  | |  .--.  |
 * |  |     |   ___/  |   ___/  |   _  <  |  | |  . `  | |  |  |  |
 * |  `----.|  |      |  |      |  |_)  | |  | |  |\   | |  '--'  |
 *  \______|| _|      | _|      |______/  |__| |__| \__| |_______/ 
 * 
 * This file is generated by cppbind on 05/12/2022-10:33.
 * Please do not change it manually.
 */

#include <pybind11/pybind11.h>
#include <pybind11/stl.h>
#include <pybind11/functional.h>

#include "cxx/templates/stack.hpp"
#include "cxx/simple/project.hpp"
#include "cxx/templates/container.hpp"
#include "cxx/simple/task.hpp"
#include "cxx/getters/number.hpp"

namespace py = pybind11;

void bindExamplesLibTemplatesStackPygen(py::module& m) {
    {
        using namespace cppbind::example;
        py::class_<cppbind::example::Stack<cppbind::example::Project>, cppbind::example::Container> stackPrj(m, "StackPrj");
        
        stackPrj.def(py::init<>());

        stackPrj.def(py::init<cppbind::example::Project &>(), py::arg("st"));
        stackPrj.def("push", &cppbind::example::Stack<cppbind::example::Project>::push, py::arg("item"));
        stackPrj.def("pop", &cppbind::example::Stack<cppbind::example::Project>::pop);
        stackPrj.def("top", &cppbind::example::Stack<cppbind::example::Project>::top, py::return_value_policy::reference);
        stackPrj.def("empty", &cppbind::example::Stack<cppbind::example::Project>::empty, py::return_value_policy::automatic);
    }
    {
        using namespace cppbind::example;
        py::class_<cppbind::example::Stack<cppbind::example::Task>, cppbind::example::Container> stackPyTask(m, "StackPyTask");
        
        stackPyTask.def(py::init<>());

        stackPyTask.def(py::init<cppbind::example::Task &>(), py::arg("st"));
        stackPyTask.def("push", &cppbind::example::Stack<cppbind::example::Task>::push, py::arg("item"));
        stackPyTask.def("pop", &cppbind::example::Stack<cppbind::example::Task>::pop);
        stackPyTask.def("top", &cppbind::example::Stack<cppbind::example::Task>::top, py::return_value_policy::reference);
        stackPyTask.def("empty", &cppbind::example::Stack<cppbind::example::Task>::empty, py::return_value_policy::automatic);
    }
    {
        using namespace cppbind::example;
        py::class_<cppbind::example::Stack<cppbind::example::Number<int>>, cppbind::example::Container> stackNumInt(m, "StackNumInt");
        
        stackNumInt.def(py::init<>());

        stackNumInt.def(py::init<cppbind::example::Number<int> &>(), py::arg("st"));
        stackNumInt.def("push", &cppbind::example::Stack<cppbind::example::Number<int>>::push, py::arg("item"));
        stackNumInt.def("pop", &cppbind::example::Stack<cppbind::example::Number<int>>::pop);
        stackNumInt.def("top", &cppbind::example::Stack<cppbind::example::Number<int>>::top, py::return_value_policy::reference);
        stackNumInt.def("empty", &cppbind::example::Stack<cppbind::example::Number<int>>::empty, py::return_value_policy::automatic);
    }
} /* bindExamplesLibTemplatesStackPygen */
