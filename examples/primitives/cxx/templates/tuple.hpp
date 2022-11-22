#ifndef tuple_wrapper_hpp
#define tuple_wrapper_hpp

namespace cppbind::example {
// [example-start]
/**
 * __API__
 * action: gen_class
 * package: templates
 * template_instance:
 *      - args: ''
 *        name: TupleEmpty
 */
template <class... Ts> struct tuple {

    virtual ~tuple() = default;
};

/**
 * __API__
 * action: gen_class
 * package: templates
 * template_instance:
 *      - args: int, int, int
 *        name: TupleThreeInt
 *      - args: int, int
 *        name: TupleTwoInt
 *      - args: int
 *        name: TupleInt
 *      - args: double
 *        name: TupleDouble
 *      - args: double, double
 *        name: TupleDoubles
 *      - args: int, double
 *        name: TupleDoubleInt
 */
template <class T, class... Ts>
struct tuple<T, Ts...>  {
    /**
     * __API__
     * action: gen_constructor
     * throws: no_throw
     */
    tuple(T t, Ts... ts) :  tail(t), rest(ts...) {}

    /**
     * __API__
     * action: gen_property_getter
     */
    T tail;

    /**
     * __API__
     * action: gen_property_getter
     */
    cppbind::example::tuple<Ts...> rest;
    virtual ~tuple() = default;
};

/**
 * An example with variadic template.
 * __API__
 * action: gen_function
 * throws: no_throw
 * package: templates
 * template_instance:
 *   - args: int, int
 *     name: createIntTuple
 *   - args: int, double
 *     name: createIntDoubleTuple
 */
template <typename... Args>
cppbind::example::tuple<Args...>* createTuple(Args... args) {
    return new tuple<Args...>(args...);
}

// [example-end]

// [tuple-usage-examples-start]
/**
 * __API__
 * action: gen_class
 * package: templates
 * file: tuple_usage
 */
struct IntsTuple: public tuple<int, int, int> {

    /**
     * __API__
     * action: gen_constructor
     * throws: no_throw
     */
    IntsTuple(int a, int b, int c): tuple<int, int, int>(a, b, c) {}
};

/**
 * __API__
 * action: gen_class
 * package: templates
 * file: tuple_usage
 * template_instance:
 *      - args: double
 *        name: MyTupleDouble
 *      - args: int
 *        name: MyTupleInt
 */
template <typename T>
struct MyTuple: public cppbind::example::tuple<T, T> {
    /**
     * __API__
     * action: gen_constructor
     * throws: no_throw
     */
    MyTuple(T a, T b): tuple<T, T>(a, b) {}

};

/**
 * __API__
 * action: gen_function
 * throws: no_throw
 * package: templates
 * file: tuple_usage
 * template_instance:
 *      - args: int, double
 *        name: getFirstElementTupleIntDouble
 *      - args: int, int
 *        name: getFirstElementTupleInts
 */
template <typename T, typename... Ts>
T getTupleFirstElement(cppbind::example::tuple<T, Ts...> t) {
    return t.tail;
}

}
// [tuple-usage-examples-end]
#endif
