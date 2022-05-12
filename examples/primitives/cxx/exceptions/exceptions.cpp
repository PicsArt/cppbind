#include "cxx/exceptions/exceptions.hpp"

void cppbind::exceptions::throwExc(bool do_throw) {
    if (do_throw) throw std::invalid_argument("inv_arg");
}
