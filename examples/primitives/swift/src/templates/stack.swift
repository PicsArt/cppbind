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

/**
 * An example of a class template.
 */
public class StackPrj: Container {

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
    release_CppbindExample_StackPrj(cself, owner)
  }

  /**
   * An internal method to bind the lifetimes of the current and another object.
   * It is intended to be used by the generated code.
   */
  public func keepCppBindReference(_ object: Any) {
    self.refs.append(object)
  }

  public convenience init() {
    var cppbindErr = CppBindCObject()
    self.init(create_CppbindExample_StackPrj(&cppbindErr), true)
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

  public convenience init(st: Project) {
    let swifttoscst = st.cself
    var cppbindErr = CppBindCObject()
    self.init(create_CppbindExample_StackPrj_1(swifttoscst, &cppbindErr), true)
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

  public func push(item: Project) -> Void {

    let swifttoscitem = item.cself
    var cppbindErr = CppBindCObject()
    _func_CppbindExample_StackPrj_push(cself, swifttoscitem, &cppbindErr)
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

  public func pop() -> Void {

    var cppbindErr = CppBindCObject()
    _func_CppbindExample_StackPrj_pop(cself, &cppbindErr)
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

  public func top() -> Project {

    var cppbindErr = CppBindCObject()
    let result = _func_CppbindExample_StackPrj_top(cself, &cppbindErr)
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
    var sctoswiftresult: Project
    sctoswiftresult = Project(result)
    return sctoswiftresult
  }

  public func empty() -> Bool {

    var cppbindErr = CppBindCObject()
    let result = _func_CppbindExample_StackPrj_empty(cself, &cppbindErr)
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
    return result
  }

  /**
   * An internal property to keep an information about the underlying C++ object type.
   * It is intended to be used by the generated code.
   */
  class var cppbindCxxTypeName : String { return "cppbind::example::Stack<cppbind::example::Project>" }
}

/**
 * An example of a class template.
 */
public class StackTask: Container {

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
    release_CppbindExample_StackTask(cself, owner)
  }

  /**
   * An internal method to bind the lifetimes of the current and another object.
   * It is intended to be used by the generated code.
   */
  public func keepCppBindReference(_ object: Any) {
    self.refs.append(object)
  }

  public convenience init() {
    var cppbindErr = CppBindCObject()
    self.init(create_CppbindExample_StackTask(&cppbindErr), true)
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

  public convenience init(st: Task) {
    let swifttoscst = st.cself
    var cppbindErr = CppBindCObject()
    self.init(create_CppbindExample_StackTask_1(swifttoscst, &cppbindErr), true)
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

  public func push(item: Task) -> Void {

    let swifttoscitem = item.cself
    var cppbindErr = CppBindCObject()
    _func_CppbindExample_StackTask_push(cself, swifttoscitem, &cppbindErr)
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

  public func pop() -> Void {

    var cppbindErr = CppBindCObject()
    _func_CppbindExample_StackTask_pop(cself, &cppbindErr)
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

  public func top() -> Task {

    var cppbindErr = CppBindCObject()
    let result = _func_CppbindExample_StackTask_top(cself, &cppbindErr)
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
    var sctoswiftresult: Task
    sctoswiftresult = Task(result)
    return sctoswiftresult
  }

  public func empty() -> Bool {

    var cppbindErr = CppBindCObject()
    let result = _func_CppbindExample_StackTask_empty(cself, &cppbindErr)
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
    return result
  }

  /**
   * An internal property to keep an information about the underlying C++ object type.
   * It is intended to be used by the generated code.
   */
  class var cppbindCxxTypeName : String { return "cppbind::example::Stack<cppbind::example::Task>" }
}

/**
 * An example of a class template.
 */
public class StackNumInt: Container {

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
    release_CppbindExample_StackNumInt(cself, owner)
  }

  /**
   * An internal method to bind the lifetimes of the current and another object.
   * It is intended to be used by the generated code.
   */
  public func keepCppBindReference(_ object: Any) {
    self.refs.append(object)
  }

  public convenience init() {
    var cppbindErr = CppBindCObject()
    self.init(create_CppbindExample_StackNumInt(&cppbindErr), true)
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

  public convenience init(st: NumberInt) {
    let swifttoscst = st.cself
    var cppbindErr = CppBindCObject()
    self.init(create_CppbindExample_StackNumInt_1(swifttoscst, &cppbindErr), true)
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

  public func push(item: NumberInt) -> Void {

    let swifttoscitem = item.cself
    var cppbindErr = CppBindCObject()
    _func_CppbindExample_StackNumInt_push(cself, swifttoscitem, &cppbindErr)
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

  public func pop() -> Void {

    var cppbindErr = CppBindCObject()
    _func_CppbindExample_StackNumInt_pop(cself, &cppbindErr)
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

  public func top() -> NumberInt {

    var cppbindErr = CppBindCObject()
    let result = _func_CppbindExample_StackNumInt_top(cself, &cppbindErr)
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
    var sctoswiftresult: NumberInt
    sctoswiftresult = NumberInt(result)
    return sctoswiftresult
  }

  public func empty() -> Bool {

    var cppbindErr = CppBindCObject()
    let result = _func_CppbindExample_StackNumInt_empty(cself, &cppbindErr)
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
    return result
  }

  /**
   * An internal property to keep an information about the underlying C++ object type.
   * It is intended to be used by the generated code.
   */
  class var cppbindCxxTypeName : String { return "cppbind::example::Stack<cppbind::example::Number<int>>" }
}
