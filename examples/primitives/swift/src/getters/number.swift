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

public class NumberInt {

  public let cself: UnsafeMutableRawPointer
  public let owner: Bool

  // internal main initializer
  internal required init(_ _cself: UnsafeMutableRawPointer, _ _owner: Bool = false) {
    self.cself = _cself
    self.owner = _owner
  }

  deinit {
    if owner {
      release_NumberInt(cself)
    }
  }

  public convenience init(n: Int) {
    let swiftToScN = CInt(n)
    self.init(create_NumberInt(swiftToScN), true)
  }

  public var num: Int {
    get {
      let result = _prop_get_NumberInt_num(cself)
      let scToSwiftResult = Int(result)
      return scToSwiftResult
    }

    set(value) {
      let swiftToScValue = CInt(value)
      _prop_set_NumberInt_num(cself, swiftToScValue)
    }
  }

  public func toInt() -> Int {

    var err = ErrorObj()
    let result = _func_NumberInt_toInt(cself, &err)
    let scToSwiftResult = Int(result)
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

public class NumberDouble {

  public let cself: UnsafeMutableRawPointer
  public let owner: Bool

  // internal main initializer
  internal required init(_ _cself: UnsafeMutableRawPointer, _ _owner: Bool = false) {
    self.cself = _cself
    self.owner = _owner
  }

  deinit {
    if owner {
      release_NumberDouble(cself)
    }
  }

  public convenience init(n: Double) {
    self.init(create_NumberDouble(n), true)
  }

  public var num: Double {
    get {
      let result = _prop_get_NumberDouble_num(cself)
      return result
    }

    set(value) {
      _prop_set_NumberDouble_num(cself, value)
    }
  }

  public func toInt() -> Int {

    var err = ErrorObj()
    let result = _func_NumberDouble_toInt(cself, &err)
    let scToSwiftResult = Int(result)
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
