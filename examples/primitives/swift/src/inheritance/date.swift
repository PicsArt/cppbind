/**
 * ,--.,------. ,----.   ,------.,--.  ,--.
 * |  ||  .---''  .-.|   |  .---'|  ,'.|  |
 * |  ||  `--, |  | .---.|  `--, |  |' '  |
 * |  ||  `---.'  '--'  ||  `---.|  | `   |
 * `--'`------' `------' `------'`--'  `--'
 * 
 * This file is generated by iegen on 11/12/2021-15:17.
 * Please do not change it manually.
 */

import CWrapper
import Foundation

public class Date: Base {

  public let cself: UnsafeMutableRawPointer
  public let owner: Bool

  // internal main initializer
  internal required init(_ _cself: UnsafeMutableRawPointer, _ _owner: Bool = false) {
    self.cself = _cself
    self.owner = _owner
  }

  deinit {
    if owner {
      release_Date(cself)
    }
  }

  public convenience init(d: Int, m: Int, y: Int) {
    let swiftToScD = CInt(d)
    let swiftToScM = CInt(m)
    let swiftToScY = CInt(y)
    self.init(create_Date(swiftToScD, swiftToScM, swiftToScY), true)
  }

  public var date: String {
    get {
      let result = _prop_get_Date_date(cself)
      let scToSwiftResult = String(cString: result)
      defer {
        result.deallocate()
      }
      return scToSwiftResult
    }
  }

  public func value() -> String {

    var err = ErrorObj()
    let result = _func_Date_value(cself, &err)
    let scToSwiftResult = String(cString: result)
    defer {
      result.deallocate()
    }
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
    return scToSwiftResult
  }

}
