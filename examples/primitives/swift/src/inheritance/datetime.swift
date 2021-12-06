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

public class DateTime: Date, Time {
  public convenience init(d: Int, mo: Int, y: Int, h: Int, mi: Int, s: Int) {
    let swiftToScD = CInt(d)
    let swiftToScMo = CInt(mo)
    let swiftToScY = CInt(y)
    let swiftToScH = CInt(h)
    let swiftToScMi = CInt(mi)
    let swiftToScS = CInt(s)
    var err = ErrorObj()
    self.init(create_DateTime(swiftToScD, swiftToScMo, swiftToScY, swiftToScH, swiftToScMi, swiftToScS, &err), true)
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

  public var datetime: String {
    get {
      let result = _prop_get_DateTime_datetime(cself)
      let scToSwiftResult = String(cString: result)
      defer {
        result.deallocate()
      }
      return scToSwiftResult
    }
  }

  public override func value() -> String {

    var err = ErrorObj()
    let result = _func_DateTime_value(cself, &err)
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
    let scToSwiftResult = String(cString: result)
    defer {
      result.deallocate()
    }
    return scToSwiftResult
  }

}
