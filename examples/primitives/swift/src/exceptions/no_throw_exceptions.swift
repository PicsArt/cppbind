/**
 * ,--.,------. ,----.   ,------.,--.  ,--. 
 * |  ||  .---''  .-.|   |  .---'|  ,'.|  | 
 * |  ||  `--, |  | .---.|  `--, |  |' '  | 
 * |  ||  `---.'  '--'  ||  `---.|  | `   | 
 * `--'`------' `------' `------'`--'  `--' 
 * 
 * This file is generated by iegen on 11/29/2021-14:24.
 * Please do not change it manually.
 */

import CWrapper
import Foundation

public class NoThrowExc  {
    
    public let cself : CDataObj
    public let owner : Bool

    // internal main initializer
    internal required init(_ _cself: CDataObj, _ _owner: Bool = false) {
        self.cself = _cself
        self.owner = _owner
    }
    deinit {
        if owner {
            release_NoThrowExc(cself)
        }
    }
    
    
    
    
    public static func noop() -> Void {

        var err = ErrorObj()
        _func_NoThrowExc_noop(&err)
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
    }
}