#ifndef IEGENCORETESTUI_IEGENOBJECT_HPP
#define IEGENCORETESTUI_IEGENOBJECT_HPP

#include <memory>
#include<string>
#include<jni.h>

namespace iegen {

/**
 * comments
 * 
 * __API__
 * gen: class
 * package: extra
 * shared_ref: True
 */
class Object {
public:
    virtual ~Object() = default;

    /**
     * String representation for mainly debug porpoises
     * @return class name and object address
     * __API__
     * gen: method
     */
    virtual std::string toString() const;

    /**
     * Human readable class name
     * @return class name
     * __API__
     * gen: method
     */
    virtual std::string className() const;

    /**
     * Compare on equality two objects
     * @param other is the second one
     * @return is equals two objects
     * __API__
     * gen: method
     */
    bool equals(std::shared_ptr<Object> other) const;

    virtual bool equals(const Object* other) const;

    /**
     * Hash for object. Used in wrappers (java, obj-c, python) to define the hash function
     * @return hash of the object
     * __API__
     * gen: method
     */
    virtual std::size_t hash() const;

    /**
     * Detailed string representation only for debug porpoises
     * @return object state as string
     * __API__
     * gen: method
     */
    virtual std::string debugInfo() const;

    /**
     * The object's size in bytes
     * @return bytes count
     * __API__
     * gen: method
     */
    virtual size_t bytesCount() const;

};

} // namespace iegen

#endif // PICORETESTUI_PIOBJECT_HPP
