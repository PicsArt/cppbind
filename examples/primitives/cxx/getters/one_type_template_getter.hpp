#ifndef one_template_getter_hpp
#define one_template_getter_hpp

namespace iegen::example {
// [example]
/**
 * __API__
 * action: gen_class
 * package: getters
 */
struct SimpleItem  {
    /**
     * __API__
     * action: gen_property_setter
     */
    int value;

    SimpleItem() : value(0){};

};

/**
 * An example class containing template getters that depend on the same type.
 *
 * __API__
 * action: gen_class
 * package: getters
 */
class OneTypeTemplateGetter  {
    public:
    /**
     * Default constructor.
     *
     * __API__
     * action: gen_constructor
     */
    OneTypeTemplateGetter() {};

    /**
     * Template getter example with return type from one template argument.
     * As we don´t specify a name here then type name(SimpleItem) will be used with appropriate naming convention.
     * E.g. for python will be simple_item.
     *
     * __API__
     * action: gen_getter
     * throws: no_throw
     * template:
     *   T:
     *     - type: iegen::example::SimpleItem
     */
    template <typename T>
    T* item() const {
       return new T();
    }

    /**
     * Template getter example with return type from one template argument.
     * Giving a name here is important as we have another template getter that can have the same type.
     * If we won´t specify the name here then both will have the same name retrieved from type name
     * thus this one will override the previous one or the code won´t compile.
     *
     * __API__
     * action: gen_getter
     * throws: no_throw
     * template:
     *   T:
     *     - type: iegen::example::SimpleItem
     *       name: simple_item_with_type
     */
    template <typename T>
    T* itemWithType() const {
       return new T();
    }
};
// [example]
}

#endif
