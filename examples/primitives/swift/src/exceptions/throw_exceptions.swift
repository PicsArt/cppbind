/**
 * ,--.,------. ,----.   ,------.,--.  ,--. 
 * |  ||  .---''  .-.|   |  .---'|  ,'.|  | 
 * |  ||  `--, |  | .---.|  `--, |  |' '  | 
 * |  ||  `---.'  '--'  ||  `---.|  | `   | 
 * `--'`------' `------' `------'`--'  `--' 
 * 
 * This file is generated by iegen on 12/22/2021-07:14.
 * Please do not change it manually.
 */

import CWrapper
import Foundation

/**
 * An example of a global function throwing an exception.
 */
public func throwExc(doThrow: Bool = false) throws -> Void {
  var err = ErrorObj()
  _func_IegenExceptions_throwExc(doThrow, &err)
  let errorType = Int(err.err_type)
  if errorType != 0 {
    switch errorType {
    case (1):
      throw StdInvalidArgument(CObject(type: strdup("std::invalid_argument"), ptr: err.err_ptr), true)
    case (2):
      let excObj = StdException(CObject(type: strdup("std::exception"), ptr: err.err_ptr), true)
      ExceptionHandler.handleUncaughtException(excObj.what())
    default:
      ExceptionHandler.handleUncaughtException("Uncaught Exception")
    }
  }
}

public class ThrowExc {

  public let cself: CObject
  public let owner: Bool

  // internal main initializer
  internal required init(_ _cself: CObject, _ _owner: Bool = false) {
    self.cself = _cself
    self.owner = _owner
  }

  deinit {
    release_ThrowExc(cself, owner)
  }

  public convenience init(doThrow: Bool = false) throws {
    var err = ErrorObj()
    self.init(create_ThrowExc(doThrow, &err), true)
    let errorType = Int(err.err_type)
    if errorType != 0 {
      switch errorType {
      case (1):
        throw StdInvalidArgument(CObject(type: strdup("std::invalid_argument"), ptr: err.err_ptr), true)
      case (2):
        let excObj = StdException(CObject(type: strdup("std::exception"), ptr: err.err_ptr), true)
        ExceptionHandler.handleUncaughtException(excObj.what())
      default:
        ExceptionHandler.handleUncaughtException("Uncaught Exception")
      }
    }
  }

  public var prop: String {
    get {
      let result = _prop_get_ThrowExc_prop(cself)
      let sctoswiftresult = String(cString: result)
      defer {
        result.deallocate()
      }
      return sctoswiftresult
    }

    set(value) {
      let swifttoscvalue = strdup(value)!
      _prop_set_ThrowExc_prop(cself, swifttoscvalue)
    }
  }

  public static func getByKey(m: Dictionary<Int, Int>, key: Int) throws -> Int {

    let _swifttoscmKey = UnsafeMutablePointer<CInt>.allocate(
      capacity: m.count)
    let _swifttoscmVal = UnsafeMutablePointer<CInt>.allocate(
      capacity: m.count)
    var swifttoscm = CDataMap()
    swifttoscm.keys = UnsafeMutableRawPointer(_swifttoscmKey)
    swifttoscm.values = UnsafeMutableRawPointer(_swifttoscmVal)
    swifttoscm.size = Int64(m.count)
    var mIdx = 0
    for (mKey, mVal) in m {
      let swifttoscmKey = CInt(mKey)
      let swifttoscmVal = CInt(mVal)
      _swifttoscmKey[mIdx] = swifttoscmKey
      _swifttoscmVal[mIdx] = swifttoscmVal
      mIdx += 1
    }
    let swifttosckey = CInt(key)
    var err = ErrorObj()
    let result = _func_ThrowExc_getByKey(swifttoscm, swifttosckey, &err)
    
    swifttoscm.keys.deallocate()
    swifttoscm.values.deallocate()
    let errorType = Int(err.err_type)
    if errorType != 0 {
      switch errorType {
      case (1):
        throw StdOutOfRange(CObject(type: strdup("std::out_of_range"), ptr: err.err_ptr), true)
      case (2):
        throw SystemError(CObject(type: strdup("iegen::example::SystemError"), ptr: err.err_ptr), true)
      case (3):
        let excObj = StdException(CObject(type: strdup("std::exception"), ptr: err.err_ptr), true)
        ExceptionHandler.handleUncaughtException(excObj.what())
      default:
        ExceptionHandler.handleUncaughtException("Uncaught Exception")
      }
    }
    let sctoswiftresult = Int(result)
    return sctoswiftresult
  }

  /**
   * Throws exception with return value of type string.
   */
  public static func throwsWithReturnValueString() throws -> String {

    var err = ErrorObj()
    let result = _func_ThrowExc_throwsWithReturnValueString(&err)
    let errorType = Int(err.err_type)
    if errorType != 0 {
      switch errorType {
      case (1):
        throw StdInvalidArgument(CObject(type: strdup("std::invalid_argument"), ptr: err.err_ptr), true)
      case (2):
        let excObj = StdException(CObject(type: strdup("std::exception"), ptr: err.err_ptr), true)
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
   * Throws exception with return value of iegen type.
   */
  public static func throwsWithReturnValuePtr() throws -> Task {

    var err = ErrorObj()
    let result = _func_ThrowExc_throwsWithReturnValuePtr(&err)
    let errorType = Int(err.err_type)
    if errorType != 0 {
      switch errorType {
      case (1):
        throw StdInvalidArgument(CObject(type: strdup("std::invalid_argument"), ptr: err.err_ptr), true)
      case (2):
        let excObj = StdException(CObject(type: strdup("std::exception"), ptr: err.err_ptr), true)
        ExceptionHandler.handleUncaughtException(excObj.what())
      default:
        ExceptionHandler.handleUncaughtException("Uncaught Exception")
      }
    }
    var sctoswiftresult: Task
    sctoswiftresult = Task(result)
    return sctoswiftresult
  }

}
