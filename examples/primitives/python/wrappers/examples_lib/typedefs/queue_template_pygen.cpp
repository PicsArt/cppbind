/**
 * ,--.,------. ,----.   ,------.,--.  ,--. 
 * |  ||  .---''  .-.|   |  .---'|  ,'.|  | 
 * |  ||  `--, |  | .---.|  `--, |  |' '  | 
 * |  ||  `---.'  '--'  ||  `---.|  | `   | 
 * `--'`------' `------' `------'`--'  `--' 
 * 
 * This file is generated by iegen on 01/31/2022-13:30.
 * Please do not change it manually.
 */

#include <pybind11/pybind11.h>
#include <pybind11/stl.h>
#include <pybind11/functional.h>

#include "cxx/typedefs/queue_template.hpp"

namespace py = pybind11;

void bindIegenExampleQueueString(py::module& m) {
    using namespace iegen::example;
    py::class_<iegen::example::Queue<std::string>> queueString(m, "QueueString");

    queueString.def(py::init<>());
    queueString.def("push_back", &iegen::example::Queue<std::string>::push_back, py::arg("element"));
    queueString.def("get_size", &iegen::example::Queue<std::string>::get_size);
}
void bindIegenExampleQueueUsage(py::module& m) {
    using namespace iegen::example;
    py::class_<iegen::example::QueueUsage> queueUsage(m, "QueueUsage");

    queueUsage.def(py::init<iegen::example::QueueStdStringPtrType>(), py::arg("q"));
    queueUsage.def_static("get_size", &iegen::example::QueueUsage::getSize, py::arg("q"));
    queueUsage.def_static("get_last_element", &iegen::example::QueueUsage::getLastElement, py::arg("q"));
    queueUsage.def_static("get_first_element", &iegen::example::QueueUsage::getFirstElement, py::arg("q"));
    queueUsage.def_static("get_rev_queue", &iegen::example::QueueUsage::getRevQueue, py::arg("v"));
    queueUsage.def("get_saved_queue", &iegen::example::QueueUsage::getSavedQueue);

    queueUsage.def_readonly("empty_queue", &iegen::example::QueueUsage::empty_queue);

    queueUsage.def_readonly("saved_queue", &iegen::example::QueueUsage::saved_queue);
}
