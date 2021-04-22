#include <pybind11/pybind11.h>
#include <pybind11/stl.h>
#include <pybind11/functional.h>

#include "cxx/base/object.hpp"

namespace py = pybind11;

void bindObject(py::module& m) {
    using namespace iegen;
    py::class_<iegen::Object, std::shared_ptr<iegen::Object>> object(m, "Object");
object.def("to_string", &iegen::Object::toString);
    object.def("class_name", &iegen::Object::className);
    object.def("equals", py::overload_cast<std::shared_ptr<Object>>(&iegen::Object::equals, py::const_), py::arg("other"));
    object.def("hash", &iegen::Object::hash);
    object.def("debug_info", &iegen::Object::debugInfo);
    object.def("bytes_count", &iegen::Object::bytesCount);
}