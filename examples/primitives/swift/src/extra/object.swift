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

/**
 * comments
 * 
 */
public class Object {

  public let cself: UnsafeMutableRawPointer
  public let owner: Bool

  // internal main initializer
  internal required init(_ _cself: UnsafeMutableRawPointer, _ _owner: Bool = false) {
    self.cself = _cself
    self.owner = _owner
  }

  deinit {
    if owner {
      release_Object(cself)
    }
  }

  /**
   * String representation for user readability
   * @return result of toReprString by default
   */
  public func toString() -> String {

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
    let result = _func_Object_toString(cself, &err)
    let scToSwiftResult = String(cString: result)
    defer {
      result.deallocate()
    }
    return scToSwiftResult
  }

  /**
   * Human readable class name
   * @return class name
   */
  public func className() -> String {

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
    let result = _func_Object_className(cself, &err)
    let scToSwiftResult = String(cString: result)
    defer {
      result.deallocate()
    }
    return scToSwiftResult
  }

  /**
   * Compare on equality two objects
   * @param other is the second one
   * @return is equals two objects
   */
  public func equals(other: Object) -> Bool {

    let swiftToScOther = other.cself
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
    let result = _func_Object_equals(cself, swiftToScOther, &err)
    return result
  }

  /**
   * Hash for object. Used in wrappers (java, obj-c, python) to define the hash function
   * @return hash of the object
   */
  public func hash() -> CUnsignedLong {

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
    let result = _func_Object_hash(cself, &err)
    return result
  }

  /**
   * Detailed string representation only for debug porpoises
   * @return object state as string
   */
  public func debugInfo() -> String {

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
    let result = _func_Object_debugInfo(cself, &err)
    let scToSwiftResult = String(cString: result)
    defer {
      result.deallocate()
    }
    return scToSwiftResult
  }

  /**
   * The object's size in bytes
   * @return bytes count
   */
  public func bytesCount() -> CUnsignedLong {

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
    let result = _func_Object_bytesCount(cself, &err)
    return result
  }

}
