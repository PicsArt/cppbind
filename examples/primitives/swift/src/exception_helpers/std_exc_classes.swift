/**
 * ,--.,------. ,----.   ,------.,--.  ,--. 
 * |  ||  .---''  .-.|   |  .---'|  ,'.|  | 
 * |  ||  `--, |  | .---.|  `--, |  |' '  | 
 * |  ||  `---.'  '--'  ||  `---.|  | `   | 
 * `--'`------' `------' `------'`--'  `--' 
 * 
 * This file is generated by iegen on 12/03/2021-06:24.
 * Please do not change it manually.
 */

import CWrapper
import Foundation

public class StdException  : Error {
    
    public let cself : UnsafeMutableRawPointer
    public let owner : Bool

    // internal main initializer
    internal required init(_ _cself: UnsafeMutableRawPointer, _ _owner: Bool = false) {
        self.cself = _cself
        self.owner = _owner
    }
    deinit {
        if owner {
            release_StdException(cself)
        }
    }
    
    
    
    
    public func what() -> String {

        var err = ErrorObj()
        let result = _func_StdException_what(cself, &err)
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
      return sc_to_swift_result
    }
}

public class StdLogicError : StdException {
    
    
    
    
}

public class StdRuntimeError : StdException {
    
    
    
    
}

public class StdDomainError : StdLogicError {
    
    
    
    
}

public class StdInvalidArgument : StdLogicError {
    
    
    
    
}

public class StdLengthError : StdLogicError {
    
    
    
    
}

public class StdOutOfRange : StdLogicError {
    
    
    
    
}

public class StdRangeError : StdRuntimeError {
    
    
    
    
}

public class StdOverflowError : StdRuntimeError {
    
    
    
    
}

public class StdUnderflowError : StdRuntimeError {
    
    
    
    
}

public class StdBadAlloc : StdException {
    
    
    
    
}

public class StdBadCast : StdException {
    
    
    
    
}

public class StdBadTypeId : StdException {
    
    
    
    
}