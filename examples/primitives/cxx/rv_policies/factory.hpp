#ifndef factory_hpp
#define factory_hpp


namespace iegen::example {

// [example]
/**
 * __API__
 * action: gen_class
 * shared_ref: False
 * package: rv_policies
 */
class Factory {
public:
    /**
     * __API__
     * action: gen_method
     * throws: no_throw
     */
    static Factory* create();

private:
    Factory();
};
// [example]
}

#endif
