/**
 * ,--.,------. ,----.   ,------.,--.  ,--. 
 * |  ||  .---''  .-.|   |  .---'|  ,'.|  | 
 * |  ||  `--, |  | .---.|  `--, |  |' '  | 
 * |  ||  `---.'  '--'  ||  `---.|  | `   | 
 * `--'`------' `------' `------'`--'  `--' 
 * 
 * This file is generated by iegen on 02/08/2022-09:07.
 * Please do not change it manually.
 */

#include <pybind11/pybind11.h>
#include <pybind11/stl.h>
#include <pybind11/functional.h>

#include "cxx/typedefs/queue_int_shared.hpp"

namespace py = pybind11;

void bindExamplesLibTypedefsQueueIntShared(py::module& m) {
    {
        using namespace iegen::example;
        py::class_<iegen::example::QueueIntShared, std::shared_ptr<iegen::example::QueueIntShared>> queueIntShared(m, "QueueIntShared");
        
        queueIntShared.def(py::init<>());
        queueIntShared.def("push_back", &iegen::example::QueueIntShared::push_back, py::arg("element"), py::return_value_policy::automatic);
        queueIntShared.def("get_size", &iegen::example::QueueIntShared::get_size, py::return_value_policy::automatic);
    }
    {
        using namespace iegen::example;
        py::class_<iegen::example::QueueIntSharedUsage> queueIntSharedUsage(m, "QueueIntSharedUsage");
        
        queueIntSharedUsage.def(py::init<iegen::example::SharedPtrOfQueueIntSharedType>(), py::arg("q"));
        queueIntSharedUsage.def_static("get_size", &iegen::example::QueueIntSharedUsage::getSize, py::arg("q"), py::return_value_policy::automatic);
        queueIntSharedUsage.def_static("get_last_element", &iegen::example::QueueIntSharedUsage::getLastElement, py::arg("q"), py::return_value_policy::automatic);
        queueIntSharedUsage.def_static("get_first_element", &iegen::example::QueueIntSharedUsage::getFirstElement, py::arg("q"), py::return_value_policy::automatic);
        queueIntSharedUsage.def_static("get_inv_queue", &iegen::example::QueueIntSharedUsage::getInvQueue, py::arg("v"), py::return_value_policy::automatic);
        queueIntSharedUsage.def("get_saved_queue", &iegen::example::QueueIntSharedUsage::getSavedQueue, py::return_value_policy::automatic);
        queueIntSharedUsage.def_readonly("saved_queue", &iegen::example::QueueIntSharedUsage::saved_queue, py::return_value_policy::reference_internal);
    }
} /* bindExamplesLibTypedefsQueueIntShared */
