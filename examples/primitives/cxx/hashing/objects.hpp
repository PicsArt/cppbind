#ifndef HASHABLE_HPP
#define HASHABLE_HPP

#include <stddef.h>
#include <functional>
#include <memory>

namespace cppbind::example {
// [example-start]
/**
 * Class with custom hash, equals and toString methods.
 * __API__
 * action: gen_class
 * package: hashing
 */
class Object1 {
public:
    /**
     * __API__
     * action: gen_constructor
     * throws: no_throw
     */
    Object1(int value=0): _value(value) {}

    /**
     * __API__
     * action: gen_getter
     * throws: no_throw
     */
    int value() const {
        return _value;
    }

    /**
     * Hash function returning dummy value for testing purposes.
     * __API__
     * action: gen_method
     * throws: no_throw
     */
    virtual size_t hash() const {
        return std::hash<int>{}(_value);
    }

    /**
     * Equals function returning dummy value for testing purposes.
     * __API__
     * action: gen_method
     * throws: no_throw
     */
    virtual bool equals(const Object1* other) const {
        return _value == other->value();
    }

    /**
     * ToString function returning dummy value for testing purposes.
     * __API__
     * action: gen_method
     * throws: no_throw
     */
    virtual std::string toString() const {
        return "Object1 " + std::to_string(_value);
    }

    virtual ~Object1() = default;

private:
    int _value;
};

/**
 * Class without any special functions.
 * For Kotlin CppBind will generate the default ones based on underlying C++ object is and type name.
 * For Swift and Python it won't generate them.
 * Instead for Python will generate a __repr__ returning a string containing C++ object id and type name.
 * __API__
 * action: gen_class
 * package: hashing
 */
struct Object2 {

    /**
     * __API__
     * action: gen_constructor
     * throws: no_throw
     */
    Object2() {}

    virtual ~Object2() = default;
};

// [example-end]

/**
 * Class with custom hash, equals and toString methods.
 * __API__
 * action: gen_class
 * package: hashing
 * shared_ref: True
 */
class Object3 {
public:
    /**
     * __API__
     * action: gen_constructor
     * throws: no_throw
     */
    Object3(int value=0): _value(value) {}

    /**
     * __API__
     * action: gen_getter
     * throws: no_throw
     */
    int value() const {
        return _value;
    }

    /**
     * Hash function returning dummy value for testing purposes.
     * __API__
     * action: gen_method
     * throws: no_throw
     */
    virtual size_t hash() const {
        return std::hash<int>{}(_value);
    }

    /**
     * Equals based on value property for testing purposes.
     * __API__
     * action: gen_method
     * throws: no_throw
     */
    virtual bool equals(std::shared_ptr<Object3> other) const {
        return _value == other->value();
    }

    /**
     * ToString based on value property for testing purposes.
     * __API__
     * action: gen_method
     * throws: no_throw
     */
    virtual std::string toString() const {
        return "Object3 " + std::to_string(_value);
    }

    virtual ~Object3() = default;

private:
    int _value;
};

/**
 * Class without any special functions.
 * For Kotlin CppBind will generate the default ones based on underlying C++ object is and type name.
 * For Swift and Python it won't generate them.
 * Instead for Python will generate a __repr__ returning a string containing C++ object id and type name.
 * __API__
 * action: gen_class
 * package: hashing
 * shared_ref: True
 */
struct Object4 {

    /**
     * __API__
     * action: gen_constructor
     * throws: no_throw
     */
    Object4() {}

    virtual ~Object4() = default;
};

/**
 * __API__
 * action: gen_class
 * package: hashing
 */
struct ExtendedObject1 : public Object1 {
    /**
     * __API__
     * action: gen_constructor
     * throws: no_throw
     */
    ExtendedObject1(int value=0): Object1(value) {}

    /**
     * Hash function returning dummy value for testing purposes.
     * __API__
     * action: gen_method
     * throws: no_throw
     */
    virtual size_t hash() const override {
        return std::hash<int>{}(value() + 1);
    }
};


/**
 * __API__
 * action: gen_class
 * package: hashing
 */
struct ExtendedObject2 : public Object2 {
    /**
     * __API__
     * action: gen_constructor
     * throws: no_throw
     */
    ExtendedObject2() {}
};

/**
 * __API__
 * action: gen_class
 * package: hashing
 * shared_ref: True
 */
struct ExtendedObject3 : public Object3 {
    /**
     * __API__
     * action: gen_constructor
     * throws: no_throw
     */
    ExtendedObject3(int value=0): Object3(value) {}
};

/**
 * __API__
 * action: gen_class
 * package: hashing
 * shared_ref: True
 */
struct ExtendedObject4 : public Object4 {
    /**
     * __API__
     * action: gen_constructor
     * throws: no_throw
     */
    ExtendedObject4() {}
};

}

#endif