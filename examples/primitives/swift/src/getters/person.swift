/**
 * ,--.,------. ,----.   ,------.,--.  ,--.
 * |  ||  .---''  .-.|   |  .---'|  ,'.|  |
 * |  ||  `--, |  | .---.|  `--, |  |' '  |
 * |  ||  `---.'  '--'  ||  `---.|  | `   |
 * `--'`------' `------' `------'`--'  `--'
 * 
 * This file is generated by iegen on 12/06/2021-09:36.
 * Please do not change it manually.
 */

import CWrapper
import Foundation

/**
 * This class contains a private string field and getter/setter methods for it.
 */
public class Person {

  public let cself: UnsafeMutableRawPointer
  public let owner: Bool

  // internal main initializer
  internal required init(_ _cself: UnsafeMutableRawPointer, _ _owner: Bool = false) {
    self.cself = _cself
    self.owner = _owner
  }

  deinit {
    if owner {
      release_Person(cself)
    }
  }

  public convenience init(name: String, email: String, age: Int) {
    let swiftToScName = strdup(name)!
    let swiftToScEmail = strdup(email)!
    let swiftToScAge = CInt(age)
    var err = ErrorObj()
    self.init(create_Person(swiftToScName, swiftToScEmail, swiftToScAge, &err), true)
    let err_type = Int(err.err_type)
    if (err_type != 0) {
      switch(err_type) {
        case(1):
          let exc_obj = StdException(err.err_ptr, true)
          ExceptionHandler.handleUncaughtException(exc_obj.what())
        default:
          ExceptionHandler.handleUncaughtException("Uncaught Exception")
      }
    }
  }

  public var name: String {
    get {
      let result = _prop_get_Person_name(cself)
      let scToSwiftResult = String(cString: result)
      defer {
        result.deallocate()
      }
      return scToSwiftResult
    }

    set(value) {
      let swiftToScValue = strdup(value)!
      _prop_set_Person_name(cself, swiftToScValue)
    }
  }

  public var email: String {
    get {
      let result = _prop_get_Person_email(cself)
      let scToSwiftResult = String(cString: result)
      defer {
        result.deallocate()
      }
      return scToSwiftResult
    }
  }

  public var age: Int {
    get {
      let result = _prop_get_Person_age(cself)
      let scToSwiftResult = Int(result)
      return scToSwiftResult
    }

    set(value) {
      let swiftToScValue = CInt(value)
      _prop_set_Person_age(cself, swiftToScValue)
    }
  }

}
