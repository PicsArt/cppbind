/**
 * ,--.,------. ,----.   ,------.,--.  ,--. 
 * |  ||  .---''  .-.|   |  .---'|  ,'.|  | 
 * |  ||  `--, |  | .---.|  `--, |  |' '  | 
 * |  ||  `---.'  '--'  ||  `---.|  | `   | 
 * `--'`------' `------' `------'`--'  `--' 
 * 
 * This file is generated by iegen on 04/05/2022-12:52.
 * Please do not change it manually.
 */

import CWrapper
import Foundation

public class WithExternalAPIComments {

  public let cself: IEGenCObject
  public let owner: Bool
  private var refs: [Any]

  /// internal main initializer
  internal required init(_ _cself: IEGenCObject, _ _owner: Bool = false) {
    self.cself = _cself
    self.owner = _owner
    self.refs = []
  }

  /// internal private initializer to prevent automatic initializer inheritance
  private init(_ _cself: IEGenCObject, _ _owner: Bool, _ _refs: [Any]) {
    fatalError("A private initializer should not be called.")
  }

  deinit {
    release_IegenExample_WithExternalAPIComments(cself, owner)
  }

  public func keepIEGenReference(_ object: Any) {
    self.refs.append(object)
  }

  public convenience init(s: String) {
    let swifttoscs = strdup(s)!
    var iegenErr = IEGenCObject()
    self.init(create_IegenExample_WithExternalAPIComments(swifttoscs, &iegenErr), true)
    if iegenErr.type != nil {
      let errorType = String(cString: iegenErr.type!)
      switch errorType {
      case ("std::exception"):
        let excObj = StdException(iegenErr, true)
        ExceptionHandler.handleUncaughtException(excObj.what())
      default:
        iegenErr.type.deallocate()
        ExceptionHandler.handleUncaughtException("Uncaught Exception")
      }
    }
  }

  public var str: String {
    get {
      var iegenErr = IEGenCObject()
      let result = _prop_get_IegenExample_WithExternalAPIComments_str(cself, &iegenErr)
      if iegenErr.type != nil {
        let errorType = String(cString: iegenErr.type!)
        switch errorType {
        case ("std::exception"):
          let excObj = StdException(iegenErr, true)
          ExceptionHandler.handleUncaughtException(excObj.what())
        default:
          iegenErr.type.deallocate()
          ExceptionHandler.handleUncaughtException("Uncaught Exception")
        }
      }
      let sctoswiftresult = String(cString: result)
      defer {
        result.deallocate()
      }
      return sctoswiftresult
    }

    set(value) {
      let swifttoscvalue = strdup(value)!
      var iegenErr = IEGenCObject()
      _prop_set_IegenExample_WithExternalAPIComments_str(cself, swifttoscvalue, &iegenErr)
      if iegenErr.type != nil {
        let errorType = String(cString: iegenErr.type!)
        switch errorType {
        case ("std::exception"):
          let excObj = StdException(iegenErr, true)
          ExceptionHandler.handleUncaughtException(excObj.what())
        default:
          iegenErr.type.deallocate()
          ExceptionHandler.handleUncaughtException("Uncaught Exception")
        }
      }
    }
  }

  public static func retInt(n: Int) -> Int {

    let swifttoscn = CInt(n)
    var iegenErr = IEGenCObject()
    let result = _func_IegenExample_WithExternalAPIComments_retInt(swifttoscn, &iegenErr)
    if iegenErr.type != nil {
      let errorType = String(cString: iegenErr.type!)
      switch errorType {
      case ("std::exception"):
        let excObj = StdException(iegenErr, true)
        ExceptionHandler.handleUncaughtException(excObj.what())
      default:
        iegenErr.type.deallocate()
        ExceptionHandler.handleUncaughtException("Uncaught Exception")
      }
    }
    let sctoswiftresult = Int(result)
    return sctoswiftresult
  }

  public static func max(a: Int, b: Int) -> Int {

    let swifttosca = CInt(a)
    let swifttoscb = CInt(b)
    var iegenErr = IEGenCObject()
    let result = _func_IegenExample_WithExternalAPIComments_maxInt(swifttosca, swifttoscb, &iegenErr)
    if iegenErr.type != nil {
      let errorType = String(cString: iegenErr.type!)
      switch errorType {
      case ("std::exception"):
        let excObj = StdException(iegenErr, true)
        ExceptionHandler.handleUncaughtException(excObj.what())
      default:
        iegenErr.type.deallocate()
        ExceptionHandler.handleUncaughtException("Uncaught Exception")
      }
    }
    let sctoswiftresult = Int(result)
    return sctoswiftresult
  }

  public static func max(a: String, b: String) -> String {

    let swifttosca = strdup(a)!
    let swifttoscb = strdup(b)!
    var iegenErr = IEGenCObject()
    let result = _func_IegenExample_WithExternalAPIComments_maxString(swifttosca, swifttoscb, &iegenErr)
    if iegenErr.type != nil {
      let errorType = String(cString: iegenErr.type!)
      switch errorType {
      case ("std::exception"):
        let excObj = StdException(iegenErr, true)
        ExceptionHandler.handleUncaughtException(excObj.what())
      default:
        iegenErr.type.deallocate()
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

public class AdderInt {

  public let cself: IEGenCObject
  public let owner: Bool
  private var refs: [Any]

  /// internal main initializer
  internal required init(_ _cself: IEGenCObject, _ _owner: Bool = false) {
    self.cself = _cself
    self.owner = _owner
    self.refs = []
  }

  /// internal private initializer to prevent automatic initializer inheritance
  private init(_ _cself: IEGenCObject, _ _owner: Bool, _ _refs: [Any]) {
    fatalError("A private initializer should not be called.")
  }

  deinit {
    release_IegenExample_AdderInt(cself, owner)
  }

  public func keepIEGenReference(_ object: Any) {
    self.refs.append(object)
  }

  public static func add(a: Int, b: Int) -> Int {

    let swifttosca = CInt(a)
    let swifttoscb = CInt(b)
    var iegenErr = IEGenCObject()
    let result = _func_IegenExample_AdderInt_add(swifttosca, swifttoscb, &iegenErr)
    if iegenErr.type != nil {
      let errorType = String(cString: iegenErr.type!)
      switch errorType {
      case ("std::exception"):
        let excObj = StdException(iegenErr, true)
        ExceptionHandler.handleUncaughtException(excObj.what())
      default:
        iegenErr.type.deallocate()
        ExceptionHandler.handleUncaughtException("Uncaught Exception")
      }
    }
    let sctoswiftresult = Int(result)
    return sctoswiftresult
  }

}

public class AdderDouble {

  public let cself: IEGenCObject
  public let owner: Bool
  private var refs: [Any]

  /// internal main initializer
  internal required init(_ _cself: IEGenCObject, _ _owner: Bool = false) {
    self.cself = _cself
    self.owner = _owner
    self.refs = []
  }

  /// internal private initializer to prevent automatic initializer inheritance
  private init(_ _cself: IEGenCObject, _ _owner: Bool, _ _refs: [Any]) {
    fatalError("A private initializer should not be called.")
  }

  deinit {
    release_IegenExample_AdderDouble(cself, owner)
  }

  public func keepIEGenReference(_ object: Any) {
    self.refs.append(object)
  }

  public static func add(a: Double, b: Double) -> Double {

    var iegenErr = IEGenCObject()
    let result = _func_IegenExample_AdderDouble_add(a, b, &iegenErr)
    if iegenErr.type != nil {
      let errorType = String(cString: iegenErr.type!)
      switch errorType {
      case ("std::exception"):
        let excObj = StdException(iegenErr, true)
        ExceptionHandler.handleUncaughtException(excObj.what())
      default:
        iegenErr.type.deallocate()
        ExceptionHandler.handleUncaughtException("Uncaught Exception")
      }
    }
    return result
  }

}

public enum color: CUnsignedInt {
  case RED = 0
  case GREEN = 1
  case BLUE = 2
}
