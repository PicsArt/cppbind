/**
 * ,--.,------. ,----.   ,------.,--.  ,--. 
 * |  ||  .---''  .-.|   |  .---'|  ,'.|  | 
 * |  ||  `--, |  | .---.|  `--, |  |' '  | 
 * |  ||  `---.'  '--'  ||  `---.|  | `   | 
 * `--'`------' `------' `------'`--'  `--' 
 * 
 * This file is generated by iegen on 02/17/2022-13:51.
 * Please do not change it manually.
 */

import CWrapper
import Foundation

public class NumberInt {

  public let cself: IEGenCObject
  public let owner: Bool
  private var refs: [AnyObject]

  // internal main initializer
  internal required init(_ _cself: IEGenCObject, _ _owner: Bool = false) {
    self.cself = _cself
    self.owner = _owner
    self.refs = []
  }

  deinit {
    release_NumberInt(cself, owner)
  }

  public func keepIEGenReference(_ object: AnyObject) {
    self.refs.append(object)
  }

  public convenience init(n: Int) {
    let swifttoscn = CInt(n)
    var err = IEGenCObject()
    self.init(create_NumberInt(swifttoscn, &err), true)
    if err.type != nil {
      let errorType = String(cString: err.type!)
      switch errorType {
      case ("std::exception"):
        let excObj = StdException(err, true)
        ExceptionHandler.handleUncaughtException(excObj.what())
      default:
        err.type.deallocate()
        ExceptionHandler.handleUncaughtException("Uncaught Exception")
      }
    }
  }

  public var num: Int {
    get {
      let result = _prop_get_NumberInt_num(cself)
      let sctoswiftresult = Int(result)
      return sctoswiftresult
    }

    set(value) {
      let swifttoscvalue = CInt(value)
      _prop_set_NumberInt_num(cself, swifttoscvalue)
    }
  }

  public func toInt() -> Int {

    var err = IEGenCObject()
    let result = _func_NumberInt_toInt(cself, &err)
    if err.type != nil {
      let errorType = String(cString: err.type!)
      switch errorType {
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

}

public class NumberDouble {

  public let cself: IEGenCObject
  public let owner: Bool
  private var refs: [AnyObject]

  // internal main initializer
  internal required init(_ _cself: IEGenCObject, _ _owner: Bool = false) {
    self.cself = _cself
    self.owner = _owner
    self.refs = []
  }

  deinit {
    release_NumberDouble(cself, owner)
  }

  public func keepIEGenReference(_ object: AnyObject) {
    self.refs.append(object)
  }

  public convenience init(n: Double) {
    var err = IEGenCObject()
    self.init(create_NumberDouble(n, &err), true)
    if err.type != nil {
      let errorType = String(cString: err.type!)
      switch errorType {
      case ("std::exception"):
        let excObj = StdException(err, true)
        ExceptionHandler.handleUncaughtException(excObj.what())
      default:
        err.type.deallocate()
        ExceptionHandler.handleUncaughtException("Uncaught Exception")
      }
    }
  }

  public var num: Double {
    get {
      let result = _prop_get_NumberDouble_num(cself)
      return result
    }

    set(value) {
      _prop_set_NumberDouble_num(cself, value)
    }
  }

  public func toInt() -> Int {

    var err = IEGenCObject()
    let result = _func_NumberDouble_toInt(cself, &err)
    if err.type != nil {
      let errorType = String(cString: err.type!)
      switch errorType {
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

}
