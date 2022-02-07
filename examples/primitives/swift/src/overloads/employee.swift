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

public class Employee {

  public let cself: IEGenCObject
  public let owner: Bool

  // internal main initializer
  internal required init(_ _cself: IEGenCObject, _ _owner: Bool = false) {
    self.cself = _cself
    self.owner = _owner
  }

  deinit {
    release_Employee(cself, owner)
  }

  public convenience init(name: String) {
    let swifttoscname = strdup(name)!
    var err = IEGenCObject()
    self.init(create_Employee(swifttoscname, &err), true)
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

  public convenience init(age: Int, email: String = "") {
    let swifttoscage = CInt(age)
    let swifttoscemail = strdup(email)!
    var err = IEGenCObject()
    self.init(create_Employee_1(swifttoscage, swifttoscemail, &err), true)
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

  public var name: String {
    get {
      let result = _prop_get_Employee_name(cself)
      let sctoswiftresult = String(cString: result)
      defer {
        result.deallocate()
      }
      return sctoswiftresult
    }
  }

  public var email: String {
    get {
      let result = _prop_get_Employee_email(cself)
      let sctoswiftresult = String(cString: result)
      defer {
        result.deallocate()
      }
      return sctoswiftresult
    }
  }

  public var age: Int {
    get {
      let result = _prop_get_Employee_age(cself)
      let sctoswiftresult = Int(result)
      return sctoswiftresult
    }
  }

  public func setData(name: String, age: Int, email: String = "") -> Void {

    let swifttoscname = strdup(name)!
    let swifttoscage = CInt(age)
    let swifttoscemail = strdup(email)!
    var err = IEGenCObject()
    _func_Employee_setData(cself, swifttoscname, swifttoscage, swifttoscemail, &err)
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

  public func setData(age: Int) -> Void {

    let swifttoscage = CInt(age)
    var err = IEGenCObject()
    _func_Employee_setData_1(cself, swifttoscage, &err)
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

}
