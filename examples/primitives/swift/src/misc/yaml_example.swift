/**
 * ,--.,------. ,----.   ,------.,--.  ,--. 
 * |  ||  .---''  .-.|   |  .---'|  ,'.|  | 
 * |  ||  `--, |  | .---.|  `--, |  |' '  | 
 * |  ||  `---.'  '--'  ||  `---.|  | `   | 
 * `--'`------' `------' `------'`--'  `--' 
 * 
 * This file is generated by iegen on 12/06/2021-14:37.
 * Please do not change it manually.
 */

import CWrapper
import Foundation

public class WithExternalAPIComments  {
    
    public let cself : CObject
    public let owner : Bool

    // internal main initializer
    internal required init(_ _cself: CObject, _ _owner: Bool = false) {
        self.cself = _cself
        self.owner = _owner
    }
    deinit {
        if owner {
            release_WithExternalAPIComments(cself)
            cself.type?.deallocate()
        }
    }
    
    
    public convenience init(s: String) {

        let swift_to_sc_s = strdup(s)!
        var err = ErrorObj()
        self.init(create_WithExternalAPIComments(swift_to_sc_s, &err), true)
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
    }
    
    public var str: String {
        get {
            let result = _prop_get_WithExternalAPIComments_str(cself)
            let sc_to_swift_result = String(cString: result)
            defer {
              result.deallocate()
            }
            return sc_to_swift_result
        }
        
        
        set(value) {
            let swift_to_sc_value = strdup(value)!
            _prop_set_WithExternalAPIComments_str(cself, swift_to_sc_value)
        }
        
    }
    
    public static func retInt(n: Int) -> Int {

        let swift_to_sc_n = CInt(n)
        var err = ErrorObj()
        let result = _func_WithExternalAPIComments_retInt(swift_to_sc_n, &err)
        let err_type = Int(err.err_type)
        if (err_type != 0) {
            switch(err_type) {
                case(1):
                    let exc_obj = StdException(CObject(type: nil, ptr: err.err_ptr), true)
                    ExceptionHandler.handleUncaughtException(exc_obj.what())
                default:
                    ExceptionHandler.handleUncaughtException("Uncaught Exception")
            }
        }
      let sc_to_swift_result = Int(result)
      return sc_to_swift_result
    }

    public static func max(arg0: Int, arg1: Int) -> Int {

        let swift_to_sc_arg0 = CInt(arg0)
        let swift_to_sc_arg1 = CInt(arg1)
        var err = ErrorObj()
        let result = _func_WithExternalAPIComments_maxInt(swift_to_sc_arg0, swift_to_sc_arg1, &err)
        let err_type = Int(err.err_type)
        if (err_type != 0) {
            switch(err_type) {
                case(1):
                    let exc_obj = StdException(CObject(type: nil, ptr: err.err_ptr), true)
                    ExceptionHandler.handleUncaughtException(exc_obj.what())
                default:
                    ExceptionHandler.handleUncaughtException("Uncaught Exception")
            }
        }
      let sc_to_swift_result = Int(result)
      return sc_to_swift_result
    }

    public static func max(arg0: String, arg1: String) -> String {

        let swift_to_sc_arg0 = strdup(arg0)!
        let swift_to_sc_arg1 = strdup(arg1)!
        var err = ErrorObj()
        let result = _func_WithExternalAPIComments_maxString(swift_to_sc_arg0, swift_to_sc_arg1, &err)
        let err_type = Int(err.err_type)
        if (err_type != 0) {
            switch(err_type) {
                case(1):
                    let exc_obj = StdException(CObject(type: nil, ptr: err.err_ptr), true)
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

public class AdderInt  {
    
    public let cself : CObject
    public let owner : Bool

    // internal main initializer
    internal required init(_ _cself: CObject, _ _owner: Bool = false) {
        self.cself = _cself
        self.owner = _owner
    }
    deinit {
        if owner {
            release_AdderInt(cself)
            cself.type?.deallocate()
        }
    }
    
    
    
    
    public static func add(a: Int, b: Int) -> Int {

        let swift_to_sc_a = CInt(a)
        let swift_to_sc_b = CInt(b)
        var err = ErrorObj()
        let result = _func_AdderInt_add(swift_to_sc_a, swift_to_sc_b, &err)
        let err_type = Int(err.err_type)
        if (err_type != 0) {
            switch(err_type) {
                case(1):
                    let exc_obj = StdException(CObject(type: nil, ptr: err.err_ptr), true)
                    ExceptionHandler.handleUncaughtException(exc_obj.what())
                default:
                    ExceptionHandler.handleUncaughtException("Uncaught Exception")
            }
        }
      let sc_to_swift_result = Int(result)
      return sc_to_swift_result
    }
}

public class AdderDouble  {
    
    public let cself : CObject
    public let owner : Bool

    // internal main initializer
    internal required init(_ _cself: CObject, _ _owner: Bool = false) {
        self.cself = _cself
        self.owner = _owner
    }
    deinit {
        if owner {
            release_AdderDouble(cself)
            cself.type?.deallocate()
        }
    }
    
    
    
    
    public static func add(a: Double, b: Double) -> Double {

        
        
        var err = ErrorObj()
        let result = _func_AdderDouble_add(a, b, &err)
        let err_type = Int(err.err_type)
        if (err_type != 0) {
            switch(err_type) {
                case(1):
                    let exc_obj = StdException(CObject(type: nil, ptr: err.err_ptr), true)
                    ExceptionHandler.handleUncaughtException(exc_obj.what())
                default:
                    ExceptionHandler.handleUncaughtException("Uncaught Exception")
            }
        }
      
      return result
    }
}

public enum color: CUnsignedInt {
    case RED = 0
    case GREEN = 1
    case BLUE = 2
}