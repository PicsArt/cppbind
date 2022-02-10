#ifndef rv_policies_hpp
#define rv_policies_hpp

#include <string>
#include <iostream>
#include <memory>

#include "cxx/simple/task.hpp"

namespace iegen::example {
// [example]

/**
 * A test example for return value policies. This is not used in documentation.
 * __API__
 * action: gen_class
 * package: rv_policies
 * shared_ref: False
 * swift.name: SwValue
 */
struct Value {
    /**
     * __API__
     * action: gen_constructor
     * throws: no_throw
     */
    Value(std::string name) : _name(name) {
        std::cout<<"Value default constructor with name="<<_name<<std::endl;
    }

    Value(const Value& v) {
        _name = v.name();
        std::cout<<"Value copy constructor for name="<<_name<<std::endl;
    }

    Value(Value&& v) {
        _name = v.name();
        std::cout<<"Value move constructor for name="<<_name<<std::endl;
    }

    /**
     * __API__
     * action: gen_getter
     * throws: no_throw
     */
     std::string name() const {
        return _name;
     }

     /**
      * __API__
      * action: gen_setter
      * throws: no_throw
      */
    void setName(std::string name) const {
        std::cout<<"set name called"<<std::endl;
        _name = name;
     }

    ~Value() {
        std::cout<<"Value destructor for name="<<_name<<" "<<this<<std::endl;
    }

private:
    mutable std::string _name;
};

/**
 * __API__
 * action: gen_class
 * package: rv_policies
 * shared_ref: True
 */
struct ValueSharedRef {
       /**
     * __API__
     * action: gen_constructor
     * throws: no_throw
     */
    ValueSharedRef(std::string name) : _name(name) {
        std::cout<<"ValueSharedRef default constructor with name="<<_name<<std::endl;
    }

    ValueSharedRef(const ValueSharedRef& v) {
        _name = v.name();
        std::cout<<"ValueSharedRef copy constructor for name="<<_name<<std::endl;
    }

    ValueSharedRef(ValueSharedRef&& v) {
        _name = v.name();
        std::cout<<"ValueSharedRef move constructor for name="<<_name<<std::endl;
    }

    /**
     * __API__
     * action: gen_getter
     * throws: no_throw
     */
    std::string name() const {
        return _name;
    }

    /**
     * __API__
     * action: gen_setter
     * throws: no_throw
     */
    void setName(std::string name) const {
        _name = name;
    }

    ~ValueSharedRef() {
        std::cout<<"ValueSharedRef destructor for name="<<_name<<std::endl;
    }

private:
    mutable std::string _name;
};

/**
 * __API__
 * action: gen_class
 * package: rv_policies
 */
class ValuesHolder {

public:
    /**
     * __API__
     * action: gen_constructor
     * throws: no_throw
     */
    ValuesHolder()
       : _valuePtr(new Value("initial"))
       , _valueRef(std::shared_ptr<ValueSharedRef>(new ValueSharedRef("initial"))) {};

    /**
     * __API__
     * action: gen_constructor
     * throws: no_throw
     */
    ValuesHolder(Value* valuePtr, std::shared_ptr<ValueSharedRef> valueRef)
       : _valuePtr(valuePtr)
       , _valueRef(valueRef) {};

    /**
     * __API__
     * action: gen_method
     * throws: no_throw
     */
    Value* getPtrDefault() {
        return _valuePtr;
    };

    /**
     * __API__
     * action: gen_method
     * throws: no_throw
     * return_value_policy: copy
     */
    Value* getPtrCopy() {
        return _valuePtr;
    };

    /**
     * __API__
     * action: gen_method
     * throws: no_throw
     * return_value_policy: move
     */
    Value* getPtrMove() {
        return _valuePtr;
    };

    /**
     * __API__
     * action: gen_method
     * throws: no_throw
     * return_value_policy: reference
     */
    Value* getPtrReference() {
        return _valuePtr;
    };

    /**
     * __API__
     * action: gen_method
     * throws: no_throw
     * return_value_policy: automatic
     */
    Value* getPtrAutomatic() {
        return _valuePtr;
    };

    /**
     * __API__
     * action: gen_method
     * throws: no_throw
     * return_value_policy: automatic_reference
     */
    Value* getPtrAutomaticReference() {
        return _valuePtr;
    };

    /**
     * __API__
     * action: gen_method
     * throws: no_throw
     * return_value_policy: take_ownership
     */
    Value* getPtrTakeOwnership() {
        return _valuePtr;
    };

    /**
     * __API__
     * action: gen_method
     * throws: no_throw
     */
    Value getValueDefault() {
        return *_valuePtr;
    };

    /**
     * __API__
     * action: gen_method
     * throws: no_throw
     * return_value_policy: copy
     */
    Value getValueCopy() {
        return *_valuePtr;
    };

    /**
     * __API__
     * action: gen_method
     * throws: no_throw
     * return_value_policy: move
     */
    Value getValueMove() {
        return *_valuePtr;
    };

    /**
     * __API__
     * action: gen_method
     * throws: no_throw
     * return_value_policy: reference
     */
    Value getValueReference() {
        return *_valuePtr;
    };

    /**
     * __API__
     * action: gen_method
     * throws: no_throw
     * return_value_policy: automatic
     */
    Value getValueAutomatic() {
        return *_valuePtr;
    };

    /**
     * __API__
     * action: gen_method
     * throws: no_throw
     * return_value_policy: automatic_reference
     */
    Value getValueAutomaticReference() {
        return *_valuePtr;
    };

    /**
     * __API__
     * action: gen_method
     * throws: no_throw
     * return_value_policy: take_ownership
     */
    Value getValueTakeOwnership() {
        return *_valuePtr;
    };

    /**
     * __API__
     * action: gen_method
     * throws: no_throw
     * return_value_policy: copy
     */
    Value& getRefCopy() {
        return *_valuePtr;
    };


    /**
     * __API__
     * action: gen_method
     * throws: no_throw
     */
    Value& getRefDefault() {
        return *_valuePtr;
    };

    /**
     * __API__
     * action: gen_method
     * throws: no_throw
     * return_value_policy: move
     */
    Value& getRefMove() {
        return *_valuePtr;
    };

    /**
     * __API__
     * action: gen_method
     * throws: no_throw
     * return_value_policy: reference
     */
    Value& getRefReference() {
        return *_valuePtr;
    };

    /**
     * __API__
     * action: gen_method
     * throws: no_throw
     * return_value_policy: automatic
     */
    Value& getRefAutomatic() {
        return *_valuePtr;
    };

    /**
     * __API__
     * action: gen_method
     * throws: no_throw
     * return_value_policy: automatic_reference
     */
    Value& getRefAutomaticReference() {
        return *_valuePtr;
    };

    /**
     * __API__
     * action: gen_method
     * throws: no_throw
     * return_value_policy: take_ownership
     */
    Value& getRefTakeOwnership() {
        return *_valuePtr;
    };

    /**
     * __API__
     * action: gen_method
     * throws: no_throw
     */
    std::shared_ptr<ValueSharedRef> getSharedRefDefault() {
        return _valueRef;
    };

    /**
     * __API__
     * action: gen_method
     * throws: no_throw
     * return_value_policy: copy
     */
    std::shared_ptr<ValueSharedRef> getSharedRefCopy() {
        return _valueRef;
    };

    /**
     * __API__
     * action: gen_method
     * throws: no_throw
     * return_value_policy: move
     */
    std::shared_ptr<ValueSharedRef> getSharedRefMove() {
        return _valueRef;
    };


    /**
     * __API__
     * action: gen_method
     * throws: no_throw
     * return_value_policy: reference
     */
    std::shared_ptr<ValueSharedRef> getSharedRefReference() {
        return _valueRef;
    };


    /**
     * __API__
     * action: gen_method
     * throws: no_throw
     * return_value_policy: automatic
     */
    std::shared_ptr<ValueSharedRef> getSharedRefAutomatic() {
        return _valueRef;
    };

    /**
     * __API__
     * action: gen_method
     * throws: no_throw
     * return_value_policy: automatic_reference
     */
    std::shared_ptr<ValueSharedRef> getSharedRefAutomaticReference() {
        return _valueRef;
    };

    /**
     * __API__
     * action: gen_method
     * throws: no_throw
     * return_value_policy: take_ownership
     */
    std::shared_ptr<ValueSharedRef> getSharedRefTakeOwnership() {
        return _valueRef;
    };


    ~ValuesHolder() {
        std::cout<<"values holder destructor"<<std::endl;
        // not removing resources here for test cases
        // _valueRef.reset();
        // delete _valuePtr;
    }

private:
    Value* _valuePtr;
    std::shared_ptr<ValueSharedRef> _valueRef;

};
// [example]
}
#endif
