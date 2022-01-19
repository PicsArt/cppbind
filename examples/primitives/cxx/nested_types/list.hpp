#ifndef nested_examples_h
#define nested_examples_h

#include <list>
#include <string>

namespace iegen::example {

/**
 * __API__
 * action: gen_class
 * package: nested_types
 */
struct List {

    /**
     * __API__
     * action: gen_class
     * package: nested_types
     */
    struct Item {
        /**
         * __API__
         * action: gen_class
         * package: nested_types
         */
        struct Value {
            /**
             * __API__
             * action: gen_property_setter
             */
            int value;

            /**
             * __API__
             * action: gen_constructor
             * throws: no_throw
             */
            Value(int _value) : value(_value){};
        };
        /**
         * __API__
         * action: gen_property_setter
         */
        Value* value;

        /**
         * __API__
         * action: gen_constructor
         * throws: no_throw
         */
        Item(Value* v) : value(v) {};
    };

    /**
     * __API__
     * action: gen_constructor
     * throws: no_throw
     */
    List() {};

    /**
     * __API__
     * action: gen_method
     * throws: no_throw
     */
    void push_back(Item* item) {
        items.push_back(item);
    };

    /**
     * __API__
     * action: gen_method
     * throws: no_throw
     */
    void pop_back() {
        items.pop_back();
    };

    /**
     * __API__
     * action: gen_getter
     * throws: no_throw
     */
    Item* back() {
        return items.back();
    };

private:
    std::list<Item*> items;
};

}

#endif /* nested_examples_h */
