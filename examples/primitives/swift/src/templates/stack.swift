/**
 * ,--.,------. ,----.   ,------.,--.  ,--. 
 * |  ||  .---''  .-.|   |  .---'|  ,'.|  | 
 * |  ||  `--, |  | .---.|  `--, |  |' '  | 
 * |  ||  `---.'  '--'  ||  `---.|  | `   | 
 * `--'`------' `------' `------'`--'  `--' 
 * 
 * This file is generated by iegen on 02/03/2022-14:57.
 * Please do not change it manually.
 */

import CWrapper
import Foundation

/**
 * comments
 * 
 */
public class StackPrj: Container {

  public let cself: IEGenCObject
  public let owner: Bool

  // internal main initializer
  internal required init(_ _cself: IEGenCObject, _ _owner: Bool = false) {
    self.cself = _cself
    self.owner = _owner
  }

  deinit {
    release_StackPrj(cself, owner)
  }

  public convenience init() {
    var err = IEGenCObject()
    self.init(create_StackPrj(&err), true)
    if err.type != nil {
      let errorType = String(cString: err.type!)
      switch errorType {
      case ("std::exception"):
        let excObj = StdException(IEGenCObject(type: err.type, ptr: err.ptr), true)
        ExceptionHandler.handleUncaughtException(excObj.what())
      default:
        ExceptionHandler.handleUncaughtException("Uncaught Exception")
      }
    }
  }

  public convenience init(st: Project) {
    let swifttoscst = st.cself
    var err = IEGenCObject()
    self.init(create_StackPrj_1(swifttoscst, &err), true)
    if err.type != nil {
      let errorType = String(cString: err.type!)
      switch errorType {
      case ("std::exception"):
        let excObj = StdException(IEGenCObject(type: err.type, ptr: err.ptr), true)
        ExceptionHandler.handleUncaughtException(excObj.what())
      default:
        ExceptionHandler.handleUncaughtException("Uncaught Exception")
      }
    }
  }

  public func push(item: Project) -> Void {

    let swifttoscitem = item.cself
    var err = IEGenCObject()
    _func_StackPrj_push(cself, swifttoscitem, &err)
    if err.type != nil {
      let errorType = String(cString: err.type!)
      switch errorType {
      case ("std::exception"):
        let excObj = StdException(IEGenCObject(type: err.type, ptr: err.ptr), true)
        ExceptionHandler.handleUncaughtException(excObj.what())
      default:
        ExceptionHandler.handleUncaughtException("Uncaught Exception")
      }
    }
  }

  public func pop() -> Void {

    var err = IEGenCObject()
    _func_StackPrj_pop(cself, &err)
    if err.type != nil {
      let errorType = String(cString: err.type!)
      switch errorType {
      case ("std::exception"):
        let excObj = StdException(IEGenCObject(type: err.type, ptr: err.ptr), true)
        ExceptionHandler.handleUncaughtException(excObj.what())
      default:
        ExceptionHandler.handleUncaughtException("Uncaught Exception")
      }
    }
  }

  public func top() -> Project {

    var err = IEGenCObject()
    let result = _func_StackPrj_top(cself, &err)
    if err.type != nil {
      let errorType = String(cString: err.type!)
      switch errorType {
      case ("std::exception"):
        let excObj = StdException(IEGenCObject(type: err.type, ptr: err.ptr), true)
        ExceptionHandler.handleUncaughtException(excObj.what())
      default:
        ExceptionHandler.handleUncaughtException("Uncaught Exception")
      }
    }
    var sctoswiftresult: Project
    sctoswiftresult = Project(result)
    return sctoswiftresult
  }

  public func empty() -> Bool {

    var err = IEGenCObject()
    let result = _func_StackPrj_empty(cself, &err)
    if err.type != nil {
      let errorType = String(cString: err.type!)
      switch errorType {
      case ("std::exception"):
        let excObj = StdException(IEGenCObject(type: err.type, ptr: err.ptr), true)
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
public class StackTask: Container {

  public let cself: IEGenCObject
  public let owner: Bool

  // internal main initializer
  internal required init(_ _cself: IEGenCObject, _ _owner: Bool = false) {
    self.cself = _cself
    self.owner = _owner
  }

  deinit {
    release_StackTask(cself, owner)
  }

  public convenience init() {
    var err = IEGenCObject()
    self.init(create_StackTask(&err), true)
    if err.type != nil {
      let errorType = String(cString: err.type!)
      switch errorType {
      case ("std::exception"):
        let excObj = StdException(IEGenCObject(type: err.type, ptr: err.ptr), true)
        ExceptionHandler.handleUncaughtException(excObj.what())
      default:
        ExceptionHandler.handleUncaughtException("Uncaught Exception")
      }
    }
  }

  public convenience init(st: Task) {
    let swifttoscst = st.cself
    var err = IEGenCObject()
    self.init(create_StackTask_1(swifttoscst, &err), true)
    if err.type != nil {
      let errorType = String(cString: err.type!)
      switch errorType {
      case ("std::exception"):
        let excObj = StdException(IEGenCObject(type: err.type, ptr: err.ptr), true)
        ExceptionHandler.handleUncaughtException(excObj.what())
      default:
        ExceptionHandler.handleUncaughtException("Uncaught Exception")
      }
    }
  }

  public func push(item: Task) -> Void {

    let swifttoscitem = item.cself
    var err = IEGenCObject()
    _func_StackTask_push(cself, swifttoscitem, &err)
    if err.type != nil {
      let errorType = String(cString: err.type!)
      switch errorType {
      case ("std::exception"):
        let excObj = StdException(IEGenCObject(type: err.type, ptr: err.ptr), true)
        ExceptionHandler.handleUncaughtException(excObj.what())
      default:
        ExceptionHandler.handleUncaughtException("Uncaught Exception")
      }
    }
  }

  public func pop() -> Void {

    var err = IEGenCObject()
    _func_StackTask_pop(cself, &err)
    if err.type != nil {
      let errorType = String(cString: err.type!)
      switch errorType {
      case ("std::exception"):
        let excObj = StdException(IEGenCObject(type: err.type, ptr: err.ptr), true)
        ExceptionHandler.handleUncaughtException(excObj.what())
      default:
        ExceptionHandler.handleUncaughtException("Uncaught Exception")
      }
    }
  }

  public func top() -> Task {

    var err = IEGenCObject()
    let result = _func_StackTask_top(cself, &err)
    if err.type != nil {
      let errorType = String(cString: err.type!)
      switch errorType {
      case ("std::exception"):
        let excObj = StdException(IEGenCObject(type: err.type, ptr: err.ptr), true)
        ExceptionHandler.handleUncaughtException(excObj.what())
      default:
        ExceptionHandler.handleUncaughtException("Uncaught Exception")
      }
    }
    var sctoswiftresult: Task
    sctoswiftresult = Task(result)
    return sctoswiftresult
  }

  public func empty() -> Bool {

    var err = IEGenCObject()
    let result = _func_StackTask_empty(cself, &err)
    if err.type != nil {
      let errorType = String(cString: err.type!)
      switch errorType {
      case ("std::exception"):
        let excObj = StdException(IEGenCObject(type: err.type, ptr: err.ptr), true)
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
public class StackNumInt: Container {

  public let cself: IEGenCObject
  public let owner: Bool

  // internal main initializer
  internal required init(_ _cself: IEGenCObject, _ _owner: Bool = false) {
    self.cself = _cself
    self.owner = _owner
  }

  deinit {
    release_StackNumInt(cself, owner)
  }

  public convenience init() {
    var err = IEGenCObject()
    self.init(create_StackNumInt(&err), true)
    if err.type != nil {
      let errorType = String(cString: err.type!)
      switch errorType {
      case ("std::exception"):
        let excObj = StdException(IEGenCObject(type: err.type, ptr: err.ptr), true)
        ExceptionHandler.handleUncaughtException(excObj.what())
      default:
        ExceptionHandler.handleUncaughtException("Uncaught Exception")
      }
    }
  }

  public convenience init(st: NumberInt) {
    let swifttoscst = st.cself
    var err = IEGenCObject()
    self.init(create_StackNumInt_1(swifttoscst, &err), true)
    if err.type != nil {
      let errorType = String(cString: err.type!)
      switch errorType {
      case ("std::exception"):
        let excObj = StdException(IEGenCObject(type: err.type, ptr: err.ptr), true)
        ExceptionHandler.handleUncaughtException(excObj.what())
      default:
        ExceptionHandler.handleUncaughtException("Uncaught Exception")
      }
    }
  }

  public func push(item: NumberInt) -> Void {

    let swifttoscitem = item.cself
    var err = IEGenCObject()
    _func_StackNumInt_push(cself, swifttoscitem, &err)
    if err.type != nil {
      let errorType = String(cString: err.type!)
      switch errorType {
      case ("std::exception"):
        let excObj = StdException(IEGenCObject(type: err.type, ptr: err.ptr), true)
        ExceptionHandler.handleUncaughtException(excObj.what())
      default:
        ExceptionHandler.handleUncaughtException("Uncaught Exception")
      }
    }
  }

  public func pop() -> Void {

    var err = IEGenCObject()
    _func_StackNumInt_pop(cself, &err)
    if err.type != nil {
      let errorType = String(cString: err.type!)
      switch errorType {
      case ("std::exception"):
        let excObj = StdException(IEGenCObject(type: err.type, ptr: err.ptr), true)
        ExceptionHandler.handleUncaughtException(excObj.what())
      default:
        ExceptionHandler.handleUncaughtException("Uncaught Exception")
      }
    }
  }

  public func top() -> NumberInt {

    var err = IEGenCObject()
    let result = _func_StackNumInt_top(cself, &err)
    if err.type != nil {
      let errorType = String(cString: err.type!)
      switch errorType {
      case ("std::exception"):
        let excObj = StdException(IEGenCObject(type: err.type, ptr: err.ptr), true)
        ExceptionHandler.handleUncaughtException(excObj.what())
      default:
        ExceptionHandler.handleUncaughtException("Uncaught Exception")
      }
    }
    var sctoswiftresult: NumberInt
    sctoswiftresult = NumberInt(result)
    return sctoswiftresult
  }

  public func empty() -> Bool {

    var err = IEGenCObject()
    let result = _func_StackNumInt_empty(cself, &err)
    if err.type != nil {
      let errorType = String(cString: err.type!)
      switch errorType {
      case ("std::exception"):
        let excObj = StdException(IEGenCObject(type: err.type, ptr: err.ptr), true)
        ExceptionHandler.handleUncaughtException(excObj.what())
      default:
        ExceptionHandler.handleUncaughtException("Uncaught Exception")
      }
    }
    return result
  }

}
