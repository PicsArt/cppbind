#ifndef nested_usage_examples_h
#define nested_usage_examples_h

#include "cxx/nested_types/list.hpp"


namespace iegen::example {
// [example]
/**
 * A dummy test example using nested types.
 * __API__
 * action: gen_class
 * package: nested_types.usage
 */
struct ListWrapper {

    /**
     * __API__
     * action: gen_constructor
     * throws: no_throw
     */
    ListWrapper() {}

    /**
     * __API__
     * action: gen_method
     * throws: no_throw
     */
    void push_back(List::Item* item) {
        items.push_back(item);
    };
    /**
     * __API__
     * action: gen_getter
     * throws: no_throw
     */
    List::Item* back() {
        return items.back();
    };

private:
    List items;
};
// [example]
}

#endif /* nested_examples_h */
