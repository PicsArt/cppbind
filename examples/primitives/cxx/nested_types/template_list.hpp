#ifndef template_list_example_h
#define template_list_example_h

#include <list>
#include <string>

namespace iegen::example {
// [example]
/**
 * An example with template nested types.
 * \internal
 * TODO remove langauge specific action after fixing the issue for python(https://picsart.atlassian.net/browse/IEGEN-236)
 * __API__
 * kotlin.action: gen_class
 * swift.action: gen_class
 * package: nested_types
 * template:
 *   T:
 *     - type: int
 *       name: Int
 *     - type: double
 */
template<typename T>
struct TemplateList {

    /**
     * __API__
     * kotlin.action: gen_class
     * swift.action: gen_class
     * package: nested_types
     */
    struct Item {

        /**
         * __API__
         * swift.action: gen_property_setter
         * kotlin.action: gen_property_setter
         */
        T value;

        /**
         * __API__
         * swift.action: gen_constructor
         * kotlin.action: gen_constructor
         * throws: no_throw
         */
        Item(T v) : value(v) {};
    };

    /**
     * __API__
     * swift.action: gen_constructor
     * kotlin.action: gen_constructor
     * throws: no_throw
     */
    TemplateList() {};

//    /**
//     * __API__
//     * action: gen_method
//     * throws: no_throw
//     */
//    void push_back(Item* item) {
//        items.push_back(item);
//    };
//
//    /**
//     * __API__
//     * action: gen_method
//     * throws: no_throw
//     */
//    void pop_back() {
//        items.pop_back();
//    };
//
//    /**
//     * __API__
//     * action: gen_getter
//     * throws: no_throw
//     * return_value_policy: reference
//     */
//    Item* back() {
//        return items.back();
//    };

private:
    std::list<Item*> items;
};
// [example]
}



#endif /* nested_examples_h */
