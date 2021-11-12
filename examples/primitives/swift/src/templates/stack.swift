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

/**
 * comments
 * 
 */
public class StackPrj {

  public let cself: UnsafeMutableRawPointer
  public let owner: Bool

  // internal main initializer
  internal required init(_ _cself: UnsafeMutableRawPointer, _ _owner: Bool = false) {
    self.cself = _cself
    self.owner = _owner
  }

  deinit {
    if owner {
      release_StackPrj(cself)
    }
  }

  public convenience init() {
    self.init(create_StackPrj(), true)
  }

  public convenience init(st: Project) {
    let swiftToScSt = st.cself
    self.init(create_StackPrj_1(swiftToScSt), true)
  }

  public func push(item: Project) -> Void {

    let swiftToScItem = item.cself
    var err = ErrorObj()
    _func_StackPrj_push(cself, swiftToScItem, &err)
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
  }

  public func pop() -> Void {

    var err = ErrorObj()
    _func_StackPrj_pop(cself, &err)
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
  }

  public func top() -> Project {

    var err = ErrorObj()
    let result = _func_StackPrj_top(cself, &err)
    let scToSwiftResult = Project(result)
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

  public func empty() -> Bool {

    var err = ErrorObj()
    let result = _func_StackPrj_empty(cself, &err)
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
    return result
  }

}

/**
 * comments
 * 
 */
public class StackTask {

  public let cself: UnsafeMutableRawPointer
  public let owner: Bool

  // internal main initializer
  internal required init(_ _cself: UnsafeMutableRawPointer, _ _owner: Bool = false) {
    self.cself = _cself
    self.owner = _owner
  }

  deinit {
    if owner {
      release_StackTask(cself)
    }
  }

  public convenience init() {
    self.init(create_StackTask(), true)
  }

  public convenience init(st: Task) {
    let swiftToScSt = st.cself
    self.init(create_StackTask_1(swiftToScSt), true)
  }

  public func push(item: Task) -> Void {

    let swiftToScItem = item.cself
    var err = ErrorObj()
    _func_StackTask_push(cself, swiftToScItem, &err)
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
  }

  public func pop() -> Void {

    var err = ErrorObj()
    _func_StackTask_pop(cself, &err)
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
  }

  public func top() -> Task {

    var err = ErrorObj()
    let result = _func_StackTask_top(cself, &err)
    let scToSwiftResult = Task(result)
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

  public func empty() -> Bool {

    var err = ErrorObj()
    let result = _func_StackTask_empty(cself, &err)
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
    return result
  }

}

/**
 * comments
 * 
 */
public class StackNumInt {

  public let cself: UnsafeMutableRawPointer
  public let owner: Bool

  // internal main initializer
  internal required init(_ _cself: UnsafeMutableRawPointer, _ _owner: Bool = false) {
    self.cself = _cself
    self.owner = _owner
  }

  deinit {
    if owner {
      release_StackNumInt(cself)
    }
  }

  public convenience init() {
    self.init(create_StackNumInt(), true)
  }

  public convenience init(st: NumberInt) {
    let swiftToScSt = st.cself
    self.init(create_StackNumInt_1(swiftToScSt), true)
  }

  public func push(item: NumberInt) -> Void {

    let swiftToScItem = item.cself
    var err = ErrorObj()
    _func_StackNumInt_push(cself, swiftToScItem, &err)
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
  }

  public func pop() -> Void {

    var err = ErrorObj()
    _func_StackNumInt_pop(cself, &err)
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
  }

  public func top() -> NumberInt {

    var err = ErrorObj()
    let result = _func_StackNumInt_top(cself, &err)
    let scToSwiftResult = NumberInt(result)
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

  public func empty() -> Bool {

    var err = ErrorObj()
    let result = _func_StackNumInt_empty(cself, &err)
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
    return result
  }

}
