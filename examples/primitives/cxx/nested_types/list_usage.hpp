#ifndef nested_usage_examples_h
#define nested_usage_examples_h

#include "cxx/nested_types/list.hpp"
#include "cxx/nested_types/template_list.hpp"


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

/**
 * A dummy test example using nested types of templates.
 * \internal
 * TODO remove langauge specific action after fixing the issue for python(https://picsart.atlassian.net/browse/IEGEN-236)
 * __API__
 * kotlin.action: gen_class
 * swift.action: gen_class
 * package: nested_types.usage
 */
struct IntListItemWrapper {

    /**
     * __API__
     * kotlin.action: gen_constructor
     * swift.action: gen_constructor
     * throws: no_throw
     */
    IntListItemWrapper() {}

    /**
     * __API__
     * kotlin.action: gen_method
     * swift.action: gen_method
     * throws: no_throw
     */
    void set(TemplateList<int>::Item* item) {
        _item = item;
    };
    /**
     * __API__
     * kotlin.action: gen_method
     * swift.action: gen_method
     * throws: no_throw
     * return_value_policy: reference
     */
    TemplateList<int>::Item* get() {
        return _item;
    };

private:
    TemplateList<int>::Item* _item;
};

}

#endif /* nested_examples_h */
