/**
 *   ______ .______   .______   .______    __  .__   __.  _______  
 *  /      ||   _  \  |   _  \  |   _  \  |  | |  \ |  | |       \ 
 * |  ,----'|  |_)  | |  |_)  | |  |_)  | |  | |   \|  | |  .--.  |
 * |  |     |   ___/  |   ___/  |   _  <  |  | |  . `  | |  |  |  |
 * |  `----.|  |      |  |      |  |_)  | |  | |  |\   | |  '--'  |
 *  \______|| _|      | _|      |______/  |__| |__| \__| |_______/ 
 * 
 * This file is generated by cppbind on 11/22/2022-06:43.
 * Please do not change it manually.
 */

#include <cxxabi.h>
#include <memory>
#include <pybind11/pybind11.h>
#include <pybind11/stl.h>
#include <pybind11/functional.h>

#include "cxx/inheritance/bicycle.hpp"
#include "cxx/inheritance/vehicle.hpp"

namespace py = pybind11;

void bindExamplesLibInheritanceBicyclePygen(py::module& m) {
    {
        using namespace cppbind::example;
        py::class_<cppbind::example::Bicycle, std::shared_ptr<cppbind::example::Bicycle>, cppbind::example::Vehicle> bicycle(m, "Bicycle");
        
        bicycle.def(py::init<int>(), py::arg("number_of_seats"));
        bicycle.def("type", &cppbind::example::Bicycle::type, py::return_value_policy::automatic);  
    }
    {
        using namespace cppbind::example;
        py::class_<cppbind::example::ElectricBicycle, std::shared_ptr<cppbind::example::ElectricBicycle>, cppbind::example::Bicycle> electricBicycle(m, "ElectricBicycle");
        
        electricBicycle.def(py::init<int>(), py::arg("number_of_seats"));
        electricBicycle.def("type", &cppbind::example::ElectricBicycle::bicycleType, py::return_value_policy::automatic);  
    }
    {
        using namespace cppbind::example;
        py::class_<cppbind::example::MountainBicycle, std::shared_ptr<cppbind::example::MountainBicycle>, cppbind::example::Bicycle> mountainBicycle(m, "MountainBicycle");
        
        mountainBicycle.def(py::init<int>(), py::arg("number_of_seats"));
        mountainBicycle.def("type", &cppbind::example::MountainBicycle::type, py::return_value_policy::automatic);  
    }
    {
        using namespace cppbind::example;
        py::class_<cppbind::example::ElectricCityBicycle, std::shared_ptr<cppbind::example::ElectricCityBicycle>, cppbind::example::ElectricBicycle> electricCityBicycle(m, "ElectricCityBicycle");
        
        electricCityBicycle.def(py::init<int>(), py::arg("number_of_seats"));
        electricCityBicycle.def("type", &cppbind::example::ElectricCityBicycle::type, py::return_value_policy::automatic);  
    }
} /* bindExamplesLibInheritanceBicyclePygen */
