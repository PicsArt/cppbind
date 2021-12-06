/**
 * ,--.,------. ,----.   ,------.,--.  ,--.
 * |  ||  .---''  .-.|   |  .---'|  ,'.|  |
 * |  ||  `--, |  | .---.|  `--, |  |' '  |
 * |  ||  `---.'  '--'  ||  `---.|  | `   |
 * `--'`------' `------' `------'`--'  `--'
 * 
 * This file is generated by iegen on 12/06/2021-05:43.
 * Please do not change it manually.
 */

import CWrapper
import Foundation

/**
 * Structure to describe user.
 */
public class UserInfo {

  public let cself: UnsafeMutableRawPointer
  public let owner: Bool

  // internal main initializer
  internal required init(_ _cself: UnsafeMutableRawPointer, _ _owner: Bool = false) {
    self.cself = _cself
    self.owner = _owner
  }

  deinit {
    if owner {
      release_UserInfo(cself)
    }
  }

  /**
   * Creates user
   */
  public convenience init(userName: String, userAge: UInt) {
    let swiftToScUserName = strdup(userName)!
    let swiftToScUserAge = CUnsignedInt(userAge)
    self.init(create_UserInfo(swiftToScUserName, swiftToScUserAge), true)
  }

  /**
   * Age of user.
   */
  public var age: UInt {
    get {
      let result = _prop_get_UserInfo_age(cself)
      let scToSwiftResult = UInt(result)
      return scToSwiftResult
    }
  }

  /**
   * Name of user.
   */
  public var name: String {
    get {
      let result = _prop_get_UserInfo_name(cself)
      let scToSwiftResult = String(cString: result)
      defer {
        result.deallocate()
      }
      return scToSwiftResult
    }
  }

  /**
   * Some wishes of the user.
   */
  public var want_a_drink: Bool {
    get {
      let result = _prop_get_UserInfo_want_a_drink(cself)
      return result
    }

    set(value) {
      _prop_set_UserInfo_want_a_drink(cself, value)
    }
  }

}

/**
 * Host class.
 */
public class Host {

  public let cself: UnsafeMutableRawPointer
  public let owner: Bool

  // internal main initializer
  internal required init(_ _cself: UnsafeMutableRawPointer, _ _owner: Bool = false) {
    self.cself = _cself
    self.owner = _owner
  }

  deinit {
    if owner {
      release_Host(cself)
    }
  }

  /**
   * Creates host
   */
  public convenience init() {
    self.init(create_Host(), true)
  }

  /**
   * Greeting function.
   */
  public func hello(user: UserInfo) -> String {

    let swiftToScUser = user.cself
    var err = ErrorObj()
    let result = _func_Host_hello(cself, swiftToScUser, &err)
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
    let scToSwiftResult = String(cString: result)
    defer {
      result.deallocate()
    }
    return scToSwiftResult
  }

  /**
   * Welcome function.
   */
  public func welcome(user: UserInfo) -> String {

    let swiftToScUser = user.cself
    var err = ErrorObj()
    let result = _func_Host_welcome(cself, swiftToScUser, &err)
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
    let scToSwiftResult = String(cString: result)
    defer {
      result.deallocate()
    }
    return scToSwiftResult
  }

}
