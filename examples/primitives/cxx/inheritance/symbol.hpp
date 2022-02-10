#ifndef symbol_hpp
#define symbol_hpp

#include <string>

namespace iegen::example {

/**
 * __API__
 * action: gen_interface
 * package: inheritance
 */
class Sign {
public:
    int id = 1;

    /**
     * __API__
     * action: gen_constructor
     * throws: no_throw
     */
    Sign() {}

    virtual ~Sign() = default;

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
 * package: inheritance
 */
class Text {
public:
    int id = 2;
    /**
     * __API__
     * action: gen_constructor
     * throws: no_throw
     */
    Text() {}

    virtual ~Text() = default;

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
 * package: inheritance
 */
class Digit : public Sign, public Text {
public:
    int id = 3;
    /**
     * __API__
     * action: gen_constructor
     * throws: no_throw
     */
    Digit() {}

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
 * package: inheritance
 */
class SymbolUsage {
public:
    /**
     * __API__
     * action: gen_constructor
     * throws: no_throw
     */
    SymbolUsage() {}

    /**
     * __API__
     * action: gen_constructor
     * throws: no_throw
     */
    SymbolUsage(Digit* d) : _d(d) {}

    /**
     * __API__
     * action: gen_method
     * throws: no_throw
     */
    std::string getTextType(Text* t) {
        return t->typeName();
    }

    /**
     * __API__
     * action: gen_method
     * throws: no_throw
     */
    std::string getSignType(Sign* s) {
        return s->typeName();
    }

    /**
     * __API__
     * action: gen_method
     * throws: no_throw
     */
    int getTextId(Text* t) {
        return t->id;
    }

    /**
     * __API__
     * action: gen_method
     * throws: no_throw
     */
    int getSignId(Sign* s) {
        return s->id;
    }

    /**
     * __API__
     * action: gen_method
     * throws: no_throw
     * return_value_policy: reference
     */
     Text* getTextPtr() {
        return _d;
     }

    /**
     * __API__
     * action: gen_method
     * throws: no_throw
     * return_value_policy: reference
     */
     Sign* getSignPtr() {
        return _d;
     }

private:
    Digit* _d;
};

}

#endif
