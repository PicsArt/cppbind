/**
 * ,--.,------. ,----.   ,------.,--.  ,--.
 * |  ||  .---''  .-.|   |  .---'|  ,'.|  |
 * |  ||  `--, |  | .---.|  `--, |  |' '  |
 * |  ||  `---.'  '--'  ||  `---.|  | `   |
 * `--'`------' `------' `------'`--'  `--'
 * 
 * This file is generated by iegen on 12/04/2021-11:54.
 * Please do not change it manually.
 */

import CWrapper
import Foundation

public class SimpleBaseException : Error {

  public let cself: UnsafeMutableRawPointer
  public let owner: Bool

  // internal main initializer
  internal required init(_ _cself: UnsafeMutableRawPointer, _ _owner: Bool = false) {
    self.cself = _cself
    self.owner = _owner
  }

  deinit {
    if owner {
      release_SimpleBaseException(cself)
    }
  }

  public convenience init(errNum: Int) {
    let swiftToScErrNum = CInt(errNum)
    self.init(create_SimpleBaseException(swiftToScErrNum), true)
  }

  public func errNum() -> Int {

    var err = ErrorObj()
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
    let result = _func_SimpleBaseException_errNum(cself, &err)
    let scToSwiftResult = Int(result)
    return scToSwiftResult
  }

}

public class SimpleChildException: SimpleBaseException {
  /**
   * comments
   * 
   */
  public convenience init(errNum: Int) {
    let swiftToScErrNum = CInt(errNum)
    self.init(create_SimpleChildException(swiftToScErrNum), true)
  }

  /**
   * comments
   * 
   */
  public override func errNum() -> Int {

    var err = ErrorObj()
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
    let result = _func_SimpleChildException_errNum(cself, &err)
    let scToSwiftResult = Int(result)
    return scToSwiftResult
  }

}
