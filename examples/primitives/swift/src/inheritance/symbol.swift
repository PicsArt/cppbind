/**
 * ,--.,------. ,----.   ,------.,--.  ,--. 
 * |  ||  .---''  .-.|   |  .---'|  ,'.|  | 
 * |  ||  `--, |  | .---.|  `--, |  |' '  | 
 * |  ||  `---.'  '--'  ||  `---.|  | `   | 
 * `--'`------' `------' `------'`--'  `--' 
 * 
 * This file is generated by iegen on 02/17/2022-13:51.
 * Please do not change it manually.
 */

import CWrapper
import Foundation

public protocol Sign {
  var cself: IEGenCObject { get }

  func keepIEGenReference(_ object: AnyObject)
  func typeName() -> String
}

extension Sign {
  public func typeName() -> String {

    var err = IEGenCObject()
    let result = _func_Sign_typeName(cself, &err)
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
    let sctoswiftresult = String(cString: result)
    defer {
      result.deallocate()
    }
    return sctoswiftresult
  }

}

public class SignImpl: Sign {
  public let cself: IEGenCObject
  public let owner: Bool
  private var refs: [AnyObject]

  // internal main initializer
  internal required init(_ _cself: IEGenCObject, _ _owner: Bool = false) {
    self.cself = _cself
    self.owner = _owner
    self.refs = []
  }

  deinit {
    release_SignImpl(cself, owner)
  }

  public func keepIEGenReference(_ object: AnyObject) {
    self.refs.append(object)
  }

  public convenience init() {
    var err = IEGenCObject()
    self.init(create_Sign(&err), true)
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

public class Text {

  public let cself: IEGenCObject
  public let owner: Bool
  private var refs: [AnyObject]

  // internal main initializer
  internal required init(_ _cself: IEGenCObject, _ _owner: Bool = false) {
    self.cself = _cself
    self.owner = _owner
    self.refs = []
  }

  deinit {
    release_Text(cself, owner)
  }

  public func keepIEGenReference(_ object: AnyObject) {
    self.refs.append(object)
  }

  public convenience init() {
    var err = IEGenCObject()
    self.init(create_Text(&err), true)
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

  public func typeName() -> String {

    var err = IEGenCObject()
    let result = _func_Text_typeName(cself, &err)
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
    let sctoswiftresult = String(cString: result)
    defer {
      result.deallocate()
    }
    return sctoswiftresult
  }

}

public class Digit: Text, Sign {
  public convenience init() {
    var err = IEGenCObject()
    self.init(create_Digit(&err), true)
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

  public override func typeName() -> String {

    var err = IEGenCObject()
    let result = _func_Digit_typeName(cself, &err)
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
    let sctoswiftresult = String(cString: result)
    defer {
      result.deallocate()
    }
    return sctoswiftresult
  }

}

public class SymbolUsage {

  public let cself: IEGenCObject
  public let owner: Bool
  private var refs: [AnyObject]

  // internal main initializer
  internal required init(_ _cself: IEGenCObject, _ _owner: Bool = false) {
    self.cself = _cself
    self.owner = _owner
    self.refs = []
  }

  deinit {
    release_SymbolUsage(cself, owner)
  }

  public func keepIEGenReference(_ object: AnyObject) {
    self.refs.append(object)
  }

  public convenience init() {
    var err = IEGenCObject()
    self.init(create_SymbolUsage(&err), true)
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

  public convenience init(d: Digit) {
    let swifttoscd = d.cself
    var err = IEGenCObject()
    self.init(create_SymbolUsage_1(swifttoscd, &err), true)
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

  public func getTextType(t: Text) -> String {

    let swifttosct = t.cself
    var err = IEGenCObject()
    let result = _func_SymbolUsage_getTextType(cself, swifttosct, &err)
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
    let sctoswiftresult = String(cString: result)
    defer {
      result.deallocate()
    }
    return sctoswiftresult
  }

  public func getSignType(s: Sign) -> String {

    let swifttoscs = s.cself
    var err = IEGenCObject()
    let result = _func_SymbolUsage_getSignType(cself, swifttoscs, &err)
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
    let sctoswiftresult = String(cString: result)
    defer {
      result.deallocate()
    }
    return sctoswiftresult
  }

  public func getTextId(t: Text) -> Int {

    let swifttosct = t.cself
    var err = IEGenCObject()
    let result = _func_SymbolUsage_getTextId(cself, swifttosct, &err)
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
    let sctoswiftresult = Int(result)
    return sctoswiftresult
  }

  public func getSignId(s: Sign) -> Int {

    let swifttoscs = s.cself
    var err = IEGenCObject()
    let result = _func_SymbolUsage_getSignId(cself, swifttoscs, &err)
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
    let sctoswiftresult = Int(result)
    return sctoswiftresult
  }

  public func getTextPtr() -> Text {

    var err = IEGenCObject()
    let result = _func_SymbolUsage_getTextPtr(cself, &err)
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
    var sctoswiftresult: Text
    let resultIndex = String(cString: result.type)
    switch(resultIndex) {
    case("iegen::example::Digit"):
      sctoswiftresult = Digit(result)
    default:
      sctoswiftresult = Text(result)
    }
    return sctoswiftresult
  }

  public func getSignPtr() -> Sign {

    var err = IEGenCObject()
    let result = _func_SymbolUsage_getSignPtr(cself, &err)
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
    var sctoswiftresult: Sign
    let resultIndex = String(cString: result.type)
    switch(resultIndex) {
    case("iegen::example::Digit"):
      sctoswiftresult = Digit(result)
    default:
      sctoswiftresult = SignImpl(result)
    }
    return sctoswiftresult
  }

}
