#ifndef many_template_getter_hpp
#define many_template_getter_hpp
#include <utility>
#include <vector>
#include <string>
#include <algorithm>

namespace cppbind::example {
// [example-start]

/**
 * __API__
 * action: gen_enum
 * package: getters
 */
enum class FruitType {
    Apple = 1,
    Pineapple = 2,
};


/**
 * __API__
 * action: gen_class
 * package: getters
 */
struct Fruit  {

    Fruit() {};

    /**
     * __API__
     * action: gen_getter
     * throws: no_throw
     */
    virtual FruitType type() const = 0;

    virtual ~Fruit() = default;
};


/**
 * __API__
 * action: gen_class
 * package: getters
 */
struct Apple : public Fruit  {

    /**
     * __API__
     * action: gen_constructor
     * throws: no_throw
     */
    Apple() : Fruit() {};

    /**
     * __API__
     * action: gen_getter
     * throws: no_throw
     */
    FruitType type() const override {
        return FruitType::Apple;
    }

    static const FruitType Type = FruitType::Apple;
};

/**
 * __API__
 * action: gen_class
 * package: getters
 */
struct Pineapple : public Fruit  {

    /**
     * __API__
     * action: gen_constructor
     * throws: no_throw
     */
    Pineapple() : Fruit() {};

    /**
     * __API__
     * action: gen_getter
     * throws: no_throw
     */
    FruitType type() const override {
        return FruitType::Pineapple;
    }
    static const FruitType Type = FruitType::Pineapple;

};

/**
 * An example class containing template getters.
 * __API__
 * action: gen_class
 * package: getters
 */
class Fruits  {
    public:
    /**
     * __API__
     * action: gen_constructor
     * throws: no_throw
     */
    Fruits(const std::vector<Fruit*>& fruits) : _fruits(fruits) {};

    /**
     * __API__
     * action: gen_getter
     * throws: no_throw
     * template:
     *   T:
     *     - type: cppbind::example::Apple
     *       name: apples
     *     - type: cppbind::example::Pineapple
     *       name: pineapple
     */
    template <typename T>
    std::vector<T*> fruits() const {
        std::vector<T*> res;
        std::for_each(_fruits.begin(), _fruits.end(), [&res](const auto& f) {
            if (f->type() == T::Type) {
                res.push_back(static_cast<T*>(f));
            }
        });
        return res;
    }

    /**
     * __API__
     * action: gen_getter
     * throws: no_throw
     * template:
     *   T:
     *     - type: cppbind::example::Apple
     *       name: applesWith
     *   U:
     *     - type: cppbind::example::Pineapple
     *       name: Pineapples
     */
    template <typename T, typename U>
    const std::vector<Fruit*> & allFruits() const {
        return _fruits;
    }

    /**
     * __API__
     * action: gen_setter
     * throws: no_throw
     * template:
     *   T:
     *     - type: cppbind::example::Apple
     *   U:
     *     - type: cppbind::example::Pineapple
     */
    template <typename T, typename U>
    void setAllFruits(const std::vector<Fruit*> & fruits) {
        _fruits = fruits;
    }


private:
    std::vector<Fruit*> _fruits;
};
// [example-end]
}

#endif
