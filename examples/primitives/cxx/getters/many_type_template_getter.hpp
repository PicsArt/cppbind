#ifndef many_template_getter_hpp
#define many_template_getter_hpp
#include <utility>

namespace iegen::example {
// [example]
/**
 * __API__
 * action: gen_class
 * package: getters
 */
struct Foo  {
    /**
     * __API__
     * action: gen_property_setter
     */
    int value;

    Foo(int v = 0) : value(v) {};

};


/**
 * __API__
 * action: gen_class
 * package: getters
 */
struct Bar  {
    /**
     * __API__
     * action: gen_property_setter
     */
    int value;

    Bar(int v = 0) : value(v) {};

};

/**
 * An example class containing template getters that depend on more than one type.
 *
 * __API__
 * action: gen_class
 * package: getters
 */
class ManyTypeTemplateGetter  {
    public:
    /**
     * Default constructor.
     *
     * __API__
     * action: gen_constructor
     */
    ManyTypeTemplateGetter(int v = 0) : value(v) {};

    /**
     * Template getter example with return type from more than one template argument.
     * As we don´t specify a name here then type names(Foo and Bar) will be used with appropriate naming convention.
     * E.g. for python will be foo_bar.
     *
     * __API__
     * action: gen_getter
     * throws: no_throw
     * template:
     *   T:
     *     - type: iegen::example::Foo
     *   U:
     *     - type: iegen::example::Bar
     */
    template <typename T, typename U>
    std::pair<T*, U*> pair() const {
        T* t = new T(value);
        U* u = new U(value);
        return std::make_pair(t, u);
    }

    /**
     * Template getter example with return type from more than one template argument.
     * Giving a name here is important as we have another template getter that can have the same types.
     * If we won´t specify the name here then both will have the same name retrieved from types names
     * thus this one will override the previous one or the code won´t compile.
     * In this case we can specify name only for the first arguments, as for the second we have one option and this way all cases will be covered.
     *
     * __API__
     * action: gen_getter
     * throws: no_throw
     * template:
     *   T:
     *     - type: iegen::example::Foo
     *       name: foo_bar_pair
     *     - type: iegen::example::Bar
     *       name: bar_bar_pair
     *   U:
     *     - type: iegen::example::Bar
     */
    template <typename T, typename U>
    std::pair<T*, U*> pairWithType() const {
        T* t = new T(value);
        U* u = new U(value);
        return std::make_pair(t, u);
    }

    /**
     * __API__
     * action: gen_property_setter
     */
    int value;
};
// [example]
}

#endif
