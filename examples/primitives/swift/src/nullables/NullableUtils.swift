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

public class NumInt {

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
    release_IegenExampleNullable_NumInt(cself, owner)
  }

  public func keepIEGenReference(_ object: Any) {
    self.refs.append(object)
  }

  public convenience init(val: Int) {
    let swifttoscval = CInt(val)
    var iegenErr = IEGenCObject()
    self.init(create_IegenExampleNullable_NumInt(swifttoscval, &iegenErr), true)
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

  public var value: Int {
    let result = _prop_get_IegenExampleNullable_NumInt_value(cself)
    let sctoswiftresult = Int(result)
    return sctoswiftresult
  }

}

public class NumDouble {

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
    release_IegenExampleNullable_NumDouble(cself, owner)
  }

  public func keepIEGenReference(_ object: Any) {
    self.refs.append(object)
  }

  public convenience init(val: Double) {
    var iegenErr = IEGenCObject()
    self.init(create_IegenExampleNullable_NumDouble(val, &iegenErr), true)
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

  public var value: Double {
    let result = _prop_get_IegenExampleNullable_NumDouble_value(cself)
    return result
  }

}

/**
 * An example with nullable arguments.
 */
public class NullableUtils {

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
    release_IegenExampleNullable_NullableUtils(cself, owner)
  }

  public func keepIEGenReference(_ object: Any) {
    self.refs.append(object)
  }

  public convenience init(num: NumDouble?) {
    let swifttoscnum = num?.cself ?? IEGenCObject(type: nil, ptr: nil)
    var iegenErr = IEGenCObject()
    self.init(create_IegenExampleNullable_NullableUtils(swifttoscnum, &iegenErr), true)
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

  public var nullable: NumDouble? {
    get {
      var iegenErr = IEGenCObject()
      let result = _prop_get_IegenExampleNullable_NullableUtils_nullable(cself, &iegenErr)
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
      var sctoswiftresult: NumDouble? = nil
      if (result.ptr != nil) {
        sctoswiftresult = NumDouble(result)
      }
      return sctoswiftresult
    }

    set(value) {
      let swifttoscvalue = value?.cself ?? IEGenCObject(type: nil, ptr: nil)
      var iegenErr = IEGenCObject()
      _prop_set_IegenExampleNullable_NullableUtils_nullable(cself, swifttoscvalue, &iegenErr)
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
  }

  public var nonNull: NumDouble {
    get {
      var iegenErr = IEGenCObject()
      let result = _prop_get_IegenExampleNullable_NullableUtils_nonNull(cself, &iegenErr)
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
      var sctoswiftresult: NumDouble
      sctoswiftresult = NumDouble(result)
      return sctoswiftresult
    }

    set(value) {
      let swifttoscvalue = value.cself
      var iegenErr = IEGenCObject()
      _prop_set_IegenExampleNullable_NullableUtils_nonNull(cself, swifttoscvalue, &iegenErr)
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
  }

  public var numDouble: NumDouble? {
    get {
      let result = _prop_get_IegenExampleNullable_NullableUtils_numDouble(cself)
      var sctoswiftresult: NumDouble? = nil
      if (result.ptr != nil) {
        sctoswiftresult = NumDouble(result)
      }
      return sctoswiftresult
    }

    set(value) {
      let swifttoscvalue = value?.cself ?? IEGenCObject(type: nil, ptr: nil)
      _prop_set_IegenExampleNullable_NullableUtils_numDouble(cself, swifttoscvalue)
    }
  }

  public var numInt: NumInt {
    get {
      let result = _prop_get_IegenExampleNullable_NullableUtils_numInt(cself)
      var sctoswiftresult: NumInt
      sctoswiftresult = NumInt(result, true)
      return sctoswiftresult
    }

    set(value) {
      let swifttoscvalue = value.cself
      _prop_set_IegenExampleNullable_NullableUtils_numInt(cself, swifttoscvalue)
    }
  }

  public static func max(first: NumDouble?, second: NumDouble) -> NumDouble? {

    let swifttoscfirst = first?.cself ?? IEGenCObject(type: nil, ptr: nil)
    let swifttoscsecond = second.cself
    var iegenErr = IEGenCObject()
    let result = _func_IegenExampleNullable_NullableUtils_max(swifttoscfirst, swifttoscsecond, &iegenErr)
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
    var sctoswiftresult: NumDouble? = nil
    if (result.ptr != nil) {
      sctoswiftresult = NumDouble(result)
    }
    return sctoswiftresult
  }

  public static func max(first: NumInt?, second: NumInt?) -> NumInt? {

    let swifttoscfirst = first?.cself ?? IEGenCObject(type: nil, ptr: nil)
    let swifttoscsecond = second?.cself ?? IEGenCObject(type: nil, ptr: nil)
    var iegenErr = IEGenCObject()
    let result = _func_IegenExampleNullable_NullableUtils_max_1(swifttoscfirst, swifttoscsecond, &iegenErr)
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
    var sctoswiftresult: NumInt? = nil
    if (result.ptr != nil) {
      sctoswiftresult = NumInt(result, true)
    }
    return sctoswiftresult
  }

  public static func checkNonnullArg(number: NumDouble) -> Void {

    let swifttoscnumber = number.cself
    var iegenErr = IEGenCObject()
    _func_IegenExampleNullable_NullableUtils_checkNonnullArg(swifttoscnumber, &iegenErr)
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

  public static func checkNonnullReturn() -> NumDouble {

    var iegenErr = IEGenCObject()
    let result = _func_IegenExampleNullable_NullableUtils_checkNonnullReturn(&iegenErr)
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
    var sctoswiftresult: NumDouble
    sctoswiftresult = NumDouble(result)
    return sctoswiftresult
  }

}
