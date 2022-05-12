#ifndef keep_alive_policies_hpp
#define keep_alive_policies_hpp

#include <string>
#include <iostream>
#include <vector>
#include <memory>

namespace cppbind::example {
// [keep-alive-raw]
/**
 * A test example for keep_alive policy with shared_ref=False.
 * __API__
 * action: gen_class
 * package: rv_policies
 * shared_ref: False
 */
class Child1 {
public:

    /**
     * __API__
     * action: gen_constructor
     * throws: no_throw
     */
    Child1(std::string name) : _name(name) {
        std::cout<<"allocating child1 with name = "<<_name<<std::endl;
    }

    /**
     * __API__
     * action: gen_getter
     * throws: no_throw
     */
    std::string name() {
        return _name;
    }

    ~Child1() {
        std::cout<<"deallocating child1 with name = "<<_name<<" "<<this<<std::endl;
    }

private:
    std::string _name;

};

/**
 *  A test example for keep_alive policy with action=gen_interface.
 * __API__
 * action: gen_interface
 * package: rv_policies
 * shared_ref: False
 */
class Child3 {
public:

    /**
     * __API__
     * action: gen_constructor
     * throws: no_throw
     */
    Child3(std::string name) : _name(name) {
        std::cout<<"allocating child3 with name = "<<_name<<std::endl;
    }

    /**
     * __API__
     * action: gen_getter
     * throws: no_throw
     */
    std::string name() {
        return _name;
    }

    ~Child3() {
        std::cout<<"deallocating child3 with name = "<<_name<<" "<<this<<std::endl;
    }

private:
    std::string _name;

};

/**
 * A test example for keep_alive policy with shared_ref=True.
 * __API__
 * action: gen_class
 * package: rv_policies
 * shared_ref: True
 */
class Child2 {
public:

    /**
     * __API__
     * action: gen_constructor
     * throws: no_throw
     */
    Child2(std::string name) : _name(name) {
        std::cout<<"allocating child2 with name = "<<_name<<std::endl;
    }

    /**
     * __API__
     * action: gen_getter
     * throws: no_throw
     */
    std::string name() {
        return _name;
    }

    ~Child2() {
        std::cout<<"deallocating child2 with name = "<<_name<<" "<<this<<std::endl;
    }

private:
    std::string _name;

};

/**
 * A test example for keep_alive policy. Container holding shared_ref and non shared_ref class and interface types.
 * __API__
 * action: gen_class
 * package: rv_policies
 * shared_ref: False
 */
class Parent1 {
public:
    /**
     * __API__
     * action: gen_constructor
     * throws: no_throw
     * keep_alive:
     *  - 2
     *  - 4
     */
    Parent1(std::string name, Child1* child1, std::shared_ptr<Child2> child2, Child3* _child3)
            : child3(_child3)
            , _name(name)
            , _child1(child1)
            , _child2(child2) {
        std::cout<<"allocating parent with name = "<<_name<<std::endl;
    }

    /**
     * __API__
     * action: gen_getter
     * throws: no_throw
     */
    std::string name() {
        return _name;
    }

    /**
     * __API__
     * action: gen_getter
     * throws: no_throw
     */
    Child1* child1() {
        return _child1;
    }

    /**
     * __API__
     * action: gen_setter
     * throws: no_throw
     * keep_alive: [1]
     */
    void setChild1(Child1* child1) {
        _child1 = child1;
    }

    /**
     * __API__
     * action: gen_getter
     * throws: no_throw
     */
     std::shared_ptr<Child2> child2() {
        return _child2;
    }

    /**
     * __API__
     * action: gen_property_setter
     * keep_alive: [1]
     */
    Child3 * child3;

    ~Parent1() {
        std::cout<<"deallocating parent with name = "<<_name<<std::endl;
    }

private:
    std::string _name;
    Child1 * _child1;
    std::shared_ptr<Child2> _child2;
};

// [keep-alive-raw]

// [keep-alive-shared]

/**
 * A test example for keep_alive policy. Container holding shared_ref and non shared_ref class and interface types.
 * __API__
 * action: gen_class
 * package: rv_policies
 * shared_ref: False
 */
class Parent2 {
public:
    /**
     * __API__
     * action: gen_constructor
     * throws: no_throw
     */
    Parent2(std::string name) : _name(name) {
        std::cout<<"allocating parent with name = "<<_name<<std::endl;
    }

    /**
     * __API__
     * action: gen_getter
     * throws: no_throw
     */
    std::string name() {
        return _name;
    }

    /**
     * __API__
     * action: gen_getter
     * throws: no_throw
     */
    const std::vector<Child1*>& children1() {
        return _children1;
    }

    /**
     * __API__
     * action: gen_method
     * throws: no_throw
     */
    void addChild1(Child1* c) {
        _children1.push_back(c);
    }

    /**
     * __API__
     * action: gen_method
     * throws: no_throw
     * keep_alive: [1]
     */
    void addChildren1(const std::vector<Child1*>& c) {
        _children1.insert(_children1.end(), c.begin(), c.end());
    }

    /**
     * __API__
     * action: gen_method
     * throws: no_throw
     */
    void addChild2(std::shared_ptr<Child2> c) {
        _children2.push_back(c);
    }

    /**
     * __API__
     * action: gen_method
     * throws: no_throw
     */
    void addChildren2(const std::vector<std::shared_ptr<Child2>>& c) {
        _children2.insert(_children2.end(), c.begin(), c.end());
    }

    /**
     * __API__
     * action: gen_getter
     * throws: no_throw
     */
    const std::vector<std::shared_ptr<Child2>>& children2() {
        return _children2;
    }


    ~Parent2() {
        std::cout<<"deallocating parent2 with name = "<<_name<<" "<<this<<std::endl;
    }

private:
    std::string _name;
    std::vector<Child1*> _children1;
    std::vector<std::shared_ptr<Child2>> _children2;

};
// [keep-alive-shared]

}

#endif