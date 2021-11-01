#ifndef animal_hpp
#define animal_hpp

#include <string>

namespace iegen::example {

class Animal {
public:
    virtual std::string soundType() const = 0;
    virtual ~Animal() = default;
};

/**
 * __API__
 * action: gen_class
 * package: inheritance
 */
class Mammal : public Animal {
public:
    /**
     * __API__
     * action: gen_constructor
     */
    Mammal() {}

    /**
     * __API__
     * action: gen_method
     * throws: no_throw
     */
     std::string soundType() const override {
        return "default mammal sound";
     }
};

/**
 * __API__
 * action: gen_class
 * package: inheritance
 */
class Dog : public Mammal {
public:
    /**
     * __API__
     * action: gen_constructor
     */
    Dog() {}

    /**
     * __API__
     * action: gen_method
     * throws: no_throw
     */
     std::string soundType() const override {
        return "barking";
    }
};

}

#endif
