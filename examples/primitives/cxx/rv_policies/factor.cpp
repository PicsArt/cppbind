#include "cxx/rv_policies/factory.hpp"

namespace iegen::example {


Factory* Factory::create() {
    return new Factory();
}

Factory::Factory() {}

}
