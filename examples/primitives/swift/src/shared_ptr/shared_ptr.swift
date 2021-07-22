/**
 * ,--.,------. ,----.   ,------.,--.  ,--. 
 * |  ||  .---''  .-.|   |  .---'|  ,'.|  | 
 * |  ||  `--, |  | .---.|  `--, |  |' '  | 
 * |  ||  `---.'  '--'  ||  `---.|  | `   | 
 * `--'`------' `------' `------'`--'  `--' 
 * 
 * This file is generated by iegen on 07/21/2021-06:13.
 * Please do not change it manually.
 */

import Foundation
import CWrapper



/**
 * comments
 * 
 */
public class Car  {
    
    public let cself : UnsafeMutableRawPointer
    public let owner : Bool

    // internal main initializer
    internal required init(_ _cself: UnsafeMutableRawPointer, _ _owner: Bool = false) {
      self.cself = _cself
      self.owner = _owner
    }
    deinit {
      if owner {
        release_Car(cself)
      }
    }
    
    /**
     * comments
     * 
     */
    public convenience init(cost: Int) {

        let swift_to_sc_cost = CInt(cost)
        self.init(create_Car(swift_to_sc_cost), true)
    }
    
    /**
     * value getter
     */
    public var cost: Int {
          get {
            let result = _prop_get_Car_cost(cself);
            let sc_to_swift_result = Int(result)
            return sc_to_swift_result
          }
          
    }
    /**
     * comments
     * 
     */
    public func setCostWithCarSharedPtr(sp: Car) -> Void {

        let swift_to_sc_sp = sp.cself
        var err = ErrorObj()
        _func_Car_setCostWithCarSharedPtr(cself, swift_to_sc_sp, &err);
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
    /**
     * comments
     * 
     */
    public func getNewCarSharedPtr() -> Car {

        var err = ErrorObj()
        let result = _func_Car_getNewCarSharedPtr(cself, &err);
        let sc_to_swift_result = Car(result, true)
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