#ifndef examples_pygen_hpp
#define examples_pygen_hpp

#include "../wrappers/classes/room_pygen.hpp"
#include "../wrappers/containers/containers_pygen.hpp"
#include "../wrappers/enums/color_pygen.hpp"
#include "../wrappers/getters/getter_pygen.hpp"
#include "../wrappers/operators/counter_pygen.hpp"
#include "../wrappers/overloads/overload_pygen.hpp"
#include <pybind11/pybind11.h>

namespace py = pybind11;
void bindIegenExamples(py::module& m);

#endif