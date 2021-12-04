/**
 * ,--.,------. ,----.   ,------.,--.  ,--. 
 * |  ||  .---''  .-.|   |  .---'|  ,'.|  | 
 * |  ||  `--, |  | .---.|  `--, |  |' '  | 
 * |  ||  `---.'  '--'  ||  `---.|  | `   | 
 * `--'`------' `------' `------'`--'  `--' 
 * 
 * This file is generated by iegen on 12/04/2021-10:56.
 * Please do not change it manually.
 */

import Foundation
import HelloExample.CWrapper
/**
 * Host class.
 */
public class Host  {
    
    public let cself : UnsafeMutableRawPointer
    public let owner : Bool

    // internal main initializer
    internal required init(_ _cself: UnsafeMutableRawPointer, _ _owner: Bool = false) {
        self.cself = _cself
        self.owner = _owner
    }
    deinit {
        if owner {
            release_Host(cself)
        }
    }
    
    /**
     * Creates host
     */
    public convenience init() {

        self.init(create_Host(), true)
    }
    
    /**
     * Greeting function.
     */
    public func hello(user: UserInfo) -> String {

        let swift_to_sc_user = user.cself
        var err = ErrorObj()
        let result = _func_Host_hello(cself, swift_to_sc_user, &err)
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
      let sc_to_swift_result = String(cString: result)
        defer {
          result.deallocate()
        }
      return sc_to_swift_result
    }
    /**
     * Welcome function.
     */
    public func welcome(user: UserInfo) -> String {

        let swift_to_sc_user = user.cself
        var err = ErrorObj()
        let result = _func_Host_welcome(cself, swift_to_sc_user, &err)
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
      let sc_to_swift_result = String(cString: result)
        defer {
          result.deallocate()
        }
      return sc_to_swift_result
    }
}