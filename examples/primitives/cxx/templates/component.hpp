/**
 * This is an example containing class that has a template specialized base.
 */

#ifndef component_hpp
#define component_hpp

#include <string>
#include "cxx/templates/addressable.hpp"
#include "cxx/simple/root.hpp"

namespace iegen::example {
// [example]
/**
 * comments
 *
 * __API__
 * action: gen_class
 * shared_ref: True
 * package: templates
 * kotlin.include: com.examples.simple.Root
 * python.include: templates.addressable_pygen
 * swift.include: CWrapper
 */
class Component : public Addressable<Root> {
public:
    /**
     * comments
     *
     * __API__
     * action: gen_constructor
     *
     */
    Component(const Root& parent, const std::string& name) : Addressable<Root>(parent, name){}

};
// [example]
}
#endif
