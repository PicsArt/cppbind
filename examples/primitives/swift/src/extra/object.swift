import Foundation
import CWrapper

/**
 * comments
 * 
 */
public class Object  {
    
    public let cself : UnsafeMutableRawPointer
    public let owner : Bool

    // internal main initializer
    internal required init(_ _cself: UnsafeMutableRawPointer , _ _owner: Bool = false) {
      self.cself = _cself
      self.owner = _owner
    }
    deinit {
      if owner {
        release_Object(cself)
      }
    }
    
    
    
    /**
     * String representation for mainly debug porpoises
     * @return class name and object address
     */
    public func toString() -> String {

        let result = _func_Object_toString(cself);
        let sc_to_swift_result = String(cString: result)
        defer{
          result.deallocate()
        }
        return sc_to_swift_result;
    }
    /**
     * Human readable class name
     * @return class name
     */
    public func className() -> String {

        let result = _func_Object_className(cself);
        let sc_to_swift_result = String(cString: result)
        defer{
          result.deallocate()
        }
        return sc_to_swift_result;
    }
    /**
     * Compare on equality two objects
     * @param other is the second one
     * @return is equals two objects
     */
    public func equals(other: Object) -> Bool {

        let swift_to_sc_other = other.cself
        let result = _func_Object_equals(cself, swift_to_sc_other);
        
        return result;
    }
    /**
     * Hash for object. Used in wrappers (java, obj-c, python) to define the hash function
     * @return hash of the object
     */
    public func hash() -> CUnsignedLong {

        let result = _func_Object_hash(cself);
        
        return result;
    }
    /**
     * Detailed string representation only for debug porpoises
     * @return object state as string
     */
    public func debugInfo() -> String {

        let result = _func_Object_debugInfo(cself);
        let sc_to_swift_result = String(cString: result)
        defer{
          result.deallocate()
        }
        return sc_to_swift_result;
    }
    /**
     * The object's size in bytes
     * @return bytes count
     */
    public func bytesCount() -> CUnsignedLong {

        let result = _func_Object_bytesCount(cself);
        
        return result;
    }
}