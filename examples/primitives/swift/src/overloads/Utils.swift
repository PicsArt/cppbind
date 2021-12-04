/**
 * ,--.,------. ,----.   ,------.,--.  ,--.
 * |  ||  .---''  .-.|   |  .---'|  ,'.|  |
 * |  ||  `--, |  | .---.|  `--, |  |' '  |
 * |  ||  `---.'  '--'  ||  `---.|  | `   |
 * `--'`------' `------' `------'`--'  `--'
 * 
 * This file is generated by iegen on 12/04/2021-19:30.
 * Please do not change it manually.
 */

import CWrapper
import Foundation

/**
 * An example with overloaded methods.
 */
public class Utils {

  public let cself: UnsafeMutableRawPointer
  public let owner: Bool

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

    let swiftToScFirst = CInt(first)
    let swiftToScSecond = CInt(second)
    var err = ErrorObj()
    let result = _func_Utils_sum(swiftToScFirst, swiftToScSecond, &err)
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
    let scToSwiftResult = Int(result)
    return scToSwiftResult
  }

  /**
   * Sum two floats.
   */
  public static func sum(first: Float, second: Float) -> Float {

    var err = ErrorObj()
    let result = _func_Utils_sum_1(first, second, &err)
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
    return result
  }

  /**
   * Concatenate with two strings.
   */
  public func concatenate(first: String, second: String) -> String {

    let swiftToScFirst = strdup(first)!
    let swiftToScSecond = strdup(second)!
    var err = ErrorObj()
    let result = _func_Utils_concatenate(cself, swiftToScFirst, swiftToScSecond, &err)
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

  /**
   * Concatenate with three strings.
   */
  public func concatenate(first: String, second: String, third: String) -> String {

    let swiftToScFirst = strdup(first)!
    let swiftToScSecond = strdup(second)!
    let swiftToScThird = strdup(third)!
    var err = ErrorObj()
    let result = _func_Utils_concatenate_1(cself, swiftToScFirst, swiftToScSecond, swiftToScThird, &err)
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
