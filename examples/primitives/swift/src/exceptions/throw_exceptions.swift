/**
 * ,--.,------. ,----.   ,------.,--.  ,--. 
 * |  ||  .---''  .-.|   |  .---'|  ,'.|  | 
 * |  ||  `--, |  | .---.|  `--, |  |' '  | 
 * |  ||  `---.'  '--'  ||  `---.|  | `   | 
 * `--'`------' `------' `------'`--'  `--' 
 * 
 * This file is generated by iegen on 02/04/2022-14:10.
 * Please do not change it manually.
 */

import CWrapper
import Foundation

/**
 * An example of a global function throwing an exception.
 */
public func throwExc(doThrow: Bool = false) throws -> Void {
  var err = IEGenCObject()
  _func_IegenExceptions_throwExc(doThrow, &err)
  if err.type != nil {
    let errorType = String(cString: err.type!)
    switch errorType {
    case ("std::invalid_argument"):
      throw StdInvalidArgument(err, true)
    case ("std::exception"):
      let excObj = StdException(err, true)
      ExceptionHandler.handleUncaughtException(excObj.what())
    default:
      err.type.deallocate()
      ExceptionHandler.handleUncaughtException("Uncaught Exception")
    }
  }
}

public class ThrowExc {

  public let cself: IEGenCObject
  public let owner: Bool

  // internal main initializer
  internal required init(_ _cself: IEGenCObject, _ _owner: Bool = false) {
    self.cself = _cself
    self.owner = _owner
  }

  deinit {
    release_ThrowExc(cself, owner)
  }

  public convenience init(doThrow: Bool = false) throws {
    var err = IEGenCObject()
    self.init(create_ThrowExc(doThrow, &err), true)
    if err.type != nil {
      let errorType = String(cString: err.type!)
      switch errorType {
      case ("std::invalid_argument"):
        throw StdInvalidArgument(err, true)
      case ("std::exception"):
        let excObj = StdException(err, true)
        ExceptionHandler.handleUncaughtException(excObj.what())
      default:
        err.type.deallocate()
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
    var swifttoscm = IEGenCDataMap()
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
    var err = IEGenCObject()
    let result = _func_ThrowExc_getByKey(swifttoscm, swifttosckey, &err)
    
    swifttoscm.keys.deallocate()
    swifttoscm.values.deallocate()
    if err.type != nil {
      let errorType = String(cString: err.type!)
      switch errorType {
      case ("std::out_of_range"):
        throw StdOutOfRange(err, true)
      case ("iegen::example::SystemError"):
        throw SystemError(err, true)
      case ("std::exception"):
        let excObj = StdException(err, true)
        ExceptionHandler.handleUncaughtException(excObj.what())
      default:
        err.type.deallocate()
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

    var err = IEGenCObject()
    let result = _func_ThrowExc_throwsWithReturnValueString(&err)
    if err.type != nil {
      let errorType = String(cString: err.type!)
      switch errorType {
      case ("std::invalid_argument"):
        throw StdInvalidArgument(err, true)
      case ("std::exception"):
        let excObj = StdException(err, true)
        ExceptionHandler.handleUncaughtException(excObj.what())
      default:
        err.type.deallocate()
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

    var err = IEGenCObject()
    let result = _func_ThrowExc_throwsWithReturnValuePtr(&err)
    if err.type != nil {
      let errorType = String(cString: err.type!)
      switch errorType {
      case ("std::invalid_argument"):
        throw StdInvalidArgument(err, true)
      case ("std::exception"):
        let excObj = StdException(err, true)
        ExceptionHandler.handleUncaughtException(excObj.what())
      default:
        err.type.deallocate()
        ExceptionHandler.handleUncaughtException("Uncaught Exception")
      }
    }
    var sctoswiftresult: Task
    sctoswiftresult = Task(result)
    return sctoswiftresult
  }

}
