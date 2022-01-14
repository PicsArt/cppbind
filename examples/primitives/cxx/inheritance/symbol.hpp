#ifndef symbol_hpp
#define symbol_hpp

#include <string>
#include <iostream>

namespace iegen::example {

///**
// * __API__
// * action: gen_interface
// * package: inheritance
// */
//class Symbol {
//public:
//    /**
//     * __API__
//     * action: gen_constructor
//     * throws: no_throw
//     */
//    Symbol() {}
//
//    virtual ~Symbol() = default;
//
//    /**
//     * __API__
//     * action: gen_method
//     * throws: no_throw
//     */
//     virtual std::string typeName()  {
//        return "symbol";
//     }
//};

/**
 * __API__
 * action: gen_interface
 * package: inheritance
 */
class Number {
public:
    int id = 1;
    /**
     * __API__
     * action: gen_constructor
     * throws: no_throw
     */
    Number() {}

    virtual ~Number() = default;

    /**
     * __API__
     * action: gen_method
     * throws: no_throw
     */
     virtual std::string typeName() {
        std::cout << "Calling Number::typeName()" << std::endl;
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
    int id = 2;
    std::string initText;
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
       std::cout << "Calling Text::typeName()" << std::endl;
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
       std::cout << "Calling Digit::typeName()" << std::endl;
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
        std::cout << "Calling SymbolUsage::getTextType()" << std::endl;
        return t->typeName();
    }

    /**
     * __API__
     * action: gen_method
     * throws: no_throw
     */
    std::string getNumberType(Number* n) {
        std::cout << "Calling SymbolUsage::getNumberType()" << std::endl;
        return n->typeName();
    }

    /**
     * __API__
     * action: gen_method
     * throws: no_throw
     */
     Text* getTextPtr() {
        std::cout << "Calling SymbolUsage::getTextPtr()" << std::endl;
        return _d;
     }

    /**
     * __API__
     * action: gen_method
     * throws: no_throw
     */
     Number* getNumberPtr() {
        std::cout << "Calling SymbolUsage::getNumberPtr()" << std::endl;
        return _d;
     }

private:
    Digit* _d;

};

}

#endif
