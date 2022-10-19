/**
 *   ______ .______   .______   .______    __  .__   __.  _______  
 *  /      ||   _  \  |   _  \  |   _  \  |  | |  \ |  | |       \ 
 * |  ,----'|  |_)  | |  |_)  | |  |_)  | |  | |   \|  | |  .--.  |
 * |  |     |   ___/  |   ___/  |   _  <  |  | |  . `  | |  |  |  |
 * |  `----.|  |      |  |      |  |_)  | |  | |  |\   | |  '--'  |
 *  \______|| _|      | _|      |______/  |__| |__| \__| |_______/ 
 * 
 * This file is generated by cppbind on 10/18/2022-08:51.
 * Please do not change it manually.
 */

import CWrapper
import Foundation

public class SimpleBaseException: Error {

  /// An internal property to keep a reference to the original C++ object.
  /// It is intended to be used by the generated code.
  public let cself: CppBindCObject

  /// An internal property to keep track whether Swift is responsible for deallocating the underlying C++ object or not.
  /// It is intended to be used by the generated code.
  public let owner: Bool
  private var refs: [Any]

  /// internal main initializer
  internal required init(_ _cself: CppBindCObject, _ _owner: Bool = false) {
    self.cself = _cself
    self.owner = _owner
    self.refs = []
  }

  deinit {
    release_CppbindExample_SimpleBaseException(cself, owner)
  }

  /// An internal method to bind the lifetimes of the current and another object.
  /// It is intended to be used by the generated code.
  public func keepCppBindReference(_ object: Any) {
    self.refs.append(object)
  }

  /// internal dummy initializer to prevent automatic initializer inheritance
  internal init(_cself: CppBindCObject, _self: SimpleBaseException) {
    fatalError("A dummy internal initializer should not be called.")
  }

  public convenience init(errNum: Int) {
    let swifttoscerrNum = CInt(errNum)
    var cppbindErr = CppBindCObject()
    self.init(create_CppbindExample_SimpleBaseException(swifttoscerrNum, &cppbindErr), true)
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

  public func errNum() -> Int {

    var cppbindErr = CppBindCObject()
    let result = _func_CppbindExample_SimpleBaseException_errNum(cself, &cppbindErr)
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
    let sctoswiftresult = Int(result)
    return sctoswiftresult
  }

  /// An internal property to keep an information about the underlying C++ object type.
  /// It is intended to be used by the generated code.
  class var cppbindCxxTypeName : String { return "cppbind::example::SimpleBaseException" }

  /// An internal method to create a Swift object from a C++ object.
  /// It is intended to be used by the generated code.
  class func cppbindConstructObject(_ cppbindObj: CppBindCObject, _ owner: Bool = false) -> SimpleBaseException {
    let typeName = String(cString: cppbindObj.type)
    var obj : SimpleBaseException
    switch(typeName) {
    case(SimpleChildException.cppbindCxxTypeName):
      obj = SimpleChildException(cppbindObj, owner)
    default:
      obj = SimpleBaseException(cppbindObj, owner)
    }
    return obj
  }
}

public class SimpleChildException: SimpleBaseException {
  /// internal main initializer
  internal required init(_ _cself: CppBindCObject, _ _owner: Bool = false) {
    super.init(_cself, _owner)
  }

  /// comments
  /// 
  public convenience init(errNum: Int) {
    let swifttoscerrNum = CInt(errNum)
    var cppbindErr = CppBindCObject()
    self.init(create_CppbindExample_SimpleChildException(swifttoscerrNum, &cppbindErr), true)
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

  /// comments
  /// 
  public override func errNum() -> Int {

    var cppbindErr = CppBindCObject()
    let result = _func_CppbindExample_SimpleChildException_errNum(cself, &cppbindErr)
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
    let sctoswiftresult = Int(result)
    return sctoswiftresult
  }

  /// An internal property to keep an information about the underlying C++ object type.
  /// It is intended to be used by the generated code.
  override class var cppbindCxxTypeName : String { return "cppbind::example::SimpleChildException" }
}
