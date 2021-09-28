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

public class SimpleBaseException  : Error {
    
    public let cself : UnsafeMutableRawPointer
    public let owner : Bool

    // internal main initializer
    internal required init(_ _cself: UnsafeMutableRawPointer, _ _owner: Bool = false) {
        self.cself = _cself
        self.owner = _owner
    }
    deinit {
        if owner {
            release_SimpleBaseException(cself)
        }
    }
    
    
    public convenience init(err_num: Int) {

        let swift_to_sc_err_num = CInt(err_num)
        self.init(create_SimpleBaseException(swift_to_sc_err_num), true)
    }
    
    
    public func errNum() -> Int {

        var err = ErrorObj()
        let result = _func_SimpleBaseException_errNum(cself, &err)
        let sc_to_swift_result = Int(result)
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

public class SimpleChildException : SimpleBaseException {
    
    /**
     * comments
     * 
     */
    public convenience init(err_num: Int) {

        let swift_to_sc_err_num = CInt(err_num)
        self.init(create_SimpleChildException(swift_to_sc_err_num), true)
    }
    
    /**
     * comments
     * 
     */
    public override func errNum() -> Int {

        var err = ErrorObj()
        let result = _func_SimpleChildException_errNum(cself, &err)
        let sc_to_swift_result = Int(result)
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