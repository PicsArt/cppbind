#ifndef component_hpp
#define component_hpp

#include <string>
#include "cxx/templates/addressable.hpp"
#include "cxx/classes/root.hpp"

namespace iegen::example {

/**
 * comments
 *
 * __API__
 * gen: class
 * shared_ref: True
 * package: templates
 * kotlin.include: com.examples.classes.Root
 * python.include: templates.addressable_pygen
 */
class Component : public Addressable<Root> {
public:
    /**
     * comments
     *
     * __API__
     * gen: constructor
     *
     */
    Component(const Root& parent, const std::string& name) : Addressable<Root>(parent, name){}

};

}

#endif
