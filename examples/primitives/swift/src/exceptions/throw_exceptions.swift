/**
 *   ______ .______   .______   .______    __  .__   __.  _______  
 *  /      ||   _  \  |   _  \  |   _  \  |  | |  \ |  | |       \ 
 * |  ,----'|  |_)  | |  |_)  | |  |_)  | |  | |   \|  | |  .--.  |
 * |  |     |   ___/  |   ___/  |   _  <  |  | |  . `  | |  |  |  |
 * |  `----.|  |      |  |      |  |_)  | |  | |  |\   | |  '--'  |
 *  \______|| _|      | _|      |______/  |__| |__| \__| |_______/ 
 * 
 * This file is generated by cppbind on 06/02/2022-11:50.
 * Please do not change it manually.
 */

import CWrapper
import Foundation

/**
 * An example of a global function throwing an exception.
 */
public func throwExc(doThrow: Bool = false) throws -> Void {
  var cppbindErr = CppBindCObject()
  _func_CppbindExceptions_throwExc(doThrow, &cppbindErr)
  if cppbindErr.type != nil {
    let errorType = String(cString: cppbindErr.type!)
    switch errorType {
    case ("std::invalid_argument"):
      throw StdInvalidArgument(cppbindErr, true)
    case ("std::exception"):
      let excObj = StdException(cppbindErr, true)
      ExceptionHandler.handleUncaughtException(excObj.what())
    default:
      cppbindErr.type.deallocate()
      ExceptionHandler.handleUncaughtException("Uncaught Exception")
    }
  }
}

public class ThrowExc {

  /**
   * An internal property to keep a reference to the original C++ object.
   * It is intended to be used by the generated code.
   */
  public let cself: CppBindCObject

  /**
   * An internal property to keep track whether Swift is responsible for deallocating the underlying C++ object or not.
   * It is intended to be used by the generated code.
   */
  public let owner: Bool
  private var refs: [Any]

  /// internal main initializer
  internal required init(_ _cself: CppBindCObject, _ _owner: Bool = false) {
    self.cself = _cself
    self.owner = _owner
    self.refs = []
  }

  deinit {
    release_CppbindExceptions_ThrowExc(cself, owner)
  }

  /**
   * An internal method to bind the lifetimes of the current and another object.
   * It is intended to be used by the generated code.
   */
  public func keepCppBindReference(_ object: Any) {
    self.refs.append(object)
  }

  public convenience init(doThrow: Bool = false) throws {
    var cppbindErr = CppBindCObject()
    self.init(create_CppbindExceptions_ThrowExc(doThrow, &cppbindErr), true)
    if cppbindErr.type != nil {
      let errorType = String(cString: cppbindErr.type!)
      switch errorType {
      case ("std::invalid_argument"):
        throw StdInvalidArgument(cppbindErr, true)
      case ("std::exception"):
        let excObj = StdException(cppbindErr, true)
        ExceptionHandler.handleUncaughtException(excObj.what())
      default:
        cppbindErr.type.deallocate()
        ExceptionHandler.handleUncaughtException("Uncaught Exception")
      }
    }
  }

  /**
   * An example to check swift throwing property getter
   */
  public var prop1: String {
    get {
      var cppbindErr = CppBindCObject()
      let result = _prop_get_CppbindExceptions_ThrowExc_prop1(cself, &cppbindErr)
      if cppbindErr.type != nil {
        let errorType = String(cString: cppbindErr.type!)
        switch errorType {
        case ("std::exception"):
          let excObj = StdException(cppbindErr, true)
          ExceptionHandler.handleUncaughtException(excObj.what())
        default:
          cppbindErr.type.deallocate()
          ExceptionHandler.handleUncaughtException("Uncaught Exception")
        }
      }
      let sctoswiftresult = String(cString: result)
      defer {
        result.deallocate()
      }
      return sctoswiftresult
    }

    set(value) {
      let swifttoscvalue = strdup(value)!
      var cppbindErr = CppBindCObject()
      _prop_set_CppbindExceptions_ThrowExc_prop1(cself, swifttoscvalue, &cppbindErr)
      if cppbindErr.type != nil {
        let errorType = String(cString: cppbindErr.type!)
        switch errorType {
        case ("std::exception"):
          let excObj = StdException(cppbindErr, true)
          ExceptionHandler.handleUncaughtException(excObj.what())
        default:
          cppbindErr.type.deallocate()
          ExceptionHandler.handleUncaughtException("Uncaught Exception")
        }
      }
    }
  }

  public static func getByKey(m: Dictionary<Int, Int>, key: Int) throws -> Int {

    let _swifttoscmKey = UnsafeMutablePointer<CInt>.allocate(
      capacity: m.count)
    let _swifttoscmVal = UnsafeMutablePointer<CInt>.allocate(
      capacity: m.count)
    var swifttoscm = CppBindCDataMap()
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
    var cppbindErr = CppBindCObject()
    let result = _func_CppbindExceptions_ThrowExc_getByKey(swifttoscm, swifttosckey, &cppbindErr)
    
    swifttoscm.keys.deallocate()
    swifttoscm.values.deallocate()
    if cppbindErr.type != nil {
      let errorType = String(cString: cppbindErr.type!)
      switch errorType {
      case ("std::out_of_range"):
        throw StdOutOfRange(cppbindErr, true)
      case ("cppbind::example::SystemError"):
        throw SystemError(cppbindErr, true)
      case ("std::exception"):
        let excObj = StdException(cppbindErr, true)
        ExceptionHandler.handleUncaughtException(excObj.what())
      default:
        cppbindErr.type.deallocate()
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

    var cppbindErr = CppBindCObject()
    let result = _func_CppbindExceptions_ThrowExc_throwsWithReturnValueString(&cppbindErr)
    if cppbindErr.type != nil {
      let errorType = String(cString: cppbindErr.type!)
      switch errorType {
      case ("std::invalid_argument"):
        throw StdInvalidArgument(cppbindErr, true)
      case ("std::exception"):
        let excObj = StdException(cppbindErr, true)
        ExceptionHandler.handleUncaughtException(excObj.what())
      default:
        cppbindErr.type.deallocate()
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
   * Throws exception with return value of cppbind type.
   */
  public static func throwsWithReturnValuePtr() throws -> Task {

    var cppbindErr = CppBindCObject()
    let result = _func_CppbindExceptions_ThrowExc_throwsWithReturnValuePtr(&cppbindErr)
    if cppbindErr.type != nil {
      let errorType = String(cString: cppbindErr.type!)
      switch errorType {
      case ("std::invalid_argument"):
        throw StdInvalidArgument(cppbindErr, true)
      case ("std::exception"):
        let excObj = StdException(cppbindErr, true)
        ExceptionHandler.handleUncaughtException(excObj.what())
      default:
        cppbindErr.type.deallocate()
        ExceptionHandler.handleUncaughtException("Uncaught Exception")
      }
    }
    var sctoswiftresult: Task
    sctoswiftresult = Task(result, true)
    return sctoswiftresult
  }

  /**
   * An internal property to keep an information about the underlying C++ object type.
   * It is intended to be used by the generated code.
   */
  class var cppbindCxxTypeName : String { return "cppbind::exceptions::ThrowExc" }
}
