#include <pybind11/pybind11.h>
#include <pybind11/stl.h>
#include <iostream>
#include "cxx/misc/buffer.hpp"

namespace py = pybind11;

PYBIND11_MODULE(buffer, m) {

    py::class_<cppbind::example::Size<float>> sizef(m, "SizeF");
    sizef.def(py::init<float, float>());
    sizef.def_readwrite("width", &cppbind::example::Size<float>::width);
    sizef.def_readwrite("height", &cppbind::example::Size<float>::height);

    py::class_<cppbind::example::Buffer<int>> buffer_(m, "Buffer");
    buffer_.def(py::init());
    buffer_.def("print", &cppbind::example::Buffer<int>::print);

}
