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

public class QueueInt {

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
    release_IegenExample_QueueInt(cself, owner)
  }

  public func keepIEGenReference(_ object: Any) {
    self.refs.append(object)
  }

  public convenience init() {
    var iegenErr = IEGenCObject()
    self.init(create_IegenExample_QueueInt(&iegenErr), true)
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

  public func push_back(element: Int) -> Void {

    let swifttoscelement = CInt(element)
    var iegenErr = IEGenCObject()
    _func_IegenExample_QueueInt_push_back(cself, swifttoscelement, &iegenErr)
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

  public func get_size() -> Int {

    var iegenErr = IEGenCObject()
    let result = _func_IegenExample_QueueInt_get_size(cself, &iegenErr)
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

public class QueueIntUsage {

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
    release_IegenExample_QueueIntUsage(cself, owner)
  }

  public func keepIEGenReference(_ object: Any) {
    self.refs.append(object)
  }

  public convenience init(q: QueueInt) {
    let swifttoscq = q.cself
    var iegenErr = IEGenCObject()
    self.init(create_IegenExample_QueueIntUsage(swifttoscq, &iegenErr), true)
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

  public var empty_queue: QueueInt {
    let result = _prop_get_IegenExample_QueueIntUsage_empty_queue(cself)
    var sctoswiftresult: QueueInt
    sctoswiftresult = QueueInt(result, true)
    return sctoswiftresult
  }

  public var saved_queue: QueueInt {
    let result = _prop_get_IegenExample_QueueIntUsage_saved_queue(cself)
    var sctoswiftresult: QueueInt
    sctoswiftresult = QueueInt(result)
    return sctoswiftresult
  }

  public static func getSize(q: QueueInt) -> Int {

    let swifttoscq = q.cself
    var iegenErr = IEGenCObject()
    let result = _func_IegenExample_QueueIntUsage_getSize(swifttoscq, &iegenErr)
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

  public static func getLastElement(q: QueueInt) -> Int {

    let swifttoscq = q.cself
    var iegenErr = IEGenCObject()
    let result = _func_IegenExample_QueueIntUsage_getLastElement(swifttoscq, &iegenErr)
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

  public static func getFirstElement(q: QueueInt) -> Int {

    let swifttoscq = q.cself
    var iegenErr = IEGenCObject()
    let result = _func_IegenExample_QueueIntUsage_getFirstElement(swifttoscq, &iegenErr)
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

  public static func getInvQueue(v: Array<Int>) -> QueueInt {

    let _swifttoscvData = UnsafeMutablePointer<CInt>.allocate(capacity: v.count)
    var swifttoscv = IEGenCDataArray()
    swifttoscv.data = UnsafeMutableRawPointer(_swifttoscvData)
    swifttoscv.size = Int64(v.count)
    for i in 0..<v.count {
      let vVal = v[i]
      let swifttoscvVal = CInt(vVal)
      _swifttoscvData[i] = swifttoscvVal
    }
    var iegenErr = IEGenCObject()
    let result = _func_IegenExample_QueueIntUsage_getInvQueue(swifttoscv, &iegenErr)
    
    swifttoscv.data.deallocate()
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
    var sctoswiftresult: QueueInt
    sctoswiftresult = QueueInt(result, true)
    return sctoswiftresult
  }

  public func getSavedQueue() -> QueueInt {

    var iegenErr = IEGenCObject()
    let result = _func_IegenExample_QueueIntUsage_getSavedQueue(cself, &iegenErr)
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
    var sctoswiftresult: QueueInt
    sctoswiftresult = QueueInt(result)
    return sctoswiftresult
  }

}
