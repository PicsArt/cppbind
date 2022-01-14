#ifndef symbol_hpp
#define symbol_hpp

#include <string>

namespace iegen::example {

/**
 * __API__
 * action: gen_interface
 * package: inheritance
 */
class Symbol {
public:
    /**
     * __API__
     * action: gen_constructor
     * throws: no_throw
     */
    Symbol() {}

    virtual ~Symbol() = default;

    /**
     * __API__
     * action: gen_method
     * throws: no_throw
     */
     virtual std::string typeName()  {
        return "symbol";
     }
};

/**
 * __API__
 * action: gen_interface
 * package: inheritance
 */
class Number {
public:
    /**
     * __API__
     * action: gen_constructor
     * throws: no_throw
     */
    Number() {}

    /**
     * __API__
     * action: gen_method
     * throws: no_throw
     */
     std::string typeName() {
        return _type;
     }

private:
    std::string _type = "number";
};

/**
 * __API__
 * action: gen_class
 * package: inheritance
 */
class Text {
public:
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
class Digit : public Number, public Text {
public:
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
     * action: gen_method
     * throws: no_throw
     */
    std::string getTextType(Text* t) {
        return t->typeName();
    }

};

}

#endif
