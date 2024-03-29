/**
 * This is a template class example.
 * For templates user mush explicitly specify all possible types for each template parameter in the API using
 * template attribute.
 */


#ifndef container_hpp
#define container_hpp

#include <vector>
#include <memory>
#include <string>


namespace cppbind::example {
// [example-start]
/**
 * An example interface which descendant types are templates. Used for an example of downcast in target language.
 * __API__
 * action: gen_interface
 * package: templates
 */
class Container {
public:
    virtual ~Container() = default;
};
// [example-end]
/**
 * An example of usage for a type which descendants are template types.
 * Used for an example of downcast in target language.
 * __API__
 * action: gen_class
 * package: templates
 */
class ContainerHolder {
public:
    /**
     * __API__
     * action: gen_constructor
     * throws: no_throw
     */
    ContainerHolder(Container* container) : _container(container) {}

    /**
      * __API__
      * action: gen_getter
      * throws: no_throw
      */
    Container* container() {
        return _container;
    }

private:
    Container* _container;
};

}
#endif

