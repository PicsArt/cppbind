#ifndef animal_hpp
#define animal_hpp

#include <string>

namespace cppbind::example {

// Side not-used class to have some classes without API in inheritance hierarchy without
template <class T>
class SideClass {
   T side_prop;
};

// The most base class without API
class Creature {
public:
    virtual std::string typeName() const = 0;
    virtual ~Creature() = default;
};

/**
 * __API__
 * action: gen_interface
 * package: inheritance
 */
class Animal : public SideClass<int>, public Creature {
public:
    /**
     * __API__
     * action: gen_constructor
     * throws: no_throw
     */
    Animal() {}

    /**
     * __API__
     * action: gen_method
     * throws: no_throw
     */
     std::string typeName() const override {
        return "animal";
     }

    /**
     * __API__
     * action: gen_method
     * throws: no_throw
     */
    bool isEqualTo(Animal* a) const {
        return this == a;
    }
};

/**
 * __API__
 * action: gen_interface
 * package: inheritance
 */
class TerrestrialAnimal : public SideClass<double>, public virtual Animal {
public:
    /**
     * __API__
     * action: gen_constructor
     * throws: no_throw
     */
    TerrestrialAnimal() {}

    /**
     * __API__
     * action: gen_method
     * throws: no_throw
     */
     std::string typeName() const override {
        return "terrestrial";
     }
};

/**
 * __API__
 * action: gen_class
 * package: inheritance
 */
class AquaticAnimal : public SideClass<float>, public virtual Animal {
public:
    /**
     * __API__
     * action: gen_constructor
     * throws: no_throw
     */
    AquaticAnimal() {}

    /**
     * __API__
     * action: gen_method
     * throws: no_throw
     */
    std::string typeName() const override {
       return "aquatic";
    }
};

/**
 * __API__
 * action: gen_class
 * package: inheritance
 * descendants: []
 */
class Frog : public SideClass<std::string>, public TerrestrialAnimal, public AquaticAnimal {
public:
    /**
     * __API__
     * action: gen_constructor
     * throws: no_throw
     */
    Frog() {}

    /**
     * __API__
     * action: gen_method
     * throws: no_throw
     */
    std::string typeName() const override {
       return "frog";
    }
};

/**
 * Class to check generated imports for descendants list for kotlin in case of nested types (also for interface types)
 * __API__
 * action: gen_interface
 * swift.action:
 * package: inheritance.mammals
 */
class Mammals {
    public:
    /**
     * __API__
     * action: gen_class
     * swift.action:
     * package: inheritance.mammals
     */
     class Dolphin : public AquaticAnimal {};
};

/**
 *  Class to help checking the empty case of descendants list
 * __API__
 * action: gen_class
 * package: inheritance
 */
class LittleFrog : public Frog {
public:
    /**
     * __API__
     * action: gen_constructor
     * throws: no_throw
     */
    LittleFrog() {}
};

/**
 * __API__
 * action: gen_class
 * package: inheritance
 */
class AnimalUsage {
public:
    /**
     * __API__
     * action: gen_constructor
     * throws: no_throw
     */
    AnimalUsage() {}

   /**
     * __API__
     * action: gen_constructor
     * throws: no_throw
     */
    AnimalUsage(LittleFrog little_frog) : _little_frog(little_frog) {}

    /**
     * __API__
     * action: gen_method
     * throws: no_throw
     */
    static std::string getAnimalTypeName(const Animal& animal) {
        return animal.typeName();
    }

    /**
     * __API__
     * action: gen_method
     * throws: no_throw
     */
    static std::string getAquaticAnimalTypeName(const AquaticAnimal& animal) {
        return animal.typeName();
    }

    /**
     * __API__
     * action: gen_method
     * throws: no_throw
     * python.return_value_policy: reference_internal
     * return_value_policy: reference
     */
    const Animal& getAnimal() {
        return frog;
    }

    /**
     * __API__
     * action: gen_method
     * throws: no_throw
     * python.return_value_policy: reference_internal
     * return_value_policy: reference
     */
    const AquaticAnimal& getAquaticAnimal() {
        return frog;
    }

    /**
     * __API__
     * action: gen_method
     * throws: no_throw
     * python.return_value_policy: reference_internal
     * return_value_policy: reference
     */
    const Frog& getFrog() {
        return frog;
    }

    /**
     * Method to check that any downcast is not done when descendants=[]
     * __API__
     * action: gen_method
     * throws: no_throw
     * return_value_policy: reference
     */
    const Frog& getLittleFrog() {
        return _little_frog;
    }

private:
    Frog frog;
    LittleFrog _little_frog;
};

/**
 * Base class to check object construction method for swift (check 'override' specifier in case of empty descendant list).
 * __API__
 * swift.action: gen_class
 * descendants: []
 * package: inheritance
 */
class Dog {
public:
    /**
     * __API__
     * swift.action: gen_constructor
     * throws: no_throw
     */
    Dog() {}

    virtual ~Dog() = default;
};

/**
 * Derived class to check object construction method for swift (check 'override' specifier in case of empty descendant list).
 * __API__
 * swift.action: gen_class
 * package: inheritance
 */
class BigDog : public Dog {
public:
    /**
     * __API__
     * swift.action: gen_constructor
     * throws: no_throw
     */
    BigDog() {}
};

/**
 * Derived class to check object construction method for swift (check 'override' specifier in case of empty descendant list).
 * This is necessary since the object construction method for BigDog won't be generated without this.
 * __API__
 * swift.action: gen_class
 * package: inheritance
 */
class BlackBigDog : public BigDog {
public:
    /**
     * __API__
     * swift.action: gen_constructor
     * throws: no_throw
     */
    BlackBigDog() {}
};

}

#endif
