/**
 * ,--.,------. ,----.   ,------.,--.  ,--.
 * |  ||  .---''  .-.|   |  .---'|  ,'.|  |
 * |  ||  `--, |  | .---.|  `--, |  |' '  |
 * |  ||  `---.'  '--'  ||  `---.|  | `   |
 * `--'`------' `------' `------'`--'  `--'
 * 
 * This file is generated by iegen on 12/06/2021-09:36.
 * Please do not change it manually.
 */

import CWrapper
import Foundation

public class NoThrowExc {

  public let cself: UnsafeMutableRawPointer
  public let owner: Bool

  // internal main initializer
  internal required init(_ _cself: UnsafeMutableRawPointer, _ _owner: Bool = false) {
    self.cself = _cself
    self.owner = _owner
  }

  deinit {
    if owner {
      release_NoThrowExc(cself)
    }
  }

  public convenience init(doThrow: Bool = false) {
    var err = ErrorObj()
    self.init(create_NoThrowExc(doThrow, &err), true)
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

  public var prop: String {
    get {
      let result = _prop_get_NoThrowExc_prop(cself)
      let scToSwiftResult = String(cString: result)
      defer {
        result.deallocate()
      }
      return scToSwiftResult
    }

    set(value) {
      let swiftToScValue = strdup(value)!
      _prop_set_NoThrowExc_prop(cself, swiftToScValue)
    }
  }

  public static func noop() -> Void {

    var err = ErrorObj()
    _func_NoThrowExc_noop(&err)
    let errorType = Int(err.err_type)
    if errorType != 0 {
      switch errorType {
      case (1):
        let excObj = StdException(err.err_ptr, true)
        ExceptionHandler.handleUncaughtException(excObj.what())
      default:
        ExceptionHandler.handleUncaughtException("Uncaught Exception")
      }
    }
  }

}
