/**
 * ,--.,------. ,----.   ,------.,--.  ,--. 
 * |  ||  .---''  .-.|   |  .---'|  ,'.|  | 
 * |  ||  `--, |  | .---.|  `--, |  |' '  | 
 * |  ||  `---.'  '--'  ||  `---.|  | `   | 
 * `--'`------' `------' `------'`--'  `--' 
 * 
 * This file is generated by iegen on 10/27/2021-13:03.
 * Please do not change it manually.
 */

#include <pybind11/pybind11.h>
#include <pybind11/stl.h>
#include <pybind11/functional.h>

#include "cxx/shared_ptr/shared_ptr.hpp"

namespace py = pybind11;

void bindExampleCar(py::module& m) {
    using namespace Example;
    py::class_<Example::Car, std::shared_ptr<Example::Car>> car(m, "Car");

    car.def(py::init<int>(), py::arg("cost"));


    car.def_property_readonly("cost", &Example::Car::cost);
    car.def("set_cost_with_car_shared_ptr", &Example::Car::setCostWithCarSharedPtr, py::arg("sp"));
    car.def("set_cost_with_car", &Example::Car::setCostWithCar, py::arg("sp"));
    car.def("set_cost_with_car_ref", &Example::Car::setCostWithCarRef, py::arg("sp"));
    car.def("set_cost_with_car_ptr", &Example::Car::setCostWithCarPtr, py::arg("sp"));
    car.def("get_new_car_shared_ptr", &Example::Car::getNewCarSharedPtr);
}