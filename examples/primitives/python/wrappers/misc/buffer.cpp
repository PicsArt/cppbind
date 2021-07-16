#include <pybind11/pybind11.h>
#include <pybind11/stl.h>
#include <iostream>
#include "cxx/misc/buffer.hpp"

namespace py = pybind11;

PYBIND11_MODULE(buffer, m) {

    py::class_<iegen::example::Size<double>> sizef(m, "SizeF");
    sizef.def(py::init<double, double>());
    sizef.def_readwrite("width", &iegen::example::Size<double>::width);
    sizef.def_readwrite("height", &iegen::example::Size<double>::height);

    py::class_<iegen::example::Buffer<int>> buffer_(m, "Buffer");
    buffer_.def(py::init());
    buffer_.def("print", &iegen::example::Buffer<int>::print);

}
