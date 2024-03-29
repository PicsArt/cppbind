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

/// A base class for checking single branch non-polymorphic inheritance cases
public class Doctor {

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
    release_CppbindExample_Doctor(cself, owner)
  }

  /// An internal method to bind the lifetimes of the current and another object.
  /// It is intended to be used by the generated code.
  public func keepCppBindReference(_ object: Any) {
    self.refs.append(object)
  }

  /// internal dummy initializer to prevent automatic initializer inheritance
  internal init(_cself: CppBindCObject, _self: Doctor) {
    fatalError("A dummy internal initializer should not be called.")
  }

  public convenience init(doctorName: String) {
    let swifttoscdoctorName = strdup(doctorName)!
    var cppbindErr = CppBindCObject()
    self.init(create_CppbindExample_Doctor(swifttoscdoctorName, &cppbindErr), true)
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

  /// An internal property to keep an information about the underlying C++ object type.
  /// It is intended to be used by the generated code.
  class var cppbindCxxTypeName : String { return "cppbind::example::Doctor" }
}

public class Surgeon: Doctor {
  /// internal main initializer
  internal required init(_ _cself: CppBindCObject, _ _owner: Bool = false) {
    super.init(_cself, _owner)
  }

  public convenience init(surgeonName: String) {
    let swifttoscsurgeonName = strdup(surgeonName)!
    var cppbindErr = CppBindCObject()
    self.init(create_CppbindExample_Surgeon(swifttoscsurgeonName, &cppbindErr), true)
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

  /// An internal property to keep an information about the underlying C++ object type.
  /// It is intended to be used by the generated code.
  override class var cppbindCxxTypeName : String { return "cppbind::example::Surgeon" }
}

/// A base class for checking multibranch mixed polymorphic inheritance cases
public protocol GoodVirtualDoctor {
  /// An internal property to keep a reference to the original C++ object.
  /// It is intended to be used by the generated code.
  var cself: CppBindCObject { get }

  /// An internal method to bind the lifetimes of the current and another object.
  /// It is intended to be used by the generated code.
  func keepCppBindReference(_ object: Any)
}

extension GoodVirtualDoctor {
}

public class GoodVirtualDoctorImpl: GoodVirtualDoctor {
  public let cself: CppBindCObject
  public let owner: Bool
  private var refs: [Any]

  /// internal main initializer
  internal required init(_ _cself: CppBindCObject, _ _owner: Bool = false) {
    self.cself = _cself
    self.owner = _owner
    self.refs = []
  }

  deinit {
    release_CppbindExample_GoodVirtualDoctorImpl(cself, owner)
  }

  public func keepCppBindReference(_ object: Any) {
    self.refs.append(object)
  }

  /// An internal property to keep an information about the underlying C++ object type.
  /// It is intended to be used by the generated code.
  class var cppbindCxxTypeName : String { return "cppbind::example::GoodVirtualDoctor" }

  /// An internal method to create a Swift object from a C++ object.
  /// It is intended to be used by the generated code.
  class func cppbindConstructObject(_ cppbindObj: CppBindCObject, _ owner: Bool = false) -> GoodVirtualDoctor {
    let typeName = String(cString: cppbindObj.type)
    var obj : GoodVirtualDoctor
    switch(typeName) {
    case(GoodYoungDoctor.cppbindCxxTypeName):
      obj = GoodYoungDoctor(cppbindObj, owner)
    default:
      obj = GoodVirtualDoctorImpl(cppbindObj, owner)
    }
    return obj
  }
}

public class GoodDoctor {

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
    release_CppbindExample_GoodDoctor(cself, owner)
  }

  /// An internal method to bind the lifetimes of the current and another object.
  /// It is intended to be used by the generated code.
  public func keepCppBindReference(_ object: Any) {
    self.refs.append(object)
  }

  /// internal dummy initializer to prevent automatic initializer inheritance
  internal init(_cself: CppBindCObject, _self: GoodDoctor) {
    fatalError("A dummy internal initializer should not be called.")
  }

  public convenience init(doctorName: String) {
    let swifttoscdoctorName = strdup(doctorName)!
    var cppbindErr = CppBindCObject()
    self.init(create_CppbindExample_GoodDoctor(swifttoscdoctorName, &cppbindErr), true)
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

  /// An internal property to keep an information about the underlying C++ object type.
  /// It is intended to be used by the generated code.
  class var cppbindCxxTypeName : String { return "cppbind::example::GoodDoctor" }
}

/// Polymorphic subclass
public class GoodYoungDoctor: GoodDoctor, GoodVirtualDoctor {
  /// internal main initializer
  internal required init(_ _cself: CppBindCObject, _ _owner: Bool = false) {
    super.init(_cself, _owner)
  }

  public convenience init(doctorName: String) {
    let swifttoscdoctorName = strdup(doctorName)!
    var cppbindErr = CppBindCObject()
    self.init(create_CppbindExample_GoodYoungDoctor(swifttoscdoctorName, &cppbindErr), true)
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

  /// An internal property to keep an information about the underlying C++ object type.
  /// It is intended to be used by the generated code.
  override class var cppbindCxxTypeName : String { return "cppbind::example::GoodYoungDoctor" }
}

/// Non-polymorphic subclass
public class GoodOldDoctor: GoodDoctor {
  /// internal main initializer
  internal required init(_ _cself: CppBindCObject, _ _owner: Bool = false) {
    super.init(_cself, _owner)
  }

  public convenience init(doctorName: String) {
    let swifttoscdoctorName = strdup(doctorName)!
    var cppbindErr = CppBindCObject()
    self.init(create_CppbindExample_GoodOldDoctor(swifttoscdoctorName, &cppbindErr), true)
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

  /// An internal property to keep an information about the underlying C++ object type.
  /// It is intended to be used by the generated code.
  override class var cppbindCxxTypeName : String { return "cppbind::example::GoodOldDoctor" }
}

public class DoctorInfo {

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
    release_CppbindExample_DoctorInfo(cself, owner)
  }

  /// An internal method to bind the lifetimes of the current and another object.
  /// It is intended to be used by the generated code.
  public func keepCppBindReference(_ object: Any) {
    self.refs.append(object)
  }

  public convenience init(s: Surgeon) {
    let swifttoscs = s.cself
    var cppbindErr = CppBindCObject()
    self.init(create_CppbindExample_DoctorInfo(swifttoscs, &cppbindErr), true)
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

  public convenience init(d: GoodYoungDoctor) {
    let swifttoscd = d.cself
    var cppbindErr = CppBindCObject()
    self.init(create_CppbindExample_DoctorInfo1(swifttoscd, &cppbindErr), true)
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

  public func getDoctorName(d: Doctor) -> String {

    let swifttoscd = d.cself
    var cppbindErr = CppBindCObject()
    let result = _func_CppbindExample_DoctorInfo_getDoctorName(cself, swifttoscd, &cppbindErr)
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
    let sctoswiftresult = String(cString: result)
    defer {
      result.deallocate()
    }
    return sctoswiftresult
  }

  public func getSurgeonName(s: Surgeon) -> String {

    let swifttoscs = s.cself
    var cppbindErr = CppBindCObject()
    let result = _func_CppbindExample_DoctorInfo_getSurgeonName(cself, swifttoscs, &cppbindErr)
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
    let sctoswiftresult = String(cString: result)
    defer {
      result.deallocate()
    }
    return sctoswiftresult
  }

  public func getDoctor() -> Doctor {

    var cppbindErr = CppBindCObject()
    let result = _func_CppbindExample_DoctorInfo_getDoctor(cself, &cppbindErr)
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
    var sctoswiftresult: Doctor
    sctoswiftresult = Doctor(result)
    return sctoswiftresult
  }

  public func getGoodDoctor() -> GoodDoctor {

    var cppbindErr = CppBindCObject()
    let result = _func_CppbindExample_DoctorInfo_getGoodDoctor(cself, &cppbindErr)
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
    var sctoswiftresult: GoodDoctor
    sctoswiftresult = GoodDoctor(result)
    return sctoswiftresult
  }

  public func getGoodVirtualDoctor() -> GoodVirtualDoctor {

    var cppbindErr = CppBindCObject()
    let result = _func_CppbindExample_DoctorInfo_getGoodVirtualDoctor(cself, &cppbindErr)
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
    var sctoswiftresult: GoodVirtualDoctor
    sctoswiftresult = GoodVirtualDoctorImpl.cppbindConstructObject(result)
    return sctoswiftresult
  }

  public func getGoodDoctorName(d: GoodDoctor) -> String {

    let swifttoscd = d.cself
    var cppbindErr = CppBindCObject()
    let result = _func_CppbindExample_DoctorInfo_getGoodDoctorName(cself, swifttoscd, &cppbindErr)
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
    let sctoswiftresult = String(cString: result)
    defer {
      result.deallocate()
    }
    return sctoswiftresult
  }

  /// An internal property to keep an information about the underlying C++ object type.
  /// It is intended to be used by the generated code.
  class var cppbindCxxTypeName : String { return "cppbind::example::DoctorInfo" }
}
