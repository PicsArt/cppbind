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

/**
 * An example for with overloaded methods.
 */
public class Counter {

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
    release_IegenExample_Counter(cself, owner)
  }

  public func keepIEGenReference(_ object: Any) {
    self.refs.append(object)
  }

  /**
   * Counter constructor.
   */
  public convenience init(count: Int) {
    let swifttosccount = CInt(count)
    var iegenErr = IEGenCObject()
    self.init(create_IegenExample_Counter(swifttosccount, &iegenErr), true)
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

  /**
   * Getter for count.
   */
  public var count: Int {
    var iegenErr = IEGenCObject()
    let result = _prop_get_IegenExample_Counter_count(cself, &iegenErr)
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

  /**
   * Plus operator
   */
  public static func +(cself: Counter, counter: Counter) -> Counter {
    let swifttosccounter = counter.cself
    var iegenErr = IEGenCObject()
    let result = _func_IegenExample_Counter__add_(cself.cself, swifttosccounter, &iegenErr)
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
    var sctoswiftresult: Counter
    sctoswiftresult = Counter(result, true)
    return sctoswiftresult
  }

  public static func >(cself: Counter, counter: Counter) -> Bool {
    let swifttosccounter = counter.cself
    var iegenErr = IEGenCObject()
    let result = _func_IegenExample_Counter__gt_(cself.cself, swifttosccounter, &iegenErr)
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

  public static func +=(cself: Counter, counter: Counter) -> Counter {
    let swifttosccounter = counter.cself
    var iegenErr = IEGenCObject()
    let result = _func_IegenExample_Counter__iadd_(cself.cself, swifttosccounter, &iegenErr)
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
    var sctoswiftresult: Counter
    sctoswiftresult = Counter(result)
    return sctoswiftresult
  }

}
