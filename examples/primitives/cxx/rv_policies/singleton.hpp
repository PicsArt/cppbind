#ifndef singleton_hpp
#define singleton_hpp


namespace iegen::example {

// [example]
/**
 * __API__
 * action: gen_class
 * shared_ref: False
 * package: rv_policies
 */
class Singleton {
public:
    /**
     * __API__
     * action: gen_method
     * throws: no_throw
     * return_value_policy: reference
     */
    static Singleton& getInstance();
    /**
     * __API__
     * action: gen_method
     * throws: no_throw
     * return_value_policy: reference
     */
    static Singleton* getInstancePtr();

    Singleton(const Singleton&) = delete;
    void operator=(const Singleton&) = delete;

private:
    Singleton();
    static Singleton* _instance;
};

// [example]
}

#endif
