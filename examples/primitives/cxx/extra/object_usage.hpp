#ifndef object_usage_hpp
#define object_usage_hpp

#include "object.hpp"

namespace cppbind {

/**
 * comments
 *
 * __API__
 * action: gen_class
 * package: extra
 * shared_ref: True
 */
class ObjectUsage : public Object {
public:
    /**
    * comments
    *
    * __API__
    * action: gen_constructor
    * throws: no_throw
    */
    ObjectUsage() {};
};

}

#endif
