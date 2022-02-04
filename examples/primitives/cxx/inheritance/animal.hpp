#ifndef animal_hpp
#define animal_hpp

#include <string>

namespace iegen::example {

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
     */
    const Animal& getAnimal() {
        return frog;
    }

    /**
     * __API__
     * action: gen_method
     * throws: no_throw
     */
    const AquaticAnimal& getAquaticAnimal() {
        return frog;
    }

    /**
     * __API__
     * action: gen_method
     * throws: no_throw
     */
    const Frog& getFrog() {
        return frog;
    }

    /**
     * Method to check that any downcast is not done when descendants=[]
     * __API__
     * action: gen_method
     * throws: no_throw
     */
    const Frog& getLittleFrog() {
        return _little_frog;
    }

private:
    Frog frog;
    LittleFrog _little_frog;
};

}

#endif
