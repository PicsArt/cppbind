/**
 * ,--.,------. ,----.   ,------.,--.  ,--. 
 * |  ||  .---''  .-.|   |  .---'|  ,'.|  | 
 * |  ||  `--, |  | .---.|  `--, |  |' '  | 
 * |  ||  `---.'  '--'  ||  `---.|  | `   | 
 * `--'`------' `------' `------'`--'  `--' 
 * 
 * This file is generated by iegen on 12/08/2021-09:10.
 * Please do not change it manually.
 */

import CWrapper
import Foundation

public class Integer {

  public let cself: UnsafeMutableRawPointer
  public let owner: Bool

  // internal main initializer
  internal required init(_ _cself: UnsafeMutableRawPointer, _ _owner: Bool = false) {
    self.cself = _cself
    self.owner = _owner
  }

  deinit {
    if owner {
      release_Integer(cself)
    }
  }

  public convenience init(n: Int) {
    let swifttoscn = CInt(n)
    var err = ErrorObj()
    self.init(create_Integer(swifttoscn, &err), true)
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

  /**
   * value getter
   */
  public var value: Int {
    get {
      let result = _prop_get_Integer_value(cself)
      let sctoswiftresult = Int(result)
      return sctoswiftresult
    }
  }

}

public class MiscExc {

  public let cself: UnsafeMutableRawPointer
  public let owner: Bool

  // internal main initializer
  internal required init(_ _cself: UnsafeMutableRawPointer, _ _owner: Bool = false) {
    self.cself = _cself
    self.owner = _owner
  }

  deinit {
    if owner {
      release_MiscExc(cself)
    }
  }

  public static func returnInteger(doThrow: Bool) throws -> Integer {

    var err = ErrorObj()
    let result = _func_MiscExc_returnInteger(doThrow, &err)
    let errorType = Int(err.err_type)
    if errorType != 0 {
      switch errorType {
      case (1):
        throw StdOutOfRange(err.err_ptr, true)
      case (2):
        let excObj = StdException(err.err_ptr, true)
        ExceptionHandler.handleUncaughtException(excObj.what())
      default:
        ExceptionHandler.handleUncaughtException("Uncaught Exception")
      }
    }
    let sctoswiftresult = Integer(result)
    return sctoswiftresult
  }

  public static func raiseErrorByType(errType: String) throws -> Void {

    let swifttoscerrType = strdup(errType)!
    var err = ErrorObj()
    _func_MiscExc_raiseErrorByType(swifttoscerrType, &err)
    let errorType = Int(err.err_type)
    if errorType != 0 {
      switch errorType {
      case (1):
        throw StdRuntimeError(err.err_ptr, true)
      case (2):
        throw FileError(err.err_ptr, true)
      case (3):
        throw SystemError(err.err_ptr, true)
      case (4):
        throw SimpleChildException(err.err_ptr, true)
      case (5):
        throw SimpleBaseException(err.err_ptr, true)
      case (6):
        throw StdException(err.err_ptr, true)
      default:
        ExceptionHandler.handleUncaughtException("Uncaught Exception")
      }
    }
  }

}
