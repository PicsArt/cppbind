/**
 * ,--.,------. ,----.   ,------.,--.  ,--. 
 * |  ||  .---''  .-.|   |  .---'|  ,'.|  | 
 * |  ||  `--, |  | .---.|  `--, |  |' '  | 
 * |  ||  `---.'  '--'  ||  `---.|  | `   | 
 * `--'`------' `------' `------'`--'  `--' 
 * 
 * This file is generated by iegen on 11/29/2021-14:22.
 * Please do not change it manually.
 */

import CWrapper
import Foundation

public class MyCar  {
    
    public let cself : CDataObj
    public let owner : Bool

    // internal main initializer
    internal required init(_ _cself: CDataObj, _ _owner: Bool = false) {
        self.cself = _cself
        self.owner = _owner
    }
    deinit {
        if owner {
            release_MyCar(cself)
        }
    }
    
    
    public convenience init(numberOfSeats: Int) {

        let swift_to_sc_numberOfSeats = CInt(numberOfSeats)
        self.init(create_MyCar(swift_to_sc_numberOfSeats), true)
    }
    
    
    public func type() -> String {

        var err = ErrorObj()
        let result = _func_MyCar_type(cself, &err)
        let err_type = Int(err.err_type)
        if (err_type != 0) {
            switch(err_type) {
                case(1):
                    let exc_obj = StdException(CDataObj(index: 0, ptr: err.err_ptr), true)
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