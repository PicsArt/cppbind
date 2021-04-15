#ifndef examples_pygen_hpp
#define examples_pygen_hpp

#include "python/wrappers/classes/task_pygen.hpp"
#include "python/wrappers/classes/project_pygen.hpp"
#include "python/wrappers/classes/root_pygen.hpp"
#include "python/wrappers/containers/containers_pygen.hpp"
#include "python/wrappers/enums/color_pygen.hpp"
#include "python/wrappers/getters/person_pygen.hpp"
#include "python/wrappers/operators/counter_pygen.hpp"
#include "python/wrappers/overloads/overload_pygen.hpp"
#include "python/wrappers/templates/addressable_pygen.hpp"
#include "python/wrappers/templates/component_pygen.hpp"
#include "python/wrappers/templates/stack_pygen.hpp"
#include "python/wrappers/templates/stack_usage_pygen.hpp"
#include "python/wrappers/templates/template_functions_pygen.hpp"
#include <pybind11/pybind11.h>

namespace py = pybind11;
void bindExamples(py::module& m);

#endif