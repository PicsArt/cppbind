/**
 * ,--.,------. ,----.   ,------.,--.  ,--. 
 * |  ||  .---''  .-.|   |  .---'|  ,'.|  | 
 * |  ||  `--, |  | .---.|  `--, |  |' '  | 
 * |  ||  `---.'  '--'  ||  `---.|  | `   | 
 * `--'`------' `------' `------'`--'  `--' 
 * 
 * This file is generated by iegen on 04/05/2022-18:55.
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
  private var refs: [Any]

  /// internal main initializer
  internal required init(_ _cself: IEGenCObject, _ _owner: Bool = false) {
    self.cself = _cself
    self.owner = _owner
    self.refs = []
  }

  deinit {
    release_IegenExample_Utils(cself, owner)
  }

  public func keepIEGenReference(_ object: Any) {
    self.refs.append(object)
  }

  public convenience init() {
    var iegenErr = IEGenCObject()
    self.init(create_IegenExample_Utils(&iegenErr), true)
    if iegenErr.type != nil {
      let errorType = String(cString: iegenErr.type!)
      switch errorType {
      case ("std::exception"):
        let excObj = StdException(iegenErr, true)
        ExceptionHandler.handleUncaughtException(excObj.what())
      default:
        iegenErr.type.deallocate()
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
    var iegenErr = IEGenCObject()
    let result = _func_IegenExample_Utils_sum(swifttoscfirst, swifttoscsecond, &iegenErr)
    if iegenErr.type != nil {
      let errorType = String(cString: iegenErr.type!)
      switch errorType {
      case ("std::exception"):
        let excObj = StdException(iegenErr, true)
        ExceptionHandler.handleUncaughtException(excObj.what())
      default:
        iegenErr.type.deallocate()
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

    var iegenErr = IEGenCObject()
    let result = _func_IegenExample_Utils_sum_1(first, second, &iegenErr)
    if iegenErr.type != nil {
      let errorType = String(cString: iegenErr.type!)
      switch errorType {
      case ("std::exception"):
        let excObj = StdException(iegenErr, true)
        ExceptionHandler.handleUncaughtException(excObj.what())
      default:
        iegenErr.type.deallocate()
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
    var iegenErr = IEGenCObject()
    let result = _func_IegenExample_Utils_concatenate(cself, swifttoscfirst, swifttoscsecond, &iegenErr)
    if iegenErr.type != nil {
      let errorType = String(cString: iegenErr.type!)
      switch errorType {
      case ("std::exception"):
        let excObj = StdException(iegenErr, true)
        ExceptionHandler.handleUncaughtException(excObj.what())
      default:
        iegenErr.type.deallocate()
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
    var iegenErr = IEGenCObject()
    let result = _func_IegenExample_Utils_concatenate_1(cself, swifttoscfirst, swifttoscsecond, swifttoscthird, &iegenErr)
    if iegenErr.type != nil {
      let errorType = String(cString: iegenErr.type!)
      switch errorType {
      case ("std::exception"):
        let excObj = StdException(iegenErr, true)
        ExceptionHandler.handleUncaughtException(excObj.what())
      default:
        iegenErr.type.deallocate()
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
    var iegenErr = IEGenCObject()
    let result = _func_IegenExample_Utils_minus(swifttoscfirst, swifttoscsecond, &iegenErr)
    if iegenErr.type != nil {
      let errorType = String(cString: iegenErr.type!)
      switch errorType {
      case ("std::exception"):
        let excObj = StdException(iegenErr, true)
        ExceptionHandler.handleUncaughtException(excObj.what())
      default:
        iegenErr.type.deallocate()
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

    var iegenErr = IEGenCObject()
    let result = _func_IegenExample_Utils_minus_1(first, second, &iegenErr)
    if iegenErr.type != nil {
      let errorType = String(cString: iegenErr.type!)
      switch errorType {
      case ("std::exception"):
        let excObj = StdException(iegenErr, true)
        ExceptionHandler.handleUncaughtException(excObj.what())
      default:
        iegenErr.type.deallocate()
        ExceptionHandler.handleUncaughtException("Uncaught Exception")
      }
    }
    return result
  }

}
