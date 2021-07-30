#include <pybind11/pybind11.h>
#include <pybind11/stl.h>
#include <iostream>
#include "cxx/misc/buffer.hpp"

namespace py = pybind11;

PYBIND11_MODULE(buffer, m) {

    py::class_<iegen::example::Size<float>> sizef(m, "SizeF");
    sizef.def(py::init<float, float>());
    sizef.def_readwrite("width", &iegen::example::Size<float>::width);
    sizef.def_readwrite("height", &iegen::example::Size<float>::height);

    py::class_<iegen::example::Buffer<int>> buffer_(m, "Buffer");
    buffer_.def(py::init());
    buffer_.def("print", &iegen::example::Buffer<int>::print);

}
