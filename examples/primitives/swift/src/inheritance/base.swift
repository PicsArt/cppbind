/**
 * ,--.,------. ,----.   ,------.,--.  ,--.
 * |  ||  .---''  .-.|   |  .---'|  ,'.|  |
 * |  ||  `--, |  | .---.|  `--, |  |' '  |
 * |  ||  `---.'  '--'  ||  `---.|  | `   |
 * `--'`------' `------' `------'`--'  `--'
 * 
 * This file is generated by iegen on 11/12/2021-15:17.
 * Please do not change it manually.
 */

import CWrapper
import Foundation

public protocol Base {
  var cself: UnsafeMutableRawPointer { get }

  func value() -> String
}

extension Base {
  public func value() -> String {

    var err = ErrorObj()
    let result = _func_Base_value(cself, &err)
    let scToSwiftResult = String(cString: result)
    defer {
      result.deallocate()
    }
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
    return scToSwiftResult
  }

}

public class BaseImpl: Base {
  public let cself: UnsafeMutableRawPointer
  public let owner: Bool

  // internal main initializer
  internal required init(_ _cself: UnsafeMutableRawPointer, _ _owner: Bool = false) {
    self.cself = _cself
    self.owner = _owner
  }

  deinit {
    if owner {
      release_BaseImpl(cself)
    }
  }

}
