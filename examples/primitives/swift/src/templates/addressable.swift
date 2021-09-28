/**
 * ,--.,------. ,----.   ,------.,--.  ,--. 
 * |  ||  .---''  .-.|   |  .---'|  ,'.|  | 
 * |  ||  `--, |  | .---.|  `--, |  |' '  | 
 * |  ||  `---.'  '--'  ||  `---.|  | `   | 
 * `--'`------' `------' `------'`--'  `--' 
 * 
 * This file is generated by iegen on 09/01/2021-15:29.
 * Please do not change it manually.
 */

import CWrapper
import Foundation
/**
 * Addressable is a base class for all the objects, that have abs path.
 */
public protocol AddressableRoot  {

    
    var cself : UnsafeMutableRawPointer { get }
    
    
    
    /**
     * comments
     * @brief Get object's abs path based on parent's abs path and object's name
     * @return the abs path of the object
     */
    func absPath() -> String
}
extension AddressableRoot {
    
    /**
     * comments
     * @brief Get object's abs path based on parent's abs path and object's name
     * @return the abs path of the object
     */
    public func absPath() -> String {

        var err = ErrorObj()
        let result = _func_AddressableRoot_absPath(cself, &err)
        let sc_to_swift_result = String(cString: result)
        defer{
          result.deallocate()
        }
        let err_type = Int(err.err_type)
        if (err_type != 0) {
            switch(err_type) {
                case(1):
                    let exc_obj = StdException(err.err_ptr, true)
                    ExceptionHandler.handleUncaughtException(exc_obj.what())
                default:
                    ExceptionHandler.handleUncaughtException("Uncaught Exception")
            }
        }
        return sc_to_swift_result
    }
}
public class AddressableImplRoot : AddressableRoot {
    public let cself : UnsafeMutableRawPointer
    public let owner : Bool

    // internal main initializer
    internal required init(_ _cself: UnsafeMutableRawPointer, _ _owner: Bool = false) {
      self.cself = _cself
      self.owner = _owner
    }
    deinit {
      if owner {
        release_AddressableImplRoot(cself)
      }
    }

    /**
     * comments
     */
    public convenience init(parent: Root, name: String) {

        let swift_to_sc_parent = parent.cself
        let swift_to_sc_name = strdup(name)!
        self.init(create_AddressableRoot(swift_to_sc_parent, swift_to_sc_name), true)
    }
}