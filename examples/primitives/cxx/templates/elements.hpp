
namespace cppbind::example {
// [example-start]
/**
 * __API__
 * action: gen_class
 * package: templates
 * include_cxx:
 *  - <vector>
 * template_instance:
 *     - args: std::vector<int>, int, int
 *       name: ElementsInt
 *     - args: std::vector<std::string>, std::string, std::string, std::string
 *       name: ElementsString
 *     - args: std::vector<double>
 *       name: ElementsEmpty
 */
template <class T, class... Ts>
struct elements {
    /**
     * __API__
     * action: gen_method
     * throws: no_throw
     */
    static cppbind::example::elements<T, Ts...>* create(Ts... ts) {
        auto self = new elements(ts...);
        return self;
    }

    /**
     * __API__
     * action: gen_getter
     * throws: no_throw
     */
    const T& holder() {
        return *_holder;
    }

private:
    elements(Ts... ts): _holder(new T({ts...})) {}
    T* _holder;
};
// [example-end]
}

