/**
 * ,--.,------. ,----.   ,------.,--.  ,--. 
 * |  ||  .---''  .-.|   |  .---'|  ,'.|  | 
 * |  ||  `--, |  | .---.|  `--, |  |' '  | 
 * |  ||  `---.'  '--'  ||  `---.|  | `   | 
 * `--'`------' `------' `------'`--'  `--' 
 * 
 * This file is generated by iegen on 01/31/2022-08:51.
 * Please do not change it manually.
 */

import CWrapper
import Foundation

/**
 * An example with overloaded methods.
 */
public class Utils {

  public let cself: IEGenCObject
  public let owner: Bool

  // internal main initializer
  internal required init(_ _cself: IEGenCObject, _ _owner: Bool = false) {
    self.cself = _cself
    self.owner = _owner
  }

  deinit {
    release_Utils(cself, owner)
  }

  public convenience init() {
    var err = IEGenCErrorObj()
    self.init(create_Utils(&err), true)
    let errorType = Int(err.err_type)
    if errorType != 0 {
      switch errorType {
      case (1):
        let excObj = StdException(IEGenCObject(type: strdup("std::exception"), ptr: err.err_ptr), true)
        ExceptionHandler.handleUncaughtException(excObj.what())
      default:
        ExceptionHandler.handleUncaughtException("Uncaught Exception")
      }
    }
  }

  /**
   * Sum two ints.
   */
  public static func sum(first: Int, second: Int) -> Int {

    let swifttoscfirst = CInt(first)
    let swifttoscsecond = CInt(second)
    var err = IEGenCErrorObj()
    let result = _func_Utils_sum(swifttoscfirst, swifttoscsecond, &err)
    let errorType = Int(err.err_type)
    if errorType != 0 {
      switch errorType {
      case (1):
        let excObj = StdException(IEGenCObject(type: strdup("std::exception"), ptr: err.err_ptr), true)
        ExceptionHandler.handleUncaughtException(excObj.what())
      default:
        ExceptionHandler.handleUncaughtException("Uncaught Exception")
      }
    }
    let sctoswiftresult = Int(result)
    return sctoswiftresult
  }

  /**
   * Sum two floats.
   */
  public static func sum(first: Float, second: Float) -> Float {

    var err = IEGenCErrorObj()
    let result = _func_Utils_sum_1(first, second, &err)
    let errorType = Int(err.err_type)
    if errorType != 0 {
      switch errorType {
      case (1):
        let excObj = StdException(IEGenCObject(type: strdup("std::exception"), ptr: err.err_ptr), true)
        ExceptionHandler.handleUncaughtException(excObj.what())
      default:
        ExceptionHandler.handleUncaughtException("Uncaught Exception")
      }
    }
    return result
  }

  /**
   * Concatenate with two strings.
   */
  public func concatenate(first: String, second: String) -> String {

    let swifttoscfirst = strdup(first)!
    let swifttoscsecond = strdup(second)!
    var err = IEGenCErrorObj()
    let result = _func_Utils_concatenate(cself, swifttoscfirst, swifttoscsecond, &err)
    let errorType = Int(err.err_type)
    if errorType != 0 {
      switch errorType {
      case (1):
        let excObj = StdException(IEGenCObject(type: strdup("std::exception"), ptr: err.err_ptr), true)
        ExceptionHandler.handleUncaughtException(excObj.what())
      default:
        ExceptionHandler.handleUncaughtException("Uncaught Exception")
      }
    }
    let sctoswiftresult = String(cString: result)
    defer {
      result.deallocate()
    }
    return sctoswiftresult
  }

  /**
   * Concatenate with three strings.
   */
  public func concatenate(first: String, second: String, third: String) -> String {

    let swifttoscfirst = strdup(first)!
    let swifttoscsecond = strdup(second)!
    let swifttoscthird = strdup(third)!
    var err = IEGenCErrorObj()
    let result = _func_Utils_concatenate_1(cself, swifttoscfirst, swifttoscsecond, swifttoscthird, &err)
    let errorType = Int(err.err_type)
    if errorType != 0 {
      switch errorType {
      case (1):
        let excObj = StdException(IEGenCObject(type: strdup("std::exception"), ptr: err.err_ptr), true)
        ExceptionHandler.handleUncaughtException(excObj.what())
      default:
        ExceptionHandler.handleUncaughtException("Uncaught Exception")
      }
    }
    let sctoswiftresult = String(cString: result)
    defer {
      result.deallocate()
    }
    return sctoswiftresult
  }

  /**
   * Sub two ints.
   */
  public static func minus(first: Int, second: Int) -> Int {

    let swifttoscfirst = CInt(first)
    let swifttoscsecond = CInt(second)
    var err = IEGenCErrorObj()
    let result = _func_Utils_minus(swifttoscfirst, swifttoscsecond, &err)
    let errorType = Int(err.err_type)
    if errorType != 0 {
      switch errorType {
      case (1):
        let excObj = StdException(IEGenCObject(type: strdup("std::exception"), ptr: err.err_ptr), true)
        ExceptionHandler.handleUncaughtException(excObj.what())
      default:
        ExceptionHandler.handleUncaughtException("Uncaught Exception")
      }
    }
    let sctoswiftresult = Int(result)
    return sctoswiftresult
  }

  /**
   * Sub two floats.
   */
  public static func minus(first: Float, second: Float) -> Float {

    var err = IEGenCErrorObj()
    let result = _func_Utils_minus_1(first, second, &err)
    let errorType = Int(err.err_type)
    if errorType != 0 {
      switch errorType {
      case (1):
        let excObj = StdException(IEGenCObject(type: strdup("std::exception"), ptr: err.err_ptr), true)
        ExceptionHandler.handleUncaughtException(excObj.what())
      default:
        ExceptionHandler.handleUncaughtException("Uncaught Exception")
      }
    }
    return result
  }

}
