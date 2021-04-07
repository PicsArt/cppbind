#include <pybind11/pybind11.h>
#include <pybind11/stl.h>
#include <pybind11/functional.h>

#include "examples/cxx/classes/room.hpp"

namespace py = pybind11;

void bindRoom(py::module& m) {
    using namespace iegen::example;
    py::class_<iegen::example::Room> room(m, "Room");
room.def("calculate_area", &iegen::example::Room::calculateArea);
    room.def("calculate_volume", &iegen::example::Room::calculateVolume);
}