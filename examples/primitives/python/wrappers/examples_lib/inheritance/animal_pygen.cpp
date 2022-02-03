/**
 * ,--.,------. ,----.   ,------.,--.  ,--. 
 * |  ||  .---''  .-.|   |  .---'|  ,'.|  | 
 * |  ||  `--, |  | .---.|  `--, |  |' '  | 
 * |  ||  `---.'  '--'  ||  `---.|  | `   | 
 * `--'`------' `------' `------'`--'  `--' 
 * 
 * This file is generated by iegen on 02/03/2022-13:11.
 * Please do not change it manually.
 */

#include <pybind11/pybind11.h>
#include <pybind11/stl.h>
#include <pybind11/functional.h>

#include "cxx/inheritance/animal.hpp"

namespace py = pybind11;

void bindIegenExampleAnimal(py::module& m) {
    using namespace iegen::example;
    py::class_<iegen::example::Animal> animal(m, "Animal");

    animal.def(py::init<>());
    animal.def("type_name", &iegen::example::Animal::typeName);
}
void bindIegenExampleTerrestrialAnimal(py::module& m) {
    using namespace iegen::example;
    py::class_<iegen::example::TerrestrialAnimal, iegen::example::Animal> terrestrialAnimal(m, "TerrestrialAnimal");

    terrestrialAnimal.def(py::init<>());
    terrestrialAnimal.def("type_name", &iegen::example::TerrestrialAnimal::typeName);
}
void bindIegenExampleAquaticAnimal(py::module& m) {
    using namespace iegen::example;
    py::class_<iegen::example::AquaticAnimal, iegen::example::Animal> aquaticAnimal(m, "AquaticAnimal");

    aquaticAnimal.def(py::init<>());
    aquaticAnimal.def("type_name", &iegen::example::AquaticAnimal::typeName);
}
void bindIegenExampleFrog(py::module& m) {
    using namespace iegen::example;
    py::class_<iegen::example::Frog, iegen::example::TerrestrialAnimal, iegen::example::AquaticAnimal> frog(m, "Frog");

    frog.def(py::init<>());
    frog.def("type_name", &iegen::example::Frog::typeName);
}
void bindIegenExampleLittleFrog(py::module& m) {
    using namespace iegen::example;
    py::class_<iegen::example::LittleFrog, iegen::example::Frog> littleFrog(m, "LittleFrog");

}
void bindIegenExampleAnimalUsage(py::module& m) {
    using namespace iegen::example;
    py::class_<iegen::example::AnimalUsage> animalUsage(m, "AnimalUsage");

    animalUsage.def(py::init<>());
    animalUsage.def_static("get_animal_type_name", &iegen::example::AnimalUsage::getAnimalTypeName, py::arg("animal"));
    animalUsage.def_static("get_aquatic_animal_type_name", &iegen::example::AnimalUsage::getAquaticAnimalTypeName, py::arg("animal"));
    animalUsage.def("get_animal", &iegen::example::AnimalUsage::getAnimal);
    animalUsage.def("get_aquatic_animal", &iegen::example::AnimalUsage::getAquaticAnimal);
    animalUsage.def("get_frog", &iegen::example::AnimalUsage::getFrog);
}
