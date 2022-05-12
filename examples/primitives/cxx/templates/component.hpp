/**
 * This is an example containing class that has a template specialized base.
 */

#ifndef component_hpp
#define component_hpp

#include <string>
#include "cxx/templates/addressable.hpp"
#include "cxx/simple/root.hpp"

namespace cppbind::example {
// [example]
/**
 * comments
 *
 * __API__
 * action: gen_class
 * shared_ref: True
 * package: templates
 */
class Component : public Addressable<Root> {
public:
    /**
     * comments
     *
     * __API__
     * action: gen_constructor
     * throws: no_throw
     *
     */
    Component(const Root& parent, const std::string& name) : Addressable<Root>(parent, name){}

};
// [example]
}
#endif
