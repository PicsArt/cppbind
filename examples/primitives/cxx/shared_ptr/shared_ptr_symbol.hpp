#ifndef shared_ptr_symbol_hpp
#define shared_ptr_symbol_hpp

#include <string>
#include <memory>

namespace cppbind::example {

/**
 * __API__
 * action: gen_interface
 * package: shared_ptr
 * shared_ref: True
 */
class SignShared {
public:
    int id = 1;

    /**
     * __API__
     * action: gen_constructor
     * throws: no_throw
     */
    SignShared() {}

    virtual ~SignShared() = default;

    /**
     * __API__
     * action: gen_method
     * throws: no_throw
     */
     virtual std::string typeName() {
        return _type;
     }

private:
    std::string _type = "sign";
};

/**
 * __API__
 * action: gen_class
 * package: shared_ptr
 * shared_ref: True
 */
class TextShared {
public:
    int id = 2;
    /**
     * __API__
     * action: gen_constructor
     * throws: no_throw
     */
    TextShared() {}

    virtual ~TextShared() = default;

    /**
     * __API__
     * action: gen_method
     * throws: no_throw
     */
    virtual std::string typeName()  {
       return _type;
    }

private:
    std::string _type = "text";
};

/**
 * __API__
 * action: gen_class
 * package: shared_ptr
 * shared_ref: True
 */
class DigitShared : public SignShared, public TextShared {
public:
    int id = 3;
    /**
     * __API__
     * action: gen_constructor
     * throws: no_throw
     */
    DigitShared() {}

    /**
     * __API__
     * action: gen_method
     * throws: no_throw
     */
    std::string typeName() {
       return _type;
    }

private:
    std::string _type = "digit";
};

/**
 * __API__
 * action: gen_class
 * package: shared_ptr
 */
class SymbolUsageShared {
public:
    /**
     * __API__
     * action: gen_constructor
     * throws: no_throw
     */
    SymbolUsageShared() {}

    /**
     * __API__
     * action: gen_constructor
     * throws: no_throw
     */
    SymbolUsageShared(std::shared_ptr<DigitShared> d) : _d(d) {}

    /**
     * __API__
     * action: gen_method
     * throws: no_throw
     */
    std::string getTextType(std::shared_ptr<TextShared> t) {
        return t->typeName();
    }

    /**
     * __API__
     * action: gen_method
     * throws: no_throw
     */
    std::string getSignType(std::shared_ptr<SignShared> s) {
        return s->typeName();
    }

    /**
     * __API__
     * action: gen_method
     * throws: no_throw
     */
    int getTextId(std::shared_ptr<TextShared> t) {
        return t->id;
    }

    /**
     * __API__
     * action: gen_method
     * throws: no_throw
     */
    int getSignId(std::shared_ptr<SignShared> s) {
        return s->id;
    }

    /**
     * __API__
     * action: gen_method
     * throws: no_throw
     */
     std::shared_ptr<TextShared> getTextPtr() {
        return _d;
     }

    /**
     * __API__
     * action: gen_method
     * throws: no_throw
     */
     std::shared_ptr<SignShared> getSignPtr() {
        return _d;
     }

private:
    std::shared_ptr<DigitShared> _d;
};

}

#endif
