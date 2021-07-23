/**
 * ,--.,------. ,----.   ,------.,--.  ,--. 
 * |  ||  .---''  .-.|   |  .---'|  ,'.|  | 
 * |  ||  `--, |  | .---.|  `--, |  |' '  | 
 * |  ||  `---.'  '--'  ||  `---.|  | `   | 
 * `--'`------' `------' `------'`--'  `--' 
 * 
 * This file is generated by iegen on 07/22/2021-12:49.
 * Please do not change it manually.
 */

import Foundation
import CWrapper


/**
 * An example with overloaded methods.
 */
public class Utils  {
    
    public let cself : UnsafeMutableRawPointer
    public let owner : Bool

    // internal main initializer
    internal required init(_ _cself: UnsafeMutableRawPointer, _ _owner: Bool = false) {
      self.cself = _cself
      self.owner = _owner
    }
    deinit {
      if owner {
        release_Utils(cself)
      }
    }
    
    
    public convenience init() {

        self.init(create_Utils(), true)
    }
    
    /**
     * Sum two ints.
     */
    public static func sum(first: Int, second: Int) -> Int {

        let swift_to_sc_first = CInt(first)
        let swift_to_sc_second = CInt(second)
        var err = ErrorObj()
        let result = _func_Utils_sum(swift_to_sc_first, swift_to_sc_second, &err);
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
        return sc_to_swift_result;
    }
    /**
     * Sum two floats.
     */
    public static func sum(first: Float, second: Float) -> Float {

        
        
        var err = ErrorObj()
        let result = _func_Utils_sum_1(first, second, &err);
        
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
        return result;
    }
    /**
     * Concatenate with two strings.
     */
    public func concatenate(first: String, second: String) -> String {

        let swift_to_sc_first = strdup(first)!
        let swift_to_sc_second = strdup(second)!
        var err = ErrorObj()
        let result = _func_Utils_concatenate(cself, swift_to_sc_first, swift_to_sc_second, &err);
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
        return sc_to_swift_result;
    }
    /**
     * Concatenate with three strings.
     */
    public func concatenate(first: String, second: String, third: String) -> String {

        let swift_to_sc_first = strdup(first)!
        let swift_to_sc_second = strdup(second)!
        let swift_to_sc_third = strdup(third)!
        var err = ErrorObj()
        let result = _func_Utils_concatenate_1(cself, swift_to_sc_first, swift_to_sc_second, swift_to_sc_third, &err);
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
        return sc_to_swift_result;
    }
}