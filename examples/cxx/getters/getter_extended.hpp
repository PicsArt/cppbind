/**
 * @file getter.h
 * @brief This is an example pf simple getter/setter.
 *
 * This class contains a private string field and getter/setter methods for it.
 */

namespace iegen::example::getter {

/**
 * This class contains a private string field and getter/setter methods for it.
 * __API__
 * gen: class
 * shared_ref: true
 * package: getters
 */
class GetterSetterExtended :public GetterSetter {
public:
    /**
     * comments
     *
     * __API__
     * gen: constructor
     */
    GetterSetterExtended() : GetterSetter() {}

};

}