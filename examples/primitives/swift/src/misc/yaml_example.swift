/**
 * ,--.,------. ,----.   ,------.,--.  ,--.
 * |  ||  .---''  .-.|   |  .---'|  ,'.|  |
 * |  ||  `--, |  | .---.|  `--, |  |' '  |
 * |  ||  `---.'  '--'  ||  `---.|  | `   |
 * `--'`------' `------' `------'`--'  `--'
 * 
 * This file is generated by iegen on 12/04/2021-11:54.
 * Please do not change it manually.
 */

import CWrapper
import Foundation

public class WithExternalAPIComments {

  public let cself: UnsafeMutableRawPointer
  public let owner: Bool

  // internal main initializer
  internal required init(_ _cself: UnsafeMutableRawPointer, _ _owner: Bool = false) {
    self.cself = _cself
    self.owner = _owner
  }

  deinit {
    if owner {
      release_WithExternalAPIComments(cself)
    }
  }

  public convenience init(s: String) {
    let swiftToScS = strdup(s)!
    self.init(create_WithExternalAPIComments(swiftToScS), true)
  }

  public var str: String {
    get {
      let result = _prop_get_WithExternalAPIComments_str(cself)
      let scToSwiftResult = String(cString: result)
      defer {
        result.deallocate()
      }
      return scToSwiftResult
    }

    set(value) {
      let swiftToScValue = strdup(value)!
      _prop_set_WithExternalAPIComments_str(cself, swiftToScValue)
    }
  }

  public static func retInt(n: Int) -> Int {

    let swiftToScN = CInt(n)
    var err = ErrorObj()
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
    let result = _func_WithExternalAPIComments_retInt(swiftToScN, &err)
    let scToSwiftResult = Int(result)
    return scToSwiftResult
  }

  public static func max(arg0: Int, arg1: Int) -> Int {

    let swiftToScArg0 = CInt(arg0)
    let swiftToScArg1 = CInt(arg1)
    var err = ErrorObj()
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
    let result = _func_WithExternalAPIComments_maxInt(swiftToScArg0, swiftToScArg1, &err)
    let scToSwiftResult = Int(result)
    return scToSwiftResult
  }

  public static func max(arg0: String, arg1: String) -> String {

    let swiftToScArg0 = strdup(arg0)!
    let swiftToScArg1 = strdup(arg1)!
    var err = ErrorObj()
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
    let result = _func_WithExternalAPIComments_maxString(swiftToScArg0, swiftToScArg1, &err)
    let scToSwiftResult = String(cString: result)
    defer {
      result.deallocate()
    }
    return scToSwiftResult
  }

}

public class AdderInt {

  public let cself: UnsafeMutableRawPointer
  public let owner: Bool

  // internal main initializer
  internal required init(_ _cself: UnsafeMutableRawPointer, _ _owner: Bool = false) {
    self.cself = _cself
    self.owner = _owner
  }

  deinit {
    if owner {
      release_AdderInt(cself)
    }
  }

  public static func add(a: Int, b: Int) -> Int {

    let swiftToScA = CInt(a)
    let swiftToScB = CInt(b)
    var err = ErrorObj()
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
    let result = _func_AdderInt_add(swiftToScA, swiftToScB, &err)
    let scToSwiftResult = Int(result)
    return scToSwiftResult
  }

}

public class AdderDouble {

  public let cself: UnsafeMutableRawPointer
  public let owner: Bool

  // internal main initializer
  internal required init(_ _cself: UnsafeMutableRawPointer, _ _owner: Bool = false) {
    self.cself = _cself
    self.owner = _owner
  }

  deinit {
    if owner {
      release_AdderDouble(cself)
    }
  }

  public static func add(a: Double, b: Double) -> Double {

    var err = ErrorObj()
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
    let result = _func_AdderDouble_add(a, b, &err)
    return result
  }

}

public enum color: CUnsignedInt {
  case RED = 0
  case GREEN = 1
  case BLUE = 2
}
