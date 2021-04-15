#include <pybind11/pybind11.h>
#include <pybind11/stl.h>
#include <pybind11/functional.h>

#include "cxx/templates/addressable.hpp"
#include "cxx/classes/root.hpp"

namespace py = pybind11;

void bindAddressableRoot(py::module& m) {
    using namespace iegen::example;
    py::class_<iegen::example::Addressable<iegen::example::Root>, std::shared_ptr<iegen::example::Addressable<iegen::example::Root>>> addressableRoot(m, "AddressableRoot");

    addressableRoot.def(py::init<const iegen::example::Root &, const std::string &>(), py::arg("parent"), py::arg("name"));
    addressableRoot.def("abs_path", &iegen::example::Addressable<iegen::example::Root>::absPath);
}