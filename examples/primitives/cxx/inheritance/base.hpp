#ifndef base_hpp
#define base_hpp

#include<string>

namespace cppbind::example {
// [example]
/**
 * __API__
 * action: gen_interface
 * shared_ref: True
 * package: inheritance
 */
class Base {
public:

    virtual ~Base() = default;

    virtual const std::string & value() const = 0;
};
// [example]
}
#endif