/**
 *   ______ .______   .______   .______    __  .__   __.  _______  
 *  /      ||   _  \  |   _  \  |   _  \  |  | |  \ |  | |       \ 
 * |  ,----'|  |_)  | |  |_)  | |  |_)  | |  | |   \|  | |  .--.  |
 * |  |     |   ___/  |   ___/  |   _  <  |  | |  . `  | |  |  |  |
 * |  `----.|  |      |  |      |  |_)  | |  | |  |\   | |  '--'  |
 *  \______|| _|      | _|      |______/  |__| |__| \__| |_______/ 
 * 
 * This file is generated by cppbind on 06/02/2022-11:51.
 * Please do not change it manually.
 */

import CWrapper
import Foundation

public class NumInt {

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
    release_CppbindExampleNullable_NumInt(cself, owner)
  }

  /**
   * An internal method to bind the lifetimes of the current and another object.
   * It is intended to be used by the generated code.
   */
  public func keepCppBindReference(_ object: Any) {
    self.refs.append(object)
  }

  public convenience init(val: Int) {
    let swifttoscval = CInt(val)
    var cppbindErr = CppBindCObject()
    self.init(create_CppbindExampleNullable_NumInt(swifttoscval, &cppbindErr), true)
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

  public var value: Int {
    let result = _prop_get_CppbindExampleNullable_NumInt_value(cself)
    let sctoswiftresult = Int(result)
    return sctoswiftresult
  }

  /**
   * An internal property to keep an information about the underlying C++ object type.
   * It is intended to be used by the generated code.
   */
  class var cppbindCxxTypeName : String { return "cppbind::example::nullable::NumberInt" }
}

public class NumDouble {

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
    release_CppbindExampleNullable_NumDouble(cself, owner)
  }

  /**
   * An internal method to bind the lifetimes of the current and another object.
   * It is intended to be used by the generated code.
   */
  public func keepCppBindReference(_ object: Any) {
    self.refs.append(object)
  }

  public convenience init(val: Double) {
    var cppbindErr = CppBindCObject()
    self.init(create_CppbindExampleNullable_NumDouble(val, &cppbindErr), true)
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

  public var value: Double {
    let result = _prop_get_CppbindExampleNullable_NumDouble_value(cself)
    return result
  }

  /**
   * An internal property to keep an information about the underlying C++ object type.
   * It is intended to be used by the generated code.
   */
  class var cppbindCxxTypeName : String { return "cppbind::example::nullable::NumberDouble" }
}

/**
 * An example with nullable arguments.
 */
public class NullableUtils {

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
    release_CppbindExampleNullable_NullableUtils(cself, owner)
  }

  /**
   * An internal method to bind the lifetimes of the current and another object.
   * It is intended to be used by the generated code.
   */
  public func keepCppBindReference(_ object: Any) {
    self.refs.append(object)
  }

  public convenience init(num: NumDouble?) {
    let swifttoscnum = num?.cself ?? CppBindCObject(type: nil, ptr: nil)
    var cppbindErr = CppBindCObject()
    self.init(create_CppbindExampleNullable_NullableUtils(swifttoscnum, &cppbindErr), true)
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

  public var nullable: NumDouble? {
    get {
      var cppbindErr = CppBindCObject()
      let result = _prop_get_CppbindExampleNullable_NullableUtils_nullable(cself, &cppbindErr)
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
      var sctoswiftresult: NumDouble? = nil
      if (result.ptr != nil) {
        sctoswiftresult = NumDouble(result)
      }
      return sctoswiftresult
    }

    set(value) {
      let swifttoscvalue = value?.cself ?? CppBindCObject(type: nil, ptr: nil)
      var cppbindErr = CppBindCObject()
      _prop_set_CppbindExampleNullable_NullableUtils_nullable(cself, swifttoscvalue, &cppbindErr)
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

  public var nonNull: NumDouble {
    get {
      var cppbindErr = CppBindCObject()
      let result = _prop_get_CppbindExampleNullable_NullableUtils_nonNull(cself, &cppbindErr)
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
      var sctoswiftresult: NumDouble
      sctoswiftresult = NumDouble(result)
      return sctoswiftresult
    }

    set(value) {
      let swifttoscvalue = value.cself
      var cppbindErr = CppBindCObject()
      _prop_set_CppbindExampleNullable_NullableUtils_nonNull(cself, swifttoscvalue, &cppbindErr)
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

  public var numDouble: NumDouble? {
    get {
      let result = _prop_get_CppbindExampleNullable_NullableUtils_numDouble(cself)
      var sctoswiftresult: NumDouble? = nil
      if (result.ptr != nil) {
        sctoswiftresult = NumDouble(result)
      }
      return sctoswiftresult
    }

    set(value) {
      let swifttoscvalue = value?.cself ?? CppBindCObject(type: nil, ptr: nil)
      _prop_set_CppbindExampleNullable_NullableUtils_numDouble(cself, swifttoscvalue)
    }
  }

  public var numInt: NumInt {
    get {
      let result = _prop_get_CppbindExampleNullable_NullableUtils_numInt(cself)
      var sctoswiftresult: NumInt
      sctoswiftresult = NumInt(result, true)
      return sctoswiftresult
    }

    set(value) {
      let swifttoscvalue = value.cself
      _prop_set_CppbindExampleNullable_NullableUtils_numInt(cself, swifttoscvalue)
    }
  }

  public static func max(first: NumDouble?, second: NumDouble) -> NumDouble? {

    let swifttoscfirst = first?.cself ?? CppBindCObject(type: nil, ptr: nil)
    let swifttoscsecond = second.cself
    var cppbindErr = CppBindCObject()
    let result = _func_CppbindExampleNullable_NullableUtils_max(swifttoscfirst, swifttoscsecond, &cppbindErr)
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
    var sctoswiftresult: NumDouble? = nil
    if (result.ptr != nil) {
      sctoswiftresult = NumDouble(result)
    }
    return sctoswiftresult
  }

  public static func max(first: NumInt?, second: NumInt?) -> NumInt? {

    let swifttoscfirst = first?.cself ?? CppBindCObject(type: nil, ptr: nil)
    let swifttoscsecond = second?.cself ?? CppBindCObject(type: nil, ptr: nil)
    var cppbindErr = CppBindCObject()
    let result = _func_CppbindExampleNullable_NullableUtils_max_1(swifttoscfirst, swifttoscsecond, &cppbindErr)
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
    var sctoswiftresult: NumInt? = nil
    if (result.ptr != nil) {
      sctoswiftresult = NumInt(result, true)
    }
    return sctoswiftresult
  }

  public static func checkNonnullArg(number: NumDouble) -> Void {

    let swifttoscnumber = number.cself
    var cppbindErr = CppBindCObject()
    _func_CppbindExampleNullable_NullableUtils_checkNonnullArg(swifttoscnumber, &cppbindErr)
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

  public static func checkNonnullReturn() -> NumDouble {

    var cppbindErr = CppBindCObject()
    let result = _func_CppbindExampleNullable_NullableUtils_checkNonnullReturn(&cppbindErr)
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
    var sctoswiftresult: NumDouble
    sctoswiftresult = NumDouble(result)
    return sctoswiftresult
  }

  /**
   * An internal property to keep an information about the underlying C++ object type.
   * It is intended to be used by the generated code.
   */
  class var cppbindCxxTypeName : String { return "cppbind::example::nullable::Utils" }
}

public func reverseString(s: String?) -> String? {
  let swifttoscs = s?.cString(using: String.Encoding.utf8)
  var cppbindErr = CppBindCObject()
  let result = _func_CppbindExampleNullable_reverseString(swifttoscs, &cppbindErr)
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
  let sctoswiftresult = result != nil ? String(cString: result!) : nil
  return sctoswiftresult
}
