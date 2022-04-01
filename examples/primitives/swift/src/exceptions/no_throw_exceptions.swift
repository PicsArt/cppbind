/**
 * ,--.,------. ,----.   ,------.,--.  ,--. 
 * |  ||  .---''  .-.|   |  .---'|  ,'.|  | 
 * |  ||  `--, |  | .---.|  `--, |  |' '  | 
 * |  ||  `---.'  '--'  ||  `---.|  | `   | 
 * `--'`------' `------' `------'`--'  `--' 
 * 
 * This file is generated by iegen on 03/30/2022-09:24.
 * Please do not change it manually.
 */

import CWrapper
import Foundation

public class NoThrowExc {

  public let cself: IEGenCObject
  public let owner: Bool
  private var refs: [Any]

  // internal main initializer
  internal required init(_ _cself: IEGenCObject, _ _owner: Bool = false) {
    self.cself = _cself
    self.owner = _owner
    self.refs = []
  }

  deinit {
    release_IegenExceptions_NoThrowExc(cself, owner)
  }

  public func keepIEGenReference(_ object: Any) {
    self.refs.append(object)
  }

  public convenience init(doThrow: Bool = false) {
    var iegenErr = IEGenCObject()
    self.init(create_IegenExceptions_NoThrowExc(doThrow, &iegenErr), true)
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

  public var prop: String {
    get {
      var iegenErr = IEGenCObject()
      let result = _prop_get_IegenExceptions_NoThrowExc_prop(cself, &iegenErr)
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
      _prop_set_IegenExceptions_NoThrowExc_prop(cself, swifttoscvalue, &iegenErr)
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

  public static func noop() -> Void {

    var iegenErr = IEGenCObject()
    _func_IegenExceptions_NoThrowExc_noop(&iegenErr)
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
