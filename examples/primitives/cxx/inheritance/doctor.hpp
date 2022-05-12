#ifndef doctor_hpp
#define doctor_hpp

#include <string>

namespace cppbind::example {

/**
 * A base class for checking single branch non-polymorphic inheritance cases
 * __API__
 * action: gen_class
 * package: inheritance
 */
class Doctor {
public:
    std::string name;

   /**
    * __API__
    * action: gen_constructor
    * throws: no_throw
    */
    Doctor(std::string doctor_name) : name(doctor_name) {}
};

/**
 * __API__
 * action: gen_class
 * package: inheritance
 */
class Surgeon : public Doctor {
public:
    std::string name;

   /**
    * __API__
    * action: gen_constructor
    * throws: no_throw
    */
    Surgeon(std::string surgeon_name) : Doctor("doctor"), name(surgeon_name) {}
};

/**
 * A base class for checking multibranch mixed polymorphic inheritance cases
 * __API__
 * action: gen_interface
 * package: inheritance
 */
class GoodVirtualDoctor {
public:
    std::string name;

    virtual ~GoodVirtualDoctor() = default;
};

/**
 * __API__
 * action: gen_class
 * package: inheritance
 */
class GoodDoctor {
public:
    std::string name;

   /**
    * __API__
    * action: gen_constructor
    * throws: no_throw
    */
    GoodDoctor(std::string doctor_name) : name(doctor_name) {}
};

/**
 * Polymorphic subclass
 * __API__
 * action: gen_class
 * package: inheritance
 */
class GoodYoungDoctor : public GoodVirtualDoctor, public GoodDoctor {
public:
    std::string name;

   /**
    * __API__
    * action: gen_constructor
    * throws: no_throw
    */
    GoodYoungDoctor(std::string doctor_name) : GoodDoctor("good_doctor"), name(doctor_name) {}
};

/**
 * Non-polymorphic subclass
 * __API__
 * action: gen_class
 * package: inheritance
 */
class GoodOldDoctor : public GoodDoctor {
public:
    std::string name;

   /**
    * __API__
    * action: gen_constructor
    * throws: no_throw
    */
    GoodOldDoctor(std::string doctor_name) : GoodDoctor("good_doctor"), name(doctor_name) {}
};

/**
 * __API__
 * action: gen_class
 * package: inheritance
 */
class DoctorInfo {
public:
    /**
     * __API__
     * action: gen_constructor
     * throws: no_throw
     */
    DoctorInfo(Surgeon* s) : _s(s) {}

    /**
     * __API__
     * action: gen_constructor
     * throws: no_throw
     */
    DoctorInfo(GoodYoungDoctor* d) : _d(d) {}

    /**
     * __API__
     * action: gen_method
     * throws: no_throw
     */
    std::string getDoctorName(Doctor* d) {
        return d->name;
    }

    /**
     * __API__
     * action: gen_method
     * throws: no_throw
     */
    std::string getSurgeonName(Surgeon* s) {
        return s->name;
    }

    /**
     * __API__
     * action: gen_method
     * throws: no_throw
     * return_value_policy: reference
     */
    Doctor* getDoctor() {
        return _s;
    }

    /**
     * __API__
     * action: gen_method
     * throws: no_throw
     * return_value_policy: reference
     */
    GoodDoctor* getGoodDoctor() {
        return _d;
    }

    /**
     * __API__
     * action: gen_method
     * throws: no_throw
     * return_value_policy: reference
     */
    GoodVirtualDoctor* getGoodVirtualDoctor() {
        return _d;
    }

    /**
     * __API__
     * action: gen_method
     * throws: no_throw
     */
    std::string getGoodDoctorName(GoodDoctor* d) {
        return d->name;
    }

private:
    Surgeon* _s;
    GoodYoungDoctor* _d;

};

}

#endif
